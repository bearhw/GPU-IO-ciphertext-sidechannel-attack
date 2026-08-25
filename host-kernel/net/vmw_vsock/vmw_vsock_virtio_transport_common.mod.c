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

SYMBOL_CRC(virtio_transport_deliver_tap_pkt, 0x7b796eea, "_gpl");
SYMBOL_CRC(virtio_transport_inc_tx_pkt, 0xb5e68ef9, "_gpl");
SYMBOL_CRC(virtio_transport_get_credit, 0x33ae09bb, "_gpl");
SYMBOL_CRC(virtio_transport_put_credit, 0x27aede70, "_gpl");
SYMBOL_CRC(virtio_transport_stream_dequeue, 0x1b160278, "_gpl");
SYMBOL_CRC(virtio_transport_seqpacket_dequeue, 0x88e9c2ce, "_gpl");
SYMBOL_CRC(virtio_transport_seqpacket_enqueue, 0x383db6a1, "_gpl");
SYMBOL_CRC(virtio_transport_dgram_dequeue, 0x81f0eb88, "_gpl");
SYMBOL_CRC(virtio_transport_stream_has_data, 0x1b85ab86, "_gpl");
SYMBOL_CRC(virtio_transport_seqpacket_has_data, 0x18aafe17, "_gpl");
SYMBOL_CRC(virtio_transport_stream_has_space, 0xd10cbce4, "_gpl");
SYMBOL_CRC(virtio_transport_do_socket_init, 0x2e575bd9, "_gpl");
SYMBOL_CRC(virtio_transport_notify_buffer_size, 0xc1caccbe, "_gpl");
SYMBOL_CRC(virtio_transport_notify_poll_in, 0x17be0799, "_gpl");
SYMBOL_CRC(virtio_transport_notify_poll_out, 0xffcd57ec, "_gpl");
SYMBOL_CRC(virtio_transport_notify_recv_init, 0x5fa905d9, "_gpl");
SYMBOL_CRC(virtio_transport_notify_recv_pre_block, 0xf7e17060, "_gpl");
SYMBOL_CRC(virtio_transport_notify_recv_pre_dequeue, 0x9eb2fce6, "_gpl");
SYMBOL_CRC(virtio_transport_notify_recv_post_dequeue, 0x8f51fe77, "_gpl");
SYMBOL_CRC(virtio_transport_notify_send_init, 0x82f914aa, "_gpl");
SYMBOL_CRC(virtio_transport_notify_send_pre_block, 0x342c5087, "_gpl");
SYMBOL_CRC(virtio_transport_notify_send_pre_enqueue, 0x12b3ccb3, "_gpl");
SYMBOL_CRC(virtio_transport_notify_send_post_enqueue, 0xb479fb8b, "_gpl");
SYMBOL_CRC(virtio_transport_stream_rcvhiwat, 0x4f3bf2ca, "_gpl");
SYMBOL_CRC(virtio_transport_stream_is_active, 0x997d23ea, "_gpl");
SYMBOL_CRC(virtio_transport_stream_allow, 0x03a81e69, "_gpl");
SYMBOL_CRC(virtio_transport_dgram_bind, 0x1349d8d2, "_gpl");
SYMBOL_CRC(virtio_transport_dgram_allow, 0xbabd30f5, "_gpl");
SYMBOL_CRC(virtio_transport_connect, 0xc8402df6, "_gpl");
SYMBOL_CRC(virtio_transport_shutdown, 0x5260695c, "_gpl");
SYMBOL_CRC(virtio_transport_dgram_enqueue, 0x24cfe49c, "_gpl");
SYMBOL_CRC(virtio_transport_stream_enqueue, 0x3150b463, "_gpl");
SYMBOL_CRC(virtio_transport_destruct, 0xf82b8098, "_gpl");
SYMBOL_CRC(virtio_transport_release, 0xb925edb8, "_gpl");
SYMBOL_CRC(virtio_transport_recv_pkt, 0xe55145d7, "_gpl");
SYMBOL_CRC(virtio_transport_free_pkt, 0x421cd04d, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x10a8eebf, "vsock_enqueue_accept" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x4aaa4f3b, "vsock_insert_connected" },
	{ 0xbe888b32, "skb_put" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0xd2a932e7, "vsock_remove_sock" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x5d0cae8f, "vsock_deliver_tap" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0xcc5c2df4, "trace_print_symbols_seq" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0xf5a143f4, "bpf_trace_run8" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x55c18542, "vsock_find_bound_socket" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x3d4b0fca, "vsock_addr_init" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xd0654aba, "woken_wake_function" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xa0552c2d, "sk_free" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x5b75338b, "vsock_stream_has_data" },
	{ 0x86490580, "current_task" },
	{ 0xeb9af979, "vsock_find_connected_socket" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0xb5eb3d0f, "bpf_trace_run10" },
	{ 0xa7db9b36, "vsock_core_get_transport" },
	{ 0xa592e628, "vsock_stream_has_space" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xb308c97d, "wait_woken" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x29cb521e, "vsock_create_connected" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x5924880d, "vsock_assign_transport" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vsock");


MODULE_INFO(srcversion, "1EEE6DF92F445D52FF1FB8F");
