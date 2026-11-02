#include "code_0200eddc.h"

// clang-format off
// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200eddc(void) {
    mov r1, #0x0
loop_outer:
    mov r0, #0x0
loop_inner:
    orr r2, r1, r0
    mcr p15, 0, r2, c7, c10, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt loop_inner
    add r1, r1, #0x40000000
    cmp r1, #0x0
    bne loop_outer
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200ee08(void) {
    mov ip, #0x0
    mov r1, #0x0
loop_outer:
    mov r0, #0x0
loop_inner:
    orr r2, r1, r0
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, r2, c7, c14, 2
    add r0, r0, #0x20
    cmp r0, #0x400
    blt loop_inner
    add r1, r1, #0x40000000
    cmp r1, #0x0
    bne loop_outer
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200ee3c(void *p, u32 n) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c6, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200ee58(void *p, u32 n) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c10, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200ee74(const void *a, int b) {
    mov ip, #0x0
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, ip, c7, c10, 4
    mcr p15, 0, r0, c7, c14, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200ee98(void) {
    mov r0, #0x0
    mcr p15, 0, r0, c7, c10, 4
    bx lr
}

// Not compiled code: C has no way to write a coprocessor 15 register (mcr).
asm void func_0200eea4(void *p, u32 n) {
    add r1, r1, r0
    bic r0, r0, #0x1f
loop:
    mcr p15, 0, r0, c7, c5, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt loop
    bx lr
}
// clang-format on
