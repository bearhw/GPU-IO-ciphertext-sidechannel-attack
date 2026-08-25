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
	{ 0x8520a781, "nla_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0x27fd6cee, "nf_ct_untimeout" },
	{ 0x37a0cba, "kfree" },
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0xdd7d2188, "nf_ct_helper_ext_add" },
	{ 0x415ee86c, "nf_conntrack_helper_put" },
	{ 0x84823cf3, "nla_strscpy" },
	{ 0xddb71190, "nf_conntrack_helper_try_module_get" },
	{ 0xb9b93c63, "nf_ct_set_auto_assign_helper_warned" },
	{ 0xd96ead83, "__nft_reg_track_cancel" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x38d85c39, "nft_dump_register" },
	{ 0xe2648860, "nft_reg_track_update" },
	{ 0x80f36393, "nft_expr_reduce_bitwise" },
	{ 0xe1da1c18, "nft_parse_register_store" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa916b694, "strnlen" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x2e0a33ae, "nf_ct_l4proto_find" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x420964e3, "__nla_parse" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x3b08a8f0, "nf_ct_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3b9dfc4b, "nf_ct_tmpl_alloc" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x6e819985, "nf_connlabels_put" },
	{ 0xe2b8cc13, "nft_parse_register_load" },
	{ 0x8c229db9, "nf_connlabels_get" },
	{ 0x7c6024bd, "init_net" },
	{ 0x4eb7d7bb, "nf_ct_expect_alloc" },
	{ 0xf1fc41fe, "nf_ct_expect_init" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xfe29d8d1, "nf_ct_expect_related_report" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0x73ef9dcd, "__nf_ct_refresh_acct" },
	{ 0x82b6160f, "nf_ct_ext_add" },
	{ 0x6115227b, "nf_connlabels_replace" },
	{ 0x86977087, "nf_ct_ecache_ext_add" },
	{ 0xd973b705, "nf_ct_get_id" },
	{ 0x9166fada, "strncpy" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x7f1125f0, "nft_register_expr" },
	{ 0x61688841, "nft_register_obj" },
	{ 0x497d4d0e, "nft_unregister_obj" },
	{ 0x68a43391, "nft_unregister_expr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack,nf_tables");


MODULE_INFO(srcversion, "A674EF425CC90F15C845728");
