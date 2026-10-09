#!/usr/bin/env python3
"""
case_study/llm/pipeline/common.py — Shared constants, utilities, safety pacing,
and evaluation metrics for the LLM End-to-End Side-Channel Attack Pipeline.
"""

import json
import os
import re
import struct
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
IMAGE_PAD_MATCH_MIN = 80    # require at least 80/256 chunk matches (~31% coverage; true pages have 140-240 chunks, noise <=40)

# Tracker GPA Window (4GB - 256GB guest memory range)
TRACK_START = 0x100000000
TRACK_SIZE = 0x800000000     # 32GB tracking range (4GB - 36GB) covers all user tensor GPAs
TRACKER_SETTLE_S = 3
TRACKER_REARM_MS = 20  # 20ms interval for trigger-based tracking during inference window

# Safety Ceilings & Pacing Defaults (Calibrated to prevent PSP resets & host reboots)
# 1 round-trip swap (--swap-back) = 6 snp_guest_page_move = ~12 low-level PSP commands.
# PSP platform-resets if sustained > ~60 commands/sec. 0.25s pace -> max ~48 cmds/s.
#
# Every knob below is overridable via env (SC_* prefix) so a run can be sped up without
# editing code. Lowering SWAP_PACE_SEC / raising the cooldown cadence pushes the PSP
# command rate up toward the ~60/s reset threshold — do it knowingly.
def _envf(name: str, default: float) -> float:
    try:
        return float(os.environ[name])
    except (KeyError, ValueError):
        return default


def _envi(name: str, default: int) -> int:
    try:
        return int(os.environ[name])
    except (KeyError, ValueError):
        return default


SWAP_PACE_SEC = _envf("SC_SWAP_PACE_SEC", 0.25)
SWAP_BURST_COOLDOWN = _envi("SC_SWAP_BURST_COOLDOWN", 10)
SWAP_BURST_SLEEP = _envf("SC_SWAP_BURST_SLEEP", 2.0)
MEGA_COOLDOWN_EVERY = _envi("SC_MEGA_COOLDOWN_EVERY", 25)
MEGA_COOLDOWN_SLEEP = _envf("SC_MEGA_COOLDOWN_SLEEP", 12.0)
INTER_TRY_SETTLE_SEC = _envf("SC_INTER_TRY_SETTLE_SEC", 2.0)

CONTINUE_TRY_BUDGET = _envi("SC_CONTINUE_TRY_BUDGET", 20)
FULL_BLOCK_TRY_BUDGET = _envi("SC_FULL_BLOCK_TRY_BUDGET", 20)

# Filtered 2MB Brute-force localization parameters (Safe bounded swap budget)
PER_BLOCK_LOC_BUDGET = _envi("SC_PER_BLOCK_LOC_BUDGET", 8)   # 8 swaps max per candidate block
RUN_START_PROBE_WINDOW = _envi("SC_RUN_START_PROBE_WINDOW", 6) # probe 0..5 pages from run start
PIXEL_VALUES_SKIP_THRESHOLD = _envi("SC_PIXEL_VALUES_SKIP_THRESHOLD", 40) # skip dense float pixel spans

# Run-aware localization: the image_pad landmark usually sits a few pages OFF the
# tracker's captured run_start (the run often starts in the prefix/indication
# text, not the image_pad region). Scan the run span plus this many pages BEFORE
# the earliest run start to catch image_pad that precedes the captured writes.
RUN_BACK_PAGES = _envi("SC_RUN_BACK_PAGES", 64)
RUN_WINDOW_BUDGET = _envi("SC_RUN_WINDOW_BUDGET", 8)   # small safe burst to prevent QEMU SNP page-move segfaults
# Cap exact run_start probes per candidate block (Phase 1) so the cheap 1-swap
# probes spread across many blocks and leave budget for the run-window scan,
# instead of one block's many run bases eating the whole per-sample ceiling.
RUN_BASE_PER_BLOCK = _envi("SC_RUN_BASE_PER_BLOCK", 6)
MAX_LOC_SWAPS_SAMPLE = _envi("SC_MAX_LOC_SWAPS", 40)  # safe per-sample swap ceiling (prevents QEMU segfaults)
MAX_TOTAL_SWAPS_RUN = _envi("SC_MAX_TOTAL_SWAPS", 50000)
N_TRACKER_CANDIDATES = _envi("SC_N_TRACKER_CANDIDATES", 40)  # safe top 40 candidate blocks

