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
	{ 0x4570d708, "memstick_resume_host" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x68136d78, "memstick_suspend_host" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x2649f6f6, "rtsx_pci_complete_unfinished_transfer" },
	{ 0xa9aba759, "memstick_next_req" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd0582469, "memstick_remove_host" },
	{ 0x6240a29e, "memstick_free_host" },
	{ 0x9c25bc16, "memstick_alloc_host" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x1cb50365, "memstick_add_host" },
	{ 0x63c2cc99, "memstick_detect_change" },
	{ 0x2ec037d0, "rtsx_pci_card_exclusive_check" },
	{ 0x6dc30ff0, "rtsx_pci_write_register" },
	{ 0xbe806e63, "rtsx_pci_switch_clock" },
	{ 0x64555890, "rtsx_pci_add_cmd" },
	{ 0x9c8fc25e, "rtsx_pci_send_cmd" },
	{ 0xa91f0379, "rtsx_pci_card_power_off" },
	{ 0x76f4b6de, "rtsx_pci_card_pull_ctl_disable" },
	{ 0xe8d3a13, "rtsx_pci_card_pull_ctl_enable" },
	{ 0x9a01ee67, "rtsx_pci_card_power_on" },
	{ 0xf9a482f9, "msleep" },
	{ 0x78cfd5ad, "rtsx_pci_read_register" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xd7d316a6, "rtsx_pci_start_run" },
	{ 0xd2cb44c3, "rtsx_pci_send_cmd_no_wait" },
	{ 0x7fe6ee6e, "rtsx_pci_transfer_data" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "memstick,rtsx_pci");

MODULE_ALIAS("platform:rtsx_pci_ms");

MODULE_INFO(srcversion, "B3E914813B70C28F08D4E99");
