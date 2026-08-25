// SPDX-License-Identifier: GPL-2.0
/*
 * dma_track.c – SEV-Step DMA page-access tracking engine.
 *
 * Provides a non-blocking (lockless-write) ring buffer for logging nested
 * page faults that fire on guest pages tracked during VFIO DMA windows.
 * This complements the synchronous usp_send_and_block() path which is
 * too slow for DMA-scale fault rates.
 *
 * Architecture
 * ============
 *  1. On VFIO MAP_DMA  → sev_step_dma_map_hook() fires (called by VFIO).
 *     We record a dma_window_entry and batch-apply KVM page tracking to
 *     every GFN in [iova, iova+size) using the no-flush variant, then
 *     flush TLBs once with kvm_flush_remote_tlbs().
 *
 *  2. On each NPF for a tracked page → page_fault_handle_page_track()
 *     in mmu.c calls dma_track_log_fault().  We write one dma_fault_entry
 *     into the lockless ring buffer using atomic_fetch_add for the slot.
 *
 *  3. On VFIO UNMAP_DMA → sev_step_dma_unmap_hook() stamps unmap_ts_ns.
 *
 *  4. KVM_DMA_TRACK_DRAIN ioctl → userspace drains windows + faults.
 *
 * SNP / RMP note
 * ==============
 * DMA buffers MUST be in "shared" (C=0) state for the IOMMU to forward
 * them to the device.  In SNP the guest calls pvalidate(SHARED) before
 * pinning memory for DMA.  We tag all logged faults is_shared=1.
 *
 * Module dependency
 * =================
 * sev_step_dma_map_hook / sev_step_dma_unmap_hook are defined and
 * EXPORT_SYMBOL'd here (in kvm.ko).  vfio_iommu_type1.ko takes extern
 * references; kvm.ko must be loaded before vfio_iommu_type1.ko which is
 * the normal order for a VM-hosting system.
 */

#include <linux/types.h>
#include <linux/atomic.h>
#include <linux/spinlock.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/ktime.h>
#include <linux/printk.h>
#include <linux/export.h>
#include <linux/ratelimit.h>
#include <linux/kvm_host.h>
#include <linux/dma-mapping.h>

#include <asm/kvm_host.h>
#include <asm/kvm_page_track.h>

#include "../mmu/mmu_internal.h"
#include <linux/sev-step/sev-step.h>
#include <linux/sev-step/dma_track.h>
#include <uapi/linux/kvm.h>

/* ── global state ──────────────────────────────────────────────── */

atomic_t dma_tracking_enabled = ATOMIC_INIT(0);
EXPORT_SYMBOL(dma_tracking_enabled);

atomic64_t dma_current_window_id = ATOMIC64_INIT(0);
EXPORT_SYMBOL(dma_current_window_id);

struct dma_fault_ring dma_fring;
EXPORT_SYMBOL(dma_fring);

struct dma_window_entry dma_win_table[DMA_WINDOW_LOG_SIZE];
EXPORT_SYMBOL(dma_win_table);

DEFINE_SPINLOCK(dma_win_lock);
EXPORT_SYMBOL(dma_win_lock);

/* Next slot to write in dma_win_table (monotonic, mod on access). */
u32 dma_win_head;
EXPORT_SYMBOL(dma_win_head);

/* Last slot returned to userspace. Protected by dma_fring.drain_mutex. */
u32 dma_win_drain_tail;
EXPORT_SYMBOL(dma_win_drain_tail);

/* ── VFIO hook function pointers ───────────────────────────────── */
/*
 * Set to the real implementations when tracking is enabled, NULL when
 * disabled.  vfio_iommu_type1.c calls these with a null-guard.
 */
/* Defined in drivers/vfio/vfio_iommu_type1.c (built-in); kvm.ko writes them. */
extern void (*sev_step_dma_map_hook)(dma_addr_t iova, size_t size, int prot);
extern void (*sev_step_dma_unmap_hook)(dma_addr_t iova, size_t size, int prot);

/* ── one-time init (idempotent) ────────────────────────────────── */

static bool dma_track_inited;

static void dma_track_init_once(void)
{
	if (dma_track_inited)
		return;

	mutex_init(&dma_fring.drain_mutex);
	atomic_set(&dma_fring.head, 0);
	dma_fring.drain_tail = 0;

	spin_lock_init(&dma_win_lock);
	memset(dma_win_table, 0, sizeof(dma_win_table));
	dma_win_head       = 0;
	dma_win_drain_tail = 0;

	dma_track_inited = true;
	pr_info("dma_track: initialised  ring=%u entries  win-table=%u slots\n",
		DMA_FAULT_RING_SIZE, DMA_WINDOW_LOG_SIZE);
}

