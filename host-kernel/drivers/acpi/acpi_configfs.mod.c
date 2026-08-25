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
	{ 0xf7da6e6f, "acpi_unload_table" },
	{ 0xfbcbfb4d, "config_item_put" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x69acdf38, "memcpy" },
	{ 0x92997ed8, "_printk" },
	{ 0x91f4d6a1, "security_locked_down" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x4715a909, "acpi_load_table" },
	{ 0x37a0cba, "kfree" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe4994173, "config_item_init_type_name" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x187b64e8, "config_group_init" },
	{ 0xffb2df28, "configfs_register_subsystem" },
	{ 0x85a19712, "configfs_register_default_group" },
	{ 0xb56b87f1, "configfs_unregister_subsystem" },
	{ 0x966e0229, "configfs_unregister_default_group" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2D95D2ECB31546319DA77C2");
