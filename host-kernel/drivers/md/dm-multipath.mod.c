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

SYMBOL_CRC(dm_register_path_selector, 0x01d37304, "_gpl");
SYMBOL_CRC(dm_unregister_path_selector, 0x5e717fd1, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x5dfc571a, "blk_start_plug" },
	{ 0xd5fd941f, "param_ops_ulong" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x2780557, "dm_table_run_md_queue_async" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xa20fcec3, "dm_noflush_suspending" },
	{ 0x3e6e3309, "dm_per_bio_data" },
	{ 0x2e0920b0, "dm_put_device" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x96848186, "scnprintf" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x37a0cba, "kfree" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe9832b3b, "dm_mq_kick_requeue_list" },
	{ 0x1d2915ac, "blk_mq_free_request" },
	{ 0x49b6b84c, "blk_finish_plug" },
	{ 0x1de23e95, "module_put" },
	{ 0x2d26b611, "bio_endio" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xa34af51, "dm_suspended" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0x11e0ec41, "dm_read_arg" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x93a6e0b2, "io_schedule" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x5eb24829, "dm_shift_arg" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x386865d5, "blk_mq_alloc_request" },
	{ 0xe02b595d, "scsi_dh_attach" },
	{ 0xe201ace2, "dm_unregister_target" },
	{ 0xabce3bcd, "scsi_dh_activate" },
	{ 0x9536b47b, "blk_lld_busy" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x2bf609c5, "dm_table_event" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xc7d094b5, "dm_read_arg_group" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x668b19a1, "down_read" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xb32a43e5, "scsi_dh_attached_handler_name" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xabe5fe4c, "dm_table_device_name" },
	{ 0xaa9b2c28, "dm_register_target" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x56470118, "__warn_printk" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xdfac7b1, "dm_start_time_ns_from_clone" },
	{ 0x41cdbe60, "dm_table_get_mode" },
	{ 0xb1b06a8f, "dm_table_get_md" },
	{ 0xdf372a6a, "dm_path_uevent" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x91e12a1b, "dm_get_device" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xe51f2310, "dm_table_set_type" },
	{ 0x53b954a2, "up_read" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x7deff673, "dm_consume_args" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x3cb1ebcd, "scsi_dh_set_params" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "477FD937C7FA7355F540CF5");
