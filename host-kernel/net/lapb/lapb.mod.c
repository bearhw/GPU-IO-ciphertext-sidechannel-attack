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

SYMBOL_CRC(lapb_register, 0x59f546a8, "");
SYMBOL_CRC(lapb_unregister, 0x2b7d4cd0, "");
SYMBOL_CRC(lapb_getparms, 0x2d06a56c, "");
SYMBOL_CRC(lapb_setparms, 0x389fc054, "");
SYMBOL_CRC(lapb_connect_request, 0xcb050dc9, "");
SYMBOL_CRC(lapb_disconnect_request, 0xdc86f08f, "");
SYMBOL_CRC(lapb_data_request, 0x8b24c83a, "");
SYMBOL_CRC(lapb_data_received, 0x2f1bc9a5, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbe888b32, "skb_put" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x51a511eb, "_raw_write_lock_bh" },
	{ 0x37a0cba, "kfree" },
	{ 0xaeb082ad, "_raw_read_unlock_bh" },
	{ 0x8dee722d, "_raw_read_lock_bh" },
	{ 0xe7ab1ecc, "_raw_write_unlock_bh" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0x7c6024bd, "init_net" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0x24d273d1, "add_timer" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc5c1e5c7, "skb_set_owner_w" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x7fab6d60, "skb_copy" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x3b9bf9ff, "skb_append" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8323997AE97C76739C548AF");
