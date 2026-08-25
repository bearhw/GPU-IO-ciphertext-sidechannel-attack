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

SYMBOL_CRC(__mcb_register_driver, 0x56614760, "_gpl");
SYMBOL_CRC(mcb_unregister_driver, 0x6987fe2d, "_gpl");
SYMBOL_CRC(mcb_device_register, 0x3880bf72, "_gpl");
SYMBOL_CRC(mcb_alloc_bus, 0x728a5a01, "_gpl");
SYMBOL_CRC(mcb_release_bus, 0x2ad0effe, "_gpl");
SYMBOL_CRC(mcb_bus_get, 0x44a953e4, "_gpl");
SYMBOL_CRC(mcb_bus_put, 0x5f24dbaf, "_gpl");
SYMBOL_CRC(mcb_alloc_dev, 0x03b02ca5, "_gpl");
SYMBOL_CRC(mcb_free_dev, 0x5b7f9ca8, "_gpl");
SYMBOL_CRC(mcb_bus_add_devices, 0xe8e5654a, "_gpl");
SYMBOL_CRC(mcb_get_resource, 0xce9096f7, "_gpl");
SYMBOL_CRC(mcb_request_mem, 0x57690545, "_gpl");
SYMBOL_CRC(mcb_release_mem, 0xeb2c8905, "_gpl");
SYMBOL_CRC(mcb_get_irq, 0x3aee7975, "_gpl");
SYMBOL_CRC(chameleon_parse_cells, 0x2434a5a3, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x96848186, "scnprintf" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x37a0cba, "kfree" },
	{ 0xa40a8382, "get_device" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x3197c4e3, "put_device" },
	{ 0x5c3bc265, "bus_for_each_dev" },
	{ 0x1de23e95, "module_put" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x48098f3, "device_add" },
	{ 0x28a4943e, "device_attach" },
	{ 0xffb7c514, "ida_free" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x77358855, "iomem_resource" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x85bd1608, "__request_region" },
	{ 0xc487b792, "bus_register" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "EC5FFFAA606F2F43808D740");
