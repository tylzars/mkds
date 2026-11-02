#include "code_02130198.h"
#include "code_021423e4.h"
#include "code_02134008.h"

// clang-format off
// Converts the double r1:r0 to an unsigned 64-bit integer in r1:r0, dropping the fraction. Fractions set inexact (or
// trap); negative values below -1, values of 2^64 and more, and NaN raise invalid (or trap) and give all ones; -1 < x <
// 0 gives 0.
// Not compiled code: it uses tst, which the 1.2 compiler never builds, and saves ip and the argument registers around
// its calls in the middle of the body; 1.2 saves registers only in the prologue, never ip, and pads every frame to 8
// bytes (docs/compiler.md; frame layout in the compiler), unlike the one-word `stmdb sp!, {lr}` frames here.
asm u64 _ll_ufrom_d(u32 a, u32 b) {
    // Negative input: see u64_negative. ip = 0x43e - exponent is the right shift that turns the 64-bit significand into
    // the integer; below 0 the value is too large, 64 or more it is below 1.
    tst r1, #0x80000000
    bne u64_negative
    ldr r2, =0x43e
    subs r2, r2, r1, lsr #20
    blt u64_invalid
    cmp r2, #64
    bge u64_too_small
    // Significand with the leading one, shifted to the top of ip:r0.
    mov ip, r1, lsl #11
    orr ip, ip, #0x80000000
    orr ip, ip, r0, lsr #21
    cmp r2, #32
    ble u64_shift_short
    // A shift of 33 to 63: only the high word remains; any bit shifted out is inexact.
    sub r2, r2, #32
    mov r3, r0, lsl #11
    mov r1, #0
    mov r0, ip, lsr r2
    rsb r2, r2, #32
    orrs ip, r3, ip, lsl r2
    bxeq lr
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x1000
    bne u64_trap_inexact
    orr r3, r3, #0x10
    str r3, [r2]
    bx lr
    // A shift of 0 to 32.
u64_shift_short:
    mov r3, r0, lsl #11
    mov r1, ip, lsr r2
    mov r0, r3, lsr r2
    rsb r2, r2, #32
    orr r0, r0, ip, lsl r2
    movs ip, r3, lsl r2
    bxeq lr
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x1000
    bne u64_trap_inexact
    orr r3, r3, #0x10
    str r3, [r2]
    bx lr
    // Below 1: zero, inexact unless the input was zero.
u64_too_small:
    orrs r1, r1, r0
    bxeq lr
    mov r1, #0
    mov r0, #0
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x1000
    bne u64_trap_inexact
    orr r3, r3, #0x10
    str r3, [r2]
    bx lr
    // Negative: -0 and values above -1 give 0, the rest are invalid.
u64_negative:
    cmn r1, #0x100000
    cmpeq r0, #0
    bhi u64_invalid
    mov r1, #0
    mov r0, #0
    bx lr
    // Invalid: trap if enabled, else set the flag and return all ones.
u64_invalid:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne u64_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
    mvn r1, #0
    mvn r0, #0
    bx lr
    // Invalid trap.
u64_trap_invalid:
    ldr r2, =0x4c000f8
    stmdb sp!, {lr}
    bl func_0213412c
    ldmia sp!, {lr}
    bx lr
    // Inexact trap: pass the result.
u64_trap_inexact:
    ldr r2, =0x40c000f8
    stmdb sp!, {lr}
    bl func_0213412c
    ldmia sp!, {lr}
    bx lr
}

// Converts the unsigned integer r0 to a double in r1:r0 (always exact).
// Not compiled code: it counts leading zeros with clz, which the 1.2 compiler never builds, and builds the constant
// 0x41e with mov and add, where 1.2 loads such a constant from a constant word (docs/compiler.md).
asm u64 _dfltu(u32 a) {
    // Zero gives 0. Shift the leading one to bit 31 and lower the exponent 0x41e by the shift.
    cmp r0, #0
    mov r1, #0
    bxeq lr
    mov r3, #0x400
    add r3, r3, #30
    bmi u_normalised                    // bit 31 already set
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    // Pack: the significand loses its leading one.
u_normalised:
    mov r1, r0
    mov r0, r1, lsl #21
    add r1, r1, r1
    mov r1, r1, lsr #12
    orr r1, r1, r3, lsl #20
    bx lr
}

// Converts the signed integer r0 to a double in r1:r0 (always exact).
// Not compiled code: clz and the mov/add constant, as in _dfltu.
asm u64 _dflt(s32 a) {
    // r2 = the sign; work on the magnitude. Zero gives 0.
    ands r2, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r0, #0
    mov r1, #0
    bxeq lr
    // Shift the leading one to bit 31 and lower the exponent 0x41e by the shift.
    mov r3, #0x400
    add r3, r3, #30
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    movs r1, r0
    // Pack sign, exponent and significand (without the leading one).
    mov r0, r1, lsl #21
    add r1, r1, r1
    orr r1, r2, r1, lsr #12
    orr r1, r1, r3, lsl #20
    bx lr
}
// clang-format on
