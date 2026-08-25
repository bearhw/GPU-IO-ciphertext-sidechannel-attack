#!/usr/bin/env python3
"""
llm_candidate_confirm.py — connect write-tracker score-based candidate
blocks to orchestrate_v4.py's sweep_blind() content oracle.

Phase 1 (write-tracker, MURA-logic scoring: score = hits * max_run,
MIN_RUN=2, GAP_TOL=2, Region A/B excluded) only tells us WHERE something is
physically active. It does not tell us WHICH block actually holds real
input_ids content. orchestrate_v4.py already has a proven content oracle
for that (sweep_blind: image-pad binary search + targeted phrase-dictionary
scan + AES-block-cleanliness + exact-match verification) -- reuse it as-is
instead of building a second, weaker tool.

For each candidate block (by score, no rank cutoff), treat its base GPA as
sweep_blind's base_gpa anchor and see whether it yields a real TOKEN_LABELS
match. This is a live-guest, live-swap-read operation -- can be slow per
candidate (sweep_blind does ~11 swaps for image_pad bsearch + up to ~42
scan steps x label count), so results are written incrementally.

Usage:
  sudo python3 llm_candidate_confirm.py --host-log /path/to/llm_host_run.log \
      --out confirm_pass.json
  sudo python3 llm_candidate_confirm.py --host-log ... --out ... --limit 20   # quick test
"""
import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from orchestrate_v4 import (  # noqa: E402
    DICT_CACHE, SWAP_TOOL, sweep_blind,
)

ALIGN_2MB = 0x200000
B_LO, B_HI = 0x3f80000000, 0x3f90000000
A_LO, A_HI = 0x3f7fc00000, 0x3f7fd00000
MIN_RUN = 2
GAP_TOL = 2
PAGE_SIZE = 0x1000


def blk(g: int) -> int:
    return g & ~(ALIGN_2MB - 1)


# ── Phase 1 candidate re-derivation (same MURA-logic scoring used by
#    write-tracker/final_logs/plot_llm_detect.py and mura_block_triage.py) --
#    kept self-contained here since this lives in a different tree. ────────
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
            else:
                cand[al] = {'hits': 1, 'max_run': length}

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


def main():
    p = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--host-log", required=True,
                   help="write_pattern_tracker host WRITE log for an LLM capture run")
    p.add_argument("--out", default="confirm_pass.json",
                   help="JSON file listing candidate blocks sweep_blind() confirmed "
                        "(written incrementally)")
    p.add_argument("--swap-tool", default=str(SWAP_TOOL))
    p.add_argument("--limit", type=int, default=None,
                   help="only try the top N candidates by score (omit for the full, "
                        "no-cutoff pass)")
    args = p.parse_args()

    if not DICT_CACHE.exists():
        print(f"[!] {DICT_CACHE} not found -- run "
              f"`sudo python3 orchestrate_v4.py --build` first.", file=sys.stderr)
        sys.exit(1)
    with open(DICT_CACHE) as f:
        cache = json.load(f)
    print(f"[confirm] cache loaded: {len(cache)} offset entries")

    print(f"[confirm] deriving candidates from {args.host_log} ...")
    ranked = load_candidates(args.host_log)
    print(f"[confirm] {len(ranked)} candidate blocks total (no rank cutoff by default)")

    if args.limit:
        ranked = ranked[:args.limit]
        print(f"[confirm] --limit set: trying only the top {len(ranked)} by score")

    passed = []
    for i, (block, info) in enumerate(ranked):
        try:
            matches, N_est = sweep_blind(block, cache, args.swap_tool)
        except Exception as e:
            print(f"[{i+1}/{len(ranked)}] block=0x{block:x} -> ERROR: {e}", file=sys.stderr)
            continue

        status = f"MATCH x{len(matches)}" if matches else "no_match"
        print(f"[{i+1}/{len(ranked)}] block=0x{block:x} hits={info['hits']} "
              f"max_run={info['max_run']}p N_est={N_est} -> {status}")

        if matches:
            passed.append({
                "block": hex(block),
                "hits": info['hits'],
                "max_run": info['max_run'],
                "N_est": N_est,
                "matches": [
                    {
                        "label": m["label"],
                        "token_idx": m["token_idx"],
                        "tok_start": m["tok_start"],
                        "ind_gpa": hex(m["ind_gpa"]),
                        "n_blocks": m["n_blocks"],
                    }
                    for m in matches
                ],
            })
            with open(args.out, "w") as f:
                json.dump(passed, f, indent=2)

    print(f"\n[confirm] Done. {len(passed)}/{len(ranked)} blocks confirmed -> {args.out}")


if __name__ == "__main__":
    main()
