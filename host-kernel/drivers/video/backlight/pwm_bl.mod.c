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
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xd28544d1, "pwm_apply_state" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0xf9a482f9, "msleep" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0x31ff6c25, "pwm_free" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0x2085b347, "devm_pwm_get" },
	{ 0x9e5f9556, "backlight_device_register" },
	{ 0x95d1030c, "gpiod_get_value_cansleep" },
	{ 0xe558725b, "regulator_is_enabled" },
	{ 0x7954df, "gpiod_direction_output" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x710c1aab, "pwm_request" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0CFBEBC4D40EA45B70A8A88");
