#!/usr/bin/env python3
"""
Figure: how the Region-B precursor lets us recover the MNIST image GT.
  Panel A (outcome)  : GT rank bump chart, B-free -> B-gated, per run.
  Panel B (mechanism): one B fire -> ascending GT staircase (GPA vs time),
                       with the 40us timing gate drawn in.
Data: mnist host/guest logs + run1_B2GT_cases.txt (ready-made cases).
"""
import re
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D

B_LO, B_HI = 0x3f80000000, 0x3f90000000
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
PAGE = 0x1000
ALIGN_2MB = 0x200000
MIN_RUN, GAP_TOL = 2, 2
LOOKAHEAD, WINDOW_NS = 12, 40_000
HOST_RE = re.compile(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)')
BATCH = {1: 512, 2: 512, 3: 512, 4: 512, 5: 256, 6: 128, 7: 128, 8: 128}


def parse_host(run):
    w = []
    with open(f"../mnist/run{run}.log") as f:
        for line in f:
            if not line.startswith('WRITE'):
                continue
            m = HOST_RE.search(line)
            if m:
                w.append((int(m.group(1), 16), int(m.group(2))))
    return w


def mnist_gt(run):
    s = set()
    with open(f"../mnist/run{run}_guest.log") as f:
        for line in f:
            m = re.search(r'\[Train\] batch \d+ (?:image )?GPA: 0x([0-9a-f]+)', line)
            if m:
                s.add((int(m.group(1), 16) & ~(PAGE - 1)) & ~(ALIGN_2MB - 1))
    return s


def _fin(cand, base, length):
    if length >= MIN_RUN:
        al = base & ~(ALIGN_2MB - 1)
        c = cand.get(al)
        if c:
            c[0] += 1
            if length > c[1]:
                c[1] = length
        else:
            cand[al] = [1, length]


def ranked(cand):
    return sorted(cand.items(), key=lambda kv: (-(kv[1][0] * kv[1][1]), -kv[1][0]))


def detect_gated(writes):
    cand = {}
    active = False
    rem = base = length = prec = 0
    for gpa, ts in writes:
        if B_LO <= gpa < B_HI:
            if active:
                _fin(cand, base, length)
            active, rem, base, length, prec = True, LOOKAHEAD, 0, 0, ts
            continue
        if not active:
            continue
        if A_LO <= gpa < A_HI:
            continue
        if length == 0 and (ts - prec) > WINDOW_NS:
            active = False
            continue
        if length == 0:
            base, length = gpa, 1
        else:
            exp = base + length * PAGE
            if gpa == exp:
                length += 1
            elif gpa > exp and (gpa - exp) // PAGE <= GAP_TOL:
                length += (gpa - exp) // PAGE + 1
            else:
                _fin(cand, base, length); base, length = gpa, 1
        if length < MIN_RUN:
            rem -= 1
            if rem <= 0:
                active = False
    if active:
        _fin(cand, base, length)
    return ranked(cand)


def detect_free(writes):
    cand = {}
    base = length = 0
    for gpa, ts in writes:
        if A_LO <= gpa < A_HI or B_LO <= gpa < B_HI:
            _fin(cand, base, length); base = length = 0
            continue
        if length == 0:
            base, length = gpa, 1
        else:
            exp = base + length * PAGE
            if gpa == exp:
                length += 1
            elif gpa > exp and (gpa - exp) // PAGE <= GAP_TOL:
                length += (gpa - exp) // PAGE + 1
            else:
                _fin(cand, base, length); base, length = gpa, 1
    _fin(cand, base, length)
    return ranked(cand)


def gt_rank(rk, gt2mb):
    for i, (al, _) in enumerate(rk):
        if al in gt2mb:
            return i + 1
    return len(rk) + 1


# ---- gather ranks ----
runs = list(range(1, 9))
free_rank, gate_rank = {}, {}
for r in runs:
    w = parse_host(r)
    gt = mnist_gt(r)
    free_rank[r] = gt_rank(detect_free(w), gt)
    gate_rank[r] = gt_rank(detect_gated(w), gt)
    print(f"run{r} b{BATCH[r]}: free #{free_rank[r]} -> gate #{gate_rank[r]}")

# ---- parse a staircase case from run1_B2GT_cases.txt ----
def parse_case(path, want_min_len=10):
    blocks = open(path).read().split("Case ")
    best = None
    for blk in blocks[1:]:
        lines = blk.splitlines()
        rows = []
        b_ts = None
        for ln in lines:
            m = HOST_RE.search(ln)
            if not m:
                continue
            gpa = int(m.group(1), 16)
            ts = int(m.group(2))
            is_b = "B-precursor #" in ln and "<==" in ln
            is_img = "image[" in ln
            rows.append((gpa, ts, is_b, is_img))
            if is_b and b_ts is None:
                b_ts = ts
        imgs = [(g, t) for g, t, b, im in rows if im]
        if b_ts and len(imgs) >= want_min_len:
            best = (b_ts, rows)
            break
    return best


case = parse_case("../mnist/run1_B2GT_cases.txt", want_min_len=12)

# ============================================================
# Figure
# ============================================================
fig, (axA, axB) = plt.subplots(1, 2, figsize=(15, 7))

