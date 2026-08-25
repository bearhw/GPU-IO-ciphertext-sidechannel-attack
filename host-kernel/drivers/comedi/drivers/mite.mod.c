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

SYMBOL_CRC(mite_bytes_in_transit, 0x3ffdcb71, "_gpl");
SYMBOL_CRC(mite_sync_dma, 0x1fd339dc, "_gpl");
SYMBOL_CRC(mite_ack_linkc, 0xc073fc32, "_gpl");
SYMBOL_CRC(mite_done, 0x54692c13, "_gpl");
SYMBOL_CRC(mite_dma_arm, 0x3ca69576, "_gpl");
SYMBOL_CRC(mite_dma_disarm, 0xfef75ac8, "_gpl");
SYMBOL_CRC(mite_prep_dma, 0x0d56f697, "_gpl");
SYMBOL_CRC(mite_request_channel_in_range, 0xb27cc7b6, "_gpl");
SYMBOL_CRC(mite_request_channel, 0x46b3a51b, "_gpl");
SYMBOL_CRC(mite_release_channel, 0xab835de0, "_gpl");
SYMBOL_CRC(mite_init_ring_descriptors, 0x6b76324b, "_gpl");
SYMBOL_CRC(mite_buf_change, 0xa9be1d81, "_gpl");
SYMBOL_CRC(mite_alloc_ring, 0xaedc3735, "_gpl");
SYMBOL_CRC(mite_free_ring, 0x7d171675, "_gpl");
SYMBOL_CRC(mite_attach, 0x8937566d, "_gpl");
SYMBOL_CRC(mite_detach, 0x78e0b696, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf14b6194, "comedi_buf_write_alloc" },
	{ 0xb8c6fad, "comedi_buf_write_free" },
	{ 0x4ea2cf27, "comedi_inc_scan_progress" },
	{ 0xba8043ee, "comedi_bytes_per_scan" },
	{ 0xe741a6bb, "comedi_buf_read_alloc" },
	{ 0x6d840572, "comedi_buf_read_free" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x92997ed8, "_printk" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa40a8382, "get_device" },
	{ 0x37a0cba, "kfree" },
	{ 0xedc03953, "iounmap" },
	{ 0x6b019029, "comedi_to_pci_dev" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0x3197c4e3, "put_device" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "comedi,comedi_pci");


MODULE_INFO(srcversion, "B2A384C297C49CA1DD769B6");
