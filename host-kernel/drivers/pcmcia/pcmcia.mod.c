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

SYMBOL_CRC(pcmcia_register_driver, 0x50a9f59c, "");
SYMBOL_CRC(pcmcia_unregister_driver, 0xb59602ab, "");
SYMBOL_CRC(pcmcia_dev_present, 0x3b89a34f, "");
SYMBOL_CRC(pcmcia_read_config_byte, 0x15075362, "");
SYMBOL_CRC(pcmcia_write_config_byte, 0xf7d8d268, "");
SYMBOL_CRC(pcmcia_map_mem_page, 0xdb321284, "");
SYMBOL_CRC(pcmcia_fixup_iowidth, 0x8ff3ed2c, "");
SYMBOL_CRC(pcmcia_fixup_vpp, 0x1a1826f5, "");
SYMBOL_CRC(pcmcia_release_window, 0x3ccca55e, "");
SYMBOL_CRC(pcmcia_enable_device, 0x781fa6ce, "");
SYMBOL_CRC(pcmcia_request_io, 0x133564c3, "");
SYMBOL_CRC(pcmcia_request_irq, 0x033860e8, "");
SYMBOL_CRC(pcmcia_request_window, 0x47050df9, "");
SYMBOL_CRC(pcmcia_disable_device, 0x1a6879ec, "");
SYMBOL_CRC(pcmcia_parse_tuple, 0xbb312663, "");
SYMBOL_CRC(pcmcia_loop_config, 0x745548c3, "");
SYMBOL_CRC(pcmcia_loop_tuple, 0xc4582630, "");
SYMBOL_CRC(pcmcia_get_tuple, 0xf3f4fcad, "");
SYMBOL_CRC(pcmcia_get_mac_from_cis, 0x41dbe096, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x13110126, "request_resource" },
	{ 0x734d5da0, "pcmcia_get_socket" },
	{ 0xc6d09aa9, "release_firmware" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x7bdff18e, "driver_remove_file" },
	{ 0x8cafebc5, "driver_attach" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x3fb7d439, "request_firmware" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xd5d074ec, "sysfs_create_bin_file" },
	{ 0xedc03953, "iounmap" },
	{ 0x69acdf38, "memcpy" },
	{ 0x37a0cba, "kfree" },
	{ 0xa40a8382, "get_device" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x57896301, "dev_addr_mod" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x3197c4e3, "put_device" },
	{ 0xf19f134f, "driver_create_file" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x5c3bc265, "bus_for_each_dev" },
	{ 0x2587f789, "_dev_info" },
	{ 0x91f4d6a1, "security_locked_down" },
	{ 0xeebaabb1, "pccard_register_pcmcia" },
	{ 0x1de23e95, "module_put" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0x69dd3b5b, "crc32_le" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x90c9f554, "class_interface_unregister" },
	{ 0xde80cd09, "ioremap" },
	{ 0x449ad0a7, "memcmp" },
	{ 0xd9a9d63d, "class_interface_register" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x422066d2, "device_register" },
	{ 0xc1a12099, "pcmcia_parse_uevents" },
	{ 0xfb578fc5, "memset" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x17f55d32, "bus_rescan_devices" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x2d39b0a7, "kstrdup" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xb9d10973, "pcmcia_socket_class" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0x65bf7f0, "pcmcia_put_socket" },
	{ 0xc5e74216, "release_resource" },
	{ 0x754d539c, "strlen" },
	{ 0x77358855, "iomem_resource" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x2eca9998, "sysfs_remove_bin_file" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0x99f2d00a, "sysfs_emit_at" },
	{ 0xf9a482f9, "msleep" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xc487b792, "bus_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "pcmcia_core");


MODULE_INFO(srcversion, "5D9F4BFBD4160A39F03B400");
