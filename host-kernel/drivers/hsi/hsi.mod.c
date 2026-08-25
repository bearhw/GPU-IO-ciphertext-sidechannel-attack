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

SYMBOL_CRC(hsi_new_client, 0xf6a3c7c6, "_gpl");
SYMBOL_CRC(hsi_remove_client, 0x281a7027, "_gpl");
SYMBOL_CRC(hsi_port_unregister_clients, 0x160de525, "_gpl");
SYMBOL_CRC(hsi_unregister_controller, 0x5ce70596, "_gpl");
SYMBOL_CRC(hsi_register_controller, 0x98a6eec1, "_gpl");
SYMBOL_CRC(hsi_register_client_driver, 0x2b081818, "_gpl");
SYMBOL_CRC(hsi_put_controller, 0x1a4458f7, "_gpl");
SYMBOL_CRC(hsi_alloc_controller, 0xa3c68992, "_gpl");
SYMBOL_CRC(hsi_free_msg, 0x5d395602, "_gpl");
SYMBOL_CRC(hsi_alloc_msg, 0xf044dd3e, "_gpl");
SYMBOL_CRC(hsi_async, 0x23c70335, "_gpl");
SYMBOL_CRC(hsi_claim_port, 0xabb5b224, "_gpl");
SYMBOL_CRC(hsi_release_port, 0xf51950e9, "_gpl");
SYMBOL_CRC(hsi_register_port_event, 0x6d4e0874, "_gpl");
SYMBOL_CRC(hsi_unregister_port_event, 0x899186ca, "_gpl");
SYMBOL_CRC(hsi_event, 0x3beee086, "_gpl");
SYMBOL_CRC(hsi_get_channel_id_by_name, 0xf18a023b, "_gpl");
SYMBOL_CRC(hsi_board_list, 0x5210a5bf, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x7f5b4fe4, "sg_free_table" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x37a0cba, "kfree" },
	{ 0xdb5ce9c4, "device_for_each_child" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x907d14d, "blocking_notifier_chain_register" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x823eae06, "blocking_notifier_call_chain" },
	{ 0x3197c4e3, "put_device" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x3a2f6702, "sg_alloc_table" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x48098f3, "device_add" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x422066d2, "device_register" },
	{ 0x3312881b, "device_del" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x4ece3615, "blocking_notifier_chain_unregister" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "941E2A06142B4A9BB15953B");
