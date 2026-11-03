// Single-precision subtraction and 64-bit integer division.
//
// Floats are passed and returned in one register each, 64-bit integers in two (low word first); the status
// word from func_02142578 and the trap handlers are as described in code_0212f884.s.
//
// Not compiled code: _fsub and _fadd (code_02130cb4.s) branch into each other past their first instructions,
// and _fmul (code_021322c8.s) runs on into _fsub with no return; _ll_udiv has a second entry, _ull_mod,
// in its middle, and branches into the middle of _ll_sdiv and of _u32_div_f (code_02133274.s). A compiled
// function is entered only at its start. _fsub also uses tst and clz, which the 1.2 compiler never builds, and
// the division routines save ip and an odd number of registers, where 1.2 never saves ip and pads every frame to
// 8 bytes (docs/compiler.md; frame layout in the compiler).

    .text
    .extern .L_02131248
    .extern .L_0213327c
    .extern _s32_div_f
    .extern func_021340d4
    .extern func_02134238
    .extern func_02142578

// Subtracts the float r1 from r0 and returns the difference in r0, rounded as the status word says. The operands and an
// operation number (2) stay saved on the stack for the invalid-operation trap. Operands of different sign continue in
// _fadd, with the second operand negated; _fadd comes here the same way.
    .global _fsub
    .type _fsub, @function
_fsub:
    // Save the operands and the operation number 2; operands of different sign are an addition.
    mov r2, #2
    stmfd sp!, {r0, r1, r2}
    eors r2, r0, r1
    eormi r1, r1, #0x80000000
    bmi .L_02131248
    // Entry from _fadd (same signs). Order the operands so that |r0| >= |r1|; swapping them flips the sign of the
    // result.
    .global .L_02132a0c
.L_02132a0c:
    subs ip, r0, r1
    eorlo ip, ip, #0x80000000
    sublo r0, r0, ip
    addlo r1, r1, ip
    // Unpack the first operand: r3 = sign and exponent, r0 = significand shifted up 8 with the leading one set.
    // Exponent 0 or 0xff goes to the special cases.
fsub_unpack:
    mov r2, #0x80000000
    mov r3, r0, lsr #23
    orr r0, r2, r0, lsl #8
    ands ip, r3, #0xff
    cmpne ip, #255
    beq fsub_a_special
    // Unpack the second operand the same way into ip and r1.
    mov ip, r1, lsr #23
    orr r1, r2, r1, lsl #8
    ands r2, ip, #0xff
    beq fsub_b_special
    // Shift the smaller significand right by the exponent difference, folding the bits shifted out into its lowest bit
    // (the shift stops at 31), and subtract. If the difference lost its leading one it is normalised again.
fsub_align:
    subs ip, r3, ip
    beq fsub_same_exponent
    cmp ip, #28
    movge ip, #31
    rsb r2, ip, #32
    movs r2, r1, lsl r2
    mov r1, r1, lsr ip
    orrne r1, r1, #1
    subs r0, r0, r1
    bpl fsub_renormalise
    // Pack: r1 = the 8 bits shifted out (bit 7 the rounding bit). Exact results return here.
    ands r1, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    addeq sp, sp, #12
    bxeq lr
    // Inexact: trap if enabled, else set the flag and round as the mode says; nearest even rounds up when above half,
    // or exactly half and odd.
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne fsub_trap_inexact
    orr r3, r3, #0x10
    str r3, [ip]
    tst r3, #0x800000
    bne fsub_mode_down
    tst r3, #0x400000
    bne fsub_mode_up
    tst r1, #0x80
    addeq sp, sp, #12
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    add sp, sp, #12
    bx lr
    // Rounding up: positive results grow.
fsub_mode_up:
    cmp r0, #0
    addpl r0, r0, #1
    add sp, sp, #12
    bx lr
    // Rounding down or toward zero: down grows only negative results.
fsub_mode_down:
    tst r3, #0x400000
    addne sp, sp, #12
    bxne lr
    cmp r0, #0
    addmi r0, r0, #1
    add sp, sp, #12
    bx lr
    // Equal exponents: the difference is exact. Zero is handled at fsub_zero; otherwise shift the leading one back to
    // bit 31 with clz. If the exponent stays above 0 pack, else shift it into a denormal.
