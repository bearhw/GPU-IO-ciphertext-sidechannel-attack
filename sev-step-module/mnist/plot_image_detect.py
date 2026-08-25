#!/usr/bin/env python3
"""
Offline replica of write_pattern_tracker_B.c logic.
Detects image DMA GPA via Region-B precursor + timing gate,
compares against guest GT, and produces per-run timeline figures.
"""

import re
import sys
import numpy as np

import matplotlib
matplotlib.use('Agg')

import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
from matplotlib.patches import Rectangle

# ============================================================
# Configuration
# ============================================================

LOG_DIR = "."
RUNS = [r for r in range(1, 9) if r != 7]

B_LO = 0x3f80000000
B_HI = 0x3f90000000
A_LO = 0x3f7fc00000
A_HI = 0x3f7fd00000

LOOKAHEAD = 12
MIN_RUN = 2
GAP_TOL = 2
WINDOW_US = 40
ALIGN_2MB = 0x200000

PAGE = 0x1000


# ============================================================
# Parsing
# ============================================================

def parse_host(run_id):
    writes = []
    path = f"{LOG_DIR}/run{run_id}.log"
    with open(path) as f:
        for line in f:
            if not line.startswith('WRITE'):
                continue
            m = re.search(
                r'gpa=0x([0-9a-f]+)\s+ts=(\d+)', line
            )
            if m:
                gpa = int(m.group(1), 16)
                ts = int(m.group(2))
                writes.append((gpa, ts))
    return writes


def parse_guest(run_id):
    gt_gpas = []
    path = f"{LOG_DIR}/run{run_id}_guest.log"
    with open(path) as f:
        for line in f:
            m = re.search(
                r'\[Train\] batch \d+ (?:image )?GPA: '
                r'0x([0-9a-f]+)',
                line
            )
            if m:
                gpa = int(m.group(1), 16)
                gt_gpas.append(gpa)
    gt_2mb = set(g & ~(ALIGN_2MB - 1) for g in gt_gpas)
    return gt_gpas, gt_2mb


# ============================================================
# Region B precursor detection (mirrors C logic)
# ============================================================

def detect_candidates(writes):
    window_ns = WINDOW_US * 1000

    candidates = {}

    look_active = False
    look_remaining = 0
    look_run_base = 0
    look_run_len = 0
    look_prec_ns = 0
    precursor_hits = 0

    # detected runs for plotting: (run_base, run_len, prec_ts)
    detected_runs = []

    def finalize_run():
        nonlocal look_run_base, look_run_len
        if look_run_len >= MIN_RUN:
            al = look_run_base & ~(ALIGN_2MB - 1)
            key = al
            if key not in candidates:
                candidates[key] = {
                    'aligned': al,
                    'exact': look_run_base,
                    'hits': 0,
                    'max_run': 0,
                }
            candidates[key]['hits'] += 1
            if look_run_len > candidates[key]['max_run']:
                candidates[key]['max_run'] = look_run_len
            if look_run_base < candidates[key]['exact']:
                candidates[key]['exact'] = look_run_base
            detected_runs.append(
                (look_run_base, look_run_len, look_prec_ns)
            )

    b_events = []

    for gpa, ts in writes:

        if B_LO <= gpa < B_HI:
            if look_active:
                finalize_run()
            precursor_hits += 1
            look_active = True
            look_remaining = LOOKAHEAD
            look_run_base = 0
            look_run_len = 0
            look_prec_ns = ts
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
            look_run_len = 1
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
                    look_run_len = 1
            else:
                finalize_run()
                look_run_base = gpa
                look_run_len = 1

        if look_run_len < MIN_RUN:
            look_remaining -= 1
            if look_remaining <= 0:
                look_active = False

    if look_active:
        finalize_run()

    ranked = sorted(
        candidates.values(),
        key=lambda c: (c['hits'] * c['max_run'], c['hits']),
        reverse=True
    )

    return ranked, b_events, detected_runs, precursor_hits


# ============================================================
# Per-run analysis (no individual figure)
# ============================================================

