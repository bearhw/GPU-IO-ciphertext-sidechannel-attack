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

SYMBOL_CRC(nvmet_wq, 0x3e0ef07a, "_gpl");
SYMBOL_CRC(nvmet_register_transport, 0x2e47c67f, "_gpl");
SYMBOL_CRC(nvmet_unregister_transport, 0x6508aecd, "_gpl");
SYMBOL_CRC(nvmet_req_complete, 0x78074d80, "_gpl");
SYMBOL_CRC(nvmet_sq_destroy, 0x035c7353, "_gpl");
SYMBOL_CRC(nvmet_sq_init, 0x3214b0a8, "_gpl");
SYMBOL_CRC(nvmet_req_init, 0x92cc0704, "_gpl");
SYMBOL_CRC(nvmet_req_uninit, 0x08ee4e8a, "_gpl");
SYMBOL_CRC(nvmet_check_transfer_len, 0x52cc8262, "_gpl");
SYMBOL_CRC(nvmet_req_alloc_sgls, 0xbdcfbf20, "_gpl");
SYMBOL_CRC(nvmet_req_free_sgls, 0x55866301, "_gpl");
SYMBOL_CRC(nvmet_ctrl_fatal_error, 0x5663ba06, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x751e692e, "filp_open" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x5dfc571a, "blk_start_plug" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x187b64e8, "config_group_init" },
	{ 0xabf06b63, "bio_add_zone_append_page" },
	{ 0xcf30c2cf, "bio_add_pc_page" },
	{ 0x788957f4, "blkdev_nr_zones" },
	{ 0x525d0aa3, "trace_seq_printf" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x81a7f541, "percpu_ref_init" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x1ba59527, "__kmalloc_node" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xbce4d380, "t10_pi_type1_crc" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0xcc5c2df4, "trace_print_symbols_seq" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x37a0cba, "kfree" },
	{ 0x77c4117a, "nvme_command_effects" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x697ed5f0, "memcpy_and_pad" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x1ed4d2eb, "percpu_ref_kill_and_confirm" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb56b87f1, "configfs_unregister_subsystem" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x2d192c70, "sg_zero_buffer" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1b5f4377, "trace_seq_putc" },
	{ 0x4af6ddf0, "kstrtou16" },
	{ 0x92997ed8, "_printk" },
	{ 0x1953c958, "mempool_create" },
	{ 0xfb3195f8, "vfs_fallocate" },
	{ 0xbb3021a7, "blkdev_zone_mgmt" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x3197c4e3, "put_device" },
	{ 0x3a13f54a, "sgl_alloc" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x1d2915ac, "blk_mq_free_request" },
	{ 0x6bce7da8, "blkdev_put" },
	{ 0x49b6b84c, "blk_finish_plug" },
	{ 0xefab6f8e, "submit_bio" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf12c728b, "t10_pi_type3_crc" },
	{ 0x800473f, "__cond_resched" },
	{ 0x9eacf8a5, "kstrndup" },
	{ 0x37bf7be3, "percpu_ref_exit" },
	{ 0xa09dd780, "bio_put" },
	{ 0x4e6e4b41, "radix_tree_delete" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x310a6f4a, "nvme_execute_passthru_rq" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x69e683de, "uuid_gen" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xd28f6a7f, "fput" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xffb2df28, "configfs_register_subsystem" },
	{ 0x8df92f66, "memchr_inv" },
	{ 0x8a99a016, "mempool_free_slab" },
	{ 0x2c541e7b, "radix_tree_next_chunk" },
	{ 0xa26854e7, "blk_execute_rq_nowait" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xb3f548ad, "kmemdup_nul" },
	{ 0xa85a3e6d, "xa_load" },
	{ 0x8bc8cc11, "config_group_init_type_name" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x7f60d7d7, "bio_integrity_add_page" },
	{ 0x5a921311, "strncmp" },
	{ 0x28aee912, "blkdev_get_by_path" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x9166fada, "strncpy" },
	{ 0x9f218161, "bio_chain" },
	{ 0x386865d5, "blk_mq_alloc_request" },
	{ 0xffb7c514, "ida_free" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0x9519cb96, "bio_add_page" },
	{ 0xf16db61d, "nvme_find_get_ns" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd0ebc22, "bio_integrity_alloc" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x11089ac7, "_ctype" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xc005bb87, "bio_init" },
	{ 0xd9aa2171, "iov_iter_bvec" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xc972449f, "mempool_alloc_slab" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xb67fec0e, "uuid_parse" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x668b19a1, "down_read" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xa0ebc08, "__xa_cmpxchg" },
	{ 0x7dcf4135, "__xa_insert" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x745a981, "xa_erase" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x1ac5d3cb, "strcspn" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x2bd37371, "vfs_fsync" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xd45cc6ca, "bin2hex" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xd9491c14, "xa_destroy" },
	{ 0x8fa25c24, "xa_find" },
	{ 0xd0fe8d51, "sg_pcopy_from_buffer" },
	{ 0x87b8798d, "sg_next" },
	{ 0x84d5b86a, "filp_close" },
	{ 0x9034a696, "mempool_destroy" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xab6d5b3b, "hex_to_bin" },
	{ 0x6b9f01cd, "blkdev_issue_flush" },
	{ 0xedb26570, "nvme_ctrl_from_file" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xdf36914b, "xa_find_after" },
	{ 0x2c80cada, "nvme_init_request" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x9f6715de, "nvme_put_ns" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x53b954a2, "up_read" },
	{ 0xf5c77bcb, "__blkdev_issue_zeroout" },
	{ 0x840342c6, "sgl_free" },
	{ 0x66ab0f6e, "nvme_get_features" },
	{ 0xbf529047, "submit_bio_wait" },
	{ 0x264fc44e, "blkdev_report_zones" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xea778fab, "sg_pcopy_to_buffer" },
	{ 0xaef27061, "__blkdev_issue_discard" },
	{ 0x9af19ea7, "fs_bio_set" },
	{ 0x26b9b950, "blk_next_bio" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nvme-core");


MODULE_INFO(srcversion, "BAF83951D6539EA69880654");
