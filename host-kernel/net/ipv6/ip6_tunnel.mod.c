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

SYMBOL_CRC(ip6_tnl_parse_tlv_enc_lim, 0x5ea86437, "");
SYMBOL_CRC(ip6_tnl_get_cap, 0xf7f3e0d4, "");
SYMBOL_CRC(ip6_tnl_rcv_ctl, 0x60e2b3da, "_gpl");
SYMBOL_CRC(ip6_tnl_rcv, 0x4c22046a, "");
SYMBOL_CRC(ip6_tnl_xmit_ctl, 0x55a723a8, "_gpl");
SYMBOL_CRC(ip6_tnl_xmit, 0x0e95f18f, "");
SYMBOL_CRC(ip6_tnl_change_mtu, 0xd09078f5, "");
SYMBOL_CRC(ip6_tnl_get_iflink, 0xf58a36fb, "");
SYMBOL_CRC(ip6_tnl_encap_add_ops, 0x1fdb9df2, "");
SYMBOL_CRC(ip6_tnl_encap_del_ops, 0xd4f953fc, "");
SYMBOL_CRC(ip6_tnl_encap_setup, 0xa8a93773, "_gpl");
SYMBOL_CRC(ip6_tnl_get_link_net, 0x8065e2df, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x784edf49, "ip6tun_encaps" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0x8f9a143f, "ipv6_chk_addr_and_flags" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xbf466c50, "rt6_lookup" },
	{ 0xe05b6928, "dst_release" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0x9f54ead7, "gro_cells_destroy" },
	{ 0xada38766, "dst_cache_destroy" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0xb39384b8, "ip_tunnel_header_ops" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x9fdecc31, "unregister_netdevice_many" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9cdfb3f7, "sysctl_fb_tunnels_only_for_init_net" },
	{ 0x7c6024bd, "init_net" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0xa916b694, "strnlen" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x92997ed8, "_printk" },
	{ 0x8520a781, "nla_put" },
	{ 0xaf793668, "__alloc_percpu_gfp" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xae39f80e, "dst_cache_init" },
	{ 0x4dc6467, "gro_cells_init" },
	{ 0xd37cbe97, "__get_hash_from_flowi6" },
	{ 0x2f972e53, "skb_scrub_packet" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x19abf763, "gro_cells_receive" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xc095e884, "eth_type_trans" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x452ba683, "ipv6_ext_hdr" },
	{ 0xa498108e, "register_netdevice" },
	{ 0x62849ac7, "dev_valid_name" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xa78dbafd, "netdev_state_change" },
	{ 0x5189c8ea, "__xfrm_policy_check" },
	{ 0x87ce5fd8, "__iptunnel_pull_header" },
	{ 0x672bdf0d, "metadata_dst_alloc" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x54afee, "ip6_redirect" },
	{ 0x5eaeadb, "ip6_update_pmtu" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x54188a32, "dst_cache_get" },
	{ 0x86f015e6, "ip6_route_output_flags" },
	{ 0x822e0163, "xfrm_lookup" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x20c3e4b2, "skb_realloc_headroom" },
	{ 0xc5c1e5c7, "skb_set_owner_w" },
	{ 0xbd505649, "consume_skb" },
	{ 0x8ba29cb8, "ipv6_push_frag_opts" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xa8037a64, "ip6_local_out" },
	{ 0x14990a44, "dst_cache_set_ip6" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3356bb23, "ip6_dst_hoplimit" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0xd5caefdc, "ipv6_dev_get_saddr" },
	{ 0xf5d59d1d, "neigh_destroy" },
	{ 0x61637ccc, "iptunnel_handle_offloads" },
	{ 0xc5374f44, "icmpv6_ndo_send" },
	{ 0x81663b8c, "icmp_ndo_send" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0xe7097cd2, "icmp6_send" },
	{ 0x9d8f446e, "ip_route_output_flow" },
	{ 0x2a71d705, "ip_route_input_noref" },
	{ 0x9def366f, "__icmp_send" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x437eb1df, "ipv6_mod_enabled" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0x4b19f3cc, "xfrm6_tunnel_register" },
	{ 0xf3f0a52, "rtnl_link_register" },
	{ 0x52cfd434, "xfrm6_tunnel_deregister" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0xa0455dcd, "rtnl_link_unregister" },
	{ 0x591518aa, "dev_get_tstats64" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "tunnel6");


MODULE_INFO(srcversion, "FF8736B51568958755AD89A");
