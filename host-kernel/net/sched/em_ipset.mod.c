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
	{ 0xbe1bbf53, "ip_set_nfnl_put" },
	{ 0x37a0cba, "kfree" },
	{ 0x7d0b6ea8, "ip_set_nfnl_get_byindex" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0xb9867643, "ip_set_test" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x5e9de322, "dev_get_by_index_rcu" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4699ca54, "tcf_em_register" },
	{ 0xb874ef43, "tcf_em_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_set");


MODULE_INFO(srcversion, "2FFEEF47248D946AED3F588");
