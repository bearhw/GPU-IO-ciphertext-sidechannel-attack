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
	{ 0x92997ed8, "_printk" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x37a0cba, "kfree" },
	{ 0xbd505649, "consume_skb" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x1b1cdbe1, "atm_dev_deregister" },
	{ 0x999e8297, "vfree" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xedc03953, "iounmap" },
	{ 0x24d273d1, "add_timer" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xbe888b32, "skb_put" },
	{ 0xf49bc67a, "atm_pcr_goal" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xe753b214, "dma_sync_single_for_device" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x74129b89, "__netdev_alloc_skb" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x95a0381b, "dma_sync_single_for_cpu" },
	{ 0x3926200e, "atm_charge" },
	{ 0x69acdf38, "memcpy" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xde80cd09, "ioremap" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x99d368a7, "atm_dev_register" },
	{ 0x22a688a2, "suni_init" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x40a9b349, "vzalloc" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x7c6024bd, "init_net" },
	{ 0xbcd1484c, "dev_get_by_name" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm,suni");

MODULE_ALIAS("pci:v0000111Dd00000003sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "DB9CF985CE00A67037779A7");
