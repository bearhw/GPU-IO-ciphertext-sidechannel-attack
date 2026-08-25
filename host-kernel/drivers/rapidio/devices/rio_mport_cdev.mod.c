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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x37a0cba, "kfree" },
	{ 0xccc178aa, "rio_unmap_inb_region" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xa22a900c, "rio_unmap_outb_region" },
	{ 0xa4cdf212, "fasync_helper" },
	{ 0xe1dccca2, "rio_mport_send_doorbell" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x800473f, "__cond_resched" },
	{ 0x4578f528, "__kfifo_to_user" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x469b212, "__rio_local_write_config_32" },
	{ 0x3761b0f5, "rio_mport_write_config_32" },
	{ 0x999e8297, "vfree" },
	{ 0x54c3fdd0, "__rio_local_read_config_32" },
	{ 0x5a3a4a00, "rio_mport_read_config_32" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xa40a8382, "get_device" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x139f2189, "__kfifo_alloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x3197c4e3, "put_device" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x43f839fa, "cdev_init" },
	{ 0x75d94f40, "cdev_device_add" },
	{ 0x2469c42, "rio_query_mport" },
	{ 0x81653635, "rio_release_dma" },
	{ 0x9ba423ba, "rio_del_mport_pw_handler" },
	{ 0x67735685, "cdev_device_del" },
	{ 0xb0285ae, "kill_fasync" },
	{ 0x2ca9a7ee, "rio_release_inb_dbell" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x6612cb1, "vm_iomap_memory" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0xae5917ce, "dma_mmap_attrs" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0xc8814bbc, "unpin_user_pages" },
	{ 0xa6257a2f, "complete" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xf23fcb99, "__kfifo_in" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xdb760f52, "__kfifo_free" },
	{ 0x86490580, "current_task" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x40a6f781, "rio_local_set_device_id" },
	{ 0x5df0ab87, "device_match_name" },
	{ 0xe207aaf7, "rio_bus_type" },
	{ 0x84909a73, "bus_find_device" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa916b694, "strnlen" },
	{ 0x53cf016d, "rio_attach_device" },
	{ 0xa1357083, "rio_add_device" },
	{ 0x2c28258e, "rio_dev_get" },
	{ 0x7cc6571d, "rio_request_inb_dbell" },
	{ 0xd7f43eda, "pin_user_pages_fast" },
	{ 0x558e68f5, "sg_alloc_table_from_pages_segment" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x9e77a6b9, "rio_dma_prep_xfer" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4854e1ea, "rio_request_mport_dma" },
	{ 0x754d539c, "strlen" },
	{ 0x45042af4, "rio_get_comptag" },
	{ 0x3a246057, "rio_dev_put" },
	{ 0xc355db22, "rio_del_device" },
	{ 0x40fb0b61, "rio_free_net" },
	{ 0x4e50474b, "rio_map_outb_region" },
	{ 0x3a2f6702, "sg_alloc_table" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x3803f560, "rio_map_inb_region" },
	{ 0xd3824161, "rio_pw_enable" },
	{ 0x1dc88e62, "rio_add_mport_pw_handler" },
	{ 0x759de4e1, "rio_alloc_net" },
	{ 0x355f024, "rio_add_net" },
	{ 0x8767ad79, "rio_mport_get_physefb" },
	{ 0x580df5ba, "rio_mport_get_feature" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xb905e0f7, "__class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xd9a9d63d, "class_interface_register" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x90c9f554, "class_interface_unregister" },
	{ 0xe069a23d, "rio_mport_class" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1EC5D3194FE84FFC3750E50");
