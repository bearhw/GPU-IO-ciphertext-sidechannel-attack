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
	{ 0xebef499b, "nf_ct_nat_ext_add" },
	{ 0xbf87fcb0, "nf_ct_expect_find_get" },
	{ 0x13a0a56, "nf_ct_unexpect_related" },
	{ 0x4cba5ac3, "nf_ct_expect_put" },
	{ 0x918169e8, "nf_nat_setup_info" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x500685b4, "__nf_nat_mangle_tcp_packet" },
	{ 0xf2a36612, "pptp_msg_name" },
	{ 0x3cd2de69, "nf_nat_pptp_hook" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_nat,nf_conntrack,nf_conntrack_pptp");


MODULE_INFO(srcversion, "C7C38083A615C69B600042D");
