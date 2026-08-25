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

SYMBOL_CRC(lcd_device_register, 0x2dea249e, "");
SYMBOL_CRC(lcd_device_unregister, 0x9d1c9b2c, "");
SYMBOL_CRC(devm_lcd_device_register, 0x946aad21, "");
SYMBOL_CRC(devm_lcd_device_unregister, 0x495b7f7d, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x37a0cba, "kfree" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x867b5609, "devres_release" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb12cbacb, "fb_unregister_client" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x422066d2, "device_register" },
	{ 0x80d68d3e, "fb_register_client" },
	{ 0x3197c4e3, "put_device" },
	{ 0x28de1031, "__devres_alloc_node" },
	{ 0xea900f57, "devres_add" },
	{ 0xe93e49c3, "devres_free" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x92997ed8, "_printk" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0AE30B30748B90EA0579197");
