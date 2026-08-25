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
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0xf0b1551a, "i2c_transfer_buffer_flags" },
	{ 0xf9a482f9, "msleep" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0x2121e851, "device_create_file" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cxircom,x1205");
MODULE_ALIAS("of:N*T*Cxircom,x1205C*");
MODULE_ALIAS("i2c:x1205");

MODULE_INFO(srcversion, "EFEB5FD6BA3A18EF728DA33");
