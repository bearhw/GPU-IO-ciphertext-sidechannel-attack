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
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x848d372e, "iowrite8" },
	{ 0xe419bc99, "iowrite32be" },
	{ 0x26f8f0b8, "iowrite16be" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xf9a482f9, "msleep" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf2a22dc6, "w1_remove_master_device" },
	{ 0xb19b445, "ioread8" },
	{ 0x9bb4e317, "ioread32be" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x842c8e9d, "ioread16" },
	{ 0xa71d2e2c, "ioread16be" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0xeb819c8e, "devm_ioremap" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0xcf9384e, "w1_add_master_device" },
	{ 0xbc477a2, "irq_set_irq_type" },
	{ 0xa6257a2f, "complete" },
	{ 0x92997ed8, "_printk" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "wire");


MODULE_INFO(srcversion, "DE9D860A7F2FC5EE87D5B60");
