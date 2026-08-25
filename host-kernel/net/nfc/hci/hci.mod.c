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

SYMBOL_CRC(nfc_hci_result_to_errno, 0x74fe3670, "");
SYMBOL_CRC(nfc_hci_reset_pipes, 0x750e1d9d, "");
SYMBOL_CRC(nfc_hci_reset_pipes_per_host, 0xc64e6d6a, "");
SYMBOL_CRC(nfc_hci_sak_to_protocol, 0xdd231c55, "");
SYMBOL_CRC(nfc_hci_target_discovered, 0x59a6d418, "");
SYMBOL_CRC(nfc_hci_allocate_device, 0xce366624, "");
SYMBOL_CRC(nfc_hci_free_device, 0x15b5d70a, "");
SYMBOL_CRC(nfc_hci_register_device, 0x4d75af05, "");
SYMBOL_CRC(nfc_hci_unregister_device, 0xd33a93f4, "");
SYMBOL_CRC(nfc_hci_set_clientdata, 0xf2663b2b, "");
SYMBOL_CRC(nfc_hci_get_clientdata, 0x2798b021, "");
SYMBOL_CRC(nfc_hci_driver_failure, 0xa2389d5a, "");
SYMBOL_CRC(nfc_hci_recv_frame, 0x6f37c68f, "");
SYMBOL_CRC(nfc_hci_send_event, 0x1c013861, "");
SYMBOL_CRC(nfc_hci_send_cmd, 0x8530c943, "");
SYMBOL_CRC(nfc_hci_send_cmd_async, 0x3fd2679b, "");
SYMBOL_CRC(nfc_hci_set_param, 0x88e9c22b, "");
SYMBOL_CRC(nfc_hci_get_param, 0x29f305cd, "");
SYMBOL_CRC(nfc_hci_disconnect_gate, 0xa40fe680, "");
SYMBOL_CRC(nfc_hci_disconnect_all_gates, 0x8de47708, "");
SYMBOL_CRC(nfc_hci_connect_gate, 0x9fa3cbad, "");
SYMBOL_CRC(nfc_llc_start, 0x8b41cf0f, "");
SYMBOL_CRC(nfc_llc_stop, 0xe6f4d741, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbe888b32, "skb_put" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x12e88147, "nfc_unregister_device" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x3a2bcc99, "nfc_allocate_device" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x1000e51, "schedule" },
	{ 0x174b1084, "nfc_alloc_recv_skb" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xe7fa526d, "skb_dequeue_tail" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x17f6a6ad, "nfc_targets_found" },
	{ 0x4abc582a, "nfc_driver_failure" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc7d4730, "nfc_register_device" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nfc");


MODULE_INFO(srcversion, "B1723B0AF01D44A4E39D55E");
