// Float to integer and integer to float conversions, and single-precision multiplication.
//
// Floats are passed and returned in one register each; the status word from func_02142578 and the trap
// handlers are as described in code_0212f884.s.
//
// Not compiled code: _ffix branches into the middle of func_02132364, and the conversion to float at _fflt is a
// second entry in the middle of func_021323c4, called from other code; _fmul ends in an entry that has
// no return and runs on into _fsub (code_021329f8.s). A compiled function is entered only at its start and ends
// in a return. All of it also uses tst, and _fflt, func_021323c4 and _fmul clz, which the 1.2 compiler
// never builds (docs/compiler.md).

    .text
    .extern func_021340d4
    .extern func_02134238
    .extern func_02142578

// Converts the float r0 to a signed integer in r0, dropping the fraction (inexact, or a trap, when bits are lost).
// Values outside the integer range continue in func_02132364.
    .global _ffix
    .type _ffix, @function
_ffix:
    // r1 = the magnitude; r2 = 0x9e - exponent is the right shift that turns the significand into the integer: 0 or
    // less is out of range, 32 or more means below 1.
    bic r1, r0, #0x80000000
    mov r2, #158
    subs r2, r2, r1, lsr #23
    ble ffix_too_large                  // too large
    cmp r2, #32
    bge ffix_below_one                  // below 1
    // Shift the significand with its leading one into place and apply the sign; lost bits are inexact.
    mov r1, r1, lsl #8
    orr r1, r1, #0x80000000
    cmp r0, #0
    mov r0, r1, lsr r2
    rsbmi r0, r0, #0
    rsb r2, r2, #32
    movs r1, r1, lsl r2
    bxeq lr
    // Inexact: trap if enabled, else set the flag.
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x1000
    bne ffix_trap_inexact
    orr r3, r3, #0x10
    str r3, [r2]
    bx lr
    // Below 1: zero is exact, anything else gives 0 and is inexact.
ffix_below_one:
    movs r0, r1
    bxeq lr
    mov r0, #0
    stmfd sp!, {r0, r2, r3, ip, lr}
    bl func_02142578
    mov r1, r0
    ldmfd sp!, {r0, r2, r3, ip, lr}
    ldr r3, [r1]
    tst r3, #0x1000
    bne ffix_trap_inexact
    orr r3, r3, #0x10
    str r3, [r1]
    bx lr
    // Out of range, except -2^31 itself, which is exact.
ffix_too_large:
    cmp r0, #0xcf000000
    beq ffix_saturate
    .size _ffix, . - _ffix

// Part of _ffix: an out-of-range value or NaN raises invalid (or traps) and gives 0x7fffffff for positive inputs,
// 0x80000000 for negative ones; -2^31 itself is exact. Also holds the two trap calls of _ffix.
    .global func_02132364
    .type func_02132364, @function
func_02132364:
    // Invalid: trap if enabled, else set the flag.
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne ffix_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
    // 0x7fffffff for positive inputs, 0x80000000 for negative ones.
ffix_saturate:
    mvn r0, r0, asr #31
    add r0, r0, #0x80000000
    bx lr
    // Invalid trap.
ffix_trap_invalid:
    ldr r1, ffix_code_invalid
    stmdb sp!, {lr}
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    // Inexact trap: pass the result.
ffix_trap_inexact:
    ldr r1, ffix_code_inexact
    stmdb sp!, {lr}
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    // Constant words: event codes.
ffix_code_invalid:
    .word 0x04c00048
ffix_code_inexact:
    .word 0x40c00048
    .size func_02132364, . - func_02132364

// Converts the unsigned integer r0 to a float in r0, rounded as the status word says. _fflt, in the middle, does the
// same for a signed integer; the rounding blocks at the end serve both.
    .global func_021323c4
    .type func_021323c4, @function
