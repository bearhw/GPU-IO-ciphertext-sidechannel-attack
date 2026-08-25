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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4fe6a37e, "fc_remove_host" },
	{ 0x37a0cba, "kfree" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xb27eb5df, "scsi_remove_host" },
	{ 0x50fe0bb6, "mptscsih_remove" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe4bf58a0, "fc_remote_port_delete" },
	{ 0x92997ed8, "_printk" },
	{ 0x3965faff, "scsi_is_fc_rport" },
	{ 0x2a667f56, "mptscsih_event_process" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x25e9e0b, "mpt_config" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xce5e793d, "mptscsih_ioc_reset" },
	{ 0xf9a482f9, "msleep" },
	{ 0x36aee7d, "mpt_attach" },
	{ 0xe2cad31b, "scsi_host_alloc" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x816fc9e7, "scsi_add_host_with_dma" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd7afac9c, "mptscsih_bus_reset" },
	{ 0xb14b7eb6, "mptscsih_dev_reset" },
	{ 0xa9fbaa99, "mptscsih_abort" },
	{ 0x30e26f5d, "fc_remote_port_add" },
	{ 0xc8f0a0d7, "fc_remote_port_rolechg" },
	{ 0x9d05c15c, "scsi_done" },
	{ 0xd38914d2, "mptscsih_qcmd" },
	{ 0xb7c0f443, "sort" },
	{ 0x5bbe79f8, "fc_attach_transport" },
	{ 0x9c1b9b08, "mptscsih_io_done" },
	{ 0xfd972c5b, "mpt_register" },
	{ 0x9da0ce8e, "mptscsih_taskmgmt_complete" },
	{ 0x58496ced, "mptscsih_scandv_complete" },
	{ 0x1ea8f504, "mpt_event_register" },
	{ 0x95f4fe1c, "mpt_reset_register" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x73b03eba, "fc_release_transport" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x610b257e, "mpt_reset_deregister" },
	{ 0xe6c1e126, "mpt_event_deregister" },
	{ 0x981efe92, "mpt_deregister" },
	{ 0xe38f5547, "mptscsih_suspend" },
	{ 0xf3edb75c, "mptscsih_resume" },
	{ 0x3ce1a011, "mptscsih_shutdown" },
	{ 0xa443bafd, "mptscsih_info" },
	{ 0x3c7dead1, "mptscsih_host_reset" },
	{ 0x4f904028, "mptscsih_slave_configure" },
	{ 0x1fbad4bf, "mptscsih_slave_destroy" },
	{ 0x52b46243, "mptscsih_change_queue_depth" },
	{ 0x4257325d, "mptscsih_bios_param" },
	{ 0x4a15b16f, "mptscsih_show_info" },
	{ 0x9a0e610a, "fc_eh_timed_out" },
	{ 0x688c78, "mptscsih_host_attr_groups" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "scsi_transport_fc,mptscsih,mptbase");

MODULE_ALIAS("pci:v00001000d00000621sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000624sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000622sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000628sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000626sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000642sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000640sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001000d00000646sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001657d00000646sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "86AFE21AEC30F1DCD65988A");
