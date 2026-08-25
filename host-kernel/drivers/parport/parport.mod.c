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

SYMBOL_CRC(__parport_register_driver, 0xefbd5788, "");
SYMBOL_CRC(parport_unregister_driver, 0x938e02c5, "");
SYMBOL_CRC(parport_get_port, 0x6d4f18f2, "");
SYMBOL_CRC(parport_del_port, 0x9f4f20bc, "");
SYMBOL_CRC(parport_put_port, 0xa716f5c5, "");
SYMBOL_CRC(parport_register_port, 0xc15defcd, "");
SYMBOL_CRC(parport_announce_port, 0xe6f675ad, "");
SYMBOL_CRC(parport_remove_port, 0x1c4c2d08, "");
SYMBOL_CRC(parport_register_dev_model, 0xd4c28eac, "");
SYMBOL_CRC(parport_unregister_device, 0x41e3ce24, "");
SYMBOL_CRC(parport_find_number, 0x6fc38723, "");
SYMBOL_CRC(parport_find_base, 0xf6f85e3f, "");
SYMBOL_CRC(parport_claim, 0xe697454e, "");
SYMBOL_CRC(parport_claim_or_block, 0x61cfa6a2, "");
SYMBOL_CRC(parport_release, 0x8b73974d, "");
SYMBOL_CRC(parport_irq_handler, 0x5e3a3912, "");
SYMBOL_CRC(parport_negotiate, 0x6340e145, "");
SYMBOL_CRC(parport_write, 0x00c1942e, "");
SYMBOL_CRC(parport_read, 0xffd758d4, "");
SYMBOL_CRC(parport_wait_peripheral, 0xdd7c688b, "");
SYMBOL_CRC(parport_wait_event, 0xb66f1944, "");
SYMBOL_CRC(parport_set_timeout, 0x45ddbc35, "");
SYMBOL_CRC(parport_ieee1284_interrupt, 0x4d2a941b, "");
SYMBOL_CRC(parport_ieee1284_ecp_write_data, 0xddfcbbe3, "");
SYMBOL_CRC(parport_ieee1284_ecp_read_data, 0x14f82304, "");
SYMBOL_CRC(parport_ieee1284_ecp_write_addr, 0x369d1f52, "");
SYMBOL_CRC(parport_ieee1284_write_compat, 0x98a97864, "");
SYMBOL_CRC(parport_ieee1284_read_nibble, 0x9b74c762, "");
SYMBOL_CRC(parport_ieee1284_read_byte, 0x2113cc70, "");
SYMBOL_CRC(parport_ieee1284_epp_write_data, 0xfa0f1ab6, "");
SYMBOL_CRC(parport_ieee1284_epp_read_data, 0xa05f234c, "");
SYMBOL_CRC(parport_ieee1284_epp_write_addr, 0x116ebe07, "");
SYMBOL_CRC(parport_ieee1284_epp_read_addr, 0xf00a0aa6, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe914e41e, "strcpy" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xcf2a6966, "up" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0x54496b4, "schedule_timeout_interruptible" },
	{ 0xd2ae15db, "bus_for_each_drv" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xa40a8382, "get_device" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xd691c6a9, "unregister_sysctl_table" },
	{ 0x3197c4e3, "put_device" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x5c3bc265, "bus_for_each_dev" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x5efde8e6, "proc_doulongvec_ms_jiffies_minmax" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x86490580, "current_task" },
	{ 0x11089ac7, "_ctype" },
	{ 0x422066d2, "device_register" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xeb078aee, "_raw_write_unlock_irqrestore" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x66b4cc41, "kmemdup" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x6bd0e573, "down_interruptible" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x5021bd81, "_raw_write_lock_irqsave" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0x6a449c4f, "register_sysctl_table" },
	{ 0x349cba85, "strchr" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xa24f23d8, "__request_module" },
	{ 0xc487b792, "bus_register" },
	{ 0x2cdf87a1, "proc_dointvec_minmax" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "057FE74095ABE9ADD037B2D");
