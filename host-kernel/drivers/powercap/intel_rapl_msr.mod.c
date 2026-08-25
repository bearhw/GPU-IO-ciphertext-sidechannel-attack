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
	{ 0x6d606913, "pv_ops" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xda8bae0d, "__cpuhp_remove_state" },
	{ 0xdce808c0, "powercap_unregister_control_type" },
	{ 0x883c3157, "rapl_find_package_domain" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0xd5736ff4, "rapl_remove_package" },
	{ 0xbc147db8, "rapl_add_package" },
	{ 0x6228c21f, "smp_call_function_single" },
	{ 0xa5e55057, "rdmsrl_safe_on_cpu" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0xcea381dd, "x86_match_cpu" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0xd97908e9, "powercap_register_control_type" },
	{ 0xa86595d8, "__cpuhp_setup_state" },
	{ 0x92997ed8, "_printk" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "intel_rapl_common");

MODULE_ALIAS("platform:intel_rapl_msr");

MODULE_INFO(srcversion, "7EA8CDDF05D324AF7329460");
