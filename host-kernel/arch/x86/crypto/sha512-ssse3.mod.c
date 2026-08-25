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
	{ 0xc0173b2f, "crypto_unregister_shashes" },
	{ 0x73dd54eb, "irq_fpu_usable" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x70bc66eb, "crypto_sha512_finup" },
	{ 0x69acdf38, "memcpy" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65848715, "crypto_sha512_update" },
	{ 0x92997ed8, "_printk" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xf943cb4c, "crypto_register_shashes" },
	{ 0xcaa68533, "cpu_has_xfeatures" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BC2B2AE4263C227B70FA99D");
