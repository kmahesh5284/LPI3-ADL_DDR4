/* Copyright 2021 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Battery pack vendor provided charging profile
 */

#include "battery.h"
#include "battery_fuel_gauge.h"
#include "charge_state.h"
#include "common.h"
#include "util.h"

/*
 * Battery info for all waddledoo battery types. Note that the fields
 * start_charging_min/max and charging_min/max are not used for the charger.
 * The effective temperature limits are given by discharging_min/max_c.
 *
 * Fuel Gauge (FG) parameters which are used for determining if the battery
 * is connected, the appropriate ship mode (battery cutoff) command, and the
 * charge/discharge FETs status.
 *
 * Ship mode (battery cutoff) requires 2 writes to the appropriate smart battery
 * register. For some batteries, the charge/discharge FET bits are set when
 * charging/discharging is active, in other types, these bits set mean that
 * charging/discharging is disabled. Therefore, in addition to the mask for
 * these bits, a disconnect value must be specified. Note that for TI fuel
 * gauge, the charge/discharge FET status is found in Operation Status (0x54),
 * but a read of Manufacturer Access (0x00) will return the lower 16 bits of
 * Operation status which contains the FET status bits.
 *
 * The assumption for battery types supported is that the charge/discharge FET
 * status can be read with a sb_read() command and therefore, only the register
 * address, mask, and disconnect value need to be provided.
 */
const struct board_batt_params board_battery_info[] = {
	/* C21N2018 Battery Information*/
	 [BATTERY_C21N2018] = {
		.fuel_gauge = {
			.manuf_name = "AS3GXXD3KA",
			.device_name = "C110160",
			.ship_mode = {
				.reg_addr = 0x00,
				.reg_data = { 0x0010, 0x0010 },
			},
			.fet = {
				.reg_addr = 0x0,
				.reg_mask = 0x2000,
				.disconnect_val = 0x2000,
				.cfet_mask = 0x4000,
				.cfet_off_val = 0x4000,
			},
		},
		.batt_info = {
			.voltage_max            = 8800,
			.voltage_normal         = 7890,
			.voltage_min            = 6000,
			.precharge_current      = 256,
			.start_charging_min_c   = 0,
			.start_charging_max_c   = 45,
			.charging_min_c         = 0,
			.charging_max_c         = 60,
			.discharging_min_c      = -20,
			.discharging_max_c      = 60,
		},
	},
	/* C21N2018 second Battery Information*/
	[BATTERY_C21N2018_2ND] = {
		.fuel_gauge = {
			.manuf_name = "AS3FXXD3KA",
			.device_name = "C110160",
			.ship_mode = {
				.reg_addr = 0x00,
				.reg_data = { 0x0010, 0x0010 },
			},
			.fet = {
				.reg_addr = 0x0,
				.reg_mask = 0x2000,
				.disconnect_val = 0x2000,
				.cfet_mask = 0x4000,
				.cfet_off_val = 0x4000,
			},
		},
		.batt_info = {
			.voltage_max            = 8800,
			.voltage_normal         = 7890,
			.voltage_min            = 6000,
			.precharge_current      = 256,
			.start_charging_min_c   = 0,
			.start_charging_max_c   = 45,
			.charging_min_c         = 0,
			.charging_max_c         = 60,
			.discharging_min_c      = -20,
			.discharging_max_c      = 60,
		},
	},
};
BUILD_ASSERT(ARRAY_SIZE(board_battery_info) == BATTERY_TYPE_COUNT);

const enum battery_type DEFAULT_BATTERY_TYPE = BATTERY_C21N2018;
