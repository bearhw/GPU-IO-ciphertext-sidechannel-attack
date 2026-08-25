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
	{ 0xbd079331, "netif_tx_wake_queue" },
	{ 0xb9492e46, "skb_queue_purge" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xc46d0af0, "qdisc_reset" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x56470118, "__warn_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x76dc93bd, "noop_qdisc" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xacbdf341, "neigh_lookup" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xfef216eb, "_raw_spin_trylock" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5f454dc5, "softnet_data" },
	{ 0x6d606913, "pv_ops" },
	{ 0xf5d59d1d, "neigh_destroy" },
	{ 0x4ccc1ddf, "__neigh_create" },
	{ 0xc6df469b, "__neigh_event_send" },
	{ 0xbd505649, "consume_skb" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x71675dfb, "alloc_netdev_mqs" },
	{ 0x45bacc1f, "register_netdev" },
	{ 0xa916b694, "strnlen" },
	{ 0x1d68ea93, "register_qdisc" },
	{ 0xcdbdcb7a, "unregister_netdev" },
	{ 0x9a79e1d0, "free_netdev" },
	{ 0x54ff57f4, "unregister_qdisc" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "A1428F5793E742EBA1F76FB");
