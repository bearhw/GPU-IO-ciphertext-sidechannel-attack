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
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaedc404e, "ntb_clear_ctx" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0x58e4bd20, "ntb_default_peer_port_number" },
	{ 0x88455b22, "ntb_set_ctx" },
	{ 0x9243b3bb, "ntb_link_event" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xff0ab6da, "debugfs_create_atomic_t" },
	{ 0x7cc2e6ed, "ntb_default_peer_port_count" },
	{ 0xa0f4e4b8, "ntb_default_port_number" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x716265c7, "debugfs_initialized" },
	{ 0x3dc25e18, "__ntb_register_client" },
	{ 0xd20d562, "ntb_unregister_client" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ntb");


MODULE_INFO(srcversion, "8E61D69C1F94C0C31082466");
