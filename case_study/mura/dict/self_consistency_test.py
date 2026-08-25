#!/usr/bin/env python3
"""Inject u8=0's known chunk fresh via ICMP right now, swap-read it, and
compare against the already-stored ref_000.out -- pure mechanism sanity
check, independent of any real victim content."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from mura_dict_build import (
    acquire_gpa, do_swap_read, parse_dump, DICT_CACHE, SWAP_TOOL, REF_CHUNKS, REF_U8_64,
)
import json

with open(DICT_CACHE) as f:
    cache = json.load(f)
fixed_gpa = int(cache["fixed_gpa"], 16)
old_ref = parse_dump(Path(cache["refs"]["0"]["file"]))

print(f"[test] injecting u8=0 fresh via ICMP...")
gpa_new = acquire_gpa(0)
print(f"[test] fresh GPA_ref000 = 0x{gpa_new:x}")

tmp = Path("self_consistency_new.out")
do_swap_read(fixed_gpa, gpa_new, tmp, str(SWAP_TOOL))
new_ref = parse_dump(tmp)

print(f"\n[test] old ref_000.out length: {len(old_ref)}  new dump length: {len(new_ref)}")
print(f"[test] IDENTICAL: {old_ref == new_ref}")
if old_ref != new_ref:
    diffs = sum(1 for a, b in zip(old_ref, new_ref) if a != b)
    print(f"[test] {diffs}/{len(old_ref)} bytes differ")
    print(f"[test] old[:32]: {old_ref[:32].hex()}")
    print(f"[test] new[:32]: {new_ref[:32].hex()}")
