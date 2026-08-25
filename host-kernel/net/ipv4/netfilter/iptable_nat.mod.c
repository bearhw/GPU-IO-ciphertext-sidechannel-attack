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
	{ 0x7c68ce19, "ipt_unregister_table_exit" },
	{ 0xbb64dc4a, "nf_nat_ipv4_unregister_fn" },
	{ 0x37a0cba, "kfree" },
	{ 0xa3f92fb8, "ipt_alloc_initial_table" },
	{ 0xe29834a6, "ipt_register_table" },
	{ 0xa10ec8d9, "xt_find_table" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xa8c553cb, "nf_nat_ipv4_register_fn" },
	{ 0xc16f7ad, "xt_register_template" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x2146cc7c, "xt_unregister_template" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x9456f63b, "ipt_do_table" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_tables,nf_nat,x_tables");


MODULE_INFO(srcversion, "A96B007447F3E782024E28F");
