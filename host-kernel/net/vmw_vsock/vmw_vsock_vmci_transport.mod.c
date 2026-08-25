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
	{ 0x10a8eebf, "vsock_enqueue_accept" },
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0xde3abc2e, "vmci_datagram_create_handle_priv" },
	{ 0x5591b58e, "vmci_context_get_priv_flags" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x4aaa4f3b, "vsock_insert_connected" },
	{ 0x1fd4782d, "vmci_qpair_get_produce_indexes" },
	{ 0x7c74d7a6, "vmci_qpair_consume_buf_ready" },
	{ 0xbe888b32, "skb_put" },
	{ 0xaf06b873, "vsock_for_each_connected_socket" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x3a22fa8a, "vmci_datagram_destroy_handle" },
	{ 0xd2a932e7, "vsock_remove_sock" },
	{ 0x69acdf38, "memcpy" },
	{ 0xea61eefe, "vmci_qpair_produce_buf_ready" },
	{ 0x37a0cba, "kfree" },
	{ 0x2449459d, "vmci_event_subscribe" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xea143610, "vmci_datagram_send" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x7257feca, "vsock_remove_connected" },
	{ 0x55c18542, "vsock_find_bound_socket" },
	{ 0x92997ed8, "_printk" },
	{ 0x24d14bc, "vmci_qpair_produce_free_space" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x3d4b0fca, "vsock_addr_init" },
	{ 0xdd733bbb, "vsock_remove_pending" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x4b99648c, "vsock_addr_bound" },
	{ 0xc6cbbc89, "capable" },
	{ 0x948dbf5a, "__sk_receive_skb" },
	{ 0xc04c7e84, "vmci_qpair_get_consume_indexes" },
	{ 0xa0552c2d, "sk_free" },
	{ 0xaf2674b5, "vsock_addr_equals_addr" },
	{ 0x676bd843, "vmci_qpair_consume_free_space" },
	{ 0xd5ab7c1a, "vsock_core_unregister" },
	{ 0x5f8681ef, "vmci_qpair_peekv" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xc403cafe, "vmci_is_context_owner" },
	{ 0x46dd187, "vmci_datagram_create_handle" },
	{ 0x5b75338b, "vsock_stream_has_data" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x3d9baff6, "vsock_core_register" },
	{ 0xe0cc9c92, "vmci_qpair_alloc" },
	{ 0x787f0fe8, "vmci_register_vsock_callback" },
	{ 0xeb9af979, "vsock_find_connected_socket" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa592e628, "vsock_stream_has_space" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x612df9ae, "vmci_qpair_detach" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0xb44254fd, "vmci_qpair_dequev" },
	{ 0xedfd14cf, "vsock_add_pending" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xc2443b63, "vmci_qpair_enquev" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x29cb521e, "vsock_create_connected" },
	{ 0xe11895c1, "vmci_event_unsubscribe" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x5924880d, "vsock_assign_transport" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0x56837fb, "vmci_get_context_id" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vsock,vmw_vmci");


MODULE_INFO(srcversion, "0A9BFEBF97B38C9AA9139E3");
