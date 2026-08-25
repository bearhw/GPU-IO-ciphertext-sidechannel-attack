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
	{ 0x7b9ddaa8, "sdhci_end_tuning" },
	{ 0xbbe839b2, "pci_save_state" },
	{ 0x38989072, "sdhci_set_bus_width" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x611b7ba7, "sdhci_send_tuning" },
	{ 0x868292f2, "sdhci_cqe_irq" },
	{ 0xbcc0ab5f, "sdhci_start_signal_voltage_switch" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x46083359, "mmc_gpiod_request_cd" },
	{ 0xb31c7751, "cqhci_init" },
	{ 0xd5c36791, "dev_pm_qos_expose_latency_tolerance" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0xf110992b, "pci_get_device" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc2e55ce, "sdhci_set_uhs_signaling" },
	{ 0xd014e30e, "cqhci_irq" },
	{ 0x37a0cba, "kfree" },
	{ 0xba06f8f2, "sdhci_reset" },
	{ 0x5d54d3b2, "sdhci_calc_clk" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xdf4256c0, "sdhci_enable_clk" },
	{ 0x1bfe1491, "pci_set_power_state" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0x7b508db1, "mmc_gpio_set_cd_wake" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x86c7272b, "iosf_mbi_read" },
	{ 0x18a35528, "device_property_read_u32_array" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x2587f789, "_dev_info" },
	{ 0x7a88da87, "iosf_mbi_write" },
	{ 0xa3bfb7e5, "mmc_gpio_get_cd" },
	{ 0xc08571f3, "sdhci_suspend_host" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x71a18456, "device_wakeup_disable" },
	{ 0x800473f, "__cond_resched" },
	{ 0x82d4f86b, "pci_find_capability" },
	{ 0x66a62249, "sdhci_runtime_resume_host" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0xaaa78c1b, "pci_clear_master" },
	{ 0xae5a04bb, "acpi_evaluate_dsm" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x3830ce15, "sdhci_runtime_suspend_host" },
	{ 0xd7fea2a8, "device_wakeup_enable" },
	{ 0x68746a00, "device_init_wakeup" },
	{ 0xdf1759f7, "sdhci_setup_host" },
	{ 0x9e47fcd5, "sdhci_dumpregs" },
	{ 0xa78a4ca1, "sdhci_cqe_disable" },
	{ 0xd4bc3b29, "__sdhci_add_host" },
	{ 0x32e55547, "sdhci_reset_tuning" },
	{ 0x6e43b44f, "sdhci_abort_tuning" },
	{ 0xbbf0b873, "pci_restore_state" },
	{ 0xa75e4ca7, "sdhci_set_clock" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x98044ffc, "sdhci_start_tuning" },
	{ 0xec8589b7, "sdhci_execute_tuning" },
	{ 0xa13544d8, "cqhci_deactivate" },
	{ 0x9b1b5206, "sdhci_free_host" },
	{ 0x7775af29, "sdhci_add_host" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0x78ddb76b, "dmi_match" },
	{ 0xbfa519c3, "acpi_device_fix_up_power" },
	{ 0xfe51e012, "pm_runtime_allow" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0xa5389eb1, "debugfs_create_x32" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x4a0766b1, "dev_pm_qos_hide_latency_tolerance" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xa2a539fa, "sdhci_cleanup_host" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xaebd384b, "sdhci_resume_host" },
	{ 0x145a1091, "sdhci_alloc_host" },
	{ 0x988f01d7, "mmc_send_tuning" },
	{ 0x2c62d5eb, "sdhci_cqe_enable" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0xb495aac3, "__pm_runtime_suspend" },
	{ 0xfe1eb5ba, "sdhci_get_cd_nogpio" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x735e6a81, "acpi_evaluate_integer" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xd1b569d4, "pci_free_irq_vectors" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x17866bc6, "sdhci_set_power" },
	{ 0xf9a482f9, "msleep" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0x688a7f13, "sdhci_remove_host" },
	{ 0x49b3544b, "sdhci_enable_v4_mode" },
	{ 0xfd85c6b3, "cqhci_resume" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sdhci,cqhci");

MODULE_ALIAS("pci:v00001180d00000822sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001180d00000843sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001180d0000E822sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001180d0000E823sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001524d00000550sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001524d00000551sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001524d00000750sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001524d00000751sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000011ABd00004101sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000197Bd00002381sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000197Bd00002382sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000197Bd00002391sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000197Bd00002392sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001148d00008000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001106d000095D0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000010ECd00005250sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000008A7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000807sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000808sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000084Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000820sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000821sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000822sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000823sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000824sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00008809sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000880Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000F14sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000F15sv00001093sd00007884bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000F15sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000F16sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000F50sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002294sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002295sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00002296sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000008F9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000008FAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000008FBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000008E5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000008E6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001190sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009D2Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009D2Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009D2Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000019DBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000018DBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000ACCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000AD0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000ACAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001ACCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001AD0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001ACAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00005ACCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00005AD0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00005ACAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000031CCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000031D0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000031CAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009DC4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00009DF5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000A375sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000034C4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000034F8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004B47sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004B48sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000002C4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000002F5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000006F5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004DC4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00004DF8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000098C4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000098F8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000054C4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001217d00008120sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001217d00008220sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001217d00008221sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001217d00008320sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001217d00008321sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001217d00008520sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001217d00008420sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001217d00008421sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001217d00008620sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001217d00008621sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000016E6d00000670sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000016C3d0000C202sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000017A0d00009750sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000017A0d00009755sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v000017A0d0000E763sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001022d*sv*sd*bc08sc05i*");
MODULE_ALIAS("pci:v*d*sv*sd*bc08sc05i*");

MODULE_INFO(srcversion, "0388BD21BAECC7A9229967E");
