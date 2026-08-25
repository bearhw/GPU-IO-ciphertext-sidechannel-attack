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
	{ 0x2de84993, "virtio_reset_device" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0x1a5cd18a, "virtqueue_add_sgs" },
	{ 0x6b5a92b2, "virtqueue_kick" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa6257a2f, "complete" },
	{ 0x559c47e5, "virtqueue_get_buf" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x800473f, "__cond_resched" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x50b88e65, "virtio_check_driver_offered_feature" },
	{ 0x754d539c, "strlen" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0xd84b9a76, "handle_level_irq" },
	{ 0x21a7b8cd, "gpiochip_remove" },
	{ 0xb481db6, "generic_handle_domain_irq" },
	{ 0x7edf0c62, "register_virtio_driver" },
	{ 0x188e7d5c, "unregister_virtio_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("virtio:d00000029v*");

MODULE_INFO(srcversion, "5132CFDC528E0B4021AC102");
