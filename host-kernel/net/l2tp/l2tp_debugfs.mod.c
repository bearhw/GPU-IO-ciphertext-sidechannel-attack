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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x391de184, "seq_puts" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3195783f, "l2tp_session_dec_refcount" },
	{ 0x7c90c120, "l2tp_tunnel_dec_refcount" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x86490580, "current_task" },
	{ 0xa1f8a9e6, "get_net_ns_by_pid" },
	{ 0x23d8225b, "seq_open" },
	{ 0x37a0cba, "kfree" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x56a53f51, "seq_release" },
	{ 0x7b0a3df8, "l2tp_session_get_nth" },
	{ 0x58ac7f2e, "l2tp_tunnel_get_nth" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x92997ed8, "_printk" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xf2b11959, "seq_read" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "l2tp_core");


MODULE_INFO(srcversion, "D8960888293A9B574037A9F");
