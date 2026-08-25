#!/usr/bin/env python3
"""
diagnose_zero_page.py — Verify whether orchestrate.py's zero_gpa acquisition
(acquire_zero_gpa(), which hardcodes gpas[1] as "the" zero page) is a
reliable, reusable baseline.

IMPORTANT: guest memory is SEV-SNP encrypted, so `xp` reads CIPHERTEXT, not
plaintext. An all-zero plaintext page does NOT look like 0x00 bytes on dump
(AES-XEX ciphertext is pseudorandom regardless of plaintext) — checking
"is the dump literally zero" is the WRONG test and was this script's first,
incorrect version.

The property that actually matters (since z.out is captured ONCE and reused
as the "before" baseline for every sample — orchestrate.py:315-328): the
ciphertext at zero_gpa must be REPRODUCIBLE, i.e. the underlying plaintext
content must be stable across repeated captures. Same plaintext + same GPA
under AES-XEX always yields identical ciphertext. If the candidate page's
content includes non-payload "leftover" memory that varies send-to-send, the
ciphertext at that GPA will NOT be identical across repeated captures —
that's the real signal of a contaminated/unreliable zero baseline.

This script sends the zero ICMP N times, dumps every "sub-page[N] GPA=..."
candidate each round, and checks whether repeated visits to the same GPA
produce byte-identical ciphertext.

Usage:
    sudo python3 diagnose_zero_page.py
"""

import hashlib
import os
import re
import socket
import struct
import subprocess
import sys
import time
from pathlib import Path

NUM_ROUNDS = 5

HERE = Path(__file__).parent

GUEST_SSH  = "ubuntu@localhost"
GUEST_PORT = "7777"

# When running under sudo, use the invoking user's SSH key, not root's
# (root has no authorized identity on the guest).
_sudo_user = os.environ.get("SUDO_USER")
_ssh_key   = (Path(f"/home/{_sudo_user}/.ssh/id_ed25519")
              if _sudo_user else Path.home() / ".ssh/id_ed25519")
SSH_BASE   = ["ssh", "-p", GUEST_PORT,
              "-i", str(_ssh_key),
              "-o", "StrictHostKeyChecking=no",
              "-o", "BatchMode=yes", "-o", "ConnectTimeout=8", GUEST_SSH]

DEST_IP      = "192.168.100.2"
# 2*4096+1 = 8193B: mathematically guarantees the MIDDLE of the 3 spanned
# pages is entirely covered by our zero payload, regardless of alignment
# (this is what orchestrate.py's stale comment assumed — send_tokens.py's
# actual PAYLOAD_SIZE=4097 does NOT meet this bound). Testing the fix here.
PAYLOAD_SIZE = 8193

MONITOR_SOCK = "/tmp/qemu-monitor.sock"
QEMU_PROMPT  = b"(qemu) "


def ssh(cmd: str, timeout: int = 15) -> str:
    r = subprocess.run(SSH_BASE + [cmd], capture_output=True, text=True, timeout=timeout)
    return r.stdout + r.stderr


def _checksum(data: bytes) -> int:
    s = 0
    for i in range(0, len(data) - 1, 2):
        s += (data[i + 1] << 8) + data[i]
    if len(data) & 1:
        s += data[-1]
    s = (s >> 16) + (s & 0xFFFF)
    s += s >> 16
    return ~s & 0xFFFF


def send_zero_icmp() -> None:
    payload = b"\x00" * PAYLOAD_SIZE
    pid = os.getpid() & 0xFFFF
    hdr = struct.pack("!BBHHH", 8, 0, 0, pid, 0)
    chk = _checksum(hdr + payload)
    hdr = struct.pack("!BBHHH", 8, 0, chk, pid, 0)
    s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
    try:
        s.sendto(hdr + payload, (DEST_IP, 0))
    finally:
        s.close()


def _recv_until_prompt(sock: socket.socket) -> bytes:
    buf = b""
    while QEMU_PROMPT not in buf:
        chunk = sock.recv(65536)
        if not chunk:
            break
        buf += chunk
    return buf


def read_page(gpa: int) -> str:
    sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    sock.settimeout(30)
    sock.connect(MONITOR_SOCK)
    _recv_until_prompt(sock)
    sock.sendall(f"xp /512gx 0x{gpa:x}\n".encode())
    raw = _recv_until_prompt(sock).decode(errors="replace")
    sock.close()
    return raw


def parse_dump_bytes(raw: str) -> bytes:
    chunks = []
    for line in raw.splitlines():
        m = re.search(r'[0-9a-f]{12,16}:\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+)', line)
        if m:
            chunks.append(struct.pack('<QQ', int(m.group(1), 16), int(m.group(2), 16)))
    return b"".join(chunks)


def one_round(round_idx: int) -> list[tuple[str, int, bytes]]:
    ssh("sudo dmesg -C")
    send_zero_icmp()
    time.sleep(1)
    out = ssh("sudo dmesg", timeout=40)
    matches = re.findall(r"sub-page\[(\d+)\]\s+GPA=0x([0-9a-f]+)", out, re.IGNORECASE)
    if not matches:
        print(f"  [round {round_idx}] [!] No sub-page lines found. Raw dmesg tail:")
        print(out[-1500:])
        return []

    print(f"  [round {round_idx}] {len(matches)} sub-page(s) spanned this send")
    results = []
    for i, (subidx, gpa_hex) in enumerate(matches):
        gpa = int(gpa_hex, 16)
        raw = read_page(gpa)
        data = parse_dump_bytes(raw)
        digest = hashlib.sha1(data).hexdigest()[:12]
        marker = ""
        if i == 1:
            marker = "  <-- orchestrate.py's choice (gpas[1])"
            if len(matches) == 3:
                marker += "  [middle of 3 — should be guaranteed full-zero]"
        print(f"  [round {round_idx}] match[{i}] sub-page[{subidx}] GPA=0x{gpa:x}  "
              f"bytes={len(data)}  sha1={digest}{marker}")
        results.append((subidx, gpa, data))
    return results


def main() -> None:
    all_rounds = []
    for r in range(NUM_ROUNDS):
        print(f"=== round {r} ===")
        all_rounds.append(one_round(r))
        time.sleep(1)

    by_gpa: dict[int, list[bytes]] = {}
    for res in all_rounds:
        for subidx, gpa, data in res:
            by_gpa.setdefault(gpa, []).append(data)

    print("\n=== consistency check: same GPA revisited across rounds ===")
    print("(same plaintext+GPA under AES-XEX ALWAYS gives identical ciphertext —")
    print(" if a GPA's content varies across rounds, it's not a stable/reusable baseline)")
    any_gpa_revisited = False
    for gpa, datas in by_gpa.items():
        if len(datas) < 2:
            continue
        any_gpa_revisited = True
        unique = {d for d in datas}
        status = "STABLE (deterministic)" if len(unique) == 1 else "VARIES !! (contaminated)"
        print(f"  GPA=0x{gpa:x}  visits={len(datas)}  unique_contents={len(unique)}  {status}")
    if not any_gpa_revisited:
        print("  No GPA was revisited across rounds (guest picked a different physical "
              "page each send) — cannot test determinism this way; see fallback below.")


if __name__ == "__main__":
    main()
