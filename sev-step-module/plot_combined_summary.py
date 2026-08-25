#!/usr/bin/env python3
"""
Side-by-side summary: MNIST top-5 (left) | MURA top-10 (right).
"""

import re
import sys
import numpy as np

import matplotlib
matplotlib.use('Agg')

import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

# ============================================================
# Shared detection parameters
# ============================================================

B_LO = 0x3f80000000
B_HI = 0x3f90000000
A_LO = 0x3f7fc00000
A_HI = 0x3f7fd00000

LOOKAHEAD  = 12
MIN_RUN    = 2
GAP_TOL    = 2
WINDOW_US  = 40
ALIGN_2MB  = 0x200000
PAGE       = 0x1000

MNIST_DIR = "mnist"
MURA_DIR  = "mura"
MNIST_RUNS = [r for r in range(1, 9) if r != 7]
MURA_RUNS  = list(range(1, 6))


# ============================================================
# Detection (shared)
# ============================================================

def detect_candidates(writes):
    window_ns   = WINDOW_US * 1000
    candidates  = {}
    detected_runs = []
    b_events    = []

    look_active    = False
    look_remaining = 0
    look_run_base  = 0
    look_run_len   = 0
    look_prec_ns   = 0
    precursor_hits = 0

    def finalize_run():
        nonlocal look_run_base, look_run_len
        if look_run_len >= MIN_RUN:
            al = look_run_base & ~(ALIGN_2MB - 1)
            if al not in candidates:
                candidates[al] = {
                    'aligned': al,
                    'exact':   look_run_base,
                    'hits':    0,
                    'max_run': 0,
                }
            candidates[al]['hits'] += 1
            if look_run_len > candidates[al]['max_run']:
                candidates[al]['max_run'] = look_run_len
            if look_run_base < candidates[al]['exact']:
                candidates[al]['exact'] = look_run_base
            detected_runs.append((look_run_base, look_run_len, look_prec_ns))

    for gpa, ts in writes:
        if B_LO <= gpa < B_HI:
            if look_active:
                finalize_run()
            precursor_hits += 1
            look_active    = True
            look_remaining = LOOKAHEAD
            look_run_base  = 0
            look_run_len   = 0
            look_prec_ns   = ts
            b_events.append(ts)
            continue

        if not look_active:
            continue
        if A_LO <= gpa < A_HI:
            continue

        if look_run_len == 0 and (ts - look_prec_ns) > window_ns:
            look_active = False
            continue

        if look_run_len == 0:
            look_run_base = gpa
            look_run_len  = 1
        else:
            expected = look_run_base + look_run_len * PAGE
            if gpa == expected:
                look_run_len += 1
            elif gpa > expected:
                gap_pages = (gpa - expected) // PAGE
                if gap_pages <= GAP_TOL:
                    look_run_len += int(gap_pages) + 1
                else:
                    finalize_run()
                    look_run_base = gpa
                    look_run_len  = 1
            else:
                finalize_run()
                look_run_base = gpa
                look_run_len  = 1

        if look_run_len < MIN_RUN:
            look_remaining -= 1
            if look_remaining <= 0:
                look_active = False

    if look_active:
        finalize_run()

    ranked = sorted(
        candidates.values(),
        key=lambda c: (c['hits'] * c['max_run'], c['hits']),
        reverse=True,
    )
    return ranked


# ============================================================
# MNIST parsing + analysis
# ============================================================

def mnist_parse_host(run_id):
    writes = []
    with open(f"{MNIST_DIR}/run{run_id}.log") as f:
        for line in f:
            if not line.startswith('WRITE'):
                continue
            m = re.search(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)', line)
            if m:
                writes.append((int(m.group(1), 16), int(m.group(2))))
    return writes


def mnist_parse_guest(run_id):
    gt_gpas = []
    with open(f"{MNIST_DIR}/run{run_id}_guest.log") as f:
        for line in f:
            m = re.search(
                r'\[Train\] batch \d+ (?:image )?GPA: 0x([0-9a-f]+)', line
            )
            if m:
                gt_gpas.append(int(m.group(1), 16))
    gt_2mb = set(g & ~(ALIGN_2MB - 1) for g in gt_gpas)
    return gt_2mb


