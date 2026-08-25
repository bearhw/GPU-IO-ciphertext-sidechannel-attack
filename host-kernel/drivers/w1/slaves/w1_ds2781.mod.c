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

SYMBOL_CRC(w1_ds2781_io, 0x73b4ee88, "");
SYMBOL_CRC(w1_ds2781_eeprom_cmd, 0xa2f4d1f5, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x5c945c57, "w1_reset_select_slave" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xfccee5f1, "w1_write_8" },
	{ 0xe5cf19c, "w1_write_block" },
	{ 0xd9d87f1c, "w1_read_block" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x376325f4, "platform_device_alloc" },
	{ 0x47155238, "platform_device_add" },
	{ 0x79f72f96, "platform_device_put" },
	{ 0x31aa6211, "w1_register_family" },
	{ 0x56f5a4a1, "w1_unregister_family" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "wire");


MODULE_INFO(srcversion, "30E8EE3D30546DC74C0442E");
