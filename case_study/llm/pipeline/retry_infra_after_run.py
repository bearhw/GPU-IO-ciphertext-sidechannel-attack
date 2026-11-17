#!/usr/bin/env python3
"""Wait for the running watchdog to finish, then re-measure the samples that
never got an attack attempt, and relaunch the watchdog on the same output dir.

"No attempt" means the infrastructure failed, not the attack:
  - SAMPLE_ERROR: the guest died mid-sample
  - GEN_FAIL: the guest's inference never returned a buffer
  - localized (SUCCESS) but killed before Stage 5 ran, so no matching attempt
These get exactly one more pass. Samples with a real attack outcome (LOC_FAIL,
MATCH, MULTI_MATCH, NO_MATCH) are never touched, so this is not a best-of-two
re-roll of failures.

Usage (as root, in tmux):
    python3 -u retry_infra_after_run.py --output-dir <run dir>
"""
import argparse
import csv
import subprocess
import sys
import time
from pathlib import Path

PIPELINE_DIR = Path(__file__).resolve().parent
sys.path.insert(0, str(PIPELINE_DIR))


def watchdog_running(out_dir: Path) -> bool:
    r = subprocess.run(["ps", "-eo", "args"], capture_output=True, text=True)
    return any(a.startswith("python3 -u auto_watchdog.py") and str(out_dir) in a
               for a in r.stdout.splitlines())


def infra_indices(out_dir: Path):
    out = []
    for r in csv.DictReader(open(out_dir / "pipeline_summary.csv", encoding="utf-8")):
        v, i = r.get("verdict"), r.get("index")
        if v in ("SAMPLE_ERROR", "GEN_FAIL") or (
                v == "SUCCESS" and not (out_dir / f"stage5_result_{i}.json").exists()):
            out.append(int(i))
    return sorted(out)


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--output-dir", type=Path, required=True)
    args = p.parse_args()
    out_dir = args.output_dir.resolve()

    print(f"[retry-infra] waiting for the watchdog on {out_dir} to exit...", flush=True)
    while watchdog_running(out_dir):
        time.sleep(60)

    import auto_watchdog as w
    w.OUTPUT_DIR = out_dir
    w.SUMMARY_CSV = out_dir / "pipeline_summary.csv"
    w.WATCHDOG_LOG = out_dir / "watchdog.log"

    idx = infra_indices(out_dir)
    print(f"[retry-infra] {len(idx)} sample(s) without an attack attempt: {idx}", flush=True)
    if not idx:
        return
    for i in idx:
        w.clear_sample(i)
    w.log(f"retry-infra: cleared {len(idx)} no-attempt sample(s) for one more pass: {idx}")

    cmd = ["python3", "-u", "auto_watchdog.py", "--blind", "--to-stage", "5",
           "--build-dict", "--output-dir", str(out_dir)]
    print(f"[retry-infra] relaunching: {' '.join(cmd)}", flush=True)
    sys.exit(subprocess.call(cmd, cwd=str(PIPELINE_DIR)))


if __name__ == "__main__":
    main()
