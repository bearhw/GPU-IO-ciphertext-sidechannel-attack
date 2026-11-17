#!/usr/bin/env python3
"""
build_sim.py — simulated cipher maps for attack-classifier pretraining.

Maps are stored as uint8 (keyword index + 1, 0 = miss), shape (N, 3, 224, 56).
  train: --n-train images sampled from split.json train_pool (disjoint from the
         victim_train / capture_train images is not required: the attacker owns
         the public dataset; test combos are never used)
  test : split.json test (the same 1,000 images the blind e2e run captures)

  python3 build_sim.py [--n-train 30000] [--workers 48]
"""
import argparse
import json
import sys
from multiprocessing import Pool
from pathlib import Path

import h5py
import numpy as np

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "pipeline"))
import shapes_map as sm  # noqa: E402

H5 = Path("/home/eun/datasets_ext/3dshapes/3dshapes.h5")
_T = None


def _init():
    global _T
    _T = sm.keyword_tables()


def _one(img):
    return (sm.simulate(img, _T) + 1).astype(np.uint8)


def build(idx, workers):
    idx = np.asarray(idx)
    order = np.argsort(idx)
    f = h5py.File(H5, "r")["images"]
    imgs = np.concatenate([f[np.sort(idx)[s:s + 5000]] for s in range(0, len(idx), 5000)])
    inv = np.empty_like(order)
    inv[order] = np.arange(len(order))
    imgs = imgs[inv]
    with Pool(workers, initializer=_init) as p:
        maps = np.stack(p.map(_one, list(imgs), chunksize=64))
    lab = h5py.File(H5, "r")["labels"]
    shape = np.array([lab[i][4] for i in idx]).astype(np.int64)
    return maps, shape


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--n-train", type=int, default=30000)
    ap.add_argument("--workers", type=int, default=48)
    a = ap.parse_args()
    split = json.loads((HERE / "split.json").read_text())
    rng = np.random.default_rng(3)
    out = HERE.parent / "datasets"
    for name, idx in (("test", split["test"]),
                      ("train", rng.choice(split["train_pool"], a.n_train, replace=False))):
        maps, shape = build(idx, a.workers)
        np.savez(out / f"sim_{name}.npz", maps=maps, shape=shape, index=np.asarray(idx))
        cov = (maps > 0).mean(axis=(0, 2, 3))
        print(f"{name}: {maps.shape}  coverage R/G/B {np.round(100 * cov, 1).tolist()}  "
              f"shapes {np.bincount(shape).tolist()}", flush=True)


if __name__ == "__main__":
    main()
