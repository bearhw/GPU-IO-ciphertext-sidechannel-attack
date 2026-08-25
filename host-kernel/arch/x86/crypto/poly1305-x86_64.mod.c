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

SYMBOL_CRC(poly1305_init_arch, 0xe1df0e1b, "");
SYMBOL_CRC(poly1305_update_arch, 0xd9ec23eb, "");
SYMBOL_CRC(poly1305_final_arch, 0xfaeb41b2, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x73dd54eb, "irq_fpu_usable" },
	{ 0x69acdf38, "memcpy" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xaed5dc46, "crypto_register_shash" },
	{ 0x188426d5, "crypto_unregister_shash" },
	{ 0xcaa68533, "cpu_has_xfeatures" },
	{ 0xfb578fc5, "memset" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6b2b69f7, "static_key_enable" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "89760B1548AC707D66CDA21");
