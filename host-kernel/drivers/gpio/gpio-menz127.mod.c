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
	{ 0xedc03953, "iounmap" },
	{ 0xeb2c8905, "mcb_release_mem" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x57690545, "mcb_request_mem" },
	{ 0xde80cd09, "ioremap" },
	{ 0x3ae3d618, "bgpio_init" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x2587f789, "_dev_info" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x56614760, "__mcb_register_driver" },
	{ 0x6987fe2d, "mcb_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mcb,gpio-generic");


MODULE_INFO(srcversion, "B6B5F3AD6C62CA8A2C8EF01");
