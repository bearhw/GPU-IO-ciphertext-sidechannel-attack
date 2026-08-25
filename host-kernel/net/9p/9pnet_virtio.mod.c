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
	{ 0x7edf0c62, "register_virtio_driver" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x1430723c, "p9_req_put" },
	{ 0x27fa66e1, "nr_free_buffer_pages" },
	{ 0x63799c0f, "sysfs_create_file_ns" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0xce78a385, "iov_iter_single_seg_count" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xcc4e4b3c, "iov_iter_advance" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xdca09c91, "sysfs_remove_file_ns" },
	{ 0x188e7d5c, "unregister_virtio_driver" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa014ecb9, "p9_release_pages" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x1a5cd18a, "virtqueue_add_sgs" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x2de84993, "virtio_reset_device" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x559c47e5, "virtqueue_get_buf" },
	{ 0x45ac8202, "_dev_emerg" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x6b5a92b2, "virtqueue_kick" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x16cd7ad4, "v9fs_register_trans" },
	{ 0x50b88e65, "virtio_check_driver_offered_feature" },
	{ 0x640b4f57, "kobject_uevent" },
	{ 0xbb530f97, "iov_iter_get_pages_alloc" },
	{ 0xed1b5526, "v9fs_unregister_trans" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x28ac4d9b, "p9_client_cb" },
	{ 0x754d539c, "strlen" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "9pnet");

MODULE_ALIAS("virtio:d00000009v*");

MODULE_INFO(srcversion, "5BA35E87715A6B8A3F28C51");
