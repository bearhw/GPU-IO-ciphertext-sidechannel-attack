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
	{ 0x8e835ca5, "ebt_unregister_table" },
	{ 0x8617fa12, "ebt_unregister_table_pre_exit" },
	{ 0x252f6ea6, "ebt_register_table" },
	{ 0xc5ccdab5, "ebt_do_table" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2a1ed665, "ebt_register_template" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x6a5bacf3, "ebt_unregister_template" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ebtables");


MODULE_INFO(srcversion, "F83E181733397621BD662D9");
