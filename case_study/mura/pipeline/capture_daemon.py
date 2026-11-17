#!/usr/bin/env python3
"""
capture_daemon.py — Keep a long capture run going across guest reboots.

A full-split capture takes days, and the guest does not survive that: it hangs,
reboots, or loses the pieces the attack depends on. Every one of those has cost a
run in practice, silently, and the numbers that came out afterwards meant nothing.
So this supervises rather than trusts — it checks the guest before each chunk,
repairs what it can, rebuilds the dictionary whenever the guest's boot id changes
(a new VM means a new VEK, so every reference page is stale), and resumes from the
last index the CSV actually recorded.

Usage:
    sudo python3 capture_daemon.py --split train --end 36808
    sudo python3 capture_daemon.py --split train --end 36808 --chunk 50 --dry-run
"""

import argparse
import atexit
import csv
from collections import Counter
import fcntl
import json
import os
import re
import signal
import subprocess
import sys
import time
from datetime import datetime
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

PY = "/home/eun/miniforge3/bin/python3"
LOCKFILE = HERE / ".capture_daemon.lock"

# The child that is running right now (stage1 build or a capture chunk). It and its
# own children (master_orchestrate -> stage1/swap_pages_tool) run in a fresh process
# group, so a single killpg takes the whole subtree down. Leaving them behind is
# what let orphaned ICMP/PSP traffic keep hammering the host until it rebooted.
_CURRENT_CHILD = None
_LOCK_FH = None


def _run_tracked(cmd, **kw):
    """Run a child in its own process group, remembering it so a signal can reap
    the entire subtree instead of just the top process."""
    global _CURRENT_CHILD
    p = subprocess.Popen(cmd, start_new_session=True, **kw)
    _CURRENT_CHILD = p
    try:
        return p.wait()
    finally:
        _CURRENT_CHILD = None


def _reap_child():
    """Terminate the current child's whole process group (SIGTERM, then SIGKILL)."""
    p = _CURRENT_CHILD
    if p is None or p.poll() is not None:
        return
    try:
        pgid = os.getpgid(p.pid)
    except ProcessLookupError:
        return
    for sig in (signal.SIGTERM, signal.SIGKILL):
        try:
            os.killpg(pgid, sig)
        except ProcessLookupError:
            return
        for _ in range(10):
            time.sleep(0.5)
            if p.poll() is not None:
                return


def _on_signal(signum, frame):
    log(f"received signal {signum} — reaping child process group and exiting")
    _reap_child()
    sys.exit(128 + signum)
GUEST_MODULE = "/home/ubuntu/guest_large_icmp_monitor.ko"
GUEST_IFACE = "enp0s4"
GUEST_IP = "192.168.100.2/24"
BOOT_WAIT_SEC = 240
BOOT_LOG = "/tmp/mura_vm_boot.log"
# Checks the whole packet path, host side included: a single QEMU, a live HMP
# monitor, tap0 up with the right route, the guest NIC, the monitor module, and
# finally a real oversized probe that must produce frag[N] on the guest. Doing
# only the guest half misses tap0, and then ICMP leaves via the physical NIC and
# never arrives — which looks exactly like a guest that is merely not ready.
PREFLIGHT = "/home/eun/proof_code/llm/net_preflight.sh"
SNAP_ROOT = HERE / "dict_snapshots"
HOST_BOOT_MARK = HERE / ".host_boot_id"
GPU_BDF = os.environ.get("MURA_GPU_BDF", "0000:61:00.0")
GPU_ID = os.environ.get("MURA_GPU_ID", "10de 2331")
CAPTURE_ROOT = HERE / "captures"
MAX_LOADERS = 6
DRY = False        # --dry-run must not touch the guest, only report what it would do


def _would(action: str) -> bool:
    """True when the caller should skip a guest-changing action under --dry-run."""
    if DRY:
        log(f"[dry-run] would {action}")
        return True
    return False


def log(msg: str):
    print(f"[daemon {datetime.now().strftime('%H:%M:%S')}] {msg}", flush=True)


def guest(cmd: str, timeout: int = 20) -> str:
    return c.ssh_run(cmd, timeout=timeout)


