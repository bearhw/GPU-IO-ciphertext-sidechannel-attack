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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xb954f70a, "tcf_action_exec" },
	{ 0x8520a781, "nla_put" },
	{ 0xbbd5e70e, "tcf_exts_dump" },
	{ 0xb92e3849, "tcf_exts_dump_stats" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xb2e83b41, "__dev_get_by_index" },
	{ 0xa916b694, "strnlen" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x3f56328e, "tcf_exts_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xefaf2e4f, "tcf_queue_work" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xed491cdf, "tcf_exts_validate" },
	{ 0x85670f1d, "rtnl_is_locked" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x84823cf3, "nla_strscpy" },
	{ 0xb2d00eb2, "__dev_get_by_name" },
	{ 0x56470118, "__warn_printk" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xfe99c7ff, "register_tcf_proto_ops" },
	{ 0x5c68b240, "unregister_tcf_proto_ops" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "DDC2CF608FAD655FE7EA4C2");
