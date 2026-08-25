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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x534fa9b, "extcon_set_state_sync" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xce2840e7, "irq_set_irq_wake" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2587f789, "_dev_info" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x47ed0b3f, "devm_extcon_dev_allocate" },
	{ 0x4a1c672c, "devm_extcon_dev_register" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0x2e1a1b74, "regmap_write" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cfcs,fsa9480");
MODULE_ALIAS("of:N*T*Cfcs,fsa9480C*");
MODULE_ALIAS("of:N*T*Cfcs,fsa880");
MODULE_ALIAS("of:N*T*Cfcs,fsa880C*");
MODULE_ALIAS("of:N*T*Cti,tsu6111");
MODULE_ALIAS("of:N*T*Cti,tsu6111C*");
MODULE_ALIAS("i2c:fsa9480");

MODULE_INFO(srcversion, "E16B850CB86D47BA0960923");
