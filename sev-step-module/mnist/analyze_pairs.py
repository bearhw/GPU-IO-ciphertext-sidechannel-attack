#!/usr/bin/env python3
"""
Pair each host-side precursor session (early-exit replay) against the guest's
ground-truth image-buffer GPAs, and report identification statistics.

Three levels of statistics:
  (A) per-precursor session : did the early-exit logic produce a run, and did
      that run land on a real image buffer?
  (B) per ground-truth buffer : how many host detections landed on it, vs. how
      many times the guest actually used it (recall proxy).
  (C) tool level : does the ranked top-N output of write_pattern_tracker_early_exit
      (score = hit_count x max_run_len) contain the true image GPA?
"""
import re, sys, collections
import replay_early_exit as R

ALIGN_2MB = 0x200000
GUEST_RE = re.compile(r'\[(Train|Test)\]\s+batch (\d+) (?:image )?GPA: 0x([0-9a-fA-F]+)')
PCT_RE = re.compile(r'Train Epoch: \d+ \[(\d+)/(\d+)')


def load_guest(path):
    batches = []          # (phase, batch_idx, gpa)
    prog = []
    for line in open(path):
        m = GUEST_RE.search(line)
        if m:
            batches.append((m.group(1), int(m.group(2)), int(m.group(3), 16)))
            continue
        m = PCT_RE.search(line)
        if m:
            prog.append(int(m.group(1)))
    return batches, prog


def infer_batch_size(prog):
    """batch_size from consecutive '[N/60000]' progress lines (log_interval=10)."""
    if len(prog) >= 2:
        return (prog[1] - prog[0]) // 10
    return None


def score(hit_count, max_run_len):
    return hit_count * max_run_len


def analyze(run, guest_path, host_path, top_n=5):
    batches, prog = load_guest(guest_path)
    bs = infer_batch_size(prog)
    img_bytes = bs * 784 * 4 if bs else None

    gt_exact = collections.Counter(g for _, _, g in batches)
    gt_train = collections.Counter(g for p, _, g in batches if p == 'Train')
    gt_test = collections.Counter(g for p, _, g in batches if p == 'Test')

    # 2MB pages actually spanned by each image buffer
    def span_of(g):
        out, a, end = [], g & ~(ALIGN_2MB - 1), g + (img_bytes or 1) - 1
        while a <= end:
            out.append(a)
            a += ALIGN_2MB
        return out

    gt_span = set()
    for g in gt_exact:
        gt_span.update(span_of(g))

    sessions, total, precursors = R.replay(host_path)

    n_run = sum(1 for s in sessions if s['hit'])
    n_match = sum(1 for s in sessions if s['hit'] and s['aligned'] in gt_span)
    n_contain = sum(1 for s in sessions if s['hit'] and
                    any(g <= s['base'] < g + img_bytes for g in gt_exact))

    # --- rebuild the tool's candidate table (record_hit semantics) ---
    cand = {}   # aligned -> [hit_count, max_run_len, best_exact]
    for s in sessions:
        if not s['hit']:
            continue
        a = s['aligned']
        if a in cand:
            c = cand[a]
            c[0] += 1
            c[1] = max(c[1], s['run_len'])
            c[2] = min(c[2], s['base'])
        else:
            cand[a] = [1, s['run_len'], s['base']]
    ranked = sorted(cand.items(),
                    key=lambda kv: (-score(kv[1][0], kv[1][1]), -kv[1][0]))

    top = ranked[:top_n]
    rank_of_truth = None
    for i, (a, c) in enumerate(ranked):
        if a in gt_span:
            rank_of_truth = i + 1
            break

    return dict(run=run, batches=len(batches), n_train=sum(gt_train.values()),
                n_test=sum(gt_test.values()), batch_size=bs, img_bytes=img_bytes,
                gt_exact=gt_exact, gt_train=gt_train, gt_test=gt_test,
                gt_span=gt_span, span_of=span_of,
                total=total, precursors=precursors,
                n_run=n_run, n_norun=len(sessions) - n_run,
                n_match=n_match, n_contain=n_contain,
                det=collections.Counter(s['aligned'] for s in sessions if s['hit']),
                ranked=ranked, top=top, rank_of_truth=rank_of_truth,
                top1_ok=(rank_of_truth == 1),
                topn_ok=(rank_of_truth is not None and rank_of_truth <= top_n))


