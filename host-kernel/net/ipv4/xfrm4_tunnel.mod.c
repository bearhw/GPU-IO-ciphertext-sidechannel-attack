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
	{ 0x6681fb42, "xfrm_input" },
	{ 0x4eb6f185, "skb_push" },
	{ 0x24c60e49, "xfrm_register_type" },
	{ 0x92997ed8, "_printk" },
	{ 0xfdd81ad2, "xfrm4_tunnel_register" },
	{ 0x844bd2de, "xfrm_unregister_type" },
	{ 0x52ca7990, "xfrm4_tunnel_deregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "tunnel4");


MODULE_INFO(srcversion, "9A836293B14E64C3516A7D8");
