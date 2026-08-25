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
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xcabcd476, "anon_inode_getfile" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x438d8df2, "iova_cache_get" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x20978fb9, "idr_find" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x941f2aaa, "eventfd_ctx_put" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0xc7061ef3, "iova_cache_put" },
	{ 0x886e3a2d, "_vdpa_register_device" },
	{ 0x90576ec4, "vmemdup_user" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0xe40f4ed3, "__vdpa_alloc_device" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x36ac17ab, "alloc_iova_fast" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x541125c9, "vdpa_mgmtdev_unregister" },
	{ 0x6d334118, "__get_user_8" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xc57c48a3, "idr_get_next" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x1de23e95, "module_put" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x8f0b781d, "iova_domain_init_rcaches" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0x800473f, "__cond_resched" },
	{ 0x8057ff4, "cdev_add" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x311c6da4, "put_iova_domain" },
	{ 0xd28f6a7f, "fput" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x69e872f9, "vhost_iotlb_itree_first" },
	{ 0x1f1f589c, "device_create" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x83be64b9, "vhost_iotlb_itree_next" },
	{ 0xf9deb0db, "vhost_iotlb_map_free" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xd67364f7, "eventfd_ctx_fdget" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0x422066d2, "device_register" },
	{ 0x5fc72f0e, "alloc_pages_exact" },
	{ 0x905cef39, "_vdpa_unregister_device" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xfb384d37, "kasprintf" },
	{ 0x668b19a1, "down_read" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0xe48d6275, "vdpa_mgmtdev_register" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xfbd87efa, "device_create_with_groups" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x999e8297, "vfree" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x4043757f, "init_iova_domain" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa24517eb, "vhost_iotlb_free" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0x56470118, "__warn_printk" },
	{ 0x885512a2, "vhost_iotlb_add_range_ctx" },
	{ 0xfa3557ac, "receive_fd" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xeb44339a, "free_pages_exact" },
	{ 0xd138c08a, "free_iova_fast" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xdf0f75c6, "eventfd_signal" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xc577832d, "vhost_iotlb_alloc" },
	{ 0x53b954a2, "up_read" },
	{ 0x43f839fa, "cdev_init" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x113f6db6, "cdev_del" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vdpa,vhost_iotlb");


MODULE_INFO(srcversion, "1BAB1986B48D46F8F93ED54");