def mnist_analyze_run(run_id):
    try:
        writes  = mnist_parse_host(run_id)
        gt_2mb  = mnist_parse_guest(run_id)
    except FileNotFoundError as e:
        print(f"  MNIST run {run_id}: missing file — {e}")
        return None
    if not writes:
        return None

    ranked = detect_candidates(writes)
    gt_in_top1  = any(c['aligned'] in gt_2mb for c in ranked[:1])
    gt_in_top3  = any(c['aligned'] in gt_2mb for c in ranked[:3])
    gt_in_top5  = any(c['aligned'] in gt_2mb for c in ranked[:5])
    gt_in_top10 = any(c['aligned'] in gt_2mb for c in ranked[:10])
    gt_rank = next(
        (i + 1 for i, c in enumerate(ranked) if c['aligned'] in gt_2mb), None
    )
    print(f"  MNIST run {run_id}: {len(ranked)} candidates, "
          f"GT rank={gt_rank}, top1={'Y' if gt_in_top1 else 'N'} "
          f"top5={'Y' if gt_in_top5 else 'N'} top10={'Y' if gt_in_top10 else 'N'}")
    return {
        'run': run_id,
        'top1': gt_in_top1, 'top3': gt_in_top3,
        'top5': gt_in_top5, 'top10': gt_in_top10,
        'top10_list': ranked[:10],
        'gt_2mb': gt_2mb,
    }


# ============================================================
# MURA parsing + analysis
# ============================================================

def mura_parse_host(run_id):
    writes = []
    with open(f"{MURA_DIR}/mura_host_regB_{run_id}.log") as f:
        for line in f:
            if not line.startswith('WRITE'):
                continue
            m = re.search(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)', line)
            if m:
                writes.append((int(m.group(1), 16), int(m.group(2))))
    return writes


def mura_parse_guest(run_id):
    iter_2mb = {}
    with open(f"{MURA_DIR}/mura_guest_nomul_{run_id}_raw.log") as f:
        for line in f:
            m = re.search(
                r'\[GPA_PAGE\] iter(\d+)/input .+ GPA=0x([0-9a-f]+)', line
            )
            if m:
                it  = int(m.group(1))
                gpa = int(m.group(2), 16) & ~(PAGE - 1)
                al  = gpa & ~(ALIGN_2MB - 1)
                iter_2mb.setdefault(it, set()).add(al)
    all_2mb = set()
    for s in iter_2mb.values():
        all_2mb |= s
    return all_2mb


def mura_analyze_run(run_id):
    try:
        writes  = mura_parse_host(run_id)
        all_2mb = mura_parse_guest(run_id)
    except FileNotFoundError as e:
        print(f"  MURA run {run_id}: missing file — {e}")
        return None
    if not writes:
        return None

    ranked = detect_candidates(writes)
    gt_in_top1  = any(c['aligned'] in all_2mb for c in ranked[:1])
    gt_in_top3  = any(c['aligned'] in all_2mb for c in ranked[:3])
    gt_in_top5  = any(c['aligned'] in all_2mb for c in ranked[:5])
    gt_in_top10 = any(c['aligned'] in all_2mb for c in ranked[:10])
    gt_rank = next(
        (i + 1 for i, c in enumerate(ranked) if c['aligned'] in all_2mb), None
    )
    print(f"  MURA  run {run_id}: {len(ranked)} candidates, "
          f"GT rank={gt_rank}, top1={'Y' if gt_in_top1 else 'N'} "
          f"top5={'Y' if gt_in_top5 else 'N'} top10={'Y' if gt_in_top10 else 'N'}")
    return {
        'run': run_id,
        'top1': gt_in_top1, 'top3': gt_in_top3,
        'top5': gt_in_top5, 'top10': gt_in_top10,
        'top10_list': ranked[:10],
        'all_2mb': all_2mb,
    }


# ============================================================
# Shared cell-drawing helper
# ============================================================

def draw_cells(ax, results, candidate_key, top_n,
               cell_gpa_fontsize, cell_stat_fontsize, cell_score_fontsize,
               xtick_fontsize, ytick_fontsize):
    runs = [r['run'] for r in results]
    ax.set_xlim(-0.5, len(runs) - 0.5)
    ax.set_ylim(-0.5, top_n - 0.5)
    ax.invert_yaxis()

    ax.set_xticks(range(len(runs)))
    ax.set_xticklabels([f'Run {r}' for r in runs], fontsize=xtick_fontsize)
    ax.set_yticks(range(top_n))
    ax.set_yticklabels([f'#{i+1}' for i in range(top_n)], fontsize=ytick_fontsize)
    ax.tick_params(axis='both', labelsize=ytick_fontsize)

    for xi, r in enumerate(results):
        candidates = r[candidate_key]
        gt_set     = r.get('gt_2mb') or r.get('all_2mb')

        for yi, c in enumerate(candidates):
            is_gt = c['aligned'] in gt_set
            score = c['hits'] * c['max_run']
            fc = '#27ae60' if is_gt else 'white'
            ec = '#1e8449' if is_gt else '#2c3e50'
            tc = 'white'   if is_gt else '#2c3e50'
            lw = 1.5       if is_gt else 0.8

            rect = Rectangle(
                (xi - 0.46, yi - 0.44), 0.92, 0.88,
                facecolor=fc, edgecolor=ec, linewidth=lw, zorder=3,
            )
            ax.add_patch(rect)

            ax.text(xi, yi - 0.20,
                    f'0x{c["aligned"] >> 20:05x}',
                    ha='center', va='center',
                    fontsize=cell_gpa_fontsize, fontweight='bold',
                    family='monospace', color=tc, zorder=4)
            ax.text(xi, yi + 0.08,
                    f'h={c["hits"]}  r={c["max_run"]}p',
                    ha='center', va='center',
                    fontsize=cell_stat_fontsize, color=tc, zorder=4)
            ax.text(xi, yi + 0.32,
                    f'sc={score}',
                    ha='center', va='center',
                    fontsize=cell_score_fontsize, color=tc, zorder=4)


