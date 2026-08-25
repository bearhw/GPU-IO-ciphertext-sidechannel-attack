// SPDX-License-Identifier: GPL-2.0
/*
 * nv_bb_track.c – NVIDIA CC GPU bounce-buffer detection + H2D correlation.
 *
 * Two subsystems:
 *
 * === Step 1: PSC event tracking ===
 *  KVM_PSC_TRACK_ENABLE/DISABLE/DRAIN — logs PSC events for userspace
 *  bounce-buffer detection.
 *
 * === Steps 2-3: NPT fault tracking + kernel-side correlation ===
 *  KVM_NV_BB_START   — write-protects BB pages (KVM_PAGE_TRACK_WRITE)
 *                      and unmaps all private memory (KVM_PAGE_TRACK_ACCESS).
 *  KVM_NV_BB_DRAIN   — drains correlated (src → bb) transfer pairs.
 *  KVM_NV_BB_REARM   — batch re-unmaps all private pages.
 *  KVM_NV_BB_STOP    — tears down all tracking.
 *
 * Correlation engine (nv_bb_handle_fault, called from mmu.c):
 *   - READ fault on private page  → store as vcpu's "last read"
 *   - WRITE fault on bounce buffer → correlate with last read → emit pair
 *   - BB pages re-armed immediately; private pages re-armed via REARM ioctl
 */

#include <linux/types.h>
#include <linux/atomic.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/ktime.h>
#include <linux/printk.h>
#include <linux/export.h>
#include <linux/kvm_host.h>

#include <asm/kvm_host.h>
#include <asm/kvm_page_track.h>

#include "../mmu/mmu_internal.h"
#include <linux/sev-step/sev-step.h>
#include <linux/sev-step/nv_bb_track.h>
#include <uapi/linux/kvm.h>

/* ══════════════════════════════════════════════════════════════════
 *  Step 1: PSC event tracking (unchanged)
 * ══════════════════════════════════════════════════════════════════ */

atomic_t psc_tracking_enabled = ATOMIC_INIT(0);
EXPORT_SYMBOL(psc_tracking_enabled);

struct psc_event_ring psc_ring;
EXPORT_SYMBOL(psc_ring);

static bool psc_track_inited;

static void psc_track_init_once(void)
{
	if (psc_track_inited)
		return;
	mutex_init(&psc_ring.drain_mutex);
	atomic_set(&psc_ring.head, 0);
	psc_ring.drain_tail = 0;
	psc_track_inited = true;
	pr_info("nv_bb_track: psc_ring initialised (%u entries)\n",
		PSC_EVENT_RING_SIZE);
}

void nv_bb_psc_event(u32 vcpu_id, u64 gpa, u8 op, u8 level)
{
	u32 idx;
	struct psc_event_entry *e;

	idx = (u32)atomic_fetch_add(1, &psc_ring.head);
	e   = &psc_ring.entries[idx % PSC_EVENT_RING_SIZE];

	WRITE_ONCE(e->gpa,          gpa);
	WRITE_ONCE(e->timestamp_ns, ktime_get_ns());
	WRITE_ONCE(e->vcpu_id,      vcpu_id);
	WRITE_ONCE(e->op,           op);
	WRITE_ONCE(e->level,        level);
}
EXPORT_SYMBOL(nv_bb_psc_event);

int psc_track_enable(void)
{
	psc_track_init_once();
	atomic_set(&psc_ring.head, 0);
	psc_ring.drain_tail = 0;
	atomic_set(&psc_tracking_enabled, 1);
	pr_info("nv_bb_track: PSC tracking ENABLED\n");
	return 0;
}
EXPORT_SYMBOL(psc_track_enable);

int psc_track_disable(void)
{
	atomic_set(&psc_tracking_enabled, 0);
	pr_info("nv_bb_track: PSC tracking DISABLED\n");
	return 0;
}
EXPORT_SYMBOL(psc_track_disable);

int psc_track_drain(void __user *argp)
{
	struct kvm_psc_drain_param   param;
	struct kvm_psc_event __user *uevents;
	struct kvm_psc_event         kevent;
	u32 nr = 0, head_snap, tail;

	if (copy_from_user(&param, argp, sizeof(param)))
		return -EFAULT;

	uevents = (struct kvm_psc_event __user *)(uintptr_t)param.events_ptr;
	if (param.max_events > PSC_EVENT_RING_SIZE)
		param.max_events = PSC_EVENT_RING_SIZE;

	mutex_lock(&psc_ring.drain_mutex);
	head_snap = (u32)atomic_read(&psc_ring.head);
	tail      = psc_ring.drain_tail;
	if ((head_snap - tail) > PSC_EVENT_RING_SIZE)
		tail = head_snap - PSC_EVENT_RING_SIZE;

	while (tail != head_snap && nr < param.max_events) {
		u32 slot = tail % PSC_EVENT_RING_SIZE;
		struct psc_event_entry *pe = &psc_ring.entries[slot];

		kevent.gpa          = READ_ONCE(pe->gpa);
		kevent.timestamp_ns = READ_ONCE(pe->timestamp_ns);
		kevent.vcpu_id      = READ_ONCE(pe->vcpu_id);
		kevent.op           = READ_ONCE(pe->op);
		kevent.level        = READ_ONCE(pe->level);
		memset(kevent._pad, 0, sizeof(kevent._pad));

		if (uevents &&
		    copy_to_user(&uevents[nr], &kevent, sizeof(kevent))) {
			mutex_unlock(&psc_ring.drain_mutex);
			return -EFAULT;
		}
		nr++;
		tail++;
	}
	psc_ring.drain_tail = tail;
	mutex_unlock(&psc_ring.drain_mutex);

	param.nr_events = nr;
	if (copy_to_user(argp, &param, sizeof(param)))
		return -EFAULT;
	return 0;
}
EXPORT_SYMBOL(psc_track_drain);

