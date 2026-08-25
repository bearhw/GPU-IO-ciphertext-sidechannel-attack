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

SYMBOL_CRC(xt_rateest_lookup, 0x03608c7c, "_gpl");
SYMBOL_CRC(xt_rateest_put, 0xcccfbef6, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xded39a6b, "gen_kill_estimator" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xa916b694, "strnlen" },
	{ 0x18e60984, "__do_once_start" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xbe38f709, "__do_once_done" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x866a62b2, "gnet_stats_basic_sync_init" },
	{ 0x69acdf38, "memcpy" },
	{ 0x5e9a01ce, "gen_new_estimator" },
	{ 0x37a0cba, "kfree" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x67a704bf, "xt_register_target" },
	{ 0xa5d0ece2, "xt_unregister_target" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "9EF0DC96CACF72BA309163D");
