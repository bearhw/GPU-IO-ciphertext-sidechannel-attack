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

SYMBOL_CRC(nf_osf_fingers, 0x35eff5e0, "_gpl");
SYMBOL_CRC(nf_osf_match, 0x5f6d9571, "_gpl");
SYMBOL_CRC(nf_osf_find, 0x91742046, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc6cbbc89, "capable" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0x6782fb8f, "skb_copy_bits" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xccfb4622, "nf_log_packet" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6fea8456, "nfnetlink_subsys_register" },
	{ 0x92997ed8, "_printk" },
	{ 0x6ece208b, "nfnetlink_subsys_unregister" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "nfnetlink");


MODULE_INFO(srcversion, "5E9F569A6926FECAB3A16A4");
