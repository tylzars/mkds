// Float and double compares.
//
// Floats are passed in r0 and r1, doubles in r1:r0 and r3:r2 (low word first); the status word from func_02142578
// and the trap handlers are as described in code_0212f884.s. The value compares return 1 or 0 in r0, the three-way
// compares 0, 1, 2 or 3 in r0, and the flag compares return their result in the condition flags.
//
// Not compiled code: the routines are entered at many points past the first instruction (_fls, _fgr, _fgeq, _dneq,
// _deq, _dls, _dleq, _dgr) and branch into the middle of each other's tails, where a compiled function is entered
// only at its start; they use tst, which the 1.2 compiler never builds, and `cmp rX, #0` feeding mi, where 1.2
// deletes the cmp; and the tails save ip and the argument registers with stm around a call in the middle of the
// body, where 1.2 builds stm only in prologues and block moves and never saves ip (docs/compiler.md). The flag
// compares also return their result in the condition flags (`cmp r0, r1; bx lr`), not in r0.

    .text
    .extern func_02134008
    .extern func_021340d4
    .extern func_02142578

    // Floats are compared by their bits: after `cmp rX, #0`, `bicmi` and `rsbmi` turn a negative float into the negated
    // magnitude, so a signed compare orders them and -0 equals +0. A NaN (bits shifted up one above 0xff000000) is
    // quiet when bit 22 is set. The quiet tests return a value for a quiet NaN and raise invalid for a signalling one;
    // the signalling tests raise invalid for any NaN.
    //
    // Three-way float compare of r0 and r1: 0 equal, 1 less, 2 greater, 3 unordered.
    .global func_02131694
    .type func_02131694, @function
func_02131694:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    mov r2, #3
    blo fcmp_a_nan
    cmp r3, r1, lsl #1
    blo fcmp_b_nan
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    moveq r0, #0
    movlt r0, #1
    movgt r0, #2
    bx lr

    // Three-way float compare, signalling: as above, any NaN raises invalid.
fcmp3_signal:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    movlo r2, #3
    blo fcmp_invalid
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    moveq r0, #0
    movlt r0, #1
    movgt r0, #2
    bx lr

    // r0 != r1 (1 or 0); unordered gives 1. Both zero (any sign) are equal.
fne_quiet:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    mov r2, #1
    blo fcmp_a_nan
    cmp r3, r1, lsl #1
    blo fcmp_b_nan
    orr r3, r0, r1
    movs r3, r3, lsl #1
    moveq r0, #0
    bxeq lr
    cmp r0, r1
    movne r0, #1
    moveq r0, #0
    bx lr

    // r0 == r1 (1 or 0); unordered gives 0.
feq_quiet:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    mov r2, #0
    blo fcmp_a_nan
    cmp r3, r1, lsl #1
    blo fcmp_b_nan
    orr r3, r0, r1
    movs r3, r3, lsl #1
    moveq r0, #1
    bxeq lr
    cmp r0, r1
    moveq r0, #1
    movne r0, #0
    bx lr

    // Compares r0 and r1 into the flags: eq when both are zero, otherwise those of `cmp r0, r1`; unordered gives ne.
fflags_quiet:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    blo fflags_a_nan
    cmp r3, r1, lsl #1
    blo fflags_b_nan
    orr r3, r0, r1
    movs r3, r3, lsl #1
    bxeq lr
    cmp r0, r1
    bx lr

    // r0 < r1 (1 or 0), signalling.
    .global _fls
_fls:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    movlo r2, #0
    blo fcmp_invalid
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movlt r0, #1
    movge r0, #0
    bx lr

    // r0 <= r1 (1 or 0), signalling.
fle_signal:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    movlo r2, #0
    blo fcmp_invalid
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movle r0, #1
    movgt r0, #0
    bx lr

    // Compares r0 and r1 into the flags, signalling: eq when both are zero, otherwise those of `cmp r0, r1`, or of
    // `cmp r1, r0` when either is negative. Unordered gives hi (carry set, zero clear).
