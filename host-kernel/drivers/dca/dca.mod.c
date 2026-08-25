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

SYMBOL_CRC(dca_add_requester, 0x23d9e9be, "_gpl");
SYMBOL_CRC(dca_remove_requester, 0xc7c900dd, "_gpl");
SYMBOL_CRC(dca3_get_tag, 0xe059f5e3, "_gpl");
SYMBOL_CRC(dca_get_tag, 0xaa634427, "_gpl");
SYMBOL_CRC(alloc_dca_provider, 0x34cf8ff9, "_gpl");
SYMBOL_CRC(free_dca_provider, 0x9b51801e, "_gpl");
SYMBOL_CRC(register_dca_provider, 0x53f50af2, "_gpl");
SYMBOL_CRC(unregister_dca_provider, 0x8d463908, "_gpl");
SYMBOL_CRC(dca_register_notify, 0xac34ecec, "_gpl");
SYMBOL_CRC(dca_unregister_notify, 0x01a33ab9, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xb905e0f7, "__class_create" },
	{ 0x39c0a04b, "device_unregister" },
	{ 0x73d00f0b, "class_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x907d14d, "blocking_notifier_chain_register" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0x823eae06, "blocking_notifier_call_chain" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x1f1f589c, "device_create" },
	{ 0x954f099c, "idr_preload" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4ece3615, "blocking_notifier_chain_unregister" },
	{ 0xdaa33c7e, "device_destroy" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F3A4463C001C0CDFFF540C1");
