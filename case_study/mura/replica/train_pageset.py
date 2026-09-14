#!/usr/bin/env python3
"""
train_pageset.py — Train permutation-invariant (page-set) classifier operating directly on entire 2MB blocks.

Differences from previous model:
  Previous: (64, 224, 56) — Clean input where 49 channel pages are arranged in logical order.
            An attacker cannot create this because they don't know where or in what order pages were placed.
  This model: (64, 512, C) — Takes all 512 pages of the 2MB block as a 'set'.
              Independent of page order, image start offset, or interleaved contaminant pages.
              Completely eliminates preprocessing (offset search / channel separation / content probe).

Input assembly (on-the-fly):
  1. Reinterpret existing (64, 224, 56) bool slices in xor_cache_64 as (64, 49, 256)
     (12544 chunks = 49 pages * 256 chunks per page)
  2. Sample 'actual physical layouts' extracted by extract_layouts.py and scatter 49 pages into 512 slots
  3. Fill remaining slots with contaminant pages. Measurement-based mixture:
       - Zero pages: REF_U8_64[0]==0, so all chunks match ref-0.
         (Freshly allocated pages; key confound that resembles true background pixels)
       - High-entropy pages: Activations/weights; match no ref -> all zeros
       - Pages from other images: Measured that 5-10 images share and rotate through the same block

Output:
  pageset_64ref.pth  (best val acc)
"""
import argparse
import glob
import os
import time
from pathlib import Path

import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import Dataset, DataLoader

HERE = Path(__file__).parent
CACHE = Path(os.environ.get("MURA_CACHE",
                            "/home/eun/open-science/case_study/mura/xor_cache_64"))
DATA_ROOT = Path(os.environ.get("MURA_DATA",
                                "/home/eun/bnb/mura/mura_downloads"))
CLASSES = ["ELBOW", "FINGER", "FOREARM", "HAND", "HUMERUS", "SHOULDER", "WRIST"]

N_REF = 64
CH_PAGES = 49          # Number of pages occupied by one image channel
SLOTS = 512            # 2MB / 4KB
CHUNKS_PER_PAGE = 256  # 4096 / 16


def collect_labels(split):
    """Matches glob order when creating xor_cache_64 -> 1:1 correspondence with cache index."""
    labels = []
    for i, cls in enumerate(CLASSES):
        pat = str(DATA_ROOT / split / f"XR_{cls}" / "**" / "*.png")
        labels.extend([i] * len(glob.glob(pat, recursive=True)))
    return np.asarray(labels, dtype=np.int64)


