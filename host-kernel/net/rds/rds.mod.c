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

SYMBOL_CRC(rds_cong_map_updated, 0xfd22dd56, "_gpl");
SYMBOL_CRC(rds_conn_create, 0x7ef8a052, "_gpl");
SYMBOL_CRC(rds_conn_create_outgoing, 0x8aa3e8e6, "_gpl");
SYMBOL_CRC(rds_conn_destroy, 0xee56629c, "_gpl");
SYMBOL_CRC(rds_for_each_conn_info, 0x897a2eff, "_gpl");
SYMBOL_CRC(rds_conn_path_drop, 0x717ca949, "_gpl");
SYMBOL_CRC(rds_conn_drop, 0xa896ebcb, "_gpl");
SYMBOL_CRC(rds_conn_path_connect_if_down, 0x802d2b61, "_gpl");
SYMBOL_CRC(rds_conn_connect_if_down, 0xf8a26897, "_gpl");
SYMBOL_CRC(rds_info_register_func, 0x77e4f355, "_gpl");
SYMBOL_CRC(rds_info_deregister_func, 0x199532d1, "_gpl");
SYMBOL_CRC(rds_info_copy, 0xc2dab779, "_gpl");
SYMBOL_CRC(rds_message_addref, 0x6e30b96b, "_gpl");
SYMBOL_CRC(rds_message_put, 0x5507bfc4, "_gpl");
SYMBOL_CRC(rds_message_populate_header, 0x585f567b, "_gpl");
SYMBOL_CRC(rds_message_add_extension, 0x2b0d543c, "_gpl");
SYMBOL_CRC(rds_message_add_rdma_dest_extension, 0x582fe5cf, "_gpl");
SYMBOL_CRC(rds_message_unmapped, 0x0f859510, "_gpl");
SYMBOL_CRC(rds_inc_init, 0x695718d0, "_gpl");
SYMBOL_CRC(rds_inc_path_init, 0x492fff02, "_gpl");
SYMBOL_CRC(rds_inc_put, 0xd8b11d13, "_gpl");
SYMBOL_CRC(rds_recv_incoming, 0x56d10d6b, "_gpl");
SYMBOL_CRC(rds_send_path_reset, 0x6a3f1119, "_gpl");
SYMBOL_CRC(rds_send_xmit, 0x3ff797db, "_gpl");
SYMBOL_CRC(rds_rdma_send_complete, 0xa01ef733, "_gpl");
SYMBOL_CRC(rds_atomic_send_complete, 0x210dcb57, "_gpl");
SYMBOL_CRC(rds_send_path_drop_acked, 0xe707f88e, "_gpl");
SYMBOL_CRC(rds_send_drop_acked, 0x665bb2fc, "_gpl");
SYMBOL_CRC(rds_send_ping, 0x8116093c, "_gpl");
SYMBOL_CRC(rds_stats, 0x36087aa4, "_gpl");
SYMBOL_CRC(rds_stats_info_copy, 0x85e4e520, "_gpl");
SYMBOL_CRC(rds_wq, 0x00a467af, "_gpl");
SYMBOL_CRC(rds_connect_path_complete, 0xff6506d9, "_gpl");
SYMBOL_CRC(rds_connect_complete, 0x3cb9903a, "_gpl");
SYMBOL_CRC(rds_addr_cmp, 0x45a4781e, "_gpl");
SYMBOL_CRC(rds_trans_register, 0xafed808c, "_gpl");
SYMBOL_CRC(rds_trans_unregister, 0xcbf9630c, "_gpl");
SYMBOL_CRC(rds_page_remainder_alloc, 0x7b399e66, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd7f43eda, "pin_user_pages_fast" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x200b2041, "in6addr_any" },
	{ 0xbe38f709, "__do_once_done" },
	{ 0xceb66bec, "sched_clock_cpu" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x10795da2, "__put_page" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xd0d156e9, "__rht_bucket_nested" },
	{ 0xe1eb907a, "unpin_user_pages_dirty_lock" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xcc4e4b3c, "iov_iter_advance" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xc8814bbc, "unpin_user_pages" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x4b5acf74, "rhashtable_init" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x37583cb4, "put_cmsg" },
	{ 0xdf2ebb87, "_raw_read_unlock_irqrestore" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x6b853d06, "ns_to_kernel_old_timeval" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0x50171cd6, "sock_register" },
	{ 0xad395dd9, "mm_account_pinned_pages" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xa916b694, "strnlen" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xb1342cdb, "_raw_read_lock_irqsave" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x68764184, "proto_register" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x57bc19d2, "down_write" },
	{ 0x7c6024bd, "init_net" },
	{ 0xce807a25, "up_write" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x5efde8e6, "proc_doulongvec_ms_jiffies_minmax" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xc3aaf0a9, "__put_user_1" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x715a5ed0, "vprintk" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x9166fada, "strncpy" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x58b8f9f7, "sock_recv_errqueue" },
	{ 0x459e6151, "mm_unaccount_pinned_pages" },
	{ 0x4139b7fe, "iov_iter_get_pages" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x58750f05, "copy_page_to_iter" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0xb202f0d7, "rht_bucket_nested_insert" },
	{ 0x380e6678, "unpin_user_page" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0xece784c2, "rb_first" },
	{ 0x2a5ea9ef, "rhashtable_destroy" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xeb078aee, "_raw_write_unlock_irqrestore" },
	{ 0x668b19a1, "down_read" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xe36d7bcf, "copy_page_from_iter" },
	{ 0x6d606913, "pv_ops" },
	{ 0xe0313d71, "rhashtable_insert_slow" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x49e60abf, "sock_i_ino" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x167e7f9d, "__get_user_1" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xa8181adf, "proc_dointvec" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x5021bd81, "_raw_write_lock_irqsave" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xb7f990e9, "rht_bucket_nested" },
	{ 0x53b954a2, "up_read" },
	{ 0xcc5d22d9, "can_do_mlock" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x2f7faaac, "iov_iter_npages" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x18e60984, "__do_once_start" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "4AD8F7C2D8F5A013C01A9B0");
