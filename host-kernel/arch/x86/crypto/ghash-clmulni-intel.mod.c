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
	{ 0xcea381dd, "x86_match_cpu" },
	{ 0xb40ed353, "cryptd_free_ahash" },
	{ 0x722c8dff, "cryptd_alloc_ahash" },
	{ 0x3abcdffb, "crypto_stats_get" },
	{ 0x73dd54eb, "irq_fpu_usable" },
	{ 0x1556bcf5, "shash_ahash_update" },
	{ 0x1f42e417, "crypto_ahash_setkey" },
	{ 0x227aaf79, "cryptd_ahash_child" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x66fa698c, "crypto_unregister_ahash" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0xaed5dc46, "crypto_register_shash" },
	{ 0x188426d5, "crypto_unregister_shash" },
	{ 0xb33867ed, "crypto_register_ahash" },
	{ 0x454e8eca, "cryptd_shash_desc" },
	{ 0x347da517, "crypto_ahash_digest" },
	{ 0x7e9b64ed, "crypto_ahash_final" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x9265315, "crypto_shash_final" },
	{ 0x3498d552, "crypto_stats_ahash_update" },
	{ 0x4ab863, "shash_ahash_digest" },
	{ 0x6f3adf0, "cryptd_ahash_queued" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cryptd");

MODULE_ALIAS("cpu:type:x86,ven*fam*mod*:feature:*0081*");

MODULE_INFO(srcversion, "093D268C05107044754339D");
