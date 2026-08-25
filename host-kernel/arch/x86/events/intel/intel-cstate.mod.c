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
	{ 0xf474c21c, "bitmap_print_to_pagebuf" },
	{ 0x68c4b824, "cpumask_any_but" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7539145c, "perf_pmu_migrate_context" },
	{ 0x25750a11, "perf_pmu_register" },
	{ 0x1389619c, "__max_die_per_package" },
	{ 0x3c427f67, "cpu_die_map" },
	{ 0xa86595d8, "__cpuhp_setup_state" },
	{ 0xc2a6474c, "perf_event_sysfs_show" },
	{ 0x983b9baa, "perf_pmu_unregister" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xb6cb556a, "_find_first_and_bit" },
	{ 0x6d606913, "pv_ops" },
	{ 0x6daf72fb, "perf_msr_probe" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xda8bae0d, "__cpuhp_remove_state" },
	{ 0x3b83610f, "cpu_sibling_map" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod001E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod001A:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod002E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0025:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod002C:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod002F:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod002A:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod002D:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003A:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003C:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003F:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0046:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0045:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0037:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod004D:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod004C:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003D:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0056:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0047:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod004F:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod004E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod005E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0055:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod008E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod009E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod00A6:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod00A5:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0066:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0057:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0085:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod005C:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod005F:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod007A:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0086:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0096:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod009C:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod007E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod007D:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod006A:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod006C:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod008F:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod008C:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod008D:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod00A7:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0097:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod009A:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod00BE:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod00B7:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod00BA:feature:*");

MODULE_INFO(srcversion, "5B3BB056B33D524662CD49F");
