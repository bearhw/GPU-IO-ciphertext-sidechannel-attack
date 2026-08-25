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
	{ 0x272e9f57, "arpt_unregister_table" },
	{ 0x51b2d6fa, "arpt_unregister_table_pre_exit" },
	{ 0x91ec39a8, "arpt_alloc_initial_table" },
	{ 0xca74480c, "arpt_register_table" },
	{ 0x37a0cba, "kfree" },
	{ 0xc16f7ad, "xt_register_template" },
	{ 0x3f116e4f, "arpt_do_table" },
	{ 0x6dfcff39, "xt_hook_ops_alloc" },
	{ 0x2146cc7c, "xt_unregister_template" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "arp_tables,x_tables");


MODULE_INFO(srcversion, "025E77FBC92D373C2D13841");
