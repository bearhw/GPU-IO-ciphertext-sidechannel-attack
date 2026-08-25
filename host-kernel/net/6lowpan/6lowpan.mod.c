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

SYMBOL_CRC(lowpan_register_netdevice, 0x17c7d3ad, "");
SYMBOL_CRC(lowpan_register_netdev, 0xc36dbe8a, "");
SYMBOL_CRC(lowpan_unregister_netdevice, 0x3e3c9028, "");
SYMBOL_CRC(lowpan_unregister_netdev, 0x8976be4c, "");
SYMBOL_CRC(lowpan_header_decompress, 0x8906f4a8, "_gpl");
SYMBOL_CRC(lowpan_header_compress, 0xd894637d, "_gpl");
SYMBOL_CRC(lowpan_nhc_add, 0x7afd4f8e, "");
SYMBOL_CRC(lowpan_nhc_del, 0x1d337a91, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x84ddb145, "__ndisc_fill_addr_option" },
	{ 0xe389f932, "addrconf_add_linklocal" },
	{ 0x69acdf38, "memcpy" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0xf516d652, "addrconf_prefix_rcv_add_addr" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x87549110, "netdev_warn" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0xa498108e, "register_netdevice" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A3E20E9D6156D4B5BD29ED6");
