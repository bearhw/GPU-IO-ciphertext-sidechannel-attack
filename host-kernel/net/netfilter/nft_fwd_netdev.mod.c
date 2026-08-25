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
	{ 0xfaaba80, "nft_fwd_dup_netdev_offload" },
	{ 0xae47eb8d, "nft_chain_validate_hooks" },
	{ 0x38d85c39, "nft_dump_register" },
	{ 0xe2b8cc13, "nft_parse_register_load" },
	{ 0xdae9e638, "nf_fwd_netdev_egress" },
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0xe589fb23, "neigh_xmit" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_dup_netdev,nf_tables");


MODULE_INFO(srcversion, "76760650023775B169A7EB7");
