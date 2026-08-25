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
	{ 0xb9cba57f, "cast_s3" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x4129f5ee, "kernel_fpu_begin_mask" },
	{ 0x38722f80, "kernel_fpu_end" },
	{ 0xa44449bb, "skcipher_walk_virt" },
	{ 0xbe883784, "simd_register_skciphers_compat" },
	{ 0x188d9d26, "__cast5_decrypt" },
	{ 0xcaa68533, "cpu_has_xfeatures" },
	{ 0x9f30b717, "cast5_setkey" },
	{ 0x86979d6, "skcipher_walk_done" },
	{ 0x5609ce41, "cast_s2" },
	{ 0xef81a4af, "__cast5_encrypt" },
	{ 0xb8fb702c, "simd_unregister_skciphers" },
	{ 0xbd3e7542, "cast_s1" },
	{ 0x5b17be06, "cast_s4" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cast_common,crypto_simd,cast5_generic");


MODULE_INFO(srcversion, "12FDF1453B7AD03245B0648");
