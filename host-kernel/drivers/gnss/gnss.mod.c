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

SYMBOL_CRC(gnss_allocate_device, 0x157f3727, "_gpl");
SYMBOL_CRC(gnss_put_device, 0xb858e9c6, "_gpl");
SYMBOL_CRC(gnss_register_device, 0x28f3d7ce, "_gpl");
SYMBOL_CRC(gnss_deregister_device, 0x16d88906, "_gpl");
SYMBOL_CRC(gnss_insert_raw, 0x30f65f59, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xf23fcb99, "__kfifo_in" },
	{ 0x67735685, "cdev_device_del" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xa40a8382, "get_device" },
	{ 0xdb760f52, "__kfifo_free" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x75d94f40, "cdev_device_add" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x57bc19d2, "down_write" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xce807a25, "up_write" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xffb7c514, "ida_free" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x4578f528, "__kfifo_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x668b19a1, "down_read" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x56470118, "__warn_printk" },
	{ 0x636a2492, "no_llseek" },
	{ 0x7ec6993, "stream_open" },
	{ 0x139f2189, "__kfifo_alloc" },
	{ 0x53b954a2, "up_read" },
	{ 0x43f839fa, "cdev_init" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0D342FC3291DD37FF7F49EB");
