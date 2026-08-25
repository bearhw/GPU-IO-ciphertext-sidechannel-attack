#!/usr/bin/env python3
"""
Prototype of write_pattern_tracker_B logic, replayed over host traces.

Improvements over early_exit:
  1. precursor = B region [0x3f80000000, 0x3f90000000) ONLY; the A clock
     region [0x3f7fc00000, 0x3f7fd00000) is explicitly NOT a precursor.
  2. timing window: a candidate run must START within WINDOW_NS of the B
     precursor's timestamp (B->image gap p90 ~88us in the data). This rejects
     long noise runs that begin much later in the same lookahead.
  3. run pages in the precursor/clock ranges are skipped, never counted.
Score = hit_count x max_run_len (unchanged).
"""
import re, sys, collections

PAGE = 0x1000
ALIGN_2MB = 0x200000
B_LO, B_HI = 0x3f80000000, 0x3f90000000       # precursor (region B)
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000       # clock (region A) - excluded

LINE = re.compile(rb'WRITE\s+gpa=0x([0-9a-fA-F]+)\s+ts=(\d+)')


def in_B(g): return B_LO <= g < B_HI
def in_A(g): return A_LO <= g < A_HI


def replay(path, lookahead=30, min_run=2, gap=2, window_ns=100_000):
    cand = {}   # aligned -> [hits, max_run, best_exact]

    def record(base, run_len):
        a = base & ~(ALIGN_2MB - 1)
        c = cand.get(a)
        if c:
            c[0] += 1
            if run_len > c[1]: c[1] = run_len
            if base < c[2]: c[2] = base
        else:
            cand[a] = [1, run_len, base]

    look_active = False
    look_remaining = 0
    look_base = 0
    look_len = 0
    look_prec_ns = 0
    total = precursors = 0

    with open(path, 'rb') as f:
        for line in f:
            m = LINE.match(line)
            if not m:
                continue
            gpa = int(m.group(1), 16)
            ts = int(m.group(2))
            total += 1

            if in_B(gpa):
                if look_active and look_len >= min_run:
                    record(look_base, look_len)
                precursors += 1
                look_active = True
                look_remaining = lookahead
                look_base = 0
                look_len = 0
                look_prec_ns = ts
                continue

            if not look_active:
                continue

            # never build a run out of the control regions themselves
            if in_A(gpa) or in_B(gpa):
                continue

            # timing gate: run must begin promptly after the precursor
            if look_len == 0 and (ts - look_prec_ns) > window_ns:
                look_active = False
                continue

            if look_len == 0:
                look_base = gpa
                look_len = 1
            else:
                expected = look_base + look_len * PAGE
                if gpa == expected:
                    look_len += 1
                elif gpa > expected:
                    gp = (gpa - expected) // PAGE
                    if gp <= gap:
                        look_len += gp + 1
                    else:
                        if look_len >= min_run:
                            record(look_base, look_len); look_active = False; continue
                        look_base = gpa; look_len = 1
                else:
                    if look_len >= min_run:
                        record(look_base, look_len); look_active = False; continue
                    look_base = gpa; look_len = 1

            if look_len < min_run:
                look_remaining -= 1
                if look_remaining <= 0:
                    look_active = False

    if look_active and look_len >= min_run:
        record(look_base, look_len)

    ranked = sorted(cand.items(), key=lambda kv: (-(kv[1][0]*kv[1][1]), -kv[1][0]))
    return ranked, total, precursors


if __name__ == '__main__':
    ranked, total, prec = replay(sys.argv[1])
    for i, (a, c) in enumerate(ranked[:5]):
        print(f"#{i+1} 0x{a:012x} hits={c[0]} max_run={c[1]} score={c[0]*c[1]} exact=0x{c[2]:x}")
