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
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xbd505649, "consume_skb" },
	{ 0x62ea9e12, "qrtr_endpoint_unregister" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xc045240, "__register_rpmsg_driver" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0xcde91d2c, "unregister_rpmsg_driver" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xa118a39f, "qrtr_endpoint_post" },
	{ 0x489d6cd5, "qrtr_endpoint_register" },
	{ 0xd9f95029, "rpmsg_send" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "qrtr,rpmsg_core");


MODULE_INFO(srcversion, "0236E93D0918730003C2EBB");
