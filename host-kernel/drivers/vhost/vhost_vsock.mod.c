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
	{ 0x99dcc22f, "vhost_add_used" },
	{ 0x5fa905d9, "virtio_transport_notify_recv_init" },
	{ 0x5cd4833d, "vhost_init_device_iotlb" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xb925edb8, "virtio_transport_release" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x90aa8549, "vsock_find_cid" },
	{ 0xac69e033, "vhost_vring_ioctl" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xaf06b873, "vsock_for_each_connected_socket" },
	{ 0x9c0b8aeb, "vhost_dev_flush" },
	{ 0xc8402df6, "virtio_transport_connect" },
	{ 0x1b85ab86, "virtio_transport_stream_has_data" },
	{ 0xcda57726, "vhost_vq_access_ok" },
	{ 0xa53ff498, "vhost_dev_stop" },
	{ 0xb7853d06, "vhost_dev_init" },
	{ 0x4f3bf2ca, "virtio_transport_stream_rcvhiwat" },
	{ 0x37a0cba, "kfree" },
	{ 0x4b524cc, "iov_iter_init" },
	{ 0x1349d8d2, "virtio_transport_dgram_bind" },
	{ 0x421cd04d, "virtio_transport_free_pkt" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0xf7e17060, "virtio_transport_notify_recv_pre_block" },
	{ 0x4abe4dbc, "vhost_vq_init_access" },
	{ 0xa909cfc5, "vhost_work_init" },
	{ 0x24cfe49c, "virtio_transport_dgram_enqueue" },
	{ 0x5260695c, "virtio_transport_shutdown" },
	{ 0xdc1784ee, "vhost_exceeds_weight" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xb479fb8b, "virtio_transport_notify_send_post_enqueue" },
	{ 0x81f0eb88, "virtio_transport_dgram_dequeue" },
	{ 0xa23180e9, "vhost_poll_queue" },
	{ 0x3a81e69, "virtio_transport_stream_allow" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x388d2410, "compat_ptr_ioctl" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x82f914aa, "virtio_transport_notify_send_init" },
	{ 0x67908767, "vhost_work_queue" },
	{ 0x51811faf, "vhost_chr_write_iter" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0x12b3ccb3, "virtio_transport_notify_send_pre_enqueue" },
	{ 0x88e9c2ce, "virtio_transport_seqpacket_dequeue" },
	{ 0x96c5445e, "vhost_get_vq_desc" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x383db6a1, "virtio_transport_seqpacket_enqueue" },
	{ 0x18aafe17, "virtio_transport_seqpacket_has_data" },
	{ 0x9eb2fce6, "virtio_transport_notify_recv_pre_dequeue" },
	{ 0x3150b463, "virtio_transport_stream_enqueue" },
	{ 0xbffc55c4, "vhost_chr_read_iter" },
	{ 0x1b160278, "virtio_transport_stream_dequeue" },
	{ 0xd5ab7c1a, "vsock_core_unregister" },
	{ 0x3d9baff6, "vsock_core_register" },
	{ 0x7ded6d97, "vhost_dev_ioctl" },
	{ 0xd1c05ff3, "vhost_signal" },
	{ 0x4708008a, "misc_register" },
	{ 0xb5fc8867, "vhost_disable_notify" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xffcd57ec, "virtio_transport_notify_poll_out" },
	{ 0x8f51fe77, "virtio_transport_notify_recv_post_dequeue" },
	{ 0xbabd30f5, "virtio_transport_dgram_allow" },
	{ 0x3cfcaa3, "vhost_set_backend_features" },
	{ 0x9324fc25, "vhost_enable_notify" },
	{ 0x7b796eea, "virtio_transport_deliver_tap_pkt" },
	{ 0xd60a8eed, "vhost_log_access_ok" },
	{ 0xd14e23b2, "vhost_dev_cleanup" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x997d23ea, "virtio_transport_stream_is_active" },
	{ 0x2e575bd9, "virtio_transport_do_socket_init" },
	{ 0x5e9789cb, "vhost_chr_poll" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x17be0799, "virtio_transport_notify_poll_in" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xd10cbce4, "virtio_transport_stream_has_space" },
	{ 0x342c5087, "virtio_transport_notify_send_pre_block" },
	{ 0xdd69362f, "vq_meta_prefetch" },
	{ 0xe5455ac, "vhost_dev_check_owner" },
	{ 0xc1caccbe, "virtio_transport_notify_buffer_size" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xdf0f75c6, "eventfd_signal" },
	{ 0x7aa1756e, "kvfree" },
	{ 0xf82b8098, "virtio_transport_destruct" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xe55145d7, "virtio_transport_recv_pkt" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vhost,vmw_vsock_virtio_transport_common,vsock");


MODULE_INFO(srcversion, "05CFF3053FD82FCBA5BD996");
