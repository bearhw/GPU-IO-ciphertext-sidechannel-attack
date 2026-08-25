#!/usr/bin/env python3
"""
Properly controlled test (previous tests confounded fixed_gpa freshness
with src_gpa freshness at the same time). This isolates ONE variable:
does fixed_gpa's AGE (how long since acquired / how much guest activity
has happened since) matter on its own, holding src_gpa and its content
fixed?

Design:
  1. Acquire ONE fresh fixed_gpa, ONE fresh src_gpa (inject u8=0).
  2. Swap-read #1 immediately -> dump1.
  3. Wait WAIT_SEC (let the guest run / potentially reuse fixed_gpa's frame).
  4. Swap-read #2 using the SAME fixed_gpa and SAME src_gpa (neither
     re-acquired) -> dump2.
  5. Compare. If identical despite the wait, fixed_gpa's age alone does
     NOT matter -- the earlier "fresh fixes it" conclusion was wrong,
     confounded by also changing src_gpa. If they differ, staleness of
     the destination genuinely matters even with source/content unchanged.
"""
import sys
import time
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from mura_dict_build import acquire_gpa, do_swap_read, parse_dump, SWAP_TOOL

WAIT_SEC = 60

print("[test] acquiring fixed_gpa and src_gpa (both fresh, once)...")
fixed_gpa = acquire_gpa(None)
print(f"[test] fixed_gpa = 0x{fixed_gpa:x}")
src_gpa = acquire_gpa(0)
print(f"[test] src_gpa (u8=0) = 0x{src_gpa:x}")

tmp1 = Path("controlled_test_1.out")
tmp2 = Path("controlled_test_2.out")

print("[test] swap-read #1 (immediately)...")
do_swap_read(fixed_gpa, src_gpa, tmp1, str(SWAP_TOOL))
dump1 = parse_dump(tmp1)

print(f"[test] waiting {WAIT_SEC}s (same fixed_gpa, same src_gpa -- NOT re-acquired)...")
time.sleep(WAIT_SEC)

print("[test] swap-read #2 (same fixed_gpa, same src_gpa, after the wait)...")
do_swap_read(fixed_gpa, src_gpa, tmp2, str(SWAP_TOOL))
dump2 = parse_dump(tmp2)

print(f"\n[test] IDENTICAL: {dump1 == dump2}")
if dump1 != dump2:
    diffs = sum(1 for a, b in zip(dump1, dump2) if a != b)
    print(f"[test] {diffs}/{len(dump1)} bytes differ")
    print(f"[test] dump1[:32]: {dump1[:32].hex()}")
    print(f"[test] dump2[:32]: {dump2[:32].hex()}")
    print("[test] -> fixed_gpa AGE matters even with src_gpa/content held constant.")
else:
    print("[test] -> fixed_gpa age alone does NOT explain the earlier mismatch;"
          " the earlier test's real confound was changing src_gpa too.")
