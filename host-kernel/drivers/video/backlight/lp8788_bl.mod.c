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
	{ 0x96848186, "scnprintf" },
	{ 0x3c8f46a4, "lp8788_write_byte" },
	{ 0xd28544d1, "pwm_apply_state" },
	{ 0x2085b347, "devm_pwm_get" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9e5f9556, "backlight_device_register" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x2eee9c04, "backlight_device_unregister" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CE6D7DB4B9AA808E0B02A64");
