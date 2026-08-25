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
	{ 0xc1514a3b, "free_irq" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xbe888b32, "skb_put" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xe753b214, "dma_sync_single_for_device" },
	{ 0xedc03953, "iounmap" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x1b1cdbe1, "atm_dev_deregister" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x92997ed8, "_printk" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xc6cbbc89, "capable" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x99d368a7, "atm_dev_register" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xf1e046cc, "panic" },
	{ 0xde80cd09, "ioremap" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x95a0381b, "dma_sync_single_for_cpu" },
	{ 0xfb578fc5, "memset" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x3926200e, "atm_charge" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x56470118, "__warn_printk" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x95316761, "dma_set_mask" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm");

MODULE_ALIAS("pci:v00001127d00000300sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "6F373794D6DADBB47CFC7B4");
