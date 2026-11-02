// Double-precision division: the reversed entry, the main routine with its rounding tails, the reciprocal
// table it starts from, and the routine for its special cases.
//
// Arguments and results, the status word from func_02142578 and the trap handlers are as described in
// code_0212f884.s; division by zero sets status bit 0x02 (trap enable 0x200).
//
// Not compiled code: the routines branch into each other's middles (_ddiv into func_0213379c and back to
// _ddiv+0x24 and _ddiv+0x38), func_02133488 and func_02133630 have no return and run on into the next
// routine, the tails pop a frame they did not push, and _ddiv reads a constant word kept in
// func_0213379c's constants and the table through a pc-relative address. A compiled function is entered
// only at its start, ends in a return and keeps its constants after itself. They also use tst and clz, which
// the 1.2 compiler never builds (docs/compiler.md). The table has to sit in .text between the routines; 1.2 puts
// a C table in .rodata (also with `#pragma section` or a section attribute), so it is written here as bytes.

    .text
    .extern func_0213406c
    .extern func_0213412c
    .extern func_02142578

// Reversed division: swaps the doubles r1:r0 and r3:r2 (three exclusive ors per word) and runs on into _ddiv, so it
// returns r3:r2 divided by r1:r0.
    .global func_02133488
    .type func_02133488, @function
func_02133488:
    // Swap r1:r0 and r3:r2.
    eor r1, r1, r3
    eor r3, r1, r3
    eor r1, r1, r3
    eor r0, r0, r2
    eor r2, r0, r2
    eor r0, r0, r2
    .size func_02133488, . - func_02133488

// Divides the double r1:r0 by r3:r2 and returns the quotient in r1:r0, rounded as the status word says. The quotient is
// estimated from the reciprocal table below and two refinement steps, then corrected and rounded by multiplying back.
// Special operands, overflow and underflow continue in func_0213379c; the rounding ends in the tails func_02133620 to
// func_02133790. The operands stay saved on the stack for the trap calls.
    .global _ddiv
    .type _ddiv, @function
_ddiv:
    // Save the operands. lr = 0xffe selects the exponent shifted up one place; r4 = the sign of the quotient. ip =
    // twice the first exponent, plus the sign in bit 0; exponent 0 or 0x7ff goes to ddivx_a_special. Replace the
    // exponent bits with the leading one.
    stmfd sp!, {r0, r1, r2, r3, r4, r5, r6, lr}
    ldr lr, ddiv_exponent_mask          // constant word in func_0213379c
    eor r4, r1, r3
    ands ip, lr, r1, lsr #19
    cmpne ip, lr
    beq ddivx_a_special
    bic r1, r1, lr, lsl #20
    orr r1, r1, #0x100000
    add ip, ip, r4, lsr #31
    // r4 = twice the divisor's exponent; exponent 0 or 0x7ff goes to ddivx_b_special. Leading one.
ddiv_unpack_divisor:
    ands r4, lr, r3, lsr #19
    cmpne r4, lr
    beq ddivx_b_special
    bic r3, r3, lr, lsl #20
    orr r3, r3, #0x100000
    // ip = the exponent difference (doubled). If the dividend's significand is the smaller, shift it up.
ddiv_exponent:
    sub ip, ip, r4
    cmp r1, r3
    cmpeq r0, r2
    bhs ddiv_estimate
    adds r0, r0, r0
    adc r1, r1, r1
    sub ip, ip, #2
    // Reciprocal estimate: the table entry for the divisor's top bits, refined twice with multiplies; then the quotient
    // r4:r5 = dividend times reciprocal, a little below the true quotient.
