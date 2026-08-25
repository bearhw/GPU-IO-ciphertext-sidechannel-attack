#!/usr/bin/env python3
"""
1×3 combined summary:
  (a) MNIST Classifier        — precursor-B detection, top-10 2MB candidates
  (b) MURA Abnormal Detection — same method, top-10 2MB candidates
  (c) LLM Input Detection     — processor-gap method, top-10 gap candidates
      columns: Run 3/Batch 2, Run 5/Batch 0, Run 5/Batch 1, Run 5/Batch 2
"""

import re
import bisect
import sys
import numpy as np

import matplotlib
matplotlib.use('Agg')

import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle

# ============================================================
# Paths & run IDs
# ============================================================

MNIST_DIR  = "mnist"
MURA_DIR   = "mura"
LLM_DIR    = "llm_input_track_logs"

MNIST_RUNS = [r for r in range(1, 9) if r != 7]   # 1-6, 8
MURA_RUNS  = list(range(1, 6))                     # 1-5
LLM_RUNS   = [3, 4, 5]

# LLM panel columns: (run_id, batch_id, x-label)
LLM_COLS = [
    (3, 2, 'Run 3\nBatch 2'),
    (5, 0, 'Run 5\nBatch 0'),
    (5, 1, 'Run 5\nBatch 1'),
    (5, 2, 'Run 5\nBatch 2'),
]

# ============================================================
# Shared constants
# ============================================================

B_LO      = 0x3f80000000
B_HI      = 0x3f90000000
A_LO      = 0x3f7fc00000
A_HI      = 0x3f7fd00000
GPA_MAX   = 0x400000000
PAGE      = 0x1000
ALIGN_2MB = 0x200000

LOOKAHEAD = 12
MIN_RUN   = 2
GAP_TOL   = 2
WINDOW_US = 40

# ============================================================
# MNIST / MURA: precursor-B detection
# ============================================================

def detect_candidates(writes):
    window_ns  = WINDOW_US * 1000
    candidates = {}

    look_active    = False
    look_remaining = 0
    look_run_base  = 0
    look_run_len   = 0
    look_prec_ns   = 0

    def finalize_run():
        nonlocal look_run_base, look_run_len
        if look_run_len < MIN_RUN:
            return
        al = look_run_base & ~(ALIGN_2MB - 1)
        if al not in candidates:
            candidates[al] = {'aligned': al, 'exact': look_run_base,
                               'hits': 0, 'max_run': 0}
        candidates[al]['hits'] += 1
        if look_run_len > candidates[al]['max_run']:
            candidates[al]['max_run'] = look_run_len
        if look_run_base < candidates[al]['exact']:
            candidates[al]['exact'] = look_run_base

    for gpa, ts in writes:
        if B_LO <= gpa < B_HI:
            if look_active:
                finalize_run()
            look_active    = True
            look_remaining = LOOKAHEAD
            look_run_base  = 0
            look_run_len   = 0
            look_prec_ns   = ts
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
            expected  = look_run_base + look_run_len * PAGE
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

    return sorted(
        candidates.values(),
        key=lambda c: (c['hits'] * c['max_run'], c['hits']),
        reverse=True,
    )


# ============================================================
# MNIST parsing
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
    return set(g & ~(ALIGN_2MB - 1) for g in gt_gpas)


def mnist_analyze_run(run_id):
    try:
        writes = mnist_parse_host(run_id)
        gt_2mb = mnist_parse_guest(run_id)
    except FileNotFoundError as e:
        print(f"  MNIST run {run_id}: missing — {e}")
        return None
    if not writes:
        return None
    ranked  = detect_candidates(writes)
    gt_rank = next(
        (i + 1 for i, c in enumerate(ranked) if c['aligned'] in gt_2mb), None
    )
    print(f"  MNIST run {run_id}: {len(ranked)} cands, GT rank={gt_rank}")
    return {
        'run':       run_id,
        'top1':      any(c['aligned'] in gt_2mb for c in ranked[:1]),
        'top5':      any(c['aligned'] in gt_2mb for c in ranked[:5]),
        'top10':     any(c['aligned'] in gt_2mb for c in ranked[:10]),
        'top10_list': ranked[:10],
        'gt_2mb':    gt_2mb,
    }


