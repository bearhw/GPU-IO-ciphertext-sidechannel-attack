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
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xc4900a58, "i2c_smbus_read_byte_data" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x7c9d6cd0, "devm_backlight_device_register" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x2587f789, "_dev_info" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:adp8860");
MODULE_ALIAS("i2c:adp8861");
MODULE_ALIAS("i2c:adp8863");

MODULE_INFO(srcversion, "F7B477ACA26E14BBC74AEB3");
