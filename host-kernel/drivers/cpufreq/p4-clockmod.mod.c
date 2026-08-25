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
	{ 0x20ba4f3e, "rdmsr_on_cpu" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x23d1b90, "wrmsr_on_cpu" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x12362d9f, "cpu_info" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x3b83610f, "cpu_sibling_map" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x69acdf38, "memcpy" },
	{ 0xd7ab2c0c, "speedstep_detect_processor" },
	{ 0xc9216a82, "recalibrate_cpu_khz" },
	{ 0x2b67f096, "speedstep_get_frequency" },
	{ 0x92997ed8, "_printk" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xcea381dd, "x86_match_cpu" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x4eb2160, "cpufreq_register_driver" },
	{ 0x96508aff, "cpufreq_unregister_driver" },
	{ 0xc289e46d, "cpufreq_generic_frequency_table_verify" },
	{ 0x56648162, "cpufreq_generic_attr" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "speedstep-lib");


MODULE_INFO(srcversion, "C6D735CE78A8C853EC217DE");
