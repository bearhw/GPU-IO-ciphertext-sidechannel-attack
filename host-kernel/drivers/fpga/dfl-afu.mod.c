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
	{ 0xd7f43eda, "pin_user_pages_fast" },
	{ 0x61960744, "dfl_fpga_port_ops_del" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0xca9360b5, "rb_next" },
	{ 0xbe6a8e52, "dma_unmap_page_attrs" },
	{ 0x96848186, "scnprintf" },
	{ 0xc8814bbc, "unpin_user_pages" },
	{ 0xd6727dc4, "remap_pfn_range" },
	{ 0x37a0cba, "kfree" },
	{ 0x38255d3f, "dfl_fpga_dev_ops_unregister" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xaccec322, "dma_map_page_attrs" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x9a788c05, "dfl_fpga_dev_feature_init" },
	{ 0x800473f, "__cond_resched" },
	{ 0x39d141a4, "devm_kfree" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0xe0e3dc52, "dfl_feature_ioctl_set_irq" },
	{ 0x86490580, "current_task" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x9e91c830, "account_locked_vm" },
	{ 0x5c3c7387, "kstrtoull" },
	{ 0xb3c12465, "dfl_feature_ioctl_get_num_irqs" },
	{ 0x13c3edaa, "generic_access_phys" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xece784c2, "rb_first" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x58f7df48, "dfl_fpga_port_ops_add" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x264dafe, "dfl_fpga_dev_feature_uinit" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x7ded4891, "dfl_fpga_dev_ops_register" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x46cf10eb, "cachemode2protval" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xa84f915, "dfl_fpga_set_irq_triggers" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dfl");


MODULE_INFO(srcversion, "3FFD6209A207160F42C8349");
