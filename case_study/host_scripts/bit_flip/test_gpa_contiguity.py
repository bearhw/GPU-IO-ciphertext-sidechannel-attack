#!/usr/bin/env python3
"""
test_gpa_contiguity.py — Measure GPA contiguity success rate under guest memory load.

Sends ICMP echo requests (8256B payload) to the guest VM and checks whether
the guest kernel's buddy allocator provides at least one fully-covered
4096-aligned interior page in the skb frag list.  Repeats under four guest
memory-pressure levels (Idle / Low / Medium / High) using stress-ng.

Output:
  gpa_contiguity_results.json   — per-trial raw data
  gpa_contiguity_summary.csv    — per-load-level summary (for charting)

Usage:
  sudo python3 test_gpa_contiguity.py                 # 50 trials per level
  sudo python3 test_gpa_contiguity.py --trials 10     # quick run
  sudo python3 test_gpa_contiguity.py --settle 15     # longer settle time
"""

import argparse
import csv
import json
import os
import re
import socket
import struct
import subprocess
import sys
import time
from pathlib import Path

# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------

DEST_IP          = "192.168.100.2"
GUEST_SSH        = "ubuntu@localhost"
GUEST_PORT       = "7777"
ICMP_PAYLOAD_SIZE = 8256
PAGE_SIZE         = 4096
ICMP_HOLD_SEC     = 7.0

_sudo_user = os.environ.get("SUDO_USER")
_ssh_key   = (Path(f"/home/{_sudo_user}/.ssh/id_ed25519")
              if _sudo_user else Path.home() / ".ssh/id_ed25519")
SSH_BASE = [
    "ssh", "-p", GUEST_PORT,
    "-i", str(_ssh_key),
    "-o", "StrictHostKeyChecking=no",
    "-o", "BatchMode=yes",
    "-o", "ConnectTimeout=30",
    GUEST_SSH,
]

HERE = Path(__file__).parent
RESULTS_JSON = HERE / "gpa_contiguity_results.json"
RESULTS_CSV  = HERE / "gpa_contiguity_summary.csv"

LOAD_LEVELS = [
    {
        "name": "Idle",
        "cmd": None,
    },
    {
        "name": "Low",
        "cmd": "stress-ng --vm 1 --vm-bytes 256M --vm-method all --timeout 0",
    },
    {
        "name": "Medium",
        "cmd": "stress-ng --vm 2 --vm-bytes 1G --vm-method all --timeout 0",
    },
    {
        "name": "High",
        "cmd": "stress-ng --vm 4 --vm-bytes 2G --vm-method all --timeout 0",
    },
]

FALLBACK_LOAD = [
    {
        "name": "Idle",
        "cmd": None,
    },
    {
        "name": "Low",
        "cmd": (
            "python3 -c \""
            "import mmap,os; "
            "mm=mmap.mmap(-1, 256*1024*1024); "
            "[mm.seek(i*4096) or mm.write(os.urandom(4096)) for i in range(256*256)]; "
            "import time; time.sleep(99999)\" &"
        ),
    },
    {
        "name": "Medium",
        "cmd": (
            "for i in 1 2; do python3 -c \""
            "import mmap,os; "
            "mm=mmap.mmap(-1, 1024*1024*1024); "
            "[mm.seek(i*4096) or mm.write(os.urandom(4096)) for i in range(1024*256)]; "
            "import time; time.sleep(99999)\" & done"
        ),
    },
    {
        "name": "High",
        "cmd": (
            "for i in 1 2 3 4; do python3 -c \""
            "import mmap,os; "
            "mm=mmap.mmap(-1, 2*1024*1024*1024); "
            "[mm.seek(i*4096) or mm.write(os.urandom(4096)) for i in range(2*1024*256)]; "
            "import time; time.sleep(99999)\" & done"
        ),
    },
]

# ---------------------------------------------------------------------------
# SSH / guest helpers
# ---------------------------------------------------------------------------

def ssh(cmd: str, timeout: int = 15) -> str:
    try:
        r = subprocess.run(SSH_BASE + [cmd], capture_output=True, text=True,
                           timeout=timeout)
        return r.stdout + r.stderr
    except subprocess.TimeoutExpired:
        return ""


def guest_alive() -> bool:
    try:
        r = subprocess.run(SSH_BASE + ["echo ok"], capture_output=True,
                           text=True, timeout=8)
        return r.returncode == 0 and "ok" in (r.stdout or "")
    except Exception:
        return False


def ensure_mtu_9000() -> None:
    r = subprocess.run(["ip", "route", "get", DEST_IP],
                       capture_output=True, text=True)
    m = re.search(r'\bdev\s+(\S+)', r.stdout)
    if m:
        host_iface = m.group(1)
        cur = subprocess.run(["ip", "link", "show", host_iface],
                             capture_output=True, text=True).stdout
        if "mtu 9000" not in cur:
            subprocess.run(["ip", "link", "set", host_iface, "mtu", "9000"],
                           check=True)
            print(f"[mtu] host {host_iface} -> 9000")
    out = ssh("ip -o addr show | awk '/192\\.168\\.100\\.2/{print $2}'")
    guest_iface = out.strip() or "enp0s4"
    result = ssh(f"ip link show {guest_iface}")
    if "mtu 9000" not in result:
        ssh(f"sudo ip link set {guest_iface} mtu 9000")
        print(f"[mtu] guest {guest_iface} -> 9000")


