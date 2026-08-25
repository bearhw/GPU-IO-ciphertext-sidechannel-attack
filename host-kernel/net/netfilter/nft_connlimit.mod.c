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
	{ 0x4629334c, "__preempt_count" },
	{ 0xca3298b8, "nf_conncount_gc_list" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xf2a1dbb9, "nf_conncount_cache_free" },
	{ 0x37a0cba, "kfree" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xded40268, "nf_conncount_list_init" },
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x65978067, "nf_conncount_add" },
	{ 0xc958e6b3, "nf_ct_get_tuplepr" },
	{ 0x5a6cdb52, "nf_ct_zone_dflt" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0x61688841, "nft_register_obj" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x497d4d0e, "nft_unregister_obj" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conncount,nf_conntrack,nf_tables");


MODULE_INFO(srcversion, "9C36D1030DFDAFC64E201A2");
