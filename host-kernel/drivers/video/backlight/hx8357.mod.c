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
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x1689b9c2, "spi_setup" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x8b51deca, "spi_sync" },
	{ 0x37a0cba, "kfree" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xf9a482f9, "msleep" },
	{ 0xe582fa0e, "gpio_to_desc" },
	{ 0x3187290a, "gpiod_set_raw_value_cansleep" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Chimax,hx8357");
MODULE_ALIAS("of:N*T*Chimax,hx8357C*");
MODULE_ALIAS("of:N*T*Chimax,hx8369");
MODULE_ALIAS("of:N*T*Chimax,hx8369C*");

MODULE_INFO(srcversion, "729E741A519B4DE4356FD11");
