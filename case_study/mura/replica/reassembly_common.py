#!/usr/bin/env python3
"""
reassembly_common.py — Shared module for write-order page reassembly attack.

Background (write trace measurements, 411 channels):
  - Channel = 49 pages. Only 29% are physically contiguous, so cannot aggregate by address alone.
  - However, in the stream, 90% appear as '49 consecutive writes with 0 external writes'.
  - Their appearance order matches logical order (ch_pg 0..48): forward 75% / reverse 24% / other 1%.
  -> An attacker can restore channels by concatenating in 'written order' ignoring physical addresses.
     Trying just forward/reverse candidates covers 99%.

Attacker degradation models (all empirical values):
  1. Page loss — Pages falling outside the dominant 2MB block cannot be obtained.
     (layouts.npz: n_valid median 49/49, mean 45.1, all 49 pages available: 58%)
  2. Temporal grouping omission — May be omitted from burst group even within the block.
     (channel recall median 100%, p25 94%, p10 49%)
  3. Direction ambiguity — Forward vs Reverse. Training uses forward only; inference compares confidence between both candidates.
  4. Unknown aspect ratio — Attacker does not know the original aspect ratio, so uses training set mean as prior.

Pages that fail recovery are zeroed out (no match with any ref = unobserved).
"""
import glob
import os
from pathlib import Path

import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import Dataset

HERE = Path(__file__).parent
CACHE = Path(os.environ.get("MURA_CACHE",
                            "/home/eun/open-science/case_study/mura/xor_cache_64"))
DATA_ROOT = Path(os.environ.get("MURA_DATA", "/home/eun/bnb/mura/mura_downloads"))
CLASSES = ["ELBOW", "FINGER", "FOREARM", "HAND", "HUMERUS", "SHOULDER", "WRIST"]

N_REF = 64
CH_PAGES = 49            # 224*224*4 / 4096
XOR_ROWS, XOR_COLS = 224, 56
CHUNKS_PER_PAGE = 256    # 4096 / 16


def collect_labels(split):
    """Matches glob order when creating xor_cache_64 -> 1:1 with cache index."""
    labels = []
    for i, cls in enumerate(CLASSES):
        pat = str(DATA_ROOT / split / f"XR_{cls}" / "**" / "*.png")
        labels.extend([i] * len(glob.glob(pat, recursive=True)))
    return np.asarray(labels, dtype=np.int64)


# ── Reassembly Dataset ─────────────────────────────────────────────────────────
class ReassemblyDataset(Dataset):
    """Applies 'attacker-perceived degradations' to cache slices to create reassembly inputs.

    Output matches the original model dimension (64, 224, 56), so the existing
    XorSliceResNet can be used directly or fine-tuned.
    """

    def __init__(self, slices_mm, labels, layouts, *, train=True,
                 aspect_prior=1.339, degrade=True, reverse=False,
                 sim_reverse_rate=0.0, undo=False, seed=0):
        self.slices = slices_mm
        self.labels = labels
        self.layouts = layouts          # (L, 49) int16, -1 = outside dominant block
        self.train = train
        self.aspect_prior = float(aspect_prior)
        self.degrade = degrade
        self.reverse = reverse          # Reassemble with reverse hypothesis (used during inference)
        # sim_reverse_rate: Rate of creating 'actually reverse assembled' observations.
        #   Case where attacker sees array X = flip(clean). Measured at 24%.
        # undo: Reverse X back to attempt forward recovery (when direction discriminator determines reverse)
        self.sim_reverse_rate = float(sim_reverse_rate)
        self.undo = undo
        self.rng = np.random.default_rng(seed)

    def __len__(self):
        return len(self.labels)

    def keep_mask(self, rng):
        """Logical page mask actually recovered in this sample."""
        keep = np.ones(CH_PAGES, dtype=bool)
        if not self.degrade:
            return keep
        # (1) Page loss outside dominant block — extracted from empirical layout
        lay = self.layouts[rng.integers(len(self.layouts))]
        keep &= (lay >= 0)
        # (2) Temporal grouping omission — channel recall median 100%, p10 49%
        if rng.random() < 0.5:
            keep &= (rng.random(CH_PAGES) < rng.uniform(0.49, 1.0))
        return keep

    def __getitem__(self, idx):
        rng = self.rng if self.train else np.random.default_rng(idx)

        sl = np.asarray(self.slices[idx])                       # (64,224,56) bool
        pages = sl.reshape(N_REF, CH_PAGES, CHUNKS_PER_PAGE)    # (64,49,256)

        keep = self.keep_mask(rng)
        rec = np.where(keep[None, :, None], pages, False)

        # (a) Real observation generation: reverse-assembled slice observed with sim_reverse_rate probability
        is_rev = (self.sim_reverse_rate > 0
                  and rng.random() < self.sim_reverse_rate)
        if is_rev:
            rec = rec[:, ::-1, :]

        # (b) Attacker manipulation: undo flips back, reverse generates reverse hypothesis
        if self.undo or self.reverse:
            rec = rec[:, ::-1, :]

        x = np.ascontiguousarray(rec.reshape(N_REF, XOR_ROWS, XOR_COLS),
                                 dtype=np.float32)
        return (torch.from_numpy(x),
                torch.tensor([self.aspect_prior], dtype=torch.float32),
                self.labels[idx],
                np.float32(keep.mean()),
                np.int64(is_rev))


