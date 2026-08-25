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
	{ 0x53a603a, "dma_release_channel" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x69acdf38, "memcpy" },
	{ 0x56470118, "__warn_printk" },
	{ 0x93c1b458, "mmc_request_done" },
	{ 0xa78af5f3, "ioread32" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x1a16cf31, "mmc_detect_change" },
	{ 0xa7f54a6c, "platform_get_irq_byname" },
	{ 0x3b5cbc5e, "mmc_alloc_host" },
	{ 0x74f6e487, "mmc_regulator_get_supply" },
	{ 0xc313ebc3, "mmc_free_host" },
	{ 0x7a91a460, "mmc_of_parse" },
	{ 0xf3a92611, "devm_pinctrl_get" },
	{ 0x3bfed546, "pinctrl_lookup_state" },
	{ 0x49df79d3, "platform_get_resource" },
	{ 0x6902f204, "devm_ioremap_resource" },
	{ 0xeb68515c, "devm_clk_get" },
	{ 0x556e4390, "clk_get_rate" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0x815588a6, "clk_enable" },
	{ 0x2587f789, "_dev_info" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0xbf3f670d, "dma_request_chan" },
	{ 0x84b01817, "mmc_add_host" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0x8d9077b9, "dma_unmap_sg_attrs" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x249d1964, "dma_map_sg_attrs" },
	{ 0x596e66f6, "mmc_regulator_set_vqmmc" },
	{ 0x30b136e2, "pinctrl_select_default_state" },
	{ 0xbd44d6b9, "pinctrl_select_state" },
	{ 0x800473f, "__cond_resched" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0x6a86bc1, "iowrite16" },
	{ 0x842c8e9d, "ioread16" },
	{ 0x87b8798d, "sg_next" },
	{ 0x8b317622, "mmc_remove_host" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0xc04a3d34, "mmc_regulator_set_ocr" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Crenesas,usdhi6rol0");
MODULE_ALIAS("of:N*T*Crenesas,usdhi6rol0C*");

MODULE_INFO(srcversion, "6BD7593E177FF2CD651D17C");
