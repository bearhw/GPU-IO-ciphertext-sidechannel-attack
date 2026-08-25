#!/usr/bin/env python3
"""
image_detect_summary_compare.pdf

Two major sections: B-free | B-gated.
Each section has two sub-groups:
  [Run 1-7  (bs=512/256/128)] | [Run 1-3 bs=64]
"""

import re
import numpy as np

import matplotlib
matplotlib.use('Agg')

import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

# ============================================================
# Config
# ============================================================

LOG_DIR = "."
RUNS_REG   = list(range(1, 8))   # 1-7  (regular)
RUNS_BS64  = [1, 2, 3]           # bs=64 runs

BATCH_REG  = {1: 512, 2: 512, 3: 512, 4: 512, 5: 256, 6: 128, 7: 128}
BATCH_BS64 = {1: 64,  2: 64,  3: 64}

B_LO = 0x3f80000000
B_HI = 0x3f90000000
A_LO = 0x3f7fc00000
A_HI = 0x3f7fd00000

LOOKAHEAD = 12
MIN_RUN   = 2
GAP_TOL   = 2
WINDOW_NS = 40_000
ALIGN_2MB = 0x200000
PAGE      = 0x1000

HOST_RE = re.compile(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)')


# ============================================================
# Parsing
# ============================================================

def _parse_host(path):
    writes = []
    with open(path) as f:
        for line in f:
            if not line.startswith('WRITE'):
                continue
            m = HOST_RE.search(line)
            if m:
                writes.append((int(m.group(1), 16), int(m.group(2))))
    return writes


def _parse_guest(path):
    gt_gpas = []
    with open(path) as f:
        for line in f:
            m = re.search(
                r'\[Train\] batch \d+ (?:image )?GPA: 0x([0-9a-f]+)', line
            )
            if m:
                gt_gpas.append(int(m.group(1), 16))
    gt_2mb = set(g & ~(ALIGN_2MB - 1) for g in gt_gpas)
    return gt_2mb


# ============================================================
# Detection helpers
# ============================================================

def _finalize(cand, base, length):
    if length < MIN_RUN or base == 0:
        return
    al = base & ~(ALIGN_2MB - 1)
    if al not in cand:
        cand[al] = {'aligned': al, 'hits': 0, 'max_run': 0}
    cand[al]['hits'] += 1
    if length > cand[al]['max_run']:
        cand[al]['max_run'] = length


def _rank(cand):
    return sorted(
        cand.values(),
        key=lambda c: (c['hits'] * c['max_run'], c['hits']),
        reverse=True,
    )


def detect_free(writes):
    cand = {}
    base = 0
    length = 0

    for gpa, ts in writes:
        if A_LO <= gpa < A_HI or B_LO <= gpa < B_HI:
            _finalize(cand, base, length)
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
            elif gpa > expected and (gpa - expected) // PAGE <= GAP_TOL:
                length += (gpa - expected) // PAGE + 1
            else:
                _finalize(cand, base, length)
                base = gpa
                length = 1

    _finalize(cand, base, length)
    return _rank(cand)


def detect_gated(writes):
    cand = {}
    active = False
    rem    = 0
    base   = 0
    length = 0
    prec   = 0

    for gpa, ts in writes:
        if B_LO <= gpa < B_HI:
            if active:
                _finalize(cand, base, length)
            active = True
            rem    = LOOKAHEAD
            base   = 0
            length = 0
            prec   = ts
            continue

        if not active:
            continue
        if A_LO <= gpa < A_HI:
            continue

        if length == 0 and (ts - prec) > WINDOW_NS:
            active = False
            continue

        if length == 0:
            base   = gpa
            length = 1
        else:
            expected = base + length * PAGE
            if gpa == expected:
                length += 1
            elif gpa > expected and (gpa - expected) // PAGE <= GAP_TOL:
                length += (gpa - expected) // PAGE + 1
            else:
                _finalize(cand, base, length)
                base   = gpa
                length = 1

        if length < MIN_RUN:
            rem -= 1
            if rem <= 0:
                active = False

    if active:
        _finalize(cand, base, length)

    return _rank(cand)


# ============================================================
# Per-run analysis
# ============================================================

