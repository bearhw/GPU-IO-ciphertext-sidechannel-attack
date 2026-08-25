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
	{ 0x83eb21c, "rfkill_unregister" },
	{ 0xdb68bbad, "rfkill_destroy" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xb0c47761, "device_property_read_string" },
	{ 0x50b73ce2, "rfkill_find_type" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0xf29a63f8, "rfkill_alloc" },
	{ 0xff282521, "rfkill_register" },
	{ 0x7bd671b3, "acpi_match_device" },
	{ 0x89b4264a, "devm_acpi_dev_add_driver_gpios" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0x815588a6, "clk_enable" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:BCM4752:*");
MODULE_ALIAS("acpi*:LNV4752:*");

MODULE_INFO(srcversion, "B471F4E8EA0C3FE4458E916");
