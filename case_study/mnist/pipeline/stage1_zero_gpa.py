#!/usr/bin/env python3
"""
stage1_zero_gpa.py — Stage 1: Zero Page GPA Acquisition and Dump.

Acquires a verified all-zero page GPA from the guest ICMP kernel module,
dumps the zero page to z.out via read_gpa.py, and caches metadata in zero_gpa.json.

Usage:
    python3 stage1_zero_gpa.py [--output-dir .] [--force-refresh] [--zero-gpa 0x...]
"""

import argparse
import os
import re
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

ZERO_PAGE_SIZE = 4096


def clear_icmp_frag_log() -> None:
    """Reset guest frag snapshot in /proc/large_icmp_last and dmesg."""
    c.ssh_run("echo clear | sudo tee /proc/large_icmp_last >/dev/null 2>&1; "
              "sudo dmesg -C 2>/dev/null; true")


def read_icmp_frag_log() -> str:
    """Read snapshot from guest /proc/large_icmp_last or fallback to dmesg."""
    proc = c.ssh_run("cat /proc/large_icmp_last 2>/dev/null")
    if proc and "frag[" in proc:
        return proc
    dmesg = c.ssh_run("sudo dmesg 2>/dev/null")
    if dmesg and "frag[" in dmesg:
        return dmesg
    return proc or dmesg or ""


def acquire_zero_gpa(max_attempts: int = 5) -> int:
    """Send a large all-zero ICMP payload and return verified fully-covered GPA."""
    send_tokens_script = c.FLOW_DIR / "send_tokens.py"
    if not send_tokens_script.exists():
        send_tokens_script = c.HOST_SCRIPTS_DIR / "send_tokens.py"

    for attempt in range(1, max_attempts + 1):
        print(f"[stage1] Clearing guest ICMP log (attempt {attempt}/{max_attempts})...")
        clear_icmp_frag_log()

        print("[stage1] Sending zero ICMP token to guest...")
        subprocess.run([sys.executable, str(send_tokens_script), "z", "1"], check=True)

        out = ""
        for _ in range(20):
            time.sleep(0.25)
            out = read_icmp_frag_log()
            if re.search(r"frag\[\d+\]:\s*compound_GPA=", out or "", re.I):
                break
            if re.search(r"payload spans \d+ page", out or "", re.I):
                break

        print("[stage1] Parsing guest ICMP log...")
        candidates = []
        source = ""

        # Case 1: nonlinear skb — paged fragments
        frags = re.findall(
            r"frag\[(\d+)\]:\s*compound_GPA=0x([0-9a-f]+)\s+off=(\d+)\s+size=(\d+)",
            out, re.IGNORECASE)
        if frags:
            for i, (_fidx, cgpa_hex, off_s, size_s) in enumerate(frags):
                compound_gpa = int(cgpa_hex, 16)
                off, size = int(off_s), int(size_s)
                header_skip = 8 if i == 0 else 0
                frag_payload_start = compound_gpa + off + header_skip
                frag_payload_end = compound_gpa + off + size
                if frag_payload_end - frag_payload_start <= 0:
                    continue
                first_page = frag_payload_start // ZERO_PAGE_SIZE
                last_page = (frag_payload_end - 1) // ZERO_PAGE_SIZE
                for p in range(first_page, last_page + 1):
                    page_gpa = p * ZERO_PAGE_SIZE
                    if (page_gpa >= frag_payload_start and
                            page_gpa + ZERO_PAGE_SIZE <= frag_payload_end):
                        candidates.append(page_gpa)
            source = f"{len(frags)} frag(s), nonlinear skb"

        # Case 2: linear skb — contiguous virtual range
        if not candidates:
            m = re.search(r"payload spans (\d+) page\(s\)", out)
            if m:
                num_pages = int(m.group(1))
                pages = dict(re.findall(
                    r"page\[(\d+)\]:\s*virt=0x[0-9a-f]+\s+GPA=0x([0-9a-f]+)",
                    out, re.IGNORECASE))
                for i in range(1, num_pages - 1):  # strictly interior only
                    gpa_hex = pages.get(str(i))
                    if gpa_hex:
                        candidates.append(int(gpa_hex, 16))
                source = f"{num_pages} page(s), linear skb"

        if not candidates:
            snippet = "\n".join((out or "").strip().splitlines()[-6:])
            print(f"[!] No fully-covered zero page found on attempt {attempt}, retrying...", file=sys.stderr)
            if snippet:
                print(f"[!] guest log tail:\n{snippet}", file=sys.stderr)
            continue

        gpa = candidates[0]
        print(f"[stage1] SUCCESS: zero_gpa = 0x{gpa:x} ({source}, {len(candidates)} candidate(s))")
        return gpa

    print(f"[!] Failed to acquire verified zero page after {max_attempts} attempts", file=sys.stderr)
    sys.exit(1)


