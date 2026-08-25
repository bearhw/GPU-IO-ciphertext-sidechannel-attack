// Decisive spatial test: which PFNs' struct page records physically live in
// Region B, and are they valid struct pages?  Load INSIDE THE GUEST.
//
//   sudo insmod spmap_probe.ko maxpfn=67633152          # top pfn from /proc/iomem
//   sudo dmesg | tail -n 120
//   sudo rmmod spmap_probe
//
// maxpfn = (top System RAM end + 1) >> 12.  For 100000000-407fffffff that is
// 0x4080000000 >> 12 = 67633152.  rb_start/rb_end default to the observed
// Region B window (0x3f80000000 .. 0x3f90000000); override if needed.
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/pfn.h>
#include <linux/sched.h>
#include <asm/io.h>
#include <asm/pgtable.h>

static unsigned long maxpfn = 0;      /* 0 -> totalram_pages() (undercounts) */
module_param(maxpfn, ulong, 0444);
MODULE_PARM_DESC(maxpfn, "highest PFN to scan; 0 = totalram_pages()");

static unsigned long step = 1;
module_param(step, ulong, 0444);
MODULE_PARM_DESC(step, "PFN scan stride (1 = every frame)");

static unsigned long long rb_start = 0x3f80000000ULL;
static unsigned long long rb_end   = 0x3f90000000ULL;
module_param(rb_start, ullong, 0444);
module_param(rb_end,   ullong, 0444);

// Level-aware VA->PA: vmemmap is often mapped with 2MB (or 1GB) pages, so the
// in-page offset spans more than 12 bits.
static phys_addr_t va_to_phys_pt(unsigned long va)
{
	unsigned int level;
	pte_t *pte = lookup_address(va, &level);
	phys_addr_t base;
	unsigned long psize;

	if (!pte || !pte_present(*pte))
		return 0;
	switch (level) {
	case PG_LEVEL_1G: psize = 1UL << 30; break;
	case PG_LEVEL_2M: psize = 1UL << 21; break;
	default:          psize = 1UL << 12; break;
	}
	base = ((phys_addr_t)pte_pfn(*pte) << PAGE_SHIFT) & ~(phys_addr_t)(psize - 1);
	return base | (va & (psize - 1));
}

static int __init spmap_init(void)
{
	unsigned long top = maxpfn ? maxpfn : totalram_pages();
	unsigned long pfn, hits = 0, live = 0, samples = 0;
	unsigned long hit_pfn_min = ~0UL, hit_pfn_max = 0;
	phys_addr_t all_min = ~0ULL, all_max = 0;

	pr_info("spmap: scanning PFNs [0, %lu) step=%lu, Region B = [%#llx, %#llx)\n",
		top, step, rb_start, rb_end);
	pr_info("spmap: sizeof(struct page)=%zu\n", sizeof(struct page));

	for (pfn = 0; pfn < top; pfn += step) {
		struct page *pg;
		unsigned long va;
		phys_addr_t pa;

		if ((pfn & 0xfffff) == 0)
			cond_resched();
		if (!pfn_valid(pfn))
			continue;
		pg = pfn_to_page(pfn);
		va = (unsigned long)pg;
		pa = va_to_phys_pt(va);
		if (!pa)
			continue;
		if (pa < all_min) all_min = pa;
		if (pa > all_max) all_max = pa;

		if (pa >= rb_start && pa < rb_end) {
			int rc = atomic_read(&pg->_refcount);
			hits++;
			if (rc > 0)
				live++;
			if (pfn < hit_pfn_min) hit_pfn_min = pfn;
			if (pfn > hit_pfn_max) hit_pfn_max = pfn;
			if (samples < 8) {
				samples++;
				pr_info("spmap: RB hit pfn=%lu (frame %#llx) sp_va=%#lx "
					"sp_PA=%#llx flags=%#lx refcount=%d mapcount=%d\n",
					pfn, (unsigned long long)pfn << PAGE_SHIFT, va,
					(unsigned long long)pa, pg->flags, rc,
					atomic_read(&pg->_mapcount));
			}
		}
	}

	pr_info("spmap: ALL struct page records span PA %#llx .. %#llx\n",
		(unsigned long long)all_min, (unsigned long long)all_max);
	pr_info("spmap: struct pages landing in Region B: %lu (of scanned), "
		"live(refcount>0)=%lu\n", hits, live);
	if (hits)
		pr_info("spmap: those belong to frames pfn [%lu, %lu] "
			"= GPA [%#llx, %#llx] -> Region B IS the vmemmap backing "
			"for these frames\n",
			hit_pfn_min, hit_pfn_max,
			(unsigned long long)hit_pfn_min << PAGE_SHIFT,
			(unsigned long long)hit_pfn_max << PAGE_SHIFT);
	else
		pr_info("spmap: no struct page landed in Region B; widen maxpfn or "
			"adjust rb_start/rb_end to the ALL-span above\n");
	return 0;
}

static void __exit spmap_exit(void) { pr_info("spmap: unloaded\n"); }
module_init(spmap_init);
module_exit(spmap_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Locate which frames' struct pages back Region B (vmemmap)");
