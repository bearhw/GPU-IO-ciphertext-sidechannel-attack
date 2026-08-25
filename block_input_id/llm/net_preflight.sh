#!/usr/bin/env bash
# net_preflight.sh — verify/repair the ICMP side-channel packet path.
#
# Run as root AFTER every QEMU (re)launch and BEFORE a dict build:
#     sudo ./net_preflight.sh
#
# Exits 0 (READY) only when a real large-ICMP probe makes the guest log
# frag[N]: compound_GPA=...  (i.e. the exact thing orchestrate_v3 --build needs).
# It auto-fixes the recoverable failures (tap0 down, MTU, guest module) and
# STOPS with a clear message on the ones that need a manual QEMU relaunch
# (no/duplicate QEMU, orphaned monitor socket).
set -u

GUEST_IP=192.168.100.2
TAP=tap0
TAP_IP=192.168.100.1
MTU=9000
MON_SOCK=/tmp/qemu-monitor.sock

USER_HOME=$(getent passwd "${SUDO_USER:-$USER}" | cut -d: -f6)
KEY="$USER_HOME/.ssh/id_ed25519"
SSH="ssh -p 7777 -i $KEY -o StrictHostKeyChecking=no -o BatchMode=yes -o ConnectTimeout=8 ubuntu@localhost"

# guest module search paths (same set orchestrate_v3 uses)
KO_CANDIDATES=(
  "~/sev-h100-sidechannel/2026attack/flow/guest_tool/guest_large_icmp_monitor.ko"
  "~/guest_large_icmp_monitor.ko"
  "/home/ubuntu/guest_large_icmp_monitor.ko"
  "/home/ubuntu/proof_code/guest_large_icmp_monitor.ko"
)

ok()   { printf '\033[32m[ok]\033[0m   %s\n' "$*"; }
info() { printf '\033[1m[..]\033[0m   %s\n' "$*"; }
fail() { printf '\033[31m[FAIL]\033[0m %s\n' "$*" >&2; exit 1; }

[ "$(id -u)" = 0 ] || fail "run as root:  sudo $0"

# 1) exactly one QEMU (duplicate launch => vfio conflict + orphaned sockets) ----
# Use process comm (ps -C), not pgrep -f: shell wrappers that mention
# "qemu-system-x86_64" in their cmdline otherwise inflate the count.
n=$(ps -C qemu-system-x86 --no-headers 2>/dev/null | wc -l)
n=$(echo "$n" | tr -d ' ')
[ "$n" = 1 ] || fail "expected 1 qemu-system-x86_64, found $n.
      Relaunch cleanly:
        sudo pkill -f launch-qemu-noncc.sh; sudo pkill -f qemu-system-x86_64
        sudo rm -f /tmp/qemu-monitor.sock /tmp/qmp-sock
        cd $(dirname $(command -v launch-qemu-noncc.sh 2>/dev/null || echo .)) ; sudo ./launch-qemu-noncc.sh -cc"
ok "single QEMU running (pid $(ps -C qemu-system-x86 -o pid= | tr -d ' '))"

# 2) monitor socket actually answers (not a stale/orphaned file) ---------------
python3 - "$MON_SOCK" <<'PY' || fail "QEMU HMP monitor $MON_SOCK is NOT answering (stale/orphaned socket file).
      A running QEMU cannot be relinked to the path — relaunch it cleanly:
        sudo pkill -f launch-qemu-noncc.sh; sudo pkill -f qemu-system-x86_64
        sudo rm -f /tmp/qemu-monitor.sock /tmp/qmp-sock
        sudo ./launch-qemu-noncc.sh -cc"
import socket, sys, time
s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM); s.settimeout(5)
try:
    s.connect(sys.argv[1]); time.sleep(0.2)
    d = s.recv(4096); s.close()
except Exception:
    sys.exit(1)
sys.exit(0 if b"(qemu)" in d else 1)
PY
ok "QEMU HMP monitor responds"

# 3) tap0 up + mtu + ip (idempotent) ------------------------------------------
ip link show "$TAP" >/dev/null 2>&1 || fail "$TAP missing — did launch-qemu-noncc.sh run? (it creates tap0)"
ip addr show "$TAP" | grep -q "$TAP_IP/" || ip addr add "$TAP_IP/24" dev "$TAP"
ip link set "$TAP" mtu "$MTU"
ip link set "$TAP" up
ok "$TAP up, mtu $MTU, $TAP_IP/24"

# 4) route to guest must go via tap0 (not the physical NIC) --------------------
dev=$(ip route get "$GUEST_IP" 2>/dev/null | grep -o 'dev [^ ]*' | awk '{print $2}')
[ "$dev" = "$TAP" ] || fail "route to $GUEST_IP goes via '$dev', not $TAP.
      (tap0 down makes $GUEST_IP leak out the physical NIC.) Re-check tap0/routes."
ok "route to $GUEST_IP via $TAP"

# 5) guest reachable over the mgmt NIC (port 7777, independent of tap0) --------
$SSH "echo ok" 2>/dev/null | grep -q ok || fail "guest SSH (port 7777) unreachable — is the guest booted?"
ok "guest SSH reachable"

# 6) guest enp0s4 up + ip + mtu (fresh boots leave it DOWN with no IP) ---------
$SSH "sudo ip link set enp0s4 up
      ip addr show enp0s4 | grep -q '$GUEST_IP/' || sudo ip addr add $GUEST_IP/24 dev enp0s4
      sudo ip link set enp0s4 mtu $MTU" 2>/dev/null
# verify it actually came up with the address (else host ARP fails -> ping errors)
$SSH "ip -br addr show enp0s4" 2>/dev/null | grep -q "$GUEST_IP" \
    || fail "guest enp0s4 is not UP with $GUEST_IP — check guest netplan/boot config"
# prime host ARP so the first real probe doesn't lose to resolution
ping -c1 -w2 "$GUEST_IP" >/dev/null 2>&1 || true
ok "guest enp0s4 up, $GUEST_IP/24, mtu $MTU"

# 7) guest monitor module ------------------------------------------------------
if $SSH "lsmod | grep -q large_icmp" 2>/dev/null; then
    ok "monitor module already loaded"
else
    info "guest monitor module not loaded — inserting..."
    for ko in "${KO_CANDIDATES[@]}"; do
        $SSH "test -f $ko && sudo insmod $ko" 2>/dev/null && break
    done
    $SSH "lsmod | grep -q large_icmp" 2>/dev/null \
        || fail "could not load guest_large_icmp_monitor.ko (checked: ${KO_CANDIDATES[*]})"
    ok "monitor module loaded"
fi

# 8) the real test: a large ICMP must produce frag[N]: compound_GPA on guest ---
info "sending one 8192B ICMP probe (waiting out any mdelay(6000) hold first)..."
$SSH "echo clear | sudo tee /proc/large_icmp_last >/dev/null 2>&1" >/dev/null 2>&1
sleep 7
ping -c1 -s 8192 -M do -W 9 "$GUEST_IP" >/dev/null 2>&1 || true
sleep 1
if $SSH "sudo cat /proc/large_icmp_last 2>/dev/null" 2>/dev/null | grep -q 'compound_GPA='; then
    ok "frag[N]: compound_GPA logged"
    printf '\n\033[1;32m[preflight] READY — packet path good. Run the build now.\033[0m\n'
    exit 0
fi
fail "no frag[N] on guest after probe — RX not producing paged frags.
      Try on guest:  sudo ethtool -K enp0s4 gro off gso off lro off
      then rerun. If it persists, relaunch QEMU (RX page pool wedged)."
