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

SYMBOL_CRC(counter_priv, 0x6f64e05d, "_gpl");
SYMBOL_CRC(counter_alloc, 0x95ffca48, "_gpl");
SYMBOL_CRC(counter_put, 0x96469bff, "_gpl");
SYMBOL_CRC(counter_add, 0x0fefced1, "_gpl");
SYMBOL_CRC(counter_unregister, 0xdbf70f88, "_gpl");
SYMBOL_CRC(devm_counter_alloc, 0x47392d90, "_gpl");
SYMBOL_CRC(devm_counter_add, 0x4331a573, "_gpl");
SYMBOL_CRC(counter_push_event, 0x4f2ce15d, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0xf23fcb99, "__kfifo_in" },
	{ 0x67735685, "cdev_device_del" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xa40a8382, "get_device" },
	{ 0xdb760f52, "__kfifo_free" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x75d94f40, "cdev_device_add" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xffb7c514, "ida_free" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x4578f528, "__kfifo_to_user" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x6a6e05bf, "kstrtou8" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x169938c1, "__sysfs_match_string" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x3b48a9d9, "nonseekable_open" },
	{ 0x473786ad, "devm_kasprintf" },
	{ 0x6d606913, "pv_ops" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x636a2492, "no_llseek" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x139f2189, "__kfifo_alloc" },
	{ 0x99f2d00a, "sysfs_emit_at" },
	{ 0x43f839fa, "cdev_init" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CF8909458738E39AB1DBAA4");
