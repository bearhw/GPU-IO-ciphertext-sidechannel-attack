#!/usr/bin/env python3
"""
color_ciphermap.py — Ideal-case Challenge-3 cipher maps for simple color datasets.

Same victim preprocessing as MURA: Resize((224,224)) -> ToTensor -> per-channel
Normalize -> (3,224,224) float32. A 16-byte block is 4 consecutive pixels of one
channel plane; Normalize is a per-channel bijection on uint8, so a block is
identified by its 4 uint8 pixels. In the ideal case the tensor alignment is known,
so any 4-pixel tuple (identical or not) can be a keyword.

Keywords are ranked per channel by frequency over the train split; Dict-K is the
top-K of each channel. Prints coverage and writes a figure of R/G/B cipher maps.

  python3 color_ciphermap.py retina|derma|blood|3dshapes|fruits360
"""

import json
import sys
from multiprocessing import Pool
from pathlib import Path

import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
EXT = Path("/home/eun/datasets_ext")
KS = [1, 16, 32, 64, 1024]
VIS_KS = [1, 16, 32, 64]


def to224(a: np.ndarray) -> np.ndarray:
    if a.shape[1:3] == (224, 224):
        return a
    return np.stack([np.asarray(Image.fromarray(x).resize((224, 224), Image.BILINEAR)) for x in a])


def load(name: str):
    if name in ("retina", "derma", "blood"):
        z = np.load(EXT / "medmnist" / f"{name}mnist_224.npz")
        return z["train_images"], z["test_images"], z["test_labels"].ravel()
    if name == "3dshapes":
        import h5py
        f = h5py.File(EXT / "3dshapes" / "3dshapes.h5", "r")
        rng = np.random.default_rng(0)
        idx = np.sort(rng.choice(len(f["images"]), 12000, replace=False))
        imgs = f["images"][idx]
        shape = f["labels"][idx][:, 4].astype(int)    # object shape factor
        return to224(imgs[:10000]), to224(imgs[10000:]), shape[10000:]
    if name == "fruits360":
        root = EXT / "fruits360"
        classes = sorted(p.name for p in (root / "Training").iterdir())

        def split(sub):
            files = [(f, i) for i, c in enumerate(classes) for f in sorted((root / sub / c).iterdir())]
            with Pool(64) as pool:
                imgs = np.stack(pool.map(_read224, [str(f) for f, _ in files], chunksize=64))
            return imgs, np.array([i for _, i in files])
        tr, _ = split("Training")
        te, te_lab = split("Test")
        return tr, te, te_lab
    raise SystemExit(f"unknown dataset {name}")


def _read224(path: str) -> np.ndarray:
    return np.asarray(Image.open(path).convert("RGB").resize((224, 224), Image.BILINEAR))


def codes(imgs: np.ndarray) -> np.ndarray:
    b = imgs.transpose(0, 3, 1, 2).reshape(len(imgs), 3, 224, 56, 4).astype(np.uint32)
    return b[..., 0] | b[..., 1] << 8 | b[..., 2] << 16 | b[..., 3] << 24


def main():
    name = sys.argv[1]
    tr, te, te_lab = load(name)
    tr, te = to224(tr), to224(te)
    ctr, cte = codes(tr), codes(te)
    print(f"{name}: train {len(tr)}, test {len(te)}")

    top, rows = [], {}
    for c, ch in enumerate("RGB"):
        u, cnt = np.unique(ctr[:, c].ravel(), return_counts=True)
        o = np.argsort(-cnt, kind="stable")
        top.append(u[o[:max(KS)]])
        for K in KS:
            rows.setdefault(K, []).append(np.isin(cte[:, c], top[c][:K]).mean() * 100)
        print(f"  {ch}: {len(u)} distinct tuples; top5 "
              f"{[tuple(int(x >> s & 255) for s in (0, 8, 16, 24)) for x in u[o[:5]]]}")
    print("  test coverage (R / G / B):")
    for K in KS:
        print(f"    Dict-{K:<5d} " + " / ".join(f"{v:5.2f}%" for v in rows[K]))
    json.dump({"dataset": name, "coverage_test": {K: rows[K] for K in KS}},
              open(HERE / f"coverage_{name}.json", "w"), indent=1)

    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    labs = np.unique(te_lab)
    labs = labs[np.linspace(0, len(labs) - 1, min(6, len(labs))).round().astype(int)]
    pick = [np.flatnonzero(te_lab == l)[0] for l in labs]
    fig, ax = plt.subplots(len(pick), 1 + 2 * len(VIS_KS),
                           figsize=(2.0 * (1 + 2 * len(VIS_KS)), 2.1 * len(pick)), squeeze=False)
    for r, i in enumerate(pick):
        ax[r, 0].imshow(te[i]); ax[r, 0].set_ylabel(f"label {te_lab[i]}", fontsize=7)
        for k, K in enumerate(VIS_KS):
            mask = np.zeros((224, 224, 3), np.uint8)
            vals = np.full((224, 224, 3), 128, np.uint8)
            hits = []
            for c in range(3):
                h = np.repeat(np.isin(cte[i, c], top[c][:K]), 4, axis=1)
                hits.append(h.mean() * 100)
                mask[..., c] = h * 255
                vals[..., c] = np.where(h, te[i][..., c], 128)
            ax[r, 1 + k].imshow(mask, interpolation="nearest")
            ax[r, 1 + k].set_xlabel("R{:.0f} G{:.0f} B{:.0f}%".format(*hits), fontsize=7)
            ax[r, 1 + len(VIS_KS) + k].imshow(vals, interpolation="nearest")
    titles = ["input"] + [f"map Dict-{K}" for K in VIS_KS] + [f"values Dict-{K}" for K in VIS_KS]
    for a, t in zip(ax[0], titles):
        a.set_title(t, fontsize=8)
    for a in ax.flat:
        a.set_xticks([]); a.set_yticks([])
    plt.suptitle(f"{name}: per-channel cipher map, top-K 4-pixel keywords per channel "
                 "(map: hit planes as RGB; values: plaintext of hit blocks, miss=gray)", fontsize=9)
    plt.tight_layout()
    (HERE / "figures").mkdir(exist_ok=True)
    plt.savefig(HERE / "figures" / f"{name}_ciphermap.png", dpi=90)


if __name__ == "__main__":
    main()
