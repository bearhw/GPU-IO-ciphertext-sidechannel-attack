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

SYMBOL_CRC(suni_init, 0x22a688a2, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x37a0cba, "kfree" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xaa024146, "sonet_copy_stats" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x9feaf287, "sonet_subtract_stats" },
	{ 0xc6cbbc89, "capable" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x3e9936e5, "atm_dev_signal_change" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x24d273d1, "add_timer" },
	{ 0x92997ed8, "_printk" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm");


MODULE_INFO(srcversion, "52C0FCC3165C95A742E8AFB");