def guest_up() -> bool:
    return "DAEMON_OK" in guest("echo DAEMON_OK", timeout=15)


_UUID_RE = re.compile(r"[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}")


def boot_id() -> str:
    """Identifies the VM instance. A change means every reference page is stale.

    ssh_run merges stderr into its result, so an SSH warning lands in the value and
    then in snapshot directory names — which, containing slashes, silently produced
    a nested tree instead of one directory. Take only the UUID.
    """
    m = _UUID_RE.search(guest("cat /proc/sys/kernel/random/boot_id 2>/dev/null"))
    return m.group(0) if m else ""


def wait_for_guest(deadline_sec: int = BOOT_WAIT_SEC) -> bool:
    end = time.time() + deadline_sec
    while time.time() < end:
        if guest_up():
            return True
        time.sleep(10)
    return False


def start_vm(launch_script: str, launch_args: str) -> bool:
    script = launch_script.split()[0]
    if not Path(script).exists():
        log(f"[!] launch script {script} not found — start the VM yourself")
        return False
    argv = ["setsid", "bash", script] + (launch_args.split() if launch_args else [])
    if _would(f"boot the guest via {' '.join(argv[2:])}"):
        return False

    # A wedged QEMU still holds the passed-through GPU and the monitor socket, so a
    # fresh launch cannot succeed until it is gone. The guest was already found
    # unreachable, so anything still running here is not serving us.
    if qemu_pids():
        log(f"clearing {len(qemu_pids())} QEMU process(es): {' '.join(qemu_pids())}")
        how = stop_vm()
        log(f"guest stopped by: {how}")
        if "synced" in how and not image_ok():
            return False
    for sock in ("/tmp/qemu-monitor.sock", "/tmp/qmp-sock"):
        # QEMU cannot be relinked to an existing path; a leftover file makes the
        # monitor check fail against a socket nothing is listening on.
        Path(sock).unlink(missing_ok=True)
    log(f"booting the guest: {' '.join(argv[2:])} (log: {BOOT_LOG})")
    # Keep the boot output. Discarding it is why a wrong launch script looked
    # identical to a guest that simply never came up.
    with open(BOOT_LOG, "ab") as lf:
        lf.write(f"\n===== boot attempt {datetime.now()} =====\n".encode())
        subprocess.Popen(argv, stdout=lf, stderr=subprocess.STDOUT,
                         stdin=subprocess.DEVNULL)
    if wait_for_guest():
        return True
    log(f"[!] guest did not answer on port {c.GUEST_PORT} within {BOOT_WAIT_SEC}s")
    try:
        tail = Path(BOOT_LOG).read_text(errors="ignore").splitlines()[-6:]
        for line in tail:
            log(f"    boot| {line[:120]}")
    except Exception:
        pass
    return False


def host_boot_id() -> str:
    try:
        return Path("/proc/sys/kernel/random/boot_id").read_text().strip()
    except Exception:
        return ""


def gpu_driver() -> str:
    out = subprocess.run(["lspci", "-k", "-s", GPU_BDF],
                         capture_output=True, text=True).stdout
    for line in out.splitlines():
        if "Kernel driver in use:" in line:
            return line.split(":", 1)[1].strip()
    return ""


def prepare_host() -> bool:
    """Re-attach the passed-through GPU to vfio-pci after a host reboot.

    The binding does not survive a host restart, and QEMU then fails to claim the
    device — which looks like a VM that simply will not boot. Run once per host
    boot rather than per launch, so a working binding is never torn down.
    """
    drv = gpu_driver()
    log(f"host boot: GPU {GPU_BDF} driver = {drv or '(none)'}")
    if _would("rebind the GPU to vfio-pci"):
        return True

    if drv == "vfio-pci" and qemu_pids():
        # A running VM holds the device; unbinding it now would kill the guest we
        # are in the middle of capturing from, for no gain.
        log("GPU already on vfio-pci and a VM is using it — leaving the binding alone")
        return True

    def sh(cmd: str):
        return subprocess.run(["sh", "-c", cmd], capture_output=True, text=True)

    if drv == "vfio-pci":
        sh(f"echo {GPU_BDF} > /sys/bus/pci/drivers/vfio-pci/unbind")
        time.sleep(1)
    sh(f"echo {GPU_ID} > /sys/bus/pci/drivers/vfio-pci/new_id")
    time.sleep(1)
    sh(f"echo {GPU_BDF} > /sys/bus/pci/drivers/vfio-pci/bind")
    time.sleep(2)

    drv = gpu_driver()
    log(f"host prepared: GPU driver = {drv or '(none)'}")
    if drv != "vfio-pci":
        log("[!] GPU is not on vfio-pci — QEMU will not be able to claim it")
        return False
    return True


