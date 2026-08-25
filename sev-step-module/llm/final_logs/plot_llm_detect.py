#!/usr/bin/env python3
"""
LLM (Qwen2-VL-2B) input_ids detection summary — batch=128 and batch=1.
S(b) = H(b) * R(b)  over 2MB blocks from host WRITE stream.
Outputs: llm_detect_summary.png, llm_detect_summary.pdf
"""
import re, os
from collections import defaultdict
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

# ── constants ────────────────────────────────────────────────────────────────
PAGE  = 0x1000
BLOCK = 0x200000        # 2 MB
TOP_N = 10
DIR   = os.path.dirname(os.path.abspath(__file__))
DIR_BS1 = os.path.join(DIR, "../final_logs_bs1")

# (run_id, log_dir, col_label, group_label)
RUNS = [
    (1, DIR,     "Run 1", "batch=128"),
    (2, DIR,     "Run 2", "batch=128"),
    (1, DIR_BS1, "Run 1", "batch=1"),
    (2, DIR_BS1, "Run 2", "batch=1"),
]

RE_W   = re.compile(r'^WRITE  gpa=0x([0-9a-f]+)\s+ts=(\d+)')
RE_IDS = re.compile(r'\[GPA_RUN\] batch(\d+)/input/input_ids: 0x([0-9a-f]+) len=(\d+)')


