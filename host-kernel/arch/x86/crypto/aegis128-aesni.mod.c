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
	{ 0xa6dee470, "simd_register_aeads_compat" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xcaa68533, "cpu_has_xfeatures" },
	{ 0x86490580, "current_task" },
	{ 0x9f0c3bd, "skcipher_walk_aead_encrypt" },
	{ 0x86979d6, "skcipher_walk_done" },
	{ 0x5a44f8cb, "__crypto_memneq" },
	{ 0x845dbf3b, "scatterwalk_map_and_copy" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0xad024ce2, "simd_unregister_aeads" },
	{ 0x87b8798d, "sg_next" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xd7f34d89, "skcipher_walk_aead_decrypt" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "crypto_simd");


MODULE_INFO(srcversion, "F1B19A00C1818A58C8C5104");
