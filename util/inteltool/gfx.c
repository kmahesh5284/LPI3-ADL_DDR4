/* inteltool - dump all registers on an Intel CPU + chipset based system */
/* SPDX-License-Identifier: GPL-2.0-only */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "inteltool.h"

#define MMIO_SIZE 0x100000

int print_gfx(struct pci_dev *gfx)
{
	uint64_t mmio_phys;
	uint8_t *mmio;
	uint32_t i;
	if (!gfx) {
		printf ("No IGD found\n");
		return 0;
	}
	printf("\n============= IGD ==============\n\n");
	mmio_phys = gfx->base_addr[0] & ~0x7ULL;
	printf("IGD MMIO = 0x%08llx (MEM)\n\n", (unsigned long long)mmio_phys);
	mmio = map_physical(mmio_phys, MMIO_SIZE);
	if (mmio == NULL) {
		perror("Error mapping MMIO");
		exit(1);
	}
	for (i = 0; i < MMIO_SIZE; i += 4) {
		if (read32(mmio + i))
			printf("0x%06x: 0x%08x\n", i, read32(mmio + i));
	}
	unmap_physical((void *)mmio, MMIO_SIZE);
	return 0;

}
