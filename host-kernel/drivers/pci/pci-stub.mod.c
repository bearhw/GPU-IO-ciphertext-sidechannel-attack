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
	{ 0x2587f789, "_dev_info" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x85df9b6c, "strsep" },
	{ 0x754d539c, "strlen" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x92997ed8, "_printk" },
	{ 0x2526e5ae, "pci_add_dynid" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x5daa032f, "param_ops_string" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "49C558367A9555E0B8385BD");
