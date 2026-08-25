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
	{ 0x37a0cba, "kfree" },
	{ 0x5c9195f7, "i2c_del_adapter" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x3b35bc92, "matroxfb_DAC_in" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x2743599c, "matroxfb_DAC_out" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x502771e2, "i2c_bit_add_bus" },
	{ 0x4136f0cb, "i2c_new_scanned_device" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc27638a0, "matroxfb_register_driver" },
	{ 0x6690493, "matroxfb_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "matroxfb_misc,i2c-algo-bit,matroxfb_base");


MODULE_INFO(srcversion, "3AE3F4606604F50119B800E");
