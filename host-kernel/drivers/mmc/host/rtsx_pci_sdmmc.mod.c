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
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x2649f6f6, "rtsx_pci_complete_unfinished_transfer" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x3690d8c5, "__pm_runtime_use_autosuspend" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0x64555890, "rtsx_pci_add_cmd" },
	{ 0x11eb262a, "rtsx_pci_dma_unmap_sg" },
	{ 0x6dc30ff0, "rtsx_pci_write_register" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x352e7e70, "pm_runtime_no_callbacks" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x9af304d4, "pm_runtime_set_autosuspend_delay" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0xd7d316a6, "rtsx_pci_start_run" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb14a07ee, "rtsx_pci_card_exist" },
	{ 0x9c8fc25e, "rtsx_pci_send_cmd" },
	{ 0x28626311, "rtsx_pci_read_ppbuf" },
	{ 0x2ec037d0, "rtsx_pci_card_exclusive_check" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x78cfd5ad, "rtsx_pci_read_register" },
	{ 0x466d997f, "rtsx_pci_switch_output_voltage" },
	{ 0xf9a482f9, "msleep" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe8d3a13, "rtsx_pci_card_pull_ctl_enable" },
	{ 0x9a01ee67, "rtsx_pci_card_power_on" },
	{ 0xbe806e63, "rtsx_pci_switch_clock" },
	{ 0xa91f0379, "rtsx_pci_card_power_off" },
	{ 0x76f4b6de, "rtsx_pci_card_pull_ctl_disable" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xfecddf50, "rtsx_pci_dma_map_sg" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xd2cb44c3, "rtsx_pci_send_cmd_no_wait" },
	{ 0x13af8b29, "rtsx_pci_dma_transfer" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x905695ab, "sg_copy_from_buffer" },
	{ 0x37a0cba, "kfree" },
	{ 0x2b8ab42, "sg_copy_to_buffer" },
	{ 0xb1fb2e8d, "rtsx_pci_write_ppbuf" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "rtsx_pci");

MODULE_ALIAS("platform:rtsx_pci_sdmmc");

MODULE_INFO(srcversion, "F03F8FDA226287BE2E7EB4A");
