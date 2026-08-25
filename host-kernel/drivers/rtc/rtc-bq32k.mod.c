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
	{ 0xf0b1551a, "i2c_transfer_buffer_flags" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x2587f789, "_dev_info" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xbfcb6f92, "devm_rtc_device_register" },
	{ 0x2121e851, "device_create_file" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cti,bq32000");
MODULE_ALIAS("of:N*T*Cti,bq32000C*");
MODULE_ALIAS("i2c:bq32000");

MODULE_INFO(srcversion, "AFCC4467124DFF310849423");
