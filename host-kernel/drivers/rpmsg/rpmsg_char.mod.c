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

SYMBOL_CRC(rpmsg_chrdev_eptdev_destroy, 0xa4143efc, "");
SYMBOL_CRC(rpmsg_chrdev_eptdev_create, 0xb982df3f, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x1ccc39c3, "rpmsg_destroy_ept" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x67735685, "cdev_device_del" },
	{ 0x3197c4e3, "put_device" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0xa40a8382, "get_device" },
	{ 0x598e2047, "rpmsg_create_ept" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7588fbe5, "rpmsg_poll" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x75d94f40, "cdev_device_add" },
	{ 0xffb7c514, "ida_free" },
	{ 0x37a0cba, "kfree" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x1e472d9e, "rpmsg_trysendto" },
	{ 0x11fcc82b, "rpmsg_sendto" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xbe888b32, "skb_put" },
	{ 0x69acdf38, "memcpy" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x915696d8, "rpmsg_class" },
	{ 0x43f839fa, "cdev_init" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xc045240, "__register_rpmsg_driver" },
	{ 0x92997ed8, "_printk" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xcde91d2c, "unregister_rpmsg_driver" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "rpmsg_core");


MODULE_INFO(srcversion, "B489329DDAAE4737DD5C6E3");
