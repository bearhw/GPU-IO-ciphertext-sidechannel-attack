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
import atexit
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

# Last pipeline stage to run. 3 = localization only. 5 = full recovery, which
# also needs BUILD_DICT (see run_pipeline).
TO_STAGE = 3
# Rebuild the ciphertext dictionary in each cycle. Required for TO_STAGE >= 5
# because every cycle relaunches QEMU and the SNP VEK is per-launch.
BUILD_DICT = False
# Re-run samples that failed, after the first pass. Off by default: a best-of-two
# rate is not a single-pass measurement and must not be reported as one.
RETRY_FAILED = False

SUMMARY_FIELDNAMES = [
    "index", "indication", "gt_base", "host_base", "loc_strategy",
    "loc_swaps", "loc_match", "blind", "N_pad_est", "verdict", "recovered_labels",
    "top1_match", "any_match", "multi_match_count", "false_positive_count",
    "false_positive_labels", "elapsed_sec"
]

# The pipeline owns the schema. Keeping a second copy here silently drops any
# column the pipeline adds (per-stage timings, the reason field), so prefer the
# real one and fall back to the list above only if the import fails.
TRACKER_BIN = "/home/eun/open-science/sev-step-module/write_pattern_tracker"
try:
    sys.path.insert(0, str(PIPELINE_DIR))
    from common import SUMMARY_FIELDNAMES as _PIPELINE_FIELDNAMES
    from common import TRACKER_BIN as _PIPELINE_TRACKER_BIN
    SUMMARY_FIELDNAMES = list(_PIPELINE_FIELDNAMES)
    TRACKER_BIN = _PIPELINE_TRACKER_BIN
except Exception as _e:      # pragma: no cover - keep the watchdog runnable
    print(f"[WATCHDOG] note: using built-in CSV schema / tracker path ({_e})",
          file=sys.stderr)


# Live children, so the watchdog can clean up after itself when IT is stopped
# (tmux kill-session, Ctrl-C, SIGTERM). Both are started with setsid, i.e. in
# their own sessions, so without this they survive as orphans: a pipeline that
# keeps swapping guest pages, and a QEMU holding the passthrough GPU.
_PIPELINE_PROC: Optional[subprocess.Popen] = None
_QEMU_PROC: Optional[subprocess.Popen] = None
_QEMU_LOGF: Optional[Any] = None
_SHUTTING_DOWN = False


def _on_exit():
    """Leave nothing running that touches the guest or the kernel."""
    global _SHUTTING_DOWN
    if _SHUTTING_DOWN:
        return
    _SHUTTING_DOWN = True
    if _PIPELINE_PROC is not None and _PIPELINE_PROC.poll() is None:
        log("Watchdog exiting — stopping the pipeline first so the tracker disarms...")
        stop_pipeline(_PIPELINE_PROC)
    # Any tracker not owned by the pipeline (e.g. left by an earlier SIGKILL).
    disarm_stray_trackers()
    if _QEMU_LOGF is not None:
        try:
            _QEMU_LOGF.close()
        except Exception:
            pass
    if _QEMU_PROC is not None and _QEMU_PROC.poll() is None:
        # QEMU is deliberately left running: it is harmless once tracking is
        # disarmed, and SIGKILLing it mid-PSP-command is its own hazard. The
        # next run's teardown_qemu() reclaims it.
        log(f"NOTE: QEMU (pid {_QEMU_PROC.pid}) left running. The next watchdog start "
            f"tears it down, or stop it with: sudo pkill -9 -f qemu-system-x86_64")


def _on_signal(signum, frame):
    log(f"Received signal {signum}; shutting down.")
    raise SystemExit(128 + signum)


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
            if rows.get(idx, {}).get("verdict") == "QUARANTINED":
                # A quarantine row is the final word on that sample; the stub
                # artefact it wrote must not overwrite it with a blank row.
                continue
            # Only fill rows that are MISSING (master was killed before writing
            # one). An existing row with an empty host_base is a real LOC_FAIL
            # written by master; overwriting it with this thin recovered row
            # used to wipe its reason / rank / timing columns.
            if idx not in rows:
                # Recovered from the Stage 3 file only, so the Stage 4/5 columns
                # stay empty -- this path exists to not lose a sample whose CSV
                # row never got written (killed mid-batch), not to score it.
                row = {k: "" for k in SUMMARY_FIELDNAMES}
                row.update({
                    "index": str(idx),
                    "indication": str(d.get("gt_indication", "")),
                    "gt_base": str(d.get("gt_base", "")),
                    "host_base": str(d.get("host_base", "")),
                    "loc_strategy": str(d.get("loc_strategy", "")),
                    "loc_swaps": str(d.get("loc_swaps", 0)),
                    "loc_match": str(d.get("loc_match", "")),
                    "page_delta": str(d.get("page_delta", "")),
                    "blind": str(d.get("blind", True)),
                    "verdict": str(d.get("status", "")),
                    "loc_best_hits": str(d.get("best_hits", "")),
                    "multi_match_count": "0",
                    "false_positive_count": "0",
                    "reason": "recovered from stage3_located JSON; "
                              "stage4/5 columns were never written for this sample",
                })
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


