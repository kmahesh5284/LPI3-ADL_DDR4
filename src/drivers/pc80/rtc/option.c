/* SPDX-License-Identifier: GPL-2.0-only */

#include <acpi/acpi.h>
#include <console/console.h>
#include <string.h>
#include <cbfs.h>
#include <option.h>
#include <pc80/mc146818rtc.h>
#include <types.h>

/* option_table.h is autogenerated */
#include "option_table.h"

/* Don't warn for checking >= LB_CKS_RANGE_START even though it may be 0. */
#pragma GCC diagnostic ignored "-Wtype-limits"

/*
 * This routine returns the value of the requested bits.
 * input bit = bit count from the beginning of the CMOS image
 * length = number of bits to include in the value
 * ret = a character pointer to where the value is to be returned
 * returns CB_SUCCESS = successful, cb_err code if an error occurred
 */
static enum cb_err get_cmos_value(unsigned long bit, unsigned long length,
				  void *vret)
{
	unsigned char *ret;
	unsigned long byte, byte_bit;
	unsigned long i;
	unsigned char uchar;

	/*
	 * The table is checked when it is built to ensure all
	 * values are valid.
	 */
	ret = vret;
	byte = bit / 8;	/* find the byte where the data starts */
	byte_bit = bit % 8; /* find the bit in the byte where the data starts */
	if (length < 9) {	/* one byte or less */
		uchar = cmos_read(byte); /* load the byte */
		uchar >>= byte_bit;	/* shift the bits to byte align */
		/* clear unspecified bits */
		ret[0] = uchar & ((1 << length) - 1);
	} else {	/* more than one byte so transfer the whole bytes */
		for (i = 0; length; i++, length -= 8, byte++) {
			/* load the byte */
			ret[i] = cmos_read(byte);
		}
	}
	return CB_SUCCESS;
}

static struct cmos_option_table *get_cmos_layout(void)
{
	static struct cmos_option_table *ct = NULL;

	/*
	 * In case VBOOT is enabled and this function is called from SMM,
	 * we have multiple CMOS layout files and to locate them we'd need to
	 * include VBOOT into SMM...
	 *
	 * Support only one CMOS layout in the RO CBFS for now.
	 */
	if (!ct)
		ct = cbfs_ro_map("cmos_layout.bin", NULL);
	if (!ct)
		printk(BIOS_ERR, "RTC: cmos_layout.bin could not be found. "
				 "Options are disabled\n");
	return ct;
}

static struct cmos_entries *find_cmos_entry(struct cmos_option_table *ct, const char *name)
{
	/* Figure out how long name is */
	const size_t namelen = strnlen(name, CMOS_MAX_NAME_LENGTH);
	struct cmos_entries *ce;

	/* Find the requested entry record */
	ce = (struct cmos_entries *)((unsigned char *)ct + ct->header_length);
	for (; ce->tag == LB_TAG_OPTION;
		ce = (struct cmos_entries *)((unsigned char *)ce + ce->size)) {
		if (memcmp(ce->name, name, namelen) == 0)
			return ce;
	}
	return NULL;
}

static enum cb_err cmos_get_uint_option(unsigned int *dest, const char *name)
{
	struct cmos_option_table *ct;
	struct cmos_entries *ce;

	ct = get_cmos_layout();
	if (!ct)
		return CB_CMOS_LAYOUT_NOT_FOUND;

	ce = find_cmos_entry(ct, name);
	if (!ce) {
		printk(BIOS_DEBUG, "No CMOS option '%s'.\n", name);
		return CB_CMOS_OPTION_NOT_FOUND;
	}

	if (ce->config != 'e' && ce->config != 'h') {
		printk(BIOS_ERR, "CMOS option '%s' is not of integer type.\n", name);
		return CB_ERR_ARG;
	}

	if (!cmos_checksum_valid(LB_CKS_RANGE_START, LB_CKS_RANGE_END, LB_CKS_LOC))
		return CB_CMOS_CHECKSUM_INVALID;

