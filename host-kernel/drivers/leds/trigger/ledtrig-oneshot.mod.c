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
	{ 0xeef4283a, "led_blink_set_oneshot" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x68c9e366, "led_set_brightness_nosleep" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x37a0cba, "kfree" },
	{ 0x43744e2f, "led_set_brightness" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x843f5a0d, "led_get_default_pattern" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x57f2ad3d, "led_trigger_register" },
	{ 0xea1972a0, "led_trigger_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DA90D5E44550A5AEB23B033");
