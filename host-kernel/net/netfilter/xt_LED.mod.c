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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xea1972a0, "led_trigger_unregister" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x37a0cba, "kfree" },
	{ 0xc97ba611, "led_trigger_event" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x81392f96, "led_trigger_blink_oneshot" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x57f2ad3d, "led_trigger_register" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x67a704bf, "xt_register_target" },
	{ 0xa5d0ece2, "xt_unregister_target" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "6053A24C4AE0734123C1C0B");
