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

SYMBOL_CRC(qcom_glink_native_probe, 0x48120335, "_gpl");
SYMBOL_CRC(qcom_glink_native_remove, 0x149236da, "_gpl");
SYMBOL_CRC(qcom_glink_native_unregister, 0xfd2d5a1d, "_gpl");
SYMBOL_CRC(qcom_glink_ssr_notify, 0xf14f5684, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x83567b99, "mbox_send_message" },
	{ 0xddf6ad7a, "completion_done" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x20978fb9, "idr_find" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xb9c37021, "mbox_free_channel" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x907d14d, "blocking_notifier_chain_register" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x823eae06, "blocking_notifier_call_chain" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa916b694, "strnlen" },
	{ 0xc57c48a3, "idr_get_next" },
	{ 0x800473f, "__cond_resched" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xc045240, "__register_rpmsg_driver" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xfbb8a761, "strscpy_pad" },
	{ 0xcde91d2c, "unregister_rpmsg_driver" },
	{ 0xbfc360e, "mbox_client_txdone" },
	{ 0x9166fada, "strncpy" },
	{ 0xa46f34a4, "rpmsg_register_device_override" },
	{ 0x3fd239e3, "mbox_request_channel" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x91f44510, "idr_alloc_cyclic" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0xdd64e639, "strscpy" },
	{ 0x4ece3615, "blocking_notifier_chain_unregister" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xe483dc39, "rpmsg_register_device" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd9f95029, "rpmsg_send" },
	{ 0xde5a9b9, "device_add_groups" },
	{ 0xb16952e2, "rpmsg_unregister_device" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "rpmsg_core");


MODULE_INFO(srcversion, "7C8EEA123BF4292AF001922");
