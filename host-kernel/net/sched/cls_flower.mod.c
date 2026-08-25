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
	{ 0x8df92f66, "memchr_inv" },
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf1db1704, "nla_memcpy" },
	{ 0x32e73b5a, "skb_flow_dissector_init" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x37a0cba, "kfree" },
	{ 0x2a5ea9ef, "rhashtable_destroy" },
	{ 0x1de23e95, "module_put" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x55c24701, "tc_setup_cb_call" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xfb578fc5, "memset" },
	{ 0x69acdf38, "memcpy" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x4b5acf74, "rhashtable_init" },
	{ 0xd79a11d7, "tc_setup_cb_destroy" },
	{ 0x2a43c84e, "tcf_exts_num_actions" },
	{ 0x9c314842, "flow_rule_alloc" },
	{ 0x544a6a64, "tc_setup_offload_action" },
	{ 0x949ca6ba, "tc_setup_cb_add" },
	{ 0x1bbaae09, "tc_cleanup_offload_action" },
	{ 0xe77d6a32, "tcf_action_update_hw_stats" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3f56328e, "tcf_exts_destroy" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xb7f990e9, "rht_bucket_nested" },
	{ 0x46302d3a, "skb_flow_dissect_tunnel_info" },
	{ 0x41cec996, "skb_flow_dissect_ct" },
	{ 0x9f260e92, "skb_flow_dissect_hash" },
	{ 0xa8c6da59, "__skb_flow_dissect" },
	{ 0x13e2551, "skb_flow_dissect_meta" },
	{ 0xb954f70a, "tcf_action_exec" },
	{ 0x84823cf3, "nla_strscpy" },
	{ 0xb2d00eb2, "__dev_get_by_name" },
	{ 0x431ec3a9, "__nla_validate" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xb202f0d7, "rht_bucket_nested_insert" },
	{ 0xe0313d71, "rhashtable_insert_slow" },
	{ 0x20978fb9, "idr_find" },
	{ 0xd0d156e9, "__rht_bucket_nested" },
	{ 0xefaf2e4f, "tcf_queue_work" },
	{ 0xcc1b882a, "idr_get_next_ul" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x6d5f5b91, "radix_tree_tagged" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xd79e38dc, "tc_setup_cb_reoffload" },
	{ 0x56470118, "__warn_printk" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0xa916b694, "strnlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbbd5e70e, "tcf_exts_dump" },
	{ 0xb92e3849, "tcf_exts_dump_stats" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0xac982700, "tcf_exts_terse_dump" },
	{ 0xd78b2513, "tcf_exts_validate_ex" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x7b82b9a1, "idr_replace" },
	{ 0xd9916c3a, "idr_alloc_u32" },
	{ 0xfe99c7ff, "register_tcf_proto_ops" },
	{ 0x5c68b240, "unregister_tcf_proto_ops" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "14C037BBA056391DB06D87D");
