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
	{ 0xa04f945a, "cpus_read_lock" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0x18fb2caf, "cpus_read_unlock" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xd92deb6b, "acpi_evaluate_object" },
	{ 0x37a0cba, "kfree" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x74754435, "acpi_bus_generate_netlink_event" },
	{ 0xc42dcb99, "acpi_evaluate_ost" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x92997ed8, "_printk" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0x96848186, "scnprintf" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0xf474c21c, "bitmap_print_to_pagebuf" },
	{ 0x2121e851, "device_create_file" },
	{ 0x170ddf79, "acpi_install_notify_handler" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0x1c58427f, "acpi_remove_notify_handler" },
	{ 0x3b83610f, "cpu_sibling_map" },
	{ 0x86490580, "current_task" },
	{ 0xe5084537, "sched_set_fifo_low" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x6d606913, "pv_ops" },
	{ 0x5c5a1b16, "tick_broadcast_control" },
	{ 0xbfe5616d, "tick_broadcast_oneshot_control" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x2b67b6b7, "mds_idle_clear" },
	{ 0x4629334c, "__preempt_count" },
	{ 0xf09cc34, "schedule_timeout_killable" },
	{ 0x1000e51, "schedule" },
	{ 0x56398615, "mark_tsc_unstable" },
	{ 0x211130c1, "alloc_cpumask_var" },
	{ 0xfb578fc5, "memset" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xa084749a, "__bitmap_or" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xadfdfcef, "__bitmap_andnot" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x1c12c32, "cpu_bit_bitmap" },
	{ 0x10a9c624, "set_cpus_allowed_ptr" },
	{ 0xb86f74c5, "free_cpumask_var" },
	{ 0x731dba7a, "xen_domain_type" },
	{ 0x54ea6dfe, "xen_start_flags" },
	{ 0x327bd7da, "acpi_bus_register_driver" },
	{ 0xf0cd6f57, "acpi_bus_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("acpi*:ACPI000C:*");

MODULE_INFO(srcversion, "7AE9D74DD34A56ACFBE5531");
