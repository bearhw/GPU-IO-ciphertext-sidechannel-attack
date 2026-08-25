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
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x2587f789, "_dev_info" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0x7c9d6cd0, "devm_backlight_device_register" },
	{ 0x2121e851, "device_create_file" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:lm3639_bl");

MODULE_INFO(srcversion, "9534FCD3A85B80691C93656");
