/* SPDX-License-Identifier: GPL-2.0-only */

// GPP_C19 SCI
Method (_L13, 0, Serialized) {
	Printf ("GPE _L13: %o", ToHexString(\_SB.PCI0.LPCB.EC0.WFNO))
	If (\_SB.PCI0.LPCB.EC0.ECOK) {
		If (\_SB.PCI0.LPCB.EC0.WFNO == 1) {
			Notify(\_SB.LID0, 0x80)
		}
	}
}