def drain_guest_rxbuf() -> None:
    ssh(
        "sudo python3 << 'EOF'\n"
        "import socket, select\n"
        "s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)\n"
        "s.setblocking(False)\n"
        "n = 0\n"
        "while select.select([s], [], [], 0.3)[0]:\n"
        "    try: s.recv(65536); n += 1\n"
        "    except OSError: break\n"
        "s.close()\nprint(f'drained {n}')\nEOF",
        timeout=20,
    )


def clear_icmp_frag_log() -> None:
    ssh("echo clear | sudo tee /proc/large_icmp_last >/dev/null 2>&1; "
        "sudo dmesg -C 2>/dev/null; true")


def read_icmp_frag_log() -> str:
    proc = ssh("cat /proc/large_icmp_last 2>/dev/null")
    if proc and "frag[" in proc:
        return proc
    dmesg = ssh("sudo dmesg")
    if dmesg and "frag[" in dmesg:
        return dmesg
    return proc or dmesg or ""


# ---------------------------------------------------------------------------
# ICMP send
# ---------------------------------------------------------------------------

def icmp_checksum(data: bytes) -> int:
    if len(data) & 1:
        data = data + b"\x00"
    s = sum(struct.unpack("!%dH" % (len(data) // 2), data))
    s = (s & 0xFFFF) + (s >> 16)
    s = (s & 0xFFFF) + (s >> 16)
    return (~s) & 0xFFFF


def send_icmp(payload: bytes) -> None:
    pid = os.getpid() & 0xFFFF
    hdr = struct.pack("!BBHHH", 8, 0, 0, pid, 0)
    chk = icmp_checksum(hdr + payload)
    hdr = struct.pack("!BBHHH", 8, 0, chk, pid, 0)
    s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
    try:
        s.sendto(hdr + payload, (DEST_IP, 0))
    finally:
        s.close()


# ---------------------------------------------------------------------------
# Interior page check
# ---------------------------------------------------------------------------

_FRAG_RE = re.compile(
    r"frag\[(\d+)\]:\s*compound_GPA=0x([0-9a-f]+)\s+off=(\d+)\s+size=(\d+)",
    re.IGNORECASE,
)


def count_interior_pages(frag_log: str) -> tuple[int, int, list]:
    """Parse frag log → (n_interior_pages, n_frags, frag_details).

    An interior page is a 4096-aligned page that is FULLY contained within
    the frag's payload region (compound_GPA + off ... compound_GPA + off + size).
    For frag[0], the first 8 bytes are the ICMP echo header and are excluded.
    """
    matches = _FRAG_RE.findall(frag_log)
    if not matches:
        return 0, 0, []

    frags = sorted(matches, key=lambda m: int(m[0]))
    total_interior = 0
    details = []

    for frag_idx_s, cgpa_s, off_s, size_s in frags:
        frag_idx = int(frag_idx_s)
        compound_gpa = int(cgpa_s, 16)
        off = int(off_s)
        size = int(size_s)

        header_skip = 8 if frag_idx == 0 and size > ICMP_PAYLOAD_SIZE else 0
        if frag_idx == 0 and size == ICMP_PAYLOAD_SIZE + 8:
            header_skip = 8

        payload_start = compound_gpa + off + header_skip
        payload_end   = compound_gpa + off + size

        first_page = payload_start // PAGE_SIZE
        last_page  = (payload_end - 1) // PAGE_SIZE
        n_interior = 0
        for p in range(first_page, last_page + 1):
            if p * PAGE_SIZE >= payload_start and (p + 1) * PAGE_SIZE <= payload_end:
                n_interior += 1

        total_interior += n_interior
        details.append({
            "frag": frag_idx,
            "compound_gpa": f"0x{compound_gpa:x}",
            "off": off,
            "size": size,
            "interior_pages": n_interior,
        })

    return total_interior, len(frags), details


# ---------------------------------------------------------------------------
# Guest load management
# ---------------------------------------------------------------------------

def check_stress_ng() -> bool:
    out = ssh("which stress-ng 2>/dev/null")
    return "stress-ng" in out


def start_guest_load(level: dict, use_fallback: bool) -> None:
    cmd = level["cmd"]
    if cmd is None:
        return
    if use_fallback:
        ssh(f"nohup bash -c '{cmd}' >/dev/null 2>&1 &", timeout=10)
    else:
        ssh(f"nohup {cmd} >/dev/null 2>&1 &", timeout=10)
    print(f"  [load] started: {level['name']}")


def stop_guest_load() -> None:
    ssh("sudo pkill -9 stress-ng 2>/dev/null; "
        "sudo pkill -9 -f 'mmap.*urandom' 2>/dev/null; "
        "true", timeout=10)
    time.sleep(2)


# ---------------------------------------------------------------------------
# Main experiment
# ---------------------------------------------------------------------------

def run_trial(trial_num: int) -> dict:
    """Send one ICMP, parse frags, return result dict."""
    drain_guest_rxbuf()
    clear_icmp_frag_log()

    payload = b"\x00" * ICMP_PAYLOAD_SIZE
    t0 = time.monotonic()
    send_icmp(payload)

    frag_log = ""
    for _ in range(8):
        time.sleep(0.15)
        frag_log = read_icmp_frag_log()
        if _FRAG_RE.search(frag_log):
            break

    elapsed = time.monotonic() - t0
    n_interior, n_frags, details = count_interior_pages(frag_log)
    success = n_interior >= 1

    return {
        "trial": trial_num,
        "success": success,
        "n_interior_pages": n_interior,
        "n_frags": n_frags,
        "elapsed_s": round(elapsed, 3),
        "frag_details": details,
    }


def run_experiment(n_trials: int, settle_s: int) -> None:
    print("[setup] Checking guest SSH...")
    if not guest_alive():
        print("[!] Guest unreachable. Aborting.", file=sys.stderr)
        sys.exit(1)

    ensure_mtu_9000()

    use_fallback = not check_stress_ng()
    if use_fallback:
        print("[setup] stress-ng not found on guest, using python mmap fallback")
    else:
        print("[setup] stress-ng available on guest")

    levels = FALLBACK_LOAD if use_fallback else LOAD_LEVELS
    all_results: dict[str, list] = {}
    summary_rows: list[dict] = []

    for level in levels:
        name = level["name"]
        print(f"\n{'='*60}")
        print(f"  Load level: {name}  ({n_trials} trials)")
        print(f"{'='*60}")

        stop_guest_load()
        start_guest_load(level, use_fallback)

        print(f"  [settle] waiting {settle_s}s for load to stabilize...")
        time.sleep(settle_s)

        if not guest_alive():
            print(f"  [!] Guest down under {name} load, skipping",
                  file=sys.stderr)
            stop_guest_load()
            summary_rows.append({
                "load_level": name,
                "trials": 0,
                "successes": 0,
                "failures": 0,
                "success_rate": 0.0,
                "avg_interior_pages": 0.0,
                "avg_frags": 0.0,
            })
            continue

        trials = []
        for t in range(n_trials):
            result = run_trial(t)
            trials.append(result)
            status = "OK" if result["success"] else "FAIL"
            print(f"  [{name}] trial {t+1:3d}/{n_trials}  "
                  f"{status}  interior={result['n_interior_pages']}  "
                  f"frags={result['n_frags']}  {result['elapsed_s']:.1f}s")
            time.sleep(ICMP_HOLD_SEC)

        stop_guest_load()

        successes = sum(1 for r in trials if r["success"])
        failures  = len(trials) - successes
        rate = successes / len(trials) * 100 if trials else 0
        avg_ip = (sum(r["n_interior_pages"] for r in trials) / len(trials)
                  if trials else 0)
        avg_fr = (sum(r["n_frags"] for r in trials) / len(trials)
                  if trials else 0)

        all_results[name] = trials
        summary_rows.append({
            "load_level": name,
            "trials": len(trials),
            "successes": successes,
            "failures": failures,
            "success_rate": round(rate, 1),
            "avg_interior_pages": round(avg_ip, 2),
            "avg_frags": round(avg_fr, 2),
        })

        print(f"\n  [{name}] Result: {successes}/{len(trials)} = {rate:.1f}%  "
              f"avg_interior={avg_ip:.2f}  avg_frags={avg_fr:.2f}")

    with open(RESULTS_JSON, "w") as f:
        json.dump(all_results, f, indent=2)
    print(f"\n[save] {RESULTS_JSON}")

    with open(RESULTS_CSV, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=[
            "load_level", "trials", "successes", "failures",
            "success_rate", "avg_interior_pages", "avg_frags",
        ])
        w.writeheader()
        w.writerows(summary_rows)
    print(f"[save] {RESULTS_CSV}")

    print(f"\n{'='*60}")
    print(f"  SUMMARY")
    print(f"{'='*60}")
    print(f"  {'Level':<10s} {'Trials':>6s} {'Success':>8s} {'Rate':>8s} "
          f"{'AvgPages':>9s} {'AvgFrags':>9s}")
    print(f"  {'-'*10} {'-'*6} {'-'*8} {'-'*8} {'-'*9} {'-'*9}")
    for row in summary_rows:
        print(f"  {row['load_level']:<10s} {row['trials']:>6d} "
              f"{row['successes']:>8d} {row['success_rate']:>7.1f}% "
              f"{row['avg_interior_pages']:>9.2f} {row['avg_frags']:>9.2f}")
    print(f"{'='*60}")


def main():
    p = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    p.add_argument("--trials", type=int, default=50,
                   help="Number of ICMP trials per load level (default: 50)")
    p.add_argument("--settle", type=int, default=10,
                   help="Seconds to wait after starting load (default: 10)")
    args = p.parse_args()

    run_experiment(args.trials, args.settle)


if __name__ == "__main__":
    main()
