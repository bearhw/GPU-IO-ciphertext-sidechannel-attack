#!/usr/bin/env python3
"""
train_pageset.py — 2MB 블록 통째로 먹는 순열 불변(page-set) 분류기 학습.

기존 모델과의 차이:
  기존: (64, 224, 56) — 채널 49페이지를 논리 순서대로 정렬한 깨끗한 입력.
        공격자는 이걸 만들 수 없다. 페이지가 어디에 어떤 순서로 놓였는지 모르니까.
  이것: (64, 512, C) — 2MB 블록의 512 페이지를 '집합'으로 입력.
        페이지 순서 무관, 이미지 시작 위치 무관, 이물질 페이지 섞여도 됨.
        전처리(offset 탐색 / 채널 구분 / content probe)가 전부 불필요해진다.

입력 조립 (on-the-fly):
  1. 기존 xor_cache_64 의 (64,224,56) bool 슬라이스를 (64, 49, 256) 로 재해석
     (12544 chunk = 49 페이지 × 페이지당 256 chunk)
  2. extract_layouts.py 가 뽑은 '실제 물리 배치'를 샘플링해 49페이지를 512슬롯에 흩뿌림
  3. 남은 슬롯은 이물질 페이지로 채움. 측정에 근거한 혼합:
       - zero 페이지: REF_U8_64[0]==0 이라 전 chunk가 ref-0에 매칭된다.
         (갓 할당된 페이지. 진짜 배경 픽셀과 헷갈리게 만드는 핵심 confound)
       - 고엔트로피 페이지: activation/weight. 어떤 ref와도 매칭 안 됨 → 전부 0
       - 다른 이미지 페이지: 같은 블록을 5~10장이 돌려쓰는 것이 측정됨

출력:
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
CH_PAGES = 49          # 이미지 한 채널이 차지하는 페이지 수
SLOTS = 512            # 2MB / 4KB
CHUNKS_PER_PAGE = 256  # 4096 / 16


def collect_labels(split):
    """xor_cache_64 를 만들 때와 동일한 glob 순서 → 캐시 인덱스와 1:1 대응."""
    labels = []
    for i, cls in enumerate(CLASSES):
        pat = str(DATA_ROOT / split / f"XR_{cls}" / "**" / "*.png")
        labels.extend([i] * len(glob.glob(pat, recursive=True)))
    return np.asarray(labels, dtype=np.int64)


class BlockDataset(Dataset):
    """(64, 224, 56) 채널 슬라이스 → (64, 512, chunks) 2MB 블록 슬라이스."""

    def __init__(self, slices_mm, aspects, labels, layouts, *,
                 chunk_pool=4, train=True, zero_frac=0.15, other_frac=0.25,
                 comp=None, recency=True, fp_ratio=0.8, seed=0):
        self.slices = slices_mm
        self.aspects = aspects
        self.labels = labels
        self.layouts = layouts              # (L, 49) int16, -1 = 블록 밖
        self.train = train
        self.pool = chunk_pool
        self.zero_frac = zero_frac
        self.other_frac = other_frac
        # v3: 실측 블록 조성 (composition.npz). layouts 와 인덱스 1:1.
        self.comp = comp
        self.recency = recency
        self.fp_ratio = fp_ratio
        self.n_chunk = CHUNKS_PER_PAGE // chunk_pool
        self.rng = np.random.default_rng(seed)
        # donor 회전 뱅크: 매 샘플 8회 memmap 읽기는 vCPU 1개에서 병목이라
        # 소수의 donor 를 캐시해두고 주기적으로 교체한다.
        self._bank = []
        self._bank_left = 0
        self._bg = {}          # li -> 미리 조립된 배경 캔버스 (다른이미지 + 비GT)
        self._bg_uses = {}
        self.bg_reuse = 24     # 배경 하나를 몇 샘플 재사용할지

    def __len__(self):
        return len(self.labels)

    def _background(self, li, rng):
        """배치 li 에 대한 배경(다른 이미지 + 비-GT) 캔버스를 캐시해 재사용.

        vCPU 1개 환경에서 샘플마다 512슬롯을 처음부터 채우는 건 감당이 안 된다.
        배경은 라벨과 무관하므로 재사용해도 정보 누수가 없고, bg_reuse 주기로
        교체해 다양성을 유지한다.
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
                nz = int(len(fr) * 0.35)      # zero 페이지 → ref-0 전 chunk 매칭
                if nz:
                    bg[fr[:nz], 0, :] = 1.0
            self._bg[li] = bg
            self._bg_uses[li] = 0
            if len(self._bg) > 48:            # 캐시 상한
                drop = next(iter(self._bg))
                self._bg.pop(drop); self._bg_uses.pop(drop, None)
        self._bg_uses[li] = self._bg_uses.get(li, 0) + 1
        return self._bg[li]

    def _donors(self, rng, k):
        """회전 donor 뱅크에서 k개 페이지 세트를 준다."""
        if self._bank_left <= 0 or len(self._bank) < k:
            self._bank = [self._pages_of(int(rng.integers(len(self.labels))))
                          for _ in range(max(k, 4))]
            self._bank_left = 32          # 32 샘플마다 교체
        self._bank_left -= 1
        return [self._bank[int(rng.integers(len(self._bank)))] for _ in range(k)]

    def _pages_of(self, idx):
        """캐시 슬라이스를 (49, 64, n_chunk) 페이지 단위로 — 풀링까지 여기서.

        풀링을 흩뿌리기 전에 끝내면 캔버스가 (512,64,256) 대신
        (512,64,n_chunk) 가 되어 pool=4 기준 메모리/연산이 1/4 로 준다.
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
            # 배경(다른 이미지 294p + 비-GT 121p)은 캐시에서 복사만 한다
            canvas = self._background(li, rng).copy()

            # 1) 타깃 채널: 실측 물리 배치대로 (블록 밖 페이지는 소실)
            canvas[tgt_slots, :N_REF] = img_pages[np.flatnonzero(valid)]

            # 2) 같은 이미지의 다른 채널 (R=G=B 동일 → 복제). 같은 라벨 = 추가 신호.
            same = np.setdiff1d(np.flatnonzero(self.comp["same_slots"][li]), tgt_slots)
            if len(same):
                canvas[same, :N_REF] = img_pages[rng.integers(CH_PAGES, size=len(same))]
            recent_true = np.concatenate([tgt_slots, same]) if len(same) else tgt_slots
        else:
            # 구버전 경로 (v1/v2 재현용)
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

        # 5) recency 채널: '이번 추론 burst 에 쓰인 페이지인가'.
        #    write 트레이스로 실제 얻을 수 있는 정보이며, 블록에 이미지가
        #    5~10장 섞여 있을 때 '현재 이미지'를 가르는 유일한 단서다.
        #    측정된 시간 그룹핑 성능을 잡음으로 반영: recall 중앙값 100%,
        #    p25 94%, p10 49% / 그룹 precision ~0.45 → 위양성도 넣는다.
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
    """페이지 하나(64 ref × chunk)를 임베딩으로. 페이지끼리 파라미터 공유.

    v2: 언더피팅(train 0.60 / val 0.48)이 관측되어 conv 한 단 추가 + 폭 확대.
    GPU 사용률이 10%대라 모델을 키워도 벽시계 시간은 거의 늘지 않는다.
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
    """순열 불변: 페이지별 인코딩 → attention pooling → 분류."""

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
        strongest = e.max(dim=1).values                 # 가장 이미지다운 페이지
        return self.head(torch.cat([pooled, strongest, aspect], dim=1))

    def page_scores(self, x):
        """진단용: 어느 페이지에 주목했는지 (B, P)."""
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
                    help="chunk 축 풀링 배수 (클수록 가볍고 정보 손실)")
    ap.add_argument("--limit-train", type=int, default=None,
                    help="학습 샘플 수 제한 (CPU 시험용)")
    ap.add_argument("--limit-val", type=int, default=None)
    ap.add_argument("--dim", type=int, default=384,
                    help="페이지 임베딩 차원 (v1=192, v2=384)")
    ap.add_argument("--no-recency", action="store_true",
                    help="recency 채널(현재 burst 여부) 끄기")
    ap.add_argument("--no-composition", action="store_true",
                    help="실측 블록 조성 대신 v1/v2 합성 조성 사용")
    ap.add_argument("--fp-ratio", type=float, default=0.8,
                    help="recency 위양성 비율 (시간 그룹핑 precision~0.45 반영)")
    ap.add_argument("--weight-decay", type=float, default=3e-4)
    ap.add_argument("--label-smooth", type=float, default=0.05)
    ap.add_argument("--no-class-weight", action="store_true",
                    help="클래스 불균형 보정 끄기")
    ap.add_argument("--workers", type=int, default=4)
    ap.add_argument("--out", type=Path, default=HERE / "pageset_64ref.pth")
    ap.add_argument("--layouts", type=Path, default=HERE / "layouts.npz")
    args = ap.parse_args()

    dev = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    print(f"device={dev}  (GPU 없으면 --limit-train 으로 규모를 줄여라)", flush=True)

    layouts = np.load(args.layouts)["slots"]
    print(f"실측 배치 {len(layouts)}개 로드", flush=True)

    comp = None
    if not args.no_composition:
        cpath = HERE / "composition.npz"
        if cpath.exists():
            c = np.load(cpath)
            comp = {"same_slots": c["same_slots"], "other_slots": c["other_slots"]}
            print(f"실측 블록 조성 로드: 타깃 {int(np.median(c['n_target']))}p / "
                  f"같은이미지 {int(np.median(c['n_same_img']))}p / "
                  f"다른이미지 {int(np.median(c['n_other_img']))}p (중앙값)", flush=True)
        else:
            print("composition.npz 없음 → 합성 조성으로 진행", flush=True)
    recency = not args.no_recency
    n_in = N_REF + (1 if recency else 0)
    print(f"입력 채널 = {n_in} (ref {N_REF}" + (" + recency 1)" if recency else ")"),
          flush=True)

    tr_s = np.lib.format.open_memmap(CACHE / "tr_slices.npy", mode="r")
    va_s = np.lib.format.open_memmap(CACHE / "va_slices.npy", mode="r")
    tr_a = np.load(CACHE / "tr_aspects.npy")
    va_a = np.load(CACHE / "va_aspects.npy")
    tr_y = collect_labels("train")
    va_y = collect_labels("valid")
    assert len(tr_y) == tr_s.shape[0] and len(va_y) == va_s.shape[0], \
        "캐시와 라벨 개수 불일치 — 데이터셋 경로/순서를 확인해라"

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
    # 클래스 불균형 보정: FOREARM(301)/HUMERUS(288) 가 다수 클래스에 흡수돼
    # recall 0.3%/4.9% 로 붕괴했었다. 역빈도 가중치로 되살린다.
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
