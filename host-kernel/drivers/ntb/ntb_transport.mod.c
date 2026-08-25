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

SYMBOL_CRC(ntb_transport_unregister_client_dev, 0xf9eb813f, "_gpl");
SYMBOL_CRC(ntb_transport_register_client_dev, 0xf55d6313, "_gpl");
SYMBOL_CRC(ntb_transport_register_client, 0x4ae0222f, "_gpl");
SYMBOL_CRC(ntb_transport_unregister_client, 0xf768d961, "_gpl");
SYMBOL_CRC(ntb_transport_create_queue, 0x88a4e349, "_gpl");
SYMBOL_CRC(ntb_transport_free_queue, 0xc270dc24, "_gpl");
SYMBOL_CRC(ntb_transport_rx_remove, 0xc37d9036, "_gpl");
SYMBOL_CRC(ntb_transport_rx_enqueue, 0xd40e7a02, "_gpl");
SYMBOL_CRC(ntb_transport_tx_enqueue, 0x3d54dbfc, "_gpl");
SYMBOL_CRC(ntb_transport_link_up, 0x9c992c8f, "_gpl");
SYMBOL_CRC(ntb_transport_link_down, 0x436098aa, "_gpl");
SYMBOL_CRC(ntb_transport_link_query, 0x32537aca, "_gpl");
SYMBOL_CRC(ntb_transport_qp_num, 0x82e6c13d, "_gpl");
SYMBOL_CRC(ntb_transport_max_size, 0x30934216, "_gpl");
SYMBOL_CRC(ntb_transport_tx_free_entry, 0x0862001f, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x754d539c, "strlen" },
	{ 0x5a921311, "strncmp" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x37a0cba, "kfree" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3197c4e3, "put_device" },
	{ 0xa40a8382, "get_device" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x2587f789, "_dev_info" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x69acdf38, "memcpy" },
	{ 0x1db7706b, "__copy_user_nocache" },
	{ 0xec94cd8e, "ntb_msi_peer_trigger" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x96848186, "scnprintf" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xf50e291a, "kmem_cache_alloc_node_trace" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x422066d2, "device_register" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0xf3e78736, "devm_free_irq" },
	{ 0x8199c8bf, "ntbm_msi_request_threaded_irq" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xcc59265e, "ntb_msi_setup_mws" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x1ba59527, "__kmalloc_node" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0xedc03953, "iounmap" },
	{ 0x1a393d95, "ntb_msi_init" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x2364c85a, "tasklet_init" },
	{ 0x7cc2e6ed, "ntb_default_peer_port_count" },
	{ 0x88455b22, "ntb_set_ctx" },
	{ 0x9243b3bb, "ntb_link_event" },
	{ 0x3c9842b6, "dmaengine_get_unmap_data" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0x8849c1c3, "dmaengine_unmap_put" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xf9a482f9, "msleep" },
	{ 0x25a9d27d, "dma_sync_wait" },
	{ 0x188236aa, "dma_unmap_resource" },
	{ 0x53a603a, "dma_release_channel" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0xaedc404e, "ntb_clear_ctx" },
	{ 0xaf0fabc0, "__dma_request_channel" },
	{ 0xc8884d94, "dma_map_resource" },
	{ 0x92997ed8, "_printk" },
	{ 0x716265c7, "debugfs_initialized" },
	{ 0xc487b792, "bus_register" },
	{ 0x3dc25e18, "__ntb_register_client" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0xd20d562, "ntb_unregister_client" },
	{ 0x6a59169d, "simple_open" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x3c872672, "param_ops_byte" },
	{ 0xd5fd941f, "param_ops_ulong" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ntb");


MODULE_INFO(srcversion, "D27B7C44DDB12E307BD2DA6");
