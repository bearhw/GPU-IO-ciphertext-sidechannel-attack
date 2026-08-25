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
	{ 0x2392f7da, "device_remove_file" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xc4900a58, "i2c_smbus_read_byte_data" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x7a2fd204, "i2c_smbus_read_i2c_block_data" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2587f789, "_dev_info" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0x2121e851, "device_create_file" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x2df97cad, "i2c_smbus_write_i2c_block_data" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cricoh,r2025sd");
MODULE_ALIAS("of:N*T*Cricoh,r2025sdC*");
MODULE_ALIAS("of:N*T*Cricoh,r2221tl");
MODULE_ALIAS("of:N*T*Cricoh,r2221tlC*");
MODULE_ALIAS("of:N*T*Cricoh,rs5c372a");
MODULE_ALIAS("of:N*T*Cricoh,rs5c372aC*");
MODULE_ALIAS("of:N*T*Cricoh,rs5c372b");
MODULE_ALIAS("of:N*T*Cricoh,rs5c372bC*");
MODULE_ALIAS("of:N*T*Cricoh,rv5c386");
MODULE_ALIAS("of:N*T*Cricoh,rv5c386C*");
MODULE_ALIAS("of:N*T*Cricoh,rv5c387a");
MODULE_ALIAS("of:N*T*Cricoh,rv5c387aC*");
MODULE_ALIAS("i2c:r2025sd");
MODULE_ALIAS("i2c:r2221tl");
MODULE_ALIAS("i2c:rs5c372a");
MODULE_ALIAS("i2c:rs5c372b");
MODULE_ALIAS("i2c:rv5c386");
MODULE_ALIAS("i2c:rv5c387a");

MODULE_INFO(srcversion, "9A71BF7FCB07212B5AB360A");
