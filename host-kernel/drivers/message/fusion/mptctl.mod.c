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
	{ 0xb0285ae, "kill_fasync" },
	{ 0x92997ed8, "_printk" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xa6257a2f, "complete" },
	{ 0x69e061, "mpt_clear_taskmgmt_in_progress_flag" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xdd805159, "ioc_list" },
	{ 0xa4cdf212, "fasync_helper" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xdba95fe3, "mpt_set_taskmgmt_in_progress_flag" },
	{ 0xc46a2c52, "mpt_get_msg_frame" },
	{ 0xd28e1237, "mpt_send_handshake_request" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x862e02c3, "mpt_free_msg_frame" },
	{ 0xb94157d5, "mpt_put_msg_frame_hi_pri" },
	{ 0x502108d0, "mpt_fwfault_debug" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xd0638300, "mpt_Soft_Hard_ResetHandler" },
	{ 0x20751c08, "mpt_halt_firmware" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x37a0cba, "kfree" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x25e9e0b, "mpt_config" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc269bdb1, "mpt_GetIocState" },
	{ 0x3b7cdd92, "mpt_put_msg_frame" },
	{ 0x754d539c, "strlen" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x7630837e, "__scsi_iterate_devices" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x8118d5fb, "dev_driver_string" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x20cfa3f, "mpt_verify_adapter" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0xbb9ed3bf, "mutex_trylock" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x7dcf294e, "mpt_free_fw_memory" },
	{ 0x1867c535, "mpt_alloc_fw_memory" },
	{ 0x9166fada, "strncpy" },
	{ 0x3bebdaa3, "mpt_HardResetHandler" },
	{ 0xbb889362, "mpt_device_driver_register" },
	{ 0x4708008a, "misc_register" },
	{ 0xfd972c5b, "mpt_register" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x981efe92, "mpt_deregister" },
	{ 0x95f4fe1c, "mpt_reset_register" },
	{ 0x1ea8f504, "mpt_event_register" },
	{ 0x74a0134a, "mpt_device_driver_deregister" },
	{ 0xe6c1e126, "mpt_event_deregister" },
	{ 0x610b257e, "mpt_reset_deregister" },
	{ 0x636a2492, "no_llseek" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mptbase");


MODULE_INFO(srcversion, "ECFB82E8A7211D9EFF4B884");
