#!/usr/bin/env python3
"""
eval_plaintext.py — plaintext baseline: the victim ResNet-18 classifying the images
directly (no side channel). Top-1/2/3 on the full test split (1,000) and on the
400 samples captured in captures/test_runhit (index s*250+k, k<100).

  python3 eval_plaintext.py [--capture ../captures/test_runhit]
"""
import argparse
import csv
import sys
from pathlib import Path

import numpy as np
import torch
import torch.nn as nn
from PIL import Image
from torchvision import models

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
sys.path.insert(0, str(ROOT / "victim"))
from train_victim import TF  # noqa: E402  identical preprocessing

CL = ["cube", "cylinder", "sphere", "capsule"]


def topk(r, y):
    return [100 * (r[:, :k] == y[:, None]).any(1).mean() for k in (1, 2, 3)]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--capture", default=str(ROOT / "captures" / "test_runhit"))
    ap.add_argument("--threads", type=int, default=8)
    a = ap.parse_args()
    torch.set_num_threads(a.threads)

    z = np.load(ROOT / "datasets" / "shapes3d_test.npz")
    X, y = z["images"], z["shape"].astype(int)

    net = models.resnet18(weights=None)
    net.fc = nn.Linear(net.fc.in_features, 4)
    net.load_state_dict(torch.load(ROOT / "victim" / "victim_resnet18.pth", map_location="cpu"))
    net.eval()
    with torch.no_grad():
        lg = torch.cat([net(torch.stack([TF(Image.fromarray(im)) for im in X[s:s + 50]]))
                        for s in range(0, len(X), 50)])
    r = lg.argsort(1, descending=True).numpy()

    sets = [("test (1000)", np.arange(len(y)))]
    cap = Path(a.capture) / "summary.csv"
    if cap.exists():
        rows = list(csv.DictReader(open(cap)))
        idx = np.array(sorted(int(row["index"]) for row in rows))
        gt = {int(row["index"]): row["gt_class"] for row in rows}
        assert all(CL[y[i]] == gt[i] for i in idx), "capture labels != test npz labels"
        sets.append((f"captured ({len(idx)})", idx))

    print("Plaintext ResNet-18 (victim), top-1 / top-2 / top-3")
    for name, ix in sets:
        t = topk(r[ix], y[ix])
        per = [100 * (r[ix, 0] == y[ix])[y[ix] == c].mean() for c in range(4)]
        print(f"  {name:15s} {t[0]:.1f}% / {t[1]:.1f}% / {t[2]:.1f}%   per-shape top-1 "
              + " ".join(f"{CL[c]} {per[c]:.1f}" for c in range(4)))


if __name__ == "__main__":
    main()
