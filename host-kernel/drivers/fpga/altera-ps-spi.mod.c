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
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0x8b51deca, "spi_sync" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe002f50c, "gpiod_get_raw_value_cansleep" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x78041b8f, "byte_rev_table" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x762d2eea, "spi_get_device_id" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x634f7f45, "devm_fpga_mgr_register" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fpga-mgr");

MODULE_ALIAS("spi:cyclone-ps-spi");
MODULE_ALIAS("spi:fpga-passive-serial");
MODULE_ALIAS("spi:fpga-arria10-passive-serial");
MODULE_ALIAS("of:N*T*Caltr,fpga-passive-serial");
MODULE_ALIAS("of:N*T*Caltr,fpga-passive-serialC*");
MODULE_ALIAS("of:N*T*Caltr,fpga-arria10-passive-serial");
MODULE_ALIAS("of:N*T*Caltr,fpga-arria10-passive-serialC*");

MODULE_INFO(srcversion, "9422A8B0480FD25941B2D66");
