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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xefe14521, "nf_dup_ipv6" },
	{ 0x37a0cba, "kfree" },
	{ 0xd3fcc511, "xt_tee_enabled" },
	{ 0x2f4880df, "static_key_slow_dec" },
	{ 0x596b8dc0, "nf_dup_ipv4" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbcd1484c, "dev_get_by_name" },
	{ 0x8e92f7c4, "static_key_slow_inc" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x7b7451f4, "xt_register_targets" },
	{ 0xd2da1048, "register_netdevice_notifier" },
	{ 0x8b4eba64, "xt_unregister_targets" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0x9d0d6206, "unregister_netdevice_notifier" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nf_dup_ipv6,x_tables,nf_dup_ipv4");


MODULE_INFO(srcversion, "26459F75F8CD9F5E61EB421");
