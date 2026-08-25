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
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5f4e5249, "vhost_iotlb_reset" },
	{ 0xac69e033, "vhost_vring_ioctl" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x941f2aaa, "eventfd_ctx_put" },
	{ 0xa6257a2f, "complete" },
	{ 0x67735685, "cdev_device_del" },
	{ 0xa53ff498, "vhost_dev_stop" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4940ba3b, "__mmap_lock_do_trace_acquire_returned" },
	{ 0xb7853d06, "vhost_dev_init" },
	{ 0xbd3718be, "device_initialize" },
	{ 0xc8814bbc, "unpin_user_pages" },
	{ 0x90576ec4, "vmemdup_user" },
	{ 0xd6727dc4, "remap_pfn_range" },
	{ 0x37a0cba, "kfree" },
	{ 0xc23532a7, "vdpa_unregister_driver" },
	{ 0x704ea0a4, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x6bec0e66, "vhost_iotlb_del_range" },
	{ 0x3b9642a2, "__tracepoint_mmap_lock_released" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfc70d89, "pin_user_pages" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x75d94f40, "cdev_device_add" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x3197c4e3, "put_device" },
	{ 0x2587f789, "_dev_info" },
	{ 0xfd98a590, "find_vma" },
	{ 0x732207b7, "vdpa_get_config" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x8a7d8ee9, "vhost_iotlb_init" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0x538508, "iommu_detach_device" },
	{ 0x24276ec4, "iommu_capable" },
	{ 0xf727c217, "vdpa_set_config" },
	{ 0xd28f6a7f, "fput" },
	{ 0x57bc19d2, "down_write" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x96c18eb5, "iommu_domain_free" },
	{ 0xce807a25, "up_write" },
	{ 0x69e872f9, "vhost_iotlb_itree_first" },
	{ 0x5da598f7, "iommu_domain_alloc" },
	{ 0xe7a6f7ec, "iommu_unmap" },
	{ 0x51811faf, "vhost_chr_write_iter" },
	{ 0x418873cc, "irq_bypass_register_producer" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xffb7c514, "ida_free" },
	{ 0xf9deb0db, "vhost_iotlb_map_free" },
	{ 0xd67364f7, "eventfd_ctx_fdget" },
	{ 0x86490580, "current_task" },
	{ 0x37cee29e, "__vdpa_register_driver" },
	{ 0x7ded6d97, "vhost_dev_ioctl" },
	{ 0x380e6678, "unpin_user_page" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3cfcaa3, "vhost_set_backend_features" },
	{ 0x668b19a1, "down_read" },
	{ 0x24f14039, "__mmap_lock_do_trace_start_locking" },
	{ 0xf6e772c3, "irq_bypass_unregister_producer" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xd14e23b2, "vhost_dev_cleanup" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x1f9907f7, "__tracepoint_mmap_lock_start_locking" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x56470118, "__warn_printk" },
	{ 0x1f06be15, "__mmap_lock_do_trace_released" },
	{ 0x885512a2, "vhost_iotlb_add_range_ctx" },
	{ 0x943ea161, "set_page_dirty_lock" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x6f0adf68, "iommu_map" },
	{ 0xe5455ac, "vhost_dev_check_owner" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xdf0f75c6, "eventfd_signal" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x53b954a2, "up_read" },
	{ 0xfcca10d4, "iommu_attach_device" },
	{ 0x43f839fa, "cdev_init" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x38ed7cee, "vdpa_set_status" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vhost_iotlb,vhost,vdpa");


MODULE_INFO(srcversion, "E72E7FE2853BDA0C74C3869");
