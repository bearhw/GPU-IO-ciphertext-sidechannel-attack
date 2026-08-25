#!/usr/bin/env python3
"""
Compare B-gated vs B-free detection on MURA:
  - GT rank (2MB region)
  - exact start-GPA match (candidate run base == a GT image page GPA)
  - false-positive characterisation of the top candidates
"""
import re

B_LO, B_HI = 0x3f80000000, 0x3f90000000
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
PAGE = 0x1000
ALIGN_2MB = 0x200000
MIN_RUN = 2
GAP_TOL = 2
LOOKAHEAD = 12
WINDOW_NS = 40_000


def parse_host(run_id):
    writes = []
    with open(f"mura_host_regB_{run_id}.log") as f:
        for line in f:
            if not line.startswith('WRITE'):
                continue
            m = re.search(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)', line)
            if m:
                writes.append((int(m.group(1), 16), int(m.group(2))))
    return writes


def parse_guest(run_id):
    """Return (all GT page GPAs set, all GT 2MB set, per-iter min page GPA set)."""
    pages = set()
    twomb = set()
    iter_pages = {}
    with open(f"mura_guest_nomul_{run_id}_raw.log") as f:
        for line in f:
            m = re.search(r'\[GPA_PAGE\] iter(\d+)/input .+ GPA=0x([0-9a-f]+)', line)
            if m:
                it = int(m.group(1))
                g = int(m.group(2), 16) & ~(PAGE - 1)
                pages.add(g)
                twomb.add(g & ~(ALIGN_2MB - 1))
                iter_pages.setdefault(it, set()).add(g)
    buf_starts = {min(s) for s in iter_pages.values()}
    return pages, twomb, buf_starts


def detect_bfree(writes):
    cand = {}
    base = length = 0

    def record(b, ln):
        if ln < MIN_RUN:
            return
        al = b & ~(ALIGN_2MB - 1)
        c = cand.get(al)
        if c:
            c['hits'] += 1
            if ln > c['max_run']:
                c['max_run'] = ln
            if b < c['exact']:
                c['exact'] = b
            c['bases'].add(b)
        else:
            cand[al] = {'hits': 1, 'max_run': ln, 'exact': b, 'bases': {b}}

    for gpa, ts in writes:
        if A_LO <= gpa < A_HI or B_LO <= gpa < B_HI:
            if length:
                record(base, length)
            base = length = 0
            continue
        if length == 0:
            base, length = gpa, 1
        else:
            exp = base + length * PAGE
            if gpa == exp:
                length += 1
            elif gpa > exp:
                gp = (gpa - exp) // PAGE
                if gp <= GAP_TOL:
                    length += gp + 1
                else:
                    record(base, length); base, length = gpa, 1
            else:
                record(base, length); base, length = gpa, 1
    if length:
        record(base, length)
    return sorted(cand.items(),
                  key=lambda kv: (-(kv[1]['hits'] * kv[1]['max_run']), -kv[1]['hits']))


def detect_bgated(writes):
    cand = {}
    active = False
    remaining = 0
    base = length = prec = 0

    def record(b, ln):
        if ln < MIN_RUN:
            return
        al = b & ~(ALIGN_2MB - 1)
        c = cand.get(al)
        if c:
            c['hits'] += 1
            if ln > c['max_run']:
                c['max_run'] = ln
            if b < c['exact']:
                c['exact'] = b
            c['bases'].add(b)
        else:
            cand[al] = {'hits': 1, 'max_run': ln, 'exact': b, 'bases': {b}}

    for gpa, ts in writes:
        if B_LO <= gpa < B_HI:
            if active and length >= MIN_RUN:
                record(base, length)
            active = True
            remaining = LOOKAHEAD
            base = length = 0
            prec = ts
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
            elif gpa > exp:
                gp = (gpa - exp) // PAGE
                if gp <= GAP_TOL:
                    length += gp + 1
                else:
                    if length >= MIN_RUN:
                        record(base, length); active = False; continue
                    base, length = gpa, 1
            else:
                if length >= MIN_RUN:
                    record(base, length); active = False; continue
                base, length = gpa, 1
        if length < MIN_RUN:
            remaining -= 1
            if remaining <= 0:
                active = False
    if active and length >= MIN_RUN:
        record(base, length)
    return sorted(cand.items(),
                  key=lambda kv: (-(kv[1]['hits'] * kv[1]['max_run']), -kv[1]['hits']))


def summarize(name, ranked, gt_pages, gt_2mb, buf_starts):
    gt_rank = next((i + 1 for i, (al, _) in enumerate(ranked) if al in gt_2mb), None)
    # exact match: does any GT-region candidate's exact base hit a real GT page?
    exact_hit = None
    for i, (al, c) in enumerate(ranked):
        if al in gt_2mb and (c['bases'] & gt_pages):
            exact_hit = i + 1
            break
    # buffer-start match (candidate exact == the true buffer start page)
    start_hit = any((c['bases'] & buf_starts) for al, c in ranked if al in gt_2mb)
    # FP among top-5: candidates NOT in a GT 2MB region
    fp_top5 = [(al, c) for al, c in ranked[:5] if al not in gt_2mb]
    return gt_rank, exact_hit, start_hit, fp_top5


print("MURA: B-gated vs B-free — full comparison")
print("=" * 78)
agg = {'g': {'t1': 0, 't3': 0, 't5': 0, 'ex': 0}, 'f': {'t1': 0, 't3': 0, 't5': 0, 'ex': 0}}
for run in range(1, 6):
    writes = parse_host(run)
    gt_pages, gt_2mb, buf_starts = parse_guest(run)
    rg = detect_bgated(writes)
    rf = detect_bfree(writes)

    print(f"\n--- Run {run}  ({len(writes):,} writes, GT 2MB regions={len(gt_2mb)}) ---")
    for tag, ranked, key in (("B-gated", rg, 'g'), ("B-free ", rf, 'f')):
        gr, ex, sh, fp = summarize(tag, ranked, gt_pages, gt_2mb, buf_starts)
        t1 = gr == 1
        t3 = gr is not None and gr <= 3
        t5 = gr is not None and gr <= 5
        agg[key]['t1'] += t1
        agg[key]['t3'] += t3
        agg[key]['t5'] += t5
        agg[key]['ex'] += ex is not None
        fp_desc = ", ".join(f"0x{al>>20:05x}(r{c['max_run']})" for al, c in fp[:3])
        print(f"  {tag}: GT_rank=#{gr:<3} exact_match={'#'+str(ex) if ex else 'no':<4} "
              f"buf_start={'Y' if sh else 'N'}  cands={len(ranked)}")
        print(f"           top-5 FP regions: {fp_desc if fp_desc else '(none)'}")

print("\n" + "=" * 78)
print("AGGREGATE (n=5)")
print(f"  {'':10} {'top1':>6} {'top3':>6} {'top5':>6} {'exact-GPA':>10}")
for key, label in (('g', 'B-gated'), ('f', 'B-free')):
    a = agg[key]
    print(f"  {label:10} {a['t1']:>4}/5 {a['t3']:>4}/5 {a['t5']:>4}/5 {a['ex']:>8}/5")
