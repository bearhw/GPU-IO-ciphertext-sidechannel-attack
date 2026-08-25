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
	{ 0xfdea2d04, "alarm_cancel" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xdca09c91, "sysfs_remove_file_ns" },
	{ 0x37a0cba, "kfree" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xa916b694, "strnlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x9621d738, "alarm_start_relative" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xb0101402, "sysfs_notify" },
	{ 0x48012e28, "xt_check_proc_name" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x9a23ea6b, "alarm_expires_remaining" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x63799c0f, "sysfs_create_file_ns" },
	{ 0x640b4f57, "kobject_uevent" },
	{ 0xf64aaa25, "alarm_init" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x1f1f589c, "device_create" },
	{ 0x7b7451f4, "xt_register_targets" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x8b4eba64, "xt_unregister_targets" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "0AF014AF65D5634652F6BE6");
