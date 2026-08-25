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

SYMBOL_CRC(synproxy_net_id, 0xca9fc082, "_gpl");
SYMBOL_CRC(synproxy_parse_options, 0x6bc0a249, "_gpl");
SYMBOL_CRC(synproxy_init_timestamp_cookie, 0x1f099794, "_gpl");
SYMBOL_CRC(synproxy_send_client_synack, 0xe12d99b5, "_gpl");
SYMBOL_CRC(synproxy_recv_client_ack, 0x65eb9bd0, "_gpl");
SYMBOL_CRC(ipv4_synproxy_hook, 0x15522dbb, "_gpl");
SYMBOL_CRC(nf_synproxy_ipv4_init, 0x66e22319, "_gpl");
SYMBOL_CRC(nf_synproxy_ipv4_fini, 0x0ce386e7, "_gpl");
SYMBOL_CRC(synproxy_send_client_synack_ipv6, 0xda58ffd4, "_gpl");
SYMBOL_CRC(synproxy_recv_client_ack_ipv6, 0x0750ccab, "_gpl");
SYMBOL_CRC(ipv6_synproxy_hook, 0x12899cd3, "_gpl");
SYMBOL_CRC(nf_synproxy_ipv6_init, 0x6a118145, "_gpl");
SYMBOL_CRC(nf_synproxy_ipv6_fini, 0x001024bb, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x391de184, "seq_puts" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x29a5badd, "nf_register_net_hooks" },
	{ 0x32f28140, "nf_unregister_net_hooks" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x3b08a8f0, "nf_ct_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6b76129f, "skb_ensure_writable" },
	{ 0xa5228d6e, "inet_proto_csum_replace4" },
	{ 0x5a6cdb52, "nf_ct_zone_dflt" },
	{ 0x3b9dfc4b, "nf_ct_tmpl_alloc" },
	{ 0x82b6160f, "nf_ct_ext_add" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x6858d526, "proc_create_net_data" },
	{ 0x7bc5c9e5, "nf_ct_tmpl_free" },
	{ 0x6a1530dc, "ip_route_me_harder" },
	{ 0x8a60e5c8, "ip_local_out" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xb47cca30, "csum_ipv6_magic" },
	{ 0x2f4ab576, "security_skb_classify_flow" },
	{ 0xf49030d3, "__nf_ip6_route" },
	{ 0x822e0163, "xfrm_lookup" },
	{ 0xa8037a64, "ip6_local_out" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x71f6670b, "__cookie_v6_check" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xbe888b32, "skb_put" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0xdaf5c16e, "__cookie_v4_check" },
	{ 0x6a5e2bde, "__cookie_v6_init_sequence" },
	{ 0xe7eee3d5, "__cookie_v4_init_sequence" },
	{ 0x98cd7d68, "nf_ct_seqadj_init" },
	{ 0xbd505649, "consume_skb" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack");


MODULE_INFO(srcversion, "58F47D67ED6D3315AE1FAD6");
