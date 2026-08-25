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
	{ 0xb42a7fb9, "metadata_dst_free" },
	{ 0xe05b6928, "dst_release" },
	{ 0xe2648860, "nft_reg_track_update" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x8520a781, "nla_put" },
	{ 0x38d85c39, "nft_dump_register" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe1da1c18, "nft_parse_register_store" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x431ec3a9, "__nla_validate" },
	{ 0x672bdf0d, "metadata_dst_alloc" },
	{ 0xae39f80e, "dst_cache_init" },
	{ 0x69acdf38, "memcpy" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x61688841, "nft_register_obj" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x497d4d0e, "nft_unregister_obj" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_tables");


MODULE_INFO(srcversion, "C3C5272DB990C266EA7F449");