fsub_same_exponent:
    subs r0, r0, r1
    beq fsub_zero
    mov r2, r3, lsl #23
    and r2, r2, #0x80000000
    bic r3, r3, #0x100
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    cmp r3, #0
    bgt fsub_same_pack
    rsb r3, r3, #9
    orr r0, r2, r0, lsr r3
    add sp, sp, #12
    bx lr
    // Pack.
fsub_same_pack:
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    add sp, sp, #12
    bx lr
    // The difference lost its leading one: shift it back with clz. If the exponent stays above 0 round it at
    // fsub_round; otherwise it is a denormal, exact, shifted into place.
fsub_renormalise:
    mov r2, r3, lsl #23
    and r2, r2, #0x80000000
    bic r3, r3, #0x100
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    cmp r3, #0
    bgt fsub_round
    rsb r3, r3, #9
    orr r0, r2, r0, lsr r3
    add sp, sp, #12
    bx lr
    // Pack with the sign in r2 and round as at fsub_pack.
fsub_round:
    ands r1, r0, #0xff
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    addeq sp, sp, #12
    bxeq lr
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne fsub_trap_inexact
    orr r3, r3, #0x10
    str r3, [ip]
    tst r3, #0x800000
    bne fsub_mode_down
    tst r3, #0x400000
    bne fsub_mode_up
    tst r1, #0x80
    addeq sp, sp, #12
    bxeq lr
    ands r1, r1, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    add sp, sp, #12
    bx lr
    // First operand has exponent 0 or 0xff. r2 = its sign. Exponent 0 is handled below; a NaN goes to fsub_a_nan;
    // infinity minus infinity is invalid, infinity minus anything else is infinity.
fsub_a_special:
    cmp r3, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    ands r3, r3, #0xff
    beq fsub_a_small
    movs r0, r0, lsl #1
    bne fsub_a_nan
    mov ip, r1, lsr #23
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq fsub_return_inf
    cmp ip, #255
    blt fsub_return_inf
    cmp r1, #0
    beq fsub_invalid
    b fsub_b_nan
    // Second operand has exponent 0 (or 0xff when reached from fsub_a_small); r2 = the sign of the result if it is an
    // infinity.
fsub_b_special:
    cmp ip, #0x100
    movge r2, #0x80000000
    movlt r2, #0
    and r3, r3, #0xff
    ands ip, ip, #0xff
    beq fsub_b_small
fsub_b_inf_or_nan:
    eor r2, r2, #0x80000000
    movs r1, r1, lsl #1
    bne fsub_b_nan
    b fsub_return_inf
    // First operand has exponent 0. Zero: see fsub_a_zero. Denormal: exponent 1, no leading one.
fsub_a_small:
    movs r0, r0, lsl #1
    beq fsub_a_zero
    mov r0, r0, lsr #1
    mov r3, #1
    mov ip, r1, lsr #23
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq fsub_b_small
    cmp ip, #255
    beq fsub_b_inf_or_nan
    orr r1, r1, #0x80000000
    orr r3, r3, r2, lsr #23
    orr ip, ip, r2, lsr #23
    b fsub_align
    // First operand is zero: unpack the second. Zero gives fsub_zero, a NaN the NaN path, infinity infinity, anything
    // else the second operand.
fsub_a_zero:
    mov r3, r1, lsr #23
    mov r0, r1, lsl #9
    ands r2, r3, #0xff
    beq fsub_both_exponent_zero
    cmp r2, #255
    blt fsub_return_b
    cmp r0, #0
    bne fsub_b_nan_a_zero
    b fsub_return_inf
fsub_both_exponent_zero:
    cmp r0, #0
    beq fsub_zero
    b fsub_return_b
    // Second operand has exponent 0. Zero: return the first. Denormal: exponent 1, no leading one.
fsub_b_small:
    movs r1, r1, lsl #1
    beq fsub_return_a
    mov r1, r1, lsr #1
    mov ip, #1
    orr ip, ip, r2, lsr #23
    orr r3, r3, r2, lsr #23
    b fsub_align
    // Return the second operand.
fsub_return_b:
    mov r0, r1
    add sp, sp, #12
    bx lr
    // The second operand is zero: return the first, repacked.
fsub_return_a:
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    add sp, sp, #12
    bx lr
    // An exact zero result: +0, or -0 when rounding down.
