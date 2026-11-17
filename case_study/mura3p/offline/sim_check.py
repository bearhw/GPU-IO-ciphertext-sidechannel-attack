#!/usr/bin/env python3
"""
sim_check.py — ceiling of the mura3p decode path on plaintext: victim preprocessing
-> per-plane level map (exact chunk match against the 64 levels) -> fusion ->
MURA classifier. Equal to the real capture when localisation is perfect, since
captured maps match simulation byte for byte (shapes3d finding).

  python3 sim_check.py --n 350
"""
import argparse
import sys
from pathlib import Path

import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "pipeline"))
import common as c
import stage45_classify as s45

ROOT = Path("/home/eun/bnb/mura")
MEAN = np.array([0.485, 0.456, 0.406], np.float32)
STD = np.array([0.229, 0.224, 0.225], np.float32)


def sim_map(path, levels):
    img = Image.open(path).convert("RGB").resize((224, 224), Image.BILINEAR)
    x = ((np.asarray(img).astype(np.float32) / np.float32(255) - MEAN) / STD).astype(np.float32)
    x = x.transpose(2, 0, 1).reshape(3, 224, 56, 4)
    m = np.full((3, 224, 56), -1, np.int16)
    for p in range(3):
        uni = (x[p] == x[p][..., :1]).all(-1)
        for k, u8 in enumerate(levels):
            v = (np.float32(u8) / np.float32(255) - MEAN[p]) / STD[p]
            m[p][uni & (x[p][..., 0] == v) & (m[p] < 0)] = k
    return m


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--n", type=int, default=350)
    a = ap.parse_args()
    import json
    levels = json.load(open(HERE / "dict_keywords.json"))["levels"]
    paths = [l.strip() for l in open(ROOT / "mura_downloads" / "valid_image_paths.csv") if l.strip()]
    rng = np.random.default_rng(0)
    idx = rng.choice(len(paths), a.n, replace=False)
    ok = okr = 0
    for j, i in enumerate(idx):
        rel = paths[i]
        cls = rel.split("/")[2].replace("XR_", "")
        m = sim_map(ROOT / rel.replace("MURA-v1.1", "mura_downloads"), levels)
        same = all((m[0] == m[p]).all() for p in (1, 2))
        ok += c.CLASSES[int(s45.classify(s45.fuse(m)).argmax())] == cls
        okr += c.CLASSES[int(s45.classify(s45.fuse(m, (0,))).argmax())] == cls
        if j < 3:
            print(i, cls, "planes identical:", same, "cov", round(float((m[0] >= 0).mean()), 3))
    print(f"n {a.n}  fused top-1 {100 * ok / a.n:.1f}%  R-only {100 * okr / a.n:.1f}%")


if __name__ == "__main__":
    main()
