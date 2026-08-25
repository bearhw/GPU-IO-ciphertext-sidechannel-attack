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
	{ 0x7447bbf1, "i2c_smbus_write_byte" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x96848186, "scnprintf" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x34b8e6d6, "i2c_smbus_read_byte" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0xf9a482f9, "msleep" },
	{ 0x6a6e05bf, "kstrtou8" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:blinkm");

MODULE_INFO(srcversion, "B150696FB9135A4E13A0672");
