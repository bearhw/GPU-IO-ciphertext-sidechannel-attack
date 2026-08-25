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

SYMBOL_CRC(xfrm6_tunnel_spi_lookup, 0xfd5208fd, "");
SYMBOL_CRC(xfrm6_tunnel_alloc_spi, 0xf97afa3d, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x4eb6f185, "skb_push" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x659ded26, "xfrm_flush_gc" },
	{ 0x52bd51b8, "xfrm_state_flush" },
	{ 0xc3690fc, "_raw_spin_lock_bh" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xe46021ca, "_raw_spin_unlock_bh" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x6b28c90b, "xfrm6_rcv_spi" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0x983d3f56, "register_pernet_subsys" },
	{ 0x24c60e49, "xfrm_register_type" },
	{ 0x4b19f3cc, "xfrm6_tunnel_register" },
	{ 0x52cfd434, "xfrm6_tunnel_deregister" },
	{ 0x844bd2de, "xfrm_unregister_type" },
	{ 0x2ffe9790, "unregister_pernet_subsys" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "tunnel6");


MODULE_INFO(srcversion, "CE83DB38D50DDCE9ED24817");
