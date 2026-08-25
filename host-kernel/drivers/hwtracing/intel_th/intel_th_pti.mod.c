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
	{ 0x4a453f53, "iowrite32" },
	{ 0x96848186, "scnprintf" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x515f47fa, "intel_th_trace_enable" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x169938c1, "__sysfs_match_string" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x286a108e, "intel_th_driver_register" },
	{ 0x730bfc73, "intel_th_trace_disable" },
	{ 0x7795f368, "intel_th_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "intel_th");


MODULE_INFO(srcversion, "A8440A9E15B4B7D69E7C655");
