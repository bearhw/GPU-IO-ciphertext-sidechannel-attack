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
	{ 0xc4900a58, "i2c_smbus_read_byte_data" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xf0b1551a, "i2c_transfer_buffer_flags" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x941062c9, "device_set_wakeup_capable" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0x16ad1742, "devm_clk_register" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:pcf8563");
MODULE_ALIAS("i2c:rtc8564");
MODULE_ALIAS("i2c:pca8565");

MODULE_INFO(srcversion, "3932F9DB7579BB1F8F90428");
