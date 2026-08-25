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
	{ 0x37a0cba, "kfree" },
	{ 0xf0b1551a, "i2c_transfer_buffer_flags" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcef59382, "drm_i2c_encoder_destroy" },
	{ 0x4f18a150, "__drm_debug" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x97ff9a18, "i2c_unregister_device" },
	{ 0x73965ef6, "i2c_new_client_device" },
	{ 0x5e6e333f, "i2c_transfer" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x1c1edde4, "_dev_printk" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm_kms_helper,drm");

MODULE_ALIAS("i2c:sil164");

MODULE_INFO(srcversion, "688BB19B71AFAB3A6AB9ABC");
