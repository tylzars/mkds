#include "code_0214a54c.h"

// clang-format off
// Writes 128 zero words to the one address a, four at a time (32 stores with no address update).
// Not compiled code: the 1.2 compiler builds ldm/stm only in prologues, epilogues and block moves (struct copies and
// fills), which keep their data in r0 upward and move the base off r0; separate stores of constants stay `str`
// (docs/compiler.md, ldm/stm; checked on C). Here every `stm r0` stores constants in r1-r3 and ip to the same address.
asm void MemZero128WordsToOneAddress(void *a) {
    mov r1, #0
    mov r2, #0
    mov r3, #0
    mov ip, #0
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    stmia r0, {r1, r2, r3, ip}
    bx lr
}
// clang-format on