ddiv_estimate:
    add r4, pc, #128                    // pc + 0x80: the reciprocal table
    ldrb lr, [r4, r3, lsr #12]
    rsbs r2, r2, #0
    rsc r3, r3, #0
    mov r4, #0x20000000
    mla r5, lr, r3, r4
    mov r6, r3, lsl #10
    mov r5, r5, lsr #7
    mul lr, r5, lr
    orr r6, r6, r2, lsr #22
    mov lr, lr, lsr #13
    mul r5, lr, r6
    mov r6, r1, lsl #10
    orr r6, r6, r0, lsr #22
    mov r5, r5, lsr #16
    mul r5, lr, r5
    mov lr, lr, lsl #14
    add lr, lr, r5, lsr #16
    umull r5, r6, lr, r6
    umull r4, r5, r6, r2
    mla r5, r3, r6, r5
    mov r4, r4, lsr #26
    orr r4, r4, r5, lsl #6
    add r4, r4, r0, lsl #2
    umull lr, r5, r4, lr
    mov r4, #0
    adds r5, r5, r6, lsl #24
    adc r4, r4, r6, lsr #8
    // Rebias the exponent: 0x800 or more overflows, below 0 underflows; pack the high word into r1.
    cmp ip, #0x800
    bge func_0213379c
    add ip, ip, #0x7f0
    adds ip, ip, #12
    bmi ddivx_underflow
    orr r1, r4, ip, lsl #31
    bic ip, ip, #1
    add r1, r1, ip, lsl #19
    // Remainder = dividend - quotient * divisor (r2:r3 = the negated divisor). Zero: exact, return. Otherwise check
    // whether the quotient is one unit low.
    rsbs r2, r2, #0
    mul lr, r2, r4
    mov r6, #0
    umlal r6, lr, r2, r5
    rsc r3, r3, #0
    mla lr, r5, r3, lr
    cmp lr, r0, lsl #20
    cmpeq r6, #0
    beq func_02133620
    adds r4, r6, r2
    adc ip, lr, r3
    cmp ip, r0, lsl #20
    bmi ddiv_adjust
    cmpeq r4, #0
    beq func_02133630
    b ddiv_round
    // One unit low: add one and take the divisor off the remainder.
ddiv_adjust:
    mov lr, ip
    mov r6, r4
    adds r5, r5, #1
    adc r1, r1, #0
    // Inexact: trap if enabled, else set the flag. Down or toward zero: func_0213377c; up: func_02133790; nearest:
    // compare twice the remainder with the divisor and round up (func_02133630) when above half, else return
    // (func_02133620).
ddiv_round:
    adds r6, r6, r6
    adc lr, lr, lr
    adds r6, r6, r2
    adc lr, lr, r3
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x1000
    bne ddivx_trap_inexact
    orr r3, r3, #0x10
    str r3, [r2]
    tst r3, #0x800000
    bne func_0213377c
    tst r3, #0x400000
    bne func_02133790
    cmp lr, r0, lsl #21
    bmi func_02133630
    .size _ddiv, . - _ddiv

// Tail of _ddiv: returns the result (low word in r5, high word in r1) and removes _ddiv's frame.
    .global func_02133620
    .type func_02133620, @function
func_02133620:
    mov r0, r5
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    .size func_02133620, . - func_02133620

// Tail of _ddiv: rounds the result up by one unit; reaching exponent 0x7ff is an overflow: trap if enabled, else it
// runs on into func_02133668.
    .global func_02133630
    .type func_02133630, @function
func_02133630:
    // Round up; no carry into exponent 0x7ff returns.
    adds r0, r5, #1
    adc r1, r1, #0
    mov r2, r1, lsl #1
    cmn r2, #0x200000
    addlo sp, sp, #16
    ldmlofd sp!, {r4, r5, r6, lr}
    bxlo lr
    // Overflow: trap if enabled.
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip]
    tst r3, #0x400
    bne ddivx_trap_overflow_round
    .size func_02133630, . - func_02133630

// Tail of _ddiv: sets overflow and inexact (r3 = the status word, ip = its address) and returns the result.
    .global func_02133668
    .type func_02133668, @function
func_02133668:
    orr r3, r3, #0x14
    str r3, [ip]
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    .size func_02133668, . - func_02133668

// Reciprocal table read by _ddiv, indexed by the 8 significand bits below the divisor's leading one: entry i is 0x10000
// / (256.5 + i) rounded to the nearest integer, 0xff for i = 0 (checked for all 256 entries).
    .global data_0213367c
    .type data_0213367c, @object