def analyze_run(run_id):

    writes = parse_host(run_id)
    gt_gpas, gt_2mb = parse_guest(run_id)

    if not writes:
        print(f"  Run {run_id}: no writes")
        return None

    ranked, b_events, detected_runs, prec_hits = \
        detect_candidates(writes)

    top5 = ranked[:5]
    gt_rank = None
    for i, c in enumerate(ranked):
        if c['aligned'] in gt_2mb:
            if gt_rank is None:
                gt_rank = i + 1

    gt_in_top1 = any(c['aligned'] in gt_2mb for c in ranked[:1])
    gt_in_top3 = any(c['aligned'] in gt_2mb for c in ranked[:3])
    gt_in_top5 = any(c['aligned'] in gt_2mb for c in ranked[:5])

    print(
        f"  Run {run_id}: {len(writes)} writes, "
        f"{prec_hits} B-hits, "
        f"{len(ranked)} candidates, "
        f"GT rank={gt_rank}, "
        f"top1={'Y' if gt_in_top1 else 'N'} "
        f"top3={'Y' if gt_in_top3 else 'N'} "
        f"top5={'Y' if gt_in_top5 else 'N'}"
    )

    return {
        'run': run_id,
        'candidates': len(ranked),
        'gt_rank': gt_rank,
        'top1': gt_in_top1,
        'top3': gt_in_top3,
        'top5': gt_in_top5,
        'top5_list': top5,
        'gt_2mb': gt_2mb,
    }


# ============================================================
# Summary figure
# ============================================================

def plot_summary(results):

    n = len(results)
    t1 = sum(1 for r in results if r['top1'])
    t3 = sum(1 for r in results if r['top3'])
    t5 = sum(1 for r in results if r['top5'])

    fig, ax_top5 = plt.subplots(1, 1, figsize=(14, 10))

    runs = [r['run'] for r in results]

    # --- Top-5 candidate table ---

    ax_top5.set_xlim(-0.5, len(runs) - 0.5)
    ax_top5.set_ylim(-0.5, 4.5)
    ax_top5.invert_yaxis()

    ax_top5.set_xticks(range(len(runs)))
    ax_top5.set_xticklabels(
        [f'Run {r}' for r in runs], fontsize=29
    )
    ax_top5.set_yticks(range(5))
    ax_top5.set_yticklabels(
        [f'#{i+1}' for i in range(5)], fontsize=29
    )
    ax_top5.set_ylabel('Candidate Rank', fontsize=20)
    ax_top5.tick_params(axis='both', labelsize=29)

    for xi, r in enumerate(results):
        top5 = r['top5_list']
        gt_2mb = r['gt_2mb']

        for yi, c in enumerate(top5):
            is_gt = c['aligned'] in gt_2mb
            score = c['hits'] * c['max_run']

            if is_gt:
                fc = '#27ae60'
                ec = '#1e8449'
                tc = 'white'
            else:
                fc = 'white'
                ec = '#2c3e50'
                tc = '#2c3e50'

            rect = Rectangle(
                (xi - 0.44, yi - 0.44),
                0.88, 0.88,
                facecolor=fc,
                edgecolor=ec,
                linewidth=1.5 if is_gt else 0.8,
                zorder=3
            )
            ax_top5.add_patch(rect)

            # GPA
            ax_top5.text(
                xi, yi - 0.20,
                f'0x{c["aligned"]>>20:05x}',
                ha='center', va='center',
                fontsize=16, fontweight='bold',
                family='monospace',
                color=tc, zorder=4
            )
            # hits / max_run
            ax_top5.text(
                xi, yi + 0.08,
                f'h={c["hits"]}  r={c["max_run"]}p',
                ha='center', va='center',
                fontsize=15,
                color=tc, zorder=4
            )
            # score
            ax_top5.text(
                xi, yi + 0.32,
                f'sc={score}',
                ha='center', va='center',
                fontsize=14,
                color=tc, zorder=4
            )

    gt_patch = Rectangle(
        (0, 0), 1, 1, facecolor='#27ae60',
        edgecolor='#1e8449', label='Ground Truth'
    )
    other_patch = Rectangle(
        (0, 0), 1, 1, facecolor='white',
        edgecolor='#2c3e50', label='Non-GT candidate'
    )
    ax_top5.legend(
        handles=[gt_patch, other_patch],
        loc='upper left', bbox_to_anchor=(1.01, 1),
        borderaxespad=0, fontsize=18, framealpha=1.0
    )

    fig.tight_layout()
    out = f"{LOG_DIR}/image_detect_summary.pdf"
    fig.savefig(out, dpi=300, bbox_inches='tight')
    fig.savefig(
        out.replace('.pdf', '.png'),
        dpi=200, bbox_inches='tight'
    )
    plt.close(fig)
    print(f"\nSaved: {out}")


