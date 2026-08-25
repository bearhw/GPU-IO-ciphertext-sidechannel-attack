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

SYMBOL_CRC(v9fs_register_trans, 0x16cd7ad4, "");
SYMBOL_CRC(v9fs_unregister_trans, 0xed1b5526, "");
SYMBOL_CRC(v9fs_get_trans_by_name, 0x5f9a8239, "");
SYMBOL_CRC(v9fs_get_default_trans, 0x531205d0, "");
SYMBOL_CRC(p9_is_proto_dotl, 0x7f5fd60b, "");
SYMBOL_CRC(p9_is_proto_dotu, 0x7a270504, "");
SYMBOL_CRC(p9_show_client_options, 0x096ed6e5, "");
SYMBOL_CRC(p9_fcall_fini, 0x984c5e73, "");
SYMBOL_CRC(p9_tag_lookup, 0xbd07c956, "");
SYMBOL_CRC(p9_req_put, 0x1430723c, "");
SYMBOL_CRC(p9_client_cb, 0x28ac4d9b, "");
SYMBOL_CRC(p9_parse_header, 0xb79f25fd, "");
SYMBOL_CRC(p9_client_create, 0x2beb78b5, "");
SYMBOL_CRC(p9_client_destroy, 0x07858b03, "");
SYMBOL_CRC(p9_client_disconnect, 0x15839fc5, "");
SYMBOL_CRC(p9_client_begin_disconnect, 0x35427249, "");
SYMBOL_CRC(p9_client_attach, 0xbc301bb5, "");
SYMBOL_CRC(p9_client_walk, 0x31e7e741, "");
SYMBOL_CRC(p9_client_open, 0xef8af8b1, "");
SYMBOL_CRC(p9_client_create_dotl, 0x7c87d016, "");
SYMBOL_CRC(p9_client_fcreate, 0x865aed45, "");
SYMBOL_CRC(p9_client_symlink, 0x43aa9283, "");
SYMBOL_CRC(p9_client_link, 0xb724537f, "");
SYMBOL_CRC(p9_client_fsync, 0x75770956, "");
SYMBOL_CRC(p9_client_clunk, 0xa665a8fa, "");
SYMBOL_CRC(p9_client_remove, 0xe989acb9, "");
SYMBOL_CRC(p9_client_unlinkat, 0x7547ef52, "");
SYMBOL_CRC(p9_client_read, 0x533e91f7, "");
SYMBOL_CRC(p9_client_read_once, 0x02f67050, "");
SYMBOL_CRC(p9_client_write, 0xed949768, "");
SYMBOL_CRC(p9_client_stat, 0xe936ef94, "");
SYMBOL_CRC(p9_client_getattr_dotl, 0xc6470aa9, "");
SYMBOL_CRC(p9_client_wstat, 0x46cba599, "");
SYMBOL_CRC(p9_client_setattr, 0x1256f94a, "");
SYMBOL_CRC(p9_client_statfs, 0x7ad73088, "");
SYMBOL_CRC(p9_client_rename, 0xdd74fee4, "");
SYMBOL_CRC(p9_client_renameat, 0xcf22cbae, "");
SYMBOL_CRC(p9_client_xattrwalk, 0x07a5436a, "_gpl");
SYMBOL_CRC(p9_client_xattrcreate, 0xbe236661, "_gpl");
SYMBOL_CRC(p9_client_readdir, 0xeb403712, "");
SYMBOL_CRC(p9_client_mknod_dotl, 0x1fb3139f, "");
SYMBOL_CRC(p9_client_mkdir_dotl, 0xcb31d748, "");
SYMBOL_CRC(p9_client_lock_dotl, 0xb2f2c677, "");
SYMBOL_CRC(p9_client_getlock_dotl, 0x2ab18da3, "");
SYMBOL_CRC(p9_client_readlink, 0x30db3d49, "");
SYMBOL_CRC(p9_error_init, 0xe58a3360, "");
SYMBOL_CRC(p9_errstr2errno, 0x3d73a797, "");
SYMBOL_CRC(p9stat_free, 0xd384c683, "");
SYMBOL_CRC(p9stat_read, 0x41ce9823, "");
SYMBOL_CRC(p9dirent_read, 0x95bd8f96, "");
SYMBOL_CRC(p9_release_pages, 0xa014ecb9, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x10795da2, "__put_page" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x2d71b6c0, "_copy_to_iter" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0x20978fb9, "idr_find" },
	{ 0xb0e602eb, "memmove" },
	{ 0xd9916c3a, "idr_alloc_u32" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xcc4e4b3c, "iov_iter_advance" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0xcc5c2df4, "trace_print_symbols_seq" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xfb6af58d, "recalc_sigpending" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0xa916b694, "strnlen" },
	{ 0xc57c48a3, "idr_get_next" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x4e3567f7, "match_int" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0xc81314f9, "kmem_cache_create_usercopy" },
	{ 0x954f099c, "idr_preload" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x5a921311, "strncmp" },
	{ 0x7f78fd7e, "from_kgid" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x7971b0bb, "iov_iter_kvec" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x402830fd, "from_kuid" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xdc1da1c6, "make_kgid" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0xdd64e639, "strscpy" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x85df9b6c, "strsep" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0x44e9a829, "match_token" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x5e46cfc0, "_copy_from_iter" },
	{ 0xacf4d843, "match_strdup" },
	{ 0x391de184, "seq_puts" },
	{ 0x754d539c, "strlen" },
	{ 0x500313ed, "iov_iter_revert" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8B661B19CF12C486B127EEC");
