#!/bin/bash
# One-shot hard relaunch. Avoid pkill -f self-match.
set -u
LOG=/tmp/guest_relaunch_manual.log
SEV=/path/to/sev-step

echo "[relaunch] $(date -Is) begin"

# Stop supervisor (exact path match via /proc)
for pid in /proc/[0-9]*; do
  cmd=$(tr '\0' ' ' <"$pid/cmdline" 2>/dev/null || true)
  case "$cmd" in
    *"/path/to/proof_code/llm/orch_supervisor.sh"*)
      echo "[relaunch] kill supervisor ${pid#/proc/}"
      kill -9 "${pid#/proc/}" 2>/dev/null || true
      ;;
  esac
done

# Kill qemu by comm
for pid in $(ps -C qemu-system-x86 -o pid= 2>/dev/null); do
  echo "[relaunch] kill qemu $pid"
  kill -9 "$pid" 2>/dev/null || true
done

# Kill launch-qemu bash parents
for pid in /proc/[0-9]*; do
  cmd=$(tr '\0' ' ' <"$pid/cmdline" 2>/dev/null || true)
  case "$cmd" in
    *"/bin/bash ./launch-qemu-noncc.sh"*|*"bash /path/to/sev-step/launch-qemu-noncc.sh"*)
      echo "[relaunch] kill launch ${pid#/proc/}"
      kill -9 "${pid#/proc/}" 2>/dev/null || true
      ;;
  esac
done

sleep 2
if ps -C qemu-system-x86 --no-headers >/dev/null 2>&1; then
  echo "[relaunch] ERROR qemu still alive" >&2
  ps -C qemu-system-x86 -o pid,etime,cmd
  exit 1
fi

rm -f /tmp/qemu-monitor.sock /tmp/qmp-sock
ip link show tap0 >/dev/null 2>&1 && ip link delete tap0 2>/dev/null || true

: >"$LOG"
cd "$SEV"
setsid ./launch-qemu-noncc.sh -cc </dev/null >>"$LOG" 2>&1 &
echo "[relaunch] launch bg=$!"
sleep 5
if ! ps -C qemu-system-x86 --no-headers >/dev/null 2>&1; then
  echo "[relaunch] ERROR qemu did not start" >&2
  cat "$LOG"
  exit 1
fi
echo "[relaunch] qemu pid=$(ps -C qemu-system-x86 -o pid= | tr -d ' ')"
ip -br link show tap0 || true
head -8 "$LOG"
echo "[relaunch] OK — waiting for SSH left to caller/supervisor"
