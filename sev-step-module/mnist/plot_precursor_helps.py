#!/usr/bin/env python3
"""
Figure (single panel): how the Region-B precursor gate promotes the MNIST
image GT toward rank #1. Bump chart, B-free -> B-gated, one line per run.
Data: mnist run{n}.log (host) + run{n}_guest.log (GT GPAs).
"""

import re
from collections import defaultdict

import numpy as np

import matplotlib
matplotlib.use('Agg')

import matplotlib.pyplot as plt
from matplotlib.lines import Line2D


B_LO, B_HI = 0x3f80000000, 0x3f90000000
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000

PAGE = 0x1000
ALIGN_2MB = 0x200000

MIN_RUN = 2
GAP_TOL = 2

LOOKAHEAD = 12
WINDOW_NS = 40_000

HOST_RE = re.compile(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)')

BATCH = {
    1: 512,
    2: 512,
    3: 512,
    4: 512,
    5: 256,
    6: 128,
    7: 128,
    8: 128,
}

RUNS_BS64 = [1, 2, 3]


def parse_host(run, suffix=""):
    writes = []
    fname = f"run{run}{suffix}.log"

    with open(fname) as f:
        for line in f:
            if not line.startswith("WRITE"):
                continue

            m = HOST_RE.search(line)
            if m:
                writes.append(
                    (
                        int(m.group(1), 16),
                        int(m.group(2)),
                    )
                )

    return writes


def mnist_gt(run, suffix=""):
    gt = set()
    fname = f"run{run}_guest{suffix}.log"

    with open(fname) as f:
        for line in f:
            m = re.search(
                r'\[Train\] batch \d+ (?:image )?GPA: 0x([0-9a-f]+)',
                line,
            )

            if m:
                gpa = int(m.group(1), 16)

                page_aligned = gpa & ~(PAGE - 1)
                aligned_2mb = page_aligned & ~(ALIGN_2MB - 1)

                gt.add(aligned_2mb)

    return gt


def _fin(cand, base, length):
    if length < MIN_RUN:
        return

    aligned = base & ~(ALIGN_2MB - 1)

    current = cand.get(aligned)

    if current:
        current[0] += 1

        if length > current[1]:
            current[1] = length

    else:
        cand[aligned] = [1, length]


def ranked(cand):
    return sorted(
        cand.items(),
        key=lambda kv: (
            -(kv[1][0] * kv[1][1]),
            -kv[1][0],
        ),
    )


def detect_gated(writes):
    cand = {}

    active = False
    rem = 0
    base = 0
    length = 0
    prec = 0

    for gpa, ts in writes:

        # Region-B precursor
        if B_LO <= gpa < B_HI:

            if active:
                _fin(cand, base, length)

            active = True
            rem = LOOKAHEAD
            base = 0
            length = 0
            prec = ts

            continue

        if not active:
            continue

        # Ignore Region-A
        if A_LO <= gpa < A_HI:
            continue

        # No run started within time window
        if length == 0 and (ts - prec) > WINDOW_NS:
            active = False
            continue

        if length == 0:
            base = gpa
            length = 1

        else:
            expected = base + length * PAGE

            if gpa == expected:
                length += 1

            elif (
                gpa > expected
                and (gpa - expected) // PAGE <= GAP_TOL
            ):
                length += (gpa - expected) // PAGE + 1

            else:
                _fin(cand, base, length)

                base = gpa
                length = 1

        if length < MIN_RUN:
            rem -= 1

            if rem <= 0:
                active = False

    if active:
        _fin(cand, base, length)

    return ranked(cand)


def detect_free(writes):
    cand = {}

    base = 0
    length = 0

    for gpa, ts in writes:

        # Region A/B terminates current run
        if (
            A_LO <= gpa < A_HI
            or B_LO <= gpa < B_HI
        ):
            _fin(cand, base, length)

            base = 0
            length = 0

            continue

        if length == 0:
            base = gpa
            length = 1

        else:
            expected = base + length * PAGE

            if gpa == expected:
                length += 1

            elif (
                gpa > expected
                and (gpa - expected) // PAGE <= GAP_TOL
            ):
                length += (gpa - expected) // PAGE + 1

            else:
                _fin(cand, base, length)

                base = gpa
                length = 1

    _fin(cand, base, length)

    return ranked(cand)


