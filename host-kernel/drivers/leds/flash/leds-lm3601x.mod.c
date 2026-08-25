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
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xf3f5b3f5, "device_get_next_child_node" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x1063441c, "devm_led_classdev_flash_register_ext" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "led-class-flash");

MODULE_ALIAS("of:N*T*Cti,lm36010");
MODULE_ALIAS("of:N*T*Cti,lm36010C*");
MODULE_ALIAS("of:N*T*Cti,lm36011");
MODULE_ALIAS("of:N*T*Cti,lm36011C*");
MODULE_ALIAS("i2c:LM36010");
MODULE_ALIAS("i2c:LM36011");

MODULE_INFO(srcversion, "76A978B717971116450971A");
