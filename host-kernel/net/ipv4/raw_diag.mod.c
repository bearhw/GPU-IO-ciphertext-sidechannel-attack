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
	{ 0xefc35200, "netlink_net_capable" },
	{ 0xed7c7b91, "raw_v6_hashinfo" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0xc4dfa4ec, "inet_diag_bc_sk" },
	{ 0xd7a3b1e2, "inet_sk_diag_fill" },
	{ 0xb510c250, "raw_v4_hashinfo" },
	{ 0x2aa8f50e, "__raw_v6_lookup" },
	{ 0x8bd13a40, "__raw_v4_lookup" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb6af2b3d, "sock_diag_destroy" },
	{ 0xa0552c2d, "sk_free" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x720d3ca3, "inet_diag_register" },
	{ 0x915a0c88, "inet_diag_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "inet_diag");


MODULE_INFO(srcversion, "B89FC66243B6A49A14306DB");