fflags_signal_hi:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo fflags_invalid_hi
    orr r3, r0, r1
    movs r3, r3, lsl #1
    cmpeq r0, r0
    bxeq lr
    orrs r2, r0, r1
    bmi fflags_signal_hi_negative
    cmp r0, r1
    bx lr
fflags_signal_hi_negative:
    cmp r1, r0
    bx lr

    // r0 > r1 (1 or 0), signalling.
    .global _fgr
_fgr:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    movlo r2, #0
    blo fcmp_invalid
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movgt r0, #1
    movle r0, #0
    bx lr

    // r0 >= r1 (1 or 0), signalling.
    .global _fgeq
_fgeq:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    movlo r2, #0
    blo fcmp_invalid
    cmp r0, #0
    bicmi r0, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r1, #0
    bicmi r1, r1, #0x80000000
    rsbmi r1, r1, #0
    cmp r0, r1
    movge r0, #1
    movlt r0, #0
    bx lr

    // As the flag compare above; unordered gives eq with carry clear.
fflags_signal_eq:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    cmphs r3, r1, lsl #1
    blo fflags_invalid_eq
    orr r3, r0, r1
    movs r3, r3, lsl #1
    cmpeq r0, r0
    bxeq lr
    orrs r2, r0, r1
    bmi fflags_signal_eq_negative
    cmp r0, r1
    bx lr
fflags_signal_eq_negative:
    cmp r1, r0
    bx lr

    // 1 when r0 or r1 is a NaN, else 0.
funordered:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    mov r2, #1
    blo fcmp_a_nan
    cmp r3, r1, lsl #1
    blo fcmp_b_nan
    mov r0, #0
    bx lr

    // 1 when neither r0 nor r1 is a NaN, else 0.
fordered:
    mov r3, #0xff000000
    cmp r3, r0, lsl #1
    mov r2, #0
    blo fcmp_a_nan
    cmp r3, r1, lsl #1
    blo fcmp_b_nan
    mov r0, #1
    bx lr

    // Raise invalid: set the sticky flag in the status word from func_02142578 (trap on 0x100) and return r2.
    // The argument registers are saved around the call.
