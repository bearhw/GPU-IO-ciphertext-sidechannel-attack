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

SYMBOL_CRC(dead_socket, 0xcf97f3bd, "");
SYMBOL_CRC(pcmcia_socket_list, 0x212db8d2, "");
SYMBOL_CRC(pcmcia_socket_list_rwsem, 0xf942709b, "");
SYMBOL_CRC(pcmcia_get_socket, 0x734d5da0, "");
SYMBOL_CRC(pcmcia_put_socket, 0x065bf7f0, "");
SYMBOL_CRC(pcmcia_register_socket, 0x9d08e002, "");
SYMBOL_CRC(pcmcia_unregister_socket, 0x045c00a5, "");
SYMBOL_CRC(pcmcia_get_socket_by_nr, 0x812dcb8d, "");
SYMBOL_CRC(pcmcia_parse_events, 0x93cdae47, "");
SYMBOL_CRC(pcmcia_parse_uevents, 0xc1a12099, "");
SYMBOL_CRC(pccard_register_pcmcia, 0xeebaabb1, "");
SYMBOL_CRC(pcmcia_reset_card, 0xb99aa394, "");
SYMBOL_CRC(pcmcia_socket_class, 0xb9d10973, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xbd11f76f, "pci_bus_size_bridges" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xa6257a2f, "complete" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x9e61bb05, "set_freezable" },
	{ 0x37a0cba, "kfree" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xa40a8382, "get_device" },
	{ 0xddbeeecc, "pci_lock_rescan_remove" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x4482cdb, "__refrigerator" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x1000e51, "schedule" },
	{ 0x12ff3037, "pci_scan_bridge" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3197c4e3, "put_device" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x800473f, "__cond_resched" },
	{ 0xf1879ab3, "pci_scan_slot" },
	{ 0x57bc19d2, "down_write" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa1600c1b, "__class_register" },
	{ 0xce807a25, "up_write" },
	{ 0x7e1b74de, "pci_bus_add_devices" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x70cc876b, "class_unregister" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xec507773, "freezing_slow_path" },
	{ 0x86490580, "current_task" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x422066d2, "device_register" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x668b19a1, "down_read" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0x823d9bcd, "pci_bus_assign_resources" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x5790e7a0, "pci_unlock_rescan_remove" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x56470118, "__warn_printk" },
	{ 0x48e2e958, "pci_fixup_cardbus" },
	{ 0x7ab88a45, "system_freezing_cnt" },
	{ 0x7e1b3ae2, "pci_stop_and_remove_bus_device" },
	{ 0x617bc4d4, "pci_set_cacheline_size" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x53b954a2, "up_read" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa24f23d8, "__request_module" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "62AE3B549ED81340E5277E1");
