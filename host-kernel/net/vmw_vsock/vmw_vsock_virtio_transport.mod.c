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
	{ 0x7edf0c62, "register_virtio_driver" },
	{ 0x5fa905d9, "virtio_transport_notify_recv_init" },
	{ 0xb925edb8, "virtio_transport_release" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x56f63035, "virtqueue_enable_cb" },
	{ 0xaf06b873, "vsock_for_each_connected_socket" },
	{ 0xf2f97c7c, "virtqueue_detach_unused_buf" },
	{ 0xc8402df6, "virtio_transport_connect" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x1b85ab86, "virtio_transport_stream_has_data" },
	{ 0x4f3bf2ca, "virtio_transport_stream_rcvhiwat" },
	{ 0x37a0cba, "kfree" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0x1349d8d2, "virtio_transport_dgram_bind" },
	{ 0x421cd04d, "virtio_transport_free_pkt" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0xf7e17060, "virtio_transport_notify_recv_pre_block" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x24cfe49c, "virtio_transport_dgram_enqueue" },
	{ 0x5260695c, "virtio_transport_shutdown" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xb479fb8b, "virtio_transport_notify_send_post_enqueue" },
	{ 0x81f0eb88, "virtio_transport_dgram_dequeue" },
	{ 0x188e7d5c, "unregister_virtio_driver" },
	{ 0x3a81e69, "virtio_transport_stream_allow" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x63c3a2a, "virtqueue_get_vring_size" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x82f914aa, "virtio_transport_notify_send_init" },
	{ 0x12b3ccb3, "virtio_transport_notify_send_pre_enqueue" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x88e9c2ce, "virtio_transport_seqpacket_dequeue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x383db6a1, "virtio_transport_seqpacket_enqueue" },
	{ 0x18aafe17, "virtio_transport_seqpacket_has_data" },
	{ 0x9eb2fce6, "virtio_transport_notify_recv_pre_dequeue" },
	{ 0x3150b463, "virtio_transport_stream_enqueue" },
	{ 0xaa85fe5, "virtqueue_disable_cb" },
	{ 0x1b160278, "virtio_transport_stream_dequeue" },
	{ 0xd5ab7c1a, "vsock_core_unregister" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x3d9baff6, "vsock_core_register" },
	{ 0x1a5cd18a, "virtqueue_add_sgs" },
	{ 0x2de84993, "virtio_reset_device" },
	{ 0xffcd57ec, "virtio_transport_notify_poll_out" },
	{ 0x8f51fe77, "virtio_transport_notify_recv_post_dequeue" },
	{ 0xbabd30f5, "virtio_transport_dgram_allow" },
	{ 0x559c47e5, "virtqueue_get_buf" },
	{ 0x7b796eea, "virtio_transport_deliver_tap_pkt" },
	{ 0x6b5a92b2, "virtqueue_kick" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x997d23ea, "virtio_transport_stream_is_active" },
	{ 0xe5a6f947, "virtqueue_add_inbuf" },
	{ 0x2e575bd9, "virtio_transport_do_socket_init" },
	{ 0x17be0799, "virtio_transport_notify_poll_in" },
	{ 0x50b88e65, "virtio_check_driver_offered_feature" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xd10cbce4, "virtio_transport_stream_has_space" },
	{ 0x342c5087, "virtio_transport_notify_send_pre_block" },
	{ 0xc1caccbe, "virtio_transport_notify_buffer_size" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xf82b8098, "virtio_transport_destruct" },
	{ 0xe55145d7, "virtio_transport_recv_pkt" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vmw_vsock_virtio_transport_common,vsock");

MODULE_ALIAS("virtio:d00000013v*");

MODULE_INFO(srcversion, "65929CF75D4FEC20674D942");
