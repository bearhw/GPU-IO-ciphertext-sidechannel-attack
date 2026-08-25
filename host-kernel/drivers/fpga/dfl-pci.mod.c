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
	{ 0xfa552711, "pci_disable_sriov" },
	{ 0x22ae580, "dfl_fpga_cdev_config_ports_pf" },
	{ 0xd8ebbd2a, "dfl_fpga_cdev_config_ports_vf" },
	{ 0xda2d4a25, "pci_enable_sriov" },
	{ 0xc02b1605, "pcim_enable_device" },
	{ 0x9819ee8, "pci_enable_pcie_error_reporting" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x54b3a267, "dfl_fpga_enum_info_alloc" },
	{ 0x683cd46f, "pci_msix_vec_count" },
	{ 0xeabc08da, "pci_alloc_irq_vectors_affinity" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xe8c72c30, "pci_irq_vector" },
	{ 0x4f6c4917, "dfl_fpga_enum_info_add_irq" },
	{ 0x37a0cba, "kfree" },
	{ 0x369301b6, "pci_find_next_ext_capability" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0x91d2a494, "dfl_fpga_enum_info_add_dfl" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xb669e969, "pcim_iounmap_regions" },
	{ 0x87afd48d, "dfl_fpga_feature_devs_enumerate" },
	{ 0xe4f698c9, "dfl_fpga_enum_info_free" },
	{ 0xd1b569d4, "pci_free_irq_vectors" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x70b011b7, "pcim_iomap_regions" },
	{ 0x7fd94de7, "pcim_iomap_table" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xdaf61130, "pci_disable_pcie_error_reporting" },
	{ 0x2587f789, "_dev_info" },
	{ 0x791a408b, "pci_bus_type" },
	{ 0x60ad8607, "dfl_fpga_feature_devs_remove" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dfl");

MODULE_ALIAS("pci:v00008086d0000BCBDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000BCBFsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000BCC0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000BCC1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000009C4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000009C5sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000B30sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000B2Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00000B2Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001C2Cd00001000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00001C2Cd00001001sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "6ECBC2BC118BCF9E09938A7");
