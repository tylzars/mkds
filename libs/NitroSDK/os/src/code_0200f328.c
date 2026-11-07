#include "code_0200f328.h"
#include "code_0200f3e0.h"
#include "Main/Unknown/unk_02170000.h"

// clang-format off
// Reads a coprocessor 15 register and clears its low 12 bits.
// Not compiled code: C has no way to read or write a coprocessor 15 register (mrc/mcr).
asm u32 OS_GetDTCMAddress(void) {
    mrc p15, 0, r0, c9, c1, 0
    ldr r1, =0xfffff000
    and r0, r0, r1
    bx lr
}

// Sets bit 0 of coprocessor 15 register c1.
// Not compiled code: C has no way to read or write a coprocessor 15 register (mrc/mcr).
asm void OS_EnableProtectionUnit(void) {
    mrc p15, 0, r0, c1, c0, 0
    orr r0, r0, #0x1
    mcr p15, 0, r0, c1, c0, 0
    bx lr
}

// Clears bit 0 of coprocessor 15 register c1.
// Not compiled code: C has no way to read or write a coprocessor 15 register (mrc/mcr).
asm void OS_DisableProtectionUnit(void) {
    mrc p15, 0, r0, c1, c0, 0
    bic r0, r0, #0x1
    mcr p15, 0, r0, c1, c0, 0
    bx lr
}

// Writes param to protection region 1 (coprocessor 15 register c6,c1).
// Not compiled code: C has no way to read or write a coprocessor 15 register (mrc/mcr).
asm void OS_SetProtectionRegion1(u32 param) {
    mcr p15, 0, r0, c6, c1, 0
    bx lr
}

// Writes param to protection region 2 (coprocessor 15 register c6,c2).
// Not compiled code: C has no way to read or write a coprocessor 15 register (mrc/mcr).
asm void OS_SetProtectionRegion2(u32 param) {
    mcr p15, 0, r0, c6, c2, 0
    bx lr
}

// Exception vector handler: calls the debugger handler in OSi_DebuggerHandler when it is set, saves r0-r3, sp and lr just
// below main memory and switches the stack there. In mode 0x17 or 0x1b it calls OSi_GetAndDisplayContext, then waits
// for OSi_DebuggerHandler to be set.
// Not compiled code: it reads the status register (mrs), saves registers with `stmdb ip!` in the middle of
// the body and sets sp directly; C has no way to do any of these.
asm void OSi_ExceptionHandler(void) {
    ldr ip, =OSi_DebuggerHandler
    ldr ip, [ip, #0x0]
    cmp ip, #0x0
    movne lr, pc
    bxne ip
    ldr ip, =0x2000000
    stmdb ip!, {r0, r1, r2, r3, sp, lr}
    and r0, sp, #0x1
    mov sp, ip
    mrs r1, cpsr
    and r1, r1, #0x1f
    teq r1, #0x17
    bne check_mode_1b
    bl OSi_GetAndDisplayContext
    b wait_for_handler
check_mode_1b:
    teq r1, #0x1b
    bne wait_for_handler
    bl OSi_GetAndDisplayContext
wait_for_handler:
    ldr ip, =OSi_DebuggerHandler
    ldr ip, [ip, #0x0]
    cmp ip, #0x0
wait_zero:
    beq wait_zero
wait_forever:
    mov r0, r0
    b wait_forever
    ldmia sp!, {r0, r1, r2, r3, ip, lr}
    mov sp, ip
    bx lr
}
// clang-format on
