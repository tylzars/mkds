#include "code_0200f3f4.h"

#include "code_0200f328.h"
#include "Main/Unknown/unk_02170000.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_0200f000.h"

UnkFunc *OSi_UserExceptionHandler;
UnkFunc *OSi_DebuggerHandler;
u32 OSi_UserExceptionHandlerArg;
u8 OSi_ExContext[0x80];

void OS_InitException(void) {
    u32 handler;
    Unk0200f4f0 *p;

    handler = *(u32 *) 0x027ffd9c;
    if (handler >= 0x2600000 && handler < 0x2800000) {
        OSi_DebuggerHandler = (UnkFunc *) handler;
    } else {
        OSi_DebuggerHandler = 0;
    }
    p = (Unk0200f4f0 *) 0x027e3000;
    if (OSi_DebuggerHandler == 0 || (OS_GetConsoleType() & 0x40000000) == 0) {
        *(UnkFunc **) 0x027ffd9c = (UnkFunc *) OSi_ExceptionHandler;
        p->mUnk_fdc = (UnkFunc *) OSi_ExceptionHandler;
    }
    OSi_UserExceptionHandler = 0;
}

// clang-format off
// Stores exinfo and the registers saved at the address in ip into the exception context OSi_ExContext (0x80 bytes),
// and the banked sp, lr and spsr of the mode in the saved status word.
// Not compiled code: it reads and writes the status registers (mrs/msr, spsr) and stores ip and r4-r11 as the
// caller left them; C has no way to do either.
asm void OSi_SetExContext(u32 exinfo) {
    ldr r1, =OSi_ExContext
    mrs r2, cpsr
    str r2, [r1, #0x74]
    str r0, [r1, #0x6c]
    ldr r0, [ip, #0x0]
    str r0, [r1, #0x4]
    ldr r0, [ip, #0x4]
    str r0, [r1, #0x8]
    ldr r0, [ip, #0x8]
    str r0, [r1, #0xc]
    ldr r0, [ip, #0xc]
    str r0, [r1, #0x10]
    ldr r2, [ip, #0x10]
    bic r2, r2, #0x1
    add r0, r1, #0x14
    stmia r0, {r4, r5, r6, r7, r8, r9, r10, r11}
    str ip, [r1, #0x70]
    ldr r0, [r2, #0x0]
    str r0, [r1, #0x64]
    ldr r3, [r2, #0x4]
    str r3, [r1, #0x0]
    ldr r0, [r2, #0x8]
    str r0, [r1, #0x34]
    ldr r0, [r2, #0xc]
    str r0, [r1, #0x40]
    mrs r0, cpsr
    orr r3, r3, #0x80
    bic r3, r3, #0x20
    msr cpsr_fsxc, r3
    str sp, [r1, #0x38]
    str lr, [r1, #0x3c]
    mrs r2, spsr
    str r2, [r1, #0x7c]
    msr cpsr_fsxc, r0
    bx lr
}

// Calls the user exception handler. Does nothing while OSi_UserExceptionHandler is zero; otherwise switches to mode 0x9f with the current sp, sets bit 0 of
// coprocessor 15 register c1, calls the function in OSi_UserExceptionHandler with OSi_ExContext and the word OSi_UserExceptionHandlerArg, and
// clears the bit again.
// Not compiled code: it switches the processor mode with msr, which C has no way to do.
asm void OSi_DisplayExContext(void) {
    stmdb sp!, {lr}
    sub sp, sp, #0x4
    ldr r0, =OSi_UserExceptionHandler
    ldr r0, [r0, #0x0]
    cmp r0, #0x0
    addeq sp, sp, #0x4
    ldmeqia sp!, {lr}
    bxeq lr
    mov r0, sp
    ldr r1, =0x9f
    msr cpsr_fsxc, r1
    mov sp, r0
    bl OS_EnableProtectionUnit
    ldr r1, =OSi_UserExceptionHandlerArg
    ldr r0, =OSi_UserExceptionHandler
    ldr r1, [r1, #0x0]
    ldr r2, [r0, #0x0]
    ldr r0, =OSi_ExContext
    blx r2
    bl OS_DisableProtectionUnit
    add sp, sp, #0x4
    ldmia sp!, {lr}
    bx lr
}
// clang-format on
