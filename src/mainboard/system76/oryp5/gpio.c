/* SPDX-License-Identifier: GPL-2.0-only */

#include <mainboard/gpio.h>
#include <soc/gpe.h>
#include <soc/gpio.h>

static const struct pad_config gpio_table[] = {
	/* ------- GPIO Group GPD ------- */
	PAD_CFG_NF(GPD0, NONE, DEEP, NF1), // PM_BATLOW#
	PAD_CFG_NF(GPD1, NATIVE, DEEP, NF1), // AC_PRESENT
	PAD_CFG_GPI(GPD2, NATIVE, PWROK), // LAN_WAKEUP#
	PAD_CFG_NF(GPD3, UP_20K, DEEP, NF1), // PWR_BTN#
	PAD_CFG_NF(GPD4, NONE, DEEP, NF1), // SUSB#_PCH
	PAD_CFG_NF(GPD5, NONE, DEEP, NF1), // SUSC#_PCH
	PAD_NC(GPD6, NONE),
	PAD_CFG_GPI(GPD7, UP_20K, PWROK), /* GPD_7 (crystal input
					     low = single ended,
					     high = differential)
					   */
	PAD_CFG_NF(GPD8, NONE, DEEP, NF1), // PCH_SUSCLK
	PAD_NC(GPD9, NONE),
	PAD_NC(GPD10, NONE),
	PAD_CFG_GPO(GPD11, 1, DEEP), // LAN_DISABLE#

	/* ------- GPIO Group GPP_A ------- */
	PAD_CFG_NF(GPP_A0, NONE, DEEP, NF1), // SB_KBCRST#
	PAD_CFG_NF(GPP_A1, NONE, DEEP, NF1), // LPC_AD0
	PAD_CFG_NF(GPP_A2, NONE, DEEP, NF1), // LPC_AD1
	PAD_CFG_NF(GPP_A3, NONE, DEEP, NF1), // LPC_AD2
	PAD_CFG_NF(GPP_A4, NONE, DEEP, NF1), // LPC_AD3
	PAD_CFG_NF(GPP_A5, NONE, DEEP, NF1), // LPC_FRAME#
	PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1), // SERIRQ
	PAD_CFG_NF(GPP_A7, NONE, DEEP, NF1), // LPC_PIRQA#
	PAD_CFG_NF(GPP_A8, NONE, DEEP, NF1), // PM_CLKRUN#
	PAD_CFG_NF(GPP_A9, NONE, DEEP, NF1), // PCLK_KBC
	PAD_NC(GPP_A10, NONE),
	PAD_CFG_GPI_APIC_HIGH(GPP_A11, NONE, PLTRST), // INTP_OUT
	PAD_NC(GPP_A12, NONE),
	PAD_NC(GPP_A13, NONE), // SUSWARN# (test point)
	PAD_NC(GPP_A14, NONE), // (test point)
	PAD_NC(GPP_A15, NONE), // SUS_PWR_ACK# (test point)
	PAD_NC(GPP_A16, NONE),
	PAD_NC(GPP_A17, NONE),
	PAD_NC(GPP_A18, NONE),
	PAD_CFG_GPO(GPP_A19, 1, DEEP), // SB_BLON
	PAD_CFG_GPI(GPP_A20, NONE, DEEP), // PEX_WAKE#
	PAD_NC(GPP_A21, NONE),
	PAD_CFG_GPO(GPP_A22, 1, DEEP), // WLAN_SSD2_GPIO1
	PAD_CFG_GPO(GPP_A23, 1, DEEP), // WLAN_SSD2_GPIO

	/* ------- GPIO Group GPP_B ------- */
	PAD_CFG_GPI(GPP_B0, UP_20K, DEEP), // TPM_PIRQ#
	PAD_NC(GPP_B1, NONE),
	PAD_NC(GPP_B2, NONE),
	PAD_CFG_GPO(GPP_B3, 1, DEEP), // BT_RF_KILL_R_N
	PAD_CFG_GPO(GPP_B4, 1, DEEP), // WIFI_RF_KILL_R_N
	PAD_NC(GPP_B5, NONE),
	PAD_NC(GPP_B6, NONE),
	PAD_CFG_GPO(GPP_B7, 1, PLTRST), // CR_GPIO_RST#
	PAD_CFG_GPO(GPP_B8, 1, PLTRST), // CR_GPIO_WAKE#
	PAD_NC(GPP_B9, NONE),
	PAD_NC(GPP_B10, NONE),
	PAD_NC(GPP_B11, NONE),
	PAD_CFG_GPI(GPP_B12, UP_20K, DEEP), // SLP_S0#
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1), // PLT_RST#
	PAD_CFG_NF(GPP_B14, NONE, DEEP, NF1), // PCH_SPKR
	PAD_NC(GPP_B15, NONE),
	PAD_NC(GPP_B16, NONE),
	PAD_NC(GPP_B17, NONE),
	PAD_NC(GPP_B18, NONE), // LPSS_GSPI0_MOSI (test point)
	PAD_NC(GPP_B19, NONE),
	PAD_CFG_GPI_SMI(GPP_B20, NONE, DEEP, EDGE_SINGLE, NONE), // SMI#
	PAD_NC(GPP_B21, NONE),
	PAD_CFG_GPI(GPP_B22, UP_20K, DEEP), // LPSS_GSPI1_MOSI
	PAD_CFG_GPI_SCI_LOW(GPP_B23, UP_20K, PLTRST, LEVEL), // SCI#

	/* ------- GPIO Group GPP_C ------- */
	PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1), // SMB_CLK
	PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1), // SMB_DATA
	PAD_CFG_GPI(GPP_C2, UP_20K, DEEP), // GPP_C2_BT_UART_WAKE_N
	PAD_NC(GPP_C3, NONE),
	PAD_NC(GPP_C4, NONE),
	PAD_CFG_GPI(GPP_C5, UP_20K, DEEP), // M.2_WLAN_WIFI_WAKE_N
	PAD_CFG_GPI(GPP_C6, UP_20K, DEEP), // SMC_CPU_THERM
	PAD_CFG_GPI(GPP_C7, UP_20K, DEEP), // SMD_CPU_THERM
	PAD_CFG_GPI(GPP_C8, NONE, DEEP), // TPM_DET
	PAD_CFG_GPI(GPP_C9, DN_20K, DEEP), // BOARD_ID1
	PAD_CFG_GPI(GPP_C10, DN_20K, DEEP), // BOARD_ID2
	PAD_CFG_GPI(GPP_C11, DN_20K, DEEP), // BOARD_ID3
	PAD_CFG_GPI(GPP_C12, NONE, DEEP), // GC6_FB_EN_PCH
	PAD_CFG_GPO(GPP_C13, 1, DEEP), // GPU_EVENT#
	PAD_CFG_GPO(GPP_C14, 1, DEEP), // M.2_PLT_RST_CNTRL1#
	PAD_CFG_GPO(GPP_C15, 1, DEEP), // M.2_PLT_RST_CNTRL2#
	PAD_CFG_NF(GPP_C16, NONE, PLTRST, NF1), // I2C_SDA_TP
	PAD_CFG_NF(GPP_C17, NONE, PLTRST, NF1), // I2C_SCL_TP
	PAD_CFG_NF(GPP_C18, NONE, PLTRST, NF1), // SMD_7411_I2C
	PAD_CFG_NF(GPP_C19, NONE, PLTRST, NF1), // SMC_7411_I2C
	//PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1), // UART2_RXD
	//PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1), // UART2_TXD
	PAD_CFG_NF(GPP_C22, UP_20K, DEEP, NF1), // UART2_RTS# / LAN_PLT_RST#
	PAD_CFG_NF(GPP_C23, UP_20K, DEEP, NF1), // BOARD_ID4

	/* ------- GPIO Group GPP_D ------- */
	PAD_NC(GPP_D0, NONE),
	PAD_NC(GPP_D1, NONE),
	PAD_NC(GPP_D2, NONE),
	PAD_NC(GPP_D3, NONE),
	PAD_NC(GPP_D4, NONE),
	PAD_CFG_NF(GPP_D5, NONE, DEEP, NF3), // M.2_BT_PCMFRM_CRF_RST_N
	PAD_CFG_NF(GPP_D6, NONE, DEEP, NF3), // M.2_BT_PCMOUT_CLKREQ0
	PAD_CFG_GPI(GPP_D7, UP_20K, DEEP), // M.2_BT_PCMIN
	PAD_CFG_GPI(GPP_D8, UP_20K, DEEP), // M.2_BT_PCMCLK
	PAD_NC(GPP_D9, NONE),
	PAD_NC(GPP_D10, NONE),
	PAD_NC(GPP_D11, NONE),
	PAD_NC(GPP_D12, NONE),
	PAD_NC(GPP_D13, NONE), // 10k pull up
	PAD_NC(GPP_D14, NONE), // 10k pull up
	PAD_NC(GPP_D15, NONE),
	PAD_NC(GPP_D16, NONE),
	PAD_NC(GPP_D17, NONE),
	PAD_NC(GPP_D18, NONE),
	PAD_NC(GPP_D19, NONE),
	PAD_NC(GPP_D20, NONE),
	PAD_NC(GPP_D21, NONE),
	PAD_NC(GPP_D22, NONE),
	PAD_NC(GPP_D23, NONE),

	/* ------- GPIO Group GPP_E ------- */
	PAD_NC(GPP_E0, NONE),
	PAD_CFG_NF(GPP_E1, NONE, DEEP, NF1), // SATAGP1 / M.2_SSD1_PEDET
	PAD_NC(GPP_E2, NONE),
	PAD_NC(GPP_E3, NONE),
	PAD_NC(GPP_E4, NONE),
	PAD_CFG_GPI(GPP_E5, UP_20K, DEEP), // M2_P0_SATA_DEVSLP
	PAD_NC(GPP_E6, NONE),
	PAD_CFG_GPI_APIC_EDGE_LOW(GPP_E7, NONE, PLTRST), // TP_ATTN#
	PAD_CFG_NF(GPP_E8, NONE, DEEP, NF1), // PCH_SATAHDD_LED#
	PAD_NC(GPP_E9, NONE), // USB_OC0# (test point)
	PAD_NC(GPP_E10, NONE), // USB_OC1# (test point)
	PAD_NC(GPP_E11, NONE), // USB_OC2# (test point)
	PAD_NC(GPP_E12, NONE), // USB_OC3# (test point)

	/* ------- GPIO Group GPP_F ------- */
	PAD_NC(GPP_F0, NONE),
	PAD_CFG_NF(GPP_F1, NONE, DEEP, NF1), // SATAGP4 / M.2_SSD2_PEDET
	PAD_NC(GPP_F2, NONE),
	PAD_NC(GPP_F3, NONE),
	PAD_NC(GPP_F4, NONE),
	PAD_NC(GPP_F5, NONE),
	PAD_CFG_NF(GPP_F6, NONE, DEEP, NF1), // M2_P4_SATA_DEVSLP
	PAD_NC(GPP_F7, NONE),
	PAD_NC(GPP_F8, NONE),
	PAD_NC(GPP_F9, NONE),
	PAD_CFG_GPI(GPP_F10, UP_20K, DEEP), // BIOS_REC
	PAD_CFG_GPI(GPP_F11, UP_20K, DEEP), // GPP_F11
	PAD_NC(GPP_F12, NONE),
	PAD_CFG_GPI(GPP_F13, UP_20K, DEEP), // GP39_GFX_CRB_DETECT
	PAD_CFG_GPI(GPP_F14, UP_20K, DEEP), // H_SKTOCC_N
	PAD_NC(GPP_F15, NONE), // USB_OC4# (test point)
	PAD_NC(GPP_F16, NONE),
	PAD_NC(GPP_F17, NONE),
	PAD_NC(GPP_F18, NONE), // USB_OC7# (test point)
	PAD_CFG_NF(GPP_F19, NONE, DEEP, NF1), // NB_ENAVDD
	PAD_CFG_NF(GPP_F20, NONE, DEEP, NF1), // BLON
	PAD_CFG_NF(GPP_F21, NONE, DEEP, NF1), // EDP_BRIGHTNESS
	// GPP_F22 (DGPU_RST#_PCH) configured in bootblock
	// GPP_F23 (DGPU_PWR_EN) configured in bootblock

	/* ------- GPIO Group GPP_G ------- */
	PAD_NC(GPP_G0, NONE),
	PAD_CFG_NF(GPP_G1, NONE, DEEP, NF1), // CNVI_WIGIG_DET#
	PAD_NC(GPP_G2, NONE),
	PAD_NC(GPP_G3, NONE),
	PAD_NC(GPP_G4, NONE),
	PAD_NC(GPP_G5, NONE),
	PAD_CFG_GPI_SCI_LOW(GPP_G6, NONE, DEEP, LEVEL), // SWI#
	PAD_NC(GPP_G7, NONE),

	/* ------- GPIO Group GPP_H ------- */
	PAD_NC(GPP_H0, NONE),
	PAD_NC(GPP_H1, NONE),
	PAD_CFG_NF(GPP_H2, NONE, DEEP, NF1), // CLK_REQ9_PEG#
	PAD_NC(GPP_H3, NONE),
	PAD_NC(GPP_H4, NONE),
	PAD_CFG_NF(GPP_H5, NONE, DEEP, NF1), // CLK_REQ12_SSD2#
	PAD_CFG_NF(GPP_H6, NONE, DEEP, NF1), // CLK_REQ13_SSD1#
	PAD_CFG_NF(GPP_H7, NONE, DEEP, NF1), // GPP_H_0_SRCCLKREQB_14
	PAD_CFG_NF(GPP_H8, NONE, DEEP, NF1), // CLK_REQ15_LAN#
	PAD_CFG_NF(GPP_H9, NONE, DEEP, NF1), // CLK_REQ16_CARD#
	PAD_NC(GPP_H10, NONE),
	PAD_NC(GPP_H11, NONE),
	PAD_NC(GPP_H12, NONE), // GPP_H_12 (test point)
	PAD_NC(GPP_H13, NONE),
	PAD_NC(GPP_H14, NONE),
	PAD_NC(GPP_H15, NONE), // GPP_H15 (reserved)
	PAD_NC(GPP_H16, NONE),
	PAD_NC(GPP_H17, NONE),
	PAD_NC(GPP_H18, NONE),
	PAD_CFG_GPI(GPP_H19, UP_20K, DEEP), // GPIO_CARD1
	PAD_CFG_GPI(GPP_H20, UP_20K, DEEP), // GPIO_CARD
	PAD_CFG_GPI(GPP_H21, DN_20K, DEEP), // 4.7k pull up, 20k pull down
	PAD_NC(GPP_H22, NONE),
	PAD_NC(GPP_H23, NONE),

	/* ------- GPIO Group GPP_I ------- */
	PAD_CFG_GPI_SCI_LOW(GPP_I0, NONE, DEEP, EDGE_BOTH), // G_DP_DHPD_A
	PAD_CFG_GPI_SCI_LOW(GPP_I1, NONE, DEEP, EDGE_BOTH), // HDMI_HPD
	PAD_CFG_GPI_SCI_LOW(GPP_I2, NONE, DEEP, EDGE_BOTH), // G_DP_DHPD_E
	PAD_NC(GPP_I3, NONE),
	PAD_CFG_NF(GPP_I4, NONE, DEEP, NF1), // EDP_HDP
	PAD_NC(GPP_I5, NONE),
	PAD_NC(GPP_I6, NONE),
	PAD_NC(GPP_I7, NONE),
	PAD_NC(GPP_I8, NONE),
	PAD_NC(GPP_I9, NONE),
	PAD_NC(GPP_I10, NONE),
	PAD_CFG_GPI(GPP_I11, UP_20K, DEEP), // H_SKTOCC_N
	PAD_CFG_GPO(GPP_I12, 1, DEEP), // SATA_PWR_EN
	PAD_NC(GPP_I13, NONE),
	PAD_NC(GPP_I14, NONE),

	/* ------- GPIO Group GPP_J ------- */
	PAD_CFG_NF(GPP_J0, NONE, DEEP, NF1), // CNVI_GNSS_PA_BLANKING
	PAD_CFG_GPO(GPP_J1, 1, DEEP), // GPP_J1
	PAD_NC(GPP_J2, NONE),
	PAD_NC(GPP_J3, NONE),
	PAD_CFG_NF(GPP_J4, NONE, DEEP, NF1), // M.2_CNV_VRI_DT_BT_UART0_RTS
	PAD_CFG_NF(GPP_J5, UP_20K, DEEP, NF1), // M.2_CNV_BRI_RSP
	PAD_CFG_NF(GPP_J6, NONE, DEEP, NF1), // M.2_CNV_RGI_DT_BT_UART0_TX
	PAD_CFG_NF(GPP_J7, UP_20K, DEEP, NF1), // M.2_CNV_RGI_RSP
	PAD_NC(GPP_J8, NONE),
	PAD_CFG_GPI(GPP_J9, UP_20K, DEEP), // CNVI_MFUART2_TXD
	PAD_NC(GPP_J10, NONE),
	PAD_NC(GPP_J11, NONE),

	/* ------- GPIO Group GPP_K ------- */
	PAD_NC(GPP_K0, NONE),
	PAD_NC(GPP_K1, NONE),
	PAD_NC(GPP_K2, NONE),
	PAD_NC(GPP_K3, NONE),
	PAD_NC(GPP_K4, NONE),
	PAD_NC(GPP_K5, NONE),
	PAD_NC(GPP_K6, NONE),
	PAD_NC(GPP_K7, NONE),
	PAD_CFG_GPO(GPP_K8, 1, DEEP), // SATA_M2_PWR_EN1
	PAD_CFG_GPO(GPP_K9, 1, DEEP), // SATA_M2_PWR_EN2
	PAD_NC(GPP_K10, NONE),
	PAD_NC(GPP_K11, NONE),
	PAD_NC(GPP_K12, NONE),
	PAD_NC(GPP_K13, NONE),
	PAD_CFG_GPO(GPP_K14, 0, DEEP), // GPP_K_14_GSXDIN (test point), 7411_TEST_R
	PAD_NC(GPP_K15, NONE),
	PAD_NC(GPP_K16, NONE),
	PAD_NC(GPP_K17, NONE),
	PAD_NC(GPP_K18, NONE),
	PAD_NC(GPP_K19, NONE),
	PAD_NC(GPP_K20, NONE),
	PAD_NC(GPP_K21, NONE),
	PAD_NC(GPP_K22, NONE),
	PAD_NC(GPP_K23, NONE),
};

void mainboard_configure_gpios(void)
{
	gpio_configure_pads(gpio_table, ARRAY_SIZE(gpio_table));
}