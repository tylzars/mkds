// Double-precision subtraction (also reversed) and single-precision addition.
//
// Arguments and results, the status word from func_02142578 and the trap handlers are as described in
// code_0212f884.s; floats are passed and returned in one register each.
//
// Not compiled code: func_02130cb4 has no return and runs on into _dsub; _dsub and _dadd (code_0212f884.s), and
// _fadd and _fsub (code_021329f8.s), branch into each other past their first instructions, where a compiled
// function is entered only at its start. All three also use tst, which the 1.2 compiler never builds
// (docs/compiler.md).

    .text
    .extern .L_0212f894
    .extern .L_02132a0c
    .extern func_0213406c
    .extern func_021340d4
    .extern func_0213412c
    .extern func_02134238
    .extern func_02142578

// Reversed subtraction: swaps the doubles r1:r0 and r3:r2 (three exclusive ors per word) and runs on into _dsub, so it
// returns r3:r2 minus r1:r0.
    .global func_02130cb4
    .type func_02130cb4, @function
func_02130cb4:
    // Swap r1:r0 and r3:r2.
    eor r1, r1, r3
    eor r3, r1, r3
    eor r1, r1, r3
    eor r0, r0, r2
    eor r2, r0, r2
    eor r0, r0, r2
    .size func_02130cb4, . - func_02130cb4

// Subtracts the double r3:r2 from r1:r0 and returns the difference in r1:r0, rounded as the status word says. Operands
// of different sign continue in _dadd, with the second operand negated; _dadd comes here the same way. The operands
// stay saved on the stack for the invalid-operation trap.
    .global _dsub
    .type _dsub, @function
_dsub:
    // Save the operands; operands of different sign are an addition.
    stmfd sp!, {r0, r1, r2, r3, r4, lr}
    eors ip, r1, r3
    eormi r3, r3, #0x80000000           // different signs: negate the second operand
    bmi .L_0212f894                     // and add
    // Entry from _dadd (same signs). Order the operands so that |r1:r0| >= |r3:r2|; swapping them flips the sign of the
    // result.
    .global .L_02130cdc
.L_02130cdc:
    subs ip, r0, r2
    sbcs lr, r1, r3
    bhs dsub_unpack
    eor lr, lr, #0x80000000
    adds r2, r2, ip
    adc r3, r3, lr
    subs r0, r0, ip
    sbc r1, r1, lr
    // Unpack the first operand: ip = sign and exponent, r1:r0 = significand shifted up 11 with the leading one set.
    // Exponent 0 or 0x7ff goes to the special cases.
dsub_unpack:
    mov lr, #0x80000000
    mov ip, r1, lsr #20
    orr r1, lr, r1, lsl #11
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #11
    movs r4, ip, lsl #21
    cmnne r4, #0x200000
    beq dsub_a_special
    // Unpack the second operand the same way into r4 and r3:r2.
    mov r4, r3, lsr #20
    orr r3, lr, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs lr, r4, lsl #21
    beq dsub_b_special
    // Shift the smaller significand right by the exponent difference, folding the bits shifted out into its lowest bit,
    // and subtract. Above 32 places only one word is left (the shift stops at 63). If the difference lost its leading
    // one it is normalised again.
dsub_align:
    subs r4, ip, r4
    beq dsub_same_exponent
    cmp r4, #32
    ble dsub_align_short
    cmp r4, #56
    movge r4, #63                       // 56 or more: only a sticky bit remains
    sub r4, r4, #32
    rsb lr, r4, #32
    orrs lr, r2, r3, lsl lr
    mov r2, r3, lsr r4
    orrne r2, r2, #1
    subs r0, r0, r2
    sbcs r1, r1, #0
    bmi dsub_pack                       // leading one kept
    b dsub_renormalise
    // A difference of 1 to 32 places: shift across both words.