/* ══════════════════════════════════════════════════════════════════
 *  Steps 2-3: NPT fault tracking + kernel-side correlation
 * ══════════════════════════════════════════════════════════════════ */

/* ── global state ─────────────────────────────────────────────── */

atomic_t nv_bb_tracking_enabled = ATOMIC_INIT(0);
EXPORT_SYMBOL(nv_bb_tracking_enabled);

struct nv_bb_pool nv_bb_pool;
EXPORT_SYMBOL(nv_bb_pool);

struct nv_bb_vcpu_ctx nv_bb_vcpu[NV_BB_MAX_VCPUS];
EXPORT_SYMBOL(nv_bb_vcpu);

struct nv_bb_xfer_ring nv_bb_xring;
EXPORT_SYMBOL(nv_bb_xring);

atomic64_t nv_bb_nr_read_faults  = ATOMIC64_INIT(0);
atomic64_t nv_bb_nr_write_faults = ATOMIC64_INIT(0);
atomic64_t nv_bb_nr_correlations = ATOMIC64_INIT(0);
EXPORT_SYMBOL(nv_bb_nr_read_faults);
EXPORT_SYMBOL(nv_bb_nr_write_faults);
EXPORT_SYMBOL(nv_bb_nr_correlations);

/* ── stepping + triggered stepping state ──────────────────────── */

atomic_t nv_bb_stepping_active = ATOMIC_INIT(0);
EXPORT_SYMBOL(nv_bb_stepping_active);

atomic_t nv_bb_trigger_armed = ATOMIC_INIT(0);
EXPORT_SYMBOL(nv_bb_trigger_armed);

static atomic_t  trig_pending = ATOMIC_INIT(0);
static u64       trig_gfn_start;
static u64       trig_nr_pages;
static u32       trig_apic_timer;
static u32       trig_max_steps;
static atomic_t  trig_step_count = ATOMIC_INIT(0);

/* forward declarations */
static bool trig_check_step_limit(void);

static bool nv_bb_xring_inited;

static void nv_bb_xring_init_once(void)
{
	if (nv_bb_xring_inited)
		return;
	mutex_init(&nv_bb_xring.drain_mutex);
	atomic_set(&nv_bb_xring.head, 0);
	nv_bb_xring.drain_tail = 0;
	nv_bb_xring_inited = true;
}

/* ── bounce buffer membership check (hot path) ────────────────── */

static bool nv_bb_is_bounce_gfn(u64 gfn)
{
	u32 i;

	for (i = 0; i < nv_bb_pool.nr_ranges; i++) {
		struct nv_bb_range *r = &nv_bb_pool.ranges[i];
		if (gfn >= r->start_gfn && gfn < r->start_gfn + r->nr_pages)
			return true;
	}
	return false;
}

/* ── emit a transfer pair to the ring ─────────────────────────── */

static void nv_bb_emit_xfer(u64 src_gfn, u64 bb_gfn,
			     u64 read_ts, u64 write_ts, u32 vcpu_id)
{
	u32 idx = (u32)atomic_fetch_add(1, &nv_bb_xring.head);
	struct nv_bb_xfer_entry *e =
		&nv_bb_xring.entries[idx % NV_BB_XFER_RING_SIZE];

	WRITE_ONCE(e->src_gpa,    src_gfn << PAGE_SHIFT);
	WRITE_ONCE(e->bb_gpa,     bb_gfn << PAGE_SHIFT);
	WRITE_ONCE(e->read_ts_ns, read_ts);
	WRITE_ONCE(e->write_ts_ns, write_ts);
	WRITE_ONCE(e->vcpu_id,    vcpu_id);
}

/* ── NPF correlation engine (hot path – called from mmu.c) ───── */

