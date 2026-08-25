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
	{ 0x569c2f54, "alloc_pages" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xc683da81, "set_memory_decrypted" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xd5f3bb7b, "set_memory_encrypted" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x56470118, "__warn_printk" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x37a0cba, "kfree" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x79df9633, "ioremap_encrypted" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa5577939, "crypto_alloc_aead" },
	{ 0x38eaab5, "crypto_aead_setkey" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xb666d487, "crypto_aead_setauthsize" },
	{ 0x4708008a, "misc_register" },
	{ 0x2587f789, "_dev_info" },
	{ 0xedc03953, "iounmap" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xf888ca21, "sg_init_table" },
	{ 0xc131710d, "crypto_req_done" },
	{ 0xb85eed2d, "crypto_aead_decrypt" },
	{ 0xd0760fc0, "kfree_sensitive" },
	{ 0x2fc2f9ff, "crypto_aead_encrypt" },
	{ 0x25974000, "wait_for_completion" },
	{ 0xfb578fc5, "memset" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x2ca89fe7, "snp_issue_guest_request" },
	{ 0x60494799, "_dev_alert" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x6f477cbc, "__platform_driver_probe" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "73965BE626DAC3E842A5AE6");
