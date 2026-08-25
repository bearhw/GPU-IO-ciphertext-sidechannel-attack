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
	{ 0x1889780a, "fuse_abort_conn" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x113f6db6, "cdev_del" },
	{ 0xf0da3ff2, "fuse_dev_release" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x37a0cba, "kfree" },
	{ 0x6ead61d1, "fuse_sync_release" },
	{ 0x2908f493, "fuse_conn_put" },
	{ 0xd88027f3, "fuse_conn_get" },
	{ 0x8fd61341, "fuse_do_open" },
	{ 0x66e9d815, "fuse_direct_io" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8029bfb8, "fuse_do_ioctl" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x754d539c, "strlen" },
	{ 0x85df9b6c, "strsep" },
	{ 0x77bc13a0, "strim" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x3197c4e3, "put_device" },
	{ 0x48098f3, "device_add" },
	{ 0xeaebae2a, "cdev_alloc" },
	{ 0x8057ff4, "cdev_add" },
	{ 0x640b4f57, "kobject_uevent" },
	{ 0x3fd78f3b, "register_chrdev_region" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0xbb44cbd, "fuse_dev_fiq_ops" },
	{ 0x5262a817, "fuse_conn_init" },
	{ 0x46a0155, "fuse_dev_alloc_install" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x34e8d69, "fuse_simple_background" },
	{ 0xc84919ec, "fuse_dev_free" },
	{ 0x74c116ef, "fuse_dev_operations" },
	{ 0xb905e0f7, "__class_create" },
	{ 0x4708008a, "misc_register" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0xdbfa69c5, "fuse_file_poll" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2AEFF4C6F1A63CE76F7CCD0");
