/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __MAINBOARD_GOOGLE_NYAN_PMIC_H__
#define __MAINBOARD_GOOGLE_NYAN_PMIC_H__

enum {
	AS3722_SDO0 = 0,
	AS3722_SDO1,
	AS3722_SDO2,
	AS3722_SDO3,
	AS3722_SDO4,
	AS3722_SDO5,
	AS3722_SDO6,

	AS3722_LDO0 = 0x10,
	AS3722_LDO1,
	AS3722_LDO2,
	AS3722_LDO3,
	AS3722_LDO4,
	AS3722_LDO5,
	AS3722_LDO6,
	AS3722_LDO7,

	AS3722_LDO9 = 0x19,
	AS3722_LDO10,
	AS3722_LDO11,
};

void pmic_init(unsigned int bus);

#endif /* __MAINBOARD_GOOGLE_NYAN_PMIC_H__ */