# ============================================================
# MURA parsing
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
        print(f"  MURA run {run_id}: missing — {e}")
        return None
    if not writes:
        return None
    ranked  = detect_candidates(writes)
    gt_rank = next(
        (i + 1 for i, c in enumerate(ranked) if c['aligned'] in all_2mb), None
    )
    print(f"  MURA  run {run_id}: {len(ranked)} cands, GT rank={gt_rank}")
    return {
        'run':       run_id,
        'top1':      any(c['aligned'] in all_2mb for c in ranked[:1]),
        'top5':      any(c['aligned'] in all_2mb for c in ranked[:5]),
        'top10':     any(c['aligned'] in all_2mb for c in ranked[:10]),
        'top10_list': ranked[:10],
        'all_2mb':   all_2mb,
    }


# ============================================================
# LLM: processor-gap detection
# ============================================================

def llm_parse_host(run_id):
    writes, burst_ts = [], []
    with open(f"{LLM_DIR}/host_run{run_id}.log") as f:
        for line in f:
            if line.startswith('WRITE'):
                m = re.search(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)', line)
                if m:
                    gpa = int(m.group(1), 16) & ~0xFFF
                    ts  = int(m.group(2))
                    if gpa < GPA_MAX:
                        writes.append((gpa, ts))
            elif line.startswith('BURST_B'):
                m = re.search(r'ts=(\d+)', line)
                if m:
                    burst_ts.append(int(m.group(1)))
    writes.sort(key=lambda w: w[1])
    burst_ts.sort()
    return writes, burst_ts


def llm_parse_guest(run_id):
    gt = {}
    with open(f"{LLM_DIR}/guest_run{run_id}.log") as f:
        for line in f:
            m = re.search(
                r'\[GPA\] batch(\d+)/input/input_ids: GPA=0x([0-9a-f]+)', line
            )
            if m:
                gt[int(m.group(1))] = int(m.group(2), 16) & ~(PAGE - 1)
    return gt


def _cluster_bursts(burst_ts, gap_ns=50_000_000):
    if not burst_ts:
        return []
    clusters = []
    cur = {'start': burst_ts[0], 'end': burst_ts[0], 'count': 1}
    for ts in burst_ts[1:]:
        if ts - cur['end'] < gap_ns:
            cur['end'] = ts
            cur['count'] += 1
        else:
            clusters.append(cur)
            cur = {'start': ts, 'end': ts, 'count': 1}
    clusters.append(cur)
    return clusters


def _contig_groups(pages):
    pages = sorted(set(pages))
    if not pages:
        return []
    groups, group = [], [pages[0]]
    for p in pages[1:]:
        if p == group[-1] + PAGE:
            group.append(p)
        else:
            groups.append(group)
            group = [p]
    groups.append(group)
    groups.sort(key=lambda g: -len(g))
    return groups


def llm_get_gaps(run_id):
    writes, burst_ts = llm_parse_host(run_id)
    gt_gpas = llm_parse_guest(run_id)
    clusters = _cluster_bursts(burst_ts)
    large = [c for c in clusters if c['count'] >= 50]
    if not large:
        return [], {}
    t_start = large[0]['start'] - 2_000_000_000
    t_end   = large[-1]['end']  + 5_000_000_000
    wts = [w[1] for w in writes]
    gaps = []
    for ci in range(len(clusters) - 1):
        gs, ge = clusters[ci]['end'], clusters[ci + 1]['start']
        gap_ms = (ge - gs) / 1e6
        if not (200 <= gap_ms <= 600):
            continue
        if gs < t_start or ge > t_end:
            continue
        i_s = bisect.bisect_left(wts, gs)
        i_e = bisect.bisect_right(wts, ge)
        gw  = [writes[j][0] for j in range(i_s, i_e)]
        if len(gw) < 50:
            continue
        grps = _contig_groups(gw)
        if not grps:
            continue
        cand = set(grps[0])
        gaps.append({
            'gap_ms':    gap_ms,
            'cand_size': len(cand),
            'n_writes':  len(gw),
            'rep_gpa':   min(cand),
            'has_gt':    {b: gpa for b, gpa in gt_gpas.items() if gpa in cand},
            'candidate': cand,
        })
    gaps.sort(key=lambda g: -g['cand_size'])
    return gaps, gt_gpas


def llm_analyze():
    run_data = {}
    for run_id in LLM_RUNS:
        try:
            gaps, gt_gpas = llm_get_gaps(run_id)
            run_data[run_id] = (gaps, gt_gpas)
            print(f"  LLM  run {run_id}: {len(gaps)} gaps, "
                  f"{len(gt_gpas)} batches")
        except FileNotFoundError as e:
            print(f"  LLM  run {run_id}: missing — {e}")
    return run_data


# ============================================================
# Cell-drawing helpers
# ============================================================

