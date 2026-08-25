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
	{ 0x79f72f96, "platform_device_put" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x33604920, "fpga_region_class_find" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x18b9f6d4, "fpga_region_program_fpga" },
	{ 0x96848186, "scnprintf" },
	{ 0xf474c21c, "bitmap_print_to_pagebuf" },
	{ 0x68c4b824, "cpumask_any_but" },
	{ 0x80a93eb3, "fpga_image_info_free" },
	{ 0x38255d3f, "dfl_fpga_dev_ops_unregister" },
	{ 0xb2b884c, "fpga_bridges_put" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x774a0a6d, "platform_device_add_data" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x2be201b9, "__cpuhp_state_remove_instance" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9a788c05, "dfl_fpga_dev_feature_init" },
	{ 0x3197c4e3, "put_device" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x7539145c, "perf_pmu_migrate_context" },
	{ 0x25750a11, "perf_pmu_register" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa86595d8, "__cpuhp_setup_state" },
	{ 0x1c12c32, "cpu_bit_bitmap" },
	{ 0x19ff5be4, "platform_device_unregister" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x47155238, "platform_device_add" },
	{ 0xe0e3dc52, "dfl_feature_ioctl_set_irq" },
	{ 0xb1e0feb2, "__cpuhp_state_add_instance" },
	{ 0x376325f4, "platform_device_alloc" },
	{ 0x983b9baa, "perf_pmu_unregister" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x6a6e05bf, "kstrtou8" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xb3c12465, "dfl_feature_ioctl_get_num_irqs" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xb3311354, "devm_hwmon_device_register_with_info" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x473786ad, "devm_kasprintf" },
	{ 0x6d606913, "pv_ops" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x264dafe, "dfl_fpga_dev_feature_uinit" },
	{ 0x999e8297, "vfree" },
	{ 0x624e770f, "fpga_image_info_alloc" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x7ded4891, "dfl_fpga_dev_ops_register" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x45bbd3c8, "dfl_fpga_cdev_assign_port" },
	{ 0x66cca4f9, "__x86_indirect_thunk_rcx" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xda8bae0d, "__cpuhp_remove_state" },
	{ 0xa84f915, "dfl_fpga_set_irq_triggers" },
	{ 0x1bc1808e, "dfl_fpga_cdev_release_port" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "fpga-region,fpga-mgr,dfl,fpga-bridge");


MODULE_INFO(srcversion, "49F2AA1F42ECE731F6310FB");
