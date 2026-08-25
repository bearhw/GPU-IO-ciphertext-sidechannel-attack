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

SYMBOL_CRC(dlm_unregister_domain, 0x3486c833, "_gpl");
SYMBOL_CRC(dlm_register_domain, 0x126ae7d7, "_gpl");
SYMBOL_CRC(dlm_setup_eviction_cb, 0x7a1211f8, "_gpl");
SYMBOL_CRC(dlm_register_eviction_cb, 0x7a46fa27, "_gpl");
SYMBOL_CRC(dlm_unregister_eviction_cb, 0xd8fa57a6, "_gpl");
SYMBOL_CRC(dlm_print_one_lock, 0x289b00f3, "_gpl");
SYMBOL_CRC(dlm_errmsg, 0xd7ba575e, "_gpl");
SYMBOL_CRC(dlm_errname, 0xfb86b96f, "_gpl");
SYMBOL_CRC(dlmlock, 0x11d31eb2, "_gpl");
SYMBOL_CRC(dlmunlock, 0x21f99940, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x96848186, "scnprintf" },
	{ 0xb6ebf62a, "o2nm_this_node" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xbd13ee5d, "o2hb_check_node_heartbeating_no_sem" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xd6eaaea1, "full_name_hash" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0xb474e92f, "o2nm_get_node_by_num" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x6a0c3847, "__mlog_printk" },
	{ 0x23b4e0d7, "clear_page_rep" },
	{ 0xa02aa74a, "__cond_resched_lock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xfc4c1f02, "o2hb_setup_callback" },
	{ 0x57bc19d2, "down_write" },
	{ 0xce807a25, "up_write" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x925493f, "clear_page_orig" },
	{ 0xbfd7d7a2, "o2hb_global_heartbeat_active" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x9084b044, "clear_page_erms" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xd539673b, "__seq_open_private" },
	{ 0x86490580, "current_task" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xcf4fdd4d, "_atomic_dec_and_lock" },
	{ 0x668b19a1, "down_read" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf2b11959, "seq_read" },
	{ 0x5e95a4b2, "o2net_send_message_vec" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x1b89c6ee, "o2hb_fill_node_map" },
	{ 0xf1a5611d, "o2net_unregister_handler_list" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xf982e6db, "o2net_send_message" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xfe1298f3, "o2net_register_handler" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x9f186838, "seq_release_private" },
	{ 0x754d539c, "strlen" },
	{ 0x664bfcdf, "o2hb_register_callback" },
	{ 0x58c88ff2, "o2hb_get_all_regions" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x53b954a2, "up_read" },
	{ 0xc61751a2, "o2hb_unregister_callback" },
	{ 0x2b2061a9, "o2nm_node_put" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ocfs2_nodemanager");


MODULE_INFO(srcversion, "4AE8E9BB235CBCFFA8D3A80");
