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
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x36aa99fd, "gpiod_set_value" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0xb0c47761, "device_property_read_string" },
	{ 0x9166fada, "strncpy" },
	{ 0x3dafe076, "devm_led_classdev_register_ext" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:lp3952");

MODULE_INFO(srcversion, "A0E82C33AF78A92187A8006");