def dump_zero_page(zero_gpa: int, zero_out: Path):
    """Dump zero page directly via QEMU HMP socket."""
    import socket
    monitor_sock = "/tmp/qemu-monitor.sock"
    qemu_prompt = b"(qemu) "

    print(f"[stage1] Dumping zero page 0x{zero_gpa:x} → {zero_out}")
    sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    sock.settimeout(60)
    sock.connect(monitor_sock)
    buf = b""
    while qemu_prompt not in buf:
        chunk = sock.recv(65536)
        if not chunk:
            break
        buf += chunk
    sock.sendall(f"xp /512gx 0x{zero_gpa:x}\n".encode())
    buf = b""
    while qemu_prompt not in buf:
        chunk = sock.recv(65536)
        if not chunk:
            break
        buf += chunk
    sock.close()

    raw_text = buf.decode(errors="replace")
    zero_out.parent.mkdir(parents=True, exist_ok=True)
    zero_out.write_text(raw_text)
    print(f"[stage1] Successfully saved {len(raw_text.splitlines())} lines → {zero_out}")

    # Also keep c.FLOW_DIR and c.HOST_SCRIPTS_DIR synchronized
    try:
        (c.FLOW_DIR / "z.out").write_text(raw_text)
        (c.HOST_SCRIPTS_DIR / "z.out").write_text(raw_text)
    except Exception:
        pass


def run_stage1(output_dir: Path, zero_gpa_override: int = None,
               force_refresh: bool = False, max_attempts: int = 5) -> dict:
    dumps_dir, logs_dir, results_dir = c.get_output_subdirs(output_dir)
    json_path = results_dir / "zero_gpa.json"
    zero_out  = dumps_dir / "z.out"

    # Also check base output_dir for existing cache
    if not force_refresh and zero_gpa_override is None:
        for candidate_json in [json_path, output_dir / "zero_gpa.json"]:
            for candidate_out in [zero_out, output_dir / "z.out"]:
                if candidate_json.exists() and candidate_out.exists():
                    try:
                        cached = c.load_json(candidate_json)
                        print(f"[stage1] Reusing cached zero_gpa: {cached.get('zero_gpa')} from {candidate_json.name}")
                        return cached
                    except Exception:
                        pass

    c.ensure_guest_suppressions()
    c.ensure_mtu_9000()

    if zero_gpa_override is not None:
        zero_gpa = zero_gpa_override
        print(f"[stage1] Using user-provided zero_gpa: 0x{zero_gpa:x}")
    else:
        zero_gpa = acquire_zero_gpa(max_attempts=max_attempts)

    dump_zero_page(zero_gpa, zero_out)

    meta = {
        "stage": 1,
        "zero_gpa": f"0x{zero_gpa:x}",
        "zero_gpa_int": zero_gpa,
        "zero_out": str(zero_out),
        "timestamp": time.time(),
    }
    c.save_json(json_path, meta)
    print(f"[stage1] Saved zero page metadata → {json_path}")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save zero_gpa.json and z.out")
    p.add_argument("--zero-gpa", default=None, help="Explicit zero GPA override (hex)")
    p.add_argument("--force-refresh", action="store_true", help="Force re-acquisition even if cached")
    p.add_argument("--max-attempts", type=int, default=5, help="Max ICMP acquisition attempts")
    args = p.parse_args()

    gpa_override = int(args.zero_gpa, 16) if args.zero_gpa else None
    run_stage1(Path(args.output_dir), zero_gpa_override=gpa_override,
               force_refresh=args.force_refresh, max_attempts=args.max_attempts)


if __name__ == "__main__":
    main()
