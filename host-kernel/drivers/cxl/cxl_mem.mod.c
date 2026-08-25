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
	{ 0x55c6ee3, "cxl_mem_active_inc" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x88f1cc05, "devm_cxl_enumerate_ports" },
	{ 0x3197c4e3, "put_device" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x33e2aa93, "cxl_mem_active_dec" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xde0001e9, "cxl_mem_find_port" },
	{ 0x7f00d276, "__cxl_driver_register" },
	{ 0x3aa44ed5, "devm_cxl_add_port" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xbc31bd33, "cxl_driver_unregister" },
	{ 0x5aaa59be, "cxl_endpoint_autoremove" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cxl_core");


MODULE_INFO(srcversion, "190594F8A63518CB1964440");
