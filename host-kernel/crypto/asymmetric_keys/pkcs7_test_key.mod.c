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
	{ 0x26a93eb2, "verify_pkcs7_signature" },
	{ 0xcc314825, "user_destroy" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x2d48af78, "user_revoke" },
	{ 0x849180c0, "unregister_key_type" },
	{ 0x1e424d61, "user_preparse" },
	{ 0x23c1e0f, "register_key_type" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x9c96a8db, "user_describe" },
	{ 0x307836e1, "user_read" },
	{ 0x8ead800c, "user_free_preparse" },
	{ 0x21cb898, "generic_key_instantiate" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6A833E4ADEC602483AED5BA");
