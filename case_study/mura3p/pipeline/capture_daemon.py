#!/usr/bin/env python3
"""
capture_daemon.py — unattended MURA 3-plane (mura3p) capture with guest recovery.

For each index: health check -> master_orchestrate.run_one (subprocess, timeout).
The guest is considered dead when ssh fails or its console (BOOT_LOG, new bytes
since this boot) shows an oops/panic. Recovery: stop OUR QEMU only (its monitor
socket, then SIGKILL of the pid that owns that socket), boot_guest.sh (drops the
page cache first so the 256 GB boot takes minutes, not half an hour), network
preflight, GPU CC ready state, scratch holder, and a fresh dictionary (the VEK
changes with every boot). The dictionary of each boot is snapshotted next to the
captures so dumps can be re-decoded later.

  sudo /home/eun/miniforge3/bin/python3 -u capture_daemon.py --split valid --indices-file valid_order.txt
"""
import argparse
import csv
import os
import re
import shutil
import socket
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c
import master_orchestrate as mo

PY = "/home/eun/miniforge3/bin/python3"
BOOT_LOG = Path("/tmp/mura_vm_boot.log")
MON = "/tmp/qemu-monitor.sock"
PREFLIGHT = "/home/eun/proof_code/llm/net_preflight.sh"
OOPS_RE = re.compile(r"general protection fault|BUG: |Oops: |Kernel panic|soft lockup|hard LOCKUP|"
                     r"blocked for more than|list_(add|del) corruption|kernel BUG at")
SAMPLE_TIMEOUT = 1200
_boot_off = 0


def log(msg):
    print(f"[daemon {time.strftime('%m-%d %H:%M:%S')}] {msg}", flush=True)


def our_qemu():
    out = subprocess.run(["pgrep", "-f", f"qemu-system-x86.*{MON}"], capture_output=True, text=True).stdout
    p = [int(x) for x in out.split()]
    return p[0] if p else None


def console_oops():
    try:
        with open(BOOT_LOG, "rb") as f:
            f.seek(_boot_off)
            m = OOPS_RE.search(f.read().decode("latin1"))
        return m.group(0) if m else None
    except FileNotFoundError:
        return None


def guest_ok():
    """Dead = oops on the console, or ssh failing for a minute. A single ssh
    timeout is not death: the ICMP monitor's 6 s hold and heavy page-move
    bursts stall sshd briefly (11-12 21:22 rebooted a healthy guest)."""
    if console_oops():
        return False
    for _ in range(4):
        if "OK" in c.ssh_run("echo OK", timeout=20):
            return True
        time.sleep(10)
    return False


def stop_vm():
    pid = our_qemu()
    if not pid:
        return
    try:
        s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        s.settimeout(5)
        s.connect(MON)
        time.sleep(0.2)
        s.recv(4096)
        s.sendall(b"quit\n")
        time.sleep(1)
    except Exception:
        pass
    for _ in range(90):
        if not Path(f"/proc/{pid}").exists():
            return
        time.sleep(1)
    log(f"QEMU {pid} ignored quit — SIGKILL")
    os.kill(pid, 9)
    while Path(f"/proc/{pid}").exists():
        time.sleep(1)


def recover(out: Path) -> bool:
    global _boot_off
    oops = console_oops()
    if oops:
        crash = HERE / "guest_crashes" / f"console_{time.strftime('%Y%m%d_%H%M%S')}.log"
        crash.parent.mkdir(exist_ok=True)
        with open(BOOT_LOG, "rb") as f:
            f.seek(_boot_off)
            crash.write_bytes(f.read())
        log(f"guest oops ({oops}) — console saved to {crash.name}")
    stop_vm()
    _boot_off = BOOT_LOG.stat().st_size if BOOT_LOG.exists() else 0
    t0 = time.time()
    r = subprocess.run(["bash", str(HERE / "boot_guest.sh")], capture_output=True, text=True)
    log(f"boot: {(r.stdout + r.stderr).strip()} ({time.time() - t0:.0f}s)")
    if r.returncode != 0:
        return False
    return rebuild_dict(out)


GUEST_FILES = {  # guest path (relative to GUEST_DIR) -> host source
    "guest_mura3p_loader.py": HERE.parent / "victim" / "guest_mura3p_loader.py",
    "guest_scratch_holder.py": HERE.parent / "victim" / "guest_scratch_holder.py",
}


def sync_guest_files():
    """A guest panic during writeback corrupted files on the guest disk (11-12:
    victim checkpoint and a dataset). Compare md5s after every boot, re-copy."""
    import hashlib
    c.ssh_run(f"mkdir -p {c.GUEST_DIR}", timeout=30)
    for rel, src in GUEST_FILES.items():
        want = hashlib.md5(src.read_bytes()).hexdigest()
        have = c.ssh_run(f"md5sum {c.GUEST_DIR}/{rel} 2>/dev/null", timeout=60).split()[:1]
        if have != [want]:
            subprocess.run(["scp", "-q", "-P", c.GUEST_PORT, "-i", str(c._ssh_key),
                            "-o", "StrictHostKeyChecking=no", "-o", "UserKnownHostsFile=/dev/null",
                            "-o", "LogLevel=ERROR", str(src), f"{c.GUEST_SSH}:{c.GUEST_DIR}/{rel}"])
            log(f"re-copied {rel} to the guest")
    c.ssh_run("sync", timeout=60)


