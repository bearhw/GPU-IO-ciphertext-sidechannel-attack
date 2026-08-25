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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(netfs_readahead, 0xc4d515d6, "");
SYMBOL_CRC(netfs_read_folio, 0x189ecaef, "");
SYMBOL_CRC(netfs_write_begin, 0x77ac2715, "");
SYMBOL_CRC(netfs_subreq_terminated, 0xddece776, "");
SYMBOL_CRC(netfs_stats_show, 0x0f58cb88, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x896e8009, "__page_file_index" },
	{ 0x10795da2, "__put_page" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xb59f000f, "folio_unlock" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x39c9d88c, "xas_find" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0xcc5c2df4, "trace_print_symbols_seq" },
	{ 0x37a0cba, "kfree" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xde5f1da7, "swapcache_mapping" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x647eba4f, "__filemap_get_folio" },
	{ 0x5d49aabc, "init_wait_var_entry" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x5e332b52, "__var_waitqueue" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x65967cd6, "readahead_expand" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xa85a3e6d, "xa_load" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x86490580, "current_task" },
	{ 0xf8f61ebc, "wake_up_var" },
	{ 0xfb578fc5, "memset" },
	{ 0xd857beda, "folio_end_private_2" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xd27d7c99, "iov_iter_zero" },
	{ 0xd4c14632, "system_unbound_wq" },
	{ 0x2460f990, "iov_iter_xarray" },
	{ 0xa0fbac79, "wake_up_bit" },
	{ 0x58ea47a5, "folio_wait_private_2_killable" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9D01EFFA08A1CA8166D6923");
