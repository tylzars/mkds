// Double-precision addition and double to float conversion.
//
// Doubles are passed and returned as two words, low word first (r0 = low, r1 = high; the second operand in r2,
// r3). func_02142578 returns the address of the floating-point status word:
//   bits 0-4    sticky flags: 0x01 invalid, 0x04 overflow, 0x08 underflow, 0x10 inexact
//   bits 8-12   the matching trap enables (0x100, 0x400, 0x800, 0x1000)
//   bits 22-23  rounding: 0 nearest even, 0x400000 up, 0x800000 down, both toward zero
// With a trap enabled the routines call a handler (func_0213406c, func_0213412c, func_021341e0, func_02134238)
// with an event code (high byte: the event, low byte: the operation) and return its result.
//
// Not compiled code: _dadd and the subtraction (_dsub, code_02130cb4.s) branch into each other past their first
// instructions, and _d2f branches into the middle of the two blocks after it; a compiled function is entered only
// at its start. All of it also uses tst, which the 1.2 compiler never builds (docs/compiler.md).

    .text
    .extern .L_02130cdc
    .extern func_0213406c
    .extern func_0213412c
    .extern func_021341e0
    .extern func_02134238
    .extern func_02142578

// Adds the doubles r1:r0 and r3:r2 and returns the sum in r1:r0, rounded as the status word says. Operands of different
// sign continue in the subtraction, with the second operand negated; the subtraction comes here the same way. The
// operands stay saved on the stack for the invalid-operation trap.
    .global _dadd
    .type _dadd, @function
_dadd:
    // Save the operands; operands of different sign are a subtraction.
    stmfd sp!, {r0, r1, r2, r3, r4, lr}
    eors ip, r1, r3
    eormi r3, r3, #0x80000000           // different signs: negate the second operand
    bmi .L_02130cdc                     // and subtract
    // Entry from the subtraction (same signs). Order the operands so that |r1:r0| >= |r3:r2|.
    .global .L_0212f894
.L_0212f894:
    subs ip, r0, r2
    sbcs lr, r1, r3
    bhs dadd_unpack
    adds r2, r2, ip
    adc r3, r3, lr
    subs r0, r0, ip
    sbc r1, r1, lr
    // Unpack the first operand: ip = sign and exponent, r1:r0 = significand shifted up 11 with the leading one set.
    // Exponent 0 (zero, denormal) or 0x7ff (infinity, NaN) goes to the special cases.
dadd_unpack:
    mov lr, #0x80000000
    mov ip, r1, lsr #20
    orr r1, lr, r1, lsl #11
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #11
    movs r4, ip, lsl #21
    cmnne r4, #0x200000
    beq dadd_a_special
    // Unpack the second operand the same way into r4 and r3:r2.
    mov r4, r3, lsr #20
    orr r3, lr, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs lr, r4, lsl #21
    beq dadd_b_small
    // Shift the smaller significand right by the exponent difference, folding the bits shifted out into its lowest bit.
    // Above 32 places only one word is left (the shift stops at 63).
dadd_align:
    subs r4, ip, r4
    beq dadd_sum
    cmp r4, #32
    ble dadd_align_short
    cmp r4, #56
    movge r4, #63                       // 56 or more: only a sticky bit remains
    sub r4, r4, #32
    rsb lr, r4, #32
    orrs lr, r2, r3, lsl lr
    mov r2, r3, lsr r4
    orrne r2, r2, #1
    adds r0, r0, r2
    adcs r1, r1, #0
    blo dadd_pack                       // no carry out
    b dadd_carry
    // A difference of 1 to 32 places: shift across both words.
dadd_align_short:
    rsb lr, r4, #32
    movs lr, r2, lsl lr
    rsb lr, r4, #32
    mov r2, r2, lsr r4
    orr r2, r2, r3, lsl lr
    mov r3, r3, lsr r4
    orrne r2, r2, #1
    // Add the significands. No carry out: the sum is already normalised.
dadd_sum:
    adds r0, r0, r2
    adcs r1, r1, r3
    blo dadd_pack
    // Carry out: shift the sum right one place back through the carry, keeping the bit shifted out, and raise the
    // exponent; reaching 0x7ff overflows.
dadd_carry:
    add ip, ip, #1
    and r4, r0, #1
    movs r1, r1, rrx
    orr r0, r4, r0, rrx
    mov lr, ip, lsl #21
    cmn lr, #0x200000
    beq dadd_overflow
    // Pack: r2 = the 11 bits below the result (bit 31 the rounding bit, the rest sticky), r1:r0 = the rounded-down
    // result. Exact results return here.
