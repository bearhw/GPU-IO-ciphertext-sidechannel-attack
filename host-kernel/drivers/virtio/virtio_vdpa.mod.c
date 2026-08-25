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
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x41f0ba5f, "unregister_virtio_device" },
	{ 0x37a0cba, "kfree" },
	{ 0xd40569bb, "vring_transport_features" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xbaeefe9d, "vring_del_virtqueue" },
	{ 0x214ec32e, "virtio_config_changed" },
	{ 0xff05fa13, "vring_interrupt" },
	{ 0x38ed7cee, "vdpa_set_status" },
	{ 0xf727c217, "vdpa_set_config" },
	{ 0x732207b7, "vdpa_get_config" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbd9fc993, "vring_create_virtqueue" },
	{ 0x63c3a2a, "virtqueue_get_vring_size" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x9e74ab5a, "virtqueue_get_desc_addr" },
	{ 0x88834a5d, "virtqueue_get_avail_addr" },
	{ 0x95cc38c8, "virtqueue_get_used_addr" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x8701d4e1, "register_virtio_device" },
	{ 0x3197c4e3, "put_device" },
	{ 0x37cee29e, "__vdpa_register_driver" },
	{ 0xc23532a7, "vdpa_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "vdpa");


MODULE_INFO(srcversion, "130BC16136D00BE799560D2");
