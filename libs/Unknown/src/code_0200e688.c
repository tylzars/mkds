#include "code_0200e688.h"

// clang-format off
// Hand-written asm: the compiler schedules the instructions in a different order and picks different registers.
asm void ThreadInitContext(Unk0200db5c *t, void (*f)(void *), u32 v) {
    add r1, r1, #0x4
    str r1, [r0, #0x40]
    str r2, [r0, #0x44]
    sub r2, r2, #0x40
    str r2, [r0, #0x38]
    ands r1, r1, #0x1
    movne r1, #0x3f
    moveq r1, #0x1f
    str r1, [r0, #0x0]
    mov r1, #0x0
    str r1, [r0, #0x4]
    str r1, [r0, #0x8]
    str r1, [r0, #0xc]
    str r1, [r0, #0x10]
    str r1, [r0, #0x14]
    str r1, [r0, #0x18]
    str r1, [r0, #0x1c]
    str r1, [r0, #0x20]
    str r1, [r0, #0x24]
    str r1, [r0, #0x28]
    str r1, [r0, #0x2c]
    str r1, [r0, #0x30]
    str r1, [r0, #0x34]
    str r1, [r0, #0x3c]
    bx lr
}
// clang-format on
