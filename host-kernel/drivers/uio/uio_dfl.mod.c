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
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa0d4f927, "__devm_uio_register_device" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x467b27e7, "__dfl_driver_register" },
	{ 0xaf4e4c1f, "dfl_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "uio,dfl");

MODULE_ALIAS("dfl:t0000f0010*");
MODULE_ALIAS("dfl:t0000f0015*");

MODULE_INFO(srcversion, "833BEB4DE79D6CA71DD79C9");
