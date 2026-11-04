#include "code_02146cbc.h"

// clang-format off
// Fills the nine words at a with a 3x3 identity in 20.12 fixed point: 0x1000 on the diagonal, 0 elsewhere.
// Not compiled code: the stores are `stm r0!` with lists that do not start at r0. The 1.2 compiler builds ldm/stm only
// in prologues, epilogues and block moves (struct copies and fills), which keep their data in r0 upward and move the
// base off r0; separate stores of constants stay `str` (docs/compiler.md, ldm/stm; checked on C).
asm void Matrix3x3Identity(Unk02012f58 *a) {
    mov r2, #0x1000
    str r2, [r0, #32]
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

// Copies the nine words at a to b and clears the three words after them (a 3x3 block becomes a 4x3 one with a zero last
// row).
// Not compiled code: it copies with `ldm r0!` / `stm r1!` and data in r2, r3 and ip. The 1.2 compiler builds ldm/stm
// only in prologues, epilogues and block moves (struct copies and fills), which keep their data in r0 upward and move
// the base off r0; separate stores of constants stay `str` (docs/compiler.md, ldm/stm; checked on C).
asm void Matrix3x3ToMatrix4x3(const s32 *a, s32 *b) {
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    mov r2, #0
    str r2, [r1]
    str r2, [r1, #4]
    str r2, [r1, #8]
    bx lr
}

// Copies the 3x3 block of words at a to b transposed (rows become columns).
// Not compiled code: it saves r4-r9 without lr; in 1.2 code a function that saves r4 also saves lr (docs/compiler.md,
// Registers), and the transposed stores are `stm` lists 1.2 never builds outside block moves.
asm void Matrix3x3Transpose(const void *a, void *b) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9}
    ldmia r0, {r2, r3, r4, r5, r6, r7, r8, r9, ip}
    stmia r1!, {r2, r5, r8}
    stmia r1!, {r3, r6, r9}
    stmia r1!, {r4, r7, ip}
    ldmfd sp!, {r4, r5, r6, r7, r8, r9}
    bx lr
}

#pragma thumb on

// Fills the nine words at a with the rows (0x1000, 0, 0), (0, c, b), (0, -b, c).
// Not compiled code: it builds 0x1000 with `movs; lsls`, which 1.2 never does in Thumb code (it loads such a constant
// from a constant word; docs/compiler.md, Thumb constants).
asm void Matrix3x3FromPairX(s32 *a, s32 b, s32 c) {
    mov r3, #1
    lsl r3, r3, #12
    str r3, [r0]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #8]
    str r3, [r0, #12]
    str r2, [r0, #16]
    str r1, [r0, #20]
    str r3, [r0, #24]
    neg r1, r1
    str r1, [r0, #28]
    str r2, [r0, #32]
    bx lr
}

// Fills the nine words at a with the rows (c, 0, -b), (0, 0x1000, 0), (b, 0, c).
// Not compiled code: it builds 0x1000 with `movs; lsls`, which 1.2 never does in Thumb code (it loads such a constant
// from a constant word; docs/compiler.md, Thumb constants).
asm void Matrix3x3FromPairY(s32 *a, s32 b, s32 c) {
    str r2, [r0]
    str r2, [r0, #32]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #12]
    str r3, [r0, #20]
    str r3, [r0, #28]
    neg r2, r1
    mov r3, #1
    lsl r3, r3, #12
    str r1, [r0, #24]
    str r2, [r0, #8]
    str r3, [r0, #16]
    bx lr
}

// Fills the nine words at a with the rows (c, b, 0), (-b, c, 0), (0, 0, 0x1000).
// Not compiled code: it builds 0x1000 with `movs; lsls`, which 1.2 never does in Thumb code (it loads such a constant
// from a constant word; docs/compiler.md, Thumb constants). It also stores the arguments with `stmia r0!`, which 1.2
// builds in Thumb code only for block moves.
asm void Matrix3x3FromPairZ(s32 *a, s32 b, s32 c) {
    stmia r0!, {r2}
    mov r3, #0
    stmia r0!, {r1, r3}
    neg r1, r1
    stmia r0!, {r1, r2}
    mov r1, #1
    lsl r1, r1, #12
    str r3, [r0]
    str r3, [r0, #4]
    str r3, [r0, #8]
    str r1, [r0, #12]
    bx lr
}

#pragma thumb off
// clang-format on
