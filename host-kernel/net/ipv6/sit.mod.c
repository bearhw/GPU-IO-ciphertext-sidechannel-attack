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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb39384b8, "ip_tunnel_header_ops" },
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xa78dbafd, "netdev_state_change" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xada38766, "dst_cache_destroy" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x37a0cba, "kfree" },
	{ 0xca9a1386, "ip6_err_gen_icmpv6_unreach" },
	{ 0x58fcb880, "ipv4_update_pmtu" },
	{ 0xfc32274f, "ipv4_redirect" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x9fdecc31, "unregister_netdevice_many" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x87ce5fd8, "__iptunnel_pull_header" },
	{ 0xe3d02dfd, "ip_tunnel_rcv" },
	{ 0x5189c8ea, "__xfrm_policy_check" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x9cdfb3f7, "sysctl_fb_tunnels_only_for_init_net" },
	{ 0x7c6024bd, "init_net" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0xa916b694, "strnlen" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x9d8f446e, "ip_route_output_flow" },
	{ 0xe05b6928, "dst_release" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0xaf793668, "__alloc_percpu_gfp" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xae39f80e, "dst_cache_init" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x2787fb32, "ipv6_chk_custom_prefix" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x1e69504f, "ipv6_chk_prefix" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x92997ed8, "_printk" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x61637ccc, "iptunnel_handle_offloads" },
	{ 0x10172333, "ip_tunnel_xmit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0x85e29c15, "dst_cache_get_ip4" },
	{ 0x20c3e4b2, "skb_realloc_headroom" },
	{ 0xc5c1e5c7, "skb_set_owner_w" },
	{ 0xbd505649, "consume_skb" },
	{ 0x647f81d7, "iptun_encaps" },
	{ 0x3e3005b, "iptunnel_xmit" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x2bb9376b, "dst_cache_set_ip4" },
	{ 0xf5d59d1d, "neigh_destroy" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0xc5374f44, "icmpv6_ndo_send" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xa498108e, "register_netdevice" },
	{ 0x62849ac7, "dev_valid_name" },
	{ 0x69acdf38, "memcpy" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6939dd10, "ip_tunnel_siocdevprivate" },
	{ 0xc6cbbc89, "capable" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x1786fc1d, "ip_tunnel_encap_setup" },
	{ 0xa0455dcd, "rtnl_link_unregister" },
	{ 0x52ca7990, "xfrm4_tunnel_deregister" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0xfdd81ad2, "xfrm4_tunnel_register" },
	{ 0xf3f0a52, "rtnl_link_register" },
	{ 0x591518aa, "dev_get_tstats64" },
	{ 0x63599b09, "ip_tunnel_get_iflink" },
	{ 0x3ca98ac, "ip_tunnel_get_link_net" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_tunnel,tunnel4");


MODULE_INFO(srcversion, "24EB46C6C27AB508664A264");
