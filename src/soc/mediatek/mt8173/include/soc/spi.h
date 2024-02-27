/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef MTK_MT8173_SPI_H
#define MTK_MT8173_SPI_H

#include <soc/spi_common.h>

#define SPI_BUS_NUMBER 1

#define GET_SCK_REG(x) x->spi_cfg0_reg
#define GET_TICK_DLY_REG(x) x->spi_cfg1_reg

DEFINE_BITFIELD(SPI_CFG_SCK_HIGH, 7, 0)
DEFINE_BITFIELD(SPI_CFG_SCK_LOW, 15, 8)
DEFINE_BITFIELD(SPI_CFG_CS_HOLD, 23, 16)
DEFINE_BITFIELD(SPI_CFG_CS_SETUP, 31, 24)

DEFINE_BITFIELD(SPI_CFG1_CS_IDLE, 7, 0)
DEFINE_BITFIELD(SPI_CFG1_PACKET_LOOP, 15, 8)
DEFINE_BITFIELD(SPI_CFG1_PACKET_LENGTH, 28, 16)
DEFINE_BITFIELD(SPI_TICK_DLY, 31, 29)

#endif