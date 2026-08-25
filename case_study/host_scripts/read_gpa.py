#!/usr/bin/env python3
"""
Read xp /512gx <GPA> from QEMU HMP monitor and save raw output to <idx>.out.

Usage:
    python3 read_gpa.py <idx> <GPA_hex>
    e.g.:  python3 read_gpa.py 0 0x10a003000
           → saves raw xp output to 0.out
"""

import socket
import sys
from pathlib import Path

MONITOR_SOCK  = "/tmp/qemu-monitor.sock"
QEMU_PROMPT   = b"(qemu) "


def _recv_until_prompt(sock: socket.socket) -> str:
    buf = b""
    while QEMU_PROMPT not in buf:
        chunk = sock.recv(65536)
        if not chunk:
            break
        buf += chunk
    return buf.decode(errors="replace")


def read_page(gpa: int) -> str:
    sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    sock.settimeout(60)
    sock.connect(MONITOR_SOCK)
    _recv_until_prompt(sock)
    sock.sendall(f"xp /512gx 0x{gpa:x}\n".encode())
    raw = _recv_until_prompt(sock)
    sock.close()
    return raw


def main() -> None:
    if len(sys.argv) < 3:
        print(f"Usage: python3 {sys.argv[0]} <idx> <GPA_hex>")
        print( "  e.g.: python3 read_gpa.py 0 0x10a003000")
        sys.exit(1)

    idx = sys.argv[1]
    gpa = int(sys.argv[2], 16)
    out_path = Path(__file__).parent / f"{idx}.out"

    print(f"xp /512gx 0x{gpa:x}")
    raw = read_page(gpa)
    out_path.write_text(raw)
    print(f"saved → {out_path}")


if __name__ == "__main__":
    main()
