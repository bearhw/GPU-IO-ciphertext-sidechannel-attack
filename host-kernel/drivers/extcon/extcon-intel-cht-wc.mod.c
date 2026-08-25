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
	{ 0x9085e9a, "_dev_err" },
	{ 0x9ab91f64, "power_supply_get_drvdata" },
	{ 0xc9fd634a, "usb_role_switch_put" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xda8e1302, "software_node_find_by_name" },
	{ 0xb9f44d98, "software_node_fwnode" },
	{ 0x8989a213, "usb_role_switch_find_by_fwnode" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x6d97917a, "devm_regulator_get_optional" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xf9a482f9, "msleep" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x534fa9b, "extcon_set_state_sync" },
	{ 0xd5474690, "usb_role_switch_set_role" },
	{ 0x8d1ce0, "power_supply_changed" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0xf10f2601, "devm_power_supply_register" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("platform:cht_wcove_pwrsrc");

MODULE_INFO(srcversion, "987CE825F79EC7F9093F2D2");