dadd_pack:
    movs r2, r0, lsl #21
    mov r0, r0, lsr #11
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    mov r1, r1, lsr #12
    orr r1, r1, ip, lsl #20
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    // Inexact: trap if enabled, else set the flag and round as the mode says.
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne dadd_trap_inexact
    orr r3, r3, #0x10
    str r3, [ip]
    tst r3, #0x800000
    bne dadd_mode_down
    tst r3, #0x400000
    bne dadd_mode_up
    // Nearest even: round up when the shifted-out bits are above half, or exactly half and the result odd.
    tst r2, #0x80000000                 // below half
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1                   // exactly half and even
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    // Round up the magnitude; carrying into exponent 0x7ff is an overflow.
dadd_round_up:
    adds r0, r0, #1
    adc r1, r1, #0
    mov r2, r1, lsl #1
    cmn r2, #0x200000
    addlo sp, sp, #16
    ldmlofd sp!, {r4, lr}
    bxlo lr
    tst r3, #0x400
    bne dadd_trap_overflow
    orr r3, r3, #0x14
    str r3, [ip]
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Rounding up: only positive results grow.
dadd_mode_up:
    cmp r1, #0
    bpl dadd_round_up
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Rounding down or toward zero: down grows only negative results.
dadd_mode_down:
    tst r3, #0x400000
    addne sp, sp, #16
    ldmnefd sp!, {r4, lr}
    bxne lr
    cmp r1, #0
    bmi dadd_round_up
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // First operand has exponent 0 or 0x7ff. lr = its sign. Exponent 0 is handled below; a NaN goes to dadd_a_nan, an
    // infinity is the result unless the second operand is a NaN.
dadd_a_special:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bics ip, ip, #0x800
    beq dadd_a_small
    orrs r4, r0, r1, lsl #1
    bne dadd_a_nan
    mov r4, r3, lsr #20
    mov r3, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs r4, r4, lsl #21
    beq dadd_return_inf
    cmn r4, #0x200000
    bne dadd_return_inf
    orrs r4, r2, r3, lsl #1
    beq dadd_return_inf
    b dadd_b_nan
    // Second operand has exponent 0: zero or denormal.
dadd_b_small:
    cmp r4, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bic ip, ip, #0x800
    bics r4, r4, #0x800
    beq dadd_both_small
    orrs r4, r2, r3, lsl #1
    bne dadd_b_nan
    b dadd_return_inf
    // First operand has exponent 0. Zero: the result is the second operand. Denormal: it has exponent 1 and no leading
    // one.
dadd_a_small:
    orrs r4, r0, r1, lsl #1
    beq dadd_a_zero
    mov ip, #1
    bic r1, r1, #0x80000000
    mov r4, r3, lsr #20
    mov r3, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs r4, r4, lsl #21
    cmnne r4, #0x200000
    mov r4, r4, lsr #21
    orr r4, r4, lr, lsr #20
    beq dadd_b_small
    orr r3, r3, #0x80000000
    orr ip, ip, lr, lsr #20
    b dadd_align
    // First operand is zero: unpack the second and return it, unless it is a NaN.
dadd_a_zero:
    mov ip, r3, lsr #20
    mov r1, r3, lsl #11
    orr r1, r1, r2, lsr #21
    mov r0, r2, lsl #11
    movs r4, ip, lsl #21
    beq dadd_return_b
    cmn r4, #0x200000
    bne dadd_return_b
    orrs r4, r0, r1, lsl #1
    beq dadd_return_inf
    b dadd_b_nan_in_r1
    // Second operand zero: the result is the first. Denormal: exponent 1, no leading one.
dadd_both_small:
    orrs r4, r2, r3, lsl #1
    beq dadd_return_a
    mov r4, #1
    bic r3, r3, #0x80000000
    cmp r1, #0
    bpl dadd_both_denormal
    orr ip, ip, lr, lsr #20
    orr r4, r4, lr, lsr #20
    b dadd_align
    // Both denormal: add the significands; a carry makes a normal result with exponent 1, otherwise the exponent stays
    // 0 when the sum has no leading one.
dadd_both_denormal:
    adds r0, r0, r2
    adcs r1, r1, r3
    blo dadd_denormal_pack
    add ip, ip, #1
    and r4, r0, #1
    movs r1, r1, rrx
    mov r0, r0, rrx
    orr r0, r0, r4
    // Pack the result and round it as in dadd_pack.
