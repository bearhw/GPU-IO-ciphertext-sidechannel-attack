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
	{ 0x38d85c39, "nft_dump_register" },
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0xe2b8cc13, "nft_parse_register_load" },
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0x5ed6a51f, "nf_nat_redirect_ipv6" },
	{ 0xcaf3db26, "nf_nat_redirect_ipv4" },
	{ 0x5d0f4059, "nft_chain_validate_dependency" },
	{ 0xae47eb8d, "nft_chain_validate_hooks" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_tables,nf_conntrack,nf_nat");


MODULE_INFO(srcversion, "4DF73B27FD50240FBC2CD0C");
