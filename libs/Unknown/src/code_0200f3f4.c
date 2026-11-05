#include "code_0200f3f4.h"

#include "code_0200f328.h"
#include "Main/Unknown/unk_02170000.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_0200f000.h"

UnkFunc *data_021701bc;
UnkFunc *data_021701c4;
u32 data_021701c0;
u8 data_021701c8[0x80];

void OS_InitException(void) {
    u32 v;
    Unk0200f4f0 *p;

    v = *(u32 *) 0x027ffd9c;
    if (v >= 0x2600000 && v < 0x2800000) {
        data_021701c4 = (UnkFunc *) v;
    } else {
        data_021701c4 = 0;
    }
    p = (Unk0200f4f0 *) 0x027e3000;
    if (data_021701c4 == 0 || (OS_GetConsoleType() & 0x40000000) == 0) {
        *(UnkFunc **) 0x027ffd9c = (UnkFunc *) func_0200f36c;
        p->mUnk_fdc = (UnkFunc *) func_0200f36c;
    }
    data_021701bc = 0;
}

// clang-format off
// Stores r0 and the registers saved at the address in ip into data_021701c8 (0x80 bytes), and the banked sp, lr and
// spsr of the mode in the saved status word.
// Not compiled code: it reads and writes the status registers (mrs/msr, spsr) and stores ip and r4-r11 as the
// caller left them; C has no way to do either.
asm void func_0200f3f4(u32 a) {
    ldr r1, =data_021701c8
    mrs r2, cpsr
    str r2, [r1, #0x74]
    str r0, [r1, #0x6c]
    ldr r0, [ip, #0x0]
    str r0, [r1, #0x4]
    ldr r0, [ip, #0x4]
    str r0, [r1, #0x8]
    ldr r0, [ip, #0x8]
    str r0, [r1, #0xc]
    ldr r0, [ip, #0xc]
    str r0, [r1, #0x10]
    ldr r2, [ip, #0x10]
    bic r2, r2, #0x1
    add r0, r1, #0x14
    stmia r0, {r4, r5, r6, r7, r8, r9, r10, r11}
    str ip, [r1, #0x70]
    ldr r0, [r2, #0x0]
    str r0, [r1, #0x64]
    ldr r3, [r2, #0x4]
    str r3, [r1, #0x0]
    ldr r0, [r2, #0x8]
    str r0, [r1, #0x34]
    ldr r0, [r2, #0xc]
    str r0, [r1, #0x40]
    mrs r0, cpsr
    orr r3, r3, #0x80
    bic r3, r3, #0x20
    msr cpsr_fsxc, r3
    str sp, [r1, #0x38]
    str lr, [r1, #0x3c]
    mrs r2, spsr
    str r2, [r1, #0x7c]
    msr cpsr_fsxc, r0
    bx lr
}

// Does nothing while data_021701bc is zero; otherwise switches to mode 0x9f with the current sp, sets bit 0 of
// coprocessor 15 register c1, calls the function in data_021701bc with data_021701c8 and the word data_021701c0, and
// clears the bit again.
// Not compiled code: it switches the processor mode with msr, which C has no way to do.
asm void func_0200f484(void) {
    stmdb sp!, {lr}
    sub sp, sp, #0x4
    ldr r0, =data_021701bc
    ldr r0, [r0, #0x0]
    cmp r0, #0x0
    addeq sp, sp, #0x4
    ldmeqia sp!, {lr}
    bxeq lr
    mov r0, sp
    ldr r1, =0x9f
    msr cpsr_fsxc, r1
    mov sp, r0
    bl OS_EnableProtectionUnit
    ldr r1, =data_021701c0
    ldr r0, =data_021701bc
    ldr r1, [r1, #0x0]
    ldr r2, [r0, #0x0]
    ldr r0, =data_021701c8
    blx r2
    bl OS_DisableProtectionUnit
    add sp, sp, #0x4
    ldmia sp!, {lr}
    bx lr
}
// clang-format on
