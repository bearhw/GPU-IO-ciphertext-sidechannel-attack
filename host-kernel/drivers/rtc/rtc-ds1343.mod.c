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
	{ 0xc83aeea2, "dev_pm_clear_wake_irq" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x5a921311, "strncmp" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x1689b9c2, "spi_setup" },
	{ 0x3e2e916b, "__devm_regmap_init_spi" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x35ddfd66, "rtc_add_group" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0xfbad13e8, "devm_rtc_nvmem_register" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0x36be3e06, "dev_pm_set_wake_irq" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("spi:ds1343");
MODULE_ALIAS("spi:ds1344");

MODULE_INFO(srcversion, "E498EB85B6EB79A0C50EF1B");
