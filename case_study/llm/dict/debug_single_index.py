#!/usr/bin/env python3
"""
Standalone diagnostic — run sweep_blind for exactly one filtered_samples.json
index, bypassing run_all's resume-by-CSV logic entirely (so already-done
indices can be re-examined without touching run_all_v3-aug6.csv).

Investigates two run_all_v3-aug6.csv anomalies from the new 27-label
(context-tokenized) dictionary:
  - index=14 indication is literally "Altered mental status" (verbatim label
    text for token_idx=8) yet run_all reported NO_MATCH.
  - index=5 "Shortness of breath and cough" reported MATCH token_idx=8
    "Altered mental status" (zero real overlap) despite MIN_CLEAN_AES_BLOCKS=2
    having been added specifically to kill this failure mode.

Usage:
    sudo python3 debug_single_index.py --index 14
"""

import argparse
import json
import subprocess

import orchestrate_v3 as v3


def main() -> None:
    p = argparse.ArgumentParser()
    p.add_argument("--index", type=int, required=True)
    p.add_argument("--swap-tool", default=str(v3.SWAP_TOOL))
    args = p.parse_args()

    with open(v3.DICT_CACHE) as f:
        cache = json.load(f)
    print(f"[diag] loaded dict cache: {len(cache)} offset entries")

    r = subprocess.run(v3.SSH_BASE + [f"cat {v3.GUEST_SAMPLES_JSON}"],
                       capture_output=True, text=True, timeout=30)
    samples = json.loads(r.stdout)
    sample = next(s for s in samples if s["index"] == args.index)
    print(f"[diag] index={args.index}  indication='{sample.get('indication','')}'")

    base_gpa, N, N_ind, tok_start_g, header_c, proc = v3._acquire_gpa_raw(args.index)
    if base_gpa is None:
        print("[diag] GPA acquisition failed")
        return

    print(f"[diag] base_gpa=0x{base_gpa:x}  N={N}  N_ind={N_ind}"
          f"  tok_start={tok_start_g}  header_const={header_c}")

    try:
        matches, N_est = v3.sweep_blind(
            base_gpa, cache, args.swap_tool,
            N=N, exact=True, N_ind=N_ind,
            tok_start_exact=tok_start_g, header_const=header_c)
    finally:
        if proc is not None:
            try:
                proc.kill(); proc.wait()
            except Exception:
                pass

    if matches:
        kind = "MULTI_MATCH" if len(matches) > 1 else "MATCH"
        print(f"[diag] RESULT: {kind} ({len(matches)})")
        for m in matches:
            print(f"  tok_start={m['tok_start']} token_idx={m['token_idx']} "
                  f"'{m['label']}' blocks={m['n_blocks']}")
    else:
        print(f"[diag] RESULT: NO_MATCH (N_est={N_est})")


if __name__ == "__main__":
    main()
