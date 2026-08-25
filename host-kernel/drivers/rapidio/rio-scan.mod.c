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
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x6d606913, "pv_ops" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x37a0cba, "kfree" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x54c3fdd0, "__rio_local_read_config_32" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x759de4e1, "rio_alloc_net" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x92997ed8, "_printk" },
	{ 0x40fb0b61, "rio_free_net" },
	{ 0x8cc5b4fe, "dev_set_name" },
	{ 0x355f024, "rio_add_net" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x7b37d4a7, "_find_first_zero_bit" },
	{ 0x5a3a4a00, "rio_mport_read_config_32" },
	{ 0x3761b0f5, "rio_mport_write_config_32" },
	{ 0x53cf016d, "rio_attach_device" },
	{ 0xa1357083, "rio_add_device" },
	{ 0x2c28258e, "rio_dev_get" },
	{ 0xc4ab77ca, "rio_route_clr_table" },
	{ 0x8767ad79, "rio_mport_get_physefb" },
	{ 0x580df5ba, "rio_mport_get_feature" },
	{ 0xb289a3ba, "rio_enable_rx_tx_port" },
	{ 0x31c6c6e9, "rio_lock_device" },
	{ 0x435aee77, "rio_route_get_entry" },
	{ 0xd6e84238, "rio_unlock_device" },
	{ 0x73887101, "rio_mport_chk_dev_access" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x4bf0c16, "rio_route_add_entry" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0x45042af4, "rio_get_comptag" },
	{ 0x114e8ae9, "rio_set_port_lockout" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x469b212, "__rio_local_write_config_32" },
	{ 0x40a6f781, "rio_local_set_device_id" },
	{ 0xd3824161, "rio_pw_enable" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xf9a482f9, "msleep" },
	{ 0x792cbab6, "rio_register_scan" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xe1bd6c99, "rio_init_mports" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C332AB5A2F1DA9918101A3B");
