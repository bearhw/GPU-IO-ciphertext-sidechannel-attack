#!/usr/bin/env python3
"""
Reverse-direction metric (GT-based):
For each GT-region ascending run (start), is there a Region-B write within
N us BEFORE its start? Report the fraction over several length thresholds and
several windows, aggregated across runs 1..7.
"""
import re

B_LO, B_HI = 0x3f80000000, 0x3f90000000
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
PAGE = 0x1000
ALIGN_2MB = 0x200000
GAP_TOL = 2
HOST_RE = re.compile(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)')
WINDOWS_NS = [40_000, 100_000, 500_000, 1_000_000]
LEN_THRESH = [1, 4, 16]


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


def gt_runs(writes, gt2mb):
    """Return list of (start_ts, length_pages, aligned) for every ascending
    contiguous run whose base 2MB block is a GT image buffer. A/B writes
    terminate the current run (they are not image accesses)."""
    runs = []
    base = length = start_ts = 0

    def fin():
        if length >= 1:
            al = base & ~(ALIGN_2MB - 1)
            if al in gt2mb:
                runs.append((start_ts, length, al))

    for g, t in writes:
        if A_LO <= g < A_HI or B_LO <= g < B_HI:
            fin(); base = length = 0; continue
        if length == 0:
            base, length, start_ts = g, 1, t
        else:
            exp = base + length * PAGE
            if g == exp:
                length += 1
            elif g > exp and (g - exp) // PAGE <= GAP_TOL:
                length += (g - exp) // PAGE + 1
            else:
                fin(); base, length, start_ts = g, 1, t
    fin()
    return runs


def b_times(writes):
    return [t for g, t in writes if B_LO <= g < B_HI]


import bisect

# accumulate deltas (start_ts - nearest preceding B) per length threshold
buckets = {L: [] for L in LEN_THRESH}
for run in range(1, 8):
    w = parse_host(run)
    gt = gt_2mb(run)
    bt = b_times(w)          # already time-sorted (log order)
    for start_ts, length, al in gt_runs(w, gt):
        idx = bisect.bisect_right(bt, start_ts) - 1
        if idx < 0:
            delta = None
        else:
            delta = start_ts - bt[idx]      # ns, >=0
        for L in LEN_THRESH:
            if length >= L:
                buckets[L].append(delta)

print(f"{'len>=':>6} {'N':>7} " +
      " ".join(f"<{w//1000}us" for w in WINDOWS_NS))
for L in LEN_THRESH:
    ds = buckets[L]
    n = len(ds)
    row = f"{L:>6} {n:>7} "
    for win in WINDOWS_NS:
        hit = sum(1 for d in ds if d is not None and d < win)
        row += f"{100*hit/n:>6.1f}% " if n else "   -   "
    print(row)
