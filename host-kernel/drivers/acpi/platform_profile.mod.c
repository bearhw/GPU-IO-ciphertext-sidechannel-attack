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

SYMBOL_CRC(platform_profile_notify, 0x67927a0d, "_gpl");
SYMBOL_CRC(platform_profile_register, 0xcac33cd4, "_gpl");
SYMBOL_CRC(platform_profile_remove, 0xbfe36436, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xd5f06bdd, "acpi_kobj" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0xb0101402, "sysfs_notify" },
	{ 0x169938c1, "__sysfs_match_string" },
	{ 0x99f2d00a, "sysfs_emit_at" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3C25CD1CC5B3A38765B4865");
