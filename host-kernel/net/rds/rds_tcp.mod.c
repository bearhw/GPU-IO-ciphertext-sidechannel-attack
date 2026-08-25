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
	{ 0xf7e927fa, "tcp_sock_set_keepintvl" },
	{ 0x200b2041, "in6addr_any" },
	{ 0xceb66bec, "sched_clock_cpu" },
	{ 0xfd22dd56, "rds_cong_map_updated" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0xf6c7e5a4, "tcp_sock_set_cork" },
	{ 0x6a3f1119, "rds_send_path_reset" },
	{ 0x885700bc, "tcp_read_sock" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x802d2b61, "rds_conn_path_connect_if_down" },
	{ 0x45a4781e, "rds_addr_cmp" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xcbf9630c, "rds_trans_unregister" },
	{ 0x199532d1, "rds_info_deregister_func" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xf09217f9, "tcp_sock_set_keepcnt" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x1000e51, "schedule" },
	{ 0xa467af, "rds_wq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xee56629c, "rds_conn_destroy" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x7c6024bd, "init_net" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xe707f88e, "rds_send_path_drop_acked" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0xf43e05f3, "kernel_sock_shutdown" },
	{ 0xc2dab779, "rds_info_copy" },
	{ 0x85e4e520, "rds_stats_info_copy" },
	{ 0xd8b11d13, "rds_inc_put" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x77e4f355, "rds_info_register_func" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xa67d1e7, "inet_addr_type" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x7e9f0b01, "pskb_extract" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xff6506d9, "rds_connect_path_complete" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x56d10d6b, "rds_recv_incoming" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xcf78d1e6, "sock_create_kern" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x7ef8a052, "rds_conn_create" },
	{ 0x8116093c, "rds_send_ping" },
	{ 0x36087aa4, "rds_stats" },
	{ 0x492fff02, "rds_inc_path_init" },
	{ 0x6e5c0971, "sock_release" },
	{ 0x742abe9a, "tcp_sock_set_keepidle" },
	{ 0xb2340e65, "tcp_sock_set_nodelay" },
	{ 0x717ca949, "rds_conn_path_drop" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0xbc769b5f, "ipv6_chk_addr" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x29016914, "sock_create_lite" },
	{ 0x55ad2c95, "kernel_sendmsg" },
	{ 0xafed808c, "rds_trans_register" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0xb916ab62, "sock_no_linger" },
	{ 0x2cdf87a1, "proc_dointvec_minmax" },
	{ 0x179f5405, "sock_set_keepalive" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "rds");


MODULE_INFO(srcversion, "7F9E2160FF2659A0D13B142");
