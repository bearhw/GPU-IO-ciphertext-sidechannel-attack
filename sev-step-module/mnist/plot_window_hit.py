#!/usr/bin/env python3
"""
Small-multiples figure: one subplot (own x-axis) per MNIST run.
Each shows ALL B->GT cases as ticks at their real B->GT delay (us), the 40us
detection window, the median delay, and the % of cases inside the window.
Data: window_hits.json (from collect_window_hits.py).
"""
import json
import statistics as st
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

WINDOW_US = 40
BATCH = {1: 512, 2: 512, 3: 512, 4: 512, 5: 256, 6: 128, 7: 128,
         'bs64-1': 64, 'bs64-2': 64, 'bs64-3': 64}
CMAP = {512: '#27ae60', 256: '#e67e22', 128: '#c0392b', 64: '#8e44ad'}

raw = json.load(open("window_hits.json"))
# support both int keys (old) and string keys (new)
data = {}
for k, v in raw.items():
    try:
        data[int(k)] = v
    except ValueError:
        data[k] = v
runs = sorted(data, key=lambda x: (str(x).startswith('bs'), str(x)))

fig, axes = plt.subplots(len(runs), 1, figsize=(11, len(runs) * 1.4))

for ax, run in zip(axes, runs):
    b = BATCH[run]
    col = CMAP[b]
    dl = sorted(data[run])
    n = len(dl)
    inside = sum(1 for d in dl if 0 <= d <= WINDOW_US)
    med = st.median(dl)
    p95 = dl[min(n - 1, int(n * 0.95))]

    # shared x range so the 40us window edge is at the same position everywhere
    xmax = 70
    outside_far = [d for d in dl if d > xmax]

    # window shading + edges
    ax.axvspan(0, WINDOW_US, color='#3498db', alpha=0.09, zorder=0)
    ax.axvline(0, color='#2980b9', lw=1.8, alpha=0.9, zorder=2)
    ax.axvline(WINDOW_US, color='#2980b9', ls='--', lw=1.5, alpha=0.85,
               zorder=2)

    # case ticks
    for d in dl:
        if d <= xmax:
            ax.plot([d, d], [-0.5, 0.5], color=col, lw=1.2, alpha=0.5,
                    zorder=4)
    # median marker + value
    ax.scatter([min(med, xmax)], [0], marker='o', s=70, color=col,
               edgecolor='white', linewidth=1.0, zorder=6)
    ax.annotate(f'med {med:.1f}µs', (min(med, xmax), 0),
                xytext=(0, -16), textcoords='offset points', ha='center',
                va='top', fontsize=8.5, color=col, fontweight='bold')
    # B precursor marker
    ax.scatter([0], [0], marker='v', s=80, color='#2980b9',
               edgecolor='white', linewidth=0.9, zorder=7)
    # far-overflow note
    if outside_far:
        ax.scatter([xmax * 0.985], [0], marker='s', s=34, color='#95a5a6',
                   zorder=5)

    # per-run title with count + percentage
    ax.text(0.0, 1.02,
            f'run{run}  (batch={b})', transform=ax.transAxes,
            ha='left', va='bottom', fontsize=10.5, color=col,
            fontweight='bold')
    ax.text(1.0, 1.02,
            f'{inside}/{n}  ({100*inside/n:.0f}%) inside 40µs window',
            transform=ax.transAxes, ha='right', va='bottom',
            fontsize=10, color='#1b4f72', fontweight='bold')

    ax.set_xlim(-xmax * 0.06, xmax)
    ax.set_ylim(-1.7, 1.1)
    ax.set_yticks([])
    ax.tick_params(axis='x', labelsize=9)
    for s in ('top', 'left', 'right'):
        ax.spines[s].set_visible(False)
    ax.grid(axis='x', alpha=0.13)

axes[-1].set_xlabel('B → first GT image access delay (µs, real host time)',
                    fontsize=12)
fig.suptitle('MNIST: GT image access delay after each B precursor '
             '(per-run axis, all cases)',
             fontsize=13, fontweight='bold', y=0.997)
fig.tight_layout(rect=[0, 0, 1, 0.98])
fig.savefig("mnist_window_hit.pdf", dpi=300, bbox_inches='tight')
fig.savefig("mnist_window_hit.png", dpi=170, bbox_inches='tight')
print("Saved mnist/mnist_window_hit.pdf / .png")
