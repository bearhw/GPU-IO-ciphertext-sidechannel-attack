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
	{ 0xe2d5255a, "strcmp" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xb549b1e4, "nf_route" },
	{ 0x535cd900, "ip6_mtu" },
	{ 0xe05b6928, "dst_release" },
	{ 0xe4ed0ac5, "ipv4_mtu" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6b76129f, "skb_ensure_writable" },
	{ 0xa5228d6e, "inet_proto_csum_replace4" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0xbe888b32, "skb_put" },
	{ 0xb0e602eb, "memmove" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x28fc4169, "ipv6_skip_exthdr" },
	{ 0x7b7451f4, "xt_register_targets" },
	{ 0x8b4eba64, "xt_unregister_targets" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "A7D727BC28D99608B33F6BC");
