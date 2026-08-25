#!/usr/bin/env python3
"""
Quantify when B-free suffices vs when the B precursor is needed.
Uses the canonical B-gated detector (mirrors plot_image_detect.py / C logic)
and a B-free detector (same run builder, no precursor gate).

Axes per run:
  W    = total writes
  Rgt  = largest run landing in a GT 2MB region   (image signal size)
  Rfp  = largest run landing OUTSIDE any GT region (worst competing FP)
  rho  = Rgt / Rfp
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
HOST_RE = re.compile(r'gpa=0x([0-9a-f]+)\s+ts=(\d+)')


def parse_host(path):
    w = []
    with open(path) as f:
        for line in f:
            if not line.startswith('WRITE'):
                continue
            m = HOST_RE.search(line)
            if m:
                w.append((int(m.group(1), 16), int(m.group(2))))
    return w


def mura_gt(run):
    s = set()
    with open(f"mura_guest_nomul_{run}_raw.log") as f:
        for line in f:
            m = re.search(r'\[GPA_PAGE\] iter\d+/input .+ GPA=0x([0-9a-f]+)', line)
            if m:
                g = int(m.group(1), 16) & ~(PAGE - 1)
                s.add(g & ~(ALIGN_2MB - 1))
    return s


def mnist_gt(run):
    s = set()
    with open(f"../mnist/run{run}_guest.log") as f:
        for line in f:
            m = re.search(r'\[Train\] batch \d+ (?:image )?GPA: 0x([0-9a-f]+)', line)
            if m:
                g = int(m.group(1), 16) & ~(PAGE - 1)
                s.add(g & ~(ALIGN_2MB - 1))
    return s


def detect_gated(writes):
    cand = {}
    active = False
    remaining = base = length = prec = 0

    def fin():
        nonlocal base, length
        if length >= MIN_RUN:
            al = base & ~(ALIGN_2MB - 1)
            c = cand.get(al)
            if c:
                c['hits'] += 1
                if length > c['max_run']:
                    c['max_run'] = length
            else:
                cand[al] = {'hits': 1, 'max_run': length}

    for gpa, ts in writes:
        if B_LO <= gpa < B_HI:
            if active:
                fin()
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
                    fin(); base, length = gpa, 1
            else:
                fin(); base, length = gpa, 1
        if length < MIN_RUN:
            remaining -= 1
            if remaining <= 0:
                active = False
    if active:
        fin()
    return sorted(cand.items(),
                  key=lambda kv: (-(kv[1]['hits'] * kv[1]['max_run']), -kv[1]['hits']))


def detect_free(writes):
    cand = {}
    base = length = 0

    def fin():
        nonlocal base, length
        if length >= MIN_RUN:
            al = base & ~(ALIGN_2MB - 1)
            c = cand.get(al)
            if c:
                c['hits'] += 1
                if length > c['max_run']:
                    c['max_run'] = length
            else:
                cand[al] = {'hits': 1, 'max_run': length}

    for gpa, ts in writes:
        if A_LO <= gpa < A_HI or B_LO <= gpa < B_HI:
            fin(); base = length = 0
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
                    fin(); base, length = gpa, 1
            else:
                fin(); base, length = gpa, 1
    fin()
    return sorted(cand.items(),
                  key=lambda kv: (-(kv[1]['hits'] * kv[1]['max_run']), -kv[1]['hits']))


def rank_of(ranked, gt2mb):
    for i, (al, _) in enumerate(ranked):
        if al in gt2mb:
            return i + 1
    return None


DATA = [("mnist", r, f"../mnist/run{r}.log", mnist_gt) for r in range(1, 9)] + \
       [("mura", r, f"mura_host_regB_{r}.log", mura_gt) for r in range(1, 6)]
BATCH = {1: 512, 2: 512, 3: 512, 4: 512, 5: 256, 6: 128, 7: 128, 8: 128}

print(f"{'run':10}{'batch':>6}{'W(M)':>7}{'Rgt':>6}{'Rfp':>6}{'rho':>7}"
      f"{'free':>6}{'gate':>6}  verdict")
print("-" * 74)
rows = []
for ds, run, hpath, gtf in DATA:
    writes = parse_host(hpath)
    gt2mb = gtf(run)
    rf = detect_free(writes)
    rg = detect_gated(writes)
    Rgt = max((c['max_run'] for al, c in rf if al in gt2mb), default=0)
    Rfp = max((c['max_run'] for al, c in rf if al not in gt2mb), default=1)
    rho = Rgt / Rfp if Rfp else 0
    rk_f = rank_of(rf, gt2mb)
    rk_g = rank_of(rg, gt2mb)

    f_ok = rk_f is not None and rk_f <= 3
    g_better = (rk_g or 999) + 2 < (rk_f or 999)   # gate materially better
    if f_ok and not g_better:
        verdict = "B-free suffices"
    elif (rk_g is not None and rk_g <= 3) and g_better:
        verdict = "B needed"
    else:
        verdict = "both weak"

    batch = BATCH.get(run, 1) if ds == "mnist" else 1
    tag = f"{ds}{run}"
    print(f"{tag:10}{batch:>6}{len(writes)/1e6:>7.2f}{Rgt:>6}{Rfp:>6}{rho:>7.2f}"
          f"{('#'+str(rk_f)):>6}{('#'+str(rk_g)):>6}  {verdict}")
    rows.append((tag, len(writes), Rgt, Rfp, rho, rk_f, rk_g, verdict))

print("-" * 74)
print("\nSorted by rho = Rgt/Rfp (image-run size / worst FP-run size):")
print(f"{'run':10}{'rho':>7}{'Rgt':>6}{'Rfp':>6}{'W(M)':>7}  free  gate  verdict")
for tag, W, Rgt, Rfp, rho, rk_f, rk_g, v in sorted(rows, key=lambda x: -x[4]):
    print(f"{tag:10}{rho:>7.2f}{Rgt:>6}{Rfp:>6}{W/1e6:>7.2f}  "
          f"{('#'+str(rk_f)):>4}  {('#'+str(rk_g)):>4}  {v}")


# ============================================================
# Real discriminant: score margin  M = (Hgt*Rgt) / (Hfp*Rfp)
# ============================================================
print("\n" + "=" * 74)
print("SCORE-MARGIN discriminant (B-free): M = score_GT / score_worstFP")
print(f"{'run':10}{'Hgt':>6}{'Rgt':>6}{'sGT':>9}{'Hfp':>6}{'Rfp':>6}{'sFP':>9}"
      f"{'M':>7}  free")
print("-" * 74)
for ds, run, hpath, gtf in DATA:
    writes = parse_host(hpath)
    gt2mb = gtf(run)
    rf = detect_free(writes)
    # best GT candidate by score
    gt_cands = [(al, c) for al, c in rf if al in gt2mb]
    fp_cands = [(al, c) for al, c in rf if al not in gt2mb]
    if not gt_cands:
        continue
    gal, gc = max(gt_cands, key=lambda x: x[1]['hits'] * x[1]['max_run'])
    fal, fc = max(fp_cands, key=lambda x: x[1]['hits'] * x[1]['max_run'])
    sGT = gc['hits'] * gc['max_run']
    sFP = fc['hits'] * fc['max_run']
    M = sGT / sFP if sFP else 0
    rk_f = rank_of(rf, gt2mb)
    print(f"{ds}{run:<5}{gc['hits']:>6}{gc['max_run']:>6}{sGT:>9}"
          f"{fc['hits']:>6}{fc['max_run']:>6}{sFP:>9}{M:>7.2f}  #{rk_f}")
