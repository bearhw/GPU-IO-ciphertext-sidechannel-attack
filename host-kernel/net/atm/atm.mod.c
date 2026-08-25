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

SYMBOL_CRC(register_atm_ioctl, 0x059f209e, "");
SYMBOL_CRC(deregister_atm_ioctl, 0x67023607, "");
SYMBOL_CRC(vcc_hash, 0x2cc2d52d, "");
SYMBOL_CRC(vcc_sklist_lock, 0x44c6e633, "");
SYMBOL_CRC(vcc_insert_socket, 0x31cbdc32, "");
SYMBOL_CRC(vcc_release_async, 0xf9a02593, "");
SYMBOL_CRC(vcc_process_recv_queue, 0xf728c38e, "");
SYMBOL_CRC(atm_dev_signal_change, 0x3e9936e5, "");
SYMBOL_CRC(atm_dev_release_vccs, 0x450ba0d5, "");
SYMBOL_CRC(register_atmdevice_notifier, 0xb09faf79, "_gpl");
SYMBOL_CRC(unregister_atmdevice_notifier, 0xcfb6a3da, "_gpl");
SYMBOL_CRC(atm_charge, 0x3926200e, "");
SYMBOL_CRC(atm_alloc_charge, 0xf0dba0fe, "");
SYMBOL_CRC(atm_pcr_goal, 0xf49bc67a, "");
SYMBOL_CRC(sonet_copy_stats, 0xaa024146, "");
SYMBOL_CRC(sonet_subtract_stats, 0x9feaf287, "");
SYMBOL_CRC(atm_init_aal5, 0x55045e31, "");
SYMBOL_CRC(atm_dev_lookup, 0x25e04082, "");
SYMBOL_CRC(atm_dev_register, 0x99d368a7, "");
SYMBOL_CRC(atm_dev_deregister, 0x1b1cdbe1, "");
SYMBOL_CRC(atm_proc_root, 0x4443d399, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbe888b32, "skb_put" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xbd505649, "consume_skb" },
	{ 0xe7d4daac, "seq_list_next" },
	{ 0x8f9c199c, "__get_user_2" },
	{ 0xf346231f, "seq_list_start_head" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x96848186, "scnprintf" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x37a0cba, "kfree" },
	{ 0x2bf33597, "proc_create_data" },
	{ 0xb6a022da, "remove_proc_subtree" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x3aca0190, "_raw_write_lock_irq" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x6d334118, "__get_user_8" },
	{ 0x1000e51, "schedule" },
	{ 0x50171cd6, "sock_register" },
	{ 0xf0a78158, "__sock_recv_cmsgs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2b9997fb, "atomic_notifier_chain_register" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x68764184, "proto_register" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x2121e851, "device_create_file" },
	{ 0xa1600c1b, "__class_register" },
	{ 0x7c6024bd, "init_net" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x894f2745, "sock_wake_async" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0xa906274e, "seq_putc" },
	{ 0x70cc876b, "class_unregister" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x422066d2, "device_register" },
	{ 0x3312881b, "device_del" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xfb578fc5, "memset" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xd3752c27, "atomic_notifier_call_chain" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7181db30, "atomic_notifier_chain_unregister" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x391de184, "seq_puts" },
	{ 0x86d7db3c, "sock_gettstamp" },
	{ 0xce8d534f, "_proc_mkdir" },
	{ 0xe71c4fef, "send_sig" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x754d539c, "strlen" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xae4cc05, "release_sock" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FA4D557F2441D05B918E94D");
