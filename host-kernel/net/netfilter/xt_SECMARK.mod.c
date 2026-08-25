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
	{ 0xe2d5255a, "strcmp" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xa916b694, "strnlen" },
	{ 0xf9c1f9ab, "security_secctx_to_secid" },
	{ 0x2c82c36a, "security_secmark_relabel_packet" },
	{ 0x2f03fc4b, "security_secmark_refcount_inc" },
	{ 0x92997ed8, "_printk" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x19bd383b, "security_secmark_refcount_dec" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7b7451f4, "xt_register_targets" },
	{ 0x8b4eba64, "xt_unregister_targets" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "x_tables");


MODULE_INFO(srcversion, "BBCC3BCAF9393FFDE10733B");
