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
	{ 0xf0b1551a, "i2c_transfer_buffer_flags" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x5838f6c9, "rtc_valid_tm" },
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x2587f789, "_dev_info" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0xbb726018, "device_property_present" },
	{ 0x35ddfd66, "rtc_add_group" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0xe4933139, "dev_fwnode" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0xfbad13e8, "devm_rtc_nvmem_register" },
	{ 0xd1f96cc2, "devm_watchdog_register_device" },
	{ 0xf9a482f9, "msleep" },
	{ 0x3e2e916b, "__devm_regmap_init_spi" },
	{ 0x762d2eea, "spi_get_device_id" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbca2be76, "__devm_regmap_init" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x92997ed8, "_printk" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("spi:pcf2127");
MODULE_ALIAS("spi:pcf2129");
MODULE_ALIAS("spi:pca2129");
MODULE_ALIAS("i2c:pcf2127");
MODULE_ALIAS("i2c:pcf2129");
MODULE_ALIAS("i2c:pca2129");

MODULE_INFO(srcversion, "C602E4D255D0D9D9206FC5A");
