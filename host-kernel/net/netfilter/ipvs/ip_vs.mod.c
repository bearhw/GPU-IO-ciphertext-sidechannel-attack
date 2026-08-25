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

SYMBOL_CRC(ip_vs_conn_in_get_proto, 0x6148ed9a, "_gpl");
SYMBOL_CRC(ip_vs_conn_out_get_proto, 0xda2f356b, "_gpl");
SYMBOL_CRC(register_ip_vs_scheduler, 0x5d5ae2d0, "");
SYMBOL_CRC(unregister_ip_vs_scheduler, 0x47b77462, "");
SYMBOL_CRC(ip_vs_proto_name, 0xd831a1a2, "");
SYMBOL_CRC(ip_vs_conn_new, 0x87754b55, "");
SYMBOL_CRC(ip_vs_conn_in_get, 0xde06188a, "");
SYMBOL_CRC(ip_vs_conn_out_get, 0x2d15a0ec, "");
SYMBOL_CRC(ip_vs_tcp_conn_listen, 0x455a7f67, "");
SYMBOL_CRC(ip_vs_conn_put, 0xcb299094, "");
SYMBOL_CRC(ip_vs_new_conn_out, 0x4be87808, "");
SYMBOL_CRC(ip_vs_scheduler_err, 0x1a7cf4e7, "");
SYMBOL_CRC(register_ip_vs_app, 0x38922c4e, "");
SYMBOL_CRC(unregister_ip_vs_app, 0x103245e2, "");
SYMBOL_CRC(register_ip_vs_app_inc, 0x12165d82, "");
SYMBOL_CRC(ip_vs_proto_get, 0x914ca4d7, "");
SYMBOL_CRC(ip_vs_proto_data_get, 0xc2b71dcb, "");
SYMBOL_CRC(register_ip_vs_pe, 0xb0233d02, "_gpl");
SYMBOL_CRC(unregister_ip_vs_pe, 0x2a5dc1f3, "_gpl");
SYMBOL_CRC(ip_vs_nfct_expect_related, 0xe22a0271, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x82b6160f, "nf_ct_ext_add" },
	{ 0xaa28cd50, "nf_conntrack_find_get" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xfb8944bd, "__ip_select_ident" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x7b5937c3, "inet_get_local_port_range" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0xe7097cd2, "icmp6_send" },
	{ 0x27fa66e1, "nr_free_buffer_pages" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x822e0163, "xfrm_lookup" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xdf6b082f, "proc_dointvec_jiffies" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0xbd505649, "consume_skb" },
	{ 0xa8037a64, "ip6_local_out" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0x1e0a0c24, "mod_timer_pending" },
	{ 0x61ce5c38, "ip_output" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x3fb130e, "nf_register_sockopt" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x2ae031ab, "genlmsg_put" },
	{ 0xadfa871d, "udp_set_csum" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x78f6cca8, "ip6_output" },
	{ 0xead8daf3, "ip6_route_me_harder" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x9d8f446e, "ip_route_output_flow" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xd2800691, "nf_conntrack_destroy" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x61637ccc, "iptunnel_handle_offloads" },
	{ 0xac3201b0, "udp_flow_hashrnd" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xb2d00eb2, "__dev_get_by_name" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x3b08a8f0, "nf_ct_destroy" },
	{ 0x6858d526, "proc_create_net_data" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x284faa6b, "__x86_indirect_thunk_r11" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0x4490c46c, "nf_unregister_sockopt" },
	{ 0xc8827b75, "sysctl_vals" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0x29a5badd, "nf_register_net_hooks" },
	{ 0x86f015e6, "ip6_route_output_flags" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0xe03d0da4, "ipv6_sock_mc_join" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x437eb1df, "ipv6_mod_enabled" },
	{ 0xfac8865f, "sysctl_wmem_max" },
	{ 0xb05fc310, "sysctl_rmem_max" },
	{ 0x800473f, "__cond_resched" },
	{ 0xd5caefdc, "ipv6_dev_get_saddr" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xfd381298, "__skb_get_hash" },
	{ 0x7c6024bd, "init_net" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0xc6f3b3fc, "refcount_dec_if_one" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xfe29d8d1, "nf_ct_expect_related_report" },
	{ 0xf4f14de6, "rtnl_trylock" },
	{ 0xe2e6482b, "nf_conntrack_alter_reply" },
	{ 0x6a1530dc, "ip_route_me_harder" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xa906274e, "seq_putc" },
	{ 0x8520a781, "nla_put" },
	{ 0xec2e1c8f, "proc_doulongvec_minmax" },
	{ 0x4eb7d7bb, "nf_ct_expect_alloc" },
	{ 0x6b76129f, "skb_ensure_writable" },
	{ 0x7971b0bb, "iov_iter_kvec" },
	{ 0x9ded96b7, "ip_mc_join_group" },
	{ 0x4cba5ac3, "nf_ct_expect_put" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x32f28140, "nf_unregister_net_hooks" },
	{ 0xc8b791be, "inet_select_addr" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xa67d1e7, "inet_addr_type" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x9739d19f, "__nf_conntrack_confirm" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x86490580, "current_task" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xcfacc347, "skb_checksum" },
	{ 0x1de7493b, "ip_defrag" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xf9c0b663, "strlcat" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xc1bdbf4f, "nf_ct_delete" },
	{ 0xb47cca30, "csum_ipv6_magic" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x131db64a, "system_long_wq" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xe035534c, "nf_hook_slow" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x6d606913, "pv_ops" },
	{ 0x40c7247c, "si_meminfo" },
	{ 0x5f98bdb6, "nf_hooks_needed" },
	{ 0xbaeddd05, "nf_ct_deliver_cached_events" },
	{ 0x20c3e4b2, "skb_realloc_headroom" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xec623802, "ipv6_find_hdr" },
	{ 0xb15b4109, "crc32c" },
	{ 0xdd64e639, "strscpy" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x9def366f, "__icmp_send" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x999e8297, "vfree" },
	{ 0xc5c1e5c7, "skb_set_owner_w" },
	{ 0x8e141268, "__skb_checksum" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xcf78d1e6, "sock_create_kern" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0xf1fc41fe, "nf_ct_expect_init" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x66b5d182, "sock_recvmsg" },
	{ 0x2124474, "ip_send_check" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xd322535f, "proc_create_net_single" },
	{ 0x58fcb880, "ipv4_update_pmtu" },
	{ 0xe766aaf7, "nf_defrag_ipv6_enable" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe05b6928, "dst_release" },
	{ 0x6e5c0971, "sock_release" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0xa8181adf, "proc_dointvec" },
	{ 0x391de184, "seq_puts" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x5a6cdb52, "nf_ct_zone_dflt" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x8a60e5c8, "ip_local_out" },
	{ 0x5849e6bc, "genl_unregister_family" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xdf27a4e5, "udp6_set_csum" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xe622b8c, "genl_register_family" },
	{ 0x55ad2c95, "kernel_sendmsg" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x7d5e1008, "__crc32c_le_shift" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2cdf87a1, "proc_dointvec_minmax" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack,libcrc32c,nf_defrag_ipv6");


MODULE_INFO(srcversion, "0F44E84E778BDCF6061D9FA");
