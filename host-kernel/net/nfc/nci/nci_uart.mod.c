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

SYMBOL_CRC(nci_uart_register, 0x0b9b7e12, "_gpl");
SYMBOL_CRC(nci_uart_unregister, 0x18814ac5, "_gpl");
SYMBOL_CRC(nci_uart_set_config, 0xa46c103a, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x7d819d8d, "tty_set_termios" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xbe888b32, "skb_put" },
	{ 0x9f63718c, "tty_register_ldisc" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x1e4466ed, "tty_driver_flush_buffer" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x6982cc2b, "n_tty_ioctl_helper" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x668b19a1, "down_read" },
	{ 0x264c5f6c, "tty_unregister_ldisc" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x5641485b, "tty_termios_encode_baud_rate" },
	{ 0xe686e851, "tty_unthrottle" },
	{ 0x53b954a2, "up_read" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F512F926BBB4B4343B0FBE8");
