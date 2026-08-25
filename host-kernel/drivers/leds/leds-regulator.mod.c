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
	{ 0x28f0da3f, "devm_regulator_get_exclusive" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x53969ea0, "regulator_list_voltage" },
	{ 0x83a0236e, "regulator_set_voltage" },
	{ 0xe30d04a4, "regulator_count_voltages" },
	{ 0xe558725b, "regulator_is_enabled" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cregulator-led");
MODULE_ALIAS("of:N*T*Cregulator-ledC*");

MODULE_INFO(srcversion, "C4F2B6B4918312560474382");
