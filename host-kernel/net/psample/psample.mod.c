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

SYMBOL_CRC(psample_group_get, 0xe91ed9f6, "_gpl");
SYMBOL_CRC(psample_group_take, 0x3697b814, "_gpl");
SYMBOL_CRC(psample_group_put, 0x6279704b, "_gpl");
SYMBOL_CRC(psample_sample_packet, 0x6a32b937, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x2ae031ab, "genlmsg_put" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa12be669, "__alloc_skb" },
	{ 0x6e3d9d78, "netlink_broadcast" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xbe888b32, "skb_put" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0xe622b8c, "genl_register_family" },
	{ 0x5849e6bc, "genl_unregister_family" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "E58368EF8E8C33C7F55877A");
