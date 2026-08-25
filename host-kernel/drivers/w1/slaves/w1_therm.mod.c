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
	{ 0x3b6c41ea, "kstrtouint" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x2587f789, "_dev_info" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x8c8569cb, "kstrtoint" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x58c0c366, "w1_reset_bus" },
	{ 0xfccee5f1, "w1_write_8" },
	{ 0xf9a482f9, "msleep" },
	{ 0x94ea671e, "w1_read_8" },
	{ 0xd9d87f1c, "w1_read_block" },
	{ 0xe5cf19c, "w1_write_block" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x656e4a6e, "snprintf" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x37a0cba, "kfree" },
	{ 0x2392f7da, "device_remove_file" },
	{ 0x5a921311, "strncmp" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x89940875, "mutex_lock_interruptible" },
	{ 0xc5aa4706, "w1_next_pullup" },
	{ 0x6ca43304, "w1_touch_bit" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0x2121e851, "device_create_file" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x63757e92, "w1_calc_crc8" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xe914e41e, "strcpy" },
	{ 0x85df9b6c, "strsep" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x37befc70, "jiffies_to_msecs" },
	{ 0x92997ed8, "_printk" },
	{ 0x31aa6211, "w1_register_family" },
	{ 0x56f5a4a1, "w1_unregister_family" },
	{ 0x437654c9, "param_ops_int" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "wire");


MODULE_INFO(srcversion, "C5ECC50745F0F96C426CEDF");