def _done_prefix() -> str:
    """Which artefact marks a sample finished for THIS run's last stage.

    With --to-stage 5 a sample that has a Stage 3 page but no Stage 5 result is
    NOT done; keying completion on stage3_located_* there would make the
    watchdog declare the batch finished while no label was ever recovered.
    """
    return "stage5_result_" if TO_STAGE >= 5 else "stage3_located_"


def target_indices() -> List[int]:
    """The batch's sample indices, derived exactly as master_orchestrate derives
    them from --filtered-only, so both agree on what the batch contains."""
    with open(FILTERED_JSON, "r", encoding="utf-8") as f:
        target_data = json.load(f)
    return [int(s.get("sample_idx", s.get("index", i)))
            for i, s in enumerate(target_data)]


def _csv_rows() -> Dict[int, Dict[str, str]]:
    """The summary CSV keyed by sample index, or {} if it is absent/unreadable."""
    if not SUMMARY_CSV.exists() or SUMMARY_CSV.stat().st_size == 0:
        return {}
    out: Dict[int, Dict[str, str]] = {}
    try:
        with open(SUMMARY_CSV, "r", encoding="utf-8") as f:
            for r in csv.DictReader(f):
                try:
                    out[int(r["index"])] = r
                except (KeyError, TypeError, ValueError):
                    pass
    except Exception as e:
        log(f"Warning reading {SUMMARY_CSV}: {e}")
    return out


def csv_indices() -> Set[int]:
    """Indices that already have a summary CSV row."""
    return set(_csv_rows().keys())


def completed_indices() -> Set[int]:
    """Samples this run is done with.

    Union of two criteria on purpose. master_orchestrate resumes from the
    summary CSV; the watchdog used to resume from the stage artefacts alone.
    Any sample that gets a CSV row but no artefact -- a guest-side generation
    failure writes exactly that -- then looks done to master and pending to the
    watchdog, so master exits with "nothing to do" and the watchdog reboots and
    calls it again, forever. That is the 17 zero-progress iterations at the end
    of the known-block run. Counting a CSV row as done makes the two agree.
    """
    prefix = _done_prefix()
    done: Set[int] = set()
    for sf in glob.glob(str(OUTPUT_DIR / f"{prefix}*.json")):
        try:
            done.add(int(os.path.basename(sf).replace(prefix, "").replace(".json", "")))
        except ValueError:
            pass
    return done | csv_indices()


def get_remaining_count() -> int:
    targets = target_indices()
    done = completed_indices() & set(targets)
    remaining = len(targets) - len(done)
    log(f"Progress Check: {len(done)}/{len(targets)} completed "
        f"({len(done) / max(len(targets), 1) * 100:.1f}%), {remaining} remaining.")
    return remaining


def next_pending_index() -> Optional[int]:
    """The sample master_orchestrate will attempt first -- i.e. the one blocking
    the batch when an iteration makes no progress at all."""
    done = completed_indices()
    for idx in target_indices():
        if idx not in done:
            return idx
    return None


