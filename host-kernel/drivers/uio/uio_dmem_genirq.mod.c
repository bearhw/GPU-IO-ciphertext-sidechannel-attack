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
	{ 0x80b95d7e, "__pm_runtime_disable" },
	{ 0x77280dd7, "__pm_runtime_idle" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0xf26750d4, "__pm_runtime_resume" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0xfcec0987, "enable_irq" },
	{ 0x27bbf221, "disable_irq_nosync" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x473786ad, "devm_kasprintf" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xbb7cf14f, "irq_get_irq_data" },
	{ 0xeb063dbe, "pm_runtime_enable" },
	{ 0xd0b0bd6e, "devm_add_action" },
	{ 0xa0d4f927, "__devm_uio_register_device" },
	{ 0x5b445cb8, "platform_get_irq" },
	{ 0x7522f3ba, "irq_modify_status" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "uio");


MODULE_INFO(srcversion, "AE91119FCC5C0C76968FECC");
