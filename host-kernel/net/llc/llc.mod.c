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

SYMBOL_CRC(llc_sap_list, 0x52d7b2fd, "");
SYMBOL_CRC(llc_sap_find, 0x5cc1f0f5, "");
SYMBOL_CRC(llc_sap_open, 0x5fe207b0, "");
SYMBOL_CRC(llc_sap_close, 0xfeda0691, "");
SYMBOL_CRC(llc_add_pack, 0xf446bc54, "");
SYMBOL_CRC(llc_remove_pack, 0x38b92846, "");
SYMBOL_CRC(llc_set_station_handler, 0xbbd66916, "");
SYMBOL_CRC(llc_mac_hdr_init, 0xe55365b5, "");
SYMBOL_CRC(llc_build_and_send_ui_pkt, 0x241ed965, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbd505649, "consume_skb" },
	{ 0x32f9ade2, "dev_add_pack" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7c6024bd, "init_net" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x33ece49c, "dev_remove_pack" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xd7ae75a, "__dev_queue_xmit" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x9113ba1b, "skb_clone" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x284bf3d3, "pskb_trim_rcsum_slow" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x609f1c7e, "synchronize_net" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "76622FCE4A942E29D39E769");
