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

SYMBOL_CRC(stm_register_protocol, 0xd12082b3, "_gpl");
SYMBOL_CRC(stm_unregister_protocol, 0x6410ff6a, "_gpl");
SYMBOL_CRC(stm_data_write, 0x04e6a8d5, "_gpl");
SYMBOL_CRC(stm_register_device, 0x0c387b0f, "_gpl");
SYMBOL_CRC(stm_unregister_device, 0xed722ca1, "_gpl");
SYMBOL_CRC(stm_source_register_device, 0x5ee254d0, "_gpl");
SYMBOL_CRC(stm_source_unregister_device, 0xc79cb4b2, "_gpl");
SYMBOL_CRC(stm_source_write, 0x29863f97, "_gpl");
SYMBOL_CRC(to_pdrv_policy_node, 0xea717ac4, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x1a8bd555, "try_module_get" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x187b64e8, "config_group_init" },
	{ 0xd64ed259, "__memcat_p" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0x6612cb1, "vm_iomap_memory" },
	{ 0xfa55dc45, "config_item_get" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x37a0cba, "kfree" },
	{ 0xfe5d8404, "synchronize_srcu" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb56b87f1, "configfs_unregister_subsystem" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x574c2e74, "bitmap_release_region" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x9f984513, "strrchr" },
	{ 0x1de23e95, "module_put" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0x7cab996a, "init_srcu_struct" },
	{ 0xa1600c1b, "__class_register" },
	{ 0xffb2df28, "configfs_register_subsystem" },
	{ 0x48098f3, "device_add" },
	{ 0xdac4913a, "bitmap_allocate_region" },
	{ 0x3fe3b715, "__srcu_read_lock" },
	{ 0x8bc8cc11, "config_group_init_type_name" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x70cc876b, "class_unregister" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x5691349, "cleanup_srcu_struct" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0x6b0cd993, "__get_task_comm" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x352e7e70, "pm_runtime_no_callbacks" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x3b48a9d9, "nonseekable_open" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0x999e8297, "vfree" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xfbcbfb4d, "config_item_put" },
	{ 0xeb0c5cb4, "__register_chrdev" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x95352ea6, "kobject_set_name" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x5df0ab87, "device_match_name" },
	{ 0x66e38f89, "__srcu_read_unlock" },
	{ 0x636a2492, "no_llseek" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x7ce88a05, "class_find_device" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "81E0DE1EAAD2FA2356919A3");
