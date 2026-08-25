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
	{ 0x653d3208, "mptcp_diag_fill_info" },
	{ 0x3f75b1, "mptcp_token_get_sock" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0xefc35200, "netlink_net_capable" },
	{ 0xd7a3b1e2, "inet_sk_diag_fill" },
	{ 0xd1fcd028, "netlink_unicast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xc4dfa4ec, "inet_diag_bc_sk" },
	{ 0x800473f, "__cond_resched" },
	{ 0xe5f128df, "mptcp_token_iter_next" },
	{ 0xf341ee35, "tcp_hashinfo" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x720d3ca3, "inet_diag_register" },
	{ 0x915a0c88, "inet_diag_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "inet_diag");


MODULE_INFO(srcversion, "BF488DD632ABA6A71032F13");
