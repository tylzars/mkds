#include "code_0200cd1c.h"
#include "code_0200ce60.h"

// non-matching: the original loads the callee address into r1 and branches with bx r1; ours uses ip. Every other ARM
// tail call through a register in the game uses ip (117 of them), so the original is likely hand-written
s32 func_0200cd1c(u32 a) {
    return func_0200ce80(a);
}

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

// non-matching: the original tests with pl/mi after cmp #0x60 (ours ge/lt) and keeps the shifted bit in its own
// register (mov, lsr, then orr; ours folds the shift into the orr). No other compiled ARM function in the game has a
// pl/mi test after a compare with a constant, so the original is likely hand-written like its neighbour
void IdFree(s32 a) {
    u32 *p;
    p = (u32 *) 0x027fffb0;
    if (a >= 0x60) {
        p = p + 1;
        a = a - 0x60;
    } else {
        a = a - 0x40;
    }
    *p = *p | (0x80000000u >> a);
}
