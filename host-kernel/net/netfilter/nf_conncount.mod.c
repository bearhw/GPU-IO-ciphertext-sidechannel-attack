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

SYMBOL_CRC(nf_conncount_add, 0x65978067, "_gpl");
SYMBOL_CRC(nf_conncount_list_init, 0xded40268, "_gpl");
SYMBOL_CRC(nf_conncount_gc_list, 0xca3298b8, "_gpl");
SYMBOL_CRC(nf_conncount_count, 0x3bdf05c1, "_gpl");
SYMBOL_CRC(nf_conncount_init, 0x79b2a904, "_gpl");
SYMBOL_CRC(nf_conncount_cache_free, 0xf2a1dbb9, "_gpl");
SYMBOL_CRC(nf_conncount_destroy, 0x3fd74579, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0x18e60984, "__do_once_start" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xbe38f709, "__do_once_done" },
	{ 0x37a0cba, "kfree" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0xece784c2, "rb_first" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x6d606913, "pv_ops" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xaa28cd50, "nf_conntrack_find_get" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3b08a8f0, "nf_ct_destroy" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xfef216eb, "_raw_spin_trylock" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xca9360b5, "rb_next" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x800473f, "__cond_resched" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack");


MODULE_INFO(srcversion, "7371D995964A094D7A902DF");
