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

SYMBOL_CRC(fscache_addremove_sem, 0x557a775f, "");
SYMBOL_CRC(fscache_clearance_waiters, 0x8c2d6da7, "");
SYMBOL_CRC(fscache_acquire_cache, 0xa88e298e, "");
SYMBOL_CRC(fscache_relinquish_cache, 0x9a332aa3, "");
SYMBOL_CRC(fscache_add_cache, 0x21bd4501, "");
SYMBOL_CRC(fscache_io_error, 0x02f2a410, "");
SYMBOL_CRC(fscache_withdraw_cache, 0xe836c1f9, "");
SYMBOL_CRC(fscache_end_cookie_access, 0x3b59ba90, "");
SYMBOL_CRC(fscache_cookie_lookup_negative, 0x750cc0e0, "");
SYMBOL_CRC(fscache_resume_after_invalidation, 0xaabc229d, "");
SYMBOL_CRC(fscache_caching_failed, 0xc3501134, "");
SYMBOL_CRC(__fscache_acquire_cookie, 0xc14a7717, "");
SYMBOL_CRC(__fscache_use_cookie, 0x0a2dc793, "");
SYMBOL_CRC(__fscache_unuse_cookie, 0x79e839b0, "");
SYMBOL_CRC(fscache_withdraw_cookie, 0x0e426411, "");
SYMBOL_CRC(__fscache_relinquish_cookie, 0xff2ed30d, "");
SYMBOL_CRC(fscache_put_cookie, 0x58f0b367, "");
SYMBOL_CRC(fscache_get_cookie, 0x70727b31, "");
SYMBOL_CRC(__fscache_invalidate, 0x848be1ea, "");
SYMBOL_CRC(fscache_wait_for_operation, 0x353ff625, "");
SYMBOL_CRC(__fscache_begin_read_operation, 0x6635c5ec, "");
SYMBOL_CRC(__fscache_begin_write_operation, 0x0d091e82, "");
SYMBOL_CRC(fscache_dirty_folio, 0x81ac0c56, "");
SYMBOL_CRC(__fscache_clear_page_bits, 0xb64e30dd, "");
SYMBOL_CRC(__fscache_write_to_cache, 0x311cc6f3, "");
SYMBOL_CRC(__fscache_resize_cookie, 0x8ab02772, "");
SYMBOL_CRC(__tracepoint_fscache_access_cache, 0xc6f957f5, "");
SYMBOL_CRC(__traceiter_fscache_access_cache, 0xae6040a5, "");
SYMBOL_CRC(__SCK__tp_func_fscache_access_cache, 0x4989a80a, "");
SYMBOL_CRC(__SCT__tp_func_fscache_access_cache, 0x7c87e02d, "");
SYMBOL_CRC(__tracepoint_fscache_access_volume, 0x88af10f3, "");
SYMBOL_CRC(__traceiter_fscache_access_volume, 0x234a140d, "");
SYMBOL_CRC(__SCK__tp_func_fscache_access_volume, 0xa5228f81, "");
SYMBOL_CRC(__SCT__tp_func_fscache_access_volume, 0x7b1b25da, "");
SYMBOL_CRC(__tracepoint_fscache_access, 0x181c7151, "");
SYMBOL_CRC(__traceiter_fscache_access, 0xdcb87498, "");
SYMBOL_CRC(__SCK__tp_func_fscache_access, 0x0ec28fec, "");
SYMBOL_CRC(__SCT__tp_func_fscache_access, 0x5954d7ac, "");
SYMBOL_CRC(fscache_wq, 0xbca46908, "");
SYMBOL_CRC(fscache_end_volume_access, 0xe944102a, "");
SYMBOL_CRC(__fscache_acquire_volume, 0xd879d018, "");
SYMBOL_CRC(__fscache_relinquish_volume, 0x1dca90ea, "");
SYMBOL_CRC(fscache_withdraw_volume, 0x29d1bdbc, "");
SYMBOL_CRC(fscache_n_updates, 0x4996bd29, "");
SYMBOL_CRC(fscache_n_read, 0x9ffefcb2, "");
SYMBOL_CRC(fscache_n_write, 0x1a0d09e7, "");
SYMBOL_CRC(fscache_n_no_write_space, 0xcce11a60, "");
SYMBOL_CRC(fscache_n_no_create_space, 0x4404d2aa, "");
SYMBOL_CRC(fscache_n_culled, 0x90d447f3, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xe7d4daac, "seq_list_next" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0xf346231f, "seq_list_start_head" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x39c9d88c, "xas_find" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0xcc5c2df4, "trace_print_symbols_seq" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xf58cb88, "netfs_stats_show" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1984d421, "out_of_line_wait_on_bit" },
	{ 0xb6a022da, "remove_proc_subtree" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x9feed7ce, "timer_reduce" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x5d49aabc, "init_wait_var_entry" },
	{ 0x16e297c3, "bit_wait" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x5e332b52, "__var_waitqueue" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x7871e78, "bpf_trace_run5" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xf8f61ebc, "wake_up_var" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0xd857beda, "folio_end_private_2" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x668b19a1, "down_read" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xfbe0e228, "filemap_dirty_folio" },
	{ 0x391de184, "seq_puts" },
	{ 0x2460f990, "iov_iter_xarray" },
	{ 0xa6aa1711, "proc_create_single_data" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xa0fbac79, "wake_up_bit" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x53b954a2, "up_read" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "netfs");


MODULE_INFO(srcversion, "8E936B737EE328F8A8C8680");
