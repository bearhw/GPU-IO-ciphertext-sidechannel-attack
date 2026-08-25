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

SYMBOL_CRC(nf_ct_nat_ext_add, 0xebef499b, "_gpl");
SYMBOL_CRC(nf_nat_setup_info, 0x918169e8, "");
SYMBOL_CRC(nf_nat_alloc_null_binding, 0x73b781fc, "_gpl");
SYMBOL_CRC(nf_nat_packet, 0x574404da, "_gpl");
SYMBOL_CRC(nf_nat_inet_fn, 0xe9947b1e, "_gpl");
SYMBOL_CRC(nf_nat_icmp_reply_translation, 0x3342eae6, "_gpl");
SYMBOL_CRC(nf_nat_ipv4_register_fn, 0xa8c553cb, "_gpl");
SYMBOL_CRC(nf_nat_ipv4_unregister_fn, 0xbb64dc4a, "_gpl");
SYMBOL_CRC(nf_nat_icmpv6_reply_translation, 0x9a620884, "_gpl");
SYMBOL_CRC(nf_nat_ipv6_register_fn, 0x7f5dc2cf, "_gpl");
SYMBOL_CRC(nf_nat_ipv6_unregister_fn, 0x58006d04, "_gpl");
SYMBOL_CRC(nf_nat_inet_register_fn, 0x0bfb178e, "_gpl");
SYMBOL_CRC(nf_nat_inet_unregister_fn, 0x47db41bd, "_gpl");
SYMBOL_CRC(__nf_nat_mangle_tcp_packet, 0x500685b4, "");
SYMBOL_CRC(nf_nat_mangle_udp_packet, 0x549632a0, "");
SYMBOL_CRC(nf_nat_follow_master, 0xe052320e, "");
SYMBOL_CRC(nf_nat_redirect_ipv4, 0xcaf3db26, "_gpl");
SYMBOL_CRC(nf_nat_redirect_ipv6, 0x5ed6a51f, "_gpl");
SYMBOL_CRC(nf_nat_masquerade_ipv4, 0x270e9014, "_gpl");
SYMBOL_CRC(nf_nat_masquerade_ipv6, 0xcdd3e126, "_gpl");
SYMBOL_CRC(nf_nat_masquerade_inet_register_notifiers, 0x3bc17c49, "_gpl");
SYMBOL_CRC(nf_nat_masquerade_inet_unregister_notifiers, 0xd9c25654, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x82b6160f, "nf_ct_ext_add" },
	{ 0xbe38f709, "__do_once_done" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xf6a9ff1d, "nf_ip6_checksum" },
	{ 0x4245ad91, "nf_hook_entries_insert_raw" },
	{ 0x822e0163, "xfrm_lookup" },
	{ 0x35215281, "nf_ct_seqadj_set" },
	{ 0xbe888b32, "skb_put" },
	{ 0xb0e602eb, "memmove" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xe3c0ac72, "nf_ct_helper_expectfn_unregister" },
	{ 0x274e8170, "__xfrm_decode_session" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x19e81a0a, "nf_ct_helper_expectfn_register" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xead8daf3, "ip6_route_me_harder" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0xa535c01b, "nf_conntrack_tuple_taken" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xef65c4b1, "nf_ct_iterate_cleanup_net" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0x29a5badd, "nf_register_net_hooks" },
	{ 0xfe029963, "unregister_inetaddr_notifier" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd5caefdc, "ipv6_dev_get_saddr" },
	{ 0x8ffe7e89, "nf_conntrack_htable_size" },
	{ 0xe2e6482b, "nf_conntrack_alter_reply" },
	{ 0x6a1530dc, "ip_route_me_harder" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x31d32941, "nf_hook_entries_delete_raw" },
	{ 0x6b76129f, "skb_ensure_writable" },
	{ 0x32f28140, "nf_unregister_net_hooks" },
	{ 0xc8b791be, "inet_select_addr" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xfe731af8, "nf_ct_invert_tuple" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xcfacc347, "skb_checksum" },
	{ 0x2fe252cc, "unregister_inet6addr_notifier" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0xb47cca30, "csum_ipv6_magic" },
	{ 0xad14ca49, "nf_ip_checksum" },
	{ 0xf126880c, "nf_ct_iterate_destroy" },
	{ 0xe4262c6, "__siphash_unaligned" },
	{ 0xc8e988a4, "inet_proto_csum_replace16" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x11b26ea6, "__put_net" },
	{ 0xb15b4109, "crc32c" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x8e141268, "__skb_checksum" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa5228d6e, "inet_proto_csum_replace4" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x60352082, "register_inet6addr_notifier" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x2124474, "ip_send_check" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe05b6928, "dst_release" },
	{ 0xd8659912, "nf_ct_kill_acct" },
	{ 0x289c3714, "nf_ct_alloc_hashtable" },
	{ 0xdebc2243, "nf_nat_hook" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xf68285c0, "register_inetaddr_notifier" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x7d5e1008, "__crc32c_le_shift" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x18e60984, "__do_once_start" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack,libcrc32c");


MODULE_INFO(srcversion, "DCAB7855575B749738C3DD2");
