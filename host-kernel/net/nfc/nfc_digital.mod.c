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

SYMBOL_CRC(nfc_digital_allocate_device, 0xf88dca58, "");
SYMBOL_CRC(nfc_digital_free_device, 0x99ca891b, "");
SYMBOL_CRC(nfc_digital_register_device, 0x53c62fd2, "");
SYMBOL_CRC(nfc_digital_unregister_device, 0xf4abfe72, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbe888b32, "skb_put" },
	{ 0xbd505649, "consume_skb" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x12e88147, "nfc_unregister_device" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x3a2bcc99, "nfc_allocate_device" },
	{ 0x52ecbc75, "crc_ccitt" },
	{ 0xb22d7a04, "nfc_tm_data_received" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x9fa78973, "__pskb_copy_fclone" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x174b1084, "nfc_alloc_recv_skb" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xa0cf1873, "skb_copy_expand" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7162243a, "nfc_get_local_general_bytes" },
	{ 0x5af25e3, "nfc_set_remote_general_bytes" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe1e427d8, "nfc_tm_activated" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x17f6a6ad, "nfc_targets_found" },
	{ 0x789a96f2, "nfc_dep_link_is_up" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x9a34a2b, "crc_itu_t" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc7d4730, "nfc_register_device" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nfc,crc-itu-t");


MODULE_INFO(srcversion, "AF7C1C299F86F5AEE263B29");