def gt_rank(ranked_candidates, gt2mb):

    for i, (aligned, _) in enumerate(ranked_candidates):

        if aligned in gt2mb:
            return i + 1

    return len(ranked_candidates) + 1


# ============================================================
# Gather ranks
# ============================================================

runs = list(range(1, 8))

free_rank = {}
gate_rank = {}

for r in runs:

    writes = parse_host(r)
    gt = mnist_gt(r)

    free_rank[r] = gt_rank(
        detect_free(writes),
        gt,
    )

    gate_rank[r] = gt_rank(
        detect_gated(writes),
        gt,
    )

    print(
        f"run{r} b{BATCH[r]}: "
        f"free #{free_rank[r]} -> "
        f"gate #{gate_rank[r]}"
    )

free_rank_64 = {}
gate_rank_64 = {}

for r in RUNS_BS64:

    writes = parse_host(r, suffix="_bs64")
    gt = mnist_gt(r, suffix="_bs64")

    free_rank_64[r] = gt_rank(
        detect_free(writes),
        gt,
    )

    gate_rank_64[r] = gt_rank(
        detect_gated(writes),
        gt,
    )

    print(
        f"run{r}_bs64 b64: "
        f"free #{free_rank_64[r]} -> "
        f"gate #{gate_rank_64[r]}"
    )


# ============================================================
# Figure
# ============================================================

# Reduced vertical height
fig, ax = plt.subplots(figsize=(8, 5.2))

xf = 0.0
xg = 1.0

cmap = {
    512: "#27ae60",
    256: "#e67e22",
    128: "#c0392b",
    64:  "#2980b9",
}


# Piecewise-linear scale: map rank tick values to equal visual positions
possible_yticks = [
    1,
    2,
    3,
    5,
    10,
    20,
    70,
]

_knots = np.array(possible_yticks, dtype=float)
_pos = np.arange(len(possible_yticks), dtype=float)


def _fwd(y):
    return np.interp(y, _knots, _pos)


def _inv(p):
    return np.interp(p, _pos, _knots)


# ------------------------------------------------------------
# Draw each run
# ------------------------------------------------------------

for r in runs:

    batch = BATCH[r]

    fr = free_rank[r]
    gr = gate_rank[r]

    ax.plot(
        [xf, xg],
        [fr, gr],
        "-",
        color=cmap[batch],
        lw=2.4,
        alpha=0.9,
        zorder=3,
    )

    ax.scatter(
        [xf],
        [fr],
        s=90,
        color=cmap[batch],
        zorder=4,
        edgecolor="white",
        linewidth=1.2,
    )

    ax.scatter(
        [xg],
        [gr],
        s=90,
        color=cmap[batch],
        zorder=4,
        edgecolor="white",
        linewidth=1.2,
    )

for r in RUNS_BS64:

    fr = free_rank_64[r]
    gr = gate_rank_64[r]

    ax.plot(
        [xf, xg],
        [fr, gr],
        "--",
        color=cmap[64],
        lw=2.0,
        alpha=0.85,
        zorder=3,
    )

    ax.scatter(
        [xf],
        [fr],
        s=70,
        color=cmap[64],
        zorder=4,
        edgecolor="white",
        linewidth=1.0,
        marker="s",
    )

    ax.scatter(
        [xg],
        [gr],
        s=70,
        color=cmap[64],
        zorder=4,
        edgecolor="white",
        linewidth=1.0,
        marker="s",
    )


# ------------------------------------------------------------
# Left-side labels, vertically dodged for near-collisions
# ------------------------------------------------------------

# Group identical free ranks (all runs)
by_free = defaultdict(list)

for r in runs:
    by_free[free_rank[r]].append(r)
for r in RUNS_BS64:
    by_free[free_rank_64[r]].append(f"{r}b64")

# Sort by visual position and cluster near-collisions
_left = sorted(
    ((_fwd(fr), fr) for fr in by_free),
    key=lambda t: t[0],
)

DODGE = 0.35
i = 0

while i < len(_left):

    j = i
    while (
        j + 1 < len(_left)
        and _left[j + 1][0] - _left[j][0] < DODGE
    ):
        j += 1

    cluster = _left[i : j + 1]
    n = len(cluster)

    for k, (_p, fr) in enumerate(cluster):

        yoff = (
            (k - (n - 1) / 2) * 24
            if n > 1
            else 0
        )

        ax.annotate(
            f"#{fr}",
            (xf, fr),
            xytext=(-8, yoff),
            textcoords="offset points",
            va="center",
            ha="right",
            fontsize=18,
            color="#555",
        )

    i = j + 1


