#!/usr/bin/env python3
"""
pv_tuple_rank.py — Rank arbitrary 16-byte keywords (4-pixel tuples) per channel plane.

Identical-value keywords (pv_build_cache.py) cover ~1% of PlantVillage color blocks:
real photo backgrounds carry sensor/JPEG noise, so four exactly equal pixels are
rare. In the ideal case the attacker also knows the tensor's intra-page alignment,
so a non-identical pattern (a,b,c,d) can be injected in the right phase and works
as a keyword too. Normalize is a per-channel bijection on uint8, so a 16-byte
float32 block is identified by its four uint8 pixels in that plane.

Each block is encoded as a uint32 (a | b<<8 | c<<16 | d<<24) and keywords are
ranked by how often they occur in the train split, separately for R, G and B.

Outputs (cache_<variant>/):
  tuples.npy        uint32 (N, 3, 224, 56)  4-pixel code of every block
  tuple_rank.npz    per channel: top codes and counts (TOPN), distinct count,
                    total train blocks per plane
"""

import argparse
import json
import time
from multiprocessing import Pool
from pathlib import Path

import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
ROWS, COLS = 224, 56
TOPN = 65536


def codes(path: str) -> np.ndarray:
    rgb = np.asarray(Image.open(path).convert("RGB").resize((224, 224), Image.BILINEAR))
    b = rgb.transpose(2, 0, 1).reshape(3, ROWS, COLS, 4).astype(np.uint32)
    return b[..., 0] | b[..., 1] << 8 | b[..., 2] << 16 | b[..., 3] << 24


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--variant", default="color", choices=["color", "segmented"])
    ap.add_argument("--workers", type=int, default=64)
    args = ap.parse_args()

    out = HERE / f"cache_{args.variant}"
    meta = json.load(open(out / "meta.json"))
    paths, test = meta["paths"], np.array(meta["test"])
    n = len(paths)

    t0 = time.time()
    mm = np.lib.format.open_memmap(out / "tuples.npy", "w+", np.uint32, (n, 3, ROWS, COLS))
    with Pool(args.workers) as pool:
        for i, c in enumerate(pool.imap(codes, paths, chunksize=32)):
            mm[i] = c
    mm.flush()
    print(f"codes {time.time()-t0:.0f}s", flush=True)

    tr = np.flatnonzero(~test)
    res = {}
    for ch, name in enumerate("RGB"):
        flat = np.ascontiguousarray(mm[tr, ch]).ravel()
        u, cnt = np.unique(flat, return_counts=True)
        o = np.argsort(-cnt, kind="stable")[:TOPN]
        res[f"{name}_codes"], res[f"{name}_counts"] = u[o], cnt[o]
        res[f"{name}_distinct"] = len(u)
        print(f"{name}: {len(u)} distinct tuples, {time.time()-t0:.0f}s", flush=True)
    np.savez(out / "tuple_rank.npz", blocks_per_plane=len(tr) * ROWS * COLS, **res)


if __name__ == "__main__":
    main()
