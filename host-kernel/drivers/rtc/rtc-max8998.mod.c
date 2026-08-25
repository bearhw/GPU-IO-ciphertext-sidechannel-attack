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
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x7f5e3430, "max8998_bulk_read" },
	{ 0xe054769a, "max8998_read_reg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x57d24212, "max8998_write_reg" },
	{ 0xf9a482f9, "msleep" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x788f5393, "max8998_bulk_write" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0xa203e539, "irq_create_mapping_affinity" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("platform:max8998-rtc");
MODULE_ALIAS("platform:lp3974-rtc");

MODULE_INFO(srcversion, "DDF1972AD8B2C1E4A318DD4");