void nv_bb_handle_fault(struct kvm_vcpu *vcpu, u64 gfn, bool is_write)
{
	u64 now = ktime_get_ns();
	u32 vid = vcpu->vcpu_id;
	struct nv_bb_vcpu_ctx *ctx;
	bool is_bb;
	bool stepping;

	if (vid >= NV_BB_MAX_VCPUS)
		return;

	ctx      = &nv_bb_vcpu[vid];
	is_bb    = nv_bb_is_bounce_gfn(gfn);
	stepping = atomic_read(&nv_bb_stepping_active) != 0;

	/*
	 * Triggered stepping: if the trigger page is accessed,
	 * signal post-VMEXIT to activate full stepping.
	 * The fault is also logged normally below.
	 */
	if (atomic_read(&nv_bb_trigger_armed) &&
	    gfn >= trig_gfn_start &&
	    gfn < trig_gfn_start + trig_nr_pages) {
		/*
		 * Don't clear trigger_armed here — svm.c needs it to
		 * call nv_bb_trigger_post_vmexit().  It gets cleared
		 * there after stepping is fully activated.
		 */
		atomic_set(&trig_pending, 1);
		pr_info("nv_bb_track: TRIGGER fired on GFN 0x%llx vcpu=%u\n",
			gfn, vid);
	}

	if (is_write && is_bb) {
		/*
		 * WRITE on bounce buffer — emit recent reads from
		 * ALL vCPU rings as candidate source pages.
		 *
		 * The image tensor may be read by a DataLoader worker
		 * thread on a different vCPU than the one doing the
		 * CUDA encryption + BB write.  Check all rings.
		 */
		u32 v;

		atomic64_inc(&nv_bb_nr_write_faults);

		for (v = 0; v < NV_BB_MAX_VCPUS; v++) {
			struct nv_bb_vcpu_ctx *vctx = &nv_bb_vcpu[v];
			u32 n, i;

			n = vctx->count < NV_BB_READ_HIST_SIZE
			    ? vctx->count : NV_BB_READ_HIST_SIZE;

			for (i = 0; i < n; i++) {
				u32 slot = (vctx->head - 1 - i) &
					   (NV_BB_READ_HIST_SIZE - 1);
				struct nv_bb_read_entry *re =
					&vctx->hist[slot];

				if (re->ts_ns == 0)
					break;

				nv_bb_emit_xfer(re->gfn, gfn,
						re->ts_ns, now, v);
				atomic64_inc(&nv_bb_nr_correlations);
			}

			vctx->count = 0;
			vctx->head  = 0;
		}

	} else if (!is_bb) {
		/*
		 * Access on private page (read or write).
		 * In normal mode: only log reads.
		 * In stepping mode: log ALL accesses (reads AND writes)
		 * and queue the page for re-unmapping after the timer
		 * VMEXIT so the next access also faults.
		 *
		 * GPA filter: skip kernel-space pages (GFN >= 0x3f00000)
		 * which corresponds to GPA >= 0x3f00000000 (~252 GB).
		 * These are CUDA staging/driver buffers that flood the
		 * read history and push out the user-space image GPAs
		 * we actually want to capture.
		 */
		if (!is_write || stepping) {
			atomic64_inc(&nv_bb_nr_read_faults);

			/*
			 * If a source range is configured, only store
			 * pages within that range in the read history.
			 * Pages outside (kernel/driver buffers) are
			 * skipped to keep the ring focused.
			 */
			if (!nv_bb_pool.src_nr_pages ||
			    (gfn >= nv_bb_pool.src_start_gfn &&
			     gfn < nv_bb_pool.src_start_gfn +
				    nv_bb_pool.src_nr_pages)) {
				u32 slot = ctx->head &
					   (NV_BB_READ_HIST_SIZE - 1);

				ctx->hist[slot].gfn   = gfn;
				ctx->hist[slot].ts_ns = now;
				ctx->head++;
				if (ctx->count < NV_BB_READ_HIST_SIZE)
					ctx->count++;
			}
		}

		/*
		 * In stepping mode: emit each fault as an individual
		 * xfer entry so userspace sees every access.
		 * src_gpa = faulted page, bb_gpa = 0 (not a BB write),
		 * write_ts_ns repurposed as is_write flag.
		 */
		if (stepping) {
			nv_bb_emit_xfer(gfn, 0, now,
					is_write ? 1 : 0, vid);
			atomic64_inc(&nv_bb_nr_correlations);
		}

		/*
		 * In old stepping mode: queue page for re-unmapping.
		 * In triggered mode: NO re-arm (one-shot), avoids
		 * the infinite fault loop.
		 */
		if (stepping && !trig_max_steps &&
		    ctx->nr_step_rearm < NV_BB_MAX_STEP_PAGES)
			ctx->step_rearm_gfns[ctx->nr_step_rearm++] = gfn;
	}
}
EXPORT_SYMBOL(nv_bb_handle_fault);

/* ── helper: ACCESS-track a specific GFN range ───────────────── */

static long track_gfn_range(struct kvm_vcpu *vcpu, u64 start_gfn,
			     u64 nr_pages, enum kvm_page_track_mode mode)
{
	struct kvm *kvm = vcpu->kvm;
	long count = 0;
	u64 gfn, end_gfn = start_gfn + nr_pages;
	int srcu_idx;

	/*
	 * Zap all SPTEs in the range FIRST.
	 *
	 * Pinned memory (cudaMallocHost) is mapped as 2MB hugepages
	 * in the NPT.  4KB-level page tracking cannot protect
	 * individual 4KB GFNs within a 2MB SPTE.  Zapping forces
	 * KVM to rebuild SPTEs on the next access.  Combined with
	 * gfn_disallow_lpage() in the tracking call, the new SPTEs
	 * will be 4KB and respect ACCESS/WRITE tracking.
	 */
	kvm_zap_gfn_range(kvm, start_gfn, end_gfn);

	srcu_idx = srcu_read_lock(&kvm->srcu);
	write_lock(&kvm->mmu_lock);

	for (gfn = start_gfn; gfn < end_gfn; gfn++) {
		struct kvm_memory_slot *slot =
			kvm_vcpu_gfn_to_memslot(vcpu, gfn);
		if (!slot)
			continue;

		if (!kvm_page_track_is_active(vcpu, gfn, mode)) {
			kvm_slot_page_track_add_page_no_flush(
				kvm, slot, gfn, mode);
		}
		count++;
	}

	write_unlock(&kvm->mmu_lock);
	srcu_read_unlock(&kvm->srcu, srcu_idx);

	if (count > 0)
		kvm_flush_remote_tlbs(kvm);

	return count;
}

