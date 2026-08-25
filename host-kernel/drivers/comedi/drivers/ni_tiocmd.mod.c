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

SYMBOL_CRC(ni_tio_cmd, 0x45622ada, "_gpl");
SYMBOL_CRC(ni_tio_cmdtest, 0xca6df2d1, "_gpl");
SYMBOL_CRC(ni_tio_cancel, 0xb7169bec, "_gpl");
SYMBOL_CRC(ni_tio_acknowledge, 0x0ead5358, "_gpl");
SYMBOL_CRC(ni_tio_handle_interrupt, 0xbbd5bd70, "_gpl");
SYMBOL_CRC(ni_tio_set_mite_channel, 0xc686ff80, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x3ca69576, "mite_dma_arm" },
	{ 0x9d0527c1, "ni_tio_arm" },
	{ 0xb1b0ded6, "ni_tio_read" },
	{ 0x2bdd8064, "ni_tio_get_soft_copy" },
	{ 0xff33fb48, "ni_tio_write" },
	{ 0x54692c13, "mite_done" },
	{ 0x2587f789, "_dev_info" },
	{ 0xc073fc32, "mite_ack_linkc" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0xfef75ac8, "mite_dma_disarm" },
	{ 0x544eb26, "ni_tio_set_bits" },
	{ 0xb3e302a3, "ni_route_to_register" },
	{ 0x8b5bc014, "ni_tio_set_gate_src_raw" },
	{ 0xf14b6194, "comedi_buf_write_alloc" },
	{ 0xd56f697, "mite_prep_dma" },
	{ 0x890ac61c, "ni_tio_set_gate_src" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x76bc308, "ni_find_route_source" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "mite,ni_tio,ni_routing,comedi");


MODULE_INFO(srcversion, "9457BA8E929F0716BC9C4FB");
