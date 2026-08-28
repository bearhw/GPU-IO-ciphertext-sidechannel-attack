# GPU I/O Ciphertext Side-Channel Attack

```
.
├── host-kernel/           # SEV-Step modified Linux kernel (5.19.0-rc6)
├── sev-step-module/       # Kernel module, experiment scripts, logs & plots
│   ├── mnist/             #   MNIST experiment runs
│   ├── mura/              #   MURA experiment runs
│   └── llm/               #   LLM experiment runs
├── qemu-script/           # QEMU VM launcher
├── case_study/
│   ├── host_scripts/      # Shared host-side page-dump pipeline
│   ├── mnist/
│   │   ├── model/         #   Trained models (.pth) & training scripts
│   │   ├── flow/          #   Page dump data
│   │   └── dict/          #   Dictionary build
│   ├── mura/
│   │   ├── DenseNet-MURA-PyTorch/
│   │   ├── dict/          #   Dictionary & XOR analysis
│   │   └── *.pth          #   Trained XOR-slice classifiers
│   └── llm/
│       ├── run_all-v4_*/  #   Blind test results (3 runs)
│       └── dict/          #   Token dictionary & pages
```

## Prerequisites

- Host kernel: `host-kernel/` (SEV-Step patched 5.19.0-rc6)
- QEMU: custom build with SEV-SNP + GPU passthrough support
- Guest: Ubuntu VM with NVIDIA GPU (CC mode), miniconda3
- Host–guest network: tap0 (192.168.100.1/24), guest enp0s4 (192.168.100.2/24), MTU 9000

## 1. Host Kernel (KVM module rebuild)

```bash
cd host-kernel/
sudo make -j$(nproc) M=arch/x86/kvm modules
sudo make modules_install M=arch/x86/kvm/ LOCALVERSION=

sudo rmmod kvm_amd
sudo rmmod kvm
sudo modprobe kvm
sudo modprobe kvm_amd
```

## 2. Launch QEMU VM

```bash
cd qemu-script/

# SEV-SNP + GPU passthrough
sudo ./launch-qemu-noncc.sh -cc

# Without SEV (for debugging)
sudo ./launch-qemu-noncc.sh

# Custom options
sudo ./launch-qemu-noncc.sh -cc -mem 256 -smp 1 -gpu 0000:61:00.0 -p 7777
```

Guest access:
```bash
ssh -p 7777 ubuntu@localhost
```

## 3. Build Write Pattern Tracker

```bash
cd sev-step-module/
make            # builds all: write_pattern_tracker, _B, _desc, _early_exit
make clean
```

Variants:
| Binary | Purpose |
|---|---|
| `write_pattern_tracker` | Tensor page identification (default) |
| `write_pattern_tracker_B` | Region-B precursor + timing-gated image GPA finder |
| `write_pattern_tracker_early_exit` | Early-exit image GPA finder via 0x3f8 precursor |

## 4. Network Preflight (before dict build)

```bash
cd sev-step-module/
sudo ./net_preflight.sh
```

Checks: QEMU running, monitor socket, tap0 up, guest SSH, guest NIC, guest monitor module, ICMP probe.

## 5. Case Study: MNIST

### Host-side write tracker
```bash
cd sev-step-module/

# Automated 6-run experiment (3x bs64, 3x bs1000)
sudo ./mnist_host.sh

# Manual single run
sudo ./write_pattern_tracker --guest-gb 256 --duration 500 > mnist/run1.log 2>&1
```

### Guest-side inference
```bash
# On guest (after host script is waiting):
sudo ./mnist_guest.sh

# Or manual:
sudo /home/ubuntu/miniconda3/bin/python3 /home/ubuntu/cc_uvm/pytorch_uvm310_test/mnist/main.py \
    --batch-size 64 --epochs 1 --no-accel
```

### Dictionary build (page dump pipeline)
```bash
cd case_study/host_scripts/

# Single sample
sudo python3 orchestrate.py --image-gpa 0x... --label 3 --index 30

# Range mode
sudo python3 -u orchestrate.py --start 0 --end 3000 --use-main 2>&1 | tee collect_log.txt

# All samples (skip already collected)
sudo python3 orchestrate.py --all --skip-existing 2>&1 | tee collect_log.txt
```

## 6. Case Study: MURA

### Host-side write tracker
```bash
cd sev-step-module/
sudo ./write_pattern_tracker --duration 300 --settle 0 > /tmp/mura_live.log 2>&1
```

### Guest-side inference
```bash
# On guest:
cd ~/DenseNet-MURA-PyTorch/

# Automated (with host signal coordination)
./run_guest_track.sh [num_runs] [max_iters] [phase]
# e.g.: ./run_guest_track.sh 5 10 valid

# Manual GPA tracking
sudo python3 track_input.py --max_iters 10 --phase valid

# Model training (DenseNet-169)
sudo python3 main.py
```

### Dictionary build & inference
```bash
cd case_study/mura/

# Build XOR dictionary
sudo python3 mura_dict_build.py --build

# Live first-hit capture (run alongside write_pattern_tracker)
sudo --preserve-env=HOME python3 mura_live_first_hit.py \
    --host-log /tmp/mura_live.log --out xor_page_sample.out

# Ground truth inference
sudo --preserve-env=HOME python3 run_infer_ground_truth.py
```

### XOR-slice classifier training
```bash
cd case_study/mura/
conda activate mura
python train_64ref.py 2>&1 | tee train_log.txt
```

## 7. Case Study: LLM

### Host-side write tracker
```bash
cd sev-step-module/llm/

# Automated 3-run experiment
sudo ./final_host.sh

# Manual
sudo ./write_pattern_tracker --duration 500 --settle 3 > final_logs/host_run1.log 2>&1
```

### Guest-side inference
```bash
# scp to guest first:
scp -P 7777 single_inference.py final_guest.sh ubuntu@localhost:~/

# On guest:
sudo ./final_guest.sh
```

### Dictionary build & blind test
```bash
cd case_study/llm/

# Build token dictionary
sudo python3 orchestrate_v4.py --build --log-file v4-build.log

# Run blind sweep (all filtered samples)
sudo python3 orchestrate_v4.py --run-all --log-file v4-run.log
```

## Experiment Workflow (typical order)

1. Build & install host kernel KVM modules
2. `sudo ./launch-qemu-noncc.sh -cc` — launch SEV-SNP VM with GPU
3. `sudo ./net_preflight.sh` — verify host–guest packet path
4. `make` in `sev-step-module/` — build write_pattern_tracker
5. Start host-side tracker, then guest-side inference
6. Run dictionary build / blind test scripts
