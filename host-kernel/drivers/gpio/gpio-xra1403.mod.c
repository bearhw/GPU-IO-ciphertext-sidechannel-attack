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
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x391de184, "seq_puts" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xd3dffe8d, "gpiochip_is_requested" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0x3e2e916b, "__devm_regmap_init_spi" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xd81a408f, "__spi_register_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cexar,xra1403");
MODULE_ALIAS("of:N*T*Cexar,xra1403C*");
MODULE_ALIAS("spi:xra1403");

MODULE_INFO(srcversion, "2D7DC2BD982DE7AAD74D120");
