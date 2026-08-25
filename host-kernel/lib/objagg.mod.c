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

SYMBOL_CRC(objagg_obj_root_priv, 0x24ca5ca9, "");
SYMBOL_CRC(objagg_obj_delta_priv, 0x342aefe2, "");
SYMBOL_CRC(objagg_obj_raw, 0x0363233d, "");
SYMBOL_CRC(objagg_obj_get, 0xb17ab162, "");
SYMBOL_CRC(objagg_obj_put, 0x6691f29d, "");
SYMBOL_CRC(objagg_create, 0x679e8cc2, "");
SYMBOL_CRC(objagg_destroy, 0x23865923, "");
SYMBOL_CRC(objagg_stats_get, 0xdaa3ee68, "");
SYMBOL_CRC(objagg_stats_put, 0xf5511527, "");
SYMBOL_CRC(objagg_hints_get, 0xfaa9d1a8, "");
SYMBOL_CRC(objagg_hints_put, 0x3c58e78f, "");
SYMBOL_CRC(objagg_hints_stats_get, 0x352633f4, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x37a0cba, "kfree" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xb7f990e9, "rht_bucket_nested" },
	{ 0xffb7c514, "ida_free" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xd0d156e9, "__rht_bucket_nested" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x2a5ea9ef, "rhashtable_destroy" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0xe0313d71, "rhashtable_insert_slow" },
	{ 0xb202f0d7, "rht_bucket_nested_insert" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x4b5acf74, "rhashtable_init" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x69acdf38, "memcpy" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xb7c0f443, "sort" },
	{ 0x2688ec10, "bitmap_zalloc" },
	{ 0xca21ebd3, "bitmap_free" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3E88BF9D3A1FBAD5CC53477");
