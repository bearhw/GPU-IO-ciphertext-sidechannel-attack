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
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x800473f, "__cond_resched" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0xfbad13e8, "devm_rtc_nvmem_register" },
	{ 0x16ad1742, "devm_clk_register" },
	{ 0xb3311354, "devm_hwmon_device_register_with_info" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cmicrocrystal,rv3032");
MODULE_ALIAS("of:N*T*Cmicrocrystal,rv3032C*");

MODULE_INFO(srcversion, "E2B41E090FF94230E0341BE");