data_0213367c:
    .byte 0xff, 0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8, 0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1
    .byte 0xf0, 0xf0, 0xef, 0xee, 0xed, 0xec, 0xeb, 0xea, 0xea, 0xe9, 0xe8, 0xe7, 0xe6, 0xe6, 0xe5, 0xe4
    .byte 0xe3, 0xe2, 0xe2, 0xe1, 0xe0, 0xdf, 0xdf, 0xde, 0xdd, 0xdc, 0xdc, 0xdb, 0xda, 0xd9, 0xd9, 0xd8
    .byte 0xd7, 0xd7, 0xd6, 0xd5, 0xd4, 0xd4, 0xd3, 0xd2, 0xd2, 0xd1, 0xd0, 0xd0, 0xcf, 0xce, 0xce, 0xcd
    .byte 0xcc, 0xcc, 0xcb, 0xcb, 0xca, 0xc9, 0xc9, 0xc8, 0xc8, 0xc7, 0xc6, 0xc6, 0xc5, 0xc5, 0xc4, 0xc3
    .byte 0xc3, 0xc2, 0xc2, 0xc1, 0xc0, 0xc0, 0xbf, 0xbf
    .byte 0xbe, 0xbe, 0xbd, 0xbd
    .byte 0xbc, 0xbc, 0xbb, 0xba
    .byte 0xba, 0xb9, 0xb9, 0xb8, 0xb8, 0xb7, 0xb7, 0xb6, 0xb6, 0xb5, 0xb5, 0xb4, 0xb4, 0xb3, 0xb3, 0xb2
    .byte 0xb2, 0xb1, 0xb1, 0xb0, 0xb0, 0xaf, 0xaf, 0xaf, 0xae, 0xae, 0xad, 0xad, 0xac, 0xac, 0xab, 0xab
    .byte 0xaa, 0xaa, 0xaa, 0xa9, 0xa9, 0xa8, 0xa8, 0xa7, 0xa7, 0xa7, 0xa6, 0xa6, 0xa5, 0xa5, 0xa4, 0xa4
    .byte 0xa4, 0xa3, 0xa3, 0xa2, 0xa2, 0xa2, 0xa1, 0xa1, 0xa0, 0xa0, 0xa0, 0x9f, 0x9f, 0x9e, 0x9e, 0x9e
    .byte 0x9d, 0x9d, 0x9d, 0x9c, 0x9c, 0x9b, 0x9b, 0x9b, 0x9a, 0x9a, 0x9a, 0x99, 0x99, 0x99, 0x98, 0x98
    .byte 0x98, 0x97, 0x97, 0x96, 0x96, 0x96, 0x95, 0x95, 0x95, 0x94, 0x94, 0x94, 0x93, 0x93, 0x93, 0x92
    .byte 0x92, 0x92, 0x91, 0x91, 0x91, 0x91, 0x90, 0x90, 0x90, 0x8f, 0x8f, 0x8f, 0x8e, 0x8e, 0x8e, 0x8d
    .byte 0x8d, 0x8d, 0x8c, 0x8c, 0x8c, 0x8c, 0x8b, 0x8b, 0x8b, 0x8a, 0x8a, 0x8a, 0x8a, 0x89, 0x89, 0x89
    .byte 0x88, 0x88, 0x88, 0x88, 0x87, 0x87, 0x87, 0x86, 0x86, 0x86, 0x86, 0x85, 0x85, 0x85, 0x85, 0x84
    .byte 0x84, 0x84, 0x83, 0x83, 0x83, 0x83, 0x82, 0x82, 0x82, 0x82, 0x81, 0x81, 0x81, 0x81, 0x80, 0x80
    .size data_0213367c, . - data_0213367c

// Tail of _ddiv, rounding down or toward zero (r3 = the status word, r1 = the result's high word): toward zero keeps
// the result; down rounds negative results up in magnitude (func_02133630).
    .global func_0213377c
    .type func_0213377c, @function
func_0213377c:
    tst r3, #0x400000
    bne func_02133620
    tst r1, #0x80000000
    bne func_02133630
    b func_02133620
    .size func_0213377c, . - func_0213377c

// Tail of _ddiv, rounding up: positive results grow (func_02133630), negative ones keep the result.
    .global func_02133790
    .type func_02133790, @function
func_02133790:
    tst r1, #0x80000000
    beq func_02133630
    b func_02133620
    .size func_02133790, . - func_02133790

// The rest of _ddiv, entered at its blocks by branches from _ddiv and its tails: overflow (at its start), underflow,
// operands with exponent 0 or 0x7ff (zero, denormal, infinity, NaN), division by zero, invalid operations, and the trap
// calls (event codes ending in 0x94). Denormal operands are normalised here and division continues in _ddiv.
    .global func_0213379c
    .type func_0213379c, @function
func_0213379c:
    // Overflow: trap if enabled, else set overflow and inexact. Nearest gives infinity, toward zero the largest finite
    // value, up and down one or the other by the sign (ip bit 0).
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x400
    bne ddivx_trap_overflow
    orr r3, r3, #0x14
    str r3, [r2]
    movs r1, ip, lsl #31
    orr r1, r1, #0x7f000000
    orr r1, r1, #0xf00000
    mov r0, #0
    bmi ddivx_overflow_negative
    tst r3, #0x800000
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, lr}
    bxeq lr
    subs r0, r0, #1
    sbc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Negative overflow: nearest and down give -infinity, up and toward zero the largest negative value.
