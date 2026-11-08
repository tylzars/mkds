#include "code_0200fc8c.h"

#include "Main/Unknown/code_0200f000.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "code_0214d5b8.h"

u16 data_02170280;
u16 data_0217027c;

// Copies the 6-byte MAC address from the fixed system block into macAddress.
void OS_GetMacAddress(void *macAddress) {
    MI_CpuCopy8((void *) 0x27ffcf4, macAddress, 6);
}

// Fills info from the owner data block in the system area.
void OS_GetOwnerInfo(Unk0200fddc *info) {
    u8 *source;

    source = (u8 *) 0x27ffc80;
    info->mUnk_00 = (u32) (*OFFSET_PTR(u16, source, 0x64) << 29) >> 29;
    info->mUnk_01 = (u32) (source[2] << 28) >> 28;
    info->mUnk_02 = source[3];
    info->mUnk_03 = source[4];
    info->mUnk_18 = source[0x1a];
    info->mUnk_4e = source[0x50];
    MIi_CpuCopy16(source + 6, info->mUnk_04, 0x14);
    MIi_CpuCopy16(source + 0x1c, info->mUnk_1a, 0x34);
}

// Opens the reset channel once and installs OSi_CommonCallback on it.
void OS_InitReset(void) {
    if (data_0217027c != 0) {
        return;
    }
    data_0217027c = 1;
    PXI_Init();
    while (PXI_IsCallbackReady(0xc, 1) == 0) {
    }
    PXI_SetFifoRecvCallback(0xc, OSi_CommonCallback);
}

// Handles reset-channel commands: command 0x10 sets the flag, any other command terminates.
void OSi_CommonCallback(u32 tag, u32 data) {
    if (((data & 0x7f00) << 8) >> 16 == 0x10) {
        data_02170280 = 1;
        return;
    }
    OS_Terminate();
}

// Disables interrupts and halts forever.
void OS_Terminate(void) {
    while (1) {
        OS_DisableInterrupts();
        OS_Halt();
    }
}

// clang-format off
// Clears the interrupt disable bit (0x80) of the status register and returns its previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode OS_EnableInterrupts(void) {
    mrs r0, cpsr
    bic r1, r0, #0x80
    msr cpsr_c, r1
    and r0, r0, #0x80
    bx lr
}

// Sets the interrupt disable bit (0x80) of the status register and returns its previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode OS_DisableInterrupts(void) {
    mrs r0, cpsr
    orr r1, r0, #0x80
    msr cpsr_c, r1
    and r0, r0, #0x80
    bx lr
}

// Replaces the interrupt disable bit (0x80) of the status register with the one in r0 and returns the previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode OS_RestoreInterrupts(OSIntrMode state) {
    mrs r1, cpsr
    bic r2, r1, #0x80
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #0x80
    bx lr
}

// Sets the bits 0xc0 of the status register and returns their previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode OS_DisableInterrupts_IrqAndFiq(void) {
    mrs r0, cpsr
    orr r1, r0, #0xc0
    msr cpsr_c, r1
    and r0, r0, #0xc0
    bx lr
}

// Replaces the bits 0xc0 of the status register with those in r0 and returns their previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state) {
    mrs r1, cpsr
    bic r2, r1, #0xc0
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #0xc0
    bx lr
}

// Returns the low five bits of the status register.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm u32 OS_GetProcMode(void) {
    mrs r0, cpsr
    and r0, r0, #0x1f
    bx lr
}

// Writes zero to a coprocessor 15 register.
// Not compiled code: C has no way to read or write a coprocessor 15 register (mrc/mcr).
asm void OS_Halt(void) {
    mov r0, #0x0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}

// Subtracts 4 from r0 until a subtraction borrows (a wait of about r0 / 4 loops).
// Not compiled code: `subs` followed by a carry test (bhs), which 1.2 never builds (docs/compiler.md).
asm void OS_SpinWait(u32 cycle) {
loop:
    subs r0, r0, #0x4
    bhs loop
    bx lr
}
// clang-format on
