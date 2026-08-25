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
	{ 0x5f4a6e61, "dm_rh_dec" },
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0xe43ddd3e, "dm_dirty_log_create" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x5ff783bf, "dm_rh_delay" },
	{ 0xfd93482e, "dm_rh_recovery_in_flight" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xa20fcec3, "dm_noflush_suspending" },
	{ 0x3e6e3309, "dm_per_bio_data" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0x3a18389a, "dm_rh_update_states" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x7d053fc5, "dm_rh_start_recovery" },
	{ 0x96848186, "scnprintf" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x2fd31db6, "dm_dirty_log_destroy" },
	{ 0xef54fbbd, "dm_rh_mark_nosync" },
	{ 0x37a0cba, "kfree" },
	{ 0x601f665f, "dm_io_client_create" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x38efaf5a, "dm_region_hash_destroy" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xd688716b, "dm_kcopyd_client_create" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x38972f23, "dm_rh_region_to_sector" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x104be7f5, "dm_rh_dirty_log" },
	{ 0x800473f, "__cond_resched" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x7774620f, "dm_rh_stop_recovery" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x24d273d1, "add_timer" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x466793e6, "dm_set_target_max_io_len" },
	{ 0x2bf609c5, "dm_table_event" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x7259b774, "dm_rh_bio_to_region" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xbe38a431, "dm_rh_recovery_prepare" },
	{ 0x1d2f9ac, "dm_rh_recovery_start" },
	{ 0x9e4faeef, "dm_io_client_destroy" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xa53387c7, "dm_rh_flush" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xd8aa4284, "dm_rh_region_context" },
	{ 0x6d606913, "pv_ops" },
	{ 0x80702017, "dm_kcopyd_copy" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xe5a35bb0, "dm_region_hash_create" },
	{ 0x154c6338, "dm_kcopyd_client_destroy" },
	{ 0x7d5e1815, "dm_rh_get_region_key" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0x45af8ade, "dm_rh_inc_pending" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0x2d8750e5, "dm_io" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0x57e16c3e, "dm_rh_get_state" },
	{ 0xf92b8a3d, "dm_rh_get_region_size" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa83588eb, "dm_rh_recovery_end" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dm-region-hash,dm-log");


MODULE_INFO(srcversion, "DA520ED5DBA7A60E482579E");
