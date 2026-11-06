#include "code_02146cbc.h"

// clang-format off
// Sets the nine words at dst to the 3x3 identity matrix (0x1000 on the diagonal, 0 elsewhere).
asm void MTX_Identity33_(MtxFx43 *dst) {
    mov r2, #0x1000
    str r2, [r0, #32]
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

// Copies the nine words at src to dst and clears the three words after them (the translation of the 4x3 matrix).
asm void MTX_Copy33To43_(const s32 *src, s32 *dst) {
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    mov r2, #0
    str r2, [r1]
    str r2, [r1, #4]
    str r2, [r1, #8]
    bx lr
}

// Writes the transpose of the 3x3 matrix at src to dst.
asm void MTX_Transpose33_(const void *src, void *dst) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9}
    ldmia r0, {r2, r3, r4, r5, r6, r7, r8, r9, ip}
    stmia r1!, {r2, r5, r8}
    stmia r1!, {r3, r6, r9}
    stmia r1!, {r4, r7, ip}
    ldmfd sp!, {r4, r5, r6, r7, r8, r9}
    bx lr
}

#pragma thumb on

// Sets dst to the rotation about the x axis: rows (0x1000, 0, 0), (0, cosVal, sinVal), (0, -sinVal, cosVal).
asm void MTX_RotX33_(s32 *dst, s32 sinVal, s32 cosVal) {
    mov r3, #1
    lsl r3, r3, #12
    str r3, [r0]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #8]
    str r3, [r0, #12]
    str r2, [r0, #16]
    str r1, [r0, #20]
    str r3, [r0, #24]
    neg r1, r1
    str r1, [r0, #28]
    str r2, [r0, #32]
    bx lr
}

// Sets dst to the rotation about the y axis: rows (cosVal, 0, -sinVal), (0, 0x1000, 0), (sinVal, 0, cosVal).
asm void MTX_RotY33_(s32 *dst, s32 sinVal, s32 cosVal) {
    str r2, [r0]
    str r2, [r0, #32]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #12]
    str r3, [r0, #20]
    str r3, [r0, #28]
    neg r2, r1
    mov r3, #1
    lsl r3, r3, #12
    str r1, [r0, #24]
    str r2, [r0, #8]
    str r3, [r0, #16]
    bx lr
}

// Sets dst to the rotation about the z axis: rows (cosVal, sinVal, 0), (-sinVal, cosVal, 0), (0, 0, 0x1000).
asm void MTX_RotZ33_(s32 *dst, s32 sinVal, s32 cosVal) {
    stmia r0!, {r2}
    mov r3, #0
    stmia r0!, {r1, r3}
    neg r1, r1
    stmia r0!, {r1, r2}
    mov r1, #1
    lsl r1, r1, #12
    str r3, [r0]
    str r3, [r0, #4]
    str r3, [r0, #8]
    str r1, [r0, #12]
    bx lr
}

#pragma thumb off
// clang-format on
