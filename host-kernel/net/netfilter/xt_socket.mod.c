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
	{ 0xbab6e799, "nf_defrag_ipv4_disable" },
	{ 0xe00aecba, "nf_defrag_ipv6_disable" },
	{ 0x3ba8a9f3, "nf_defrag_ipv4_enable" },
	{ 0xe766aaf7, "nf_defrag_ipv6_enable" },
	{ 0x56470118, "__warn_printk" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x92997ed8, "_printk" },
	{ 0x9d58a9c, "nf_sk_lookup_slow_v6" },
	{ 0x2c795cac, "sock_gen_put" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x8eb22bf5, "nf_sk_lookup_slow_v4" },
	{ 0x7ec922ce, "xt_register_matches" },
	{ 0x4bb1f65e, "xt_unregister_matches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_defrag_ipv4,nf_defrag_ipv6,nf_socket_ipv6,nf_socket_ipv4,x_tables");


MODULE_INFO(srcversion, "CA044B9489DFE40B00FF330");
