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
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x9db2f5e1, "target_execute_cmd" },
	{ 0xd295dae8, "fc_seq_send" },
	{ 0xd20e5487, "target_submit_tmr" },
	{ 0xdf0631c9, "target_wait_for_sess_cmds" },
	{ 0xa695b5fc, "target_submit_prep" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x61fa78b, "target_submit" },
	{ 0xe5cf06b5, "fc_lport_notifier_head" },
	{ 0x7f3407a7, "fc_seq_start_next" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x907d14d, "blocking_notifier_chain_register" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x5085599b, "target_unregister_template" },
	{ 0x3d4912de, "target_setup_session" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x917f0bbb, "fc_seq_set_resp" },
	{ 0x1c6580f6, "fc_frame_alloc_fill" },
	{ 0xcf62688d, "target_remove_session" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xd05ba368, "fc_fc4_deregister_provider" },
	{ 0x5a921311, "strncmp" },
	{ 0x5a42c937, "sbitmap_queue_clear" },
	{ 0x977165e6, "core_tpg_set_initiator_node_tag" },
	{ 0x811811e0, "fc_exch_done" },
	{ 0xb2b730d8, "fc_fill_reply_hdr" },
	{ 0x86490580, "current_task" },
	{ 0x32612683, "_fc_frame_alloc" },
	{ 0x11089ac7, "_ctype" },
	{ 0xfb578fc5, "memset" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x7c47ca19, "fc_seq_assign" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xf2c36958, "target_init_cmd" },
	{ 0x4ece3615, "blocking_notifier_chain_unregister" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xa718b46d, "target_stop_session" },
	{ 0xea3c8e4e, "scsilun_to_int" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x87b8798d, "sg_next" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x590775d8, "core_tpg_deregister" },
	{ 0xab6d5b3b, "hex_to_bin" },
	{ 0xd2719129, "target_register_template" },
	{ 0x5a207c8d, "transport_generic_free_cmd" },
	{ 0x6e57150f, "fc_lport_iterate" },
	{ 0x97c3aaa4, "fc_fc4_register_provider" },
	{ 0x3464c940, "core_tpg_register" },
	{ 0x4ed847b6, "target_put_sess_cmd" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xfa4667d1, "fc_seq_release" },
	{ 0x3288b93b, "__sbitmap_queue_get" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "target_core_mod,libfc");


MODULE_INFO(srcversion, "04146260199DFEF82B3BCAC");
