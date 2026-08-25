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

SYMBOL_CRC(spmi_device_add, 0xe23f450c, "_gpl");
SYMBOL_CRC(spmi_device_remove, 0xe94ef8eb, "_gpl");
SYMBOL_CRC(spmi_register_read, 0x36b5eaef, "_gpl");
SYMBOL_CRC(spmi_ext_register_read, 0x3dbb46f7, "_gpl");
SYMBOL_CRC(spmi_ext_register_readl, 0x3cf64684, "_gpl");
SYMBOL_CRC(spmi_register_write, 0xde8263bb, "_gpl");
SYMBOL_CRC(spmi_register_zero_write, 0xe87b8d32, "_gpl");
SYMBOL_CRC(spmi_ext_register_write, 0x915226e0, "_gpl");
SYMBOL_CRC(spmi_ext_register_writel, 0xb566268e, "_gpl");
SYMBOL_CRC(spmi_command_reset, 0x14fef9c3, "_gpl");
SYMBOL_CRC(spmi_command_sleep, 0x1b89141e, "_gpl");
SYMBOL_CRC(spmi_command_wakeup, 0x2ffbe8db, "_gpl");
SYMBOL_CRC(spmi_command_shutdown, 0x98bd6304, "_gpl");
SYMBOL_CRC(spmi_device_alloc, 0x074c9bef, "_gpl");
SYMBOL_CRC(spmi_controller_alloc, 0x50ae0fbf, "_gpl");
SYMBOL_CRC(spmi_controller_add, 0x4b8138c5, "_gpl");
SYMBOL_CRC(spmi_controller_remove, 0x4cc64918, "_gpl");
SYMBOL_CRC(__spmi_driver_register, 0xf9f94927, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x7871e78, "bpf_trace_run5" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0x4c75845f, "bpf_trace_run6" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x48098f3, "device_add" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xffb7c514, "ida_free" },
	{ 0x37a0cba, "kfree" },
	{ 0x8fab03fb, "__pm_runtime_set_status" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x5a921311, "strncmp" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0x3312881b, "device_del" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xbd3718be, "device_initialize" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0xc487b792, "bus_register" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0207B1288A388317F945DF3");
