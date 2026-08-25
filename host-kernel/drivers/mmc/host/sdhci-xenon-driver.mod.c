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
	{ 0xbb726018, "device_property_present" },
	{ 0x38989072, "sdhci_set_bus_width" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xbcc0ab5f, "sdhci_start_signal_voltage_switch" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0xba06f8f2, "sdhci_reset" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0xed3ef16f, "sdhci_pltfm_free" },
	{ 0xc04a3d34, "mmc_regulator_set_ocr" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x66a62249, "sdhci_runtime_resume_host" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x3830ce15, "sdhci_runtime_suspend_host" },
	{ 0x6dfa11a2, "sdhci_set_ios" },
	{ 0xb0c47761, "device_property_read_string" },
	{ 0x61cb6be1, "sdhci_get_property" },
	{ 0xa75e4ca7, "sdhci_set_clock" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x9c90d539, "device_get_match_data" },
	{ 0xec8589b7, "sdhci_execute_tuning" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x7775af29, "sdhci_add_host" },
	{ 0x7e1899ad, "sdhci_pltfm_clk_get_max_clock" },
	{ 0x7a91a460, "mmc_of_parse" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x71e4b866, "sdhci_enable_sdio_irq" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x90c0cf4c, "pm_runtime_force_resume" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x44c9d482, "sdhci_set_power_noreg" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0x2ab86846, "sdhci_pltfm_init" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0x81188c30, "match_string" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x815588a6, "clk_enable" },
	{ 0xf2b8ed86, "pm_runtime_force_suspend" },
	{ 0x688a7f13, "sdhci_remove_host" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sdhci,sdhci-pltfm");

MODULE_ALIAS("acpi*:MRVL0002:*");
MODULE_ALIAS("acpi*:MRVL0003:*");
MODULE_ALIAS("acpi*:MRVL0004:*");
MODULE_ALIAS("of:N*T*Cmarvell,armada-ap806-sdhci");
MODULE_ALIAS("of:N*T*Cmarvell,armada-ap806-sdhciC*");
MODULE_ALIAS("of:N*T*Cmarvell,armada-ap807-sdhci");
MODULE_ALIAS("of:N*T*Cmarvell,armada-ap807-sdhciC*");
MODULE_ALIAS("of:N*T*Cmarvell,armada-cp110-sdhci");
MODULE_ALIAS("of:N*T*Cmarvell,armada-cp110-sdhciC*");
MODULE_ALIAS("of:N*T*Cmarvell,armada-3700-sdhci");
MODULE_ALIAS("of:N*T*Cmarvell,armada-3700-sdhciC*");

MODULE_INFO(srcversion, "6908F1AB0B480414AB55EAA");
