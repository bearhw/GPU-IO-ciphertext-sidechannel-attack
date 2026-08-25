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
	{ 0x754d539c, "strlen" },
	{ 0xae7f4086, "v4l2_flash_init" },
	{ 0xc37d5373, "v4l2_flash_indicator_init" },
	{ 0xf8d190e6, "v4l2_flash_release" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc4900a58, "i2c_smbus_read_byte_data" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0xe4933139, "dev_fwnode" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xd404c390, "fwnode_get_next_child_node" },
	{ 0xf5303a12, "fwnode_handle_get" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x2587f789, "_dev_info" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x16c36dbb, "led_classdev_flash_register_ext" },
	{ 0x46bfcb53, "led_classdev_flash_unregister" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "v4l2-flash-led-class,led-class-flash");

MODULE_ALIAS("of:N*T*Cams,as3645a");
MODULE_ALIAS("of:N*T*Cams,as3645aC*");
MODULE_ALIAS("i2c:as3645a");

MODULE_INFO(srcversion, "E498A1F5697AB89DE60E4A6");
