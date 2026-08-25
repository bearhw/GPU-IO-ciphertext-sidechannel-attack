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
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x5fac85af, "tcf_idrinfo_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x3697b814, "psample_group_take" },
	{ 0x6279704b, "psample_group_put" },
	{ 0xb0d72d67, "tcf_action_update_stats" },
	{ 0x1fecca28, "tcf_generic_walker" },
	{ 0x6c82ac38, "tcf_idr_search" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x8520a781, "nla_put" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x7d0db45c, "jiffies_to_clock_t" },
	{ 0xdc1885ea, "nla_put_64bit" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xa0ccec95, "tcf_idr_check_alloc" },
	{ 0x98233750, "tcf_action_check_ctrlact" },
	{ 0xe91ed9f6, "psample_group_get" },
	{ 0x77c89692, "tcf_action_set_ctrlact" },
	{ 0xee12f7aa, "tcf_chain_put_by_act" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x8b91cbe3, "tcf_idr_release" },
	{ 0xe43ef545, "tcf_idr_create" },
	{ 0xae55b187, "tcf_idr_cleanup" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x6a32b937, "psample_sample_packet" },
	{ 0x74a3d5c0, "skb_pull" },
	{ 0xe66395f2, "tcf_register_action" },
	{ 0x11d85980, "tcf_unregister_action" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "psample");


MODULE_INFO(srcversion, "2392893AA9BDBFF7272EB89");
