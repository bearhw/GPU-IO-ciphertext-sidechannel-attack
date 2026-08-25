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
	{ 0x92997ed8, "_printk" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x37a0cba, "kfree" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x7630837e, "__scsi_iterate_devices" },
	{ 0x25e9e0b, "mpt_config" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa6257a2f, "complete" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xaedf4da3, "device_reprobe" },
	{ 0xf305d6c7, "scsi_device_set_state" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x7fc07a65, "bsg_job_done" },
	{ 0xc46a2c52, "mpt_get_msg_frame" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3b7cdd92, "mpt_put_msg_frame" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x862e02c3, "mpt_free_msg_frame" },
	{ 0xd0638300, "mpt_Soft_Hard_ResetHandler" },
	{ 0xb94157d5, "mpt_put_msg_frame_hi_pri" },
	{ 0x69e061, "mpt_clear_taskmgmt_in_progress_flag" },
	{ 0xd38914d2, "mptscsih_qcmd" },
	{ 0x9d05c15c, "scsi_done" },
	{ 0x26f89323, "scsi_print_command" },
	{ 0x5ed90adc, "int_to_scsilun" },
	{ 0xbdf15926, "sas_end_device_alloc" },
	{ 0x830ef656, "sas_rphy_add" },
	{ 0xf002f123, "sas_rphy_free" },
	{ 0x1c1edde4, "_dev_printk" },
	{ 0x23e44245, "mpt_raid_phys_disk_pg0" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xdba95fe3, "mpt_set_taskmgmt_in_progress_flag" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x4462227f, "sas_remove_host" },
	{ 0x50fe0bb6, "mptscsih_remove" },
	{ 0xaf4fe92d, "mpt_detach" },
	{ 0xa5e40119, "sas_port_delete" },
	{ 0x7759bb1f, "sas_port_delete_phy" },
	{ 0xe157eb0a, "mptscsih_taskmgmt_response_code" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0xd0b5865a, "mptscsih_is_phys_disk" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xce5e793d, "mptscsih_ioc_reset" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x3ac441cd, "starget_for_each_device" },
	{ 0x82ecb338, "scsi_is_host_device" },
	{ 0xc6842f3f, "mptscsih_raid_id_to_num" },
	{ 0x2d68fc5c, "sas_read_port_mode_page" },
	{ 0x4f904028, "mptscsih_slave_configure" },
	{ 0x8225558d, "sdev_prefix_printk" },
	{ 0xfa296f2d, "sas_port_add_phy" },
	{ 0xaafc38df, "sas_port_mark_backlink" },
	{ 0x4e190f1, "sas_phy_add" },
	{ 0x718faf52, "sas_phy_alloc" },
	{ 0x6b2e5549, "sas_port_alloc_num" },
	{ 0x9cc40e43, "sas_port_add" },
	{ 0x9db1d710, "sas_phy_free" },
	{ 0x7d9ca8d6, "sas_expander_alloc" },
	{ 0x441b833e, "scsi_is_sas_rphy" },
	{ 0x9166fada, "strncpy" },
	{ 0x3e39391e, "mpt_findImVolumes" },
	{ 0xb363452c, "scsi_remove_device" },
	{ 0x12e047bb, "scsi_device_put" },
	{ 0xec3322d, "mpt_raid_phys_disk_get_num_paths" },
	{ 0xe91d12ad, "mpt_raid_phys_disk_pg1" },
	{ 0x4e6c5045, "scsi_add_device" },
	{ 0x69ab51db, "scsi_device_lookup" },
	{ 0x36aee7d, "mpt_attach" },
	{ 0x9bff935b, "mptscsih_flush_running_cmds" },
	{ 0xe2cad31b, "scsi_host_alloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x816fc9e7, "scsi_add_host_with_dma" },
	{ 0x4228b0e4, "mptbase_sas_persist_operation" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x5cae0e3, "scsi_track_queue_full" },
	{ 0xe748b1d0, "mptscsih_get_scsi_lookup" },
	{ 0xc269bdb1, "mpt_GetIocState" },
	{ 0x65acf90c, "sbitmap_weight" },
	{ 0xef8d2234, "sas_attach_transport" },
	{ 0x9c1b9b08, "mptscsih_io_done" },
	{ 0xfd972c5b, "mpt_register" },
	{ 0x9da0ce8e, "mptscsih_taskmgmt_complete" },
	{ 0x58496ced, "mptscsih_scandv_complete" },
	{ 0x1ea8f504, "mpt_event_register" },
	{ 0x95f4fe1c, "mpt_reset_register" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xf26bd8fe, "sas_release_transport" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x610b257e, "mpt_reset_deregister" },
	{ 0xe6c1e126, "mpt_event_deregister" },
	{ 0x981efe92, "mpt_deregister" },
	{ 0xe38f5547, "mptscsih_suspend" },
	{ 0xf3edb75c, "mptscsih_resume" },
	{ 0xa443bafd, "mptscsih_info" },
	{ 0xa9fbaa99, "mptscsih_abort" },
	{ 0xb14b7eb6, "mptscsih_dev_reset" },
	{ 0x3c7dead1, "mptscsih_host_reset" },
	{ 0x1fbad4bf, "mptscsih_slave_destroy" },
	{ 0x52b46243, "mptscsih_change_queue_depth" },
	{ 0x4257325d, "mptscsih_bios_param" },
	{ 0x4a15b16f, "mptscsih_show_info" },
	{ 0x688c78, "mptscsih_host_attr_groups" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mptbase,mptscsih,scsi_transport_sas");

MODULE_ALIAS("pci:v00001000d00000050sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000054sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000056sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000058sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000062sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000059sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "C24244ED603C419E826451B");
