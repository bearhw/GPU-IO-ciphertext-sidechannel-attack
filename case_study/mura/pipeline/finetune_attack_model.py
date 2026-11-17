#!/usr/bin/env python3
"""
finetune_attack_model.py — Adapt the v2 XorSliceSENet to attack-captured maps.

The checkpoint was trained on 36,808 clean maps built straight from the images.
What the attack produces is the same kind of map from a different distribution:
pages recovered from ciphertext collisions, so it is sparser (density ~0.0035 vs
~0.0040) and its window is often shifted by a page or two. Same task, different
input distribution — which is what fine-tuning is for.

The zero-shot accuracy of the unmodified checkpoint on these maps is measured and
printed first. Without it there is no way to tell whether fine-tuning helped.

Evaluation uses the MURA valid split, not a slice of the training captures. The
checkpoint was trained on every image in the train split, so scoring it there says
nothing — and the path list groups three or four images per patient, so an
index-based holdout puts the same patient's other views on both sides. The valid
split shares no patient with train, and the checkpoint never saw it.

Falling back to an index holdout inside one split is still possible (--holdout-split)
for a quick signal, but it carries both of those problems and says so when used.

The aspect-ratio scalar the architecture takes is fed as 1.0: it is the original
image's height/width, which the side channel cannot observe (the tensor is already
resized to 224x224). Measured cost of that substitution on clean data: 2.7 points.

Usage:
    python3 finetune_attack_model.py --eval-only          # zero-shot baseline
    python3 finetune_attack_model.py --epochs 30
    python3 finetune_attack_model.py --balance --epochs 30
"""

import argparse
import json
import sys
from collections import Counter
from pathlib import Path

import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import DataLoader, Dataset

import datetime as _dt

HERE = Path(__file__).resolve().parent
_LOG_FH = None


def log(*args):
    """Print to the terminal and, once --log is set, append to that file too.

    Fine-tuning runs for hours; capturing the exact zero-shot baseline, per-epoch
    curve, and final confusion matrix in a timestamped file makes a run auditable
    after the fact instead of living only in a scrollback buffer.
    """
    msg = " ".join(str(a) for a in args)
    print(msg, flush=True)
    if _LOG_FH is not None:
        _LOG_FH.write(msg + "\n")
        _LOG_FH.flush()
sys.path.insert(0, str(HERE))
import common as c
from stage5_reconstruct import XorSliceSENet


class _ResBlock(nn.Module):
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
    """The 16/32-ref checkpoints are a plainer net than v2 — no SE, no stats head,
    stem width 32 — so they need their own class to load with strict=True."""
    def __init__(self, num_classes=7, n_ref=32):
        super().__init__()
        self.stem = nn.Sequential(
            nn.Conv2d(n_ref, 32, (7, 3), stride=(2, 1), padding=(3, 1), bias=False),
            nn.BatchNorm2d(32), nn.ReLU(inplace=True))
        self.pool1 = nn.MaxPool2d((2, 1), stride=(2, 1))
        self.layer1 = _ResBlock(32, 64, 1)
        self.layer2 = _ResBlock(64, 128, 2)
        self.layer3 = _ResBlock(128, 256, 2)
        self.layer4 = _ResBlock(256, 512, 2)
        self.gap = nn.AdaptiveAvgPool2d(1)
        self.head = nn.Sequential(
            nn.Linear(512 + 1, 256), nn.ReLU(inplace=True),
            nn.Dropout(0.4), nn.Linear(256, num_classes))

    def forward(self, x, sc):
        x = self.pool1(self.stem(x))
        x = self.layer1(x); x = self.layer2(x); x = self.layer3(x); x = self.layer4(x)
        return self.head(torch.cat([self.gap(x).flatten(1), sc], dim=1))


# The 64-ref checkpoint is the SE variant (v2); 16/32 are the plain ResNet (v1).
DEFAULT_CKPT = {16: "mura_xor_slice_16ref.pth",
                32: "mura_xor_slice_32ref.pth",
                64: "mura_xor_slice_64ref_v2.pth"}


def build_model(n_ref: int, num_classes: int):
    if n_ref == 64:
        return XorSliceSENet(num_classes, n_ref=n_ref)
    return XorSliceResNet(num_classes, n_ref=n_ref)

DATASETS = HERE / "datasets"