# ── Model (Same architecture as XorSliceResNet in train_64ref.py) ──────────────
class ResBlock(nn.Module):
    def __init__(self, in_ch, out_ch, stride=1):
        super().__init__()
        self.c1 = nn.Conv2d(in_ch, out_ch, 3, stride=stride, padding=1, bias=False)
        self.b1 = nn.BatchNorm2d(out_ch)
        self.c2 = nn.Conv2d(out_ch, out_ch, 3, padding=1, bias=False)
        self.b2 = nn.BatchNorm2d(out_ch)
        self.down = nn.Sequential(
            nn.Conv2d(in_ch, out_ch, 1, stride=stride, bias=False),
            nn.BatchNorm2d(out_ch),
        ) if (stride != 1 or in_ch != out_ch) else nn.Identity()

    def forward(self, x):
        return F.relu(self.b2(self.c2(F.relu(self.b1(self.c1(x))))) + self.down(x))


class XorSliceResNet(nn.Module):
    def __init__(self, num_classes=7, n_ref=N_REF):
        super().__init__()
        self.stem = nn.Sequential(
            nn.Conv2d(n_ref, 32, kernel_size=(7, 3), stride=(2, 1),
                      padding=(3, 1), bias=False),
            nn.BatchNorm2d(32), nn.ReLU(inplace=True),
        )
        self.pool1 = nn.MaxPool2d(kernel_size=(2, 1), stride=(2, 1))
        self.layer1 = ResBlock(32, 64, stride=1)
        self.layer2 = ResBlock(64, 128, stride=2)
        self.layer3 = ResBlock(128, 256, stride=2)
        self.layer4 = ResBlock(256, 512, stride=2)
        self.gap = nn.AdaptiveAvgPool2d(1)
        self.head = nn.Sequential(
            nn.Linear(512 + 1, 256), nn.ReLU(inplace=True),
            nn.Dropout(0.4),
            nn.Linear(256, num_classes),
        )

    def forward(self, x, sc):
        x = self.pool1(self.stem(x))
        x = self.layer4(self.layer3(self.layer2(self.layer1(x))))
        return self.head(torch.cat([self.gap(x).flatten(1), sc], dim=1))


def load_cache(split):
    name = "tr" if split == "train" else "va"
    slices = np.lib.format.open_memmap(CACHE / f"{name}_slices.npy", mode="r")
    labels = collect_labels(split)
    assert len(labels) == slices.shape[0], \
        f"{split}: cache {slices.shape[0]} vs labels {len(labels)} mismatch"
    return slices, labels


def train_aspect_prior():
    """Only aspect ratio information available to attacker = training set mean."""
    return float(np.load(CACHE / "tr_aspects.npy").mean())


def plot_cm(cm, classes, out_stem, title, subtitle):
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt

    n = len(classes)
    norm = cm / np.maximum(cm.sum(axis=1, keepdims=True), 1)
    fig, ax = plt.subplots(figsize=(1.15 * n + 3.2, 1.15 * n + 2.6))
    im = ax.imshow(norm, cmap="Blues", vmin=0, vmax=1)
    ax.set_xticks(range(n)); ax.set_yticks(range(n))
    ax.set_xticklabels(classes, rotation=45, ha="right", fontsize=12)
    ax.set_yticklabels(classes, fontsize=12)
    ax.set_xlabel("Predicted", fontsize=14); ax.set_ylabel("True", fontsize=14)
    ax.set_title(title, fontsize=15, fontweight="bold", pad=14)
    if subtitle:
        ax.text(0.5, 1.015, subtitle, transform=ax.transAxes, ha="center",
                va="bottom", fontsize=11, color="#555")
    for i in range(n):
        for j in range(n):
            v = norm[i, j]
            ax.text(j, i, f"{cm[i, j]}\n{v*100:.0f}%", ha="center", va="center",
                color="white" if v > 0.5 else "#222")
    cb = fig.colorbar(im, ax=ax, fraction=0.046, pad=0.04)
    cb.set_label("row-normalized", fontsize=11)
    fig.tight_layout()
    for ext in ("png", "pdf"):
        fig.savefig(f"{out_stem}.{ext}", dpi=200 if ext == "png" else None,
                    bbox_inches="tight")
        print(f"saved: {out_stem}.{ext}")
    plt.close(fig)
