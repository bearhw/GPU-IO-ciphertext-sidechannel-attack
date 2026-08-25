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
	{ 0xe00aecba, "nf_defrag_ipv6_disable" },
	{ 0xbab6e799, "nf_defrag_ipv4_disable" },
	{ 0xe766aaf7, "nf_defrag_ipv6_enable" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x3ba8a9f3, "nf_defrag_ipv4_enable" },
	{ 0xec623802, "ipv6_find_hdr" },
	{ 0x3bb3c15d, "nf_tproxy_get_sock_v6" },
	{ 0x4a5a24c4, "nf_tproxy_laddr6" },
	{ 0x2c795cac, "sock_gen_put" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa3bdc4ed, "sock_edemux" },
	{ 0x15cc0609, "nf_tproxy_handle_time_wait6" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xfce16e7b, "nf_tproxy_get_sock_v4" },
	{ 0xb8751235, "nf_tproxy_laddr4" },
	{ 0x42a229bc, "nf_tproxy_handle_time_wait4" },
	{ 0x7b7451f4, "xt_register_targets" },
	{ 0x8b4eba64, "xt_unregister_targets" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_defrag_ipv6,nf_defrag_ipv4,nf_tproxy_ipv6,nf_tproxy_ipv4,x_tables");


MODULE_INFO(srcversion, "33F387C72D0CD6BB15ABF43");
