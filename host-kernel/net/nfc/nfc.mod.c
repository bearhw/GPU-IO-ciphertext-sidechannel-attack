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

SYMBOL_CRC(nfc_fw_download_done, 0x00323cef, "");
SYMBOL_CRC(nfc_dep_link_is_up, 0x789a96f2, "");
SYMBOL_CRC(nfc_find_se, 0x87bd80e5, "");
SYMBOL_CRC(nfc_set_remote_general_bytes, 0x05af25e3, "");
SYMBOL_CRC(nfc_get_local_general_bytes, 0x7162243a, "");
SYMBOL_CRC(nfc_tm_data_received, 0xb22d7a04, "");
SYMBOL_CRC(nfc_tm_activated, 0xe1e427d8, "");
SYMBOL_CRC(nfc_tm_deactivated, 0x731eddca, "");
SYMBOL_CRC(nfc_alloc_recv_skb, 0x174b1084, "");
SYMBOL_CRC(nfc_targets_found, 0x17f6a6ad, "");
SYMBOL_CRC(nfc_target_lost, 0x6a55bff0, "");
SYMBOL_CRC(nfc_driver_failure, 0x4abc582a, "");
SYMBOL_CRC(nfc_add_se, 0x64c93d5d, "");
SYMBOL_CRC(nfc_remove_se, 0x27b2dd4d, "");
SYMBOL_CRC(nfc_se_transaction, 0x6f24dcf3, "");
SYMBOL_CRC(nfc_se_connectivity, 0xeee47a67, "");
SYMBOL_CRC(nfc_class, 0x2068ef1d, "");
SYMBOL_CRC(nfc_allocate_device, 0x3a2bcc99, "");
SYMBOL_CRC(nfc_register_device, 0x0c7d4730, "");
SYMBOL_CRC(nfc_unregister_device, 0x12e88147, "");
SYMBOL_CRC(__nfc_alloc_vendor_cmd_reply_skb, 0x82aa5f08, "");
SYMBOL_CRC(nfc_vendor_cmd_reply, 0xe9292f70, "");
SYMBOL_CRC(nfc_proto_register, 0xfb960282, "");
SYMBOL_CRC(nfc_proto_unregister, 0x646428c1, "");
SYMBOL_CRC(nfc_send_to_raw_sock, 0xd3b8ef40, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xda10ec3, "security_sock_graft" },
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x5a5ac216, "class_dev_iter_next" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x83eb21c, "rfkill_unregister" },
	{ 0xbe888b32, "skb_put" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xc0763484, "rfkill_blocked" },
	{ 0xde293f9e, "add_wait_queue_exclusive" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x16eef981, "sock_no_sendmsg" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x2ae031ab, "genlmsg_put" },
	{ 0x69acdf38, "memcpy" },
	{ 0xdb68bbad, "rfkill_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x9fa78973, "__pskb_copy_fclone" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x61413fe8, "class_dev_iter_exit" },
	{ 0x92997ed8, "_printk" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x50171cd6, "sock_register" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x3197c4e3, "put_device" },
	{ 0x6e3d9d78, "netlink_broadcast" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x68764184, "proto_register" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x1de23e95, "module_put" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7561021b, "__sock_recv_timestamp" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0xa1600c1b, "__class_register" },
	{ 0x7c6024bd, "init_net" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x48098f3, "device_add" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x5a921311, "strncmp" },
	{ 0x8520a781, "nla_put" },
	{ 0xffb7c514, "ida_free" },
	{ 0x70cc876b, "class_unregister" },
	{ 0x9487d3e1, "ns_capable" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0xf29a63f8, "rfkill_alloc" },
	{ 0x3dae8bda, "class_dev_iter_init" },
	{ 0x86490580, "current_task" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x3312881b, "device_del" },
	{ 0xfd6361e7, "__sock_recv_wifi_status" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x738737f9, "skb_unlink" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xff282521, "rfkill_register" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xdf54a8f7, "netlink_unregister_notifier" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0xf5e8df48, "sock_alloc_send_pskb" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x84823cf3, "nla_strscpy" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0xfdb9d649, "sock_no_ioctl" },
	{ 0xfa599bb2, "netlink_register_notifier" },
	{ 0x5849e6bc, "genl_unregister_family" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x420964e3, "__nla_parse" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0xe622b8c, "genl_register_family" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xae4cc05, "release_sock" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x7ce88a05, "class_find_device" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2642A225693A42491A1314B");
