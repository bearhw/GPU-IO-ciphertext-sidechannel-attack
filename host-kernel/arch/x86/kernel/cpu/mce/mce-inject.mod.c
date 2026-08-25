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
	{ 0x211130c1, "alloc_cpumask_var" },
	{ 0xe85fea61, "simple_attr_write" },
	{ 0x6228c21f, "smp_call_function_single" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xbee8bbb8, "simple_attr_open" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x77bc13a0, "strim" },
	{ 0xa8be3ba8, "apic" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x7915cee5, "do_machine_check" },
	{ 0xe64ad8ea, "unregister_nmi_handler" },
	{ 0x69acdf38, "memcpy" },
	{ 0x20ba4f3e, "rdmsr_on_cpu" },
	{ 0x18fb2caf, "cpus_read_unlock" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x92997ed8, "_printk" },
	{ 0xa7127da7, "mce_unregister_injector_chain" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xc45d0d13, "injectm" },
	{ 0x1aff3d55, "mce_register_injector_chain" },
	{ 0x5f56663b, "rdmsrl_on_cpu" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xdba0e344, "machine_check_poll" },
	{ 0xa04f945a, "cpus_read_lock" },
	{ 0xe5e94814, "simple_attr_release" },
	{ 0x23d1b90, "wrmsr_on_cpu" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xde4eeab5, "__register_nmi_handler" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x5a921311, "strncmp" },
	{ 0x738fe32b, "amd_get_nodes_per_socket" },
	{ 0xd1f6c5f3, "smp_num_siblings" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x20a00b75, "simple_attr_read" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0xb86f74c5, "free_cpumask_var" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xbb13595e, "smp_call_function_many" },
	{ 0x6d606913, "pv_ops" },
	{ 0x953e1b9e, "ktime_get_real_seconds" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x12362d9f, "cpu_info" },
	{ 0xe0c77bb5, "mce_notify_irq" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x754d539c, "strlen" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0xec5e4645, "node_to_amd_nb" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0x3df82d00, "mce_log" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3D428B632A35F7E09BD46F0");
