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
	{ 0x92997ed8, "_printk" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xff2d0d54, "dma_free_attrs" },
	{ 0x71c35994, "dma_alloc_attrs" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x55d97ddb, "pci_disable_device" },
	{ 0x999e8297, "vfree" },
	{ 0xedc03953, "iounmap" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0xfb578fc5, "memset" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x78f5dd88, "__dev_kfree_skb_any" },
	{ 0x44c6e633, "vcc_sklist_lock" },
	{ 0xb1342cdb, "_raw_read_lock_irqsave" },
	{ 0xf49cdd0f, "skb_queue_tail" },
	{ 0xdf2ebb87, "_raw_read_unlock_irqrestore" },
	{ 0xc89d03e1, "skb_dequeue" },
	{ 0x42ddc4c1, "skb_queue_head" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xf0dba0fe, "atm_alloc_charge" },
	{ 0xbe888b32, "skb_put" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xfef216eb, "_raw_spin_trylock" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xf9a482f9, "msleep" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xf49bc67a, "atm_pcr_goal" },
	{ 0x4427650a, "pci_read_config_word" },
	{ 0x68a6d7a5, "pci_write_config_word" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x99d368a7, "atm_dev_register" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xdc47a75f, "pci_enable_device" },
	{ 0x1b1cdbe1, "atm_dev_deregister" },
	{ 0xbea0b7c1, "pci_set_master" },
	{ 0x95316761, "dma_set_mask" },
	{ 0x6624ff97, "dma_set_coherent_mask" },
	{ 0xe662b4ba, "pci_write_config_byte" },
	{ 0xde80cd09, "ioremap" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x24d273d1, "add_timer" },
	{ 0x302eae70, "__pci_register_driver" },
	{ 0xc85c376e, "pci_unregister_driver" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "atm");

MODULE_ALIAS("pci:v0000111Ad00000003sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v0000111Ad00000005sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "278D1894639AFF71892BA69");
