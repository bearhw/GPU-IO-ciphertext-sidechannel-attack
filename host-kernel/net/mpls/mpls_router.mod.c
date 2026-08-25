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

SYMBOL_CRC(mpls_output_possible, 0x93de6018, "_gpl");
SYMBOL_CRC(mpls_dev_mtu, 0x82a2807f, "_gpl");
SYMBOL_CRC(mpls_pkt_too_big, 0x0ef7ef73, "_gpl");
SYMBOL_CRC(mpls_stats_inc_outucastpkts, 0x984d7fb9, "_gpl");
SYMBOL_CRC(nla_put_labels, 0xa86a0de7, "_gpl");
SYMBOL_CRC(nla_get_labels, 0x7670b536, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x526d36d0, "ip_tunnel_encap_add_ops" },
	{ 0x73f0decb, "netlink_strict_get_check" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x653ab71e, "skb_gso_validate_network_len" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xbd505649, "consume_skb" },
	{ 0x32f9ade2, "dev_add_pack" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xad115d2, "nla_reserve" },
	{ 0x579e0bf5, "rtnl_unregister_all" },
	{ 0xe589fb23, "neigh_xmit" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x9d8f446e, "ip_route_output_flow" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xc8827b75, "sysctl_vals" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc98f4f7e, "rtnl_af_register" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xd8a6c1d8, "rtnl_set_sk_err" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2938cd80, "rtnl_unicast" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0xa8d4fe3e, "nla_reserve_64bit" },
	{ 0xd6ac372b, "ip_valid_fib_dump_req" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0xe35d19bb, "ipv6_stub" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xbf1b6ce, "nla_reserve_nohdr" },
	{ 0xa4aaf754, "rtnl_af_unregister" },
	{ 0x33ece49c, "dev_remove_pack" },
	{ 0x7980ce43, "dev_get_by_index" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x8520a781, "nla_put" },
	{ 0xcd279169, "nla_find" },
	{ 0x4f2c7261, "__skb_warn_lro_forwarding" },
	{ 0x9366c653, "rtnl_register_module" },
	{ 0x76e9ccb3, "ip_tunnel_encap_del_ops" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x31dd3bbc, "rtnl_notify" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xe05b6928, "dst_release" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0xa8181adf, "proc_dointvec" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x6264afe0, "dev_get_flags" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2cdf87a1, "proc_dointvec_minmax" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_tunnel");


MODULE_INFO(srcversion, "FAAC5AE5F28329FAFC1925B");
