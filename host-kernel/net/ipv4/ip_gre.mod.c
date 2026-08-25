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

SYMBOL_CRC(gretap_fb_dev_create, 0x80dcc407, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x1786fc1d, "ip_tunnel_encap_setup" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa32fb801, "ether_setup" },
	{ 0x2b3c0769, "ip_tunnel_setup" },
	{ 0xaa7aa0c4, "ip_tunnel_init" },
	{ 0x9d8f446e, "ip_route_output_flow" },
	{ 0xe05b6928, "dst_release" },
	{ 0xab90ce61, "ip_mc_inc_group" },
	{ 0xccbfba88, "ip_tunnel_delete_nets" },
	{ 0xa111798b, "ip_tunnel_init_net" },
	{ 0xbb87b7e5, "inetdev_by_index" },
	{ 0xee7389a1, "__ip_mc_dec_group" },
	{ 0xffb431e3, "gre_parse_header" },
	{ 0xca8141df, "ip_tunnel_lookup" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x58fcb880, "ipv4_update_pmtu" },
	{ 0xfc32274f, "ipv4_redirect" },
	{ 0xca9a1386, "ip6_err_gen_icmpv6_unreach" },
	{ 0x87ce5fd8, "__iptunnel_pull_header" },
	{ 0x672bdf0d, "metadata_dst_alloc" },
	{ 0xe3d02dfd, "ip_tunnel_rcv" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9def366f, "__icmp_send" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xfd381298, "__skb_get_hash" },
	{ 0x3c55e630, "ip_tunnel_changelink" },
	{ 0x7190d095, "ip_tunnel_newlink" },
	{ 0x96516add, "rtnl_create_link" },
	{ 0xd8366ada, "__ip_tunnel_change_mtu" },
	{ 0x4669f865, "ip_tunnel_dellink" },
	{ 0x9fdecc31, "unregister_netdevice_many" },
	{ 0x8480ea43, "rtnl_configure_link" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x61637ccc, "iptunnel_handle_offloads" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x79c01205, "ip_md_tunnel_xmit" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0x10172333, "ip_tunnel_xmit" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x30d2d4a6, "ip_tunnel_ctl" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x8520a781, "nla_put" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x3499aa91, "___pskb_trim" },
	{ 0x92997ed8, "_printk" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0xa0ee67ce, "gre_add_protocol" },
	{ 0xf3f0a52, "rtnl_link_register" },
	{ 0xa0455dcd, "rtnl_link_unregister" },
	{ 0x577a69c3, "gre_del_protocol" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0x3ca98ac, "ip_tunnel_get_link_net" },
	{ 0x8deb7121, "ip_tunnel_uninit" },
	{ 0xe838916, "eth_mac_addr" },
	{ 0x9977539, "eth_validate_addr" },
	{ 0x11a364af, "ip_tunnel_change_mtu" },
	{ 0x591518aa, "dev_get_tstats64" },
	{ 0x63599b09, "ip_tunnel_get_iflink" },
	{ 0x6939dd10, "ip_tunnel_siocdevprivate" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_tunnel,gre");


MODULE_INFO(srcversion, "6B04B8E84B1C2179C6A0419");
