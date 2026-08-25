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

SYMBOL_CRC(__ntb_register_client, 0x3dc25e18, "");
SYMBOL_CRC(ntb_unregister_client, 0x0d20d562, "");
SYMBOL_CRC(ntb_register_device, 0x1949bb7c, "");
SYMBOL_CRC(ntb_unregister_device, 0x162ac598, "");
SYMBOL_CRC(ntb_set_ctx, 0x88455b22, "");
SYMBOL_CRC(ntb_clear_ctx, 0xaedc404e, "");
SYMBOL_CRC(ntb_link_event, 0x9243b3bb, "");
SYMBOL_CRC(ntb_db_event, 0x0ce93cd8, "");
SYMBOL_CRC(ntb_msg_event, 0xbe178a6d, "");
SYMBOL_CRC(ntb_default_port_number, 0xa0f4e4b8, "");
SYMBOL_CRC(ntb_default_peer_port_count, 0x7cc2e6ed, "");
SYMBOL_CRC(ntb_default_peer_port_number, 0x58e4bd20, "");
SYMBOL_CRC(ntb_default_peer_port_idx, 0xea094786, "");
SYMBOL_CRC(ntb_msi_init, 0x1a393d95, "");
SYMBOL_CRC(ntb_msi_setup_mws, 0xcc59265e, "");
SYMBOL_CRC(ntb_msi_clear_mws, 0x0a639fa6, "");
SYMBOL_CRC(ntbm_msi_request_threaded_irq, 0x8199c8bf, "");
SYMBOL_CRC(ntbm_msi_free_irq, 0x8cb90e4e, "");
SYMBOL_CRC(ntb_msi_peer_trigger, 0xec94cd8e, "");
SYMBOL_CRC(ntb_msi_peer_addr, 0x4b0019f7, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6f7e6040, "irq_has_action" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xa6257a2f, "complete" },
	{ 0xf8c2f2bb, "devm_iounmap" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x2791bd65, "devres_destroy" },
	{ 0x35e01ad9, "msi_unlock_descs" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0xa40a8382, "get_device" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xf18176a5, "msi_lock_descs" },
	{ 0xea900f57, "devres_add" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0xf3e78736, "devm_free_irq" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0xbb7cf14f, "irq_get_irq_data" },
	{ 0x28de1031, "__devres_alloc_node" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x422066d2, "device_register" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc274a9d7, "msi_first_desc" },
	{ 0xae62ee9, "msi_next_desc" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xc487b792, "bus_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2B51C723BE41A2FD33E1D75");
