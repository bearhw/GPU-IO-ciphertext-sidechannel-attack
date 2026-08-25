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
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0xff4e0bdf, "devm_gpiod_get" },
	{ 0x2ab20b28, "gpiod_set_consumer_name" },
	{ 0xf9a482f9, "msleep" },
	{ 0x7c9d6cd0, "devm_backlight_device_register" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x36aa99fd, "gpiod_set_value" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Ckinetic,ktd253");
MODULE_ALIAS("of:N*T*Ckinetic,ktd253C*");
MODULE_ALIAS("of:N*T*Ckinetic,ktd259");
MODULE_ALIAS("of:N*T*Ckinetic,ktd259C*");

MODULE_INFO(srcversion, "AABCB93A468623C889B8FD2");
