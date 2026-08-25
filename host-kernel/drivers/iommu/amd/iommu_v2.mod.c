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

SYMBOL_CRC(amd_iommu_bind_pasid, 0x6ae84b98, "");
SYMBOL_CRC(amd_iommu_unbind_pasid, 0x392663c0, "");
SYMBOL_CRC(amd_iommu_init_device, 0x650ab4d5, "");
SYMBOL_CRC(amd_iommu_free_device, 0xb58cb534, "");
SYMBOL_CRC(amd_iommu_set_invalid_ppr_cb, 0x7bb07f83, "");
SYMBOL_CRC(amd_iommu_set_invalidate_ctx_cb, 0xce5dc9de, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xafd5ff2c, "amd_iommu_v2_supported" },
	{ 0xb0d01304, "amd_iommu_flush_page" },
	{ 0x342575b0, "amd_iommu_flush_tlb" },
	{ 0x800473f, "__cond_resched" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xcf6a4658, "amd_iommu_domain_clear_gcr3" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb746da86, "amd_iommu_complete_ppr" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x37a0cba, "kfree" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xabdc439, "cc_platform_has" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x791a408b, "pci_bus_type" },
	{ 0x5da598f7, "iommu_domain_alloc" },
	{ 0x31ff9132, "amd_iommu_domain_direct_map" },
	{ 0xd2f5031, "amd_iommu_domain_enable_v2" },
	{ 0xe2084028, "iommu_group_get" },
	{ 0xd44d9b88, "iommu_attach_group" },
	{ 0x89485687, "iommu_group_put" },
	{ 0x96c18eb5, "iommu_domain_free" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x1f9907f7, "__tracepoint_mmap_lock_start_locking" },
	{ 0x668b19a1, "down_read" },
	{ 0x704ea0a4, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0x66dae46b, "find_extend_vma" },
	{ 0x3b9642a2, "__tracepoint_mmap_lock_released" },
	{ 0x53b954a2, "up_read" },
	{ 0x4940ba3b, "__mmap_lock_do_trace_acquire_returned" },
	{ 0x24f14039, "__mmap_lock_do_trace_start_locking" },
	{ 0x1f06be15, "__mmap_lock_do_trace_released" },
	{ 0xb0e6fc13, "handle_mm_fault" },
	{ 0x414e1379, "mmu_notifier_unregister" },
	{ 0x579f68d6, "iommu_detach_group" },
	{ 0x58ab7f99, "get_task_mm" },
	{ 0x5966da5d, "mmu_notifier_register" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x1fde295a, "amd_iommu_domain_set_gcr3" },
	{ 0x6e2b016f, "mmput" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xc5027a1f, "pci_get_domain_bus_and_slot" },
	{ 0xffb8a886, "amd_iommu_is_attach_deferred" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x92997ed8, "_printk" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x48d50e79, "amd_iommu_register_ppr_notifier" },
	{ 0x76fb08a7, "amd_iommu_unregister_ppr_notifier" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1622CC5515760927AB3A9E7");
