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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x36aa99fd, "gpiod_set_value" },
	{ 0xf2a22dc6, "w1_remove_master_device" },
	{ 0xe272a15f, "gpiod_get_value" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2a11d5c9, "devm_gpiod_get_index" },
	{ 0x115aed6d, "devm_gpiod_get_index_optional" },
	{ 0x7954df, "gpiod_direction_output" },
	{ 0xcf9384e, "w1_add_master_device" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6a7d4e41, "gpiod_set_raw_value" },
	{ 0xf9a482f9, "msleep" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "wire");


MODULE_INFO(srcversion, "D68AAEA6B1450D31FBF8E9E");
