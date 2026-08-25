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
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x421cd04d, "virtio_transport_free_pkt" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7b796eea, "virtio_transport_deliver_tap_pkt" },
	{ 0xe55145d7, "virtio_transport_recv_pkt" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x3d9baff6, "vsock_core_register" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xd5ab7c1a, "vsock_core_unregister" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x2e575bd9, "virtio_transport_do_socket_init" },
	{ 0xf82b8098, "virtio_transport_destruct" },
	{ 0xb925edb8, "virtio_transport_release" },
	{ 0xc8402df6, "virtio_transport_connect" },
	{ 0x1349d8d2, "virtio_transport_dgram_bind" },
	{ 0x81f0eb88, "virtio_transport_dgram_dequeue" },
	{ 0x24cfe49c, "virtio_transport_dgram_enqueue" },
	{ 0xbabd30f5, "virtio_transport_dgram_allow" },
	{ 0x1b160278, "virtio_transport_stream_dequeue" },
	{ 0x3150b463, "virtio_transport_stream_enqueue" },
	{ 0x1b85ab86, "virtio_transport_stream_has_data" },
	{ 0xd10cbce4, "virtio_transport_stream_has_space" },
	{ 0x4f3bf2ca, "virtio_transport_stream_rcvhiwat" },
	{ 0x997d23ea, "virtio_transport_stream_is_active" },
	{ 0x3a81e69, "virtio_transport_stream_allow" },
	{ 0x88e9c2ce, "virtio_transport_seqpacket_dequeue" },
	{ 0x383db6a1, "virtio_transport_seqpacket_enqueue" },
	{ 0x18aafe17, "virtio_transport_seqpacket_has_data" },
	{ 0x17be0799, "virtio_transport_notify_poll_in" },
	{ 0xffcd57ec, "virtio_transport_notify_poll_out" },
	{ 0x5fa905d9, "virtio_transport_notify_recv_init" },
	{ 0xf7e17060, "virtio_transport_notify_recv_pre_block" },
	{ 0x9eb2fce6, "virtio_transport_notify_recv_pre_dequeue" },
	{ 0x8f51fe77, "virtio_transport_notify_recv_post_dequeue" },
	{ 0x82f914aa, "virtio_transport_notify_send_init" },
	{ 0x342c5087, "virtio_transport_notify_send_pre_block" },
	{ 0x12b3ccb3, "virtio_transport_notify_send_pre_enqueue" },
	{ 0xb479fb8b, "virtio_transport_notify_send_post_enqueue" },
	{ 0xc1caccbe, "virtio_transport_notify_buffer_size" },
	{ 0x5260695c, "virtio_transport_shutdown" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vmw_vsock_virtio_transport_common,vsock");


MODULE_INFO(srcversion, "41A01488BD9B33EB91C6BC9");
