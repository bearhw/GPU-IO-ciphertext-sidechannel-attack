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
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xf7f3e0d4, "ip6_tnl_get_cap" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0xbf466c50, "rt6_lookup" },
	{ 0xe05b6928, "dst_release" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0xaf793668, "__alloc_percpu_gfp" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb39384b8, "ip_tunnel_header_ops" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x9fdecc31, "unregister_netdevice_many" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x9cdfb3f7, "sysctl_fb_tunnels_only_for_init_net" },
	{ 0x7c6024bd, "init_net" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0xa916b694, "strnlen" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x274e8170, "__xfrm_decode_session" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x65c180fa, "ip_route_output_key_hash" },
	{ 0xe436823b, "xfrm_lookup_route" },
	{ 0x55a723a8, "ip6_tnl_xmit_ctl" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x81663b8c, "icmp_ndo_send" },
	{ 0x86f015e6, "ip6_route_output_flags" },
	{ 0x2f972e53, "skb_scrub_packet" },
	{ 0x78f6cca8, "ip6_output" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x61ce5c38, "ip_output" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0xc5374f44, "icmpv6_ndo_send" },
	{ 0x92997ed8, "_printk" },
	{ 0x5189c8ea, "__xfrm_policy_check" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0xa498108e, "register_netdevice" },
	{ 0x62849ac7, "dev_valid_name" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xa78dbafd, "netdev_state_change" },
	{ 0xf96be110, "xfrm_state_lookup" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x5eaeadb, "ip6_update_pmtu" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x54afee, "ip6_redirect" },
	{ 0x9f8178fd, "__xfrm_state_destroy" },
	{ 0x60e2b3da, "ip6_tnl_rcv_ctl" },
	{ 0x6681fb42, "xfrm_input" },
	{ 0xfd5208fd, "xfrm6_tunnel_spi_lookup" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0x816f7600, "xfrm6_protocol_register" },
	{ 0x4b19f3cc, "xfrm6_tunnel_register" },
	{ 0xf3f0a52, "rtnl_link_register" },
	{ 0x52cfd434, "xfrm6_tunnel_deregister" },
	{ 0x1909477e, "xfrm6_protocol_deregister" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0xa0455dcd, "rtnl_link_unregister" },
	{ 0x591518aa, "dev_get_tstats64" },
	{ 0xf58a36fb, "ip6_tnl_get_iflink" },
	{ 0x8065e2df, "ip6_tnl_get_link_net" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip6_tunnel,xfrm6_tunnel,tunnel6");


MODULE_INFO(srcversion, "777E51A25305F11256CCAA4");