ddivx_overflow_negative:
    tst r3, #0x400000
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, lr}
    bxeq lr
    subs r0, r0, #1
    sbc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Underflow: trap if enabled, else the quotient becomes a denormal. r6 = the right shift: above 52 the result is
    // zero or the smallest denormal, exactly 52 only the rounding bit is left.
ddivx_underflow:
    stmfd sp!, {r0, r1, r2, r3, ip, lr}
    bl func_02142578
    mov r6, r0
    ldmfd sp!, {r0, r1, r2, r3, ip, lr}
    ldr r6, [r6]
    tst r6, #0x800
    bne ddivx_trap_underflow
    mvn r6, ip, asr #1
    cmp r6, #52
    bgt ddivx_tiny
    beq ddivx_half_smallest
    // A shift below 20: the high word keeps some bits.
    cmp r6, #20
    bge ddivx_shift_long
    rsb r6, r6, #19
    mov lr, r0, lsl r6
    rsb r6, r6, #20
    mov r0, r5, lsr r6
    rsb r6, r6, #32
    orr r0, r0, r4, lsl r6
    rsb r6, r6, #32
    mov r4, r4, lsr r6
    orr r1, r4, ip, lsl #31
    mov ip, lr
    mov lr, #0
    b ddivx_check
    // A shift of 20 to 51: only the low word keeps bits.
ddivx_shift_long:
    rsb r6, r6, #51
    mov lr, r1, lsl r6
    mov r1, ip, lsl #31
    rsb r6, r6, #32
    orr ip, lr, r0, lsr r6
    rsb r6, r6, #32
    mov lr, r0, lsl r6
    mov r5, r5, lsr #21
    orr r5, r5, r4, lsl #11
    rsb r6, r6, #31
    mov r0, r5, lsr r6
    mov r4, #0
    // Multiply back: exact results return. Otherwise compare the remainder with the divisor to find the rounding bits.
ddivx_check:
    rsbs r2, r2, #0
    mul r4, r2, r4
    mov r5, #0
    umlal r5, r4, r2, r0
    rsc r3, r3, #0
    mla r4, r0, r3, r4
    cmp r4, ip
    cmpeq r5, lr
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, lr}
    bxeq lr
    adds r5, r5, r2
    adc r4, r4, r3
    cmp r4, ip
    bmi ddivx_add_one
    bne ddivx_adjust
    cmp r5, lr
    beq ddivx_round_up
    blo ddivx_add_one
ddivx_adjust:
    subs r5, r5, r2
    sbc r4, r4, r3
    // Inexact: underflow and inexact (or trap), then round as the mode says; nearest compares twice the remainder with
    // the divisor, exactly half rounds to even.
ddivx_inexact:
    adds r5, r5, r5
    adc r4, r4, r4
    adds r5, r5, r2
    adc r4, r4, r3
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x1000
    bne ddivx_trap_inexact
    orr r3, r3, #0x18
    str r3, [r2]
    tst r3, #0x800000
    bne ddivx_mode_down
    tst r3, #0x400000
    bne ddivx_mode_up
    adds lr, lr, lr
    adc ip, ip, ip
    cmp r4, ip
    bmi ddivx_round_up
    addne sp, sp, #16
    ldmnefd sp!, {r4, r5, r6, lr}
    bxne lr
    cmp r5, lr
    blo ddivx_round_up
    addne sp, sp, #16
    ldmnefd sp!, {r4, r5, r6, lr}
    bxne lr
    tst r0, #1
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, lr}
    bxeq lr
    // Round up by one unit and return.
ddivx_round_up:
    adds r0, r0, #1
    adc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // The quotient was one unit low: add one and round again.
ddivx_add_one:
    adds r0, r0, #1
    adc r1, r1, #0
    b ddivx_inexact
    // Rounding up: positive results grow.
ddivx_mode_up:
    eor r4, r1, #0x80000000
    adds r0, r0, r4, lsr #31
    adc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Rounding down or toward zero: down grows only negative results.
