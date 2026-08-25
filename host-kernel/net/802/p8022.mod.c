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

SYMBOL_CRC(register_8022_client, 0x6682cf5e, "");
SYMBOL_CRC(unregister_8022_client, 0xed15fea9, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x241ed965, "llc_build_and_send_ui_pkt" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x5fe207b0, "llc_sap_open" },
	{ 0x37a0cba, "kfree" },
	{ 0xfeda0691, "llc_sap_close" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "llc");


MODULE_INFO(srcversion, "A71AFC2AA971C8922E8B7CB");