def qemu_pids() -> list:
    return subprocess.run(["ps", "-C", "qemu-system-x86", "-o", "pid="],
                          capture_output=True, text=True).stdout.split()


def _wait_gone(seconds: int) -> bool:
    for _ in range(seconds):
        time.sleep(1)
        if not qemu_pids():
            return True
    return False


def stop_vm() -> str:
    """Shut the guest down as gently as it still allows, and say which rung it took.

    Killing QEMU outright leaves the guest filesystem as if the power was pulled:
    the qcow2 format survives, but the guest's own filesystem does not get to sync,
    and a 1.1TB image is not something to fsck casually. So try the guest first, the
    ACPI button next, and only then signals.
    """
    if not qemu_pids():
        return "already stopped"

    if guest_up():
        log("asking the guest to power off")
        if not _would("power the guest off from inside"):
            guest("sudo sync; sudo systemctl poweroff -i", timeout=15)
            if _wait_gone(60):
                return "clean poweroff from inside the guest"

    sock = Path("/tmp/qemu-monitor.sock")
    if sock.exists() and not _would("press the ACPI power button via the QEMU monitor"):
        log("pressing the ACPI power button via the QEMU monitor")
        try:
            import socket as _s
            with _s.socket(_s.AF_UNIX, _s.SOCK_STREAM) as m:
                m.settimeout(5)
                m.connect(str(sock))
                time.sleep(0.2)
                m.recv(4096)
                m.sendall(b"system_powerdown\n")
            if _wait_gone(60):
                return "ACPI powerdown via monitor"
        except Exception as e:
            log(f"    monitor powerdown failed: {e}")

    if _would("SIGTERM QEMU"):
        return "would signal"
    log("guest is not responding — sending SIGTERM to QEMU")
    subprocess.run(["pkill", "-f", "launch-qemu"], capture_output=True)
    subprocess.run(["pkill", "-f", "qemu-system-x86"], capture_output=True)
    if _wait_gone(30):
        return "SIGTERM (guest filesystem was not synced)"

    log("[!] SIGTERM did not work — SIGKILL")
    subprocess.run(["pkill", "-9", "-f", "qemu-system-x86"], capture_output=True)
    _wait_gone(10)
    return "SIGKILL (guest filesystem was not synced)"


def image_ok(image: str = "/home/eun/usenix.qcow2") -> bool:
    """Cheap corruption flag read from the qcow2 header after an ungraceful stop."""
    out = subprocess.run(["qemu-img", "info", image], capture_output=True, text=True).stdout
    if "corrupt: true" in out:
        log(f"[!] {image} is flagged corrupt — stopping rather than writing more to it")
        return False
    return True


