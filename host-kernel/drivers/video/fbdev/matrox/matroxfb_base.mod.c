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

SYMBOL_CRC(matroxfb_register_driver, 0xc27638a0, "");
SYMBOL_CRC(matroxfb_unregister_driver, 0x06690493, "");
SYMBOL_CRC(matroxfb_wait_for_sync, 0xb861f595, "");
SYMBOL_CRC(matroxfb_enable_irq, 0x00a3b2aa, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x92997ed8, "_printk" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x800473f, "__cond_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xcdc90c64, "matroxfb_var2my" },
	{ 0x668b19a1, "down_read" },
	{ 0x53b954a2, "up_read" },
	{ 0x5ddf7dea, "matrox_cfbX_init" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x55385e2e, "__x86_indirect_thunk_r14" },
	{ 0xfce4fa8a, "unregister_framebuffer" },
	{ 0x28343d9a, "matroxfb_g450_shutdown" },
	{ 0x50d68377, "arch_phys_wc_del" },
	{ 0xedc03953, "iounmap" },
	{ 0x77358855, "iomem_resource" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x37a0cba, "kfree" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xa52fb313, "pci_read_config_dword" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x85bd1608, "__request_region" },
	{ 0xde80cd09, "ioremap" },
	{ 0xfd93ee35, "ioremap_wc" },
	{ 0x7483dc59, "pci_dev_present" },
	{ 0x3f64a755, "pci_write_config_dword" },
	{ 0xe6bc56f8, "matroxfb_read_pins" },
	{ 0x5b641283, "arch_phys_wc_add" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x3a367f61, "matroxfb_g450_connect" },
	{ 0x7a890c8, "fb_alloc_cmap" },
	{ 0xe1f63bc3, "register_framebuffer" },
	{ 0xa4bd5528, "fb_set_var" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0x5daa032f, "param_ops_string" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x1de8b80a, "matrox_G100" },
	{ 0x8b269b46, "matrox_mystique" },
	{ 0x92220728, "matrox_millennium" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "matroxfb_misc,matroxfb_accel,matroxfb_g450,matroxfb_DAC1064,matroxfb_Ti3026");

MODULE_ALIAS("pci:v0000102Bd00000519sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd0000051Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd0000051Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd0000051Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00001000sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00001001sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000520sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000532sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000521sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00000525sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000102Bd00002527sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "6338BDF68822C26630FEB0C");
