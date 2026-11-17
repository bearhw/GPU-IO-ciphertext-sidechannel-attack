#!/usr/bin/env python3
"""
build_capture_set.py — collect captured cipher maps into a training/eval set.

Reads <capture dir>/summary.csv and cmap_<index>.npy (written by Stage 4) and
stores maps in the same uint8 format as build_sim.py.

  python3 build_capture_set.py ../captures/test_blind --name cap_test
  python3 build_capture_set.py ../captures/capture_train_blind --name cap_train
"""
import argparse
import csv
from pathlib import Path

import numpy as np

HERE = Path(__file__).resolve().parent
CLASSES = ["cube", "cylinder", "sphere", "capsule"]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("dirs", nargs="+")
    ap.add_argument("--name", required=True)
    a = ap.parse_args()
    maps, ys, idx, src = [], [], [], []
    for d in map(Path, a.dirs):
        rows = {int(r["index"]): r for r in csv.DictReader(open(d / "summary.csv")) if not r["error"]}
        for i, r in sorted(rows.items()):
            f = d / f"cmap_{i}.npy"
            if not f.exists() or r["gt_class"] not in CLASSES:
                continue
            maps.append(np.load(f))
            ys.append(CLASSES.index(r["gt_class"]))
            idx.append(i)
            src.append(str(d))
    maps = np.stack(maps)
    out = HERE.parent / "datasets" / f"{a.name}.npz"
    np.savez(out, maps=maps, shape=np.array(ys), index=np.array(idx), src=np.array(src))
    cov = (maps > 0).mean(axis=(0, 2, 3))
    print(f"{out}: {len(ys)} maps, shapes {np.bincount(ys, minlength=4).tolist()}, "
          f"coverage R/G/B {np.round(100 * cov, 1).tolist()}")


if __name__ == "__main__":
    main()
