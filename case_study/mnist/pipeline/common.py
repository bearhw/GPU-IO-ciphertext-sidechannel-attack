#!/usr/bin/env python3
"""
common.py — Shared utilities, paths, constants, and evaluation metrics for MNIST pipeline.
"""

import ast
import json
import math
import os
import re
import subprocess
import sys
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

import numpy as np

# ---------------------------------------------------------------------------
# Directories & Canonical Paths
# ---------------------------------------------------------------------------
PIPELINE_DIR = Path(__file__).resolve().parent
MNIST_DIR    = PIPELINE_DIR.parent
CASE_STUDY_DIR = MNIST_DIR.parent

HOST_SCRIPTS_DIR = CASE_STUDY_DIR / "host_scripts"
MODEL_DIR        = MNIST_DIR / "model"
FLOW_DIR         = MNIST_DIR / "flow"
DICT_DIR         = MNIST_DIR / "dict"

DEFAULT_DATA_DIR = MODEL_DIR / "data"
DEFAULT_JSON     = FLOW_DIR / "UNet_training_v5.json"
PAGE2_CACHE_FILE = PIPELINE_DIR / "page2_cache.json"
DEFAULT_OUTPUT_DIR = PIPELINE_DIR / "output"

def get_output_subdirs(base_dir: Path) -> Tuple[Path, Path, Path]:
    """Return (dumps_dir, logs_dir, results_dir) ensuring subdirectories exist."""
    base = Path(base_dir)
    dumps_dir   = base / "dumps"
    logs_dir    = base / "logs"
    results_dir = base / "results"
    for d in (dumps_dir, logs_dir, results_dir):
        d.mkdir(parents=True, exist_ok=True)
    return dumps_dir, logs_dir, results_dir

# Symlink or binary for write_pattern_tracker
TRACKER_PATH = FLOW_DIR / "write_pattern_tracker"
if not TRACKER_PATH.exists():
    fallback_tracker = CASE_STUDY_DIR.parent / "sev-step-module" / "write_pattern_tracker"
    if fallback_tracker.exists():
        TRACKER_PATH = fallback_tracker

# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------
PAGE_SIZE    = 4096
CHUNK_BYTES  = 16
CHUNKS_PER_PAGE = PAGE_SIZE // CHUNK_BYTES  # 256
NUM_CHUNKS   = 196
IMAGE_SIZE   = NUM_CHUNKS * CHUNK_BYTES     # 3136 bytes
IMG_BYTES    = IMAGE_SIZE
PYTORCH_ALIGN = 64
PAGES_PER_512_BATCH = 392                    # (512 * 3136) / 4096 = 392

from datetime import datetime

def make_timestamp_tag(index: int, batch_size: int = 1, start_idx: Optional[int] = None,
                       end_idx: Optional[int] = None, now: Optional[datetime] = None) -> str:
    """Generate standardized filename tag: YYYYMMDD_HHMMSS_bs{BS}_idx{START}-{END}"""
    if now is None:
        now = datetime.now()
    dt_str = now.strftime("%Y%m%d_%H%M%S")
    if batch_size > 1:
        st = start_idx if start_idx is not None else index * batch_size
        en = end_idx if end_idx is not None else (index + 1) * batch_size - 1
        return f"{dt_str}_bs{batch_size}_idx{st}-{en}"
    else:
        idx_val = start_idx if start_idx is not None else index
        return f"{dt_str}_bs1_idx{idx_val}"

# Pacing & Safety Ceilings
SWAP_PACE_SEC        = 0.05
SWAP_BURST_COOLDOWN  = 10
SWAP_BURST_SLEEP     = 2.0
MEGA_COOLDOWN_EVERY  = 50
MEGA_COOLDOWN_SLEEP  = 12.0
MAX_TOTAL_SWAPS_RUN  = 3200


class RunAborted(Exception):
    pass


