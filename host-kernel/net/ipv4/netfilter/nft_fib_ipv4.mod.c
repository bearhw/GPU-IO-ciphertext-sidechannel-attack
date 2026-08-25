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

SYMBOL_CRC(nft_fib4_eval_type, 0x73ed2ee9, "_gpl");
SYMBOL_CRC(nft_fib4_eval, 0x6b994b84, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa49ea9b8, "nft_fib_store_result" },
	{ 0x18b52244, "fib_table_lookup" },
	{ 0x78b279d1, "fib_info_nh_uses_dev" },
	{ 0x94a6da4d, "__fib_lookup" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1ac1e32b, "inet_dev_addr_type" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x496464b1, "nft_fib_init" },
	{ 0xc96487a0, "nft_fib_dump" },
	{ 0x85b243f9, "nft_fib_validate" },
	{ 0xebc15f3e, "nft_fib_reduce" },
	{ 0xb3c36947, "nft_fib_policy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nft_fib,nf_tables");


MODULE_INFO(srcversion, "A46997A50AAC131EF1FA39D");
