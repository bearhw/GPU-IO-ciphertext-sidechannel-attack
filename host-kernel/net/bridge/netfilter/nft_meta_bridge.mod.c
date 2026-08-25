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
	{ 0xd96ead83, "__nft_reg_track_cancel" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe1da1c18, "nft_parse_register_store" },
	{ 0xe0c85dcd, "nft_meta_get_init" },
	{ 0x22db3a4b, "netdev_master_upper_dev_get_rcu" },
	{ 0x99311936, "br_vlan_enabled" },
	{ 0x16da6c69, "br_vlan_get_proto" },
	{ 0x9166fada, "strncpy" },
	{ 0x94b94301, "nft_meta_get_eval" },
	{ 0x48d93b44, "br_vlan_get_pvid_rcu" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x92fd7b2d, "nft_meta_set_eval" },
	{ 0xee472574, "nft_meta_set_init" },
	{ 0x43480a5d, "nft_meta_set_destroy" },
	{ 0x196482b4, "nft_meta_set_dump" },
	{ 0x25fcc86f, "nft_meta_set_validate" },
	{ 0x13e8e7f7, "nft_meta_get_dump" },
	{ 0x36eb0946, "nft_meta_get_reduce" },
	{ 0x6c6ca47, "nft_meta_policy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_tables,bridge");


MODULE_INFO(srcversion, "36D67BA2DDD30471D927C66");
