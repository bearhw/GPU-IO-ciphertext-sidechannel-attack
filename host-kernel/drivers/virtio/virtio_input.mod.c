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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x37a0cba, "kfree" },
	{ 0x559c47e5, "virtqueue_get_buf" },
	{ 0x84ddca63, "input_unregister_device" },
	{ 0x2de84993, "virtio_reset_device" },
	{ 0xf2f97c7c, "virtqueue_detach_unused_buf" },
	{ 0x800473f, "__cond_resched" },
	{ 0xc2261e62, "input_event" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0xe5a6f947, "virtqueue_add_inbuf" },
	{ 0x6b5a92b2, "virtqueue_kick" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x56c0046e, "virtqueue_add_outbuf" },
	{ 0x63c3a2a, "virtqueue_get_vring_size" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x3da716bf, "input_allocate_device" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xd5a679cf, "input_set_abs_params" },
	{ 0x8b19fc7a, "input_alloc_absinfo" },
	{ 0x86721907, "input_mt_init_slots" },
	{ 0xaddf64b0, "input_register_device" },
	{ 0xe42878c7, "input_free_device" },
	{ 0x7edf0c62, "register_virtio_driver" },
	{ 0x188e7d5c, "unregister_virtio_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("virtio:d00000012v*");

MODULE_INFO(srcversion, "E79A9C8E17FC9AC49D912A8");
