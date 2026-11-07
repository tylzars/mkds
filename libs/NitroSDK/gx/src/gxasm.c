#include "gxasm.h"

// clang-format off
// Sends the twelve words at pSrc, three at a time, all to the one address pDest (no update of pDest).
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward and move the base off r0; separate stores of constants stay `str`
// (docs/compiler.md, ldm/stm; checked on C). Here it reads with `ldm r0!` into r2, r3 and ip and stores them with `stm
// r1`, always to the same address.
asm void GX_SendFifo48B(const void *pSrc, void *pDest) {
    ldmia r0!, {r2, r3, ip}
    stmia r1, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1, {r2, r3, ip}
    bx lr
}

// Sends the sixteen words at pSrc, eight at a time, all to the one address pDest (no update of pDest).
// Not compiled code: it saves r4-r8 without lr and without a padding word, where 1.2 saves lr with r4 and pads every
// frame to 8 bytes (docs/compiler.md, Registers; frame layout in the compiler); and its eight-register `ldm r0!` / `stm
// r1` copies are not a 1.2 block move (data in r0 upward, base moved off r0).
asm void GX_SendFifo64B(const void *pSrc, void *pDest) {
    stmfd sp!, {r4, r5, r6, r7, r8}
    ldmia r0!, {r2, r3, r4, r5, r6, r7, r8, ip}
    stmia r1, {r2, r3, r4, r5, r6, r7, r8, ip}
    ldmia r0!, {r2, r3, r4, r5, r6, r7, r8, ip}
    stmia r1, {r2, r3, r4, r5, r6, r7, r8, ip}
    ldmfd sp!, {r4, r5, r6, r7, r8}
    bx lr
}
// clang-format on
