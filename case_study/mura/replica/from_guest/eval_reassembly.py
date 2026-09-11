#!/usr/bin/env python3
"""
eval_reassembly.py — write-순서 재조립 공격의 최종 평가 + confusion matrix.

공격 절차:
  1. host write 트레이스에서 연속된 49-write 버스트를 잘라낸다
     (채널의 90% 가 외부 write 0개로 연달아 나타난다)
  2. 등장 '순서대로' 페이지를 이어붙인다 — 물리 주소는 무시
     (물리 연속은 29% 뿐이지만 시간 연속은 90%)
  3. 그 순서는 논리 순서와 정순 75% / 역순 24% 로 일치한다.
     역순이면 조립본이 뒤집혀 있으므로 되뒤집어야 한다.
  4. (224,56) 격자로 재조립해 분류

평가 설계 (중요):
  --sim-reverse-rate 로 '실제로 역순 조립된 관측' 을 실측 비율(24%)만큼 만든다.
  이렇게 해야 방향 처리의 이득과 손실을 공정하게 잴 수 있다. 이게 없으면
  모든 샘플이 정순이라 어떤 방향 탐색도 손해로만 보인다.

비교 모드:
  --order none       방향 처리 없음 (역순 샘플은 뒤집힌 채 분류)
  --order oracle     정답 방향을 안다고 가정 (상한)
  --order softmax    두 후보 중 max-softmax 높은 쪽 (실측상 부적절)
  --order model      방향 판별기로 결정 (--direction-ckpt 필요)
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
    """(확률, 라벨, 확보페이지비율, 실제역순여부)."""
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
                    help="실제 역순 조립 비율 (실측 24%%)")
    ap.add_argument("--layouts", type=Path, default=HERE / "layouts.npz")
    ap.add_argument("--batch", type=int, default=64)
    ap.add_argument("--workers", type=int, default=1)
    ap.add_argument("--limit", type=int, default=None)
    ap.add_argument("--no-degrade", action="store_true", help="열화 없이 (상한)")
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
          f"sim_reverse={args.sim_reverse_rate:.2f}  열화={'on' if degrade else 'off'}",
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

    # 그대로 분류한 결과 / 되뒤집어 분류한 결과 (같은 seed 라 열화·역순여부 동일)
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
            raise SystemExit("--order model 에는 --direction-ckpt 가 필요하다")
        dm = XorSliceResNet(2, N_REF).to(dev)
        dsd = torch.load(args.direction_ckpt, map_location=dev, weights_only=False)
        dm.load_state_dict(dsd["model"] if isinstance(dsd, dict) and "model" in dsd
                           else dsd)
        dprob, _, _, _ = predict(dm, loader(False), dev)
        use_undo = dprob.argmax(1) == 1
        da = (use_undo.numpy() == is_rev.astype(bool)).mean()
        print(f"방향 판별기 {args.direction_ckpt.name}: "
              f"이번 평가셋 방향 정확도 {da:.4f}", flush=True)

    pred = torch.where(use_undo, p_un.argmax(1), p_as.argmax(1)).numpy()

    n = len(CLASSES)
    cm = np.zeros((n, n), dtype=int)
    for t_, p_ in zip(y_true, pred):
        cm[t_, p_] += 1
    acc = (y_true == pred).mean()
    bal = float(np.mean([cm[i, i] / max(cm[i].sum(), 1) for i in range(n)]))

    print(f"\naccuracy = {acc:.4f}  balanced = {bal:.4f}  "
          f"({(y_true == pred).sum()}/{len(y_true)})")
    print(f"평균 확보 페이지 = {kf.mean()*49:.1f}/49 ({kf.mean()*100:.0f}%)")
    print(f"실제 역순 = {is_rev.sum()}/{len(is_rev)} ({100*is_rev.mean():.0f}%)  "
          f"| 되뒤집기 적용 = {int(use_undo.sum())} ({100*float(use_undo.float().mean()):.0f}%)")
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
