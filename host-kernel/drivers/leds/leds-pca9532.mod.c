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
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x21a7b8cd, "gpiochip_remove" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0xc4900a58, "i2c_smbus_read_byte_data" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2587f789, "_dev_info" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x9d67f7e3, "devm_input_allocate_device" },
	{ 0xaddf64b0, "input_register_device" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:pca9530");
MODULE_ALIAS("i2c:pca9531");
MODULE_ALIAS("i2c:pca9532");
MODULE_ALIAS("i2c:pca9533");

MODULE_INFO(srcversion, "9520EBB176EE496489E73E6");
