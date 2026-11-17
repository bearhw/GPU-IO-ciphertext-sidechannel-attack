#!/usr/bin/env python3
"""
select_dict.py — choose the 3DShapes dictionary: top-K 4-pixel tuples per channel.

Victim preprocessing (same as MURA): Resize((224,224), bilinear) -> ToTensor ->
Normalize(ImageNet). A 16 B block is 4 consecutive float32 pixels of one channel
plane. Normalize is a per-channel bijection on uint8, so a block is identified by
its channel and 4 uint8 pixels. Keywords are ranked by block frequency over a
sample of train_pool images; Dict-K keeps the top-K of each channel (3K refs).

Each keyword's ICMP chunk is the exact float32 bytes the victim writes, computed
with the same float32 op order as torchvision (u8/255, then (x-mean)/std).

Outputs dict_keywords.json and prints test coverage per channel for several K.

  python3 select_dict.py [--k 16] [--n-train 20000]
"""
import argparse
import json
from pathlib import Path

import h5py
import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
H5 = Path("/home/eun/datasets_ext/3dshapes/3dshapes.h5")
CH = ("R", "G", "B")
MEAN = {"R": 0.485, "G": 0.456, "B": 0.406}
STD = {"R": 0.229, "G": 0.224, "B": 0.225}


def to224(imgs: np.ndarray) -> np.ndarray:
    return np.stack([np.asarray(Image.fromarray(x).resize((224, 224), Image.BILINEAR)) for x in imgs])


def codes(imgs224: np.ndarray) -> np.ndarray:
    """(N,224,224,3) uint8 -> (N,3,224,56) uint32 block codes (4 pixels per block)."""
    b = imgs224.transpose(0, 3, 1, 2).reshape(len(imgs224), 3, 224, 56, 4).astype(np.uint32)
    return b[..., 0] | b[..., 1] << 8 | b[..., 2] << 16 | b[..., 3] << 24


def norm_f32(u8: np.ndarray, ch: str) -> np.ndarray:
    return ((u8.astype(np.float32) / np.float32(255) - np.float32(MEAN[ch])) / np.float32(STD[ch])).astype(np.float32)


def chunk_bytes(code: int, ch: str) -> bytes:
    px = np.array([(code >> (8 * i)) & 0xFF for i in range(4)], dtype=np.uint8)
    return norm_f32(px, ch).view(np.uint8).tobytes()


def load(idx):
    f = h5py.File(H5, "r")["images"]
    idx = np.sort(np.asarray(idx))
    out = []
    for s in range(0, len(idx), 2000):
        out.append(to224(f[idx[s:s + 2000]]))
    return np.concatenate(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--k", type=int, default=16)
    ap.add_argument("--n-train", type=int, default=20000)
    a = ap.parse_args()

    split = json.loads((HERE / "split.json").read_text())
    rng = np.random.default_rng(1)
    tr_idx = rng.choice(split["train_pool"], a.n_train, replace=False)
    ctr = codes(load(tr_idx))
    cte = codes(load(split["test"]))

    kw = {}
    print(f"train sample {len(ctr)}, test {len(cte)}")
    print("K      " + "  ".join(f"{c:>6}" for c in CH) + "   (test coverage %)")
    tops = {}
    for ci, ch in enumerate(CH):
        u, n = np.unique(ctr[:, ci].ravel(), return_counts=True)
        tops[ch] = u[np.argsort(-n)]
    for K in (1, 4, 8, 16, 32, 64):
        cov = [100 * np.isin(cte[:, ci], tops[ch][:K]).mean() for ci, ch in enumerate(CH)]
        print(f"{K:<6} " + "  ".join(f"{v:6.1f}" for v in cov))

    for ch in CH:
        kw[ch] = [{"rank": r, "code": int(code),
                   "pixels": [(int(code) >> (8 * i)) & 0xFF for i in range(4)],
                   "chunk_hex": chunk_bytes(int(code), ch).hex()}
                  for r, code in enumerate(tops[ch][:a.k])]
    out = HERE / "dict_keywords.json"
    out.write_text(json.dumps({"k": a.k, "channels": kw}, indent=1))
    print(f"-> {out} ({3 * a.k} refs)")


if __name__ == "__main__":
    main()
