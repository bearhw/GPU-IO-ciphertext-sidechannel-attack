#!/usr/bin/env python3
"""
stage2b_locate_pages.py — the missing blind step: locate the tensor start page
inside a candidate 2MB block, using the block's dumped content.

Stage 2 ranks candidate 2MB blocks from the host write trace, but the host trace
alone cannot pin the tensor's start page inside the block — measured on the paired
run logs, the longest observed run begins 44-254 pages from the true start,
because GPU DMA leaves only 9-67% of the tensor's pages faulting. So the start
must come from content, not from write timing.

Each of a block's 512 pages is swap-dumped and XORed against the clean zero page:
a chunk that changed is foreground, one that did not is background (u8=0). MNIST
pixels are ~80.9% background, so the real tensor window is the 49-page run whose
background ratio sits closest to that. score_windows (mnist_blind_locate.py, the
verified scorer) ranks start positions; with an anchor from Stage 2's observed run
it searches only a neighbourhood, otherwise the whole block.

Usage (offline, from already-dumped block pages):
    python3 stage2b_locate_pages.py --block-dumps page_dumps.txt --zero zero.out \
        --anchor-page 120 --top 5
"""

import argparse
import sys
from pathlib import Path

import numpy as np

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

# the verified scorer lives in the write-tracker tree
sys.path.insert(0, "/home/eun/esp_bak/sev-step/userspace/write-tracker/mnist")
import mnist_blind_locate as loc

PAGES_PER_BLOCK = loc.PAGES_PER_BLOCK      # 512
CHUNKS_PAGE = loc.CHUNKS_PAGE              # 256


def page_scan_row(dump_page: bytearray, zero_page: bytearray) -> np.ndarray:
    """One page -> 256 chunks, 0 = background (matches zero), -1 = foreground.

    Same background test Stage 4 uses: a chunk is background when no byte differs
    from the clean zero page. score_windows expects 0 for background, -1 otherwise.
    """
    row = np.full(CHUNKS_PAGE, -1, dtype=np.int16)
    n = min(CHUNKS_PAGE, len(dump_page) // c.CHUNK_BYTES, len(zero_page) // c.CHUNK_BYTES)
    for k in range(n):
        s = k * c.CHUNK_BYTES
        e = s + c.CHUNK_BYTES
        if not any(dump_page[i] ^ zero_page[i] for i in range(s, e)):
            row[k] = 0
    return row


def build_scan(page_dump_files, zero_file: Path) -> np.ndarray:
    """Assemble a (512, 256) scan array from the block's per-page dumps.

    page_dump_files is ordered by page index within the block; missing pages
    (never dumped / never faulted) stay all-foreground (-1), which is what an
    unobserved page looks like to the scorer.
    """
    zero = c.parse_dump(Path(zero_file))
    scan = np.full((PAGES_PER_BLOCK, CHUNKS_PAGE), -1, dtype=np.int16)
    for p, f in enumerate(page_dump_files):
        if p >= PAGES_PER_BLOCK:
            break
        if f is None:
            continue
        scan[p] = page_scan_row(c.parse_dump(Path(f)), zero)
    return scan


def locate(scan: np.ndarray, anchor_page=None, anchor_window=30, win_pages=None,
           top=5):
    """Rank candidate tensor start pages. Returns [(page, bg_ratio, dist), ...]."""
    wp = win_pages or loc.N_PAGES_TENSOR
    ranked = loc.score_windows(scan, win_pages=wp, anchor_page=anchor_page,
                               anchor_window=anchor_window)
    return ranked[:top]


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--block-dumps", required=True,
                    help="text file: one per-page dump path per line, in page order "
                         "(blank line = page not dumped)")
    ap.add_argument("--zero", required=True, help="clean zero-page dump")
    ap.add_argument("--anchor-page", type=int, default=None,
                    help="Stage 2's observed run start, page-indexed in this block")
    ap.add_argument("--anchor-window", type=int, default=30)
    ap.add_argument("--win-pages", type=int, default=None,
                    help=f"tensor size in pages (default {loc.N_PAGES_TENSOR} for bs=64)")
    ap.add_argument("--top", type=int, default=5)
    ap.add_argument("--gt-page", type=int, default=None,
                    help="true tensor start page, to report the error")
    args = ap.parse_args()

    files = []
    for line in open(args.block_dumps):
        s = line.strip()
        files.append(s if s else None)
    print(f"[locate] {sum(f is not None for f in files)} of {len(files)} block pages dumped")

    scan = build_scan(files, Path(args.zero))
    bg = (scan == 0).mean()
    print(f"[locate] block background ratio = {bg:.3f} (MNIST expects {loc.EXPECTED_BG_RATIO})")

    ranked = locate(scan, anchor_page=args.anchor_page,
                    anchor_window=args.anchor_window, win_pages=args.win_pages,
                    top=args.top)
    print(f"\ntop-{args.top} candidate tensor start pages:")
    for i, (p, r, d) in enumerate(ranked):
        tag = ""
        if args.gt_page is not None and p == args.gt_page:
            tag = "  <-- GT"
        print(f"  #{i+1}  page {p:>3}  bg_ratio={r:.3f}  dist={d:.4f}{tag}")

    if args.gt_page is not None and ranked:
        best = ranked[0][0]
        print(f"\nGT page {args.gt_page}, top-1 page {best}, "
              f"error {abs(best - args.gt_page)} pages")


if __name__ == "__main__":
    main()
