#pragma avoid_byte all

#include "code_021423e4.h"
#include "code_02004dc0.h"
#include "Main/Unknown/unk_0217e000.h"

void func_02142590(void) {
    func_0214240c();
}

Unk0217ee98 *func_02142584(void) {
    return &data_0217eeb8;
}

u32 *func_02142578(void) {
    return &data_0217eeb4;
}

void func_02142540(void) {
    void (**p)(void);

    for (p = data_usa_02161748; p != 0 && *p != 0; p++) {
        (*p)();
    }
}

void func_021424e8(void) {
    Unk02005210 *n;

    n = data_0217eeb0;
    if (n == 0) {
        return;
    }
    do {
        data_0217eeb0 = n->mUnk_00;
        ((void (*)(void *, s32)) n->mUnk_04)(n->mUnk_08, -1);
        n = data_0217eeb0;
    } while (n != 0);
}

s32 func_0214245c(s32 a, u8 *b, u32 *c) {
    u32 i;
    u32 n;

    n = *c;
    for (i = 0; i < n; i++) {
        b[i] = (u8) func_021423f8();
        if (b[i] == 13 || b[i] == 10) {
            *c = i + 1;
            break;
        }
    }
    return 0;
}

s32 func_02142424(s32 a, const u8 *b, const u32 *c) {
    u32 i;
    u32 n;

    n = *c;
    for (i = 0; i < n; i++) {
        func_021423e4(b + i);
    }
    return 0;
}

s32 func_0214241c(void) {
    return 0;
}

// clang-format off
// Makes supervisor call 0x123456 with r0 = 3 and r1 = a; func_02142424 calls it once per byte of a buffer, with the
// byte's address.
// Not compiled code: the 1.2 compiler never builds swi (its code generator has no use of that instruction), and it
// saves lr alone with a single store and returns by loading pc, where 1.2 pads every frame to 8 bytes and returns
// through `bx lr` (docs/compiler.md; frame layout in the compiler).
asm void func_021423e4(const void *a) {
    str lr, [sp, #-4]!
    mov r1, r0
    mov r0, #3
    swi 0x123456
    ldr pc, [sp], #4
}

// Makes supervisor call 0x123456 with r0 = 7 and r1 = 0 and returns its r0; func_0214245c stores the low byte of each
// result into a buffer.
// Not compiled code: swi, and the same one-word frame and return as func_021423e4.
asm u32 func_021423f8(void) {
    str lr, [sp, #-4]!
    mov r1, #0
    mov r0, #7
    swi 0x123456
    ldr pc, [sp], #4
}

// Makes supervisor call 0x123456 with r0 = 24 and r1 = 0, then returns.
// Not compiled code: swi, and it returns with `mov pc, lr`, where 1.2 with -interworking returns through `bx lr`
// (docs/compiler.md).
asm void func_0214240c(void) {
    mov r1, #0
    mov r0, #24
    swi 0x123456
    mov pc, lr
}
// clang-format on
