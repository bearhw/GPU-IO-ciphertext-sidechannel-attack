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
	{ 0xf883c540, "charlcd_unregister" },
	{ 0xf3304696, "charlcd_free" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xc4900a58, "i2c_smbus_read_byte_data" },
	{ 0xf0b1551a, "i2c_transfer_buffer_flags" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7447bbf1, "i2c_smbus_write_byte" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x8b45326c, "charlcd_alloc" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0x6fd9cc4a, "charlcd_register" },
	{ 0x349cba85, "strchr" },
	{ 0xab6d5b3b, "hex_to_bin" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "charlcd");

MODULE_ALIAS("of:N*T*Cmodtronix,lcd2s");
MODULE_ALIAS("of:N*T*Cmodtronix,lcd2sC*");
MODULE_ALIAS("i2c:lcd2s");

MODULE_INFO(srcversion, "E9D918D7598952CB4256745");
