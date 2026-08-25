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
	{ 0x113f6db6, "cdev_del" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x37a0cba, "kfree" },
	{ 0x5d395602, "hsi_free_msg" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x3fd78f3b, "register_chrdev_region" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x43f839fa, "cdev_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x8057ff4, "cdev_add" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xf51950e9, "hsi_release_port" },
	{ 0xf044dd3e, "hsi_alloc_msg" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xabb5b224, "hsi_claim_port" },
	{ 0x23c70335, "hsi_async" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x92997ed8, "_printk" },
	{ 0x2b081818, "hsi_register_client_driver" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "hsi");


MODULE_INFO(srcversion, "AA2716C2CB9DAFD0A30FE4E");
