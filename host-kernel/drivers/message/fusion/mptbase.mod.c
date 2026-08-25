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

SYMBOL_CRC(mpt_fwfault_debug, 0x502108d0, "");
SYMBOL_CRC(mpt_raid_phys_disk_get_num_paths, 0x0ec3322d, "");
SYMBOL_CRC(mpt_raid_phys_disk_pg1, 0xe91d12ad, "");
SYMBOL_CRC(mpt_set_taskmgmt_in_progress_flag, 0xdba95fe3, "");
SYMBOL_CRC(mpt_clear_taskmgmt_in_progress_flag, 0x0069e061, "");
SYMBOL_CRC(mpt_halt_firmware, 0x20751c08, "");
SYMBOL_CRC(mpt_Soft_Hard_ResetHandler, 0xd0638300, "");
SYMBOL_CRC(mpt_attach, 0x036aee7d, "");
SYMBOL_CRC(mpt_detach, 0xaf4fe92d, "");
SYMBOL_CRC(mpt_resume, 0x1af8cb8c, "");
SYMBOL_CRC(mpt_suspend, 0xff9fa43f, "");
SYMBOL_CRC(ioc_list, 0xdd805159, "");
SYMBOL_CRC(mpt_register, 0xfd972c5b, "");
SYMBOL_CRC(mpt_deregister, 0x981efe92, "");
SYMBOL_CRC(mpt_event_register, 0x1ea8f504, "");
SYMBOL_CRC(mpt_event_deregister, 0xe6c1e126, "");
SYMBOL_CRC(mpt_reset_register, 0x95f4fe1c, "");
SYMBOL_CRC(mpt_reset_deregister, 0x610b257e, "");
SYMBOL_CRC(mpt_device_driver_register, 0xbb889362, "");
SYMBOL_CRC(mpt_device_driver_deregister, 0x74a0134a, "");
SYMBOL_CRC(mpt_get_msg_frame, 0xc46a2c52, "");
SYMBOL_CRC(mpt_put_msg_frame, 0x3b7cdd92, "");
SYMBOL_CRC(mpt_put_msg_frame_hi_pri, 0xb94157d5, "");
SYMBOL_CRC(mpt_free_msg_frame, 0x862e02c3, "");
SYMBOL_CRC(mpt_send_handshake_request, 0xd28e1237, "");
SYMBOL_CRC(mpt_verify_adapter, 0x020cfa3f, "");
SYMBOL_CRC(mpt_GetIocState, 0xc269bdb1, "");
SYMBOL_CRC(mpt_print_ioc_summary, 0x2fa97d80, "");
SYMBOL_CRC(mpt_HardResetHandler, 0x3bebdaa3, "");
SYMBOL_CRC(mpt_config, 0x025e9e0b, "");
SYMBOL_CRC(mpt_findImVolumes, 0x3e39391e, "");
SYMBOL_CRC(mpt_alloc_fw_memory, 0x1867c535, "");
SYMBOL_CRC(mpt_free_fw_memory, 0x7dcf294e, "");
SYMBOL_CRC(mptbase_sas_persist_operation, 0x4228b0e4, "");
SYMBOL_CRC(mpt_raid_phys_disk_pg0, 0x23e44245, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x5792f848, "strlcpy" },
	{ 0x92997ed8, "_printk" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xf9a482f9, "msleep" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xea673cef, "pci_stop_and_remove_bus_device_locked" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x5b2439a7, "pci_select_bars" },
	{ 0x3e32aadb, "pci_enable_device_mem" },
	{ 0xe223bb16, "pci_request_selected_regions" },
	{ 0x34b9b10b, "dma_get_required_mask" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xde80cd09, "ioremap" },
	{ 0x12bcb93d, "pci_release_selected_regions" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xfb578fc5, "memset" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x37a0cba, "kfree" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xf1e046cc, "panic" },
	{ 0xa6257a2f, "complete" },
	{ 0x825b201, "param_set_int" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x754d539c, "strlen" },
	{ 0xa906274e, "seq_putc" },
	{ 0xb1edfe5e, "pci_choose_state" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x20d8d10f, "pci_disable_msi" },
	{ 0xbbe839b2, "pci_save_state" },
	{ 0x1bfe1491, "pci_set_power_state" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa8a194c9, "pci_enable_msi" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x800473f, "__cond_resched" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x65162719, "pci_get_slot" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xedc03953, "iounmap" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0xa6aa1711, "proc_create_single_data" },
	{ 0xc3637570, "pci_enable_wake" },
	{ 0xbbf0b873, "pci_restore_state" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xe523ad75, "synchronize_irq" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x47c333ea, "param_get_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A345DC17C1290A3DDD6E007");
