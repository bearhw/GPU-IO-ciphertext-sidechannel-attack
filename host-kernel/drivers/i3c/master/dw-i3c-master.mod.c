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
	{ 0x6c94fa3e, "i3c_master_unregister" },
	{ 0x6c4b6684, "reset_control_assert" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x37a0cba, "kfree" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x556e4390, "clk_get_rate" },
	{ 0xbb126c9a, "i3c_master_get_free_addr" },
	{ 0x9f4099, "i3c_master_set_info" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x63526f4c, "__devm_reset_control_get" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0x815588a6, "clk_enable" },
	{ 0xb2210d64, "reset_control_deassert" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x6b7080dd, "i3c_master_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa6257a2f, "complete" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0xeddeb948, "i3c_master_add_i3c_dev_locked" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "i3c");

MODULE_ALIAS("of:N*T*Csnps,dw-i3c-master-1.00a");
MODULE_ALIAS("of:N*T*Csnps,dw-i3c-master-1.00aC*");

MODULE_INFO(srcversion, "942E431B16BF601534A91C2");
