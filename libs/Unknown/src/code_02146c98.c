#include "code_02146c98.h"

// clang-format off
// Sets the four words at dst to the 2x2 identity matrix (0x1000 on the diagonal, 0 elsewhere).
asm void MTX_Identity22_(s32 *dst) {
    mov r1, #0
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r2}
    bx lr
}
// clang-format on
