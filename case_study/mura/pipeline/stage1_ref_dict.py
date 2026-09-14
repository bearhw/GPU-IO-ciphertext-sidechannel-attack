#!/usr/bin/env python3
"""
stage1_ref_dict.py — Stage 1: Reference Dictionary & Fixed GPA Management.

Acquires / verifies FIXED_GPA and 64 reference pages (ref-16, ref-32, ref-64)
injected with normalized MURA pixel levels. Dumps the reference pages to
dict_pages_mura/ and outputs ref_dict.json for downstream stages.

Usage:
    sudo python3 stage1_ref_dict.py [--rebuild] [--output-dir .]
"""

import argparse
import ctypes
import fcntl
import json
import os
import re
import socket
import struct
import subprocess
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional, Tuple

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

_KVMIO = 0xAE
KVM_READ_PAGE_DUMP = (0x80000000 | ((c.PAGE_SIZE & 0x3FFF) << 16) | (_KVMIO << 8) | 0x2b)
PAYLOAD_SIZE = 8193
_ICMP_HOLD_SEC = 7.0
_last_icmp_mono: float = 0.0


def _bytes_to_xp(gpa: int, raw: bytes) -> str:
    lines = [f"(qemu) xp /512gx 0x{gpa:x}"]
    for i in range(0, c.PAGE_SIZE, 16):
        lo = int.from_bytes(raw[i:i+8], "little")
        hi = int.from_bytes(raw[i+8:i+16], "little")
        lines.append(f"{gpa+i:016x}: 0x{lo:016x} 0x{hi:016x}")
    return "\n".join(lines)


def do_swap_read(dict_gpa: int, src_gpa: int, out_path: Path,
                 swap_tool: Path = c.SWAP_TOOL_PATH,
                 kvm_dev: str = "/dev/kvm") -> None:
    """Perform PSP swap-back and read kernel dump to output file."""
    rc = subprocess.run([str(swap_tool), f"0x{dict_gpa:x}", f"0x{src_gpa:x}", "--swap-back"]).returncode
    if rc != 0:
        print(f"[stage1] [!] swap_pages_tool failed (exit {rc})", file=sys.stderr)
        raise RuntimeError("swap_pages_tool failed")

    kvm_fd = os.open(kvm_dev, os.O_RDWR | os.O_CLOEXEC)
    try:
        buf = ctypes.create_string_buffer(c.PAGE_SIZE)
        fcntl.ioctl(kvm_fd, KVM_READ_PAGE_DUMP, buf)
        raw = bytes(buf)
    finally:
        os.close(kvm_fd)

    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(_bytes_to_xp(dict_gpa, raw) + "\n")


def _checksum(data: bytes) -> int:
    s = 0
    for i in range(0, len(data) - 1, 2):
        s += (data[i+1] << 8) + data[i]
    if len(data) & 1:
        s += data[-1]
    s = (s >> 16) + (s & 0xFFFF)
    s += s >> 16
    return ~s & 0xFFFF


def _send_icmp_payload(payload: bytes):
    global _last_icmp_mono
    if _last_icmp_mono > 0:
        wait = _ICMP_HOLD_SEC - (time.monotonic() - _last_icmp_mono)
        if wait > 0:
            time.sleep(wait)

    pid = os.getpid() & 0xFFFF
    hdr = struct.pack("!BBHHH", 8, 0, 0, pid, 0)
    chk = _checksum(hdr + payload)
    hdr = struct.pack("!BBHHH", 8, 0, chk, pid, 0)
    sock = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
    try:
        sock.sendto(hdr + payload, ("192.168.100.2", 0))
    finally:
        sock.close()
    _last_icmp_mono = time.monotonic()


