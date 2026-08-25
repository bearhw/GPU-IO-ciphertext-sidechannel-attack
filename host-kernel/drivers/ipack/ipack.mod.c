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

SYMBOL_CRC(ipack_bus_register, 0xb171ca46, "_gpl");
SYMBOL_CRC(ipack_bus_unregister, 0x13b08d1c, "_gpl");
SYMBOL_CRC(ipack_driver_register, 0x94e254ac, "_gpl");
SYMBOL_CRC(ipack_driver_unregister, 0xed3a558f, "_gpl");
SYMBOL_CRC(ipack_device_init, 0x82ab6ab7, "_gpl");
SYMBOL_CRC(ipack_device_add, 0xd2db9d20, "_gpl");
SYMBOL_CRC(ipack_device_del, 0x4e2d9168, "_gpl");
SYMBOL_CRC(ipack_get_device, 0xb7c9edf6, "_gpl");
SYMBOL_CRC(ipack_put_device, 0x903e8731, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x37a0cba, "kfree" },
	{ 0x5c3bc265, "bus_for_each_dev" },
	{ 0xffb7c514, "ida_free" },
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x1e4e4e73, "driver_register" },
	{ 0xa6d0ea6b, "driver_unregister" },
	{ 0x48098f3, "device_add" },
	{ 0xa40a8382, "get_device" },
	{ 0x3197c4e3, "put_device" },
	{ 0x3312881b, "device_del" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xe7a02573, "ida_alloc_range" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xbd3718be, "device_initialize" },
	{ 0xde80cd09, "ioremap" },
	{ 0xb19b445, "ioread8" },
	{ 0xedc03953, "iounmap" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa71d2e2c, "ioread16be" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xc487b792, "bus_register" },
	{ 0x6190ff9b, "bus_unregister" },
	{ 0xa7d5f92e, "ida_destroy" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D61E60F266FA055CA3B6F19");
