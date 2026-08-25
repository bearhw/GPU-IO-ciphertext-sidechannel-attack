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
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x94863f08, "lm3533_update" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x9609a890, "lm3533_ctrlbank_set_brightness" },
	{ 0xa4a35010, "lm3533_ctrlbank_disable" },
	{ 0x10bf740f, "led_classdev_unregister" },
	{ 0x8ca57575, "lm3533_write" },
	{ 0x56867ff8, "lm3533_read" },
	{ 0x96848186, "scnprintf" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6a6e05bf, "kstrtou8" },
	{ 0x4762a555, "lm3533_ctrlbank_set_pwm" },
	{ 0x525bf8a3, "lm3533_ctrlbank_get_pwm" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xc5f22f39, "lm3533_ctrlbank_get_brightness" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x7d1f7670, "led_classdev_register_ext" },
	{ 0x6da91286, "lm3533_ctrlbank_set_max_current" },
	{ 0x4e0a5f5d, "lm3533_ctrlbank_enable" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "lm3533-core,lm3533-ctrlbank");


MODULE_INFO(srcversion, "D1763BC376731218E3E3CF1");
