#------------------------------------------------------------------------------
#
# Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>
# This program and the accompanying materials
# are licensed and made available under the terms and conditions of the BSD License
# which accompanies this distribution.  The full text of the license may be found at
# http://opensource.org/licenses/bsd-license.php.
#
# THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
# Module Name:
#
#   AsmVmPtrStore.s
#
#------------------------------------------------------------------------------

ASM_GLOBAL ASM_PFX(AsmVmPtrStore)
ASM_PFX(AsmVmPtrStore):
    movq   %rcx, %rax
    .byte  0x0f, 0xc7, 0x38           # VMPTST [rax]
    pushfq
    pop    %rax
    ret
