#!/usr/bin/env python3
"""
common.py — Shared constants, paths, SSH utilities, dictionary references,
and quantitative metrics for MURA End-to-End Attack Pipeline.
"""

import json
import math
import os
import re
import struct
import subprocess
import sys
import time
from pathlib import Path
from typing import Any, Dict, List, Optional, Tuple

import numpy as np

# ---------------------------------------------------------------------------
# Directories & Canonical Paths
# ---------------------------------------------------------------------------
PIPELINE_DIR    = Path(__file__).resolve().parent
MURA_DIR        = PIPELINE_DIR.parent
CASE_STUDY_DIR  = MURA_DIR.parent
HOST_SCRIPTS_DIR = CASE_STUDY_DIR / "host_scripts"
DICT_DIR        = MURA_DIR / "dict" / "dict_pages_mura"
DICT_CACHE_FILE = MURA_DIR / "dict" / "dict_cache_mura.json"
SWAP_TOOL_PATH  = MURA_DIR / "dict" / "swap_pages_tool"
DENSITY_SURVEY_PATH = MURA_DIR / "xor_density_survey.npy"

# Model Checkpoints
CHECKPOINT_V3   = MURA_DIR / "mura_xor_slice_64ref_v3.pth"
CHECKPOINT_V2   = MURA_DIR / "mura_xor_slice_64ref_v2.pth"

# Tracker binary
TRACKER_PATH = MURA_DIR.parent / "sev-step-module" / "write_pattern_tracker"
if not TRACKER_PATH.exists():
    fallback_tracker = CASE_STUDY_DIR / "mnist" / "flow" / "write_pattern_tracker"
    if fallback_tracker.exists():
        TRACKER_PATH = fallback_tracker

# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------
CLASSES         = ["ELBOW", "FINGER", "FOREARM", "HAND", "HUMERUS", "SHOULDER", "WRIST"]
CLASS2IDX       = {c: i for i, c in enumerate(CLASSES)}
IMG_SIZE        = 224
PAGE_SIZE       = 4096
CHUNK_SIZE      = 16
CHUNKS_PER_PAGE = PAGE_SIZE // CHUNK_SIZE  # 256 chunks/page
IMG_PAGES       = 49                       # 224x224 f32 = 200,704 B = 49 pages
TOTAL_CHANNELS  = 3
XOR_ROWS        = 224
XOR_COLS        = 56                       # 224 // 4 pixels per chunk
NUM_REFS        = 64

# Precursor Blind Tracking Constants
BLIND_B_LO, BLIND_B_HI = 0x3f80000000, 0x3f90000000   # Region B: Precursor
BLIND_A_LO, BLIND_A_HI = 0x3f7fc00000, 0x3f7fd00000   # Region A: Excluded
BLIND_LOOKAHEAD  = 12
BLIND_MIN_RUN    = 2
BLIND_GAP_TOL    = 2
BLIND_WINDOW_US  = 40
BLIND_ALIGN_2MB  = 0x200000

# Normalization Parameters (ImageNet per-channel)
IMAGENET_MEAN = {"R": 0.485, "G": 0.456, "B": 0.406}
IMAGENET_STD  = {"R": 0.229, "G": 0.224, "B": 0.225}
CHANNELS_ALL  = ("R", "G", "B")

# ---------------------------------------------------------------------------
# 64-Ref Density Selection
# ---------------------------------------------------------------------------
if DENSITY_SURVEY_PATH.exists():
    _hit = np.load(DENSITY_SURVEY_PATH)
    REF_U8_64 = np.argsort(-_hit)[:NUM_REFS].tolist()
else:
    REF_U8_64 = list(range(NUM_REFS))


def normalize_u8(u8: int, ch: str = "R") -> np.float32:
    """Float32 normalized pixel value after /255 + ImageNet mean/std."""
    return ((np.float32(u8) / np.float32(255) - np.float32(IMAGENET_MEAN[ch]))
            / np.float32(IMAGENET_STD[ch]))


def chunk16(u8: int, ch: str = "R") -> bytes:
    """16-byte chunk representing 4 consecutive identical normalized pixels."""
    return (np.array([normalize_u8(u8, ch)], dtype=np.float32)).view(np.uint8).tobytes() * 4


REF_CHUNKS_BY_CH: Dict[str, Dict[int, bytes]] = {
    ch: {u8: chunk16(u8, ch) for u8 in REF_U8_64} for ch in CHANNELS_ALL
}

# ---------------------------------------------------------------------------
# SSH Configuration
# ---------------------------------------------------------------------------
GUEST_SSH  = "ubuntu@localhost"
GUEST_PORT = "7777"
GUEST_PY   = "/home/ubuntu/miniconda3/envs/mura/bin/python3"

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
        "echo never | sudo tee /sys/kernel/mm/transparent_hugepage/enabled > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/printk_ratelimit > /dev/null 2>&1"
    )


def ensure_mtu_9000():
    """Ensure MTU 9000 on host TAP and guest interface."""
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
# JSON & Dump Parsing Utilities
# ---------------------------------------------------------------------------
def load_json(path: Path) -> Dict[str, Any]:
    with open(path, "r") as f:
        return json.load(f)


def save_json(path: Path, data: Dict[str, Any]):
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w") as f:
        json.dump(data, f, indent=2)


HEX_LINE = re.compile(r'^[0-9a-f]+:\s+0x([0-9a-f]{16})\s+0x([0-9a-f]{16})', re.IGNORECASE)


def parse_dump(path: Path) -> bytes:
    """Parse a single QEMU xp dump file into raw bytes."""
    chunks = []
    if not path.exists():
        return b"\x00" * PAGE_SIZE
    with open(path, errors='replace') as f:
        for line in f:
            m = HEX_LINE.match(line.strip())
            if m:
                chunks.append(struct.pack("<QQ", int(m.group(1), 16), int(m.group(2), 16)))
    return b"".join(chunks) if chunks else b"\x00" * PAGE_SIZE



