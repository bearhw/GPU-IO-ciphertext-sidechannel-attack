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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(udp_sock_create6, 0x0627234d, "_gpl");
SYMBOL_CRC(udp_tunnel6_xmit_skb, 0x6cf82542, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcf78d1e6, "sock_create_kern" },
	{ 0xbd9acb3b, "kernel_bind" },
	{ 0xf43e05f3, "kernel_sock_shutdown" },
	{ 0x6e5c0971, "sock_release" },
	{ 0x285fef57, "lock_sock_nested" },
	{ 0xae4cc05, "release_sock" },
	{ 0xf0ee15f5, "sock_bindtoindex" },
	{ 0x288ef7e1, "kernel_connect" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xdf27a4e5, "udp6_set_csum" },
	{ 0xa8037a64, "ip6_local_out" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "9F50A9632EDFF8B1C88BAE3");
