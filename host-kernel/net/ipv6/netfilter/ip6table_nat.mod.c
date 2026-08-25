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
	{ 0x949ea9cc, "ip6t_unregister_table_exit" },
	{ 0x58006d04, "nf_nat_ipv6_unregister_fn" },
	{ 0x37a0cba, "kfree" },
	{ 0x16d8a0e, "ip6t_alloc_initial_table" },
	{ 0xc3f30d21, "ip6t_register_table" },
	{ 0xa10ec8d9, "xt_find_table" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x7f5dc2cf, "nf_nat_ipv6_register_fn" },
	{ 0xc16f7ad, "xt_register_template" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x2146cc7c, "xt_unregister_template" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xae85d15b, "ip6t_do_table" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip6_tables,nf_nat,x_tables");


MODULE_INFO(srcversion, "CB3A6F4FFFB8C8633CFDEC9");
