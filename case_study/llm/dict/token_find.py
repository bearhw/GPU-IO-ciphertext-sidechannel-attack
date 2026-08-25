import re
import sys

HEX_LINE = re.compile(r'^([0-9a-f]+):\s+(0x[0-9a-f]+)\s+(0x[0-9a-f]+)$')


def parse(path):
    """addr -> (v1, v2, raw_line)"""
    by_addr = {}
    by_val  = {}
    with open(path, 'r', errors='replace') as f:
        for line in f:
            line = line.strip()
            m = HEX_LINE.match(line)
            if m:
                addr, v1, v2 = m.group(1), m.group(2), m.group(3)
                by_addr[addr] = (v1, v2, line)
                by_val[(v1, v2)] = (addr, line)
    return by_addr, by_val


def prompt_path(prompt: str, default: str) -> str:
    try:
        val = input(f'{prompt} [{default}]: ').strip()
    except EOFError:
        val = ''
    return val if val else default


def main():
    if len(sys.argv) > 2:
        cp_path  = sys.argv[1]
        gpa_path = sys.argv[2]
    elif len(sys.argv) == 2:
        cp_path  = sys.argv[1]
        gpa_path = prompt_path('gpa.out path', 'gpa.out')
    else:
        cp_path  = prompt_path('cp.out  path', 'cp.out')
        gpa_path = prompt_path('gpa.out path', 'gpa.out')

    cp_addr,  cp_val  = parse(cp_path)
    gpa_addr, gpa_val = parse(gpa_path)

    # --- 1. rows with same address and same value ---
    common_addrs = set(cp_addr) & set(gpa_addr)
    addr_matches = [
        addr for addr in common_addrs
        if cp_addr[addr][:2] == gpa_addr[addr][:2]   # both (v1,v2) match
    ]

    # --- 2. rows with same value pair regardless of address ---
    val_matches = set(cp_val) & set(gpa_val)

    if not addr_matches and not val_matches:
        print('No matching rows found.')
        if common_addrs:
            print(f'(Address ranges overlap: {len(common_addrs)} shared addresses,'
                  ' but no values match.)')
        return

    if addr_matches:
        print(f'[same address + same value] {len(addr_matches)} row(s):\n')
        for addr in sorted(addr_matches):
            print(f'  {cp_addr[addr][2]}')
        print()

    # rows with same value but different address (excluding addr_matches overlap)
    val_only_matches = {k for k in val_matches
                        if cp_val[k][0] != gpa_val[k][0]}
    if val_only_matches:
        print(f'[same value, different address] {len(val_only_matches)} row(s):\n')
        for key in sorted(val_only_matches):
            cp_a,  cp_line  = cp_val[key]
            gpa_a, gpa_line = gpa_val[key]
            print(f'  cp  @ {cp_a} : {cp_line}')
            print(f'  gpa @ {gpa_a} : {gpa_line}')
            print()


if __name__ == '__main__':
    main()
