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
	{ 0xae47eb8d, "nft_chain_validate_hooks" },
	{ 0x4115b9d4, "nf_send_unreach" },
	{ 0xdb22ea97, "nf_send_unreach6" },
	{ 0x93e1bf7b, "nf_send_reset6" },
	{ 0x2bbde5c2, "nf_send_reset" },
	{ 0xe2c84666, "nft_reject_icmp_code" },
	{ 0x1de558c1, "nft_reject_icmpv6_code" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0xc68d427f, "nft_reject_init" },
	{ 0x2a5b95f2, "nft_reject_dump" },
	{ 0x6081751d, "nft_reject_policy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_tables,nf_reject_ipv4,nf_reject_ipv6,nft_reject");


MODULE_INFO(srcversion, "B1C0FF5C2DED80F3E257151");
