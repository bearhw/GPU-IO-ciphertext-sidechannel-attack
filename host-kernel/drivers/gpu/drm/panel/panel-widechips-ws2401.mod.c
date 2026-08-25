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
	{ 0xe6eded86, "drm_panel_remove" },
	{ 0x57563a, "mipi_dbi_command_stackbuf" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb5e74aec, "drm_mode_duplicate" },
	{ 0xeb96c64a, "drm_display_info_set_bus_formats" },
	{ 0x4a35d30d, "drm_mode_set_name" },
	{ 0xa53d4e7, "drm_mode_probed_add" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa7f82999, "regulator_bulk_enable" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xfdd691bf, "devm_regulator_bulk_get" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0xbe787cc2, "mipi_dbi_spi_init" },
	{ 0x10e15c16, "mipi_dbi_command_read" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x58d77836, "regulator_bulk_disable" },
	{ 0x38505e42, "drm_panel_init" },
	{ 0x5ff68af9, "drm_panel_of_backlight" },
	{ 0x71b4708d, "drm_panel_add" },
	{ 0x2587f789, "_dev_info" },
	{ 0x7c9d6cd0, "devm_backlight_device_register" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,drm_mipi_dbi");

MODULE_ALIAS("of:N*T*Csamsung,lms380kf01");
MODULE_ALIAS("of:N*T*Csamsung,lms380kf01C*");

MODULE_INFO(srcversion, "39013D6A5AF3BE0F1C207BE");
