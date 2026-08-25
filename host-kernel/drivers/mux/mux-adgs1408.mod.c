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
	{ 0xc1ee0772, "devm_mux_chip_alloc" },
	{ 0x762d2eea, "spi_get_device_id" },
	{ 0xa07321bc, "spi_write_then_read" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb414d0f3, "devm_mux_chip_register" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x9c90d539, "device_get_match_data" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mux-core");

MODULE_ALIAS("of:N*T*Cadi,adgs1408");
MODULE_ALIAS("of:N*T*Cadi,adgs1408C*");
MODULE_ALIAS("of:N*T*Cadi,adgs1409");
MODULE_ALIAS("of:N*T*Cadi,adgs1409C*");
MODULE_ALIAS("spi:adgs1408");
MODULE_ALIAS("spi:adgs1409");

MODULE_INFO(srcversion, "097F7A4083C843EB225D6AD");
