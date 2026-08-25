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

SYMBOL_CRC(ni_tio_write, 0xff33fb48, "_gpl");
SYMBOL_CRC(ni_tio_read, 0xb1b0ded6, "_gpl");
SYMBOL_CRC(ni_tio_set_bits, 0x0544eb26, "_gpl");
SYMBOL_CRC(ni_tio_get_soft_copy, 0x2bdd8064, "_gpl");
SYMBOL_CRC(ni_tio_arm, 0x9d0527c1, "_gpl");
SYMBOL_CRC(ni_tio_set_gate_src_raw, 0x8b5bc014, "_gpl");
SYMBOL_CRC(ni_tio_set_gate_src, 0x890ac61c, "_gpl");
SYMBOL_CRC(ni_tio_insn_config, 0x6a7fe1ee, "_gpl");
SYMBOL_CRC(ni_tio_get_routing, 0xac1cf23a, "_gpl");
SYMBOL_CRC(ni_tio_set_routing, 0xd4e06b79, "_gpl");
SYMBOL_CRC(ni_tio_unset_routing, 0x409afd9e, "_gpl");
SYMBOL_CRC(ni_tio_insn_read, 0xcd67167f, "_gpl");
SYMBOL_CRC(ni_tio_insn_write, 0x8c13f188, "_gpl");
SYMBOL_CRC(ni_tio_init_counter, 0xbc68fce2, "_gpl");
SYMBOL_CRC(ni_gpct_device_construct, 0xdcd7c831, "_gpl");
SYMBOL_CRC(ni_gpct_device_destroy, 0x24b9787e, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x37a0cba, "kfree" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "CC2447AA9F59A00D7F9C824");
