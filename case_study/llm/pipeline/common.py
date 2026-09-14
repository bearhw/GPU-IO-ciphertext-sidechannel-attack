#!/usr/bin/env python3
"""
case_study/llm/pipeline/common.py — Shared constants, utilities, safety pacing,
and evaluation metrics for the LLM End-to-End Side-Channel Attack Pipeline.
"""

import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Set, Tuple

import numpy as np

# ---------------------------------------------------------------------------
# Paths and Core Constants
# ---------------------------------------------------------------------------
PIPELINE_DIR = Path(__file__).resolve().parent
LLM_DIR = PIPELINE_DIR.parent
CASE_STUDY_DIR = LLM_DIR.parent

# Search paths for dictionary and mura modules
MURA_DICT_DIR = CASE_STUDY_DIR / "mura" / "dict"
LLM_DICT_DIR = LLM_DIR / "dict"
HOST_SCRIPTS_DIR = CASE_STUDY_DIR / "host_scripts"

for p in [str(MURA_DICT_DIR), str(LLM_DICT_DIR), str(HOST_SCRIPTS_DIR), str(LLM_DIR), str(PIPELINE_DIR)]:
    if p in sys.path:
        sys.path.remove(p)
    sys.path.insert(0, p)

SWAP_TOOL = str(LLM_DIR / "swap_pages_tool")
TRACKER_BIN = "/home/eun/open-science/sev-step-module/write_pattern_tracker"
NET_PREFLIGHT = Path("/home/eun/proof_code/llm/net_preflight.sh")

DICT_CACHE = LLM_DIR / "dict_cache_v4.json"
DICT_DIR = LLM_DIR / "dict_pages_v4"
SCAN_TMP = LLM_DIR / "scan_tmp_llm"

PAGE_SIZE = 4096            # 4 KB
BLOCK_SIZE = 0x200000       # 2 MB
PAGES_PER_BLOCK = BLOCK_SIZE // PAGE_SIZE  # 512
CHUNK_SIZE = 16
CHUNKS_PAGE = PAGE_SIZE // CHUNK_SIZE     # 256

IMAGE_PAD_TOKEN_ID = 151655 # Qwen2-VL <|image_pad|>
IMAGE_PAD_MATCH_MIN = 40

# Tracker GPA Window (4GB - 256GB guest memory range)
TRACK_START = 0x100000000
TRACK_SIZE = 0x3f00000000
TRACKER_SETTLE_S = 3

# Safety Ceilings & Pacing Defaults (Calibrated to prevent PSP resets & host reboots)
# 1 round-trip swap (--swap-back) = 6 snp_guest_page_move = ~12 low-level PSP commands.
# PSP platform-resets if sustained > ~60 commands/sec. 0.25s pace -> max ~48 cmds/s.
SWAP_PACE_SEC = 0.25
SWAP_BURST_COOLDOWN = 10
SWAP_BURST_SLEEP = 2.0
MEGA_COOLDOWN_EVERY = 50
MEGA_COOLDOWN_SLEEP = 12.0
INTER_TRY_SETTLE_SEC = 2.0

CONTINUE_TRY_BUDGET = 150
FULL_BLOCK_TRY_BUDGET = 200
MAX_LOC_SWAPS_SAMPLE = 1000     # strict safety ceiling to prevent runaway swap loops
MAX_TOTAL_SWAPS_RUN = 50000
N_TRACKER_CANDIDATES = 5

# Guest SSH Configuration
_sudo_user = os.environ.get("SUDO_USER")
_user_home = Path(f"/home/{_sudo_user}") if _sudo_user else Path.home()
KEY = str(_user_home / ".ssh/id_ed25519") if (_user_home / ".ssh/id_ed25519").exists() else str(Path("/home/eun/.ssh/id_ed25519"))
GUEST = "ubuntu@localhost"
GPORT = "7777"
GUEST_PY = "/home/ubuntu/miniconda3/envs/vlm/bin/python3"
GUEST_CWD = "~/medical_ml/med_vlm/scripts"
GSCRIPT = "single_inference_indication_gpa.py"
SSH_CMD = [
    "ssh", "-p", GPORT, "-i", KEY,
    "-o", "BatchMode=yes",
    "-o", "StrictHostKeyChecking=no",
    "-o", "ConnectTimeout=8",
    GUEST,
]


