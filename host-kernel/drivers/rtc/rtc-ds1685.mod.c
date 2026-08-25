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

SYMBOL_CRC(ds1685_rtc_poweroff, 0x53d86eef, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x27bbf221, "disable_irq_nosync" },
	{ 0x92997ed8, "_printk" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xf9a482f9, "msleep" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xd7945cb2, "rtc_update_irq" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x4859b8bb, "rtc_year_days" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0x6971447a, "rtc_month_days" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x434c7510, "devm_platform_ioremap_resource" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9e9124a4, "devm_rtc_allocate_device" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x35ddfd66, "rtc_add_group" },
	{ 0xfbad13e8, "devm_rtc_nvmem_register" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x733a4dce, "__devm_rtc_register_device" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "23C1768DB476C03BD857282");
