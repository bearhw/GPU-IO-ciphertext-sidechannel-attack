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

SYMBOL_CRC(__tracepoint_bcache_request_start, 0x0434f128, "_gpl");
SYMBOL_CRC(__traceiter_bcache_request_start, 0xc0a04e9d, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_request_start, 0x8b28ea05, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_request_start, 0xd7a7fbec, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_request_end, 0xfb1f0420, "_gpl");
SYMBOL_CRC(__traceiter_bcache_request_end, 0x5ad2020f, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_request_end, 0xa2757c29, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_request_end, 0xfce76b1e, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_bypass_sequential, 0x5326d90b, "_gpl");
SYMBOL_CRC(__traceiter_bcache_bypass_sequential, 0x24feede8, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_bypass_sequential, 0x8a7d2195, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_bypass_sequential, 0xf57f81ae, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_bypass_congested, 0xee0dbd4b, "_gpl");
SYMBOL_CRC(__traceiter_bcache_bypass_congested, 0xc013fcaa, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_bypass_congested, 0x63afffa2, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_bypass_congested, 0x7f252e00, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_read, 0x98c0c0d8, "_gpl");
SYMBOL_CRC(__traceiter_bcache_read, 0xe5b0afa2, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_read, 0x3e884576, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_read, 0xedf90bb3, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_write, 0xb76dbf9d, "_gpl");
SYMBOL_CRC(__traceiter_bcache_write, 0x37c2e24b, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_write, 0x86a579f7, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_write, 0x5dd80bd5, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_read_retry, 0x58544dc3, "_gpl");
SYMBOL_CRC(__traceiter_bcache_read_retry, 0x6f8daa72, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_read_retry, 0x811153bf, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_read_retry, 0x787810b2, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_cache_insert, 0x058f3f55, "_gpl");
SYMBOL_CRC(__traceiter_bcache_cache_insert, 0xb5a62a8c, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_cache_insert, 0x7c0aed89, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_cache_insert, 0x752f7fa4, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_journal_replay_key, 0x671814af, "_gpl");
SYMBOL_CRC(__traceiter_bcache_journal_replay_key, 0x2766fb04, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_journal_replay_key, 0x7076f114, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_journal_replay_key, 0xb7e5379d, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_journal_write, 0x1204e0cd, "_gpl");
SYMBOL_CRC(__traceiter_bcache_journal_write, 0xcefae5a9, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_journal_write, 0x9d18fbe0, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_journal_write, 0x287090dc, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_journal_full, 0xfe528479, "_gpl");
SYMBOL_CRC(__traceiter_bcache_journal_full, 0x2dd43ff9, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_journal_full, 0x87d756a5, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_journal_full, 0xdb0682eb, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_journal_entry_full, 0x8dbf5f47, "_gpl");
SYMBOL_CRC(__traceiter_bcache_journal_entry_full, 0x3d11e07d, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_journal_entry_full, 0x9ad1bafc, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_journal_entry_full, 0xf7a5edc7, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_btree_cache_cannibalize, 0x636900ce, "_gpl");
SYMBOL_CRC(__traceiter_bcache_btree_cache_cannibalize, 0xed3b1cf3, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_btree_cache_cannibalize, 0xa215ea7d, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_btree_cache_cannibalize, 0x822db771, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_btree_read, 0x0b61fb5d, "_gpl");
SYMBOL_CRC(__traceiter_bcache_btree_read, 0x76f43674, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_btree_read, 0xd224e521, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_btree_read, 0xce451ad8, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_btree_write, 0x2a2c6909, "_gpl");
SYMBOL_CRC(__traceiter_bcache_btree_write, 0x80e755dd, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_btree_write, 0x73461100, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_btree_write, 0x629c9180, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_btree_node_alloc, 0x46851d2e, "_gpl");
SYMBOL_CRC(__traceiter_bcache_btree_node_alloc, 0x9fa9554f, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_btree_node_alloc, 0xcb275fc7, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_btree_node_alloc, 0x21b87a42, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_btree_node_alloc_fail, 0x81c18181, "_gpl");
SYMBOL_CRC(__traceiter_bcache_btree_node_alloc_fail, 0x7e015855, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_btree_node_alloc_fail, 0xc1c9db91, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_btree_node_alloc_fail, 0x297e0da3, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_btree_node_free, 0xfbc4183a, "_gpl");
SYMBOL_CRC(__traceiter_bcache_btree_node_free, 0x26b689f8, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_btree_node_free, 0x518b0425, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_btree_node_free, 0x817ad796, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_btree_gc_coalesce, 0x5e5a8def, "_gpl");
SYMBOL_CRC(__traceiter_bcache_btree_gc_coalesce, 0x1c599ebe, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_btree_gc_coalesce, 0x87017571, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_btree_gc_coalesce, 0xa15bd7c4, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_gc_start, 0xc9d32fee, "_gpl");
SYMBOL_CRC(__traceiter_bcache_gc_start, 0xd528b2b7, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_gc_start, 0x848c5b63, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_gc_start, 0x6677ebf0, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_gc_end, 0x96b518cf, "_gpl");
SYMBOL_CRC(__traceiter_bcache_gc_end, 0xf14f55be, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_gc_end, 0x3be3584f, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_gc_end, 0xd7a376b3, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_gc_copy, 0xa58bda08, "_gpl");
SYMBOL_CRC(__traceiter_bcache_gc_copy, 0xad6440b4, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_gc_copy, 0x489e0f68, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_gc_copy, 0x36f317a4, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_gc_copy_collision, 0x2108d4ce, "_gpl");
SYMBOL_CRC(__traceiter_bcache_gc_copy_collision, 0xec29e22a, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_gc_copy_collision, 0xf8532c50, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_gc_copy_collision, 0xd30206ff, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_btree_insert_key, 0x734002bd, "_gpl");
SYMBOL_CRC(__traceiter_bcache_btree_insert_key, 0xff58a81f, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_btree_insert_key, 0xfee24054, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_btree_insert_key, 0x972aa384, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_btree_node_split, 0xac853c19, "_gpl");
SYMBOL_CRC(__traceiter_bcache_btree_node_split, 0xce3efb5a, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_btree_node_split, 0x21277ef0, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_btree_node_split, 0x9d28d153, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_btree_node_compact, 0xdb1198b1, "_gpl");
SYMBOL_CRC(__traceiter_bcache_btree_node_compact, 0xdd13022a, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_btree_node_compact, 0xcc7f7d0a, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_btree_node_compact, 0xa784e073, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_btree_set_root, 0x14862ca1, "_gpl");
SYMBOL_CRC(__traceiter_bcache_btree_set_root, 0x17dbf083, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_btree_set_root, 0x51d66ccf, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_btree_set_root, 0x25cacb14, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_invalidate, 0xe5e53602, "_gpl");
SYMBOL_CRC(__traceiter_bcache_invalidate, 0xeee38674, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_invalidate, 0x3ca0287e, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_invalidate, 0xc73e0c99, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_alloc_fail, 0xec2091f4, "_gpl");
SYMBOL_CRC(__traceiter_bcache_alloc_fail, 0xcbf0ece3, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_alloc_fail, 0x35658f88, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_alloc_fail, 0x300c8ff4, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_writeback, 0x7365101f, "_gpl");
SYMBOL_CRC(__traceiter_bcache_writeback, 0x17a83e40, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_writeback, 0xe021b0f6, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_writeback, 0xfb767f16, "_gpl");
SYMBOL_CRC(__tracepoint_bcache_writeback_collision, 0x97dac6a5, "_gpl");
SYMBOL_CRC(__traceiter_bcache_writeback_collision, 0x64e39418, "_gpl");
SYMBOL_CRC(__SCK__tp_func_bcache_writeback_collision, 0xcb7ec244, "_gpl");
SYMBOL_CRC(__SCT__tp_func_bcache_writeback_collision, 0x4543b49b, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xd2e83b51, "set_disk_ro" },
	{ 0x56232755, "__blk_alloc_disk" },
	{ 0xceb66bec, "sched_clock_cpu" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x10795da2, "__put_page" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x2ce5db37, "__bio_add_page" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x81088473, "blk_queue_logical_block_size" },
	{ 0xc63d2aad, "zero_fill_bio" },
	{ 0xdf2c2742, "rb_last" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0xd7e56a4e, "simple_strtoll" },
	{ 0x87c820c0, "bio_copy_data" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x77bc13a0, "strim" },
	{ 0xd64d9143, "set_blocksize" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0xb0e602eb, "memmove" },
	{ 0x88330529, "device_add_disk" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x205bff71, "bio_init_clone" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0xca9360b5, "rb_next" },
	{ 0x98b142fa, "blk_fill_rwbs" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x96848186, "scnprintf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xcf2a6966, "up" },
	{ 0x15c85de3, "mempool_init" },
	{ 0x5c000d78, "kobject_init" },
	{ 0xeee3ef31, "register_shrinker" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0x3496c7a, "blk_queue_write_cache" },
	{ 0xd35a6d31, "mempool_kmalloc" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xeaf3cb23, "crc64_be" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc3ff38c2, "down_read_trylock" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbc1c6683, "bio_end_io_acct_remapped" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x963afbea, "wake_up_process" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0xb678366f, "int_sqrt" },
	{ 0x6a037cf1, "mempool_kfree" },
	{ 0x93391c7f, "bio_clone_blkg_association" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x92997ed8, "_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x3517383e, "register_reboot_notifier" },
	{ 0x95b79998, "fs_kobj" },
	{ 0xeae84dbe, "blk_queue_flag_set" },
	{ 0xddb1cd7, "llist_reverse_order" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x231b2691, "unregister_shrinker" },
	{ 0x6bce7da8, "blkdev_put" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x40a9b349, "vzalloc" },
	{ 0xefab6f8e, "submit_bio" },
	{ 0x1de23e95, "module_put" },
	{ 0xf1d5773d, "blk_queue_flag_clear" },
	{ 0xa1179cbd, "bio_start_io_acct" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x60e4f971, "sysfs_create_link" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x2c07ddf, "bioset_exit" },
	{ 0x800473f, "__cond_resched" },
	{ 0xb5a459dc, "unregister_blkdev" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xac1a55be, "unregister_reboot_notifier" },
	{ 0x9eacf8a5, "kstrndup" },
	{ 0xd376caec, "kobject_uevent_env" },
	{ 0xa09dd780, "bio_put" },
	{ 0x2d26b611, "bio_endio" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x2b73bad9, "__bio_advance" },
	{ 0x57bc19d2, "down_write" },
	{ 0xcfb8f52a, "kobject_add" },
	{ 0xce807a25, "up_write" },
	{ 0xb7c0f443, "sort" },
	{ 0x8a99a016, "mempool_free_slab" },
	{ 0x12e0c97, "sysfs_remove_link" },
	{ 0x24d273d1, "add_timer" },
	{ 0xb3f548ad, "kmemdup_nul" },
	{ 0xe3f3d437, "set_capacity" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x6626afca, "down" },
	{ 0x7871e78, "bpf_trace_run5" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0xd985dc99, "mempool_free_pages" },
	{ 0x28aee912, "blkdev_get_by_path" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0xffb7c514, "ida_free" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xf1e046cc, "panic" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x8f381413, "del_gendisk" },
	{ 0xb2aabc17, "blk_queue_max_discard_sectors" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe9ffc063, "down_trylock" },
	{ 0x6c5a75f0, "read_cache_page_gfp" },
	{ 0x86490580, "current_task" },
	{ 0x11089ac7, "_ctype" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x169938c1, "__sysfs_match_string" },
	{ 0xca868887, "bd_unlink_disk_holder" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xc005bb87, "bio_init" },
	{ 0x53c25af3, "bio_alloc_clone" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xb5f8bf36, "bio_reset" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xc972449f, "mempool_alloc_slab" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xece784c2, "rb_first" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xe40c37ea, "down_write_trylock" },
	{ 0xeaf730c2, "kobject_create_and_add" },
	{ 0x668b19a1, "down_read" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x34c7cdbc, "lookup_bdev" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x18219d34, "bio_free_pages" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x999e8297, "vfree" },
	{ 0x6b980b08, "kobject_del" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x720a27a7, "__register_blkdev" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xe08efff5, "bioset_init" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0xee91879b, "rb_first_postorder" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x631ba0f2, "sysfs_create_files" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x4e5ffe32, "bd_link_disk_holder" },
	{ 0x18888d00, "downgrade_write" },
	{ 0x4e68e9be, "rb_next_postorder" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xb5c4e0ab, "blk_cleanup_disk" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0xc7a1840e, "llist_add_batch" },
	{ 0xc29bf967, "strspn" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0x35e03f29, "blk_queue_io_opt" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x53b954a2, "up_read" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x929d9ed2, "kobject_get" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x38e46431, "mempool_exit" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x54366892, "bio_split" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x766a0927, "mempool_alloc_pages" },
	{ 0xe3a87077, "blkdev_issue_discard" },
	{ 0x7c181721, "kobject_put" },
	{ 0x61b7b126, "simple_strtoull" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "793DA7E5D6E6DB59749A4A3");
