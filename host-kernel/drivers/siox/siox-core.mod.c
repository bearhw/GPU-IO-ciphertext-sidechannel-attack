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

SYMBOL_CRC(siox_device_synced, 0x01d118c5, "_gpl");
SYMBOL_CRC(siox_device_connected, 0xd5ab5dcc, "_gpl");
SYMBOL_CRC(siox_master_alloc, 0xcb072af3, "_gpl");
SYMBOL_CRC(siox_master_register, 0x0e5353e3, "_gpl");
SYMBOL_CRC(siox_master_unregister, 0x7eff36c4, "_gpl");
SYMBOL_CRC(__siox_driver_register, 0x39dc8707, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x69acdf38, "memcpy" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0x7871e78, "bpf_trace_run5" },
	{ 0x37a0cba, "kfree" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xffae8e8b, "nsecs_to_jiffies" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x7f24de73, "jiffies_to_usecs" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x48098f3, "device_add" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0x92997ed8, "_printk" },
	{ 0xeb78b21b, "kernfs_notify" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x3312881b, "device_del" },
	{ 0x3197c4e3, "put_device" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xbd3718be, "device_initialize" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x422066d2, "device_register" },
	{ 0x590b666e, "kernfs_find_and_get_ns" },
	{ 0xc8dcc62a, "krealloc" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa40a8382, "get_device" },
	{ 0x86490580, "current_task" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xfb578fc5, "memset" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xc487b792, "bus_register" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "89FA7E5C494409DF52AAE4F");
