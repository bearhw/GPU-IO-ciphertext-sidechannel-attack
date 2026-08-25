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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(ahci_ignore_sss, 0xea50dad3, "_gpl");
SYMBOL_CRC(ahci_shost_groups, 0xfec4464e, "_gpl");
SYMBOL_CRC(ahci_sdev_groups, 0xe403dd30, "_gpl");
SYMBOL_CRC(ahci_ops, 0x9bf952f4, "_gpl");
SYMBOL_CRC(ahci_pmp_retry_srst_ops, 0xdd9f8497, "_gpl");
SYMBOL_CRC(ahci_save_initial_config, 0xb9ed2d3a, "_gpl");
SYMBOL_CRC(ahci_start_engine, 0xdb4e5887, "_gpl");
SYMBOL_CRC(ahci_stop_engine, 0x2da93111, "_gpl");
SYMBOL_CRC(ahci_start_fis_rx, 0xb5dd2474, "_gpl");
SYMBOL_CRC(ahci_reset_controller, 0x18825c8b, "_gpl");
SYMBOL_CRC(ahci_reset_em, 0xf2ce5b92, "_gpl");
SYMBOL_CRC(ahci_init_controller, 0x0c9f1ef1, "_gpl");
SYMBOL_CRC(ahci_dev_classify, 0xb27ecd22, "_gpl");
SYMBOL_CRC(ahci_fill_cmd_slot, 0x517de13f, "_gpl");
SYMBOL_CRC(ahci_kick_engine, 0x6639133b, "_gpl");
SYMBOL_CRC(ahci_check_ready, 0x8ba6d583, "_gpl");
SYMBOL_CRC(ahci_do_softreset, 0x17455f86, "_gpl");
SYMBOL_CRC(ahci_do_hardreset, 0x941b8840, "_gpl");
SYMBOL_CRC(ahci_handle_port_intr, 0x6d12a30d, "_gpl");
SYMBOL_CRC(ahci_qc_issue, 0x67dc9420, "_gpl");
SYMBOL_CRC(ahci_error_handler, 0x81e887d7, "_gpl");
SYMBOL_CRC(ahci_port_resume, 0x25c2ae69, "_gpl");
SYMBOL_CRC(ahci_print_info, 0x09ab89f8, "_gpl");
SYMBOL_CRC(ahci_set_em_messages, 0x1c496d9e, "_gpl");
SYMBOL_CRC(ahci_host_activate, 0xb6e9da2d, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x6128b5fc, "__printk_ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x96c7964e, "ata_link_next" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x999436a, "ata_wait_register" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9b13ca59, "ata_dev_set_feature" },
	{ 0x1157c11c, "sata_link_scr_lpm" },
	{ 0xf5b49047, "ata_msleep" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x906b8ac5, "ata_std_postreset" },
	{ 0xf9a482f9, "msleep" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x3e952a00, "ata_port_classify" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xa2e251fd, "sata_pmp_error_handler" },
	{ 0x9f3916d3, "ata_host_start" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x6d435d09, "ata_port_desc" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x443a89a, "ata_host_register" },
	{ 0xd256f811, "ata_host_activate" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa4c085f8, "ata_tf_from_fis" },
	{ 0xe9c8768a, "ata_std_qc_defer" },
	{ 0xbe58a932, "sata_pmp_qc_defer_cmd_switch" },
	{ 0xc03ebe7f, "ata_dummy_port_ops" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x44ce4eb, "acpi_storage_d3" },
	{ 0x42635d55, "pm_suspend_global_flags" },
	{ 0xbb2509b2, "ata_port_freeze" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x3943995e, "dmam_alloc_attrs" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0xcccfb2fa, "sata_deb_timing_hotplug" },
	{ 0x4fdc945d, "sata_deb_timing_normal" },
	{ 0xdf0c757f, "ata_tf_to_fis" },
	{ 0xc094da0a, "sata_link_hardreset" },
	{ 0xb8e53f5e, "ata_wait_after_reset" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x69acdf38, "memcpy" },
	{ 0x87b8798d, "sg_next" },
	{ 0xd3474e88, "sata_lpm_ignore_phy_events" },
	{ 0x3914ae2c, "ata_qc_complete_multiple" },
	{ 0x624ad0d2, "sata_async_notification" },
	{ 0x5899aa85, "ata_ehi_clear_desc" },
	{ 0x973f082a, "ata_ehi_push_desc" },
	{ 0x85d3140e, "ata_link_abort" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x62f4d6d5, "ata_port_abort" },
	{ 0xf8f3a0fb, "ata_ratelimit" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x53a9a01e, "sata_pmp_port_ops" },
	{ 0x12fe6f58, "dev_attr_sw_activity" },
	{ 0xaf6c1985, "dev_attr_unload_heads" },
	{ 0x6d84707f, "dev_attr_ncq_prio_supported" },
	{ 0x56febec2, "dev_attr_ncq_prio_enable" },
	{ 0xdf20377, "dev_attr_link_power_management_policy" },
	{ 0x8edd7911, "dev_attr_em_message_type" },
	{ 0xb5377074, "dev_attr_em_message" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9FA4335B9B989C263D18BB5");
