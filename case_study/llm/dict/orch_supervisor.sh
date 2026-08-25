#!/usr/bin/env bash
# orch_supervisor.sh — unattended guest/orchestrate recover+resume.
# Intended to run as root (NOPASSWD):  sudo /home/eun/proof_code/llm/orch_supervisor.sh
set -u

PROOF=/home/eun/proof_code
SEV=/home/eun/esp_bak/sev-step
END=2500
KEY=/home/eun/.ssh/id_ed25519
SSH=(ssh -p 7777 -i "$KEY" -o StrictHostKeyChecking=no -o BatchMode=yes -o ConnectTimeout=5 ubuntu@localhost)
LOG=/tmp/orch_auto_supervisor.log
GUEST_LOG=/tmp/guest_relaunch_auto.log
WAKE_TAG='AGENT_LOOP_WAKE_orch_resume'

exec >>"$LOG" 2>&1
echo "supervisor start $(date -Is) pid=$$ uid=$(id -u)"

[ "$(id -u)" = 0 ] || { echo "must run as root: sudo $0"; exit 1; }

qemu_alive() { ps -C qemu-system-x86 --no-headers >/dev/null 2>&1; }
orch_alive() {
  # Match the real orchestrate python process only (absolute interpreter+script).
  pgrep -f '^/usr/bin/python3 -u /home/eun/proof_code/orchestrate\.py ' >/dev/null 2>&1
}
ssh_ok() { timeout 8 "${SSH[@]}" 'echo ok' 2>/dev/null | grep -q ok; }

wake() {
  # stdout is the log; also echo a wake line the agent watches for
  printf '%s %s\n' "$WAKE_TAG" "$1"
}

last_idx() {
  python3 - <<'PY'
import csv
last = None
with open("/home/eun/proof_code/match_rate.csv") as f:
    for row in csv.reader(f):
        if len(row) >= 2 and row[1].isdigit():
            last = int(row[1])
print(last if last is not None else -1)
PY
}

wait_ssh() {
  local i
  for i in $(seq 1 120); do
    qemu_alive || { echo "qemu died while waiting ssh"; return 1; }
    ssh_ok && { echo "ssh ready ($i)"; return 0; }
    echo "$(date -Is) waiting ssh ($i)"
    sleep 5
  done
  echo "ssh timeout"; return 1
}

relaunch_guest() {
  echo "$(date -Is) relaunch guest"
  # Prefer PID kill — pkill -f matches itself and can no-op.
  for pid in $(ps -C qemu-system-x86 -o pid= 2>/dev/null); do
    kill -9 "$pid" 2>/dev/null || true
  done
  for pid in /proc/[0-9]*; do
    cmd=$(tr "\0" " " <"$pid/cmdline" 2>/dev/null || true)
    case "$cmd" in
      *launch-qemu-noncc.sh*) kill -9 "${pid#/proc/}" 2>/dev/null || true ;;
    esac
  done
  sleep 2
  rm -f /tmp/qemu-monitor.sock /tmp/qmp-sock
  cd "$SEV" || return 1
  : >"$GUEST_LOG"
  setsid ./launch-qemu-noncc.sh -cc </dev/null >>"$GUEST_LOG" 2>&1 &
  sleep 5
  qemu_alive || { echo "qemu failed to start"; tail -40 "$GUEST_LOG"; return 1; }
  wait_ssh || return 1
}

run_preflight() {
  echo "$(date -Is) net_preflight"
  "$PROOF/llm/net_preflight.sh"
}

start_orch() {
  local start
  start=$(last_idx)
  start=$((start + 1))
  if [ "$start" -gt "$END" ]; then
    echo "done: last=$((start - 1)) >= END=$END"
    wake "{\"prompt\":\"batch complete through $END; supervisor stopping\",\"reason\":\"batch_done\",\"last\":$((start - 1))}"
    return 2
  fi
  echo "$(date -Is) start orchestrate --start $start --end $END"
  pkill -f 'python3 -u .*orchestrate\.py' 2>/dev/null || true
  sleep 1
  cd "$PROOF" || return 1
  # system python under root; -u unbuffered; append collect_log
  nohup /usr/bin/python3 -u "$PROOF/orchestrate.py" --start "$start" --end "$END" --use-main \
    >>"$PROOF/collect_log.txt" 2>&1 &
  local i
  for i in 1 2 3 4 5 6 7 8 9 10; do
    orch_alive && break
    sleep 1
  done
  orch_alive || { echo "orch failed to start"; return 1; }
  wake "{\"prompt\":\"auto-resumed orchestrate --start $start --end $END\",\"reason\":\"auto_resumed\",\"start\":$start}"
  return 0
}

recover() {
  echo "$(date -Is) RECOVER begin"
  wake "{\"prompt\":\"supervisor auto-recovering (relaunch+preflight+resume if needed)\",\"reason\":\"auto_recover_start\"}"
  pkill -f 'python3 -u .*orchestrate\.py' 2>/dev/null || true
  if ! qemu_alive || ! ssh_ok; then
    relaunch_guest || return 1
  else
    echo "guest already up with ssh"
  fi
  run_preflight || return 1
  start_orch
  return $?
}

fail_streak=0
while true; do
  if qemu_alive && orch_alive; then
    fail_streak=0
    if ! ssh_ok; then
      echo "$(date -Is) warn: qemu up but ssh down"
      sleep 15
      if ! ssh_ok; then
        echo "$(date -Is) ssh still down — recover"
        recover || fail_streak=$((fail_streak + 1))
      fi
    fi
  else
    echo "$(date -Is) unhealthy qemu=$(qemu_alive && echo y || echo n) orch=$(orch_alive && echo y || echo n)"
    recover
    rc=$?
    if [ "$rc" -eq 2 ]; then
      echo "batch complete — supervisor exiting"
      exit 0
    elif [ "$rc" -ne 0 ]; then
      fail_streak=$((fail_streak + 1))
      echo "recover failed streak=$fail_streak"
      sleep $(( fail_streak < 6 ? fail_streak * 20 : 120 ))
      continue
    fi
  fi
  sleep 20
done
