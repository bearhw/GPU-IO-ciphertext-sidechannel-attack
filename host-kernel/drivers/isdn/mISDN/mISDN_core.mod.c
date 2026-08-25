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

SYMBOL_CRC(mISDN_register_device, 0xc5339c64, "");
SYMBOL_CRC(mISDN_unregister_device, 0xd822b137, "");
SYMBOL_CRC(mISDN_register_Bprotocol, 0x05f00e12, "");
SYMBOL_CRC(mISDN_unregister_Bprotocol, 0x733f357e, "");
SYMBOL_CRC(mISDNDevName4ch, 0xdd8a0720, "");
SYMBOL_CRC(mISDN_FsmNew, 0x9c928457, "");
SYMBOL_CRC(mISDN_FsmFree, 0x2348cc3c, "");
SYMBOL_CRC(mISDN_FsmEvent, 0xd5145151, "");
SYMBOL_CRC(mISDN_FsmChangeState, 0x50c2230c, "");
SYMBOL_CRC(mISDN_FsmInitTimer, 0x6047df40, "");
SYMBOL_CRC(mISDN_FsmDelTimer, 0x30d25b0d, "");
SYMBOL_CRC(mISDN_FsmAddTimer, 0x313b1fde, "");
SYMBOL_CRC(mISDN_FsmRestartTimer, 0x03a68066, "");
SYMBOL_CRC(mISDN_register_clock, 0xc3401729, "");
SYMBOL_CRC(mISDN_unregister_clock, 0xe8f617eb, "");
SYMBOL_CRC(mISDN_clock_update, 0x26236de8, "");
SYMBOL_CRC(mISDN_clock_get, 0xd285995f, "");
SYMBOL_CRC(mISDN_initdchannel, 0xd5a938fc, "");
SYMBOL_CRC(mISDN_initbchannel, 0x9ce1309f, "");
SYMBOL_CRC(mISDN_freedchannel, 0xb6e0a005, "");
SYMBOL_CRC(mISDN_clear_bchannel, 0xd057a352, "");
SYMBOL_CRC(mISDN_freebchannel, 0x222d708e, "");
SYMBOL_CRC(mISDN_ctrl_bchannel, 0x84052933, "");
SYMBOL_CRC(recv_Dchannel, 0xbb3fc6f8, "");
SYMBOL_CRC(recv_Echannel, 0x9987c730, "");
SYMBOL_CRC(recv_Bchannel, 0x72c9f6b2, "");
SYMBOL_CRC(recv_Dchannel_skb, 0xdb1b6c8d, "");
SYMBOL_CRC(recv_Bchannel_skb, 0xd2d06d15, "");
SYMBOL_CRC(get_next_dframe, 0xfcb51bb5, "");
SYMBOL_CRC(get_next_bframe, 0xbb2bf4ae, "");
SYMBOL_CRC(queue_ch_frame, 0x86f76de7, "");
SYMBOL_CRC(dchannel_senddata, 0xf294dd92, "");
SYMBOL_CRC(bchannel_senddata, 0x6d2e16a4, "");
SYMBOL_CRC(bchannel_get_rxbuf, 0x60ab036c, "");
SYMBOL_CRC(l1_event, 0x588886a6, "");
SYMBOL_CRC(create_l1, 0x71b337ed, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xddb27f7b, "skb_free_datagram" },
	{ 0xe914e41e, "strcpy" },
	{ 0x61802a13, "sock_queue_rcv_skb_reason" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbe888b32, "skb_put" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xbd505649, "consume_skb" },
	{ 0xa6257a2f, "complete" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x16eef981, "sock_no_sendmsg" },
	{ 0x62737e1d, "sock_unregister" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x27b0d5bd, "device_rename" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x37583cb4, "put_cmsg" },
	{ 0xdf2ebb87, "_raw_read_unlock_irqrestore" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x6b853d06, "ns_to_kernel_old_timeval" },
	{ 0x1000e51, "schedule" },
	{ 0x50171cd6, "sock_register" },
	{ 0xbfc24b6e, "datagram_poll" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xb1342cdb, "_raw_read_lock_irqsave" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xf4e44828, "class_for_each_device" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xa1600c1b, "__class_register" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x48098f3, "device_add" },
	{ 0x24d273d1, "add_timer" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xc3aaf0a9, "__put_user_1" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x9166fada, "strncpy" },
	{ 0x70cc876b, "class_unregister" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x5b8a40d1, "skb_copy_datagram_iter" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x3312881b, "device_del" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x4708008a, "misc_register" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x5928b1b, "sock_no_recvmsg" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xeb078aee, "_raw_write_unlock_irqrestore" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x3b48a9d9, "nonseekable_open" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x6d606913, "pv_ops" },
	{ 0x20c3e4b2, "skb_realloc_headroom" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xdd64e639, "strscpy" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x1f732c33, "skb_recv_datagram" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x636a2492, "no_llseek" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x5021bd81, "_raw_write_lock_irqsave" },
	{ 0x754d539c, "strlen" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xae4cc05, "release_sock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x7ce88a05, "class_find_device" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D46BFA4F4D38F4AAC4584E5");
