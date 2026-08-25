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
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0x36aa99fd, "gpiod_set_value" },
	{ 0x533ac20c, "gpiod_cansleep" },
	{ 0x7954df, "gpiod_direction_output" },
	{ 0x3dafe076, "devm_led_classdev_register_ext" },
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2a11d5c9, "devm_gpiod_get_index" },
	{ 0x2ab20b28, "gpiod_set_consumer_name" },
	{ 0xce9da695, "device_get_child_node_count" },
	{ 0xf719c0d, "led_init_default_state_get" },
	{ 0xd8cad17f, "fwnode_property_present" },
	{ 0xf3f5b3f5, "device_get_next_child_node" },
	{ 0x27c5bd3c, "devm_fwnode_gpiod_get_index" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0xd0731f29, "devm_gpio_request_one" },
	{ 0xe582fa0e, "gpio_to_desc" },
	{ 0x2587f789, "_dev_info" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cgpio-leds");
MODULE_ALIAS("of:N*T*Cgpio-ledsC*");

MODULE_INFO(srcversion, "4769AB7588F43C9420B6DF6");
