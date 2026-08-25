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

SYMBOL_CRC(o2hb_fill_node_map, 0x1b89c6ee, "_gpl");
SYMBOL_CRC(o2hb_setup_callback, 0xfc4c1f02, "_gpl");
SYMBOL_CRC(o2hb_register_callback, 0x664bfcdf, "_gpl");
SYMBOL_CRC(o2hb_unregister_callback, 0xc61751a2, "_gpl");
SYMBOL_CRC(o2hb_check_node_heartbeating_no_sem, 0xbd13ee5d, "_gpl");
SYMBOL_CRC(o2hb_check_node_heartbeating_from_callback, 0xc4d99852, "_gpl");
SYMBOL_CRC(o2hb_stop_all_regions, 0x4900035b, "_gpl");
SYMBOL_CRC(o2hb_get_all_regions, 0x58c88ff2, "_gpl");
SYMBOL_CRC(o2hb_global_heartbeat_active, 0xbfd7d7a2, "");
SYMBOL_CRC(mlog_and_bits, 0x81a17396, "_gpl");
SYMBOL_CRC(mlog_not_bits, 0xf56c2017, "_gpl");
SYMBOL_CRC(__mlog_printk, 0x6a0c3847, "_gpl");
SYMBOL_CRC(o2nm_get_node_by_num, 0xb474e92f, "_gpl");
SYMBOL_CRC(o2nm_configured_node_map, 0xa87bc9e7, "_gpl");
SYMBOL_CRC(o2nm_get_node_by_ip, 0x63079dcf, "_gpl");
SYMBOL_CRC(o2nm_node_put, 0x2b2061a9, "_gpl");
SYMBOL_CRC(o2nm_node_get, 0x45846efb, "_gpl");
SYMBOL_CRC(o2nm_this_node, 0xb6ebf62a, "_gpl");
SYMBOL_CRC(o2net_register_handler, 0xfe1298f3, "_gpl");
SYMBOL_CRC(o2net_unregister_handler_list, 0xf1a5611d, "_gpl");
SYMBOL_CRC(o2net_fill_node_map, 0xd859ac8c, "_gpl");
SYMBOL_CRC(o2net_send_message_vec, 0x5e95a4b2, "_gpl");
SYMBOL_CRC(o2net_send_message, 0xf982e6db, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x187b64e8, "config_group_init" },
	{ 0x20978fb9, "idr_find" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xb0e602eb, "memmove" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x96848186, "scnprintf" },
	{ 0xfa55dc45, "config_item_get" },
	{ 0xaf468156, "set_user_nice" },
	{ 0xd72a9f53, "sock_create" },
	{ 0xa7ba69da, "tcp_sock_set_user_timeout" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x3f7b09fb, "kset_unregister" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb56b87f1, "configfs_unregister_subsystem" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x9ae47436, "_find_last_bit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x96b29254, "strncasecmp" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xd0c05159, "emergency_restart" },
	{ 0x5d6cbf9f, "bdevname" },
	{ 0x95b79998, "fs_kobj" },
	{ 0x6bce7da8, "blkdev_put" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xefab6f8e, "submit_bio" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x9f46ced8, "__sw_hweight64" },
	{ 0xa09dd780, "bio_put" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xd28f6a7f, "fput" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0xffb2df28, "configfs_register_subsystem" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x2acfb021, "blkdev_get_by_dev" },
	{ 0xfc89af6e, "configfs_remove_default_groups" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x8bc8cc11, "config_group_init_type_name" },
	{ 0xf43e05f3, "kernel_sock_shutdown" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x69dd3b5b, "crc32_le" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x7971b0bb, "iov_iter_kvec" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xf1e046cc, "panic" },
	{ 0x9519cb96, "bio_add_page" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd539673b, "__seq_open_private" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x86490580, "current_task" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xfb578fc5, "memset" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xbaad92ad, "configfs_depend_item" },
	{ 0x668b19a1, "down_read" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf2b11959, "seq_read" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xe4994173, "config_item_init_type_name" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0xfbcbfb4d, "config_item_put" },
	{ 0x95352ea6, "kobject_set_name" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x66b5d182, "sock_recvmsg" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x20000329, "simple_strtoul" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x6e5c0971, "sock_release" },
	{ 0x7c144603, "configfs_undepend_item" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xb2340e65, "tcp_sock_set_nodelay" },
	{ 0x9f186838, "seq_release_private" },
	{ 0xc1d8cfaf, "__fdget" },
	{ 0xe8eb5b88, "kset_register" },
	{ 0x754d539c, "strlen" },
	{ 0x29016914, "sock_create_lite" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x55ad2c95, "kernel_sendmsg" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x84502a47, "blk_status_to_errno" },
	{ 0x53b954a2, "up_read" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x9af19ea7, "fs_bio_set" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x7233a2e6, "kset_create_and_add" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2C24A8989C39BA8AED181A0");
