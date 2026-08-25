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
	{ 0xe2648860, "nft_reg_track_update" },
	{ 0x80f36393, "nft_expr_reduce_bitwise" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xae47eb8d, "nft_chain_validate_hooks" },
	{ 0x8520a781, "nla_put" },
	{ 0x38d85c39, "nft_dump_register" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe1da1c18, "nft_parse_register_store" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x9d58a9c, "nf_sk_lookup_slow_v6" },
	{ 0x2c795cac, "sock_gen_put" },
	{ 0x8eb22bf5, "nf_sk_lookup_slow_v4" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_tables,nf_socket_ipv6,nf_socket_ipv4");


MODULE_INFO(srcversion, "2A5CB897C8D7EC52E50CE3C");
