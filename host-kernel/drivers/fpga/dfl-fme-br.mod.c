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
	{ 0xba5e0275, "fpga_bridge_unregister" },
	{ 0x3197c4e3, "put_device" },
	{ 0xf21650b3, "dfl_fpga_port_ops_put" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xf3643ec5, "fpga_bridge_register" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x1eeae15c, "dfl_fpga_check_port_id" },
	{ 0x5a0548e2, "__dfl_fpga_cdev_find_port" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xbc584623, "dfl_fpga_port_ops_get" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fpga-bridge,dfl");


MODULE_INFO(srcversion, "BD51A4C7FD395F60E9063B1");
