#!/usr/bin/env python3
"""
llm_validate_single.py -- prove the dictionary-matching CORE works on one
sample, before trusting the blind candidate-enumeration pipeline.

Why this exists: llm_candidate_confirm.py feeds sweep_blind() a 2MB-aligned
block (blk(base)) as base_gpa. But sweep_blind treats base_gpa as the EXACT
page of input_ids[0] (ind_gpa = base_gpa + tok_start*8, image_pad probed at
tok 15..~250 from there). input_ids[0] sits at some page INSIDE the 2MB
block (e.g. 0x33f163000, ~1.4MB past the block start 0x33f000000), so the
probe lands in unrelated memory and every match fails silently -- even when
the write was captured.

This script isolates the question "does dict/swap/verify even work?" from
"does blind enumeration find the right page?" by running sweep_blind on the
guest's OWN reported input_ids page (free ground truth from
dump_tensor_gpa_full's [GPA] line -- never used by the real blind attack,
only to validate here):

  Test A: sweep_blind(gt_page)            -- MUST match if the core works.
  Test B: address-sorted run enumeration  -- find gt_page's rank among
          page-granular candidates, i.e. would a blind pass reach it?

Run on the HOST, with sudo (swap_tool needs root), while the guest is idle
(no competing capture -- single vCPU).

Usage:
  sudo python3 llm_validate_single.py --index 2
"""
import argparse
import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from orchestrate_v4 import DICT_CACHE, SWAP_TOOL, sweep_blind  # noqa: E402

SCRIPT_DIR = Path(__file__).resolve().parent
PAGE = 0x1000
ALIGN_2MB = 0x200000
B_LO, B_HI = 0x3f80000000, 0x3f90000000
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
GAP_TOL = 2
MIN_RUN = 2

VLM_PYTHON = "/home/ubuntu/miniconda3/envs/vlm/bin/python3"
INFERENCE_SCRIPT = "/home/ubuntu/medical_ml/med_vlm/scripts/single_inference.py"
HOST_ADDR_ON_GUEST = "eun@10.0.2.2"

RE_W = re.compile(r'^WRITE\s+gpa=0x([0-9a-f]+)\s+ts=(\d+)')
RE_GPA_IDS = re.compile(r'\[GPA\] batch\d+/input/input_ids: GPA=0x([0-9a-f]+)')


