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

SYMBOL_CRC(g_token_size, 0x482ac5a4, "_gpl");
SYMBOL_CRC(g_make_token_header, 0x38d3dce5, "_gpl");
SYMBOL_CRC(g_verify_token_header, 0xd7673035, "_gpl");
SYMBOL_CRC(gss_mech_register, 0x8dba9065, "_gpl");
SYMBOL_CRC(gss_mech_unregister, 0x31a725c8, "_gpl");
SYMBOL_CRC(gss_mech_get, 0x777bb344, "");
SYMBOL_CRC(gss_pseudoflavor_to_service, 0x8164af62, "");
SYMBOL_CRC(gss_mech_put, 0xbcfb4bf9, "");
SYMBOL_CRC(svcauth_gss_flavor, 0x26853760, "_gpl");
SYMBOL_CRC(svcauth_gss_register_pseudoflavor, 0x321db71d, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x214071a1, "rpc_put_task" },
	{ 0xef464c28, "getboottime64" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0xe914e41e, "strcpy" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x10795da2, "__put_page" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xb28c35c8, "xdr_buf_trim" },
	{ 0x989b5a67, "rpc_find_or_alloc_pipe_dir_object" },
	{ 0x984a4df3, "xdr_buf_from_iov" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x704e125c, "xdr_write_pages" },
	{ 0xca160458, "rpc_shutdown_client" },
	{ 0xaeb41bc7, "auth_domain_find" },
	{ 0xb0e602eb, "memmove" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x68af92a9, "xdr_inline_decode" },
	{ 0xb3f41d30, "cache_create_net" },
	{ 0xcaef865a, "rpcauth_destroy_credcache" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0xb742fd7, "simple_strtol" },
	{ 0x4c75845f, "bpf_trace_run6" },
	{ 0x7923b5f2, "rpc_net_ns" },
	{ 0x416cd128, "read_bytes_from_xdr_buf" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x71bc40e3, "rpc_wake_up" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x96848186, "scnprintf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xa1e4c4b3, "sunrpc_cache_lookup_rcu" },
	{ 0xd5fd90f1, "prepare_to_wait" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0xcc5c2df4, "trace_print_symbols_seq" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xfc201b66, "sprint_oid" },
	{ 0x4e8f6ca7, "sunrpc_net_id" },
	{ 0x2bf33597, "proc_create_data" },
	{ 0x43d22fb9, "groups_alloc" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x9a504911, "rpcauth_unregister" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x2eabc3ca, "__module_get" },
	{ 0xe5919cb1, "xdr_encode_opaque" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc97e10e9, "rpc_sleep_on" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xd6eaaea1, "full_name_hash" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xed238617, "__put_cred" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6f04483c, "cache_purge" },
	{ 0x92997ed8, "_printk" },
	{ 0xb8e322a3, "rpc_release_client" },
	{ 0xe09411d9, "auth_domain_lookup" },
	{ 0x1000e51, "schedule" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x34d184de, "rpc_wake_up_status" },
	{ 0x4dac77f0, "xdr_encode_netobj" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6080969a, "svc_auth_register" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0xa916b694, "strnlen" },
	{ 0x7fea6a5, "rpc_destroy_pipe_data" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0x3a0ed473, "rpc_pipe_generic_upcall" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x365e7911, "kstrdup_const" },
	{ 0x800473f, "__cond_resched" },
	{ 0xb3340a34, "cache_unregister_net" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xcf88386e, "sunrpc_cache_unhash" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x2dd1ace0, "rpcauth_lookup_credcache" },
	{ 0xc8e96dea, "qword_addhex" },
	{ 0xb3f548ad, "kmemdup_nul" },
	{ 0xe97f4ce5, "qword_get" },
	{ 0x9643a510, "rpcauth_init_credcache" },
	{ 0x620c436, "sunrpc_cache_pipe_upcall_timeout" },
	{ 0xcdead3e3, "xdr_init_decode" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x9166fada, "strncpy" },
	{ 0x76026229, "rpc_call_null" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x7021fc9f, "rpc_sleep_on_timeout" },
	{ 0x4c30766f, "rpc_create" },
	{ 0x86490580, "current_task" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0xb83fa370, "rpc_call_sync" },
	{ 0x402830fd, "from_kuid" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xdc00de68, "rpc_queue_upcall" },
	{ 0xfb578fc5, "memset" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x6d5c4b72, "cache_check" },
	{ 0x31a89d59, "rpc_debug" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x123709d2, "svcauth_unix_set_client" },
	{ 0x879cf980, "xdr_buf_subsegment" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xcf4fdd4d, "_atomic_dec_and_lock" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0x56e04f7e, "rpc_remove_pipe_dir_object" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xf474fdcb, "kfree_const" },
	{ 0x16239ec4, "xdr_reserve_space" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x3b48a9d9, "nonseekable_open" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x99078b39, "trace_print_flags_seq" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7a43d9bc, "rpc_mkpipe_dentry" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x667e1bb1, "rpc_mkpipe_data" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xc609969, "gssd_running" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x732dd326, "groups_free" },
	{ 0xa33a719, "cache_register_net" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xd4330163, "xdr_inline_pages" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x56470118, "__warn_printk" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0x5a45ba31, "svc_auth_unregister" },
	{ 0xf0b7775d, "rpc_init_wait_queue" },
	{ 0x5904bcfe, "put_rpccred" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x2c694930, "rpc_unlink" },
	{ 0x294666a5, "rpcauth_wrap_req_encode" },
	{ 0xad73041f, "autoremove_wake_function" },
	{ 0xa23ffc04, "groups_sort" },
	{ 0x2a08161f, "from_kuid_munged" },
	{ 0xda80c241, "rpcauth_init_cred" },
	{ 0x5f210060, "xdr_decode_word" },
	{ 0x3854774b, "kstrtoll" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x64966af8, "cache_destroy_net" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xb4f551e7, "rpc_init_pipe_dir_object" },
	{ 0x349cba85, "strchr" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x4c06a761, "sunrpc_cache_update" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x66ed2439, "rpc_destroy_wait_queue" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xa4b6337, "auth_domain_put" },
	{ 0xdd655325, "xdr_shift_buf" },
	{ 0x39976333, "rpcauth_unwrap_resp_decode" },
	{ 0xbbc22e9b, "rpcauth_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sunrpc");


MODULE_INFO(srcversion, "5274D751687C4DAA139B105");
