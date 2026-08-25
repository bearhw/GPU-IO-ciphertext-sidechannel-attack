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
	{ 0x6d606913, "pv_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0xcd3165e6, "__dev_kfree_skb_irq" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0x37a0cba, "kfree" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x1b1cdbe1, "atm_dev_deregister" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xedc03953, "iounmap" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xf49bc67a, "atm_pcr_goal" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x738737f9, "skb_unlink" },
	{ 0x74129b89, "__netdev_alloc_skb" },
	{ 0xc6cbbc89, "capable" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x1000e51, "schedule" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xde80cd09, "ioremap" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xfb578fc5, "memset" },
	{ 0x99d368a7, "atm_dev_register" },
	{ 0x652032cb, "mac_pton" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x95a0381b, "dma_sync_single_for_cpu" },
	{ 0x3926200e, "atm_charge" },
	{ 0xbe888b32, "skb_put" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x69acdf38, "memcpy" },
	{ 0xfef216eb, "_raw_spin_trylock" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x20978fb9, "idr_find" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x24d273d1, "add_timer" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x786109b9, "param_array_ops" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm");

MODULE_ALIAS("pci:v0000111Dd00000001sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "40543BA609691E007D2CD26");
