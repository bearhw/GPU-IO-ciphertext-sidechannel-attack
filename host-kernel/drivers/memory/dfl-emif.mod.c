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
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x6902f204, "devm_ioremap_resource" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x800473f, "__cond_resched" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xe783e261, "sysfs_emit" },
	{ 0x467b27e7, "__dfl_driver_register" },
	{ 0xaf4e4c1f, "dfl_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dfl");

MODULE_ALIAS("dfl:t0000f0009*");

MODULE_INFO(srcversion, "C0225FA5B36A8453FE33B28");
