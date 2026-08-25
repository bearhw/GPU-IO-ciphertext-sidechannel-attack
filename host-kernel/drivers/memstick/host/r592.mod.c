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

SYMBOL_CRC(memstick_debug_get_tpc_name, 0x52f1b23b, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x963afbea, "wake_up_process" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x92997ed8, "_printk" },
	{ 0x13d0adf7, "__kfifo_out" },
	{ 0xf23fcb99, "__kfifo_in" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4fe03630, "sg_miter_start" },
	{ 0x110e06ce, "sg_miter_next" },
	{ 0x6ccf4d5f, "sg_miter_stop" },
	{ 0x63c2cc99, "memstick_detect_change" },
	{ 0xf9a482f9, "msleep" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xa9aba759, "memstick_next_req" },
	{ 0xd0582469, "memstick_remove_host" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xedc03953, "iounmap" },
	{ 0xe99e47b4, "pci_release_regions" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x6240a29e, "memstick_free_host" },
	{ 0x68136d78, "memstick_suspend_host" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x4570d708, "memstick_resume_host" },
	{ 0xa6257a2f, "complete" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x4a3ad70e, "wait_for_completion_timeout" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x86490580, "current_task" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x1000e51, "schedule" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x9c25bc16, "memstick_alloc_host" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x95316761, "dma_set_mask" },
	{ 0xafbe9f1e, "pci_request_regions" },
	{ 0xac37aa30, "pci_ioremap_bar" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x1cb50365, "memstick_add_host" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "memstick");

MODULE_ALIAS("pci:v00001180d00000592sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "BF381A25C6C36BEA02D0891");
