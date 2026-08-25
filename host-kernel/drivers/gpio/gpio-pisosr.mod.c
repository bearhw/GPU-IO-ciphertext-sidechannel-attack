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
	{ 0x21a7b8cd, "gpiochip_remove" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x8b51deca, "spi_sync" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x862790c1, "gpiod_set_value_cansleep" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0xb14fc46a, "find_next_clump8" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cpisosr-gpio");
MODULE_ALIAS("of:N*T*Cpisosr-gpioC*");
MODULE_ALIAS("spi:pisosr-gpio");

MODULE_INFO(srcversion, "CDD070F99C4F5FE5CD3FCFC");
