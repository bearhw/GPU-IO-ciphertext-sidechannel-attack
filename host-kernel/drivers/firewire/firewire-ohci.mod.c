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
	{ 0x8a35b432, "sme_me_mask" },
	{ 0xbbe839b2, "pci_save_state" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x7cb8cb5f, "pci_request_region" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xae121354, "pci_iomap" },
	{ 0xb0e602eb, "memmove" },
	{ 0xb1edfe5e, "pci_choose_state" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x1d773d47, "dma_free_pages" },
	{ 0xe753b214, "dma_sync_single_for_device" },
	{ 0x6128b5fc, "__printk_ratelimit" },
	{ 0x20d8d10f, "pci_disable_msi" },
	{ 0x69acdf38, "memcpy" },
	{ 0x94961283, "vunmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x1bfe1491, "pci_set_power_state" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x6cf685e0, "fw_card_add" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x9b3dfc25, "fw_core_handle_request" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xa7740ca9, "dma_alloc_pages" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0xb0f43515, "fw_core_remove_card" },
	{ 0xa8a194c9, "pci_enable_msi" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x2364c85a, "tasklet_init" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xed2a2b32, "vmap" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xbbf0b873, "pci_restore_state" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0x95a0381b, "dma_sync_single_for_cpu" },
	{ 0xfb578fc5, "memset" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x9fcd89b0, "fw_core_handle_response" },
	{ 0x37fefd44, "fw_fill_response" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xe3feba56, "tasklet_unlock_spin_wait" },
	{ 0x6df810a, "fw_schedule_bus_reset" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x279526d8, "fw_card_initialize" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x56470118, "__warn_printk" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xa9320d27, "ktime_get_seconds" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x350f6ce5, "tasklet_unlock_wait" },
	{ 0xf34989c, "pci_release_region" },
	{ 0x4e89d458, "fw_core_handle_bus_reset" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "firewire-core");

MODULE_ALIAS("pci:v*d*sv*sd*bc0Csc00i10*");

MODULE_INFO(srcversion, "E7A9075D5DE58FF3D1F1086");
