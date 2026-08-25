#!/usr/bin/env python3
"""
2nd-page statistics for the batch-size-1 MNIST run.

Guest line format:
  [Train] batch N GPA: 0x<buf>            -> image fits in ONE 4KB page
  [Train] batch N GPA: 0x<buf>, page2: 0x<p2>  -> image spills into a 2nd page

image size = batch(1) x 1 x 28 x 28 x float32 = 3136 B, so the spill happens
iff (buf & 0xFFF) + 3136 > 4096, i.e. page offset > 960.
"""
import re, collections, statistics

IMG = 1 * 784 * 4          # 3136 B, batch_size = 1
PAGE = 0x1000

LINE = re.compile(r'\[Train\] batch (\d+) GPA: 0x([0-9a-fA-F]+)(?:, page2: 0x([0-9a-fA-F]+))?')


def load(path):
    out = []
    for line in open(path, errors='replace'):
        m = LINE.search(line)
        if m:
            out.append((int(m.group(1)), int(m.group(2), 16),
                        int(m.group(3), 16) if m.group(3) else None))
    return out


def runs_of(flags):
    """Maximal runs of True. Returns list of (start_index, length)."""
    out, i, n = [], 0, len(flags)
    while i < n:
        if flags[i]:
            j = i
            while j < n and flags[j]:
                j += 1
            out.append((i, j - i))
            i = j
        else:
            i += 1
    return out


def main():
    b = load('2ndPage_guest.txt')
    n = len(b)
    flags = [p2 is not None for _, _, p2 in b]
    n2 = sum(flags)

    print("=" * 96)
    print(" 2nd-PAGE USAGE  —  MNIST batch_size=1, image = %d B (%.2f pages)" % (IMG, IMG / PAGE))
    print("=" * 96)
    print(f"  total batches logged            : {n}")
    print(f"  batches using a 2nd page        : {n2:>6}  ({n2/n*100:.2f} %)")
    print(f"  batches inside a single page    : {n-n2:>6}  ({(n-n2)/n*100:.2f} %)")

    # --- sanity: does the spill match the geometric prediction? ---
    pred = sum(1 for _, g, _ in b if (g & 0xFFF) + IMG > PAGE)
    mism = sum(1 for (_, g, p2) in b if ((g & 0xFFF) + IMG > PAGE) != (p2 is not None))
    print(f"\n  geometric prediction (off+3136>4096): {pred}  "
          f"({pred/n*100:.2f} %)   mismatches vs. log: {mism}")
    print(f"  theoretical if offsets uniform over 4KB: "
          f"{(PAGE-(PAGE-IMG+1))/PAGE*100:.2f} % ... offsets are 64B-aligned in practice")

    # --- page-offset distribution ---
    offs = [g & 0xFFF for _, g, _ in b]
    print(f"\n  page offset: min=0x{min(offs):03x} max=0x{max(offs):03x}  "
          f"distinct={len(set(offs))}  all 64B-aligned={all(o % 64 == 0 for o in offs)}")

    # --- physical contiguity of the 2nd page ---
    cont = sum(1 for _, g, p2 in b if p2 is not None and p2 == (g & ~0xFFF) + PAGE)
    print(f"\n  2nd page physically CONTIGUOUS  : {cont:>6}  ({cont/n2*100:.2f} % of spilling batches)")
    print(f"  2nd page physically SCATTERED   : {n2-cont:>6}  ({(n2-cont)/n2*100:.2f} % of spilling batches)")

    # --- consecutive runs ---
    r2 = runs_of(flags)
    r1 = runs_of([not f for f in flags])
    print("\n" + "=" * 96)
    print(" CONSECUTIVE RUNS OF 2nd-PAGE BATCHES")
    print("=" * 96)
    print(f"  number of runs                  : {len(r2)}")
    print(f"  mean run length                 : {n2/len(r2):.2f}")
    print(f"  median / max run length         : {statistics.median(l for _,l in r2):.1f} / {max(l for _,l in r2)}")
    print(f"  runs of length >= 2             : {sum(1 for _,l in r2 if l>=2)}  "
          f"covering {sum(l for _,l in r2 if l>=2)} batches "
          f"({sum(l for _,l in r2 if l>=2)/n*100:.2f} % of all batches)")
    print(f"  runs of length >= 5             : {sum(1 for _,l in r2 if l>=5)}  "
          f"covering {sum(l for _,l in r2 if l>=5)} batches")
    print(f"  runs of length >= 10            : {sum(1 for _,l in r2 if l>=10)}  "
          f"covering {sum(l for _,l in r2 if l>=10)} batches")

    hist = collections.Counter(l for _, l in r2)
    print(f"\n  {'run len':>8} {'# runs':>8} {'batches':>9} {'cum % of 2p batches':>21}")
    cum = 0
    for L in sorted(hist):
        cum += hist[L] * L
        print(f"  {L:>8} {hist[L]:>8} {hist[L]*L:>9} {cum/n2*100:>20.2f}%")

    print(f"\n  longest run: length {max(l for _,l in r2)} at batches "
          f"{[s for s,l in r2 if l==max(x for _,x in r2)]}")
    print(f"\n  (gaps) runs of single-page batches: {len(r1)} runs, "
          f"mean {(n-n2)/len(r1):.2f}, max {max(l for _,l in r1)}")

    # --- Markov / independence check ---
    p = n2 / n
    trans = collections.Counter(zip(flags, flags[1:]))
    p11 = trans[(True, True)] / max(1, trans[(True, True)] + trans[(True, False)])
    p01 = trans[(False, True)] / max(1, trans[(False, True)] + trans[(False, False)])
    print("\n" + "=" * 96)
    print(" IS THE 2nd-PAGE EVENT CORRELATED ACROSS BATCHES?")
    print("=" * 96)
    print(f"  P(2page)                = {p*100:.2f} %")
    print(f"  P(2page | prev 2page)   = {p11*100:.2f} %")
    print(f"  P(2page | prev 1page)   = {p01*100:.2f} %")
    print(f"  expected mean run if i.i.d. = 1/(1-p) = {1/(1-p):.2f}   observed = {n2/len(r2):.2f}")

    # --- how many distinct buffers / reuse ---
    bufs = collections.Counter(g for _, g, _ in b)
    print(f"\n  distinct buffer GPAs: {len(bufs)}   most reused: "
          + ', '.join(f'0x{g:x}x{c}' for g, c in bufs.most_common(5)))


if __name__ == '__main__':
    main()