/* ── VFIO MAP_DMA handler ──────────────────────────────────────── */

static void dma_track_on_map(dma_addr_t iova, size_t size, int prot)
{
	u64    window_id;
	u32    slot;
	struct dma_window_entry *win;
	struct kvm  *kvm;
	struct kvm_vcpu *vcpu;
	u64    gfn, gfn_start, gfn_end;
	long   tracked = 0;
	enum   kvm_page_track_mode mode;
	struct kvm_memory_slot *memslot;
	int    srcu_idx;
	unsigned long flags;

	window_id = (u64)atomic64_fetch_add(1, &dma_current_window_id) + 1;

	pr_info("dma_track: MAP_DMA window_id=%llu iova=0x%llx "
		"size=0x%zx pages=%zu prot=0x%x pid=%d comm=%.16s\n",
		window_id, (u64)iova, size,
		size >> PAGE_SHIFT, prot,
		current->pid, current->comm);

	/* Record window metadata. */
	spin_lock_irqsave(&dma_win_lock, flags);
	slot = dma_win_head % DMA_WINDOW_LOG_SIZE;
	win  = &dma_win_table[slot];
	win->window_id   = window_id;
	win->iova        = (u64)iova;
	win->size        = (u64)size;
	win->prot        = prot;
	win->map_ts_ns   = ktime_get_ns();
	win->unmap_ts_ns = 0;
	win->valid       = true;
	atomic_set(&win->nr_faults, 0);
	dma_win_head++;
	spin_unlock_irqrestore(&dma_win_lock, flags);

	atomic64_set(&dma_current_window_id, window_id);

	kvm = global_sev_step_config.main_vm;
	if (!kvm) {
		pr_warn("dma_track: MAP hook: main_vm==NULL "
			"(SEV-Step not yet connected?)\n");
		return;
	}

	/*
	 * Always track ACCESS (clears P-bit) so we catch both reads and
	 * writes.  Direction is determined in userspace from dma->prot
	 * and fault timestamps.
	 */
	mode = KVM_PAGE_TRACK_ACCESS;

	gfn_start = (u64)iova >> PAGE_SHIFT;
	gfn_end   = ((u64)iova + size + PAGE_SIZE - 1) >> PAGE_SHIFT;

	vcpu = kvm_get_vcpu(kvm, 0);
	if (!vcpu) {
		pr_warn("dma_track: MAP hook: no vCPU[0], skipping tracking\n");
		return;
	}

	pr_info("dma_track: batch-tracking GFNs [0x%llx, 0x%llx) "
		"(%llu pages, mode=ACCESS)\n",
		gfn_start, gfn_end, gfn_end - gfn_start);

	srcu_idx = srcu_read_lock(&kvm->srcu);
	write_lock(&kvm->mmu_lock);

	for (gfn = gfn_start; gfn < gfn_end; gfn++) {
		memslot = kvm_vcpu_gfn_to_memslot(vcpu, gfn);
		if (!memslot)
			continue;
		if (kvm_page_track_is_active(vcpu, gfn, mode))
			continue;
		kvm_slot_page_track_add_page_no_flush(kvm, memslot, gfn, mode);
		tracked++;
	}

	write_unlock(&kvm->mmu_lock);
	srcu_read_unlock(&kvm->srcu, srcu_idx);

	if (tracked > 0)
		kvm_flush_remote_tlbs(kvm);

	pr_info("dma_track: MAP_DMA window_id=%llu: tracked %ld/%llu GFNs\n",
		window_id, tracked, gfn_end - gfn_start);
}

/* ── VFIO UNMAP_DMA handler ────────────────────────────────────── */

static void dma_track_on_unmap(dma_addr_t iova, size_t size, int prot)
{
	u32 i;
	unsigned long flags;
	u64 matched_id = 0;

	pr_info("dma_track: UNMAP_DMA iova=0x%llx size=0x%zx "
		"prot=0x%x pid=%d comm=%.16s\n",
		(u64)iova, size, prot, current->pid, current->comm);

	/* Walk backwards to find the most-recent matching active window. */
	spin_lock_irqsave(&dma_win_lock, flags);
	for (i = 0; i < DMA_WINDOW_LOG_SIZE; i++) {
		u32 idx = (dma_win_head - 1 - i) % DMA_WINDOW_LOG_SIZE;
		struct dma_window_entry *w = &dma_win_table[idx];

		if (!w->valid)
			continue;
		if (w->iova == (u64)iova &&
		    w->size == (u64)size &&
		    w->unmap_ts_ns == 0) {
			w->unmap_ts_ns = ktime_get_ns();
			matched_id     = w->window_id;
			pr_info("dma_track: UNMAP matched window_id=%llu "
				"faults=%d\n",
				w->window_id, atomic_read(&w->nr_faults));
			break;
		}
	}
	spin_unlock_irqrestore(&dma_win_lock, flags);

	if (!matched_id)
		pr_warn("dma_track: UNMAP iova=0x%llx: no active window matched\n",
			(u64)iova);
}

