#include "code_02146c98.h"

// clang-format off
// Stores 0x1000, 0, 0, 0x1000 at param_1 and returns param_1 + 4 (the word after them).
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward and move the base off r0; separate stores of constants stay `str`
// (docs/compiler.md, ldm/stm; checked on C). Here the stores are `stm r0!` with lists of constants that do not start at
// r0.
asm u32 *Matrix2x2Identity(s32 *a) {
    mov r1, #0
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r2}
    bx lr
}
// clang-format on
