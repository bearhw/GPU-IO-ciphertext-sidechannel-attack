#!/usr/bin/env python3
"""
verify_stitching.py — Detailed Validation of Multi-Block Temporal Stitching.

Compares the stitched 49-page channels produced by Stage 2 against the
Ground Truth GPA pages logged by the guest VM (mura_guest_nomul_*.log).

Usage:
    python3 verify_stitching.py [--run 1] [--verbose]
"""

import argparse
import os
import re
import sys
from pathlib import Path
from typing import Dict, List, Set, Tuple

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c
import stage2_track_gpa as s2

GUEST_LOG_TMPL = "/home/eun/esp_bak/sev-step/userspace/write-tracker/mura/mura_guest_nomul_{run}_raw.log"
HOST_LOG_TMPL  = "/home/eun/esp_bak/sev-step/userspace/write-tracker/mura/mura_host_regB_{run}.log"


def parse_guest_ground_truth(guest_log_path: str) -> Dict[int, Dict[Tuple[int, str], List[int]]]:
    """Parse guest raw log into {iter_id: {(img_id, ch): [gpa0, gpa1, ..., gpa48]}}."""
    iters = {}
    with open(guest_log_path, errors="ignore") as f:
        for line in f:
            m = re.search(r'\[GPA_PAGE\] iter(\d+)/input img=(\d+) ch=(\w+) ch_pg=(\d+) GPA=0x([0-9a-fA-F]+)', line)
            if m:
                it = int(m.group(1))
                img = int(m.group(2))
                ch = m.group(3)
                ch_pg = int(m.group(4))
                gpa = int(m.group(5), 16)
                iters.setdefault(it, {}).setdefault((img, ch), {})[ch_pg] = gpa

    ordered_iters = {}
    for it, img_map in iters.items():
        ordered_iters[it] = {}
        for (img, ch), pmap in img_map.items():
            ordered_iters[it][(img, ch)] = [pmap[i] for i in sorted(pmap.keys())]
    return ordered_iters


def verify_run(run_id: int, verbose: bool = False):
    guest_log = GUEST_LOG_TMPL.format(run=run_id)
    host_log  = HOST_LOG_TMPL.format(run=run_id)

    if not os.path.exists(guest_log) or not os.path.exists(host_log):
        print(f"[!] Log files for Run {run_id} not found.")
        return

    print("\n" + "=" * 94)
    print(f"  MULTI-BLOCK TEMPORAL STITCHING VALIDATION: RUN {run_id}")
    print(f"  - Host Log : {os.path.basename(host_log)}")
    print(f"  - Guest GT : {os.path.basename(guest_log)}")
    print("=" * 94 + "\n")

    # 1. Parse ground truth
    gt_iters = parse_guest_ground_truth(guest_log)
    print(f"[GT] Parsed {len(gt_iters)} iteration(s) from guest log.")

    # 2. Parse and stitch host writes
    writes = []
    with open(host_log, errors="ignore") as f:
        for line in f:
            if not line.startswith("WRITE"):
                continue
            m = re.search(r'gpa=0x([0-9a-fA-F]+)\s+ts=(\d+)', line)
            if m:
                writes.append((int(m.group(1), 16), int(m.group(2))))

    print(f"[Host] Loaded {len(writes):,} write events. Performing Temporal Stitching...")
    candidates = s2.stitch_temporal_runs(writes)
    print(f"[Stitch] Formed {len(candidates)} stitched channel candidate(s).\n")

    # Split candidates into 49p slices
    all_slices = []
    for cand in candidates:
        all_slices.append({
            "set": set(cand["channel_pages"]),
            "pages": cand["channel_pages"],
            "blocks": cand["blocks"],
            "num_blocks": cand["num_blocks"],
            "dt_ms": cand["dt_ms"]
        })

    # 3. Match against Ground Truth
    print(f"{'Iter':<6}{'Img':<5}{'Ch':<4}{'GT 2MB Blocks':<24}{'Stitched Blocks':<24}{'Pages':<8}{'Match %':<10}{'Status'}")
    print("-" * 94)

    c_49 = 0
    c_36 = 0
    c_25 = 0
    total_gt_channels = 0

    for it in sorted(gt_iters.keys()):
        for (img, ch), gt_pgs in gt_iters[it].items():
            total_gt_channels += 1
            gt_set = set(gt_pgs)
            gt_blocks = sorted(list(set(hex(p & ~(c.BLIND_ALIGN_2MB - 1)) for p in gt_pgs)))

            # Find best matching stitched slice
            best_match_count = 0
            best_slice = None
            for s in all_slices:
                overlap = len(gt_set & s["set"])
                if overlap > best_match_count:
                    best_match_count = overlap
                    best_slice = s

            match_pct = (best_match_count / len(gt_pgs)) * 100.0 if gt_pgs else 0.0
            if best_match_count == len(gt_pgs):
                c_49 += 1
            if best_match_count >= 36:
                c_36 += 1
                status = f"SUCCESS ({best_match_count}/49)"
            elif best_match_count >= 25:
                c_25 += 1
                status = f"PARTIAL ({best_match_count}/49)"
            else:
                status = f"MISSED ({best_match_count}/49)"

            cand_blocks_str = str(best_slice["blocks"][:2]) if best_slice else "[]"
            gt_blocks_str = str(gt_blocks[:2])

            print(f"{it:<6}{img:<5}{ch:<4}{gt_blocks_str:<24}{cand_blocks_str:<24}{len(gt_pgs):<8}{match_pct:>6.1f}%   {status}")

    print("-" * 94)
    print(f"\n[Summary] Precursor-Gated Stitching Recovery for Run {run_id}:")
    print(f"  - Exact 49/49 (100.0%)       : {c_49}/{total_gt_channels} channels ({c_49/max(1,total_gt_channels)*100:.1f}%)")
    print(f"  - Usable Target (>=36/49)    : {c_36}/{total_gt_channels} channels ({c_36/max(1,total_gt_channels)*100:.1f}%)")
    print(f"  - Partial Capture (>=25/49)  : {c_36+c_25}/{total_gt_channels} channels ({(c_36+c_25)/max(1,total_gt_channels)*100:.1f}%)")
    print("=" * 94 + "\n")


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--run", type=int, default=1, help="Validation Run ID (1-5)")
    p.add_argument("--verbose", action="store_true", help="Print per-block straddle breakdown")
    args = p.parse_args()

    verify_run(args.run, verbose=args.verbose)


if __name__ == "__main__":
    main()
