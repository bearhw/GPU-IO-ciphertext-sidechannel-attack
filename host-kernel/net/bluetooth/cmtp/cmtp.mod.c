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


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x14b1fdc3, "bt_procfs_cleanup" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xbe888b32, "skb_put" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x623ea7b3, "detach_capi_ctr" },
	{ 0xfa779867, "bt_procfs_init" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xaf468156, "set_user_nice" },
	{ 0x16eef981, "sock_no_sendmsg" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xf38617e3, "proto_unregister" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa916b694, "strnlen" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x68764184, "proto_register" },
	{ 0xd0654aba, "woken_wake_function" },
	{ 0xc6cbbc89, "capable" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x1de23e95, "module_put" },
	{ 0x800473f, "__cond_resched" },
	{ 0xf9b939ef, "bt_sock_link" },
	{ 0x92bb6262, "sock_no_shutdown" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xd28f6a7f, "fput" },
	{ 0x57bc19d2, "down_write" },
	{ 0x7c6024bd, "init_net" },
	{ 0xce807a25, "up_write" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x8fea24bd, "bt_sock_unregister" },
	{ 0xb90f0461, "__module_put_and_kthread_exit" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x121c7732, "sock_no_accept" },
	{ 0xfc85905d, "sock_no_listen" },
	{ 0x9166fada, "strncpy" },
	{ 0xd684322b, "capi_ctr_ready" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0x8cb81e1a, "l2cap_is_socket" },
	{ 0x86490580, "current_task" },
	{ 0x13d29713, "sk_alloc" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0xf3895984, "bt_sock_unlink" },
	{ 0x5928b1b, "sock_no_recvmsg" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x718b8b7, "bt_info" },
	{ 0x7b8c32f1, "bt_err" },
	{ 0x668b19a1, "down_read" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xf0f5849e, "capi_ctr_down" },
	{ 0x644f1f0d, "bt_sock_register" },
	{ 0x18c78aba, "capi_ctr_handle_message" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xb308c97d, "wait_woken" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0xac24667c, "attach_capi_ctr" },
	{ 0x6194c18d, "sockfd_lookup" },
	{ 0x55ad2c95, "kernel_sendmsg" },
	{ 0x53b954a2, "up_read" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "bluetooth,kernelcapi");


MODULE_INFO(srcversion, "5977D9388A729AFF2144BCF");
