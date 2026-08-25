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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(ip_tunnel_lookup, 0xca8141df, "_gpl");
SYMBOL_CRC(ip_tunnel_rcv, 0xe3d02dfd, "_gpl");
SYMBOL_CRC(ip_tunnel_encap_add_ops, 0x526d36d0, "");
SYMBOL_CRC(ip_tunnel_encap_del_ops, 0x76e9ccb3, "");
SYMBOL_CRC(ip_tunnel_encap_setup, 0x1786fc1d, "_gpl");
SYMBOL_CRC(ip_md_tunnel_xmit, 0x79c01205, "_gpl");
SYMBOL_CRC(ip_tunnel_xmit, 0x10172333, "_gpl");
SYMBOL_CRC(ip_tunnel_ctl, 0x30d2d4a6, "_gpl");
SYMBOL_CRC(ip_tunnel_siocdevprivate, 0x6939dd10, "_gpl");
SYMBOL_CRC(__ip_tunnel_change_mtu, 0xd8366ada, "_gpl");
SYMBOL_CRC(ip_tunnel_change_mtu, 0x11a364af, "_gpl");
SYMBOL_CRC(ip_tunnel_dellink, 0x4669f865, "_gpl");
SYMBOL_CRC(ip_tunnel_get_link_net, 0x03ca98ac, "");
SYMBOL_CRC(ip_tunnel_get_iflink, 0x63599b09, "");
SYMBOL_CRC(ip_tunnel_init_net, 0xa111798b, "_gpl");
SYMBOL_CRC(ip_tunnel_delete_nets, 0xccbfba88, "_gpl");
SYMBOL_CRC(ip_tunnel_newlink, 0x7190d095, "_gpl");
SYMBOL_CRC(ip_tunnel_changelink, 0x3c55e630, "_gpl");
SYMBOL_CRC(ip_tunnel_init, 0xaa7aa0c4, "_gpl");
SYMBOL_CRC(ip_tunnel_uninit, 0x8deb7121, "_gpl");
SYMBOL_CRC(ip_tunnel_setup, 0x2b3c0769, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x647f81d7, "iptun_encaps" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0x9fdecc31, "unregister_netdevice_many" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x9f54ead7, "gro_cells_destroy" },
	{ 0xada38766, "dst_cache_destroy" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x754d539c, "strlen" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x62849ac7, "dev_valid_name" },
	{ 0xa916b694, "strnlen" },
	{ 0x69acdf38, "memcpy" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0xa498108e, "register_netdevice" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xaf793668, "__alloc_percpu_gfp" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xae39f80e, "dst_cache_init" },
	{ 0x4dc6467, "gro_cells_init" },
	{ 0x9d8f446e, "ip_route_output_flow" },
	{ 0xe05b6928, "dst_release" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0x45a696d7, "l3mdev_master_upper_ifindex_by_index_rcu" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x2f972e53, "skb_scrub_packet" },
	{ 0x19abf763, "gro_cells_receive" },
	{ 0xc095e884, "eth_type_trans" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0x92997ed8, "_printk" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xa78dbafd, "netdev_state_change" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x4ae8d076, "dev_set_mtu" },
	{ 0x9cdfb3f7, "sysctl_fb_tunnels_only_for_init_net" },
	{ 0x7c6024bd, "init_net" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0xc5374f44, "icmpv6_ndo_send" },
	{ 0x81663b8c, "icmp_ndo_send" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x85e29c15, "dst_cache_get_ip4" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0xfd381298, "__skb_get_hash" },
	{ 0x2bb9376b, "dst_cache_set_ip4" },
	{ 0x3e3005b, "iptunnel_xmit" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0xf5d59d1d, "neigh_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0403F50833A2DB3676748D5");
