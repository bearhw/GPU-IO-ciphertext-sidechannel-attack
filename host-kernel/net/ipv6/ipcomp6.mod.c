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
	{ 0xa67c380, "ipcomp_init_state" },
	{ 0xfd5208fd, "xfrm6_tunnel_spi_lookup" },
	{ 0xf96be110, "xfrm_state_lookup" },
	{ 0x3338d282, "xfrm_state_alloc" },
	{ 0xf97afa3d, "xfrm6_tunnel_alloc_spi" },
	{ 0x37b4f03a, "xfrm_init_state" },
	{ 0xdc5965cb, "xfrm_state_insert" },
	{ 0x9f8178fd, "__xfrm_state_destroy" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x6b7cb10, "make_kuid" },
	{ 0x5eaeadb, "ip6_update_pmtu" },
	{ 0x54afee, "ip6_redirect" },
	{ 0x24c60e49, "xfrm_register_type" },
	{ 0x92997ed8, "_printk" },
	{ 0x816f7600, "xfrm6_protocol_register" },
	{ 0x844bd2de, "xfrm_unregister_type" },
	{ 0x1909477e, "xfrm6_protocol_deregister" },
	{ 0x32050f48, "xfrm6_rcv" },
	{ 0x6681fb42, "xfrm_input" },
	{ 0x7726f66a, "ipcomp_destroy" },
	{ 0x4e419ac5, "ipcomp_input" },
	{ 0x93d9e272, "ipcomp_output" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "xfrm_ipcomp,xfrm6_tunnel");


MODULE_INFO(srcversion, "F4618135589C9A890EACC9D");
