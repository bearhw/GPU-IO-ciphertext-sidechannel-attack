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

SYMBOL_CRC(nci_get_conn_info_by_dest_type_params, 0xca81b001, "");
SYMBOL_CRC(nci_req_complete, 0x62a61abc, "");
SYMBOL_CRC(nci_prop_cmd, 0x4ac48516, "");
SYMBOL_CRC(nci_core_cmd, 0x2dbe4f2f, "");
SYMBOL_CRC(nci_core_reset, 0x96f90d78, "");
SYMBOL_CRC(nci_core_init, 0x95078ab4, "");
SYMBOL_CRC(nci_nfcc_loopback, 0xe46f473b, "");
SYMBOL_CRC(nci_set_config, 0x07089bca, "");
SYMBOL_CRC(nci_nfcee_discover, 0x6532d135, "");
SYMBOL_CRC(nci_nfcee_mode_set, 0x7ab19323, "");
SYMBOL_CRC(nci_core_conn_create, 0x3a42e9a5, "");
SYMBOL_CRC(nci_core_conn_close, 0x35422fa6, "");
SYMBOL_CRC(nci_allocate_device, 0x4849e2d8, "");
SYMBOL_CRC(nci_free_device, 0x1e92577c, "");
SYMBOL_CRC(nci_register_device, 0xcbbb7ff4, "");
SYMBOL_CRC(nci_unregister_device, 0x6c434492, "");
SYMBOL_CRC(nci_recv_frame, 0xbd44746e, "");
SYMBOL_CRC(nci_send_frame, 0x8642f0cd, "");
SYMBOL_CRC(nci_send_cmd, 0x9687a9f1, "");
SYMBOL_CRC(nci_conn_max_data_pkt_payload_size, 0xcad2c0ce, "");
SYMBOL_CRC(nci_send_data, 0x7d8a640a, "");
SYMBOL_CRC(nci_to_errno, 0xba490602, "");
SYMBOL_CRC(nci_hci_send_event, 0xc21b3b48, "");
SYMBOL_CRC(nci_hci_send_cmd, 0x7974ba84, "");
SYMBOL_CRC(nci_hci_clear_all_pipes, 0x2ed27f41, "");
SYMBOL_CRC(nci_hci_open_pipe, 0x7fa2d977, "");
SYMBOL_CRC(nci_hci_set_param, 0xa9559586, "");
SYMBOL_CRC(nci_hci_get_param, 0x5b7b5dce, "");
SYMBOL_CRC(nci_hci_connect_gate, 0x58b84b77, "");
SYMBOL_CRC(nci_hci_dev_session_init, 0xe7de3b80, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xbe888b32, "skb_put" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x12e88147, "nfc_unregister_device" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x3a2bcc99, "nfc_allocate_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xb22d7a04, "nfc_tm_data_received" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0x731eddca, "nfc_tm_deactivated" },
	{ 0xf02aa937, "wait_for_completion_interruptible_timeout" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x174b1084, "nfc_alloc_recv_skb" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7162243a, "nfc_get_local_general_bytes" },
	{ 0x5af25e3, "nfc_set_remote_general_bytes" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xe1e427d8, "nfc_tm_activated" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x17f6a6ad, "nfc_targets_found" },
	{ 0x789a96f2, "nfc_dep_link_is_up" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xd3b8ef40, "nfc_send_to_raw_sock" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc7d4730, "nfc_register_device" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nfc");


MODULE_INFO(srcversion, "E077DB757803180E24F1885");
