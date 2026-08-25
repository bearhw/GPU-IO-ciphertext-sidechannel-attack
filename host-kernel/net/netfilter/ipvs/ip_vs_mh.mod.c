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
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0xcfd884a8, "__hsiphash_unaligned" },
	{ 0x1a7cf4e7, "ip_vs_scheduler_err" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xea124bd1, "gcd" },
	{ 0xb8b9f817, "kmalloc_order_trace" },
	{ 0x5d5ae2d0, "register_ip_vs_scheduler" },
	{ 0x47b77462, "unregister_ip_vs_scheduler" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_vs");


MODULE_INFO(srcversion, "EEFAF99718393E14655C135");
