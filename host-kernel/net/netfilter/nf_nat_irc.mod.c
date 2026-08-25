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
	{ 0x92997ed8, "_printk" },
	{ 0xe052320e, "nf_nat_follow_master" },
	{ 0xfe29d8d1, "nf_ct_expect_related_report" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa916b694, "strnlen" },
	{ 0x500685b4, "__nf_nat_mangle_tcp_packet" },
	{ 0x81e39ae6, "nf_ct_helper_log" },
	{ 0x13a0a56, "nf_ct_unexpect_related" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x41267473, "nf_nat_helper_unregister" },
	{ 0x9137028a, "nf_nat_irc_hook" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x693d67e1, "nf_nat_helper_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_nat,nf_conntrack,nf_conntrack_irc");


MODULE_INFO(srcversion, "C481E7EC416976675B71310");