func_021323c4:
    // Zero gives 0. Shift the leading one to bit 31 with clz and lower the exponent 0x9e by the shift.
    cmp r0, #0
    bxeq lr
    mov r3, #158
    bmi uflt_pack                       // bit 31 already set
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    // Pack: r2 = the 8 bits shifted out (bit 7 the rounding bit). Exact results return.
uflt_pack:
    ands r2, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    // Inexact: trap if enabled, else set the flag. Rounding down or toward zero keeps the result, up adds one, nearest
    // even rounds up when above half, or exactly half and odd.
    stmfd sp!, {r0, r2, r3, ip, lr}
    bl func_02142578
    mov r1, r0
    ldmfd sp!, {r0, r2, r3, ip, lr}
    ldr r3, [r1]
    tst r3, #0x1000
    bne uflt_trap_inexact
    orr r3, r3, #0x10
    str r3, [r1]
    tst r3, #0x800000
    bxne lr
    tst r3, #0x400000
    bne uflt_mode_up
    tst r2, #0x80
    bxeq lr
    ands r1, r2, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
    // Signed integer to float: r2 = the sign, work on the magnitude. Zero gives 0; shift the leading one to bit 31 and
    // set the exponent 0x9e minus the shift.
    .global _fflt
_fflt:
    ands r2, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r0, #0
    bxeq lr
    clz r3, r0
    movs r0, r0, lsl r3
    rsb r3, r3, #158
    // Pack with the sign: r1 = the 8 bits shifted out. Exact results return.
    ands r1, r0, #0xff
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    // Inexact: trap if enabled, else set the flag and round as the mode says.
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne flt_trap_inexact
    orr r3, r3, #0x10
    str r3, [ip]
    tst r3, #0x800000
    bne flt_mode_down
    tst r3, #0x400000
    bne flt_mode_up
    tst r1, #0x80
    bxeq lr
    ands r3, r1, #0x7f
    andeqs r3, r0, #1
    addne r0, r0, #1
    bx lr
    // Unsigned, rounding up: add one.
uflt_mode_up:
    add r0, r0, #1
    bx lr
    // Signed, rounding down or toward zero: down grows only negative results.
flt_mode_down:
    tst r3, #0x400000
    addeq r0, r0, r2, lsr #31
    bx lr
    // Signed, rounding up: positive results grow.
flt_mode_up:
    cmp r2, #0
    addpl r0, r0, #1
    bx lr
    // Inexact traps: pass the result.
uflt_trap_inexact:
    stmdb sp!, {lr}
    ldr r1, uflt_code_inexact
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
flt_trap_inexact:
    stmdb sp!, {lr}
    ldr r1, flt_code_inexact
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    // Constant words: event codes.
uflt_code_inexact:
    .word 0x40000308
flt_code_inexact:
    .word 0x40000208
    .size func_021323c4, . - func_021323c4

// Multiplies the floats r0 and r1 and returns the product in r0, rounded as the status word says. Denormals are
// normalised first; underflow, overflow, inexact and invalid (zero times infinity, signalling NaNs) set their flags or
// call the trap handlers with event codes ending in 3. The operands stay saved on the stack for the invalid trap. Its
// last three instructions are a separate entry: they swap r0 and r1 and run on into _fsub (reversed subtraction);
// nothing in the program uses it.
    .global _fmul
    .type _fmul, @function
_fmul:
    // Save the operands. r2 = the sign of the product. Unpack the first operand: r3 = exponent, r0 = significand
    // shifted up 8 with the leading one set; exponent 0 or 0xff is special.
    stmfd sp!, {r0, r1}
    eor r2, r0, r1
    and r2, r2, #0x80000000
    mov ip, #255
    ands r3, ip, r0, lsr #23
    mov r0, r0, lsl #8
    cmpne r3, #255
    beq fmul_a_special
    orr r0, r0, #0x80000000
    // Unpack the second operand the same way into ip and r1.
    ands ip, ip, r1, lsr #23
    mov r1, r1, lsl #8
    cmpne ip, #255
    beq fmul_b_special
    orr r1, r1, #0x80000000
    // Add the exponents and multiply the significands; r0 = the top 32 bits of the product, bit 0 set when any lower
    // bit is, shifted up once if its leading one is in bit 30. Remove the extra bias: below 0 underflows, 0xfe or above
    // overflows.