fsub_zero:
    mov r0, #0
    stmfd sp!, {r0, r1, r2, ip, lr}
    bl func_02142578
    mov r3, r0
    ldmfd sp!, {r0, r1, r2, ip, lr}
    ldr r3, [r3]
    tst r3, #0x800000
    addeq sp, sp, #12
    bxeq lr
    tst r3, #0x400000
    addne sp, sp, #12
    bxne lr
    mov r0, #0x80000000
    add sp, sp, #12
    bx lr
    // Pack the first operand (no branch reaches this block).
    cmp r0, #0
    subges r3, r3, #1
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    add sp, sp, #12
    bx lr
    // First operand zero, second a NaN: the default NaN. A signalling NaN also sets invalid; this path does not check
    // the trap enable.
fsub_b_nan_a_zero:
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
    // Return infinity with the sign in r2.
fsub_return_inf:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    add sp, sp, #12
    bx lr
    // First operand is a NaN. A signalling NaN is invalid. A quiet one gives the default NaN, invalid only when the
    // second operand is a signalling NaN.
fsub_a_nan:
    tst r0, #0x80000000
    beq fsub_invalid
    mov ip, r1, lsr #23
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq fsub_default_nan
    cmp ip, #255
    blt fsub_default_nan
    cmp r1, #0
    beq fsub_default_nan
    // Second operand is a NaN: signalling is invalid, quiet gives the default NaN.
fsub_b_nan:
    tst r1, #0x80000000
    beq fsub_invalid
    mvn r0, #0x80000000
    add sp, sp, #12
    bx lr
    // Invalid operation: trap if enabled, else set the flag and return the default NaN.
fsub_invalid:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne fsub_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
    // Return the default NaN.
fsub_default_nan:
    mvn r0, #0x80000000
    add sp, sp, #12
    bx lr
    // Inexact trap: pass the rounded result.
fsub_trap_inexact:
    add sp, sp, #12
    stmdb sp!, {lr}
    mov r1, #0x40000002
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    // Invalid trap: pass the operands and the operation number from the stack.
fsub_trap_invalid:
    ldmfd sp!, {r0, r1, r2}
    stmdb sp!, {lr}
    mov ip, #0x4000000
    orr r2, r2, ip
    bl func_021340d4
    ldmia sp!, {lr}
    bx lr
    .size _fsub, . - _fsub

// Unsigned 64-bit division: r1:r0 divided by r3:r2 gives the quotient in r1:r0. _ull_mod, its second entry, gives the
// remainder instead. r4 says which (0 quotient, 1 remainder). Division by zero returns the dividend. When both operands
// fit in 32 bits it uses the 32-bit division in _u32_div_f; otherwise the long division in _ll_sdiv. A third entry at
// its end (signed remainder) is not used by anything.
    .global _ll_udiv
    .type _ll_udiv, @function
_ll_udiv:
    // Quotient entry: r4 = 0.
    stmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
    mov r4, #0
    b lludiv_check
    // Remainder entry: r4 = 1.
    .global _ull_mod
_ull_mod:
    stmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
    mov r4, #1
    // Division by zero returns the dividend.
lludiv_check:
    orrs r5, r3, r2
    bne lludiv_divide
    ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
    // Both high words zero: 32-bit division (quotient in r0, remainder in r1); otherwise the long division of _ll_sdiv.
lludiv_divide:
    orrs r5, r1, r3
    bne lldiv_unsigned
    mov r1, r2
    bl .L_0213327c
    cmp r4, #0
    movne r0, r1
    mov r1, #0
    ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
    // Signed remainder entry: r4 = the dividend's sign, bit 0 set.
    stmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
    mov r4, r1
    orr r4, r4, #1
    b lldiv_zero_check
    .size _ll_udiv, . - _ll_udiv

// Signed 64-bit division: r1:r0 divided by r3:r2 gives the quotient in r1:r0, rounded toward zero. r4 holds the sign of
// the result in bit 31 and, in bit 0, whether the remainder is wanted (the entries in _ll_udiv set it). Division by
// zero returns the dividend. Operands that fit in 32 bits use _s32_div_f; otherwise both are made positive and divided
// by shift-and-subtract, one quotient bit per step, then the sign is applied.
    .global _ll_sdiv
    .type _ll_sdiv, @function
_ll_sdiv:
    // r4 = the sign of the quotient, bit 0 clear (quotient wanted).
    stmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
    eor r4, r1, r3
    mov r4, r4, asr #1
    mov r4, r4, lsl #1
    // Division by zero returns the dividend.