# ---------------------------------------------------------------------------
# Exceptions & Safety Control (Pacer)
# ---------------------------------------------------------------------------
class RunAborted(Exception):
    """Raised when swap safety limit or critical error is encountered."""
    pass


class Pacer:
    """Controls rate of PSP page swaps to avoid overwhelming QEMU / PSP firmware."""

    def __init__(self, max_total_swaps: int = MAX_TOTAL_SWAPS_RUN):
        self.n = 0
        self.max_total_swaps = max_total_swaps

    def tick(self) -> None:
        if self.n >= self.max_total_swaps:
            raise RunAborted(f"MAX_TOTAL_SWAPS_RUN={self.max_total_swaps} reached")
        if MEGA_COOLDOWN_EVERY and self.n and self.n % MEGA_COOLDOWN_EVERY == 0:
            print(f"  [pace] MEGA cooldown after {self.n} swaps ({MEGA_COOLDOWN_SLEEP:.0f}s)")
            time.sleep(MEGA_COOLDOWN_SLEEP)
        elif SWAP_BURST_COOLDOWN and self.n and self.n % SWAP_BURST_COOLDOWN == 0:
            time.sleep(SWAP_BURST_SLEEP)
        else:
            time.sleep(SWAP_PACE_SEC)
        self.n += 1


# ---------------------------------------------------------------------------
# Network Preflight & MTU Configuration
# ---------------------------------------------------------------------------
def run_net_preflight() -> bool:
    """Run net_preflight.sh if available to verify network configuration."""
    if NET_PREFLIGHT.exists() and os.access(str(NET_PREFLIGHT), os.X_OK):
        print(f"[net] Running {NET_PREFLIGHT}...")
        try:
            env = os.environ.copy()
            if "SUDO_USER" not in env or env["SUDO_USER"] == "root":
                env["SUDO_USER"] = "eun"
            cmd = [str(NET_PREFLIGHT)] if os.geteuid() == 0 else ["sudo", "-E", str(NET_PREFLIGHT)]
            r = subprocess.run(cmd, env=env, check=True)
            return r.returncode == 0
        except Exception as e:
            print(f"[net] WARNING: net_preflight.sh failed or skipped: {e}", file=sys.stderr)
            return False
    return True


def ensure_mtu_9000() -> None:
    """Ensure MTU 9000 on host TAP and guest network interface for large ICMP."""
    try:
        r = subprocess.run(["ip", "route", "get", "192.168.100.2"], capture_output=True, text=True)
        m = re.search(r'\bdev\s+(\S+)', r.stdout)
        if m:
            host_iface = m.group(1)
            cur = subprocess.run(["ip", "link", "show", host_iface], capture_output=True, text=True).stdout
            if "mtu 9000" not in cur:
                subprocess.run(["ip", "link", "set", host_iface, "mtu", "9000"], check=False)
                print(f"[mtu] Host {host_iface} MTU set to 9000")
    except Exception as e:
        print(f"[mtu] Note: host MTU configuration: {e}", file=sys.stderr)


# ---------------------------------------------------------------------------
# Byte & Fingerprint Helpers
# ---------------------------------------------------------------------------
def get_chunk(b: bytes, j: int) -> bytes:
    """Extract 16-byte chunk j from 4096-byte buffer."""
    return b[j * CHUNK_SIZE:(j + 1) * CHUNK_SIZE]


def imagepad_chunk() -> bytes:
    """Return 16-byte chunk consisting of two <|image_pad|> int64 tokens."""
    return np.array([IMAGE_PAD_TOKEN_ID, IMAGE_PAD_TOKEN_ID], dtype="<i8").tobytes()


# ---------------------------------------------------------------------------
# JSON I/O Helpers
# ---------------------------------------------------------------------------
def load_json(path: Path) -> Dict[str, Any]:
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)