def ensure_server() -> bool:
    """Start the resident victim if its socket is missing; wait for SERVER_READY."""
    if "yes" in c.ssh_run("test -S /tmp/shapes_victim.sock && pgrep -f '[g]uest_shapes_server.py serve' >/dev/null && echo yes"):
        return True
    # Separate calls: a pkill pattern in the same shell line as the start command
    # matches that shell itself and kills it before the server starts.
    c.ssh_run("sudo pkill -f '[g]uest_shapes_server.py serve'", timeout=20)
    c.ssh_run(f"cd {c.GUEST_DIR} && sudo nohup {c.GUEST_PY} -u guest_shapes_server.py serve "
              "> /tmp/shapes_server.log 2>&1 < /dev/null &", timeout=20)
    for _ in range(60):
        if "SERVER_READY" in c.ssh_run("cat /tmp/shapes_server.log 2>/dev/null"):
            log("victim server ready")
            return True
        time.sleep(5)
    log("[!] victim server did not come up: " + c.ssh_run("tail -3 /tmp/shapes_server.log")[-200:])
    return False


def rebuild_dict(out: Path) -> bool:
    subprocess.run(["bash", PREFLIGHT], capture_output=True, text=True)
    sync_guest_files()
    if c.USE_SERVER:
        c.ssh_run("sudo nvidia-smi conf-compute -srs 1", timeout=60)
        ensure_server()
    c.ssh_run("sudo nvidia-smi conf-compute -srs 1", timeout=60)
    t0 = time.time()
    r = subprocess.run([PY, "-u", str(HERE / "stage1_ref_dict.py"), "--rebuild",
                        "--output-dir", str(HERE)], capture_output=True, text=True)
    tail = (r.stdout.strip().splitlines() or ["?"])[-1]
    log(f"dictionary: {tail} ({time.time() - t0:.0f}s)")
    bid = c.ssh_run("cat /proc/sys/kernel/random/boot_id").strip()[:8]
    snap = out / f"dict_{time.strftime('%m%d_%H%M')}_{bid}"
    shutil.copytree(c.DICT_DIR, snap / "dict_pages_m3", dirs_exist_ok=True)
    shutil.copy(c.DICT_CACHE_FILE, snap / "dict_cache_m3.json")
    m = re.search(r"(\d+)/(\d+) usable", tail)
    return r.returncode == 0 and bool(m) and m.group(1) == m.group(2) == str(3 * c.NUM_REFS)


def main():
    global _boot_off
    p = argparse.ArgumentParser()
    p.add_argument("--split", default="valid", choices=["valid", "train"])
    p.add_argument("--indices", default=None)
    p.add_argument("--indices-file", default=None, help="one index per line, capture order")
    p.add_argument("--gt", action="store_true")
    p.add_argument("--gpu", action="store_true")
    p.add_argument("--output-dir", default=None)
    p.add_argument("--fresh-dict", action="store_true", help="rebuild the dictionary before starting")
    a = p.parse_args()
    out = Path(a.output_dir or HERE.parent / "captures" / f"{a.split}_{'gt' if a.gt else 'blind'}")
    out.mkdir(parents=True, exist_ok=True)
    # Only oopses after the daemon starts count; older ones belong to past boots.
    _boot_off = BOOT_LOG.stat().st_size if BOOT_LOG.exists() else 0
    idx = ([int(l) for l in open(a.indices_file) if l.strip()] if a.indices_file
           else mo.parse_indices(a.indices))
    todo = [i for i in idx if i not in mo.done_set(out / "summary.csv")]
    log(f"{len(todo)} sample(s) to capture -> {out}")
    if not guest_ok():
        while not recover(out):
            log("recovery failed — retrying in 60s")
            time.sleep(60)
    elif a.fresh_dict:
        # A failed build usually means the guest wedged mid-build (11-14 12:10:
        # stage1 stopped at 108/192, sshd hung, no console oops). Rebuilding on
        # that guest only loops; reboot it when it no longer answers.
        while not rebuild_dict(out):
            if not guest_ok():
                log("dictionary failed and guest unhealthy — recovering")
                while not recover(out):
                    log("recovery failed — retrying in 60s")
                    time.sleep(60)
                break
            log("dictionary failed — retrying in 60s")
            time.sleep(60)
    fails = {}
    for idx in todo:
        while not guest_ok() or (c.USE_SERVER and not ensure_server()):
            log("guest unhealthy — recovering")
            while not recover(out):
                time.sleep(60)
        cmd = [PY, "-u", str(HERE / "master_orchestrate.py"), "--split", a.split,
               "--indices", str(idx), "--output-dir", str(out)] + \
              (["--gt"] if a.gt else []) + (["--gpu"] if a.gpu else [])
        t0 = time.time()
        try:
            r = subprocess.run(cmd, capture_output=True, text=True, timeout=SAMPLE_TIMEOUT)
            last = [l for l in r.stdout.splitlines() if l.startswith("[master]")]
            log(last[-1] if last else f"#{idx}: no result line (rc={r.returncode})")
        except subprocess.TimeoutExpired:
            log(f"#{idx}: timed out after {SAMPLE_TIMEOUT}s")
        if console_oops() or not guest_ok():
            fails[idx] = fails.get(idx, 0) + 1
            log(f"#{idx}: guest died during the sample ({time.time() - t0:.0f}s)")
    rows = list(csv.DictReader(open(out / "summary.csv"))) if (out / "summary.csv").exists() else []
    ok = [r for r in rows if not r.get("error")]
    acc = sum(r["correct"] == "True" for r in ok)
    log(f"done: {len(ok)} captured, top-1 {acc}/{len(ok)}")


if __name__ == "__main__":
    main()