def repair_guest() -> bool:
    """Bring the ICMP side-channel path back after a (re)boot.

    Delegates to net_preflight.sh, which verifies and repairs both ends and only
    succeeds once a real probe is logged by the guest. The hand-rolled checks below
    it are a fallback for when that script is not on this machine.
    """
    if Path(PREFLIGHT).exists():
        if _would(f"run {Path(PREFLIGHT).name}"):
            return True
        r = subprocess.run(["bash", PREFLIGHT], capture_output=True, text=True)
        for line in (r.stdout + r.stderr).strip().splitlines():
            log(f"    preflight| {line[:130]}")
        log(f"preflight {'READY' if r.returncode == 0 else f'FAILED (exit {r.returncode})'}")
        return r.returncode == 0

    log(f"[!] {PREFLIGHT} missing — falling back to the built-in guest checks")
    if "No such file" in guest(f"ls {GUEST_MODULE}"):
        log(f"[!] {GUEST_MODULE} missing on the guest")
        return False
    if "large_icmp_last" not in guest("ls /proc/large_icmp_last 2>&1"):
        if not _would("load the ICMP monitor module"):
            log("loading the ICMP monitor module")
            guest(f"sudo insmod {GUEST_MODULE} 2>&1")
    if not _would(f"bring {GUEST_IFACE} up"):
        guest(f"sudo ip link set {GUEST_IFACE} up; "
              f"sudo ip addr add {GUEST_IP} dev {GUEST_IFACE} 2>/dev/null; "
              f"sudo ip link set {GUEST_IFACE} mtu 9000")
    if not _would("kill stale guest loaders"):
        guest("sudo pkill -f guest_mura_loader; rm -f /tmp/host_read_done")

    ok_mod = "large_icmp_last" in guest("ls /proc/large_icmp_last 2>&1")
    ok_net = icmp_path_works()
    log(f"guest repair: module={'ok' if ok_mod else 'FAIL'} icmp={'ok' if ok_net else 'FAIL'}")
    return ok_mod and ok_net


def icmp_path_works() -> bool:
    """Does an oversized ICMP payload reach the guest's monitor?

    Not a ping: the monitor module may swallow echo requests, so a failed ping is
    no evidence either way. What the attack needs is for the payload to arrive and
    be recorded, which is what this checks.
    """
    import stage1_ref_dict as s1
    guest("echo clear | sudo tee /proc/large_icmp_last >/dev/null 2>&1; true")
    try:
        s1._send_icmp_payload(b"\x00" * s1.PAYLOAD_SIZE)
    except Exception as e:
        log(f"[!] ICMP send failed: {e}")
        return False
    time.sleep(1.5)
    return bool(s1.parse_frags(guest("cat /proc/large_icmp_last")))


def loaders_alive() -> int:
    out = guest("pgrep -fc guest_mura_loader").strip()
    try:
        return int(out.splitlines()[0])
    except (ValueError, IndexError):
        return 0


def snapshot_dictionary(bid: str) -> bool:
    """Keep this boot's reference pages so its dumps stay interpretable.

    The next boot overwrites dict_pages_mura with references encrypted under a new
    VEK. Without a per-boot copy, every dump captured before the last reboot becomes
    impossible to turn into a sparsity map — which is most of a multi-day run.
    """
    import shutil
    dest = SNAP_ROOT / bid
    if _would(f"snapshot the dictionary to {dest.name}"):
        return True
    dest.mkdir(parents=True, exist_ok=True)
    n = 0
    for f in sorted(c.DICT_DIR.glob("ref_*.out")):
        shutil.copy2(f, dest / f.name)
        n += 1
    # stage1 writes ref_dict.json into whatever --output-dir the chunk used, so look
    # there as well as beside this script. Without it the snapshot loses the
    # fixed_gpa the references were read at, which is what a later check needs.
    for meta in (CAPTURE_ROOT / "train" / "ref_dict.json",
                 CAPTURE_ROOT / "valid" / "ref_dict.json",
                 HERE / "ref_dict.json"):
        if meta.exists():
            shutil.copy2(meta, dest / "ref_dict.json")
            break
    else:
        log("[!] no ref_dict.json found to snapshot — fixed_gpa will not be recorded")
    log(f"dictionary snapshot: {n} ref page(s) -> dict_snapshots/{bid}")
    return n > 0


BOOT_MARK = c.DICT_DIR / ".boot_id"


def wanted_refs(refs: str) -> list:
    return [int(x) for x in refs.split(",")] if refs else list(c.REF_U8_64)


def dictionary_state(bid: str, refs: str):
    """Which of this boot's reference pages already exist, and which are missing.

    The marker file ties the pages in dict_pages_mura to the boot that produced
    them. Without it a daemon restart cannot tell a still-valid dictionary from a
    stale one, and rebuilds a good dictionary for 21 minutes — during which the
    guest often dies, so the run never reaches a single capture.
    """
    want = wanted_refs(refs)
    marker = BOOT_MARK.read_text().strip() if BOOT_MARK.exists() else ""
    if marker != bid:
        return want, []          # different boot: every page is encrypted under an old VEK
    have = [u for u in want if (c.DICT_DIR / f"ref_{u:03d}.out").exists()]
    return [u for u in want if u not in have], have


