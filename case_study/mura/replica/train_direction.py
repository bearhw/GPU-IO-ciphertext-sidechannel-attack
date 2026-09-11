#!/usr/bin/env python3
"""
train_direction.py — 재조립 방향(정순/역순) 판별기.

왜 필요한가:
  write 순서로 이어붙인 배열이 논리 순서와 같은지(정순 75%) 뒤집혔는지(역순 24%)
  공격자는 모른다. 두 후보를 모두 분류기에 넣고 max-softmax 로 고르는 방식은
  실측에서 오히려 손해였다:
      clean 모델      66.91% → 58.18%  (역순 33% 채택, 실제 24%)
      fine-tune 모델  80.11% → 74.35%  (역순 19% 채택, 실제 24%)
  max-softmax 는 방향 판별 기준으로 부적절하다. 그래서 방향만 맞히는 전용
  이진 분류기를 따로 학습한다.

무엇을 학습하나:
  입력  : 재조립된 (64,224,56) — 실측 열화 적용
  라벨  : 0 = 정순, 1 = 역순(페이지 순서가 뒤집힌 채 조립됨)
  주의  : 페이지 역순은 '이미지 상하 반전'이 아니다. 4096바이트(≈4.57 픽셀행)
          단위로 블록 반전되고 페이지 내부 행 순서는 유지된다. 그 인공물이
          오히려 뚜렷한 단서가 된다.

출력: direction_64ref.pth
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
    """같은 이미지를 정순/역순 두 라벨로 만들어 방향 판별을 학습시킨다."""

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

        y = int(rng.integers(2))          # 0=정순, 1=역순
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
                    help="body-part 체크포인트에서 backbone 초기화 (head 제외)")
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
    print(f"device={dev}  실측 배치 {len(layouts)}개  aspect prior={prior:.3f}",
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

    model = XorSliceResNet(2, N_REF).to(dev)       # 2-class: 정순 / 역순
    if args.init:
        sd = torch.load(args.init, map_location=dev, weights_only=False)
        sd = sd["model"] if isinstance(sd, dict) and "model" in sd else sd
        sd = {k: v for k, v in sd.items() if not k.startswith("head.")}
        missing, unexpected = model.load_state_dict(sd, strict=False)
        print(f"init backbone from {args.init.name} "
              f"(head 새로 학습, missing={len(missing)})", flush=True)
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
