#!/usr/bin/env python3
"""
verify_swap_back.py — Confirm swap_pages_tool --swap-back restores zero_gpa.

Steps:
  1. Acquire zero_gpa  (ICMP send → guest dmesg)
  2. Read ciphertext at zero_gpa via QEMU xp  → before_hash
  3. Acquire gpa2      (second ICMP send, any content — used as swap target)
  4. swap_pages_tool 0x<zero_gpa> 0x<gpa2> --swap-back
  5. Read ciphertext at zero_gpa via QEMU xp  → after_hash
  6. PASS if before_hash == after_hash, FAIL otherwise

Usage:
    sudo python3 verify_swap_back.py
"""

import hashlib
import os
import re
import socket
import subprocess
import sys
import time
from pathlib import Path

HERE       = Path(__file__).parent
SWAP_TOOL  = HERE / "swap_pages_tool"
MONITOR    = "/tmp/qemu-monitor.sock"
DEST_IP    = "192.168.100.2"
GUEST_PORT = "7777"
GUEST_SSH  = "ubuntu@localhost"

_sudo_user = os.environ.get("SUDO_USER")
_ssh_key   = (Path(f"/home/{_sudo_user}/.ssh/id_ed25519")
              if _sudo_user else Path.home() / ".ssh/id_ed25519")
SSH_BASE   = ["ssh", "-p", GUEST_PORT, "-i", str(_ssh_key),
              "-o", "StrictHostKeyChecking=no", "-o", "BatchMode=yes",
              "-o", "ConnectTimeout=10", GUEST_SSH]

# ── helpers ───────────────────────────────────────────────────────────────────

def ssh(cmd: str, timeout: int = 20) -> str:
    try:
        r = subprocess.run(SSH_BASE + [cmd], capture_output=True, text=True, timeout=timeout)
        return r.stdout + r.stderr
    except subprocess.TimeoutExpired:
        return ""


def _icmp_checksum(data: bytes) -> int:
    s = 0
    for i in range(0, len(data) - 1, 2):
        s += (data[i+1] << 8) + data[i]
    if len(data) & 1:
        s += data[-1]
    s = (s >> 16) + (s & 0xFFFF)
    s += s >> 16
    return ~s & 0xFFFF


def send_zero_icmp(payload_size: int = 8193) -> None:
    payload = b"\x00" * payload_size
    pid = os.getpid() & 0xFFFF
    hdr = b"\x08\x00\x00\x00" + pid.to_bytes(2, "big") + b"\x00\x01"
    chk = _icmp_checksum(hdr + payload)
    hdr = b"\x08\x00" + chk.to_bytes(2, "big") + hdr[4:]
    sock = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
    try:
        sock.sendto(hdr + payload, (DEST_IP, 0))
    finally:
        sock.close()


def acquire_gpa(label: str) -> int:
    print(f"  [{label}] Clearing dmesg...")
    ssh("sudo dmesg -C")
    print(f"  [{label}] Sending zero ICMP (8193 B)...")
    send_zero_icmp()
    for attempt in range(5):
        time.sleep(1.5)
        out = ssh("sudo dmesg", timeout=15)
        # prefer compound_GPA parse (reliable, not rate-limited)
        m = re.search(
            r"frag\[0\].*?compound_GPA=0x([0-9a-f]+).*?\boff=(\d+)",
            out, re.IGNORECASE,
        )
        if m:
            compound = int(m.group(1), 16)
            off      = int(m.group(2))
            gpa = compound + ((off // 4096) + 1) * 4096
            print(f"  [{label}] GPA = 0x{gpa:x}  (attempt {attempt+1})")
            return gpa
        # fallback: sub-page lines
        gpas = re.findall(r"sub-page\[\d+\]\s+GPA=0x([0-9a-f]+)", out, re.IGNORECASE)
        if len(gpas) >= 2:
            gpa = int(gpas[1], 16)
            print(f"  [{label}] GPA = 0x{gpa:x}  (sub-page fallback, attempt {attempt+1})")
            return gpa
        print(f"  [{label}] no GPA yet (attempt {attempt+1}/5)...")
    print(f"  [{label}] FAILED to acquire GPA", file=sys.stderr)
    sys.exit(1)


def qemu_xp(gpa: int) -> bytes:
    """Read GPA ciphertext via QEMU HMP xp command, return raw bytes of response."""
    sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    sock.settimeout(30)
    sock.connect(MONITOR)
    buf = b""
    while b"(qemu)" not in buf:
        buf += sock.recv(65536)
    sock.sendall(f"xp /512gx 0x{gpa:x}\n".encode())
    buf = b""
    while b"(qemu)" not in buf:
        buf += sock.recv(65536)
    sock.close()
    return buf


def ciphertext_hash(gpa: int) -> str:
    raw = qemu_xp(gpa)
    return hashlib.sha256(raw).hexdigest()


# ── main ──────────────────────────────────────────────────────────────────────

def main() -> None:
    print("=" * 60)
    print("verify_swap_back.py")
    print("=" * 60)

    # Step 1: acquire zero_gpa
    print("\n[1/5] Acquiring zero_gpa...")
    zero_gpa = acquire_gpa("zero_gpa")

    # Step 2: ciphertext hash BEFORE swap
    print(f"\n[2/5] Reading ciphertext at 0x{zero_gpa:x} (before swap)...")
    before_hash = ciphertext_hash(zero_gpa)
    print(f"  SHA256 = {before_hash[:16]}...")

    # Step 3: acquire a second GPA (swap target — any content OK)
    print("\n[3/5] Acquiring gpa2 (swap target)...")
    gpa2 = acquire_gpa("gpa2")
    print(f"  gpa2 = 0x{gpa2:x}")
    if gpa2 == zero_gpa:
        print("  [!] Same GPA — kernel reused the buffer. Retrying...")
        gpa2 = acquire_gpa("gpa2-retry")

    # Step 4: swap --swap-back
    print(f"\n[4/5] Running swap_pages_tool 0x{zero_gpa:x} 0x{gpa2:x} --swap-back ...")
    rc = subprocess.run(
        [str(SWAP_TOOL), f"0x{zero_gpa:x}", f"0x{gpa2:x}", "--swap-back"]
    ).returncode
    if rc != 0:
        print(f"  [!] swap_pages_tool exited {rc} — ABORT", file=sys.stderr)
        sys.exit(1)

    # Step 5: ciphertext hash AFTER swap
    print(f"\n[5/5] Reading ciphertext at 0x{zero_gpa:x} (after swap)...")
    after_hash = ciphertext_hash(zero_gpa)
    print(f"  SHA256 = {after_hash[:16]}...")

    # Verdict
    print("\n" + "=" * 60)
    if before_hash == after_hash:
        print("PASS — ciphertext identical before and after swap.")
        print("       zero_gpa IS correctly restored by --swap-back.")
    else:
        print("FAIL — ciphertext CHANGED after swap!")
        print(f"  before: {before_hash}")
        print(f"  after : {after_hash}")
        print("  zero_gpa was NOT restored. Do NOT reuse the zero page.")
        sys.exit(1)
    print("=" * 60)


if __name__ == "__main__":
    main()
