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
	{ 0x656e4a6e, "snprintf" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xd3e84000, "intel_th_output_enable" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x473786ad, "devm_kasprintf" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x286a108e, "intel_th_driver_register" },
	{ 0x7795f368, "intel_th_driver_unregister" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "intel_th");


MODULE_INFO(srcversion, "8E16BAF74BE23918538CDD1");
