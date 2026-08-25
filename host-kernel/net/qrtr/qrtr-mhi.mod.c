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
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x381bd073, "mhi_queue_skb" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa0552c2d, "sk_free" },
	{ 0x197a3490, "kfree_skb_reason" },
	{ 0x49e63ca4, "__pskb_pull_tail" },
	{ 0xa118a39f, "qrtr_endpoint_post" },
	{ 0xfa296300, "mhi_driver_unregister" },
	{ 0x489d6cd5, "qrtr_endpoint_register" },
	{ 0xcc1fc515, "mhi_unprepare_from_transfer" },
	{ 0xac571ac0, "mhi_prepare_for_transfer_autoqueue" },
	{ 0xf3627dca, "__mhi_driver_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "qrtr,mhi");

MODULE_ALIAS("mhi:IPCR");

MODULE_INFO(srcversion, "34C53C5E6A27442DC5C3D28");
