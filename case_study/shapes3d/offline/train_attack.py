#!/usr/bin/env python3
"""
train_attack.py — shape classifier on 3DShapes cipher maps.

Input: shapes_map.to_input() of a map, (4,224,224) = recovered R/G/B values + hit
mask, average-pooled to 112x112. Model: small ResNet-style CNN.

Pretraining uses simulated maps (datasets/sim_train.npz) with capture-degradation
augmentation; --finetune adds real captured maps (datasets/cap_train.npz). Evaluation
on datasets/sim_test.npz (dictionary ceiling) and, when present, cap_test.npz.

Degradation model (per plane, applied to the map):
  * missing pages: each of the 49 pages dropped with prob p_drop, plus with prob
    p_tail a run at the start/end (partial capture, as in MURA's top-align cases)
  * tensor offset: the whole tensor shifted by 0-3 blocks (allocator alignment)

  python3 train_attack.py --epochs 15 [--finetune] [--out attack_shapes.pth]
"""
import argparse
import sys
import time
from pathlib import Path

import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F

HERE = Path(__file__).resolve().parent
DS = HERE.parent / "datasets"
sys.path.insert(0, str(HERE.parent / "pipeline"))
import shapes_map as sm  # noqa: E402

BLOCKS_PER_PAGE = 256
TABLES = sm.keyword_tables()
PX = {i: torch.from_numpy(TABLES[ch][1].astype(np.float32) / 255.0) for i, ch in enumerate("RGB")}


def degrade(m: np.ndarray, rng, p_drop=0.03, p_tail=0.3) -> np.ndarray:
    m = m.copy()
    flat = m.reshape(3, -1)
    shift = rng.integers(0, 4)
    if shift:
        flat[:] = np.roll(flat, shift, axis=1)
        flat[:, :shift] = 0
    for p in range(3):
        drop = rng.random(49) < p_drop
        if rng.random() < p_tail:
            n = rng.integers(1, 12)
            if rng.random() < 0.5:
                drop[:n] = True
            else:
                drop[-n:] = True
        for k in np.flatnonzero(drop):
            flat[p, k * BLOCKS_PER_PAGE:(k + 1) * BLOCKS_PER_PAGE] = 0
    return m


def _zero_pages(flat_p, ks):
    for k in ks:
        if 0 <= k < 49:
            flat_p[k * BLOCKS_PER_PAGE:(k + 1) * BLOCKS_PER_PAGE] = 0


def _shift(flat_p, n):
    """Shift one plane by n blocks (positive = later), zero fill."""
    if n > 0:
        flat_p[n:] = flat_p[:-n].copy()
        flat_p[:n] = 0
    elif n < 0:
        flat_p[:n] = flat_p[-n:].copy()
        flat_p[n:] = 0


