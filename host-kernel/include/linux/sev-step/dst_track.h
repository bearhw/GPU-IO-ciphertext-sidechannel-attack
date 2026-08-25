/* SPDX-License-Identifier: GPL-2.0 */
/*
 * dst_track.h – Kernel-internal API for SEV-Step Dst-Page tracking.
 *
 * Detects which guest pages the CPU *writes* after data arrives from
 * a GPU DMA bounce buffer (the "Dst Pages" in store [Bounce Buffer] /
 * store [Dst]).
 *
 * Complements src_track (reads before bounce write) and dma_track
 * (bounce buffer faults).  All three can run simultaneously.
 *
 * Each logged write fault carries the current dma_current_window_id so
 * userspace can correlate directly: if a D2H window (IOMMU_WRITE) has
 * id=N, write faults with dma_window_id=N that arrive after
 * window.unmap_ts_ns are candidates for the destination page.
 *
 * Lives in kvm.ko (arch/x86/kvm/sev-step/dst_track.c).
 * Consumed by:
 *   - arch/x86/kvm/mmu/mmu.c  (dst_track_log_fault in NPF hot path)
 *   - virt/kvm/kvm_main.c     (ioctl dispatch)
 */
#ifndef _SEV_STEP_DST_TRACK_H
#define _SEV_STEP_DST_TRACK_H

#include <linux/types.h>
#include <linux/atomic.h>
#include <linux/mutex.h>

/* Same ring size as src_track / dma_track */
#define DST_FAULT_RING_SIZE  131072

/* ── in-kernel fault entry (32 bytes) ─────────────────────────── */
struct dst_fault_entry {
	u64  fault_gpa;       /* destination GPA (GFN << PAGE_SHIFT)    */
	u64  timestamp_ns;    /* ktime_get_ns() at fault                */
	u64  dma_window_id;   /* dma_current_window_id at fault time    */
	u32  vcpu_id;
	u8   _pad[4];
};

/* ── ring-buffer state ─────────────────────────────────────────── */
struct dst_fault_ring {
	struct dst_fault_entry  entries[DST_FAULT_RING_SIZE];
	atomic_t                head;
	u32                     drain_tail;
	struct mutex            drain_mutex;
};

/* ── globals exported from kvm.ko ──────────────────────────────── */
extern atomic_t              dst_tracking_enabled;
extern struct dst_fault_ring dst_fring;

/* ── API ──────────────────────────────────────────────────────── */
/* Hot path – write faults only, lockless write side */
void dst_track_log_fault(u64 gfn, u32 vcpu_id);

int  dst_track_enable(u64 start_gfn, u64 nr_pages);
int  dst_track_disable(void);
int  dst_track_drain(void __user *argp);

#endif /* _SEV_STEP_DST_TRACK_H */
