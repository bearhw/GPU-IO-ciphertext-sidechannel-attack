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

SYMBOL_CRC(nf_tproxy_laddr6, 0x4a5a24c4, "_gpl");
SYMBOL_CRC(nf_tproxy_handle_time_wait6, 0x15cc0609, "_gpl");
SYMBOL_CRC(nf_tproxy_get_sock_v6, 0x3bb3c15d, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xf341ee35, "tcp_hashinfo" },
	{ 0xc55c35e3, "__inet6_lookup_established" },
	{ 0x1838fe0d, "udp6_lib_lookup" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x16836ff1, "inet6_lookup_listener" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x5ef1ee12, "inet_twsk_deschedule_put" },
	{ 0x283c2885, "inet_twsk_put" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5ADD49EF3A226C401CCF6A2");
