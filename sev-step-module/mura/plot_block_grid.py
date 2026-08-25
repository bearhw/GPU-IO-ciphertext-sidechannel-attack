#!/usr/bin/env python3
"""
MURA top-N 2MB-block grid (real boxes, like mura_detect_summary):
  columns = runs, rows = candidate rank #1..#N.
  each box = one 2MB block of the 256 GB guest space, showing GPA / H / R /
  score(=H*R). Ground-truth image-buffer blocks are green; the rank-#1 box is
  the block the attack SELECTS (gold border + star) -> if it is green, the
  image buffer was correctly recovered.
"""
import re
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.patches import FancyBboxPatch, Patch

HOST = re.compile(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)')
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
B_LO, B_HI = 0x3f80000000, 0x3f90000000
PAGE = 0x1000
AL = 0x200000
TOPN = 10
GREEN, WHITE, GOLD = '#27ae60', '#ffffff', '#e6a817'


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


# gather top-N per run
cols = []
for run in range(1, 6):
    w = parse_host(f"mura_host_regB_{run}.log")
    gt = mura_gt(run)
    blocks = sorted(((al, h, r, h * r, al in gt)
                     for al, (h, r) in detect_free(w).items()),
                    key=lambda x: -x[3])[:TOPN]
    cols.append((run, blocks))

fig, ax = plt.subplots(figsize=(17.5, 15.5))
CW, CH, GX, GY = 1.0, 0.92, 0.34, 0.16

for c, (run, blocks) in enumerate(cols):
    for rank, (al, h, r, s, isgt) in enumerate(blocks):
        x = c * (CW + GX)
        y = (TOPN - 1 - rank) * (CH + GY)
        face = GREEN if isgt else WHITE
        txtc = 'white' if isgt else '#1b2b3a'
        selected = (rank == 0)
        edge = GOLD if selected else '#2c3e50'
        lw = 4.0 if selected else 1.3
        box = FancyBboxPatch((x, y), CW, CH,
                             boxstyle="round,pad=0.008,rounding_size=0.05",
                             linewidth=lw, edgecolor=edge, facecolor=face,
                             zorder=3 if not selected else 5)
        ax.add_patch(box)
        cx = x + CW / 2
        star = '★ ' if selected else ''
        ax.text(cx, y + CH * 0.70, f'{star}0x{al >> 20:05x}',
                ha='center', va='center', fontsize=13, fontweight='bold',
                color=txtc, zorder=6)
        ax.text(cx, y + CH * 0.44, f'H={h:,}  R={r}p',
                ha='center', va='center', fontsize=9.5, color=txtc, zorder=6)
        ax.text(cx, y + CH * 0.19, f'S = {s:,}',
                ha='center', va='center', fontsize=9.5,
                fontweight='bold', color=txtc, zorder=6)
    # column header
    ax.text(c * (CW + GX) + CW / 2, TOPN * (CH + GY) + 0.15,
            f'Run {run}', ha='center', va='bottom', fontsize=15,
            fontweight='bold', color='#2c3e50')

# row labels
for rank in range(TOPN):
    y = (TOPN - 1 - rank) * (CH + GY) + CH / 2
    ax.text(-0.35, y, f'#{rank + 1}', ha='right', va='center',
            fontsize=14, fontweight='bold', color='#2c3e50')

ax.text(-1.15, TOPN * (CH + GY) / 2, 'candidate rank  (by score = H × R)',
        rotation=90, ha='center', va='center', fontsize=14,
        fontweight='bold', color='#2c3e50')

legend = [
    Patch(facecolor=GREEN, edgecolor='#1e7a45', label='image buffer (ground truth)'),
    Patch(facecolor=WHITE, edgecolor='#2c3e50', label='other / FP candidate'),
    Patch(facecolor=WHITE, edgecolor=GOLD, linewidth=3,
          label='★ #1 = block the attack selects'),
]
ax.legend(handles=legend, loc='lower center', ncol=3, fontsize=12,
          bbox_to_anchor=(0.5, -0.075), frameon=True)

ax.set_xlim(-1.3, 5 * (CW + GX))
ax.set_ylim(-0.9, TOPN * (CH + GY) + 0.7)
ax.set_aspect('equal')
ax.axis('off')
fig.suptitle('MURA: top-10 of 131,072 2MB blocks (256 GB) — image buffer '
             'selected as the #1 score',
             fontsize=16, fontweight='bold', y=0.965)
fig.tight_layout()
fig.savefig("mura_block_grid.pdf", dpi=300, bbox_inches='tight')
fig.savefig("mura_block_grid.png", dpi=150, bbox_inches='tight')
print("Saved mura/mura_block_grid.pdf / .png")
