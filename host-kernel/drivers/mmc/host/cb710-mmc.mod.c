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
	{ 0xa78af5f3, "ioread32" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x6d606913, "pv_ops" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x848d372e, "iowrite8" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0xb19b445, "ioread8" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0x416c185e, "cb710_set_irq_handler" },
	{ 0x4a453f53, "iowrite32" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xa07d1b3c, "tasklet_setup" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0x2a696ea8, "cb710_sg_dwiter_write_next_block" },
	{ 0x18d45d08, "cb710_pci_update_config_reg" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0xd7e87ce5, "cb710_sg_dwiter_read_next_block" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "cb710");


MODULE_INFO(srcversion, "4A1C3BBC1BCFD2352BD733A");
