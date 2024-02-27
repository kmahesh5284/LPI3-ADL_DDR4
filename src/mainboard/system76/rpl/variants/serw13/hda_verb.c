/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
	/* Realtek, ALC1220 */
	0x10ec1220, /* Vendor ID */
	0x1558d502, /* Subsystem ID */
	241,

	0x02050008, 0x020480cb, 0x02050008, 0x0204c0cb,
	AZALIA_SUBVENDOR(0, 0x1558d502),
	AZALIA_RESET(1),
	AZALIA_PIN_CFG(0, 0x12, 0x90a60130),
	AZALIA_PIN_CFG(0, 0x14, 0x0421101f),
	AZALIA_PIN_CFG(0, 0x15, 0x40000000),
	AZALIA_PIN_CFG(0, 0x16, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x17, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x18, 0x04a11040),
	AZALIA_PIN_CFG(0, 0x19, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1a, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1b, 0x90170110),
	AZALIA_PIN_CFG(0, 0x1d, 0x40b7952d),
	AZALIA_PIN_CFG(0, 0x1e, 0x04451150),

	// ALC1318 smart amp
	0x02050016, 0x02048020, 0x02050016, 0x02048020,
	0x02050043, 0x02043005, 0x02050058, 0x02048ed1,
	0x02050063, 0x0204e430, 0x05b50000, 0x05b43530,
	0x05750002, 0x05741400, 0x05b5000a, 0x05b45520,
	0x02050042, 0x020486cb, 0x0143b000, 0x01470700,
	0x02050036, 0x02042a6a, 0x02050008, 0x0204800b,
	0x02050007, 0x020403c3, 0x01470c02, 0x01470c02,
	0x00c37180, 0x01b3b000, 0x01b70700, 0x00b37419,
	0x0205001b, 0x02044002, 0x0205001b, 0x02044002,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c000, 0x0205002b, 0x02040001,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f20d,
	0x0205002b, 0x02040000, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f212, 0x0205002b, 0x0204003e,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c001,
	0x0205002b, 0x02040002, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c003, 0x0205002b, 0x02040022,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c004,
	0x0205002b, 0x02040044, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c005, 0x0205002b, 0x02040044,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c007,
	0x0205002b, 0x02040064, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c00e, 0x0205002b, 0x020400e7,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f223,
	0x0205002b, 0x0204007f, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f224, 0x0205002b, 0x020400db,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f225,
	0x0205002b, 0x020400ee, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f226, 0x0205002b, 0x0204003f,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f227,
	0x0205002b, 0x0204000f, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f21a, 0x0205002b, 0x02040078,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f242,
	0x0205002b, 0x0204003c, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c120, 0x0205002b, 0x02040040,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c125,
	0x0205002b, 0x02040003, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c321, 0x0205002b, 0x0204000b,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c200,
	0x0205002b, 0x020400d8, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c201, 0x0205002b, 0x02040027,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c202,
	0x0205002b, 0x0204000f, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c400, 0x0205002b, 0x0204000e,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c401,
	0x0205002b, 0x02040043, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c402, 0x0205002b, 0x020400e0,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c403,
	0x0205002b, 0x02040000, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c404, 0x0205002b, 0x0204004c,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c406,
	0x0205002b, 0x02040040, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c407, 0x0205002b, 0x02040002,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c408,
	0x0205002b, 0x0204003f, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c300, 0x0205002b, 0x02040001,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c125,
	0x0205002b, 0x02040003, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204df00, 0x0205002b, 0x02040010,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204df5f,
	0x0205002b, 0x02040001, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204df60, 0x0205002b, 0x020400a7,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204ea00,
	0x0205002b, 0x02040047, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c203, 0x0205002b, 0x02040004,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c206,
	0x0205002b, 0x02040078, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f102, 0x0205002b, 0x02040000,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f103,
	0x0205002b, 0x02040000, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f104, 0x0205002b, 0x020400f4,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f105,
	0x0205002b, 0x02040003, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f109, 0x0205002b, 0x020400e0,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f10a,
	0x0205002b, 0x0204000b, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f10b, 0x0205002b, 0x0204004c,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f10b,
	0x0205002b, 0x0204005c, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f102, 0x0205002b, 0x02040000,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f103,
	0x0205002b, 0x02040000, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f104, 0x0205002b, 0x020400f4,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f105,
	0x0205002b, 0x02040004, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f109, 0x0205002b, 0x02040065,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f10a,
	0x0205002b, 0x0204000b, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f10b, 0x0205002b, 0x0204004c,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f10b,
	0x0205002b, 0x0204005c, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204e706, 0x0205002b, 0x0204000f,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204e707,
	0x0205002b, 0x02040030, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204e806, 0x0205002b, 0x0204000f,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204e807,
	0x0205002b, 0x02040030, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204ce04, 0x0205002b, 0x02040002,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204ce05,
	0x0205002b, 0x02040087, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204ce06, 0x0205002b, 0x020400a2,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204ce07,
	0x0205002b, 0x0204006c, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204cf04, 0x0205002b, 0x02040002,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204cf05,
	0x0205002b, 0x02040087, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204cf06, 0x0205002b, 0x020400a2,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204cf07,
	0x0205002b, 0x0204006c, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204ce60, 0x0205002b, 0x020400e3,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204c130,
	0x0205002b, 0x02040051, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204e000, 0x0205002b, 0x020400a8,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f102,
	0x0205002b, 0x02040000, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f103, 0x0205002b, 0x02040000,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f104,
	0x0205002b, 0x020400f5, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f105, 0x0205002b, 0x02040023,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f109,
	0x0205002b, 0x02040004, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f10a, 0x0205002b, 0x0204000b,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f10b,
	0x0205002b, 0x0204004c, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f10b, 0x0205002b, 0x0204005c,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02044100, 0x02050029, 0x02041888,
	0x0205002b, 0x02040000, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204c121, 0x0205002b, 0x0204000b,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f102,
	0x0205002b, 0x02040000, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f103, 0x0205002b, 0x02040000,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f104,
	0x0205002b, 0x020400f5, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f105, 0x0205002b, 0x02040023,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f109,
	0x0205002b, 0x02040000, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f10a, 0x0205002b, 0x0204000b,
	0x0205002c, 0x0204b423, 0x02050027, 0x02040010,
	0x02050028, 0x02040000, 0x02050029, 0x0204f10b,
	0x0205002b, 0x0204004c, 0x0205002c, 0x0204b423,
	0x02050027, 0x02040010, 0x02050028, 0x02040000,
	0x02050029, 0x0204f10b, 0x0205002b, 0x0204005c,
	0x0205002c, 0x0204b423,

	// XXX: Duplicate last 2 u32s to keep in 4-dword blocks
	0x0205002c, 0x0204b423,
};

const u32 pc_beep_verbs[] = {};

AZALIA_ARRAY_SIZES;
