#!/usr/bin/env python3
"""
reassembly_common.py — write-순서 페이지 재조립 공격의 공용 모듈.

배경 (write 트레이스 실측, 채널 411개):
  - 채널 = 49 페이지. 물리적으로 연속인 건 29% 뿐이라 주소로는 못 모은다.
  - 그러나 스트림에서는 90% 가 '외부 write 0개인 49연속 write' 로 나타난다.
  - 그 등장 순서가 논리 순서(ch_pg 0..48)와 일치: 정순 75% / 역순 24% / 기타 1%.
  → 공격자는 물리 주소를 무시하고 '쓰인 순서대로' 이어붙이면 채널을 복원한다.
    정순/역순 두 후보만 시도하면 99% 를 덮는다.

공격자 관점의 열화 (모두 실측값):
  1. 페이지 소실 — 지배 2MB 블록 밖으로 나간 페이지는 못 얻는다.
     (layouts.npz: n_valid 중앙값 49/49, 평균 45.1, 49개 전부는 58%)
  2. 시간 그룹핑 누락 — 블록 안이어도 burst 그룹에서 빠질 수 있다.
     (채널 recall 중앙값 100%, p25 94%, p10 49%)
  3. 순서 모호성 — 정순/역순. 학습은 정순만, 추론에서 두 후보 confidence 비교.
  4. 종횡비 미상 — 공격자는 원본 aspect 를 모르므로 학습셋 평균을 prior 로 쓴다.

복원 실패한 페이지는 0 으로 둔다 (어떤 ref 와도 매칭 없음 = 관측 없음).
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
    """xor_cache_64 생성 때와 같은 glob 순서 → 캐시 인덱스와 1:1."""
    labels = []
    for i, cls in enumerate(CLASSES):
        pat = str(DATA_ROOT / split / f"XR_{cls}" / "**" / "*.png")
        labels.extend([i] * len(glob.glob(pat, recursive=True)))
    return np.asarray(labels, dtype=np.int64)


# ── 재조립 데이터셋 ───────────────────────────────────────────────────────────
class ReassemblyDataset(Dataset):
    """캐시 슬라이스에 '공격자가 겪는 열화'를 씌워 재조립 입력을 만든다.

    출력은 원본 모델과 동일한 (64, 224, 56) 이므로 기존 XorSliceResNet 을
    그대로 쓰거나 fine-tune 할 수 있다.
    """

    def __init__(self, slices_mm, labels, layouts, *, train=True,
                 aspect_prior=1.339, degrade=True, reverse=False,
                 sim_reverse_rate=0.0, undo=False, seed=0):
        self.slices = slices_mm
        self.labels = labels
        self.layouts = layouts          # (L, 49) int16, -1 = 지배 블록 밖
        self.train = train
        self.aspect_prior = float(aspect_prior)
        self.degrade = degrade
        self.reverse = reverse          # 역순 가설로 재조립 (추론 시 사용)
        # sim_reverse_rate: 이 비율만큼 '실제로 역순으로 조립된' 관측을 만든다.
        #   공격자가 보는 배열 X = flip(clean) 이 되는 경우. 실측 24%.
        # undo: X 를 다시 뒤집어 정순 복원을 시도 (방향 판별기가 역순이라 판단한 경우)
        self.sim_reverse_rate = float(sim_reverse_rate)
        self.undo = undo
        self.rng = np.random.default_rng(seed)

    def __len__(self):
        return len(self.labels)

    def keep_mask(self, rng):
        """이번 샘플에서 실제로 복원되는 논리 페이지 마스크."""
        keep = np.ones(CH_PAGES, dtype=bool)
        if not self.degrade:
            return keep
        # (1) 지배 블록 밖 페이지 소실 — 실측 배치에서 추출
        lay = self.layouts[rng.integers(len(self.layouts))]
        keep &= (lay >= 0)
        # (2) 시간 그룹핑 누락 — 채널 recall 중앙값 100%, p10 49%
        if rng.random() < 0.5:
            keep &= (rng.random(CH_PAGES) < rng.uniform(0.49, 1.0))
        return keep

    def __getitem__(self, idx):
        rng = self.rng if self.train else np.random.default_rng(idx)

        sl = np.asarray(self.slices[idx])                       # (64,224,56) bool
        pages = sl.reshape(N_REF, CH_PAGES, CHUNKS_PER_PAGE)    # (64,49,256)

        keep = self.keep_mask(rng)
        rec = np.where(keep[None, :, None], pages, False)

        # (a) 실제 관측 생성: sim_reverse_rate 확률로 역순 조립본이 관측된다
        is_rev = (self.sim_reverse_rate > 0
                  and rng.random() < self.sim_reverse_rate)
        if is_rev:
            rec = rec[:, ::-1, :]

        # (b) 공격자 측 조작: undo 는 되뒤집기, reverse 는 역순 가설 생성
        if self.undo or self.reverse:
            rec = rec[:, ::-1, :]

        x = np.ascontiguousarray(rec.reshape(N_REF, XOR_ROWS, XOR_COLS),
                                 dtype=np.float32)
        return (torch.from_numpy(x),
                torch.tensor([self.aspect_prior], dtype=torch.float32),
                self.labels[idx],
                np.float32(keep.mean()),
                np.int64(is_rev))


# ── 모델 (train_64ref.py 의 XorSliceResNet 과 동일 구조) ──────────────────────
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
        f"{split}: 캐시 {slices.shape[0]} vs 라벨 {len(labels)} 불일치"
    return slices, labels


def train_aspect_prior():
    """공격자가 쓸 수 있는 유일한 종횡비 정보 = 학습셋 평균."""
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
                    fontsize=10, color="white" if v > 0.5 else "#222")
    cb = fig.colorbar(im, ax=ax, fraction=0.046, pad=0.04)
    cb.set_label("row-normalized", fontsize=11)
    fig.tight_layout()
    for ext in ("png", "pdf"):
        fig.savefig(f"{out_stem}.{ext}", dpi=200 if ext == "png" else None,
                    bbox_inches="tight")
        print(f"saved: {out_stem}.{ext}")
    plt.close(fig)
