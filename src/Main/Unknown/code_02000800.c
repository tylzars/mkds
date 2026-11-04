#include "Main/Unknown/code_02000800.h"

// clang-format off
// Start-up: sets the stacks of the IRQ, supervisor and system modes, clears the stack memory and two other areas,
// unpacks main and runs the autoload copies, clears the uninitialised data and its cache lines, sets the IRQ handler
// address, then calls FloatInit, func_02000b48 and CallCtorTable and jumps to main with lr = 0xffff0000.
// Not compiled code: it switches processor modes and sets sp directly (msr), writes coprocessor 15 (mcr) and ends in a
// jump with a set return address instead of a call; C has no way to do any of these.
asm void Entry(void) {
    mov ip, #0x4000000
    str ip, [ip, #0x208]
    bl func_02000a5c
    mov r0, #0x13
    msr cpsr_c, r0
    ldr r0, =data_027e0000
    add r0, r0, #0x3fc0
    mov sp, r0
    mov r0, #0x12
    msr cpsr_c, r0
    ldr r0, =data_027e0000
    add r0, r0, #0x3fc0
    sub r0, r0, #0x40
    sub sp, r0, #0x4
    ldr r1, =0xc00
    sub r1, r0, r1
    mov r0, #0x1f
    msr cpsr_fsxc, r0
    sub sp, r1, #0x4
    mov r0, #0x0
    ldr r1, =data_027e0000
    mov r2, #0x4000
    bl func_02000920
    mov r0, #0x0
    ldr r1, =0x5000000
    mov r2, #0x400
    bl func_02000920
    mov r0, #0x200
    ldr r1, =0x7000000
    mov r2, #0x400
    bl func_02000920
    ldr r1, =BuildInfo
    ldr r0, [r1, #0x14]
    bl func_02000934
    bl func_020009e0
    ldr r0, =BuildInfo
    ldr r1, [r0, #0xc]
    ldr r2, [r0, #0x10]
    mov r3, r1
    mov r0, #0x0
clear_bss:
    cmp r1, r2
    strlo r0, [r1], #0x4
    blo clear_bss
    bic r1, r3, #0x1f
flush_line:
    mcr p15, 0, r0, c7, c10, 4
    mcr p15, 0, r1, c7, c5, 1
    mcr p15, 0, r1, c7, c14, 1
    add r1, r1, #0x20
    cmp r1, r2
    blt flush_line
    ldr r1, =0x27fff9c
    str r0, [r1, #0x0]
    ldr r1, =data_027e0000
    add r1, r1, #0x3fc0
    add r1, r1, #0x3c
    ldr r0, =func_01ff8000
    str r0, [r1, #0x0]
    bl FloatInit
    bl func_02000b48
    bl CallCtorTable
    ldr r1, =main
    ldr lr, =0xffff0000
    bx r1
}
// clang-format on
