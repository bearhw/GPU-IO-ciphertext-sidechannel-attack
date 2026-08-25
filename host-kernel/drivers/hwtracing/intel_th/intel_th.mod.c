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

SYMBOL_CRC(intel_th_driver_register, 0x286a108e, "_gpl");
SYMBOL_CRC(intel_th_driver_unregister, 0x7795f368, "_gpl");
SYMBOL_CRC(intel_th_output_enable, 0xd3e84000, "_gpl");
SYMBOL_CRC(intel_th_alloc, 0xd416f32e, "_gpl");
SYMBOL_CRC(intel_th_free, 0x58465e91, "_gpl");
SYMBOL_CRC(intel_th_trace_enable, 0x515f47fa, "_gpl");
SYMBOL_CRC(intel_th_trace_switch, 0x575d1ed3, "_gpl");
SYMBOL_CRC(intel_th_trace_disable, 0x730bfc73, "_gpl");
SYMBOL_CRC(intel_th_set_output, 0xc9a93fc3, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe914e41e, "strcpy" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x96848186, "scnprintf" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xf3e78736, "devm_free_irq" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x84909a73, "bus_find_device" },
	{ 0x48098f3, "device_add" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0xffb7c514, "ida_free" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x3312881b, "device_del" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x8fb7579d, "device_match_devt" },
	{ 0x352e7e70, "pm_runtime_no_callbacks" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0xe7c59702, "pm_runtime_forbid" },
	{ 0xfe51e012, "pm_runtime_allow" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xeb0c5cb4, "__register_chrdev" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x31795ba9, "device_release_driver" },
	{ 0x754d539c, "strlen" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xc487b792, "bus_register" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C6F154B609ACAA93B6C2336");