def rebuild_dictionary(bid: str, refs: str, dry: bool) -> bool:
    missing, have = dictionary_state(bid, refs)
    if not missing:
        log(f"dictionary already complete for this boot ({len(have)} ref page(s)) — skipping build")
        return True
    if dry:
        log(f"[dry-run] would build {len(missing)} ref page(s)")
        return True

    if not have:
        # Nothing reusable: drop the previous boot's pages, which would parse fine
        # and never match, and record whose pages these will be.
        for f in c.DICT_DIR.glob("ref_*.out"):
            f.unlink()
        BOOT_MARK.parent.mkdir(parents=True, exist_ok=True)
        BOOT_MARK.write_text(bid)
        cmd = [PY, str(HERE / "stage1_ref_dict.py"), "--rebuild"]
        if refs:
            cmd += ["--only", refs]
        log(f"building {len(missing)} reference page(s) from scratch")
    else:
        # Resume: fixed_gpa from this boot is still valid, so only fill the gap.
        # A build that dies at ref 40 of 64 otherwise costs all 40 again.
        cmd = [PY, str(HERE / "stage1_ref_dict.py"),
               "--only", ",".join(str(u) for u in missing)]
        log(f"resuming: {len(have)} page(s) kept, {len(missing)} to build")

    rc = _run_tracked(cmd, cwd=str(HERE))
    still_missing, have = dictionary_state(bid, refs)
    log(f"dictionary now has {len(have)} ref page(s), {len(still_missing)} missing "
        f"(stage1 exit {rc})")
    return not still_missing


def done_indices(csv_path: Path, split: str) -> set:
    if not csv_path.exists():
        return set()
    out = set()
    with open(csv_path) as f:
        for row in csv.DictReader(f):
            idx = (row.get("index") or "").strip()
            # Indices are per split, so valid rows say nothing about a train run.
            if row.get("split", "valid") != split:
                continue
            # A row whose capture failed is worth retrying after a guest repair.
            if idx.isdigit() and (row.get("gt_overlap") or "-") not in ("-", "", "0"):
                out.add(int(idx))
    return out


def blind_done_indices(split: str) -> set:
    """Indices in <split> that already have a BLIND capture, by the same provenance
    test build_attack_dataset --blind-only uses: probe_choice is set (the 2MB block
    was chosen from burst candidates, not handed over by the guest).

    The pipeline CSV counts block-given captures as done too, so in blind mode it
    would report a class complete when only its old block-given samples exist, and
    --per-class would stop short of 324 *blind* samples. Failed blind attempts
    (0 pages) count as done: they are honest data points, and retrying them would
    cherry-pick the recovery rate upward.
    """
    out = set()
    cap = CAPTURE_ROOT / split
    for m in cap.glob("swap_meta_*.json"):
        try:
            d = json.loads(m.read_text())
        except Exception:
            continue
        if d.get("probe_choice") is None:
            continue
        idx = d.get("index")
        if isinstance(idx, int):
            out.add(idx)
    return out


def index_classes(split: str) -> dict:
    """Class of every index in the split, cached from the guest's path list.

    The CSV is ordered by body part, so capturing 0,1,2,... spends weeks inside one
    class and leaves a single-class dataset if the run is stopped — useless for a
    seven-way classifier.
    """
    cache = HERE / f".index_classes_{split}.json"
    if cache.exists():
        return {int(k): v for k, v in json.loads(cache.read_text()).items()}
    raw = guest(f"cat ~/cc_uvm/pytorch_uvm310_test/mura/mura_downloads/"
                f"{split}_image_paths.csv", timeout=60)
    out = {}
    for i, line in enumerate(raw.splitlines()):
        parts = line.strip().split("/")
        if len(parts) > 2 and parts[2].startswith("XR_"):
            out[i] = parts[2].replace("XR_", "")
    if out:
        cache.write_text(json.dumps(out))
        log(f"cached class labels for {len(out)} {split} indices")
    return out


