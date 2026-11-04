#include "code_0200fc8c.h"

#include "Main/Unknown/code_0200f000.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "code_0214d5b8.h"

u16 data_02170280;
u16 data_0217027c;

void func_0200fe58(void *p) {
    MemCopy((void *) 0x27ffcf4, p, 6);
}

void func_0200fddc(Unk0200fddc *p) {
    u8 *s;

    s = (u8 *) 0x27ffc80;
    p->mUnk_00 = (u32) (*(u16 *) (s + 0x64) << 29) >> 29;
    p->mUnk_01 = (u32) (s[2] << 28) >> 28;
    p->mUnk_02 = s[3];
    p->mUnk_03 = s[4];
    p->mUnk_18 = s[0x1a];
    p->mUnk_4e = s[0x50];
    MemCopyHalfwords(s + 6, p->mUnk_04, 0x14);
    MemCopyHalfwords(s + 0x1c, p->mUnk_1a, 0x34);
}

void func_0200fd74(void) {
    if (data_0217027c != 0) {
        return;
    }
    data_0217027c = 1;
    PxiInit();
    while (PxiCallbackBitIsSet(0xc, 1) == 0) {
    }
    PxiCallbackSet(0xc, func_0200fd30);
}

void func_0200fd30(u32 a, u32 b) {
    if (((b & 0x7f00) << 8) >> 16 == 0x10) {
        data_02170280 = 1;
        return;
    }
    IrqDisableLoopForever();
}

void IrqDisableLoopForever(void) {
    while (1) {
        IrqDisable();
        func_0200fd04();
    }
}

// clang-format off
// Clears the interrupt disable bit (0x80) of the status register and returns its previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm u32 IrqEnable(void) {
    mrs r0, cpsr
    bic r1, r0, #0x80
    msr cpsr_c, r1
    and r0, r0, #0x80
    bx lr
}

// Sets the interrupt disable bit (0x80) of the status register and returns its previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm u32 IrqDisable(void) {
    mrs r0, cpsr
    orr r1, r0, #0x80
    msr cpsr_c, r1
    and r0, r0, #0x80
    bx lr
}

// Replaces the interrupt disable bit (0x80) of the status register with the one in r0 and returns the previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm u32 IrqRestore(u32 a) {
    mrs r1, cpsr
    bic r2, r1, #0x80
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #0x80
    bx lr
}

// Sets the bits 0xc0 of the status register and returns their previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm u32 func_0200fccc(void) {
    mrs r0, cpsr
    orr r1, r0, #0xc0
    msr cpsr_c, r1
    and r0, r0, #0xc0
    bx lr
}

// Replaces the bits 0xc0 of the status register with those in r0 and returns their previous value.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm u32 func_0200fce0(u32 a) {
    mrs r1, cpsr
    bic r2, r1, #0xc0
    orr r2, r2, r0
    msr cpsr_c, r2
    and r0, r1, #0xc0
    bx lr
}

// Returns the low five bits of the status register.
// Not compiled code: C has no way to read or write the status register (mrs/msr).
asm u32 ProcessorModeGet(void) {
    mrs r0, cpsr
    and r0, r0, #0x1f
    bx lr
}

// Writes zero to a coprocessor 15 register.
// Not compiled code: C has no way to read or write a coprocessor 15 register (mrc/mcr).
asm void func_0200fd04(void) {
    mov r0, #0x0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}

// Subtracts 4 from r0 until a subtraction borrows (a wait of about r0 / 4 loops).
// Not compiled code: `subs` followed by a carry test (bhs), which 1.2 never builds (docs/compiler.md).
asm void func_0200fd10(u32 a) {
loop:
    subs r0, r0, #0x4
    bhs loop
    bx lr
}
// clang-format on
