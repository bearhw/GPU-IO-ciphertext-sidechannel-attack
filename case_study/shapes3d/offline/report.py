#!/usr/bin/env python3
"""
report.py — 3DShapes blind end-to-end results from a capture directory.

Accuracy (overall, per shape, confusion), localization (tensor pages recovered,
cipher-map coverage) and time per stage, from <dir>/summary.csv. Failed samples
(pipeline error) count as wrong in the strict end-to-end number.

  python3 report.py ../captures/test_blind
"""
import ast
import csv
import sys
from collections import Counter

import numpy as np

CLASSES = ["cube", "cylinder", "sphere", "capsule"]


def main():
    d = sys.argv[1]
    rows = list(csv.DictReader(open(f"{d}/summary.csv")))
    last = {}
    for r in rows:
        last[r["index"]] = r
    rows = list(last.values())
    ok = [r for r in rows if not r["error"] and r["gt_class"] in CLASSES]
    err = [r for r in rows if r["error"] or r["gt_class"] not in CLASSES]
    acc = np.mean([r["correct"] == "True" for r in ok]) if ok else 0
    strict = sum(r["correct"] == "True" for r in ok) / max(1, len(rows))
    print(f"samples {len(rows)}  completed {len(ok)}  failed {len(err)}")
    print(f"top-1 (completed) {100 * acc:.1f}%   strict e2e {100 * strict:.1f}%   chance 25.0%")
    cm = np.zeros((4, 4), int)
    for r in ok:
        cm[CLASSES.index(r["gt_class"]), CLASSES.index(r["pred"])] += 1
    print("per shape: " + "  ".join(f"{c} {100 * cm[i, i] / max(1, cm[i].sum()):.1f}% (n={cm[i].sum()})"
                                     for i, c in enumerate(CLASSES)))
    print("confusion (rows gt, cols pred):\n" + "\n".join(f"  {c:9s} {cm[i].tolist()}" for i, c in enumerate(CLASSES)))
    ov = np.array([int(r["gt_overlap"]) for r in ok])
    cov = np.array([ast.literal_eval(r["coverage"]) for r in ok])
    print(f"tensor pages recovered: median {np.median(ov):.0f}/148, >=140 in {100 * np.mean(ov >= 140):.1f}%")
    print(f"cipher-map coverage R/G/B mean {np.round(100 * cov.mean(0), 1).tolist()}")
    gpu = Counter(r["gpu_pred"] == r["gt_class"] for r in ok if r["gpu_pred"])
    print(f"victim GPU prediction correct: {gpu[True]}/{sum(gpu.values())}")
    for col in ("t_stage2", "t_localize", "t_dump", "t_stage45", "elapsed_sec"):
        v = np.array([float(r[col]) for r in ok if r[col]])
        print(f"  {col:11s} median {np.median(v):6.1f}s  mean {v.mean():6.1f}s")


if __name__ == "__main__":
    main()
