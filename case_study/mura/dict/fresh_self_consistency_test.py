#!/usr/bin/env python3
"""
Test the user's hypothesis: the earlier self-consistency failure (511/4096
bytes differed comparing a fresh u8=0 swap against the OLD dict_cache's
long-lived fixed_gpa) was caused by fixed_gpa staleness -- the guest
reusing that physical frame for something else between when it was
recorded and when it's reused later.

Fix under test: acquire a BRAND NEW fixed_gpa right now, and do two
swap-reads of the SAME source in immediate succession using that SAME
fresh fixed_gpa. If they match, freshness fixes it. If they still don't
match, the problem is deeper than fixed_gpa staleness.
"""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from mura_dict_build import acquire_gpa, do_swap_read, parse_dump, SWAP_TOOL

print("[test] acquiring a BRAND NEW fixed_gpa right now...")
fixed_gpa = acquire_gpa(None)
print(f"[test] fresh fixed_gpa = 0x{fixed_gpa:x}")

print("[test] injecting u8=0 fresh via ICMP...")
gpa_val = acquire_gpa(0)
print(f"[test] fresh gpa_val = 0x{gpa_val:x}")

tmp_a = Path("fresh_test_a.out")
tmp_b = Path("fresh_test_b.out")

print("[test] swap-read #1 (same fresh fixed_gpa, same source)...")
do_swap_read(fixed_gpa, gpa_val, tmp_a, str(SWAP_TOOL))
dump_a = parse_dump(tmp_a)

print("[test] swap-read #2 (immediately after, same fresh fixed_gpa, same source)...")
do_swap_read(fixed_gpa, gpa_val, tmp_b, str(SWAP_TOOL))
dump_b = parse_dump(tmp_b)

print(f"\n[test] IDENTICAL: {dump_a == dump_b}")
if dump_a != dump_b:
    diffs = sum(1 for a, b in zip(dump_a, dump_b) if a != b)
    print(f"[test] {diffs}/{len(dump_a)} bytes differ")
    print(f"[test] a[:32]: {dump_a[:32].hex()}")
    print(f"[test] b[:32]: {dump_b[:32].hex()}")
else:
    print("[test] MATCH -- fresh fixed_gpa fixes self-consistency.")
