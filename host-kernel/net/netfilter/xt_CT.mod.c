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
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x415ee86c, "nf_conntrack_helper_put" },
	{ 0xda86c0fa, "nf_ct_netns_put" },
	{ 0xcce6e49d, "nf_ct_destroy_timeout" },
	{ 0x3b08a8f0, "nf_ct_destroy" },
	{ 0x89d99ee1, "__nf_ct_ext_find" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4bebc483, "nf_ct_netns_get" },
	{ 0x3b9dfc4b, "nf_ct_tmpl_alloc" },
	{ 0x86977087, "nf_ct_ecache_ext_add" },
	{ 0x7bc5c9e5, "nf_ct_tmpl_free" },
	{ 0xa916b694, "strnlen" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xddb71190, "nf_conntrack_helper_try_module_get" },
	{ 0xdd7d2188, "nf_ct_helper_ext_add" },
	{ 0x2e0a33ae, "nf_ct_l4proto_find" },
	{ 0xa8c27b5, "nf_ct_set_timeout" },
	{ 0x92997ed8, "_printk" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x67a704bf, "xt_register_target" },
	{ 0x7b7451f4, "xt_register_targets" },
	{ 0xa5d0ece2, "xt_unregister_target" },
	{ 0x8b4eba64, "xt_unregister_targets" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_conntrack,x_tables");


MODULE_INFO(srcversion, "C013D983E5ACFDD4EEF3CFF");
