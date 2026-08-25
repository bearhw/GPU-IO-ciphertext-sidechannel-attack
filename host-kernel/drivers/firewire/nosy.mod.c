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
	{ 0x69acdf38, "memcpy" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x800473f, "__cond_resched" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x95316761, "dma_set_mask" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xde80cd09, "ioremap" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4708008a, "misc_register" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xedc03953, "iounmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x7ec6993, "stream_open" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6d606913, "pv_ops" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x9ec6ca96, "ktime_get_real_ts64" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v0000104Cd00008000sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "B84B17356928BF9B428F894");
