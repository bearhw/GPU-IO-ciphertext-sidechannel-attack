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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6cee69e8, "i3c_generic_ibi_recycle_slot" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x76fe3e05, "i3c_generic_ibi_free_pool" },
	{ 0x694af998, "i3c_generic_ibi_alloc_pool" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd856bf7, "i3c_master_do_daa" },
	{ 0xfdc0f64c, "i3c_master_disec_locked" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x6c94fa3e, "i3c_master_unregister" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x7ad4242b, "i3c_generic_ibi_get_free_slot" },
	{ 0x223b920c, "i3c_master_queue_ibi" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0x815588a6, "clk_enable" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x9e289f24, "pinctrl_pm_select_default_state" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x6b7080dd, "i3c_master_register" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3a769fb4, "pinctrl_pm_select_sleep_state" },
	{ 0x37a0cba, "kfree" },
	{ 0xbb126c9a, "i3c_master_get_free_addr" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x9033a0c5, "i3c_master_enec_locked" },
	{ 0x556e4390, "clk_get_rate" },
	{ 0x9f4099, "i3c_master_set_info" },
	{ 0xeddeb948, "i3c_master_add_i3c_dev_locked" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xa6257a2f, "complete" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x69acdf38, "memcpy" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xf2b8ed86, "pm_runtime_force_suspend" },
	{ 0x90c0cf4c, "pm_runtime_force_resume" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "i3c");

MODULE_ALIAS("of:N*T*Csilvaco,i3c-master");
MODULE_ALIAS("of:N*T*Csilvaco,i3c-masterC*");

MODULE_INFO(srcversion, "E0D03AAD733A00FEF870D5F");
