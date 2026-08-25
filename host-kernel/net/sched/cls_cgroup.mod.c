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
	{ 0x86490580, "current_task" },
	{ 0x37db8865, "task_cls_state" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xb954f70a, "tcf_action_exec" },
	{ 0x932b011f, "__tcf_em_tree_match" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x8520a781, "nla_put" },
	{ 0xbbd5e70e, "tcf_exts_dump" },
	{ 0x74272ecc, "tcf_em_tree_dump" },
	{ 0xb92e3849, "tcf_exts_dump_stats" },
	{ 0x812cebbe, "skb_trim" },
	{ 0x3f56328e, "tcf_exts_destroy" },
	{ 0x2a723f5a, "tcf_em_tree_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0x11b26ea6, "__put_net" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xefaf2e4f, "tcf_queue_work" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xed491cdf, "tcf_exts_validate" },
	{ 0x47c6539c, "tcf_em_tree_validate" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xfe99c7ff, "register_tcf_proto_ops" },
	{ 0x5c68b240, "unregister_tcf_proto_ops" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "37370F327F677AA371894EA");
