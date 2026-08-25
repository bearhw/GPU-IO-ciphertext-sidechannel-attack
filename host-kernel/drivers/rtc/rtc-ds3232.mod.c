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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0xb3311354, "devm_hwmon_device_register_with_info" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0xfbad13e8, "devm_rtc_nvmem_register" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x941062c9, "device_set_wakeup_capable" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0x3e2e916b, "__devm_regmap_init_spi" },
	{ 0x1689b9c2, "spi_setup" },
	{ 0x2587f789, "_dev_info" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x92997ed8, "_printk" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cdallas,ds3232");
MODULE_ALIAS("of:N*T*Cdallas,ds3232C*");
MODULE_ALIAS("i2c:ds3232");

MODULE_INFO(srcversion, "FB51BE04D66A9252F686C58");