/* ── ioctl: KVM_NV_BB_START ───────────────────────────────────── */

int nv_bb_start(void __user *argp)
{
	struct kvm_nv_bb_start_param param;
	struct kvm_nv_bb_range __user *uranges;
	struct kvm *kvm;
	struct kvm_vcpu *vcpu;
	long tracked;
	u32 i;
	int srcu_idx;

	if (copy_from_user(&param, argp, sizeof(param)))
		return -EFAULT;

	if (param.nr_ranges == 0 || param.nr_ranges > NV_BB_MAX_RANGES)
		return -EINVAL;

	kvm = global_sev_step_config.main_vm;
	if (!kvm) {
		pr_err("nv_bb_track: START: main_vm == NULL\n");
		return -ENXIO;
	}
	vcpu = kvm_get_vcpu(kvm, 0);
	if (!vcpu) {
		pr_err("nv_bb_track: START: no vCPU[0]\n");
		return -ENXIO;
	}

	/* Initialise transfer ring */
	nv_bb_xring_init_once();
	atomic_set(&nv_bb_xring.head, 0);
	nv_bb_xring.drain_tail = 0;

	/* Reset counters */
	atomic64_set(&nv_bb_nr_read_faults, 0);
	atomic64_set(&nv_bb_nr_write_faults, 0);
	atomic64_set(&nv_bb_nr_correlations, 0);

	/* Reset per-vCPU state */
	memset(nv_bb_vcpu, 0, sizeof(nv_bb_vcpu));

	/* Copy bounce buffer ranges from userspace */
	uranges = (struct kvm_nv_bb_range __user *)(uintptr_t)param.ranges_ptr;
	nv_bb_pool.nr_ranges = param.nr_ranges;
	for (i = 0; i < param.nr_ranges; i++) {
		struct kvm_nv_bb_range kr;
		if (copy_from_user(&kr, &uranges[i], sizeof(kr)))
			return -EFAULT;
		nv_bb_pool.ranges[i].start_gfn = kr.start_gfn;
		nv_bb_pool.ranges[i].nr_pages  = kr.nr_pages;
		pr_info("nv_bb_track: BB range %u: GFN [0x%llx, 0x%llx) "
			"(%llu pages)\n",
			i, kr.start_gfn, kr.start_gfn + kr.nr_pages,
			kr.nr_pages);
	}

	/* Store source range */
	nv_bb_pool.src_start_gfn = param.src_start_gfn;
	nv_bb_pool.src_nr_pages  = param.src_nr_pages;

	/*
	 * Step 2a: ACCESS-track source pages.
	 * If src range specified, track only that range.
	 * Otherwise, track ALL guest memory (legacy behavior).
	 */
	if (param.src_start_gfn && param.src_nr_pages) {
		tracked = track_gfn_range(vcpu, param.src_start_gfn,
					  param.src_nr_pages,
					  KVM_PAGE_TRACK_ACCESS);
		pr_info("nv_bb_track: source range GFN [0x%llx, 0x%llx) "
			"tracked (%ld pages)\n",
			param.src_start_gfn,
			param.src_start_gfn + param.src_nr_pages,
			tracked);
	} else {
		tracked = kvm_start_tracking(vcpu, KVM_PAGE_TRACK_ACCESS);
		pr_info("nv_bb_track: all guest memory unmapped (%ld pages)\n",
			tracked);
	}

	/*
	 * Step 2b: Set BB pages to WRITE-only.
	 * If we tracked all memory, BB pages also got ACCESS — remove it.
	 * If we tracked a specific range, BB pages may or may not overlap.
	 * Either way, ensure BB pages have WRITE tracking.
	 */
	for (i = 0; i < nv_bb_pool.nr_ranges; i++) {
		struct nv_bb_range *r = &nv_bb_pool.ranges[i];
		u64 gfn;

		srcu_idx = srcu_read_lock(&kvm->srcu);
		write_lock(&kvm->mmu_lock);

		for (gfn = r->start_gfn; gfn < r->start_gfn + r->nr_pages; gfn++) {
			struct kvm_memory_slot *slot =
				kvm_vcpu_gfn_to_memslot(vcpu, gfn);
			if (!slot)
				continue;
			if (kvm_page_track_is_active(vcpu, gfn,
						     KVM_PAGE_TRACK_ACCESS))
				kvm_slot_page_track_remove_page(
					kvm, slot, gfn, KVM_PAGE_TRACK_ACCESS);
			if (!kvm_page_track_is_active(vcpu, gfn,
						      KVM_PAGE_TRACK_WRITE))
				kvm_slot_page_track_add_page_no_flush(
					kvm, slot, gfn, KVM_PAGE_TRACK_WRITE);
		}

		write_unlock(&kvm->mmu_lock);
		srcu_read_unlock(&kvm->srcu, srcu_idx);
	}
	kvm_flush_remote_tlbs(kvm);
	pr_info("nv_bb_track: BB pages set to WRITE-only tracking\n");

	/* Enable the hot-path flag */
	atomic_set(&nv_bb_tracking_enabled, 1);
	pr_info("nv_bb_track: NPT tracking ENABLED\n");

	return 0;
}
EXPORT_SYMBOL(nv_bb_start);

/* ── ioctl: KVM_NV_BB_STOP ────────────────────────────────────── */