def degrade_v2(m: np.ndarray, rng) -> np.ndarray:
    """Damage model from the blind pipeline's failure modes (not fitted to captures):
      * localisation lands on a stale R-only copy: G and B planes empty (5%)
      * plane boundary misplaced by the channel assembly: plane shifted by whole pages
      * blind base offset off by a few 64 B steps: plane shifted by 4-block multiples
      * pieces not probed / foreign runs: 1-3 contiguous page gaps, plus random drops
      * runs written out of order: two page runs swapped within a plane
      * pages with few keyword hits: blocks thinned out within some pages
    Each plane draws its own damage; probabilities chosen so ~25% of maps stay clean."""
    m = degrade(m, rng)                                  # v1: tail cut, 0-3 block shift
    flat = m.reshape(3, -1)
    if rng.random() < 0.05:
        flat[1:] = 0
        return m
    for p in range(3):
        f = flat[p]
        if rng.random() < 0.3:
            _shift(f, int(rng.integers(-6, 7)) * BLOCKS_PER_PAGE)
        if rng.random() < 0.2:
            _shift(f, int(rng.integers(-16, 17)) * 4)
        if rng.random() < 0.5:
            for _ in range(rng.integers(1, 4)):
                a = int(rng.integers(0, 49))
                _zero_pages(f, range(a, a + int(rng.integers(1, 20))))
        if rng.random() < 0.3:
            _zero_pages(f, np.flatnonzero(rng.random(49) < rng.uniform(0.05, 0.3)))
        if rng.random() < 0.2:
            n = int(rng.integers(2, 13))
            a, b = sorted(rng.choice(49 - n, 2, replace=False))
            if b - a >= n:
                A = f[a * BLOCKS_PER_PAGE:(a + n) * BLOCKS_PER_PAGE].copy()
                f[a * BLOCKS_PER_PAGE:(a + n) * BLOCKS_PER_PAGE] = f[b * BLOCKS_PER_PAGE:(b + n) * BLOCKS_PER_PAGE]
                f[b * BLOCKS_PER_PAGE:(b + n) * BLOCKS_PER_PAGE] = A
        if rng.random() < 0.3:
            thin = rng.random(f.shape[0]) < rng.uniform(0.1, 0.6)
            pages = rng.random(49) < 0.5
            thin &= np.repeat(pages, BLOCKS_PER_PAGE)
            f[thin] = 0
    return m


def to_tensor(maps_u8: np.ndarray) -> torch.Tensor:
    """(B,3,224,56) uint8 (idx+1) -> (B,4,112,112) float."""
    m = torch.from_numpy(maps_u8.astype(np.int64)) - 1                       # -1 = miss
    B = m.shape[0]
    x = torch.zeros(B, 4, 224, 56, 4)
    for i in range(3):
        hit = m[:, i] >= 0
        x[:, i][hit] = PX[i][m[:, i][hit]]
        x[:, 3] = torch.maximum(x[:, 3], hit.unsqueeze(-1).float().expand(-1, -1, -1, 4))
    x = x.reshape(B, 4, 224, 224)
    return F.avg_pool2d(x, 2)


class Block(nn.Module):
    def __init__(self, cin, cout, stride):
        super().__init__()
        self.c1 = nn.Conv2d(cin, cout, 3, stride, 1, bias=False)
        self.b1 = nn.BatchNorm2d(cout)
        self.c2 = nn.Conv2d(cout, cout, 3, 1, 1, bias=False)
        self.b2 = nn.BatchNorm2d(cout)
        self.sc = (nn.Sequential(nn.Conv2d(cin, cout, 1, stride, bias=False), nn.BatchNorm2d(cout))
                   if stride != 1 or cin != cout else nn.Identity())

    def forward(self, x):
        return F.relu(self.b2(self.c2(F.relu(self.b1(self.c1(x))))) + self.sc(x))


class ShapeNet(nn.Module):
    def __init__(self, n_cls=4):
        super().__init__()
        self.stem = nn.Sequential(nn.Conv2d(4, 32, 3, 1, 1, bias=False), nn.BatchNorm2d(32), nn.ReLU())
        self.l = nn.Sequential(Block(32, 32, 2), Block(32, 64, 2), Block(64, 128, 2), Block(128, 128, 2))
        self.fc = nn.Linear(128, n_cls)

    def forward(self, x):
        return self.fc(F.adaptive_avg_pool2d(self.l(self.stem(x)), 1).flatten(1))


