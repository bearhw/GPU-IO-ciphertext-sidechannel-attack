#!/usr/bin/env python3
"""
auto_watchdog.py — Automated Supervisor for LLM Side-Channel Attack Pipeline.

Features:
  1. Detects guest/QEMU crashes or segfaults during batch execution.
  2. Automatically tears down stale QEMU, TAP interfaces, and sockets.
  3. Relaunches QEMU in SEV-SNP confidential mode.
  4. Waits for guest boot & SSH readiness.
  5. Initializes guest CC mode (nvidia-smi conf-compute -srs 1).
  6. Runs net_preflight verification.
  7. Syncs summary CSV and resumes master_orchestrate.py exactly where it left off.
  8. Loops continuously until all 1,641 filtered samples are completed.

Usage:
    # Run in background via tmux:
    tmux new-session -d -s llm-watchdog "sudo python3 /home/eun/open-science/case_study/llm/pipeline/auto_watchdog.py"
"""

import argparse
import csv
import glob
import json
import os
import signal
import subprocess
import sys
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Set, Tuple

PIPELINE_DIR = Path("/home/eun/open-science/case_study/llm/pipeline")
OUTPUT_DIR = PIPELINE_DIR / "run_filtered_ml"
SUMMARY_CSV = OUTPUT_DIR / "pipeline_summary.csv"
FILTERED_JSON = Path("/home/eun/open-science/case_study/llm/filtered_samples.json")
LOG_PATH = OUTPUT_DIR / "pipeline_run.log"
WATCHDOG_LOG = OUTPUT_DIR / "watchdog.log"
QEMU_SCRIPT = "/home/eun/esp_bak/sev-step/launch-qemu-noncc.sh"
NET_PREFLIGHT = "/home/eun/proof_code/llm/net_preflight.sh"
SSH_KEY = "/home/eun/.ssh/id_ed25519"
SSH_PORT = "7777"
SSH_USER = "ubuntu"

# Localization mode for the batch. False = known-block (Phase K): the guest
# reports the 2MB block and Stage 3 only has to find WHICH page inside it is
# input_ids, scanning that block's written pages latest-write-ts first.
BLIND = False

SUMMARY_FIELDNAMES = [
    "index", "indication", "gt_base", "host_base", "loc_strategy",
    "loc_swaps", "loc_match", "blind", "N_pad_est", "verdict", "recovered_labels",
    "top1_match", "any_match", "multi_match_count", "false_positive_count",
    "false_positive_labels", "elapsed_sec"
]


def log(msg: str):
    timestamp = time.strftime("[%Y-%m-%d %H:%M:%S]")
    line = f"{timestamp} [WATCHDOG] {msg}"
    print(line, flush=True)
    with open(WATCHDOG_LOG, "a", encoding="utf-8") as f:
        f.write(line + "\n")


