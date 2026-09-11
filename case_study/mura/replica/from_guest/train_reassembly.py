#!/usr/bin/env python3
"""
train_reassembly.py — write-순서로 재조립한 (열화된) 입력으로 분류기 학습.

왜 이게 맞는 설계인가:
  앞서 만든 순열 불변 page-set 모델은 val 48.6% 에 그쳤다. 페이지 순서를
  '모른다'고 가정하고 불변성을 강제했기 때문이다. 그러나 write 트레이스는
  순서를 실제로 알려준다 (정순 75% / 역순 24%). 그 정보를 되살려 (224,56)
  격자를 복원하면 clean 모델이 그대로 76.95% 를 낸다.

  다만 clean 모델은 '완전한 49페이지'로 학습돼 있어 페이지 소실에 취약하다.
  여기서는 소실을 포함한 재조립 입력으로 학습해 그 열화에 맞춘다.

기본은 기존 체크포인트에서 fine-tune (수렴이 훨씬 빠르다).
  python train_reassembly.py --init ../mura_xor_slice_64ref.pth --epochs 12

출력: reassembly_64ref.pth  (best val acc)
"""
import argparse
import time
from pathlib import Path

import numpy as np
import torch
import torch.nn as nn
from torch.utils.data import DataLoader, Subset

from reassembly_common import (
    CLASSES, N_REF, ReassemblyDataset, XorSliceResNet,
    load_cache, train_aspect_prior, HERE,
)


def evaluate(model, loader, dev, n_cls):
    """정순 가설만으로 평가 (학습 중 모니터링용). 최종 평가는 eval_reassembly.py."""
    model.eval()
    cm = np.zeros((n_cls, n_cls), dtype=int)
    with torch.no_grad():
        for x, sc, y, *_ in loader:
            pred = model(x.to(dev), sc.to(dev)).argmax(1).cpu().numpy()
            for t_, p_ in zip(y.numpy(), pred):
                cm[t_, p_] += 1
    acc = np.trace(cm) / max(cm.sum(), 1)
    bal = float(np.mean([cm[i, i] / max(cm[i].sum(), 1) for i in range(n_cls)]))
    return acc, bal


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--init", type=Path,
                    help="기존 clean 체크포인트에서 fine-tune (권장)")
    ap.add_argument("--epochs", type=int, default=12)
    ap.add_argument("--batch", type=int, default=32)
    ap.add_argument("--lr", type=float, default=1e-4)
    ap.add_argument("--weight-decay", type=float, default=1e-4)
    ap.add_argument("--label-smooth", type=float, default=0.05)
    ap.add_argument("--no-class-weight", action="store_true")
    ap.add_argument("--no-degrade", action="store_true",
                    help="열화 없이 학습 (상한 확인용)")
    ap.add_argument("--limit-train", type=int, default=None)
    ap.add_argument("--limit-val", type=int, default=None)
    ap.add_argument("--workers", type=int, default=1)
    ap.add_argument("--layouts", type=Path, default=HERE / "layouts.npz")
    ap.add_argument("--out", type=Path, default=HERE / "reassembly_64ref.pth")
    args = ap.parse_args()

    dev = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    layouts = np.load(args.layouts)["slots"]
    prior = train_aspect_prior()
    print(f"device={dev}  실측 배치 {len(layouts)}개  aspect prior={prior:.3f}", flush=True)

    tr_s, tr_y = load_cache("train")
    va_s, va_y = load_cache("valid")
    degrade = not args.no_degrade

    tr_ds = ReassemblyDataset(tr_s, tr_y, layouts, train=True,
                              aspect_prior=prior, degrade=degrade)
    va_ds = ReassemblyDataset(va_s, va_y, layouts, train=False,
                              aspect_prior=prior, degrade=degrade)

    tr_idx = np.arange(len(tr_y)); va_idx = np.arange(len(va_y))
    if args.limit_train:
        tr_idx = np.random.default_rng(0).choice(
            tr_idx, size=min(args.limit_train, len(tr_idx)), replace=False)
    if args.limit_val:
        va_idx = np.random.default_rng(1).choice(
            va_idx, size=min(args.limit_val, len(va_idx)), replace=False)
    tr_ds, va_ds = Subset(tr_ds, tr_idx.tolist()), Subset(va_ds, va_idx.tolist())
    print(f"train {len(tr_ds):,}  valid {len(va_ds):,}  "
          f"열화={'on' if degrade else 'off'}", flush=True)

    tr_ld = DataLoader(tr_ds, batch_size=args.batch, shuffle=True,
                       num_workers=args.workers, pin_memory=(dev.type == "cuda"))
    va_ld = DataLoader(va_ds, batch_size=args.batch, shuffle=False,
                       num_workers=args.workers, pin_memory=(dev.type == "cuda"))

    model = XorSliceResNet(len(CLASSES), N_REF).to(dev)
    if args.init:
        sd = torch.load(args.init, map_location=dev, weights_only=False)
        model.load_state_dict(sd if not isinstance(sd, dict) or "model" not in sd
                              else sd["model"])
        print(f"init from {args.init.name} (fine-tune)", flush=True)
    print(f"params={sum(p.numel() for p in model.parameters()):,}", flush=True)

    if args.no_class_weight:
        crit = nn.CrossEntropyLoss(label_smoothing=args.label_smooth)
        print("class weight: off", flush=True)
    else:
        cnt = np.bincount(tr_y[tr_idx], minlength=len(CLASSES)).astype(np.float64)
        w = cnt.sum() / (len(CLASSES) * np.maximum(cnt, 1))
        crit = nn.CrossEntropyLoss(
            weight=torch.tensor(w, dtype=torch.float32, device=dev),
            label_smoothing=args.label_smooth)
        print("class weight: " + "  ".join(f"{c}={v:.2f}"
                                           for c, v in zip(CLASSES, w)), flush=True)

    opt = torch.optim.AdamW(model.parameters(), lr=args.lr,
                            weight_decay=args.weight_decay)
    sched = torch.optim.lr_scheduler.CosineAnnealingLR(opt, T_max=args.epochs)

    base_acc, base_bal = evaluate(model, va_ld, dev, len(CLASSES))
    print(f"[fine-tune 전] val {base_acc:.4f}  bal {base_bal:.4f}", flush=True)

    best = base_acc
    for ep in range(1, args.epochs + 1):
        model.train()
        t0, tot, corr, ls, kf = time.time(), 0, 0, 0.0, []
        for x, sc, y, k, _ in tr_ld:
            x, sc, y = x.to(dev), sc.to(dev), y.to(dev)
            opt.zero_grad()
            out = model(x, sc)
            loss = crit(out, y)
            loss.backward()
            opt.step()
            ls += loss.item() * y.size(0)
            corr += (out.argmax(1) == y).sum().item()
            tot += y.size(0)
            kf.append(float(k.mean()))
        acc, bal = evaluate(model, va_ld, dev, len(CLASSES))
        sched.step()

        flag = ""
        if acc > best:
            best = acc
            torch.save({"model": model.state_dict(), "n_ref": N_REF,
                        "classes": CLASSES, "aspect_prior": prior,
                        "degrade": degrade, "val_acc": best}, args.out)
            flag = "  *saved"
        print(f"ep{ep:>3}  loss {ls/max(tot,1):.4f}  train {corr/max(tot,1):.4f}  "
              f"val {acc:.4f}  bal {bal:.4f}  pages {np.mean(kf)*100:.0f}%  "
              f"{time.time()-t0:.0f}s{flag}", flush=True)

    print(f"\nbest val acc = {best:.4f} → {args.out}")


if __name__ == "__main__":
    main()
