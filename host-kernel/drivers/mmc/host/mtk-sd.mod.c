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
	{ 0xb43f9365, "ktime_get" },
	{ 0x90c0cf4c, "pm_runtime_force_resume" },
	{ 0xa13544d8, "cqhci_deactivate" },
	{ 0xf2b8ed86, "pm_runtime_force_suspend" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x596e66f6, "mmc_regulator_set_vqmmc" },
	{ 0xbd44d6b9, "pinctrl_select_state" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa3bfb7e5, "mmc_gpio_get_cd" },
	{ 0x479f7d4b, "clk_bulk_disable" },
	{ 0x63c08029, "clk_bulk_unprepare" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0xc4682d1d, "sdio_signal_irq" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0xead5c8e5, "clk_bulk_prepare" },
	{ 0x815588a6, "clk_enable" },
	{ 0xc7a7e770, "clk_bulk_enable" },
	{ 0x800473f, "__cond_resched" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xf74bb274, "mod_delayed_work_on" },
	{ 0x87b8798d, "sg_next" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0xd014e30e, "cqhci_irq" },
	{ 0xa361a674, "mmc_get_ext_csd" },
	{ 0x37a0cba, "kfree" },
	{ 0x2587f789, "_dev_info" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6c4b6684, "reset_control_assert" },
	{ 0xb2210d64, "reset_control_deassert" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0x7a91a460, "mmc_of_parse" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x6902f204, "devm_ioremap_resource" },
	{ 0x74f6e487, "mmc_regulator_get_supply" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x506741f6, "devm_clk_get_optional" },
	{ 0xe63e70c4, "devm_clk_bulk_get_optional" },
	{ 0x63526f4c, "__devm_reset_control_get" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0xf3a92611, "devm_pinctrl_get" },
	{ 0x3bfed546, "pinctrl_lookup_state" },
	{ 0x556e4390, "clk_get_rate" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xfb578fc5, "memset" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xb31c7751, "cqhci_init" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0x63150e06, "clk_get_parent" },
	{ 0xaa331e5c, "mmc_can_gpio_cd" },
	{ 0xc04a3d34, "mmc_regulator_set_ocr" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x988f01d7, "mmc_send_tuning" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x13a52dda, "mmc_gpio_get_ro" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cqhci");

MODULE_ALIAS("of:N*T*Cmediatek,mt8135-mmc");
MODULE_ALIAS("of:N*T*Cmediatek,mt8135-mmcC*");
MODULE_ALIAS("of:N*T*Cmediatek,mt8173-mmc");
MODULE_ALIAS("of:N*T*Cmediatek,mt8173-mmcC*");
MODULE_ALIAS("of:N*T*Cmediatek,mt8183-mmc");
MODULE_ALIAS("of:N*T*Cmediatek,mt8183-mmcC*");
MODULE_ALIAS("of:N*T*Cmediatek,mt2701-mmc");
MODULE_ALIAS("of:N*T*Cmediatek,mt2701-mmcC*");
MODULE_ALIAS("of:N*T*Cmediatek,mt2712-mmc");
MODULE_ALIAS("of:N*T*Cmediatek,mt2712-mmcC*");
MODULE_ALIAS("of:N*T*Cmediatek,mt7622-mmc");
MODULE_ALIAS("of:N*T*Cmediatek,mt7622-mmcC*");
MODULE_ALIAS("of:N*T*Cmediatek,mt8516-mmc");
MODULE_ALIAS("of:N*T*Cmediatek,mt8516-mmcC*");
MODULE_ALIAS("of:N*T*Cmediatek,mt7620-mmc");
MODULE_ALIAS("of:N*T*Cmediatek,mt7620-mmcC*");
MODULE_ALIAS("of:N*T*Cmediatek,mt6779-mmc");
MODULE_ALIAS("of:N*T*Cmediatek,mt6779-mmcC*");

MODULE_INFO(srcversion, "6CC3418D32BF01BD5D3E077");
