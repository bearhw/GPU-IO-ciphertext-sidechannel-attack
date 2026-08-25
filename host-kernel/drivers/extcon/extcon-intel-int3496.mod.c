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
	{ 0x2d3385d3, "system_wq" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0x7954df, "gpiod_direction_output" },
	{ 0x534fa9b, "extcon_set_state_sync" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x89b4264a, "devm_acpi_dev_add_driver_gpios" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0xef7859b8, "gpiod_to_irq" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xb5e73116, "flush_delayed_work" },
	{ 0x6d97917a, "devm_regulator_get_optional" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("platform:intel-int3496");
MODULE_ALIAS("acpi*:INT3496:*");

MODULE_INFO(srcversion, "64C9DC8C0D28EF061723FBE");
