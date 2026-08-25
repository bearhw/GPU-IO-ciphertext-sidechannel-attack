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
	{ 0x15ba50a6, "jiffies" },
	{ 0x618911fc, "numa_node" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xbe888b32, "skb_put" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x74129b89, "__netdev_alloc_skb" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xcd22b3bf, "skb_add_rx_frag" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x49608959, "migrate_disable" },
	{ 0xf84bd6ee, "bpf_stats_enabled_key" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3a26ed11, "sched_clock" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x4d7272e4, "migrate_enable" },
	{ 0x9728e1cd, "bpf_prog_free" },
	{ 0x37a0cba, "kfree" },
	{ 0xf5e7ea40, "ktime_get_coarse_ts64" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x1a9a433c, "prandom_u32_state" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xa916b694, "strnlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x92997ed8, "_printk" },
	{ 0xdd64e639, "strscpy" },
	{ 0x800473f, "__cond_resched" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xb237e1d6, "bpf_prog_create" },
	{ 0x35b09b15, "bpf_prog_alloc" },
	{ 0xf413fb7, "bpf_prog_select_runtime" },
	{ 0x7c6024bd, "init_net" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x76048be1, "bpf_prog_destroy" },
	{ 0x6ef6b54f, "ktime_get_boot_fast_ns" },
	{ 0xc9827693, "__bpf_call_base" },
	{ 0x8f142d61, "skb_segment" },
	{ 0xd01cc0c4, "kfree_skb_list_reason" },
	{ 0x5daa032f, "param_ops_string" },
	{ 0x786109b9, "param_array_ops" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DB9AED92D2FFC51B7345585");
