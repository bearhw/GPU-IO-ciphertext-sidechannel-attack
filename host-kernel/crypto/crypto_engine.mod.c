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

SYMBOL_CRC(crypto_transfer_aead_request_to_engine, 0x4c56cc41, "_gpl");
SYMBOL_CRC(crypto_transfer_akcipher_request_to_engine, 0x3ac538cc, "_gpl");
SYMBOL_CRC(crypto_transfer_hash_request_to_engine, 0xbadf278a, "_gpl");
SYMBOL_CRC(crypto_transfer_kpp_request_to_engine, 0x1c82326b, "_gpl");
SYMBOL_CRC(crypto_transfer_skcipher_request_to_engine, 0xb302dc9b, "_gpl");
SYMBOL_CRC(crypto_finalize_aead_request, 0x91adc3d1, "_gpl");
SYMBOL_CRC(crypto_finalize_akcipher_request, 0xd2968a30, "_gpl");
SYMBOL_CRC(crypto_finalize_hash_request, 0x1b76db1f, "_gpl");
SYMBOL_CRC(crypto_finalize_kpp_request, 0xa2ca32cb, "_gpl");
SYMBOL_CRC(crypto_finalize_skcipher_request, 0xf344871d, "_gpl");
SYMBOL_CRC(crypto_engine_start, 0x7a555c95, "_gpl");
SYMBOL_CRC(crypto_engine_stop, 0x5f1077c0, "_gpl");
SYMBOL_CRC(crypto_engine_alloc_init_and_set, 0x17e120ab, "_gpl");
SYMBOL_CRC(crypto_engine_alloc_init, 0x92148c6e, "_gpl");
SYMBOL_CRC(crypto_engine_exit, 0x6663aa59, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xf4753987, "kthread_queue_work" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xf9a482f9, "msleep" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x56dc6f0a, "kthread_destroy_worker" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x499043d3, "crypto_init_queue" },
	{ 0xe6e15da0, "kthread_create_worker" },
	{ 0x2587f789, "_dev_info" },
	{ 0xcd34c8dd, "sched_set_fifo" },
	{ 0x7db4dbe9, "crypto_enqueue_request" },
	{ 0x372076ef, "crypto_dequeue_request" },
	{ 0xadaeacb, "crypto_enqueue_request_head" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "584AFCFF9C636005734C012");
