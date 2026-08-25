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

SYMBOL_CRC(cqhci_deactivate, 0xa13544d8, "");
SYMBOL_CRC(cqhci_resume, 0xfd85c6b3, "");
SYMBOL_CRC(cqhci_irq, 0xd014e30e, "");
SYMBOL_CRC(cqhci_pltfm_init, 0xada53007, "");
SYMBOL_CRC(cqhci_init, 0xb31c7751, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x3943995e, "dmam_alloc_attrs" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x92540fbf, "finish_wait" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x69acdf38, "memcpy" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xd7d18c4, "platform_get_resource_byname" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xd7ba36e6, "mmc_cqe_request_done" },
	{ 0x76aa840b, "dmam_free_coherent" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x6d606913, "pv_ops" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x87b8798d, "sg_next" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x56470118, "__warn_printk" },
	{ 0xefce2322, "devm_blk_crypto_profile_init" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C0C66730EFF7B66502AC0D8");
