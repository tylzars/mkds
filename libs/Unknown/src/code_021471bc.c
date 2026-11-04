#include "code_021471bc.h"

// clang-format off
// Fills the twelve words at a with a 4x3 identity in 20.12 fixed point: 0x1000 on the diagonal of the first three rows,
// 0 elsewhere.
// Not compiled code: the stores are `stm r0!` with lists that do not start at r0. The 1.2 compiler builds ldm/stm only
// in prologues, epilogues and block moves (struct copies and fills), which keep their data in r0 upward and move the
// base off r0; separate stores of constants stay `str` (docs/compiler.md, ldm/stm; checked on C).
asm void Matrix4x3Identity(Unk02012f58 *a) {
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

// Copies the twelve words at a (four rows of three) to b as four rows of four, the fourth column being 0, 0, 0, 0x1000.
// Not compiled code: it saves r4 alone, with no lr and no padding word, where 1.2 saves lr with r4 and pads every frame
// to 8 bytes; and it copies with `ldm r0!` / `stm r1!` lists 1.2 builds only for block moves (docs/compiler.md; frame
// layout in the compiler).
asm void Matrix4x3ToMatrix4x4(const Unk02012f58 *a, s32 *b) {
    stmdb sp!, {r4}
    mov ip, #0
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, ip}
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, ip}
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, ip}
    mov ip, #0x1000
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, ip}
    ldmia sp!, {r4}
    bx lr
}

#pragma thumb on

// Fills the twelve words at a with the rows (b, 0, 0), (0, c, 0), (0, 0, d), (0, 0, 0).
// Not compiled code: it stores separate values with `stmia r0!`, which the 1.2 compiler builds in Thumb code only for
// block moves (docs/compiler.md, ldm/stm).
asm void Matrix4x3FromDiagonal(Unk02012f58 *a, s32 b, s32 c, s32 d) {
    stmia r0!, {r1}
    mov r1, #0
    str r3, [r0, #28]
    mov r3, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    mov r2, #0
    stmia r0!, {r1, r3}
    add r0, #4
    stmia r0!, {r1, r2, r3}
    bx lr
}

// Fills the twelve words at a with the rows (0x1000, 0, 0), (0, c, b), (0, -b, c), (0, 0, 0).
// Not compiled code: it stores separate values with `stmia r0!`, which the 1.2 compiler builds in Thumb code only for
// block moves (docs/compiler.md, ldm/stm). It also builds 0x1000 with `movs; lsls`, which 1.2 never does in Thumb code
// (docs/compiler.md, Thumb constants).
asm void Matrix4x3FromPairX(s32 *a, s32 b, s32 c) {
    str r1, [r0, #20]
    neg r1, r1
    str r1, [r0, #28]
    mov r1, #1
    lsl r1, r1, #12
    stmia r0!, {r1}
    mov r3, #0
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2}
    str r1, [r0, #4]
    add r0, #12
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

// Fills the twelve words at a with the rows (c, 0, -b), (0, 0x1000, 0), (b, 0, c), (0, 0, 0).
// Not compiled code: it stores separate values with `stmia r0!`, which the 1.2 compiler builds in Thumb code only for
// block moves (docs/compiler.md, ldm/stm). It also builds 0x1000 with `movs; lsls`, which 1.2 never does in Thumb code
// (docs/compiler.md, Thumb constants).
asm void Matrix4x3FromPairY(void *a, s32 b, s32 c) {
    str r1, [r0, #24]
    mov r3, #0
    stmia r0!, {r2, r3}
    neg r1, r1
    stmia r0!, {r1, r3}
    mov r1, #1
    lsl r1, r1, #12
    stmia r0!, {r1, r3}
    add r0, #4
    mov r1, #0
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

// Fills the twelve words at a with the rows (c, b, 0), (-b, c, 0), (0, 0, 0x1000), (0, 0, 0).
// Not compiled code: it stores separate values with `stmia r0!`, which the 1.2 compiler builds in Thumb code only for
// block moves (docs/compiler.md, ldm/stm). It also builds 0x1000 with `movs; lsls`, which 1.2 never does in Thumb code
// (docs/compiler.md, Thumb constants).
asm void Matrix4x3FromPairZ(s32 *a, s32 b, s32 c) {
    stmia r0!, {r2}
    mov r3, #0
    stmia r0!, {r1, r3}
    neg r1, r1
    stmia r0!, {r1, r2, r3}
    mov r1, #0
    mov r2, #0
    mov r3, #1
    lsl r3, r3, #12
    stmia r0!, {r1, r2, r3}
    mov r3, #0
    stmia r0!, {r1, r2, r3}
    bx lr
}

#pragma thumb off
// clang-format on