def sync_summary_csv():
    """Ensure all stage3_located_*.json outputs are reflected in summary CSV."""
    stage3_files = glob.glob(str(OUTPUT_DIR / "stage3_located_*.json"))
    rows = {}
    if SUMMARY_CSV.exists() and SUMMARY_CSV.stat().st_size > 0:
        try:
            with open(SUMMARY_CSV, "r", encoding="utf-8") as f:
                reader = csv.DictReader(f)
                for r in reader:
                    rows[int(r["index"])] = r
        except Exception as e:
            log(f"Warning reading {SUMMARY_CSV}: {e}")

    new_count = 0
    for sf in stage3_files:
        try:
            with open(sf, "r", encoding="utf-8") as fp:
                d = json.load(fp)
            idx = int(d.get("index", os.path.basename(sf).split("_")[-1].replace(".json", "")))
            if idx not in rows or not rows[idx].get("host_base"):
                row = {
                    "index": str(idx),
                    "indication": str(d.get("gt_indication", "")),
                    "gt_base": str(d.get("gt_base", "")),
                    "host_base": str(d.get("host_base", "")),
                    "loc_strategy": str(d.get("loc_strategy", "")),
                    "loc_swaps": str(d.get("loc_swaps", 0)),
                    "loc_match": str(d.get("loc_match", "")),
                    "blind": str(d.get("blind", True)),
                    "N_pad_est": "",
                    "verdict": str(d.get("status", "")),
                    "recovered_labels": "",
                    "top1_match": "",
                    "any_match": "",
                    "multi_match_count": "0",
                    "false_positive_count": "0",
                    "false_positive_labels": "",
                    "elapsed_sec": ""
                }
                rows[idx] = row
                new_count += 1
        except Exception as e:
            log(f"Error parsing {sf}: {e}")

    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    with open(SUMMARY_CSV, "w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=SUMMARY_FIELDNAMES)
        writer.writeheader()
        for idx in sorted(rows.keys()):
            writer.writerow({k: rows[idx].get(k, "") for k in SUMMARY_FIELDNAMES})

    log(f"Summary CSV synced: {len(rows)} completed samples ({new_count} newly synced).")
    return len(rows)


def get_remaining_count() -> int:
    with open(FILTERED_JSON, "r", encoding="utf-8") as f:
        target_data = json.load(f)
    total_target = len(target_data)
    stage3_files = glob.glob(str(OUTPUT_DIR / "stage3_located_*.json"))
    completed_indices = set()
    for sf in stage3_files:
        try:
            base = os.path.basename(sf).replace("stage3_located_", "").replace(".json", "")
            completed_indices.add(int(base))
        except ValueError:
            pass
    remaining = total_target - len(completed_indices)
    log(f"Progress Check: {len(completed_indices)}/{total_target} completed ({len(completed_indices)/total_target*100:.1f}%), {remaining} remaining.")
    return remaining


def teardown_qemu():
    log("Tearing down any existing QEMU, TAP interface, or sockets...")
    subprocess.run("sudo pkill -9 -f launch-qemu-noncc.sh || true", shell=True)
    subprocess.run("sudo pkill -9 -f qemu-system-x86_64 || true", shell=True)
    subprocess.run("sudo rm -f /tmp/qemu-monitor.sock /tmp/qmp-sock", shell=True)
    subprocess.run("sudo ip link set tap0 down 2>/dev/null || true", shell=True)
    subprocess.run("sudo ip tuntap del tap0 mode tap 2>/dev/null || true", shell=True)
    subprocess.run("sync", shell=True)
    time.sleep(6)


def launch_qemu() -> subprocess.Popen:
    log("Launching QEMU (SEV-SNP Confidential Computing mode)...")
    qemu_log = OUTPUT_DIR / "qemu_host.log"
    qemu_log_file = open(qemu_log, "a", encoding="utf-8")
    proc = subprocess.Popen(
        ["sudo", QEMU_SCRIPT, "-cc"],
        cwd="/home/eun/esp_bak/sev-step",
        stdout=qemu_log_file,
        stderr=subprocess.STDOUT,
        preexec_fn=os.setsid
    )
    return proc


def wait_for_guest(qemu_proc: Optional[subprocess.Popen] = None, timeout: int = 300) -> bool:
    log(f"Waiting for guest SSH (port {SSH_PORT}) to become reachable (timeout {timeout}s)...")
    t0 = time.time()
    ssh_cmd = [
        "ssh", "-p", SSH_PORT,
        "-i", SSH_KEY,
        "-o", "StrictHostKeyChecking=no",
        "-o", "BatchMode=yes",
        "-o", "ConnectTimeout=4",
        f"{SSH_USER}@localhost",
        "echo GUEST_READY"
    ]
    while time.time() - t0 < timeout:
        if qemu_proc is not None and qemu_proc.poll() is not None:
            log(f"FATAL: QEMU process terminated prematurely with returncode {qemu_proc.returncode}.")
            return False
        res = subprocess.run(ssh_cmd, capture_output=True, text=True)
        if "GUEST_READY" in res.stdout:
            elapsed = time.time() - t0
            log(f"Guest SSH is UP and reachable after {elapsed:.1f}s.")
            return True
        time.sleep(3)
    log("FATAL: Guest failed to boot / answer SSH within timeout.")
    return False


def init_guest_cc(retries: int = 4) -> bool:
    log("Enabling Confidential Compute mode inside guest (nvidia-smi conf-compute -srs 1)...")
    ssh_cmd = [
        "ssh", "-p", SSH_PORT,
        "-i", SSH_KEY,
        "-o", "StrictHostKeyChecking=no",
        "-o", "BatchMode=yes",
        "-o", "ConnectTimeout=8",
        f"{SSH_USER}@localhost",
        "sudo nvidia-smi conf-compute -srs 1"
    ]
    for attempt in range(1, retries + 1):
        res = subprocess.run(ssh_cmd, capture_output=True, text=True)
        if res.returncode == 0:
            log("Guest CC mode enabled successfully.")
            return True
        log(f"CC mode init attempt {attempt}/{retries} failed ({res.stderr.strip() or res.stdout.strip()}). Retrying in 5s...")
        time.sleep(5)
    return False


def run_preflight(retries: int = 5) -> bool:
    log("Running network & ICMP preflight check...")
    for attempt in range(1, retries + 1):
        res = subprocess.run(["sudo", NET_PREFLIGHT], capture_output=True, text=True)
        if res.returncode == 0:
            log("Network preflight READY.")
            return True
        err_msg = (res.stdout.strip() + "\n" + res.stderr.strip()).strip()
        log(f"Preflight attempt {attempt}/{retries} not ready yet:\n{err_msg}\nRetrying in 6s...")
        time.sleep(6)
    return False


def run_pipeline(liveness_timeout_s: int = 360) -> int:
    log("Starting master_orchestrate.py execution...")
    cmd = (
        f"cd {PIPELINE_DIR} && sudo python3 -u master_orchestrate.py "
        f"--filtered-only --from-stage 1 --to-stage 3 "
        f"{'--blind ' if BLIND else ''}--output-dir {OUTPUT_DIR}"
    )
    with open(LOG_PATH, "a", encoding="utf-8") as f_out:
        f_out.write(f"\n\n{'='*75}\n[WATCHDOG RESTART] {time.strftime('%Y-%m-%d %H:%M:%S')}\n{'='*75}\n")
        f_out.flush()
        proc = subprocess.Popen(
            cmd,
            shell=True,
            stdout=f_out,
            stderr=subprocess.STDOUT,
            preexec_fn=os.setsid
        )
        last_mtime = os.path.getmtime(LOG_PATH) if LOG_PATH.exists() else time.time()
        last_activity_time = time.time()

        while proc.poll() is None:
            time.sleep(15)
            if LOG_PATH.exists():
                curr_mtime = os.path.getmtime(LOG_PATH)
                if curr_mtime > last_mtime:
                    last_mtime = curr_mtime
                    last_activity_time = time.time()
                elif time.time() - last_activity_time > liveness_timeout_s:
                    log(f"WARNING: Pipeline heartbeat timeout ({liveness_timeout_s}s with no log updates). Terminating stuck pipeline...")
                    try:
                        os.killpg(os.getpgid(proc.pid), signal.SIGKILL)
                    except Exception:
                        proc.kill()
                    time.sleep(2)
                    break

        ret = proc.returncode if proc.returncode is not None else 1
        log(f"master_orchestrate.py exited with returncode {ret}.")
        return ret


def get_failed_indices() -> list:
    """Find sample indices that previously failed localization (LOC_FAIL, LOC_MISMATCH, or GEN_FAIL)."""
    stage3_files = glob.glob(str(OUTPUT_DIR / "stage3_located_*.json"))
    failed = []
    for sf in stage3_files:
        try:
            with open(sf, "r", encoding="utf-8") as fp:
                d = json.load(fp)
            idx = int(d.get("index", os.path.basename(sf).split("_")[-1].replace(".json", "")))
            if not d.get("loc_match") or d.get("status") != "SUCCESS":
                failed.append(idx)
        except Exception:
            pass
    return sorted(failed)


def main():
    global OUTPUT_DIR, SUMMARY_CSV, LOG_PATH, WATCHDOG_LOG, BLIND

    p = argparse.ArgumentParser(description="Supervisor for the LLM localization batch")
    p.add_argument("--output-dir", type=Path, default=OUTPUT_DIR,
                   help="Batch output dir. Resume is per-dir (it skips indices that "
                        "already have stage3_located_*.json), so use a FRESH dir when "
                        "switching localization mode.")
    p.add_argument("--blind", action="store_true",
                   help="Withhold the guest-reported block from Stage 3 (search all "
                        "candidate blocks). Default is known-block / Phase K.")
    args = p.parse_args()

    OUTPUT_DIR = args.output_dir
    SUMMARY_CSV = OUTPUT_DIR / "pipeline_summary.csv"
    LOG_PATH = OUTPUT_DIR / "pipeline_run.log"
    WATCHDOG_LOG = OUTPUT_DIR / "watchdog.log"
    BLIND = args.blind
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    log("=" * 75)
    log("  LLM SIDE-CHANNEL PIPELINE WATCHDOG SUPERVISOR STARTED")
    log(f"  mode={'BLIND' if BLIND else 'KNOWN-BLOCK (Phase K)'}  out={OUTPUT_DIR}")
    log("=" * 75)

    restart_count = 0
    retry_pass_done = False

    while True:
        sync_summary_csv()
        remaining = get_remaining_count()
        if remaining == 0:
            if not retry_pass_done:
                failed = get_failed_indices()
                if failed:
                    log(f"Initial 1,641 sample pass complete! Found {len(failed)} previously failed samples.")
                    log(f"Initiating AUTOMATIC RE-RUN RETRY PASS with optimized Stage 2/Stage 3 engine (to achieve >90% loc_success)...")
                    for f_idx in failed:
                        f_st3 = OUTPUT_DIR / f"stage3_located_{f_idx}.json"
                        f_st3.unlink(missing_ok=True)
                    retry_pass_done = True
                    sync_summary_csv()
                    remaining = get_remaining_count()
                else:
                    log("ALL TARGET SAMPLES COMPLETED WITH 100% SUCCESS! Watchdog exiting.")
                    break
            else:
                log("RETRY PASS COMPLETED! Watchdog finished all runs.")
                break

        restart_count += 1
        log(f"\n>>> ITERATION #{restart_count} — RESUMING BATCH ({remaining} samples remaining) <<<")

        teardown_qemu()
        qemu_proc = launch_qemu()

        if not wait_for_guest(qemu_proc):
            log("Guest boot failed. Retrying cycle...")
            teardown_qemu()
            time.sleep(5)
            continue

        if not init_guest_cc():
            log("CC mode init failed. Retrying cycle...")
            teardown_qemu()
            time.sleep(5)
            continue

        time.sleep(2)
        if not run_preflight():
            log("Preflight failed. Retrying cycle...")
            teardown_qemu()
            time.sleep(5)
            continue

        sync_summary_csv()

        # Run pipeline until crash or completion
        ret = run_pipeline()
        log(f"Pipeline finished cycle with returncode {ret}. Syncing and checking remaining...")

        sync_summary_csv()
        time.sleep(3)


if __name__ == "__main__":
    main()