dadd_denormal_pack:
    cmp r1, #0
    subges ip, ip, #1
    movs r2, r0, lsl #21
    mov r0, r0, lsr #11
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne dadd_trap_inexact
    orr r3, r3, #0x10
    str r3, [ip]
    tst r3, #0x800000
    bne dadd_mode_down
    tst r3, #0x400000
    bne dadd_mode_up
    tst r2, #0x80000000
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    // Return the second operand.
dadd_return_b:
    mov r1, r3
    mov r0, r2
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // The second operand is zero: return the first, repacked.
dadd_return_a:
    cmp r1, #0
    subges ip, ip, #1
    mov r0, r0, lsr #11
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Return infinity with the first operand's sign.
dadd_return_inf:
    ldr r1, dadd_inf_high
    orr r1, lr, r1
    mov r0, #0
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // First operand is a NaN. A signalling NaN (bit 51 clear) is invalid. A quiet one gives the default NaN, which is
    // invalid only when the second operand is a signalling NaN.
dadd_a_nan:
    tst r1, #0x40000000
    beq dadd_a_signalling
    mov r4, r3, lsr #20
    mov r3, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs r4, r4, lsl #21
    beq dadd_default_nan
    cmn r4, #0x200000
    bne dadd_default_nan
    orrs r4, r2, r3, lsl #1
    beq dadd_default_nan
    // Second operand is a NaN: the default NaN, invalid when it is signalling.
dadd_b_nan:
    mov r1, r3                          // its high word is in r3
dadd_b_nan_in_r1:
    mov r3, r1                          // (entry with it in r1)
    mvn r0, #0
    bic r1, r0, #0x80000000
    tst r3, #0x40000000
    addne sp, sp, #16
    ldmnefd sp!, {r4, lr}
    bxne lr
    // Invalid operation: trap if enabled, else set the flag and return the default NaN in r1:r0.
dadd_b_signalling:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne dadd_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // First operand is a signalling NaN: raise invalid, return the default NaN.
dadd_a_signalling:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne dadd_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
dadd_default_nan:
    mvn r0, #0
    bic r1, r0, #0x80000000
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Overflow while normalising: trap if enabled, else set overflow and inexact. Nearest gives infinity, toward zero
    // the largest finite value, up and down one or the other by the sign.
dadd_overflow:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x400
    bne dadd_trap_overflow_carry
    orr r3, r3, #0x14
    str r3, [ip]
    ldr r1, dadd_inf_high
    orr r1, lr, r1
    mov r0, #0
    tst r3, #0x800000
    bne dadd_overflow_down
    tst r3, #0x400000
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    subs r0, r0, lr, lsr #31
    sbc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Down or toward zero: start from the largest finite value.
dadd_overflow_down:
    subs r0, r0, #1
    sbc r1, r1, #0
    tst r3, #0x400000
    addne sp, sp, #16
    ldmnefd sp!, {r4, lr}
    bxne lr
    adds r0, r0, lr, lsr #31
    adc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Overflow trap after rounding: pass the result with its exponent wrapped down by 0x600.
dadd_trap_overflow:
    add sp, sp, #16
    sub r1, r1, #0x60000000
    ldr r2, dadd_code_overflow
    bl func_0213412c
    ldmfd sp!, {r4, lr}
    bx lr
    // Overflow trap while normalising: pass the result with the exponent 0x1ff.
dadd_trap_overflow_carry:
    add sp, sp, #16
    mov r0, r0, lsr #11
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    mov r1, r1, lsr #12
    ldr r2, dadd_exp_wrap
    orr r1, r1, r2, lsl #20
    orr r1, r1, lr
    ldr r2, dadd_code_overflow
    bl func_0213412c
    ldmfd sp!, {r4, lr}
    bx lr
    // Invalid trap: pass the original operands from the stack.
dadd_trap_invalid:
    ldmfd sp!, {r0, r1, r2, r3}
    ldr ip, dadd_code_invalid
    stmdb sp!, {ip}
    bl func_0213406c
    add sp, sp, #4
    ldmfd sp!, {r4, lr}
    bx lr
    // Inexact trap: pass the rounded result.
dadd_trap_inexact:
    add sp, sp, #16
    ldr r2, dadd_code_inexact
    bl func_0213412c
    ldmfd sp!, {r4, lr}
    bx lr
    // Constant words: the high word of infinity, the event codes and the wrapped exponent.
dadd_inf_high:
    .word 0x7ff00000
dadd_code_overflow:
    .word 0x10000091
dadd_exp_wrap:
    .word 0x000001ff
dadd_code_invalid:
    .word 0x04000091
