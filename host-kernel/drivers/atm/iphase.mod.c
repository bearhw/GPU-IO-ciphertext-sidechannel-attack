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
	{ 0x92997ed8, "_printk" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x37a0cba, "kfree" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x1b1cdbe1, "atm_dev_deregister" },
	{ 0xedc03953, "iounmap" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x86490580, "current_task" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x99d368a7, "atm_dev_register" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xde80cd09, "ioremap" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa4191c0b, "memset_io" },
	{ 0xfb578fc5, "memset" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x22a688a2, "suni_init" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xc6cbbc89, "capable" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x5a4896a8, "__put_user_2" },
	{ 0xf0dba0fe, "atm_alloc_charge" },
	{ 0xbe888b32, "skb_put" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x24d273d1, "add_timer" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm,suni");

MODULE_ALIAS("pci:v0000107Ed00000008sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000107Ed00000009sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "3F1811A886B33983B40E06C");