/* ── NPF fault logger (hot path – called from mmu.c) ───────────── */

void dma_track_log_fault(u64 gfn, bool is_write)
{
	u32 idx;
	struct dma_fault_entry *e;
	u64 win_id;
	u32 win_slot;

	/*
	 * Lockless ring-buffer write: each caller atomically claims a unique
	 * slot index, then fills it in place.
	 * Multi-CPU races write to different slots so no slot-level lock
	 * is needed.  The reader (drain) uses READ_ONCE on each field.
	 */
	idx    = (u32)atomic_fetch_add(1, &dma_fring.head);
	e      = &dma_fring.entries[idx % DMA_FAULT_RING_SIZE];
	win_id = (u64)atomic64_read(&dma_current_window_id);

	WRITE_ONCE(e->fault_gpa,     gfn << PAGE_SHIFT);
	WRITE_ONCE(e->timestamp_ns,  ktime_get_ns());
	WRITE_ONCE(e->dma_window_id, win_id);
	WRITE_ONCE(e->is_write,      is_write ? 1 : 0);
	WRITE_ONCE(e->is_shared,     1); /* DMA pages are shared by definition */

	/* Best-effort fault counter on the most recent window (racy is OK). */
	win_slot = (READ_ONCE(dma_win_head) - 1) % DMA_WINDOW_LOG_SIZE;
	if (READ_ONCE(dma_win_table[win_slot].window_id) == win_id &&
	    READ_ONCE(dma_win_table[win_slot].valid))
		atomic_inc(&dma_win_table[win_slot].nr_faults);

	pr_info_ratelimited("dma_track: FAULT gpa=0x%llx %s win=%llu idx=%u\n",
			    gfn << PAGE_SHIFT,
			    is_write ? "W" : "R",
			    win_id,
			    idx % DMA_FAULT_RING_SIZE);
}
EXPORT_SYMBOL(dma_track_log_fault);

/* ── ioctl: KVM_DMA_TRACK_ENABLE ───────────────────────────────── */

int dma_track_enable(void)
{
	dma_track_init_once();

	WRITE_ONCE(sev_step_dma_map_hook,   dma_track_on_map);
	WRITE_ONCE(sev_step_dma_unmap_hook, dma_track_on_unmap);
	atomic_set(&dma_tracking_enabled, 1);

	pr_info("dma_track: ENABLED\n");
	pr_info("dma_track:  ring-buffer  = %u slots (%zu KB)\n",
		DMA_FAULT_RING_SIZE,
		(DMA_FAULT_RING_SIZE * sizeof(struct dma_fault_entry)) >> 10);
	pr_info("dma_track:  window-table = %u slots\n", DMA_WINDOW_LOG_SIZE);
	pr_info("dma_track:  main_vm      = %p  main_vm_pid=%d\n",
		global_sev_step_config.main_vm,
		global_sev_step_config.main_vm_pid);
	return 0;
}
EXPORT_SYMBOL(dma_track_enable);

/* ── ioctl: KVM_DMA_TRACK_DISABLE ──────────────────────────────── */

int dma_track_disable(void)
{
	atomic_set(&dma_tracking_enabled, 0);
	WRITE_ONCE(sev_step_dma_map_hook,   NULL);
	WRITE_ONCE(sev_step_dma_unmap_hook, NULL);
	pr_info("dma_track: DISABLED\n");
	return 0;
}
EXPORT_SYMBOL(dma_track_disable);

/* ── ioctl: KVM_DMA_TRACK_DRAIN ────────────────────────────────── */

