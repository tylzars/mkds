#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_0200b00c.h"
#include "Main/Unknown/code_0200b018.h"
#include "Main/Unknown/code_0200b02c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02009928.h"
#include "Main/Unknown/code_020091fc.h"

#pragma thumb on

// non-matching: 0x78 bytes, original 0x74; 4 lines differ; first: original `ldr r1, [pc, #96]`, ours `ldr r0, [pc, //
// #96]`
void func_02007ec4(Unk02007ec4 *a, u16 b, u16 c, u32 d, u32 e) {
    u32 v1;
    u32 v2;
    func_0214d1fc(*(u16 *) 0x027ffc40 == 2 ? (void *) 0x027ffc42 : (void *) 0, a, 0x3c);
    a->mUnk_3c = 0x10;
    a->mUnk_44 = a->mUnk_0c | (a->mUnk_0e << 16);
    a->mUnk_48 = a->mUnk_10;
    a->mUnk_4a = 0;
    a->mUnk_4c = b;
    a->mUnk_4e = c;
    v1 = 0;
    if (e != 0) {
        v1 = 8;
    }
    if (d != 0) {
        v2 = 4;
    } else {
        v2 = 0;
    }
    a->mUnk_4b = v2 | v1 | 1;
}

// non-matching: same size; register allocation only; 0 lines differ; first: original `nothing`, ours `nothing`
u32 func_02007f38(u32 a, u32 b, u32 c) {
    u32 v1;
    switch (data_02152bc0[a]) {
        case 0:
        case 2:
// non-matching: 0x84 bytes, original 0x7c; 43 lines differ; first: original `ldr r0, [pc, #96]`, ours `ldr
// r0, [pc, // #104]`
            return func_02007ff0(a, b, c);
        case 1:
            if (b >= 0x02000000 && b < 0x023fe800) {
                v1 = b + c;
                if (b < 0x02300000 && v1 > 0x02300000) {
                    return 0;
                }
                if (v1 <= 0x02300000) {
                    return 1;
                }
                if (v1 < 0x023fe800 && c <= 0x40000) {
                    return 1;
                }
                return 0;
            }
            if (b >= 0x037f8000 && b < 0x0380f000) {
                if (b + c <= 0x0380f000) {
                    return 1;
                }
                return 0;
            }
            return 0;
        default:
            return 0;
    }
}

// non-matching: 0x84 bytes, original 0x7c; 43 lines differ; first: original `ldr r0, [pc, #96]`, ours `ldr r0, [pc,
// #104]`
u32 func_02007ff0(u32 a, u32 b, u32 c) {
    switch (data_02152bc0[a]) {
        case 2:
            if (b >= 0x027ffe00 && b + c <= 0x027fff60) {
                return 1;
            }
            return 0;
        case 0:
            if (b >= 0x02000000 && b + c <= 0x022c0000) {
                return 1;
            }
            return 0;
        case 1:
            if (b >= 0x022c0000 && b + c <= 0x02300000) {
                return 1;
            }
            if (b >= 0x02000000 && b + c <= 0x02300000) {
                return 1;
            }
            return 0;
        default:
            return 0;
    }
}

static inline struct Unk0216fdac *func_0200806c_inline(void) {
    return data_0216fdac;
}

BOOL func_0200806c(Unk020072c0_buf *a, void *b, u16 c, void *d) {
    u32 v4;
    Unk020082b4 *v2;
    Unk020082b4_0c *v3;
    Unk0200806c_b *v1;
    s8 i;
    v1 = b;
    v2 = d;
    if (c >= v1->mUnk_0c[3]) {
        return FALSE;
    }
    for (i = 2; i >= 0; i--) {
        if (c >= v1->mUnk_0c[i]) {
            break;
        }
    }
    if (i < 0) {
        return FALSE;
    }
    v4 = (c - v1->mUnk_0c[i]) * func_0200806c_inline()->mUnk_1318;
    v3 = &v2->mUnk_0c[i];
    a->mUnk_04 = v3->mUnk_08 - v4;
    if (a->mUnk_04 > data_0216fdac->mUnk_1318) {
        a->mUnk_04 = data_0216fdac->mUnk_1318;
    }
    a->mUnk_08 = v4 + v1->mUnk_00[i];
    a->mUnk_00 = v4 + v3->mUnk_00;
    a->mUnk_0c = i;
    return TRUE;
}

