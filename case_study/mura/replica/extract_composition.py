#!/usr/bin/env python3
"""
extract_composition.py — Extract the 'composition' of actual 2MB blocks.

While extract_layouts.py provided 'which slots the target 49p channels occupy',
this provides 'what is inside the remaining 463 slots of that block'. Measured values:
    Target channel               median  48p
    Same image, other channels   median  81p   <- Same label, additional signal
    Other images                 median 294p   <- Different label, confounder
    Non-GT                       median 121p

1:1 correspondence with layouts.npz index (same iteration order).

Outputs: composition.npz
  n_target / n_same_img / n_other_img : (N,) int16
  same_slots  : (N, 512) bool — slots containing other channels of same image
  other_slots : (N, 512) bool — slots containing pages from other images
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
print(f"Channels {len(nt)} -> {out}")
print(f"  Target median {int(np.median(nt))}p, same image {int(np.median(ns))}p, "
      f"other images {int(np.median(no))}p")
