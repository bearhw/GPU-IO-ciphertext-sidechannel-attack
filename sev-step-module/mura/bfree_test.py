#!/usr/bin/env python3
"""
B-free detection test for MURA: find long ascending runs ANYWHERE in the
host write log (no Region-B precursor gate), rank by score, check GT rank.
Compare against the B-gated detector.
"""
import re

B_LO, B_HI = 0x3f80000000, 0x3f90000000
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
PAGE = 0x1000
ALIGN_2MB = 0x200000
MIN_RUN = 2
GAP_TOL = 2


def parse_host(run_id):
    writes = []
    path = f"mura_host_regB_{run_id}.log"
    with open(path) as f:
        for line in f:
            if not line.startswith('WRITE'):
                continue
            m = re.search(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)', line)
            if m:
                writes.append((int(m.group(1), 16), int(m.group(2))))
    return writes


def parse_guest_2mb(run_id):
    path = f"mura_guest_nomul_{run_id}_raw.log"
    all_2mb = set()
    with open(path) as f:
        for line in f:
            m = re.search(r'\[GPA_PAGE\] iter\d+/input .+ GPA=0x([0-9a-f]+)', line)
            if m:
                gpa = int(m.group(1), 16) & ~(PAGE - 1)
                all_2mb.add(gpa & ~(ALIGN_2MB - 1))
    return all_2mb


def detect_bfree(writes):
    """No B gate. Just find every ascending contiguous run over the whole log,
    skipping A and B regions themselves. Score = hits * max_run per 2MB region."""
    cand = {}
    base = 0
    length = 0

    def record(b, ln):
        if ln < MIN_RUN:
            return
        al = b & ~(ALIGN_2MB - 1)
        c = cand.get(al)
        if c:
            c[0] += 1
            if ln > c[1]:
                c[1] = ln
        else:
            cand[al] = [1, ln]

    for gpa, ts in writes:
        # skip control regions entirely (they are not image data)
        if A_LO <= gpa < A_HI or B_LO <= gpa < B_HI:
            if length:
                record(base, length)
            base = 0
            length = 0
            continue
        if length == 0:
            base = gpa
            length = 1
        else:
            expected = base + length * PAGE
            if gpa == expected:
                length += 1
            elif gpa > expected:
                gp = (gpa - expected) // PAGE
                if gp <= GAP_TOL:
                    length += gp + 1
                else:
                    record(base, length)
                    base = gpa
                    length = 1
            else:
                record(base, length)
                base = gpa
                length = 1
    if length:
        record(base, length)

    ranked = sorted(cand.items(), key=lambda kv: (-(kv[1][0] * kv[1][1]), -kv[1][0]))
    return ranked


print("B-FREE detection (no precursor gate) — MURA")
print("=" * 60)
for run in range(1, 6):
    writes = parse_host(run)
    gt2mb = parse_guest_2mb(run)
    ranked = detect_bfree(writes)

    gt_rank = None
    for i, (al, c) in enumerate(ranked):
        if al in gt2mb:
            gt_rank = i + 1
            break
    top1 = ranked[0][0] in gt2mb if ranked else False
    top3 = any(al in gt2mb for al, _ in ranked[:3])
    top5 = any(al in gt2mb for al, _ in ranked[:5])
    print(f"Run {run}: {len(writes)} writes, {len(ranked)} candidates, "
          f"GT rank=#{gt_rank}  top1={'Y' if top1 else 'N'} "
          f"top3={'Y' if top3 else 'N'} top5={'Y' if top5 else 'N'}")
    for i, (al, c) in enumerate(ranked[:5]):
        tag = " <-- GT" if al in gt2mb else ""
        print(f"   #{i+1} 0x{al>>20:05x}  hits={c[0]} max_run={c[1]} "
              f"score={c[0]*c[1]}{tag}")
