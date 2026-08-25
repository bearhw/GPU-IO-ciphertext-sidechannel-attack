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
	{ 0x3eeb2322, "__wake_up" },
	{ 0x96848186, "scnprintf" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xcd91b127, "system_highpri_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9f46ced8, "__sw_hweight64" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x1ba59527, "__kmalloc_node" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x8849c1c3, "dmaengine_unmap_put" },
	{ 0x1000e51, "schedule" },
	{ 0x3c9842b6, "dmaengine_get_unmap_data" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0xf9a482f9, "msleep" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0x53a603a, "dma_release_channel" },
	{ 0x37a0cba, "kfree" },
	{ 0xaf0fabc0, "__dma_request_channel" },
	{ 0xc8884d94, "dma_map_resource" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x800473f, "__cond_resched" },
	{ 0x188236aa, "dma_unmap_resource" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x93d6dd8c, "complete_all" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xdf256037, "kstrtou8_from_user" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x22a9685a, "devm_ioremap_wc" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x88455b22, "ntb_set_ctx" },
	{ 0x9243b3bb, "ntb_link_event" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x23bd38fe, "debugfs_create_u8" },
	{ 0x4465655e, "debugfs_create_bool" },
	{ 0x58e4bd20, "ntb_default_peer_port_number" },
	{ 0x7cc2e6ed, "ntb_default_peer_port_count" },
	{ 0xa0f4e4b8, "ntb_default_port_number" },
	{ 0xaedc404e, "ntb_clear_ctx" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xf9ca2eb4, "kstrtoint_from_user" },
	{ 0x2e3bcce2, "wait_for_completion_interruptible" },
	{ 0x92997ed8, "_printk" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x716265c7, "debugfs_initialized" },
	{ 0x3dc25e18, "__ntb_register_client" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xd20d562, "ntb_unregister_client" },
	{ 0x6a59169d, "simple_open" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x3c872672, "param_ops_byte" },
	{ 0xd5fd941f, "param_ops_ulong" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ntb");


MODULE_INFO(srcversion, "FD36108A24D9132A3B07F8A");
