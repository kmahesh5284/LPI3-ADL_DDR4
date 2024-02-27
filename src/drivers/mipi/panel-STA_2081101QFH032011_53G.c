/* SPDX-License-Identifier: GPL-2.0-only */

#include <mipi/panel.h>

struct panel_serializable_data STA_QFH032011_53G = {
	.edid = {
		.ascii_string = "QFH032011-53G",
		.manufacturer_name = "STA",
		.panel_bits_per_color = 8,
		.panel_bits_per_pixel = 24,
		.mode = {
			.pixel_clock = 165731,
			.lvds_dual_channel = 0,
			.refresh = 60,
			.ha = 1200, .hbl = 210, .hso = 100, .hspw = 10,
			.va = 1920, .vbl = 39, .vso = 14, .vspw = 10,
			.phsync = '-', .pvsync = '-',
			.x_mm = 135, .y_mm = 217,
		},
	},
	.init = {
		PANEL_DCS(0xB0, 0x01),
		PANEL_DCS(0xC3, 0x4F),
		PANEL_DCS(0xC4, 0x40),
		PANEL_DCS(0xC5, 0x40),
		PANEL_DCS(0xC6, 0x40),
		PANEL_DCS(0xC7, 0x40),
		PANEL_DCS(0xC8, 0x4D),
		PANEL_DCS(0xC9, 0x52),
		PANEL_DCS(0xCA, 0x51),
		PANEL_DCS(0xCD, 0x5D),
		PANEL_DCS(0xCE, 0x5B),
		PANEL_DCS(0xCF, 0x4B),
		PANEL_DCS(0xD0, 0x49),
		PANEL_DCS(0xD1, 0x47),
		PANEL_DCS(0xD2, 0x45),
		PANEL_DCS(0xD3, 0x41),
		PANEL_DCS(0xD7, 0x50),
		PANEL_DCS(0xD8, 0x40),
		PANEL_DCS(0xD9, 0x40),
		PANEL_DCS(0xDA, 0x40),
		PANEL_DCS(0xDB, 0x40),
		PANEL_DCS(0xDC, 0x4E),
		PANEL_DCS(0xDD, 0x52),
		PANEL_DCS(0xDE, 0x51),
		PANEL_DCS(0xE1, 0x5E),
		PANEL_DCS(0xE2, 0x5C),
		PANEL_DCS(0xE3, 0x4C),
		PANEL_DCS(0xE4, 0x4A),
		PANEL_DCS(0xE5, 0x48),
		PANEL_DCS(0xE6, 0x46),
		PANEL_DCS(0xE7, 0x42),
		PANEL_DCS(0xB0, 0x03),
		PANEL_DCS(0xBE, 0x03),
		PANEL_DCS(0xCC, 0x44),
		PANEL_DCS(0xC8, 0x07),
		PANEL_DCS(0xC9, 0x05),
		PANEL_DCS(0xCA, 0x42),
		PANEL_DCS(0xCD, 0x3E),
		PANEL_DCS(0xCF, 0x60),
		PANEL_DCS(0xD2, 0x04),
		PANEL_DCS(0xD3, 0x04),
		PANEL_DCS(0xD4, 0x01),
		PANEL_DCS(0xD5, 0x00),
		PANEL_DCS(0xD6, 0x03),
		PANEL_DCS(0xD7, 0x04),
		PANEL_DCS(0xD9, 0x01),
		PANEL_DCS(0xDB, 0x01),
		PANEL_DCS(0xE4, 0xF0),
		PANEL_DCS(0xE5, 0x0A),
		PANEL_DCS(0xB0, 0x00),
		PANEL_DCS(0xCC, 0x08),
		PANEL_DCS(0xC2, 0x08),
		PANEL_DCS(0xC4, 0x10),
		PANEL_DCS(0xB0, 0x02),
		PANEL_DCS(0xC0, 0x00),
		PANEL_DCS(0xC1, 0x0A),
		PANEL_DCS(0xC2, 0x20),
		PANEL_DCS(0xC3, 0x24),
		PANEL_DCS(0xC4, 0x23),
		PANEL_DCS(0xC5, 0x29),
		PANEL_DCS(0xC6, 0x23),
		PANEL_DCS(0xC7, 0x1C),
		PANEL_DCS(0xC8, 0x19),
		PANEL_DCS(0xC9, 0x17),
		PANEL_DCS(0xCA, 0x17),
		PANEL_DCS(0xCB, 0x18),
		PANEL_DCS(0xCC, 0x1A),
		PANEL_DCS(0xCD, 0x1E),
		PANEL_DCS(0xCE, 0x20),
		PANEL_DCS(0xCF, 0x23),
		PANEL_DCS(0xD0, 0x07),
		PANEL_DCS(0xD1, 0x00),
		PANEL_DCS(0xD2, 0x00),
		PANEL_DCS(0xD3, 0x0A),
		PANEL_DCS(0xD4, 0x13),
		PANEL_DCS(0xD5, 0x1C),
		PANEL_DCS(0xD6, 0x1A),
		PANEL_DCS(0xD7, 0x13),
		PANEL_DCS(0xD8, 0x17),
		PANEL_DCS(0xD9, 0x1C),
		PANEL_DCS(0xDA, 0x19),
		PANEL_DCS(0xDB, 0x17),
		PANEL_DCS(0xDC, 0x17),
		PANEL_DCS(0xDD, 0x18),
		PANEL_DCS(0xDE, 0x1A),
		PANEL_DCS(0xDF, 0x1E),
		PANEL_DCS(0xE0, 0x20),
		PANEL_DCS(0xE1, 0x23),
		PANEL_DCS(0xE2, 0x07),
		PANEL_DCS(0X11),
		PANEL_DELAY(120),
		PANEL_DCS(0X29),
		PANEL_DELAY(50),
		PANEL_END,
	},
};