# ------------------------------------------------------------
# Right-side labels: show the B-gated rank as #N (one per unique
# rank), vertically dodged for near-collisions
# ------------------------------------------------------------

by_gate = defaultdict(list)

for r in runs:
    by_gate[gate_rank[r]].append(r)
for r in RUNS_BS64:
    by_gate[gate_rank_64[r]].append(f"{r}b64")

_right = sorted(
    ((_fwd(gr), gr) for gr in by_gate),
    key=lambda t: t[0],
)

i = 0

while i < len(_right):

    j = i
    while (
        j + 1 < len(_right)
        and _right[j + 1][0] - _right[j][0] < DODGE
    ):
        j += 1

    cluster = _right[i : j + 1]
    n = len(cluster)

    for k, (_p, gr) in enumerate(cluster):

        yoff = (
            (k - (n - 1) / 2) * 24
            if n > 1
            else 0
        )

        ax.annotate(
            f"#{gr}",
            (xg, gr),
            xytext=(9, yoff),
            textcoords="offset points",
            va="center",
            ha="left",
            fontsize=18,
            color="#555",
            fontweight="bold",
        )

    i = j + 1


# ------------------------------------------------------------
# Top-3 region
# ------------------------------------------------------------

# ax.axhspan(
#     0.8,
#     3.5,
#     color="#2ecc71",
#     alpha=0.10,
#     zorder=0,
# )

# # Original 11 -> 26
# ax.text(
#     0.5,
#     2.0,
#     "top-3\n(usable)",
#     ha="center",
#     va="center",
#     fontsize=26,
#     color="#1e8449",
#     fontweight="bold",
#     alpha=0.6,
# )


# ------------------------------------------------------------
# Axes
# ------------------------------------------------------------

ax.set_xlim(
    -0.35,
    1.50,
)


# Use actual rank range instead of excessive vertical space
max_rank = max(
    max(free_rank.values()),
    max(gate_rank.values()),
    max(free_rank_64.values()),
    max(gate_rank_64.values()),
)

ymax = max_rank * 1.08

ax.set_ylim(
    0.8,
    ymax,
)

# Keep only ticks that fit inside current rank range
yticks = [
    y
    for y in possible_yticks
    if y <= ymax
]

ax.set_yscale("function", functions=(_fwd, _inv))

ax.invert_yaxis()

ax.set_yticks(yticks)

ax.set_yticklabels(
    [str(v) for v in yticks],
    fontsize=19,
)


# ------------------------------------------------------------
# X labels: ONLY B-free / B-gated
# ------------------------------------------------------------

ax.set_xticks(
    [xf, xg]
)

ax.set_xticklabels(
    [
        "B-free",
        "B-gated",
    ],
    fontsize=21,
    fontweight="bold",
)


# ------------------------------------------------------------
# Y-axis label
# ------------------------------------------------------------

ax.set_ylabel(
    "GT candidate rank",
    fontsize=21,
)


# Tick size
ax.tick_params(
    axis="y",
    labelsize=19,
    width=1.5,
    length=6,
)

ax.tick_params(
    axis="x",
    labelsize=21,
    width=1.5,
    length=6,
)


# ------------------------------------------------------------
# Grid
# ------------------------------------------------------------

ax.grid(
    axis="y",
    alpha=0.2,
)


# ------------------------------------------------------------
# Legend
# ------------------------------------------------------------

handles = [
    Line2D(
        [0],
        [0],
        color=cmap[b],
        lw=3,
        linestyle="-" if b != 64 else "--",
        label=f"bs={b}",
    )
    for b in (512, 256, 128, 64)
]

ax.legend(
    handles=handles,
    loc="lower center",
    bbox_to_anchor=(0.5, 1.01),
    bbox_transform=ax.transAxes,
    ncol=4,
    fontsize=19,
    framealpha=1.0,
    borderaxespad=0.3,
)


# ============================================================
# Save
# ============================================================

fig.tight_layout()

out = "mnist_precursor_helps"

fig.savefig(
    f"{out}.pdf",
    dpi=300,
    bbox_inches="tight",
)

fig.savefig(
    f"{out}.png",
    dpi=170,
    bbox_inches="tight",
)

print(
    f"\nSaved {out}.pdf / {out}.png"
)