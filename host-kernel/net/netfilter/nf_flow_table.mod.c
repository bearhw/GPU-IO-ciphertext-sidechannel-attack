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

SYMBOL_CRC(flow_offload_alloc, 0x9285c4f8, "_gpl");
SYMBOL_CRC(flow_offload_route_init, 0xd9ce211b, "_gpl");
SYMBOL_CRC(flow_offload_free, 0x3d218f35, "_gpl");
SYMBOL_CRC(flow_offload_add, 0xe41d9ee2, "_gpl");
SYMBOL_CRC(flow_offload_refresh, 0x3b4c831b, "_gpl");
SYMBOL_CRC(flow_offload_teardown, 0x83009121, "_gpl");
SYMBOL_CRC(flow_offload_lookup, 0xb0c7e117, "_gpl");
SYMBOL_CRC(nf_flow_snat_port, 0x13ba158e, "_gpl");
SYMBOL_CRC(nf_flow_dnat_port, 0x61489c4d, "_gpl");
SYMBOL_CRC(nf_flow_table_init, 0xe6e8770b, "_gpl");
SYMBOL_CRC(nf_flow_table_cleanup, 0xa964fc1a, "_gpl");
SYMBOL_CRC(nf_flow_table_free, 0x83b2a57a, "_gpl");
SYMBOL_CRC(nf_flow_offload_ip_hook, 0x5f762a35, "_gpl");
SYMBOL_CRC(nf_flow_offload_ipv6_hook, 0x6943d367, "_gpl");
SYMBOL_CRC(nf_flow_rule_route_ipv4, 0x05efd69a, "_gpl");
SYMBOL_CRC(nf_flow_rule_route_ipv6, 0x77701025, "_gpl");
SYMBOL_CRC(nf_flow_table_offload_setup, 0x52f6e549, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x200b2041, "in6addr_any" },
	{ 0x9c314842, "flow_rule_alloc" },
	{ 0x7ceff001, "ip6_dst_check" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xd0d156e9, "__rht_bucket_nested" },
	{ 0x653ab71e, "skb_gso_validate_network_len" },
	{ 0x61ce5c38, "ip_output" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xe589fb23, "neigh_xmit" },
	{ 0x600425fb, "flow_block_cb_free" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x78f6cca8, "ip6_output" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0x4b5acf74, "rhashtable_init" },
	{ 0xe5ce1a56, "rhashtable_walk_enter" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x3b08a8f0, "nf_ct_destroy" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xb5e73116, "flush_delayed_work" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x7980ce43, "dev_get_by_index" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x9a5dce5c, "rhashtable_walk_start_check" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x7762c736, "flow_indr_dev_setup_offload" },
	{ 0x9cd7551a, "rhashtable_walk_stop" },
	{ 0xb202f0d7, "rht_bucket_nested_insert" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x2a5ea9ef, "rhashtable_destroy" },
	{ 0x668b19a1, "down_read" },
	{ 0xc8e988a4, "inet_proto_csum_replace16" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xe0313d71, "rhashtable_insert_slow" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xf5d59d1d, "neigh_destroy" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xa5228d6e, "inet_proto_csum_replace4" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x7ba873bf, "nf_ct_acct_add" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xe05b6928, "dst_release" },
	{ 0x54651f9b, "rhashtable_walk_next" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x1010f037, "ipv4_dst_check" },
	{ 0x47884890, "system_power_efficient_wq" },
	{ 0xb7f990e9, "rht_bucket_nested" },
	{ 0x53b954a2, "up_read" },
	{ 0xf188a662, "rhashtable_walk_exit" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack");


MODULE_INFO(srcversion, "7E3E796A78A6BA89B1225AC");