# Contiguous write run bounds
LOC_RUN_LEN_MIN = _envi("SC_LOC_RUN_LEN_MIN", 1)
LOC_RUN_LEN_MAX = _envi("SC_LOC_RUN_LEN_MAX", 512)

# Qwen vocab bound for the "indication text follows image_pad" confirmation: real
# input_ids has plausible text token IDs (0 < id < vocab, not the image_pad id)
# after the image_pad run; an image-only buffer does not.
QWEN_VOCAB_SIZE = _envi("SC_QWEN_VOCAB_SIZE", 152064)
# Min text-token chunks on a run page for the "indication follows image_pad"
# confirmation (a genuine input_ids run holds image_pad AND text tokens; an
# image-only buffer holds neither text nor a text tail).
IND_TEXT_MIN_CHUNKS = _envi("SC_IND_TEXT_MIN_CHUNKS", 4)

# Localization success criterion. loc_match counts a hit when the located page is
# in the SAME 2MB block as the ground-truth input_ids base AND within this many
# pages of it. The image_pad buffer spans many contiguous pages, so the blind
# fingerprint scan / run-base probe commonly lands a page or two off the exact
# base (observed: host = gt+1 with 80-213/256 image_pad chunk matches) — that is
# a real localization of the input buffer (Stage 4 then estimates the bounds),
# not a miss. Byte-exact gt_base was too strict and undercounted success ~2x.
LOC_MATCH_PAGE_WINDOW = _envi("SC_LOC_MATCH_PAGE_WINDOW", 24)

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
            cmd = [str(NET_PREFLIGHT)] if os.geteuid() == 0 else ["sudo", str(NET_PREFLIGHT)]
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


def loc_is_hit(host_base: Optional[int], gt_base: Optional[int]) -> bool:
    """Localization success: located page is in the same 2MB block as the GT
    input_ids base and within LOC_MATCH_PAGE_WINDOW pages of it. See the
    LOC_MATCH_PAGE_WINDOW comment for why this is the right criterion (not
    byte-exact gt_base). Returns False if either address is missing."""
    if not host_base or not gt_base:
        return False
    if (host_base & ~(BLOCK_SIZE - 1)) != (gt_base & ~(BLOCK_SIZE - 1)):
        return False
    dpages = (host_base - gt_base) // PAGE_SIZE
    return -LOC_MATCH_PAGE_WINDOW <= dpages <= LOC_MATCH_PAGE_WINDOW


def text_token_chunks(data: bytes) -> int:
    """Count 16-byte chunks in a 4096-byte page that look like a pair of real
    text token IDs — each int64 in (0, vocab) and not the image_pad id. Used to
    confirm the indication text that follows the image_pad run in a genuine
    input_ids buffer (a distinguishing signal vs image-only buffers)."""
    n = 0
    for j in range(CHUNKS_PAGE):
        a, b = struct.unpack_from("<qq", data, j * CHUNK_SIZE)
        if 0 < a < QWEN_VOCAB_SIZE and a != IMAGE_PAD_TOKEN_ID and \
           0 < b < QWEN_VOCAB_SIZE and b != IMAGE_PAD_TOKEN_ID:
            n += 1
    return n


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
    "loc_swaps", "loc_match", "blind", "N_pad_est", "verdict", "recovered_labels",
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


def init_summary_csv(csv_path: Path) -> None:
    """Ensure summary CSV exists and has headers written."""
    csv_path.parent.mkdir(parents=True, exist_ok=True)
    if not csv_path.exists() or csv_path.stat().st_size == 0:
        import csv
        with open(csv_path, "w", newline="", encoding="utf-8") as f:
            writer = csv.DictWriter(f, fieldnames=SUMMARY_FIELDNAMES)
            writer.writeheader()


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
