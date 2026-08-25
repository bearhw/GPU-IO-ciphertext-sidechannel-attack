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
	{ 0x103245e2, "unregister_ip_vs_app" },
	{ 0x38922c4e, "register_ip_vs_app" },
	{ 0x12165d82, "register_ip_vs_app_inc" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x96b29254, "strncasecmp" },
	{ 0xac5fcec0, "in4_pton" },
	{ 0x609bcd98, "in6_pton" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2d15a0ec, "ip_vs_conn_out_get" },
	{ 0xa916b694, "strnlen" },
	{ 0x455a7f67, "ip_vs_tcp_conn_listen" },
	{ 0xcb299094, "ip_vs_conn_put" },
	{ 0x500685b4, "__nf_nat_mangle_tcp_packet" },
	{ 0xe22a0271, "ip_vs_nfct_expect_related" },
	{ 0x87754b55, "ip_vs_conn_new" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x6b76129f, "skb_ensure_writable" },
	{ 0xde06188a, "ip_vs_conn_in_get" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x786109b9, "param_array_ops" },
	{ 0x5897cdd4, "param_ops_ushort" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ip_vs,nf_nat");


MODULE_INFO(srcversion, "9C9835176D249C1D8579438");
