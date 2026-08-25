/* SPDX-License-Identifier: GPL-2.0 */
/*
 * src_track.h – Kernel-internal API for SEV-Step Src-Page tracking.
 *
 * Detects which guest pages were read by the CPU before data arrived
 * in a DMA bounce buffer (the "Src Pages" in load [Src] / store [BB]).
 *
 * Lives in kvm.ko (arch/x86/kvm/sev-step/src_track.c).
 * Consumed by:
 *   - arch/x86/kvm/mmu/mmu.c  (src_track_log_fault in NPF hot path)
 *   - virt/kvm/kvm_main.c     (ioctl dispatch)
 */
#ifndef _SEV_STEP_SRC_TRACK_H
#define _SEV_STEP_SRC_TRACK_H

#include <linux/types.h>
#include <linux/atomic.h>
#include <linux/mutex.h>

/* Ring size: same as DMA tracking (8192 slots = 256 KB at 32 B/entry) */
#define SRC_FAULT_RING_SIZE  131072

/* ── in-kernel fault entry (32 bytes, cache-line friendly) ────── */
struct src_fault_entry {
	u64  fault_gpa;       /* faulting guest physical address        */
	u64  timestamp_ns;    /* ktime_get_ns() at fault time           */
	u32  vcpu_id;         /* vCPU that caused the fault             */
	u8   is_write;        /* 0=read (Src access)  1=write           */
	u8   _pad[3];
};

/* ── ring-buffer state ─────────────────────────────────────────── */
struct src_fault_ring {
	struct src_fault_entry  entries[SRC_FAULT_RING_SIZE];
	atomic_t                head;        /* monotonic write counter   */
	u32                     drain_tail;  /* last position drained     */
	struct mutex            drain_mutex; /* serialises drain callers  */
};

/* ── globals defined in src_track.c, exported from kvm.ko ─────── */
extern atomic_t              src_tracking_enabled;
extern struct src_fault_ring src_fring;

/* ── API ──────────────────────────────────────────────────────── */
/* Hot path – called from mmu.c, lockless write side. */
void src_track_log_fault(u64 gfn, u32 vcpu_id, bool is_write);

/* Ioctl handlers called from kvm_dev_ioctl. */
int  src_track_enable(u64 start_gfn, u64 nr_pages);
int  src_track_disable(void);
int  src_track_drain(void __user *argp);

#endif /* _SEV_STEP_SRC_TRACK_H */