fmul_multiply:
    add ip, r3, ip
    umull r1, r3, r0, r1
    cmp r1, #0
    orrne r3, r3, #1
    movs r0, r3
    addpl r0, r0, r0
    subpl ip, ip, #1
    subs ip, ip, #127
    bmi fmul_underflow
    cmp ip, #254
    bge fmul_overflow
    // Pack: r3 = the 8 bits shifted out (bit 7 the rounding bit). Exact results return here.
fmul_pack:
    ands r3, r0, #0xff
    orr r0, r2, r0, lsr #8
    add r0, r0, ip, lsl #23
    addeq sp, sp, #8
    bxeq lr
    // Inexact: trap if enabled, else set the flag and round as the mode says.
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r1, [ip]
    tst r1, #0x1000
    bne fmul_trap_inexact
    orr r1, r1, #0x10
    str r1, [ip]
    tst r1, #0x800000
    bne fmul_mode_down
    tst r1, #0x400000
    bne fmul_mode_up
    // Nearest even: round up when above half, or exactly half and odd.
    tst r3, #0x80
    addeq sp, sp, #8
    bxeq lr
    ands r3, r3, #0x7f
    andeqs r3, r0, #1
    addeq sp, sp, #8
    bxeq lr
    // Round up the magnitude; reaching exponent 0xff is an overflow.
fmul_round_up:
    add r0, r0, #1
    mov r3, r0, lsl #1
    cmn r3, #0x1000000
    addlo sp, sp, #8
    bxlo lr
    tst r1, #0x400
    bne fmul_trap_overflow_round
    orr r1, r1, #0x14
    str r1, [ip]
    add sp, sp, #8
    bx lr
    // Rounding up: only positive results grow.
fmul_mode_up:
    cmp r2, #0
    beq fmul_round_up
    add sp, sp, #8
    bx lr
    // Rounding down or toward zero: down grows only negative results.
fmul_mode_down:
    tst r1, #0x400000
    addne sp, sp, #8
    bxne lr
    cmp r2, #0
    bne fmul_round_up
    add sp, sp, #8
    bx lr
    // First operand has exponent 0 or 0xff. A NaN goes to fmul_a_nan; infinity times zero is invalid, infinity times
    // anything else but a NaN is infinity.
fmul_a_special:
    cmp r3, #0
    beq fmul_a_small
    movs r0, r0, lsl #1
    bne fmul_a_nan
    mov ip, r1, lsr #23
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq fmul_inf_times_small
    cmp ip, #255
    blt fmul_return_inf
    cmp r1, #0
    beq fmul_return_inf
    b fmul_b_nan
    // Infinity times an operand with exponent 0: invalid for zero, infinity for a denormal.
fmul_inf_times_small:
    cmp r1, #0
    beq fmul_invalid
    b fmul_return_inf
    // Second operand has exponent 0 or 0xff (the first is finite and not zero).
fmul_b_special:
    cmp ip, #0
    beq fmul_b_small
fmul_b_inf_or_nan:
    movs r1, r1, lsl #1
    bne fmul_b_nan
    b fmul_return_inf
    // First operand has exponent 0. Zero: see fmul_a_zero. Denormal: shift its leading one up to bit 31 with clz, the
    // exponent going below 1 by the shift; then unpack the second operand and multiply.
fmul_a_small:
    movs r0, r0, lsl #1
    beq fmul_a_zero
    mov r0, r0, lsr #1
    clz r3, r0
    movs r0, r0, lsl r3
    rsb r3, r3, #1
    mov ip, r1, lsr #23
    mov r1, r1, lsl #8
    ands ip, ip, #0xff
    beq fmul_b_small
    cmp ip, #255
    beq fmul_b_inf_or_nan
    orr r1, r1, #0x80000000
    b fmul_multiply
    // First operand is zero: the product is zero, except for an infinity (invalid) or a NaN.