def analyze_run(run_id, batch, host_path, guest_path, label):
    writes = _parse_host(host_path)
    gt_2mb = _parse_guest(guest_path)

    free  = detect_free(writes)
    gated = detect_gated(writes)

    def gt_rank(ranked):
        for i, c in enumerate(ranked):
            if c['aligned'] in gt_2mb:
                return i + 1
        return len(ranked) + 1

    r_free  = gt_rank(free)
    r_gated = gt_rank(gated)

    print(f"{label}: free #{r_free} -> gated #{r_gated}")

    return {
        'label':      label,
        'run':        run_id,
        'batch':      batch,
        'gt_2mb':     gt_2mb,
        'free_top5':  free[:5],
        'gated_top5': gated[:5],
        'free_rank':  r_free,
        'gated_rank': r_gated,
    }


# ============================================================
# Figure
# ============================================================

def plot_compare(results_reg, results_bs64):
    N_REG   = len(results_reg)    # 7
    N_BS64  = len(results_bs64)   # 3
    N_TOTAL = N_REG + N_BS64      # 10 columns per section

    GAP       = 0.3   # data-unit gap between B-free and B-gated sections
    CELL_HW   = 0.46
    CELL_H    = 0.66
    ROW_STEP  = 0.82  # vertical distance between row centres

    # x-position within one section for column xi (0-based)
    def col_x(xi):
        return float(xi)

    SECTION_SPAN = col_x(N_TOTAL - 1) + 0.5 + 0.5   # left-pad + right-pad

    def xf(xi): return col_x(xi)
    def xg(xi): return col_x(xi) + SECTION_SPAN + GAP

    x_lo  = -0.5
    x_hi  = xg(N_TOTAL - 1) + 0.5
    x_mid = (xf(N_TOTAL - 1) + xg(0)) / 2   # gap centre for legend

    # Vertical slots (data y; smaller = higher due to invert_yaxis)
    Y_LEG   = -1.45
    Y_SEC   = -1.22   # "B-free" / "B-gated" headers
    Y_HLINE = -1.03   # coloured separator lines
    Y_RUN   = -0.55   # "Run N\nbs=B" labels
    Y_RANK  =  3.80   # GT rank annotations at bottom

    fig_w = max(30, (x_hi - x_lo) * 1.70)
    fig, ax = plt.subplots(1, 1, figsize=(fig_w, 9))
    ax.set_xlim(x_lo, x_hi)
    ax.set_ylim(-1.62, 4.02)
    ax.invert_yaxis()

    GT_FC  = '#27ae60';  GT_EC  = '#1e8449';  GT_TC  = 'white'
    NON_FC = 'white';    NON_EC = 'black';    NON_TC = 'black'

    all_results = results_reg + results_bs64   # xi 0..9

    # ----------------------------------------------------------
    # Draw cells
    # ----------------------------------------------------------
    for xi, r in enumerate(all_results):
        gt_2mb = r['gt_2mb']
        for xc, cands in ((xf(xi), r['free_top5']), (xg(xi), r['gated_top5'])):
            for yi, c in enumerate(cands):
                yc    = yi * ROW_STEP
                is_gt = c['aligned'] in gt_2mb
                score = c['hits'] * c['max_run']
                fc, ec, tc = (GT_FC, GT_EC, GT_TC) if is_gt else (NON_FC, NON_EC, NON_TC)

                ax.add_patch(Rectangle(
                    (xc - CELL_HW, yc - CELL_H / 2),
                    2 * CELL_HW, CELL_H,
                    facecolor=fc, edgecolor=ec,
                    linewidth=1.6 if is_gt else 0.7, zorder=3,
                ))
                ax.text(xc, yc - 0.18,
                        f'0x{c["aligned"]>>20:05x}',
                        ha='center', va='center',
                        fontsize=16, fontweight='bold',
                        family='monospace', color=tc, zorder=4)
                ax.text(xc, yc + 0.05,
                        f'h={c["hits"]}  r={c["max_run"]}p',
                        ha='center', va='center',
                        fontsize=14, color=tc, zorder=4)
                ax.text(xc, yc + 0.26,
                        f'sc={score}',
                        ha='center', va='center',
                        fontsize=13, color=tc, zorder=4)


    # ----------------------------------------------------------
    # Header text (no x-ticks — all placed manually)
    # ----------------------------------------------------------
    ax.set_xticks([])
    ax.tick_params(axis='x', which='both', bottom=False, top=False)

    # Run labels: "Run N\nbs=B"
    for xi, r in enumerate(all_results):
        for xc in (xf(xi), xg(xi)):
            ax.text(xc, Y_RUN,
                    f'Run {r["run"]}\nbs={r["batch"]}',
                    ha='center', va='center',
                    fontsize=16, fontweight='normal',
                    multialignment='center', zorder=5)

    # Section headers: "B-free" / "B-gated"
    xf_sec_mid = (xf(0) + xf(N_TOTAL - 1)) / 2
    xg_sec_mid = (xg(0) + xg(N_TOTAL - 1)) / 2
    ax.text(xf_sec_mid, Y_SEC, 'B-free',
            ha='center', va='center', fontsize=24, fontweight='bold',
            color='#2980b9', zorder=5)
    ax.text(xg_sec_mid, Y_SEC, 'B-gated',
            ha='center', va='center', fontsize=24, fontweight='bold',
            color='#8e44ad', zorder=5)

    # Horizontal lines below section headers
    lw = 2.8
    ax.plot([xf(0) - 0.5, xf(N_TOTAL - 1) + 0.5], [Y_HLINE, Y_HLINE],
            color='#2980b9', linewidth=lw, zorder=5)
    ax.plot([xg(0) - 0.5, xg(N_TOTAL - 1) + 0.5], [Y_HLINE, Y_HLINE],
            color='#8e44ad', linewidth=lw, zorder=5)

    # ----------------------------------------------------------
    # GT rank annotation below each column
    # ----------------------------------------------------------
    for xi, r in enumerate(all_results):
        ax.text(xf(xi), Y_RANK, f'#{r["free_rank"]}',
                ha='center', va='center', fontsize=20,
                color='#2980b9', fontweight='bold', zorder=5)
        ax.text(xg(xi), Y_RANK, f'#{r["gated_rank"]}',
                ha='center', va='center', fontsize=20,
                color='#8e44ad', fontweight='bold', zorder=5)

    # ----------------------------------------------------------
    # Y-axis
    # ----------------------------------------------------------
    ax.set_yticks([i * ROW_STEP for i in range(5)])
    ax.set_yticklabels([f'#{i+1}' for i in range(5)], fontsize=22)
    ax.set_ylabel('Candidate GPA', fontsize=20)
    ax.tick_params(axis='y', labelsize=22, width=1.5, length=6)

    # ----------------------------------------------------------
    # Legend
    # ----------------------------------------------------------
    gt_patch  = Rectangle((0, 0), 1, 1, facecolor=GT_FC,
                           edgecolor=GT_EC, label='Ground Truth')
    non_patch = Rectangle((0, 0), 1, 1, facecolor=NON_FC,
                           edgecolor=NON_EC, label='Non-GT candidate')
    ax.legend(
        handles=[gt_patch, non_patch],
        loc='center',
        bbox_to_anchor=(x_mid, Y_LEG),
        bbox_transform=ax.transData,
        ncol=2, fontsize=20, framealpha=1.0,
        borderaxespad=0.4,
    )

    ax.grid(axis='y', alpha=0.12)

    for spine in ax.spines.values():
        spine.set_visible(False)

    fig.tight_layout()

    out = f"{LOG_DIR}/image_detect_summary_compare"
    fig.savefig(f"{out}.pdf", dpi=300, bbox_inches='tight')
    fig.savefig(f"{out}.png", dpi=170, bbox_inches='tight')
    plt.close(fig)
    print(f"\nSaved {out}.pdf / {out}.png")


# ============================================================
# Main
# ============================================================

if __name__ == '__main__':
    print("=== Regular runs (bs=512/256/128) ===")
    results_reg = []
    for run_id in RUNS_REG:
        results_reg.append(analyze_run(
            run_id,
            batch=BATCH_REG[run_id],
            host_path=f"{LOG_DIR}/run{run_id}.log",
            guest_path=f"{LOG_DIR}/run{run_id}_guest.log",
            label=f"run{run_id}",
        ))

    print("\n=== bs=64 runs ===")
    results_bs64 = []
    for run_id in RUNS_BS64:
        results_bs64.append(analyze_run(
            run_id,
            batch=64,
            host_path=f"{LOG_DIR}/run{run_id}_bs64.log",
            guest_path=f"{LOG_DIR}/run{run_id}_guest_bs64.log",
            label=f"run{run_id}_bs64",
        ))

    plot_compare(results_reg, results_bs64)
