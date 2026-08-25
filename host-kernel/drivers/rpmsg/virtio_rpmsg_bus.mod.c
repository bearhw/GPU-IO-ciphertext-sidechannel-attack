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
	{ 0x37a0cba, "kfree" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x2de84993, "virtio_reset_device" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xb16952e2, "rpmsg_unregister_device" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0x531b604e, "__virt_addr_valid" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x63c3a2a, "virtqueue_get_vring_size" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xe5a6f947, "virtqueue_add_inbuf" },
	{ 0xaa85fe5, "virtqueue_disable_cb" },
	{ 0xa46f34a4, "rpmsg_register_device_override" },
	{ 0x50b88e65, "virtio_check_driver_offered_feature" },
	{ 0x5d711499, "rpmsg_ns_register_device" },
	{ 0x78ba473a, "virtqueue_kick_prepare" },
	{ 0xe6c15b26, "virtqueue_notify" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0xe58ef434, "rpmsg_find_device" },
	{ 0x9166fada, "strncpy" },
	{ 0xe483dc39, "rpmsg_register_device" },
	{ 0x3197c4e3, "put_device" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x559c47e5, "virtqueue_get_buf" },
	{ 0x20978fb9, "idr_find" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x6b5a92b2, "virtqueue_kick" },
	{ 0x56f63035, "virtqueue_enable_cb" },
	{ 0x800473f, "__cond_resched" },
	{ 0x69acdf38, "memcpy" },
	{ 0x56c0046e, "virtqueue_add_outbuf" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x11fcc82b, "rpmsg_sendto" },
	{ 0x7edf0c62, "register_virtio_driver" },
	{ 0x92997ed8, "_printk" },
	{ 0x188e7d5c, "unregister_virtio_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "rpmsg_core,rpmsg_ns");

MODULE_ALIAS("virtio:d00000007v*");

MODULE_INFO(srcversion, "F9BB3EB98A5F45C13DCBDFC");
