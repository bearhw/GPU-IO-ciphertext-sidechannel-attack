#!/usr/bin/env python3
"""
Standalone diagnostic — is the mdelay(HOLD_MS) window in
guest_large_icmp_monitor.c actually protecting the captured dict page long
enough for the host to read it?

For each round:
  1. send one ICMP probe for a chosen TOKEN_LABELS entry (same acquire_gpa()
     path build_dict uses)
  2. compute the same clean-interior-page dict_gpa build_dict would pick
  3. read it once immediately, record elapsed time since the packet was sent
  4. sleep --delay-ms, read it again, compare byte-for-byte

If read1 == read2 even when total elapsed time exceeds HOLD_MS, corruption
isn't happening in this window and the bug is elsewhere (e.g. swap_pages_tool
at run_all time). If they differ, that's direct proof the physical page gets
reused within the window we thought was safe.

Usage:
    python3 debug_capture_race.py --label-idx 4 --rounds 10 --delay-ms 2500
    python3 debug_capture_race.py --label-idx 0 --rounds 10 --delay-ms 2500
"""

import argparse
import time

import orchestrate_v3 as v3


def find_clean_page(frags, token_ids, byte_shift):
    """Same candidate-selection logic as build_dict's inner loop, simplified
    to just return the FIRST clean interior page (any 8-aligned landing)."""
    L = len(token_ids) * 8
    cum_payload = 0
    for i, (compound_gpa, off, size) in enumerate(frags):
        header_skip = (8 + byte_shift) if i == 0 else 0
        frag_payload_start = compound_gpa + off + header_skip
        frag_payload_end = compound_gpa + off + size
        frag_payload_len = size - header_skip
        if frag_payload_len <= 0:
            continue
        first_page = frag_payload_start // 4096
        last_page = (frag_payload_end - 1) // 4096
        for p in range(first_page, last_page + 1):
            if p * 4096 >= frag_payload_start and (p + 1) * 4096 <= frag_payload_end:
                pos_in_payload = cum_payload + (p * 4096 - frag_payload_start)
                landing = (L - pos_in_payload % L) % L
                if landing % 8 == 0:
                    return p * 4096, landing
        cum_payload += frag_payload_len
    return None, None


def main() -> None:
    p = argparse.ArgumentParser()
    p.add_argument("--label-idx", type=int, default=4,
                    help="index into orchestrate_v3.TOKEN_LABELS to test")
    p.add_argument("--rounds", type=int, default=10)
    p.add_argument("--delay-ms", type=int, default=2500,
                    help="delay between read1 and read2, in ms")
    args = p.parse_args()

    label, token_ids = v3.TOKEN_LABELS[args.label_idx]
    print(f"[diag] label_idx={args.label_idx} '{label}' token_ids={token_ids}  "
          f"delay_ms={args.delay_ms}  rounds={args.rounds}")

    monitor_sock = v3.read_gpa.connect_monitor()

    n_same = n_diff = n_no_page = n_send_fail = 0

    for rnd in range(args.rounds):
        byte_shift = rnd % 8
        t_send = time.monotonic()
        try:
            frags = v3._acquire_retry(token_ids, byte_shift=byte_shift, retries=2)
        except RuntimeError as e:
            print(f"  round {rnd}: send/acquire failed: {e}")
            n_send_fail += 1
            continue
        t_acquired = time.monotonic()

        dict_gpa, landing = find_clean_page(frags, token_ids, byte_shift)
        if dict_gpa is None:
            print(f"  round {rnd}: no clean 8-aligned interior page this send, skip")
            n_no_page += 1
            continue

        raw1 = v3.read_gpa.read_page(monitor_sock, dict_gpa)
        t_read1 = time.monotonic()
        time.sleep(args.delay_ms / 1000.0)
        raw2 = v3.read_gpa.read_page(monitor_sock, dict_gpa)
        t_read2 = time.monotonic()

        send_to_read1_ms = (t_read1 - t_send) * 1000
        acquire_ms        = (t_acquired - t_send) * 1000
        total_ms          = (t_read2 - t_send) * 1000
        same = (raw1 == raw2)

        print(f"  round {rnd}: dict_gpa=0x{dict_gpa:x} landing=0x{landing:x}  "
              f"acquire={acquire_ms:.0f}ms  send→read1={send_to_read1_ms:.0f}ms  "
              f"total(incl. {args.delay_ms}ms sleep)={total_ms:.0f}ms  "
              f"→ {'SAME' if same else 'DIFFERENT'}")

        if same:
            n_same += 1
        else:
            n_diff += 1
            (v3.HERE / f"debug_race_r{rnd}_read1.out").write_text(raw1)
            (v3.HERE / f"debug_race_r{rnd}_read2.out").write_text(raw2)
            print(f"    [!] saved debug_race_r{rnd}_read1.out / _read2.out for inspection")

    monitor_sock.close()
    print(f"\n[diag] done: {n_same} same, {n_diff} different, "
          f"{n_no_page} no-clean-page, {n_send_fail} send-failed (of {args.rounds} rounds)")


if __name__ == "__main__":
    main()
