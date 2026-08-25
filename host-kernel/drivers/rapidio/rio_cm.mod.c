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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x37a0cba, "kfree" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x20978fb9, "idr_find" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x92818dc5, "rio_request_outb_mbox" },
	{ 0x68eb1f9c, "rio_request_inb_mbox" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x2e897a83, "rio_release_inb_mbox" },
	{ 0xdc171761, "rio_release_outb_mbox" },
	{ 0x92997ed8, "_printk" },
	{ 0xc57c48a3, "idr_get_next" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x954f099c, "idr_preload" },
	{ 0x91f44510, "idr_alloc_cyclic" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0x668b19a1, "down_read" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x53b954a2, "up_read" },
	{ 0x8f9c199c, "__get_user_2" },
	{ 0x5a4896a8, "__put_user_2" },
	{ 0x21ef374c, "try_wait_for_completion" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x86490580, "current_task" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xb905e0f7, "__class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xd9a9d63d, "class_interface_register" },
	{ 0x1f967bf8, "subsys_interface_register" },
	{ 0x3517383e, "register_reboot_notifier" },
	{ 0x43f839fa, "cdev_init" },
	{ 0x8057ff4, "cdev_add" },
	{ 0x1f1f589c, "device_create" },
	{ 0x113f6db6, "cdev_del" },
	{ 0xac1a55be, "unregister_reboot_notifier" },
	{ 0xd93e9025, "subsys_interface_unregister" },
	{ 0x90c9f554, "class_interface_unregister" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xe069a23d, "rio_mport_class" },
	{ 0xe207aaf7, "rio_bus_type" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "022962BEF13599E9148A415");
