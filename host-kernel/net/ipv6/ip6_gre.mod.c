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
	{ 0x15ba50a6, "jiffies" },
	{ 0x9f54ead7, "gro_cells_destroy" },
	{ 0xada38766, "dst_cache_destroy" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xf7f3e0d4, "ip6_tnl_get_cap" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0xbf466c50, "rt6_lookup" },
	{ 0xe05b6928, "dst_release" },
	{ 0xa32fb801, "ether_setup" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x9fdecc31, "unregister_netdevice_many" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9cdfb3f7, "sysctl_fb_tunnels_only_for_init_net" },
	{ 0x7c6024bd, "init_net" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0xa916b694, "strnlen" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xd37cbe97, "__get_hash_from_flowi6" },
	{ 0xa498108e, "register_netdevice" },
	{ 0xd09078f5, "ip6_tnl_change_mtu" },
	{ 0xa8a93773, "ip6_tnl_encap_setup" },
	{ 0xaf793668, "__alloc_percpu_gfp" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xae39f80e, "dst_cache_init" },
	{ 0x4dc6467, "gro_cells_init" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x5ea86437, "ip6_tnl_parse_tlv_enc_lim" },
	{ 0xc5374f44, "icmpv6_ndo_send" },
	{ 0xffb431e3, "gre_parse_header" },
	{ 0x54afee, "ip6_redirect" },
	{ 0x5eaeadb, "ip6_update_pmtu" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x87ce5fd8, "__iptunnel_pull_header" },
	{ 0x4c22046a, "ip6_tnl_rcv" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xe7097cd2, "icmp6_send" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x672bdf0d, "metadata_dst_alloc" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x62849ac7, "dev_valid_name" },
	{ 0x69acdf38, "memcpy" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xe95f18f, "ip6_tnl_xmit" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x61637ccc, "iptunnel_handle_offloads" },
	{ 0x81663b8c, "icmp_ndo_send" },
	{ 0x55a723a8, "ip6_tnl_xmit_ctl" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0xa78dbafd, "netdev_state_change" },
	{ 0x8520a781, "nla_put" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x3499aa91, "___pskb_trim" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x92997ed8, "_printk" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0x9f492618, "inet6_add_protocol" },
	{ 0xf3f0a52, "rtnl_link_register" },
	{ 0xa0455dcd, "rtnl_link_unregister" },
	{ 0xbef14778, "inet6_del_protocol" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0xe838916, "eth_mac_addr" },
	{ 0x9977539, "eth_validate_addr" },
	{ 0x591518aa, "dev_get_tstats64" },
	{ 0xf58a36fb, "ip6_tnl_get_iflink" },
	{ 0x8065e2df, "ip6_tnl_get_link_net" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip6_tunnel,gre");


MODULE_INFO(srcversion, "FCFCD1151D93F41C33BC9DF");
