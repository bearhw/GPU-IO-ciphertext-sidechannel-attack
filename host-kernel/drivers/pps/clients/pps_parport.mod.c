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
	{ 0xe2d5255a, "strcmp" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6450e28b, "pps_unregister_source" },
	{ 0x8b73974d, "parport_release" },
	{ 0x41e3ce24, "parport_unregister_device" },
	{ 0xffb7c514, "ida_free" },
	{ 0x37a0cba, "kfree" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0xd4c28eac, "parport_register_dev_model" },
	{ 0x61cfa6a2, "parport_claim_or_block" },
	{ 0x4af699f6, "pps_register_source" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4cb27100, "ktime_get_snapshot" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0x6d606913, "pv_ops" },
	{ 0x48bb1255, "pps_event" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xefbd5788, "__parport_register_driver" },
	{ 0x938e02c5, "parport_unregister_driver" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "parport");


MODULE_INFO(srcversion, "914C52901581BDA239CFE93");
