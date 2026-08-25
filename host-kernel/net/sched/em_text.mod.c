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
	{ 0x9166fada, "strncpy" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2f379280, "nla_put_nohdr" },
	{ 0x3394be1, "nla_append" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x44536dd2, "textsearch_destroy" },
	{ 0x9b7caa3d, "textsearch_prepare" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x7bd1658f, "skb_find_text" },
	{ 0x4699ca54, "tcf_em_register" },
	{ 0xb874ef43, "tcf_em_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0E54FFEB488B5E351B0E649");
