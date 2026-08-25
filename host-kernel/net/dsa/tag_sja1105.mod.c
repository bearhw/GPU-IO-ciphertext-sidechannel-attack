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
	{ 0x56dc6f0a, "kthread_destroy_worker" },
	{ 0x37a0cba, "kfree" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x16da6c69, "br_vlan_get_proto" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x99311936, "br_vlan_enabled" },
	{ 0x45ca5090, "dsa_tag_8021q_bridge_vid" },
	{ 0xb878d86c, "dsa_8021q_xmit" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xb0e602eb, "memmove" },
	{ 0x75e27164, "pskb_expand_head" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe6e15da0, "kthread_create_worker" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0xf13e1803, "vid_is_dsa_8021q" },
	{ 0xd31594b6, "dsa_tag_8021q_find_port_by_vbid" },
	{ 0x631bbd47, "br_vlan_get_info_rcu" },
	{ 0x6d63a14c, "skb_pull_rcsum" },
	{ 0x87549110, "netdev_warn" },
	{ 0x10a8ab8a, "dsa_8021q_rcv" },
	{ 0xd031cc6f, "dsa_switch_find" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0x59a2f0ee, "packing" },
	{ 0x284bf3d3, "pskb_trim_rcsum_slow" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x92997ed8, "_printk" },
	{ 0x7d78794c, "netdev_txq_to_tc" },
	{ 0x1dce07df, "dsa_tag_8021q_standalone_vid" },
	{ 0xf4753987, "kthread_queue_work" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xbe888b32, "skb_put" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe489931, "dsa_tag_drivers_register" },
	{ 0xf69aec4a, "dsa_tag_drivers_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "bridge,dsa_core");


MODULE_INFO(srcversion, "6C00928408F9BC8E52340B3");
