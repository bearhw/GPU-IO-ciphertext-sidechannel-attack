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

SYMBOL_CRC(fou_encap_hlen, 0x1757d1a4, "");
SYMBOL_CRC(gue_encap_hlen, 0xf13914b3, "");
SYMBOL_CRC(__fou_build_header, 0x2e871af2, "");
SYMBOL_CRC(__gue_build_header, 0xbd71c13e, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xf46d4b31, "inet6_offloads" },
	{ 0x69b3475e, "inet_offloads" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2ae031ab, "genlmsg_put" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xadfa871d, "udp_set_csum" },
	{ 0x61637ccc, "iptunnel_handle_offloads" },
	{ 0x7b5937c3, "inet_get_local_port_range" },
	{ 0xfd381298, "__skb_get_hash" },
	{ 0xac3201b0, "udp_flow_hashrnd" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0xbffe826a, "udp_tunnel_sock_release" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x627234d, "udp_sock_create6" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0x458fde4a, "setup_udp_tunnel_sock" },
	{ 0x70852ca3, "udp_sock_create4" },
	{ 0xbeb153c2, "inet_protos" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x45308af5, "__skb_checksum_complete" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0xe622b8c, "genl_register_family" },
	{ 0x526d36d0, "ip_tunnel_encap_add_ops" },
	{ 0x92997ed8, "_printk" },
	{ 0x76e9ccb3, "ip_tunnel_encap_del_ops" },
	{ 0x5849e6bc, "genl_unregister_family" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "udp_tunnel,ip6_udp_tunnel,ip_tunnel");


MODULE_INFO(srcversion, "0EDF1A74A2EA0DFD4E59377");
