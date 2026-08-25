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
	{ 0xd28544d1, "pwm_apply_state" },
	{ 0xce9da695, "device_get_child_node_count" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3dafe076, "devm_led_classdev_register_ext" },
	{ 0xf3f5b3f5, "device_get_next_child_node" },
	{ 0xb053cfac, "fwnode_property_read_string" },
	{ 0xd8cad17f, "fwnode_property_present" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0xf719c0d, "led_init_default_state_get" },
	{ 0xf14ad8b5, "devm_fwnode_pwm_get" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cpwm-leds");
MODULE_ALIAS("of:N*T*Cpwm-ledsC*");

MODULE_INFO(srcversion, "4C8952602F0E6A1EF79C66F");