# Shift distribution measured over the captures, normalised so it sums to exactly 1
# (a hand-typed list summing to 0.9 makes np.random.choice raise on the first batch).
_SHIFTS = [0, -1, 1, -2, 2, -3, 3]
_SHIFT_W = [0.40, 0.17, 0.09, 0.09, 0.05, 0.07, 0.03]
_SHIFT_P = [w / sum(_SHIFT_W) for w in _SHIFT_W]


class MapDataset(Dataset):
    """Attack maps with optional page-shift augmentation.

    The shift is not arbitrary jitter: a window that starts k writes early or late
    puts k junk pages at one end and drops k real ones at the other, which is
    exactly what was measured over 3,197 captures (|k| <= 1 for 63% of them). The
    augmentation reproduces that failure instead of inventing a different one.
    """

    PAGE_CHUNKS = c.CHUNKS_PER_PAGE          # 256 chunks per 4KB page
    SHIFTS = _SHIFTS
    SHIFT_P = _SHIFT_P

    def __init__(self, x, y, augment=False, seed=0, shifts=None, shift_p=None,
                 foreign_p=0.0, pool=None):
        self.x, self.y, self.augment = x, y, augment
        self.seed = seed
        self.rng = np.random.default_rng(seed)
        self._worker = None
        # Override the default (block-given) shift distribution with a measured one,
        # e.g. the blind distribution where the window runs 7+ pages late far more
        # often. The model only becomes robust to shifts it is actually shown.
        if shifts is not None:
            self.SHIFTS = shifts
            self.SHIFT_P = shift_p
        # In blind captures the pages a shifted window picks up are not empty: samples
        # missing 3-9 GT pages have the same empty-slot count as complete ones and a
        # higher density. They hold the neighbouring image's pages. With probability
        # foreign_p the shifted-in slots are filled from another sample (its head
        # for a late window, its tail for an early one) instead of zeros.
        self.foreign_p = foreign_p
        self.pool = pool if pool is not None else range(len(y))

    def __len__(self):
        return len(self.y)

    def _reseed_for_worker(self):
        # Each DataLoader worker gets a copy of the same rng, so without this the
        # workers draw identical augmentations. wi.seed differs per worker and epoch.
        wi = torch.utils.data.get_worker_info()
        if wi is not None and self._worker != (wi.id, wi.seed):
            self.rng = np.random.default_rng(wi.seed)
            self._worker = (wi.id, wi.seed)

    def _shift(self, m: np.ndarray) -> np.ndarray:
        k = int(self.rng.choice(self.SHIFTS, p=self.SHIFT_P))
        if k == 0:
            return m
        n_ref, rows, cols = m.shape
        flat = m.reshape(n_ref, rows * cols)
        off = abs(k) * self.PAGE_CHUNKS
        out = np.zeros_like(flat)
        donor = None
        if self.foreign_p > 0 and self.rng.random() < self.foreign_p:
            j = self.pool[int(self.rng.integers(len(self.pool)))]
            donor = np.asarray(self.x[j]).reshape(n_ref, rows * cols)
        if k < 0:                 # window started early: junk at the front
            out[:, off:] = flat[:, :-off]
            if donor is not None:  # previous image's last pages
                out[:, :off] = donor[:, -off:]
        else:                     # started late: junk at the back
            out[:, :-off] = flat[:, off:]
            if donor is not None:  # next image's first pages
                out[:, -off:] = donor[:, :off]
        return out.reshape(n_ref, rows, cols)

    def __getitem__(self, i):
        self._reseed_for_worker()
        m = self.x[i]
        if self.augment:
            m = self._shift(np.asarray(m))
        return torch.from_numpy(np.ascontiguousarray(m)).float(), int(self.y[i])


def load_dataset(split: str, n_ref: int):
    tag = f"{split}_{n_ref}ref"
    xs, ys = DATASETS / f"{tag}_slices.npy", DATASETS / f"{tag}_labels.npy"
    if not xs.exists():
        sys.exit(f"{xs} not found — run build_attack_dataset.py --split {split} "
                 f"--n-ref {n_ref} first")
    idx_path = DATASETS / f"{tag}_index.json"
    meta = json.loads(idx_path.read_text()) if idx_path.exists() else []
    return np.load(xs, mmap_mode="r"), np.load(ys), meta


def split_indices(meta, n: int, holdout: int, every: int):
    """Validation = samples whose capture index is congruent to `holdout`."""
    if meta and len(meta) == n:
        keys = [m.get("index", i) for i, m in enumerate(meta)]
    else:
        keys = list(range(n))
    val = [i for i, k in enumerate(keys) if k % every == holdout]
    tr = [i for i in range(n) if i not in set(val)]
    return tr, val


