#include "code_02130a70.h"
#include "code_021423e4.h"
#include "code_02134008.h"

// clang-format off
// Returns the square root of the double r1:r0, computed one bit at a time and rounded as the floating-point status word
// says (func_02142578; see code_0212f884.s). Zero and +infinity return themselves, a quiet NaN returns itself; negative
// numbers and signalling NaNs raise invalid (or trap with event code 0x04000097).
// Not compiled code: it counts leading zeros with clz and tests bits with tst, neither of which the 1.2 compiler
// builds, and saves ip and the argument registers around its call in the middle of the body, where 1.2 saves registers
// only in the prologue and never ip (docs/compiler.md).
asm double func_02130a70(double a) {
    // Negative numbers, infinities and NaNs (high word 0x7ff00000 or above, unsigned) are special.
    stmfd sp!, {r4, r5, r6, lr}
    ldr r2, =0x7ff00000
    cmp r1, r2
    bhs sqrt_special
    // ip = exponent; exponent 0 (zero, denormal) is normalised first.
    movs ip, r1, lsr #20
    beq sqrt_exponent_zero
    // Replace the exponent bits with the leading one.
    bic r1, r1, r2
    orr r1, r1, #0x100000
    // Halve the exponent. For an even exponent the significand is shifted up one place more, so the root of r1:r3 below
    // has its leading one in a fixed place.
sqrt_halve_exponent:
    movs ip, ip, asr #1
    bhs sqrt_even_exponent              // odd exponent: no extra shift
    sub ip, ip, #1
    movs r0, r0, lsl #1
    adc r1, r1, r1
sqrt_even_exponent:
    movs r3, r0, lsl #1
    adc r1, r1, r1
    // Bits 20 to 0 of the high word of the root (r2), one per pass: r4 = root so far times 2.
    mov r2, #0
    mov r4, #0
    mov lr, #0x200000
sqrt_high_loop:
    add r6, r4, lr
    cmp r6, r1
    addle r4, r6, lr
    suble r1, r1, r6
    addle r2, r2, lr
    movs r3, r3, lsl #1
    adc r1, r1, r1
    movs lr, lr, lsr #1
    bne sqrt_high_loop
    // The top bit of the low word (r0) needs the full 64-bit remainder compare.
    mov r0, #0
    mov r5, #0
    cmp r1, r4
    cmpeq r3, #0x80000000
    blo sqrt_low_start
    subs r3, r3, #0x80000000
    sbc r1, r1, r4
    add r4, r4, #1
    mov r0, #0x80000000
    // Bits 30 to 0 of the low word; r1:r3 is the remainder, r4:r5 the root so far times 2.
sqrt_low_start:
    movs r3, r3, lsl #1
    adc r1, r1, r1
    mov lr, #0x40000000
sqrt_low_loop:
    add r6, r5, lr
    cmp r4, r1
    cmpeq r6, r3
    bhi sqrt_low_next
    add r5, r6, lr
    subs r3, r3, r6
    sbc r1, r1, r4
    add r0, r0, lr
sqrt_low_next:
    movs r3, r3, lsl #1
    adc r1, r1, r1
    movs lr, lr, lsr #1
    bne sqrt_low_loop
    // A zero remainder is exact. Otherwise inexact (or trap); the extra root bit in r0 bit 0 is the rounding bit:
    // cleared when rounding down or toward zero, set when rounding up.
    orrs r1, r1, r3
    biceq r0, r0, #1
    beq sqrt_pack
    stmfd sp!, {r0, r1, r2, r3, ip, lr}
    bl func_02142578
    mov r5, r0
    ldmfd sp!, {r0, r1, r2, r3, ip, lr}
    ldr r6, [r5]
    tst r6, #0x1000
    bne sqrt_trap_inexact
    orr r6, r6, #0x10
    str r6, [r5]
    tst r6, #0x800000
    bicne r0, r0, #1
    bne sqrt_pack
    tst r6, #0x400000
    orrne r0, r0, #1
    // Drop the rounding bit, adding it back in, and set the exponent: (e - 0x3ff) / 2 + 0x3ff.
sqrt_pack:
    movs r1, r2, lsr #1
    movs r0, r0, rrx
    adcs r0, r0, #0
    adc r1, r1, #0
    add r1, r1, #0x20000000
    sub r1, r1, #0x100000
    add r1, r1, ip, lsl #20
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Exponent 0: zero returns itself. A denormal is shifted until its leading one is in bit 20 of the high word, the
    // exponent going below 1 by the shift.
sqrt_exponent_zero:
    cmp r1, #0
    bne sqrt_normalise_high
    cmp r0, #0
    ldmeqfd sp!, {r4, r5, r6, lr}
    bxeq lr
    mvn ip, #0x13
    clz r5, r0
    movs r0, r0, lsl r5
    sub ip, ip, r5
    mov r1, r0, lsr #11
    mov r0, r0, lsl #21
    b sqrt_halve_exponent
    // Leading one in the high word.
sqrt_normalise_high:
    clz r2, r1
    movs r1, r1, lsl r2
    rsb r2, r2, #43
    mov r1, r1, lsr #11
    orr r1, r1, r0, lsr r2
    rsb r2, r2, #32
    mov r0, r0, lsl r2
    rsb ip, r2, #1
    b sqrt_halve_exponent
    // Negative: -0 returns itself, anything else below zero (or -infinity) is invalid; a NaN is a NaN.
sqrt_special:
    tst r1, #0x80000000
    beq sqrt_inf_or_nan
    bics r3, r1, #0x80000000
    cmpeq r0, #0
    ldmeqfd sp!, {r4, r5, r6, lr}
    bxeq lr
    cmp r3, r2
    blo sqrt_invalid
    orrs r2, r0, r1, lsl #12
    bne sqrt_nan
    b sqrt_invalid
    // +infinity and quiet NaNs return themselves; a signalling NaN is invalid.
sqrt_inf_or_nan:
    orrs r2, r0, r1, lsl #12
    ldmeqfd sp!, {r4, r5, r6, lr}
    bxeq lr
sqrt_nan:
    tst r1, #0x80000
    ldmnefd sp!, {r4, r5, r6, lr}
    bxne lr
    // Invalid: trap if enabled, else set the flag and return the input with the quiet-NaN bits set.
sqrt_invalid:
    ldr r2, =0x7ff80000
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x100
    bne sqrt_trap_invalid
    orr r3, r3, #1
    str r3, [ip]
    orr r1, r1, r2
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Invalid trap.
sqrt_trap_invalid:
    ldr r2, =0x4000097
    bl func_0213412c
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Inexact trap: pass the rounded-down root.
sqrt_trap_inexact:
    movs r1, r2, lsr #1
    movs r0, r0, rrx
    add r1, r1, #0x20000000
    sub r1, r1, #0x100000
    add r1, r1, ip, lsl #20
    ldr r2, =0x40000097
    bl func_0213412c
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
}
// clang-format on
