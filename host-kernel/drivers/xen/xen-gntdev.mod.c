#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd7f43eda, "pin_user_pages_fast" },
	{ 0x5da0bdb4, "mmu_interval_notifier_remove" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0xe1eb907a, "unpin_user_pages_dirty_lock" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x3165daa3, "arbitrary_virt_to_machine" },
	{ 0xd1753559, "mmu_interval_read_begin" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0x90e2c790, "mmu_interval_notifier_insert_locked" },
	{ 0x3362b03c, "xen_p2m_size" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x5a4896a8, "__put_user_2" },
	{ 0x4940ba3b, "__mmap_lock_do_trace_acquire_returned" },
	{ 0xcaf1d958, "evtchn_get" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x37a0cba, "kfree" },
	{ 0xed72617, "gnttab_dma_free_pages" },
	{ 0x704ea0a4, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0xf75af443, "dma_buf_attach" },
	{ 0x3b9642a2, "__tracepoint_mmap_lock_released" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xba6e4b5e, "dma_buf_export" },
	{ 0x97fa4dd1, "dma_buf_map_attachment" },
	{ 0xfd98a590, "find_vma" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x800473f, "__cond_resched" },
	{ 0xec515638, "gnttab_dma_alloc_pages" },
	{ 0xd28f6a7f, "fput" },
	{ 0x380eaa4, "dma_buf_unmap_attachment" },
	{ 0xd2bc5c46, "__get_user_nocheck_2" },
	{ 0x7c9ca58f, "__sg_page_iter_next" },
	{ 0x7444e1a3, "gnttab_batch_copy" },
	{ 0xa94a09bb, "mem_section" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x81808c2b, "dma_buf_get" },
	{ 0xd0f82335, "dma_buf_put" },
	{ 0x4f537213, "apply_to_page_range" },
	{ 0x85479ed4, "dma_buf_fd" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x65df35ca, "__put_user_nocheck_2" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0xa88847fe, "gnttab_free_pages" },
	{ 0x558e68f5, "sg_alloc_table_from_pages_segment" },
	{ 0x4708008a, "misc_register" },
	{ 0x14ec4fdb, "evtchn_put" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x93d1d424, "gnttab_free_grant_references" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0x668b19a1, "down_read" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xf27d0a7b, "gnttab_grant_foreign_access_ref" },
	{ 0x24f14039, "__mmap_lock_do_trace_start_locking" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x3a7d80f9, "xen_max_p2m_pfn" },
	{ 0xa3b1739c, "gnttab_unmap_refs_async" },
	{ 0x93636f65, "dma_map_sgtable" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x1f9907f7, "__tracepoint_mmap_lock_start_locking" },
	{ 0xccd4c999, "__sg_page_iter_start" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x1f06be15, "__mmap_lock_do_trace_released" },
	{ 0x31dca4d8, "gnttab_claim_grant_reference" },
	{ 0xd27f215d, "gnttab_alloc_grant_references" },
	{ 0x4b931968, "xen_features" },
	{ 0x25fdcdad, "dma_buf_detach" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x1b77f03c, "gnttab_alloc_pages" },
	{ 0xfe727411, "get_phys_to_machine" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xbda2916c, "vm_map_pages_zero" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xe1f7ab96, "gnttab_end_foreign_access" },
	{ 0x17001b5e, "gnttab_map_refs" },
	{ 0x53b954a2, "up_read" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x45d14bdf, "hypercall_page" },
	{ 0x25f02c87, "xen_p2m_addr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A39ED3466C7ECA31100E9CB");
