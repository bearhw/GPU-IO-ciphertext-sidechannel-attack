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
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0xf49030d3, "__nf_ip6_route" },
	{ 0xe05b6928, "dst_release" },
	{ 0xbc769b5f, "ipv6_chk_addr" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd542439, "__ipv6_addr_type" },
	{ 0x1ac1e32b, "inet_dev_addr_type" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7ec922ce, "xt_register_matches" },
	{ 0x4bb1f65e, "xt_unregister_matches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "213C86A49406D11109A6DCD");