	if (get_cmos_value(ce->bit, ce->length, dest) != CB_SUCCESS)
		return CB_CMOS_ACCESS_ERROR;

	return CB_SUCCESS;
}

unsigned int get_uint_option(const char *name, const unsigned int fallback)
{
	unsigned int value = 0;
	return cmos_get_uint_option(&value, name) == CB_SUCCESS ? value : fallback;
}

static enum cb_err set_cmos_value(unsigned long bit, unsigned long length,
				  void *vret)
{
	unsigned char *ret;
	unsigned long byte, byte_bit;
	unsigned long i;
	unsigned char uchar, mask;
	unsigned int chksum_update_needed = 0;

	ret = vret;
	byte = bit / 8;		/* find the byte where the data starts */
	byte_bit = bit % 8;	/* find the bit where the data starts */
	if (length <= 8) {	/* one byte or less */
		mask = (1 << length) - 1;
		mask <<= byte_bit;

		uchar = cmos_read(byte);
		uchar &= ~mask;
		uchar |= (ret[0] << byte_bit);
		cmos_write(uchar, byte);
		if (byte >= LB_CKS_RANGE_START && byte <= LB_CKS_RANGE_END)
			chksum_update_needed = 1;
	} else { /* more that one byte so transfer the whole bytes */
		if (byte_bit || length % 8)
			return CB_ERR_ARG;

		for (i = 0; length; i++, length -= 8, byte++) {
			cmos_write(ret[i], byte);
			if (byte >= LB_CKS_RANGE_START &&
			    byte <= LB_CKS_RANGE_END)
				chksum_update_needed = 1;
		}
	}

	if (chksum_update_needed) {
		cmos_set_checksum(LB_CKS_RANGE_START, LB_CKS_RANGE_END,
				  LB_CKS_LOC);
	}
	return CB_SUCCESS;
}

static enum cb_err cmos_set_uint_option(const char *name, unsigned int *value)
{
	struct cmos_option_table *ct;
	struct cmos_entries *ce;

	ct = get_cmos_layout();
	if (!ct)
		return CB_CMOS_LAYOUT_NOT_FOUND;

	ce = find_cmos_entry(ct, name);
	if (!ce) {
		printk(BIOS_DEBUG, "WARNING: No CMOS option '%s'.\n", name);
		return CB_CMOS_OPTION_NOT_FOUND;
	}

	if (ce->config != 'e' && ce->config != 'h') {
		printk(BIOS_ERR, "CMOS option '%s' is not of integer type.\n", name);
		return CB_ERR_ARG;
	}

	if (set_cmos_value(ce->bit, ce->length, value) != CB_SUCCESS)
		return CB_CMOS_ACCESS_ERROR;

	return CB_SUCCESS;
}

enum cb_err set_uint_option(const char *name, unsigned int value)
{
	return cmos_set_uint_option(name, &value);
}

int cmos_lb_cks_valid(void)
{
	return cmos_checksum_valid(LB_CKS_RANGE_START, LB_CKS_RANGE_END, LB_CKS_LOC);
}

void sanitize_cmos(void)
{
	const unsigned char *cmos_default;
	const bool cmos_need_reset =
		(CONFIG(STATIC_OPTION_TABLE) || cmos_error() || !cmos_lb_cks_valid())
		&& !acpi_is_wakeup_s3();
	size_t length = 128;
	size_t i;

	if (CONFIG(TPM_MEASURED_BOOT) || cmos_need_reset) {
		cmos_default = cbfs_map("cmos.default", &length);

		if (!cmos_default || !cmos_need_reset)
			return;

		u8 control_state = cmos_disable_rtc();
		/* Max length of 256 spans bank 0 and bank 1 */
		for (i = 14; i < MIN(256, length); i++)
			cmos_write_inner(cmos_default[i], i);
		cmos_restore_rtc(control_state);
	}
}
