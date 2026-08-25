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
	{ 0x90b0f1ed, "scsi_dma_map" },
	{ 0xbe564b91, "fw_send_response" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xc8f2543, "fw_run_transaction" },
	{ 0xaedf84ce, "fw_high_memory_region" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xa6257a2f, "complete" },
	{ 0xb27eb5df, "scsi_remove_host" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x69acdf38, "memcpy" },
	{ 0x478437e6, "scsi_dma_unmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x36eadb73, "fw_core_remove_address_handler" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa1939e45, "fw_core_add_address_handler" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x69ab51db, "scsi_device_lookup" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xab25a05c, "fw_cancel_transaction" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x12e047bb, "scsi_device_put" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x61d12418, "blk_queue_update_dma_alignment" },
	{ 0x6ec3e817, "scsi_host_put" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x3c56ef91, "fw_workqueue" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0xea3c8e4e, "scsilun_to_int" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xe80e5087, "fw_csr_iterator_init" },
	{ 0x87b8798d, "sg_next" },
	{ 0x2369da5f, "fw_bus_type" },
	{ 0x56470118, "__warn_printk" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x9d05c15c, "scsi_done" },
	{ 0xa84c174d, "scsi_unblock_requests" },
	{ 0x15cf37f1, "fw_send_request" },
	{ 0xb363452c, "scsi_remove_device" },
	{ 0xbb146a4b, "blk_queue_max_hw_sectors" },
	{ 0xf856ea45, "scsi_block_requests" },
	{ 0x816fc9e7, "scsi_add_host_with_dma" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xe2cad31b, "scsi_host_alloc" },
	{ 0x1b17d541, "__scsi_add_device" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x95b42ae9, "fw_device_enable_phys_dma" },
	{ 0xe3fde125, "fw_csr_iterator_next" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "firewire-core");

MODULE_ALIAS("ieee1394:ven*mo*sp0000609Ever00010483*");

MODULE_INFO(srcversion, "23164C86D8370AFC3076332");
