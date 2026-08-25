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
	{ 0x21a7b8cd, "gpiochip_remove" },
	{ 0x2587f789, "_dev_info" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x85bd1608, "__request_region" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xfbdca2ae, "__devm_request_region" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x72aacf07, "gpiochip_add_data_with_key" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x92997ed8, "_printk" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x376325f4, "platform_device_alloc" },
	{ 0x774a0a6d, "platform_device_add_data" },
	{ 0x47155238, "platform_device_add" },
	{ 0x79f72f96, "platform_device_put" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "47BAF3CD31DF17E3294794A");
