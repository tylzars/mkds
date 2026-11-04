#include "code_0200e6ec.h"
#include "code_02146bb8.h"

// clang-format off
// Calls func_02146c24 with the address of mUnk_48, stores the status register and the registers (r0 = 1 saved) into
// the words from 0, the banked sp of mode 0xd3 at 0x44 and the address of the return point at 0x3c, and returns 0.
// non-matching: same size; 1 lines differ; first: original `add r1, r0, #0`, ours `mov r1, r0`
asm s32 ThreadSaveContext(Unk0200db5c *t) {
    stmdb sp!, {r0, lr}
    add r0, r0, #0x48
    ldr r1, =func_02146c24
    blx r1
    ldmia sp!, {r0, lr}
    add r1, r0, #0x0
    mrs r2, cpsr
    str r2, [r1], #0x4
    mov r0, #0xd3
    msr cpsr_c, r0
    str sp, [r1, #0x40]
    msr cpsr_c, r2
    mov r0, #0x1
    stmia r1, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}
    add r0, pc, #0x8
    str r0, [r1, #0x3c]
    mov r0, #0x0
    bx lr
}

// Calls func_02146bb8 with the address of mUnk_48, then switches to mode 0xd3 and restores the registers and the
// status word saved by ThreadSaveContext.
asm void ThreadLoadContext(Unk0200db5c *t) {
    stmdb sp!, {r0, lr}
    add r0, r0, #0x48
    ldr r1, =func_02146bb8
    blx r1
    ldmia sp!, {r0, lr}
    mrs r1, cpsr
    bic r1, r1, #0x1f
    orr r1, r1, #0xd3
    msr cpsr_c, r1
    ldr r1, [r0], #0x4
    msr spsr_fsxc, r1
    ldr sp, [r0, #0x40]
    ldr lr, [r0, #0x3c]
    ldmia r0, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}^
    mov r0, r0
    subs pc, lr, #0x4
}
// clang-format on
