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
	{ 0x37a0cba, "kfree" },
	{ 0x3678191d, "dev_get_by_name_rcu" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xc3eac2ae, "__netlink_dump_start" },
	{ 0x1de23e95, "module_put" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x84823cf3, "nla_strscpy" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa916b694, "strnlen" },
	{ 0xdd64e639, "strscpy" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbc110b45, "__nlmsg_put" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x349cba85, "strchr" },
	{ 0x754d539c, "strlen" },
	{ 0x8520a781, "nla_put" },
	{ 0x812cebbe, "skb_trim" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x6fea8456, "nfnetlink_subsys_register" },
	{ 0x6ece208b, "nfnetlink_subsys_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nfnetlink");


MODULE_INFO(srcversion, "AABB3AA99C74A94F6A0E119");