# ============================================================
# Combined figure
# ============================================================

def plot_combined(mnist_results, mura_results):

    top_n = 10
    row_h = 1.8

    fig = plt.figure(figsize=(29, top_n * row_h))
    gs = fig.add_gridspec(
        top_n, 2,
        width_ratios=[0.55, 0.45],
        wspace=0.10,
    )
    ax_mnist = fig.add_subplot(gs[:, 0])
    ax_mura  = fig.add_subplot(gs[:, 1])

    # --- MNIST panel (top-10) ---
    draw_cells(
        ax_mnist, mnist_results,
        candidate_key='top10_list', top_n=top_n,
        cell_gpa_fontsize=19, cell_stat_fontsize=16, cell_score_fontsize=15,
        xtick_fontsize=27, ytick_fontsize=27,
    )
    ax_mnist.set_ylabel('Top-10 Candidate GPA', fontsize=28)
    ax_mnist.set_xlabel('(a) MNIST Classifier', fontsize=29, labelpad=14)

    # --- MURA panel (top-10) ---
    draw_cells(
        ax_mura, mura_results,
        candidate_key='top10_list', top_n=top_n,
        cell_gpa_fontsize=19, cell_stat_fontsize=16, cell_score_fontsize=15,
        xtick_fontsize=27, ytick_fontsize=27,
    )
    ax_mura.set_ylabel('')
    ax_mura.set_yticks([])
    ax_mura.set_xlabel('(b) MURA Abnormal Detection', fontsize=29, labelpad=14)

    # Legend placed just above the figure top; bbox_inches='tight' captures it
    gt_patch    = Rectangle((0, 0), 1, 1, facecolor='#27ae60',
                             edgecolor='#1e8449', label='Ground Truth')
    other_patch = Rectangle((0, 0), 1, 1, facecolor='white',
                             edgecolor='#2c3e50', label='Non-GT candidate')
    fig.legend(
        handles=[gt_patch, other_patch],
        loc='lower center',
        ncol=2,
        fontsize=27,
        framealpha=1.0,
        bbox_to_anchor=(0.5, 0.85),
    )

    fig.subplots_adjust(top=0.86)

    fig.tight_layout()

    out = "combined_summary.pdf"
    fig.savefig(out, dpi=300, bbox_inches='tight')
    fig.savefig(out.replace('.pdf', '.png'), dpi=200, bbox_inches='tight')
    plt.close(fig)
    print(f"\nSaved: {out}")


# ============================================================
# Main
# ============================================================

def main():
    print("=== MNIST analysis ===")
    mnist_results = []
    for run_id in MNIST_RUNS:
        r = mnist_analyze_run(run_id)
        if r:
            mnist_results.append(r)

    print("\n=== MURA analysis ===")
    mura_results = []
    for run_id in MURA_RUNS:
        r = mura_analyze_run(run_id)
        if r:
            mura_results.append(r)

    if not mnist_results and not mura_results:
        print("No data found.")
        sys.exit(1)

    n = len(mnist_results)
    if n:
        t1  = sum(1 for r in mnist_results if r['top1'])
        t5  = sum(1 for r in mnist_results if r['top5'])
        t10 = sum(1 for r in mnist_results if r['top10'])
        print(f"\nMNIST summary ({n} runs): "
              f"top1={t1}/{n}, top5={t5}/{n}, top10={t10}/{n}")

    n = len(mura_results)
    if n:
        t1  = sum(1 for r in mura_results if r['top1'])
        t5  = sum(1 for r in mura_results if r['top5'])
        t10 = sum(1 for r in mura_results if r['top10'])
        print(f"MURA  summary ({n} runs): "
              f"top1={t1}/{n}, top5={t5}/{n}, top10={t10}/{n}")

    plot_combined(mnist_results, mura_results)


if __name__ == '__main__':
    main()
