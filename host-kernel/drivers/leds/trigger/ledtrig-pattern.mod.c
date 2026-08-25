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
	{ 0x3213f038, "mutex_unlock" },
	{ 0x96848186, "scnprintf" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x24d273d1, "add_timer" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x43744e2f, "led_set_brightness" },
	{ 0x37a0cba, "kfree" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x843f5a0d, "led_get_default_pattern" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x57f2ad3d, "led_trigger_register" },
	{ 0xea1972a0, "led_trigger_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7582CFBF5591EAB9D62DD54");
