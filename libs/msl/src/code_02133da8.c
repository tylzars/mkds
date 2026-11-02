#pragma avoid_byte all

#include "code_02133da8.h"
#include "code_021423e4.h"

// clang-format off
// Clears the floating-point status word (func_02142578) and the five words from offset 4 of the block func_02142584
// returns.
// Not compiled code: it saves lr alone with `stmdb sp!, {lr}`, a 4-byte frame with no padding word; the 1.2 compiler
// pads every frame to 8 bytes (frame layout in the compiler; C of the same function gives `sub sp, sp, #4`).
asm void func_02133da8(void) {
    stmdb sp!, {lr}
    bl func_02142578
    mov r1, #0
    str r1, [r0]
    bl func_02142584
    mov r1, #0
    str r1, [r0, #4]
    str r1, [r0, #8]
    str r1, [r0, #12]
    str r1, [r0, #16]
    str r1, [r0, #20]
    ldmia sp!, {lr}
    bx lr
}

// Updates the floating-point status word: clears the bits in a, then flips the bits in b; returns the old value.
// Not compiled code: it saves r0-r2, ip and lr around its call, inside the body (a 20-byte frame); 1.2 saves registers
// only in its prologue, never ip or the argument registers, and pads every frame to 8 bytes (docs/compiler.md; frame
// layout in the compiler).
asm u32 func_02133ddc(u32 a, u32 b) {
    stmfd sp!, {r0, r1, r2, ip, lr}
    bl func_02142578
    mov r3, r0
    ldmfd sp!, {r0, r1, r2, ip, lr}
    ldr r2, [r3]
    bic ip, r2, r0
    eor ip, ip, r1
    str ip, [r3]
    mov r0, r2
    bx lr
}

// Like func_02133ddc, for the flag bits only: a and b hold flags in bits 0-4 and trap enables in bits 16-20, which are
// moved down to bits 8-12 first. Returns the old flags (bits 0-4), the old trap enables moved up to bits 16-20, and bit
// 30 set.
// Not compiled code: it saves r0-r2, ip and lr around its call, inside the body; 1.2 saves registers only in its
// prologue, never ip or the argument registers, and pads every frame to 8 bytes.
asm u32 func_02133e04(u32 a, u32 b) {
    and r2, r0, #0x1f
    and r3, r0, #0x1f0000
    orr r0, r2, r3, lsr #8
    and r2, r1, #0x1f
    and r3, r1, #0x1f0000
    orr r1, r2, r3, lsr #8
    stmfd sp!, {r0, r1, r2, ip, lr}
    bl func_02142578
    mov r3, r0
    ldmfd sp!, {r0, r1, r2, ip, lr}
    ldr r2, [r3]
    bic ip, r2, r0
    eor ip, ip, r1
    str ip, [r3]
    and r0, r2, #0x1f
    and r2, r2, #0x1f00
    orr r0, r0, r2, lsl #8
    orr r0, r0, #0x40000000
    bx lr
}
// clang-format on