def evaluate(model, maps, y, bs=200):
    model.eval()
    pred = []
    with torch.no_grad():
        for s in range(0, len(y), bs):
            pred.append(model(to_tensor(maps[s:s + bs])).argmax(1))
    p = torch.cat(pred).numpy()
    per = [100 * (p[y == k] == k).mean() for k in range(4)]
    return 100 * (p == y).mean(), per


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--epochs", type=int, default=15)
    ap.add_argument("--bs", type=int, default=64)
    ap.add_argument("--finetune", action="store_true")
    ap.add_argument("--init", default=None)
    ap.add_argument("--out", default=str(HERE / "attack_shapes.pth"))
    ap.add_argument("--no-degrade", action="store_true")
    ap.add_argument("--aug", default="v1", choices=["v1", "v2"])
    ap.add_argument("--keep-ch", default="RGB", help="planes kept; others zeroed everywhere (single-channel ablation)")
    ap.add_argument("--threads", type=int, default=48)
    ap.add_argument("--dict-k", type=int, default=16, help="keep the top-K keywords per channel (Dict-K is a prefix of Dict-16)")
    a = ap.parse_args()
    torch.set_num_threads(a.threads)
    rng = np.random.default_rng(0)
    deg = degrade_v2 if a.aug == "v2" else degrade

    tr = np.load(DS / ("cap_train.npz" if a.finetune else "sim_train.npz"))
    Xtr, ytr = tr["maps"], tr["shape"]
    te = np.load(DS / "sim_test.npz")
    evals = [("sim_test", te["maps"], te["shape"])]
    if a.aug == "v2":
        # Model selection on held-out TRAIN images with fixed damage; the test split
        # (simulated or captured) never picks the checkpoint.
        vrng = np.random.default_rng(123)
        vi = vrng.permutation(len(ytr))[:2000]
        keep = np.setdiff1d(np.arange(len(ytr)), vi)
        Xv = np.stack([degrade_v2(Xtr[i], vrng) for i in vi])
        yv = ytr[vi]
        Xtr, ytr = Xtr[keep], ytr[keep]
        evals.append(("sim_val_damaged", Xv, yv))
    elif (DS / "cap_test.npz").exists():
        ct = np.load(DS / "cap_test.npz")
        evals.append(("cap_test", ct["maps"], ct["shape"]))

    if a.dict_k < 16:                                    # maps store idx+1; rank >= K -> miss
        Xtr = np.where(Xtr > a.dict_k, 0, Xtr).astype(Xtr.dtype)
        evals = [(n, np.where(X > a.dict_k, 0, X).astype(X.dtype), y) for n, X, y in evals]
    drop = [i for i, ch in enumerate("RGB") if ch not in a.keep_ch]
    if drop:
        Xtr = Xtr.copy(); Xtr[:, drop] = 0
        evals = [(n, X.copy(), y) for n, X, y in evals]
        for _, X, _ in evals:
            X[:, drop] = 0

    model = ShapeNet()
    if a.init:
        model.load_state_dict(torch.load(a.init))
    opt = torch.optim.AdamW(model.parameters(), lr=3e-4 if a.finetune else 1e-3, weight_decay=1e-4)
    sched = torch.optim.lr_scheduler.CosineAnnealingLR(opt, a.epochs)
    best = -1
    for ep in range(a.epochs):
        model.train()
        t0, perm, tot = time.time(), rng.permutation(len(ytr)), 0.0
        for s in range(0, len(perm), a.bs):
            b = perm[s:s + a.bs]
            mb = Xtr[b] if (a.no_degrade or a.finetune) else np.stack([deg(Xtr[i], rng) for i in b])
            loss = F.cross_entropy(model(to_tensor(mb)), torch.from_numpy(ytr[b]))
            opt.zero_grad()
            loss.backward()
            opt.step()
            tot += loss.item() * len(b)
        sched.step()
        msg = [f"[ep {ep + 1:2d}] loss {tot / len(ytr):.4f}"]
        for name, X, y in evals:
            acc, per = evaluate(model, X, y)
            msg.append(f"{name} {acc:.1f}% {np.round(per, 1).tolist()}")
        score = evaluate(model, *evals[-1][1:])[0]
        if score > best:
            best = score
            torch.save(model.state_dict(), a.out)
            msg.append("*saved")
        print("  ".join(msg) + f"  ({time.time() - t0:.0f}s)", flush=True)
    print(f"best {evals[-1][0]} {best:.1f}% -> {a.out}")


if __name__ == "__main__":
    main()
