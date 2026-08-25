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
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x92997ed8, "_printk" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd057a352, "mISDN_clear_bchannel" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x1de23e95, "module_put" },
	{ 0x84052933, "mISDN_ctrl_bchannel" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xabdc439, "cc_platform_has" },
	{ 0xbd505649, "consume_skb" },
	{ 0xbb2bf4ae, "get_next_bframe" },
	{ 0x60ab036c, "bchannel_get_rxbuf" },
	{ 0xbe888b32, "skb_put" },
	{ 0x72c9f6b2, "recv_Bchannel" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x222d708e, "mISDN_freebchannel" },
	{ 0xd822b137, "mISDN_unregister_device" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x5021bd81, "_raw_write_lock_irqsave" },
	{ 0xeb078aee, "_raw_write_unlock_irqrestore" },
	{ 0x37a0cba, "kfree" },
	{ 0xb74b780e, "param_set_uint" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x6d2e16a4, "bchannel_senddata" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xdd3f7346, "mISDNisac_irq" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xca0d845a, "mISDNisac_init" },
	{ 0x9ce1309f, "mISDN_initbchannel" },
	{ 0x85bd1608, "__request_region" },
	{ 0xc5339c64, "mISDN_register_device" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x18f07c94, "param_get_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mISDN_core,mISDNipac");

MODULE_ALIAS("pci:v00001244d00000A00sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001244d00000E00sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "D9666A3CA9CFBEC49874B01");
