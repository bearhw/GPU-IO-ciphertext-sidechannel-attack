#!/usr/bin/env python3
"""
make_split.py — 3DShapes split held out by hue combination.

3DShapes has no official split, and images that differ only in orientation or
scale are near-duplicates. An image-level random split would put the same scene
on both sides, so the split is made on (floor_hue, wall_hue, object_hue)
combinations: 20% of the 1,000 combinations are test-only.

Outputs split.json:
  train_pool   : all train-combo image indices (dictionary keywords, simulation)
  capture_train: shape-balanced subset of train_pool for real captures (fine-tune)
  test         : shape-balanced subset of test combos for blind e2e evaluation

  python3 make_split.py [--test-per-shape 250] [--ft-per-shape 150]
"""
import argparse
import json
from pathlib import Path

import h5py
import numpy as np

H5 = Path("/home/eun/datasets_ext/3dshapes/3dshapes.h5")
OUT = Path(__file__).resolve().parent / "split.json"
SHAPES = ["cube", "cylinder", "sphere", "capsule"]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--test-per-shape", type=int, default=250)
    ap.add_argument("--ft-per-shape", type=int, default=150)
    ap.add_argument("--test-frac", type=float, default=0.2)
    ap.add_argument("--seed", type=int, default=0)
    a = ap.parse_args()

    lab = h5py.File(H5, "r")["labels"][:]
    hue = np.rint(lab[:, :3] * 10).astype(int) % 10        # hues are 0, 0.1, ..., 0.9
    combo = hue[:, 0] * 100 + hue[:, 1] * 10 + hue[:, 2]
    shape = lab[:, 4].astype(int)

    rng = np.random.default_rng(a.seed)
    test_combos = set(rng.choice(1000, int(1000 * a.test_frac), replace=False).tolist())
    is_test = np.isin(combo, list(test_combos))

    def balanced(mask, per):
        out = []
        for s in range(4):
            idx = np.flatnonzero(mask & (shape == s))
            out += sorted(rng.choice(idx, per, replace=False).tolist())
        return out

    train_pool = np.flatnonzero(~is_test)
    split = {
        "seed": a.seed,
        "shapes": SHAPES,
        "test_combos": sorted(test_combos),
        "train_pool": train_pool.tolist(),
        "capture_train": balanced(~is_test, a.ft_per_shape),
        "test": balanced(is_test, a.test_per_shape),
    }
    OUT.write_text(json.dumps(split))
    print(f"train_pool {len(train_pool)}  test-combo images {is_test.sum()}  "
          f"capture_train {len(split['capture_train'])}  test {len(split['test'])} -> {OUT}")


if __name__ == "__main__":
    main()
