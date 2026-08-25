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
	{ 0x37a0cba, "kfree" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x800473f, "__cond_resched" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x47884890, "system_power_efficient_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x2dea39bb, "proc_mkdir" },
	{ 0xa875b7e, "remove_proc_entry" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x999e8297, "vfree" },
	{ 0x99f7371c, "refcount_dec_and_mutex_lock" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x944375db, "_totalram_pages" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xfb578fc5, "memset" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0xd1b0de59, "proc_create_seq_private" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x92997ed8, "_printk" },
	{ 0x48012e28, "xt_check_proc_name" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6d606913, "pv_ops" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x7ec922ce, "xt_register_matches" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x4bb1f65e, "xt_unregister_matches" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "1B252D4060FF09CC633A32A");
