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

SYMBOL_CRC(sdhci_dumpregs, 0x9e47fcd5, "_gpl");
SYMBOL_CRC(sdhci_enable_v4_mode, 0x49b3544b, "_gpl");
SYMBOL_CRC(sdhci_reset, 0xba06f8f2, "_gpl");
SYMBOL_CRC(sdhci_adma_write_desc, 0xba01d2d6, "_gpl");
SYMBOL_CRC(sdhci_set_data_timeout_irq, 0x59623d37, "_gpl");
SYMBOL_CRC(__sdhci_set_timeout, 0xe8a1e935, "_gpl");
SYMBOL_CRC(sdhci_switch_external_dma, 0x72302832, "_gpl");
SYMBOL_CRC(sdhci_calc_clk, 0x5d54d3b2, "_gpl");
SYMBOL_CRC(sdhci_enable_clk, 0xdf4256c0, "_gpl");
SYMBOL_CRC(sdhci_set_clock, 0xa75e4ca7, "_gpl");
SYMBOL_CRC(sdhci_set_power_noreg, 0x44c9d482, "_gpl");
SYMBOL_CRC(sdhci_set_power, 0x17866bc6, "_gpl");
SYMBOL_CRC(sdhci_set_power_and_bus_voltage, 0x8cf1b8b9, "_gpl");
SYMBOL_CRC(sdhci_request, 0x2eb6f4e6, "_gpl");
SYMBOL_CRC(sdhci_request_atomic, 0xe6e6b8b5, "_gpl");
SYMBOL_CRC(sdhci_set_bus_width, 0x38989072, "_gpl");
SYMBOL_CRC(sdhci_set_uhs_signaling, 0x0c2e55ce, "_gpl");
SYMBOL_CRC(sdhci_set_ios, 0x6dfa11a2, "_gpl");
SYMBOL_CRC(sdhci_get_cd_nogpio, 0xfe1eb5ba, "_gpl");
SYMBOL_CRC(sdhci_enable_sdio_irq, 0x71e4b866, "_gpl");
SYMBOL_CRC(sdhci_start_signal_voltage_switch, 0xbcc0ab5f, "_gpl");
SYMBOL_CRC(sdhci_start_tuning, 0x98044ffc, "_gpl");
SYMBOL_CRC(sdhci_end_tuning, 0x7b9ddaa8, "_gpl");
SYMBOL_CRC(sdhci_reset_tuning, 0x32e55547, "_gpl");
SYMBOL_CRC(sdhci_abort_tuning, 0x6e43b44f, "_gpl");
SYMBOL_CRC(sdhci_send_tuning, 0x611b7ba7, "_gpl");
SYMBOL_CRC(sdhci_execute_tuning, 0xec8589b7, "_gpl");
SYMBOL_CRC(sdhci_suspend_host, 0xc08571f3, "_gpl");
SYMBOL_CRC(sdhci_resume_host, 0xaebd384b, "_gpl");
SYMBOL_CRC(sdhci_runtime_suspend_host, 0x3830ce15, "_gpl");
SYMBOL_CRC(sdhci_runtime_resume_host, 0x66a62249, "_gpl");
SYMBOL_CRC(sdhci_cqe_enable, 0x2c62d5eb, "_gpl");
SYMBOL_CRC(sdhci_cqe_disable, 0xa78a4ca1, "_gpl");
SYMBOL_CRC(sdhci_cqe_irq, 0x868292f2, "_gpl");
SYMBOL_CRC(sdhci_alloc_host, 0x145a1091, "_gpl");
SYMBOL_CRC(__sdhci_read_caps, 0x859b921d, "_gpl");
SYMBOL_CRC(sdhci_setup_host, 0xdf1759f7, "_gpl");
SYMBOL_CRC(sdhci_cleanup_host, 0xa2a539fa, "_gpl");
SYMBOL_CRC(__sdhci_add_host, 0xd4bc3b29, "_gpl");
SYMBOL_CRC(sdhci_add_host, 0x7775af29, "_gpl");
SYMBOL_CRC(sdhci_remove_host, 0x688a7f13, "_gpl");
SYMBOL_CRC(sdhci_free_host, 0x9b1b5206, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6d606913, "pv_ops" },
	{ 0x86490580, "current_task" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x92997ed8, "_printk" },
	{ 0xe753b214, "dma_sync_single_for_device" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x2b8ab42, "sg_copy_to_buffer" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x95a0381b, "dma_sync_single_for_cpu" },
	{ 0x800473f, "__cond_resched" },
	{ 0x905695ab, "sg_copy_from_buffer" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xe44459bf, "mmc_retune_timer_stop" },
	{ 0xaa309cf, "synchronize_hardirq" },
	{ 0xbad5402e, "mmc_send_abort_tuning" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc04a3d34, "mmc_regulator_set_ocr" },
	{ 0xa3bfb7e5, "mmc_gpio_get_cd" },
	{ 0xaa331e5c, "mmc_can_gpio_cd" },
	{ 0xce2840e7, "irq_set_irq_wake" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xaa4bf8f6, "mmc_can_gpio_ro" },
	{ 0x13a52dda, "mmc_gpio_get_ro" },
	{ 0xf9a482f9, "msleep" },
	{ 0x596e66f6, "mmc_regulator_set_vqmmc" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0x6a9dc528, "device_property_read_u64_array" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xe20299b5, "regulator_is_supported_voltage" },
	{ 0x16fb74cf, "regulator_get_current_limit" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0x74f6e487, "mmc_regulator_get_supply" },
	{ 0xff44f9f8, "dma_max_mapping_size" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xffae8e8b, "nsecs_to_jiffies" },
	{ 0x87b8798d, "sg_next" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x9c0c24e2, "dma_sync_sg_for_cpu" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xc4682d1d, "sdio_signal_irq" },
	{ 0x167e40f4, "mmc_command_done" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E98EF911B764CC651070C15");
