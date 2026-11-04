#include "code_02023374.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"

void func_020244f4(Unk02180728 *a, s32 b, s32 c, u32 d, u16 *e, u16 **f) {
    s32 n;
    Unk02022aa8 *s;
    u16 *p;
    Unk02022aa8_f *g;
    u16 ch;

    n = a->mUnk_08;
    s = a->mUnk_04;
    p = e;
    g = s->mUnk_04;
    ch = g(&p);
    if (ch != 0) {
        do {
            if (ch == 10) {
                break;
            }
            b += func_02023450((Unk02023374 *) a->mUnk_00, s, b, c, d, ch);
            b += n;
            ch = g(&p);
        } while (ch != 0);
    }
    if (f != 0) {
        *f = ch == 10 ? p : 0;
    }
}

void func_020243f0(Unk02180728 *a, s32 b, s32 c, s32 d, u32 e, u32 f, u16 *g) {
    s32 h;
    s32 n;
    s32 x;
    u32 m1;
    u32 m2;
    s32 t;
    u16 *v;

    h = a->mUnk_0c + ((Unk02022aa8 *) a->mUnk_04)->mUnk_00->mUnk_01;
    v = g;
    if (v == 0) {
        return;
    }
    m1 = f & 0x800;
    m2 = f & 0x400;
    t = (d + 1) / 2;
    do {
        x = b;
        if (m1 != 0) {
            n = func_02022bbc(a->mUnk_04, a->mUnk_08, (u8 *) v, 0);
            x = b + (d - n);
        } else if (m2 != 0) {
            n = func_02022bbc(a->mUnk_04, a->mUnk_08, (u8 *) v, 0);
            x = b + (t - (n + 1) / 2);
        }
        func_020244f4(a, x, c, e, v, &v);
        c += h;
    } while (v != 0);
}

u32 func_02024340(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f) {
    Unk02022b10 z;

    func_02022aa8(&z, a->mUnk_04, a->mUnk_08, a->mUnk_0c, f);
    if (e & 0x10) {
        b -= (z.mUnk_00 + 1) / 2;
    } else if (e & 0x20) {
        b -= z.mUnk_00;
    }
    if (e & 2) {
        c -= (z.mUnk_04 + 1) / 2;
    } else if (e & 4) {
        c -= z.mUnk_04;
    }
    func_020243f0(a, b, c, z.mUnk_00, d, e, f);
}

void func_0202428c(Unk02180728 *a, s32 b, s32 c, s32 d, s32 e, s32 f, u32 g, u16 *h) {
    s32 n;

    if (g & 0x100) {
        n = func_02022b44(a->mUnk_04, a->mUnk_0c, (u8 *) h);
        c += e - n;
    } else if (g & 0x80) {
        n = func_02022b44(a->mUnk_04, a->mUnk_0c, (u8 *) h);
        c += (e + 1) / 2 - (n + 1) / 2;
    }
    func_020243f0(a, b, c, d, f, g, h);
}

// clang-format off
// Walks two block sizes (c by d, with the limits a by b) down through the table data_usa_021530f8, which gives the shifts
// e and f for the base-2 logarithms of the remaining sizes (each capped at 3 once it is 8 or more), and returns the sum
// of the areas it peels off. It stops when a whole block no longer fits and adds the remainder of the position.
// Not compiled code: it takes the logarithms with clz, which 1.2 never builds (docs/compiler.md).
asm u32 func_02024184(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x4
    ldr r11, =data_usa_021530f8
    mov r9, #0x0
    mov r10, #0x3
    mvn r7, #0x0
loop_top:
    ldr r4, [sp, #0x2c]
    ldr r6, [sp, #0x28]
    and ip, r3, r7, lsl r4
    cmp ip, r1
    mov r8, r7, lsl r6
    mov r5, r7, lsl r4
    and lr, r2, r7, lsl r6
    bhi d_masked_above
    mla r9, r2, ip, r9
    cmp lr, r0
    movhi r2, lr
    subhi r1, r1, ip
    subhi r3, r3, ip
    bhi next_sizes
    sub r3, r3, ip
    mla r9, lr, r3, r9
    sub r0, r0, lr
    sub r1, r1, ip
    sub r2, r2, lr
    b next_sizes
d_masked_above:
    cmp lr, r0
    mlals r9, lr, ip, r9
    mvn r3, r5
    movls r3, ip
    subls r0, r0, lr
    subls r2, r2, lr
    bls next_sizes
    and r2, r1, r5
    mla r5, lr, r2, r9
    and r2, r0, r8
    and r1, r1, r3
    add r2, r5, r2, lsl r4
    mvn r3, r8
    add r1, r2, r1, lsl r6
    and r0, r0, r3
    add sp, sp, #0x4
    add r0, r1, r0
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
next_sizes:
    cmp r2, #0x8
    movlt r4, r2
    movge r5, r10
    clzlt r4, r4
    rsblt r5, r4, #0x1f
    cmp r3, #0x8
    movge r4, r10
    movlt r4, r3
    clzlt r4, r4
    rsblt r4, r4, #0x1f
    add r4, r11, r4, lsl #0x3
    add r6, r4, r5, lsl #0x1
    ldrb r5, [r4, r5, lsl #0x1]
    ldrb r4, [r6, #0x1]
    str r5, [sp, #0x28]
    str r4, [sp, #0x2c]
    b loop_top
    add sp, sp, #0x4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
}// clang-format on
