#!/usr/bin/env python3
"""
summarize_recovery.py — Page-recovery statistics from pipeline_summary.csv.

Reports how many of the guest's 49 channel pages each run actually dumped.
Rows without a GT column (guest never reported its pages) are counted as
failures, not skipped, so the mean is not flattered by dropping them.

Usage:
    python3 summarize_recovery.py [--csv pipeline_summary.csv] [--min-index N]
"""

import argparse
import csv
import statistics
import sys
from collections import Counter
from pathlib import Path

HERE = Path(__file__).resolve().parent


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--csv", default=str(HERE / "pipeline_summary.csv"))
    p.add_argument("--min-index", type=int, default=None,
                   help="Ignore rows below this index (e.g. to skip a bad early run)")
    p.add_argument("--drop-failures", action="store_true",
                   help="Exclude zero-page runs from the mean (reports them separately)")
    args = p.parse_args()

    path = Path(args.csv)
    if not path.exists():
        sys.exit(f"{path} not found")

    rows = list(csv.DictReader(open(path)))
    if args.min_index is not None:
        rows = [r for r in rows if r.get("index", "").isdigit()
                and int(r["index"]) >= args.min_index]

    ovs, bests, failures, no_gt, malformed = [], [], 0, 0, 0
    per_class = {}
    for r in rows:
        raw = (r.get("gt_overlap") or "-").strip()
        if raw in ("-", ""):
            no_gt += 1
            ovs.append(0)
            continue
        try:
            v = int(raw)
        except ValueError:
            # A row written under a different column set shifts every field; it is
            # not recoverable here and counting it would corrupt the mean.
            malformed += 1
            continue
        ovs.append(v)
        b = (r.get("gt_best_cand") or "-").strip()
        if b not in ("-", ""):
            bests.append(int(b))
        if v == 0:
            failures += 1
        per_class.setdefault(r.get("gt_label", "?"), []).append(v)

    if not ovs:
        sys.exit("no rows to summarize")

    pool = [v for v in ovs if v > 0] if args.drop_failures else ovs
    n = len(ovs)
    total = int(rows[0].get("gt_pages") or 49)

    print(f"runs                : {n}")
    print(f"  zero-page failures: {failures}")
    print(f"  guest gave no GT  : {no_gt}")
    if malformed:
        print(f"  [!] malformed rows: {malformed} (skipped — column set mismatch)")
    print()
    print(f"mean recovered      : {statistics.mean(pool):.2f}/{total} "
          f"= {statistics.mean(pool)/total*100:.1f}%"
          f"{'  (failures excluded)' if args.drop_failures else ''}")
    print(f"median              : {statistics.median(pool):.0f}/{total}")
    if len(pool) > 1:
        print(f"stdev               : {statistics.stdev(pool):.2f}")
    print(f"min / max           : {min(pool)} / {max(pool)}")
    print()
    for thr in (49, 45, 40, 36, 25):
        k = sum(1 for v in ovs if v >= thr)
        print(f"  >= {thr:>2}/{total} pages : {k:>5}/{n}  ({k/n*100:5.1f}%)")

    if bests:
        print()
        print(f"ceiling (best candidate in the top-K, whatever selector is used)")
        print(f"  mean              : {statistics.mean(bests):.2f}/{total} "
              f"= {statistics.mean(bests)/total*100:.1f}%")
        print(f"  >= 45/{total}        : {sum(1 for v in bests if v >= 45)}/{len(bests)}")

    if len(per_class) > 1:
        print()
        print(f"{'class':<10} {'runs':>6} {'mean':>8}")
        for cls, v in sorted(per_class.items(), key=lambda kv: -len(kv[1])):
            print(f"{cls:<10} {len(v):>6} {statistics.mean(v):>7.1f}")


if __name__ == "__main__":
    main()