def acquire_gpa(u8_val: Optional[int], chunk_bytes: Optional[bytes] = None, retries: int = 5) -> int:
    """Acquire page[1] GPA via ICMP injection."""
    def _read_icmp():
        proc = c.ssh_run("cat /proc/large_icmp_last 2>/dev/null")
        if proc and "frag[" in proc:
            return proc
        dmesg = c.ssh_run("sudo dmesg")
        return dmesg if (dmesg and "frag[" in dmesg) else (proc or "")

    def _clear_icmp():
        c.ssh_run("echo clear | sudo tee /proc/large_icmp_last >/dev/null 2>&1; sudo dmesg -C 2>/dev/null; true")

    def _parse_frag_p1(out: str):
        m = re.search(r"frag\[0\].*?\boff=(\d+)", out)
        return (c.PAGE_SIZE - (int(m.group(1)) % c.PAGE_SIZE) - 8) if m else None

    def _parse_sub_page1_gpa(out: str):
        m = re.search(r"frag\[0\].*?compound_GPA=0x([0-9a-f]+).*?\boff=(\d+)", out, re.IGNORECASE)
        if not m:
            return None
        compound_gpa = int(m.group(1), 16)
        frag_off = int(m.group(2))
        return compound_gpa + ((frag_off // c.PAGE_SIZE) + 1) * c.PAGE_SIZE

    probe = b"\x00" * PAYLOAD_SIZE
    for attempt in range(retries):
        _clear_icmp()
        _send_icmp_payload(probe)
        time.sleep(1.0)
        out1 = _read_icmp()
        fp1_a = _parse_frag_p1(out1)

        _clear_icmp()
        _send_icmp_payload(probe)
        time.sleep(1.0)
        out2 = _read_icmp()
        fp1_b = _parse_frag_p1(out2)

        if fp1_a is None or fp1_b is None:
            time.sleep(5)
            continue

        delta = (fp1_a - fp1_b) % c.PAGE_SIZE
        expected_frag = (fp1_b - delta) % c.PAGE_SIZE

        # Aligned send
        content_size = PAYLOAD_SIZE - expected_frag
        if u8_val is None and chunk_bytes is None:
            content = b"\x00" * content_size
        else:
            chunk = chunk_bytes if chunk_bytes is not None else c.chunk16(u8_val, "R")
            content = (chunk * (content_size // c.CHUNK_SIZE + 1))[:content_size]

        payload = b"\x00" * expected_frag + content
        _clear_icmp()
        _send_icmp_payload(payload)
        time.sleep(1.0)

        for _ in range(3):
            out = _read_icmp()
            gpa = _parse_sub_page1_gpa(out)
            if gpa is not None:
                return gpa
            time.sleep(2)

    raise RuntimeError("acquire_gpa: failed after retries")


def run_stage1(output_dir: Path, rebuild: bool = False, channels: Tuple[str, ...] = ("R",)) -> Dict:
    """Execute Stage 1."""
    output_dir.mkdir(parents=True, exist_ok=True)
    json_path = output_dir / "ref_dict.json"

    c.ensure_guest_suppressions()
    c.ensure_mtu_9000()

    dict_dir = c.DICT_DIR
    dict_dir.mkdir(parents=True, exist_ok=True)

    cache: Dict = {"fixed_gpa": None, "refs": {}}
    if c.DICT_CACHE_FILE.exists() and not rebuild:
        try:
            cache = c.load_json(c.DICT_CACHE_FILE)
            print(f"[stage1] Loaded cache from {c.DICT_CACHE_FILE}")
        except Exception:
            pass

    # Verify or acquire FIXED_GPA
    if not cache.get("fixed_gpa") or rebuild:
        print("[stage1] Acquiring clean FIXED_GPA via Zero ICMP...")
        fixed_gpa = acquire_gpa(None)
        cache["fixed_gpa"] = hex(fixed_gpa)
        c.save_json(c.DICT_CACHE_FILE, cache)
    else:
        fixed_gpa = int(cache["fixed_gpa"], 16)
    print(f"[stage1] FIXED_GPA = 0x{fixed_gpa:x}")

    # Check available ref dumps
    available_refs = {}
    missing_refs = []
    for u8 in c.REF_U8_64:
        ref_file = dict_dir / f"ref_{u8:03d}.out"
        if ref_file.exists() and not rebuild:
            available_refs[str(u8)] = {
                "u8": u8,
                "file": str(ref_file),
                "ref_gpa": cache.get("refs", {}).get(str(u8), {}).get("ref_gpa", "0x0"),
            }
        else:
            missing_refs.append(u8)

    print(f"[stage1] Available ref page dumps: {len(available_refs)}/{len(c.REF_U8_64)}")

    if missing_refs and rebuild:
        print(f"[stage1] Rebuilding {len(missing_refs)} missing reference dumps...")
        for idx, u8 in enumerate(missing_refs):
            chunk = c.chunk16(u8, "R")
            ref_gpa = acquire_gpa(u8, chunk_bytes=chunk)
            out_file = dict_dir / f"ref_{u8:03d}.out"
            print(f"  [{idx+1}/{len(missing_refs)}] u8={u8:3d} GPA=0x{ref_gpa:x} → {out_file.name}")
            do_swap_read(fixed_gpa, ref_gpa, out_file)
            time.sleep(1.0)
            available_refs[str(u8)] = {
                "u8": u8,
                "file": str(out_file),
                "ref_gpa": hex(ref_gpa),
            }
            cache.setdefault("refs", {})[str(u8)] = {
                "ref_gpa": hex(ref_gpa),
                "fixed_gpa": hex(fixed_gpa),
                "file": str(out_file),
            }
            c.save_json(c.DICT_CACHE_FILE, cache)

    meta = {
        "stage": 1,
        "fixed_gpa": hex(fixed_gpa),
        "fixed_gpa_int": fixed_gpa,
        "num_refs": len(c.REF_U8_64),
        "available_refs_count": len(available_refs),
        "ref_list": c.REF_U8_64,
        "dict_dir": str(dict_dir),
        "timestamp": time.time(),
    }
    c.save_json(json_path, meta)
    print(f"[stage1] Saved reference dictionary metadata → {json_path}")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--rebuild", action="store_true", help="Force rebuilding ref dictionary via ICMP")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save ref_dict.json")
    args = p.parse_args()

    run_stage1(Path(args.output_dir), rebuild=args.rebuild)


if __name__ == "__main__":
    main()
