#!/usr/bin/env python3
"""Status of the blind e2e runs: progress, top-10 block coverage, localization,
strict matching, end-to-end.

"No attempt" samples (guest died, guest inference timed out, or localized but
killed before Stage 5) are excluded from the rates; they get re-measured by
retry_infra_after_run.py.

Usage: python3 run_status.py [run_dir ...]   (default: the three v2 chain runs;
       the old-estimator baseline is run_e2e_blind)
"""
import csv
import json
import os
import sys
from pathlib import Path

PIPELINE_DIR = Path(__file__).resolve().parent
DEFAULT_RUNS = ["run_e2e_v2_r1", "run_e2e_v2_r2", "run_e2e_v2_r3"]


def no_attempt(d: Path, row: dict) -> bool:
    v = row.get("verdict")
    return v in ("SAMPLE_ERROR", "GEN_FAIL") or (
        v == "SUCCESS" and not (d / f"stage5_result_{row['index']}.json").exists())


def window_rank(d: Path, idx: str):
    p = d / f"stage2_tracked_{idx}.json"
    if not p.exists():
        return None
    try:
        return json.load(open(p)).get("gt_window_rank")
    except Exception:
        return None


def report(d: Path) -> None:
    csv_path = d / "pipeline_summary.csv"
    if not csv_path.exists():
        print(f"{d.name}: not started")
        return
    rows = list(csv.DictReader(open(csv_path, encoding="utf-8")))
    att = [r for r in rows if not no_attempt(d, r)]
    n = len(att)
    top10 = sum(1 for r in att if (window_rank(d, r["index"]) or 10**9) <= 10)
    loc = [r for r in att if r.get("loc_match") == "True"]
    strict = sum(1 for r in loc if r.get("top1_match") == "True"
                 and int(r.get("false_positive_count") or 0) == 0)
    pct = lambda a, b: f"{a}/{b} ({a / b * 100:.1f}%)" if b else f"{a}/0"
    print(f"{d.name}: rows {len(rows)}/1641, no-attempt {len(rows) - n}, attempted {n}")
    print(f"  true block in top-10 : {pct(top10, n)}")
    print(f"  localization         : {pct(len(loc), n)}")
    print(f"  match | loc (strict) : {pct(strict, len(loc))}")
    print(f"  end-to-end (strict)  : {pct(strict, n)}")


if __name__ == "__main__":
    for name in (sys.argv[1:] or DEFAULT_RUNS):
        p = Path(name)
        report(p if p.is_absolute() else PIPELINE_DIR / p)
