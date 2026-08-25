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
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0xa7d6cfc9, "mc13xxx_reg_rmw" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x393b10e4, "mc13xxx_reg_write" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x6f477cbc, "__platform_driver_probe" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mc13xxx-core");

MODULE_ALIAS("platform:mc13783-led");
MODULE_ALIAS("platform:mc13892-led");
MODULE_ALIAS("platform:mc34708-led");

MODULE_INFO(srcversion, "C8BCFB2825257ADAD09E19E");
