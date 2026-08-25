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

SYMBOL_CRC(vsock_bind_table, 0x284e07d8, "_gpl");
SYMBOL_CRC(vsock_connected_table, 0x9bb6fd09, "_gpl");
SYMBOL_CRC(vsock_table_lock, 0xc92f7f50, "_gpl");
SYMBOL_CRC(vsock_insert_connected, 0x4aaa4f3b, "_gpl");
SYMBOL_CRC(vsock_remove_bound, 0x34e2d0a3, "_gpl");
SYMBOL_CRC(vsock_remove_connected, 0x7257feca, "_gpl");
SYMBOL_CRC(vsock_find_bound_socket, 0x55c18542, "_gpl");
SYMBOL_CRC(vsock_find_connected_socket, 0xeb9af979, "_gpl");
SYMBOL_CRC(vsock_remove_sock, 0xd2a932e7, "_gpl");
SYMBOL_CRC(vsock_for_each_connected_socket, 0xaf06b873, "_gpl");
SYMBOL_CRC(vsock_add_pending, 0xedfd14cf, "_gpl");
SYMBOL_CRC(vsock_remove_pending, 0xdd733bbb, "_gpl");
SYMBOL_CRC(vsock_enqueue_accept, 0x10a8eebf, "_gpl");
SYMBOL_CRC(vsock_assign_transport, 0x5924880d, "_gpl");
SYMBOL_CRC(vsock_find_cid, 0x90aa8549, "_gpl");
SYMBOL_CRC(vsock_create_connected, 0x29cb521e, "_gpl");
SYMBOL_CRC(vsock_stream_has_data, 0x5b75338b, "_gpl");
SYMBOL_CRC(vsock_stream_has_space, 0xa592e628, "_gpl");
SYMBOL_CRC(vsock_core_get_transport, 0xa7db9b36, "_gpl");
SYMBOL_CRC(vsock_core_register, 0x3d9baff6, "_gpl");
SYMBOL_CRC(vsock_core_unregister, 0xd5ab7c1a, "_gpl");
SYMBOL_CRC(vsock_add_tap, 0x91a950cf, "_gpl");
SYMBOL_CRC(vsock_remove_tap, 0x18744f54, "_gpl");
SYMBOL_CRC(vsock_deliver_tap, 0x5d0cae8f, "_gpl");
SYMBOL_CRC(vsock_addr_init, 0x3d4b0fca, "_gpl");
SYMBOL_CRC(vsock_addr_validate, 0xec96eadf, "_gpl");
SYMBOL_CRC(vsock_addr_bound, 0x4b99648c, "_gpl");
SYMBOL_CRC(vsock_addr_unbind, 0x0e9bc9b6, "_gpl");
SYMBOL_CRC(vsock_addr_equals_addr, 0xaf2674b5, "_gpl");
SYMBOL_CRC(vsock_addr_cast, 0x77c14317, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xda10ec3, "security_sock_graft" },
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbd505649, "consume_skb" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xf3fc8a70, "ns_capable_noaudit" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xed238617, "__put_cred" },
	{ 0x5e0d5e33, "sk_error_report" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x50171cd6, "sock_register" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x68764184, "proto_register" },
	{ 0xd0654aba, "woken_wake_function" },
	{ 0xc6cbbc89, "capable" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xedd17b31, "sock_get_timeout" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x86490580, "current_task" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x4708008a, "misc_register" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0xe06141e9, "security_sk_clone" },
	{ 0x842977c4, "sock_no_sendpage" },
	{ 0x5bdb7603, "sock_copy_user_timeval" },
	{ 0x3b48a9d9, "nonseekable_open" },
	{ 0x6d606913, "pv_ops" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xb308c97d, "wait_woken" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0xfdb9d649, "sock_no_ioctl" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "7299BC81FBC3A0F427BDDCE");