# ---------- Panel A: bump chart ----------
xf, xg = 0.0, 1.0
cmap = {512: '#27ae60', 256: '#e67e22', 128: '#c0392b'}
for r in runs:
    b = BATCH[r]
    fr, gr = free_rank[r], gate_rank[r]
    axA.plot([xf, xg], [fr, gr], '-', color=cmap[b], lw=2.4,
             alpha=0.9, zorder=3)
    axA.scatter([xf], [fr], s=90, color=cmap[b], zorder=4,
                edgecolor='white', linewidth=1.2)
    axA.scatter([xg], [gr], s=90, color=cmap[b], zorder=4,
                edgecolor='white', linewidth=1.2)
    axA.annotate(f'#{fr}', (xf, fr), xytext=(-8, 0),
                 textcoords='offset points', va='center', ha='right',
                 fontsize=9, color='#555')

# group right-side labels by identical gate rank to avoid overlap
from collections import defaultdict
by_rank = defaultdict(list)
for r in runs:
    by_rank[gate_rank[r]].append(r)
for gr, rs in by_rank.items():
    b0 = BATCH[rs[0]]
    label = "run " + ",".join(str(x) for x in rs)
    axA.annotate(label, (xg, gr), xytext=(9, 0),
                 textcoords='offset points', va='center',
                 fontsize=10, color=cmap[b0] if len(set(BATCH[x] for x in rs)) == 1 else '#333',
                 fontweight='bold')

axA.axhspan(0.5, 3.5, color='#2ecc71', alpha=0.10, zorder=0)
axA.text(0.5, 2.0, 'top-3\n(usable)', ha='center', va='center',
         fontsize=11, color='#1e8449', fontweight='bold', alpha=0.6)
axA.set_xlim(-0.35, 1.5)
axA.set_ylim(0.3, max(free_rank.values()) + 3)
axA.invert_yaxis()
axA.set_yscale('log')
axA.set_yticks([1, 2, 3, 5, 10, 20, 40, 70])
axA.set_yticklabels([str(v) for v in [1, 2, 3, 5, 10, 20, 40, 70]])
axA.set_xticks([xf, xg])
axA.set_xticklabels(['B-free\n(run size only)', 'B-gated\n(+ precursor)'],
                    fontsize=12, fontweight='bold')
axA.set_ylabel('GT candidate rank  (lower = better)', fontsize=12)
axA.set_title('(a) Precursor promotes the image GT toward #1',
              fontsize=13, fontweight='bold')
axA.grid(axis='y', alpha=0.2)
handlesA = [Line2D([0], [0], color=cmap[b], lw=3, label=f'batch={b}')
            for b in (512, 256, 128)]
axA.legend(handles=handlesA, loc='lower right', fontsize=10,
           title='MNIST run', title_fontsize=10)

# ---------- Panel B: staircase mechanism ----------
if case:
    b_ts, rows = case
    t0 = b_ts
    # B precursor markers
    for gpa, ts, is_b, is_img in rows:
        if is_b:
            axB.scatter([(ts - t0) / 1000.0], [0], marker='v', s=140,
                        color='#2980b9', zorder=5, edgecolor='white',
                        linewidth=1.0)
    # image staircase (right y-axis in page index)
    imgs = [(g, t) for g, t, b, im in rows if im]
    base_gpa = min(g for g, _ in imgs)
    xs = [(t - t0) / 1000.0 for _, t in imgs]
    ys = [(g - base_gpa) // PAGE for g, _ in imgs]
    axB.step(xs, ys, where='post', color='#c0392b', lw=1.5,
             alpha=0.5, zorder=3)
    axB.scatter(xs, ys, marker='s', s=55, color='#e74c3c',
                edgecolor='#922b21', linewidth=0.6, zorder=4)
    # 40us gate
    axB.axvspan(0, WINDOW_NS / 1000.0, color='#3498db', alpha=0.08, zorder=0)
    axB.axvline(WINDOW_NS / 1000.0, color='#2980b9', ls='--', lw=1.4,
                alpha=0.7, zorder=2)
    axB.text(WINDOW_NS / 1000.0, max(ys) * 0.5, ' 40µs timing gate',
             color='#2980b9', fontsize=10, va='center', fontweight='bold')
    first_delay = (imgs[0][1] - b_ts) / 1000.0
    axB.annotate(f'B fires → {first_delay:.1f}µs →\nascending GT run',
                 xy=(xs[0], ys[0]), xytext=(xs[0] + 8, ys[0] + max(ys) * 0.35),
                 fontsize=10, color='#c0392b', fontweight='bold',
                 arrowprops=dict(arrowstyle='->', color='#c0392b', lw=1.2))
    axB.set_xlabel('Time since B precursor (µs)', fontsize=12)
    axB.set_ylabel(f'GT page index  (base 0x{base_gpa:x})', fontsize=12)
    axB.set_title('(b) Mechanism: B → contiguous image staircase',
                  fontsize=13, fontweight='bold')
    axB.grid(alpha=0.2)
    handlesB = [
        Line2D([0], [0], marker='v', color='w', markerfacecolor='#2980b9',
               markersize=11, label='B precursor (AES-GCM write)'),
        Line2D([0], [0], marker='s', color='w', markerfacecolor='#e74c3c',
               markersize=9, label='GT image page (0x1000 step)'),
    ]
    axB.legend(handles=handlesB, loc='lower right', fontsize=10)

fig.suptitle('MNIST: Region-B precursor recovers the image buffer GPA',
             fontsize=15, fontweight='bold', y=0.99)
fig.tight_layout(rect=[0, 0, 1, 0.97])
out = "mnist_precursor_helps"
fig.savefig(f"{out}.pdf", dpi=300, bbox_inches='tight')
fig.savefig(f"{out}.png", dpi=170, bbox_inches='tight')
print(f"\nSaved {out}.pdf / .png")
