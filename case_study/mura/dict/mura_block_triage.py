#!/usr/bin/env python3
"""
mura_block_triage.py — Phase 2-1: cheap content-based block triage.

Score-based candidate ranking (write_pattern_tracker host log -> MURA-logic
candidate blocks: score = hits * max_run) only tells you WHERE something is
physically active. It does NOT tell you whether a given candidate actually
contains real pixel content vs. incidental background traffic (measured
purity at top-10 was only 6-37%). This script adds the missing content check,
reusing the existing chosen-plaintext dictionary oracle from
mura_dict_build.py, WITHOUT discarding any candidate by rank -- every
candidate block gets probed (no cutoff), just cheaply (a few representative
pages per block, not the full 49-page image dump).

Pipeline position:
  Phase 1   (write-tracker)      -> ranked candidate blocks (no cutoff)
  Phase 2-1 (THIS SCRIPT)        -> per-block cheap probe -> pass/reject
  Phase 2-2 (mura_dict_build.py --infer, unchanged) -> full per-channel
            49-page extraction for every block that passed 2-1

Why probe MULTIPLE representative pages per block (not just one):
  A block's single longest run can still include foreign (non-image) pages
  at its edges (mixed bursts, see the LLM burst analysis in this project).
  Probing only the very first page of the run risks a false reject if that
  particular page happens to be the foreign part. We probe start/middle/end
  of the run instead.

Why comparison uses the DUMPED reference pages, not the intended write
pattern (REF_CHUNKS): mura_dict_build.py's own infer() compares against
parse_dump(ref_file) (what came back from swap-read), not REF_CHUNKS
directly, and does so position-wise (chunk j vs chunk j, not chunk j vs any
chunk). We replicate that exact comparison rule here for consistency.

Usage:
  sudo python3 mura_block_triage.py --host-log /path/to/mura_host_regB_1.log \
      --out triage_pass.json
  sudo python3 mura_block_triage.py --host-log ... --out triage_pass.json --limit 50   # quick test
"""
import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from mura_dict_build import (  # noqa: E402
    DICT_CACHE, REF_U8_64, CHUNK_SIZE, PAGE_SIZE,
    do_swap_read, parse_dump, SWAP_TOOL,
)

ALIGN_2MB = 0x200000
B_LO, B_HI = 0x3f80000000, 0x3f90000000
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
MIN_RUN = 2
GAP_TOL = 2

HERE = Path(__file__).parent
TRIAGE_TMP = HERE / "triage_tmp"


def blk(g: int) -> int:
    return g & ~(ALIGN_2MB - 1)


# ── Phase 1 candidate re-derivation (same MURA-logic scoring as
#    write-tracker/mura/plot_mura_detect.py) -- kept self-contained here since
#    this lives in a different tree; also tracks each candidate's single
#    longest observed run (best_range), which is all triage needs. ──────────
def load_candidates(host_log_path: str):
    cand = {}
    base = length = 0

    def record():
        nonlocal base, length
        if length >= MIN_RUN:
            al = blk(base)
            c = cand.get(al)
            if c:
                c['hits'] += 1
                if length > c['max_run']:
                    c['max_run'] = length
                    c['best_range'] = (base, length)
            else:
                cand[al] = {'hits': 1, 'max_run': length, 'best_range': (base, length)}

    with open(host_log_path, errors='ignore') as f:
        for line in f:
            m = re.match(r'WRITE\s+gpa=0x([0-9a-f]+)\s+ts=(\d+)', line)
            if not m:
                continue
            gpa = int(m.group(1), 16)
            if A_LO <= gpa < A_HI or B_LO <= gpa < B_HI:
                record(); base = length = 0
                continue
            if length == 0:
                base, length = gpa, 1
            else:
                expected = base + length * PAGE_SIZE
                if gpa == expected:
                    length += 1
                elif gpa > expected:
                    gap = (gpa - expected) // PAGE_SIZE
                    if gap <= GAP_TOL:
                        length += gap + 1
                    else:
                        record(); base, length = gpa, 1
                else:
                    record(); base, length = gpa, 1
    record()

    ranked = sorted(cand.items(),
                     key=lambda kv: (-(kv[1]['hits'] * kv[1]['max_run']), -kv[1]['hits']))
    return ranked  # [(block_addr, info_dict), ...] descending by score


