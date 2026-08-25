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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0x113f6db6, "cdev_del" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xe268024a, "most_start_channel" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x43f839fa, "cdev_init" },
	{ 0x8057ff4, "cdev_add" },
	{ 0x139f2189, "__kfifo_alloc" },
	{ 0x37a0cba, "kfree" },
	{ 0xffb7c514, "ida_free" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x1f1f589c, "device_create" },
	{ 0x640b4f57, "kobject_uevent" },
	{ 0xdb760f52, "__kfifo_free" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xff782251, "channel_has_mbo" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x4e66de1e, "most_put_mbo" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x624e5609, "most_get_mbo" },
	{ 0xf23fcb99, "__kfifo_in" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x693294db, "most_submit_mbo" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x13d0adf7, "__kfifo_out" },
	{ 0x796322e0, "most_stop_channel" },
	{ 0xb905e0f7, "__class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x48cfb9b7, "most_register_component" },
	{ 0x5bbab859, "most_register_configfs_subsys" },
	{ 0xcbd95f6c, "most_deregister_component" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x46bfdd77, "most_deregister_configfs_subsys" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "most_core");


MODULE_INFO(srcversion, "8C2E02E6EF512BAE1A485AC");
