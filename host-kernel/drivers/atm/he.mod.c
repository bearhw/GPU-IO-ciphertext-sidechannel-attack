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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x2f7754a8, "dma_pool_free" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x7b37d4a7, "_find_first_zero_bit" },
	{ 0x678b96ec, "dma_pool_alloc" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x44c6e633, "vcc_sklist_lock" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x2cc2d52d, "vcc_hash" },
	{ 0xf0dba0fe, "atm_alloc_charge" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xbe888b32, "skb_put" },
	{ 0x69acdf38, "memcpy" },
	{ 0x6d606913, "pv_ops" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0x350f6ce5, "tasklet_unlock_wait" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x37a0cba, "kfree" },
	{ 0xb5aa7165, "dma_pool_destroy" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xedc03953, "iounmap" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x1b1cdbe1, "atm_dev_deregister" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x99d368a7, "atm_dev_register" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x2364c85a, "tasklet_init" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xde80cd09, "ioremap" },
	{ 0xf9a482f9, "msleep" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xd9aa089e, "dma_pool_create" },
	{ 0x22a688a2, "suni_init" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xc6cbbc89, "capable" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x86490580, "current_task" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xf49bc67a, "atm_pcr_goal" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x82f7ca44, "param_ops_short" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm,suni");

MODULE_ALIAS("pci:v00001127d00000400sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "51C82C1CE046525BCDD8AE5");
