/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <baseboard/gpio.h>
#include <baseboard/variants.h>

/* Pad configuration in ramstage */
static const struct pad_config override_gpio_table[] = {
	/* B4  : H1_PCH_INT_ODL ==> TPM_AP_INT_ODL */
	/* C12 : AP_PEN_DET_ODL  ==> NC */
	PAD_NC(GPP_C12, UP_20K),
	/* C18 : AP_I2C_EMR_SDA */
	PAD_NC(GPP_C18, NONE),
	/* C19 : AP_I2C_EMR_SCL */
	PAD_NC(GPP_C19, NONE),
	/* C22 : UART2_RTS_N ==> NC */
	PAD_NC(GPP_C22, UP_20K),
	/* D12 : WCAM_RST_L ==> NC */
	PAD_NC(GPP_D12, NONE),
	/* D14 : EN_PP1200_CAMERA ==> NC */
	PAD_NC(GPP_D14, NONE),
	/* D15 : UCAM_RST_L ==> NC */
	PAD_NC(GPP_D15, NONE),
	/* D18 : I2S_MCLK ==> NC */
	PAD_NC(GPP_D18, NONE),
	/* D19 : WWAN_WLAN_COEX1 ==> NC */
	PAD_NC(GPP_D19, NONE),
	/* D20 : WWAN_WLAN_COEX2 ==> NC */
	PAD_NC(GPP_D20, NONE),
	/* D21 : WWAN_WLAN_COEX3 ==> NC */
	PAD_NC(GPP_D21, NONE),
	/* E0  : CLK_24M_UCAM ==> NC */
	PAD_NC(GPP_E0, NONE),
	/* E2  : CLK_24M_WCAM ==> NC */
	PAD_NC(GPP_E2, NONE),
	/* E17 : HDMI_DDC_SCL ==> NC */
	PAD_NC(GPP_E17, NONE),
	/* H1  : EN_PP3300_SD_U ==> NC */
	PAD_NC(GPP_H1, NONE),
	/* H6  : AP_I2C_CAM_SDA ==> NC */
	PAD_NC(GPP_H6, NONE),
	/* H7  : AP_I2C_CAM_SCL ==> NC */
	PAD_NC(GPP_H7, NONE),
	/* H16 : AP_SUB_IO_L ==> HP_RST_ODL */
	PAD_CFG_GPO(GPP_H16, 1, PWROK),
	/* G0  : SD_CMD ==> NC */
	PAD_NC(GPP_G0, NONE),
	/* G1  : SD_DATA0 ==> NC */
	PAD_NC(GPP_G1, NONE),
	/* G2  : SD_DATA1 ==> NC */
	PAD_NC(GPP_G2, NONE),
	/* G3  : SD_DATA2 ==> NC */
	PAD_NC(GPP_G3, NONE),
	/* G4  : SD_DATA3 ==> NC */
	PAD_NC(GPP_G4, NONE),
	/* G5  : SD_CD_ODL ==> NC */
	PAD_NC(GPP_G5, UP_20K),
	/* G6  : SD_CLK ==> NC */
	PAD_NC(GPP_G6, NONE),
	/* G7  : SD_SDIO_WP ==> NC */
	PAD_NC(GPP_G7, NONE),
	/* S2  : DMIC1_CLK ==> NC */
	PAD_NC(GPP_S2, NONE),
	/* S3  : DMIC1_DATA ==> NC */
	PAD_NC(GPP_S3, NONE),
};

const struct pad_config *variant_override_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(override_gpio_table);
	return override_gpio_table;
}
