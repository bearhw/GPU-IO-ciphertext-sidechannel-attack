#!/usr/bin/env python3
"""
extract_layouts.py — replica 학습용 '실제 물리 페이지 배치' 추출.

왜 필요한가:
  공격자가 보는 것은 깔끔한 49페이지 텐서가 아니라 2MB 블록(512페이지) 안에
  흩어진 페이지들이다. 측정 결과:
    - 채널 49페이지가 물리적으로 완전 연속인 경우는 29%뿐
    - ch_pg(논리) 순서가 물리 오름차순인 경우는 38%
    - 나머지는 512슬롯 안에 임의로 흩어짐
  따라서 학습 데이터도 같은 방식으로 흩뿌려야 실전에서 동작한다.

무엇을 하는가:
  guest GT 로그(mura_guest_nomul_*_raw.log)에서 각 채널의 실제 배치를 뽑는다.
  채널 하나 = 논리 페이지 0..48 이 2MB 블록 안 어느 슬롯(0..511)에 놓였는지의 맵.

출력:
  layouts.npz
    slots   : (N, 49) int16  — 논리 페이지 i가 놓인 블록 내 슬롯. 블록 밖이면 -1
    n_valid : (N,)    int16  — 지배 블록 안에 들어온 페이지 수
"""
import argparse
import re
from collections import defaultdict
from pathlib import Path

import numpy as np

PAGE = 0x1000
BLOCK = 0x200000
SLOTS = BLOCK // PAGE          # 512
CH_PAGES = 49                  # 224*224*4 / 4096

RE_GPA_PAGE = re.compile(
    r'\[GPA_PAGE\] iter(\d+)/input img=(\d+) ch=([RGB]) ch_pg=(\d+) GPA=0x([0-9a-f]+)'
)

DEFAULT_LOGS = sorted(
    Path("/home/eun/esp_bak/sev-step/userspace/write-tracker/mura").glob(
        "mura_guest_nomul_*_raw.log")
)


def parse_channels(log_path):
    """(iter, img, ch) -> {ch_pg: page_aligned_gpa}"""
    chans = defaultdict(dict)
    with open(log_path, errors="ignore") as f:
        for line in f:
            m = RE_GPA_PAGE.search(line)
            if not m:
                continue
            key = (int(m.group(1)), int(m.group(2)), m.group(3))
            chans[key][int(m.group(4))] = int(m.group(5), 16) & ~(PAGE - 1)
    return chans


def layout_of(pages_by_chpg):
    """논리 페이지 -> 블록 슬롯. 지배 블록(가장 많은 페이지를 담은 2MB) 기준."""
    if len(pages_by_chpg) != CH_PAGES:
        return None
    blocks = defaultdict(int)
    for gpa in pages_by_chpg.values():
        blocks[(gpa // BLOCK) * BLOCK] += 1
    base = max(blocks, key=blocks.get)

    slots = np.full(CH_PAGES, -1, dtype=np.int16)
    for ch_pg, gpa in pages_by_chpg.items():
        if (gpa // BLOCK) * BLOCK == base:
            slots[ch_pg] = (gpa - base) // PAGE
    return slots


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--logs", nargs="*", type=Path, default=DEFAULT_LOGS,
                    help="guest GT 로그들 (기본: write-tracker/mura 의 mura_guest_nomul_*_raw.log)")
    ap.add_argument("--out", type=Path, default=Path(__file__).parent / "layouts.npz")
    args = ap.parse_args()

    if not args.logs:
        raise SystemExit("guest 로그를 찾지 못했다. --logs 로 직접 지정해라.")

    all_slots = []
    for lp in args.logs:
        chans = parse_channels(lp)
        n_ok = 0
        for key, pages in sorted(chans.items()):
            s = layout_of(pages)
            if s is not None:
                all_slots.append(s)
                n_ok += 1
        print(f"  {lp.name}: 채널 {len(chans)}개 → 배치 {n_ok}개")

    if not all_slots:
        raise SystemExit("배치를 하나도 못 뽑았다.")

    slots = np.stack(all_slots)                       # (N, 49)
    n_valid = (slots >= 0).sum(axis=1).astype(np.int16)

    # 통계 (스크립트가 실제로 뭘 뽑았는지 확인용)
    contiguous = 0
    ascending = 0
    for s in slots:
        v = s[s >= 0]
        if len(v) == CH_PAGES:
            if np.all(np.diff(np.sort(v)) == 1):
                contiguous += 1
            if np.all(np.diff(v) > 0):
                ascending += 1

    np.savez_compressed(args.out, slots=slots, n_valid=n_valid)
    print(f"\n총 배치 {len(slots)}개 → {args.out}")
    print(f"  지배 블록 안 페이지 수: 중앙값 {int(np.median(n_valid))}/49, "
          f"최소 {n_valid.min()}, 49개 전부: {(n_valid == CH_PAGES).sum()}")
    print(f"  물리 완전 연속 : {contiguous}/{len(slots)} ({100*contiguous/len(slots):.0f}%)")
    print(f"  논리=물리 오름차순: {ascending}/{len(slots)} ({100*ascending/len(slots):.0f}%)")


if __name__ == "__main__":
    main()
