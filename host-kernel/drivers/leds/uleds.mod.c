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
	{ 0x37a0cba, "kfree" },
	{ 0x3f50fb39, "devm_led_classdev_unregister" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x349cba85, "strchr" },
	{ 0x3dafe076, "devm_led_classdev_register_ext" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x7ec6993, "stream_open" },
	{ 0x4708008a, "misc_register" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x636a2492, "no_llseek" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "37C11695E96DE0EAE97612A");
