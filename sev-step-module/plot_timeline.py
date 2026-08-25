#!/usr/bin/env python3
"""Timeline figure: B burst density + GPA scatter for input_ids identification."""

import re, bisect
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle
from matplotlib.lines import Line2D
import matplotlib.ticker as mticker

LOG_DIR = "input_track_logs"
RUN = 3
GPA_MAX = 0x400000000  # 16GB — exclude MMIO/BAR

def parse(run_id):
    writes, bursts = [], []
    with open(f"{LOG_DIR}/host_run{run_id}.log") as f:
        for line in f:
            if line.startswith('WRITE'):
                m = re.search(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)', line)
                gpa = int(m.group(1), 16) & ~0xFFF
                if gpa < GPA_MAX:
                    writes.append((gpa, int(m.group(2))))
            elif line.startswith('BURST_B'):
                m = re.search(r'ts=(\d+)\s+burst_id=(\d+)', line)
                bursts.append((int(m.group(1)), int(m.group(2))))
    gt_ids = {}
    with open(f"{LOG_DIR}/guest_run{run_id}.log") as f:
        for line in f:
            m = re.search(r'batch(\d)/input/input_ids: GPA=0x([0-9a-f]+)', line)
            if m:
                gt_ids[int(m.group(1))] = int(m.group(2), 16) & ~0xFFF
    return writes, bursts, gt_ids

def cluster_bursts(bursts, gap_ns=50_000_000):
    clusters = []
    cl = {'start': bursts[0][0], 'end': bursts[0][0], 'count': 1}
    for ts, _ in bursts[1:]:
        if ts - cl['end'] < gap_ns:
            cl['end'] = ts; cl['count'] += 1
        else:
            clusters.append(cl)
            cl = {'start': ts, 'end': ts, 'count': 1}
    clusters.append(cl)
    return clusters

def contig_groups(pages):
    sp = sorted(set(pages))
    if not sp: return []
    groups, grp = [], [sp[0]]
    for p in sp[1:]:
        if p == grp[-1] + 0x1000: grp.append(p)
        else: groups.append(grp); grp = [p]
    groups.append(grp)
    groups.sort(key=lambda g: -len(g))
    return groups

