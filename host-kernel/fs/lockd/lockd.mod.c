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

SYMBOL_CRC(nlmclnt_init, 0x5106980f, "_gpl");
SYMBOL_CRC(nlmclnt_done, 0x0efde1cd, "_gpl");
SYMBOL_CRC(nlmclnt_proc, 0x1b201c84, "_gpl");
SYMBOL_CRC(nlmsvc_ops, 0x9b7f287d, "_gpl");
SYMBOL_CRC(lockd_up, 0x0f2b6770, "_gpl");
SYMBOL_CRC(lockd_down, 0x59fe30ca, "_gpl");
SYMBOL_CRC(nlmsvc_unlock_all_by_sb, 0xca3fb4a1, "_gpl");
SYMBOL_CRC(nlmsvc_unlock_all_by_ip, 0x77e35ccc, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x214071a1, "rpc_put_task" },
	{ 0xda88c5c, "svc_generic_rpcbind_set" },
	{ 0x78b762ec, "svc_wake_up" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0xca160458, "rpc_shutdown_client" },
	{ 0xf9a2fb03, "svc_bind" },
	{ 0x60eda3b5, "proc_create" },
	{ 0x9d1c2653, "svc_recv" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x68af92a9, "xdr_inline_decode" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x1fe1e1ad, "locks_end_grace" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x99f7371c, "refcount_dec_and_mutex_lock" },
	{ 0x6128b5fc, "__printk_ratelimit" },
	{ 0x9e61bb05, "set_freezable" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0x6df1aaf1, "kernel_sigaction" },
	{ 0x69acdf38, "memcpy" },
	{ 0x76b50580, "simple_transaction_get" },
	{ 0x37a0cba, "kfree" },
	{ 0x55d17cba, "vfs_test_lock" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0xed262ed7, "svc_exit_thread" },
	{ 0x1f2a9970, "rpc_ntop" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xe5919cb1, "xdr_encode_opaque" },
	{ 0x65994f1, "xdr_encode_opaque_fixed" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe41c93d, "param_get_ulong" },
	{ 0x685a8c47, "rpc_run_task" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xed238617, "__put_cred" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0xcf481a3b, "locks_in_grace" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x4482cdb, "__refrigerator" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2c71fbfb, "proc_dobool" },
	{ 0x483ce87d, "locks_lock_inode_wait" },
	{ 0x92997ed8, "_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xd691c6a9, "unregister_sysctl_table" },
	{ 0xbe6b26dd, "locks_release_private" },
	{ 0xa916b694, "strnlen" },
	{ 0xfe029963, "unregister_inetaddr_notifier" },
	{ 0xf9bda437, "locks_init_lock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x8fa68418, "__rpc_wait_for_completion_task" },
	{ 0x66dab246, "simple_transaction_release" },
	{ 0xdb551b32, "svc_xprt_put" },
	{ 0x800473f, "__cond_resched" },
	{ 0x61e876a5, "flush_signals" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xb4da330f, "svc_age_temp_xprts_now" },
	{ 0x57bc19d2, "down_write" },
	{ 0x7c6024bd, "init_net" },
	{ 0xce807a25, "up_write" },
	{ 0xe5492206, "svc_set_num_threads" },
	{ 0xce889e55, "svc_rpcb_cleanup" },
	{ 0xa07a37f0, "memchr" },
	{ 0xedbdb033, "svc_process" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xc6f3b3fc, "refcount_dec_if_one" },
	{ 0xcdead3e3, "xdr_init_decode" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x2331dbf0, "vfs_cancel_lock" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xec2e1c8f, "proc_doulongvec_minmax" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x53445f68, "nlm_debug" },
	{ 0xec507773, "freezing_slow_path" },
	{ 0x4c30766f, "rpc_create" },
	{ 0x86490580, "current_task" },
	{ 0xc0908dd0, "svc_destroy" },
	{ 0xde069776, "rpc_call_start" },
	{ 0x3311703d, "svc_create" },
	{ 0x23af578f, "default_llseek" },
	{ 0xb83fa370, "rpc_call_sync" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x83de54a1, "vfs_lock_file" },
	{ 0x3b9dae01, "rpc_delay" },
	{ 0x2fe252cc, "unregister_inet6addr_notifier" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xa8292d19, "svc_generic_init_request" },
	{ 0x668b19a1, "down_read" },
	{ 0x8d4a4542, "svc_set_client" },
	{ 0x16239ec4, "xdr_reserve_space" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xcbdb31ac, "rpc_force_rebind" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x45935925, "rpc_restart_call" },
	{ 0xb9492ed9, "svc_xprt_destroy_all" },
	{ 0x60352082, "register_inet6addr_notifier" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd77d91a9, "svc_find_xprt" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x7ab88a45, "system_freezing_cnt" },
	{ 0xa8181adf, "proc_dointvec" },
	{ 0x97ac8caf, "svc_print_addr" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0xf68285c0, "register_inetaddr_notifier" },
	{ 0xed016371, "locks_delete_block" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x659ad814, "locks_start_grace" },
	{ 0x5e06bc5c, "refcount_dec_and_lock" },
	{ 0x47c333ea, "param_get_int" },
	{ 0x6a449c4f, "register_sysctl_table" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x53b954a2, "up_read" },
	{ 0x236c3d2f, "svc_xprt_create" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x62aa5dc1, "locks_copy_lock" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2cdf87a1, "proc_dointvec_minmax" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sunrpc,grace");


MODULE_INFO(srcversion, "96066EE67863802C85715FC");