fmul_a_zero:
    mov ip, r1, lsr #23
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq fmul_return_zero
    cmp ip, #255
    blt fmul_return_zero
    cmp r1, #0
    beq fmul_invalid
    b fmul_b_nan
    // Second operand has exponent 0: zero gives zero; a denormal is normalised like the first.
fmul_b_small:
    movs r1, r1, lsl #1
    beq fmul_return_zero
    mov r1, r1, lsr #1
    clz ip, r1
    movs r1, r1, lsl ip
    rsb ip, ip, #1
    b fmul_multiply
    // Exponent below 1: underflow trap if enabled, else the product is a denormal. At exactly -24 only the rounding bit
    // is left; below that the result is zero or the smallest denormal.
fmul_underflow:
    stmfd sp!, {r0, r1, r2, ip, lr}
    bl func_02142578
    mov r3, r0
    ldmfd sp!, {r0, r1, r2, ip, lr}     // exactly -24
    ldr r3, [r3]                        // below -24
    tst r3, #0x800
    bne fmul_trap_underflow
    cmn ip, #24
    beq fmul_round_bit_only
    bmi fmul_tiny
    // Shift the product right into a denormal; r1 = the bits shifted out. Exact results return.
    mov r3, r0
    mov r0, r0, lsr #8
    rsb ip, ip, #0
    orr r0, r2, r0, lsr ip
    rsb ip, ip, #24
    movs r1, r3, lsl ip
    addeq sp, sp, #8
    bxeq lr
    // Inexact: underflow and inexact (or trap), then round as the mode says; nearest even first.
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne fmul_trap_inexact
    orr r3, r3, #0x18
    str r3, [ip]
    tst r3, #0x800000
    bne fmul_denormal_down
    tst r3, #0x400000
    bne fmul_denormal_up
    tst r1, #0x80000000
    addeq sp, sp, #8
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    add sp, sp, #8
    bx lr
    // Rounding up: positive results grow.
fmul_denormal_up:
    cmp r2, #0
    addeq r0, r0, #1
    add sp, sp, #8
    bx lr
    // Rounding down or toward zero: down grows only negative results.
fmul_denormal_down:
    tst r3, #0x400000
    addeq r0, r0, r0, lsr #31
    add sp, sp, #8
    bx lr
    // Only the rounding bit is left: r0 = the bits below it, for fmul_half_smallest.
fmul_round_bit_only:
    mov r0, r0, lsl #1
    b fmul_half_smallest
    // Return infinity with the product's sign.
fmul_return_inf:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    add sp, sp, #8
    bx lr
    // First operand is a NaN. A signalling NaN is invalid; a quiet one gives the default NaN, invalid only when the
    // second operand is a signalling NaN.
fmul_a_nan:
    tst r0, #0x80000000
    beq fmul_invalid
    mov ip, r1, lsr #23
    mov r1, r1, lsl #9
    ands ip, ip, #0xff
    beq fmul_default_nan
    cmp ip, #255
    blt fmul_default_nan
    cmp r1, #0
    beq fmul_default_nan
    // Second operand is a NaN: signalling is invalid, quiet gives the default NaN.
fmul_b_nan:
    tst r1, #0x80000000
    beq fmul_invalid
    mvn r0, #0x80000000
    add sp, sp, #8
    bx lr
    // Invalid operation: trap if enabled, else set the flag and return the default NaN.
fmul_invalid:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne fmul_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
    // Return the default NaN.
fmul_default_nan:
    mvn r0, #0x80000000
    add sp, sp, #8
    bx lr
    // Overflow: trap if enabled, else set overflow and inexact. Nearest gives infinity, toward zero the largest float,
    // up and down one or the other by the sign.
