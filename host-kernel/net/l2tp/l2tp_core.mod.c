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

SYMBOL_CRC(l2tp_sk_to_tunnel, 0xce886e70, "_gpl");
SYMBOL_CRC(l2tp_tunnel_inc_refcount, 0xc59ed1d6, "_gpl");
SYMBOL_CRC(l2tp_tunnel_dec_refcount, 0x7c90c120, "_gpl");
SYMBOL_CRC(l2tp_session_inc_refcount, 0xb8359cc7, "_gpl");
SYMBOL_CRC(l2tp_session_dec_refcount, 0x3195783f, "_gpl");
SYMBOL_CRC(l2tp_tunnel_get, 0x5f4375c2, "_gpl");
SYMBOL_CRC(l2tp_tunnel_get_nth, 0x58ac7f2e, "_gpl");
SYMBOL_CRC(l2tp_tunnel_get_session, 0x44e8a412, "_gpl");
SYMBOL_CRC(l2tp_session_get, 0xd010dd2e, "_gpl");
SYMBOL_CRC(l2tp_session_get_nth, 0x7b0a3df8, "_gpl");
SYMBOL_CRC(l2tp_session_get_by_ifname, 0xaa750062, "_gpl");
SYMBOL_CRC(l2tp_session_register, 0x6242c13e, "_gpl");
SYMBOL_CRC(l2tp_recv_common, 0xe3591ce7, "_gpl");
SYMBOL_CRC(l2tp_udp_encap_recv, 0x1ebe39c0, "_gpl");
SYMBOL_CRC(l2tp_xmit_skb, 0x17c410a1, "_gpl");
SYMBOL_CRC(l2tp_tunnel_create, 0x4f7c2e55, "_gpl");
SYMBOL_CRC(l2tp_tunnel_register, 0xeb9dec00, "_gpl");
SYMBOL_CRC(l2tp_tunnel_delete, 0x2c1a0516, "_gpl");
SYMBOL_CRC(l2tp_session_delete, 0x4238cc26, "_gpl");
SYMBOL_CRC(l2tp_session_set_header_len, 0xebf0ff1e, "_gpl");
SYMBOL_CRC(l2tp_session_create, 0xddeee1c6, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0xcc5c2df4, "trace_print_symbols_seq" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x627234d, "udp_sock_create6" },
	{ 0xf43e05f3, "kernel_sock_shutdown" },
	{ 0x6e5c0971, "sock_release" },
	{ 0xcf78d1e6, "sock_create_kern" },
	{ 0xbd9acb3b, "kernel_bind" },
	{ 0x288ef7e1, "kernel_connect" },
	{ 0x70852ca3, "udp_sock_create4" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x37a0cba, "kfree" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x69acdf38, "memcpy" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x47ad4ec3, "ip_queue_xmit" },
	{ 0x6d606913, "pv_ops" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0xadfa871d, "udp_set_csum" },
	{ 0x1f12fa6, "inet6_csk_xmit" },
	{ 0xdf27a4e5, "udp6_set_csum" },
	{ 0xd2800691, "nf_conntrack_destroy" },
	{ 0xe05b6928, "dst_release" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6194c18d, "sockfd_lookup" },
	{ 0xd28f6a7f, "fput" },
	{ 0x458fde4a, "setup_udp_tunnel_sock" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xd3fdf94d, "register_pernet_device" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x92997ed8, "_printk" },
	{ 0x643e518b, "unregister_pernet_device" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip6_udp_tunnel,udp_tunnel");


MODULE_INFO(srcversion, "D9BEFEF5971A4254F21400C");
