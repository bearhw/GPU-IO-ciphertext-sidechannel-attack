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
	{ 0x67871714, "fuse_mount_destroy" },
	{ 0x765c4cac, "fuse_dax_cancel_work" },
	{ 0xdd626ee3, "fuse_len_args" },
	{ 0x56f63035, "virtqueue_enable_cb" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xed9e1bf9, "virtqueue_is_broken" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x79bbbb16, "unregister_filesystem" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xecaf27db, "sget_fc" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0xf0b65f4c, "fs_param_is_enum" },
	{ 0x388a5624, "register_filesystem" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x68438a13, "alloc_dax" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x2d609547, "dax_direct_access" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0xb5e73116, "flush_delayed_work" },
	{ 0x92997ed8, "_printk" },
	{ 0xfad9c827, "kill_dax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x188e7d5c, "unregister_virtio_driver" },
	{ 0x44ae0eb0, "fuse_mount_remove" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xb84da3ba, "fuse_dequeue_forget" },
	{ 0x63c3a2a, "virtqueue_get_vring_size" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xe6c15b26, "virtqueue_notify" },
	{ 0x9c29a675, "fuse_dev_alloc" },
	{ 0x64f36620, "dax_flush" },
	{ 0xc84919ec, "fuse_dev_free" },
	{ 0xc4a75a39, "fuse_dev_install" },
	{ 0xa07a37f0, "memchr" },
	{ 0x5f6f1e9e, "dax_get_private" },
	{ 0xd4603273, "fuse_init_fs_context_submount" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xaa85fe5, "virtqueue_disable_cb" },
	{ 0x1a5cd18a, "virtqueue_add_sgs" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x38fa124a, "fuse_send_init" },
	{ 0x2de84993, "virtio_reset_device" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x559c47e5, "virtqueue_get_buf" },
	{ 0x56c0046e, "virtqueue_add_outbuf" },
	{ 0x6d606913, "pv_ops" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0xdd64e639, "strscpy" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x5262a817, "fuse_conn_init" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x78ba473a, "virtqueue_kick_prepare" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xf0850137, "devm_memremap_pages" },
	{ 0x946c8d11, "set_anon_super_fc" },
	{ 0xd9b85ef6, "lockref_get" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xcb3af48c, "deactivate_locked_super" },
	{ 0x39a586df, "fuse_get_unique" },
	{ 0x7242d92, "put_dax" },
	{ 0x9e4d8096, "__fs_parse" },
	{ 0xec276a21, "fuse_request_end" },
	{ 0x82b7c307, "kill_anon_super" },
	{ 0x6924f78a, "fuse_fill_super_common" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x77358855, "iomem_resource" },
	{ 0x2eb9d0dd, "fuse_conn_destroy" },
	{ 0x7d2a440f, "fuse_free_conn" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("virtio:d0000001Av*");

MODULE_INFO(srcversion, "C6E4DD129409B39E5ECA152");
