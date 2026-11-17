#!/usr/bin/env python3
"""
common.py — constants and helpers for the MURA 3-plane end-to-end attack (mura3p).

Same machinery as case_study/shapes3d (run probe + channel assembly over all
three planes); the dictionary is MURA's uniform u8 levels, one ref per level per
channel (normalize differs per channel). MURA is grayscale, so R/G/B planes carry
the same pixels: the three planes are fused into one (64,224,56) level map for
MURA's existing XorSliceSENet classifier.

(Original 3DShapes notes follow.)

Mirrors case_study/mura/pipeline/common.py (SSH, MTU, dump parsing, Region A/B)
with 3DShapes-specific values. The victim tensor is (3,224,224) float32 after
Resize(224) -> ToTensor -> Normalize(ImageNet): 3 planes x 49 pages = 147 pages.

The dictionary is not MURA's uniform levels: each ref is one 16 B chunk of 4
(possibly different) normalized pixels of one channel, chosen by
offline/select_dict.py and stored in offline/dict_keywords.json.
"""

import json
import os
import re
import struct
import subprocess
import sys
from pathlib import Path
from typing import Any, Dict, List

import numpy as np

PIPELINE_DIR = Path(__file__).resolve().parent
SHAPES_DIR = PIPELINE_DIR.parent          # = case_study/mura3p
CASE_STUDY_DIR = SHAPES_DIR.parent
MURA_DIR = CASE_STUDY_DIR / "mura"

DICT_DIR = SHAPES_DIR / "dict" / "dict_pages_m3"
DICT_CACHE_FILE = SHAPES_DIR / "dict" / "dict_cache_m3.json"
KEYWORDS_FILE = SHAPES_DIR / "offline" / "dict_keywords.json"
SWAP_TOOL_PATH = MURA_DIR / "dict" / "swap_pages_tool"
TRACKER_PATH = CASE_STUDY_DIR.parent / "sev-step-module" / "write_pattern_tracker"

CLASSES = ["ELBOW", "FINGER", "FOREARM", "HAND", "HUMERUS", "SHOULDER", "WRIST"]
NUM_REFS = 64                    # levels per channel (MURA REF_U8_64)
MURA_GUEST_DIR = "/home/ubuntu/cc_uvm/pytorch_uvm310_test/mura"
IMG_SIZE = 224
PAGE_SIZE = 4096
CHUNK_SIZE = 16
CHUNKS_PER_PAGE = PAGE_SIZE // CHUNK_SIZE
PLANE_PAGES = 49                 # 224*224*4 B = 200,704 B
TOTAL_CHANNELS = 3
IMG_PAGES = PLANE_PAGES * TOTAL_CHANNELS   # 147
MAP_ROWS, MAP_COLS = 224, 56     # blocks per plane
CHANNELS_ALL = ("R", "G", "B")
IMAGENET_MEAN = {"R": 0.485, "G": 0.456, "B": 0.406}
IMAGENET_STD = {"R": 0.229, "G": 0.224, "B": 0.225}

# Same guest kernel / workload class as MURA: reuse its Region A/B filter.
BLIND_B_LO, BLIND_B_HI = 0x3f80000000, 0x3f90000000
BLIND_A_LO, BLIND_A_HI = 0x3f7fc00000, 0x3f7fd00000
BLIND_ALIGN_2MB = 0x200000

GUEST_SSH = "ubuntu@localhost"
GUEST_PORT = "7777"
GUEST_PY = "/home/ubuntu/miniconda3/envs/mura/bin/python3"
GUEST_DIR = "/home/ubuntu/mura3p"
# Resident victim (guest_shapes_server.py) instead of one loader process per sample.
USE_SERVER = False                # fresh loader process per sample (shapes3d finding)

_sudo_user = os.environ.get("SUDO_USER")
_ssh_key = (Path(f"/home/{_sudo_user}/.ssh/id_ed25519") if _sudo_user
            else Path.home() / ".ssh/id_ed25519")
SSH_BASE = ["ssh", "-p", GUEST_PORT, "-i", str(_ssh_key),
            "-o", "StrictHostKeyChecking=no", "-o", "UserKnownHostsFile=/dev/null",
            "-o", "BatchMode=yes", "-o", "ConnectTimeout=10", GUEST_SSH]


def ssh_run(cmd: str, timeout: int = 15) -> str:
    try:
        r = subprocess.run(SSH_BASE + [cmd], capture_output=True, text=True, timeout=timeout)
        return r.stdout + r.stderr
    except subprocess.TimeoutExpired:
        return ""


def ensure_guest_suppressions():
    ssh_run(
        "echo 0 | sudo tee /proc/sys/kernel/watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/nmi_watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/softlockup_panic > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/hardlockup_panic > /dev/null 2>&1 ; "
        "echo 1 | sudo tee /proc/sys/kernel/rcu_cpu_stall_suppress > /dev/null 2>&1 ; "
        "echo never | sudo tee /sys/kernel/mm/transparent_hugepage/enabled > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/printk_ratelimit > /dev/null 2>&1")


def ensure_mtu_9000():
    r = subprocess.run(["ip", "route", "get", "192.168.100.2"], capture_output=True, text=True)
    m = re.search(r'\bdev\s+(\S+)', r.stdout)
    if m:
        iface = m.group(1)
        if "mtu 9000" not in subprocess.run(["ip", "link", "show", iface],
                                            capture_output=True, text=True).stdout:
            subprocess.run(["ip", "link", "set", iface, "mtu", "9000"])
    out = ssh_run("ip -o addr show | awk '/192\\.168\\.100\\.2/{print $2}'")
    giface = out.strip() or "enp0s4"
    if "mtu 9000" not in ssh_run(f"ip link show {giface}"):
        ssh_run(f"sudo ip link set {giface} mtu 9000")


def norm_f32(u8, ch: str) -> np.ndarray:
    """torchvision ToTensor + Normalize, float32 op order."""
    u8 = np.asarray(u8)
    return ((u8.astype(np.float32) / np.float32(255) - np.float32(IMAGENET_MEAN[ch]))
            / np.float32(IMAGENET_STD[ch])).astype(np.float32)


def load_keywords() -> List[Dict]:
    """Flat ref list: [{'name','ch','rank','pixels','chunk'(bytes)}], 3K entries."""
    kw = json.loads(KEYWORDS_FILE.read_text())
    refs = []
    for ch in CHANNELS_ALL:
        for e in kw["channels"][ch]:
            refs.append({"name": f"{ch}{e['rank']:02d}", "ch": ch, "rank": e["rank"],
                         "pixels": e["pixels"], "chunk": bytes.fromhex(e["chunk_hex"])})
    return refs


def load_json(path: Path) -> Dict[str, Any]:
    with open(path) as f:
        return json.load(f)


def save_json(path: Path, data: Dict[str, Any]):
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w") as f:
        json.dump(data, f, indent=2)


HEX_LINE = re.compile(r'^[0-9a-f]+:\s+0x([0-9a-f]{16})\s+0x([0-9a-f]{16})', re.IGNORECASE)


def parse_dump(path: Path) -> bytes:
    if not path.exists():
        return b"\x00" * PAGE_SIZE
    out = []
    with open(path, errors="replace") as f:
        for line in f:
            m = HEX_LINE.match(line.strip())
            if m:
                out.append(struct.pack("<QQ", int(m.group(1), 16), int(m.group(2), 16)))
    return b"".join(out) if out else b"\x00" * PAGE_SIZE