fmul_overflow:
    stmfd sp!, {r0, r2, r3, ip, lr}
    bl func_02142578
    mov r1, r0
    ldmfd sp!, {r0, r2, r3, ip, lr}
    ldr r3, [r1]
    tst r3, #0x400
    bne fmul_trap_overflow
    orr r3, r3, #0x14
    str r3, [r1]
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    tst r3, #0x800000
    bne fmul_overflow_down
    tst r3, #0x400000
    subne r0, r0, r2, lsr #31
    add sp, sp, #8
    bx lr
    // Down or toward zero: the largest float, infinity again for negative results when down.
fmul_overflow_down:
    sub r0, r0, #1
    tst r3, #0x400000
    addeq r0, r0, r2, lsr #31
    add sp, sp, #8
    bx lr
    // Half the smallest denormal or a little more: zero or the smallest denormal by the mode, with underflow and
    // inexact. Nearest rounds up unless it is exactly half.
fmul_half_smallest:
    movs r1, r0
    mov r0, r2
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne fmul_trap_inexact
    orr r3, r3, #0x18
    str r3, [ip]
    cmp r1, #0
    tst r3, #0x800000
    bne fmul_tiny_down
    tst r3, #0x400000
    bne fmul_tiny_up
    cmp r1, #0
    addne r0, r0, #1
    add sp, sp, #8
    bx lr
    // Smaller still: zero, or the smallest denormal when rounding away from zero for this sign, with underflow and
    // inexact.
fmul_tiny:
    mov r0, r2
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x1000
    bne fmul_trap_inexact
    orr r3, r3, #0x18
    str r3, [ip]
    tst r3, #0x800000
    bne fmul_tiny_down
    tst r3, #0x400000
    addeq sp, sp, #8
    bxeq lr
    cmp r0, #0
    addeq r0, r0, #1
    add sp, sp, #8
    bx lr
    // Return zero with the product's sign.
fmul_return_zero:
    mov r0, r2
    add sp, sp, #8
    bx lr
    // Rounding up: positive results become the smallest denormal.
fmul_tiny_up:
    cmp r2, #0
    addeq r0, r0, #1
    add sp, sp, #8
    bx lr
    // Rounding down: negative results become the smallest denormal.
fmul_tiny_down:
    tst r3, #0x400000
    addeq r0, r0, r0, lsr #31
    add sp, sp, #8
    bx lr
    // Overflow trap after rounding: pass the result with its exponent wrapped down by 0xc0.
fmul_trap_overflow_round:
    add sp, sp, #8
    sub r0, r0, #0x60000000
    stmdb sp!, {lr}
    mov r1, #0x10000003
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    // Overflow trap: pass the result with its exponent lowered by 0xc0.
fmul_trap_overflow:
    add sp, sp, #8
    sub ip, ip, #192
    orr r0, r2, r0, lsr #8
    add r0, r0, ip, lsl #23
    stmdb sp!, {lr}
    mov r1, #0x10000003
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    // Underflow trap: pass the result with its exponent raised by 0xc0.
fmul_trap_underflow:
    add sp, sp, #8
    add ip, ip, #192
    orr r0, r2, r0, lsr #8
    add r0, r0, ip, lsl #23
    stmdb sp!, {lr}
    mov r1, #0x20000003
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    // Invalid trap: pass the original operands from the stack.
fmul_trap_invalid:
    ldmfd sp!, {r0, r1}
    stmdb sp!, {lr}
    mov r2, #0x4000003
    bl func_021340d4
    ldmia sp!, {lr}
    bx lr
    // Inexact trap: pass the rounded result.
fmul_trap_inexact:
    add sp, sp, #8
    stmdb sp!, {lr}
    mov r1, #0x40000003
    bl func_02134238
    ldmia sp!, {lr}
    bx lr
    // Reversed subtraction entry: swap r0 and r1 and run on into _fsub.
    eor r0, r0, r1
    eor r1, r0, r1
    eor r0, r0, r1
    .size _fmul, . - _fmul
