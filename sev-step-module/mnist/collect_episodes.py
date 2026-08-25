#!/usr/bin/env python3
"""
For each MNIST run pick ONE real B-precursor episode: a B fire followed
within 40us by a GT-region ascending run. Dump the actual writes (B, GT,
other) with their real host timestamps in a [t_B, t_B+45us] window.
"""
import re
import json

B_LO, B_HI = 0x3f80000000, 0x3f90000000
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
PAGE = 0x1000
ALIGN_2MB = 0x200000
WINDOW_NS = 40_000
SPAN_NS = 46_000
HOST_RE = re.compile(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)')


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
            m = re.search(r'\[Train\] batch \d+ (?:image )?GPA: 0x([0-9a-f]+)', line)
            if m:
                s.add((int(m.group(1), 16) & ~(PAGE - 1)) & ~(ALIGN_2MB - 1))
    return s


def pick_episode(writes, gt2mb):
    """Find a B fire whose following GT ascending run (start within 40us) has
    the most GT pages inside the 45us span. Return (t_B, events)."""
    n = len(writes)
    best = None
    best_score = 0
    for i in range(n):
        gpa, ts = writes[i]
        if not (B_LO <= gpa < B_HI):
            continue
        t_b = ts
        # collect window writes
        ev = []
        gt_run_start = None
        j = i + 1
        prev_gt_gpa = None
        gt_pages = 0
        while j < n and writes[j][1] - t_b <= SPAN_NS:
            g, t = writes[j]
            if B_LO <= g < B_HI:
                kind = 'B'
            elif A_LO <= g < A_HI:
                kind = 'A'
            elif (g & ~(ALIGN_2MB - 1)) in gt2mb:
                kind = 'GT'
            else:
                kind = 'other'
            ev.append((g, t, kind))
            if kind == 'GT':
                # detect ascending run start within window
                if (t - t_b) <= WINDOW_NS and gt_run_start is None:
                    gt_run_start = t
                gt_pages += 1
            j += 1
        if gt_run_start is not None and gt_pages > best_score:
            best_score = gt_pages
            best = (t_b, ev)
    return best


out = {}
for run in range(1, 9):
    w = parse_host(run)
    gt = gt_2mb(run)
    ep = pick_episode(w, gt)
    if ep:
        t_b, ev = ep
        out[run] = {
            't_b': t_b,
            'events': [[g, t, k] for g, t, k in ev],
        }
        ngt = sum(1 for _, _, k in ev if k == 'GT')
        print(f"run{run}: t_B={t_b} ns, GT accesses in span={ngt}")
    else:
        print(f"run{run}: no episode")
json.dump(out, open("episodes.json", "w"))
print("wrote episodes.json")
