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
	{ 0x15ba50a6, "jiffies" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xd057a352, "mISDN_clear_bchannel" },
	{ 0x1de23e95, "module_put" },
	{ 0x84052933, "mISDN_ctrl_bchannel" },
	{ 0x69acdf38, "memcpy" },
	{ 0xfb578fc5, "memset" },
	{ 0xbd505649, "consume_skb" },
	{ 0xbb2bf4ae, "get_next_bframe" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x86490580, "current_task" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xbe888b32, "skb_put" },
	{ 0x72c9f6b2, "recv_Bchannel" },
	{ 0x60ab036c, "bchannel_get_rxbuf" },
	{ 0xed87e4f9, "driver_for_each_device" },
	{ 0x24d273d1, "add_timer" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xedc03953, "iounmap" },
	{ 0xd822b137, "mISDN_unregister_device" },
	{ 0x222d708e, "mISDN_freebchannel" },
	{ 0xb6e0a005, "mISDN_freedchannel" },
	{ 0x37a0cba, "kfree" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x588886a6, "l1_event" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd5a938fc, "mISDN_initdchannel" },
	{ 0x9ce1309f, "mISDN_initbchannel" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xde80cd09, "ioremap" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5339c64, "mISDN_register_device" },
	{ 0xf294dd92, "dchannel_senddata" },
	{ 0x86f76de7, "queue_ch_frame" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x71b337ed, "create_l1" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x6d2e16a4, "bchannel_senddata" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xfcb51bb5, "get_next_dframe" },
	{ 0xbb3fc6f8, "recv_Dchannel" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mISDN_core");

MODULE_ALIAS("pci:v00001397d00002BD0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d0000B000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d0000B006sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d0000B007sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d0000B008sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d0000B009sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d0000B00Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d0000B00Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d0000B00Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d0000B100sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d0000B700sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d0000B701sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000013D1d00002BD1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001043d00000675sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00000871d0000FFA2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00000871d0000FFA1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001051d00000100sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000015B0d00002BD0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000114Fd00000070sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000114Fd00000071sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000114Fd00000072sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000114Fd00000073sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000182Dd00003069sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "34CAADB77D032C41FB0F445");
