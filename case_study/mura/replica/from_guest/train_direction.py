#!/usr/bin/env python3
"""
train_direction.py — Reassembly direction (forward/reverse) discriminator.

Why it is needed:
  The attacker does not know whether an array assembled in write-order matches
  logical order (forward 75%) or is inverted (reverse 24%).
  Feeding both candidates into the classifier and selecting via max-softmax
  proved detrimental in empirical tests:
      clean model      66.91% -> 58.18%  (selected reverse 33%, actual 24%)
      fine-tune model  80.11% -> 74.35%  (selected reverse 19%, actual 24%)
  Max-softmax is inappropriate as a direction decision criterion.
  Therefore, a dedicated binary classifier is trained specifically for direction.

What it learns:
  Input : Reassembled (64, 224, 56) — with empirical degradations applied
  Label : 0 = Forward, 1 = Reverse (assembled with reversed page sequence)
  Note  : Page reversal is NOT 'vertical image flip'. It is a block reversal
          at 4096-byte (~4.57 pixel rows) granularity while intra-page row
          order is preserved. This artifact serves as a distinctive signature.

Output: direction_64ref.pth
"""
import argparse
import time
from pathlib import Path

import numpy as np
import torch
import torch.nn as nn
from torch.utils.data import Dataset, DataLoader, Subset

from reassembly_common import (
    N_REF, CH_PAGES, XOR_ROWS, XOR_COLS, CHUNKS_PER_PAGE,
    XorSliceResNet, load_cache, train_aspect_prior, HERE,
)


class DirectionDataset(Dataset):
    """Train direction discrimination by generating both forward/reverse labels for each image."""

    def __init__(self, slices_mm, layouts, *, train=True, aspect_prior=1.339,
                 degrade=True, seed=0):
        self.slices = slices_mm
        self.layouts = layouts
        self.train = train
        self.aspect_prior = float(aspect_prior)
        self.degrade = degrade
        self.rng = np.random.default_rng(seed)

    def __len__(self):
        return self.slices.shape[0]

    def __getitem__(self, idx):
        rng = self.rng if self.train else np.random.default_rng(idx)

        sl = np.asarray(self.slices[idx])
        pages = sl.reshape(N_REF, CH_PAGES, CHUNKS_PER_PAGE)

        keep = np.ones(CH_PAGES, dtype=bool)
        if self.degrade:
            lay = self.layouts[rng.integers(len(self.layouts))]
            keep &= (lay >= 0)
            if rng.random() < 0.5:
                keep &= (rng.random(CH_PAGES) < rng.uniform(0.49, 1.0))
        rec = np.where(keep[None, :, None], pages, False)

        y = int(rng.integers(2))          # 0=forward, 1=reverse
        if y == 1:
            rec = rec[:, ::-1, :]

        x = np.ascontiguousarray(rec.reshape(N_REF, XOR_ROWS, XOR_COLS),
                                 dtype=np.float32)
        return (torch.from_numpy(x),
                torch.tensor([self.aspect_prior], dtype=torch.float32),
                y)


def evaluate(model, loader, dev):
    model.eval()
    corr = tot = 0
    with torch.no_grad():
        for x, sc, y in loader:
            p = model(x.to(dev), sc.to(dev)).argmax(1).cpu()
            corr += (p == y).sum().item(); tot += y.numel()
    return corr / max(tot, 1)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--init", type=Path,
                    help="Initialize backbone from body-part checkpoint (excluding head)")
    ap.add_argument("--epochs", type=int, default=8)
    ap.add_argument("--batch", type=int, default=32)
    ap.add_argument("--lr", type=float, default=2e-4)
    ap.add_argument("--weight-decay", type=float, default=1e-4)
    ap.add_argument("--limit-train", type=int, default=None)
    ap.add_argument("--limit-val", type=int, default=None)
    ap.add_argument("--workers", type=int, default=1)
    ap.add_argument("--layouts", type=Path, default=HERE / "layouts.npz")
    ap.add_argument("--out", type=Path, default=HERE / "direction_64ref.pth")
    args = ap.parse_args()

    dev = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    layouts = np.load(args.layouts)["slots"]
    prior = train_aspect_prior()
    print(f"device={dev}  empirical layouts={len(layouts)}  aspect prior={prior:.3f}",
          flush=True)

    tr_s, _ = load_cache("train")
    va_s, _ = load_cache("valid")
    tr_ds = DirectionDataset(tr_s, layouts, train=True, aspect_prior=prior)
    va_ds = DirectionDataset(va_s, layouts, train=False, aspect_prior=prior)

    tr_idx = np.arange(tr_s.shape[0]); va_idx = np.arange(va_s.shape[0])
    if args.limit_train:
        tr_idx = np.random.default_rng(0).choice(
            tr_idx, size=min(args.limit_train, len(tr_idx)), replace=False)
    if args.limit_val:
        va_idx = np.random.default_rng(1).choice(
            va_idx, size=min(args.limit_val, len(va_idx)), replace=False)
    tr_ds, va_ds = Subset(tr_ds, tr_idx.tolist()), Subset(va_ds, va_idx.tolist())
    print(f"train {len(tr_ds):,}  valid {len(va_ds):,}", flush=True)

    tr_ld = DataLoader(tr_ds, batch_size=args.batch, shuffle=True,
                       num_workers=args.workers, pin_memory=(dev.type == "cuda"))
    va_ld = DataLoader(va_ds, batch_size=args.batch, shuffle=False,
                       num_workers=args.workers, pin_memory=(dev.type == "cuda"))

    model = XorSliceResNet(2, N_REF).to(dev)       # 2-class: forward / reverse
    if args.init:
        sd = torch.load(args.init, map_location=dev, weights_only=False)
        sd = sd["model"] if isinstance(sd, dict) and "model" in sd else sd
        sd = {k: v for k, v in sd.items() if not k.startswith("head.")}
        missing, unexpected = model.load_state_dict(sd, strict=False)
        print(f"init backbone from {args.init.name} "
              f"(training head from scratch, missing={len(missing)})", flush=True)
    print(f"params={sum(p.numel() for p in model.parameters()):,}", flush=True)

    opt = torch.optim.AdamW(model.parameters(), lr=args.lr,
                            weight_decay=args.weight_decay)
    sched = torch.optim.lr_scheduler.CosineAnnealingLR(opt, T_max=args.epochs)
    crit = nn.CrossEntropyLoss()

    best = 0.0
    for ep in range(1, args.epochs + 1):
        model.train()
        t0, tot, corr, ls = time.time(), 0, 0, 0.0
        for x, sc, y in tr_ld:
            x, sc, y = x.to(dev), sc.to(dev), y.to(dev)
            opt.zero_grad()
            out = model(x, sc)
            loss = crit(out, y)
            loss.backward(); opt.step()
            ls += loss.item() * y.size(0)
            corr += (out.argmax(1) == y).sum().item(); tot += y.size(0)
        acc = evaluate(model, va_ld, dev)
        sched.step()
        flag = ""
        if acc > best:
            best = acc
            torch.save({"model": model.state_dict(), "n_ref": N_REF,
                        "aspect_prior": prior, "val_acc": best}, args.out)
            flag = "  *saved"
        print(f"ep{ep:>3}  loss {ls/max(tot,1):.4f}  train {corr/max(tot,1):.4f}  "
              f"val {acc:.4f}  {time.time()-t0:.0f}s{flag}", flush=True)

    print(f"\nbest direction acc = {best:.4f} → {args.out}")


if __name__ == "__main__":
    main()
