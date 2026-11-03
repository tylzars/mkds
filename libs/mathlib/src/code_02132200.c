#include "code_02132200.h"
#include "code_021423e4.h"
#include "code_02134008.h"

// clang-format off
// Converts the float r0 to a double in r1:r0 (always exact). Denormals are normalised; a signalling NaN raises invalid
// (or traps with event code 0x04000018) and, like a quiet NaN, gives the default NaN.
// Not compiled code: it counts leading zeros with clz and tests bits with tst, neither of which the 1.2 compiler
// builds, and saves ip and the argument registers around its call in the middle of the body, where 1.2 saves registers
// only in the prologue and never ip (docs/compiler.md).
asm u64 _f2d(u32 a) {
    // r2 = the sign, ip = the exponent, r3 = the significand without its leading one, at the top. Exponent 0 (zero,
    // denormal) and 0xff (infinity, NaN) are special.
    and r2, r0, #0x80000000
    mov ip, r0, lsr #23
    mov r3, r0, lsl #9
    ands ip, ip, #0xff
    beq f2d_exponent_zero
    cmp ip, #255
    beq f2d_inf_or_nan
    // Rebias the exponent (+0x380) and pack.
f2d_pack:
    add ip, ip, #0x380
    mov r0, r3, lsl #20
    orr r1, r2, r3, lsr #12
    orr r1, r1, ip, lsl #20
    bx lr
    // Zero gives a signed zero.
f2d_exponent_zero:
    cmp r3, #0
    bne f2d_denormal
    mov r1, r2
    mov r0, #0
    bx lr
    // Denormal: shift the leading one out of the top with clz; exponent 1 minus the shift.
f2d_denormal:
    mov r3, r3, lsr #1
    clz ip, r3
    movs r3, r3, lsl ip
    rsb ip, ip, #1
    add r3, r3, r3
    b f2d_pack
    // Infinity gives infinity with the sign.
f2d_inf_or_nan:
    cmp r3, #0
    bhi f2d_nan
    ldr r1, =0x7ff00000
    orr r1, r1, r2
    mov r0, #0
    bx lr
    // NaN: quiet ones give the default NaN; signalling ones raise invalid first (or trap).
f2d_nan:
    tst r3, #0x80000000
    bne f2d_default_nan
    stmfd sp!, {r0, r1, r3, ip, lr}
    bl func_02142578
    mov r2, r0
    ldmfd sp!, {r0, r1, r3, ip, lr}
    ldr r3, [r2]
    tst r3, #0x100
    bne f2d_trap_invalid
    orr r3, r3, #1
    str r3, [r2]
    // Return the default NaN.
f2d_default_nan:
    mvn r0, #0
    bic r1, r0, #0x80000000
    bx lr
    // Invalid trap.
f2d_trap_invalid:
    ldr r1, =0x4000018
    stmdb sp!, {lr}
    bl func_02134188
    ldmia sp!, {lr}
    bx lr
}
// clang-format on
