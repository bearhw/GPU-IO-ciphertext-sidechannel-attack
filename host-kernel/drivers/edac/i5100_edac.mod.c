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
	{ 0xfe295174, "edac_mc_del_mc" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0x2c39ca93, "edac_mc_free" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x3c7181, "edac_mc_handle_error" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x3dad9978, "cancel_delayed_work" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xf110992b, "pci_get_device" },
	{ 0x7a537036, "edac_mc_alloc" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xb51fbd64, "edac_op_state" },
	{ 0xbfbb39b8, "edac_mc_add_mc_with_groups" },
	{ 0x92997ed8, "_printk" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("pci:v00008086d000065F0sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "030BC7234C957F2E3F90A94");
