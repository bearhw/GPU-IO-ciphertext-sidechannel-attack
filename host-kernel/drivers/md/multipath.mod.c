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
	{ 0x6012a0ef, "bio_associate_blkg" },
	{ 0x21d6e3b6, "register_md_personality" },
	{ 0x5ef68429, "md_integrity_register" },
	{ 0x7c04c00f, "md_check_no_bitmap" },
	{ 0x205bff71, "bio_init_clone" },
	{ 0x8eb7efa2, "md_error" },
	{ 0x15c85de3, "mempool_init" },
	{ 0x37a0cba, "kfree" },
	{ 0xd35a6d31, "mempool_kmalloc" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xa897e3e7, "mempool_free" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x22c71c1, "md_wakeup_thread" },
	{ 0x6a037cf1, "mempool_kfree" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0xac25495b, "md_set_array_sectors" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xc3762aec, "mempool_alloc" },
	{ 0x2d26b611, "bio_endio" },
	{ 0xb244293b, "md_integrity_add_rdev" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x36c22ba6, "submit_bio_noacct" },
	{ 0xa906274e, "seq_putc" },
	{ 0x90d27bc3, "disk_stack_limits" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x2c4354fc, "md_flush_request" },
	{ 0x5232906e, "md_register_thread" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4f2e94e7, "unregister_md_personality" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xd3220720, "md_check_recovery" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x38e46431, "mempool_exit" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1D8B146F0FD19FD985184FA");