dsub_align_short:
    rsb lr, r4, #32
    movs lr, r2, lsl lr
    rsb lr, r4, #32
    mov r2, r2, lsr r4
    orr r2, r2, r3, lsl lr
    mov r3, r3, lsr r4
    orrne r2, r2, #1
    subs r0, r0, r2
    sbcs r1, r1, r3
    bpl dsub_renormalise
    // Pack: r2 = the 11 bits below the result (bit 31 the rounding bit, the rest sticky), r1:r0 = the rounded-down
    // result. Exact results return here.
dsub_pack:
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
    bne dsub_trap_inexact
    orr r3, r3, #0x10
    str r3, [ip]
    tst r3, #0x800000
    bne dsub_mode_down
    tst r3, #0x400000
    bne dsub_mode_up
    // Nearest even: round up when the shifted-out bits are above half, or exactly half and the result odd.
    tst r2, #0x80000000
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Rounding up: only positive results grow.
dsub_mode_up:
    cmp r1, #0
    addmi sp, sp, #16
    ldmmifd sp!, {r4, lr}
    bxmi lr
    adds r0, r0, #1
    adc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Rounding down or toward zero: down grows only negative results.
dsub_mode_down:
    tst r3, #0x400000
    addne sp, sp, #16
    ldmnefd sp!, {r4, lr}
    bxne lr
    adds r0, r0, r1, lsr #31
    adc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Equal exponents: the difference is exact. Zero is handled at dsub_zero; otherwise shift the leading one back to
    // bit 63 (a whole word at a time, then with clz).
dsub_same_exponent:
    subs r0, r0, r2
    sbc r1, r1, r3
    orrs lr, r1, r0
    beq dsub_zero
    mov lr, ip, lsl #20
    and lr, lr, #0x80000000
    bic ip, ip, #0x800
    cmp r1, #0
    bmi dsub_same_normal
    bne dsub_same_clz
    sub ip, ip, #32
    movs r1, r0
    mov r0, #0
    bmi dsub_same_check
dsub_same_clz:
    clz r4, r1
    movs r1, r1, lsl r4
    rsb r4, r4, #32
    orr r1, r1, r0, lsr r4
    rsb r4, r4, #32
    mov r0, r0, lsl r4
    sub ip, ip, r4
    // Exponent still above 0: pack. Otherwise the result is a denormal: shift it right into place (no bits are lost)
    // and return.
dsub_same_check:
    cmp ip, #0
    bgt dsub_same_pack
    rsb ip, ip, #12
    cmp ip, #32
    movge r0, r1
    movge r1, #0
    subge ip, ip, #32
    rsb r4, ip, #32
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Leading one already in bit 63: pack.
dsub_same_normal:
    cmp r1, #0
    subges ip, ip, #1
dsub_same_pack:
    mov r0, r0, lsr #11
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // The difference lost its leading one: shift it back up (a whole word at a time, then with clz). If the exponent
    // stays above 0 round it at dsub_pack; otherwise it is a denormal, exact, shifted into place.
dsub_renormalise:
    mov lr, ip, lsl #20
    and lr, lr, #0x80000000
    bic ip, ip, #0x800
    cmp r1, #0
    bne dsub_renormalise_clz
    sub ip, ip, #32
    movs r1, r0
    mov r0, #0
    bmi dsub_renormalise_check
dsub_renormalise_clz:
    clz r4, r1
    movs r1, r1, lsl r4
    rsb r4, r4, #32
    orr r1, r1, r0, lsr r4
    rsb r4, r4, #32
    mov r0, r0, lsl r4
    sub ip, ip, r4
dsub_renormalise_check:
    cmp ip, #0
    orrgt ip, ip, lr, lsr #20
    bgt dsub_pack
    rsb ip, ip, #12
    cmp ip, #32
    movge r0, r1
    movge r1, #0
    subge ip, ip, #32
    rsb r4, ip, #32
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // First operand has exponent 0 or 0x7ff. lr = its sign. Exponent 0 is handled below; a NaN goes to dsub_a_nan;
    // infinity minus infinity is invalid, infinity minus anything else is infinity.