def main():
    rows = [analyze(i, f'run{i}_guest.log', f'run{i}.log') for i in range(1, 9)]
    W = 120

    print("=" * W)
    print(" (A)  PER-PRECURSOR SESSION  —  early-exit state machine replayed on the host trace")
    print("=" * W)
    print(f"{'run':>3} {'host writes':>11} {'precursors':>10} {'guest batches':>13} "
          f"{'bsz':>4} {'run found':>10} {'no run':>8} {'on image buf':>13} "
          f"{'P(run|prec)':>12} {'P(img|run)':>11} {'P(img|prec)':>12}")
    print("-" * W)
    for r in rows:
        print(f"{r['run']:>3} {r['total']:>11} {r['precursors']:>10} {r['batches']:>13} "
              f"{str(r['batch_size']):>4} {r['n_run']:>10} {r['n_norun']:>8} "
              f"{r['n_match']:>13} "
              f"{r['n_run']/r['precursors']*100:>11.2f}% "
              f"{r['n_match']/r['n_run']*100:>10.2f}% "
              f"{r['n_match']/r['precursors']*100:>11.2f}%")
    T = lambda k: sum(r[k] for r in rows)
    print("-" * W)
    print(f"{'ALL':>3} {T('total'):>11} {T('precursors'):>10} {T('batches'):>13} "
          f"{'':>4} {T('n_run'):>10} {T('n_norun'):>8} {T('n_match'):>13} "
          f"{T('n_run')/T('precursors')*100:>11.2f}% "
          f"{T('n_match')/T('n_run')*100:>10.2f}% "
          f"{T('n_match')/T('precursors')*100:>11.2f}%")
    print("=" * W)

    print()
    print("=" * W)
    print(" (C)  TOOL-LEVEL VERDICT  —  ranked candidate table (score = hits x max_run), top-5 output")
    print("=" * W)
    print(f"{'run':>3} {'uniq cands':>11} {'truth rank':>11} {'TOP-1':>7} {'TOP-5':>7}   rank-1 candidate            true image GPA(s)")
    print("-" * W)
    for r in rows:
        rk = r['rank_of_truth']
        a1 = r['ranked'][0][0] if r['ranked'] else 0
        truths = ' '.join('0x%x' % g for g in sorted(r['gt_train'])[:2])
        print(f"{r['run']:>3} {len(r['ranked']):>11} {str(rk) if rk else '  -':>11} "
              f"{'YES' if r['top1_ok'] else 'no':>7} {'YES' if r['topn_ok'] else 'no':>7}   "
              f"0x{a1:012x}  {truths}")
    print("-" * W)
    n1 = sum(1 for r in rows if r['top1_ok'])
    n5 = sum(1 for r in rows if r['topn_ok'])
    print(f"  TOP-1 success: {n1}/8 = {n1/8*100:.1f}%      "
          f"TOP-5 success: {n5}/8 = {n5/8*100:.1f}%")
    print("=" * W)

    print("\n\n" + "=" * W)
    print(" (B)  PER-RUN DETAIL — ground truth vs. host detections")
    print("=" * W)
    for r in rows:
        print(f"\n### run{r['run']}   batch_size={r['batch_size']}   image buffer="
              f"{r['img_bytes']} B ({r['img_bytes']/1048576:.2f} MB)   "
              f"train={r['n_train']} test={r['n_test']} batches   precursors={r['precursors']}")
        print(f"  {'guest image buffer GPA':<26} {'uses':>6}  {'2MB page(s)':<26} {'host det':>9}  {'det/use':>8}")
        for g, n in r['gt_exact'].most_common():
            sp = r['span_of'](g)
            hits = sum(r['det'][a] for a in sp)
            print(f"    0x{g:016x}       {n:>6}  {' '.join('0x%x' % a for a in sp):<26} "
                  f"{hits:>9}  {hits/n*100:>7.1f}%")
        print("  host ranked candidates (top 8):")
        for i, (a, c) in enumerate(r['ranked'][:8]):
            tag = "   <== TRUE IMAGE BUFFER" if a in r['gt_span'] else ""
            print(f"    #{i+1:<2} 0x{a:016x}  hits={c[0]:>5}  max_run={c[1]:>4}  "
                  f"score={score(c[0], c[1]):>6}  exact=0x{c[2]:012x}{tag}")


if __name__ == '__main__':
    main()
