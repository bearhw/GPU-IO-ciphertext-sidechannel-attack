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

SYMBOL_CRC(mISDNisar_irq, 0xaf5ee792, "");
SYMBOL_CRC(mISDNisar_init, 0x57466aef, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xfe916dc6, "hex_dump_to_buffer" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x9ce1309f, "mISDN_initbchannel" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd057a352, "mISDN_clear_bchannel" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x1de23e95, "module_put" },
	{ 0x84052933, "mISDN_ctrl_bchannel" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xbd505649, "consume_skb" },
	{ 0xbb2bf4ae, "get_next_bframe" },
	{ 0x6d2e16a4, "bchannel_senddata" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x60ab036c, "bchannel_get_rxbuf" },
	{ 0xbe888b32, "skb_put" },
	{ 0x72c9f6b2, "recv_Bchannel" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x24d273d1, "add_timer" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mISDN_core");


MODULE_INFO(srcversion, "BC16005578E36B8ED117948");
