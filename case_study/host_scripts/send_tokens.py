#!/usr/bin/env python3
"""
Send ICMP echo requests with int64 token IDs packed as little-endian int64
into the payload.  Payload is zero-padded to > 4 KB so that
guest_large_icmp_monitor.ko captures the GPA of the page holding the data.

Usage:
    sudo python3 send_tokens.py            # list all labels
    sudo python3 send_tokens.py <idx>      # send that label indefinitely (Ctrl-C to stop)
    sudo python3 send_tokens.py <idx> <n>  # send n packets then exit

Dest: 192.168.100.2 (guest TAP interface)
"""

import os
import struct
import socket
import sys
import time

DEST_IP        = "192.168.100.2"
PAYLOAD_SIZE   = 4097          # > 4 KB  →  triggers GPA page walk in guest module
# 2*4096+1 = 8191 is the minimum to mathematically guarantee some interior
# page is entirely covered by the payload regardless of alignment.
# 4097 (above) is NOT enough for that guarantee — see diagnose_zero_page.py.
# Kept just over that minimum (rather than orchestrate_v3.py's 3*4096
# margin) to stay under the MTU-9000 ceiling set by ensure_mtu_9000()
# (IP hdr 20B + ICMP hdr 8B + payload <= 9000) and avoid IP-level
# fragmentation — not a guaranteed-never, just fewer acquire_zero_gpa()
# retries in practice (see diagnose_zero_page.py / test_zero_gpa.py runs).
ZERO_PAYLOAD_SIZE = 8193
INTERVAL       = 1.0           # seconds between packets

TOKENS: dict[str, list[int]] = {
    "Chest pain":            [34, 6402, 6646],
    "Chest pain.":           [34, 6402, 6646, 13],
    "Shortness of breath":   [12472, 2090, 315, 11486],
    "Shortness of breath.":  [12472, 2090, 315, 11486, 13],
    "Cough":                 [34, 1384],
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


def _make_payload(token_ids: list[int]) -> bytes:
    token_bytes = struct.pack(f"<{len(token_ids)}q", *token_ids)
    return (token_bytes * (PAYLOAD_SIZE // len(token_bytes) + 1))[:PAYLOAD_SIZE]


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

def main() -> None:
    items = list(TOKENS.items())

    if len(sys.argv) < 2:
        print("Available labels:")
        for i, (label, ids) in enumerate(items):
            print(f"  {i}  {label!r:35s}  {ids}")
        print(f"  z  zeros (0x00 × {ZERO_PAYLOAD_SIZE})")
        print(f"\nUsage: sudo python3 {sys.argv[0]} <idx|z> [count]")
        sys.exit(0)

    arg = sys.argv[1]
    count = int(sys.argv[2]) if len(sys.argv) > 2 else 0

    if arg == "z":
        send("zeros", _make_zero_payload(), count)
    else:
        idx = int(arg)
        if idx < 0 or idx >= len(items):
            print(f"idx must be 0..{len(items)-1}")
            sys.exit(1)
        label, token_ids = items[idx]
        send(label, _make_payload(token_ids), count)


if __name__ == "__main__":
    main()
