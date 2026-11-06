#include "code_021471bc.h"

// clang-format off
// Sets dst to the 4x3 identity matrix: 0x1000 on the diagonal of the first three rows, 0 elsewhere.
asm void MTX_Identity43_(MtxFx43 *dst) {
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

// Copies the four rows of three words at src to dst as four rows of four, the fourth column being 0, 0, 0, 0x1000.
asm void MTX_Copy43To44_(const MtxFx43 *src, s32 *dst) {
    stmdb sp!, {r4}
    mov ip, #0
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, ip}
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, ip}
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, ip}
    mov ip, #0x1000
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, ip}
    ldmia sp!, {r4}
    bx lr
}

#pragma thumb on

// Sets dst to the scale matrix with x, y and z on the diagonal and a zero translation.
asm void MTX_Scale43_(MtxFx43 *dst, s32 x, s32 y, s32 z) {
    stmia r0!, {r1}
    mov r1, #0
    str r3, [r0, #28]
    mov r3, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    mov r2, #0
    stmia r0!, {r1, r3}
    add r0, #4
    stmia r0!, {r1, r2, r3}
    bx lr
}

// Sets dst to the rotation about the x axis, rows (0x1000, 0, 0), (0, cosVal, sinVal), (0, -sinVal, cosVal), (0, 0, 0).
asm void MTX_RotX43_(s32 *dst, s32 sinVal, s32 cosVal) {
    str r1, [r0, #20]
    neg r1, r1
    str r1, [r0, #28]
    mov r1, #1
    lsl r1, r1, #12
    stmia r0!, {r1}
    mov r3, #0
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2}
    str r1, [r0, #4]
    add r0, #12
    stmia r0!, {r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

// Sets dst to the rotation about the y axis, rows (cosVal, 0, -sinVal), (0, 0x1000, 0), (sinVal, 0, cosVal), (0, 0, 0).
asm void MTX_RotY43_(MtxFx43 *dst, s32 sinVal, s32 cosVal) {
    str r1, [r0, #24]
    mov r3, #0
    stmia r0!, {r2, r3}
    neg r1, r1
    stmia r0!, {r1, r3}
    mov r1, #1
    lsl r1, r1, #12
    stmia r0!, {r1, r3}
    add r0, #4
    mov r1, #0
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}

// Sets dst to the rotation about the z axis, rows (cosVal, sinVal, 0), (-sinVal, cosVal, 0), (0, 0, 0x1000), (0, 0, 0).
asm void MTX_RotZ43_(s32 *dst, s32 sinVal, s32 cosVal) {
    stmia r0!, {r2}
    mov r3, #0
    stmia r0!, {r1, r3}
    neg r1, r1
    stmia r0!, {r1, r2, r3}
    mov r1, #0
    mov r2, #0
    mov r3, #1
    lsl r3, r3, #12
    stmia r0!, {r1, r2, r3}
    mov r3, #0
    stmia r0!, {r1, r2, r3}
    bx lr
}

#pragma thumb off
// clang-format on
