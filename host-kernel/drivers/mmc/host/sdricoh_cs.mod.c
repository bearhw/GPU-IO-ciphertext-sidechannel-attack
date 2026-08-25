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
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0xefdceb01, "pci_iounmap" },
	{ 0xe964051f, "pci_dev_put" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0x1a6879ec, "pcmcia_disable_device" },
	{ 0x2587f789, "_dev_info" },
	{ 0xf110992b, "pci_get_device" },
	{ 0xae121354, "pci_iomap" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x800473f, "__cond_resched" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x50a9f59c, "pcmcia_register_driver" },
	{ 0xb59602ab, "pcmcia_unregister_driver" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "pcmcia");

MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paD9F522EDpbC3901202pc*pd*");
MODULE_ALIAS("pcmcia:m*c*f*fn*pfn*paD9F522EDpbACE80909pc*pd*");

MODULE_INFO(srcversion, "D3C15B64506CEBCA84EBCA9");