dadd_code_inexact:
    .word 0x40000091
    .size _dadd, . - _dadd

// Converts the double r1:r0 to a float in r0, rounded as the status word says. Too small, too large and NaN inputs
// continue in the two blocks below.
    .global _d2f
    .type _d2f, @function
_d2f:
    // r2 = sign, ip = exponent. Exponent 0 (zero, denormal) and 0x7ff (infinity, NaN) are special; the float exponent
    // is the double's minus 0x380, and 0 or less underflows, 0xff or more overflows.
    and r2, r1, #0x80000000
    mov ip, r1, lsr #20
    bics ip, ip, #0x800
    beq ff0c_zero_check
    mov r3, ip, lsl #21
    cmn r3, #0x200000
    bhs d2f_inf_or_nan                  // infinity or NaN
    subs ip, ip, #0x380
    bls f40_small                       // too small
    cmp ip, #255
    bge f40_overflow                    // too large
    // Pack sign, exponent and the top 23 bits; r1 = the 29 bits shifted out. Exact results return.
    mov r1, r1, lsl #12
    orr r3, r2, r1, lsr #9
    orr r3, r3, r0, lsr #29
    movs r1, r0, lsl #3
    orr r0, r3, ip, lsl #23
    bxeq lr
    // Inexact: trap if enabled, else set the flag and round as the mode says.
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne f40_trap_inexact
    orr r3, r3, #0x10
    str r3, [ip]
    tst r3, #0x800000
    bne d2f_mode_down
    tst r3, #0x400000
    bne d2f_mode_up
    // Nearest even: round up when above half, or exactly half and odd.
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    bxeq lr
    // Round up the magnitude; reaching exponent 0xff is an overflow.
d2f_round_up:
    add r0, r0, #1
    mov r1, r0, lsl #1
    cmn r1, #0x1000000
    bxlo lr
    tst r3, #0x400
    bne f40_trap_overflow_round
    orr r3, r3, #0x14
    str r3, [ip]
    bx lr
    // Rounding up: only positive results grow.
d2f_mode_up:
    cmp r2, #0
    beq d2f_round_up
    bx lr
    // Rounding down or toward zero: down grows only negative results.
d2f_mode_down:
    tst r3, #0x400000
    bxne lr
    cmp r2, #0
    bne d2f_round_up
    bx lr
    // Infinity keeps its sign; a NaN goes to the NaN path.
d2f_inf_or_nan:
    orrs r3, r0, r1, lsl #12
    bne d2f_nan
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
    // A NaN with bit 51 set is quiet.
d2f_nan:
    tst r1, #0x80000
    bne d2f_nan_result
    .size _d2f, . - _d2f

// Part of _d2f: a NaN input. A quiet NaN gives 0x7fffffff; a signalling one also raises invalid (or traps). Not entered
// at its start: _d2f branches to its last two instructions and into the middle.
    .global func_0212ff0c
    .type func_0212ff0c, @function
func_0212ff0c:
    // A signalling NaN: raise invalid (or trap). A quiet or a signalling NaN gives 0x7fffffff.
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne f40_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
d2f_nan_result:
    mvn r0, #0x80000000
    bx lr
    // Exponent 0: a zero gives a signed zero; a denormal is far too small for a float.
ff0c_zero_check:
    orrs r3, r0, r1, lsl #12
    beq f40_zero
    .size func_0212ff0c, . - func_0212ff0c

// Part of _d2f: results too small for a normal float (underflow), too large (overflow), and the trap calls. Its blocks
// are reached by branches from _d2f and func_0212ff0c, not through its first instruction.
    .global func_0212ff40
    .type func_0212ff40, @function
func_0212ff40:
    // A denormal input: underflow trap if enabled, else the tiny-result path.
    stmfd sp!, {r0, r1, r2, ip, lr}
    bl func_02142578
    mov r3, r0
    ldmfd sp!, {r0, r1, r2, ip, lr}
    ldr r3, [r3]
    tst r3, #0x800
    bne f40_trap_underflow
    beq f40_tiny
f40_zero:
    mov r0, r2
    bx lr
    // Exponent 0x380 or below: the result is a float denormal. The underflow trap gets the exact value; otherwise
    // exponent 0x380 - 23 (ip = -23) keeps only the rounding bit, smaller ones go to f40_tiny.
