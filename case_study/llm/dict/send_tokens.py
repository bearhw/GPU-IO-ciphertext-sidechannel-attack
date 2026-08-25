#!/usr/bin/env python3
"""
Send ICMP echo requests with int64 token IDs packed as little-endian int64
into the payload.  Payload is zero-padded to > 4 KB so that
guest_large_icmp_monitor.ko captures the GPA of the page holding the data.

Usage:
    sudo python3 send_tokens.py            # list all labels
    sudo python3 send_tokens.py <idx>      # send that label indefinitely (Ctrl-C to stop)
    sudo python3 send_tokens.py <idx> <n>  # send n packets then exit
    sudo python3 send_tokens.py <idx> <n> --prefix N  # shift token bytes by N bytes for alignment
    sudo python3 send_tokens.py <idx> --try-all-phases  # send prefix 0..31 and print each GPA

Dest: 192.168.100.2 (guest TAP interface)
"""

import os
import re
import struct
import socket
import subprocess
import sys
import time
from pathlib import Path

DEST_IP        = "192.168.100.2"
PAYLOAD_SIZE      = 4097   # > 4 KB  →  triggers GPA page walk in guest module
ZERO_PAYLOAD_SIZE = 8193   # 2×4096+1: guarantees page[1] is always a full zero page
INTERVAL       = 1.0           # seconds between packets

GUEST_SSH  = "ubuntu@localhost"
GUEST_PORT = "7777"
_sudo_user = os.environ.get("SUDO_USER")
_ssh_key   = (Path(f"/home/{_sudo_user}/.ssh/id_ed25519")
              if _sudo_user else Path.home() / ".ssh/id_ed25519")
_SSH_BASE  = [
    "ssh", "-p", GUEST_PORT,
    "-i", str(_ssh_key),
    "-o", "StrictHostKeyChecking=no",
    "-o", "BatchMode=yes",
    "-o", "ConnectTimeout=5",
    GUEST_SSH,
]

IMAGE_PAD_TOKEN_ID = 151655   # <|image_pad|> token ID for Qwen2-VL

# Must match TOKEN_LABELS order in orchestrate_v2.py exactly.
TOKENS: dict[str, list[int]] = {
    "Chest PAIN":                          [41771, 393, 6836],                                  # 0  3tok
    "Short of breath":                     [10698, 315, 11486],                                 # 1  3tok
    "short of breath":                     [2805,  315, 11486],                                 # 2  3tok
    "Productive cough":                    [5643,  533, 39600],                                 # 3  3tok
    "Left chest pain":                     [13727, 15138, 6646],                                # 4  3tok
    "Central chest pain":                  [10684, 15138, 6646],                                # 5  3tok
    "Nonproductive cough":                 [11581, 33270, 39600],                               # 6  3tok
    "Shortness of breath":                 [10698, 2090, 315, 11486],                           # 7  4tok
    "shortness of breath":                 [2805,  2090, 315, 11486],                           # 8  4tok
    "CHEST PAIN":                          [49521, 784, 393, 6836],                             # 9  4tok
    "Shortness of Breath":                 [10698, 2090, 315, 57192],                           # 10 4tok
    "shortness of Breath":                 [2805,  2090, 315, 57192],                           # 11 4tok
    "Respiratory failure":                 [76834, 5269, 7901],                                 # 12 3tok
    "Altered mental status":               [1674, 33159, 10502, 2639],                          # 13 4tok
    "altered mental status":               [28752, 10502, 2639],                                # 14 3tok
    "Respiratory distress":                [76834, 5269, 34004],                                # 15 3tok
    "Abdominal pain":                      [3680,  5600, 977, 6646],                            # 16 4tok
    "Left-sided chest pain":               [13727, 49758, 15138, 6646],                         # 17 4tok
    "Right-sided chest pain":              [10083, 49758, 15138, 6646],                         # 18 4tok
    "Acute respiratory failure":           [6381,  1070, 41531, 7901],                          # 19 4tok
    "Increasing shortness of breath":      [73440, 2805, 2090, 315, 11486],                     # 20 5tok
    "Severe shortness of breath":          [1345, 19289, 2805, 2090, 315, 11486],               # 21 6tok
    "Cough, short of breath":              [356, 1384, 11, 2805, 315, 11486],                   # 22 6tok
    "Cough, shortness of breath":          [356, 1384, 11, 2805, 2090, 315, 11486],             # 23 7tok
    "Cough and shortness of breath":       [356, 1384, 323, 2805, 2090, 315, 11486],            # 24 7tok
    "Worsening shortness of breath":       [467, 1087, 6019, 2805, 2090, 315, 11486],           # 25 7tok
    "Acute onset of shortness of breath":  [6381, 1070, 40980, 315, 2805, 2090, 315, 11486],    # 26 8tok
    "respiratory failure":                 [41531, 7901],                                       # 27 2tok
    "respiratory distress":                [41531, 34004],                                      # 28 2tok
    "abdominal pain":                      [55956, 6646],                                       # 29 2tok
    "image_pad×4":                         [IMAGE_PAD_TOKEN_ID] * 4,                            # 30 sentinel
}

# ---------------------------------------------------------------------------

def _checksum(data: bytes) -> int:
    s = 0
    for i in range(0, len(data) - 1, 2):
        s += (data[i + 1] << 8) + data[i]
    if len(data) & 1:
        s += data[-1]
    s = (s >> 16) + (s & 0xFFFF)
    s += s >> 16
    return ~s & 0xFFFF