fcmp_invalid:
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip, #0]
    tst r3, #0x100
    bne func_021321cc
    orr r3, r3, #1
    str r3, [ip, #0]
    mov r0, r2
    bx lr

    // Raise invalid, then return ne (movs of 1).
fflags_invalid_ne:
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip, #0]
    tst r3, #0x100
    bne func_021321cc
    orr r3, r3, #1
    str r3, [ip, #0]
    movs r2, #1
    bx lr

    // Raise invalid, then return hi: 0xff000000 + 0x10000000 sets the carry, clears zero.
fflags_invalid_hi:
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip, #0]
    tst r3, #0x100
    bne func_021321cc
    orr r3, r3, #1
    str r3, [ip, #0]
    mov r2, #0xff000000
    adds r2, r2, #0x10000000
    bx lr

    // Raise invalid, then return eq with the carry clear (0 + 0).
fflags_invalid_eq:
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr r3, [ip, #0]
    tst r3, #0x100
    bne func_021321cc
    orr r3, r3, #1
    str r3, [ip, #0]
    mov r2, #0
    adds r2, r2, #0
    bx lr

    // r0 is a NaN: signalling raises invalid; quiet returns r2 unless r1 is a signalling NaN.
fcmp_a_nan:
    tst r0, #0x400000
    beq fcmp_invalid
    cmp r3, r1, lsl #1
    movhs r0, r2
    bxhs lr

    // r1 is a NaN: signalling raises invalid, quiet returns r2.
fcmp_b_nan:
    tst r1, #0x400000
    beq fcmp_invalid
    mov r0, r2
    bx lr

    // Flag compares: r0 is a NaN, as above but returning ne.
fflags_a_nan:
    tst r0, #0x400000
    beq fflags_invalid_ne
    cmp r3, r1, lsl #1
    blo fflags_b_nan
    movs r2, #1
    bx lr

    // Flag compares: r1 is a NaN.
fflags_b_nan:
    tst r1, #0x400000
    beq fflags_invalid_ne
    movs r2, #1
    bx lr

    // Doubles are r1:r0 and r3:r2 (high words r1, r3). `cmn ip, rX, lsl #1` with ip = 0x200000 sets the carry when the
    // exponent is all ones; a NaN then has a nonzero significand, quiet when bit 19 of the high word is set. Two
    // positive doubles compare as unsigned 64-bit numbers; when either is negative the operands are swapped, and two
    // zeros of any sign are equal. The special paths load ip with the unordered result first.
    //
    // Three-way double compare: 0 equal, 1 less, 2 greater, 3 unordered.
dcmp3_quiet:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dcmp3_quiet_a_special
    cmn ip, r3, lsl #1
    bhs dcmp3_quiet_b_special
dcmp3_quiet_ordered:
    orrs ip, r3, r1
    bmi dcmp3_quiet_negative
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #0
    movlo r0, #1
    movhi r0, #2
    bx lr
dcmp3_quiet_negative:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    moveq r0, #0
    movlo r0, #1
    movhi r0, #2
    bx lr
dcmp3_quiet_a_special:
    movne ip, #3
    bne dcmp_a_nan
    cmp r0, #0
    movhi ip, #3
    bhi dcmp_a_nan
    cmn ip, r3, lsl #1
    blo dcmp3_quiet_ordered
dcmp3_quiet_b_special:
    movne ip, #3
    bne dcmp_b_nan
    cmp r2, #0
    movhi ip, #3
    bhi dcmp_b_nan
    b dcmp3_quiet_ordered

    // Three-way double compare, signalling.
dcmp3_signal:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dcmp3_signal_a_special
    cmn ip, r3, lsl #1
    bhs dcmp3_signal_b_special
dcmp3_signal_ordered:
    orrs ip, r3, r1
    bmi dcmp3_signal_negative
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #0
    movlo r0, #1
    movhi r0, #2
    bx lr
dcmp3_signal_negative:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    moveq r0, #0
    movlo r0, #1
    movhi r0, #2
    bx lr
dcmp3_signal_a_special:
    movne ip, #3
    bne dcmp_invalid
    cmp r0, #0
    movhi ip, #3
    bhi dcmp_invalid
    cmn ip, r3, lsl #1
    blo dcmp3_signal_ordered
dcmp3_signal_b_special:
    movne ip, #3
    bne dcmp_invalid
    cmp r2, #0
    movhi ip, #3
    bhi dcmp_invalid
    b dcmp3_signal_ordered

    // r1:r0 != r3:r2 (1 or 0); unordered gives 1.
    .global _dneq
_dneq:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dneq_a_special
    cmn ip, r3, lsl #1
    bhs dneq_b_special
dneq_ordered:
    orrs ip, r3, r1
    bmi dneq_negative
    cmp r1, r3
    cmpeq r0, r2
    movne r0, #1
    moveq r0, #0
    bx lr
dneq_negative:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movne r0, #1
    moveq r0, #0
    bx lr
dneq_a_special:
    movne ip, #1
    bne dcmp_a_nan
    cmp r0, #0
    movhi ip, #1
    bhi dcmp_a_nan
    cmn ip, r3, lsl #1
    blo dneq_ordered
dneq_b_special:
    movne ip, #1
    bne dcmp_b_nan
    cmp r2, #0
    movhi ip, #1
    bhi dcmp_b_nan
    b dneq_ordered

    // r1:r0 == r3:r2 (1 or 0); unordered gives 0.
    .global _deq
_deq:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs deq_a_special
    cmn ip, r3, lsl #1
    bhs deq_b_special
deq_ordered:
    orrs ip, r3, r1
    bmi deq_negative
    cmp r1, r3
    cmpeq r0, r2
    moveq r0, #1
    movne r0, #0
    bx lr
deq_negative:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    moveq r0, #1
    movne r0, #0
    bx lr
deq_a_special:
    movne ip, #0
    bne dcmp_a_nan
    cmp r0, #0
    movhi ip, #0
    bhi dcmp_a_nan
    cmn ip, r3, lsl #1
    blo deq_ordered
deq_b_special:
    movne ip, #0
    bne dcmp_b_nan
    cmp r2, #0
    movhi ip, #0
    bhi dcmp_b_nan
    b deq_ordered

    // Compares the doubles into the flags; unordered gives ne.
dflags_quiet:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dflags_quiet_a_special
    cmn ip, r3, lsl #1
    bhs dflags_quiet_b_special
dflags_quiet_ordered:
    orrs ip, r3, r1
    bmi dflags_quiet_negative
    cmp r1, r3
    cmpeq r0, r2
    bx lr
dflags_quiet_negative:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    bx lr
dflags_quiet_a_special:
    bne dflags_a_nan
    cmp r0, #0
    bhi dflags_a_nan
    cmn ip, r3, lsl #1
    blo dflags_quiet_ordered
dflags_quiet_b_special:
    bne dflags_b_nan
    cmp r2, #0
    bhi dflags_b_nan
    b dflags_quiet_ordered

    // r1:r0 < r3:r2 (1 or 0), signalling.
    .global _dls
_dls:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dls_a_special
    cmn ip, r3, lsl #1
    bhs dls_b_special
dls_ordered:
    orrs ip, r3, r1
    bmi dls_negative
    cmp r1, r3
    cmpeq r0, r2
    movlo r0, #1
    movhs r0, #0
    bx lr
dls_negative:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movlo r0, #1
    movhs r0, #0
    bx lr
dls_a_special:
    movne ip, #0
    bne dcmp_invalid
    cmp r0, #0
    movhi ip, #0
    bhi dcmp_invalid
    cmn ip, r3, lsl #1
    blo dls_ordered
dls_b_special:
    movne ip, #0
    bne dcmp_invalid
    cmp r2, #0
    movhi ip, #0
    bhi dcmp_invalid
    b dls_ordered

    // r1:r0 <= r3:r2 (1 or 0), signalling.
    .global _dleq
_dleq:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dleq_a_special
    cmn ip, r3, lsl #1
    bhs dleq_b_special
dleq_ordered:
    orrs ip, r3, r1
    bmi dleq_negative
    cmp r1, r3
    cmpeq r0, r2
    movls r0, #1
    movhi r0, #0
    bx lr
dleq_negative:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movls r0, #1
    movhi r0, #0
    bx lr
dleq_a_special:
    movne ip, #0
    bne dcmp_invalid
    cmp r0, #0
    movhi ip, #0
    bhi dcmp_invalid
    cmn ip, r3, lsl #1
    blo dleq_ordered
dleq_b_special:
    movne ip, #0
    bne dcmp_invalid
    cmp r2, #0
    movhi ip, #0
    bhi dcmp_invalid
    b dleq_ordered

    // Compares the doubles into the flags, signalling; unordered gives hi.
dflags_signal_hi:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dflags_signal_hi_a_special
    cmn ip, r3, lsl #1
    bhs dflags_signal_hi_b_special
dflags_signal_hi_ordered:
    orrs ip, r3, r1
    bmi dflags_signal_hi_negative
    cmp r1, r3
    cmpeq r0, r2
    bx lr
dflags_signal_hi_negative:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    cmpeq r1, r1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    bx lr
dflags_signal_hi_a_special:
    bne dflags_invalid_hi
    cmp r0, #0
    bhi dflags_invalid_hi
    cmn ip, r3, lsl #1
    blo dflags_signal_hi_ordered
dflags_signal_hi_b_special:
    bne dflags_invalid_hi
    cmp r2, #0
    bhi dflags_invalid_hi
    b dflags_signal_hi_ordered

    // r1:r0 > r3:r2 (1 or 0), signalling.
    .global _dgr
_dgr:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dgr_a_special
    cmn ip, r3, lsl #1
    bhs dgr_b_special
dgr_ordered:
    orrs ip, r3, r1
    bmi dgr_negative
    cmp r1, r3
    cmpeq r0, r2
    movhi r0, #1
    movls r0, #0
    bx lr
dgr_negative:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #0
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movhi r0, #1
    movls r0, #0
    bx lr
dgr_a_special:
    movne ip, #0
    bne dcmp_invalid
    cmp r0, #0
    movhi ip, #0
    bhi dcmp_invalid
    cmn ip, r3, lsl #1
    blo dgr_ordered
dgr_b_special:
    movne ip, #0
    bne dcmp_invalid
    cmp r2, #0
    movhi ip, #0
    bhi dcmp_invalid
    b dgr_ordered

    // r1:r0 >= r3:r2 (1 or 0), signalling.
dge_signal:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dge_a_special
    cmn ip, r3, lsl #1
    bhs dge_b_special
dge_ordered:
    orrs ip, r3, r1
    bmi dge_negative
    cmp r1, r3
    cmpeq r0, r2
    movhs r0, #1
    movlo r0, #0
    bx lr
dge_negative:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    moveq r0, #1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    movhs r0, #1
    movlo r0, #0
    bx lr
dge_a_special:
    movne ip, #0
    bne dcmp_invalid
    cmp r0, #0
    movhi ip, #0
    bhi dcmp_invalid
    cmn ip, r3, lsl #1
    blo dge_ordered
dge_b_special:
    movne ip, #0
    bne dcmp_invalid
    cmp r2, #0
    movhi ip, #0
    bhi dcmp_invalid
    b dge_ordered

    // Compares the doubles into the flags, signalling; unordered gives eq with the carry clear.
dflags_signal_eq:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dflags_signal_eq_a_special
    cmn ip, r3, lsl #1
    bhs dflags_signal_eq_b_special
dflags_signal_eq_ordered:
    orrs ip, r3, r1
    bmi dflags_signal_eq_negative
    cmp r1, r3
    cmpeq r0, r2
    bx lr
dflags_signal_eq_negative:
    orr ip, r0, ip, lsl #1
    orrs ip, ip, r2
    cmpeq r1, r1
    bxeq lr
    cmp r3, r1
    cmpeq r2, r0
    bx lr
dflags_signal_eq_a_special:
    bne dflags_invalid_eq
    cmp r0, #0
    bhi dflags_invalid_eq
    cmn ip, r3, lsl #1
    blo dflags_signal_eq_ordered
dflags_signal_eq_b_special:
    bne dflags_invalid_eq
    cmp r2, #0
    bhi dflags_invalid_eq
    b dflags_signal_eq_ordered

    // 1 when either double is a NaN, else 0.
dunordered:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dunordered_a_special
    cmn ip, r3, lsl #1
    bhs dunordered_b_special
dunordered_no:
    mov r0, #0
    bx lr
dunordered_a_special:
    movne ip, #1
    bne dcmp_a_nan
    cmp r0, #0
    movhi ip, #1
    bhi dcmp_a_nan
    cmn ip, r3, lsl #1
    blo dunordered_no
dunordered_b_special:
    movne ip, #1
    bne dcmp_b_nan
    cmp r2, #0
    movhi ip, #1
    bhi dcmp_b_nan
    b dunordered_no

    // 1 when neither double is a NaN, else 0.
dordered:
    mov ip, #0x200000
    cmn ip, r1, lsl #1
    bhs dordered_a_special
    cmn ip, r3, lsl #1
    bhs dordered_b_special
dordered_yes:
    mov r0, #1
    bx lr
dordered_a_special:
    movne ip, #0
    bne dcmp_a_nan
    cmp r0, #0
    movhi ip, #0
    bhi dcmp_a_nan
    cmn ip, r3, lsl #1
    blo dordered_yes
dordered_b_special:
    movne ip, #0
    bne dcmp_b_nan
    cmp r2, #0
    movhi ip, #0
    bhi dcmp_b_nan
    b dordered_yes

    // Raise invalid for a double compare and return the result in ip, which is saved with lr first; the trap path
    // drops both.
dcmp_invalid:
    stmfd sp!, {ip, lr}
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr lr, [ip, #0]
    tst lr, #0x100
    bne func_021321e0
    orr lr, lr, #1
    str lr, [ip, #0]
    ldmfd sp!, {r0}
    ldmfd sp!, {lr}
    bx lr

    // Raise invalid, then return ne.
dflags_invalid_ne:
    stmfd sp!, {ip, lr}
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr lr, [ip, #0]
    tst lr, #0x100
    bne func_021321e0
    orr lr, lr, #1
    str lr, [ip, #0]
    add sp, sp, #4
    movs ip, #1
    ldmfd sp!, {lr}
    bx lr

    // Raise invalid, then return hi.
dflags_invalid_hi:
    stmfd sp!, {ip, lr}
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr lr, [ip, #0]
    tst lr, #0x100
    bne func_021321e0
    orr lr, lr, #1
    str lr, [ip, #0]
    add sp, sp, #4
    mov ip, #0xff000000
    adds ip, ip, #0x10000000
    ldmfd sp!, {lr}
    bx lr

    // Raise invalid, then return eq with the carry clear.
dflags_invalid_eq:
    stmfd sp!, {ip, lr}
    stmfd sp!, {r0, r1, r2, r3, lr}
    bl func_02142578
    mov ip, r0
    ldmfd sp!, {r0, r1, r2, r3, lr}
    ldr lr, [ip, #0]
    tst lr, #0x100
    bne func_021321e0
    orr lr, lr, #1
    str lr, [ip, #0]
    add sp, sp, #4
    mov ip, #0
    adds ip, ip, #0
    ldmfd sp!, {lr}
    bx lr

    // r1:r0 is a NaN: signalling raises invalid; quiet returns ip unless r3:r2 is a signalling NaN.
dcmp_a_nan:
    tst r1, #0x80000
    beq dcmp_invalid
    stmfd sp!, {ip}
    mov ip, #0x200000
    cmn ip, r3, lsl #1
    ldmfd sp!, {ip}
    blo dcmp_return_ip
    bne dcmp_b_nan
    cmp r2, #0
    beq dcmp_return_ip

    // r3:r2 is a NaN: signalling raises invalid, quiet returns ip.
dcmp_b_nan:
    tst r3, #0x80000
    beq dcmp_invalid
dcmp_return_ip:
    mov r0, ip
    bx lr

    // Flag compares: r1:r0 is a NaN, as above but returning ne.
dflags_a_nan:
    tst r1, #0x80000
    beq dflags_invalid_ne
    stmfd sp!, {ip}
    mov ip, #0x200000
    cmn ip, r3, lsl #1
    ldmfd sp!, {ip}
    blo dflags_return_ne
    bne dflags_b_nan
    cmp r2, #0
    beq dflags_return_ne

    // Flag compares: r3:r2 is a NaN.
dflags_b_nan:
    tst r3, #0x80000
    beq dflags_invalid_ne
dflags_return_ne:
    movs ip, #1
    bx lr
    .size func_02131694, . - func_02131694

// Invalid trap for floats: event code 0x04000049 with the operands in r0, r1.
    .global func_021321cc
    .type func_021321cc, @function
func_021321cc:
    stmfd sp!, {lr}
    ldr r2, fcmp_code_invalid
    bl func_021340d4
    ldmfd sp!, {lr}
    bx lr
    .size func_021321cc, . - func_021321cc

// Invalid trap for doubles: event code 0x040000c9 on the stack, the operands in r0-r3.
    .global func_021321e0
    .type func_021321e0, @function
func_021321e0:
    ldr ip, dcmp_code_invalid
    stmfd sp!, {ip}
    bl func_02134008
    add sp, sp, #8
    ldmfd sp!, {lr}
    bx lr
    // Constant words: the event codes for the invalid traps.
fcmp_code_invalid:
    .word 0x04000049
dcmp_code_invalid:
    .word 0x040000c9
    .size func_021321e0, . - func_021321e0
