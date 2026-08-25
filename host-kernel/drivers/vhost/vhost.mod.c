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

SYMBOL_CRC(vhost_work_init, 0xa909cfc5, "_gpl");
SYMBOL_CRC(vhost_poll_init, 0xfd4a98d7, "_gpl");
SYMBOL_CRC(vhost_poll_start, 0x943b520b, "_gpl");
SYMBOL_CRC(vhost_poll_stop, 0xa14210ba, "_gpl");
SYMBOL_CRC(vhost_dev_flush, 0x9c0b8aeb, "_gpl");
SYMBOL_CRC(vhost_work_queue, 0x67908767, "_gpl");
SYMBOL_CRC(vhost_has_work, 0x766512ca, "_gpl");
SYMBOL_CRC(vhost_poll_queue, 0xa23180e9, "_gpl");
SYMBOL_CRC(vhost_vq_is_setup, 0x2bfe6d96, "_gpl");
SYMBOL_CRC(vhost_exceeds_weight, 0xdc1784ee, "_gpl");
SYMBOL_CRC(vhost_dev_init, 0xb7853d06, "_gpl");
SYMBOL_CRC(vhost_dev_check_owner, 0x0e5455ac, "_gpl");
SYMBOL_CRC(vhost_dev_has_owner, 0x305b044c, "_gpl");
SYMBOL_CRC(vhost_dev_set_owner, 0x10392876, "_gpl");
SYMBOL_CRC(vhost_dev_reset_owner_prepare, 0xfd2b3e45, "_gpl");
SYMBOL_CRC(vhost_dev_reset_owner, 0x53e74c7d, "_gpl");
SYMBOL_CRC(vhost_dev_stop, 0xa53ff498, "_gpl");
SYMBOL_CRC(vhost_dev_cleanup, 0xd14e23b2, "_gpl");
SYMBOL_CRC(vhost_chr_write_iter, 0x51811faf, "");
SYMBOL_CRC(vhost_chr_poll, 0x5e9789cb, "");
SYMBOL_CRC(vhost_chr_read_iter, 0xbffc55c4, "_gpl");
SYMBOL_CRC(vq_meta_prefetch, 0xdd69362f, "_gpl");
SYMBOL_CRC(vhost_log_access_ok, 0xd60a8eed, "_gpl");
SYMBOL_CRC(vhost_vq_access_ok, 0xcda57726, "_gpl");
SYMBOL_CRC(vhost_vring_ioctl, 0xac69e033, "_gpl");
SYMBOL_CRC(vhost_init_device_iotlb, 0x5cd4833d, "_gpl");
SYMBOL_CRC(vhost_dev_ioctl, 0x7ded6d97, "_gpl");
SYMBOL_CRC(vhost_log_write, 0xdf8ef628, "_gpl");
SYMBOL_CRC(vhost_vq_init_access, 0x4abe4dbc, "_gpl");
SYMBOL_CRC(vhost_get_vq_desc, 0x96c5445e, "_gpl");
SYMBOL_CRC(vhost_discard_vq_desc, 0xe35eb75d, "_gpl");
SYMBOL_CRC(vhost_add_used, 0x99dcc22f, "_gpl");
SYMBOL_CRC(vhost_add_used_n, 0x4016cb35, "_gpl");
SYMBOL_CRC(vhost_signal, 0xd1c05ff3, "_gpl");
SYMBOL_CRC(vhost_add_used_and_signal, 0xa86ef8f2, "_gpl");
SYMBOL_CRC(vhost_add_used_and_signal_n, 0x65a1e247, "_gpl");
SYMBOL_CRC(vhost_vq_avail_empty, 0x6c3fdebe, "_gpl");
SYMBOL_CRC(vhost_enable_notify, 0x9324fc25, "_gpl");
SYMBOL_CRC(vhost_disable_notify, 0xb5fc8867, "_gpl");
SYMBOL_CRC(vhost_new_msg, 0x69338a18, "_gpl");
SYMBOL_CRC(vhost_enqueue_msg, 0xe3d38451, "_gpl");
SYMBOL_CRC(vhost_dequeue_msg, 0x5e58c983, "_gpl");
SYMBOL_CRC(vhost_set_backend_features, 0x03cfcaa3, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x86490580, "current_task" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0xa6257a2f, "complete" },
	{ 0xf52f864, "kthread_use_mm" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xddb1cd7, "llist_reverse_order" },
	{ 0x1000e51, "schedule" },
	{ 0xc83b983b, "kthread_unuse_mm" },
	{ 0x781f2be8, "cgroup_attach_task_all" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc577832d, "vhost_iotlb_alloc" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa24517eb, "vhost_iotlb_free" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xe1eb907a, "unpin_user_pages_dirty_lock" },
	{ 0xd7f43eda, "pin_user_pages_fast" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xdf0f75c6, "eventfd_signal" },
	{ 0x6e2b016f, "mmput" },
	{ 0xa9e668b8, "__mmdrop" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc7a1840e, "llist_add_batch" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xcc4e4b3c, "iov_iter_advance" },
	{ 0x38ff875f, "vhost_iotlb_add_range" },
	{ 0x6bec0e66, "vhost_iotlb_del_range" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x37a0cba, "kfree" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0x58ab7f99, "get_task_mm" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xd67364f7, "eventfd_ctx_fdget" },
	{ 0x941f2aaa, "eventfd_ctx_put" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x69e872f9, "vhost_iotlb_itree_first" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd2bc5c46, "__get_user_nocheck_2" },
	{ 0xecdcabd2, "copy_user_generic_unrolled" },
	{ 0x1f199d24, "copy_user_generic_string" },
	{ 0x21271fd0, "copy_user_enhanced_fast_string" },
	{ 0x4b524cc, "iov_iter_init" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x65df35ca, "__put_user_nocheck_2" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xb9177197, "eventfd_fget" },
	{ 0xd28f6a7f, "fput" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x5897cdd4, "param_ops_ushort" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vhost_iotlb");


MODULE_INFO(srcversion, "661A798AA64198206DC333D");
