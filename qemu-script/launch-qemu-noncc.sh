#!/bin/bash

#
# Non-Confidential VM Launcher (SEV-SNP optional)
#

# -------------------------
# User-configurable
# -------------------------
EXEC_PATH="/home/eun/esp_bak/sev-step/local-installation/usr/local"
UEFI_PATH="${EXEC_PATH}/share/qemu"
VDD_IMAGE="/home/eun/usenix.qcow2"
NVIDIA_GPU="0000:61:00.0"

MEM_GB=256
SMP_CORES=1
FWDPORT=7777

TAP_IF="tap0"
TAP_HOST_IP="192.168.100.1"
TAP_MTU=9000

USE_CC=0
DO_ECHO=0

# -------------------------
# Usage
# -------------------------
usage() {
    echo "$0 [options]"
    echo "  -cc              Enable SEV-SNP"
    echo "  -gpu BDF         (ex: 0000:61:00.0)"
    echo "  -mem GB          Memory size in GB"
    echo "  -smp CORES       Number of cores"
    echo "  -p PORT          Forwarded SSH port"
    echo "  -echo            Bind GPU to vfio"
    exit 1
}

# -------------------------
# Root check
# -------------------------
if [ "$(id -u)" -ne 0 ]; then
    echo "Must run as root"
    exit 1
fi

# -------------------------
# Parse args
# -------------------------
while [ -n "$1" ]; do
    case "$1" in
        -cc) USE_CC=1 ;;
        -gpu) NVIDIA_GPU="$2"; shift ;;
        -mem) MEM_GB="$2"; shift ;;
        -smp) SMP_CORES="$2"; shift ;;
        -p) FWDPORT="$2"; shift ;;
        -echo) DO_ECHO=1 ;;
        *) usage ;;
    esac
    shift
done

# -------------------------
# Optional vfio bind
# -------------------------
if [ "$DO_ECHO" = "1" ]; then
    echo "[+] Binding GPU to vfio-pci"
    modprobe vfio-pci
    echo 10de ${NVIDIA_GPU#0000:} > /sys/bus/pci/drivers/vfio-pci/new_id
fi

# -------------------------
# Resolve paths
# -------------------------
QEMU_EXE="$(readlink -e $EXEC_PATH/bin/qemu-system-x86_64)"
UEFI_CODE="$(readlink -e $UEFI_PATH/OVMF_CODE.fd)"

[ -z "$QEMU_EXE" ] && { echo "QEMU not found"; exit 1; }
[ -z "$UEFI_CODE" ] && { echo "OVMF not found"; exit 1; }

# Create guest-specific VARS
GUEST_NAME="$(basename "$VDD_IMAGE" | sed -re 's|\.[^.]+$||')"
UEFI_VARS="./${GUEST_NAME}.fd"
[ ! -f "$UEFI_VARS" ] && cp "$UEFI_PATH/OVMF_VARS.fd" "$UEFI_VARS"

# -------------------------
# Get cbitpos (for SEV)
# -------------------------
get_cbitpos() {
    modprobe cpuid
    EBX=$(dd if=/dev/cpu/0/cpuid ibs=16 count=32 skip=134217728 2>/dev/null | \
          tail -c 16 | od -An -t u4 -j 4 -N 4 | sed -re 's|^ *||')
    echo $((EBX & 0x3f))
}

# -------------------------
# Build QEMU cmd
# -------------------------

CMD=""

CMD+=" $QEMU_EXE"
CMD+=" -enable-kvm"
CMD+=" -machine q35,accel=kvm,kernel-irqchip=split"
CMD+=" -cpu EPYC-v4"
CMD+=" -smp ${SMP_CORES}"
CMD+=" -m ${MEM_GB}G,slots=2,maxmem=512G"
CMD+=" -nographic"
CMD+=" -no-reboot"

# OVMF 64-bit MMIO window (for GPU BAR mapping)
CMD+=" -fw_cfg name=opt/ovmf/X-PciMmio64Mb,string=262144"

# UEFI
CMD+=" -drive if=pflash,format=raw,unit=0,file=${UEFI_CODE},readonly=on"
CMD+=" -drive if=pflash,format=raw,unit=1,file=${UEFI_VARS}"

# Disk
CMD+=" -drive file=${VDD_IMAGE},if=none,id=disk0,format=qcow2,cache=none"
CMD+=" -device virtio-scsi-pci,id=scsi0,disable-legacy=on,iommu_platform=true"
CMD+=" -device scsi-hd,drive=disk0"

# Network – SLIRP (SSH port forward)
CMD+=" -netdev user,id=vmnic,hostfwd=tcp::${FWDPORT}-:22"
CMD+=" -device virtio-net-pci,disable-legacy=on,iommu_platform=true,netdev=vmnic,romfile="

# Network – TAP (direct host<->guest, for large ICMP / SEV-Step tracking)
CMD+=" -netdev tap,id=tapnet,ifname=${TAP_IF},script=no,downscript=no"
CMD+=" -device virtio-net-pci,netdev=tapnet,id=net-tap,romfile="

# GPU passthrough
CMD+=" -device pcie-root-port,id=pci.1,bus=pcie.0"
CMD+=" -device vfio-pci,host=${NVIDIA_GPU},bus=pci.1"

# Monitors
CMD+=" -monitor unix:/tmp/qemu-monitor.sock,server,nowait"
CMD+=" -qmp unix:/tmp/qmp-sock,server,nowait"

# -------------------------
# Optional SEV-SNP
# -------------------------
if [ "$USE_CC" = "1" ]; then
    echo "[+] Enabling SEV-SNP"
    CBITPOS=$(get_cbitpos)
    CMD+=" -machine memory-encryption=sev0,vmport=off"
    CMD+=" -object sev-snp-guest,policy=0xb0000,id=sev0,cbitpos=${CBITPOS},reduced-phys-bits=1"
fi

# -------------------------
# TAP setup
# -------------------------
echo "[+] Setting up TAP interface: ${TAP_IF}  host IP: ${TAP_HOST_IP}/24"
ip tuntap add "${TAP_IF}" mode tap 2>/dev/null || true
ip addr flush dev "${TAP_IF}" 2>/dev/null || true
ip addr add "${TAP_HOST_IP}/24" dev "${TAP_IF}"
ip link set "${TAP_IF}" mtu "${TAP_MTU}"
ip link set "${TAP_IF}" up

# Remove TAP on exit
trap 'echo "[+] Removing TAP ${TAP_IF}"; ip link set "${TAP_IF}" down; ip tuntap del "${TAP_IF}" mode tap' EXIT

# -------------------------
# Launch
# -------------------------
echo "=============================="
echo "$CMD"
echo "=============================="
eval $CMD

