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
	{ 0x97ccc282, "cxl_probe_component_regs" },
	{ 0x291866a4, "cxl_enumerate_cmds" },
	{ 0x5897cdd4, "param_ops_ushort" },
	{ 0xae121354, "pci_iomap" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x7d628444, "memcpy_fromio" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x43694967, "devm_cxl_add_nvdimm" },
	{ 0x64a31445, "mutex_lock_io" },
	{ 0xb9e7429c, "memcpy_toio" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xbdb6dbf3, "cxl_find_regblock" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xfbdc7a3d, "cxl_map_component_regs" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xa418d353, "devm_cxl_add_memdev" },
	{ 0x6f3148e1, "cxl_probe_device_regs" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0xa446c503, "cxl_map_device_regs" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x3274edae, "cxl_dev_state_identify" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xec580ef0, "cxl_mem_create_range_info" },
	{ 0xb2bc638b, "pci_find_dvsec_capability" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0xfe61ec2f, "cxl_dev_state_create" },
	{ 0xcc9f27a6, "pci_get_dsn" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cxl_core");

MODULE_ALIAS("pci:v*d*sv*sd*bc05sc02i10*");

MODULE_INFO(srcversion, "4FECDED6C7252551439C57A");
