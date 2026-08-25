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

SYMBOL_CRC(mptscsih_flush_running_cmds, 0x9bff935b, "");
SYMBOL_CRC(mptscsih_IssueTaskMgmt, 0x7d9731b4, "");
SYMBOL_CRC(mptscsih_taskmgmt_response_code, 0xe157eb0a, "");
SYMBOL_CRC(mptscsih_is_phys_disk, 0xd0b5865a, "");
SYMBOL_CRC(mptscsih_raid_id_to_num, 0xc6842f3f, "");
SYMBOL_CRC(mptscsih_get_scsi_lookup, 0xe748b1d0, "");
SYMBOL_CRC(mptscsih_host_attr_groups, 0x00688c78, "");
SYMBOL_CRC(mptscsih_remove, 0x50fe0bb6, "");
SYMBOL_CRC(mptscsih_shutdown, 0x3ce1a011, "");
SYMBOL_CRC(mptscsih_suspend, 0xe38f5547, "");
SYMBOL_CRC(mptscsih_resume, 0xf3edb75c, "");
SYMBOL_CRC(mptscsih_show_info, 0x4a15b16f, "");
SYMBOL_CRC(mptscsih_info, 0xa443bafd, "");
SYMBOL_CRC(mptscsih_qcmd, 0xd38914d2, "");
SYMBOL_CRC(mptscsih_slave_destroy, 0x1fbad4bf, "");
SYMBOL_CRC(mptscsih_slave_configure, 0x4f904028, "");
SYMBOL_CRC(mptscsih_abort, 0xa9fbaa99, "");
SYMBOL_CRC(mptscsih_dev_reset, 0xb14b7eb6, "");
SYMBOL_CRC(mptscsih_bus_reset, 0xd7afac9c, "");
SYMBOL_CRC(mptscsih_host_reset, 0x3c7dead1, "");
SYMBOL_CRC(mptscsih_bios_param, 0x4257325d, "");
SYMBOL_CRC(mptscsih_io_done, 0x9c1b9b08, "");
SYMBOL_CRC(mptscsih_taskmgmt_complete, 0x9da0ce8e, "");
SYMBOL_CRC(mptscsih_scandv_complete, 0x58496ced, "");
SYMBOL_CRC(mptscsih_event_process, 0x2a667f56, "");
SYMBOL_CRC(mptscsih_ioc_reset, 0xce5e793d, "");
SYMBOL_CRC(mptscsih_change_queue_depth, 0x52b46243, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x92997ed8, "_printk" },
	{ 0x37a0cba, "kfree" },
	{ 0x6ec3e817, "scsi_host_put" },
	{ 0xaf4fe92d, "mpt_detach" },
	{ 0xf856ea45, "scsi_block_requests" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xff9fa43f, "mpt_suspend" },
	{ 0x1af8cb8c, "mpt_resume" },
	{ 0xa84c174d, "scsi_unblock_requests" },
	{ 0x2fa97d80, "mpt_print_ioc_summary" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xc46a2c52, "mpt_get_msg_frame" },
	{ 0x5ed90adc, "int_to_scsilun" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3b7cdd92, "mpt_put_msg_frame" },
	{ 0x90b0f1ed, "scsi_dma_map" },
	{ 0x87b8798d, "sg_next" },
	{ 0x862e02c3, "mpt_free_msg_frame" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xc269bdb1, "mpt_GetIocState" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xdba95fe3, "mpt_set_taskmgmt_in_progress_flag" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xd28e1237, "mpt_send_handshake_request" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x69e061, "mpt_clear_taskmgmt_in_progress_flag" },
	{ 0xd0638300, "mpt_Soft_Hard_ResetHandler" },
	{ 0xb94157d5, "mpt_put_msg_frame_hi_pri" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x3bebdaa3, "mpt_HardResetHandler" },
	{ 0x26f89323, "scsi_print_command" },
	{ 0x9d05c15c, "scsi_done" },
	{ 0x502108d0, "mpt_fwfault_debug" },
	{ 0x20751c08, "mpt_halt_firmware" },
	{ 0xa6257a2f, "complete" },
	{ 0x17cef504, "scsi_change_queue_depth" },
	{ 0x17dd96bd, "blk_queue_dma_alignment" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x754d539c, "strlen" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xec3322d, "mpt_raid_phys_disk_get_num_paths" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xe91d12ad, "mpt_raid_phys_disk_pg1" },
	{ 0x478437e6, "scsi_dma_unmap" },
	{ 0x8225558d, "sdev_prefix_printk" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mptbase");


MODULE_INFO(srcversion, "619C6C995FB40CC10D833B8");