int nv_bb_stop(void)
{
	atomic_set(&nv_bb_tracking_enabled, 0);
	nv_bb_pool.nr_ranges = 0;
	pr_info("nv_bb_track: NPT tracking DISABLED\n");
	return 0;
}
EXPORT_SYMBOL(nv_bb_stop);

/* ── ioctl: KVM_NV_BB_REARM ──────────────────────────────────── */

int nv_bb_rearm(void)
{
	struct kvm *kvm;
	struct kvm_vcpu *vcpu;
	long tracked;
	u32 i;
	int srcu_idx;

	kvm = global_sev_step_config.main_vm;
	if (!kvm)
		return -ENXIO;
	vcpu = kvm_get_vcpu(kvm, 0);
	if (!vcpu)
		return -ENXIO;

	/*
	 * Re-arm ACCESS tracking.
	 * If source range was specified, only re-arm that range (fast).
	 * Otherwise, re-arm all memory (slow for large guests).
	 */
	if (nv_bb_pool.src_start_gfn && nv_bb_pool.src_nr_pages) {
		/* Re-arm ACCESS on source range */
		tracked = track_gfn_range(vcpu, nv_bb_pool.src_start_gfn,
					  nv_bb_pool.src_nr_pages,
					  KVM_PAGE_TRACK_ACCESS);
		(void)tracked;

		/* Re-arm WRITE on BB pages (consumed by one-shot faults) */
		for (i = 0; i < nv_bb_pool.nr_ranges; i++) {
			tracked = track_gfn_range(vcpu,
					nv_bb_pool.ranges[i].start_gfn,
					nv_bb_pool.ranges[i].nr_pages,
					KVM_PAGE_TRACK_WRITE);
			(void)tracked;
		}
	} else {
		tracked = kvm_start_tracking(vcpu, KVM_PAGE_TRACK_ACCESS);
		(void)tracked;

		/* Fix BB pages: remove ACCESS, ensure WRITE-only */
		for (i = 0; i < nv_bb_pool.nr_ranges; i++) {
			struct nv_bb_range *r = &nv_bb_pool.ranges[i];
			u64 gfn;

			srcu_idx = srcu_read_lock(&kvm->srcu);
			write_lock(&kvm->mmu_lock);

			for (gfn = r->start_gfn;
			     gfn < r->start_gfn + r->nr_pages; gfn++) {
				struct kvm_memory_slot *slot =
					kvm_vcpu_gfn_to_memslot(vcpu, gfn);
				if (!slot)
					continue;
				if (kvm_page_track_is_active(vcpu, gfn,
							KVM_PAGE_TRACK_ACCESS))
					kvm_slot_page_track_remove_page(
						kvm, slot, gfn,
						KVM_PAGE_TRACK_ACCESS);
				if (!kvm_page_track_is_active(vcpu, gfn,
							KVM_PAGE_TRACK_WRITE))
					kvm_slot_page_track_add_page_no_flush(
						kvm, slot, gfn,
						KVM_PAGE_TRACK_WRITE);
			}

			write_unlock(&kvm->mmu_lock);
			srcu_read_unlock(&kvm->srcu, srcu_idx);
		}
		kvm_flush_remote_tlbs(kvm);
	}

	return 0;
}
EXPORT_SYMBOL(nv_bb_rearm);

/* ── ioctl: KVM_NV_BB_DRAIN ──────────────────────────────────── */

int nv_bb_drain_xfers(void __user *argp)
{
	struct kvm_nv_bb_drain_param         param;
	struct kvm_nv_bb_xfer_entry __user  *uxfers;
	struct kvm_nv_bb_xfer_entry          kxfer;
	u32 nr = 0, head_snap, tail;

	if (copy_from_user(&param, argp, sizeof(param)))
		return -EFAULT;

	uxfers = (struct kvm_nv_bb_xfer_entry __user *)
		 (uintptr_t)param.xfers_ptr;

	if (param.max_xfers > NV_BB_XFER_RING_SIZE)
		param.max_xfers = NV_BB_XFER_RING_SIZE;

	mutex_lock(&nv_bb_xring.drain_mutex);
	head_snap = (u32)atomic_read(&nv_bb_xring.head);
	tail      = nv_bb_xring.drain_tail;

	if ((head_snap - tail) > NV_BB_XFER_RING_SIZE)
		tail = head_snap - NV_BB_XFER_RING_SIZE;

	while (tail != head_snap && nr < param.max_xfers) {
		u32 slot = tail % NV_BB_XFER_RING_SIZE;
		struct nv_bb_xfer_entry *xe = &nv_bb_xring.entries[slot];

		kxfer.src_gpa     = READ_ONCE(xe->src_gpa);
		kxfer.bb_gpa      = READ_ONCE(xe->bb_gpa);
		kxfer.read_ts_ns  = READ_ONCE(xe->read_ts_ns);
		kxfer.write_ts_ns = READ_ONCE(xe->write_ts_ns);
		kxfer.vcpu_id     = READ_ONCE(xe->vcpu_id);
		kxfer._pad        = 0;

		if (uxfers &&
		    copy_to_user(&uxfers[nr], &kxfer, sizeof(kxfer))) {
			mutex_unlock(&nv_bb_xring.drain_mutex);
			return -EFAULT;
		}
		nr++;
		tail++;
	}
	nv_bb_xring.drain_tail = tail;
	mutex_unlock(&nv_bb_xring.drain_mutex);

	/* Fill diagnostics */
	param.nr_xfers       = nr;
	param.nr_read_faults  = (u64)atomic64_read(&nv_bb_nr_read_faults);
	param.nr_write_faults = (u64)atomic64_read(&nv_bb_nr_write_faults);
	param.nr_correlations = (u64)atomic64_read(&nv_bb_nr_correlations);

	if (copy_to_user(argp, &param, sizeof(param)))
		return -EFAULT;

	return 0;
}
EXPORT_SYMBOL(nv_bb_drain_xfers);