def interleave(todo: list, classes: dict) -> list:
    """Round-robin the pending indices across classes, order kept deterministic."""
    if not classes:
        return todo
    buckets = {}
    for i in todo:
        buckets.setdefault(classes.get(i, "?"), []).append(i)
    order = sorted(buckets)
    out, n = [], max(len(v) for v in buckets.values())
    for k in range(n):
        for cls in order:
            if k < len(buckets[cls]):
                out.append(buckets[cls][k])
    return out


def capture_dir(split: str) -> Path:
    """Per-split output. Dump names are {class}_{index}_p{NN}.out, so train and
    valid would otherwise overwrite each other whenever a class and index coincide.
    """
    return CAPTURE_ROOT / split


def run_chunk(indices: list, args, bid: str) -> int:
    out = capture_dir(args.split)
    out.mkdir(parents=True, exist_ok=True)
    cmd = [PY, "-u", str(HERE / "master_orchestrate.py"),
           "--indices", ",".join(str(i) for i in indices),
           "--split", args.split, "--blind",
           "--to-stage", str(args.to_stage), "--output-dir", str(out),
           "--max-dead", "3", "--max-loaders", str(MAX_LOADERS)]
    if not args.blind_block:
        # Default: guest names its 2MB block (the measured 94.4% setting).
        # --blind-block drops it, so blocks come only from burst candidates and
        # probe must pick among them — the fully-blind end-to-end attack.
        cmd.append("--block-from-guest")
    if args.probe:
        cmd.append("--probe")
    log(f"chunk of {len(indices)} (first {indices[0]}, last {indices[-1]}) -> {out}")
    if args.dry_run:
        return 0
    env = dict(os.environ, MURA_BOOT_ID=bid)
    return _run_tracked(cmd, cwd=str(HERE), env=env)


