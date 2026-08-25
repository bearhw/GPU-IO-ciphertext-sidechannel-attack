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
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0xf9a482f9, "msleep" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x901c70e2, "extcon_set_state" },
	{ 0x5b1ad755, "extcon_set_property" },
	{ 0x50c903ee, "extcon_sync" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0x9c90d539, "device_get_match_data" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0xde49eaa4, "extcon_set_property_capability" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x2587f789, "_dev_info" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cti,tusb320");
MODULE_ALIAS("of:N*T*Cti,tusb320C*");
MODULE_ALIAS("of:N*T*Cti,tusb320l");
MODULE_ALIAS("of:N*T*Cti,tusb320lC*");

MODULE_INFO(srcversion, "24D6631E2E26B1B6E19C2F7");