# ============================================================
# Per-run timeline figure (broken Y-axis)
# ============================================================

def plot_run(run_id):

    writes = parse_host(run_id)
    gt_gpas, gt_2mb = parse_guest(run_id)

    if not writes:
        print(f"  Run {run_id}: skip timeline (no data)")
        return

    ranked, b_events, detected_runs, prec_hits = \
        detect_candidates(writes)

    # GT rank
    gt_rank = None
    for i, c in enumerate(ranked):
        if c['aligned'] in gt_2mb:
            gt_rank = i + 1
            break
    gt_in_top5 = any(c['aligned'] in gt_2mb for c in ranked[:5])

    # GT page GPAs (4K-aligned)
    gt_pages = set(g & ~(PAGE - 1) for g in gt_gpas)

    # Find GT page write-fault times from host log
    gt_hits = []
    for gpa, ts in writes:
        if gpa in gt_pages:
            gt_hits.append((gpa, ts))

    t0 = writes[0][1]

    # Auto-crop: find time range with B events
    if b_events:
        t_inf_start = b_events[0] - 2_000_000_000
        t_inf_end = b_events[-1] + 5_000_000_000
    else:
        t_inf_start = t0
        t_inf_end = writes[-1][1]

    # Separate GT-matching and FP detected runs (within time window)
    gt_det = []   # (prec_ts, run_base)
    fp_det = []   # (prec_ts, run_base)
    for run_base, run_len, prec_ts in detected_runs:
        if not (t_inf_start <= prec_ts <= t_inf_end):
            continue
        al = run_base & ~(ALIGN_2MB - 1)
        if al in gt_2mb:
            gt_det.append((prec_ts, run_base))
        else:
            fp_det.append((prec_ts, run_base))

    # GPA range: all detected run bases + GT pages
    all_run_bases = [r[1] for r in gt_det + fp_det]
    all_gpas = all_run_bases + list(gt_pages)
    if all_gpas:
        gpa_lo = min(all_gpas) - 0x400000
        gpa_hi = max(all_gpas) + 0x400000
    else:
        gpa_lo = 0
        gpa_hi = 0x200000000

    # ---- Figure: broken Y-axis ----
    fig, (ax_b, ax_img) = plt.subplots(
        2, 1, figsize=(14, 5), sharex=True,
        gridspec_kw={'height_ratios': [1, 5], 'hspace': 0.04}
    )

    x_lo = (t_inf_start - t0) / 1e9
    x_hi = (t_inf_end - t0) / 1e9

    # === Top panel: all B precursor events ===
    b_gpa_mid = (B_LO + B_HI) // 2
    b_arr = np.array(b_events, dtype=np.int64)
    b_mask = (b_arr >= t_inf_start) & (b_arr <= t_inf_end)
    b_crop = b_arr[b_mask]
    b_step = max(1, len(b_crop) // 8000)
    ax_b.scatter(
        (b_crop[::b_step] - t0) / 1e9,
        [b_gpa_mid] * len(b_crop[::b_step]),
        s=0.5, color='#2980b9', alpha=0.3,
        rasterized=True, zorder=2
    )
    ax_b.set_ylim(B_LO, B_HI)
    ax_b.set_ylabel('Region B\n(AES-GCM enc)', fontsize=8)
    ax_b.set_yticks([b_gpa_mid])
    ax_b.set_yticklabels([f'0x{b_gpa_mid:09x}'], fontsize=7)
    ax_b.tick_params(labelsize=7)
    ax_b.grid(axis='x', alpha=0.15)
    ax_b.spines['bottom'].set_visible(False)
    ax_b.tick_params(axis='x', bottom=False)

    # === Bottom panel: all detected runs (FP gray, GT green) ===

    # FP runs — gray dots at (prec_ts, run_base)
    if fp_det:
        fp_step = max(1, len(fp_det) // 6000)
        fp_ts  = np.array([r[0] for r in fp_det[::fp_step]], dtype=np.int64)
        fp_gpa = np.array([r[1] for r in fp_det[::fp_step]], dtype=np.int64)
        ax_img.scatter(
            (fp_ts - t0) / 1e9, fp_gpa,
            s=4, color='#95a5a6', alpha=0.25,
            rasterized=True, zorder=2
        )

    # GT-matching runs — green circles at (prec_ts, run_base)
    if gt_det:
        gt_det_ts  = np.array([r[0] for r in gt_det], dtype=np.int64)
        gt_det_gpa = np.array([r[1] for r in gt_det], dtype=np.int64)
        ax_img.scatter(
            (gt_det_ts - t0) / 1e9, gt_det_gpa,
            s=25, color='#27ae60', alpha=0.75,
            marker='o', zorder=5
        )

    # GT-triggering B precursor: vertical line + 40μs timing gate shade
    for prec_ts, _ in gt_det:
        x_prec = (prec_ts - t0) / 1e9
        x_gate = (prec_ts + WINDOW_US * 1000 - t0) / 1e9
        for ax in (ax_b, ax_img):
            ax.axvline(x_prec, color='#27ae60', linewidth=0.9,
                       linestyle='--', alpha=0.7, zorder=4)
            ax.axvspan(x_prec, x_gate, color='#27ae60',
                       alpha=0.10, zorder=1)

    # GT 2MB-aligned reference line
    for al in gt_2mb:
        ax_img.axhline(
            al, color='#e74c3c', linestyle=':',
            linewidth=0.8, alpha=0.6, zorder=3
        )

    # GT page write faults — red stars
    gt_x = []
    gt_y = []
    for gpa, ts in gt_hits:
        if ts < t_inf_start or ts > t_inf_end:
            continue
        gt_x.append((ts - t0) / 1e9)
        gt_y.append(gpa)

    if gt_x:
        step_gt = max(1, len(gt_x) // 3000)
        ax_img.scatter(
            gt_x[::step_gt], gt_y[::step_gt],
            s=50, marker='*', color='#e74c3c',
            edgecolors='#c0392b', linewidths=0.3,
            alpha=0.8, zorder=6
        )

    # Info box
    info = (
        f'candidates={len(ranked)}  '
        f'GT rank=#{gt_rank}  '
        f'top-5={"Y" if gt_in_top5 else "N"}\n'
        f'B precursors={prec_hits}  '
        f'GT runs={len(gt_det)}  FP runs={len(fp_det)}'
    )
    ax_b.text(
        0.02, 0.90, info,
        transform=ax_b.transAxes, ha='left', va='top',
        fontsize=8, fontweight='bold', color='#2c3e50',
        bbox=dict(
            boxstyle='round,pad=0.4', facecolor='white',
            edgecolor='#bdc3c7', alpha=0.92
        ), zorder=10
    )

    # Axes
    ax_img.set_xlim(x_lo, x_hi)
    ax_img.set_ylim(gpa_lo, gpa_hi)
    ax_b.set_xlim(x_lo, x_hi)

    ax_img.spines['top'].set_visible(False)
    d = 0.012
    kwargs = dict(
        transform=ax_b.transAxes, color='k',
        clip_on=False, linewidth=0.8
    )
    ax_b.plot((-d, +d), (-d, +d), **kwargs)
    ax_b.plot((1 - d, 1 + d), (-d, +d), **kwargs)
    kwargs['transform'] = ax_img.transAxes
    ax_img.plot((-d, +d), (1 - d, 1 + d), **kwargs)
    ax_img.plot((1 - d, 1 + d), (1 - d, 1 + d), **kwargs)

    ax_img.set_xlabel('Time (seconds)', fontsize=11)
    ax_img.set_ylabel('Detected Run GPA', fontsize=10)

    gpa_span = gpa_hi - gpa_lo
    _nice = [0x200000, 0x400000, 0x800000, 0x1000000, 0x2000000,
             0x4000000, 0x8000000, 0x10000000, 0x20000000, 0x40000000]
    tick_step = next((s for s in _nice if gpa_span / s <= 6), _nice[-1])
    yticks = np.arange(
        (gpa_lo // tick_step) * tick_step,
        gpa_hi + tick_step, tick_step
    )
    yticks = yticks[(yticks >= gpa_lo) & (yticks <= gpa_hi)]
    ax_img.set_yticks(yticks)
    ax_img.set_yticklabels(
        [f'0x{int(v):09x}' for v in yticks], fontsize=7
    )
    ax_img.tick_params(labelsize=8)
    ax_img.grid(axis='both', alpha=0.15)

    # Legend
    handles = [
        Line2D([0], [0], marker='o', color='w',
               markerfacecolor='#2980b9', markersize=5,
               label='B precursor'),
        Line2D([0], [0], marker='o', color='w',
               markerfacecolor='#27ae60', markersize=7,
               label=f'GT run detected ({len(gt_det)})'),
        Line2D([0], [0], marker='o', color='w',
               markerfacecolor='#95a5a6', markersize=5,
               label=f'FP run detected ({len(fp_det)})'),
        Line2D([0], [0], linestyle='--', color='#27ae60',
               linewidth=0.9, label='GT precursor trigger'),
        Rectangle((0, 0), 1, 1, facecolor='#27ae60', alpha=0.25,
                  edgecolor='none', label=f'{WINDOW_US}μs timing gate'),
        Line2D([0], [0], linestyle=':', color='#e74c3c',
               label='GT 2MB-aligned GPA'),
        Line2D([0], [0], marker='*', color='w',
               markerfacecolor='#e74c3c', markeredgecolor='#c0392b',
               markersize=12, label='GT image page written'),
    ]
    ax_img.legend(
        handles=handles, loc='lower right',
        fontsize=7.5, framealpha=0.92
    )

    # fig.suptitle(
    #     f'MNIST Run {run_id}: Region-B Precursor Detection — '
    #     f'all candidates (green=GT, gray=FP)',
    #     fontsize=12, fontweight='bold', y=0.98
    # )

    fig.tight_layout()
    out = f"{LOG_DIR}/mnist_timeline_run{run_id}.pdf"
    fig.savefig(out, dpi=300, bbox_inches='tight')
    fig.savefig(
        out.replace('.pdf', '.png'),
        dpi=200, bbox_inches='tight'
    )
    plt.close(fig)
    print(f"  Saved: {out}")


# ============================================================
# Main
# ============================================================

def main():

    print("Image GPA Detection — Region-B Precursor Logic")
    print(f"Parameters: lookahead={LOOKAHEAD}, "
          f"min_run={MIN_RUN}, gap={GAP_TOL}, "
          f"window={WINDOW_US}us")
    print()

    results = []

    for run_id in RUNS:
        r = analyze_run(run_id)
        if r:
            results.append(r)

    if not results:
        return

    n = len(results)
    t1 = sum(1 for r in results if r['top1'])
    t3 = sum(1 for r in results if r['top3'])
    t5 = sum(1 for r in results if r['top5'])

    print()
    print("=" * 50)
    print("SUMMARY")
    print("=" * 50)
    print(f"  Runs: {n}")
    print(f"  GT in top-1: {t1}/{n} ({t1/n*100:.0f}%)")
    print(f"  GT in top-3: {t3}/{n} ({t3/n*100:.0f}%)")
    print(f"  GT in top-5: {t5}/{n} ({t5/n*100:.0f}%)")

    plot_summary(results)

    print("\nGenerating per-run timeline figures...")
    for run_id in RUNS:
        plot_run(run_id)


if __name__ == '__main__':
    main()
