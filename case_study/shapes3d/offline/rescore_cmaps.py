#!/usr/bin/env python3
"""
rescore_cmaps.py — classify the cipher maps Stage 4 saved (cmap_<i>.npy) with
another attack checkpoint. Localisation and assembly are exactly the capture's;
only the classifier changes.

  python3 rescore_cmaps.py ../captures/test_blind attack_shapes_sim.pth attack_shapes_sim_v2.pth
"""
import csv
import sys
from pathlib import Path

import numpy as np
import torch

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
from train_attack import ShapeNet, to_tensor

CLASSES = ["cube", "cylinder", "sphere", "capsule"]


def main():
    d = Path(sys.argv[1])
    last = {}
    for r in csv.DictReader(open(d / "summary.csv")):
        last[int(r["index"])] = r
    idx = sorted(i for i in last if (d / f"cmap_{i}.npy").exists())
    X = np.stack([np.load(d / f"cmap_{i}.npy") for i in idx])
    y = np.array([CLASSES.index(last[i]["gt_class"]) for i in idx])
    lost = np.array([last[i]["gt_overlap"] == "0" for i in idx])
    for ck in sys.argv[2:]:
        net = ShapeNet()
        net.load_state_dict(torch.load(HERE / ck, map_location="cpu"))
        net.eval()
        with torch.no_grad():
            p = torch.cat([net(to_tensor(X[s:s + 100])).argmax(1) for s in range(0, len(X), 100)]).numpy()
        cm = np.zeros((4, 4), int)
        for a, b in zip(y, p):
            cm[a, b] += 1
        print(f"{ck}: top-1 {100 * (p == y).mean():.1f}% ({(p == y).sum()}/{len(y)})  "
              f"localised-only {100 * (p == y)[~lost].mean():.1f}% (n={(~lost).sum()})")
        print("  per shape " + "  ".join(f"{c} {100 * cm[k, k] / cm[k].sum():.1f}%" for k, c in enumerate(CLASSES)))
        print("  confusion " + str(cm.tolist()))


if __name__ == "__main__":
    main()
