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

SYMBOL_CRC(qrtr_endpoint_post, 0xa118a39f, "_gpl");
SYMBOL_CRC(qrtr_endpoint_register, 0x489d6cd5, "_gpl");
SYMBOL_CRC(qrtr_endpoint_unregister, 0x62ea9e12, "_gpl");
SYMBOL_CRC(qrtr_ns_init, 0xa47e91ba, "_gpl");
SYMBOL_CRC(qrtr_ns_remove, 0x8d25501f, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0xe914e41e, "strcpy" },
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0x657dfd17, "__skb_pad" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x6fbc6a00, "radix_tree_insert" },
	{ 0xbe888b32, "skb_put" },
	{ 0xbd505649, "consume_skb" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x33fc2a31, "get_user_ifreq" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x70ad75fb, "radix_tree_lookup" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xbd9acb3b, "kernel_bind" },
	{ 0x99f7371c, "refcount_dec_and_mutex_lock" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xbbd13bd3, "kernel_recvmsg" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0x6dc35b25, "radix_tree_iter_delete" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x50171cd6, "sock_register" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x68764184, "proto_register" },
	{ 0xc6cbbc89, "capable" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x9114b616, "__xa_alloc" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x4e6e4b41, "radix_tree_delete" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x7c6024bd, "init_net" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x2c541e7b, "radix_tree_next_chunk" },
	{ 0xa85a3e6d, "xa_load" },
	{ 0x26ad0377, "kernel_getsockname" },
	{ 0x5102a30b, "do_wait_intr_irq" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x4967e79f, "radix_tree_iter_resume" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x74129b89, "__netdev_alloc_skb" },
	{ 0x7dcf4135, "__xa_insert" },
	{ 0x745a981, "xa_erase" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xc5c1e5c7, "skb_set_owner_w" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xcf78d1e6, "sock_create_kern" },
	{ 0x8fa25c24, "xa_find" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x6e5c0971, "sock_release" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0xdf36914b, "xa_find_after" },
	{ 0x754d539c, "strlen" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x55ad2c95, "kernel_sendmsg" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0x38f48af7, "put_user_ifreq" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xae4cc05, "release_sock" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5585D63A937876806B92B71");
