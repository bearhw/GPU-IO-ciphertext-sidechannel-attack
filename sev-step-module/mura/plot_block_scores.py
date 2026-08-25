#!/usr/bin/env python3
"""
MURA memory-map view: the 256GB guest physical space is tiled into 2MB blocks
(131,072 of them). For each run we score every ACTIVE block by S = H x R
(hits x max contiguous run length) and plot it as a stem at its GPA. The image
buffer blocks (GT) are gold; the tallest stem = the block the attack selects.
This shows "out of the whole 256GB, this 2MB block wins on score -> image".
"""
import re
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D

HOST = re.compile(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)')
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
B_LO, B_HI = 0x3f80000000, 0x3f90000000
PAGE = 0x1000
AL = 0x200000
GIB = 1024 ** 3
TOTAL_BLOCKS = 256 * GIB // AL
GT_COL, FP_COL = '#e6a817', '#9fb6c7'


def parse_host(p):
    w = []
    for line in open(p):
        if line.startswith("WRITE"):
            m = HOST.search(line)
            if m:
                w.append((int(m.group(1), 16), int(m.group(2))))
    return w


def mura_gt(run):
    s = set()
    for line in open(f"mura_guest_nomul_{run}_raw.log"):
        m = re.search(r'\[GPA_PAGE\] iter\d+/input .+ GPA=0x([0-9a-f]+)', line)
        if m:
            s.add((int(m.group(1), 16) & ~(PAGE - 1)) & ~(AL - 1))
    return s


def detect_free(writes):
    cand = {}
    base = length = 0

    def fin():
        nonlocal base, length
        if length >= 2:
            al = base & ~(AL - 1)
            c = cand.get(al)
            if c:
                c[0] += 1
                if length > c[1]:
                    c[1] = length
            else:
                cand[al] = [1, length]

    for g, t in writes:
        if A_LO <= g < A_HI or B_LO <= g < B_HI:
            fin(); base = length = 0; continue
        if length == 0:
            base, length = g, 1
        else:
            exp = base + length * PAGE
            if g == exp:
                length += 1
            elif g > exp and (g - exp) // PAGE <= 2:
                length += (g - exp) // PAGE + 1
            else:
                fin(); base, length = g, 1
    fin()
    return cand


fig, axes = plt.subplots(5, 1, figsize=(13, 13))

for ax, run in zip(axes, range(1, 6)):
    w = parse_host(f"mura_host_regB_{run}.log")
    gt = mura_gt(run)
    cand = detect_free(w)
    blocks = [(al, h * r, h, r, al in gt) for al, (h, r) in cand.items()]
    blocks.sort(key=lambda x: -x[1])
    top_al, top_s, *_ , top_isgt = blocks[0]
    gt_rank = next((i + 1 for i, b in enumerate(blocks) if b[4]), None)

    xs_fp = [al / GIB for al, s, h, r, g in blocks if not g]
    ys_fp = [s for al, s, h, r, g in blocks if not g]
    xs_gt = [al / GIB for al, s, h, r, g in blocks if g]
    ys_gt = [s for al, s, h, r, g in blocks if g]

    ax.vlines(xs_fp, 0, ys_fp, color=FP_COL, lw=1.0, alpha=0.8, zorder=2)
    ax.vlines(xs_gt, 0, ys_gt, color=GT_COL, lw=2.2, zorder=4)
    ax.scatter(xs_gt, ys_gt, s=22, color=GT_COL, zorder=5,
               edgecolor='#8a6d0b', linewidth=0.5)

    # selected block (#1) callout
    sel_ok = top_isgt
    star_col = '#c0392b' if sel_ok else '#7f8c8d'
    ax.scatter([top_al / GIB], [top_s], marker='*', s=260, color=star_col,
               edgecolor='white', linewidth=0.8, zorder=6)
    tag = 'IMAGE ✓' if sel_ok else 'FP ✗ (image is #%d)' % gt_rank
    ax.annotate(f'#1 selected  0x{top_al:x}\nscore={top_s:,} = H×R  [{tag}]',
                (top_al / GIB, top_s), xytext=(12, -4),
                textcoords='offset points', fontsize=9,
                color=star_col, fontweight='bold', va='top')

    # label the best GT block if it is not #1
    if not sel_ok and gt_rank:
        gal, gs = blocks[gt_rank - 1][0], blocks[gt_rank - 1][1]
        ax.annotate(f'image (GT) #{gt_rank}\nscore={gs:,}',
                    (gal / GIB, gs), xytext=(8, 14),
                    textcoords='offset points', fontsize=8.5,
                    color='#b9770e', fontweight='bold',
                    arrowprops=dict(arrowstyle='->', color='#b9770e', lw=1))

    ax.set_ylim(0, max(ys_fp + ys_gt) * 1.18)
    lo = min(xs_fp + xs_gt); hi = max(xs_fp + xs_gt)
    ax.set_xlim(lo - 0.1, hi + 0.6)
    ax.set_ylabel('block score\nH × R', fontsize=9)
    ax.set_title(
        f'mura{run}:  {len(blocks)} active 2MB blocks / {TOTAL_BLOCKS:,} '
        f'(256 GB)   —   populated band {lo:.2f}–{hi:.2f} GiB',
        fontsize=10.5, loc='left', color='#2c3e50', fontweight='bold')
    ax.grid(axis='y', alpha=0.15)
    for sp in ('top', 'right'):
        ax.spines[sp].set_visible(False)
    ax.tick_params(labelsize=8.5)

axes[-1].set_xlabel('guest physical address (GiB)   —   each stem = one 2MB '
                    'block; height = H × R score', fontsize=11)
handles = [
    Line2D([0], [0], color=GT_COL, lw=3, label='image buffer block (GT)'),
    Line2D([0], [0], color=FP_COL, lw=3, label='other / FP block'),
    Line2D([0], [0], marker='*', color='w', markerfacecolor='#c0392b',
           markersize=15, label='selected block (top score)'),
]
axes[0].legend(handles=handles, loc='upper left', fontsize=9, ncol=1,
               framealpha=0.9)
fig.suptitle('MURA: every 2MB block of the 256 GB guest memory scored by '
             'H×R — the image buffer wins',
             fontsize=14, fontweight='bold', y=1.002)
fig.tight_layout(rect=[0, 0, 1, 0.985])
fig.savefig("mura_block_scores.pdf", dpi=300, bbox_inches='tight')
fig.savefig("mura_block_scores.png", dpi=155, bbox_inches='tight')
print("Saved mura/mura_block_scores.pdf / .png")