class BlockDataset(Dataset):
    """(64, 224, 56) channel slice -> (64, 512, chunks) 2MB block slice."""

    def __init__(self, slices_mm, aspects, labels, layouts, *,
                 chunk_pool=4, train=True, zero_frac=0.15, other_frac=0.25,
                 comp=None, recency=True, fp_ratio=0.8, seed=0):
        self.slices = slices_mm
        self.aspects = aspects
        self.labels = labels
        self.layouts = layouts              # (L, 49) int16, -1 = outside block
        self.train = train
        self.pool = chunk_pool
        self.zero_frac = zero_frac
        self.other_frac = other_frac
        # v3: Empirical block composition (composition.npz). 1:1 index with layouts.
        self.comp = comp
        self.recency = recency
        self.fp_ratio = fp_ratio
        self.n_chunk = CHUNKS_PER_PAGE // chunk_pool
        self.rng = np.random.default_rng(seed)
        # Donor rotating bank: Reading memmap 8 times per sample bottlenecks on 1 vCPU,
        # so cache a few donors and periodically rotate.
        self._bank = []
        self._bank_left = 0
        self._bg = {}          # li -> pre-assembled background canvas (other images + non-GT)
        self._bg_uses = {}
        self.bg_reuse = 24     # Number of samples to reuse one background canvas

    def __len__(self):
        return len(self.labels)

    def _background(self, li, rng):
        """Cache and reuse background (other images + non-GT) canvas for layout li.

        Populating 512 slots from scratch per sample on a 1 vCPU environment is too costly.
        Since background is independent of labels, reuse causes no information leakage,
        and rotating every bg_reuse maintains diversity.
        """
        n = self._bg_uses.get(li, 0)
        if li not in self._bg or n >= self.bg_reuse:
            n_in = N_REF + (1 if self.recency else 0)
            bg = np.zeros((SLOTS, n_in, self.n_chunk), dtype=np.float32)
            tgt = self.layouts[li]
            tgt = tgt[tgt >= 0].astype(np.int64)
            same = np.flatnonzero(self.comp["same_slots"][li])
            same = np.setdiff1d(same, tgt)
            other = np.setdiff1d(np.flatnonzero(self.comp["other_slots"][li]),
                                 np.union1d(tgt, same))
            if len(other):
                k = max(1, min(6, len(other) // 49))
                for part, dp in zip(np.array_split(other, k), self._donors(rng, k)):
                    if len(part):
                        bg[part, :N_REF] = dp[rng.integers(CH_PAGES, size=len(part))]
            free = np.setdiff1d(np.arange(SLOTS),
                                np.concatenate([tgt, same, other]) if len(other)
                                else np.union1d(tgt, same))
            if len(free):
                fr = free.copy(); rng.shuffle(fr)
                nz = int(len(fr) * 0.35)      # zero pages -> match ref-0 across all chunks
                if nz:
                    bg[fr[:nz], 0, :] = 1.0
            self._bg[li] = bg
            self._bg_uses[li] = 0
            if len(self._bg) > 48:            # cache capacity upper bound
                drop = next(iter(self._bg))
                self._bg.pop(drop); self._bg_uses.pop(drop, None)
        self._bg_uses[li] = self._bg_uses.get(li, 0) + 1
        return self._bg[li]

    def _donors(self, rng, k):
        """Provides set of k pages from rotating donor bank."""
        if self._bank_left <= 0 or len(self._bank) < k:
            self._bank = [self._pages_of(int(rng.integers(len(self.labels))))
                          for _ in range(max(k, 4))]
            self._bank_left = 32          # rotate every 32 samples
        self._bank_left -= 1
        return [self._bank[int(rng.integers(len(self._bank)))] for _ in range(k)]

    def _pages_of(self, idx):
        """Convert cache slice to (49, 64, n_chunk) page units — including pooling here.

        Completing pooling before scattering reduces canvas from (512, 64, 256)
        to (512, 64, n_chunk), cutting memory/compute to 1/4 with pool=4.
        """
        s = np.asarray(self.slices[idx])            # (64, 224, 56) bool
        p = s.reshape(N_REF, CH_PAGES, CHUNKS_PER_PAGE).transpose(1, 0, 2)
        p = p.astype(np.float32)
        if self.pool == 1:
            return p
        return p.reshape(CH_PAGES, N_REF, self.n_chunk, self.pool).mean(axis=3)

    def __getitem__(self, idx):
        rng = self.rng if self.train else np.random.default_rng(idx)

        img_pages = self._pages_of(idx)                        # (49, 64, n_chunk)
        n_in = N_REF + (1 if self.recency else 0)
        li = int(rng.integers(len(self.layouts)))
        lay = self.layouts[li]
        valid = lay >= 0
        tgt_slots = lay[valid].astype(np.int64)
        canvas = (None if self.comp is not None
                  else np.zeros((SLOTS, n_in, self.n_chunk), dtype=np.float32))
        if canvas is not None:
            canvas[tgt_slots, :N_REF] = img_pages[np.flatnonzero(valid)]

        if self.comp is not None:
            # Background (other images 294p + non-GT 121p) is copied directly from cache
            canvas = self._background(li, rng).copy()

            # 1) Target channel: follow empirical physical layout (pages outside block are lost)
            canvas[tgt_slots, :N_REF] = img_pages[np.flatnonzero(valid)]

            # 2) Other channels of same image (R=G=B identical -> duplicate). Same label = additional signal.
            same = np.setdiff1d(np.flatnonzero(self.comp["same_slots"][li]), tgt_slots)
            if len(same):
                canvas[same, :N_REF] = img_pages[rng.integers(CH_PAGES, size=len(same))]
            recent_true = np.concatenate([tgt_slots, same]) if len(same) else tgt_slots
        else:
            # Legacy path (for reproducing v1/v2)
            free = np.setdiff1d(np.arange(SLOTS), tgt_slots)
            rng.shuffle(free)
            n_zero = int(len(free) * self.zero_frac)
            n_other = int(len(free) * self.other_frac)
            if n_zero:
                canvas[free[:n_zero], 0, :] = 1.0
            if n_other:
                dp = self._donors(rng, 1)[0]
                canvas[free[n_zero:n_zero + n_other], :N_REF] = \
                    dp[rng.integers(CH_PAGES, size=n_other)]
            recent_true = tgt_slots

        # 5) Recency channel: 'Was this page written in the current inference burst?'.
        #    This is real information obtainable from write traces, and serves as the
        #    only clue to isolate the 'current image' when 5~10 images are mixed in the block.
        #    Reflect measured temporal grouping performance with noise: recall median 100%,
        #    p25 94%, p10 49% / group precision ~0.45 -> false positives included.
        if self.recency:
            keep = rng.uniform(0.55, 1.0)
            tp = recent_true[rng.random(len(recent_true)) < keep]
            canvas[tp, N_REF, :] = 1.0
            n_fp = int(len(tp) * self.fp_ratio * rng.uniform(0.5, 1.5))
            if n_fp:
                pool = np.setdiff1d(np.arange(SLOTS), recent_true)
                if len(pool):
                    fp = rng.choice(pool, size=min(n_fp, len(pool)), replace=False)
                    canvas[fp, N_REF, :] = 1.0

        x = torch.from_numpy(canvas).permute(1, 0, 2).contiguous()  # (n_in, 512, n_chunk)
        return x, torch.tensor([self.aspects[idx]], dtype=torch.float32), self.labels[idx]


class PageEncoder(nn.Module):
    """Embed single page (64 ref * chunk). Parameters shared across pages.

    v2: Added 1 conv layer and widened channels after observing underfitting (train 0.60 / val 0.48).
    GPU utilization is ~10%, so increasing model size barely increases wall-clock time.
    """

    def __init__(self, n_ref=N_REF, dim=384):
        super().__init__()
        h1, h2 = dim // 2, dim
        self.net = nn.Sequential(
            nn.Conv1d(n_ref, h1, 5, stride=2, padding=2, bias=False),
            nn.BatchNorm1d(h1), nn.ReLU(inplace=True),
            nn.Conv1d(h1, h2, 3, stride=2, padding=1, bias=False),
            nn.BatchNorm1d(h2), nn.ReLU(inplace=True),
            nn.Conv1d(h2, dim, 3, stride=1, padding=1, bias=False),
            nn.BatchNorm1d(dim), nn.ReLU(inplace=True),
            nn.AdaptiveAvgPool1d(1),
        )

    def forward(self, x):                # x: (B*P, n_ref, C)
        return self.net(x).squeeze(-1)   # (B*P, dim)


class PageSetNet(nn.Module):
    """Permutation-invariant: per-page encoding -> attention pooling -> classification."""

    def __init__(self, num_classes=7, n_ref=N_REF, dim=384):
        super().__init__()
        self.enc = PageEncoder(n_ref, dim)
        self.attn = nn.Sequential(
            nn.Linear(dim, 128), nn.Tanh(), nn.Linear(128, 1)
        )
        self.head = nn.Sequential(
            nn.Linear(dim * 2 + 1, 512), nn.ReLU(inplace=True),
            nn.Dropout(0.4),
            nn.Linear(512, 256), nn.ReLU(inplace=True),
            nn.Dropout(0.3),
            nn.Linear(256, num_classes),
        )

    def forward(self, x, aspect):
        B, R, P, C = x.shape
        e = self.enc(x.permute(0, 2, 1, 3).reshape(B * P, R, C)).reshape(B, P, -1)
        w = torch.softmax(self.attn(e), dim=1)          # (B, P, 1)
        pooled = (e * w).sum(dim=1)                     # attention pooling
        strongest = e.max(dim=1).values                 # Most image-like page
        return self.head(torch.cat([pooled, strongest, aspect], dim=1))

    def page_scores(self, x):
        """Diagnostic: which pages were attended to (B, P)."""
        B, R, P, C = x.shape
        e = self.enc(x.permute(0, 2, 1, 3).reshape(B * P, R, C)).reshape(B, P, -1)
        return torch.softmax(self.attn(e), dim=1).squeeze(-1)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--epochs", type=int, default=60)
    ap.add_argument("--batch", type=int, default=16)
    ap.add_argument("--lr", type=float, default=3e-4)
    ap.add_argument("--chunk-pool", type=int, default=4,
                    help="Chunk axis pooling factor (larger = lighter but more information loss)")
    ap.add_argument("--limit-train", type=int, default=None,
                    help="Limit number of train samples (for CPU testing)")
    ap.add_argument("--limit-val", type=int, default=None)
    ap.add_argument("--dim", type=int, default=384,
                    help="Page embedding dimension (v1=192, v2=384)")
    ap.add_argument("--no-recency", action="store_true",
                    help="Disable recency channel (whether in current burst)")
    ap.add_argument("--no-composition", action="store_true",
                    help="Use v1/v2 synthetic composition instead of empirical block composition")
    ap.add_argument("--fp-ratio", type=float, default=0.8,
                    help="Recency false positive ratio (reflecting temporal grouping precision ~0.45)")
    ap.add_argument("--weight-decay", type=float, default=3e-4)
    ap.add_argument("--label-smooth", type=float, default=0.05)
    ap.add_argument("--no-class-weight", action="store_true",
                    help="Disable class imbalance weighting")
    ap.add_argument("--workers", type=int, default=4)
    ap.add_argument("--out", type=Path, default=HERE / "pageset_64ref.pth")
    ap.add_argument("--layouts", type=Path, default=HERE / "layouts.npz")
    args = ap.parse_args()

    dev = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    print(f"device={dev}  (Without GPU, reduce scale using --limit-train)", flush=True)

    layouts = np.load(args.layouts)["slots"]
    print(f"Loaded {len(layouts)} empirical layouts", flush=True)

    comp = None
    if not args.no_composition:
        cpath = HERE / "composition.npz"
        if cpath.exists():
            c = np.load(cpath)
            comp = {"same_slots": c["same_slots"], "other_slots": c["other_slots"]}
            print(f"Loaded empirical block composition: target {int(np.median(c['n_target']))}p / "
                  f"same_image {int(np.median(c['n_same_img']))}p / "
                  f"other_image {int(np.median(c['n_other_img']))}p (median)", flush=True)
        else:
            print("composition.npz not found -> proceeding with synthetic composition", flush=True)
    recency = not args.no_recency
    n_in = N_REF + (1 if recency else 0)
    print(f"Input channels = {n_in} (ref {N_REF}" + (" + recency 1)" if recency else ")"),
          flush=True)

    tr_s = np.lib.format.open_memmap(CACHE / "tr_slices.npy", mode="r")
    va_s = np.lib.format.open_memmap(CACHE / "va_slices.npy", mode="r")
    tr_a = np.load(CACHE / "tr_aspects.npy")
    va_a = np.load(CACHE / "va_aspects.npy")
    tr_y = collect_labels("train")
    va_y = collect_labels("valid")
    assert len(tr_y) == tr_s.shape[0] and len(va_y) == va_s.shape[0], \
        "Cache and label count mismatch — check dataset path and ordering"

    tr_idx = np.arange(len(tr_y))
    va_idx = np.arange(len(va_y))
    if args.limit_train:
        rng = np.random.default_rng(0)
        tr_idx = rng.choice(tr_idx, size=min(args.limit_train, len(tr_idx)), replace=False)
    if args.limit_val:
        rng = np.random.default_rng(1)
        va_idx = rng.choice(va_idx, size=min(args.limit_val, len(va_idx)), replace=False)

    tr_ds = BlockDataset(tr_s, tr_a, tr_y, layouts, chunk_pool=args.chunk_pool,
                         train=True, comp=comp, recency=recency, fp_ratio=args.fp_ratio)
    va_ds = BlockDataset(va_s, va_a, va_y, layouts, chunk_pool=args.chunk_pool,
                         train=False, comp=comp, recency=recency, fp_ratio=args.fp_ratio)
    tr_ds = torch.utils.data.Subset(tr_ds, tr_idx.tolist())
    va_ds = torch.utils.data.Subset(va_ds, va_idx.tolist())
    print(f"train {len(tr_ds):,}  valid {len(va_ds):,}", flush=True)

    tr_ld = DataLoader(tr_ds, batch_size=args.batch, shuffle=True,
                       num_workers=args.workers, pin_memory=(dev.type == "cuda"))
    va_ld = DataLoader(va_ds, batch_size=args.batch, shuffle=False,
                       num_workers=args.workers, pin_memory=(dev.type == "cuda"))

    model = PageSetNet(len(CLASSES), n_in, dim=args.dim).to(dev)
    n_par = sum(p.numel() for p in model.parameters())
    print(f"params={n_par:,}", flush=True)

    opt = torch.optim.AdamW(model.parameters(), lr=args.lr,
                            weight_decay=args.weight_decay)
    sched = torch.optim.lr_scheduler.CosineAnnealingLR(opt, T_max=args.epochs)
    # Class imbalance compensation: FOREARM(301)/HUMERUS(288) collapsed to
    # recall 0.3%/4.9% absorbed by majority classes. Restored via inverse frequency weighting.
    if args.no_class_weight:
        crit = nn.CrossEntropyLoss(label_smoothing=args.label_smooth)
        print("class weight: off", flush=True)
    else:
        cnt = np.bincount(tr_y[tr_idx], minlength=len(CLASSES)).astype(np.float64)
        w = cnt.sum() / (len(CLASSES) * np.maximum(cnt, 1))
        cw = torch.tensor(w, dtype=torch.float32, device=dev)
        crit = nn.CrossEntropyLoss(weight=cw, label_smoothing=args.label_smooth)
        print("class weight: " + "  ".join(
            f"{c}={v:.2f}" for c, v in zip(CLASSES, w)), flush=True)

    best = 0.0
    for ep in range(1, args.epochs + 1):
        model.train()
        t0, tot, corr, loss_sum = time.time(), 0, 0, 0.0
        for x, a, y in tr_ld:
            x, a, y = x.to(dev), a.to(dev), y.to(dev)
            opt.zero_grad()
            out = model(x, a)
            loss = crit(out, y)
            loss.backward()
            opt.step()
            loss_sum += loss.item() * y.size(0)
            corr += (out.argmax(1) == y).sum().item()
            tot += y.size(0)
        tr_acc = corr / max(tot, 1)

        model.eval()
        vtot, vcorr = 0, 0
        per_tot = np.zeros(len(CLASSES)); per_ok = np.zeros(len(CLASSES))
        with torch.no_grad():
            for x, a, y in va_ld:
                x, a, y = x.to(dev), a.to(dev), y.to(dev)
                out = model(x, a)
                pred = out.argmax(1)
                vcorr += (pred == y).sum().item()
                vtot += y.size(0)
                for c in range(len(CLASSES)):
                    m = (y == c)
                    per_tot[c] += m.sum().item()
                    per_ok[c] += (pred[m] == c).sum().item()
        va_acc = vcorr / max(vtot, 1)
        bal_acc = float(np.mean(per_ok / np.maximum(per_tot, 1)))
        sched.step()

        flag = ""
        if va_acc > best:
            best = va_acc
            torch.save({"model": model.state_dict(),
                        "chunk_pool": args.chunk_pool,
                        "dim": args.dim,
                        "recency": recency,
                        "n_in": n_in,
                        "use_comp": comp is not None,
                        "n_ref": N_REF, "classes": CLASSES,
                        "val_acc": best}, args.out)
            flag = "  *saved"
        print(f"ep{ep:>3}  loss {loss_sum/max(tot,1):.4f}  train {tr_acc:.4f}  "
              f"val {va_acc:.4f}  bal {bal_acc:.4f}  {time.time()-t0:.0f}s{flag}",
              flush=True)

    print(f"\nbest val acc = {best:.4f} → {args.out}")


if __name__ == "__main__":
    main()
