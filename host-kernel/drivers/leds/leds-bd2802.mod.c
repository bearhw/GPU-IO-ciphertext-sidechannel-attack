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
	{ 0x36aa99fd, "gpiod_set_value" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x668b19a1, "down_read" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x53b954a2, "up_read" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x2121e851, "device_create_file" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0x2587f789, "_dev_info" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:BD2802");

MODULE_INFO(srcversion, "F2E80E55648B5907F5AE94C");
