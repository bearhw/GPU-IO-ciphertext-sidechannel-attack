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
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd53c67b3, "unregister_net_sysctl_table" },
	{ 0x7c6024bd, "init_net" },
	{ 0x37a0cba, "kfree" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x3e2da886, "init_user_ns" },
	{ 0xb8329e66, "register_net_sysctl" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x1a7cf4e7, "ip_vs_scheduler_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x5d5ae2d0, "register_ip_vs_scheduler" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x47b77462, "unregister_ip_vs_scheduler" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0xdf6b082f, "proc_dointvec_jiffies" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_vs");


MODULE_INFO(srcversion, "AB2C2F625DD9784DD84884B");
