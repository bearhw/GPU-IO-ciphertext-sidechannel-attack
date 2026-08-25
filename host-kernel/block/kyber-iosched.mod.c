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
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x754d539c, "strlen" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x619ab02e, "bpf_trace_run7" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe7d4daac, "seq_list_next" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xff1e9dd8, "seq_list_start" },
	{ 0xe2e8c2c7, "sbitmap_queue_show" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xf8540d8c, "sbitmap_any_bit_set" },
	{ 0x5a42c937, "sbitmap_queue_clear" },
	{ 0xf2f72f5c, "sbitmap_queue_min_shallow_depth" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xdf9c6f3e, "sbitmap_del_wait_queue" },
	{ 0xb9a7e1b, "blk_mq_run_hw_queue" },
	{ 0x3288b93b, "__sbitmap_queue_get" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x6d606913, "pv_ops" },
	{ 0x2cc9d064, "sbitmap_add_wait_queue" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x37a0cba, "kfree" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x66669637, "blk_stat_disable_accounting" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x9feed7ce, "timer_reduce" },
	{ 0xe427e216, "elevator_alloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xf50e291a, "kmem_cache_alloc_node_trace" },
	{ 0xaf793668, "__alloc_percpu_gfp" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x449ebed1, "sbitmap_queue_init_node" },
	{ 0x7874a6d, "blk_stat_enable_accounting" },
	{ 0xf1d5773d, "blk_queue_flag_clear" },
	{ 0x7c181721, "kobject_put" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x6cfabcdc, "sbitmap_queue_resize" },
	{ 0x1ba59527, "__kmalloc_node" },
	{ 0x1cff8eab, "sbitmap_init_node" },
	{ 0xe053ebce, "__tracepoint_block_rq_insert" },
	{ 0x85bfc5f9, "__SCT__tp_func_block_rq_insert" },
	{ 0xcf04bfb4, "blk_bio_list_merge" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x5ea5718b, "elv_register" },
	{ 0xf4a863cd, "elv_unregister" },
	{ 0xfa8d188c, "blk_mq_debugfs_rq_show" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x4610dba7, "__SCK__tp_func_block_rq_insert" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7D1152C18A56C131440E7F4");
