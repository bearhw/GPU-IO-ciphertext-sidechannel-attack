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
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xf474c21c, "bitmap_print_to_pagebuf" },
	{ 0x37a0cba, "kfree" },
	{ 0x12362d9f, "cpu_info" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0x3c427f67, "cpu_die_map" },
	{ 0xb6cb556a, "_find_first_and_bit" },
	{ 0x618911fc, "numa_node" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xf50e291a, "kmem_cache_alloc_node_trace" },
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x92997ed8, "_printk" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x828e22f4, "hrtimer_forward" },
	{ 0x68c4b824, "cpumask_any_but" },
	{ 0x7539145c, "perf_pmu_migrate_context" },
	{ 0xcea381dd, "x86_match_cpu" },
	{ 0x6daf72fb, "perf_msr_probe" },
	{ 0x1389619c, "__max_die_per_package" },
	{ 0x39081193, "__max_logical_packages" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa86595d8, "__cpuhp_setup_state" },
	{ 0x25750a11, "perf_pmu_register" },
	{ 0xda8bae0d, "__cpuhp_remove_state" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x983b9baa, "perf_pmu_unregister" },
	{ 0xc2a6474c, "perf_event_sysfs_show" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("cpu:type:x86,ven*fam*mod*:feature:*007D*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod002A:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod002D:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003A:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003C:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003F:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0045:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0046:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod003D:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0047:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod004F:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0056:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0057:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0085:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod004E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod005E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0055:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod008E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod009E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0066:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod005C:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod005F:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod007A:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod007E:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod007D:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod006C:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod006A:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod00A6:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod00A5:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod0097:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod009A:feature:*");
MODULE_ALIAS("cpu:type:x86,ven0000fam0006mod008F:feature:*");

MODULE_INFO(srcversion, "AA598AEBEC16A522AC44798");
