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
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x67c3268b, "slim_do_transfer" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x5ea191c, "slim_ctrl_clk_pause" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0x69acdf38, "memcpy" },
	{ 0xfcec0987, "enable_irq" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x8f2b0c85, "slim_register_controller" },
	{ 0xd7d18c4, "platform_get_resource_byname" },
	{ 0x76d9b876, "clk_set_rate" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0xbf72cdba, "slim_msg_response" },
	{ 0x9cf37c44, "__iowrite32_copy" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x3801776b, "__ioread32_copy" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x56cfb72a, "devm_platform_ioremap_resource_byname" },
	{ 0xec04e37a, "slim_unregister_controller" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0xbac257df, "slim_device_report_present" },
	{ 0x6902f204, "devm_ioremap_resource" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x815588a6, "clk_enable" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "slimbus");


MODULE_INFO(srcversion, "40AF87D2727429EB4FE2D73");