dsub_a_special:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bics ip, ip, #0x800
    beq dsub_a_small
    orrs r4, r0, r1, lsl #1
    bne dsub_a_nan
    mov r4, r3, lsr #20
    mov r3, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs r4, r4, lsl #21
    beq dsub_return_inf
    cmn r4, #0x200000
    bne dsub_return_inf
    orrs r4, r2, r3, lsl #1
    beq dsub_invalid
    b dsub_b_nan
    // Second operand has exponent 0 (or 0x7ff when reached from dsub_a_small).
dsub_b_special:
    cmp r4, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bic ip, ip, #0x800
    bics r4, r4, #0x800
    beq dsub_b_small
    orrs r4, r2, r3, lsl #1
    bne dsub_b_nan
    b dsub_return_inf
    // First operand has exponent 0. Zero: see dsub_a_zero. Denormal: it has exponent 1 and no leading one.
dsub_a_small:
    orrs r4, r0, r1, lsl #1
    beq dsub_a_zero
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
    beq dsub_b_special
    orr r3, r3, #0x80000000
    orr ip, ip, lr, lsr #20
    b dsub_align
    // First operand is zero: unpack the second. Zero gives dsub_zero, a NaN the NaN path, infinity infinity, anything
    // else the second operand.
dsub_a_zero:
    mov ip, r3, lsr #20
    mov r1, r3, lsl #11
    orr r1, r1, r2, lsr #21
    mov r0, r2, lsl #11
    movs r4, ip, lsl #21
    beq dsub_both_exponent_zero
    cmn r4, #0x200000
    bne dsub_return_b
    orrs r4, r0, r1, lsl #1
    bne dsub_b_nan_in_r1
    b dsub_return_inf
    // Both have exponent 0 and the first is zero: zero minus zero is dsub_zero.
dsub_both_exponent_zero:
    orrs r4, r0, r1, lsl #1
    beq dsub_zero
    b dsub_return_b
    // Second operand zero: the result is the first. Denormal: exponent 1, no leading one.
dsub_b_small:
    orrs r4, r2, r3, lsl #1
    beq dsub_return_a
    mov r4, #1
    bic r3, r3, #0x80000000
    orr ip, ip, lr, lsr #20
    orr r4, r4, lr, lsr #20
    b dsub_align
    // Return the second operand.
dsub_return_b:
    mov r1, r3
    mov r0, r2
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // The second operand is zero: return the first, repacked.
dsub_return_a:
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
dsub_return_inf:
    ldr r1, dsub_inf_high
    orr r1, lr, r1
    mov r0, #0
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // First operand is a NaN. A signalling NaN is invalid. A quiet one gives the default NaN, which is invalid only
    // when the second operand is a signalling NaN.
dsub_a_nan:
    tst r1, #0x40000000
    beq dsub_invalid
    mov r4, r3, lsr #20
    mov r3, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #11
    movs r4, r4, lsl #21
    beq dsub_default_nan
    cmn r4, #0x200000
    bne dsub_default_nan
    orrs r4, r2, r3, lsl #1
    beq dsub_default_nan
    // Second operand is a NaN: the default NaN, invalid when it is signalling.
dsub_b_nan:
    mov r1, r3                          // its high word is in r3
