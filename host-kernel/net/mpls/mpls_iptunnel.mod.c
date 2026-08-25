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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x93de6018, "mpls_output_possible" },
	{ 0x82a2807f, "mpls_dev_mtu" },
	{ 0xef7ef73, "mpls_pkt_too_big" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x984d7fb9, "mpls_stats_inc_outucastpkts" },
	{ 0xe589fb23, "neigh_xmit" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x4f2c7261, "__skb_warn_lro_forwarding" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa86a0de7, "nla_put_labels" },
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x7670b536, "nla_get_labels" },
	{ 0x9d6167ca, "lwtunnel_state_alloc" },
	{ 0x37a0cba, "kfree" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x822d582b, "lwtunnel_encap_add_ops" },
	{ 0x5ae74c8b, "lwtunnel_encap_del_ops" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mpls_router");


MODULE_INFO(srcversion, "94031D6E2FCD40ABAA72A69");
