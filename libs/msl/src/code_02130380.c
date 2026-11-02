#include "code_02130380.h"
#include "code_021423e4.h"
#include "code_02134008.h"

// clang-format off
// Multiplies the doubles r1:r0 and r3:r2 and returns the product in r1:r0, rounded as the floating-point status word
// says (func_02142578; see code_0212f884.s). Denormal operands are normalised first; underflow, overflow, inexact and
// invalid (zero times infinity, signalling NaNs) set their flags or call the trap handlers with event codes ending in
// 0x93. The operands stay saved on the stack for the invalid-operation trap.
// Not compiled code: it counts leading zeros with clz and tests bits with tst, neither of which the 1.2 compiler
// builds, and saves the argument registers and ip around its calls in the middle of the body, where 1.2 saves registers
// only in the prologue and never ip (docs/compiler.md).
asm u64 _dmul(u32 a, u32 b, u32 c, u32 d) {
    // Save the operands. lr = the sign of the product. Unpack the first operand: ip = exponent, r1:r0 = significand
    // shifted up 11 with the leading one set; exponent 0 or 0x7ff is special.
    stmfd sp!, {r0, r1, r2, r3, r4, r5, r6, r7, lr}
    eor lr, r1, r3
    and lr, lr, #0x80000000
    mov ip, r1, lsr #20
    mov r1, r1, lsl #11
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #11
    movs r6, ip, lsl #21
    cmnne r6, #0x200000
    beq dmul_a_special
    orr r1, r1, #0x80000000
    bic ip, ip, #0x800
    // Unpack the second operand the same way into r4 and r3:r2.
    mov r4, r3, lsr #20
    mov r3, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs r5, r4, lsl #21
    cmnne r5, #0x200000
    beq dmul_b_special
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
    // Add the exponents and multiply the significands (four 32x32 products); r1:r0 = the top 64 bits of the product,
    // with bit 0 set when any lower bit is.
dmul_multiply:
    add ip, r4, ip
    umull r5, r4, r0, r2
    umull r7, r6, r0, r3
    adds r4, r7, r4
    adc r6, r6, #0
    umull r7, r0, r1, r2
    adds r4, r7, r4
    adcs r0, r0, r6
    umull r7, r2, r1, r3
    adc r1, r2, #0
    adds r0, r0, r7
    adc r1, r1, #0
    orrs r4, r4, r5
    orrne r0, r0, #1
    // The product has its leading one in bit 63 or 62; shift it up one place in the second case.
    cmp r1, #0                          // leading one in bit 63
    blt dmul_normalised
    sub ip, ip, #1
    adds r0, r0, r0
    adc r1, r1, r1
    // Remove the extra bias: 0 or below underflows, 0x7ff or above overflows.
dmul_normalised:
    add ip, ip, #2
    subs ip, ip, #0x400
    bmi dmul_underflow
    beq dmul_underflow
    mov r6, ip, lsl #20
    cmn r6, #0x100000
    bmi dmul_overflow
    // Pack: r2 = the 11 bits below the result (bit 31 the rounding bit, the rest sticky), r1:r0 = the rounded-down
    // result. Exact results return here.
dmul_pack:
    movs r2, r0, lsl #21
    mov r0, r0, lsr #11
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    // Inexact: trap if enabled, else set the flag and round as the mode says.
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne dmul_trap_inexact
    orr r3, r3, #0x10
    str r3, [ip]
    tst r3, #0x800000
    bne dmul_mode_down
    tst r3, #0x400000
    bne dmul_mode_up
    // Nearest even: round up when the shifted-out bits are above half, or exactly half and the result odd.
    tst r2, #0x80000000
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    // Round up the magnitude; carrying into exponent 0x7ff is an overflow.
dmul_round_up:
    adds r0, r0, #1
    adc r1, r1, #0
    mov r2, r1, lsl #1
    cmn r2, #0x200000
    addlo sp, sp, #16
    ldmlofd sp!, {r4, r5, r6, r7, lr}
    bxlo lr
    tst r3, #0x400
    bne dmul_trap_overflow_round
    orr r3, r3, #0x14
    str r3, [ip]
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Rounding up: only positive results grow.
dmul_mode_up:
    cmp lr, #0
    beq dmul_round_up
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Rounding down or toward zero: down grows only negative results.
dmul_mode_down:
    tst r3, #0x400000
    addne sp, sp, #16
    ldmnefd sp!, {r4, r5, r6, r7, lr}
    bxne lr
    cmp lr, #0
    bne dmul_round_up
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // First operand has exponent 0 or 0x7ff. A NaN goes to dmul_a_nan; infinity times zero is invalid, infinity times
    // anything else but a NaN is infinity.
dmul_a_special:
    bics ip, ip, #0x800
    beq dmul_a_small
    orrs r6, r0, r1, lsl #1
    bne dmul_a_nan
    mov r4, r3, lsr #20
    mov r3, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs r5, r4, lsl #21
    beq dmul_inf_times_small
    cmn r5, #0x200000                   // exponent 0
    bne dmul_return_inf
    orrs r5, r2, r3, lsl #1
    beq dmul_return_inf
    b dmul_b_nan
    // Infinity times an operand with exponent 0: invalid for zero, infinity for a denormal.
dmul_inf_times_small:
    orrs r5, r3, r2
    beq dmul_invalid
    b dmul_return_inf
    // Second operand has exponent 0 or 0x7ff (the first is finite and not zero).
dmul_b_special:
    bics r4, r4, #0x800
    beq dmul_b_small
    orrs r6, r2, r3, lsl #1
    bne dmul_b_nan
    b dmul_return_inf
    // First operand has exponent 0. Zero: see dmul_a_zero. Denormal: shift its leading one up to bit 63 (a whole word
    // at a time, then with clz) and lower the exponent from 1 by the shift.
dmul_a_small:
    orrs r6, r0, r1, lsl #1
    beq dmul_a_zero
    mov ip, #1
    cmp r1, #0
    bne dmul_a_normalise
    sub ip, ip, #32
    movs r1, r0
    mov r0, #0
    bmi dmul_a_unpack_b
dmul_a_normalise:
    clz r6, r1
    movs r1, r1, lsl r6
    rsb r6, r6, #32
    orr r1, r1, r0, lsr r6
    rsb r6, r6, #32
    mov r0, r0, lsl r6
    sub ip, ip, r6
    // Unpack the second operand and multiply.
dmul_a_unpack_b:
    mov r4, r3, lsr #20
    mov r3, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs r5, r4, lsl #21
    cmnne r5, #0x200000
    beq dmul_b_special
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
    b dmul_multiply
    // First operand is zero: the product is zero, except for an infinity (invalid) or a NaN.
dmul_a_zero:
    mov r4, r3, lsr #20
    mov r3, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs r5, r4, lsl #21
    beq dmul_return_zero
    cmn r5, #0x200000
    bne dmul_return_zero
    orrs r6, r2, r3, lsl #1
    beq dmul_invalid
    b dmul_b_nan
    // Second operand has exponent 0: zero gives zero; a denormal is normalised like the first.
dmul_b_small:
    orrs r5, r2, r3, lsl #1
    beq dmul_return_zero
    mov r4, #1
    cmp r3, #0
    bne dmul_b_normalise
    sub r4, r4, #32
    movs r3, r2
    mov r2, #0
    bmi dmul_multiply
dmul_b_normalise:
    clz r6, r3
    movs r3, r3, lsl r6
    rsb r6, r6, #32
    orr r3, r3, r2, lsr r6
    rsb r6, r6, #32
    mov r2, r2, lsl r6
    sub r4, r4, r6
    b dmul_multiply
    // Exponent 0 or below: underflow trap if enabled, else the product is a denormal. At exactly -52 only the rounding
    // bit is left; below that the result is zero or the smallest denormal.
dmul_underflow:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r2, [r2]
    tst r2, #0x800
    bne dmul_trap_underflow
    cmn ip, #52                         // exactly -52
    beq dmul_round_bit_only
    bmi dmul_tiny                       // below -52
    // Shift the product right into a denormal: r2:r3 collect the bits shifted out, r2's bit 31 being the rounding bit,
    // and any lower bit sets bit 0 of r2.
    mov r2, r1
    mov r3, r0
    add r4, ip, #52
    cmp r4, #32
    movge r2, r3
    movge r3, #0
    subge r4, r4, #32
    rsb r5, r4, #32
    mov r2, r2, lsl r4
    orr r2, r2, r3, lsr r5
    movs r3, r3, lsl r4
    orrne r2, r2, #1
    rsb ip, ip, #12
    cmp ip, #32
    movge r0, r1
    movge r1, #0
    subge ip, ip, #32
    rsb r4, ip, #32
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    // Exact: return. Inexact: underflow and inexact (or trap), then round as the mode says.
dmul_denormal_round:
    cmp r2, #0
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne dmul_trap_inexact
    orr r3, r3, #0x18
    str r3, [ip]
    tst r3, #0x800000
    bne dmul_denormal_down
    tst r3, #0x400000
    bne dmul_denormal_up
    // Nearest even.
    tst r2, #0x80000000
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Rounding up: positive results grow.
dmul_denormal_up:
    cmp lr, #0
    addne sp, sp, #16
    ldmnefd sp!, {r4, r5, r6, r7, lr}
    bxne lr
    adds r0, r0, #1
    adc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Rounding down or toward zero: down grows only negative results.
dmul_denormal_down:
    tst r3, #0x400000
    addne sp, sp, #16
    ldmnefd sp!, {r4, r5, r6, r7, lr}
    bxne lr
    adds r0, r0, r1, lsr #31
    adc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Only the rounding bit is left: r0 = the bits below it, ready for dmul_half_smallest.
dmul_round_bit_only:
    orr r0, r0, r1, lsl #1
    b dmul_half_smallest
    // Return infinity with the product's sign.
dmul_return_inf:
    ldr r1, =0x7ff00000
    orr r1, lr, r1
    mov r0, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // First operand is a NaN. A signalling NaN is invalid; a quiet one gives the default NaN, invalid only when the
    // second operand is a signalling NaN.
dmul_a_nan:
    tst r1, #0x40000000
    beq dmul_invalid
    mov r4, r3, lsr #20
    mov r3, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs r5, r4, lsl #21
    beq dmul_default_nan
    cmn r5, #0x200000
    bne dmul_default_nan
    orrs r5, r2, r3, lsl #1
    beq dmul_default_nan
    // Second operand is a NaN: the default NaN, invalid when it is signalling.
dmul_b_nan:
    mov r1, r3                          // its high word is in r3
    mov r3, r1
    mvn r0, #0
    bic r1, r0, #0x80000000
    tst r3, #0x40000000
    addne sp, sp, #16
    ldmnefd sp!, {r4, r5, r6, r7, lr}
    bxne lr
    // Invalid operation: trap if enabled, else set the flag.
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne dmul_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Invalid operation: trap if enabled, else set the flag and return the default NaN.
dmul_invalid:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne dmul_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
dmul_default_nan:
    mvn r0, #0
    bic r1, r0, #0x80000000
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Half the smallest denormal or a little more: zero or the smallest denormal by the mode, with underflow and
    // inexact. Nearest rounds up unless it is exactly half.
dmul_half_smallest:
    movs r2, r0
    mov r1, lr
    mov r0, #0
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne dmul_trap_inexact
    orr r3, r3, #0x18
    str r3, [ip]
    tst r3, #0x800000
    bne dmul_denormal_down
    tst r3, #0x400000
    bne dmul_denormal_up
    cmp r2, #0
    addne r0, r0, #1
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Smaller still: zero, or the smallest denormal when rounding away from zero for this sign, with underflow and
    // inexact.
dmul_tiny:
    mov r1, lr
    mov r0, #0
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne dmul_trap_inexact
    orr r3, r3, #0x18
    str r3, [ip]
    tst r3, #0x800000
    bne dmul_denormal_down
    tst r3, #0x400000
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    cmp r1, #0
    addeq r0, r0, #1
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Overflow: trap if enabled, else set overflow and inexact. Nearest gives infinity, toward zero the largest finite
    // value, up and down one or the other by the sign.
dmul_overflow:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x400
    bne dmul_trap_overflow
    orr r3, r3, #0x14
    str r3, [r2]
    ldr r1, =0x7ff00000
    orr r1, lr, r1
    mov r0, #0
    tst r3, #0x800000
    bne dmul_overflow_down
    tst r3, #0x400000
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    subs r0, r0, lr, lsr #31
    sbc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Down or toward zero: start from the largest finite value.
dmul_overflow_down:
    subs r0, r0, #1
    sbc r1, r1, #0
    tst r3, #0x400000
    addne sp, sp, #16
    ldmnefd sp!, {r4, r5, r6, r7, lr}
    bxne lr
    adds r0, r0, lr, lsr #31
    adc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Return zero with the product's sign.
dmul_return_zero:
    mov r1, lr
    mov r0, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Overflow trap after rounding: pass the result with its exponent wrapped down by 0x600.
dmul_trap_overflow_round:
    add sp, sp, #16
    sub r1, r1, #0x60000000
    ldr r2, =0x10000093
    bl func_0213412c
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Overflow trap: pass the result with its exponent lowered by 0x600.
dmul_trap_overflow:
    add sp, sp, #16
    mov r0, r0, lsr #11
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    sub ip, ip, #0x600
    orr r1, r1, ip, lsl #20
    ldr r2, =0x10000093
    bl func_0213412c
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Underflow trap: pass the result with its exponent raised by 0x600.
dmul_trap_underflow:
    add sp, sp, #16
    mov r0, r0, lsr #11
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    add ip, ip, #0x600
    orr r1, r1, ip, lsl #20
    ldr r2, =0x20000093
    bl func_0213412c
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Invalid trap: pass the original operands from the stack.
dmul_trap_invalid:
    ldmfd sp!, {r0, r1, r2, r3}
    ldr ip, =0x4000093
    stmdb sp!, {ip}
    bl func_0213406c
    add sp, sp, #4
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
    // Inexact trap: pass the rounded result.
dmul_trap_inexact:
    add sp, sp, #16
    ldr r2, =0x40000093
    bl func_0213412c
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
}
// clang-format on
