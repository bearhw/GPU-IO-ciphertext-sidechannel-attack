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
	{ 0xce2840e7, "irq_set_irq_wake" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xc9fd634a, "usb_role_switch_put" },
	{ 0x131db64a, "system_long_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x9a5c00da, "extcon_get_state" },
	{ 0xd5474690, "usb_role_switch_set_role" },
	{ 0xff42c374, "usb_role_switch_get_role" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcea381dd, "x86_match_cpu" },
	{ 0xda8e1302, "software_node_find_by_name" },
	{ 0xb9f44d98, "software_node_fwnode" },
	{ 0x8989a213, "usb_role_switch_find_by_fwnode" },
	{ 0xf3d01128, "fwnode_handle_put" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x278797c8, "acpi_dev_get_first_match_dev" },
	{ 0x3db7d641, "extcon_get_extcon_dev" },
	{ 0x3197c4e3, "put_device" },
	{ 0x86f27420, "iosf_mbi_block_punit_i2c_access" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x44414ff2, "iosf_mbi_unblock_punit_i2c_access" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x55784228, "regmap_irq_get_virq" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x2a023b5d, "devm_extcon_register_notifier_all" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2587f789, "_dev_info" },
	{ 0x534fa9b, "extcon_set_state_sync" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("platform:axp288_extcon");

MODULE_INFO(srcversion, "C7AF7D9707C9BA022A025B0");