def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--split", default="train", choices=["train", "valid"])
    p.add_argument("--start", type=int, default=0)
    p.add_argument("--end", type=int, default=10**9,
                   help="Upper index bound (exclusive). Default: the whole split. "
                        "Note this is an INDEX bound, not a sample count — the valid "
                        "CSV is ordered by body part, so a small --end lands entirely "
                        "in one class. Use --per-class to cap how many are captured.")
    p.add_argument("--per-class", type=int, default=None,
                   help="Stop once every class has this many captures. With "
                        "interleave this fills the classes evenly, which a plain "
                        "--end cannot (that just truncates the index range).")
    p.add_argument("--chunk", type=int, default=100, help="Indices per supervised chunk")
    p.add_argument("--to-stage", type=int, default=3, choices=[2, 3, 5])
    p.add_argument("--probe", action="store_true")
    p.add_argument("--blind-block", action="store_true",
                   help="Do NOT take the 2MB block from the guest; find it blind "
                        "from burst candidates (requires --probe to select)")
    p.add_argument("--refs", default="", help="Comma-separated u8 list for a partial dictionary")
    p.add_argument("--launch-script", default="/home/eun/esp_bak/sev-step/launch-qemu-noncc.sh",
                   help="Script that brings the guest up on the pipeline's SSH port")
    p.add_argument("--launch-args", default="-cc",
                   help="Arguments for the launch script")
    p.add_argument("--no-interleave", dest="interleave", action="store_false",
                   help="Capture indices in order instead of round-robin by class")
    p.add_argument("--dry-run", action="store_true")
    args = p.parse_args()

    global DRY, _LOCK_FH
    DRY = args.dry_run

    # Single instance only. A second daemon would drive the same ICMP/PSP hardware
    # concurrently with the first, corrupting the dictionary and overloading the
    # host — the failure that took the server down.
    if not args.dry_run:
        _LOCK_FH = open(LOCKFILE, "w")
        try:
            fcntl.flock(_LOCK_FH, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError:
            print(f"[daemon] another capture_daemon holds {LOCKFILE} — refusing to "
                  f"start a second one", file=sys.stderr)
            return 2
        _LOCK_FH.write(str(os.getpid()))
        _LOCK_FH.flush()

    # Reap the running child's whole process group on any clean termination, so no
    # stage1/swap_pages_tool is ever orphaned behind the daemon.
    for s in (signal.SIGTERM, signal.SIGINT, signal.SIGHUP):
        signal.signal(s, _on_signal)
    atexit.register(_reap_child)

    csv_path = capture_dir(args.split) / "pipeline_summary.csv"
    # Read back from the dictionary itself, so a daemon restart does not mistake a
    # still-valid dictionary for a stale one.
    last_boot = BOOT_MARK.read_text().strip() if BOOT_MARK.exists() else None
    stalled = 0

    while True:
        # A host reboot drops the vfio binding and every VM with it; the guest just
        # looks unreachable and no amount of relaunching helps until this is redone.
        hb = host_boot_id()
        if hb and hb != (HOST_BOOT_MARK.read_text().strip()
                         if HOST_BOOT_MARK.exists() else None):
            log(f"host boot changed -> {hb[:8]}…")
            if not prepare_host():
                log("[!] host preparation failed; retrying in 120s")
                time.sleep(120)
                continue
            if not args.dry_run:
                HOST_BOOT_MARK.write_text(hb)

        # In blind mode, "done" means a blind capture exists — old block-given
        # captures in the same dir must not count toward a blind per-class target.
        cap_done = (lambda: blind_done_indices(args.split)) if args.blind_block \
            else (lambda: done_indices(csv_path, args.split))
        done = cap_done()
        classes = index_classes(args.split) if (args.interleave or args.per_class) else {}
        # --end defaults to the whole split; restrict to indices that actually exist
        # so a huge --end does not generate phantom todo entries.
        universe = ([i for i in sorted(classes) if args.start <= i < args.end]
                    if classes else list(range(args.start, args.end)))
        todo = [i for i in universe if i not in done]

        if args.per_class is not None and classes:
            by_class = Counter(classes.get(i, "?") for i in done)
            log("per-class done: "
                + "  ".join(f"{k} {by_class.get(k,0)}" for k in sorted(set(classes.values()))))
            under = {cls for cls in set(classes.values())
                     if by_class.get(cls, 0) < args.per_class}
            if not under:
                log(f"every class reached {args.per_class} captures — done")
                return 0
            todo = [i for i in todo if classes.get(i) in under]

        if not todo:
            log("all requested indices captured — done")
            return 0
        if args.interleave:
            todo = interleave(todo, classes)
        log(f"{len(done)} captured, {len(todo)} remaining (next {todo[0]})")

        if not guest_up():
            log("guest unreachable — booting")
            if not start_vm(args.launch_script, args.launch_args):
                log("[!] guest did not come back; retrying in 120s")
                time.sleep(120)
                continue

        bid = boot_id()
        if bid and bid != last_boot:
            # New VM instance: the VEK changed, so the old dictionary matches nothing.
            log(f"guest boot id changed ({last_boot} -> {bid[:8]}…)")
            if not repair_guest():
                log("[!] guest repair failed; retrying in 120s")
                time.sleep(120)
                continue
            if not rebuild_dictionary(bid, args.refs, args.dry_run):
                time.sleep(120)
                continue
            if not snapshot_dictionary(bid):
                log("[!] could not snapshot the dictionary; refusing to capture "
                    "dumps that could never be decoded")
                time.sleep(120)
                continue
            last_boot = bid
        elif loaders_alive() > MAX_LOADERS:
            log(f"{loaders_alive()} stale loaders — clearing")
            if not _would("kill stale guest loaders"):
                guest("sudo pkill -f guest_mura_loader; rm -f /tmp/host_read_done")
                time.sleep(10)

        before = len(done)
        run_chunk(todo[:args.chunk], args, last_boot or "")
        gained = len(cap_done()) - before
        log(f"chunk added {gained} capture(s)")

        if gained == 0:
            stalled += 1
            # Nothing landed: the guest is wedged in a way a repair did not fix.
            # Force a fresh instance rather than looping on a broken one.
            log(f"no progress ({stalled} in a row)")
            if stalled >= 2:
                if _would("reboot the guest"):
                    log("[dry-run] stopping here rather than looping")
                    return 0
                log("forcing a guest reboot")
                guest("sudo reboot", timeout=10)
                last_boot = None
                time.sleep(60)
                stalled = 0
            else:
                time.sleep(30)
        else:
            stalled = 0


if __name__ == "__main__":
    sys.exit(main())
