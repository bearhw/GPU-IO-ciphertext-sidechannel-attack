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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(nft_fib_policy, 0xb3c36947, "");
SYMBOL_CRC(nft_fib_validate, 0x85b243f9, "_gpl");
SYMBOL_CRC(nft_fib_init, 0x496464b1, "_gpl");
SYMBOL_CRC(nft_fib_dump, 0xc96487a0, "_gpl");
SYMBOL_CRC(nft_fib_store_result, 0xa49ea9b8, "_gpl");
SYMBOL_CRC(nft_fib_reduce, 0xebc15f3e, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xae47eb8d, "nft_chain_validate_hooks" },
	{ 0xe1da1c18, "nft_parse_register_store" },
	{ 0x38d85c39, "nft_dump_register" },
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe2648860, "nft_reg_track_update" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9166fada, "strncpy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_tables");


MODULE_INFO(srcversion, "CA28BE3B32F5CB6A2902DC9");