def quarantine_sample(idx: int, reason: str) -> None:
    """Record a sample as attempted-and-failed so the batch can move past it.

    Without this a sample that never completes -- the guest's VLM loop times
    out on it every single time -- stalls the whole batch: the watchdog reboots,
    master starts on the same index, hangs, gets killed, repeat. Writing BOTH a
    CSV row and the stage artefact the watchdog keys on is what makes the skip
    stick on both sides. The row is a real measured outcome (the attack got
    nothing for this sample), not a silent drop, and `reason` says why.
    """
    row = {k: "" for k in SUMMARY_FIELDNAMES}
    row.update({
        "index": str(idx),
        "blind": str(BLIND),
        "verdict": "QUARANTINED",
        "loc_match": "False",
        "top1_match": "False",
        "any_match": "False",
        "multi_match_count": "0",
        "false_positive_count": "0",
        "reason": f"watchdog quarantine: {reason}",
    })
    rows = {}
    if SUMMARY_CSV.exists() and SUMMARY_CSV.stat().st_size > 0:
        try:
            with open(SUMMARY_CSV, "r", encoding="utf-8") as f:
                for r in csv.DictReader(f):
                    try:
                        rows[int(r["index"])] = r
                    except (KeyError, TypeError, ValueError):
                        pass
        except Exception as e:
            log(f"Warning reading {SUMMARY_CSV} while quarantining {idx}: {e}")
    rows[idx] = row
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    with open(SUMMARY_CSV, "w", newline="", encoding="utf-8") as f:
        wr = csv.DictWriter(f, fieldnames=SUMMARY_FIELDNAMES)
        wr.writeheader()
        for i in sorted(rows.keys()):
            wr.writerow({k: rows[i].get(k, "") for k in SUMMARY_FIELDNAMES})

    artefact = OUTPUT_DIR / f"{_done_prefix()}{idx}.json"
    if not artefact.exists():
        artefact.write_text(json.dumps({
            "index": idx,
            "status": "QUARANTINED",
            "host_base": None,
            "loc_match": False,
            "blind": BLIND,
            "reason": reason,
            "timestamp": time.time(),
        }, indent=2), encoding="utf-8")
    log(f"QUARANTINED sample {idx}: {reason}. Batch will continue past it.")


def _tracker_pids() -> List[str]:
    """PIDs of running write_pattern_tracker processes.

    Deliberately NOT `shell=True`: a `sh -c "pgrep -f write_pattern_tracker"`
    wrapper has the pattern in its own command line and matches itself, so every
    call would report a phantom tracker, burn the full SIGTERM wait and bury a
    real orphan under false warnings. With list args pgrep skips itself, and we
    drop our own pid too. Matching is on the full path so an unrelated process
    merely mentioning the name is not hit (the binary's `comm` is truncated to
    15 chars, so `pgrep -x` on the name would never match).
    """
    me = str(os.getpid())
    try:
        r = subprocess.run(["pgrep", "-f", TRACKER_BIN], capture_output=True, text=True)
    except Exception as e:
        log(f"Note probing for stray trackers: {e}")
        return []
    return [p for p in r.stdout.split() if p.strip() and p != me]


def disarm_stray_trackers(wait_s: int = 25) -> None:
    """SIGTERM any write_pattern_tracker still running, and give it time to issue
    KVM_DST_TRACK_DISABLE.

    A tracker killed with SIGKILL never disarms, leaving the guest's whole GPA
    range write-protected; the guest then crawls and the host has faulted from
    that state before. DISABLE is an ioctl on the live VM, so this must happen
    BEFORE QEMU is torn down, never after.
    """
    pids = _tracker_pids()
    if not pids:
        return
    log(f"Found {len(pids)} stray write tracker(s) {pids}; sending SIGTERM so they "
        f"disarm DST_TRACK (waiting up to {wait_s}s)...")
    for pid in pids:
        subprocess.run(["sudo", "kill", "-TERM", pid], capture_output=True)
    for _ in range(wait_s):
        time.sleep(1)
        if not _tracker_pids():
            log("Stray tracker(s) exited cleanly.")
            return
    left = _tracker_pids()
    log(f"WARNING: tracker(s) {left} did not exit on SIGTERM; SIGKILLing. DST_TRACK "
        f"may be left armed — the next arm's startup DISABLE should clear it.")
    for pid in left:
        subprocess.run(["sudo", "kill", "-9", pid], capture_output=True)


def teardown_qemu():
    log("Tearing down any existing QEMU, TAP interface, or sockets...")
    # Order matters: disarm tracking while the VM still exists, then stop any
    # leftover pipeline, and only then kill QEMU.
    disarm_stray_trackers()
    subprocess.run("sudo pkill -TERM -f master_orchestrate.py || true", shell=True)
    time.sleep(3)
    subprocess.run("sudo pkill -9 -f master_orchestrate.py || true", shell=True)
    subprocess.run("sudo pkill -9 -f launch-qemu-noncc.sh || true", shell=True)
    subprocess.run("sudo pkill -9 -f qemu-system-x86_64 || true", shell=True)
    subprocess.run("sudo rm -f /tmp/qemu-monitor.sock /tmp/qmp-sock", shell=True)
    subprocess.run("sudo ip link set tap0 down 2>/dev/null || true", shell=True)
    subprocess.run("sudo ip tuntap del tap0 mode tap 2>/dev/null || true", shell=True)
    subprocess.run("sync", shell=True)
    time.sleep(6)