// non-matching: same size; 72 lines differ; first: original `str r0, [sp, #0]`, ours `adds r5, r0, #0`
u32 func_020080e8(Unk0200806c_b *a, Unk020082b4 *b) {
    u32 v1;
    u32 v2;
    u16 v3;
    u8 i;
    Unk020082b4_0c *v4;
    v1 = 0;
    if (b == NULL) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        a->mUnk_00[i] = v1;
        v1 += b->mUnk_0c[i].mUnk_08;
    }
    a->mUnk_0c[0] = 0;
    for (i = 0; i < 3; i++) {
        v4 = &b->mUnk_0c[i];
        v2 = v4->mUnk_08;
        v3 = a->mUnk_0c[i] + (u16) ((v2 + data_0216fdac->mUnk_1318 - 1) / data_0216fdac->mUnk_1318);
        if (func_02007f38(i, v4->mUnk_04, v2) == 0) {
            return 0;
        }
        if (i < 2) {
            a->mUnk_0c[i + 1] = v3;
        } else {
            a->mUnk_0c[3] = v3;
        }
    }
    return 1;
}

// non-matching: 0x128 bytes, original 0x12c; 86 lines differ; first: original `adds r4, r3, #0`, ours `adds r6, r3, #0`
void func_02008188(Unk02008188 *a, u32 *b, Unk020082b4_0c *c, u32 *d) {
    u32 v1;
    u32 v2;
    u32 *v3;
    switch (*b) {
        case 0:
            v3 = a->mUnk_028;
            if (a->mUnk_028[0] >= 0x02000000 && a->mUnk_028[0] < 0x022c0000 && a->mUnk_028[0] + v3[1] <= 0x022c0000) {
                c->mUnk_08 = v3[1];
                c->mUnk_04 = v3[0];
                c->mUnk_00 = c->mUnk_04;
                c->mUnk_0c &= ~1;
                return;
            }
            func_0200fd1c();
            return;
        case 1:
            v1 = 0;
            v2 = 0;
            v3 = a->mUnk_038;
            if (a->mUnk_038[0] >= 0x02000000 && a->mUnk_038[0] < 0x023fe800) {
                if (a->mUnk_038[0] + v3[1] > 0x02300000) {
                    if (a->mUnk_038[0] + v3[1] < 0x023fe800 && v3[1] <= 0x40000) {
                        v2 = 1;
                    } else {
                        v1 = 1;
                    }
                }
            } else if (a->mUnk_038[0] >= 0x037f8000 && a->mUnk_038[0] < 0x0380f000) {
                if (a->mUnk_038[0] + v3[1] <= 0x0380f000) {
                    v2 = 1;
                } else {
                    v1 = 1;
                }
            } else {
                v1 = 1;
            }
            if (v1 == 1) {
                func_0200fd1c();
            }
            c->mUnk_08 = v3[1];
            c->mUnk_04 = v3[0];
            if (v2 == 0) {
                c->mUnk_00 = c->mUnk_04;
            } else {
                c->mUnk_00 = *d;
                *d = *d + c->mUnk_08;
            }
            c->mUnk_0c = (c->mUnk_0c & ~1) | 1;
            return;
        case 2:
            c->mUnk_08 = 0x160;
            c->mUnk_04 = 0x027ffe00;
            c->mUnk_00 = c->mUnk_04;
            c->mUnk_0c &= ~1;
            return;
    }
}