def save_json(path: Path, data: Dict[str, Any]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", encoding="utf-8") as f:
        json.dump(data, f, indent=2)


# ---------------------------------------------------------------------------
# CSV & Metrics I/O Helpers
# ---------------------------------------------------------------------------
SUMMARY_FIELDNAMES = [
    "index", "indication", "gt_base", "host_base", "loc_strategy",
    "loc_swaps", "loc_match", "N_pad_est", "verdict", "recovered_labels",
    "top1_match", "any_match", "multi_match_count", "false_positive_count",
    "false_positive_labels", "elapsed_sec"
]


def load_summary_csv(csv_path: Path) -> Dict[int, Dict[str, Any]]:
    """Load existing summary CSV into a dictionary keyed by int(index)."""
    rows: Dict[int, Dict[str, Any]] = {}
    if not csv_path.exists():
        return rows
    try:
        import csv
        with open(csv_path, "r", encoding="utf-8") as f:
            reader = csv.DictReader(f)
            for r in reader:
                try:
                    idx = int(r["index"])
                    rows[idx] = r
                except (ValueError, KeyError):
                    continue
    except Exception as e:
        print(f"[summary] Note reading {csv_path}: {e}", file=sys.stderr)
    return rows


def update_summary_csv(csv_path: Path, new_row: Dict[str, Any]) -> None:
    """Update or append a single sample's summary row in the CSV incrementally."""
    rows = load_summary_csv(csv_path)
    idx = int(new_row["index"])
    str_row = {}
    for k in SUMMARY_FIELDNAMES:
        val = new_row.get(k, "")
        if isinstance(val, list):
            str_row[k] = " / ".join(str(x) for x in val)
        else:
            str_row[k] = str(val) if val is not None else ""
    rows[idx] = str_row

    csv_path.parent.mkdir(parents=True, exist_ok=True)
    import csv
    with open(csv_path, "w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=SUMMARY_FIELDNAMES)
        writer.writeheader()
        for i in sorted(rows.keys()):
            writer.writerow({k: rows[i].get(k, "") for k in SUMMARY_FIELDNAMES})


# ---------------------------------------------------------------------------
# Evaluation & Metrics Calculator
# ---------------------------------------------------------------------------
def _norm(s: str) -> str:
    return re.sub(r'[^\w\s]', '', s).strip().lower()


def evaluate_recovery(recovered_labels: List[str], ground_truth_indication: Optional[str]) -> Dict[str, Any]:
    """
    Perform rigorous evaluation of recovered clinical labels against Ground Truth.
    Calculates:
      - top1_exact_match: bool
      - any_label_match: bool
      - multi_match_count: int
      - false_positive_labels: list[str]
      - false_positive_count: int
      - verdict: str ("MATCH", "MULTI_MATCH", "NO_MATCH")
    """
    gt = (ground_truth_indication or "").strip()
    gt_norm = _norm(gt)
    cleaned_recovered = [lbl.strip() for lbl in recovered_labels if lbl.strip()]

    if not cleaned_recovered:
        return {
            "verdict": "NO_MATCH",
            "top1_exact_match": False,
            "any_label_match": False,
            "multi_match_count": 0,
            "false_positive_labels": [],
            "false_positive_count": 0,
            "recovered_labels": [],
        }

    def _is_match(lbl: str) -> bool:
        if not gt_norm:
            return False
        l_norm = _norm(lbl)
        return bool(l_norm and (l_norm in gt_norm or lbl.strip().lower() in gt.lower()))

    top1 = cleaned_recovered[0]
    top1_match = _is_match(top1)
    any_match = any(_is_match(lbl) for lbl in cleaned_recovered)

    # False positives are labels matched by ciphertext verification that do NOT appear in GT
    false_positives = [lbl for lbl in cleaned_recovered if not _is_match(lbl)]

    verdict = "MATCH" if len(cleaned_recovered) == 1 else "MULTI_MATCH"

    return {
        "verdict": verdict,
        "top1_exact_match": top1_match,
        "any_label_match": any_match,
        "multi_match_count": len(cleaned_recovered),
        "false_positive_labels": false_positives,
        "false_positive_count": len(false_positives),
        "recovered_labels": cleaned_recovered,
    }
