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
	{ 0xcaff6dc5, "vmbus_driver_unregister" },
	{ 0x10a8eebf, "vsock_enqueue_accept" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0x4aaa4f3b, "vsock_insert_connected" },
	{ 0x4b2210b8, "vmbus_send_tl_connect_request" },
	{ 0xd2a932e7, "vsock_remove_sock" },
	{ 0x2fd90375, "vmbus_sendpacket" },
	{ 0x530b2628, "hv_pkt_iter_first" },
	{ 0x37a0cba, "kfree" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xa3afc2c1, "vmbus_close" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x55c18542, "vsock_find_bound_socket" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0x3d4b0fca, "vsock_addr_init" },
	{ 0x77f9ae61, "vmbus_open" },
	{ 0xa0552c2d, "sk_free" },
	{ 0xd5ab7c1a, "vsock_core_unregister" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x46a417ca, "vmbus_proto_version" },
	{ 0x5b75338b, "vsock_stream_has_data" },
	{ 0x3d9baff6, "vsock_core_register" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xbd88cc07, "hv_pkt_iter_close" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x79510029, "vmbus_set_chn_rescind_callback" },
	{ 0x8f4947c8, "__vmbus_driver_register" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0x29cb521e, "vsock_create_connected" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x5924880d, "vsock_assign_transport" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0xd048f90f, "__hv_pkt_iter_next" },
	{ 0x8d0809, "vmbus_hvsock_device_unregister" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "hv_vmbus,vsock");


MODULE_INFO(srcversion, "2B4050135306E1A9B804479");
