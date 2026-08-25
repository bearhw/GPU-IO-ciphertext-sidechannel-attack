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
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x5c945c57, "w1_reset_select_slave" },
	{ 0xe5cf19c, "w1_write_block" },
	{ 0x2587f789, "_dev_info" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xfccee5f1, "w1_write_8" },
	{ 0x94ea671e, "w1_read_8" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x6ca43304, "w1_touch_bit" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0xbd6841d4, "crc16" },
	{ 0xd9d87f1c, "w1_read_block" },
	{ 0xd18e830d, "w1_reset_resume_command" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xf9c0b663, "strlcat" },
	{ 0x6b7bb67b, "i2c_add_adapter" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x31aa6211, "w1_register_family" },
	{ 0x56f5a4a1, "w1_unregister_family" },
	{ 0x3c872672, "param_ops_byte" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "wire");


MODULE_INFO(srcversion, "596DA5B591B6BF120E4C603");
