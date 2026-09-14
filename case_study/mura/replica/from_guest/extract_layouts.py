#!/usr/bin/env python3
"""
extract_layouts.py — Extract 'empirical physical page layouts' for replica training.

Why it is needed:
  What an attacker observes is not a clean 49-page tensor, but pages scattered
  inside a 2MB block (512 pages). Measurement results:
    - 49 channel pages are fully physically contiguous in only 29% of cases
    - ch_pg (logical) order matches physical ascending order in only 38%
    - Remaining cases are arbitrarily scattered across 512 slots
  Therefore, training data must be scattered in the same manner to work in practice.

What it does:
  Extract actual layouts for each channel from guest GT logs (mura_guest_nomul_*_raw.log).
  One channel = map of which slots (0..511) within a 2MB block hold logical pages 0..48.

Outputs:
  layouts.npz
    slots   : (N, 49) int16  — slot in block where logical page i is located. -1 if outside block
    n_valid : (N,)    int16  — number of pages contained within dominant block
"""
import argparse
import re
from collections import defaultdict
from pathlib import Path

import numpy as np

PAGE = 0x1000
BLOCK = 0x200000
SLOTS = BLOCK // PAGE          # 512
CH_PAGES = 49                  # 224*224*4 / 4096

RE_GPA_PAGE = re.compile(
    r'\[GPA_PAGE\] iter(\d+)/input img=(\d+) ch=([RGB]) ch_pg=(\d+) GPA=0x([0-9a-f]+)'
)

DEFAULT_LOGS = sorted(
    Path("/home/eun/esp_bak/sev-step/userspace/write-tracker/mura").glob(
        "mura_guest_nomul_*_raw.log")
)


def parse_channels(log_path):
    """(iter, img, ch) -> {ch_pg: page_aligned_gpa}"""
    chans = defaultdict(dict)
    with open(log_path, errors="ignore") as f:
        for line in f:
            m = RE_GPA_PAGE.search(line)
            if not m:
                continue
            key = (int(m.group(1)), int(m.group(2)), m.group(3))
            chans[key][int(m.group(4))] = int(m.group(5), 16) & ~(PAGE - 1)
    return chans


def layout_of(pages_by_chpg):
    """Logical page -> block slot. Based on dominant block (2MB block holding most pages)."""
    if len(pages_by_chpg) != CH_PAGES:
        return None
    blocks = defaultdict(int)
    for gpa in pages_by_chpg.values():
        blocks[(gpa // BLOCK) * BLOCK] += 1
    base = max(blocks, key=blocks.get)

    slots = np.full(CH_PAGES, -1, dtype=np.int16)
    for ch_pg, gpa in pages_by_chpg.items():
        if (gpa // BLOCK) * BLOCK == base:
            slots[ch_pg] = (gpa - base) // PAGE
    return slots


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--logs", nargs="*", type=Path, default=DEFAULT_LOGS,
                    help="Guest GT logs (default: mura_guest_nomul_*_raw.log in write-tracker/mura)")
    ap.add_argument("--out", type=Path, default=Path(__file__).parent / "layouts.npz")
    args = ap.parse_args()

    if not args.logs:
        raise SystemExit("Guest logs not found. Specify directly via --logs.")

    all_slots = []
    for lp in args.logs:
        chans = parse_channels(lp)
        n_ok = 0
        for key, pages in sorted(chans.items()):
            s = layout_of(pages)
            if s is not None:
                all_slots.append(s)
                n_ok += 1
        print(f"  {lp.name}: {len(chans)} channels -> {n_ok} layouts")

    if not all_slots:
        raise SystemExit("No layouts extracted.")

    slots = np.stack(all_slots)                       # (N, 49)
    n_valid = (slots >= 0).sum(axis=1).astype(np.int16)

    # Statistics (for verifying what the script actually extracted)
    contiguous = 0
    ascending = 0
    for s in slots:
        v = s[s >= 0]
        if len(v) == CH_PAGES:
            if np.all(np.diff(np.sort(v)) == 1):
                contiguous += 1
            if np.all(np.diff(v) > 0):
                ascending += 1

    np.savez_compressed(args.out, slots=slots, n_valid=n_valid)
    print(f"\nTotal layouts {len(slots)} -> {args.out}")
    print(f"  Pages in dominant block: median {int(np.median(n_valid))}/49, "
          f"min {n_valid.min()}, all 49 pages: {(n_valid == CH_PAGES).sum()}")
    print(f"  Fully physically contiguous: {contiguous}/{len(slots)} ({100*contiguous/len(slots):.0f}%)")
    print(f"  Logical == physical ascending: {ascending}/{len(slots)} ({100*ascending/len(slots):.0f}%)")


if __name__ == "__main__":
    main()
