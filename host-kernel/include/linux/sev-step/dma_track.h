/* SPDX-License-Identifier: GPL-2.0 */
/*
 * dma_track.h – Kernel-internal API for SEV-Step DMA page-access tracking.
 *
 * Lives in kvm.ko (arch/x86/kvm/sev-step/dma_track.c).
 * Consumed by:
 *   - arch/x86/kvm/mmu/mmu.c  (dma_track_log_fault in NPF hot path)
 *   - virt/kvm/kvm_main.c     (ioctl dispatch)
 *   - drivers/vfio/vfio_iommu_type1.c (calls hook fn-ptrs exported here)
 */
#ifndef _SEV_STEP_DMA_TRACK_H
#define _SEV_STEP_DMA_TRACK_H

#include <linux/types.h>
#include <linux/atomic.h>
#include <linux/spinlock.h>
#include <linux/mutex.h>
#include <linux/dma-mapping.h>   /* dma_addr_t */

/* ── sizes (both powers of two) ───────────────────────────────── */
#define DMA_FAULT_RING_SIZE   8192   /* fault ring-buffer slots      */
#define DMA_WINDOW_LOG_SIZE    128   /* concurrent trackable windows */

/* ── in-kernel fault entry ────────────────────────────────────── */
struct dma_fault_entry {
	u64  fault_gpa;       /* faulting guest physical address        */
	u64  timestamp_ns;    /* ktime_get_ns() at fault time           */
	u64  dma_window_id;   /* window active when tracking was applied*/
	u8   is_write;        /* 0=read  1=write (from fault->write)    */
	u8   is_shared;       /* 1=RMP shows page shared (DMA-capable)  */
	u8   _pad[6];
};

/* ── per-window metadata ───────────────────────────────────────── */
struct dma_window_entry {
	u64      window_id;
	u64      iova;          /* start IOVA == GPA for QEMU identity   */
	u64      size;          /* byte span                             */
	int      prot;          /* IOMMU_READ | IOMMU_WRITE              */
	u64      map_ts_ns;     /* ktime at MAP_DMA                      */
	u64      unmap_ts_ns;   /* ktime at UNMAP; 0 while active        */
	atomic_t nr_faults;     /* approx count (racy, best-effort)      */
	bool     valid;
};

/* ── ring-buffer state ─────────────────────────────────────────── */
struct dma_fault_ring {
	struct dma_fault_entry  entries[DMA_FAULT_RING_SIZE];
	atomic_t                head;        /* monotonic write counter   */
	u32                     drain_tail;  /* last position drained     */
	struct mutex            drain_mutex; /* serialises drain callers  */
};

/* ── globals defined in dma_track.c, exported from kvm.ko ─────── */
extern atomic_t               dma_tracking_enabled;
extern atomic64_t             dma_current_window_id;
extern struct dma_fault_ring  dma_fring;
extern struct dma_window_entry dma_win_table[DMA_WINDOW_LOG_SIZE];
extern spinlock_t             dma_win_lock;
extern u32                    dma_win_head;
extern u32                    dma_win_drain_tail;

/*
 * VFIO hook fn-ptrs – defined and EXPORT_SYMBOL'd by dma_track.c so
 * that vfio_iommu_type1.c can call them without compile-time linking
 * to kvm.ko.  Non-NULL only while dma_track_enable() is active.
 */
extern void (*sev_step_dma_map_hook)(dma_addr_t iova,
				     size_t size, int prot);
extern void (*sev_step_dma_unmap_hook)(dma_addr_t iova,
				       size_t size, int prot);

/* ── API ──────────────────────────────────────────────────────── */
/* Hot path – called from mmu.c, must stay lockless on write side. */
void dma_track_log_fault(u64 gfn, bool is_write);

/* Ioctl handlers called from kvm_dev_ioctl / kvm_vm_ioctl. */
int  dma_track_enable(void);
int  dma_track_disable(void);
int  dma_track_drain(void __user *argp);

#endif /* _SEV_STEP_DMA_TRACK_H */
