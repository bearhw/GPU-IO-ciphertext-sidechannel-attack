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
	{ 0xceb66bec, "sched_clock_cpu" },
	{ 0x5cd4833d, "vhost_init_device_iotlb" },
	{ 0x10795da2, "__put_page" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0xac69e033, "vhost_vring_ioctl" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x408042d, "tap_get_ptr_ring" },
	{ 0x9c0b8aeb, "vhost_dev_flush" },
	{ 0x4099f919, "tun_ptr_free" },
	{ 0xcda57726, "vhost_vq_access_ok" },
	{ 0xa53ff498, "vhost_dev_stop" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x840a7827, "tap_get_socket" },
	{ 0xcc4e4b3c, "iov_iter_advance" },
	{ 0x46ed28d8, "fget" },
	{ 0xb7853d06, "vhost_dev_init" },
	{ 0x766512ca, "vhost_has_work" },
	{ 0x53e74c7d, "vhost_dev_reset_owner" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x4b524cc, "iov_iter_init" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xfd4a98d7, "vhost_poll_init" },
	{ 0x4abe4dbc, "vhost_vq_init_access" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa14210ba, "vhost_poll_stop" },
	{ 0x4b813e16, "tun_get_tx_ring" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x1000e51, "schedule" },
	{ 0xdc1784ee, "vhost_exceeds_weight" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa23180e9, "vhost_poll_queue" },
	{ 0x52901809, "tun_get_socket" },
	{ 0xe35eb75d, "vhost_discard_vq_desc" },
	{ 0xa86ef8f2, "vhost_add_used_and_signal" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xd28f6a7f, "fput" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xfd2b3e45, "vhost_dev_reset_owner_prepare" },
	{ 0x65a1e247, "vhost_add_used_and_signal_n" },
	{ 0x10392876, "vhost_dev_set_owner" },
	{ 0x51811faf, "vhost_chr_write_iter" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x96c5445e, "vhost_get_vq_desc" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xbffc55c4, "vhost_chr_read_iter" },
	{ 0xdf8ef628, "vhost_log_write" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x7ded6d97, "vhost_dev_ioctl" },
	{ 0x4708008a, "misc_register" },
	{ 0xb5fc8867, "vhost_disable_notify" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x305b044c, "vhost_dev_has_owner" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x3cfcaa3, "vhost_set_backend_features" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x9324fc25, "vhost_enable_notify" },
	{ 0xe36d7bcf, "copy_page_from_iter" },
	{ 0x6d606913, "pv_ops" },
	{ 0x7e81267f, "__page_frag_cache_drain" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xd60a8eed, "vhost_log_access_ok" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xd14e23b2, "vhost_dev_cleanup" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x5e9789cb, "vhost_chr_poll" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x943b520b, "vhost_poll_start" },
	{ 0xdd69362f, "vq_meta_prefetch" },
	{ 0xe5455ac, "vhost_dev_check_owner" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xdf0f75c6, "eventfd_signal" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x6194c18d, "sockfd_lookup" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x6c3fdebe, "vhost_vq_avail_empty" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vhost,tap");


MODULE_INFO(srcversion, "43E93F58B816A1239D65B50");
