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

SYMBOL_CRC(dccp_feat_list_purge, 0x4cdd391d, "_gpl");
SYMBOL_CRC(dccp_feat_nn_get, 0x2c33d198, "_gpl");
SYMBOL_CRC(dccp_feat_signal_nn_change, 0xe8627a56, "_gpl");
SYMBOL_CRC(dccp_rcv_established, 0x2ccc02d6, "_gpl");
SYMBOL_CRC(dccp_rcv_state_process, 0xc0a5b6ab, "_gpl");
SYMBOL_CRC(dccp_death_row, 0x014a1f33, "_gpl");
SYMBOL_CRC(dccp_create_openreq_child, 0x1e1391f2, "_gpl");
SYMBOL_CRC(dccp_check_req, 0x181e53ce, "_gpl");
SYMBOL_CRC(dccp_child_process, 0xb344f8ce, "_gpl");
SYMBOL_CRC(dccp_reqsk_send_ack, 0xf4bb6920, "_gpl");
SYMBOL_CRC(dccp_reqsk_init, 0x83a57545, "_gpl");
SYMBOL_CRC(dccp_parse_options, 0xb17f840d, "_gpl");
SYMBOL_CRC(dccp_insert_option, 0x537d5030, "_gpl");
SYMBOL_CRC(dccp_sync_mss, 0x0368fb95, "_gpl");
SYMBOL_CRC(dccp_make_response, 0x5d82976e, "_gpl");
SYMBOL_CRC(dccp_ctl_make_reset, 0xb61539d2, "_gpl");
SYMBOL_CRC(dccp_connect, 0x6103fa99, "_gpl");
SYMBOL_CRC(dccp_send_ack, 0x73e0af9b, "_gpl");
SYMBOL_CRC(dccp_send_sync, 0xf48f4278, "_gpl");
SYMBOL_CRC(dccp_statistics, 0x59814a84, "_gpl");
SYMBOL_CRC(dccp_orphan_count, 0xd75b7072, "_gpl");
SYMBOL_CRC(dccp_hashinfo, 0x0e4fac9e, "_gpl");
SYMBOL_CRC(dccp_set_state, 0x765268f3, "_gpl");
SYMBOL_CRC(dccp_done, 0x78981924, "_gpl");
SYMBOL_CRC(dccp_packet_name, 0x86be7924, "_gpl");
SYMBOL_CRC(dccp_init_sock, 0x48802110, "_gpl");
SYMBOL_CRC(dccp_destroy_sock, 0x9e865606, "_gpl");
SYMBOL_CRC(dccp_disconnect, 0x5a66d955, "_gpl");
SYMBOL_CRC(dccp_poll, 0x28fa21d8, "_gpl");
SYMBOL_CRC(dccp_ioctl, 0x413fd817, "_gpl");
SYMBOL_CRC(dccp_setsockopt, 0xd08bbb91, "_gpl");
SYMBOL_CRC(dccp_getsockopt, 0x89f9370b, "_gpl");
SYMBOL_CRC(dccp_sendmsg, 0x399c3608, "_gpl");
SYMBOL_CRC(dccp_recvmsg, 0x631af98f, "_gpl");
SYMBOL_CRC(inet_dccp_listen, 0x0108eb16, "_gpl");
SYMBOL_CRC(dccp_close, 0x16248a0d, "_gpl");
SYMBOL_CRC(dccp_shutdown, 0x3969fc9a, "_gpl");
SYMBOL_CRC(dccp_timestamp, 0x80993155, "_gpl");
SYMBOL_CRC(dccp_ackvec_parsed_add, 0x182ec2bf, "_gpl");
SYMBOL_CRC(dccp_ackvec_parsed_cleanup, 0x9598d24d, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xce945996, "inet_hashinfo2_init_mod" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xf4707cf4, "inet_ehash_locks_alloc" },
	{ 0xbe888b32, "skb_put" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xbd505649, "consume_skb" },
	{ 0xcf6d36d0, "sock_wmalloc" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x84c1c552, "proc_dointvec_ms_jiffies" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x926eb584, "inet_csk_clear_xmit_timers" },
	{ 0x148653, "vsnprintf" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x2ba1559, "inet_twsk_alloc" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0xf03d537f, "inet_sock_destruct" },
	{ 0x56be1f23, "inet_put_port" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x92997ed8, "_printk" },
	{ 0x843082e, "inet_csk_init_xmit_timers" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xc8827b75, "sysctl_vals" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xd09cd600, "sk_reset_timer" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0xf4a8adc2, "sk_stream_wait_close" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xba2e9f96, "inet_twsk_hashdance" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x7c6024bd, "init_net" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x894f2745, "sock_wake_async" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xec2e1c8f, "proc_doulongvec_minmax" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0xd2c99738, "__kmalloc_track_caller" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x944375db, "_totalram_pages" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x86490580, "current_task" },
	{ 0xd319981b, "tcp_stream_memory_free" },
	{ 0xcfacc347, "skb_checksum" },
	{ 0xfb578fc5, "memset" },
	{ 0xf7fec202, "sk_wait_data" },
	{ 0xe2a4d262, "inet_csk_clone_lock" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x738737f9, "skb_unlink" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x7634aa0e, "inet_csk_listen_start" },
	{ 0x6d606913, "pv_ops" },
	{ 0x43caacf, "sk_free_unlock_clone" },
	{ 0x2235b121, "sock_rfree" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0xc5c1e5c7, "skb_set_owner_w" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xb827bc31, "inet_sk_set_state" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe05b6928, "dst_release" },
	{ 0x75a90502, "sk_stream_wait_connect" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x9450a7c1, "inet_csk_destroy_sock" },
	{ 0x8991d825, "sk_stop_timer" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x2dea2f3c, "inet_rtx_syn_ack" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0xa07d1b3c, "tasklet_setup" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xa249aa30, "inet_csk_listen_stop" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x2173216f, "__kfree_skb" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x2d4479bb, "inet_csk_complete_hashdance" },
	{ 0xae4cc05, "release_sock" },
	{ 0x62a85488, "inet_csk_reqsk_queue_drop" },
	{ 0x8f126d5d, "__inet_twsk_schedule" },
	{ 0x2cdf87a1, "proc_dointvec_minmax" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1BF7B0817BC6C16147208A6");
