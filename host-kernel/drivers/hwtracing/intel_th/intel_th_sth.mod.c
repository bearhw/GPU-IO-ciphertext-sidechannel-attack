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
	{ 0xa78af5f3, "ioread32" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xc387b0f, "stm_register_device" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xc9a93fc3, "intel_th_set_output" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xed722ca1, "stm_unregister_device" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x286a108e, "intel_th_driver_register" },
	{ 0x7795f368, "intel_th_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "stm_core,intel_th");


MODULE_INFO(srcversion, "785533B532E76555FE29C46");
