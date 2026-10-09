#!/usr/bin/env python3
"""
case_study/llm/pipeline/evaluate_localization.py — Address Localization Evaluation & Metrics.

Computes Base GPA localization success rate, swap efficiency, and runtime stats
from pipeline_summary.csv — and, crucially, separates *blind* localization
(the honest attacker number) from *GT-assisted* hits where the ground-truth
block was fed to the search as a bootstrap fallback (strategy == "bootstrap").

Usage:
    python3 evaluate_localization.py
    python3 evaluate_localization.py --csv pipeline_summary.csv
    python3 evaluate_localization.py --from-json     # aggregate stage3_located_*.json instead of the CSV
"""

import argparse
import glob
import json
import sys
from collections import Counter
from pathlib import Path
from typing import Any, Dict, List

import common as c


def parse_args():
    p = argparse.ArgumentParser(description="Evaluate Address Localization Accuracy")
    p.add_argument("--csv", type=Path, default=c.PIPELINE_DIR / "pipeline_summary.csv",
                   help="Path to pipeline_summary.csv")
    p.add_argument("--from-json", action="store_true",
                   help="Aggregate stage3_located_*.json files in the output dir instead of the CSV")
    p.add_argument("--output-dir", type=Path, default=c.PIPELINE_DIR,
                   help="Directory holding stage3_located_*.json (with --from-json)")
    return p.parse_args()


def strategy_family(strat: str) -> str:
    """Collapse a per-sample winning strategy label into its family."""
    s = (strat or "").strip()
    if not s or s.upper() == "FAIL":
        return "FAIL"
    return s.split("@")[0].split("-cand")[0] if s.startswith("tracker") else s.split("@")[0]


def load_rows_from_csv(csv_path: Path) -> List[Dict[str, Any]]:
    return list(c.load_summary_csv(csv_path).values())


def load_rows_from_json(out_dir: Path) -> List[Dict[str, Any]]:
    rows = []
    files = glob.glob(str(out_dir / "stage3_located_*.json"))
    files.sort(key=lambda p: int(Path(p).stem.split("_")[-1]))
    for f in files:
        try:
            d = json.load(open(f))
        except Exception:
            continue
        rows.append({
            "index": d.get("index", ""),
            "gt_base": d.get("gt_base") or "",
            "host_base": d.get("host_base") or "",
            "loc_strategy": d.get("loc_strategy", "FAIL"),
            "loc_swaps": d.get("loc_swaps", 0),
            "loc_match": d.get("loc_match", False),
            "blind": d.get("blind", ""),
            "elapsed_sec": 0.0,
        })
    return rows


def _to_int(s: Any) -> int:
    try:
        return int(str(s).strip(), 16)
    except (ValueError, TypeError):
        return 0


def is_match(r: Dict[str, Any]) -> bool:
    # Recompute from addresses with the shared relaxed criterion (c.loc_is_hit)
    # so old CSVs/JSONs are re-scored under the same rule as fresh runs; fall
    # back to the stored loc_match flag only when an address is missing.
    gt = _to_int(r.get("gt_base"))
    host = _to_int(r.get("host_base"))
    if gt and host:
        return c.loc_is_hit(host, gt)
    return str(r.get("loc_match", "")).strip().lower() == "true"


def is_blind_run(r: Dict[str, Any]) -> bool:
    return str(r.get("blind", "")).strip().lower() == "true"


def pct(n: int, d: int) -> str:
    return f"{(n / d * 100.0):.2f}%" if d else "n/a"


def report_block(title: str, rows: List[Dict[str, Any]]) -> None:
    total = len(rows)
    if total == 0:
        return
    matched = [r for r in rows if is_match(r)]
    # A "blind-legitimate" success is a match NOT won via the GT bootstrap fallback.
    blind_ok = [r for r in matched if strategy_family(r.get("loc_strategy")) != "bootstrap"]
    gt_assisted = [r for r in matched if strategy_family(r.get("loc_strategy")) == "bootstrap"]

    swaps = []
    times = []
    for r in rows:
        try:
            swaps.append(int(float(r.get("loc_swaps", 0))))
        except (ValueError, TypeError):
            pass
        try:
            times.append(float(r.get("elapsed_sec", 0.0)))
        except (ValueError, TypeError):
            pass
    swap_dist = Counter(swaps)

    print("=" * 75)
    print(f"  {title}")
    print("=" * 75)
    print(f"  Total Samples                : {total}")
    print(f"  Localized (any strategy)     : {len(matched)}/{total} ({pct(len(matched), total)})")
    print(f"  -> BLIND-legit (no GT block) : {len(blind_ok)}/{total} ({pct(len(blind_ok), total)})   <-- honest attacker rate")
    print(f"  -> GT-assisted (bootstrap)   : {len(gt_assisted)}/{total} ({pct(len(gt_assisted), total)})   <-- leakage, exclude from claims")
    if swaps:
        print(f"  1-Swap Perfect Hits          : {swap_dist.get(1, 0)}/{total} ({pct(swap_dist.get(1, 0), total)})")
        print(f"  Avg Swaps / Sample           : {sum(swaps) / len(swaps):.2f}")
    if times and any(times):
        print(f"  Avg Runtime / Sample         : {sum(times) / len(times):.1f} sec")

    # Winning-strategy breakdown among matches
    win = Counter(strategy_family(r.get("loc_strategy")) for r in matched)
    print("-" * 75)
    print("  Winning strategy (successful localizations only):")
    if win:
        for strat, cnt in win.most_common():
            print(f"    - {strat:14s}: {cnt:5d} ({pct(cnt, len(matched))} of hits)")
    else:
        print("    (none)")

    if swaps:
        print("-" * 75)
        print("  Swap distribution:")
        for sw in sorted(swap_dist.keys()):
            print(f"    - {sw:3d} swap(s): {swap_dist[sw]:5d} ({pct(swap_dist[sw], total)})")
    print("=" * 75)


def main():
    args = parse_args()

    if args.from_json:
        rows = load_rows_from_json(args.output_dir)
        src = f"{args.output_dir}/stage3_located_*.json"
    else:
        if not args.csv.exists():
            print(f"[!] Error: CSV file not found: {args.csv}", file=sys.stderr)
            sys.exit(1)
        rows = load_rows_from_csv(args.csv)
        src = str(args.csv)

    if not rows:
        print(f"[!] Warning: no sample rows found in {src}")
        return

    print(f"\n[source] {src}  ({len(rows)} rows)\n")

    blind_rows = [r for r in rows if is_blind_run(r)]
    assisted_rows = [r for r in rows if not is_blind_run(r)]

    # Always show the combined picture.
    report_block("BASE GPA LOCALIZATION — ALL SAMPLES", rows)

    # If the run(s) are tagged, split blind-mode vs GT-assisted-mode runs too.
    if blind_rows and assisted_rows:
        print()
        report_block("SUBSET: runs launched with --blind", blind_rows)
        print()
        report_block("SUBSET: runs launched WITHOUT --blind", assisted_rows)


if __name__ == "__main__":
    main()