f40_small:
    stmfd sp!, {r0, r1, r2, ip, lr}
    bl func_02142578
    mov r3, r0
    ldmfd sp!, {r0, r1, r2, ip, lr}
    ldr r3, [r3]
    tst r3, #0x800                      // underflow traps take the exact value
    bne f40_trap_underflow
    cmn ip, #23
    beq f40_round_bit_only              // exponent 0x380 - 23: only the rounding bit
    bmi f40_tiny
    // Shift the significand into a float denormal; r3 collects the bits shifted out.
    mov r1, r1, lsl #11
    orr r1, r1, #0x80000000
    mov r3, r1, lsr #8
    orr r3, r3, r0, lsr #29
    rsb ip, ip, #1
    movs r1, r0, lsl #3
    orr r0, r2, r3, lsr ip
    rsb ip, ip, #32
    mov r3, r3, lsl ip
    orrne r3, r3, #1
    movs r1, r3
    bxeq lr
    // Inexact and underflow: trap if inexact traps are enabled, else set both flags and round.
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne f40_trap_inexact
    orr r3, r3, #0x18
    str r3, [ip]
    tst r3, #0x800000
    bne f40_mode_down
    tst r3, #0x400000
    bne f40_mode_up
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
    // Rounding up: positive results grow.
f40_mode_up:
    cmp r2, #0
    addeq r0, r0, #1
    bx lr
    // Rounding down or toward zero: down grows only negative results.
f40_mode_down:
    tst r3, #0x400000
    addeq r0, r0, r0, lsr #31
    bx lr
    // Only the rounding bit survives: round it as above.
f40_round_bit_only:
    orr r0, r0, r1, lsl #12
    movs r1, r0
    mov r0, r2
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne f40_trap_inexact
    orr r3, r3, #0x18
    str r3, [ip]
    cmp r1, #0
    tst r3, #0x800000
    bne f40_mode_down
    tst r3, #0x400000
    bne f40_mode_up
    cmp r1, #0
    addne r0, r0, #1
    bx lr
    // Too small for any float: the result is a signed zero, or the smallest denormal by the mode.
f40_tiny:
    mov r0, r2
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne f40_trap_inexact
    orr r3, r3, #0x18
    str r3, [ip]
    tst r3, #0x800000
    bne f40_mode_down
    tst r3, #0x400000
    bxeq lr
    cmp r0, #0
    addeq r0, r0, #1
    bx lr
    // Too large: trap if overflow traps are enabled, else set overflow and inexact and return infinity, or the largest
    // float when the mode rounds toward zero for this sign.
f40_overflow:
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x400
    bne f40_trap_overflow
    orr r3, r3, #0x14
    str r3, [ip]
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    tst r3, #0x800000
    bne f40_overflow_down
    tst r3, #0x400000
    subne r0, r0, r2, lsr #31
    bx lr
    // Down or toward zero: the largest float, infinity again for negative results when down.
f40_overflow_down:
    sub r0, r0, #1
    tst r3, #0x400000
    addeq r0, r0, r2, lsr #31
    bx lr
    // Overflow trap: pass the double with its exponent lowered by 0xc0 (in float terms).
f40_trap_overflow:
    sub r1, r1, #0xc000000
    and r0, r0, #0xe0000000
    stmdb sp!, {lr}
    ldr r2, f40_code_overflow
    bl func_021341e0
    ldmia sp!, {lr}
    bx lr
    // Overflow trap after rounding up: pass the double 0x3bf00000:00000000.
f40_trap_overflow_round:
    ldr r1, f40_overflow_high
    mov r0, #0
    stmdb sp!, {lr}
    ldr r2, f40_code_overflow
    bl func_021341e0
    ldmia sp!, {lr}
    bx lr
    // Underflow trap: pass the double with its exponent raised by 0xc0 (in float terms).
f40_trap_underflow:
    add r1, r1, #0xc000000
    and r0, r0, #0xe0000000
    stmdb sp!, {lr}
    ldr r2, f40_code_underflow
    bl func_021341e0
    ldmia sp!, {lr}
    bx lr
    // Invalid trap.
f40_trap_invalid:
    ldr r2, f40_code_invalid
    stmdb sp!, {lr}
    bl func_021341e0
    ldmia sp!, {lr}
    bx lr
    // Inexact trap: pass the rounded float.
f40_trap_inexact:
    stmdb sp!, {lr}
    ldr r1, f40_code_inexact
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    // Constant words: event codes and the high word passed by the overflow trap.
f40_code_overflow:
    .word 0x10000088
f40_overflow_high:
    .word 0x3bf00000
f40_code_underflow:
    .word 0x20000088
f40_code_invalid:
    .word 0x04000088
f40_code_inexact:
    .word 0x40000088
    .size func_0212ff40, . - func_0212ff40
