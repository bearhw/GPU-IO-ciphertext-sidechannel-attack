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
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3141f3e1, "padata_do_serial" },
	{ 0xb85eed2d, "crypto_aead_decrypt" },
	{ 0x8fa05a4d, "padata_do_parallel" },
	{ 0x2fc2f9ff, "crypto_aead_encrypt" },
	{ 0xb666d487, "crypto_aead_setauthsize" },
	{ 0x38eaab5, "crypto_aead_setkey" },
	{ 0x6b3ccdb4, "crypto_destroy_tfm" },
	{ 0x8bce639d, "crypto_drop_spawn" },
	{ 0x935e4a4c, "padata_free_shell" },
	{ 0x37a0cba, "kfree" },
	{ 0x5f1680ae, "padata_alloc" },
	{ 0xcfb8f52a, "kobject_add" },
	{ 0x640b4f57, "kobject_uevent" },
	{ 0xb51b0f5, "padata_free" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xfa57f273, "crypto_spawn_tfm2" },
	{ 0xfdbd7a17, "crypto_get_attr_type" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xce4934c5, "padata_alloc_shell" },
	{ 0x9a11a0fc, "crypto_attr_alg_name" },
	{ 0xa01fdea1, "crypto_grab_aead" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x1a7bb158, "aead_register_instance" },
	{ 0xaf8a4594, "kernel_kobj" },
	{ 0x7233a2e6, "kset_create_and_add" },
	{ 0xfd9dcc31, "crypto_register_template" },
	{ 0x3f7b09fb, "kset_unregister" },
	{ 0x8e04220, "crypto_unregister_template" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0A189F0F00A2CC8B8914FCA");