ddivx_mode_down:
    tst r3, #0x400000
    addne sp, sp, #16
    ldmnefd sp!, {r4, r5, r6, lr}
    bxne lr
    adds r0, r0, r1, lsr #31
    adc r1, r1, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Exactly half the smallest denormal or a little more: r0 = 1 unless it is exactly half; underflow and inexact (or
    // trap), then the mode decides.
ddivx_half_smallest:
    rsbs r2, r2, #0
    rsc r3, r3, #0
    cmp r1, r3
    cmpeq r0, r2
    mov r1, ip, lsl #31
    mov r0, #0
    movne r0, #1
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x1000
    bne ddivx_trap_inexact
    orr r3, r3, #0x18
    str r3, [r2]
    tst r3, #0x800000
    bne ddivx_half_down
    tst r3, #0x400000
    bne ddivx_half_up
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Rounding up: the smallest denormal for positive results.
ddivx_half_up:
    mov r0, r1, lsr #31
    eor r0, r0, #1
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Rounding down or toward zero: the smallest denormal for negative results when down.
ddivx_half_down:
    tst r3, #0x400000
    mov r0, #0
    moveq r0, r1, lsr #31
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Smaller still: zero, or the smallest denormal when rounding away from zero for this sign, with underflow and
    // inexact.
ddivx_tiny:
    mov r1, ip, lsl #31
    mov r0, #0
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x1000
    bne ddivx_trap_inexact
    orr r3, r3, #0x18
    str r3, [r2]
    and r3, r3, #0xc00000
    cmp r3, #0
    cmpne r3, #0xc00000
    addeq sp, sp, #16
    ldmeqfd sp!, {r4, r5, r6, lr}
    bxeq lr
    cmp r3, #0x400000
    tsteq r1, #0x80000000
    addeq r0, r0, #1
    cmp r3, #0x400000
    tstne r1, #0x80000000
    addne r0, r0, #1
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // First operand has exponent 0 or 0x7ff. Zero: ddivx_a_zero; infinity or NaN: ddivx_a_inf_or_nan. A denormal is
    // shifted until its leading one is in bit 20 of the high word (exponent going below 1), then division continues in
    // _ddiv.
ddivx_a_special:
    orrs r5, r0, r1, lsl #1
    beq ddivx_a_zero
    cmp ip, lr
    beq ddivx_a_inf_or_nan
    movs r1, r1, lsl #12
    beq ddivx_a_high_zero
    clz r5, r1
    movs r1, r1, lsl r5
    sub ip, ip, r5
    add r5, ip, #31
    mov r1, r1, lsr #11
    orr r1, r1, r0, lsr r5
    rsb r5, r5, #32
    mov r0, r0, lsl r5
    mov ip, ip, lsl #1
    orr ip, ip, r4, lsr #31
    b ddiv_unpack_divisor
    // Leading one in the low word.
ddivx_a_high_zero:
    mvn ip, #0x13
    clz r5, r0
    movs r0, r0, lsl r5
    sub ip, ip, r5
    mov r1, r0, lsr #11
    mov r0, r0, lsl #21
    mov ip, ip, lsl #1
    orr ip, ip, r4, lsr #31
    b ddiv_unpack_divisor
    // First operand infinity: infinity with the quotient's sign, unless the divisor is infinity or NaN.
ddivx_a_inf_or_nan:
    orrs r5, r0, r1, lsl #12
    bne ddivx_a_nan
    bic r5, r3, #0x80000000
    cmp r5, lr, lsl #19
    bhs ddivx_inf_by_special
    and r5, r3, #0x80000000
    eor r1, r5, r1
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Infinity by infinity is invalid; by a NaN, the NaN path.
ddivx_inf_by_special:
    orrs r5, r2, r3, lsl #12
    bne ddivx_b_nan
    b ddivx_invalid
    // Divisor has exponent 0 or 0x7ff (the first operand is finite and not zero). Zero: division by zero; infinity or
    // NaN: ddivx_b_inf_or_nan. A denormal is normalised like the first operand.
ddivx_b_special:
    orrs r5, r2, r3, lsl #1
    beq ddivx_divide_by_zero
    cmp r4, lr
    beq ddivx_b_inf_or_nan
    movs r3, r3, lsl #12
    beq ddivx_b_high_zero
    clz r5, r3
    movs r3, r3, lsl r5
    sub r4, r4, r5
    add r5, r4, #31
    mov r3, r3, lsr #11
    orr r3, r3, r2, lsr r5
    rsb r5, r5, #32
    mov r2, r2, lsl r5
    mov r4, r4, lsl #1
    b ddiv_exponent
    // Leading one in the low word.
ddivx_b_high_zero:
    mvn r4, #0x13
    clz r5, r2
    movs r2, r2, lsl r5
    sub r4, r4, r5
    mov r3, r2, lsr #11
    mov r2, r2, lsl #21
    mov r4, r4, lsl #1
    b ddiv_exponent
    // Divisor infinity: zero with the quotient's sign; a NaN takes the NaN path.
ddivx_b_inf_or_nan:
    orrs r5, r2, r3, lsl #12
    bne ddivx_b_nan
    mov r1, ip, lsl #31
    mov r0, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Division by zero: trap if enabled, else set the flag and return infinity with the quotient's sign.
ddivx_divide_by_zero:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x200
    bne ddivx_trap_divide_by_zero
    orr r3, r3, #2
    str r3, [r2]
    mov r1, ip, lsl #31
    orr r1, r1, lr, lsl #19
    mov r0, #0
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // First operand zero: zero by zero is invalid, by a NaN the NaN path, otherwise a signed zero.
ddivx_a_zero:
    orrs r5, r2, r3, lsl #1
    beq ddivx_invalid
    bic r5, r3, #0x80000000
    cmp r5, lr, lsl #19
    cmpeq r2, #0
    bhi ddivx_b_nan
    eor r1, r1, r3
    and r1, r1, #0x80000000
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // First operand a NaN: signalling is invalid; quiet returns itself unless the divisor is a NaN.
ddivx_a_nan:
    tst r1, #0x80000
    beq ddivx_invalid
    bic r5, r3, #0x80000000
    cmp r5, lr, lsl #19
    cmpeq r2, #0
    bhi ddivx_b_nan
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Divisor a NaN: signalling is invalid, quiet returns the divisor.
ddivx_b_nan:
    tst r3, #0x80000
    beq ddivx_invalid
    mov r1, r3
    mov r0, r2
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Invalid: trap if enabled, else set the flag and return r1:r0 with the quiet-NaN bits set.
ddivx_invalid:
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne ddivx_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
    orr r1, r1, #0x7f000000
    orr r1, r1, #0xf80000
    add sp, sp, #16
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Overflow trap from func_02133630: pass infinity's exponent minus 0x600 with the sign.
ddivx_trap_overflow_round:
    add sp, sp, #16
    and r1, r1, #0x80000000
    orr r1, r1, #0x10000000
    orr r1, r1, #0xff00000
    mov r0, #0
    ldr r2, ddivx_code_overflow
    bl func_0213412c
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Overflow trap: pass the quotient with its exponent wrapped down by 0x600.
ddivx_trap_overflow:
    add sp, sp, #16
    sub ip, ip, #0x200
    sub ip, ip, #2
    orr r1, r4, ip, lsl #31
    bic ip, ip, #1
    add r1, r1, ip, lsl #19
    mov r0, r5
    ldr r2, ddivx_code_overflow
    bl func_0213412c
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Underflow trap: pass the quotient with its exponent raised by 0x600.
ddivx_trap_underflow:
    add sp, sp, #16
    add ip, ip, #0x600
    orr r1, r4, ip, lsl #31
    bic ip, ip, #1
    add r1, r1, ip, lsl #19
    mov r0, r5
    ldr r2, ddivx_code_underflow
    bl func_0213412c
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Division-by-zero trap: pass the original operands from the stack.
ddivx_trap_divide_by_zero:
    ldmfd sp!, {r0, r1, r2, r3}
    ldr ip, ddivx_code_divide_by_zero
    stmdb sp!, {ip}
    bl func_0213406c
    add sp, sp, #4
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Invalid trap: pass the original operands from the stack.
ddivx_trap_invalid:
    ldmfd sp!, {r0, r1, r2, r3}
    ldr ip, ddivx_code_invalid
    stmdb sp!, {ip}
    bl func_0213406c
    add sp, sp, #4
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    // Inexact trap: pass the rounded result.
ddivx_trap_inexact:
    add sp, sp, #16
    ldr r2, ddivx_code_inexact
    bl func_0213412c
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
    .size func_0213379c, . - func_0213379c

// Constant words: the exponent mask read by _ddiv, then event codes.
    .global data_02133d90
    .type data_02133d90, @object
data_02133d90:
ddiv_exponent_mask:
    .word 0x00000ffe
    .size data_02133d90, . - data_02133d90
ddivx_code_overflow:
    .word 0x10000094
ddivx_code_underflow:
    .word 0x20000094
ddivx_code_divide_by_zero:
    .word 0x08000094
ddivx_code_invalid:
    .word 0x04000094
ddivx_code_inexact:
    .word 0x40000094
