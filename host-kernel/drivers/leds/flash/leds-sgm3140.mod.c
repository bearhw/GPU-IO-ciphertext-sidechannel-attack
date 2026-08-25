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
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xf8d190e6, "v4l2_flash_release" },
	{ 0x36aa99fd, "gpiod_set_value" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0x3dc5780e, "fwnode_get_next_available_child_node" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x1063441c, "devm_led_classdev_flash_register_ext" },
	{ 0xa916b694, "strnlen" },
	{ 0xdd64e639, "strscpy" },
	{ 0xae7f4086, "v4l2_flash_init" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xf1969a8e, "__usecs_to_jiffies" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "v4l2-flash-led-class,led-class-flash");

MODULE_ALIAS("of:N*T*Cocs,ocp8110");
MODULE_ALIAS("of:N*T*Cocs,ocp8110C*");
MODULE_ALIAS("of:N*T*Csgmicro,sgm3140");
MODULE_ALIAS("of:N*T*Csgmicro,sgm3140C*");

MODULE_INFO(srcversion, "6F573BC17AE2DFAD19F6837");
