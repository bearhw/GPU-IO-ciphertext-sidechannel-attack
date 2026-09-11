#!/usr/bin/env python3
"""
eval_confusion.py — 학습된 page-set 모델을 MURA valid 세트로 추론하고
confusion matrix 를 png/pdf 로 저장.

  python eval_confusion.py --ckpt pageset_64ref.pth

출력:
  pageset_confusion_matrix.png
  pageset_confusion_matrix.pdf
  (+ per-class precision/recall/F1 을 표준출력에)
"""
import argparse
from pathlib import Path

import numpy as np
import torch
from torch.utils.data import DataLoader

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

from train_pageset import (  # noqa: E402
    BlockDataset, PageSetNet, collect_labels, CACHE, CLASSES, N_REF,
)

HERE = Path(__file__).parent


def plot_cm(cm, classes, out_stem, title, subtitle):
    n = len(classes)
    cm_norm = cm / np.maximum(cm.sum(axis=1, keepdims=True), 1)

    fig, ax = plt.subplots(figsize=(1.15 * n + 3.2, 1.15 * n + 2.6))
    im = ax.imshow(cm_norm, cmap="Blues", vmin=0, vmax=1)

    ax.set_xticks(range(n)); ax.set_yticks(range(n))
    ax.set_xticklabels(classes, rotation=45, ha="right", fontsize=12)
    ax.set_yticklabels(classes, fontsize=12)
    ax.set_xlabel("Predicted", fontsize=14)
    ax.set_ylabel("True", fontsize=14)
    ax.set_title(title, fontsize=16, fontweight="bold", pad=14)
    if subtitle:
        ax.text(0.5, 1.015, subtitle, transform=ax.transAxes,
                ha="center", va="bottom", fontsize=11, color="#555")

    for i in range(n):
        for j in range(n):
            v = cm_norm[i, j]
            ax.text(j, i, f"{cm[i, j]}\n{v*100:.0f}%", ha="center", va="center",
                    fontsize=10, color="white" if v > 0.5 else "#222")

    cb = fig.colorbar(im, ax=ax, fraction=0.046, pad=0.04)
    cb.set_label("row-normalized", fontsize=11)
    fig.tight_layout()

    for ext in ("png", "pdf"):
        p = f"{out_stem}.{ext}"
        fig.savefig(p, dpi=200 if ext == "png" else None, bbox_inches="tight")
        print(f"saved: {p}")
    plt.close(fig)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--ckpt", type=Path, default=HERE / "pageset_64ref.pth")
    ap.add_argument("--batch", type=int, default=16)
    ap.add_argument("--workers", type=int, default=4)
    ap.add_argument("--limit", type=int, default=None, help="valid 샘플 수 제한")
    ap.add_argument("--layouts", type=Path, default=HERE / "layouts.npz")
    ap.add_argument("--out", type=str, default=str(HERE / "pageset_confusion_matrix"))
    args = ap.parse_args()

    if not args.ckpt.exists():
        raise SystemExit(f"{args.ckpt} 없음 — train_pageset.py 를 먼저 돌려라.")

    dev = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    ck = torch.load(args.ckpt, map_location=dev, weights_only=False)
    chunk_pool = ck.get("chunk_pool", 4)
    dim = ck.get("dim", 192)
    recency = ck.get("recency", False)
    n_in = ck.get("n_in", N_REF)
    print(f"device={dev}  ckpt val_acc={ck.get('val_acc', float('nan')):.4f}  "
          f"chunk_pool={chunk_pool}  dim={dim}", flush=True)

    layouts = np.load(args.layouts)["slots"]
    va_s = np.lib.format.open_memmap(CACHE / "va_slices.npy", mode="r")
    va_a = np.load(CACHE / "va_aspects.npy")
    va_y = collect_labels("valid")
    assert len(va_y) == va_s.shape[0], "캐시와 라벨 개수 불일치"

    comp = None
    if ck.get("use_comp", False):
        c = np.load(HERE / "composition.npz")
        comp = {"same_slots": c["same_slots"], "other_slots": c["other_slots"]}
    ds = BlockDataset(va_s, va_a, va_y, layouts, chunk_pool=chunk_pool, train=False,
                      comp=comp, recency=recency)
    idx = np.arange(len(va_y))
    if args.limit:
        idx = np.random.default_rng(1).choice(idx, size=min(args.limit, len(idx)),
                                              replace=False)
    ds = torch.utils.data.Subset(ds, idx.tolist())
    ld = DataLoader(ds, batch_size=args.batch, shuffle=False, num_workers=args.workers)

    model = PageSetNet(len(CLASSES), n_in, dim=dim).to(dev)
    model.load_state_dict(ck["model"])
    model.eval()

    ys, ps = [], []
    with torch.no_grad():
        for x, a, y in ld:
            out = model(x.to(dev), a.to(dev))
            ps.append(out.argmax(1).cpu().numpy())
            ys.append(y.numpy())
    y_true = np.concatenate(ys)
    y_pred = np.concatenate(ps)

    n = len(CLASSES)
    cm = np.zeros((n, n), dtype=int)
    for t, p in zip(y_true, y_pred):
        cm[t, p] += 1
    acc = (y_true == y_pred).mean()

    print(f"\naccuracy = {acc:.4f}  ({(y_true == y_pred).sum()}/{len(y_true)})\n")
    print(f"{'class':<10}{'prec':>8}{'recall':>8}{'f1':>8}{'n':>7}")
    for i, c in enumerate(CLASSES):
        tp = cm[i, i]
        prec = tp / max(cm[:, i].sum(), 1)
        rec = tp / max(cm[i, :].sum(), 1)
        f1 = 2 * prec * rec / max(prec + rec, 1e-9)
        print(f"{c:<10}{prec:>8.3f}{rec:>8.3f}{f1:>8.3f}{cm[i].sum():>7}")

    plot_cm(cm, CLASSES, args.out,
            "MURA body-part from a 2 MB block (page-set model)",
            f"accuracy {acc*100:.1f}%  ·  n={len(y_true)}  ·  "
            f"permutation-invariant over 512 pages")


if __name__ == "__main__":
    main()
