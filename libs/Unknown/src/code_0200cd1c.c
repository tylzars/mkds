#include "code_0200cd1c.h"
#include "code_0200ce60.h"

// clang-format off
// Hand-written asm: jumps to OS_UnlockCartridge through r1; compiled C would jump through ip.
asm s32 OS_UnLockCartridge(u32 a) {
    ldr r1, =OS_UnlockCartridge
    bx r1
}
// clang-format on

// clang-format off
// Takes the highest set bit out of the two words at 0x027fffb0 (first word, then the second) and returns its number:
// 0x40 plus the bit position counted from the top for the first word, 0x60 plus it for the second, or -3 when both
// words are zero.
// Not compiled code: it counts leading zeros with clz, which 1.2 never builds (docs/compiler.md).
asm s32 IdAlloc(void) {
    ldr r3, =0x27fffb0
    ldr r1, [r3, #0x0]
    clz r2, r1
    cmp r2, #0x20
    movne r0, #0x40
    bne cd28_clear
    add r3, r3, #0x4
    ldr r1, [r3, #0x0]
    clz r2, r1
    cmp r2, #0x20
    ldr r0, =0xfffffffd
    bxeq lr
    mov r0, #0x60
cd28_clear:
    add r0, r0, r2
    mov r1, #0x80000000
    mov r1, r1, lsr r2
    ldr r2, [r3, #0x0]
    bic r2, r2, r1
    str r2, [r3, #0x0]
    bx lr
}
// clang-format on

// clang-format off
// Hand-written asm: sets bit a of the two words at 0x027fffb0 (bits 0x40 to 0x5f in the first, 0x60 and up in the
// second). It tests with pl/mi after a compare, which the compiler never does.
asm void IdFree(s32 a) {
    ldr r3, =0x27fffb0
    cmp r0, #0x60
    addpl r3, r3, #0x4
    subpl r0, r0, #0x60
    submi r0, r0, #0x40
    mov r1, #0x80000000
    mov r1, r1, lsr r0
    ldr r2, [r3, #0x0]
    orr r2, r2, r1
    str r2, [r3, #0x0]
    bx lr
}
// clang-format on
