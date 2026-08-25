#!/usr/bin/env python3
"""
Matched label frequency horizontal bar chart — publication quality.
Outputs: label_freq.pdf, label_freq.png
"""

import csv
from collections import Counter
from pathlib import Path
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

# ── data ──────────────────────────────────────────────────────────────────────
HERE = Path(__file__).parent
with open(HERE / "run_all_v4_1.csv", newline="") as f:
    rows = list(csv.DictReader(f))

label_counter = Counter()
for r in rows:
    if r["verdict"] in ("MATCH", "MULTI_MATCH"):
        for lbl in r["label"].split(";"):
            lbl = lbl.strip()
            if lbl:
                label_counter[lbl] += 1

top_n = 15
labels_raw, counts = zip(*label_counter.most_common(top_n))

# display names: add surrounding quotes for clarity
labels_disp = [f'"{l}"' for l in labels_raw]

# reverse so largest is at top
labels_disp = labels_disp[::-1]
counts = counts[::-1]

# ── palette (reference palette slot 1 — blue sequential, step 450) ─────────
BAR_COLOR   = "#2a78d6"   # categorical slot 1 light
SURFACE     = "#fcfcfb"
TEXT_PRI    = "#0b0b0b"
TEXT_SEC    = "#52514e"
TEXT_MUTED  = "#898781"
GRID_COLOR  = "#e1e0d9"
BASELINE    = "#c3c2b7"

# ── figure ────────────────────────────────────────────────────────────────────
fig, ax = plt.subplots(figsize=(7.5, 5.5))
fig.patch.set_facecolor(SURFACE)
ax.set_facecolor(SURFACE)

y = range(top_n)
bars = ax.barh(
    y, counts,
    height=0.62,
    color=BAR_COLOR,
    linewidth=0,
)

# 4 px rounded ends — approximate with capstyle (PDF vector safe)
for bar in bars:
    bar.set_capstyle("round")

# direct value labels — right of bar end
for i, (bar, cnt) in enumerate(zip(bars, counts)):
    ax.text(
        bar.get_width() + 3, bar.get_y() + bar.get_height() / 2,
        str(cnt),
        va="center", ha="left",
        fontsize=8.5, color=TEXT_SEC,
        fontfamily="DejaVu Sans",
    )

# ── axes & grid ───────────────────────────────────────────────────────────────
ax.set_yticks(list(y))
ax.set_yticklabels(labels_disp, fontsize=9.5, color=TEXT_PRI, fontfamily="monospace")
ax.xaxis.set_major_locator(ticker.MultipleLocator(50))
ax.tick_params(axis="x", labelsize=8.5, colors=TEXT_MUTED, length=0)
ax.tick_params(axis="y", length=0)

# vertical grid (recessive)
ax.xaxis.grid(True, color=GRID_COLOR, linewidth=0.6, zorder=0)
ax.set_axisbelow(True)

# baseline only (left spine)
for spine in ax.spines.values():
    spine.set_visible(False)
ax.spines["bottom"].set_visible(True)
ax.spines["bottom"].set_color(BASELINE)
ax.spines["bottom"].set_linewidth(0.8)

ax.set_xlim(0, max(counts) * 1.13)
ax.set_ylim(-0.55, top_n - 0.45)

# ── labels ────────────────────────────────────────────────────────────────────
ax.set_xlabel("Number of matched samples", fontsize=9, color=TEXT_SEC, labelpad=6)
ax.set_title(
    "Matched Clinical Label Frequency\n"
    r"(MATCH + MULTI\_MATCH, $n=1{,}641$ samples)",
    fontsize=11, color=TEXT_PRI, fontweight="bold",
    pad=10, loc="left",
)

# footnote
fig.text(
    0.01, 0.01,
    "Source: run_all_v4_1.csv  |  Dictionary: dict_cache_v4.json  |  Top 15 labels shown",
    fontsize=7, color=TEXT_MUTED, va="bottom",
)

plt.tight_layout(rect=[0, 0.03, 1, 1])

out_pdf = HERE / "label_freq.pdf"
out_png = HERE / "label_freq.png"
fig.savefig(out_pdf, dpi=300, bbox_inches="tight", facecolor=SURFACE)
fig.savefig(out_png, dpi=300, bbox_inches="tight", facecolor=SURFACE)
print(f"Saved: {out_pdf}")
print(f"Saved: {out_png}")
plt.close()