/* ══════════════════════════════════════════════════════════════════
 *  Step 4: Single-stepping
 *  (globals moved to top of Steps 2-3 section for forward visibility)
 * ══════════════════════════════════════════════════════════════════ */

/* ── post-VMEXIT: re-unmap pages faulted in last step ─────────── */

void nv_bb_step_post_vmexit(struct kvm_vcpu *vcpu)
{
	u32 vid = vcpu->vcpu_id;
	struct nv_bb_vcpu_ctx *ctx;
	u32 i;

	if (vid >= NV_BB_MAX_VCPUS)
		return;

	/* Auto-disarm check for triggered stepping */
	if (trig_max_steps && trig_check_step_limit())
		return;

	ctx = &nv_bb_vcpu[vid];

	for (i = 0; i < ctx->nr_step_rearm; i++) {
		u64 gfn = ctx->step_rearm_gfns[i];
		/*
		 * Re-apply ACCESS tracking.  The page was untracked by
		 * __untrack_single_page() during the fault.  Re-tracking
		 * it here is safe: we are NOT inside the page fault handler,
		 * so there is no infinite loop.  The guest will fault again
		 * on the next access to this page.
		 */
		__track_single_page(vcpu, gfn, KVM_PAGE_TRACK_ACCESS, true);
	}
	ctx->nr_step_rearm = 0;
}
EXPORT_SYMBOL(nv_bb_step_post_vmexit);

/* ── ioctl: KVM_NV_BB_STEP_ARM ────────────────────────────────── */

int nv_bb_step_arm(void __user *argp)
{
	struct kvm_nv_bb_step_param param;
	struct kvm_nv_bb_range __user *uranges;
	struct kvm *kvm;
	struct kvm_vcpu *vcpu;
	long tracked;
	u32 i;
	int srcu_idx;

	if (copy_from_user(&param, argp, sizeof(param)))
		return -EFAULT;

	if (param.nr_ranges == 0 || param.nr_ranges > NV_BB_MAX_RANGES)
		return -EINVAL;
	if (param.apic_timer_value == 0)
		return -EINVAL;

	kvm = global_sev_step_config.main_vm;
	if (!kvm) {
		pr_err("nv_bb_track: STEP_ARM: main_vm == NULL\n");
		return -ENXIO;
	}
	vcpu = kvm_get_vcpu(kvm, 0);
	if (!vcpu) {
		pr_err("nv_bb_track: STEP_ARM: no vCPU[0]\n");
		return -ENXIO;
	}

	/* Init transfer ring */
	nv_bb_xring_init_once();
	atomic_set(&nv_bb_xring.head, 0);
	nv_bb_xring.drain_tail = 0;
	atomic64_set(&nv_bb_nr_read_faults, 0);
	atomic64_set(&nv_bb_nr_write_faults, 0);
	atomic64_set(&nv_bb_nr_correlations, 0);
	memset(nv_bb_vcpu, 0, sizeof(nv_bb_vcpu));

	/* Copy BB ranges */
	uranges = (struct kvm_nv_bb_range __user *)(uintptr_t)param.ranges_ptr;
	nv_bb_pool.nr_ranges = param.nr_ranges;
	for (i = 0; i < param.nr_ranges; i++) {
		struct kvm_nv_bb_range kr;
		if (copy_from_user(&kr, &uranges[i], sizeof(kr)))
			return -EFAULT;
		nv_bb_pool.ranges[i].start_gfn = kr.start_gfn;
		nv_bb_pool.ranges[i].nr_pages  = kr.nr_pages;
		pr_info("nv_bb_track: STEP BB range %u: GFN [0x%llx, 0x%llx)\n",
			i, kr.start_gfn, kr.start_gfn + kr.nr_pages);
	}

	/* Unmap ALL guest memory */
	tracked = kvm_start_tracking(vcpu, KVM_PAGE_TRACK_ACCESS);
	pr_info("nv_bb_track: STEP all memory unmapped (%ld pages)\n", tracked);

	/* Fix BB pages: remove ACCESS, set WRITE-only */
	for (i = 0; i < nv_bb_pool.nr_ranges; i++) {
		struct nv_bb_range *r = &nv_bb_pool.ranges[i];
		u64 gfn;

		srcu_idx = srcu_read_lock(&kvm->srcu);
		write_lock(&kvm->mmu_lock);

		for (gfn = r->start_gfn; gfn < r->start_gfn + r->nr_pages; gfn++) {
			struct kvm_memory_slot *slot =
				kvm_vcpu_gfn_to_memslot(vcpu, gfn);
			if (!slot)
				continue;
			if (kvm_page_track_is_active(vcpu, gfn,
						     KVM_PAGE_TRACK_ACCESS))
				kvm_slot_page_track_remove_page(
					kvm, slot, gfn, KVM_PAGE_TRACK_ACCESS);
			if (!kvm_page_track_is_active(vcpu, gfn,
						      KVM_PAGE_TRACK_WRITE))
				kvm_slot_page_track_add_page_no_flush(
					kvm, slot, gfn, KVM_PAGE_TRACK_WRITE);
		}

		write_unlock(&kvm->mmu_lock);
		srcu_read_unlock(&kvm->srcu, srcu_idx);
	}
	kvm_flush_remote_tlbs(kvm);

	/* Enable APIC timer single-stepping */
	mutex_lock(&sev_step_config_mutex);
	global_sev_step_config.tmict_value = param.apic_timer_value;
	global_sev_step_config.single_stepping_status =
		SEV_STEP_STEPPING_STATUS_DISABLED_WANT_INIT;
	mutex_unlock(&sev_step_config_mutex);

	/* Enable the hot-path flags */
	atomic_set(&nv_bb_tracking_enabled, 1);
	atomic_set(&nv_bb_stepping_active, 1);

	pr_info("nv_bb_track: STEP armed (apic_timer=%u)\n",
		param.apic_timer_value);
	return 0;
}
EXPORT_SYMBOL(nv_bb_step_arm);

