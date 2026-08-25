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
	{ 0x7954df, "gpiod_direction_output" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xce9da695, "device_get_child_node_count" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0xf3f5b3f5, "device_get_next_child_node" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0xd8cad17f, "fwnode_property_present" },
	{ 0x3dafe076, "devm_led_classdev_register_ext" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xf235f72e, "device_property_read_u8_array" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0x2587f789, "_dev_info" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:lm3532-led");
MODULE_ALIAS("of:N*T*Cti,lm3532");
MODULE_ALIAS("of:N*T*Cti,lm3532C*");

MODULE_INFO(srcversion, "1295783CFF250EDD3FB1131");
