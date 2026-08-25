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
	{ 0x732aeac, "cxgbi_ppm_make_ppod_hdr" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0xb55164b8, "cxgb4_create_server" },
	{ 0x10795da2, "__put_page" },
	{ 0x8dcf9ec3, "cxgb4_l2t_get" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xd081686c, "iscsit_add_reject" },
	{ 0xa428eda2, "iscsit_handle_task_mgt_cmd" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x2d76f0e8, "__napi_alloc_skb" },
	{ 0xcc394c0d, "cxgb4_pktgl_to_skb" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x633f7914, "iscsit_add_cmd_to_immediate_queue" },
	{ 0xfa3db473, "iscsit_build_r2ts_for_cmd" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xab10554f, "cxgb4_port_idx" },
	{ 0x47b27d14, "__ip_dev_find" },
	{ 0xa79cc6ef, "iscsit_find_cmd_from_itt_or_dump" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0xa59cd11d, "iscsit_build_datain_pdu" },
	{ 0xefa19b8f, "iscsit_register_transport" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x50ee5c07, "cxgb4_best_aligned_mtu" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x9b99786a, "iscsit_process_nop_out" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x744fc724, "cxgb4_register_uld" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xad980c4, "cxgbi_ppm_release" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x92997ed8, "_printk" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc0f8d9d9, "cxgb4_remove_server" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x387e3a0a, "iscsit_increment_maxcmdsn" },
	{ 0xbea6d845, "iscsit_find_cmd_from_itt" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x2758dc19, "iscsit_check_dataout_payload" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xc11368ca, "cxgb4_clip_get" },
	{ 0x68b1e409, "cxgb_find_route" },
	{ 0x93b3fc74, "register_dcbevent_notifier" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x212f14f3, "vlan_dev_real_dev" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x7c6024bd, "init_net" },
	{ 0xe53c1081, "dcb_ieee_getapp_mask" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0x5d350f5c, "iscsit_free_cmd" },
	{ 0x673efb3, "cxgb_find_route6" },
	{ 0x7980ce43, "dev_get_by_index" },
	{ 0x2ce0a58d, "skb_store_bits" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x3b43528a, "cxgb4_l2t_send" },
	{ 0xcc215396, "iscsit_queue_rsp" },
	{ 0x2e3bcce2, "wait_for_completion_interruptible" },
	{ 0x255ab30f, "cxgb_get_4tuple" },
	{ 0xc9ec65cb, "cxgb4_alloc_stid" },
	{ 0x68f9aee, "skb_prepare_seq_read" },
	{ 0xefa78c65, "iscsit_sequence_cmd" },
	{ 0x5dcd3f54, "iscsit_setup_nop_out" },
	{ 0x4ad50087, "iscsit_process_text_cmd" },
	{ 0xb8eed18, "cxgbi_ppm_init" },
	{ 0x86490580, "current_task" },
	{ 0x6a6e05bf, "kstrtou8" },
	{ 0x98b63eb4, "skb_abort_seq_read" },
	{ 0xeb4a89d0, "dcb_getapp" },
	{ 0x21936970, "iscsit_response_queue" },
	{ 0x28e2482f, "iscsit_allocate_cmd" },
	{ 0x86914231, "cxgb4_ofld_send" },
	{ 0xb32919ac, "cxgb4_remove_tid" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xf34332f0, "iscsi_find_param_from_key" },
	{ 0x9b33e0d7, "unregister_dcbevent_notifier" },
	{ 0xc6df469b, "__neigh_event_send" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x525353fe, "alloc_skb_with_frags" },
	{ 0x30d55d53, "iscsit_setup_scsi_cmd" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x6cd314c0, "iscsit_setup_text_cmd" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xfd043f15, "cxgb4_port_chan" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0xf5d59d1d, "neigh_destroy" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xf1a5528, "cxgb4_unregister_uld" },
	{ 0xd2941706, "iscsit_check_dataout_hdr" },
	{ 0xd0fe8d51, "sg_pcopy_from_buffer" },
	{ 0x3fa9736d, "cxgb4_free_stid" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x87b8798d, "sg_next" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xf7ca011d, "iscsit_handle_snack" },
	{ 0xdad1bbd8, "iscsit_handle_logout_cmd" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe05b6928, "dst_release" },
	{ 0xa42b1947, "iscsit_reject_cmd" },
	{ 0x53a2c6fc, "__iscsit_check_dataout_hdr" },
	{ 0x517c20a0, "cxgbi_ppm_ppod_release" },
	{ 0x541d5635, "iscsi_change_param_sprintf" },
	{ 0xe89b6c41, "cxgb4_create_server6" },
	{ 0xa9c29f67, "iscsit_thread_check_cpumask" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0xbc769b5f, "ipv6_chk_addr" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x4ed847b6, "target_put_sess_cmd" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xa2758f29, "iscsi_target_check_login_request" },
	{ 0x2baa2683, "iscsit_aborted_task" },
	{ 0x1c3b957b, "iscsit_unregister_transport" },
	{ 0x25d97f8f, "cxgb4_l2t_release" },
	{ 0xa223e4f7, "skb_seq_read" },
	{ 0xafbd7d9b, "iscsit_set_unsolicited_dataout" },
	{ 0x2173216f, "__kfree_skb" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xde916c50, "cxgb4_clip_release" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xb9f1b6cc, "iscsit_process_scsi_cmd" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xddb99393, "iscsit_immediate_queue" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x30bef374, "cxgbi_ppm_ppods_reserve" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "libcxgb,cxgb4,iscsi_target_mod,target_core_mod");


MODULE_INFO(srcversion, "13237ED4215499CAEE48ADB");