class Pacer:
    """Controls swap pacing to avoid PSP/kernel lockups during multi-page scans."""
    def __init__(self, max_total: int = MAX_TOTAL_SWAPS_RUN):
        self.n = 0
        self.max_total = max_total

    def tick(self):
        if self.n >= self.max_total:
            raise RunAborted(f"MAX_TOTAL_SWAPS_RUN={self.max_total} reached")
        if MEGA_COOLDOWN_EVERY and self.n and self.n % MEGA_COOLDOWN_EVERY == 0:
            print(f"  [pace] MEGA cooldown after {self.n} swaps ({MEGA_COOLDOWN_SLEEP:.0f}s)...")
            time.sleep(MEGA_COOLDOWN_SLEEP)
        elif SWAP_BURST_COOLDOWN and self.n and self.n % SWAP_BURST_COOLDOWN == 0:
            time.sleep(SWAP_BURST_SLEEP)
        else:
            time.sleep(SWAP_PACE_SEC)
        self.n += 1


# Blind tracking constants
DEFAULT_TRACKER_DURATION = 120                         # Default tracking duration (seconds)
BLIND_B_LO, BLIND_B_HI   = 0x3f80000000, 0x3f90000000   # Region B: AES-GCM staging (precursor)
BLIND_A_LO, BLIND_A_HI   = 0x3f7fc00000, 0x3f7fd00000   # Region A: per-batch clock (excluded)
BLIND_LOOKAHEAD          = 500                          # max WRITE events scanned after a Region-B precursor
BLIND_MIN_RUN            = 2                            # default min contiguous 4K pages
BLIND_GAP_TOL            = 4                            # max skipped pages within a run
BLIND_WINDOW_US          = 2000000                      # max elapsed time (2.0s) from precursor to run start
BLIND_ALIGN_2MB          = 0x200000

# ---------------------------------------------------------------------------
# SSH Configuration
# ---------------------------------------------------------------------------
GUEST_SSH  = "ubuntu@localhost"
GUEST_PORT = "7777"
GUEST_PY   = "/home/ubuntu/miniconda3/envs/mnist/bin/python3"

_sudo_user = os.environ.get("SUDO_USER")
_ssh_key   = (Path(f"/home/{_sudo_user}/.ssh/id_ed25519")
              if _sudo_user else Path.home() / ".ssh/id_ed25519")

SSH_BASE = [
    "ssh", "-p", GUEST_PORT,
    "-i", str(_ssh_key),
    "-o", "StrictHostKeyChecking=no",
    "-o", "BatchMode=yes",
    "-o", "ConnectTimeout=10",
    GUEST_SSH,
]


def ssh_run(cmd: str, timeout: int = 15) -> str:
    """Execute command on guest via SSH."""
    try:
        r = subprocess.run(SSH_BASE + [cmd], capture_output=True, text=True, timeout=timeout)
        return r.stdout + r.stderr
    except subprocess.TimeoutExpired:
        return ""


def ensure_guest_suppressions():
    """Suppress guest kernel watchdogs and THP before page swapping."""
    ssh_run(
        "echo 0 | sudo tee /proc/sys/kernel/watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/nmi_watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/softlockup_panic > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/hardlockup_panic > /dev/null 2>&1 ; "
        "echo 1 | sudo tee /proc/sys/kernel/rcu_cpu_stall_suppress > /dev/null 2>&1 ; "
        "echo never | sudo tee /sys/kernel/mm/transparent_hugepage/enabled > /dev/null 2>&1"
    )


