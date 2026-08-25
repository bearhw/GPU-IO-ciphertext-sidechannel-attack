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
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x37a0cba, "kfree" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x92997ed8, "_printk" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0x364bd292, "vme_irq_handler" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x27352a9d, "__root_device_register" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x2364c85a, "tasklet_init" },
	{ 0xca2f0dd4, "vme_register_bridge" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x36046213, "vme_unregister_bridge" },
	{ 0x1c6dbfe, "root_device_unregister" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A0CA88C327A875AEC97867E");