_FC_GT    = '#27ae60'
_EC_GT    = '#1e8449'
_TC_GT    = 'white'
_FC_OTHER = 'white'
_EC_OTHER = '#2c3e50'
_TC_OTHER = '#2c3e50'


def _cell(ax, xi, yi, is_gt):
    fc = _FC_GT if is_gt else _FC_OTHER
    ec = _EC_GT if is_gt else _EC_OTHER
    lw = 1.5    if is_gt else 0.8
    ax.add_patch(Rectangle(
        (xi - 0.46, yi - 0.44), 0.92, 0.88,
        facecolor=fc, edgecolor=ec, linewidth=lw, zorder=3,
    ))
    return _TC_GT if is_gt else _TC_OTHER


def draw_mnist_mura_cells(ax, results, top_n, candidate_key,
                          gpa_fs, stat_fs, score_fs,
                          xtick_fs, ytick_fs, y_max=None):
    runs = [r['run'] for r in results]
    ylim_max = y_max if y_max is not None else top_n + 0.5
    ax.set_xlim(-0.5, len(runs) - 0.5)
    ax.set_ylim(-0.5, ylim_max)
    ax.invert_yaxis()
    ax.set_xticks(range(len(runs)))
    ax.set_xticklabels([f'Run {r}' for r in runs], fontsize=xtick_fs)
    ax.set_yticks(range(top_n))
    ax.set_yticklabels([f'#{i+1}' for i in range(top_n)], fontsize=ytick_fs)
    ax.tick_params(axis='both', labelsize=ytick_fs)

    for xi, r in enumerate(results):
        gt_set = r.get('gt_2mb') or r.get('all_2mb')
        for yi, c in enumerate(r[candidate_key]):
            is_gt = c['aligned'] in gt_set
            tc    = _cell(ax, xi, yi, is_gt)
            score = c['hits'] * c['max_run']
            ax.text(xi, yi - 0.20, f'0x{c["aligned"] >> 20:05x}',
                    ha='center', va='center', fontsize=gpa_fs,
                    fontweight='bold', family='monospace',
                    color=tc, zorder=4)
            ax.text(xi, yi + 0.08, f'h={c["hits"]}  r={c["max_run"]}p',
                    ha='center', va='center', fontsize=stat_fs,
                    color=tc, zorder=4)
            ax.text(xi, yi + 0.32, f'sc={score}',
                    ha='center', va='center', fontsize=score_fs,
                    color=tc, zorder=4)


def draw_llm_cells(ax, llm_run_data, cols, top_n,
                   gpa_fs, stat_fs, score_fs, xtick_fs, ytick_fs):
    n_cols = len(cols)
    ax.set_xlim(-0.5, n_cols - 0.5)
    ax.set_ylim(-0.5, top_n + 1.2)   # extra room for ∩ annotation
    ax.invert_yaxis()
    ax.set_xticks(range(n_cols))
    ax.set_xticklabels([lbl for _, _, lbl in cols], fontsize=xtick_fs)
    ax.set_yticks(range(top_n))
    ax.set_yticklabels([f'#{i+1}' for i in range(top_n)], fontsize=ytick_fs)
    ax.tick_params(axis='both', labelsize=ytick_fs)

    for xi, (run_id, batch_id, _) in enumerate(cols):
        if run_id not in llm_run_data:
            continue
        gaps, _ = llm_run_data[run_id]

        # cross-intersection for annotation
        gt_gaps = [g for g in gaps if batch_id in g['has_gt']]
        inter   = set()
        if gt_gaps:
            inter = set(gt_gaps[0]['candidate'])
            for g in gt_gaps[1:]:
                inter &= g['candidate']

        for yi, g in enumerate(gaps[:top_n]):
            is_gt = batch_id in g['has_gt']
            tc    = _cell(ax, xi, yi, is_gt)
            ax.text(xi, yi - 0.20, f'0x{g["rep_gpa"] >> 12:06x}',
                    ha='center', va='center', fontsize=gpa_fs,
                    fontweight='bold', family='monospace',
                    color=tc, zorder=4)
            ax.text(xi, yi + 0.08, f'{g["cand_size"]}p  {g["gap_ms"]:.0f}ms',
                    ha='center', va='center', fontsize=stat_fs,
                    color=tc, zorder=4)
            ax.text(xi, yi + 0.32, f'w={g["n_writes"]}',
                    ha='center', va='center', fontsize=score_fs,
                    color=tc, zorder=4)

        if gt_gaps:
            n_gg   = len(gt_gaps)
            label  = (f'{n_gg} GT gap{"s" if n_gg > 1 else ""}'
                      f'\n∩ → {len(inter)}p')
            ax.text(xi, top_n + 0.20, label,
                    ha='center', va='top',
                    fontsize=ytick_fs - 4, fontweight='bold',
                    color=_FC_GT, zorder=5)


