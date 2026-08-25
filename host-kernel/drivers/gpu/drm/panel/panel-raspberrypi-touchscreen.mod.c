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
	{ 0xb2e0d50e, "mipi_dsi_detach" },
	{ 0xe6eded86, "drm_panel_remove" },
	{ 0x8ff636f7, "mipi_dsi_device_unregister" },
	{ 0x8841440c, "mipi_dsi_attach" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xc4900a58, "i2c_smbus_read_byte_data" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0xf65ae7d0, "mipi_dsi_driver_register_full" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0xfe7c0d8e, "mipi_dsi_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm");

MODULE_ALIAS("of:N*T*Craspberrypi,7inch-touchscreen-panel");
MODULE_ALIAS("of:N*T*Craspberrypi,7inch-touchscreen-panelC*");

MODULE_INFO(srcversion, "FC8D7A4E251AD9C1CDD3D11");
