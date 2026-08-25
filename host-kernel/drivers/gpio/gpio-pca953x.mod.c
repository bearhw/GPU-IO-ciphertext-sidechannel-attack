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
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0xe571fcf8, "regcache_cache_only" },
	{ 0x3c97fe5f, "regulator_disable" },
	{ 0xf90a1e85, "__x86_indirect_thunk_r8" },
	{ 0x9085e9a, "_dev_err" },
	{ 0xc93334f0, "gpiochip_get_data" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xd75eb10d, "seq_printf" },
	{ 0xce2840e7, "irq_set_irq_wake" },
	{ 0xa7bacb0b, "gpiochip_enable_irq" },
	{ 0x8ed93f5d, "gpiochip_disable_irq" },
	{ 0x96cb9774, "regmap_bulk_write" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xb04e5f25, "regcache_sync_region" },
	{ 0xb68e31b4, "regmap_update_bits_base" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0x4e91bfb0, "regmap_read" },
	{ 0xea5b49a9, "regmap_bulk_read" },
	{ 0x18345b8e, "__bitmap_replace" },
	{ 0x17b6730a, "devm_kmalloc" },
	{ 0x4c9391a0, "devm_regulator_get" },
	{ 0xb26ae49c, "regulator_enable" },
	{ 0x9c90d539, "device_get_match_data" },
	{ 0x1e90587a, "devm_gpiod_get_optional" },
	{ 0xde5f9a03, "dev_err_probe" },
	{ 0x2587f789, "_dev_info" },
	{ 0xa9181537, "__devm_regmap_init_i2c" },
	{ 0x72b3d561, "regcache_mark_dirty" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x50877b9, "dmi_first_match" },
	{ 0x89b4264a, "devm_acpi_dev_add_driver_gpios" },
	{ 0x66dbe96c, "_dev_warn" },
	{ 0x55046979, "is_acpi_device_node" },
	{ 0x5343a5ab, "acpi_dev_gpio_irq_get_by" },
	{ 0x9f8700d8, "devm_gpiochip_add_data_with_key" },
	{ 0x39b52d19, "__bitmap_and" },
	{ 0xbe1ed923, "handle_simple_irq" },
	{ 0x6c6710bc, "devm_request_threaded_irq" },
	{ 0x65487097, "__x86_indirect_thunk_rax" },
	{ 0xf6fc8791, "__bitmap_xor" },
	{ 0x8810754a, "_find_first_bit" },
	{ 0xa084749a, "__bitmap_or" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x549525ef, "handle_nested_irq" },
	{ 0x764d9ae7, "__irq_resolve_mapping" },
	{ 0x1d24c881, "___ratelimit" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0x7c173634, "__bitmap_complement" },
	{ 0xd916199f, "regcache_sync" },
	{ 0xf43dea22, "i2c_register_driver" },
	{ 0x71b401cc, "i2c_del_driver" },
	{ 0x5986a03b, "gpiochip_irq_reqres" },
	{ 0xcd995a5b, "gpiochip_irq_relres" },
	{ 0x817bf968, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("of:N*T*Cnxp,pca6408");
MODULE_ALIAS("of:N*T*Cnxp,pca6408C*");
MODULE_ALIAS("of:N*T*Cnxp,pca6416");
MODULE_ALIAS("of:N*T*Cnxp,pca6416C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9505");
MODULE_ALIAS("of:N*T*Cnxp,pca9505C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9506");
MODULE_ALIAS("of:N*T*Cnxp,pca9506C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9534");
MODULE_ALIAS("of:N*T*Cnxp,pca9534C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9535");
MODULE_ALIAS("of:N*T*Cnxp,pca9535C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9536");
MODULE_ALIAS("of:N*T*Cnxp,pca9536C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9537");
MODULE_ALIAS("of:N*T*Cnxp,pca9537C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9538");
MODULE_ALIAS("of:N*T*Cnxp,pca9538C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9539");
MODULE_ALIAS("of:N*T*Cnxp,pca9539C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9554");
MODULE_ALIAS("of:N*T*Cnxp,pca9554C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9555");
MODULE_ALIAS("of:N*T*Cnxp,pca9555C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9556");
MODULE_ALIAS("of:N*T*Cnxp,pca9556C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9557");
MODULE_ALIAS("of:N*T*Cnxp,pca9557C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9574");
MODULE_ALIAS("of:N*T*Cnxp,pca9574C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9575");
MODULE_ALIAS("of:N*T*Cnxp,pca9575C*");
MODULE_ALIAS("of:N*T*Cnxp,pca9698");
MODULE_ALIAS("of:N*T*Cnxp,pca9698C*");
MODULE_ALIAS("of:N*T*Cnxp,pcal6416");
MODULE_ALIAS("of:N*T*Cnxp,pcal6416C*");
MODULE_ALIAS("of:N*T*Cnxp,pcal6524");
MODULE_ALIAS("of:N*T*Cnxp,pcal6524C*");
MODULE_ALIAS("of:N*T*Cnxp,pcal9535");
MODULE_ALIAS("of:N*T*Cnxp,pcal9535C*");
MODULE_ALIAS("of:N*T*Cnxp,pcal9554b");
MODULE_ALIAS("of:N*T*Cnxp,pcal9554bC*");
MODULE_ALIAS("of:N*T*Cnxp,pcal9555a");
MODULE_ALIAS("of:N*T*Cnxp,pcal9555aC*");
MODULE_ALIAS("of:N*T*Cmaxim,max7310");
MODULE_ALIAS("of:N*T*Cmaxim,max7310C*");
MODULE_ALIAS("of:N*T*Cmaxim,max7312");
MODULE_ALIAS("of:N*T*Cmaxim,max7312C*");
MODULE_ALIAS("of:N*T*Cmaxim,max7313");
MODULE_ALIAS("of:N*T*Cmaxim,max7313C*");
MODULE_ALIAS("of:N*T*Cmaxim,max7315");
MODULE_ALIAS("of:N*T*Cmaxim,max7315C*");
MODULE_ALIAS("of:N*T*Cmaxim,max7318");
MODULE_ALIAS("of:N*T*Cmaxim,max7318C*");
MODULE_ALIAS("of:N*T*Cti,pca6107");
MODULE_ALIAS("of:N*T*Cti,pca6107C*");
MODULE_ALIAS("of:N*T*Cti,pca9536");
MODULE_ALIAS("of:N*T*Cti,pca9536C*");
MODULE_ALIAS("of:N*T*Cti,tca6408");
MODULE_ALIAS("of:N*T*Cti,tca6408C*");
MODULE_ALIAS("of:N*T*Cti,tca6416");
MODULE_ALIAS("of:N*T*Cti,tca6416C*");
MODULE_ALIAS("of:N*T*Cti,tca6424");
MODULE_ALIAS("of:N*T*Cti,tca6424C*");
MODULE_ALIAS("of:N*T*Cti,tca9539");
MODULE_ALIAS("of:N*T*Cti,tca9539C*");
MODULE_ALIAS("of:N*T*Connn,cat9554");
MODULE_ALIAS("of:N*T*Connn,cat9554C*");
MODULE_ALIAS("of:N*T*Connn,pca9654");
MODULE_ALIAS("of:N*T*Connn,pca9654C*");
MODULE_ALIAS("of:N*T*Connn,pca9655");
MODULE_ALIAS("of:N*T*Connn,pca9655C*");
MODULE_ALIAS("of:N*T*Cexar,xra1202");
MODULE_ALIAS("of:N*T*Cexar,xra1202C*");
MODULE_ALIAS("acpi*:INT3491:*");
MODULE_ALIAS("i2c:pca6408");
MODULE_ALIAS("i2c:pca6416");
MODULE_ALIAS("i2c:pca9505");
MODULE_ALIAS("i2c:pca9506");
MODULE_ALIAS("i2c:pca9534");
MODULE_ALIAS("i2c:pca9535");
MODULE_ALIAS("i2c:pca9536");
MODULE_ALIAS("i2c:pca9537");
MODULE_ALIAS("i2c:pca9538");
MODULE_ALIAS("i2c:pca9539");
MODULE_ALIAS("i2c:pca9554");
MODULE_ALIAS("i2c:pca9555");
MODULE_ALIAS("i2c:pca9556");
MODULE_ALIAS("i2c:pca9557");
MODULE_ALIAS("i2c:pca9574");
MODULE_ALIAS("i2c:pca9575");
MODULE_ALIAS("i2c:pca9698");
MODULE_ALIAS("i2c:pcal6416");
MODULE_ALIAS("i2c:pcal6524");
MODULE_ALIAS("i2c:pcal9535");
MODULE_ALIAS("i2c:pcal9554b");
MODULE_ALIAS("i2c:pcal9555a");
MODULE_ALIAS("i2c:max7310");
MODULE_ALIAS("i2c:max7312");
MODULE_ALIAS("i2c:max7313");
MODULE_ALIAS("i2c:max7315");
MODULE_ALIAS("i2c:max7318");
MODULE_ALIAS("i2c:pca6107");
MODULE_ALIAS("i2c:tca6408");
MODULE_ALIAS("i2c:tca6416");
MODULE_ALIAS("i2c:tca6424");
MODULE_ALIAS("i2c:tca9539");
MODULE_ALIAS("i2c:tca9554");
MODULE_ALIAS("i2c:xra1202");

MODULE_INFO(srcversion, "53AAB35F67E151B66E8345B");