lldiv_zero_check:
    orrs r5, r3, r2
    bne lldiv_divide
    ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
    // Both operands fit in 32 bits (each high word is the sign of its low word): 32-bit signed division, the result
    // sign-extended.
lldiv_divide:
    mov r5, r0, lsr #31
    add r5, r5, r1
    mov r6, r2, lsr #31
    add r6, r6, r3
    orrs r6, r5, r6
    bne lldiv_long
    mov r1, r2
    bl _s32_div_f
    ands r4, r4, #1
    movne r0, r1
    mov r1, r0, asr #31
    ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
    // Make both operands positive.
lldiv_long:
    cmp r1, #0
    bge lldiv_divisor_sign
    rsbs r0, r0, #0
    rsc r1, r1, #0
lldiv_divisor_sign:
    cmp r3, #0
    bge lldiv_unsigned
    rsbs r2, r2, #0
    rsc r3, r3, #0
    // Unsigned long division. A zero dividend gives 0. r5 counts the places the divisor is shifted up until its top bit
    // is set; r6 = the number of quotient bits, less one for each place the dividend is shifted up.
lldiv_unsigned:
    orrs r5, r1, r0
    beq lldiv_zero
    mov r5, #0
    mov r6, #1
    cmp r3, #0
    bmi lldiv_shift_dividend_check
lldiv_shift_divisor:
    add r5, r5, #1
    adds r2, r2, r2
    adcs r3, r3, r3
    bpl lldiv_shift_divisor
    add r6, r6, r5
lldiv_shift_dividend_check:
    cmp r1, #0
    blt lldiv_start
lldiv_shift_dividend:
    cmp r6, #1
    beq lldiv_start
    sub r6, r6, #1
    adds r0, r0, r0
    adcs r1, r1, r1
    bpl lldiv_shift_dividend
    // r7:r1:r0 is the partial remainder, r11:ip the quotient. Each step shifts both up one place and subtracts the
    // divisor (or adds it back while the remainder is negative); a non-negative remainder gives a quotient bit of 1.
lldiv_start:
    mov r7, #0
    mov ip, #0
    mov r11, #0
    b lldiv_subtract
lldiv_bit_one:
    orr ip, ip, #1
    subs r6, r6, #1
    beq lldiv_result
    adds r0, r0, r0
    adcs r1, r1, r1
    adcs r7, r7, r7
lldiv_subtract:
    subs r0, r0, r2
    sbcs r1, r1, r3
    sbcs r7, r7, #0
    adds ip, ip, ip
    adc r11, r11, r11
    cmp r7, #0
    bge lldiv_bit_one
lldiv_bit_zero:
    subs r6, r6, #1
    beq lldiv_restore
    adds r0, r0, r0
    adcs r1, r1, r1
    adc r7, r7, r7
    adds r0, r0, r2
    adcs r1, r1, r3
    adc r7, r7, #0
    adds ip, ip, ip
    adc r11, r11, r11
    cmp r7, #0
    bge lldiv_bit_one
    b lldiv_bit_zero
    // Negative at the end: add the divisor back.
lldiv_restore:
    adds r0, r0, r2
    adc r1, r1, r3
    // Quotient wanted: r11:ip. Remainder wanted: shift it back down by r5.
lldiv_result:
    ands r7, r4, #1
    moveq r0, ip
    moveq r1, r11
    beq lldiv_sign
    subs r7, r5, #32
    movge r0, r1, lsr r7
    bge lldiv_high_zero
    rsb r7, r5, #32
    mov r0, r0, lsr r5
    orr r0, r0, r1, lsl r7
    mov r1, r1, lsr r5
    b lldiv_sign
    // (no branch reaches these two instructions)
    mov r0, r1, lsr r7
    mov r1, #0
    // Apply the sign.
lldiv_sign:
    cmp r4, #0
    blt lldiv_negate
    ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
lldiv_negate:
    rsbs r0, r0, #0
    rsc r1, r1, #0
    ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
    // A zero result.
lldiv_zero:
    mov r0, #0
lldiv_high_zero:
    mov r1, #0                          // (entry: high word of a remainder shifted 32 or more)
    cmp r4, #0
    blt lldiv_negate
    ldmfd sp!, {r4, r5, r6, r7, r11, ip, lr}
    bx lr
    .size _ll_sdiv, . - _ll_sdiv