# ============================================================
# 1×3 combined figure
# ============================================================

def plot_1x3(mnist_results, mura_results, llm_run_data):
    mn_top_n  = 10   # MNIST / MURA
    llm_top_n = 25   # LLM
    row_h     = 1.8

    n_mnist = len(mnist_results)
    n_mura  = len(mura_results)
    n_llm   = len(LLM_COLS)
    total   = n_mnist + n_mura + n_llm

    fig_w = 7.0 * total / 4
    fig_h = llm_top_n * row_h + 1.5  # height driven by tallest panel

    fig = plt.figure(figsize=(fig_w, fig_h))
    gs  = fig.add_gridspec(
        llm_top_n, 3,
        width_ratios=[n_mnist / total, n_mura / total, n_llm / total],
        wspace=0.08,
    )
    ax_mnist = fig.add_subplot(gs[:, 0])
    ax_mura  = fig.add_subplot(gs[:, 1])
    ax_llm   = fig.add_subplot(gs[:, 2])

    fs_xt, fs_yt = 24, 24
    fs_gpa, fs_stat, fs_sc = 17, 14, 13

    # (a) MNIST
    draw_mnist_mura_cells(
        ax_mnist, mnist_results, mn_top_n, 'top10_list',
        gpa_fs=fs_gpa, stat_fs=fs_stat, score_fs=fs_sc,
        xtick_fs=fs_xt, ytick_fs=fs_yt,
        y_max=llm_top_n + 1.2,
    )
    ax_mnist.set_ylabel('Top-10 Candidate Rank', fontsize=25)
    ax_mnist.set_xlabel('(a) MNIST Classifier', fontsize=26, labelpad=14)

    # (b) MURA
    draw_mnist_mura_cells(
        ax_mura, mura_results, mn_top_n, 'top10_list',
        gpa_fs=fs_gpa, stat_fs=fs_stat, score_fs=fs_sc,
        xtick_fs=fs_xt, ytick_fs=fs_yt,
        y_max=llm_top_n + 1.2,
    )
    ax_mura.set_ylabel('')
    ax_mura.set_yticks([])
    ax_mura.set_xlabel('(b) MURA Abnormal Detection', fontsize=26, labelpad=14)

    # (c) VLM Inference
    draw_llm_cells(
        ax_llm, llm_run_data, LLM_COLS, llm_top_n,
        gpa_fs=16, stat_fs=13, score_fs=12,
        xtick_fs=22, ytick_fs=22,
    )
    ax_llm.set_ylabel('')
    ax_llm.set_yticks([])
    ax_llm.set_xlabel('(c) VLM Inference', fontsize=26, labelpad=14)

    # shared legend above panels
    gt_patch    = Rectangle((0, 0), 1, 1, facecolor=_FC_GT,
                             edgecolor=_EC_GT,
                             label='Ground Truth in candidate')
    other_patch = Rectangle((0, 0), 1, 1, facecolor=_FC_OTHER,
                             edgecolor=_EC_OTHER,
                             label='Non-GT candidate')
    fig.legend(
        handles=[gt_patch, other_patch],
        loc='upper center',
        ncol=2,
        fontsize=24,
        framealpha=1.0,
        bbox_to_anchor=(0.5, 1.00),
    )

    fig.tight_layout(rect=(0, 0, 1, 0.96))

    out = "combined_1x3_summary.pdf"
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

    print("\n=== LLM analysis ===")
    llm_run_data = llm_analyze()

    if not mnist_results and not mura_results and not llm_run_data:
        print("No data found.")
        sys.exit(1)

    if mnist_results:
        n = len(mnist_results)
        t1  = sum(1 for r in mnist_results if r['top1'])
        t5  = sum(1 for r in mnist_results if r['top5'])
        t10 = sum(1 for r in mnist_results if r['top10'])
        print(f"\nMNIST ({n} runs): top1={t1}/{n}, top5={t5}/{n}, top10={t10}/{n}")

    if mura_results:
        n = len(mura_results)
        t1  = sum(1 for r in mura_results if r['top1'])
        t5  = sum(1 for r in mura_results if r['top5'])
        t10 = sum(1 for r in mura_results if r['top10'])
        print(f"MURA  ({n} runs): top1={t1}/{n}, top5={t5}/{n}, top10={t10}/{n}")

    plot_1x3(mnist_results, mura_results, llm_run_data)


if __name__ == '__main__':
    main()
