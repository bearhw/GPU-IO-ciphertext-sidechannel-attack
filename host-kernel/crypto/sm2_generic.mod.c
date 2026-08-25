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

SYMBOL_CRC(sm2_compute_z_digest, 0xf7aa3bed, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xdbf7cb70, "mpi_get_nbits" },
	{ 0xb6410433, "mpi_addm" },
	{ 0xf3797506, "mpi_ec_deinit" },
	{ 0xa98edad1, "sm3_update" },
	{ 0xceb1f126, "mpi_read_raw_data" },
	{ 0x37a0cba, "kfree" },
	{ 0x5fa625ed, "mpi_ec_mul_point" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xf04338f9, "sm3_final" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x3450ad94, "mpi_set_ui" },
	{ 0x9eebdde7, "mpi_point_new" },
	{ 0x4efcf021, "mpi_normalize" },
	{ 0x4c4f603, "mpi_get_buffer" },
	{ 0x98503a63, "mpi_alloc" },
	{ 0x1d4b95bf, "crypto_unregister_akcipher" },
	{ 0x4230a8d7, "sg_nents_for_len" },
	{ 0x291876f3, "mpi_ec_get_affine" },
	{ 0x8a83fb45, "mpi_point_free_parts" },
	{ 0x6c205008, "mpi_print" },
	{ 0x9bece81b, "mpi_cmp_ui" },
	{ 0x6bcdedc0, "mpi_point_init" },
	{ 0x38e1fde7, "mpi_set" },
	{ 0xae7c231d, "mpi_cmp" },
	{ 0x80d5e57a, "mpi_free" },
	{ 0x95843030, "mpi_ec_init" },
	{ 0x91b774a1, "mpi_scanval" },
	{ 0x8ff60436, "mpi_ec_add_points" },
	{ 0x223ceec2, "crypto_register_akcipher" },
	{ 0x13ce87e8, "asn1_ber_decoder" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xea778fab, "sg_pcopy_to_buffer" },
	{ 0xfe1a7a7b, "mpi_point_release" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "sm3");


MODULE_INFO(srcversion, "8F082D97B6955B5D9AA179B");
