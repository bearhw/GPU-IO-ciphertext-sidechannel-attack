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
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xc4900a58, "i2c_smbus_read_byte_data" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9c90d539, "device_get_match_data" },
	{ 0xce9da695, "device_get_child_node_count" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xf3f5b3f5, "device_get_next_child_node" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xb5a6b0cd, "fwnode_property_read_u32_array" },
	{ 0xb053cfac, "fwnode_property_read_string" },
	{ 0x6c14ab6f, "i2c_match_id" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x3dafe076, "devm_led_classdev_register_ext" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cnxp,pca9550");
MODULE_ALIAS("of:N*T*Cnxp,pca9550C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9551");
MODULE_ALIAS("of:N*T*Cnxp,pca9551C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9552");
MODULE_ALIAS("of:N*T*Cnxp,pca9552C*");
MODULE_ALIAS("of:N*T*Cibm,pca9552");
MODULE_ALIAS("of:N*T*Cibm,pca9552C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9553");
MODULE_ALIAS("of:N*T*Cnxp,pca9553C*");
MODULE_ALIAS("i2c:pca9550");
MODULE_ALIAS("i2c:pca9551");
MODULE_ALIAS("i2c:pca9552");
MODULE_ALIAS("i2c:ibm-pca9552");
MODULE_ALIAS("i2c:pca9553");

MODULE_INFO(srcversion, "347B684ED3BC868B8B502D8");
