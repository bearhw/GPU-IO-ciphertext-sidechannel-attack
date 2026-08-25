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
	{ 0x37a0cba, "kfree" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xc46a2c52, "mpt_get_msg_frame" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3b7cdd92, "mpt_put_msg_frame" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x92997ed8, "_printk" },
	{ 0x3bebdaa3, "mpt_HardResetHandler" },
	{ 0x862e02c3, "mpt_free_msg_frame" },
	{ 0xb27eb5df, "scsi_remove_host" },
	{ 0x50fe0bb6, "mptscsih_remove" },
	{ 0xd38914d2, "mptscsih_qcmd" },
	{ 0x26f89323, "scsi_print_command" },
	{ 0x9d05c15c, "scsi_done" },
	{ 0xd0b5865a, "mptscsih_is_phys_disk" },
	{ 0x36aee7d, "mpt_attach" },
	{ 0xe2cad31b, "scsi_host_alloc" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x816fc9e7, "scsi_add_host_with_dma" },
	{ 0x36eb54d3, "scsi_scan_host" },
	{ 0x7d9731b4, "mptscsih_IssueTaskMgmt" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x82ecb338, "scsi_is_host_device" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x25e9e0b, "mpt_config" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x2a6fe346, "scsi_device_lookup_by_target" },
	{ 0x8225558d, "sdev_prefix_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x1c1edde4, "_dev_printk" },
	{ 0x1fbad4bf, "mptscsih_slave_destroy" },
	{ 0x2a667f56, "mptscsih_event_process" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xf3edb75c, "mptscsih_resume" },
	{ 0xce5e793d, "mptscsih_ioc_reset" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xc7878fd0, "spi_dv_device" },
	{ 0xc0267bf4, "spi_display_xfer_agreement" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7630837e, "__scsi_iterate_devices" },
	{ 0x4f904028, "mptscsih_slave_configure" },
	{ 0x3e39391e, "mpt_findImVolumes" },
	{ 0x1250b664, "scsi_scan_target" },
	{ 0xc6842f3f, "mptscsih_raid_id_to_num" },
	{ 0x599e386f, "spi_attach_transport" },
	{ 0x9c1b9b08, "mptscsih_io_done" },
	{ 0xfd972c5b, "mpt_register" },
	{ 0x9da0ce8e, "mptscsih_taskmgmt_complete" },
	{ 0x58496ced, "mptscsih_scandv_complete" },
	{ 0x1ea8f504, "mpt_event_register" },
	{ 0x95f4fe1c, "mpt_reset_register" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xf4d49220, "spi_release_transport" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x610b257e, "mpt_reset_deregister" },
	{ 0xe6c1e126, "mpt_event_deregister" },
	{ 0x981efe92, "mpt_deregister" },
	{ 0xe38f5547, "mptscsih_suspend" },
	{ 0x3ce1a011, "mptscsih_shutdown" },
	{ 0xa443bafd, "mptscsih_info" },
	{ 0xa9fbaa99, "mptscsih_abort" },
	{ 0xb14b7eb6, "mptscsih_dev_reset" },
	{ 0xd7afac9c, "mptscsih_bus_reset" },
	{ 0x3c7dead1, "mptscsih_host_reset" },
	{ 0x52b46243, "mptscsih_change_queue_depth" },
	{ 0x4257325d, "mptscsih_bios_param" },
	{ 0x4a15b16f, "mptscsih_show_info" },
	{ 0x688c78, "mptscsih_host_attr_groups" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mptbase,mptscsih,scsi_transport_spi");

MODULE_ALIAS("pci:v00001000d00000030sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000117Cd00000030sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000040sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "7D1BD9BB8B701CFB70EFFE3");
