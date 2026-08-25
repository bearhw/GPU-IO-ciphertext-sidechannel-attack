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

SYMBOL_CRC(target_depend_item, 0x22f68c44, "");
SYMBOL_CRC(target_undepend_item, 0xe615e671, "");
SYMBOL_CRC(target_register_template, 0xd2719129, "");
SYMBOL_CRC(target_unregister_template, 0x5085599b, "");
SYMBOL_CRC(sbc_attrib_attrs, 0x58dfdea7, "");
SYMBOL_CRC(passthrough_attrib_attrs, 0x3aed5964, "");
SYMBOL_CRC(passthrough_pr_attrib_attrs, 0x0e6b161a, "");
SYMBOL_CRC(transport_lookup_cmd_lun, 0xce1f2e9c, "");
SYMBOL_CRC(transport_lookup_tmr_lun, 0x7aca4af8, "");
SYMBOL_CRC(target_lun_is_rdonly, 0x8c7184ab, "");
SYMBOL_CRC(target_nacl_find_deve, 0x24602a2b, "");
SYMBOL_CRC(target_configure_unmap_from_queue, 0xa42e29af, "");
SYMBOL_CRC(target_to_linux_sector, 0x7f70af7a, "");
SYMBOL_CRC(passthrough_parse_cdb, 0xe189049a, "");
SYMBOL_CRC(transport_backend_register, 0xec722f37, "");
SYMBOL_CRC(target_backend_unregister, 0xded62f97, "");
SYMBOL_CRC(core_alua_check_nonop_delay, 0x4e717dc0, "");
SYMBOL_CRC(core_tmr_alloc_req, 0x4163bd28, "");
SYMBOL_CRC(core_tpg_get_initiator_node_acl, 0xac657885, "");
SYMBOL_CRC(core_allocate_nexus_loss_ua, 0x8c5933d7, "");
SYMBOL_CRC(target_tpg_has_node_acl, 0x380a781d, "");
SYMBOL_CRC(core_tpg_check_initiator_node_acl, 0x87aac2f8, "");
SYMBOL_CRC(core_tpg_set_initiator_node_queue_depth, 0x364ab031, "");
SYMBOL_CRC(core_tpg_set_initiator_node_tag, 0x977165e6, "");
SYMBOL_CRC(core_tpg_register, 0x3464c940, "");
SYMBOL_CRC(core_tpg_deregister, 0x590775d8, "");
SYMBOL_CRC(transport_init_session, 0x0497bb8d, "");
SYMBOL_CRC(transport_alloc_session, 0x079bb909, "");
SYMBOL_CRC(transport_alloc_session_tags, 0x89d1ee5c, "");
SYMBOL_CRC(__transport_register_session, 0xf5c45043, "");
SYMBOL_CRC(transport_register_session, 0xa5dc8a63, "");
SYMBOL_CRC(target_setup_session, 0x3d4912de, "");
SYMBOL_CRC(target_show_dynamic_sessions, 0x0b3eec32, "");
SYMBOL_CRC(target_put_nacl, 0x41bfe1df, "");
SYMBOL_CRC(transport_deregister_session_configfs, 0x07f026ac, "");
SYMBOL_CRC(transport_free_session, 0x989bb726, "");
SYMBOL_CRC(transport_deregister_session, 0xd67475d7, "");
SYMBOL_CRC(target_remove_session, 0xcf62688d, "");
SYMBOL_CRC(transport_copy_sense_to_cmd, 0x5fe9aab5, "");
SYMBOL_CRC(target_complete_cmd_with_sense, 0xcdacc519, "");
SYMBOL_CRC(target_complete_cmd, 0x6cab4b6b, "");
SYMBOL_CRC(target_set_cmd_data_length, 0xb46119af, "");
SYMBOL_CRC(target_complete_cmd_with_length, 0x1dd8eda9, "");
SYMBOL_CRC(transport_set_vpd_proto_id, 0xf3c2dfe0, "");
SYMBOL_CRC(transport_set_vpd_assoc, 0x142072c0, "");
SYMBOL_CRC(transport_set_vpd_ident_type, 0x3a20a9d7, "");
SYMBOL_CRC(transport_set_vpd_ident, 0x0871ffd6, "");
SYMBOL_CRC(__target_init_cmd, 0xb4cc8898, "");
SYMBOL_CRC(target_cmd_init_cdb, 0x423defb2, "");
SYMBOL_CRC(target_cmd_parse_cdb, 0xd67c7de1, "");
SYMBOL_CRC(transport_handle_cdb_direct, 0x654b4a33, "");
SYMBOL_CRC(target_init_cmd, 0xf2c36958, "_gpl");
SYMBOL_CRC(target_submit_prep, 0xa695b5fc, "_gpl");
SYMBOL_CRC(target_submit, 0x061fa78b, "_gpl");
SYMBOL_CRC(target_submit_cmd, 0x320237e3, "");
SYMBOL_CRC(target_queue_submission, 0x497f6a4d, "_gpl");
SYMBOL_CRC(target_submit_tmr, 0xd20e5487, "");
SYMBOL_CRC(transport_generic_request_failure, 0x3a8f3f5e, "");
SYMBOL_CRC(target_execute_cmd, 0x9db2f5e1, "");
SYMBOL_CRC(target_free_sgl, 0x638bffb7, "");
SYMBOL_CRC(transport_kmap_data_sg, 0x717b0c2b, "");
SYMBOL_CRC(transport_kunmap_data_sg, 0xb76c87df, "");
SYMBOL_CRC(target_alloc_sgl, 0x7a1d0d3c, "");
SYMBOL_CRC(transport_generic_new_cmd, 0x628bc7ff, "");
SYMBOL_CRC(transport_generic_free_cmd, 0x5a207c8d, "");
SYMBOL_CRC(target_get_sess_cmd, 0x1155806f, "");
SYMBOL_CRC(target_put_sess_cmd, 0x4ed847b6, "");
SYMBOL_CRC(target_show_cmd, 0x5e9da140, "");
SYMBOL_CRC(target_stop_session, 0xa718b46d, "");
SYMBOL_CRC(target_wait_for_sess_cmds, 0xdf0631c9, "");
SYMBOL_CRC(transport_wait_for_tasks, 0xa9a4ef21, "");
SYMBOL_CRC(transport_send_check_condition_and_sense, 0xe3ffa071, "");
SYMBOL_CRC(target_send_busy, 0x02dc34d4, "");
SYMBOL_CRC(transport_generic_handle_tmr, 0xc93ffbbd, "");
SYMBOL_CRC(sbc_get_write_same_sectors, 0xa668688f, "");
SYMBOL_CRC(sbc_parse_cdb, 0x14fa2140, "");
SYMBOL_CRC(sbc_get_device_type, 0xf7dcd754, "");
SYMBOL_CRC(sbc_dif_copy_prot, 0xe69b3dc5, "");
SYMBOL_CRC(sbc_dif_verify, 0x9d3ab428, "");
SYMBOL_CRC(spc_emulate_inquiry_std, 0x330dc88c, "");
SYMBOL_CRC(spc_emulate_evpd_83, 0x3be549a6, "");
SYMBOL_CRC(spc_emulate_report_luns, 0xad479b9d, "");
SYMBOL_CRC(spc_parse_cdb, 0x5910af20, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x8a35b432, "sme_me_mask" },
	{ 0x751e692e, "filp_open" },
	{ 0xe914e41e, "strcpy" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xc91fdf58, "percpu_ref_is_zero" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x187b64e8, "config_group_init" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x77bc13a0, "strim" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x6aa11aa6, "sgl_free_n_order" },
	{ 0x81a7f541, "percpu_ref_init" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0xc666a132, "crc_t10dif" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xfa55dc45, "config_item_get" },
	{ 0xcf2a6966, "up" },
	{ 0xfba7ddd2, "match_u64" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0xcc5c2df4, "trace_print_symbols_seq" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x94961283, "vunmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x5ed90adc, "int_to_scsilun" },
	{ 0x818416e1, "scsi_set_sense_information" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xe02ba436, "trace_print_hex_seq" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x1ed4d2eb, "percpu_ref_kill_and_confirm" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x449ebed1, "sbitmap_queue_init_node" },
	{ 0xb56b87f1, "configfs_unregister_subsystem" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x50cf7585, "hex2bin" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x96b29254, "strncasecmp" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x91aef43c, "config_item_get_unless_zero" },
	{ 0xa916b694, "strnlen" },
	{ 0xddb1cd7, "llist_reverse_order" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x8058afd3, "bdev_discard_alignment" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x3a2f6702, "sg_alloc_table" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x37bf7be3, "percpu_ref_exit" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xd28f6a7f, "fput" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xffb2df28, "configfs_register_subsystem" },
	{ 0x4e3567f7, "match_int" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0xfc89af6e, "configfs_remove_default_groups" },
	{ 0x8bc8cc11, "config_group_init_type_name" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x5a921311, "strncmp" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x9166fada, "strncpy" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x2e3bcce2, "wait_for_completion_interruptible" },
	{ 0xed2a2b32, "vmap" },
	{ 0x97a57333, "crc_t10dif_update" },
	{ 0x334da4e, "scsi_command_size_tbl" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x72ea7b2d, "scsi_device_type" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0x86490580, "current_task" },
	{ 0x91f44510, "idr_alloc_cyclic" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x11089ac7, "_ctype" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0xfb578fc5, "memset" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xbaad92ad, "configfs_depend_item" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x1d40b6f3, "idr_for_each" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x999e8297, "vfree" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x87b8798d, "sg_next" },
	{ 0x84d5b86a, "filp_close" },
	{ 0xfbcbfb4d, "config_item_put" },
	{ 0x44e9a829, "match_token" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0x6bd0e573, "down_interruptible" },
	{ 0xab6d5b3b, "hex_to_bin" },
	{ 0x8112b3d2, "scsi_build_sense_buffer" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xacf4d843, "match_strdup" },
	{ 0x7c144603, "configfs_undepend_item" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xc7a1840e, "llist_add_batch" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xeb9e913d, "sgl_alloc_order" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x349cba85, "strchr" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x2b8ab42, "sg_copy_to_buffer" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xdd6a20bc, "kernel_write" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "63F5F4C180529F37EFF37A9");
