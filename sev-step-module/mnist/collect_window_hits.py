#!/usr/bin/env python3
"""
For every MNIST run, pair each Region-B precursor with the FIRST GT-region
ascending run that follows it (within a lookahead of non-control writes),
WITHOUT applying the 40us gate, and record the B->GT delay.
This reproduces the run1_B2GT_cases method for all runs so we can show how
often GT access lands inside the 40us window across the whole dataset.
"""
import re
import statistics as st

B_LO, B_HI = 0x3f80000000, 0x3f90000000
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
PAGE = 0x1000
ALIGN_2MB = 0x200000
LOOKAHEAD = 30
HOST_RE = re.compile(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)')
BATCH = {1: 512, 2: 512, 3: 512, 4: 512, 5: 256, 6: 128, 7: 128,
         'bs64-1': 64, 'bs64-2': 64, 'bs64-3': 64}


def parse_host(run):
    if str(run).startswith('bs64'):
        n = run.split('-')[1]
        fname = f"run{n}_bs64.log"
    else:
        fname = f"run{run}.log"
    w = []
    with open(fname) as f:
        for line in f:
            if not line.startswith('WRITE'):
                continue
            m = HOST_RE.search(line)
            if m:
                w.append((int(m.group(1), 16), int(m.group(2))))
    return w


def gt_2mb(run):
    if str(run).startswith('bs64'):
        n = run.split('-')[1]
        fname = f"run{n}_guest_bs64.log"
    else:
        fname = f"run{run}_guest.log"
    s = set()
    with open(fname) as f:
        for line in f:
            m = re.search(r'\[Train\] batch \d+ (?:image )?GPA: 0x([0-9a-f]+)', line)
            if m:
                s.add((int(m.group(1), 16) & ~(PAGE - 1)) & ~(ALIGN_2MB - 1))
    return s


def collect_delays(writes, gt2mb):
    """For each B precursor, scan up to LOOKAHEAD non-control writes; find the
    first page in a GT 2MB region that begins an ascending run (next scanned
    page == p+0x1000). Record delay(us) = (ts_p - ts_B)."""
    delays = []
    n = len(writes)
    i = 0
    while i < n:
        gpa, ts = writes[i]
        if not (B_LO <= gpa < B_HI):
            i += 1
            continue
        b_ts = ts
        # gather following non-control writes
        seq = []
        j = i + 1
        steps = 0
        while j < n and steps < LOOKAHEAD:
            g, t = writes[j]
            if B_LO <= g < B_HI:
                break
            if A_LO <= g < A_HI:
                j += 1
                continue
            seq.append((g, t))
            steps += 1
            j += 1
        # find first GT-region ascending-run start
        for k in range(len(seq) - 1):
            g, t = seq[k]
            if (g & ~(ALIGN_2MB - 1)) in gt2mb and seq[k + 1][0] == g + PAGE:
                delays.append((t - b_ts) / 1000.0)
                break
        i += 1
    return delays


if __name__ == '__main__':
    import json
    all_out = {}
    runs = list(range(1, 8)) + ['bs64-1', 'bs64-2', 'bs64-3']
    for run in runs:
        w = parse_host(run)
        gt = gt_2mb(run)
        d = collect_delays(w, gt)
        all_out[str(run)] = d
        if d:
            inside = sum(1 for x in d if 0 <= x <= 40)
            print(f"run{run} b{BATCH[run]}: {len(d)} B->GT cases, "
                  f"inside 40us: {inside} ({100*inside/len(d):.0f}%), "
                  f"median {st.median(d):.1f}us")
        else:
            print(f"run{run}: no cases")
    json.dump(all_out, open("window_hits.json", "w"))
    print("wrote window_hits.json")
