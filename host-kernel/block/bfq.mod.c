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
	{ 0xaf0b6ba7, "blkg_rwstat_init" },
	{ 0x85bfc5f9, "__SCT__tp_func_block_rq_insert" },
	{ 0x279c0740, "elv_rb_add" },
	{ 0x6e8f2b0f, "blkg_rwstat_recursive_sum" },
	{ 0xc19836bb, "blkcg_activate_policy" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x77bc13a0, "strim" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x7874a6d, "blk_stat_enable_accounting" },
	{ 0xc3923267, "blk_mq_sched_try_merge" },
	{ 0xe1194d5, "hrtimer_try_to_cancel" },
	{ 0x9826f0c0, "wbt_disable_default" },
	{ 0xca9360b5, "rb_next" },
	{ 0x9c938036, "elv_rb_former_request" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x452b220f, "kernfs_path_from_node" },
	{ 0xf2f72f5c, "sbitmap_queue_min_shallow_depth" },
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0x40720230, "blkcg_print_blkgs" },
	{ 0x8ae54c5b, "__blkg_prfill_u64" },
	{ 0xba656661, "blkcg_deactivate_policy" },
	{ 0x66669637, "blk_stat_disable_accounting" },
	{ 0x37a0cba, "kfree" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x49e5bc8e, "blkcg_policy_unregister" },
	{ 0x7de6cc23, "io_cgrp_subsys_on_dfl_key" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf82ec573, "rb_prev" },
	{ 0xeae84dbe, "blk_queue_flag_set" },
	{ 0x28b6f5e2, "elv_bio_merge_ok" },
	{ 0x19edd064, "blkg_rwstat_exit" },
	{ 0x1d2915ac, "blk_mq_free_request" },
	{ 0xf50e291a, "kmem_cache_alloc_node_trace" },
	{ 0x69469d7a, "__blkg_prfill_rwstat" },
	{ 0x5ea5718b, "elv_register" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xde08f9a9, "put_io_context" },
	{ 0xfebfdd3, "ioc_find_get_icq" },
	{ 0x4d5f0607, "ioc_lookup_icq" },
	{ 0x4610dba7, "__SCK__tp_func_block_rq_insert" },
	{ 0x12a374c2, "of_css" },
	{ 0xe053ebce, "__tracepoint_block_rq_insert" },
	{ 0xc063c384, "elv_rqhash_add" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x64f5171, "blkg_conf_finish" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x1645c8ce, "__blk_trace_note_message" },
	{ 0xf4a863cd, "elv_unregister" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xe427e216, "elevator_alloc" },
	{ 0xb5a58a61, "blkg_prfill_rwstat" },
	{ 0x94ddeb46, "blk_mq_sched_try_insert_merge" },
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0xbfda6825, "bio_associate_blkg_from_css" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xe80fb7fc, "elv_rb_find" },
	{ 0x426b077d, "elv_rb_del" },
	{ 0xece784c2, "rb_first" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x2d2af022, "elv_rqhash_del" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xd0209497, "blkg_conf_prep" },
	{ 0xe138fb8c, "percpu_counter_add_batch" },
	{ 0x997cd293, "bdi_dev_name" },
	{ 0xa631b6f7, "elv_rb_latter_request" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x31ee3f7b, "wbt_enable_default" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x707469fc, "blkcg_policy_register" },
	{ 0xffae8e8b, "nsecs_to_jiffies" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x149d0e30, "blk_mq_run_hw_queues" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x5be3b198, "kmem_cache_alloc_node" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x7c181721, "kobject_put" },
	{ 0x61b7b126, "simple_strtoull" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "160EF0E1247284F4C8CFCB7");
