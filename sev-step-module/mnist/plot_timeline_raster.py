#!/usr/bin/env python3
"""
B-aligned raster: show the WHOLE run as a timeline (y = real host time into
the run) while keeping the window-hit readability (x = delay from each B).

Each B precursor is one row placed at its real host time (y). Along x we plot
the GT image accesses that follow it, measured as delay from that B (us).
A vertical band inside the shaded 40us window => every time B fires, GT
follows within the window, across the entire run.

Data: mnist run{n}.log (host) + run{n}_guest.log (GT GPAs).
"""
import re
import statistics as st
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

B_LO, B_HI = 0x3f80000000, 0x3f90000000
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
PAGE = 0x1000
ALIGN_2MB = 0x200000
WINDOW_US = 40
SPAN_NS = 70_000          # look at most 70us past each B
LOOKAHEAD = 30
HOST_RE = re.compile(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)')
BATCH = {1: 512, 2: 512, 3: 512, 4: 512, 5: 256, 6: 128, 7: 128}
CMAP = {512: '#27ae60', 256: '#e67e22', 128: '#c0392b'}


def parse_host(run):
    w = []
    with open(f"run{run}.log") as f:
        for line in f:
            if not line.startswith('WRITE'):
                continue
            m = HOST_RE.search(line)
            if m:
                w.append((int(m.group(1), 16), int(m.group(2))))
    return w


def gt_2mb(run):
    s = set()
    with open(f"run{run}_guest.log") as f:
        for line in f:
            m = re.search(r'\[Train\] batch \d+ (?:image )?GPA: 0x([0-9a-f]+)',
                          line)
            if m:
                s.add((int(m.group(1), 16) & ~(PAGE - 1)) & ~(ALIGN_2MB - 1))
    return s


def episodes(writes, gt2mb):
    """One entry per B precursor: (b_time_ns, first_asc_delay|None, [all_gt])."""
    eps = []
    n = len(writes)
    i = 0
    while i < n:
        gpa, ts = writes[i]
        if not (B_LO <= gpa < B_HI):
            i += 1
            continue
        b_ts = ts
        seq = []
        j = i + 1
        steps = 0
        while j < n and steps < LOOKAHEAD and (writes[j][1] - b_ts) <= SPAN_NS:
            g, t = writes[j]
            if B_LO <= g < B_HI:
                break
            if A_LO <= g < A_HI:
                j += 1
                continue
            seq.append((g, t))
            steps += 1
            j += 1
        all_gt = [(t - b_ts) / 1000.0 for g, t in seq
                  if (g & ~(ALIGN_2MB - 1)) in gt2mb]
        first = None
        for k in range(len(seq) - 1):
            g, t = seq[k]
            if (g & ~(ALIGN_2MB - 1)) in gt2mb and seq[k + 1][0] == g + PAGE:
                first = (t - b_ts) / 1000.0
                break
        eps.append((b_ts, first, all_gt))
        i += 1
    return eps


fig, axes = plt.subplots(2, 4, figsize=(18, 9))
axes = axes.ravel()
RUNS = list(range(1, 8))
for ax in axes[len(RUNS):]:
    ax.axis('off')

for ax, run in zip(axes, RUNS):
    b = BATCH[run]
    col = CMAP[b]
    w = parse_host(run)
    gt = gt_2mb(run)
    eps = episodes(w, gt)
    t0 = w[0][1]

    firsts = [e[1] for e in eps if e[1] is not None]
    n = len(firsts)
    inside = sum(1 for d in firsts if 0 <= d <= WINDOW_US)
    med = st.median(firsts) if firsts else 0

    # 40us window
    ax.axvspan(0, WINDOW_US, color='#3498db', alpha=0.10, zorder=0)
    ax.axvline(WINDOW_US, color='#2980b9', ls='--', lw=1.4, alpha=0.85,
               zorder=2)

    ys_first, xs_first = [], []
    for b_ts, first, all_gt in eps:
        y = (b_ts - t0) / 1e9          # seconds into the run
        # faint dots: every GT access in the tail
        for d in all_gt:
            if d <= 70:
                ax.plot(d, y, '.', color=col, alpha=0.12, ms=3, zorder=3)
        if first is not None and first <= 70:
            xs_first.append(first)
            ys_first.append(y)
    # solid dots: first GT ascending-run access per B
    ax.scatter(xs_first, ys_first, s=14, color=col, alpha=0.75,
               edgecolor='none', zorder=4)

    ax.set_xlim(-2, 70)
    ax.set_title(f'run{run} (batch={b})   {inside}/{n} ({100*inside/n:.0f}%) '
                 f'in 40µs\nmed {med:.1f}µs',
                 fontsize=11, color=col, fontweight='bold')
    ax.tick_params(labelsize=9)
    ax.grid(axis='x', alpha=0.15)
    for s in ('top', 'right'):
        ax.spines[s].set_visible(False)

for ax in axes[4:]:
    ax.set_xlabel('B → GT image access delay (µs)', fontsize=11)
for ax in (axes[0], axes[4]):
    ax.set_ylabel('host time into run (s)', fontsize=11)

fig.suptitle('MNIST: B-aligned raster — every B precursor (a row at its real '
             'time) is followed by GT inside the 40µs window',
             fontsize=14, fontweight='bold', y=1.0)
fig.tight_layout(rect=[0, 0, 1, 0.97])
fig.savefig("mnist_timeline_raster.pdf", dpi=300, bbox_inches='tight')
fig.savefig("mnist_timeline_raster.png", dpi=160, bbox_inches='tight')
print("Saved mnist/mnist_timeline_raster.pdf / .png")
