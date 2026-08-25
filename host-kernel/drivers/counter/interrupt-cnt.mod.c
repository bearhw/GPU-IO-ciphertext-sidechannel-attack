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
	{ 0x6f64e05d, "counter_priv" },
	{ 0x4f2ce15d, "counter_push_event" },
	{ 0xe272a15f, "gpiod_get_value" },
	{ 0x47392d90, "devm_counter_alloc" },
	{ 0x548ad742, "platform_get_irq_optional" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0xef7859b8, "gpiod_to_irq" },
	{ 0x473786ad, "devm_kasprintf" },
	{ 0x7522f3ba, "irq_modify_status" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x4331a573, "devm_counter_add" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xfcec0987, "enable_irq" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "counter");

MODULE_ALIAS("of:N*T*Cinterrupt-counter");
MODULE_ALIAS("of:N*T*Cinterrupt-counterC*");

MODULE_INFO(srcversion, "28C0D8AA1BD7D19C2F8F1F1");