def _make_payload(token_ids: list[int], prefix: int = 0) -> bytes:
    """
    Fill payload with repeated token bytes after `prefix` zero bytes.
    Adjusting prefix places token bytes at different page offsets,
    allowing alignment with the indication token's page offset (O_target).
    payload_size = max(PAYLOAD_SIZE, prefix + token_len + 1).
    """
    token_bytes = struct.pack(f"<{len(token_ids)}q", *token_ids)
    payload_size = max(PAYLOAD_SIZE, prefix + len(token_bytes) + 1)
    remaining = payload_size - prefix
    repeated = (token_bytes * (remaining // len(token_bytes) + 1))[:remaining]
    return b"\x00" * prefix + repeated


def _make_zero_payload() -> bytes:
    return b"\x00" * ZERO_PAYLOAD_SIZE


def _build_packet(payload: bytes, seq: int) -> bytes:
    pid = os.getpid() & 0xFFFF
    hdr = struct.pack("!BBHHH", 8, 0, 0, pid, seq & 0xFFFF)
    chk = _checksum(hdr + payload)
    hdr = struct.pack("!BBHHH", 8, 0, chk, pid, seq & 0xFFFF)
    return hdr + payload


def send(label: str, payload: bytes, count: int = 0) -> None:
    print(f"\n[{label}]  payload={len(payload)}B")

    sock = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
    seq = 0
    try:
        while True:
            pkt = _build_packet(payload, seq)
            sock.sendto(pkt, (DEST_IP, 0))
            print(f"  sent seq={seq}")
            seq += 1
            if count and seq >= count:
                break
            time.sleep(INTERVAL)
    except KeyboardInterrupt:
        print("\nstopped.")
    finally:
        sock.close()


# ---------------------------------------------------------------------------
# SSH helper + all-phases
# ---------------------------------------------------------------------------

def _ssh(cmd: str, timeout: int = 10) -> str:
    r = subprocess.run(_SSH_BASE + [cmd], capture_output=True, text=True, timeout=timeout)
    return r.stdout + r.stderr


def _parse_gpa(dmesg_out: str) -> int | None:
    """Parse the last 'GPA=0x...' from dmesg output."""
    gpas = re.findall(r"GPA=0x([0-9a-f]+)", dmesg_out, re.IGNORECASE)
    return int(gpas[-1], 16) if gpas else None


def _send_one_quiet(token_ids: list[int], prefix: int, seq: int = 0) -> None:
    """Open one socket and silently send one packet."""
    payload = _make_payload(token_ids, prefix=prefix)
    pkt = _build_packet(payload, seq)
    sock = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
    try:
        sock.sendto(pkt, (DEST_IP, 0))
    finally:
        sock.close()


def try_all_phases(token_ids: list[int], n_phases: int = 32) -> list[tuple[int, int]]:
    """
    Send one packet per prefix 0..n_phases-1 and collect GPAs from guest dmesg.
    Returns [(prefix, gpa), ...] — prefixes with no GPA are omitted.
    Prints 'PHASE  0  GPA=0x...' format to stdout (parseable by orchestrate.py).
    """
    results = []
    for prefix in range(n_phases):
        _ssh("sudo dmesg -C")
        _send_one_quiet(token_ids, prefix=prefix)
        time.sleep(0.5)
        gpa = _parse_gpa(_ssh("sudo dmesg"))
        if gpa is not None:
            print(f"PHASE {prefix:2d}  GPA=0x{gpa:x}")
            results.append((prefix, gpa))
        else:
            print(f"PHASE {prefix:2d}  GPA=None", file=sys.stderr)
    return results


# ---------------------------------------------------------------------------

def main() -> None:
    import argparse
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("idx_or_z", nargs="?",
                   help="Token index or 'z' (zeros). Omit to list all labels")
    p.add_argument("count", nargs="?", type=int, default=0,
                   help="Number of packets to send (0 = infinite)")
    p.add_argument("--prefix", type=int, default=0, metavar="N",
                   help="Number of 0x00 bytes to prepend before token bytes (for alignment)")
    p.add_argument("--try-all-phases", action="store_true",
                   help="Send one packet per prefix 0..31 and print each GPA as 'PHASE N GPA=0x...'")
    args = p.parse_args()

    items = list(TOKENS.items())

    if args.idx_or_z is None:
        print("Available labels:")
        for i, (label, ids) in enumerate(items):
            print(f"  {i}  {label!r:35s}  {ids}")
        print(f"  z  zeros (0x00 × {ZERO_PAYLOAD_SIZE})")
        print(f"\nUsage: sudo python3 {sys.argv[0]} <idx|z> [count] [--prefix N]")
        sys.exit(0)

    arg   = args.idx_or_z
    count = args.count

    if arg == "z":
        send("zeros", _make_zero_payload(), count)
    else:
        idx = int(arg)
        if idx < 0 or idx >= len(items):
            print(f"idx must be 0..{len(items)-1}")
            sys.exit(1)
        label, token_ids = items[idx]

        if args.try_all_phases:
            print(f"[try-all-phases] '{label}'  sending prefix 0..31 sequentially")
            try_all_phases(token_ids)
        else:
            if args.prefix:
                print(f"  prefix={args.prefix} bytes (token starts at page offset O_icmp+{args.prefix})")
            send(label, _make_payload(token_ids, prefix=args.prefix), count)


if __name__ == "__main__":
    main()
