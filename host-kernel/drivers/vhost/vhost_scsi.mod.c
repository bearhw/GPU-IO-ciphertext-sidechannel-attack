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
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x99dcc22f, "vhost_add_used" },
	{ 0x10795da2, "__put_page" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x22f68c44, "target_depend_item" },
	{ 0xac69e033, "vhost_vring_ioctl" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x9c0b8aeb, "vhost_dev_flush" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0x9db2f5e1, "target_execute_cmd" },
	{ 0xcda57726, "vhost_vq_access_ok" },
	{ 0xa53ff498, "vhost_dev_stop" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xd20e5487, "target_submit_tmr" },
	{ 0xcc4e4b3c, "iov_iter_advance" },
	{ 0xb7853d06, "vhost_dev_init" },
	{ 0xa695b5fc, "target_submit_prep" },
	{ 0x1cff8eab, "sbitmap_init_node" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x4b524cc, "iov_iter_init" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4abe4dbc, "vhost_vq_init_access" },
	{ 0xa909cfc5, "vhost_work_init" },
	{ 0x4af6ddf0, "kstrtou16" },
	{ 0x92997ed8, "_printk" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xdc1784ee, "vhost_exceeds_weight" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x5085599b, "target_unregister_template" },
	{ 0xa916b694, "strnlen" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x3d4912de, "target_setup_session" },
	{ 0xa86ef8f2, "vhost_add_used_and_signal" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xecdcabd2, "copy_user_generic_unrolled" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xe615e671, "target_undepend_item" },
	{ 0x67908767, "vhost_work_queue" },
	{ 0xcf62688d, "target_remove_session" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x96c5445e, "vhost_get_vq_desc" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x5a921311, "strncmp" },
	{ 0x1f199d24, "copy_user_generic_string" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x4139b7fe, "iov_iter_get_pages" },
	{ 0x334da4e, "scsi_command_size_tbl" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x7ded6d97, "vhost_dev_ioctl" },
	{ 0xd1c05ff3, "vhost_signal" },
	{ 0x4708008a, "misc_register" },
	{ 0xb5fc8867, "vhost_disable_notify" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x9324fc25, "vhost_enable_notify" },
	{ 0x21271fd0, "copy_user_enhanced_fast_string" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xd60a8eed, "vhost_log_access_ok" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xf2c36958, "target_init_cmd" },
	{ 0xd14e23b2, "vhost_dev_cleanup" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x590775d8, "core_tpg_deregister" },
	{ 0x497f6a4d, "target_queue_submission" },
	{ 0x2bfe6d96, "vhost_vq_is_setup" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xd2719129, "target_register_template" },
	{ 0x5a207c8d, "transport_generic_free_cmd" },
	{ 0xc7a1840e, "llist_add_batch" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3464c940, "core_tpg_register" },
	{ 0x754d539c, "strlen" },
	{ 0xdf0f75c6, "eventfd_signal" },
	{ 0x4ed847b6, "target_put_sess_cmd" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x403eac60, "sbitmap_get" },
	{ 0x2f7faaac, "iov_iter_npages" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vhost,target_core_mod");


MODULE_INFO(srcversion, "2751398A646203D886900C6");
