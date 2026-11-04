#include "code_02147954.h"

// clang-format off
// Fills the sixteen words at a with a 4x4 identity in 20.12 fixed point: 0x1000 on the diagonal, 0 elsewhere.
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward and move the base off r0; separate stores of constants stay `str`
// (docs/compiler.md, ldm/stm; checked on C). Here the stores are `stm r0!` with lists of constants that do not start at
// r0.
asm void Matrix4x4Identity(s32 *a) {
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2}
    bx lr
}

// Copies the first three words of each of the four rows of four at a to b (four rows of three).
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward and move the base off r0; separate stores of constants stay `str`
// (docs/compiler.md, ldm/stm; checked on C). Here it copies with `ldm r0!` / `stm r1!` and data in r2, r3 and ip.
asm void Matrix4x4ToMatrix4x3(const s32 *a, Unk02012f58 *b) {
    ldmia r0!, {r2, r3, ip}
    add r0, r0, #4
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    add r0, r0, #4
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    add r0, r0, #4
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    add r0, r0, #4
    stmia r1!, {r2, r3, ip}
    bx lr
}
// clang-format on
