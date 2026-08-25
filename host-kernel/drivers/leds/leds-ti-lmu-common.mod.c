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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(ti_lmu_common_set_brightness, 0xced72aae, "");
SYMBOL_CRC(ti_lmu_common_set_ramp, 0x54a12ec4, "");
SYMBOL_CRC(ti_lmu_common_get_ramp_params, 0xe78e764f, "");
SYMBOL_CRC(ti_lmu_common_get_brt_res, 0x4d324cde, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FA6D13AEF283BF770326046");
