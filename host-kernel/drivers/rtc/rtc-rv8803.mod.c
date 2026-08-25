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
	{ 0x7a2fd204, "i2c_smbus_read_i2c_block_data" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2df97cad, "i2c_smbus_write_i2c_block_data" },
	{ 0xc4900a58, "i2c_smbus_read_byte_data" },
	{ 0xce27b7ac, "i2c_smbus_write_byte_data" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0xfbad13e8, "devm_rtc_nvmem_register" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4f2250ba, "rtc_tm_to_time64" },
	{ 0x356461c8, "rtc_time64_to_tm" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cmicrocrystal,rv8803");
MODULE_ALIAS("of:N*T*Cmicrocrystal,rv8803C*");
MODULE_ALIAS("of:N*T*Cepson,rx8803");
MODULE_ALIAS("of:N*T*Cepson,rx8803C*");
MODULE_ALIAS("of:N*T*Cepson,rx8804");
MODULE_ALIAS("of:N*T*Cepson,rx8804C*");
MODULE_ALIAS("of:N*T*Cepson,rx8900");
MODULE_ALIAS("of:N*T*Cepson,rx8900C*");
MODULE_ALIAS("i2c:rv8803");
MODULE_ALIAS("i2c:rv8804");
MODULE_ALIAS("i2c:rx8803");
MODULE_ALIAS("i2c:rx8900");

MODULE_INFO(srcversion, "71652368B919BAD214B6431");