def launch_qemu() -> subprocess.Popen:
    global _QEMU_PROC, _QEMU_LOGF
    log("Launching QEMU (SEV-SNP Confidential Computing mode)...")
    qemu_log = OUTPUT_DIR / "qemu_host.log"
    if _QEMU_LOGF is not None:
        try:
            _QEMU_LOGF.close()      # don't leak one fd per cycle
        except Exception:
            pass
    qemu_log_file = open(qemu_log, "a", encoding="utf-8")
    _QEMU_LOGF = qemu_log_file
    proc = subprocess.Popen(
        ["sudo", QEMU_SCRIPT, "-cc"],
        cwd="/home/eun/esp_bak/sev-step",
        stdout=qemu_log_file,
        stderr=subprocess.STDOUT,
        preexec_fn=os.setsid
    )
    _QEMU_PROC = proc
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


def stop_pipeline(proc: Optional[subprocess.Popen], grace_s: int = 45) -> None:
    """Stop the pipeline process group WITHOUT SIGKILLing it first.

    master_orchestrate turns SIGTERM into SystemExit so its atexit hook runs
    _stop_tracker, which SIGTERMs the write tracker and waits for it to issue
    KVM_DST_TRACK_DISABLE (up to 20s). SIGKILLing the group instead -- which is
    what this used to do on a heartbeat timeout -- skips all of that and leaves
    the guest's whole range write-protected, the exact state the tracker code
    warns about. SIGKILL stays only as the last resort after the grace period.
    """
    if proc is None or proc.poll() is not None:
        return
    try:
        pgid = os.getpgid(proc.pid)
    except Exception:
        pgid = None
    try:
        if pgid is not None:
            os.killpg(pgid, signal.SIGTERM)
        else:
            proc.terminate()
    except Exception as e:
        log(f"Note sending SIGTERM to pipeline: {e}")
    try:
        proc.wait(timeout=grace_s)
        log("Pipeline exited cleanly on SIGTERM (tracker disarmed).")
        return
    except Exception:
        pass
    log(f"Pipeline still alive {grace_s}s after SIGTERM; escalating to SIGKILL.")
    try:
        if pgid is not None:
            os.killpg(pgid, signal.SIGKILL)
        else:
            proc.kill()
    except Exception:
        pass
    try:
        proc.wait(timeout=10)
    except Exception:
        pass
    # SIGKILL skipped the tracker's DISABLE, so clean up explicitly.
    disarm_stray_trackers()


