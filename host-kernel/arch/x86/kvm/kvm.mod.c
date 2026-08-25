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

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

SYMBOL_CRC(halt_poll_ns, 0x59e640c0, "_gpl");
SYMBOL_CRC(halt_poll_ns_grow, 0x7afe324e, "_gpl");
SYMBOL_CRC(halt_poll_ns_grow_start, 0x5fb8848b, "_gpl");
SYMBOL_CRC(halt_poll_ns_shrink, 0x39fd83db, "_gpl");
SYMBOL_CRC(kvm_debugfs_dir, 0x880febc3, "_gpl");
SYMBOL_CRC(kvm_rebooting, 0x485cd7f6, "_gpl");
SYMBOL_CRC(main_vm, 0x5957d66b, "");
SYMBOL_CRC(vcpu_load, 0xdd86ff72, "_gpl");
SYMBOL_CRC(vcpu_put, 0x2825f280, "_gpl");
SYMBOL_CRC(kvm_make_all_cpus_request, 0xe14d8c3a, "_gpl");
SYMBOL_CRC(kvm_flush_remote_tlbs, 0xba9f60fb, "_gpl");
SYMBOL_CRC(kvm_destroy_vcpus, 0x316defa8, "_gpl");
SYMBOL_CRC(kvm_get_kvm, 0x338cc852, "_gpl");
SYMBOL_CRC(kvm_get_kvm_safe, 0xd51ce8c3, "_gpl");
SYMBOL_CRC(kvm_put_kvm, 0x7400f381, "_gpl");
SYMBOL_CRC(kvm_put_kvm_no_destroy, 0xd81d498e, "_gpl");
SYMBOL_CRC(__kvm_set_memory_region, 0xd062f881, "_gpl");
SYMBOL_CRC(kvm_set_memory_region, 0x267d3a32, "_gpl");
SYMBOL_CRC(gfn_to_memslot, 0x084f04eb, "_gpl");
SYMBOL_CRC(kvm_is_visible_gfn, 0x9180ca20, "_gpl");
SYMBOL_CRC(kvm_vcpu_is_visible_gfn, 0x712c4f0e, "_gpl");
SYMBOL_CRC(gfn_to_hva_memslot, 0xf950e4c6, "_gpl");
SYMBOL_CRC(gfn_to_hva, 0xdae9454d, "_gpl");
SYMBOL_CRC(kvm_vcpu_gfn_to_hva, 0x4fea78cd, "_gpl");
SYMBOL_CRC(__gfn_to_pfn_memslot, 0x7099a471, "_gpl");
SYMBOL_CRC(gfn_to_pfn_prot, 0x5caf3a53, "_gpl");
SYMBOL_CRC(gfn_to_pfn_memslot, 0x2d3616db, "_gpl");
SYMBOL_CRC(gfn_to_pfn_memslot_atomic, 0xa07a481c, "_gpl");
SYMBOL_CRC(kvm_vcpu_gfn_to_pfn_atomic, 0x3ae64a42, "_gpl");
SYMBOL_CRC(gfn_to_pfn, 0x1e2b946b, "_gpl");
SYMBOL_CRC(kvm_vcpu_gfn_to_pfn, 0xd1191b76, "_gpl");
SYMBOL_CRC(gfn_to_page_many_atomic, 0xe3f9758c, "_gpl");
SYMBOL_CRC(gfn_to_page, 0xaccb382c, "_gpl");
SYMBOL_CRC(kvm_vcpu_map, 0xd82f0c5e, "_gpl");
SYMBOL_CRC(kvm_vcpu_unmap, 0xdf46c21a, "_gpl");
SYMBOL_CRC(kvm_vcpu_gfn_to_page, 0xc4d0d9d8, "_gpl");
SYMBOL_CRC(kvm_release_page_clean, 0xead0fecf, "_gpl");
SYMBOL_CRC(kvm_release_pfn_clean, 0x4e3fd1b4, "_gpl");
SYMBOL_CRC(kvm_release_page_dirty, 0xbaf3ff45, "_gpl");
SYMBOL_CRC(kvm_release_pfn_dirty, 0x7c94c99a, "_gpl");
SYMBOL_CRC(kvm_set_pfn_dirty, 0xa1c4231f, "_gpl");
SYMBOL_CRC(kvm_set_pfn_accessed, 0x6892e3c3, "_gpl");
SYMBOL_CRC(kvm_read_guest_page, 0x528cb2a2, "_gpl");
SYMBOL_CRC(kvm_vcpu_read_guest_page, 0xd8b63610, "_gpl");
SYMBOL_CRC(kvm_read_guest, 0x0952690f, "_gpl");
SYMBOL_CRC(kvm_vcpu_read_guest, 0xf6517802, "_gpl");
SYMBOL_CRC(kvm_vcpu_read_guest_atomic, 0xfab68691, "_gpl");
SYMBOL_CRC(kvm_write_guest_page, 0xd97bf385, "_gpl");
SYMBOL_CRC(kvm_vcpu_write_guest_page, 0xcae7c6f2, "_gpl");
SYMBOL_CRC(kvm_write_guest, 0xdc081791, "_gpl");
SYMBOL_CRC(kvm_vcpu_write_guest, 0x813a6af9, "_gpl");
SYMBOL_CRC(kvm_gfn_to_hva_cache_init, 0x9dd051be, "_gpl");
SYMBOL_CRC(kvm_write_guest_offset_cached, 0x56318ae7, "_gpl");
SYMBOL_CRC(kvm_write_guest_cached, 0x83121d4f, "_gpl");
SYMBOL_CRC(kvm_read_guest_offset_cached, 0x56e5ced2, "_gpl");
SYMBOL_CRC(kvm_read_guest_cached, 0x9112295f, "_gpl");
SYMBOL_CRC(kvm_clear_guest, 0x26294e6a, "_gpl");
SYMBOL_CRC(mark_page_dirty_in_slot, 0xe48aa001, "_gpl");
SYMBOL_CRC(mark_page_dirty, 0x2937ccef, "_gpl");
SYMBOL_CRC(kvm_vcpu_mark_page_dirty, 0x4e254253, "_gpl");
SYMBOL_CRC(kvm_vcpu_halt, 0x7937840f, "_gpl");
SYMBOL_CRC(kvm_vcpu_wake_up, 0x318df014, "_gpl");
SYMBOL_CRC(kvm_vcpu_kick, 0xd788c8be, "_gpl");
SYMBOL_CRC(kvm_vcpu_yield_to, 0x68bbf817, "_gpl");
SYMBOL_CRC(kvm_vcpu_on_spin, 0x744e7623, "_gpl");
SYMBOL_CRC(file_is_kvm, 0x0136b1c0, "_gpl");
SYMBOL_CRC(kvm_io_bus_write, 0x0d7f9a54, "_gpl");
SYMBOL_CRC(kvm_io_bus_get_dev, 0x29ddb74e, "_gpl");
SYMBOL_CRC(kvm_get_running_vcpu, 0x4e561fe2, "_gpl");
SYMBOL_CRC(kvm_init, 0x488e0030, "_gpl");
SYMBOL_CRC(kvm_exit, 0x27046576, "_gpl");
SYMBOL_CRC(kvm_irq_has_notifier, 0xeddf9b55, "_gpl");
SYMBOL_CRC(kvm_gfn_to_pfn_cache_check, 0xe129f505, "_gpl");
SYMBOL_CRC(kvm_gfn_to_pfn_cache_refresh, 0x9eebc921, "_gpl");
SYMBOL_CRC(kvm_gfn_to_pfn_cache_unmap, 0xe15a231b, "_gpl");
SYMBOL_CRC(kvm_gfn_to_pfn_cache_init, 0x42fad4bc, "_gpl");
SYMBOL_CRC(kvm_gfn_to_pfn_cache_destroy, 0x25ab4cf6, "_gpl");
SYMBOL_CRC(kvm_mce_cap_supported, 0x0d8f4740, "_gpl");
SYMBOL_CRC(__SCK__kvm_x86_get_cs_db_l_bits, 0x28f33fbf, "_gpl");
SYMBOL_CRC(__SCT__kvm_x86_get_cs_db_l_bits, 0x53d9f927, "_gpl");
SYMBOL_CRC(__SCK__kvm_x86_cache_reg, 0x6ce99915, "_gpl");
SYMBOL_CRC(__SCT__kvm_x86_cache_reg, 0x59387ba3, "_gpl");
SYMBOL_CRC(report_ignored_msrs, 0xc96d35f4, "_gpl");
SYMBOL_CRC(kvm_has_tsc_control, 0xd0459e67, "_gpl");
SYMBOL_CRC(kvm_max_guest_tsc_khz, 0x1cf65ffc, "_gpl");
SYMBOL_CRC(kvm_tsc_scaling_ratio_frac_bits, 0x1235000a, "_gpl");
SYMBOL_CRC(kvm_max_tsc_scaling_ratio, 0x28411ed7, "_gpl");
SYMBOL_CRC(kvm_default_tsc_scaling_ratio, 0x63270977, "_gpl");
SYMBOL_CRC(kvm_has_bus_lock_exit, 0x944882ed, "_gpl");
SYMBOL_CRC(enable_vmware_backdoor, 0x1db1c372, "_gpl");
SYMBOL_CRC(enable_pmu, 0xb82c0987, "_gpl");
SYMBOL_CRC(kvm_nr_uret_msrs, 0x0b58a11d, "_gpl");
SYMBOL_CRC(host_efer, 0x159b8d5e, "_gpl");
SYMBOL_CRC(allow_smaller_maxphyaddr, 0x9cf59e7a, "_gpl");
SYMBOL_CRC(enable_apicv, 0xce576a13, "_gpl");
SYMBOL_CRC(host_xss, 0x6c95726c, "_gpl");
SYMBOL_CRC(supported_xss, 0x130fd155, "_gpl");
SYMBOL_CRC(supported_xcr0, 0xe9674a16, "_gpl");
SYMBOL_CRC(kvm_add_user_return_msr, 0x7fe19488, "_gpl");
SYMBOL_CRC(kvm_find_user_return_msr, 0x3ab2794c, "_gpl");
SYMBOL_CRC(kvm_set_user_return_msr, 0x053614ec, "_gpl");
SYMBOL_CRC(kvm_get_apic_base, 0xb1efe8bd, "_gpl");
SYMBOL_CRC(kvm_get_apic_mode, 0x6d273134, "_gpl");
SYMBOL_CRC(kvm_set_apic_base, 0xa2992e61, "_gpl");
SYMBOL_CRC(kvm_spurious_fault, 0x709cd8cb, "_gpl");
SYMBOL_CRC(kvm_deliver_exception_payload, 0x58f995db, "_gpl");
SYMBOL_CRC(kvm_queue_exception, 0xffdf47fa, "_gpl");
SYMBOL_CRC(kvm_requeue_exception, 0xa4b3e8a2, "_gpl");
SYMBOL_CRC(kvm_queue_exception_p, 0x6438ed81, "_gpl");
SYMBOL_CRC(kvm_complete_insn_gp, 0xed89a04d, "_gpl");
SYMBOL_CRC(kvm_inject_page_fault, 0x5b14a04f, "_gpl");
SYMBOL_CRC(kvm_inject_emulated_page_fault, 0xcf931d71, "_gpl");
SYMBOL_CRC(kvm_inject_nmi, 0x91255f56, "_gpl");
SYMBOL_CRC(kvm_queue_exception_e, 0xe2a2d163, "_gpl");
SYMBOL_CRC(kvm_requeue_exception_e, 0xe577ab6c, "_gpl");
SYMBOL_CRC(kvm_require_cpl, 0xfdf2fe9c, "_gpl");
SYMBOL_CRC(kvm_require_dr, 0xa3698dd0, "_gpl");
SYMBOL_CRC(load_pdptrs, 0xc7d571bc, "_gpl");
SYMBOL_CRC(kvm_post_set_cr0, 0xd9067b31, "_gpl");
SYMBOL_CRC(kvm_set_cr0, 0x0f0af269, "_gpl");
SYMBOL_CRC(kvm_lmsw, 0xf0454aca, "_gpl");
SYMBOL_CRC(kvm_load_guest_xsave_state, 0x842bab7a, "_gpl");
SYMBOL_CRC(kvm_load_host_xsave_state, 0xcbc56e5a, "_gpl");
SYMBOL_CRC(kvm_emulate_xsetbv, 0x3c8e5a27, "_gpl");
SYMBOL_CRC(kvm_is_valid_cr4, 0x5e8aac24, "_gpl");
SYMBOL_CRC(kvm_post_set_cr4, 0x0bba5bf4, "_gpl");
SYMBOL_CRC(kvm_set_cr4, 0x9e4a7e16, "_gpl");
SYMBOL_CRC(kvm_set_cr3, 0x1526d6d9, "_gpl");
SYMBOL_CRC(kvm_set_cr8, 0xf6faecd6, "_gpl");
SYMBOL_CRC(kvm_get_cr8, 0x471a92c6, "_gpl");
SYMBOL_CRC(kvm_update_dr7, 0xcbe33926, "_gpl");
SYMBOL_CRC(kvm_set_dr, 0x4cb9abc9, "_gpl");
SYMBOL_CRC(kvm_get_dr, 0x51401eef, "_gpl");
SYMBOL_CRC(kvm_emulate_rdpmc, 0x068dd392, "_gpl");
SYMBOL_CRC(kvm_valid_efer, 0x6b9fe8cf, "_gpl");
SYMBOL_CRC(kvm_enable_efer_bits, 0x1d013832, "_gpl");
SYMBOL_CRC(kvm_msr_allowed, 0x57923399, "_gpl");
SYMBOL_CRC(kvm_get_msr, 0xf8399f52, "_gpl");
SYMBOL_CRC(kvm_set_msr, 0x042701c1, "_gpl");
SYMBOL_CRC(kvm_emulate_rdmsr, 0xed508c11, "_gpl");
SYMBOL_CRC(kvm_emulate_wrmsr, 0x1ed5a0e3, "_gpl");
SYMBOL_CRC(kvm_emulate_as_nop, 0x65868912, "_gpl");
SYMBOL_CRC(kvm_emulate_invd, 0xf35aa6e7, "_gpl");
SYMBOL_CRC(kvm_emulate_mwait, 0x819243cb, "_gpl");
SYMBOL_CRC(kvm_handle_invalid_op, 0x250fc332, "_gpl");
SYMBOL_CRC(kvm_emulate_monitor, 0x2a6a7603, "_gpl");
SYMBOL_CRC(handle_fastpath_set_msr_irqoff, 0x80215a92, "_gpl");
SYMBOL_CRC(kvm_scale_tsc, 0xe1d25080, "_gpl");
SYMBOL_CRC(kvm_read_l1_tsc, 0x71d8a59f, "_gpl");
SYMBOL_CRC(kvm_calc_nested_tsc_offset, 0x6303c089, "_gpl");
SYMBOL_CRC(kvm_calc_nested_tsc_multiplier, 0xef14fd98, "_gpl");
SYMBOL_CRC(kvm_service_local_tlb_flush_requests, 0x57df5b3f, "_gpl");
SYMBOL_CRC(kvm_set_msr_common, 0xed0df891, "_gpl");
SYMBOL_CRC(kvm_get_msr_common, 0xc94bfd3a, "_gpl");
SYMBOL_CRC(kvm_mmu_gva_to_gpa_read, 0xb6ab52ed, "_gpl");
SYMBOL_CRC(kvm_mmu_gva_to_gpa_write, 0x979ddadf, "_gpl");
SYMBOL_CRC(kvm_read_guest_virt, 0xf4c7f91a, "_gpl");
SYMBOL_CRC(kvm_write_guest_virt_system, 0xcffaa928, "_gpl");
SYMBOL_CRC(handle_ud, 0xf94b4561, "_gpl");
SYMBOL_CRC(kvm_emulate_wbinvd, 0xf32825cb, "_gpl");
SYMBOL_CRC(kvm_inject_realmode_interrupt, 0xc878f03d, "_gpl");
SYMBOL_CRC(__kvm_prepare_emulation_failure_exit, 0xe6037282, "_gpl");
SYMBOL_CRC(kvm_prepare_emulation_failure_exit, 0x070d3be3, "_gpl");
SYMBOL_CRC(kvm_skip_emulated_instruction, 0xff44c9e4, "_gpl");
SYMBOL_CRC(x86_decode_emulated_instruction, 0x40efaba7, "_gpl");
SYMBOL_CRC(kvm_emulate_instruction, 0x8fa4f0e4, "_gpl");
SYMBOL_CRC(kvm_emulate_instruction_from_buffer, 0x59709e97, "_gpl");
SYMBOL_CRC(kvm_fast_pio, 0x90e803da, "_gpl");
SYMBOL_CRC(kvm_emulate_halt_noskip, 0xb1ea32b6, "_gpl");
SYMBOL_CRC(kvm_emulate_halt, 0x7d8f203f, "_gpl");
SYMBOL_CRC(kvm_emulate_ap_reset_hold, 0x5af136e0, "_gpl");
SYMBOL_CRC(kvm_apicv_activated, 0xc2ed93cc, "_gpl");
SYMBOL_CRC(kvm_vcpu_apicv_activated, 0x833a9f6f, "_gpl");
SYMBOL_CRC(kvm_emulate_hypercall, 0xc82be642, "_gpl");
SYMBOL_CRC(kvm_vcpu_update_apicv, 0xc0101a86, "_gpl");
SYMBOL_CRC(kvm_set_or_clear_apicv_inhibit, 0xfc20177c, "_gpl");
SYMBOL_CRC(__kvm_request_immediate_exit, 0xd09f36f6, "_gpl");
SYMBOL_CRC(kvm_task_switch, 0x383185bc, "_gpl");
SYMBOL_CRC(kvm_vcpu_reset, 0x93c137ec, "_gpl");
SYMBOL_CRC(kvm_vcpu_deliver_sipi_vector, 0xa3f2e35c, "_gpl");
SYMBOL_CRC(kvm_vcpu_is_reset_bsp, 0x3f00e8ef, "_gpl");
SYMBOL_CRC(kvm_has_noapic_vcpu, 0x3f510ff5, "_gpl");
SYMBOL_CRC(__x86_set_memory_region, 0xa6b18e31, "_gpl");
SYMBOL_CRC(kvm_get_linear_rip, 0x3d5945bd, "_gpl");
SYMBOL_CRC(kvm_is_linear_rip, 0xdd556420, "_gpl");
SYMBOL_CRC(kvm_get_rflags, 0x02965b23, "_gpl");
SYMBOL_CRC(kvm_set_rflags, 0xdf2e7a57, "_gpl");
SYMBOL_CRC(kvm_arch_start_assignment, 0x46c9903e, "_gpl");
SYMBOL_CRC(kvm_arch_end_assignment, 0x58aac291, "_gpl");
SYMBOL_CRC(kvm_arch_has_assigned_device, 0x4fcf1870, "_gpl");
SYMBOL_CRC(kvm_arch_register_noncoherent_dma, 0xf497bac8, "_gpl");
SYMBOL_CRC(kvm_arch_unregister_noncoherent_dma, 0x46ccabae, "_gpl");
SYMBOL_CRC(kvm_arch_has_noncoherent_dma, 0xf26f4a8d, "_gpl");
SYMBOL_CRC(kvm_arch_no_poll, 0x144c9a1e, "_gpl");
SYMBOL_CRC(kvm_spec_ctrl_test_value, 0x2d82cc24, "_gpl");
SYMBOL_CRC(kvm_fixup_and_inject_pf_error, 0x2bc622d5, "_gpl");
SYMBOL_CRC(kvm_handle_memory_failure, 0x640c75fd, "_gpl");
SYMBOL_CRC(kvm_handle_invpcid, 0x425ad9d1, "_gpl");
SYMBOL_CRC(kvm_sev_es_mmio_write, 0x49b3ea22, "_gpl");
SYMBOL_CRC(kvm_sev_es_mmio_read, 0x407bb154, "_gpl");
SYMBOL_CRC(kvm_sev_es_string_io, 0x8003705e, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_entry, 0x23a35351, "_gpl");
SYMBOL_CRC(__traceiter_kvm_entry, 0x193c0acd, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_entry, 0xb21b17da, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_entry, 0xc071e99f, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_exit, 0x503fe847, "_gpl");
SYMBOL_CRC(__traceiter_kvm_exit, 0xc171199e, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_exit, 0x8c17f409, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_exit, 0x616e6c95, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_fast_mmio, 0x600e0399, "_gpl");
SYMBOL_CRC(__traceiter_kvm_fast_mmio, 0x752c2b00, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_fast_mmio, 0x86d190dd, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_fast_mmio, 0xea5cda33, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_inj_virq, 0x18e2373b, "_gpl");
SYMBOL_CRC(__traceiter_kvm_inj_virq, 0xa80595a6, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_inj_virq, 0xa42d7274, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_inj_virq, 0x6becaded, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_page_fault, 0x0ec8150a, "_gpl");
SYMBOL_CRC(__traceiter_kvm_page_fault, 0xff02e467, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_page_fault, 0x7f9f4f10, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_page_fault, 0x7ff2a104, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_msr, 0x3922920f, "_gpl");
SYMBOL_CRC(__traceiter_kvm_msr, 0xdc7369fe, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_msr, 0xc7331321, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_msr, 0xf084b57d, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_cr, 0xb8ab9176, "_gpl");
SYMBOL_CRC(__traceiter_kvm_cr, 0x17f9cfe3, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_cr, 0x7d31c9ee, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_cr, 0x778e30b9, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_nested_vmrun, 0x78d1c19a, "_gpl");
SYMBOL_CRC(__traceiter_kvm_nested_vmrun, 0x7263ae77, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_nested_vmrun, 0x4342f2fc, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_nested_vmrun, 0x70288943, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_nested_vmexit, 0x02fc7944, "_gpl");
SYMBOL_CRC(__traceiter_kvm_nested_vmexit, 0x0a5f0f55, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_nested_vmexit, 0xa6162e1a, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_nested_vmexit, 0x2510fc6d, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_nested_vmexit_inject, 0x9abec274, "_gpl");
SYMBOL_CRC(__traceiter_kvm_nested_vmexit_inject, 0x114eb824, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_nested_vmexit_inject, 0x58b239fd, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_nested_vmexit_inject, 0x8b618aa6, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_nested_intr_vmexit, 0xe63b34ca, "_gpl");
SYMBOL_CRC(__traceiter_kvm_nested_intr_vmexit, 0x912a9286, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_nested_intr_vmexit, 0x59dc5ee0, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_nested_intr_vmexit, 0xd09da48b, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_nested_vmenter_failed, 0x8de3d01f, "_gpl");
SYMBOL_CRC(__traceiter_kvm_nested_vmenter_failed, 0x23263c0a, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_nested_vmenter_failed, 0x1945e760, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_nested_vmenter_failed, 0xe93dfc8c, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_invlpga, 0x9af96e41, "_gpl");
SYMBOL_CRC(__traceiter_kvm_invlpga, 0x0b8a3365, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_invlpga, 0x333f3bf0, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_invlpga, 0x4a1c261b, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_skinit, 0xe1aeb507, "_gpl");
SYMBOL_CRC(__traceiter_kvm_skinit, 0xb96e9aa1, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_skinit, 0x9b5557eb, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_skinit, 0xe0e786a7, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_nested_intercepts, 0x5e8b3231, "_gpl");
SYMBOL_CRC(__traceiter_kvm_nested_intercepts, 0xa6a50230, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_nested_intercepts, 0x69800e02, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_nested_intercepts, 0xa588ef67, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_write_tsc_offset, 0xd8069da6, "_gpl");
SYMBOL_CRC(__traceiter_kvm_write_tsc_offset, 0x5c11e105, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_write_tsc_offset, 0x0b015e4d, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_write_tsc_offset, 0xa84a2e73, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_ple_window_update, 0x242662dc, "_gpl");
SYMBOL_CRC(__traceiter_kvm_ple_window_update, 0x1412f042, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_ple_window_update, 0x132d5eef, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_ple_window_update, 0x93a3e40e, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_pml_full, 0x66256c0b, "_gpl");
SYMBOL_CRC(__traceiter_kvm_pml_full, 0xc60d7d0c, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_pml_full, 0xdaea2944, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_pml_full, 0xf2df48f3, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_pi_irte_update, 0xb78d7582, "_gpl");
SYMBOL_CRC(__traceiter_kvm_pi_irte_update, 0x45e80fdf, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_pi_irte_update, 0x3bfae326, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_pi_irte_update, 0x388e0e10, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_avic_unaccelerated_access, 0x0168c967, "_gpl");
SYMBOL_CRC(__traceiter_kvm_avic_unaccelerated_access, 0x9f68faa3, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_avic_unaccelerated_access, 0x1c2fc68a, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_avic_unaccelerated_access, 0xf32dff97, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_avic_incomplete_ipi, 0xa800fa81, "_gpl");
SYMBOL_CRC(__traceiter_kvm_avic_incomplete_ipi, 0x9e20b2bc, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_avic_incomplete_ipi, 0x7304d43d, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_avic_incomplete_ipi, 0x4942be67, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_avic_ga_log, 0xf6597eee, "_gpl");
SYMBOL_CRC(__traceiter_kvm_avic_ga_log, 0xa7022320, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_avic_ga_log, 0x0b4ad0ce, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_avic_ga_log, 0x1d1b139a, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_avic_kick_vcpu_slowpath, 0x3e77e4cb, "_gpl");
SYMBOL_CRC(__traceiter_kvm_avic_kick_vcpu_slowpath, 0x4733bf8c, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_avic_kick_vcpu_slowpath, 0x2e6db05b, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_avic_kick_vcpu_slowpath, 0x5f911332, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_apicv_accept_irq, 0x21700fd7, "_gpl");
SYMBOL_CRC(__traceiter_kvm_apicv_accept_irq, 0x3d93fb92, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_apicv_accept_irq, 0xf277cc3c, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_apicv_accept_irq, 0x5c7e9f84, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_vmgexit_enter, 0x3e41f89d, "_gpl");
SYMBOL_CRC(__traceiter_kvm_vmgexit_enter, 0x369ae04c, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_vmgexit_enter, 0x9aabafc3, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_vmgexit_enter, 0x8a7fe54a, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_vmgexit_exit, 0x97d51d49, "_gpl");
SYMBOL_CRC(__traceiter_kvm_vmgexit_exit, 0x449f4dd0, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_vmgexit_exit, 0xac462e2f, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_vmgexit_exit, 0x48644036, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_vmgexit_msr_protocol_enter, 0xb3b069a4, "_gpl");
SYMBOL_CRC(__traceiter_kvm_vmgexit_msr_protocol_enter, 0x0ca8df68, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_vmgexit_msr_protocol_enter, 0x6d16b06e, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_vmgexit_msr_protocol_enter, 0xf54e2886, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_vmgexit_msr_protocol_exit, 0x6e49d156, "_gpl");
SYMBOL_CRC(__traceiter_kvm_vmgexit_msr_protocol_exit, 0x25c07225, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_vmgexit_msr_protocol_exit, 0x730edebb, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_vmgexit_msr_protocol_exit, 0x0cff45f4, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_snp_psc, 0x6e430bc7, "_gpl");
SYMBOL_CRC(__traceiter_kvm_snp_psc, 0x7b989e95, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_snp_psc, 0xc7855e76, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_snp_psc, 0x643a9c8c, "_gpl");
SYMBOL_CRC(__tracepoint_kvm_sev_es_unmap_ghcb, 0x07a084e0, "_gpl");
SYMBOL_CRC(__traceiter_kvm_sev_es_unmap_ghcb, 0xf7efaf7b, "_gpl");
SYMBOL_CRC(__SCK__tp_func_kvm_sev_es_unmap_ghcb, 0x30abb8d3, "_gpl");
SYMBOL_CRC(__SCT__tp_func_kvm_sev_es_unmap_ghcb, 0x4ffd0d46, "_gpl");
SYMBOL_CRC(kvm_cpu_has_pending_timer, 0x53113723, "");
SYMBOL_CRC(kvm_cpu_has_injectable_intr, 0xa88583af, "_gpl");
SYMBOL_CRC(kvm_cpu_has_interrupt, 0xa86ace31, "_gpl");
SYMBOL_CRC(kvm_cpu_get_interrupt, 0x3b303f55, "_gpl");
SYMBOL_CRC(kvm_inject_pending_timer_irqs, 0xdf927327, "_gpl");
SYMBOL_CRC(kvm_can_use_hv_timer, 0xf93108ed, "_gpl");
SYMBOL_CRC(__kvm_apic_update_irr, 0x6243ac82, "_gpl");
SYMBOL_CRC(kvm_apic_update_irr, 0x35f6e8d5, "_gpl");
SYMBOL_CRC(kvm_apic_clear_irr, 0x6c2fa484, "_gpl");
SYMBOL_CRC(kvm_lapic_find_highest_irr, 0xcefb8b72, "_gpl");
SYMBOL_CRC(kvm_apic_update_ppr, 0x3cf0f744, "_gpl");
SYMBOL_CRC(kvm_apic_match_dest, 0xf86cfab1, "_gpl");
SYMBOL_CRC(kvm_apic_set_eoi_accelerated, 0x8874dd37, "_gpl");
SYMBOL_CRC(kvm_apic_send_ipi, 0xe7f5d03a, "_gpl");
SYMBOL_CRC(kvm_wait_lapic_expire, 0xb192063d, "_gpl");
SYMBOL_CRC(kvm_lapic_hv_timer_in_use, 0x59bf7a0f, "_gpl");
SYMBOL_CRC(kvm_lapic_expired_hv_timer, 0xb4ac7d99, "_gpl");
SYMBOL_CRC(kvm_lapic_set_eoi, 0x29993fdb, "_gpl");
SYMBOL_CRC(kvm_apic_write_nodecode, 0x43e120ff, "_gpl");
SYMBOL_CRC(kvm_apic_update_apicv, 0x71cd0b92, "_gpl");
SYMBOL_CRC(kvm_apic_has_interrupt, 0xb78071c5, "_gpl");
SYMBOL_CRC(kvm_set_msi_irq, 0x8b6faac2, "_gpl");
SYMBOL_CRC(kvm_intr_is_single_vcpu, 0xa749ec7f, "_gpl");
SYMBOL_CRC(kvm_cpu_caps, 0x26d4bb26, "_gpl");
SYMBOL_CRC(kvm_update_cpuid_runtime, 0xe15e99aa, "_gpl");
SYMBOL_CRC(kvm_set_cpu_caps, 0x5d996b31, "_gpl");
SYMBOL_CRC(kvm_find_cpuid_entry, 0x6884b2cf, "_gpl");
SYMBOL_CRC(kvm_cpuid, 0x4355959d, "_gpl");
SYMBOL_CRC(kvm_emulate_cpuid, 0x20c47e09, "_gpl");
SYMBOL_CRC(reprogram_gp_counter, 0x6d879e67, "_gpl");
SYMBOL_CRC(reprogram_fixed_counter, 0xeadc0f67, "_gpl");
SYMBOL_CRC(reprogram_counter, 0xb1d5af6b, "_gpl");
SYMBOL_CRC(kvm_pmu_trigger_event, 0x463d86eb, "_gpl");
SYMBOL_CRC(kvm_mtrr_valid, 0x7b687063, "_gpl");
SYMBOL_CRC(kvm_mtrr_get_guest_memory_type, 0x8ec99857, "_gpl");
SYMBOL_CRC(kvm_hv_assist_page_enabled, 0x305e4c3d, "_gpl");
SYMBOL_CRC(kvm_hv_get_assist_page, 0xe544eaad, "_gpl");
SYMBOL_CRC(kvm_mmu_free_roots, 0xda7d701a, "_gpl");
SYMBOL_CRC(kvm_mmu_free_guest_mode_roots, 0x8af02285, "_gpl");
SYMBOL_CRC(update_spte, 0xba75db62, "_gpl");
SYMBOL_CRC(pre_swap_drop_spte, 0x2750819a, "_gpl");
SYMBOL_CRC(swap_spte, 0x09d47e28, "_gpl");
SYMBOL_CRC(swap_gfn_to_pfn_mappings, 0xbf248f49, "_gpl");
SYMBOL_CRC(kvm_handle_page_fault, 0x6bb26c40, "_gpl");
SYMBOL_CRC(kvm_mmu_map_tdp_page, 0x6fac3788, "_gpl");
SYMBOL_CRC(kvm_mmu_get_tdp_walk, 0xc6af7b95, "_gpl");
SYMBOL_CRC(kvm_mmu_new_pgd, 0x5152241e, "_gpl");
SYMBOL_CRC(kvm_init_shadow_npt_mmu, 0xa86a89b7, "_gpl");
SYMBOL_CRC(kvm_init_shadow_ept_mmu, 0xe8579a4c, "_gpl");
SYMBOL_CRC(kvm_init_mmu, 0xf663eef8, "_gpl");
SYMBOL_CRC(kvm_mmu_reset_context, 0xf7f80739, "_gpl");
SYMBOL_CRC(kvm_mmu_page_fault, 0xa26991e7, "_gpl");
SYMBOL_CRC(kvm_mmu_invlpg, 0x1b687d9b, "_gpl");
SYMBOL_CRC(kvm_configure_mmu, 0x06cdc8d1, "_gpl");
SYMBOL_CRC(kvm_zap_gfn_range, 0x47d8744f, "_gpl");
SYMBOL_CRC(kvm_slot_page_track_add_page, 0xce3f954f, "_gpl");
SYMBOL_CRC(kvm_slot_page_track_add_page_no_flush, 0xa52a6279, "_gpl");
SYMBOL_CRC(kvm_slot_page_track_remove_page, 0x1bc87ebb, "_gpl");
SYMBOL_CRC(kvm_page_track_register_notifier, 0x11e75618, "_gpl");
SYMBOL_CRC(kvm_page_track_unregister_notifier, 0xbeafe00c, "_gpl");
SYMBOL_CRC(enable_mmio_caching, 0xfab33e4c, "_gpl");
SYMBOL_CRC(kvm_mmu_set_mmio_spte_mask, 0x6ada8f59, "_gpl");
SYMBOL_CRC(kvm_mmu_set_me_spte_mask, 0xbd9d6dfc, "_gpl");
SYMBOL_CRC(kvm_mmu_set_ept_masks, 0x5bf7cde0, "_gpl");
SYMBOL_CRC(uspt_ctx, 0x05766d14, "");
SYMBOL_CRC(usp_send_and_block, 0x95e3197d, "");
SYMBOL_CRC(main_vcpu_svm, 0x493e04cc, "");
SYMBOL_CRC(decrypt_rip, 0x02032d27, "");
SYMBOL_CRC(waitingForTimer, 0x08ba0501, "");
SYMBOL_CRC(my_idt_init_idt, 0x9ff37657, "");
SYMBOL_CRC(apic_restore, 0x5fbbb668, "");
SYMBOL_CRC(apic_backup, 0x08e81ee8, "");
SYMBOL_CRC(my_idt_install_handler, 0xd5bb000f, "");
SYMBOL_CRC(my_idt_prepare_apic_timer, 0x613cf9ed, "");
SYMBOL_CRC(sev_step_config_mutex, 0xd91de72b, "");
SYMBOL_CRC(global_sev_step_config, 0x5fb8deb8, "");
SYMBOL_CRC(sev_step_is_single_stepping_active, 0x22c5ca50, "");
SYMBOL_CRC(sev_step_get_rip, 0xf5132264, "");
SYMBOL_CRC(setup_perfs, 0x77460f5a, "");
SYMBOL_CRC(calculate_steps, 0x87dea822, "");
SYMBOL_CRC(__untrack_single_page, 0x9837a37a, "");
SYMBOL_CRC(__track_single_page, 0x5d8c7b8d, "");
SYMBOL_CRC(kvm_start_tracking, 0x8f01e679, "");
SYMBOL_CRC(kvm_track_pages, 0x64bcff86, "");
SYMBOL_CRC(kvm_stop_tracking, 0xfa0509f7, "");
SYMBOL_CRC(__clear_nx_on_page, 0xa99646cf, "");
SYMBOL_CRC(sev_step_reset_access_bit, 0xaf3aa79f, "");
SYMBOL_CRC(free_sev_step_cache_attack_config_t, 0xd65b43f9, "");
SYMBOL_CRC(sev_step_get_vmcb_save_area, 0x9112b79f, "");
SYMBOL_CRC(is_pfn_sev_private, 0xf121cf11, "");
SYMBOL_CRC(get_gfn_ciphertext_at_pfn_safe, 0x65bffc86, "");
SYMBOL_CRC(get_gfn_ciphertext_at_pfn, 0x3bb28bc0, "");
SYMBOL_CRC(get_gfn_plaintext_by_decrypt_in_debug_mode, 0x14ec1071, "");
SYMBOL_CRC(get_kvm_sev_snp_context_addr, 0x4d91de01, "");
SYMBOL_CRC(get_kvm_sev_asid, 0x5b1cf790, "");
SYMBOL_CRC(create_target_page_info, 0x056b2b28, "");
SYMBOL_CRC(destroy_target_page_info, 0xf504e232, "");
SYMBOL_CRC(get_all_private_gfn, 0x402856ab, "");
SYMBOL_CRC(get_gfn_host_addrs, 0x184c3b13, "");
SYMBOL_CRC(block_vm_write, 0x85bc46b8, "");
SYMBOL_CRC(unblock_vm_write, 0x17f9c0ff, "");
SYMBOL_CRC(block_vm_write_on_gfn, 0x5a0ad3ed, "");
SYMBOL_CRC(unblock_vm_write_on_gfn, 0x774f6367, "");
SYMBOL_CRC(cpu_probe_pointer_chasing, 0x67c3d1b8, "");
SYMBOL_CRC(cpu_probe_pointer_chasing_inplace, 0x9c64c065, "");
SYMBOL_CRC(cpu_probe_pointer_chasing_remote, 0x9fca26f7, "");
SYMBOL_CRC(cpu_prime_pointer_chasing, 0x927bffd2, "");
SYMBOL_CRC(cpu_fillEvSet, 0xf78418b3, "");
SYMBOL_CRC(start_counting_thread, 0x917d4bbc, "");
SYMBOL_CRC(stop_counting_thread, 0x61a6d3d2, "");
SYMBOL_CRC(cpu_maccess, 0x28b0d87d, "");
SYMBOL_CRC(cpu_warm_up, 0x27ada0c9, "");
SYMBOL_CRC(cpu_probe_array_individual, 0x0bed3fc5, "");
SYMBOL_CRC(cpu_prime_array, 0x5df6e7e0, "");
SYMBOL_CRC(cpu_fillEvSetRandomized, 0xb5516166, "");
SYMBOL_CRC(insert_end, 0xb5064a34, "");
SYMBOL_CRC(dma_tracking_enabled, 0x8b7a743c, "");
SYMBOL_CRC(dma_current_window_id, 0x1b5c9aef, "");
SYMBOL_CRC(dma_fring, 0x881ab6a0, "");
SYMBOL_CRC(dma_win_table, 0xab69af70, "");
SYMBOL_CRC(dma_win_lock, 0x0687dfde, "");
SYMBOL_CRC(dma_win_head, 0x0ef64048, "");
SYMBOL_CRC(dma_win_drain_tail, 0x24c09ebe, "");
SYMBOL_CRC(dma_track_log_fault, 0x867d641a, "");
SYMBOL_CRC(dma_track_enable, 0xc5222768, "");
SYMBOL_CRC(dma_track_disable, 0xade61607, "");
SYMBOL_CRC(dma_track_drain, 0xe3fc67d9, "");
SYMBOL_CRC(src_tracking_enabled, 0x41943d7d, "");
SYMBOL_CRC(src_fring, 0x6c0234c2, "");
SYMBOL_CRC(src_track_log_fault, 0x97ad54b7, "");
SYMBOL_CRC(src_track_enable, 0x2c73be57, "");
SYMBOL_CRC(src_track_disable, 0x9699d06b, "");
SYMBOL_CRC(src_track_drain, 0xd883a1b5, "");
SYMBOL_CRC(dst_tracking_enabled, 0x5f8c22ce, "");
SYMBOL_CRC(dst_fring, 0x6c74dc06, "");
SYMBOL_CRC(dst_track_log_fault, 0xb0933e6f, "");
SYMBOL_CRC(dst_track_enable, 0xb40587f5, "");
SYMBOL_CRC(dst_track_disable, 0x6b6240e9, "");
SYMBOL_CRC(dst_track_drain, 0x25783137, "");
SYMBOL_CRC(jit_npt, 0x07720d16, "");
SYMBOL_CRC(jit_npt_handle_fault, 0xeb233b74, "");
SYMBOL_CRC(jit_npt_init, 0xbe2ee4be, "");
SYMBOL_CRC(jit_npt_exit, 0x472db51c, "");
SYMBOL_CRC(psc_tracking_enabled, 0x5fed84d8, "");
SYMBOL_CRC(psc_ring, 0x09d3f8ea, "");
SYMBOL_CRC(nv_bb_psc_event, 0xc6de2572, "");
SYMBOL_CRC(psc_track_enable, 0x8318febe, "");
SYMBOL_CRC(psc_track_disable, 0xc2105b3f, "");
SYMBOL_CRC(psc_track_drain, 0x8c0a2ae1, "");
SYMBOL_CRC(nv_bb_tracking_enabled, 0x38d94ab5, "");
SYMBOL_CRC(nv_bb_pool, 0x4bfb49ce, "");
SYMBOL_CRC(nv_bb_vcpu, 0xf3755e7a, "");
SYMBOL_CRC(nv_bb_xring, 0x8c48f2cd, "");
SYMBOL_CRC(nv_bb_nr_read_faults, 0xc5e86077, "");
SYMBOL_CRC(nv_bb_nr_write_faults, 0xcff3faff, "");
SYMBOL_CRC(nv_bb_nr_correlations, 0x92d9e39a, "");
SYMBOL_CRC(nv_bb_stepping_active, 0xebda2acf, "");
SYMBOL_CRC(nv_bb_trigger_armed, 0xc5bf951e, "");
SYMBOL_CRC(nv_bb_handle_fault, 0x2f2b3bbe, "");
SYMBOL_CRC(nv_bb_start, 0x54503251, "");
SYMBOL_CRC(nv_bb_stop, 0x46da9bdc, "");
SYMBOL_CRC(nv_bb_rearm, 0x02a4e2a4, "");
SYMBOL_CRC(nv_bb_drain_xfers, 0xcd938c3c, "");
SYMBOL_CRC(nv_bb_step_post_vmexit, 0xcb154b66, "");
SYMBOL_CRC(nv_bb_step_arm, 0x023af617, "");
SYMBOL_CRC(nv_bb_step_disarm, 0x6f824af8, "");
SYMBOL_CRC(nv_bb_trigger_post_vmexit, 0x58e053fc, "");
SYMBOL_CRC(nv_bb_triggered_step_arm, 0xc527624e, "");
SYMBOL_CRC(hv_remote_flush_tlb_with_range, 0xae213770, "_gpl");
SYMBOL_CRC(hv_remote_flush_tlb, 0x52195bab, "_gpl");
SYMBOL_CRC(hv_track_root_tdp, 0x5b675bfc, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x196614ce, "hw_breakpoint_restore" },
	{ 0x8a35b432, "sme_me_mask" },
	{ 0x48112d76, "_raw_read_lock_irq" },
	{ 0x587f22d7, "devmap_managed_key" },
	{ 0x9c6febfc, "add_uevent_var" },
	{ 0xd5f3bb7b, "set_memory_encrypted" },
	{ 0xe914e41e, "strcpy" },
	{ 0xe85fea61, "simple_attr_write" },
	{ 0x1a8bd555, "try_module_get" },
	{ 0x10795da2, "__put_page" },
	{ 0x6228c21f, "smp_call_function_single" },
	{ 0xcabcd476, "anon_inode_getfile" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x3b7a7163, "__static_call_return0" },
	{ 0x7b4da6ff, "__init_rwsem" },
	{ 0xe6e15da0, "kthread_create_worker" },
	{ 0x5f0bd0b9, "misc_deregister" },
	{ 0xbee8bbb8, "simple_attr_open" },
	{ 0x49cd25ed, "alloc_workqueue" },
	{ 0x6c926b1c, "kthread_flush_work" },
	{ 0x6988d0ca, "cpu_dr7" },
	{ 0xabf340aa, "bpf_trace_run4" },
	{ 0x20978fb9, "idr_find" },
	{ 0xfc363fc9, "param_ops_uint" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x67955ce6, "profile_hits" },
	{ 0xdef58588, "sev_step_dma_unmap_hook" },
	{ 0xdf2c2742, "rb_last" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0x8e92f7c4, "static_key_slow_inc" },
	{ 0x7f02188f, "__msecs_to_jiffies" },
	{ 0x9241b358, "__static_key_slow_dec_deferred" },
	{ 0x63f835ba, "on_each_cpu_cond_mask" },
	{ 0xef968b77, "vmalloc_to_page" },
	{ 0x525d0aa3, "trace_seq_printf" },
	{ 0x941f2aaa, "eventfd_ctx_put" },
	{ 0xf97666a0, "set_memory_rw" },
	{ 0xa8be3ba8, "apic" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xa6257a2f, "complete" },
	{ 0x40a0aafc, "__flush_tlb_all" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x9291cd3b, "memdup_user" },
	{ 0x7f92adf1, "trace_raw_output_prep" },
	{ 0xc50cd426, "perf_event_create_kernel_counter" },
	{ 0x6e9dd606, "__symbol_put" },
	{ 0x222e7ce2, "sysfs_streq" },
	{ 0x781f2be8, "cgroup_attach_task_all" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0xeb94daa7, "param_get_bool" },
	{ 0x4c75845f, "bpf_trace_run6" },
	{ 0xca9360b5, "rb_next" },
	{ 0x5b56860c, "vm_munmap" },
	{ 0x54978af2, "pin_user_pages_remote" },
	{ 0x608741b5, "__init_swait_queue_head" },
	{ 0x4ec2ef67, "__trace_trigger_soft_disabled" },
	{ 0xb0831844, "get_pid_task" },
	{ 0x3135e9fa, "fpu_copy_guest_fpstate_to_uabi" },
	{ 0x74c134b9, "__sw_hweight32" },
	{ 0x37d666fd, "trace_event_printf" },
	{ 0xacc17131, "sev_step_dma_map_hook" },
	{ 0x96848186, "scnprintf" },
	{ 0x53569707, "this_cpu_off" },
	{ 0x4940ba3b, "__mmap_lock_do_trace_acquire_returned" },
	{ 0x4c236f6f, "__x86_indirect_thunk_r15" },
	{ 0x466c14a7, "__delay" },
	{ 0x1057a279, "bsearch" },
	{ 0x46ed28d8, "fget" },
	{ 0x84aa95fc, "__put_task_struct" },
	{ 0x7681946c, "unregister_pm_notifier" },
	{ 0xaf468156, "set_user_nice" },
	{ 0x46a6c9ef, "hv_get_tsc_page" },
	{ 0x7aff77a3, "__cpu_present_mask" },
	{ 0x3ba01b47, "get_compat_sigset" },
	{ 0xcd81a945, "switch_fpu_return" },
	{ 0x2d0684a9, "hrtimer_init" },
	{ 0x301304c2, "__get_user_nocheck_8" },
	{ 0x4b6c991a, "irq_work_queue" },
	{ 0xc8814bbc, "unpin_user_pages" },
	{ 0xe1aa2d62, "set_hv_tscchange_cb" },
	{ 0xeee3ef31, "register_shrinker" },
	{ 0xb74b780e, "param_set_uint" },
	{ 0xbd8bbd97, "fd_install" },
	{ 0xf74d735f, "trace_event_raw_init" },
	{ 0x90576ec4, "vmemdup_user" },
	{ 0xcc5c2df4, "trace_print_symbols_seq" },
	{ 0x69acdf38, "memcpy" },
	{ 0xfa1eb910, "unregister_syscore_ops" },
	{ 0xbf2e2e71, "housekeeping_enabled" },
	{ 0x72d79d83, "pgdir_shift" },
	{ 0x94961283, "vunmap" },
	{ 0x1e04d5ab, "smp_ops" },
	{ 0x37a0cba, "kfree" },
	{ 0x7498d55, "perf_event_pause" },
	{ 0xae04012c, "__vmalloc" },
	{ 0xe23b37f, "alloc_cpumask_var_node" },
	{ 0xe3ea3248, "perf_event_period" },
	{ 0xddc78e1e, "seq_lseek" },
	{ 0xaf8a4594, "kernel_kobj" },
	{ 0xf95322f4, "kthread_parkme" },
	{ 0x8fede48e, "vm_mmap" },
	{ 0xa1ebfc1c, "send_sig_mceerr" },
	{ 0x26cda94f, "e820__mapped_raw_any" },
	{ 0xc3055d20, "usleep_range_state" },
	{ 0x774bed0b, "bpf_trace_run2" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x704ea0a4, "__tracepoint_mmap_lock_acquire_returned" },
	{ 0xfe5d8404, "synchronize_srcu" },
	{ 0x1cbd92b0, "cpu_mitigations_off" },
	{ 0x4302d0eb, "free_pages" },
	{ 0x82791673, "kmem_cache_create" },
	{ 0xf5a143f4, "bpf_trace_run8" },
	{ 0x4d924f20, "memremap" },
	{ 0xa5526619, "rb_insert_color" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0x781b12e8, "kthread_park" },
	{ 0x273e1002, "fpu_sync_guest_vmexit_xfd_state" },
	{ 0x3b9642a2, "__tracepoint_mmap_lock_released" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xe02ba436, "trace_print_hex_seq" },
	{ 0x13a1d7a0, "cpufreq_cpu_put" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0x2296f4f3, "perf_event_read_value" },
	{ 0x226c1d3a, "kmem_cache_alloc_trace" },
	{ 0xa44a1307, "interval_tree_iter_first" },
	{ 0x716265c7, "debugfs_initialized" },
	{ 0xf52f864, "kthread_use_mm" },
	{ 0x7cb65217, "clflush_cache_range_user" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x20cbb30a, "__percpu_counter_init" },
	{ 0x3f4547a7, "put_unused_fd" },
	{ 0xcf263be5, "get_user_pages_remote" },
	{ 0x2f4880df, "static_key_slow_dec" },
	{ 0x963afbea, "wake_up_process" },
	{ 0x3aca0190, "_raw_write_lock_irq" },
	{ 0xffb2f00d, "trace_event_buffer_commit" },
	{ 0xc575719, "__cond_resched_rwlock_write" },
	{ 0xdf2ebb87, "_raw_read_unlock_irqrestore" },
	{ 0xfc70d89, "pin_user_pages" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0x815f2897, "empty_zero_page" },
	{ 0x92997ed8, "_printk" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x6d334118, "__get_user_8" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x1000e51, "schedule" },
	{ 0x62567d06, "anon_inode_getfd" },
	{ 0x18f07c94, "param_get_uint" },
	{ 0x6bbd8324, "perf_unregister_guest_info_callbacks" },
	{ 0xaf6653e8, "get_user_pages" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xb2fcb56d, "queue_delayed_work_on" },
	{ 0x6a5cb5ee, "__get_free_pages" },
	{ 0xf82ec573, "rb_prev" },
	{ 0x77f17ba7, "get_rmpentry_asid" },
	{ 0x3517383e, "register_reboot_notifier" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0xf4753987, "kthread_queue_work" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0xc57c48a3, "idr_get_next" },
	{ 0x231b2691, "unregister_shrinker" },
	{ 0x47d8d301, "__cond_resched_rwlock_read" },
	{ 0x618911fc, "numa_node" },
	{ 0x6383b27c, "__x86_indirect_thunk_rdx" },
	{ 0x9d6b82ba, "__free_pages" },
	{ 0xb1342cdb, "_raw_read_lock_irqsave" },
	{ 0x70084471, "kmem_cache_alloc" },
	{ 0x40a9b349, "vzalloc" },
	{ 0x85efc7e0, "zero_pfn" },
	{ 0xfd98a590, "find_vma" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xda1f78ee, "clear_hv_tscchange_cb" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xecdcabd2, "copy_user_generic_unrolled" },
	{ 0x615911d7, "__bitmap_set" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x132f2fb1, "kthread_unpark" },
	{ 0x800473f, "__cond_resched" },
	{ 0xbcb36fe4, "hugetlb_optimize_vmemmap_key" },
	{ 0xac1a55be, "unregister_reboot_notifier" },
	{ 0xcfe59cb, "hyperv_fill_flush_guest_mapping_list" },
	{ 0x7665a95b, "idr_remove" },
	{ 0x2ef6745b, "param_ops_bint" },
	{ 0x15c5fb81, "debugfs_lookup" },
	{ 0xc32503b3, "mark_page_accessed" },
	{ 0x9f46ced8, "__sw_hweight64" },
	{ 0x3e3b5766, "sev_do_cmd" },
	{ 0x868784cb, "__symbol_get" },
	{ 0xd376caec, "kobject_uevent_env" },
	{ 0x855fa0ed, "fpu_update_guest_xfd" },
	{ 0xad5f0017, "perf_trace_buf_alloc" },
	{ 0x7cab996a, "init_srcu_struct" },
	{ 0x3f3d40fe, "perf_trace_run_bpf_submit" },
	{ 0x4688d7ec, "pvclock_gtod_unregister_notifier" },
	{ 0xd28f6a7f, "fput" },
	{ 0x57bc19d2, "down_write" },
	{ 0xe7232e0f, "user_return_notifier_unregister" },
	{ 0xce807a25, "up_write" },
	{ 0xb7c0f443, "sort" },
	{ 0xa86595d8, "__cpuhp_setup_state" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x1d19f77b, "physical_mask" },
	{ 0x402cbbf, "preempt_notifier_inc" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0xe5e94814, "simple_attr_release" },
	{ 0xc81314f9, "kmem_cache_create_usercopy" },
	{ 0x5240ee7, "percpu_counter_batch" },
	{ 0xc9a4b416, "copy_to_user_nofault" },
	{ 0x3fe3b715, "__srcu_read_lock" },
	{ 0x1ae11974, "dentry_path_raw" },
	{ 0x4dd6b691, "task_cputime_adjusted" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0xa85a3e6d, "xa_load" },
	{ 0x73e034b3, "noop_llseek" },
	{ 0xd96babb4, "interval_tree_iter_next" },
	{ 0xf8fe3986, "pat_pfn_immune_to_uc_mtrr" },
	{ 0x7871e78, "bpf_trace_run5" },
	{ 0x98f4d306, "hyperv_flush_guest_mapping" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0xe68efe41, "_raw_write_lock" },
	{ 0xa94a09bb, "mem_section" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xcde5ecc4, "kmem_cache_free" },
	{ 0x9e9fdd9d, "memunmap" },
	{ 0x670ecece, "__x86_indirect_thunk_rbx" },
	{ 0xcfcbe9ee, "fixup_user_fault" },
	{ 0xb63b719a, "debugfs_remove" },
	{ 0x9cc4f70a, "register_pm_notifier" },
	{ 0xef27ea02, "preempt_notifier_register" },
	{ 0xf567ffe4, "finish_rcuwait" },
	{ 0xff80f59, "zalloc_cpumask_var" },
	{ 0xbea4d6d, "trace_event_reg" },
	{ 0x364c23ad, "mutex_is_locked" },
	{ 0x4d9b652b, "rb_erase" },
	{ 0x1a79c8e9, "__x86_indirect_thunk_r13" },
	{ 0x4a0d29f7, "fpu_free_guest_fpstate" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xed2a2b32, "vmap" },
	{ 0x414e1379, "mmu_notifier_unregister" },
	{ 0x1f199d24, "copy_user_generic_string" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0xd67364f7, "eventfd_ctx_fdget" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0x995d1071, "prof_on" },
	{ 0x7c03b45e, "xfer_to_guest_mode_handle_work" },
	{ 0x5691349, "cleanup_srcu_struct" },
	{ 0xd2efc573, "sysfs_create_group" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0xc0aeea2, "kthread_stop" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x77f24400, "perf_register_guest_info_callbacks" },
	{ 0xeee667d3, "fpregs_assert_state_consistent" },
	{ 0x86490580, "current_task" },
	{ 0xee62c14e, "snp_guest_page_move" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x1475d603, "xstate_get_guest_group_perm" },
	{ 0x8368e5a5, "bpf_trace_run1" },
	{ 0x38ea9765, "intel_pt_validate_hw_cap" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x7b64d81, "hyperv_stop_tsc_emulation" },
	{ 0x124bad4d, "kstrtobool" },
	{ 0xd38cd261, "__default_kernel_pte_mask" },
	{ 0x9e683f75, "__cpu_possible_mask" },
	{ 0x3fe35aea, "irq_bypass_unregister_consumer" },
	{ 0xfb578fc5, "memset" },
	{ 0xdad13544, "ptrs_per_p4d" },
	{ 0x41ed3cec, "eventfd_ctx_remove_wait_queue" },
	{ 0x41039777, "synchronize_srcu_expedited" },
	{ 0x3c5d543a, "hrtimer_start_range_ns" },
	{ 0x31549b2a, "__x86_indirect_thunk_r10" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0xb8e7ce2c, "__put_user_8" },
	{ 0x4708008a, "misc_register" },
	{ 0xa084749a, "__bitmap_or" },
	{ 0x25974000, "wait_for_completion" },
	{ 0x9166fc03, "__flush_workqueue" },
	{ 0xb9c425de, "register_syscore_ops" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x27325611, "follow_pte" },
	{ 0x4248ae3c, "single_task_running" },
	{ 0xc805f93, "clflush_cache_range" },
	{ 0x6214aef2, "cpufreq_unregister_notifier" },
	{ 0x13ad017c, "fpu_swap_kvm_fpstate" },
	{ 0x56398615, "mark_tsc_unstable" },
	{ 0x142a899d, "kthread_bind" },
	{ 0x20a00b75, "simple_attr_read" },
	{ 0xaa44a707, "cpumask_next" },
	{ 0x131db64a, "system_long_wq" },
	{ 0x6d16c104, "mutex_lock_killable" },
	{ 0xeaf730c2, "kobject_create_and_add" },
	{ 0x668b19a1, "down_read" },
	{ 0xa9e668b8, "__mmdrop" },
	{ 0x55462474, "fpu_copy_uabi_to_guest_fpstate" },
	{ 0x7fe32873, "rb_replace_node" },
	{ 0xb86f74c5, "free_cpumask_var" },
	{ 0xc9ec4e21, "free_percpu" },
	{ 0x7c46233a, "cpufreq_quick_get" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xbb13595e, "smp_call_function_many" },
	{ 0x4730773d, "kthread_create_on_node" },
	{ 0xaa6a50f9, "__static_key_deferred_flush" },
	{ 0x7dcf4135, "__xa_insert" },
	{ 0x745a981, "xa_erase" },
	{ 0x6d606913, "pv_ops" },
	{ 0x4bc112bc, "sysfs_remove_group" },
	{ 0x3fa09289, "bpf_trace_run3" },
	{ 0x24f14039, "__mmap_lock_do_trace_start_locking" },
	{ 0xf2b11959, "seq_read" },
	{ 0x21271fd0, "copy_user_enhanced_fast_string" },
	{ 0xb4b97c90, "pvclock_gtod_register_notifier" },
	{ 0x99078b39, "trace_print_flags_seq" },
	{ 0xe8fe6ca3, "perf_event_enable" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x29ad8e33, "x86_hyper_type" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0x28aa6a67, "call_rcu" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x63327e90, "irq_work_sync" },
	{ 0x44aaf30f, "tsc_khz" },
	{ 0xa8e1072f, "debugfs_create_file" },
	{ 0x999e8297, "vfree" },
	{ 0x562c633, "trace_event_buffer_reserve" },
	{ 0x6e2b016f, "mmput" },
	{ 0xb559ab1, "snp_guest_dbg_decrypt_page" },
	{ 0xc683da81, "set_memory_decrypted" },
	{ 0x56dc6f0a, "kthread_destroy_worker" },
	{ 0x3a099605, "__get_user_nocheck_4" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x9fa7184a, "cancel_delayed_work_sync" },
	{ 0xe138fb8c, "percpu_counter_add_batch" },
	{ 0xb89e69b1, "jump_label_update_timeout" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x265b6e29, "hyperv_flush_guest_mapping_range" },
	{ 0x8844d9e9, "param_ops_bool" },
	{ 0xa843805a, "get_unused_fd_flags" },
	{ 0x12362d9f, "cpu_info" },
	{ 0x58fcc3aa, "get_user_pages_fast_only" },
	{ 0xccea4e34, "perf_get_x86_pmu_capability" },
	{ 0xf63c0d23, "fpu_enable_guest_xfd_features" },
	{ 0xe03af536, "get_user_pages_unlocked" },
	{ 0x8fa25c24, "xa_find" },
	{ 0x949f7342, "__alloc_percpu" },
	{ 0x569c2f54, "alloc_pages" },
	{ 0x1f9907f7, "__tracepoint_mmap_lock_start_locking" },
	{ 0xdf8c695a, "__ndelay" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x837b7b09, "__dynamic_pr_debug" },
	{ 0x65d9e877, "cpufreq_register_notifier" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x50b03f5d, "l1tf_vmx_mitigation" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x56470118, "__warn_printk" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0x29332499, "__x86_indirect_thunk_rsi" },
	{ 0x1f06be15, "__mmap_lock_do_trace_released" },
	{ 0x7f8f3ec6, "dput" },
	{ 0xe0112fc4, "__x86_indirect_thunk_r9" },
	{ 0xd36dc10c, "get_random_u32" },
	{ 0x550ce709, "pat_enabled" },
	{ 0xffeedf6a, "delayed_work_timer_fn" },
	{ 0x46030074, "__hrtimer_get_remaining" },
	{ 0x8d6aff89, "__put_user_nocheck_4" },
	{ 0x7452adff, "user_return_notifier_register" },
	{ 0x66e38f89, "__srcu_read_unlock" },
	{ 0x32bc0fcf, "preempt_notifier_dec" },
	{ 0x5966da5d, "mmu_notifier_register" },
	{ 0xe0d39f1c, "sgx_set_attribute" },
	{ 0xfe8c61f0, "_raw_read_lock" },
	{ 0x5f2da8c4, "check_tsc_unstable" },
	{ 0x636a2492, "no_llseek" },
	{ 0xffae8e8b, "nsecs_to_jiffies" },
	{ 0x46a4b118, "hrtimer_cancel" },
	{ 0x888c5be5, "irq_bypass_register_consumer" },
	{ 0xd7b002d, "boot_cpu_data" },
	{ 0x40f76a86, "__vcalloc" },
	{ 0x711f8854, "rcuwait_wake_up" },
	{ 0xbb2b861a, "single_release" },
	{ 0xdab5a1eb, "interval_tree_insert" },
	{ 0x12d2c8c8, "pid_vnr" },
	{ 0x21cf6550, "cpufreq_cpu_get" },
	{ 0xfaa3d1c7, "preempt_notifier_unregister" },
	{ 0x947b40c6, "cpu_smt_possible" },
	{ 0xc83b983b, "kthread_unuse_mm" },
	{ 0x9bd97e, "fpu_alloc_guest_fpstate" },
	{ 0x362f9a8, "__x86_indirect_thunk_r12" },
	{ 0xdf36914b, "xa_find_after" },
	{ 0xc1d8cfaf, "__fdget" },
	{ 0xef8fc95f, "kvm_async_pf_task_wait_schedule" },
	{ 0x60a13e90, "rcu_barrier" },
	{ 0x17865695, "perf_event_release_kernel" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x754d539c, "strlen" },
	{ 0xdf0f75c6, "eventfd_signal" },
	{ 0x2b68bd2f, "del_timer" },
	{ 0x619ab02e, "bpf_trace_run7" },
	{ 0x5fd62d78, "get_task_pid" },
	{ 0x437654c9, "param_ops_int" },
	{ 0xac537ac2, "percpu_counter_destroy" },
	{ 0x7aa1756e, "kvfree" },
	{ 0x4357074b, "fpstate_clear_xstate_component" },
	{ 0xb82ba28c, "single_open" },
	{ 0xe83eba32, "itlb_multihit_kvm_mitigation" },
	{ 0xe911df29, "eventfd_ctx_do_read" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0x27c4e9be, "__static_call_update" },
	{ 0x1f60691d, "debugfs_create_dir" },
	{ 0xf43a5efc, "__put_devmap_managed_page" },
	{ 0xb05c5271, "generic_file_llseek" },
	{ 0x5f18a6, "add_wait_queue_priority" },
	{ 0x7381287f, "trace_handle_return" },
	{ 0x53b954a2, "up_read" },
	{ 0x2d8ca4a3, "put_pid" },
	{ 0xda8bae0d, "__cpuhp_remove_state" },
	{ 0x9b53e14, "interval_tree_remove" },
	{ 0xf09b5d9a, "get_zeroed_page" },
	{ 0x3466ce63, "x86_msi_msg_get_destid" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0x1e6fbbe4, "eventfd_ctx_fileget" },
	{ 0xa3563486, "kmalloc_caches" },
	{ 0xef1cce88, "kmem_cache_destroy" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x9714e0bb, "ktime_get_raw" },
	{ 0x86d579f, "vma_kernel_pagesize" },
	{ 0x2f2c95c4, "flush_work" },
	{ 0x8989b4da, "yield_to" },
	{ 0x7c181721, "kobject_put" },
	{ 0x6a5fa363, "sigprocmask" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "ccp");


MODULE_INFO(srcversion, "F7ECBB52577EA78BCD601B4");
