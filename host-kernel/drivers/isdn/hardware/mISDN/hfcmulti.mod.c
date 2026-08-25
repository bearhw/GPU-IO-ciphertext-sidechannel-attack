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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xedc03953, "iounmap" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x92997ed8, "_printk" },
	{ 0xbd505649, "consume_skb" },
	{ 0xbb2bf4ae, "get_next_bframe" },
	{ 0xfcb51bb5, "get_next_dframe" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xd057a352, "mISDN_clear_bchannel" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xbe888b32, "skb_put" },
	{ 0xdb1b6c8d, "recv_Dchannel_skb" },
	{ 0x1de23e95, "module_put" },
	{ 0x84052933, "mISDN_ctrl_bchannel" },
	{ 0x60ab036c, "bchannel_get_rxbuf" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x72c9f6b2, "recv_Bchannel" },
	{ 0xbb3fc6f8, "recv_Dchannel" },
	{ 0x69acdf38, "memcpy" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x284faa6b, "__x86_indirect_thunk_r11" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xd2d06d15, "recv_Bchannel_skb" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x26236de8, "mISDN_clock_update" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x222d708e, "mISDN_freebchannel" },
	{ 0x37a0cba, "kfree" },
	{ 0xb6e0a005, "mISDN_freedchannel" },
	{ 0xd822b137, "mISDN_unregister_device" },
	{ 0x588886a6, "l1_event" },
	{ 0xe8f617eb, "mISDN_unregister_clock" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x6d2e16a4, "bchannel_senddata" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0xf294dd92, "dchannel_senddata" },
	{ 0x86f76de7, "queue_ch_frame" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x71b337ed, "create_l1" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xde80cd09, "ioremap" },
	{ 0x85bd1608, "__request_region" },
	{ 0xc3401729, "mISDN_register_clock" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xd5a938fc, "mISDN_initdchannel" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5339c64, "mISDN_register_device" },
	{ 0x9ce1309f, "mISDN_initbchannel" },
	{ 0x86490580, "current_task" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x786109b9, "param_array_ops" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mISDN_core");

MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000B567bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000B566bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000B569bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000B560bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000B568bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd000008B4bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000B520bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000B620bc*sc*i*");
MODULE_ALIAS("pci:v0000D161d0000B410sv0000D161sd0000B410bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000B540bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000B550bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd00001234bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000E888bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000E884bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000B761bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv00001397sd0000B762bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000016B8sv00001397sd0000B562bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000016B8sv00001397sd0000B56Bbc*sc*i*");
MODULE_ALIAS("pci:v00001397d000016B8sv00001397sd000016B8bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000016B8sv00001397sd0000B521bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000016B8sv00001397sd0000B522bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000016B8sv00001397sd0000B552bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000016B8sv00001397sd0000B622bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000016B8sv00001397sd0000E998bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000016B8sv00001397sd0000B55Bbc*sc*i*");
MODULE_ALIAS("pci:v00001397d000030B1sv00001397sd0000B563bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000030B1sv00001397sd0000B56Abc*sc*i*");
MODULE_ALIAS("pci:v00001397d000030B1sv00001397sd0000B565bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000030B1sv00001397sd0000B564bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000030B1sv00001397sd000030B1bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000030B1sv00001397sd0000B523bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000030B1sv00001397sd0000C523bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009030sv00001397sd00003136bc*sc*i*");
MODULE_ALIAS("pci:v000010B5d00009030sv00001397sd00003137bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000030B1sv00001397sd0000B553bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000008B4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000016B8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001397d000030B1sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "6759AACD4AAF34945B073FC");
