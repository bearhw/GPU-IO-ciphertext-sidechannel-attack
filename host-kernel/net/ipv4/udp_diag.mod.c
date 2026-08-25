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
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xc4dfa4ec, "inet_diag_bc_sk" },
	{ 0xd7a3b1e2, "inet_sk_diag_fill" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xd4d1983c, "udplite_table" },
	{ 0x95a67b07, "udp_table" },
	{ 0x6385a95b, "__udp4_lib_lookup" },
	{ 0x2ec631e3, "sock_diag_check_cookie" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x2cd97432, "__udp6_lib_lookup" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xb6af2b3d, "sock_diag_destroy" },
	{ 0x720d3ca3, "inet_diag_register" },
	{ 0x915a0c88, "inet_diag_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "inet_diag");


MODULE_INFO(srcversion, "A6913F04E5CF94B0DEC8CAB");
