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
	{ 0x4a39f83b, "nf_ct_tcp_seqadj_set" },
	{ 0x4cba5ac3, "nf_ct_expect_put" },
	{ 0x6115227b, "nf_connlabels_replace" },
	{ 0xba53adab, "nla_policy_len" },
	{ 0x2e0a33ae, "nf_ct_l4proto_find" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x287598ab, "nf_conntrack_unregister_notifier" },
	{ 0x38be4902, "nf_conntrack_register_notifier" },
	{ 0xe4262c6, "__siphash_unaligned" },
	{ 0xe17678a, "siphash_4u64" },
	{ 0x18e60984, "__do_once_start" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xbe38f709, "__do_once_done" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0xdebc2243, "nf_nat_hook" },
	{ 0xdb065657, "nfnl_unlock" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x5ce3b588, "nfnl_lock" },
	{ 0x8520a781, "nla_put" },
	{ 0xf44d53da, "security_secid_to_secctx" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x431ec3a9, "__nla_validate" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0xbf87fcb0, "nf_ct_expect_find_get" },
	{ 0x9adb7399, "nf_conntrack_expect_lock" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x51debcdc, "nf_ct_unlink_expect_report" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x32ca6c6a, "nf_ct_expect_iterate_net" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xe4efabed, "nf_conntrack_count" },
	{ 0xf38bcdf3, "nf_conntrack_max" },
	{ 0xd807659f, "nfnetlink_unicast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x7457d34f, "nf_ct_remove_expectations" },
	{ 0x8aa26d24, "__nf_conntrack_helper_find" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x3b08a8f0, "nf_ct_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x4eb7d7bb, "nf_ct_expect_alloc" },
	{ 0xd7922687, "nf_ct_helper_expectfn_find_by_name" },
	{ 0xfe29d8d1, "nf_ct_expect_related_report" },
	{ 0xa916b694, "strnlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x754d539c, "strlen" },
	{ 0xed61f6b3, "security_release_secctx" },
	{ 0xb637256e, "nf_ct_helper_expectfn_find_by_symbol" },
	{ 0x421b2d09, "nfnetlink_has_listeners" },
	{ 0xf57d1ead, "nfnetlink_set_err" },
	{ 0xda159d28, "nfnetlink_send" },
	{ 0xc18ac88d, "nf_ct_expect_hsize" },
	{ 0xec8beba6, "nf_ct_expect_hash" },
	{ 0xd973b705, "nf_ct_get_id" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x8ffe7e89, "nf_conntrack_htable_size" },
	{ 0xaf0847f0, "nf_conntrack_locks" },
	{ 0xdba7326b, "nf_conntrack_lock" },
	{ 0x28eff409, "nf_conntrack_hash" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xc1bdbf4f, "nf_ct_delete" },
	{ 0xaa28cd50, "nf_conntrack_find_get" },
	{ 0xd8895533, "__nf_ct_expect_find" },
	{ 0x24d273d1, "add_timer" },
	{ 0xb85bd397, "nf_conn_pernet_ecache" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x137ce6f6, "nf_conntrack_alloc" },
	{ 0xdd7d2188, "nf_ct_helper_ext_add" },
	{ 0x82b6160f, "nf_ct_ext_add" },
	{ 0x86977087, "nf_ct_ecache_ext_add" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xbc8bf472, "nf_conntrack_hash_check_insert" },
	{ 0x3979a864, "__nf_ct_try_assign_helper" },
	{ 0xbbcc0a90, "nf_conntrack_free" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x1bb51d38, "nf_conntrack_eventmask_report" },
	{ 0xef65c4b1, "nf_ct_iterate_cleanup_net" },
	{ 0x6fea8456, "nfnetlink_subsys_register" },
	{ 0x92997ed8, "_printk" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x6ece208b, "nfnetlink_subsys_unregister" },
	{ 0x2bf15ca4, "nfnl_ct_hook" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack,nfnetlink");


MODULE_INFO(srcversion, "A98F74DBEB988C8FEE4B14F");
