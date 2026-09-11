#!/usr/bin/env python3
"""
extract_composition.py — 실제 2MB 블록의 '구성'을 뽑는다.

extract_layouts.py 가 '타깃 채널 49p 가 어느 슬롯에 놓이나'를 줬다면,
이건 '그 블록의 나머지 463 슬롯에 뭐가 들어있나'를 준다. 측정값:
    타깃 채널        중앙값  48p
    같은 이미지 다른채널 중앙값  81p   ← 같은 라벨, 추가 신호
    다른 이미지        중앙값 294p   ← 다른 라벨, 교란
    비-GT             중앙값 121p

layouts.npz 와 인덱스가 1:1 대응한다 (같은 순회 순서).

출력: composition.npz
  n_target / n_same_img / n_other_img : (N,) int16
  same_slots  : (N, 512) bool — 같은 이미지 다른 채널이 놓인 슬롯
  other_slots : (N, 512) bool — 다른 이미지 페이지가 놓인 슬롯
"""
import re
from collections import defaultdict
from pathlib import Path
import numpy as np

PAGE, BLOCK = 0x1000, 0x200000
SLOTS, CH_PAGES = BLOCK // PAGE, 49
RE = re.compile(r'\[GPA_PAGE\] iter(\d+)/input img=(\d+) ch=([RGB]) ch_pg=(\d+) GPA=0x([0-9a-f]+)')
LOGS = sorted(Path("/home/eun/esp_bak/sev-step/userspace/write-tracker/mura")
              .glob("mura_guest_nomul_*_raw.log"))

nt, ns, no = [], [], []
same_slots, other_slots = [], []

for lp in LOGS:
    ch = defaultdict(dict)
    for line in open(lp, errors="ignore"):
        m = RE.search(line)
        if m:
            ch[(int(m.group(1)), int(m.group(2)), m.group(3))][int(m.group(4))] = \
                int(m.group(5), 16) & ~(PAGE - 1)
    owner = {}
    for k, d in ch.items():
        for p in d.values():
            owner[p] = k

    for k, d in sorted(ch.items()):
        if len(d) != CH_PAGES:
            continue
        pages = list(d.values())
        cand = defaultdict(int)
        for p in pages:
            cand[(p // BLOCK) * BLOCK] += 1
        base = max(cand, key=cand.get)

        s_mask = np.zeros(SLOTS, dtype=bool)
        o_mask = np.zeros(SLOTS, dtype=bool)
        t = s = o = 0
        for p, ow in owner.items():
            if (p // BLOCK) * BLOCK != base:
                continue
            slot = (p - base) // PAGE
            if ow == k:
                t += 1
            elif ow[:2] == k[:2]:
                s += 1; s_mask[slot] = True
            else:
                o += 1; o_mask[slot] = True
        nt.append(t); ns.append(s); no.append(o)
        same_slots.append(s_mask); other_slots.append(o_mask)

out = Path(__file__).parent / "composition.npz"
np.savez_compressed(
    out,
    n_target=np.array(nt, dtype=np.int16),
    n_same_img=np.array(ns, dtype=np.int16),
    n_other_img=np.array(no, dtype=np.int16),
    same_slots=np.stack(same_slots),
    other_slots=np.stack(other_slots),
)
print(f"채널 {len(nt)}개 → {out}")
print(f"  타깃 중앙값 {int(np.median(nt))}p, 같은이미지 {int(np.median(ns))}p, "
      f"다른이미지 {int(np.median(no))}p")
