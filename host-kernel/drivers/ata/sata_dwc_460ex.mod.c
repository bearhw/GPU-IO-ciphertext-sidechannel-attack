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
	{ 0xa586d479, "ata_host_detach" },
	{ 0xe11e23a2, "phy_exit" },
	{ 0xa404912d, "dw_dma_remove" },
	{ 0x76e1eca9, "__dynamic_dev_dbg" },
	{ 0x9085e9a, "_dev_err" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xbb38e0c0, "ata_sff_error_handler" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xaf0fabc0, "__dma_request_channel" },
	{ 0x8fd79e71, "phy_power_on" },
	{ 0x37a0cba, "kfree" },
	{ 0x4f94d4d0, "ata_host_alloc_pinfo" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x9e32c947, "devm_platform_get_and_ioremap_resource" },
	{ 0x25bc979e, "_dev_notice" },
	{ 0xb91e9c6d, "sata_sff_hardreset" },
	{ 0x821a95c0, "ata_qc_complete" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x53a603a, "dma_release_channel" },
	{ 0xc8a6e45b, "phy_power_off" },
	{ 0x800473f, "__cond_resched" },
	{ 0x59f3f569, "ata_sff_exec_command" },
	{ 0x7bfc26b9, "__tracepoint_ata_tf_load" },
	{ 0xde948f87, "__tracepoint_ata_exec_command" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xcf2b93c8, "__SCT__tp_func_ata_tf_load" },
	{ 0x7d813863, "ata_bmdma_qc_issue" },
	{ 0x46047827, "__SCT__tp_func_ata_exec_command" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xcefed80c, "__platform_driver_register" },
	{ 0x91ad6f94, "platform_driver_unregister" },
	{ 0x734f0af5, "ata_sff_port_ops" },
	{ 0xb944aee5, "__SCK__tp_func_ata_bmdma_start" },
	{ 0xbdf4af97, "__SCK__tp_func_ata_exec_command" },
	{ 0x65e156bc, "__SCK__tp_func_ata_tf_load" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "dw_dmac_core");

MODULE_ALIAS("of:N*T*Camcc,sata-460ex");
MODULE_ALIAS("of:N*T*Camcc,sata-460exC*");

MODULE_INFO(srcversion, "6CD9371A2E2BE783C0497A0");