def representative_pages(base: int, length: int, n: int = 3) -> list[int]:
    """start / middle / end pages of the run (deduped, order preserved)."""
    if length <= n:
        offsets = list(range(length))
    else:
        offsets = sorted(set([0, length // 2, length - 1]))
    return [base + o * PAGE_SIZE for o in offsets]


def load_ref_dumps(cache: dict) -> dict[int, bytes]:
    """Load the 64 already-dumped reference pages (Phase 0 output),
    same as mura_dict_build.py's infer() does."""
    ref_dumps = {}
    missing = []
    for u8_val in REF_U8_64:
        entry = cache["refs"].get(str(u8_val))
        if entry is None:
            missing.append(u8_val)
            continue
        ref_dumps[u8_val] = parse_dump(Path(entry["file"]))
    if missing:
        print(f"[!] Missing ref dumps for u8 values: {missing}", file=sys.stderr)
        print("[!] Re-run mura_dict_build.py --build to complete the dictionary.",
              file=sys.stderr)
        sys.exit(1)
    return ref_dumps


def probe_page(fixed_gpa: int, page_gpa: int, ref_dumps: dict[int, bytes],
               swap_tool: str) -> bool:
    """One do_swap_read + position-wise chunk compare against all 64 refs.
    Early-exits on the first exact 16-byte match at a shared chunk offset --
    matches infer()'s comparison rule exactly (chunk j vs chunk j)."""
    tmp = TRIAGE_TMP / f"probe_{page_gpa:x}.out"
    do_swap_read(fixed_gpa, page_gpa, tmp, swap_tool)
    data = parse_dump(tmp)
    tmp.unlink(missing_ok=True)

    for off in range(0, PAGE_SIZE, CHUNK_SIZE):
        chunk = data[off:off + CHUNK_SIZE]
        for ref_bytes in ref_dumps.values():
            if chunk == ref_bytes[off:off + CHUNK_SIZE]:
                return True
    return False


def main():
    p = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--host-log", required=True,
                   help="write_pattern_tracker host WRITE log (e.g. mura_host_regB_1.log)")
    p.add_argument("--out", default="triage_pass.json",
                   help="JSON file listing blocks that passed triage (written incrementally)")
    p.add_argument("--swap-tool", default=str(SWAP_TOOL))
    p.add_argument("--rep-pages", type=int, default=3,
                   help="representative pages probed per block (default: 3)")
    p.add_argument("--limit", type=int, default=None,
                   help="only triage the first N candidates by score -- for a quick test run "
                        "(omit for the real no-cutoff pass over all candidates)")
    args = p.parse_args()

    if not DICT_CACHE.exists():
        print(f"[!] {DICT_CACHE} not found -- run `sudo python3 mura_dict_build.py --build` first.",
              file=sys.stderr)
        sys.exit(1)
    with open(DICT_CACHE) as f:
        cache = json.load(f)
    fixed_gpa = int(cache["fixed_gpa"], 16)

    ref_dumps = load_ref_dumps(cache)
    print(f"[triage] {len(ref_dumps)} reference pages loaded")

    print(f"[triage] deriving candidates from {args.host_log} ...")
    ranked = load_candidates(args.host_log)
    print(f"[triage] {len(ranked)} candidate blocks total (no rank cutoff by default)")

    if args.limit:
        ranked = ranked[:args.limit]
        print(f"[triage] --limit set: probing only the top {len(ranked)} by score")

    TRIAGE_TMP.mkdir(exist_ok=True)

    passed = []
    for i, (block, info) in enumerate(ranked):
        base, length = info['best_range']
        pages = representative_pages(base, length, args.rep_pages)

        hit = False
        for page_gpa in pages:
            try:
                if probe_page(fixed_gpa, page_gpa, ref_dumps, args.swap_tool):
                    hit = True
                    break
            except Exception as e:
                print(f"  [!] probe failed at 0x{page_gpa:x}: {e}", file=sys.stderr)

        status = "PASS" if hit else "reject"
        print(f"[{i+1}/{len(ranked)}] block=0x{block:x} hits={info['hits']} "
              f"max_run={info['max_run']}p probed={len(pages)}p -> {status}")

        if hit:
            passed.append({
                "block": hex(block),
                "hits": info['hits'],
                "max_run": info['max_run'],
                "best_range_base": hex(base),
                "best_range_len": length,
            })
            with open(args.out, "w") as f:
                json.dump(passed, f, indent=2)

    print(f"\n[triage] Done. {len(passed)}/{len(ranked)} blocks passed -> {args.out}")
    if passed:
        print("[triage] Next (Phase 2-2), for each passed block's best_range_base, per channel:")
        print("  sudo python3 mura_dict_build.py --infer "
              "--image-gpa <best_range_base> --out <block>_chR.npy")


if __name__ == "__main__":
    main()
