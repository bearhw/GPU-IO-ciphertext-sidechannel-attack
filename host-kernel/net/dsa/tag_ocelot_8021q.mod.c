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
	{ 0x10a8ab8a, "dsa_8021q_rcv" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe6e15da0, "kthread_create_worker" },
	{ 0x7d78794c, "netdev_txq_to_tc" },
	{ 0x1dce07df, "dsa_tag_8021q_standalone_vid" },
	{ 0xf4753987, "kthread_queue_work" },
	{ 0xb878d86c, "dsa_8021q_xmit" },
	{ 0xf652d653, "skb_checksum_help" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe489931, "dsa_tag_drivers_register" },
	{ 0xf69aec4a, "dsa_tag_drivers_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dsa_core");


MODULE_INFO(srcversion, "BDA86F105A2CA3EE0044A6F");
