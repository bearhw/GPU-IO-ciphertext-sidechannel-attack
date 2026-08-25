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
	{ 0xc1ee0772, "devm_mux_chip_alloc" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb414d0f3, "devm_mux_chip_register" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mux-core");

MODULE_ALIAS("of:N*T*Cadi,adg792a");
MODULE_ALIAS("of:N*T*Cadi,adg792aC*");
MODULE_ALIAS("of:N*T*Cadi,adg792g");
MODULE_ALIAS("of:N*T*Cadi,adg792gC*");
MODULE_ALIAS("i2c:adg792a");
MODULE_ALIAS("i2c:adg792g");

MODULE_INFO(srcversion, "390684CCF98887D434D39C4");
