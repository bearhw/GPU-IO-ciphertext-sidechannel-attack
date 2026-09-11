#!/usr/bin/env python3
"""
llm_block_candidates.py — Step (A) of the host-only input_ids localizer.

Read a write_pattern_tracker WRITE log captured during real (model-loaded)
LLM inference and rank 2MB blocks that are worth swap-scanning for the
input_ids buffer. This REPLACES the single guest-cooperation step in
orchestrate_v4.py (the guest printing "input_ids base GPA: 0x...").

Scoring (same as write-tracker/final_logs/plot_llm_detect.py, validated to
put the ground-truth input_ids block in the top-7 across bs=1 and bs=128
runs): build gap-tolerant contiguous 4K runs, skip/finalize on the GPU-CC
control regions A/B, and score each 2MB block by  hits * max_run_len.

Output: the top-N candidate 2MB block base GPAs, machine-readable on stdout
as CAND_BLK=0x<addr>, ranked table on stderr. These blocks are the input to
step (B) — swap-scan each one for the image_pad ciphertext fingerprint.

Usage:
  python3 llm_block_candidates.py host_run.log            # top 7
  python3 llm_block_candidates.py host_run.log --top 10
  # grade against a guest GPA_RUN log (has the true input_ids GPAs):
  python3 llm_block_candidates.py host_run.log --guest guest_run.log
"""
import argparse
import re
import sys
from collections import defaultdict

PAGE  = 0x1000
BLOCK = 0x200000            # 2 MB
MIN_RUN = 2
GAP_TOL = 2
# GPU-CC control regions: A = per-batch clock (fixed), B = image-DMA staging.
# Both only DELIMIT runs; pages inside them never build a candidate run.
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
B_LO, B_HI = 0x3f80000000, 0x3f90000000

RE_W   = re.compile(r'WRITE\s+gpa=0x([0-9a-f]+)\s+ts=(\d+)', re.I)
# guest-side ground-truth (grading only): true input_ids page runs
RE_IDS = re.compile(r'input_ids:\s*0x([0-9a-f]+)\s+len=(\d+)', re.I)
# fallback: a plain "input_ids base GPA: 0x..." line (single page)
RE_BASE = re.compile(r'input_ids base(?: page)? GPA:\s*0x([0-9a-f]+)', re.I)


def blk(gpa: int) -> int:
    return (gpa // BLOCK) * BLOCK


def score_blocks(host_log: str) -> dict:
    """Return {block_base: (score, hits, max_run)} from a WRITE log."""
    faults = []
    with open(host_log, errors="ignore") as f:
        for line in f:
            m = RE_W.search(line)
            if m:
                faults.append((int(m.group(2)), int(m.group(1), 16) & ~(PAGE - 1)))
    faults.sort()

    runs = defaultdict(list)
    base = length = 0

    def record():
        nonlocal base, length
        if length >= MIN_RUN:
            runs[blk(base)].append(length)

    for _, gpa in faults:
        if A_LO <= gpa < A_HI or B_LO <= gpa < B_HI:
            record()
            base = length = 0
            continue
        if length == 0:
            base, length = gpa, 1
        else:
            expected = base + length * PAGE
            if gpa == expected:
                length += 1
            elif gpa > expected:
                gap = (gpa - expected) // PAGE
                if gap <= GAP_TOL:
                    length += int(gap) + 1
                else:
                    record()
                    base, length = gpa, 1
            else:
                record()
                base, length = gpa, 1
    record()

    return {b: (len(r) * max(r), len(r), max(r)) for b, r in runs.items()}


def gt_blocks(guest_log: str) -> set:
    """2MB blocks that truly hold input_ids pages (grading only)."""
    gt = set()
    with open(guest_log, errors="ignore") as f:
        for line in f:
            m = RE_IDS.search(line)
            if m:
                b = int(m.group(1), 16) & ~(PAGE - 1)
                n = int(m.group(2))
                for i in range(n):
                    gt.add(blk(b + i * PAGE))
                continue
            m = RE_BASE.search(line)
            if m:
                gt.add(blk(int(m.group(1), 16)))
    return gt


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("host_log", help="write_pattern_tracker WRITE log")
    p.add_argument("--top", type=int, default=7, help="candidate blocks to emit")
    p.add_argument("--guest", default=None, help="guest GPA_RUN log for grading")
    args = p.parse_args()

    scores = score_blocks(args.host_log)
    if not scores:
        print("[!] no WRITE events parsed", file=sys.stderr)
        sys.exit(1)
    ranked = sorted(scores, key=lambda b: -scores[b][0])
    gt = gt_blocks(args.guest) if args.guest else set()

    print(f"[cand] {len(scores)} 2MB blocks scored; top {args.top}:", file=sys.stderr)
    print("  rank  block(2MB)      score       hits   max_run   gt", file=sys.stderr)
    for i, b in enumerate(ranked[:args.top]):
        s, h, r = scores[b]
        mark = "GT" if b in gt else ""
        print(f"  #{i+1:<3d} 0x{b:011x}  {s:>10,}  {h:>5}  {r:>6}p   {mark}",
              file=sys.stderr)

    if gt:
        gt_ranks = [i + 1 for i, b in enumerate(ranked) if b in gt]
        best = min(gt_ranks) if gt_ranks else None
        in_top = [r for r in gt_ranks if r <= args.top]
        print(f"[grade] GT blocks total={len(gt)}  best GT rank=#{best}  "
              f"GT in top-{args.top}: {len(in_top)}", file=sys.stderr)

    for b in ranked[:args.top]:
        print(f"CAND_BLK=0x{b:x}")


if __name__ == "__main__":
    main()
