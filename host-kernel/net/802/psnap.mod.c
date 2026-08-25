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

SYMBOL_CRC(register_snap_client, 0xfd8d6441, "");
SYMBOL_CRC(unregister_snap_client, 0xd30ba6c1, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x241ed965, "llc_build_and_send_ui_pkt" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0x37a0cba, "kfree" },
	{ 0x6d63a14c, "skb_pull_rcsum" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x5fe207b0, "llc_sap_open" },
	{ 0x92997ed8, "_printk" },
	{ 0xfeda0691, "llc_sap_close" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "llc");


MODULE_INFO(srcversion, "2C96DF8FCE99F86E0EEE474");
