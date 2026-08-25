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
	{ 0x47db41bd, "nf_nat_inet_unregister_fn" },
	{ 0xbfb178e, "nf_nat_inet_register_fn" },
	{ 0xec623802, "ipv6_find_hdr" },
	{ 0x41675c5e, "nft_do_chain" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcdc37acf, "nft_register_chain_type" },
	{ 0xa0187704, "nft_unregister_chain_type" },
	{ 0x7f5dc2cf, "nf_nat_ipv6_register_fn" },
	{ 0x58006d04, "nf_nat_ipv6_unregister_fn" },
	{ 0xa8c553cb, "nf_nat_ipv4_register_fn" },
	{ 0xbb64dc4a, "nf_nat_ipv4_unregister_fn" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_nat,nf_tables");


MODULE_INFO(srcversion, "355DF73E2976056E9EE21A7");
