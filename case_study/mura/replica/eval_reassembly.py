#!/usr/bin/env python3
"""
eval_reassembly.py — Final evaluation + confusion matrix for write-order reassembly attack.

Attack Procedure:
  1. Slice contiguous 49-write bursts from host write trace
     (90% of channels appear consecutively with 0 external writes)
  2. Concatenate pages in their appearance order — ignoring physical addresses
     (Physical contiguity is only 29%, but temporal contiguity is 90%)
  3. That order matches logical order: forward 75% / reverse 24%.
     If reversed, the assembled tensor is inverted and must be un-reversed.
  4. Reassemble into (224, 56) grid and classify

Evaluation Design (Important):
  --sim-reverse-rate creates 'actually reverse-assembled observations' at empirical rate (24%).
  This allows fair measurement of the gains and losses of direction handling. Without this,
  all samples would be forward and any direction search would only appear detrimental.

Comparison Modes:
  --order none       No direction handling (reverse samples classified as-is)
  --order oracle     Assume ground truth direction is known (upper bound)
  --order softmax    Select candidate with higher max-softmax (inappropriate empirically)
  --order model      Decide using direction discriminator (requires --direction-ckpt)
"""
import argparse
from pathlib import Path

import numpy as np
import torch
from torch.utils.data import DataLoader, Subset

from reassembly_common import (
    CLASSES, N_REF, ReassemblyDataset, XorSliceResNet,
    load_cache, train_aspect_prior, plot_cm, HERE,
)


def predict(model, loader, dev):
    """(probs, labels, kept_page_ratio, is_reverse)."""
    probs, ys, kfs, rs = [], [], [], []
    model.eval()
    with torch.no_grad():
        for x, sc, y, k, r in loader:
            p = torch.softmax(model(x.to(dev), sc.to(dev)), dim=1)
            probs.append(p.cpu()); ys.append(y); kfs.append(k); rs.append(r)
    return (torch.cat(probs), torch.cat(ys).numpy(),
            torch.cat(kfs).numpy(), torch.cat(rs).numpy())


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--ckpt", type=Path, required=True)
    ap.add_argument("--direction-ckpt", type=Path)
    ap.add_argument("--order", choices=["none", "oracle", "softmax", "model"],
                    default="none")
    ap.add_argument("--sim-reverse-rate", type=float, default=0.24,
                    help="Simulated reverse assembly rate (empirical 24%%)")
    ap.add_argument("--layouts", type=Path, default=HERE / "layouts.npz")
    ap.add_argument("--batch", type=int, default=64)
    ap.add_argument("--workers", type=int, default=1)
    ap.add_argument("--limit", type=int, default=None)
    ap.add_argument("--no-degrade", action="store_true", help="Without degradation (upper bound)")
    ap.add_argument("--out", type=str,
                    default=str(HERE / "reassembly_confusion_matrix"))
    args = ap.parse_args()

    dev = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    model = XorSliceResNet(len(CLASSES), N_REF).to(dev)
    sd = torch.load(args.ckpt, map_location=dev, weights_only=False)
    model.load_state_dict(sd["model"] if isinstance(sd, dict) and "model" in sd else sd)

    layouts = np.load(args.layouts)["slots"]
    prior = train_aspect_prior()
    va_s, va_y = load_cache("valid")
    degrade = not args.no_degrade
    print(f"device={dev}  ckpt={args.ckpt.name}  order={args.order}  "
          f"sim_reverse={args.sim_reverse_rate:.2f}  degradation={'on' if degrade else 'off'}",
          flush=True)

    idx = np.arange(len(va_y))
    if args.limit:
        idx = np.random.default_rng(1).choice(idx, size=min(args.limit, len(idx)),
                                              replace=False)

    def loader(undo):
        ds = ReassemblyDataset(va_s, va_y, layouts, train=False, aspect_prior=prior,
                               degrade=degrade,
                               sim_reverse_rate=args.sim_reverse_rate, undo=undo)
        return DataLoader(Subset(ds, idx.tolist()), batch_size=args.batch,
                          shuffle=False, num_workers=args.workers)

    # Classified as-is / classified after flipping (same seed -> identical degradation & reversal status)
    p_as, y_true, kf, is_rev = predict(model, loader(False), dev)
    p_un, _, _, _ = predict(model, loader(True), dev)

    if args.order == "none":
        use_undo = torch.zeros(len(y_true), dtype=torch.bool)
    elif args.order == "oracle":
        use_undo = torch.from_numpy(is_rev.astype(bool))
    elif args.order == "softmax":
        use_undo = p_un.max(1).values > p_as.max(1).values
    else:
        if not args.direction_ckpt:
            raise SystemExit("--order model requires --direction-ckpt")
        dm = XorSliceResNet(2, N_REF).to(dev)
        dsd = torch.load(args.direction_ckpt, map_location=dev, weights_only=False)
        dm.load_state_dict(dsd["model"] if isinstance(dsd, dict) and "model" in dsd
                           else dsd)
        dprob, _, _, _ = predict(dm, loader(False), dev)
        use_undo = dprob.argmax(1) == 1
        da = (use_undo.numpy() == is_rev.astype(bool)).mean()
        print(f"Direction discriminator {args.direction_ckpt.name}: "
              f"evaluation set direction accuracy {da:.4f}", flush=True)

    pred = torch.where(use_undo, p_un.argmax(1), p_as.argmax(1)).numpy()

    n = len(CLASSES)
    cm = np.zeros((n, n), dtype=int)
    for t_, p_ in zip(y_true, pred):
        cm[t_, p_] += 1
    acc = (y_true == pred).mean()
    bal = float(np.mean([cm[i, i] / max(cm[i].sum(), 1) for i in range(n)]))

    print(f"\naccuracy = {acc:.4f}  balanced = {bal:.4f}  "
          f"({(y_true == pred).sum()}/{len(y_true)})")
    print(f"Mean recovered pages = {kf.mean()*49:.1f}/49 ({kf.mean()*100:.0f}%)")
    print(f"Actual reverse = {is_rev.sum()}/{len(is_rev)} ({100*is_rev.mean():.0f}%)  "
          f"| Flip back applied = {int(use_undo.sum())} ({100*float(use_undo.float().mean()):.0f}%)")
    print()
    print(f"{'class':<10}{'prec':>8}{'recall':>8}{'f1':>8}{'n':>7}")
    for i, c in enumerate(CLASSES):
        tp = cm[i, i]
        pr_ = tp / max(cm[:, i].sum(), 1)
        rc = tp / max(cm[i].sum(), 1)
        f1 = 2 * pr_ * rc / max(pr_ + rc, 1e-9)
        print(f"{c:<10}{pr_:>8.3f}{rc:>8.3f}{f1:>8.3f}{cm[i].sum():>7}")

    plot_cm(cm, CLASSES, args.out,
            "MURA body-part via write-order page reassembly",
            f"accuracy {acc*100:.1f}%  ·  balanced {bal*100:.1f}%  ·  "
            f"pages {kf.mean()*100:.0f}%  ·  order={args.order}  ·  n={len(y_true)}")


if __name__ == "__main__":
    main()