def evaluate(model, loader, device):
    model.eval()
    preds, trues = [], []
    with torch.no_grad():
        for xb, yb in loader:
            xb = xb.to(device)
            sc = torch.ones(len(xb), 1, device=device)   # aspect is unobservable
            preds += model(xb, sc).argmax(1).cpu().tolist()
            trues += yb.tolist()
    preds, trues = np.array(preds), np.array(trues)
    per = {}
    for i, name in enumerate(c.CLASSES):
        m = trues == i
        if m.any():
            per[name] = float((preds[m] == i).mean())
    return {
        "top1": float((preds == trues).mean()),
        "macro": float(np.mean(list(per.values()))) if per else 0.0,
        "per_class": per,
        "preds": preds, "trues": trues,
    }


def report(tag, r):
    log(f"[{tag}] top-1 {r['top1']*100:.1f}%   macro {r['macro']*100:.1f}%")
    log("        " + "  ".join(f"{k} {v*100:.0f}%" for k, v in sorted(r["per_class"].items())))


def _save_curve(history, path):
    """Plot train accuracy / val macro / val top-1 (left axis) and train loss
    (right axis) against epoch. Failing to plot must not fail a multi-hour run, so
    the history JSON is the source of truth and this is best-effort on top of it."""
    eps = history["epoch"]
    if not eps:
        return
    try:
        import matplotlib
        matplotlib.use("Agg")
        import matplotlib.pyplot as plt
        x = [e["ep"] for e in eps]
        fig, ax = plt.subplots(figsize=(7, 4.5))
        ax.plot(x, [e["train_acc"] * 100 for e in eps], "-o", ms=3, label="train acc", color="#1f77b4")
        ax.plot(x, [e["val_top1"] * 100 for e in eps], "-o", ms=3, label="val top-1", color="#2ca02c")
        ax.plot(x, [e["val_macro"] * 100 for e in eps], "-o", ms=3, label="val macro", color="#ff7f0e")
        ax.axhline(history["zero_shot"]["macro"] * 100, ls="--", lw=1, color="#888",
                   label=f"zero-shot macro {history['zero_shot']['macro']*100:.1f}%")
        ax.set_xlabel("epoch"); ax.set_ylabel("accuracy (%)"); ax.set_ylim(0, 100)
        ax.grid(alpha=0.3)
        ax2 = ax.twinx()
        ax2.plot(x, [e["train_loss"] for e in eps], ":", lw=1.2, color="#d62728", label="train loss")
        ax2.set_ylabel("train loss", color="#d62728")
        best = max(eps, key=lambda e: e["val_macro"])
        ax.set_title(f"Dict-{history['n_ref']} blind fine-tune  "
                     f"(best val macro {best['val_macro']*100:.1f}% @ ep{best['ep']})")
        h1, l1 = ax.get_legend_handles_labels(); h2, l2 = ax2.get_legend_handles_labels()
        ax.legend(h1 + h2, l1 + l2, loc="lower right", fontsize=8)
        fig.tight_layout(); fig.savefig(path, dpi=130); plt.close(fig)
        log(f"[curve] {path}")
    except Exception as e:
        log(f"[curve] skipped ({e}); history in {path.with_suffix('.json').name}")


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--train-split", default="train", help="Captures to fine-tune on")
    p.add_argument("--eval-split", default="valid",
                   help="Captures to evaluate on; must be a split the checkpoint "
                        "never trained on")
    p.add_argument("--holdout-split", action="store_true",
                   help="Ignore --eval-split and hold out 1-in-N of the training "
                        "captures instead (contaminated; for a quick signal only)")
    p.add_argument("--n-ref", type=int, default=64)
    p.add_argument("--ckpt", default=None,
                   help="Pretrained checkpoint; defaults to the one matching --n-ref")
    p.add_argument("--epochs", type=int, default=30)
    p.add_argument("--batch", type=int, default=16)
    p.add_argument("--lr", type=float, default=1e-4, help="Head learning rate")
    p.add_argument("--backbone-lr", type=float, default=2e-5,
                   help="Lower, so pretrained features are nudged rather than overwritten")
    p.add_argument("--holdout", type=int, default=0)
    p.add_argument("--every", type=int, default=10, help="1-in-N held out (9:1 at 10)")
    p.add_argument("--balance", action="store_true",
                   help="Subsample every class to the smallest instead of weighting the loss")
    p.add_argument("--no-augment", dest="augment", action="store_false")
    p.add_argument("--shift-dist", default=None,
                   help="JSON {k: prob} of the page-shift distribution to augment "
                        "with (e.g. the blind distribution). Default: built-in "
                        "block-given distribution (|k|<=3).")
    p.add_argument("--foreign-fill", type=float, default=0.0,
                   help="Probability that pages shifted into the window are filled from "
                        "another training sample instead of zeros (blind captures pick "
                        "up the neighbouring image's pages). Default 0 = zeros.")
    p.add_argument("--eval-only", action="store_true", help="Report zero-shot and stop")
    p.add_argument("--out", default=None)
    p.add_argument("--log", default=None,
                   help="Append all output to this file as well (default: "
                        "finetune_<eval-split>_<timestamp>.log)")
    args = p.parse_args()

    global _LOG_FH
    log_path = args.log or (HERE / f"finetune_{args.eval_split}_"
                            f"{_dt.datetime.now():%Y%m%d-%H%M%S}.log")
    _LOG_FH = open(log_path, "a")
    log(f"# {_dt.datetime.now():%Y-%m-%d %H:%M:%S}  cmd: {' '.join(sys.argv)}")

    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    x, y, meta = load_dataset(args.train_split, args.n_ref)
    log(f"[train data] {x.shape} density {np.asarray(x[:64]).mean():.5f}")
    log(f"[train data] classes: {dict(Counter(c.CLASSES[i] for i in y))}")

    if args.holdout_split:
        log(f"[!] holding out 1-in-{args.every} of {args.train_split}: the checkpoint "
              f"trained on these images and a patient's other views sit on both sides, "
              f"so treat the number as a sanity check, not a result")
        tr, val = split_indices(meta, len(y), args.holdout, args.every)
        vx, vy = x, y
    else:
        vx, vy, _ = load_dataset(args.eval_split, args.n_ref)
        log(f"[eval data]  {vx.shape} from {args.eval_split} split "
              f"(unseen by the checkpoint)")
        tr, val = list(range(len(y))), list(range(len(vy)))
    if args.balance:
        per = Counter(y[i] for i in tr)
        cap = min(per.values())
        kept, seen = [], Counter()
        for i in tr:
            if seen[y[i]] < cap:
                kept.append(i); seen[y[i]] += 1
        log(f"[data] balanced train: {len(tr)} -> {len(kept)} ({cap} per class)")
        tr = kept

    log(f"[data] train {len(tr)}  eval {len(val)}")
    log(f"[data] eval classes: {dict(Counter(c.CLASSES[vy[i]] for i in val))}")

    # Index through the memmap lazily rather than materialising a 1.5GB copy.
    sh_k = sh_p = None
    if args.shift_dist:
        dd = json.loads(Path(args.shift_dist).read_text())
        sh_k = [int(k) for k in dd]
        tot = sum(dd.values())
        sh_p = [dd[k] / tot for k in dd]
        log(f"[aug] custom shift distribution: {len(sh_k)} shifts, "
            f"k range [{min(sh_k)}, {max(sh_k)}], "
            f"P(|k|>=4)={sum(p for k,p in zip(sh_k,sh_p) if abs(k)>=4):.2f}")

    if args.foreign_fill > 0:
        log(f"[aug] foreign fill: shifted-in pages from another sample with "
            f"p={args.foreign_fill}")
    tr_ld = DataLoader(_Subset(x, y, tr, augment=args.augment, shifts=sh_k, shift_p=sh_p,
                               foreign_p=args.foreign_fill),
                       batch_size=args.batch, shuffle=True, num_workers=2)
    va_ld = DataLoader(_Subset(vx, vy, val, augment=False),
                       batch_size=args.batch, num_workers=2)

    ckpt = args.ckpt or str(HERE.parent / DEFAULT_CKPT[args.n_ref])
    model = build_model(args.n_ref, len(c.CLASSES)).to(device)
    sd = torch.load(ckpt, map_location=device, weights_only=True)
    model.load_state_dict(sd, strict=True)
    log(f"[model] {type(model).__name__} loaded {Path(ckpt).name}")

    base = evaluate(model, va_ld, device)
    report("zero-shot", base)
    if args.eval_only:
        return 0

    counts = Counter(int(y[i]) for i in tr)
    w = torch.tensor([len(tr) / (len(counts) * counts.get(i, 1))
                      for i in range(len(c.CLASSES))], dtype=torch.float32, device=device)
    crit = nn.CrossEntropyLoss(weight=None if args.balance else w)
    head = [n for n, _ in model.named_parameters() if n.startswith(("head", "stats_head"))]
    opt = torch.optim.AdamW([
        {"params": [q for n, q in model.named_parameters() if n in head], "lr": args.lr},
        {"params": [q for n, q in model.named_parameters() if n not in head],
         "lr": args.backbone_lr},
    ], weight_decay=1e-4)
    sched = torch.optim.lr_scheduler.CosineAnnealingLR(opt, T_max=args.epochs)

    out = Path(args.out or HERE / f"mura_attack_{args.n_ref}ref_ft.pth")
    hist_path = out.with_name(out.stem + "_history.json")
    curve_path = out.with_name(out.stem + "_curve.png")
    history = {"n_ref": args.n_ref, "epochs": args.epochs, "ckpt": Path(ckpt).name,
               "shift_dist": args.shift_dist, "foreign_fill": args.foreign_fill,
               "zero_shot": {"top1": base["top1"], "macro": base["macro"]},
               "epoch": []}
    best = base["macro"]
    log(f"[train] {args.epochs} epochs, head lr {args.lr}, backbone lr {args.backbone_lr}, "
          f"{'balanced' if args.balance else 'class-weighted'}"
          f"{', shift-augmented' if args.augment else ''}")
    for ep in range(1, args.epochs + 1):
        model.train()
        tot = n = correct = 0
        for xb, yb in tr_ld:
            xb, yb = xb.to(device), yb.to(device)
            sc = torch.ones(len(xb), 1, device=device)
            opt.zero_grad()
            out_logits = model(xb, sc)
            loss = crit(out_logits, yb)
            loss.backward()
            opt.step()
            tot += loss.item() * len(xb); n += len(xb)
            correct += (out_logits.argmax(1) == yb).sum().item()
        sched.step()
        tr_loss = tot / max(n, 1)
        tr_acc = correct / max(n, 1)      # running train accuracy over the epoch
        r = evaluate(model, va_ld, device)
        mark = ""
        saved = r["macro"] > best
        if saved:
            best = r["macro"]; torch.save(model.state_dict(), out); mark = "  *saved"
        log(f"[ep {ep:>3}] loss {tr_loss:.4f}  train-acc {tr_acc*100:.1f}%  "
              f"val top-1 {r['top1']*100:.1f}%  macro {r['macro']*100:.1f}%{mark}")
        # Write the curve after every epoch so a crash still leaves the history so far.
        history["epoch"].append({"ep": ep, "train_loss": tr_loss, "train_acc": tr_acc,
                                 "val_top1": r["top1"], "val_macro": r["macro"],
                                 "lr": sched.get_last_lr()[0], "saved": saved})
        hist_path.write_text(json.dumps(history, indent=2))

    _save_curve(history, curve_path)
    log()
    model.load_state_dict(torch.load(out, map_location=device, weights_only=True))
    fin = evaluate(model, va_ld, device)
    report("zero-shot", base)
    report("fine-tuned", fin)
    log(f"\n[result] macro {base['macro']*100:.1f}% -> {fin['macro']*100:.1f}% "
          f"({(fin['macro']-base['macro'])*100:+.1f} points)")
    cm = np.zeros((len(c.CLASSES), len(c.CLASSES)), dtype=int)
    for t, q in zip(fin["trues"], fin["preds"]):
        cm[t, q] += 1
    log("\nconfusion (rows = truth)")
    log("          " + " ".join(f"{n[:4]:>5}" for n in c.CLASSES))
    for i, n in enumerate(c.CLASSES):
        log(f"{n:<10}" + " ".join(f"{v:>5}" for v in cm[i]))
    log(f"\n[saved] {out}")
    log(f"[saved] history -> {hist_path}")
    log(f"[saved] curve   -> {curve_path}")
    return 0


class _Subset(Dataset):
    def __init__(self, x, y, idx, augment, shifts=None, shift_p=None, foreign_p=0.0):
        self.x, self.y, self.idx = x, y, idx
        # Donor pages come from the same training indices, never the holdout.
        self.ds = MapDataset(x, y, augment=augment, shifts=shifts, shift_p=shift_p,
                             foreign_p=foreign_p, pool=list(idx))

    def __len__(self):
        return len(self.idx)

    def __getitem__(self, i):
        return self.ds[self.idx[i]]


if __name__ == "__main__":
    sys.exit(main())
