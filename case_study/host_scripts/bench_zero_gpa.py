#!/usr/bin/env python3
"""
bench_zero_gpa.py — Benchmark orchestrate.py's "acquire zero_gpa + dump to
z.out" setup step in isolation, repeated over N runs.

This is exactly the piece orchestrate.py's main() runs once at startup:
  1. acquire_zero_gpa()   — send zero ICMP(s), verify a fully-covered page
  2. read_gpa.py z <gpa>  — dump that page's ciphertext to z.out

Each run's timings (and outcome) are appended to bench_zero_gpa_results.csv
immediately (not just at the end), so an interrupted run still leaves
usable data.

Usage:
    sudo python3 bench_zero_gpa.py [--runs 100]
"""

import argparse
import csv
import datetime
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).parent
sys.path.insert(0, str(HERE))
import orchestrate

CSV_PATH = HERE / "bench_zero_gpa_results.csv"
CSV_FIELDS = ["run", "timestamp", "status", "zero_gpa",
              "acquire_time_sec", "read_gpa_time_sec", "total_time_sec"]


def _write_row(row: dict) -> None:
    write_header = not CSV_PATH.exists()
    with open(CSV_PATH, "a", newline="") as f:
        w = csv.DictWriter(f, fieldnames=CSV_FIELDS)
        if write_header:
            w.writeheader()
        w.writerow(row)


def _last_run_idx() -> int:
    """Return the highest `run` value already recorded in the CSV, or 0."""
    if not CSV_PATH.exists():
        return 0
    last = 0
    with open(CSV_PATH, newline="") as f:
        for row in csv.DictReader(f):
            try:
                last = max(last, int(row["run"]))
            except (KeyError, ValueError):
                continue
    return last


def run_once(run_idx: int) -> dict:
    ts = datetime.datetime.now().strftime("%Y-%m-%dT%H:%M:%S")
    total_t0 = time.time()

    t0 = time.time()
    try:
        zero_gpa = orchestrate.acquire_zero_gpa()
    except SystemExit:
        acquire_time = time.time() - t0
        return {
            "run":               run_idx,
            "timestamp":         ts,
            "status":            "ACQUIRE_FAILED",
            "zero_gpa":          "",
            "acquire_time_sec":  f"{acquire_time:.4f}",
            "read_gpa_time_sec": "",
            "total_time_sec":    f"{time.time() - total_t0:.4f}",
        }
    acquire_time = time.time() - t0

    t0 = time.time()
    try:
        subprocess.run(
            [sys.executable, str(HERE / "read_gpa.py"), "z", f"0x{zero_gpa:x}"],
            check=True,
        )
        read_gpa_time = time.time() - t0
        status = "OK"
    except subprocess.CalledProcessError:
        read_gpa_time = time.time() - t0
        status = "READ_GPA_FAILED"

    total_time = time.time() - total_t0

    return {
        "run":               run_idx,
        "timestamp":         ts,
        "status":            status,
        "zero_gpa":          f"0x{zero_gpa:x}",
        "acquire_time_sec":  f"{acquire_time:.4f}",
        "read_gpa_time_sec": f"{read_gpa_time:.4f}",
        "total_time_sec":    f"{total_time:.4f}",
    }


def main() -> None:
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--runs", type=int, default=100,
                   help="Number of repetitions (default: 100)")
    args = p.parse_args()

    print("[bench] Ensuring MTU 9000 (one-time setup, not counted in timings)...")
    orchestrate.ensure_mtu_9000()

    start_idx = _last_run_idx()
    if start_idx:
        print(f"[bench] Resuming: {start_idx} run(s) already in "
              f"{CSV_PATH.name}; continuing from run {start_idx + 1}.")

    print(f"[bench] Running {args.runs} iterations of "
          f"acquire_zero_gpa() + read_gpa.py z ...")
    print(f"[bench] Results -> {CSV_PATH.name}")

    n_ok = 0
    for i in range(start_idx + 1, start_idx + args.runs + 1):
        print(f"\n{'='*60}")
        print(f"[bench] run {i} ({i - start_idx}/{args.runs})")
        row = run_once(i)
        _write_row(row)
        if row["status"] == "OK":
            n_ok += 1
        print(f"[bench] run {i}: status={row['status']}  "
              f"acquire={row['acquire_time_sec']}s  "
              f"read_gpa={row['read_gpa_time_sec']}s  "
              f"total={row['total_time_sec']}s")

    print(f"\n[bench] Done. {n_ok}/{args.runs} OK. Results -> {CSV_PATH}")


if __name__ == "__main__":
    main()
