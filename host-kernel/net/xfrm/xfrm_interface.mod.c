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
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0xaf793668, "__alloc_percpu_gfp" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x4dc6467, "gro_cells_init" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8520a781, "nla_put" },
	{ 0x9c7ed5f4, "unregister_netdevice_queue" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0xa78dbafd, "netdev_state_change" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x9f54ead7, "gro_cells_destroy" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x9fdecc31, "unregister_netdevice_many" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x52ca7990, "xfrm4_tunnel_deregister" },
	{ 0x6ac54c65, "xfrm4_protocol_deregister" },
	{ 0x6681fb42, "xfrm_input" },
	{ 0x52cfd434, "xfrm6_tunnel_deregister" },
	{ 0x1909477e, "xfrm6_protocol_deregister" },
	{ 0xfd5208fd, "xfrm6_tunnel_spi_lookup" },
	{ 0x6b28c90b, "xfrm6_rcv_spi" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd2800691, "nf_conntrack_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xce1ac14a, "__skb_ext_del" },
	{ 0xe05b6928, "dst_release" },
	{ 0x274e8170, "__xfrm_decode_session" },
	{ 0x25304997, "xfrm_lookup_with_ifid" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0x653ab71e, "skb_gso_validate_network_len" },
	{ 0x78f6cca8, "ip6_output" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x65c180fa, "ip_route_output_key_hash" },
	{ 0x86f015e6, "ip6_route_output_flags" },
	{ 0x81663b8c, "icmp_ndo_send" },
	{ 0xc5374f44, "icmpv6_ndo_send" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x61ce5c38, "ip_output" },
	{ 0x92997ed8, "_printk" },
	{ 0x5189c8ea, "__xfrm_policy_check" },
	{ 0x9f8178fd, "__xfrm_state_destroy" },
	{ 0xb39384b8, "ip_tunnel_header_ops" },
	{ 0xf96be110, "xfrm_state_lookup" },
	{ 0xfc32274f, "ipv4_redirect" },
	{ 0x58fcb880, "ipv4_update_pmtu" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x5eaeadb, "ip6_update_pmtu" },
	{ 0x54afee, "ip6_redirect" },
	{ 0xa498108e, "register_netdevice" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0xd9e90548, "xfrm4_protocol_register" },
	{ 0xfdd81ad2, "xfrm4_tunnel_register" },
	{ 0x816f7600, "xfrm6_protocol_register" },
	{ 0x4b19f3cc, "xfrm6_tunnel_register" },
	{ 0xf3f0a52, "rtnl_link_register" },
	{ 0x10f994da, "xfrm_if_register_cb" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0x582b6275, "xfrm_if_unregister_cb" },
	{ 0xa0455dcd, "rtnl_link_unregister" },
	{ 0x5c5fc4c, "xfrm4_rcv" },
	{ 0x32050f48, "xfrm6_rcv" },
	{ 0x591518aa, "dev_get_tstats64" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "tunnel4,tunnel6,xfrm6_tunnel");


MODULE_INFO(srcversion, "1C7F84EF5F072DA06E76142");
