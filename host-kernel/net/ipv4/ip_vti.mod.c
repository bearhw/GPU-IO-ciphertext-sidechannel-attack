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
	{ 0x3c55e630, "ip_tunnel_changelink" },
	{ 0x7190d095, "ip_tunnel_newlink" },
	{ 0xb39384b8, "ip_tunnel_header_ops" },
	{ 0x2b3c0769, "ip_tunnel_setup" },
	{ 0x30d2d4a6, "ip_tunnel_ctl" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xaa7aa0c4, "ip_tunnel_init" },
	{ 0xccbfba88, "ip_tunnel_delete_nets" },
	{ 0xa111798b, "ip_tunnel_init_net" },
	{ 0x274e8170, "__xfrm_decode_session" },
	{ 0x86f015e6, "ip6_route_output_flags" },
	{ 0xe436823b, "xfrm_lookup_route" },
	{ 0xe05b6928, "dst_release" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x2f972e53, "skb_scrub_packet" },
	{ 0x78f6cca8, "ip6_output" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x65c180fa, "ip_route_output_key_hash" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0x81663b8c, "icmp_ndo_send" },
	{ 0x61ce5c38, "ip_output" },
	{ 0xc5374f44, "icmpv6_ndo_send" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x5189c8ea, "__xfrm_policy_check" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xca8141df, "ip_tunnel_lookup" },
	{ 0xf96be110, "xfrm_state_lookup" },
	{ 0xfc32274f, "ipv4_redirect" },
	{ 0x58fcb880, "ipv4_update_pmtu" },
	{ 0x9f8178fd, "__xfrm_state_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6681fb42, "xfrm_input" },
	{ 0x92997ed8, "_printk" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0xd9e90548, "xfrm4_protocol_register" },
	{ 0xfdd81ad2, "xfrm4_tunnel_register" },
	{ 0xf3f0a52, "rtnl_link_register" },
	{ 0x52ca7990, "xfrm4_tunnel_deregister" },
	{ 0x6ac54c65, "xfrm4_protocol_deregister" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0xa0455dcd, "rtnl_link_unregister" },
	{ 0x8deb7121, "ip_tunnel_uninit" },
	{ 0x6939dd10, "ip_tunnel_siocdevprivate" },
	{ 0x11a364af, "ip_tunnel_change_mtu" },
	{ 0x591518aa, "dev_get_tstats64" },
	{ 0x63599b09, "ip_tunnel_get_iflink" },
	{ 0x4669f865, "ip_tunnel_dellink" },
	{ 0x3ca98ac, "ip_tunnel_get_link_net" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_tunnel,tunnel4");


MODULE_INFO(srcversion, "73F9E9165E9B813BB1D6EDD");