/* ── ioctl: KVM_NV_BB_STEP_DISARM ────────────────────────────── */

int nv_bb_step_disarm(void)
{
	atomic_set(&nv_bb_stepping_active, 0);
	atomic_set(&nv_bb_tracking_enabled, 0);
	nv_bb_pool.nr_ranges = 0;

	/* Disable single-stepping */
	mutex_lock(&sev_step_config_mutex);
	if (sev_step_is_single_stepping_active(&global_sev_step_config))
		global_sev_step_config.single_stepping_status =
			SEV_STEP_STEPPING_STATUS_ENABLED_WANT_DISABLE;
	mutex_unlock(&sev_step_config_mutex);

	pr_info("nv_bb_track: STEP disarmed\n");
	return 0;
}
EXPORT_SYMBOL(nv_bb_step_disarm);

/* ══════════════════════════════════════════════════════════════════
 *  Step 4b: Triggered single-stepping
 * ══════════════════════════════════════════════════════════════════ */

/*
 * Helper: remove ACCESS from BB pages and ensure WRITE-only.
 * Caller must NOT hold mmu_lock.
 */
static void fix_bb_pages_write_only(struct kvm *kvm, struct kvm_vcpu *vcpu)
{
	u32 i;
	int srcu_idx;

	for (i = 0; i < nv_bb_pool.nr_ranges; i++) {
		struct nv_bb_range *r = &nv_bb_pool.ranges[i];
		u64 gfn;

		srcu_idx = srcu_read_lock(&kvm->srcu);
		write_lock(&kvm->mmu_lock);

		for (gfn = r->start_gfn;
		     gfn < r->start_gfn + r->nr_pages; gfn++) {
			struct kvm_memory_slot *slot =
				kvm_vcpu_gfn_to_memslot(vcpu, gfn);
			if (!slot)
				continue;
			if (kvm_page_track_is_active(vcpu, gfn,
						     KVM_PAGE_TRACK_ACCESS))
				kvm_slot_page_track_remove_page(
					kvm, slot, gfn, KVM_PAGE_TRACK_ACCESS);
			if (!kvm_page_track_is_active(vcpu, gfn,
						      KVM_PAGE_TRACK_WRITE))
				kvm_slot_page_track_add_page_no_flush(
					kvm, slot, gfn, KVM_PAGE_TRACK_WRITE);
		}

		write_unlock(&kvm->mmu_lock);
		srcu_read_unlock(&kvm->srcu, srcu_idx);
	}
	kvm_flush_remote_tlbs(kvm);
}

/**
 * nv_bb_trigger_post_vmexit - activate stepping after trigger fires.
 *
 * Called from svm.c post-VMEXIT when nv_bb_trigger_armed was set.
 * If the trigger page was accessed (trig_pending == 1), unmaps ALL
 * guest memory, fixes BB pages to WRITE-only, and enables APIC
 * timer single-stepping.
 *
 * Runs outside mmu_lock and sev_step_config_mutex, so safe to call
 * kvm_start_tracking() and update global_sev_step_config.
 */
void nv_bb_trigger_post_vmexit(struct kvm_vcpu *vcpu)
{
	long tracked;

	if (!atomic_cmpxchg(&trig_pending, 1, 0))
		return;

	pr_info("nv_bb_track: TRIGGER activating full stepping\n");

	/* Unmap ALL guest memory */
	tracked = kvm_start_tracking(vcpu, KVM_PAGE_TRACK_ACCESS);
	pr_info("nv_bb_track: TRIGGER unmapped %ld pages\n", tracked);

	/* Fix BB pages: remove ACCESS, set WRITE-only */
	fix_bb_pages_write_only(vcpu->kvm, vcpu);

	/* Enable APIC timer single-stepping */
	mutex_lock(&sev_step_config_mutex);
	global_sev_step_config.tmict_value = trig_apic_timer;
	global_sev_step_config.single_stepping_status =
		SEV_STEP_STEPPING_STATUS_DISABLED_WANT_INIT;
	mutex_unlock(&sev_step_config_mutex);

	/* Activate stepping hot-path, clear trigger_armed */
	atomic_set(&nv_bb_stepping_active, 1);
	atomic_set(&nv_bb_trigger_armed, 0);
	atomic_set(&trig_step_count, 0);

	pr_info("nv_bb_track: TRIGGER stepping active (max_steps=%u)\n",
		trig_max_steps);
}
EXPORT_SYMBOL(nv_bb_trigger_post_vmexit);