def main():
    writes, bursts, gt_ids = parse(RUN)
    clusters = cluster_bursts(bursts)
    write_ts = np.array([w[1] for w in writes])
    write_gpa = np.array([w[0] for w in writes])
    burst_ts = np.array([b[0] for b in bursts])

    # Crop to inference region: use first cluster of large ones only
    large_cl = [c for c in clusters if c['count'] >= 50]
    t_start = large_cl[0]['start'] - 2_000_000_000
    # Find end of inference: last large cluster within 60s of first
    infer_cl = [c for c in large_cl
                if c['start'] - large_cl[0]['start'] < 60_000_000_000]
    t_end = infer_cl[-1]['end'] + 5_000_000_000
    t0 = t_start

    # Gaps adjacent to large clusters (>=30 bursts)
    gaps = []
    for ci in range(len(clusters) - 1):
        gs, ge = clusters[ci]['end'], clusters[ci+1]['start']
        gap_ms = (ge - gs) / 1e6
        if not (200 <= gap_ms <= 600): continue
        if gs < t_start or ge > t_end: continue
        if clusters[ci]['count'] < 30 and clusters[ci+1]['count'] < 30: continue

        i_s = bisect.bisect_left(write_ts, gs)
        i_e = bisect.bisect_right(write_ts, ge)
        gw = [(writes[j][0], writes[j][1]) for j in range(i_s, i_e)]
        if len(gw) < 50: continue
        groups = contig_groups([p for p, _ in gw if p < GPA_MAX])
        if not groups: continue
        top1 = set(groups[0])
        has_gt = {b: gpa for b, gpa in gt_ids.items() if gpa in top1}
        rank_gt = {}
        for b, gpa in gt_ids.items():
            for ri, g in enumerate(groups):
                if gpa in g: rank_gt[b] = ri + 1; break
        gaps.append({
            'start': gs, 'end': ge, 'ms': gap_ms, 'writes': gw,
            'groups': groups, 'top1': top1, 'top1_size': len(groups[0]),
            'has_gt': has_gt, 'rank_gt': rank_gt, 'ci': ci,
        })

    print(f"Window: {(t_end-t_start)/1e9:.1f}s, gaps: {len(gaps)}, "
          f"with GT: {sum(1 for g in gaps if g['has_gt'])}")

    # --- Figure ---
    fig, (ax_b, ax_g) = plt.subplots(
        2, 1, figsize=(12, 5.5), sharex=True,
        gridspec_kw={'height_ratios': [1, 4], 'hspace': 0.06})

    # Top: burst density
    b_in = burst_ts[(burst_ts >= t_start) & (burst_ts <= t_end)]
    bw = 200_000_000
    bins = np.arange(t_start, t_end + bw, bw)
    counts, edges = np.histogram(b_in, bins=bins)
    centers = (edges[:-1] + edges[1:]) / 2
    ax_b.bar((centers - t0) / 1e9, counts, width=bw / 1e9 * 0.9,
             color='#2c3e50', alpha=0.85, zorder=2)
    ax_b.set_ylabel('B bursts\n/ 200 ms', fontsize=8)
    ax_b.set_ylim(bottom=0)
    ax_b.tick_params(labelsize=7)
    ax_b.set_title(f'Run {RUN}:  B Burst Density and Write Fault GPA Timeline',
                   fontsize=10, fontweight='bold', pad=8)
    for g in gaps:
        ax_b.axvspan((g['start']-t0)/1e9, (g['end']-t0)/1e9,
                     color='#f39c12', alpha=0.35, zorder=1)

    # Bottom: GPA scatter
    mask = (write_ts >= t_start) & (write_ts <= t_end)
    wt, wg = write_ts[mask], write_gpa[mask]
    step = max(1, len(wt) // 20000)
    ax_g.scatter((wt[::step]-t0)/1e9, wg[::step], s=0.3, alpha=0.10,
                 c='#bdc3c7', zorder=1, rasterized=True)

    for g in gaps:
        c = '#f39c12' if g['has_gt'] else '#f5e6cc'
        a = 0.30 if g['has_gt'] else 0.18
        ax_g.axvspan((g['start']-t0)/1e9, (g['end']-t0)/1e9,
                     color=c, alpha=a, zorder=0)

    # Top-1 group dots
    for g in gaps:
        top1 = g['top1']
        tx, gx = [], []
        for p, t in g['writes']:
            if p in top1:
                tx.append((t-t0)/1e9); gx.append(p)
        if tx:
            ax_g.scatter(tx, gx, s=4, c='#2980b9', alpha=0.8,
                         zorder=3, rasterized=True)

    # All GT occurrences (x)
    for batch, gpa in gt_ids.items():
        idxs = np.where((write_gpa == gpa) & mask)[0]
        if len(idxs):
            ax_g.scatter((write_ts[idxs]-t0)/1e9,
                         np.full(len(idxs), gpa, dtype=np.int64),
                         s=40, c='#e74c3c', marker='x', zorder=4, alpha=0.65)

    # In-gap GT (star)
    for g in gaps:
        for batch, gpa in g['has_gt'].items():
            for p, t in g['writes']:
                if p == gpa:
                    ax_g.scatter((t-t0)/1e9, p, s=250, c='#e74c3c',
                                 marker='*', zorder=5,
                                 edgecolors='black', linewidths=0.6)
                    break

    # Annotation
    for g in gaps:
        if g['has_gt']:
            mid = ((g['start']+g['end'])/2 - t0)/1e9
            for batch, rank in g['rank_gt'].items():
                gpa = gt_ids[batch]
                ax_g.annotate(
                    f'batch{batch} input_ids\nrank #{rank}, {g["top1_size"]} pages',
                    xy=(mid, gpa), xytext=(40, 40), textcoords='offset points',
                    fontsize=7.5, color='#c0392b', fontweight='bold',
                    ha='left', va='bottom',
                    arrowprops=dict(arrowstyle='->', color='#c0392b', lw=1.0))

    ax_g.set_ylabel('Guest Physical Address (GPA)', fontsize=9)
    ax_g.set_xlabel('Time (seconds, relative to detect phase)', fontsize=9)
    ax_g.tick_params(labelsize=7)

    # Hex Y-axis at 2GB steps
    gpa_ticks = np.arange(0, GPA_MAX + 1, 0x80000000)
    ax_g.set_yticks(gpa_ticks)
    ax_g.set_yticklabels([f'0x{int(v):09x}' for v in gpa_ticks])
    ax_g.set_ylim(0, GPA_MAX)

    handles = [
        Line2D([0],[0], marker='o', color='w', markerfacecolor='#bdc3c7',
               markersize=4, label='Write faults (sampled)'),
        Line2D([0],[0], marker='o', color='w', markerfacecolor='#2980b9',
               markersize=6, label='Largest contiguous group in gap'),
        Line2D([0],[0], marker='*', color='w', markerfacecolor='#e74c3c',
               markersize=12, markeredgecolor='black',
               label='GT input_ids (identified in gap)'),
        Line2D([0],[0], marker='x', color='#e74c3c', markersize=7,
               label='GT input_ids (all occurrences)'),
        Rectangle((0,0),1,1, fc='#f39c12', alpha=0.3,
                  label='Processor gap (200–600 ms)'),
    ]
    ax_g.legend(handles=handles, loc='lower right', fontsize=7, framealpha=0.92)

    out = f"{LOG_DIR}/timeline_run{RUN}.pdf"
    fig.savefig(out, dpi=300, bbox_inches='tight')
    print(f"Saved: {out}")
    plt.close()

if __name__ == '__main__':
    main()