dsub_b_nan_in_r1:
    mov r3, r1                          // (entry with it in r1)
    mvn r0, #0
    bic r1, r0, #0x80000000
    tst r3, #0x40000000
    addne sp, sp, #16
    ldmnefd sp!, {r4, lr}
    bxne lr
    // Invalid operation: trap if enabled, else set the flag and return the default NaN in r1:r0.
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne dsub_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Invalid operation (also infinity minus infinity): raise invalid, return the default NaN.
dsub_invalid:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne dsub_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
dsub_default_nan:
    mvn r0, #0
    bic r1, r0, #0x80000000
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // An exact zero result: +0, or -0 when rounding down.
dsub_zero:
    mov r1, #0
    mov r0, #0
    stmfd sp!, {r0, r1, r2, ip, lr}
    bl func_02142578
    mov r3, r0
    ldmfd sp!, {r0, r1, r2, ip, lr}
    ldr r3, [r3]
    tst r3, #0x800000
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, lr}
    bxeq lr
    tst r3, #0x400000
    addne sp, sp, #16
    ldmnefd sp!, {r4, lr}
    bxne lr
    mov r1, #0x80000000
    add sp, sp, #16
    ldmfd sp!, {r4, lr}
    bx lr
    // Invalid trap: pass the original operands from the stack.
dsub_trap_invalid:
    ldmfd sp!, {r0, r1, r2, r3}
    ldr ip, dsub_code_invalid
    stmdb sp!, {ip}
    bl func_0213406c
    add sp, sp, #4
    ldmfd sp!, {r4, lr}
    bx lr
    // Inexact trap: pass the rounded result.
dsub_trap_inexact:
    add sp, sp, #16
    ldr r2, dsub_code_inexact
    bl func_0213412c
    ldmfd sp!, {r4, lr}
    bx lr
    // Constant words: the high word of infinity and the event codes.
dsub_inf_high:
    .word 0x7ff00000
dsub_code_invalid:
    .word 0x04000092
dsub_code_inexact:
    .word 0x40000092
    .size _dsub, . - _dsub

// Adds the floats r0 and r1 and returns the sum in r0, rounded as the status word says. The operands and an operation
// number (1) stay saved on the stack for the invalid-operation trap. Operands of different sign continue in _fsub, with
// the second operand negated; _fsub comes here the same way.
    .global _fadd
    .type _fadd, @function
_fadd:
    // Save the operands and the operation number 1; operands of different sign are a subtraction.
    mov r2, #1
    stmfd sp!, {r0, r1, r2}
    eors r2, r0, r1
    eormi r1, r1, #0x80000000           // different signs: negate the second operand
    bmi .L_02132a0c                     // and subtract
    // Entry from _fsub (same signs). Order the operands so that |r0| >= |r1|.
    .global .L_02131248
.L_02131248:
    subs ip, r0, r1
    sublo r0, r0, ip
    addlo r1, r1, ip
    // Unpack the first operand: r3 = sign and exponent, r0 = significand shifted up 8 with the leading one set.
    // Exponent 0 or 0xff goes to the special cases.
fadd_unpack:
    mov r2, #0x80000000
    mov r3, r0, lsr #23
    orr r0, r2, r0, lsl #8
    ands ip, r3, #0xff
    cmpne ip, #255
    beq fadd_a_special
    // Unpack the second operand the same way into ip and r1.
    mov ip, r1, lsr #23
    orr r1, r2, r1, lsl #8
    ands r2, ip, #0xff
    beq fadd_b_small
    // Shift the smaller significand right by the exponent difference, folding the bits shifted out into its lowest bit
    // (the shift stops at 31).
fadd_align:
    subs ip, r3, ip
    beq fadd_sum
    cmp ip, #28
    movge ip, #31                       // 28 or more: only a sticky bit remains
    rsb r2, ip, #32
    movs r2, r1, lsl r2
    mov r1, r1, lsr ip
    orrne r1, r1, #1
    // Add. A carry out shifts the sum right one place back through the carry, keeping the bit shifted out, and raises
    // the exponent; reaching 0xff overflows.
fadd_sum:
    adds r0, r0, r1
    blo fadd_pack
    and r1, r0, #1
    orr r0, r1, r0, rrx
    add r3, r3, #1
    and r2, r3, #0xff
    cmp r2, #255
    beq fadd_overflow
    // Pack: r1 = the 8 bits below the result (bit 7 the rounding bit). Exact results return here.
