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

SYMBOL_CRC(nft_do_chain, 0x41675c5e, "_gpl");
SYMBOL_CRC(nft_reg_track_update, 0xe2648860, "_gpl");
SYMBOL_CRC(nft_reg_track_cancel, 0x3ba8815c, "_gpl");
SYMBOL_CRC(__nft_reg_track_cancel, 0xd96ead83, "_gpl");
SYMBOL_CRC(nft_request_module, 0xc49d60a2, "_gpl");
SYMBOL_CRC(nft_register_chain_type, 0xcdc37acf, "_gpl");
SYMBOL_CRC(nft_unregister_chain_type, 0xa0187704, "_gpl");
SYMBOL_CRC(nft_register_expr, 0x7f1125f0, "_gpl");
SYMBOL_CRC(nft_unregister_expr, 0x68a43391, "_gpl");
SYMBOL_CRC(nft_chain_validate, 0x5297dfd8, "_gpl");
SYMBOL_CRC(nft_set_lookup_global, 0x7202e3e1, "_gpl");
SYMBOL_CRC(nf_tables_bind_set, 0x247dca3c, "_gpl");
SYMBOL_CRC(nf_tables_deactivate_set, 0xd2ff380f, "_gpl");
SYMBOL_CRC(nf_tables_destroy_set, 0x81038d2f, "_gpl");
SYMBOL_CRC(nft_set_elem_destroy, 0x809007ac, "_gpl");
SYMBOL_CRC(nft_set_catchall_lookup, 0x84cf13b7, "_gpl");
SYMBOL_CRC(nft_set_catchall_gc, 0x1956faae, "_gpl");
SYMBOL_CRC(nft_register_obj, 0x61688841, "_gpl");
SYMBOL_CRC(nft_unregister_obj, 0x497d4d0e, "_gpl");
SYMBOL_CRC(nft_obj_lookup, 0x6ca5c4b2, "_gpl");
SYMBOL_CRC(nft_obj_notify, 0x7f0c58ba, "_gpl");
SYMBOL_CRC(nft_register_flowtable_type, 0x1bc1a5b7, "_gpl");
SYMBOL_CRC(nft_unregister_flowtable_type, 0xc9345284, "_gpl");
SYMBOL_CRC(nft_flowtable_lookup, 0xa1525092, "_gpl");
SYMBOL_CRC(nf_tables_deactivate_flowtable, 0xfbc67e43, "_gpl");
SYMBOL_CRC(nf_tables_trans_destroy_flush_work, 0x3251d762, "_gpl");
SYMBOL_CRC(nft_chain_validate_dependency, 0x5d0f4059, "_gpl");
SYMBOL_CRC(nft_chain_validate_hooks, 0xae47eb8d, "_gpl");
SYMBOL_CRC(nft_parse_u32_check, 0xde57b5f5, "_gpl");
SYMBOL_CRC(nft_dump_register, 0x38d85c39, "_gpl");
SYMBOL_CRC(nft_parse_register_load, 0xe2b8cc13, "_gpl");
SYMBOL_CRC(nft_parse_register_store, 0xe1da1c18, "_gpl");
SYMBOL_CRC(nft_data_init, 0x8fc2eda3, "_gpl");
SYMBOL_CRC(nft_data_release, 0x5fb53a4c, "_gpl");
SYMBOL_CRC(nft_data_dump, 0xba3c52e8, "_gpl");
SYMBOL_CRC(__nft_release_basechain, 0x7fe8182c, "_gpl");
SYMBOL_CRC(nft_trace_enabled, 0x41b71e65, "_gpl");
SYMBOL_CRC(nft_expr_reduce_bitwise, 0x80f36393, "_gpl");
SYMBOL_CRC(nft_set_do_lookup, 0x7a2c13de, "_gpl");
SYMBOL_CRC(nft_meta_get_eval, 0x94b94301, "_gpl");
SYMBOL_CRC(nft_meta_set_eval, 0x92fd7b2d, "_gpl");
SYMBOL_CRC(nft_meta_policy, 0x06c6ca47, "_gpl");
SYMBOL_CRC(nft_meta_get_init, 0xe0c85dcd, "_gpl");
SYMBOL_CRC(nft_meta_set_validate, 0x25fcc86f, "_gpl");
SYMBOL_CRC(nft_meta_set_init, 0xee472574, "_gpl");
SYMBOL_CRC(nft_meta_get_dump, 0x13e8e7f7, "_gpl");
SYMBOL_CRC(nft_meta_set_dump, 0x196482b4, "_gpl");
SYMBOL_CRC(nft_meta_set_destroy, 0x43480a5d, "_gpl");
SYMBOL_CRC(nft_meta_get_reduce, 0x36eb0946, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbe38f709, "__do_once_done" },
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0x9c314842, "flow_rule_alloc" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xd0d156e9, "__rht_bucket_nested" },
	{ 0x9968aacb, "__audit_log_nfcfg" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0xbe888b32, "skb_put" },
	{ 0x8e92f7c4, "static_key_slow_inc" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xedbaee5e, "nla_strcmp" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xb0e602eb, "memmove" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xad115d2, "nla_reserve" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x73dd54eb, "irq_fpu_usable" },
	{ 0x7a53a06d, "flow_indr_dev_exists" },
	{ 0x1ba59527, "__kmalloc_node" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xca9360b5, "rb_next" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x2c82c36a, "security_secmark_relabel_packet" },
	{ 0xf57d1ead, "nfnetlink_set_err" },
	{ 0x75d0deb9, "nsecs_to_jiffies64" },
	{ 0x7b37d4a7, "_find_first_zero_bit" },
	{ 0x6d7c7dcc, "bitmap_cut" },
	{ 0x600425fb, "flow_block_cb_free" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x6fea8456, "nfnetlink_subsys_register" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xead8daf3, "ip6_route_me_harder" },
	{ 0x39b52d19, "__bitmap_and" },
	{ 0x4b5acf74, "rhashtable_init" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x148653, "vsnprintf" },
	{ 0xe5ce1a56, "rhashtable_walk_enter" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xb2d00eb2, "__dev_get_by_name" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x2f4880df, "static_key_slow_dec" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x99177604, "__ip_options_compile" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xb549b1e4, "nf_route" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0x618911fc, "numa_node" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x615911d7, "__bitmap_set" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x60e68b98, "nf_unregister_net_hook" },
	{ 0xaf793668, "__alloc_percpu_gfp" },
	{ 0xfe5d4bb2, "sys_tz" },
	{ 0xd70cb50a, "nf_register_net_hook" },
	{ 0xfd381298, "__skb_get_hash" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x19bd383b, "security_secmark_refcount_dec" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0x6a1530dc, "ip_route_me_harder" },
	{ 0x2ce0a58d, "skb_store_bits" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xd807659f, "nfnetlink_unicast" },
	{ 0x8520a781, "nla_put" },
	{ 0x9166fada, "strncpy" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x6b76129f, "skb_ensure_writable" },
	{ 0xc0ff12fb, "nla_strdup" },
	{ 0x9a5dce5c, "rhashtable_walk_start_check" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xdb065657, "nfnl_unlock" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x7762c736, "flow_indr_dev_setup_offload" },
	{ 0x9cd7551a, "rhashtable_walk_stop" },
	{ 0x86490580, "current_task" },
	{ 0xb44e18ea, "audit_enabled" },
	{ 0x838d2bc8, "siphash_3u32" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x7f6cee89, "rhashtable_free_and_destroy" },
	{ 0xcfacc347, "skb_checksum" },
	{ 0xfb578fc5, "memset" },
	{ 0x92ec510d, "jiffies64_to_msecs" },
	{ 0xb202f0d7, "rht_bucket_nested_insert" },
	{ 0xda159d28, "nfnetlink_send" },
	{ 0x6b0cd993, "__get_task_comm" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xece784c2, "rb_first" },
	{ 0x6ece208b, "nfnetlink_subsys_unregister" },
	{ 0xc0acbebd, "from_kgid_munged" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0xe0313d71, "rhashtable_insert_slow" },
	{ 0xec623802, "ipv6_find_hdr" },
	{ 0xb15b4109, "crc32c" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x2f03fc4b, "security_secmark_refcount_inc" },
	{ 0x8e141268, "__skb_checksum" },
	{ 0x5ce3b588, "nfnl_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xa5228d6e, "inet_proto_csum_replace4" },
	{ 0xdf54a8f7, "netlink_unregister_notifier" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x3ac3feba, "rhltable_init" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xfff5afc, "time64_to_tm" },
	{ 0xe05b6928, "dst_release" },
	{ 0x84823cf3, "nla_strscpy" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x54651f9b, "rhashtable_walk_next" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xfa599bb2, "netlink_register_notifier" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0xf9c1f9ab, "security_secctx_to_secid" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x349cba85, "strchr" },
	{ 0x47884890, "system_power_efficient_wq" },
	{ 0xb7f990e9, "rht_bucket_nested" },
	{ 0xf188a662, "rhashtable_walk_exit" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x7d5e1008, "__crc32c_le_shift" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x18e60984, "__do_once_start" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x421b2d09, "nfnetlink_has_listeners" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nfnetlink,libcrc32c");


MODULE_INFO(srcversion, "D709B18270B6BDE98F58CBA");
