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
	{ 0x4be87808, "ip_vs_new_conn_out" },
	{ 0xeedf6f72, "ct_sip_get_header" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0xec623802, "ipv6_find_hdr" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xb0233d02, "register_ip_vs_pe" },
	{ 0x2a5dc1f3, "unregister_ip_vs_pe" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_vs,nf_conntrack_sip");


MODULE_INFO(srcversion, "C9C76B0127BA9FB1A4B93EC");
