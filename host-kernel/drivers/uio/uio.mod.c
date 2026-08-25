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

SYMBOL_CRC(uio_event_notify, 0xaa50bea4, "_gpl");
SYMBOL_CRC(__uio_register_device, 0x9061f154, "_gpl");
SYMBOL_CRC(__devm_uio_register_device, 0xa0d4f927, "_gpl");
SYMBOL_CRC(uio_unregister_device, 0xf14a7a00, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xb0285ae, "kill_fasync" },
	{ 0x37a0cba, "kfree" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x7c181721, "kobject_put" },
	{ 0xa4cdf212, "fasync_helper" },
	{ 0x1de23e95, "module_put" },
	{ 0x3197c4e3, "put_device" },
	{ 0x20978fb9, "idr_find" },
	{ 0xa40a8382, "get_device" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd6727dc4, "remap_pfn_range" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x113f6db6, "cdev_del" },
	{ 0x86490580, "current_task" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x1000e51, "schedule" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x48098f3, "device_add" },
	{ 0xeaf730c2, "kobject_create_and_add" },
	{ 0x5c000d78, "kobject_init" },
	{ 0xcfb8f52a, "kobject_add" },
	{ 0x640b4f57, "kobject_uevent" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x3312881b, "device_del" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x28de1031, "__devres_alloc_node" },
	{ 0xea900f57, "devres_add" },
	{ 0xe93e49c3, "devres_free" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xeaebae2a, "cdev_alloc" },
	{ 0x95352ea6, "kobject_set_name" },
	{ 0x8057ff4, "cdev_add" },
	{ 0xa1600c1b, "__class_register" },
	{ 0x92997ed8, "_printk" },
	{ 0x70cc876b, "class_unregister" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x13c3edaa, "generic_access_phys" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8053400DED8163E5F106571");
