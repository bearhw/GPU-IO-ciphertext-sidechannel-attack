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
	{ 0x6943d367, "nf_flow_offload_ipv6_hook" },
	{ 0x5f762a35, "nf_flow_offload_ip_hook" },
	{ 0x77701025, "nf_flow_rule_route_ipv6" },
	{ 0x5efd69a, "nf_flow_rule_route_ipv4" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x1bc1a5b7, "nft_register_flowtable_type" },
	{ 0xc9345284, "nft_unregister_flowtable_type" },
	{ 0xe6e8770b, "nf_flow_table_init" },
	{ 0x52f6e549, "nf_flow_table_offload_setup" },
	{ 0x83b2a57a, "nf_flow_table_free" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_flow_table,nf_tables");


MODULE_INFO(srcversion, "3192D473615F36A6403D9F2");
