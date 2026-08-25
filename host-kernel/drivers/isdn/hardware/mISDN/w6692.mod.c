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
	{ 0x588886a6, "l1_event" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x92997ed8, "_printk" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x60ab036c, "bchannel_get_rxbuf" },
	{ 0xbe888b32, "skb_put" },
	{ 0xabdc439, "cc_platform_has" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0xb74b780e, "param_set_uint" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xd057a352, "mISDN_clear_bchannel" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xd822b137, "mISDN_unregister_device" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x222d708e, "mISDN_freebchannel" },
	{ 0xb6e0a005, "mISDN_freedchannel" },
	{ 0x5021bd81, "_raw_write_lock_irqsave" },
	{ 0xeb078aee, "_raw_write_unlock_irqrestore" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x37a0cba, "kfree" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x1de23e95, "module_put" },
	{ 0x84052933, "mISDN_ctrl_bchannel" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xd5a938fc, "mISDN_initdchannel" },
	{ 0x9ce1309f, "mISDN_initbchannel" },
	{ 0x85bd1608, "__request_region" },
	{ 0xc5339c64, "mISDN_register_device" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x71b337ed, "create_l1" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbd505649, "consume_skb" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xbb2bf4ae, "get_next_bframe" },
	{ 0x72c9f6b2, "recv_Bchannel" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x24d273d1, "add_timer" },
	{ 0xf294dd92, "dchannel_senddata" },
	{ 0x86f76de7, "queue_ch_frame" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xfcb51bb5, "get_next_dframe" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xbb3fc6f8, "recv_Dchannel" },
	{ 0x6d2e16a4, "bchannel_senddata" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x18f07c94, "param_get_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mISDN_core");

MODULE_ALIAS("pci:v00000675d00001702sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001050d00006692sv000016ECsd00003409bc*sc*i*");
MODULE_ALIAS("pci:v00001050d00006692sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "E4EC95587C0F51AAD76313A");