def ensure_mtu_9000():
    """Ensure MTU 9000 on host TAP and guest network interface for large ICMP."""
    r = subprocess.run(["ip", "route", "get", "192.168.100.2"], capture_output=True, text=True)
    m = re.search(r'\bdev\s+(\S+)', r.stdout)
    if m:
        host_iface = m.group(1)
        cur = subprocess.run(["ip", "link", "show", host_iface], capture_output=True, text=True).stdout
        if "mtu 9000" not in cur:
            try:
                subprocess.run(["ip", "link", "set", host_iface, "mtu", "9000"], check=True)
                print(f"[mtu] Host {host_iface} MTU set to 9000")
            except Exception as e:
                print(f"[mtu] WARNING: Could not set host MTU: {e}", file=sys.stderr)

    out = ssh_run("ip -o addr show | awk '/192\\.168\\.100\\.2/{print $2}'")
    guest_iface = out.strip() or "enp0s4"
    result = ssh_run(f"ip link show {guest_iface}")
    if "mtu 9000" not in result:
        ssh_run(f"sudo ip link set {guest_iface} mtu 9000")
        print(f"[mtu] Guest {guest_iface} MTU set to 9000")


# ---------------------------------------------------------------------------
# JSON Helpers
# ---------------------------------------------------------------------------
def load_json(path: Path) -> Dict[str, Any]:
    with open(path, "r") as f:
        return json.load(f)


def save_json(path: Path, data: Dict[str, Any]):
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w") as f:
        json.dump(data, f, indent=2)


# ---------------------------------------------------------------------------
# Page2 Cache Management
# ---------------------------------------------------------------------------
def load_page2_table() -> Dict[int, int]:
    table = {}
    if PAGE2_CACHE_FILE.exists():
        try:
            data = load_json(PAGE2_CACHE_FILE)
            for k, v in data.items():
                table[int(k, 16)] = int(v, 16)
        except Exception:
            pass
    return table


def save_page2_table(table: Dict[int, int]):
    data = {f"0x{k:x}": f"0x{v:x}" for k, v in table.items()}
    save_json(PAGE2_CACHE_FILE, data)


def learn_page2(image_gpa: int, page2_gpa: int):
    table = load_page2_table()
    if table.get(image_gpa) != page2_gpa:
        table[image_gpa] = page2_gpa
        save_page2_table(table)
        print(f"[page2] Learned 0x{image_gpa:x} → 0x{page2_gpa:x}")


# ---------------------------------------------------------------------------
# Image & Metric Utilities
# ---------------------------------------------------------------------------
def compute_ssim(a: np.ndarray, b: np.ndarray, win: int = 7, data_range: float = 1.0) -> float:
    """Compute SSIM between two 2D image arrays in [0, 1]."""
    from scipy.ndimage import uniform_filter
    C1 = (0.01 * data_range) ** 2
    C2 = (0.03 * data_range) ** 2
    a = a.astype(np.float64)
    b = b.astype(np.float64)
    mu1 = uniform_filter(a, win)
    mu2 = uniform_filter(b, win)
    s1  = uniform_filter(a * a, win) - mu1 ** 2
    s2  = uniform_filter(b * b, win) - mu2 ** 2
    s12 = uniform_filter(a * b, win) - mu1 * mu2
    num = (2 * mu1 * mu2 + C1) * (2 * s12 + C2)
    den = (mu1 ** 2 + mu2 ** 2 + C1) * (s1 + s2 + C2)
    return float((num / den).mean())


def compute_psnr(a: np.ndarray, b: np.ndarray, data_range: float = 1.0) -> float:
    mse = float(np.mean((a.astype(np.float64) - b.astype(np.float64)) ** 2))
    if mse < 1e-10:
        return 99.99
    return float(20.0 * math.log10(data_range / math.sqrt(mse)))


def compute_l1(a: np.ndarray, b: np.ndarray) -> float:
    return float(np.mean(np.abs(a.astype(np.float64) - b.astype(np.float64))))


HEX_LINE = re.compile(r'^(?:0x)?[0-9a-f]+:\s+0x([0-9a-f]{16})\s+0x([0-9a-f]{16})', re.IGNORECASE)


def parse_dump(path: Path) -> bytearray:
    """Parse a single QEMU xp dump file into a little-endian bytearray."""
    buf = bytearray()
    with open(path, errors='replace') as f:
        for line in f:
            m = HEX_LINE.match(line.strip())
            if m:
                for grp in (m.group(1), m.group(2)):
                    buf += int(grp, 16).to_bytes(8, 'little')
    return buf