fadd_pack:
    ands r1, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    addeq sp, sp, #12
    bxeq lr
    // Inexact: trap if enabled, else set the flag and round as the mode says.
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne fadd_trap_inexact
    orr r3, r3, #0x10
    str r3, [ip]
    tst r3, #0x800000
    bne fadd_mode_down
    tst r3, #0x400000
    bne fadd_mode_up
    // Nearest even: round up when above half, or exactly half and odd.
    tst r1, #0x80
    addeq sp, sp, #12
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addeq sp, sp, #12
    bxeq lr
    // Round up the magnitude; reaching exponent 0xff is an overflow.
fadd_round_up:
    add r0, r0, #1
    mov r1, r0, lsl #1
    cmn r1, #0x1000000
    addlo sp, sp, #12
    bxlo lr
    tst r3, #0x400
    bne fadd_trap_overflow_round
    orr r3, r3, #0x14
    str r3, [ip]
    add sp, sp, #12
    bx lr
    // Rounding up: only positive results grow.
fadd_mode_up:
    cmp r0, #0
    bpl fadd_round_up
    add sp, sp, #12
    bx lr
    // Rounding down or toward zero: down grows only negative results.
fadd_mode_down:
    tst r3, #0x400000
    addne sp, sp, #12
    bxne lr
    cmp r0, #0
    bmi fadd_round_up
    add sp, sp, #12
    bx lr
    // First operand has exponent 0 or 0xff. r2 = its sign. Exponent 0 is handled below; a NaN goes to fadd_a_nan, an
    // infinity is the result unless the second operand is a NaN.
fadd_a_special:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    ands r3, r3, #0xff
    beq fadd_a_small
    movs r0, r0, lsl #1
    bne fadd_a_nan
    mov ip, r1, lsr #23
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq fadd_return_inf
    cmp ip, #255
    blt fadd_return_inf
    cmp r1, #0
    beq fadd_return_inf
    b fadd_b_nan
    // Second operand has exponent 0 (or 0xff when reached from fadd_a_small).
fadd_b_small:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    and r3, r3, #0xff
    ands ip, ip, #0xff
    beq fadd_b_exponent_zero
fadd_b_inf_or_nan:
    movs r1, r1, lsl #1
    bne fadd_b_nan
    b fadd_return_inf
    // First operand has exponent 0. Zero: see fadd_a_zero. Denormal: exponent 1, no leading one.
fadd_a_small:
    movs r0, r0, lsl #1
    beq fadd_a_zero
    mov r3, #1
    mov r0, r0, lsr #1
    mov ip, r1, lsr #23
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq fadd_b_exponent_zero
    cmp ip, #255
    beq fadd_b_inf_or_nan
    orr r1, r1, #0x80000000
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    b fadd_align
    // First operand is zero: return the second; an infinity gives infinity, a NaN the NaN path.
fadd_a_zero:
    mov r3, r1, lsr #23
    mov r0, r1, lsl #9
    ands r3, r3, #0xff
    beq fadd_return_b
    cmp r3, #255
    blt fadd_return_b
    cmp r0, #0
    beq fadd_return_inf
    b fadd_b_nan_a_zero
    // Second operand has exponent 0. Zero: return the first. Denormal: exponent 1, no leading one; if the first is a
    // denormal too, add them here.
fadd_b_exponent_zero:
    movs r1, r1, lsl #1
    beq fadd_return_a
    mov r1, r1, lsr #1
    mov ip, #1
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    cmp r0, #0
    bmi fadd_align
    adds r0, r0, r1
    blo fadd_denormal_pack
    and r1, r0, #1
    orr r0, r1, r0, rrx
    add ip, ip, #1
    // Pack the denormal sum (exponent 1 if it reached a leading one, else 0) and round it.
