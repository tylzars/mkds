#include "code_0214d464.h"

// clang-format off
// Resumable form of the expansion in ExpandCompressed. a points at the saved state: the output pointer at 0, the number
// of bytes still to write at 4, the current flag byte at 0xb, the flag bits left at 0xc, the back copy length at 0xd
// and a pending-byte flag at 0xe. Reads at most c bytes from b, writes every output byte with swpb, stores the state
// back and returns the number of bytes still to write.
// Not compiled code: it uses swpb, tst and a flag-setting add of an asr operand, which the 1.2 compiler never builds.
asm s32 ExpandCompressedContinue(void *a, const u8 *b, s32 c) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
    ldr r3, [r0, #0x0]
    ldr r4, [r0, #0x4]
    ldrb r5, [r0, #0xb]
    ldrb r6, [r0, #0xc]
    ldrb r7, [r0, #0xd]
    ldrb r8, [r0, #0xe]
lz_top:
    cmp r4, #0x0
    ble lz_store
    cmp r6, #0x0
    beq lz_flags
lz_item:
    cmp r2, #0x0
    beq lz_store
    tst r5, #0x80
    bne lz_back_copy
    ldrb r9, [r1], #0x1
    sub r4, r4, #0x1
    sub r2, r2, #0x1
    swpb r9, r9, [r3]
    add r3, r3, #0x1
    b lz_item_done
lz_back_copy:
    cmp r8, #0x0
    bne lz_second
    ldrb r7, [r1], #0x1
    mov r8, #0x1
    sub r2, r2, #0x1
lz_second:
    cmp r2, #0x0
    beq lz_store
    and r9, r7, #0xf
    mov r10, r9, lsl #0x8
    ldrb r9, [r1], #0x1
    mov r8, #0x0
    sub r2, r2, #0x1
    orr r9, r9, r10
    add r9, r9, #0x1
    mov r10, #0x3
    adds r7, r10, r7, asr #0x4
    beq lz_item_done
lz_copy_loop:
    ldrb r10, [r3, -r9]
    sub r4, r4, #0x1
    swpb r10, r10, [r3]
    add r3, r3, #0x1
    subs r7, r7, #0x1
    bgt lz_copy_loop
lz_item_done:
    cmp r4, #0x0
    beq lz_store
    mov r5, r5, lsl #0x1
    subs r6, r6, #0x1
    bne lz_item
lz_flags:
    cmp r2, #0x0
    beq lz_store
    ldrb r5, [r1], #0x1
    mov r6, #0x8
    sub r2, r2, #0x1
    b lz_top
lz_store:
    str r3, [r0, #0x0]
    str r4, [r0, #0x4]
    strb r5, [r0, #0xb]
    strb r6, [r0, #0xc]
    strb r7, [r0, #0xd]
    strb r8, [r0, #0xe]
    mov r0, r4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10}
    bx lr
}
// clang-format on
