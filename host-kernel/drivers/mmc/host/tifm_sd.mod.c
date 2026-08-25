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
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0xf9a482f9, "msleep" },
	{ 0x92997ed8, "_printk" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0xa07d1b3c, "tasklet_setup" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0xa46ed636, "tifm_eject" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0xa666c41a, "tifm_unmap_sg" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0x9d2ab8ac, "__tasklet_schedule" },
	{ 0xea3c74e, "tasklet_kill" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x6d606913, "pv_ops" },
	{ 0x86490580, "current_task" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xb320cc0e, "sg_init_one" },
	{ 0x1d2a58aa, "tifm_map_sg" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x25094524, "tifm_register_driver" },
	{ 0x20f8366c, "tifm_unregister_driver" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "tifm_core");


MODULE_INFO(srcversion, "FC2F26A73F43D0E9F04988E");
