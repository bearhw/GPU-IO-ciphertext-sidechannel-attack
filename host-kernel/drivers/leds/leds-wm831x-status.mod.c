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
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x7c82439, "wm831x_reg_write" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x169938c1, "__sysfs_match_string" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xf7567faa, "wm831x_reg_read" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C187133C687AD407E39FC3E");
