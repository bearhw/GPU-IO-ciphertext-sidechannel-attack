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
	{ 0xbcab6ee6, "sscanf" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe582fa0e, "gpio_to_desc" },
	{ 0xe002f50c, "gpiod_get_raw_value_cansleep" },
	{ 0x68c9e366, "led_set_brightness_nosleep" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0xef7859b8, "gpiod_to_irq" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x57f2ad3d, "led_trigger_register" },
	{ 0xea1972a0, "led_trigger_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8ED3BFCF6A6536461F2B76A");
