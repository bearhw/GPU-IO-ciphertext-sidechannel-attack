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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x5838f6c9, "rtc_valid_tm" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x548ad742, "platform_get_irq_optional" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0xfbad13e8, "devm_rtc_nvmem_register" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "22FCBCB5664D0BDD6996FE4");
