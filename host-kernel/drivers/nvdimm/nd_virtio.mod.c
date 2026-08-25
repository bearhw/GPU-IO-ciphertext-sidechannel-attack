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

SYMBOL_CRC(virtio_pmem_host_ack, 0xb8774cae, "_gpl");
SYMBOL_CRC(async_pmem_flush, 0xd58f40e1, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x559c47e5, "virtqueue_get_buf" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x800473f, "__cond_resched" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0x1a5cd18a, "virtqueue_add_sgs" },
	{ 0x6b5a92b2, "virtqueue_kick" },
	{ 0x37a0cba, "kfree" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x2587f789, "_dev_info" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9af19ea7, "fs_bio_set" },
	{ 0x7dcdb7d2, "bio_alloc_bioset" },
	{ 0x93391c7f, "bio_clone_blkg_association" },
	{ 0x9f218161, "bio_chain" },
	{ 0xefab6f8e, "submit_bio" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C20567CE3F13C4CE96D15D1");