int dma_track_drain(void __user *argp)
{
	struct kvm_dma_drain_param param;
	struct kvm_dma_window_info __user        *uwin;
	struct kvm_dma_fault_log_entry __user    *ufault;
	struct kvm_dma_window_info    kwin;
	struct kvm_dma_fault_log_entry kfault;
	u32 nr_win = 0, nr_fault = 0;
	u32 head_snap, tail, i;
	unsigned long flags;

	if (copy_from_user(&param, argp, sizeof(param))) {
		pr_err("dma_track: DRAIN copy_from_user(param) failed\n");
		return -EFAULT;
	}

	uwin   = (struct kvm_dma_window_info __user *)
		 (uintptr_t)param.windows_ptr;
	ufault = (struct kvm_dma_fault_log_entry __user *)
		 (uintptr_t)param.faults_ptr;

	pr_info("dma_track: DRAIN  max_win=%u max_fault=%u "
		"win_head=%u win_drain=%u ring_head=%u ring_drain=%u\n",
		param.max_windows, param.max_faults,
		dma_win_head, dma_win_drain_tail,
		(u32)atomic_read(&dma_fring.head), dma_fring.drain_tail);

	/* ── windows ─────────────────────────────────────────────── */
	if (param.max_windows > DMA_WINDOW_LOG_SIZE)
		param.max_windows = DMA_WINDOW_LOG_SIZE;

	spin_lock_irqsave(&dma_win_lock, flags);
	head_snap = dma_win_head;
	spin_unlock_irqrestore(&dma_win_lock, flags);

	for (i = dma_win_drain_tail;
	     i != head_snap && nr_win < param.max_windows; i++) {
		u32 slot = i % DMA_WINDOW_LOG_SIZE;
		struct dma_window_entry *w;

		spin_lock_irqsave(&dma_win_lock, flags);
		w = &dma_win_table[slot];
		if (!w->valid) {
			spin_unlock_irqrestore(&dma_win_lock, flags);
			continue;
		}
		kwin.window_id   = w->window_id;
		kwin.iova        = w->iova;
		kwin.size        = w->size;
		kwin.prot        = w->prot;
		kwin.nr_faults   = (u32)atomic_read(&w->nr_faults);
		kwin.map_ts_ns   = w->map_ts_ns;
		kwin.unmap_ts_ns = w->unmap_ts_ns;
		spin_unlock_irqrestore(&dma_win_lock, flags);

		if (uwin && copy_to_user(&uwin[nr_win], &kwin, sizeof(kwin))) {
			pr_err("dma_track: DRAIN copy_to_user(win[%u]) failed\n",
			       nr_win);
			return -EFAULT;
		}
		nr_win++;
	}
	dma_win_drain_tail = head_snap;

	/* ── faults ──────────────────────────────────────────────── */
	if (param.max_faults > DMA_FAULT_RING_SIZE)
		param.max_faults = DMA_FAULT_RING_SIZE;

	mutex_lock(&dma_fring.drain_mutex);

	head_snap = (u32)atomic_read(&dma_fring.head);
	tail      = dma_fring.drain_tail;

	/* Handle ring wrap: only expose the last RING_SIZE entries. */
	if ((head_snap - tail) > DMA_FAULT_RING_SIZE)
		tail = head_snap - DMA_FAULT_RING_SIZE;

	while (tail != head_snap && nr_fault < param.max_faults) {
		u32 slot = tail % DMA_FAULT_RING_SIZE;
		struct dma_fault_entry *fe = &dma_fring.entries[slot];

		kfault.fault_gpa     = READ_ONCE(fe->fault_gpa);
		kfault.timestamp_ns  = READ_ONCE(fe->timestamp_ns);
		kfault.dma_window_id = READ_ONCE(fe->dma_window_id);
		kfault.is_write      = READ_ONCE(fe->is_write);
		kfault.is_shared     = READ_ONCE(fe->is_shared);
		memset(kfault._pad, 0, sizeof(kfault._pad));

		if (ufault &&
		    copy_to_user(&ufault[nr_fault], &kfault, sizeof(kfault))) {
			mutex_unlock(&dma_fring.drain_mutex);
			pr_err("dma_track: DRAIN copy_to_user(fault[%u]) "
			       "failed\n", nr_fault);
			return -EFAULT;
		}
		nr_fault++;
		tail++;
	}
	dma_fring.drain_tail = tail;
	mutex_unlock(&dma_fring.drain_mutex);

	pr_info("dma_track: DRAIN done  windows=%u  faults=%u\n",
		nr_win, nr_fault);

	param.nr_windows = nr_win;
	param.nr_faults  = nr_fault;
	if (copy_to_user(argp, &param, sizeof(param))) {
		pr_err("dma_track: DRAIN copy_to_user(param out) failed\n");
		return -EFAULT;
	}
	return 0;
}
EXPORT_SYMBOL(dma_track_drain);