def run_pipeline(liveness_timeout_s: int = 600) -> int:
    """Run one pipeline pass.

    liveness_timeout_s is a backstop for a genuinely hung process, not a
    per-sample bound (master has its own 180s guest-inference timeout). It has
    to exceed the longest legitimately quiet stretch -- the ~4 min dictionary
    rebuild under --build-dict -- or the watchdog kills a working run.
    """
    global _PIPELINE_PROC
    log("Starting master_orchestrate.py execution...")
    # Every watchdog cycle tears down and relaunches QEMU, which means a NEW
    # SNP VEK -- so a dictionary built in a previous cycle is dead. Whenever
    # Stage 5 runs we therefore have to rebuild it in the cycle that uses it
    # (~4 min), otherwise Stage 5 matches against foreign ciphertext and
    # reports only false positives without erroring.
    cmd = (
        f"cd {PIPELINE_DIR} && sudo python3 -u master_orchestrate.py "
        f"--filtered-only --from-stage 1 --to-stage {TO_STAGE} "
        f"{'--blind ' if BLIND else ''}"
        f"{'--build-dict ' if BUILD_DICT else ''}--output-dir {OUTPUT_DIR}"
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
        _PIPELINE_PROC = proc
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
                    log(f"WARNING: Pipeline heartbeat timeout ({liveness_timeout_s}s with "
                        f"no log updates). Terminating stuck pipeline...")
                    stop_pipeline(proc)
                    break

        ret = proc.returncode if proc.returncode is not None else 1
        _PIPELINE_PROC = None
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
            if d.get("status") == "QUARANTINED":
                # Quarantine means the sample already consumed STALL_STRIKES
                # whole cycles without ever producing a result. Handing it back
                # to --retry-failed would clear the quarantine and drop the
                # batch straight back into the stall loop it was added to break.
                continue
            if not d.get("loc_match") or d.get("status") != "SUCCESS":
                failed.append(idx)
        except Exception:
            pass
    return sorted(failed)


def clear_sample(idx: int) -> None:
    """Drop every artefact for one sample so it is genuinely re-run.

    Deleting only stage3_located_* is not enough: master_orchestrate resumes
    from the summary CSV, so a sample whose row still exists is skipped no
    matter which JSON files were removed.
    """
    for name in (f"stage2_tracked_{idx}.json", f"stage3_located_{idx}.json",
                 f"stage4_bounds_{idx}.json", f"stage5_result_{idx}.json"):
        (OUTPUT_DIR / name).unlink(missing_ok=True)
    if not SUMMARY_CSV.exists():
        return
    try:
        with open(SUMMARY_CSV, "r", encoding="utf-8") as f:
            rows = [r for r in csv.DictReader(f) if str(r.get("index")) != str(idx)]
        with open(SUMMARY_CSV, "w", newline="", encoding="utf-8") as f:
            wr = csv.DictWriter(f, fieldnames=SUMMARY_FIELDNAMES)
            wr.writeheader()
            for r in rows:
                wr.writerow({k: r.get(k, "") for k in SUMMARY_FIELDNAMES})
    except Exception as e:
        log(f"Warning clearing CSV row for {idx}: {e}")


def main():
    atexit.register(_on_exit)
    signal.signal(signal.SIGTERM, _on_signal)
    signal.signal(signal.SIGINT, _on_signal)

    global OUTPUT_DIR, SUMMARY_CSV, LOG_PATH, WATCHDOG_LOG, BLIND, TO_STAGE, BUILD_DICT, RETRY_FAILED

    p = argparse.ArgumentParser(description="Supervisor for the LLM localization batch")
    p.add_argument("--output-dir", type=Path, default=OUTPUT_DIR,
                   help="Batch output dir. Resume is per-dir (it skips indices that "
                        "already have stage3_located_*.json), so use a FRESH dir when "
                        "switching localization mode.")
    p.add_argument("--blind", action="store_true",
                   help="Withhold the guest-reported block from Stage 3 (search all "
                        "candidate blocks). Default is known-block / Phase K.")
    p.add_argument("--to-stage", type=int, default=TO_STAGE, choices=range(1, 6),
                   help="Last stage to run. 3 = localization only (default). "
                        "5 = full label recovery, which also needs --build-dict.")
    p.add_argument("--build-dict", action="store_true",
                   help="Rebuild the ciphertext dictionary in every cycle (~4 min). "
                        "Required with --to-stage 5: each cycle relaunches QEMU and the "
                        "SNP VEK is per-launch, so a dictionary from a previous cycle "
                        "matches nothing and Stage 5 yields only false positives.")
    p.add_argument("--retry-failed", action="store_true",
                   help="After the first pass, re-run the samples that failed. OFF by "
                        "default: keeping the better of two attempts per sample inflates "
                        "the rate, so a reported measurement should be a single pass.")
    args = p.parse_args()

    OUTPUT_DIR = args.output_dir
    SUMMARY_CSV = OUTPUT_DIR / "pipeline_summary.csv"
    LOG_PATH = OUTPUT_DIR / "pipeline_run.log"
    WATCHDOG_LOG = OUTPUT_DIR / "watchdog.log"
    BLIND = args.blind
    TO_STAGE = args.to_stage
    BUILD_DICT = args.build_dict
    RETRY_FAILED = args.retry_failed
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    log("=" * 75)
    log("  LLM SIDE-CHANNEL PIPELINE WATCHDOG SUPERVISOR STARTED")
    log(f"  mode={'BLIND' if BLIND else 'KNOWN-BLOCK (Phase K)'}  "
        f"to_stage={TO_STAGE}  build_dict={BUILD_DICT}  "
        f"retry_failed={RETRY_FAILED}  out={OUTPUT_DIR}")
    log("=" * 75)
    if TO_STAGE >= 5 and not BUILD_DICT:
        log("FATAL: --to-stage 5 without --build-dict. Each cycle relaunches QEMU, so "
            "the SNP VEK changes and a dictionary from an earlier boot cannot match — "
            "Stage 5 would report only false positives. Re-run with --build-dict.")
        sys.exit(1)

    restart_count = 0
    retry_pass_done = False
    # Stall detection. An iteration that finishes with the batch no further
    # along than it started means the first pending sample cannot be completed
    # -- the guest wedges on it every time, or it fails in a way that leaves no
    # artefact. Retrying it forever is what burned 17 iterations at the end of
    # the known-block run, so after STALL_STRIKES such iterations on the SAME
    # index that sample is quarantined and the batch moves on.
    STALL_STRIKES = 2
    stall_idx: Optional[int] = None
    stall_count = 0
    # A guest that will not boot, init CC mode, or pass preflight is a host-side
    # fault no amount of retrying fixes. Spinning on it silently burns days, so
    # give up loudly instead and leave the results collected so far intact.
    MAX_BOOT_FAILURES = 5
    boot_failures = 0

    while True:
        sync_summary_csv()
        remaining = get_remaining_count()
        if remaining == 0:
            failed = get_failed_indices()
            if not RETRY_FAILED:
                # Default: one attempt per sample. Re-running only the failures
                # and keeping whichever attempt succeeded biases the reported
                # rate upward -- the published number has to come from a single
                # pass over every sample.
                log(f"Batch complete. {len(failed)} sample(s) did not succeed; leaving "
                    f"them as measured (pass --retry-failed to re-run them).")
                break
            if not retry_pass_done and failed:
                log(f"Batch complete. Re-running {len(failed)} failed sample(s) "
                    f"(--retry-failed). NOTE: the resulting rate is a best-of-two "
                    f"figure, not a single-pass measurement.")
                for f_idx in failed:
                    clear_sample(f_idx)
                retry_pass_done = True
                sync_summary_csv()
                remaining = get_remaining_count()
            else:
                log("Retry pass complete. Watchdog finished all runs.")
                break

        restart_count += 1
        blocking_idx = next_pending_index()
        log(f"\n>>> ITERATION #{restart_count} — RESUMING BATCH ({remaining} samples "
            f"remaining, next pending index {blocking_idx}) <<<")

        teardown_qemu()
        qemu_proc = launch_qemu()

        def _infra_failure(what: str) -> bool:
            """Count a host-side cycle failure and say whether to keep going."""
            nonlocal boot_failures
            boot_failures += 1
            log(f"{what} failed ({boot_failures}/{MAX_BOOT_FAILURES}). Retrying cycle...")
            teardown_qemu()
            time.sleep(5)
            return boot_failures < MAX_BOOT_FAILURES

        if not wait_for_guest(qemu_proc):
            if _infra_failure("Guest boot"):
                continue
            break

        if not init_guest_cc():
            if _infra_failure("CC mode init"):
                continue
            break

        time.sleep(2)
        if not run_preflight():
            if _infra_failure("Preflight"):
                continue
            break

        sync_summary_csv()

        # Run pipeline until crash or completion
        boot_failures = 0
        ret = run_pipeline()
        log(f"Pipeline finished cycle with returncode {ret}. Syncing and checking remaining...")

        sync_summary_csv()

        # Did this iteration actually advance the batch?
        after = get_remaining_count()
        if after < remaining:
            stall_idx, stall_count = None, 0
        else:
            if blocking_idx is not None and blocking_idx == stall_idx:
                stall_count += 1
            else:
                stall_idx, stall_count = blocking_idx, 1
            log(f"No progress this iteration (still {after} remaining); "
                f"strike {stall_count}/{STALL_STRIKES} on index {stall_idx}.")
            if stall_idx is not None and stall_count >= STALL_STRIKES:
                quarantine_sample(
                    stall_idx,
                    f"no progress in {stall_count} consecutive iterations "
                    f"(last pipeline rc={ret}); sample never produced a result")
                stall_idx, stall_count = None, 0

        time.sleep(3)

    # ---------------- final report ----------------
    sync_summary_csv()
    done = len(completed_indices() & set(target_indices()))
    total = len(target_indices())
    quarantined = sorted(
        i for i, r in _csv_rows().items() if r.get("verdict") == "QUARANTINED")
    log("=" * 75)
    log(f"  WATCHDOG FINISHED after {restart_count} iteration(s): "
        f"{done}/{total} samples recorded.")
    if quarantined:
        log(f"  {len(quarantined)} quarantined (never completed): {quarantined}")
    log(f"  Results: {SUMMARY_CSV}")
    log("=" * 75)
    if boot_failures >= MAX_BOOT_FAILURES:
        log(f"FATAL: gave up after {boot_failures} consecutive host-side cycle "
            f"failures (guest boot / CC init / preflight). Results collected so "
            f"far are intact in {SUMMARY_CSV}.")
        sys.exit(1)


if __name__ == "__main__":
    main()
