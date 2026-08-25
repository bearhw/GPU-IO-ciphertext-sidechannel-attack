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

SYMBOL_CRC(nf_conntrack_locks, 0xaf0847f0, "_gpl");
SYMBOL_CRC(nf_conntrack_expect_lock, 0x9adb7399, "_gpl");
SYMBOL_CRC(nf_conntrack_hash, 0x28eff409, "_gpl");
SYMBOL_CRC(nf_conntrack_lock, 0xdba7326b, "_gpl");
SYMBOL_CRC(nf_conntrack_htable_size, 0x8ffe7e89, "_gpl");
SYMBOL_CRC(nf_conntrack_max, 0xf38bcdf3, "_gpl");
SYMBOL_CRC(nf_ct_get_tuplepr, 0xc958e6b3, "_gpl");
SYMBOL_CRC(nf_ct_invert_tuple, 0xfe731af8, "_gpl");
SYMBOL_CRC(nf_ct_get_id, 0xd973b705, "_gpl");
SYMBOL_CRC(nf_ct_tmpl_alloc, 0x3b9dfc4b, "_gpl");
SYMBOL_CRC(nf_ct_tmpl_free, 0x7bc5c9e5, "_gpl");
SYMBOL_CRC(nf_ct_destroy, 0x3b08a8f0, "");
SYMBOL_CRC(nf_ct_delete, 0xc1bdbf4f, "_gpl");
SYMBOL_CRC(nf_conntrack_find_get, 0xaa28cd50, "_gpl");
SYMBOL_CRC(nf_conntrack_hash_check_insert, 0xbc8bf472, "_gpl");
SYMBOL_CRC(nf_ct_acct_add, 0x7ba873bf, "_gpl");
SYMBOL_CRC(__nf_conntrack_confirm, 0x9739d19f, "_gpl");
SYMBOL_CRC(nf_conntrack_tuple_taken, 0xa535c01b, "_gpl");
SYMBOL_CRC(nf_conntrack_alloc, 0x137ce6f6, "_gpl");
SYMBOL_CRC(nf_conntrack_free, 0xbbcc0a90, "_gpl");
SYMBOL_CRC(nf_conntrack_in, 0x64175a25, "_gpl");
SYMBOL_CRC(nf_conntrack_alter_reply, 0xe2e6482b, "_gpl");
SYMBOL_CRC(__nf_ct_refresh_acct, 0x73ef9dcd, "_gpl");
SYMBOL_CRC(nf_ct_kill_acct, 0xd8659912, "_gpl");
SYMBOL_CRC(nf_ct_port_tuple_to_nlattr, 0x0cdf83c8, "_gpl");
SYMBOL_CRC(nf_ct_port_nla_policy, 0xdf0aed48, "_gpl");
SYMBOL_CRC(nf_ct_port_nlattr_to_tuple, 0xafbd6cf5, "_gpl");
SYMBOL_CRC(nf_ct_port_nlattr_tuple_size, 0xd505c3e0, "_gpl");
SYMBOL_CRC(nf_ct_iterate_cleanup_net, 0xef65c4b1, "_gpl");
SYMBOL_CRC(nf_ct_iterate_destroy, 0xf126880c, "_gpl");
SYMBOL_CRC(nf_ct_alloc_hashtable, 0x289c3714, "_gpl");
SYMBOL_CRC(nf_conntrack_count, 0xe4efabed, "_gpl");
SYMBOL_CRC(nf_ct_expect_hsize, 0xc18ac88d, "_gpl");
SYMBOL_CRC(nf_ct_expect_hash, 0xec8beba6, "_gpl");
SYMBOL_CRC(nf_ct_unlink_expect_report, 0x51debcdc, "_gpl");
SYMBOL_CRC(nf_ct_remove_expect, 0x4ccad4d6, "_gpl");
SYMBOL_CRC(__nf_ct_expect_find, 0xd8895533, "_gpl");
SYMBOL_CRC(nf_ct_expect_find_get, 0xbf87fcb0, "_gpl");
SYMBOL_CRC(nf_ct_remove_expectations, 0x7457d34f, "_gpl");
SYMBOL_CRC(nf_ct_unexpect_related, 0x013a0a56, "_gpl");
SYMBOL_CRC(nf_ct_expect_alloc, 0x4eb7d7bb, "_gpl");
SYMBOL_CRC(nf_ct_expect_init, 0xf1fc41fe, "_gpl");
SYMBOL_CRC(nf_ct_expect_put, 0x4cba5ac3, "_gpl");
SYMBOL_CRC(nf_ct_expect_related_report, 0xfe29d8d1, "_gpl");
SYMBOL_CRC(nf_ct_expect_iterate_destroy, 0x76a30f0f, "_gpl");
SYMBOL_CRC(nf_ct_expect_iterate_net, 0x32ca6c6a, "_gpl");
SYMBOL_CRC(nf_ct_helper_hash, 0x693c3961, "_gpl");
SYMBOL_CRC(nf_ct_helper_hsize, 0xc40f284c, "_gpl");
SYMBOL_CRC(__nf_conntrack_helper_find, 0x8aa26d24, "_gpl");
SYMBOL_CRC(nf_conntrack_helper_try_module_get, 0xddb71190, "_gpl");
SYMBOL_CRC(nf_conntrack_helper_put, 0x415ee86c, "_gpl");
SYMBOL_CRC(nf_nat_helper_try_module_get, 0x0bc00f80, "_gpl");
SYMBOL_CRC(nf_nat_helper_put, 0x1e93b83f, "_gpl");
SYMBOL_CRC(nf_ct_helper_ext_add, 0xdd7d2188, "_gpl");
SYMBOL_CRC(__nf_ct_try_assign_helper, 0x3979a864, "_gpl");
SYMBOL_CRC(nf_ct_helper_expectfn_register, 0x19e81a0a, "_gpl");
SYMBOL_CRC(nf_ct_helper_expectfn_unregister, 0xe3c0ac72, "_gpl");
SYMBOL_CRC(nf_ct_helper_expectfn_find_by_name, 0xd7922687, "_gpl");
SYMBOL_CRC(nf_ct_helper_expectfn_find_by_symbol, 0xb637256e, "_gpl");
SYMBOL_CRC(nf_ct_helper_log, 0x81e39ae6, "_gpl");
SYMBOL_CRC(nf_conntrack_helper_register, 0x3f9abf02, "_gpl");
SYMBOL_CRC(nf_conntrack_helper_unregister, 0x924f2ced, "_gpl");
SYMBOL_CRC(nf_ct_helper_init, 0x250f5474, "_gpl");
SYMBOL_CRC(nf_conntrack_helpers_register, 0x35c98d0a, "_gpl");
SYMBOL_CRC(nf_conntrack_helpers_unregister, 0x98914c14, "_gpl");
SYMBOL_CRC(nf_nat_helper_register, 0x693d67e1, "_gpl");
SYMBOL_CRC(nf_nat_helper_unregister, 0x41267473, "_gpl");
SYMBOL_CRC(nf_ct_set_auto_assign_helper_warned, 0xb9b93c63, "_gpl");
SYMBOL_CRC(nf_l4proto_log_invalid, 0x8602f2bc, "_gpl");
SYMBOL_CRC(nf_ct_l4proto_log_invalid, 0x2bbd1711, "_gpl");
SYMBOL_CRC(nf_ct_l4proto_find, 0x2e0a33ae, "_gpl");
SYMBOL_CRC(nf_confirm, 0xf5bdc7aa, "_gpl");
SYMBOL_CRC(nf_ct_netns_get, 0x4bebc483, "_gpl");
SYMBOL_CRC(nf_ct_netns_put, 0xda86c0fa, "_gpl");
SYMBOL_CRC(nf_ct_bridge_register, 0xf3a9ffe3, "_gpl");
SYMBOL_CRC(nf_ct_bridge_unregister, 0xdaba6bed, "_gpl");
SYMBOL_CRC(nf_ct_ext_add, 0x82b6160f, "");
SYMBOL_CRC(__nf_ct_ext_find, 0x89d99ee1, "");
SYMBOL_CRC(nf_ct_seqadj_init, 0x98cd7d68, "_gpl");
SYMBOL_CRC(nf_ct_seqadj_set, 0x35215281, "_gpl");
SYMBOL_CRC(nf_ct_tcp_seqadj_set, 0x4a39f83b, "_gpl");
SYMBOL_CRC(nf_ct_seq_adjust, 0x971bd91e, "_gpl");
SYMBOL_CRC(nf_ct_seq_offset, 0xe45da9b3, "_gpl");
SYMBOL_CRC(nf_ct_timeout_hook, 0xc2ad8480, "_gpl");
SYMBOL_CRC(nf_ct_untimeout, 0x27fd6cee, "_gpl");
SYMBOL_CRC(nf_ct_set_timeout, 0x0a8c27b5, "_gpl");
SYMBOL_CRC(nf_ct_destroy_timeout, 0xcce6e49d, "_gpl");
SYMBOL_CRC(nf_conn_pernet_ecache, 0xb85bd397, "_gpl");
SYMBOL_CRC(nf_conntrack_eventmask_report, 0x1bb51d38, "_gpl");
SYMBOL_CRC(nf_ct_deliver_cached_events, 0xbaeddd05, "_gpl");
SYMBOL_CRC(nf_conntrack_register_notifier, 0x38be4902, "_gpl");
SYMBOL_CRC(nf_conntrack_unregister_notifier, 0x287598ab, "_gpl");
SYMBOL_CRC(nf_ct_ecache_ext_add, 0x86977087, "_gpl");
SYMBOL_CRC(nf_connlabels_replace, 0x6115227b, "_gpl");
SYMBOL_CRC(nf_connlabels_get, 0x8c229db9, "_gpl");
SYMBOL_CRC(nf_connlabels_put, 0x6e819985, "_gpl");
SYMBOL_CRC(nf_ct_gre_keymap_add, 0x9df39187, "_gpl");
SYMBOL_CRC(nf_ct_gre_keymap_destroy, 0x9ba74647, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbe38f709, "__do_once_done" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0xbab6e799, "nf_defrag_ipv4_disable" },
	{ 0xf6a9ff1d, "nf_ip6_checksum" },
	{ 0xfc03a4ca, "proc_dou8vec_minmax" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xdf6b082f, "proc_dointvec_jiffies" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x3fb130e, "nf_register_sockopt" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xb74b780e, "param_set_uint" },
	{ 0x3ba8a9f3, "nf_defrag_ipv4_enable" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x75ea7f7c, "nf_ct_hook" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x7f24de73, "jiffies_to_usecs" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x1000e51, "schedule" },
	{ 0x4490c46c, "nf_unregister_sockopt" },
	{ 0x18f07c94, "param_get_uint" },
	{ 0xc8827b75, "sysctl_vals" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xe00aecba, "nf_defrag_ipv6_disable" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0x29a5badd, "nf_register_net_hooks" },
	{ 0xa916b694, "strnlen" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x800473f, "__cond_resched" },
	{ 0x185d73d6, "nf_checksum" },
	{ 0x51d13875, "nf_hooks_lwtunnel_sysctl_handler" },
	{ 0x7c6024bd, "init_net" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x24d273d1, "add_timer" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x8520a781, "nla_put" },
	{ 0x3efe91aa, "nf_checksum_partial" },
	{ 0x6b76129f, "skb_ensure_writable" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0x32f28140, "nf_unregister_net_hooks" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x944375db, "_totalram_pages" },
	{ 0x86490580, "current_task" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x6d2fc5a6, "net_namespace_list" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xccfb4622, "nf_log_packet" },
	{ 0xad14ca49, "nf_ip_checksum" },
	{ 0xe4262c6, "__siphash_unaligned" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x668b19a1, "down_read" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0xba53adab, "nla_policy_len" },
	{ 0xb15b4109, "crc32c" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xe17678a, "siphash_4u64" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x8e141268, "__skb_checksum" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xa5228d6e, "inet_proto_csum_replace4" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xe766aaf7, "nf_defrag_ipv6_enable" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xa8181adf, "proc_dointvec" },
	{ 0xdebc2243, "nf_nat_hook" },
	{ 0xf44a904a, "net_ns_barrier" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x5a6cdb52, "nf_ct_zone_dflt" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xe98873fc, "nf_queue_nf_hook_drop" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x47884890, "system_power_efficient_wq" },
	{ 0x53b954a2, "up_read" },
	{ 0xe1a8d7c9, "net_rwsem" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x7d5e1008, "__crc32c_le_shift" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x18e60984, "__do_once_start" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_defrag_ipv4,nf_defrag_ipv6,libcrc32c");


MODULE_INFO(srcversion, "6DEACE40C15804FFEE7A367");