/* ── step counter for triggered mode ─────────────────────────── */

/*
 * Called from nv_bb_step_post_vmexit() to count steps and auto-disarm.
 * Returns true if stepping was auto-disarmed.
 */
static bool trig_check_step_limit(void)
{
	u32 count;

	if (!trig_max_steps)
		return false;

	count = (u32)atomic_inc_return(&trig_step_count);
	if (count >= trig_max_steps) {
		pr_info("nv_bb_track: TRIGGER auto-disarm after %u steps\n",
			count);
		nv_bb_step_disarm();
		trig_max_steps = 0;
		return true;
	}
	return false;
}

/* ── ioctl: KVM_NV_BB_TRIGGERED_STEP ─────────────────────────── */

int nv_bb_triggered_step_arm(void __user *argp)
{
	struct kvm_nv_bb_triggered_step_param param;
	struct kvm_nv_bb_range __user *uranges;
	struct kvm *kvm;
	struct kvm_vcpu *vcpu;
	u32 i;
	int srcu_idx;

	if (copy_from_user(&param, argp, sizeof(param)))
		return -EFAULT;

	if (param.nr_ranges == 0 || param.nr_ranges > NV_BB_MAX_RANGES)
		return -EINVAL;
	if (param.apic_timer_value == 0)
		return -EINVAL;
	if (param.nr_trigger_pages == 0)
		return -EINVAL;

	kvm = global_sev_step_config.main_vm;
	if (!kvm) {
		pr_err("nv_bb_track: TRIGGERED_STEP: main_vm == NULL\n");
		return -ENXIO;
	}
	vcpu = kvm_get_vcpu(kvm, 0);
	if (!vcpu) {
		pr_err("nv_bb_track: TRIGGERED_STEP: no vCPU[0]\n");
		return -ENXIO;
	}

	/* Init transfer ring + counters */
	nv_bb_xring_init_once();
	atomic_set(&nv_bb_xring.head, 0);
	nv_bb_xring.drain_tail = 0;
	atomic64_set(&nv_bb_nr_read_faults, 0);
	atomic64_set(&nv_bb_nr_write_faults, 0);
	atomic64_set(&nv_bb_nr_correlations, 0);
	memset(nv_bb_vcpu, 0, sizeof(nv_bb_vcpu));

	/* Copy BB ranges */
	uranges = (struct kvm_nv_bb_range __user *)(uintptr_t)param.ranges_ptr;
	nv_bb_pool.nr_ranges = param.nr_ranges;
	for (i = 0; i < param.nr_ranges; i++) {
		struct kvm_nv_bb_range kr;
		if (copy_from_user(&kr, &uranges[i], sizeof(kr)))
			return -EFAULT;
		nv_bb_pool.ranges[i].start_gfn = kr.start_gfn;
		nv_bb_pool.ranges[i].nr_pages  = kr.nr_pages;
		pr_info("nv_bb_track: TRIG BB range %u: GFN [0x%llx, 0x%llx)\n",
			i, kr.start_gfn, kr.start_gfn + kr.nr_pages);
	}

	/* Store trigger parameters */
	trig_gfn_start = param.trigger_gfn;
	trig_nr_pages  = param.nr_trigger_pages;
	trig_apic_timer = param.apic_timer_value;
	trig_max_steps = param.max_steps;
	atomic_set(&trig_step_count, 0);
	atomic_set(&trig_pending, 0);

	/*
	 * Only ACCESS-track the trigger page(s).
	 * Guest runs at full speed until one of them is accessed.
	 */
	srcu_idx = srcu_read_lock(&kvm->srcu);
	write_lock(&kvm->mmu_lock);
	for (i = 0; i < param.nr_trigger_pages; i++) {
		u64 gfn = param.trigger_gfn + i;
		struct kvm_memory_slot *slot =
			kvm_vcpu_gfn_to_memslot(vcpu, gfn);
		if (slot && !kvm_page_track_is_active(vcpu, gfn,
						      KVM_PAGE_TRACK_ACCESS))
			kvm_slot_page_track_add_page_no_flush(
				kvm, slot, gfn, KVM_PAGE_TRACK_ACCESS);
	}
	write_unlock(&kvm->mmu_lock);
	srcu_read_unlock(&kvm->srcu, srcu_idx);
	kvm_flush_remote_tlbs(kvm);

	pr_info("nv_bb_track: TRIG trigger pages GFN [0x%llx, 0x%llx) tracked\n",
		param.trigger_gfn, param.trigger_gfn + param.nr_trigger_pages);

	/*
	 * Enable nv_bb_tracking_enabled so nv_bb_handle_fault() is called.
	 * Do NOT enable stepping yet — it activates on trigger.
	 * Set trigger_armed so svm.c calls nv_bb_trigger_post_vmexit().
	 */
	atomic_set(&nv_bb_tracking_enabled, 1);
	atomic_set(&nv_bb_stepping_active, 0);
	atomic_set(&nv_bb_trigger_armed, 1);

	pr_info("nv_bb_track: TRIGGERED_STEP armed "
		"(trigger=0x%llx+%llu, apic=%u, max_steps=%u)\n",
		param.trigger_gfn, param.nr_trigger_pages,
		param.apic_timer_value, param.max_steps);
	return 0;
}
EXPORT_SYMBOL(nv_bb_triggered_step_arm);
