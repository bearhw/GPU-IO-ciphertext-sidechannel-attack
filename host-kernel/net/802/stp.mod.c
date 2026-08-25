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

SYMBOL_CRC(stp_proto_register, 0xe8ac1889, "_gpl");
SYMBOL_CRC(stp_proto_unregister, 0x54aef0e8, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x5fe207b0, "llc_sap_open" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xfeda0691, "llc_sap_close" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "llc");


MODULE_INFO(srcversion, "6AEBB72A8A6FF2BF9226E29");