void func_020082b4(Unk020082b4 *a, Unk02008188 *b) {
    u32 v1;
    u8 *v2;
    u32 *v4;
    Unk020082b4_0c *v3;
    s32 i;
    v1 = 0x022c0000;
    v2 = b->mUnk_160;
    a->mUnk_00 = b->mUnk_024;
    a->mUnk_04 = b->mUnk_034;
    v3 = a->mUnk_0c;
    v4 = data_02152bc0;
    for (i = 0; i < 3; i++) {
        func_02008188(b, v4, v3, &v1);
        v3++;
        v4++;
    }
    func_0214d1fc(v2, a->mUnk_3c, 0x88);
}

u32 func_02008310(void *a, Unk02008188 *b) {
    u32 v2;
    u32 v1;
    u32 v3;
    Unk0216fdac *v4;
    Unk020082b4 *v5;
    u8 i;
    v2 = 0xff;
    v1 = func_0200fca0();
    if (func_02009958() == 0) {
        func_0200fcb4(v1);
        return 0;
    }
    v4 = data_0216fdac;
    if (v4->mUnk_1524 + 1 > 0x10) {
        func_0200fcb4(v1);
        return 0;
    }
    for (i = 0; i < 0x10; i++) {
        if (((Unk0216fdac *) ((u8 *) v4 + i * 0x5d4))->mUnk_1d40 == a) {
            func_0200fcb4(v1);
            return 0;
        }
        if (((Unk0216fdac *) ((u8 *) v4 + i * 0x5d4))->mUnk_1d52 == 0) {
            v2 = i;
            break;
        }
    }
    if (i == 0x10) {
        func_0200fcb4(v1);
        return 0;
    }
    v3 = v2 * 0x5d4;
    ((Unk0216fdac *) ((u8 *) data_0216fdac + v3))->mUnk_1d40 = a;
    v5 = (Unk020082b4 *) (data_0216fdac->mUnk_1788 + v3);
    func_020082b4(v5, b);
    func_0214d1fc((u8 *) a + 0x1c, v5->mUnk_c4, 0x20);
    if (func_020080e8((Unk0200806c_b *) (data_0216fdac->mUnk_1d2c + v3), v5) == 0) {
        func_0200fcb4(v1);
        return 0;
    }
    func_02009828((Unk0200b610 *) (data_0216fdac->mUnk_1788 + 0xe4 + v3), a, (const u8 *) &data_0216fdac->mUnk_1300);
    ((Unk0216fdac *) ((u8 *) data_0216fdac + v3))->mUnk_1d21 = v2;
    func_020096f4((Unk0200b610 *) (data_0216fdac->mUnk_1788 + 0xe4 + v3));
    ((Unk0216fdac *) ((u8 *) data_0216fdac + v3))->mUnk_1d1f = data_0216fc30++;
    ((Unk0216fdac *) ((u8 *) data_0216fdac + v3))->mUnk_1d4e = 1;
    ((Unk0216fdac *) ((u8 *) data_0216fdac + v3))->mUnk_1d44 = b;
    ((Unk0216fdac *) ((u8 *) data_0216fdac + v3))->mUnk_1d54 = &b->mUnk_1e8;
    ((Unk0216fdac *) ((u8 *) data_0216fdac + v3))->mUnk_1d58 = b->mUnk_258;
    if (((Unk0216fdac *) ((u8 *) data_0216fdac + v3))->mUnk_1d54->mUnk_30[3].mUnk_0c != 0) {
        if (func_0200b018() == 0) {
            func_0200b00c(data_0216fdac->mUnk_7ce0);
            func_0200b02c(&data_0216fdac->mUnk_74e0, 0x800);
        }
    }
    ((Unk0216fdac *) ((u8 *) data_0216fdac + v3))->mUnk_1d52 = 1;
    data_0216fdac->mUnk_1524++;
    func_0200fcb4(v1);
    return 1;
}

#pragma thumb off
