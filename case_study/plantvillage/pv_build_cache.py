#!/usr/bin/env python3
"""
pv_build_cache.py — Ground-truth cipher-map source data for PlantVillage (color).

Ideal-case Challenge-3 study (paper Sec. 5.4.2 setting: the input buffer pages are
known, cipher maps are built straight from the images). The victim preprocessing is
the same as the MURA workload: Resize((224,224)) on the PIL image -> ToTensor ->
per-channel ImageNet Normalize -> (3,224,224) float32, three planes of 49 pages.

A dictionary keyword is a 16-byte block of four identical normalized float32 values
in one channel plane. Normalize is a per-channel bijection on uint8 levels, so a
block equals keyword (c, v) exactly when its four uint8 pixels in plane c are all v.
That lets every dictionary configuration be derived later from one "run map":
for each plane and each 16-byte block, the shared uint8 level if the four pixels
are identical, else -1.

Outputs (OUT dir):
  rgb_runs.npy   int16 (N, 3, 224, 56)   R/G/B planes of the color tensor
  gray_runs.npy  int16 (N, 224, 56)      same image as a grayscale victim (convert("L"))
  meta.json      paths, class names, labels, species labels, 80/20 stratified split
  density.npz    per-level identical-block counts on the train split:
                   rgb (3, 256), gray (256,), total blocks per plane
"""

import argparse
import json
import time
from multiprocessing import Pool
from pathlib import Path

import numpy as np
from PIL import Image

ROOT = Path("/home/eun/datasets_ext/plantvillage/raw")
HERE = Path(__file__).resolve().parent
ROWS, COLS = 224, 56


def runs(plane: np.ndarray) -> np.ndarray:
    b = plane.reshape(ROWS, COLS, 4)
    same = (b == b[..., :1]).all(axis=2)
    return np.where(same, b[..., 0].astype(np.int16), np.int16(-1))


def one(path: str):
    img = Image.open(path)
    rgb = np.asarray(img.convert("RGB").resize((224, 224), Image.BILINEAR))
    gray = np.asarray(img.convert("L").resize((224, 224), Image.BILINEAR))
    return np.stack([runs(rgb[..., c]) for c in range(3)]), runs(gray)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--variant", default="color", choices=["color", "segmented"])
    ap.add_argument("--workers", type=int, default=64)
    ap.add_argument("--test-frac", type=float, default=0.2)
    args = ap.parse_args()

    out = HERE / f"cache_{args.variant}"
    out.mkdir(exist_ok=True)
    classes = sorted(p.name for p in (ROOT / args.variant).iterdir() if p.is_dir())
    species = sorted({c.split("___")[0] for c in classes})
    paths, labels = [], []
    for i, cname in enumerate(classes):
        files = sorted(f for f in (ROOT / args.variant / cname).iterdir()
                       if f.suffix.lower() in (".jpg", ".jpeg", ".png"))
        paths += [str(f) for f in files]
        labels += [i] * len(files)
    labels = np.array(labels)
    n = len(paths)
    print(f"{n} images, {len(classes)} classes, {len(species)} species", flush=True)

    rng = np.random.default_rng(0)
    test = np.zeros(n, bool)
    for i in range(len(classes)):
        idx = np.flatnonzero(labels == i)
        test[rng.choice(idx, int(round(len(idx) * args.test_frac)), replace=False)] = True

    rgb_mm = np.lib.format.open_memmap(out / "rgb_runs.npy", "w+", np.int16, (n, 3, ROWS, COLS))
    gray_mm = np.lib.format.open_memmap(out / "gray_runs.npy", "w+", np.int16, (n, ROWS, COLS))
    t0 = time.time()
    with Pool(args.workers) as pool:
        for i, (r, g) in enumerate(pool.imap(one, paths, chunksize=32)):
            rgb_mm[i], gray_mm[i] = r, g
            if (i + 1) % 5000 == 0:
                print(f"  {i+1}/{n}  {time.time()-t0:.0f}s", flush=True)
    rgb_mm.flush(); gray_mm.flush()

    tr = ~test
    dens_rgb = np.zeros((3, 256), np.int64)
    dens_gray = np.zeros(256, np.int64)
    for s in range(0, n, 4096):
        sl = slice(s, min(s + 4096, n))
        m = tr[sl]
        r, g = rgb_mm[sl][m], gray_mm[sl][m]
        for c in range(3):
            v = r[:, c][r[:, c] >= 0]
            dens_rgb[c] += np.bincount(v, minlength=256)
        dens_gray += np.bincount(g[g >= 0], minlength=256)
    np.savez(out / "density.npz", rgb=dens_rgb, gray=dens_gray,
             blocks_per_plane=int(tr.sum()) * ROWS * COLS)

    sp_of = [species.index(c.split("___")[0]) for c in classes]
    json.dump({"variant": args.variant, "classes": classes, "species": species,
               "paths": paths, "labels": labels.tolist(),
               "species_labels": [sp_of[l] for l in labels],
               "test": test.tolist()}, open(out / "meta.json", "w"))
    print(f"done {time.time()-t0:.0f}s -> {out}", flush=True)


if __name__ == "__main__":
    main()
