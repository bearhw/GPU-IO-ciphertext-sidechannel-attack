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
	{ 0x80ca5026, "_bin2bcd" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0x83a196d8, "regmap_register_patch" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3e2e916b, "__devm_regmap_init_spi" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:rx6110");
MODULE_ALIAS("acpi*:SECC6110:*");
MODULE_ALIAS("of:N*T*Cepson,rx6110");
MODULE_ALIAS("of:N*T*Cepson,rx6110C*");
MODULE_ALIAS("spi:rx6110");

MODULE_INFO(srcversion, "0FB822A999926046BE40156");
