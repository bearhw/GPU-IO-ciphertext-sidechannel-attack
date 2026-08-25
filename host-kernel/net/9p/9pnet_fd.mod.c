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
	{ 0x49e120bd, "__sock_create" },
	{ 0x1430723c, "p9_req_put" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x46ed28d8, "fget" },
	{ 0xbd9acb3b, "kernel_bind" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x90cf6253, "sock_alloc_file" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd28f6a7f, "fput" },
	{ 0x4e3567f7, "match_int" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x8d70148e, "kernel_read" },
	{ 0xbd07c956, "p9_tag_lookup" },
	{ 0xb79f25fd, "p9_parse_header" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0x85df9b6c, "strsep" },
	{ 0x16cd7ad4, "v9fs_register_trans" },
	{ 0x44e9a829, "match_token" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x6e5c0971, "sock_release" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0x1b6314fd, "in_aton" },
	{ 0xed1b5526, "v9fs_unregister_trans" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x28ac4d9b, "p9_client_cb" },
	{ 0x754d539c, "strlen" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xdd6a20bc, "kernel_write" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "9pnet");


MODULE_INFO(srcversion, "75FEB3B59B9B2D31AA6E2DB");
