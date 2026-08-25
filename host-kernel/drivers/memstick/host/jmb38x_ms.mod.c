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
	{ 0x68136d78, "memstick_suspend_host" },
	{ 0x71a18456, "device_wakeup_disable" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xf9a482f9, "msleep" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0xe662e495, "pci_read_config_byte" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x95316761, "dma_set_mask" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x1cb50365, "memstick_add_host" },
	{ 0x9c25bc16, "memstick_alloc_host" },
	{ 0xde80cd09, "ioremap" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x2364c85a, "tasklet_init" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xedc03953, "iounmap" },
	{ 0x6240a29e, "memstick_free_host" },
	{ 0x37a0cba, "kfree" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x4570d708, "memstick_resume_host" },
	{ 0x63c2cc99, "memstick_detect_change" },
	{ 0x86490580, "current_task" },
	{ 0x6d606913, "pv_ops" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0xa9aba759, "memstick_next_req" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0xd0582469, "memstick_remove_host" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "memstick");

MODULE_ALIAS("pci:v0000197Bd00002383sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000197Bd00002388sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000197Bd00002393sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "E540EF6AAEB726C01F955CA");
