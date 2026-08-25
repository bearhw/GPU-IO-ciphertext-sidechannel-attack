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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(linedisp_register, 0xb16b33b3, "_gpl");
SYMBOL_CRC(linedisp_unregister, 0xf8f29f5f, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x3312881b, "device_del" },
	{ 0x37a0cba, "kfree" },
	{ 0x3197c4e3, "put_device" },
	{ 0x754d539c, "strlen" },
	{ 0xb3f548ad, "kmemdup_nul" },
	{ 0xfb578fc5, "memset" },
	{ 0xbd3718be, "device_initialize" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x48098f3, "device_add" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8F694371478A7F6503D77B1");
