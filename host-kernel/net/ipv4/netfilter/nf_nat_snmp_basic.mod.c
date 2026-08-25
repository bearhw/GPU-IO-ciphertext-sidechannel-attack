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
	{ 0xe113bbbc, "csum_partial" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x81e39ae6, "nf_ct_helper_log" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0xe48f35f1, "nf_nat_snmp_hook" },
	{ 0x6b76129f, "skb_ensure_writable" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x924f2ced, "nf_conntrack_helper_unregister" },
	{ 0x3f9abf02, "nf_conntrack_helper_register" },
	{ 0x13ce87e8, "asn1_ber_decoder" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack,nf_conntrack_snmp");


MODULE_INFO(srcversion, "F9A637915F8F4B12ACC2B5A");
