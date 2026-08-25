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
	{ 0xa53d4e7, "drm_mode_probed_add" },
	{ 0xed77317d, "drm_property_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0xf0b1551a, "i2c_transfer_buffer_flags" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xcef59382, "drm_i2c_encoder_destroy" },
	{ 0x1a0f57db, "drm_crtc_helper_set_mode" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x6bc0a4ce, "drm_mode_create_tv_properties" },
	{ 0xb5e74aec, "drm_mode_duplicate" },
	{ 0x9bc9f8fe, "drm_object_attach_property" },
	{ 0x5927ae8, "param_ops_charp" },
	{ 0xe2d5255a, "strcmp" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7727ca0b, "drm_object_property_set_value" },
	{ 0x5907632e, "drm_helper_probe_single_connector_modes" },
	{ 0x4088b7b0, "drm_property_create_range" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x1c1edde4, "_dev_printk" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "drm,drm_kms_helper");

MODULE_ALIAS("i2c:ch7006");

MODULE_INFO(srcversion, "7327E9C928051FC771AFFB0");
