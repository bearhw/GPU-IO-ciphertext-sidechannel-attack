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

SYMBOL_CRC(amd_register_ecc_decoder, 0x8592d892, "_gpl");
SYMBOL_CRC(amd_unregister_ecc_decoder, 0x0be1a4d8, "_gpl");
SYMBOL_CRC(pp_msgs, 0x1d34e996, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xf2d7d87, "mce_unregister_decode_chain" },
	{ 0x5fdf7b32, "smca_get_bank_type" },
	{ 0x6340434e, "x86_model" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xc3cc4300, "smca_get_long_name" },
	{ 0x6d606913, "pv_ops" },
	{ 0x12362d9f, "cpu_info" },
	{ 0xb8b2b1f7, "mce_register_decode_chain" },
	{ 0x4c762b5c, "x86_stepping" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2c2f5a09, "x86_family" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C3739588B8F9C446E0E1A2A");
