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

SYMBOL_CRC(gre_add_protocol, 0xa0ee67ce, "_gpl");
SYMBOL_CRC(gre_del_protocol, 0x577a69c3, "_gpl");
SYMBOL_CRC(gre_parse_header, 0xffb431e3, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x45308af5, "__skb_checksum_complete" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x1e208bf5, "inet_add_protocol" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xe71edfc0, "inet_del_protocol" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "AAADDD31CCE61A2B7418302");
