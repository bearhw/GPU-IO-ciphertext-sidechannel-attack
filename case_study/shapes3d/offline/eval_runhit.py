#!/usr/bin/env python3
"""
eval_runhit.py — tables for the run*hit test capture (captures/test_runhit, 400).

  * localization: GT pages present after assembly, all planes (148) and per plane
  * classification top-1/2/3: RGB (Dict-16), R/G/B-only models, Dict-8 replay
  * single-channel accuracy by pages found in that plane

Needs attack_shapes_sim_v2{,_Ronly,_Gonly,_Bonly,_dict8}.pth (train_attack.py with
--keep-ch / --dict-k) and dictk_out/<capture>/ from dict_k_redecode.py --k 8.

  python3 eval_runhit.py [../captures/test_runhit]
"""
import csv
import json
import sys
from pathlib import Path

import numpy as np
import torch

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
from train_attack import ShapeNet, to_tensor  # noqa: E402

CL = ["cube", "cylinder", "sphere", "capsule"]
PLANE_BYTES = 224 * 224 * 4


def plane_pages(gt, off, ci):
    lo, hi = ci * PLANE_BYTES, (ci + 1) * PLANE_BYTES
    return {gt[k] for k in range(len(gt)) if k * 4096 - off < hi and (k + 1) * 4096 - off > lo}


def predict(ck, X):
    net = ShapeNet()
    net.load_state_dict(torch.load(HERE / ck, map_location="cpu"))
    net.eval()
    with torch.no_grad():
        lg = torch.cat([net(to_tensor(X[s:s + 100])) for s in range(0, len(X), 100)])
    return lg.argsort(1, descending=True).numpy()


def keep_planes(X, keep):
    X = X.copy()
    for j, ch in enumerate("RGB"):
        if ch not in keep:
            X[:, j] = 0
    return X


def pct(k, n):
    return f"{100 * k / n:.1f}% ({k})"


def main():
    d = Path(sys.argv[1]) if len(sys.argv) > 1 else HERE.parent / "captures" / "test_runhit"
    rows = {int(r["index"]): r for r in csv.DictReader(open(d / "summary.csv"))}
    idx = sorted(i for i in rows if (d / f"cmap_{i}.npy").exists())
    N = len(idx)
    y = np.array([CL.index(rows[i]["gt_class"]) for i in idx])
    X16 = np.stack([np.load(d / f"cmap_{i}.npy") for i in idx])

    tot, per = [], {ch: [] for ch in "RGB"}
    for i in idx:
        m, t = json.load(open(d / f"dump_{i}.json")), json.load(open(d / f"tracked_{i}.json"))
        asm = set(m["pages_int"])
        tot.append(m["gt_overlap"])
        for ci, ch in enumerate("RGB"):
            pg = plane_pages(t["gt_pages_int"], t["gt_base_off"], ci)
            per[ch].append((len(pg & asm), len(pg)))
    tot = np.array(tot)
    per = {ch: np.array(v) for ch, v in per.items()}

    print(f"== Pages found, all planes (148), n={N}")
    for th, lab in [(1, ">= 1 page"), (74, ">= 74"), (109, ">= 109"), (136, ">= 136"), (148, "All 148")]:
        print(f"  {lab:10s} {pct((tot >= th).sum(), N)}")
    print("== Pages found per plane (R | G | B)")
    for th, lab in [(1, ">= 1 page"), (25, ">= 25"), (36, ">= 36"), (45, ">= 45"), (None, "All pages")]:
        cells = [pct(((a[:, 0] == a[:, 1]) if th is None else (a[:, 0] >= th)).sum(), N) for a in per.values()]
        print(f"  {lab:10s} " + " | ".join(cells))

    print("== Classification top-1/2/3")
    models = [("RGB (Dict-16)", "attack_shapes_sim_v2.pth", X16)]
    models += [(f"{ch} only", f"attack_shapes_sim_v2_{ch}only.pth", keep_planes(X16, ch)) for ch in "RGB"]
    od = HERE / "dictk_out" / d.name
    if (od / f"cmap_{idx[0]}_d8.npy").exists():
        models.append(("RGB (Dict-8)", "attack_shapes_sim_v2_dict8.pth",
                       np.stack([np.load(od / f"cmap_{i}_d8.npy") for i in idx])))
    preds = {}
    for name, ck, X in models:
        if not (HERE / ck).exists():
            print(f"  {name:14s} missing {ck}")
            continue
        r = predict(ck, X)
        preds[name] = r[:, 0]
        tk = [100 * (r[:, :k] == y[:, None]).any(1).mean() for k in (1, 2, 3)]
        print(f"  {name:14s} {tk[0]:.1f}% / {tk[1]:.1f}% / {tk[2]:.1f}%")

    print("== Single-channel top-1 by pages found in that plane")
    bins = [(0, 0), (1, 24), (25, 35), (36, 44), (45, 50)]
    for ch in "RGB":
        if f"{ch} only" not in preds:
            continue
        ok, n = preds[f"{ch} only"] == y, per[ch][:, 0]
        cells = []
        for a, b in bins:
            s = (n >= a) & (n <= b)
            cells.append(f"{a}-{b}: {100 * ok[s].mean():.1f}% ({ok[s].sum()}/{s.sum()})")
        print(f"  {ch}  " + " | ".join(cells))


if __name__ == "__main__":
    main()
