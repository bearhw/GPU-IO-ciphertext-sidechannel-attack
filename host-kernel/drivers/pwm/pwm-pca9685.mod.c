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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x74e9decc, "pwmchip_remove" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0x9f46ced8, "__sw_hweight64" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xbb726018, "device_property_present" },
	{ 0xa76b4903, "pwmchip_add" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:INT3492:*");
MODULE_ALIAS("i2c:pca9685");

MODULE_INFO(srcversion, "2E7F770303D7D6ECD608B22");