# ── helpers ──────────────────────────────────────────────────────────────────
def blk(gpa):
    return (gpa // BLOCK) * BLOCK


def score_blocks(run, log_dir):
    """Return {block_addr: (S, H, R)}, plus GT block set."""
    faults = []
    with open(f"{log_dir}/host_run{run}.log") as f:
        for l in f:
            m = RE_W.match(l)
            if m:
                faults.append((int(m.group(2)), int(m.group(1), 16) & ~(PAGE - 1)))
    faults.sort()

    block_runs = defaultdict(list)
    if not faults:
        return {}, set()

    cur_blk  = blk(faults[0][1])
    cur_len  = 1
    cur_prev = faults[0][1]
    for _, gpa in faults[1:]:
        b = blk(gpa)
        if b == blk(cur_prev) and gpa == cur_prev + PAGE:
            cur_len += 1
            cur_prev = gpa
        else:
            if cur_len >= 4:
                block_runs[cur_blk].append(cur_len)
            cur_blk  = b
            cur_len  = 1
            cur_prev = gpa
    if cur_len >= 4:
        block_runs[cur_blk].append(cur_len)

    scores = {b: (len(r) * max(r), len(r), max(r)) for b, r in block_runs.items()}

    gt_blocks = set()
    with open(f"{log_dir}/guest_run{run}.log") as f:
        for l in f:
            m = RE_IDS.search(l)
            if m:
                base = int(m.group(2), 16) & ~(PAGE - 1)
                n = int(m.group(3))
                for i in range(n):
                    gt_blocks.add(blk(base + i * PAGE))

    return scores, gt_blocks


# ── compute ──────────────────────────────────────────────────────────────────
run_data = []   # [(col_label, group_label, [(block, S, H, R, is_gt), ...]), ...]
for run_id, log_dir, col_label, group_label in RUNS:
    scores, gt_blocks = score_blocks(run_id, log_dir)
    top = sorted(scores, key=lambda b: -scores[b][0])[:TOP_N]
    run_data.append((col_label, group_label, [
        (b, scores[b][0], scores[b][1], scores[b][2], b in gt_blocks)
        for b in top
    ]))


# ── plot ─────────────────────────────────────────────────────────────────────
GT_GREEN  = "#27ae60"
GT_TEXT   = "white"
BG_FILL   = "white"
BG_TEXT   = "#2c3e50"
BORDER    = "#2c3e50"
RANK_COL  = "#2c3e50"
GRP_COLS  = {"batch=128": "#2980b9", "batch=1": "#8e44ad"}

n_rows = TOP_N
n_cols = len(run_data)
CW = 3.8
CH = 1.90
LEFT_MARGIN  = 1.1
RIGHT_MARGIN = 0.3
TOP_MARGIN   = 1.50   # legend + group header + col header (no title)
BOT_MARGIN   = 0.7

fig_w = LEFT_MARGIN + n_cols * CW + RIGHT_MARGIN
fig_h = TOP_MARGIN  + n_rows * CH + BOT_MARGIN

fig, ax = plt.subplots(figsize=(fig_w, fig_h))
fig.subplots_adjust(left=0, right=1, bottom=0, top=1)
ax.set_xlim(0, fig_w)
ax.set_ylim(0, fig_h)
ax.axis("off")
fig.patch.set_facecolor("white")

# ── title ────────────────────────────────────────────────────────────────────
# ax.text(fig_w / 2, fig_h - 0.22,
#         "LLM Input Tensor (input_ids) Detection",
#         ha="center", va="center",
#         fontsize=22, fontweight="bold", color=RANK_COL)
# ax.text(fig_w / 2, fig_h - 0.57,
#         "S(b) = H(b) × R(b)  ·  Qwen2-VL-2B-Instruct  ·  2 MB blocks",
#         ha="center", va="center",
#         fontsize=18.5, color="#555555")

# ── group headers (batch=128 / batch=1) ──────────────────────────────────────
groups = {}
for ci, (col_label, group_label, _) in enumerate(run_data):
    groups.setdefault(group_label, []).append(ci)

for grp, cols in groups.items():
    cx_left  = LEFT_MARGIN + cols[0]  * CW
    cx_right = LEFT_MARGIN + (cols[-1] + 1) * CW
    cx_mid   = (cx_left + cx_right) / 2
    cy_grp   = fig_h - 0.88
    color    = GRP_COLS.get(grp, RANK_COL)
    ax.plot([cx_left + 0.1, cx_right - 0.1], [cy_grp - 0.06, cy_grp - 0.06],
            color=color, lw=1.5)
    ax.text(cx_mid, cy_grp + 0.03, grp,
            ha="center", va="bottom",
            fontsize=25, fontweight="bold", color=color)

# ── column headers ───────────────────────────────────────────────────────────
for ci, (col_label, group_label, _) in enumerate(run_data):
    cx  = LEFT_MARGIN + ci * CW + CW / 2
    cy  = fig_h - TOP_MARGIN + 0.35
    color = GRP_COLS.get(group_label, RANK_COL)
    ax.text(cx, cy, col_label, ha="center", va="center",
            fontsize=25, fontweight="bold", color=color)

# ── rank labels ──────────────────────────────────────────────────────────────
for ri in range(n_rows):
    cy = fig_h - TOP_MARGIN - (ri + 0.5) * CH
    ax.text(LEFT_MARGIN - 0.12, cy, f"#{ri+1}",
            ha="right", va="center", fontsize=26,
            fontweight="bold", color=RANK_COL)

# ── cells ─────────────────────────────────────────────────────────────────────
for ci, (col_label, group_label, rows) in enumerate(run_data):
    for ri, (b_addr, S, H, R, is_gt) in enumerate(rows):
        cx  = LEFT_MARGIN + ci * CW
        cy  = fig_h - TOP_MARGIN - (ri + 1) * CH
        PAD = 0.06

        fc = GT_GREEN if is_gt else BG_FILL
        tc = GT_TEXT  if is_gt else BG_TEXT
        ec = GT_GREEN if is_gt else BORDER

        rect = mpatches.FancyBboxPatch(
            (cx + PAD, cy + PAD), CW - 2*PAD, CH - 2*PAD,
            boxstyle="round,pad=0.015",
            linewidth=1.5 if is_gt else 1.2,
            edgecolor=ec,
            facecolor=fc,
        )
        ax.add_patch(rect)

        blk_idx  = b_addr >> 21
        addr_str = f"0x{blk_idx:04x}"
        mid_x    = cx + CW / 2

        ax.text(mid_x, cy + CH * 0.67, addr_str,
                ha="center", va="center",
                fontsize=30, fontweight="bold", color=tc,
                fontfamily="monospace")
        ax.text(mid_x, cy + CH * 0.38, f"h={H}  r={R}p",
                ha="center", va="center",
                fontsize=28, color=tc)
        ax.text(mid_x, cy + CH * 0.13, f"score={S:,}",
                ha="center", va="center",
                fontsize=28, color=tc)

# ── column divider between the two groups ────────────────────────────────────
div_x = LEFT_MARGIN + 2 * CW
ax.plot([div_x, div_x],
        [BOT_MARGIN * 0.8, fig_h - TOP_MARGIN + 0.5],
        color="#cccccc", lw=1.2, linestyle="--")

# ── y-axis label ─────────────────────────────────────────────────────────────
ax.text(0.22, TOP_MARGIN + n_rows * CH / 2,
        "Top-10 Candidate GPA",
        ha="center", va="center", fontsize=24, color=RANK_COL,
        rotation=90)

# ── legend (drawn manually inside axes, just above group headers) ─────────────
leg_cy  = fig_h - 0.26          # vertical center of legend items
box_h   = 0.28
box_w   = 0.32
fs      = 19

# two items symmetrically placed around fig_w/2
# "Ground Truth (input_ids)" ~4.5in wide at fs=19; leave 0.3in gap between items
items = [
    (GT_GREEN, GT_GREEN, "Ground Truth (input_ids)"),
    (BG_FILL,  BORDER,   "Non-GT candidate"),
]
# item centers: 3.0in left and right of fig center
offsets = [-3.2, 1.8]   # x offset of box left from fig_w/2

for off, (fc, ec, label) in zip(offsets, items):
    x0 = fig_w / 2 + off
    rect = mpatches.FancyBboxPatch(
        (x0, leg_cy - box_h / 2), box_w, box_h,
        boxstyle="round,pad=0.01",
        linewidth=1.0, edgecolor=ec, facecolor=fc,
    )
    ax.add_patch(rect)
    ax.text(x0 + box_w + 0.15, leg_cy, label,
            ha="left", va="center", fontsize=24, color=RANK_COL)

out_png = os.path.join(DIR, "llm_detect_summary.png")
out_pdf = os.path.join(DIR, "llm_detect_summary.pdf")
plt.savefig(out_png, dpi=150, bbox_inches="tight")
plt.savefig(out_pdf, bbox_inches="tight")
print(f"saved: {out_png}")
print(f"saved: {out_pdf}")
