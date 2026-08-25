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

SYMBOL_CRC(nvmet_fc_register_targetport, 0x85de129b, "_gpl");
SYMBOL_CRC(nvmet_fc_invalidate_host, 0x4a013682, "_gpl");
SYMBOL_CRC(nvmet_fc_unregister_targetport, 0x9ef76d99, "_gpl");
SYMBOL_CRC(nvmet_fc_rcv_ls_req, 0x0b98123d, "_gpl");
SYMBOL_CRC(nvmet_fc_rcv_fcp_req, 0x1048b92a, "_gpl");
SYMBOL_CRC(nvmet_fc_rcv_fcp_abort, 0x7fa5302a, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x78074d80, "nvmet_req_complete" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0xe753b214, "dma_sync_single_for_device" },
	{ 0xfba7ddd2, "match_u64" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x35c7353, "nvmet_sq_destroy" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x92997ed8, "_printk" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa916b694, "strnlen" },
	{ 0x3a13f54a, "sgl_alloc" },
	{ 0x6508aecd, "nvmet_unregister_transport" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x92cc0704, "nvmet_req_init" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x2e47c67f, "nvmet_register_transport" },
	{ 0x5a921311, "strncmp" },
	{ 0xffb7c514, "ida_free" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x95a0381b, "dma_sync_single_for_cpu" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x6d606913, "pv_ops" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x3214b0a8, "nvmet_sq_init" },
	{ 0x87b8798d, "sg_next" },
	{ 0x56470118, "__warn_printk" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x840342c6, "sgl_free" },
	{ 0x3e0ef07a, "nvmet_wq" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nvmet");


MODULE_INFO(srcversion, "143D9710C7C25B1BF3F4F2A");
