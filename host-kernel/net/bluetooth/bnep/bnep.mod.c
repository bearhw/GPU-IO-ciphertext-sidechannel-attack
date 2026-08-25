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
	{ 0xcdbdcb7a, "unregister_netdev" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0xfa779867, "bt_procfs_init" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0xaf468156, "set_user_nice" },
	{ 0x16eef981, "sock_no_sendmsg" },
	{ 0x4df02057, "crc32_be" },
	{ 0x69acdf38, "memcpy" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x9977539, "eth_validate_addr" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0x5d0e791b, "sock_no_connect" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0xa32fb801, "ether_setup" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0xc095e884, "eth_type_trans" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0xf38617e3, "proto_unregister" },
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
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf9b939ef, "bt_sock_link" },
	{ 0x92bb6262, "sock_no_shutdown" },
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
	{ 0x45bacc1f, "register_netdev" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x7b5ce5c3, "baswap" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xd0419ee0, "sock_no_bind" },
	{ 0x8cb81e1a, "l2cap_is_socket" },
	{ 0x86490580, "current_task" },
	{ 0x13d29713, "sk_alloc" },
	{ 0xbd079331, "netif_tx_wake_queue" },
	{ 0x7a5212e2, "sock_no_socketpair" },
	{ 0xf3895984, "bt_sock_unlink" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x5928b1b, "sock_no_recvmsg" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3932d27c, "sock_no_mmap" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x1c1f8ce8, "netif_rx" },
	{ 0x718b8b7, "bt_info" },
	{ 0x7b8c32f1, "bt_err" },
	{ 0x668b19a1, "down_read" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x644f1f0d, "bt_sock_register" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xe9628893, "sock_no_getname" },
	{ 0xb308c97d, "wait_woken" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6194c18d, "sockfd_lookup" },
	{ 0x55ad2c95, "kernel_sendmsg" },
	{ 0x53b954a2, "up_read" },
	{ 0x3811c23d, "sock_init_data" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "bluetooth");


MODULE_INFO(srcversion, "9B81BD6253270BF3BBDADA1");
