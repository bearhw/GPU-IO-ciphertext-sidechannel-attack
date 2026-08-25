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
	{ 0xcea381dd, "x86_match_cpu" },
	{ 0x86c7272b, "iosf_mbi_read" },
	{ 0x7a88da87, "iosf_mbi_write" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x66a62249, "sdhci_runtime_resume_host" },
	{ 0xaebd384b, "sdhci_resume_host" },
	{ 0x859b921d, "__sdhci_read_caps" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x9cf2f83b, "acpi_dev_hid_uid_match" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xa3bfb7e5, "mmc_gpio_get_cd" },
	{ 0xfe1eb5ba, "sdhci_get_cd_nogpio" },
	{ 0x50877b9, "dmi_first_match" },
	{ 0xbfa519c3, "acpi_device_fix_up_power" },
	{ 0x28e09af1, "iosf_mbi_available" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x77358855, "iomem_resource" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x145a1091, "sdhci_alloc_host" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x46083359, "mmc_gpiod_request_cd" },
	{ 0xdf1759f7, "sdhci_setup_host" },
	{ 0xd4bc3b29, "__sdhci_add_host" },
	{ 0x9b1b5206, "sdhci_free_host" },
	{ 0xa2a539fa, "sdhci_cleanup_host" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xec8589b7, "sdhci_execute_tuning" },
	{ 0xae5a04bb, "acpi_evaluate_dsm" },
	{ 0x37a0cba, "kfree" },
	{ 0x3830ce15, "sdhci_runtime_suspend_host" },
	{ 0xc08571f3, "sdhci_suspend_host" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xbcc0ab5f, "sdhci_start_signal_voltage_switch" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x688a7f13, "sdhci_remove_host" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0xba06f8f2, "sdhci_reset" },
	{ 0x6dfa11a2, "sdhci_set_ios" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xa75e4ca7, "sdhci_set_clock" },
	{ 0x38989072, "sdhci_set_bus_width" },
	{ 0xc2e55ce, "sdhci_set_uhs_signaling" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sdhci");

MODULE_ALIAS("acpi*:80865ACA:*");
MODULE_ALIAS("acpi*:80865ACC:*");
MODULE_ALIAS("acpi*:80865AD0:*");
MODULE_ALIAS("acpi*:80860F14:*");
MODULE_ALIAS("acpi*:80860F16:*");
MODULE_ALIAS("acpi*:INT33BB:*");
MODULE_ALIAS("acpi*:INT33C6:*");
MODULE_ALIAS("acpi*:INT3436:*");
MODULE_ALIAS("acpi*:INT344D:*");
MODULE_ALIAS("acpi*:PNP0D40:*");
MODULE_ALIAS("acpi*:QCOM8051:*");
MODULE_ALIAS("acpi*:QCOM8052:*");
MODULE_ALIAS("acpi*:AMDI0040:*");
MODULE_ALIAS("acpi*:AMDI0041:*");

MODULE_INFO(srcversion, "0F1F21A57C52DA537078EE1");
