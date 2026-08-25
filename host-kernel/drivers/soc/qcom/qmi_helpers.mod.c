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

SYMBOL_CRC(qmi_encode_message, 0x0ef12cc9, "");
SYMBOL_CRC(qmi_decode_message, 0x68772745, "");
SYMBOL_CRC(qmi_response_type_v01_ei, 0x21ce5888, "");
SYMBOL_CRC(qmi_add_lookup, 0x9ed125b3, "");
SYMBOL_CRC(qmi_add_server, 0x33eab7a6, "");
SYMBOL_CRC(qmi_txn_init, 0x1cda85e1, "");
SYMBOL_CRC(qmi_txn_wait, 0x11900ba7, "");
SYMBOL_CRC(qmi_txn_cancel, 0x8a02a490, "");
SYMBOL_CRC(qmi_handle_init, 0xc6374116, "");
SYMBOL_CRC(qmi_handle_release, 0xc5cd0290, "");
SYMBOL_CRC(qmi_send_request, 0xcfb3d4d9, "");
SYMBOL_CRC(qmi_send_response, 0x1b52523f, "");
SYMBOL_CRC(qmi_send_indication, 0xa2e53871, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x20978fb9, "idr_find" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xbbd13bd3, "kernel_recvmsg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x7c6024bd, "init_net" },
	{ 0x26ad0377, "kernel_getsockname" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x91f44510, "idr_alloc_cyclic" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xcf78d1e6, "sock_create_kern" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x6e5c0971, "sock_release" },
	{ 0x754d539c, "strlen" },
	{ 0x55ad2c95, "kernel_sendmsg" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D9C2A89249E32F8D1C33BDE");
