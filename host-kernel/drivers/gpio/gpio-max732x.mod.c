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
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x7447bbf1, "i2c_smbus_write_byte" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x34b8e6d6, "i2c_smbus_read_byte" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0x3d6cf774, "devm_i2c_new_dummy_device" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:max7319");
MODULE_ALIAS("i2c:max7320");
MODULE_ALIAS("i2c:max7321");
MODULE_ALIAS("i2c:max7322");
MODULE_ALIAS("i2c:max7323");
MODULE_ALIAS("i2c:max7324");
MODULE_ALIAS("i2c:max7325");
MODULE_ALIAS("i2c:max7326");
MODULE_ALIAS("i2c:max7327");

MODULE_INFO(srcversion, "17409BD1053F22D3A8B7269");