fadd_denormal_pack:
    cmp r0, #0
    subge ip, ip, #1
    ands r1, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, ip, lsl #23
    addeq sp, sp, #12
    bxeq lr
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne fadd_trap_inexact
    orr r3, r3, #0x10
    str r3, [ip]
    tst r3, #0x800000
    bne fadd_mode_down
    tst r3, #0x400000
    bne fadd_mode_up
    tst r1, #0x80
    addeq sp, sp, #12
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    add sp, sp, #12
    bx lr
    // Return the second operand.
fadd_return_b:
    mov r0, r1
    add sp, sp, #12
    bx lr
    // The second operand is zero: return the first, repacked.
fadd_return_a:
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    add sp, sp, #12
    bx lr
    // Overflow: trap if enabled, else set overflow and inexact. Nearest gives infinity, toward zero the largest float,
    // up and down one or the other by the sign.
fadd_overflow:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x400
    bne fadd_trap_overflow
    orr r3, r3, #0x14
    str r3, [ip]
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    tst r3, #0x800000
    bne fadd_overflow_down
    tst r3, #0x400000
    subne r0, r0, r2, lsr #31
    add sp, sp, #12
    bx lr
    // Down or toward zero: the largest float, infinity again for negative results when down.
fadd_overflow_down:
    sub r0, r0, #1
    tst r3, #0x400000
    addeq r0, r0, r2, lsr #31
    add sp, sp, #12
    bx lr
    // First operand zero, second a NaN: the default NaN. A signalling NaN also sets invalid; this path does not check
    // the trap enable.
fadd_b_nan_a_zero:
    mov r3, r0
    mvn r0, #0x80000000
    tst r3, #0x80000000
    addne sp, sp, #12
    bxne lr
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    orr r3, r3, #1
    str r3, [r2]
    add sp, sp, #12
    bx lr
    // Return infinity with the first operand's sign.
fadd_return_inf:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    add sp, sp, #12
    bx lr
    // First operand is a NaN. A signalling NaN is invalid. A quiet one gives the default NaN, invalid only when the
    // second operand is a signalling NaN.
fadd_a_nan:
    tst r0, #0x80000000
    beq fadd_invalid
    mov ip, r1, lsr #23
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq fadd_default_nan
    cmp ip, #255
    blt fadd_default_nan
    cmp r1, #0
    beq fadd_default_nan
    // Second operand is a NaN: signalling is invalid, quiet gives the default NaN.
fadd_b_nan:
    tst r1, #0x80000000
    beq fadd_invalid
    mvn r0, #0x80000000
    add sp, sp, #12
    bx lr
    // Invalid operation: trap if enabled, else set the flag.
fadd_invalid:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne fadd_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
    // Return the default NaN.
fadd_default_nan:
    mvn r0, #0x80000000
    add sp, sp, #12
    bx lr
    // Overflow trap after rounding: pass the result with its exponent wrapped down by 0xc0.
fadd_trap_overflow_round:
    add sp, sp, #12
    sub r0, r0, #0x60000000
    stmdb sp!, {lr}
    mov r1, #0x10000001
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    // Overflow trap while adding: pass the sum with its exponent wrapped down by 0xc0.
fadd_trap_overflow:
    add sp, sp, #12
    orr r0, r2, r0, lsr #8
    add r0, r0, #0x1f000000
    stmdb sp!, {lr}
    mov r1, #0x10000001
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    // Invalid trap: pass the operands and the operation number from the stack.
fadd_trap_invalid:
    ldmfd sp!, {r0, r1, r2}
    stmdb sp!, {lr}
    mov ip, #0x4000000
    orr r2, r2, ip
    bl func_021340d4
    ldmia sp!, {lr}
    bx lr
    // Inexact trap: pass the rounded result.
fadd_trap_inexact:
    add sp, sp, #12
    stmdb sp!, {lr}
    mov r1, #0x40000001
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    .size _fadd, . - _fadd
