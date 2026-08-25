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
	{ 0xb0d72d67, "tcf_action_update_stats" },
	{ 0x1fecca28, "tcf_generic_walker" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x83b2a57a, "nf_flow_table_free" },
	{ 0x57bc19d2, "down_write" },
	{ 0x600425fb, "flow_block_cb_free" },
	{ 0xce807a25, "up_write" },
	{ 0x37a0cba, "kfree" },
	{ 0x1de23e95, "module_put" },
	{ 0x6c82ac38, "tcf_idr_search" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0x8520a781, "nla_put" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x6e819985, "nf_connlabels_put" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x5fac85af, "tcf_idrinfo_destroy" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x7d0db45c, "jiffies_to_clock_t" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x8c229db9, "nf_connlabels_get" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x92997ed8, "_printk" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x574404da, "nf_nat_packet" },
	{ 0x73b781fc, "nf_nat_alloc_null_binding" },
	{ 0x3342eae6, "nf_nat_icmp_reply_translation" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x918169e8, "nf_nat_setup_info" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0x9a620884, "nf_nat_icmpv6_reply_translation" },
	{ 0xfe731af8, "nf_ct_invert_tuple" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xd0d156e9, "__rht_bucket_nested" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x6fb49676, "queue_rcu_work" },
	{ 0x3b08a8f0, "nf_ct_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xe0313d71, "rhashtable_insert_slow" },
	{ 0xe6e8770b, "nf_flow_table_init" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0xb7f990e9, "rht_bucket_nested" },
	{ 0xb202f0d7, "rht_bucket_nested_insert" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xa0ccec95, "tcf_idr_check_alloc" },
	{ 0x98233750, "tcf_action_check_ctrlact" },
	{ 0x3b9dfc4b, "nf_ct_tmpl_alloc" },
	{ 0xee12f7aa, "tcf_chain_put_by_act" },
	{ 0x8b91cbe3, "tcf_idr_release" },
	{ 0xcb4e8e16, "tcf_idr_create_from_flags" },
	{ 0xae55b187, "tcf_idr_cleanup" },
	{ 0x77c89692, "tcf_action_set_ctrlact" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0xb0c7e117, "flow_offload_lookup" },
	{ 0x3b4c831b, "flow_offload_refresh" },
	{ 0x7ba873bf, "nf_ct_acct_add" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x83009121, "flow_offload_teardown" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x6d63a14c, "skb_pull_rcsum" },
	{ 0x64175a25, "nf_conntrack_in" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xec623802, "ipv6_find_hdr" },
	{ 0xdba43280, "nf_ct_frag6_gather" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xbaeddd05, "nf_ct_deliver_cached_events" },
	{ 0x7c6024bd, "init_net" },
	{ 0x9285c4f8, "flow_offload_alloc" },
	{ 0xe41d9ee2, "flow_offload_add" },
	{ 0x3d218f35, "flow_offload_free" },
	{ 0x1de7493b, "ip_defrag" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0x284bf3d3, "pskb_trim_rcsum_slow" },
	{ 0xebef499b, "nf_ct_nat_ext_add" },
	{ 0x6115227b, "nf_connlabels_replace" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x82b6160f, "nf_ct_ext_add" },
	{ 0xc1bdbf4f, "nf_ct_delete" },
	{ 0xd2800691, "nf_conntrack_destroy" },
	{ 0x9739d19f, "__nf_conntrack_confirm" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x4b5acf74, "rhashtable_init" },
	{ 0xe66395f2, "tcf_register_action" },
	{ 0x2a5ea9ef, "rhashtable_destroy" },
	{ 0x22d60537, "tcf_frag_xmit_count" },
	{ 0x8e92f7c4, "static_key_slow_inc" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x2f4880df, "static_key_slow_dec" },
	{ 0x11d85980, "tcf_unregister_action" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_flow_table,nf_conntrack,nf_nat,nf_defrag_ipv6");


MODULE_INFO(srcversion, "4154E10E4D5D474B1B3BBEC");