def enum_runs(host_log):
    """Address-sorted contiguous-run detection (robust for tiny 2-page
    tensors, unlike line-order scanning). Returns page-anchored candidates
    ranked by score = total_hits * run_len_pages, descending.

    Each unique written page counts its write frequency (churn). Pages are
    then sorted by address and coalesced into runs (gap<=GAP_TOL). The run's
    START page is the sweep_blind anchor; input_ids[0] lives there.
    """
    hits = {}
    with open(host_log, errors='ignore') as f:
        for line in f:
            m = RE_W.match(line)
            if not m:
                continue
            gpa = int(m.group(1), 16) & ~(PAGE - 1)
            if A_LO <= gpa < A_HI or B_LO <= gpa < B_HI:
                continue
            hits[gpa] = hits.get(gpa, 0) + 1

    pages = sorted(hits)
    runs = []  # (start_page, len_pages, total_hits)
    i = 0
    while i < len(pages):
        start = pages[i]
        length = 1
        total = hits[pages[i]]
        j = i + 1
        while j < len(pages):
            gap = (pages[j] - (start + length * PAGE)) // PAGE
            if pages[j] == start + length * PAGE:
                length += 1; total += hits[pages[j]]; j += 1
            elif 0 <= gap <= GAP_TOL:
                length += gap + 1; total += hits[pages[j]]; j += 1
            else:
                break
        if length >= MIN_RUN:
            runs.append((start, length, total))
        i = j
    runs.sort(key=lambda r: (-(r[2] * r[1]), -r[1]))
    return runs


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, required=True)
    p.add_argument("--ssh-target", default="ubuntu@localhost")
    p.add_argument("--ssh-port", type=int, default=7777)
    p.add_argument("--capture-dir", default="./single_sample_captures")
    p.add_argument("--guest-timeout", type=int, default=300)
    p.add_argument("--blind-top", type=int, default=5,
                   help="also run sweep_blind on the top-N page candidates "
                        "to show whether a blind pass reaches gt_page")
    args = p.parse_args()

    if not DICT_CACHE.exists():
        print(f"[!] {DICT_CACHE} not found -- run `sudo python3 orchestrate_v4.py --build`.",
              file=sys.stderr)
        sys.exit(1)
    with open(DICT_CACHE) as f:
        cache = json.load(f)

    cap = Path(args.capture_dir); cap.mkdir(parents=True, exist_ok=True)
    idx = args.index
    t0 = int(time.time())

    host_proc = subprocess.Popen(
        ["bash", str(SCRIPT_DIR / "llm_single_host_capture.sh"), str(idx), str(cap)])
    time.sleep(1.0)

    guest_log = cap / f"guest_idx{idx}_{t0}.log"
    guest_cmd = (f"sudo {VLM_PYTHON} {INFERENCE_SCRIPT} --index {idx} "
                 f"--track-input --input-only --host-addr {HOST_ADDR_ON_GUEST}")
    # This whole script runs as root (swap_tool needs it), but root has no
    # ssh key/known_hosts for the guest -- the keys belong to the invoking
    # user. Drop to that user for the guest ssh (mirrors how the guest itself
    # signals back via `sudo -u ubuntu ssh`). Without this the ssh fails
    # instantly, the guest never runs, /tmp/input_start never arrives, and
    # the host capture script hangs producing no log.
    ssh_base = ["ssh", "-p", str(args.ssh_port), "-o", "ConnectTimeout=20",
                "-o", "BatchMode=yes", args.ssh_target, guest_cmd]
    sudo_user = os.environ.get("SUDO_USER")
    ssh_cmd = (["sudo", "-u", sudo_user] + ssh_base) if sudo_user else ssh_base
    print(f"[validate] running guest inference for index {idx} "
          f"(as {sudo_user or 'current user'}, may take ~60s)...")
    with open(guest_log, "w") as gf:
        subprocess.run(ssh_cmd, stdout=gf, stderr=subprocess.STDOUT,
                       timeout=args.guest_timeout)
    try:
        host_proc.communicate(timeout=120)
    except subprocess.TimeoutExpired:
        host_proc.kill(); host_proc.communicate()

    host_logs = sorted(cap.glob(f"host_idx{idx}_*.log"), key=lambda q: q.stat().st_mtime)
    if not host_logs:
        print("[validate] no host capture log -- capture failed.", file=sys.stderr)
        sys.exit(2)
    host_log = host_logs[-1]

    gt_page = None
    with open(guest_log, errors='ignore') as f:
        for line in f:
            m = RE_GPA_IDS.search(line)
            if m:
                gt_page = int(m.group(1), 16) & ~(PAGE - 1)
                break
    if gt_page is None:
        print("[validate] guest did not report an input_ids [GPA] line.", file=sys.stderr)
        sys.exit(3)

    n_writes = sum(1 for l in open(host_log, errors='ignore') if l.startswith("WRITE"))
    print(f"\n[validate] host log: {host_log}  ({n_writes} WRITE lines)")
    print(f"[validate] guest ground-truth input_ids page: 0x{gt_page:x}")
    print(f"[validate] (2MB block would be 0x{gt_page & ~(ALIGN_2MB-1):x} -- "
          f"{(gt_page & (ALIGN_2MB-1)) // PAGE} pages into the block)")

    runs = enum_runs(host_log)
    print(f"[validate] {len(runs)} page-anchored run candidates")
    gt_rank = next((r + 1 for r, (s, _l, _h) in enumerate(runs) if s == gt_page), None)
    if gt_rank:
        s, l, h = runs[gt_rank - 1]
        print(f"[validate] gt_page IS candidate #{gt_rank}/{len(runs)} "
              f"(len={l}p hits={h} score={h*l})")
    else:
        in_any = any(s <= gt_page < s + l * PAGE for s, l, _h in runs)
        print(f"[validate] gt_page is NOT a run-start "
              f"({'but falls inside some run' if in_any else 'and is in no run'}) "
              f"-- write-tracker did not see it as a contiguous burst")

    # ── Test A: definitive core check on the known-correct anchor ──
    print(f"\n[validate] === Test A: sweep_blind on ground-truth page 0x{gt_page:x} ===")
    matches, N_est = sweep_blind(gt_page, cache, str(SWAP_TOOL))
    if matches:
        print(f"[validate] *** CORE WORKS: {len(matches)} match(es), N_est={N_est} ***")
        for m in matches:
            print(f"    label={m['label']!r}  tok_start={m['tok_start']}  "
                  f"ind_gpa=0x{m['ind_gpa']:x}  n_blocks={m['n_blocks']}")
    else:
        print(f"[validate] !!! NO MATCH on the ground-truth page (N_est={N_est}). "
              f"Dict/offset problem, NOT an enumeration problem. Debug here first.")

    # ── Test B: would a blind top-N pass reach it? ──
    if args.blind_top and runs:
        print(f"\n[validate] === Test B: sweep_blind on top-{args.blind_top} "
              f"page candidates (blind) ===")
        for r, (s, l, h) in enumerate(runs[:args.blind_top]):
            mm, ne = sweep_blind(s, cache, str(SWAP_TOOL))
            tag = "  <-- gt_page" if s == gt_page else ""
            print(f"  #{r+1} 0x{s:x} len={l}p score={h*l} -> "
                  f"{'MATCH x%d' % len(mm) if mm else 'no_match'}{tag}")

    print(f"\n[validate] done. host_log={host_log} guest_log={guest_log}")


if __name__ == "__main__":
    main()
