#include "00/code_02193818.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_0218e49c.h"
#include "00/code_02193e70.h"
#include "00/code_02194000.h"
#include "00/code_021965a0.h"
#include "00/code_02196590.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e368.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/unk_021b3000.h"
#include "code_02134d30.h"
#include "code_02135014.h"

void func_ov000_02193818(Unk0218f960 *param_1, Unk021937c0Node *param_2) {
    Unk0218f960_00 *a = param_1->mUnk_00;
    Unk021937c0Node *b = a->mUnk_424;
    Unk021937c0Node *c = 0;

    while (b != 0) {
        if (b == param_2) {
            if (c == 0) {
                a->mUnk_424 = b->mNext;
            } else {
                c->mNext = param_2->mNext;
            }
            func_ov000_02193858(param_1, param_2);
            return;
        }
        c = b;
        b = b->mNext;
    }
}

void func_ov000_02193858(Unk0218f960 *param_1, Unk021937c0Node *param_2) {
    Unk0218f960_00 *a = param_1->mUnk_00;
    Unk02193858 *b;

    if (param_2->mUnk_00 == 3) {
        b = (Unk02193858 *) param_2->mUnk_04;
        a->mUnk_210--;
        if (a->mUnk_210 < 0) {
            func_0213442c(data_ov000_021b32c0, data_ov000_021b32b0, 0, 0xb6);
        }
        func_ov000_0218e524(b->mUnk_04, 2);
        func_ov000_0218e53c(b->mUnk_04);
        func_ov000_021a3668(b->mUnk_18);
        b->mUnk_18 = 0;
        func_ov000_021a3668(b->mUnk_08);
        b->mUnk_08 = 0;
    }
    func_ov000_021a3668(param_2->mUnk_04);
    param_2->mUnk_04 = 0;
    func_ov000_021a3668(param_2);
}

u32 func_ov000_021938cc(Unk0218f960 *param_1, int param_2, int param_3, int *param_4, int param_5, int param_6,
                        int param_7) {
    Unk0218f960_00 *a = param_1->mUnk_00;
    Unk021937c0Node *b = func_ov000_021a3690(0x24);

    if (b == 0) {
        func_ov000_02196590(param_1, data_ov000_021b32e0);
        return 1;
    }
    b->mUnk_00 = param_2;
    b->mUnk_04 = (void *) param_3;
    b->mUnk_08 = param_5;
    b->mUnk_14 = 0;
    if (param_2 == 0) {
        b->mUnk_18 = 1;
    } else {
        b->mUnk_18 = a->mUnk_20c++;
        if (a->mUnk_20c < 2) {
            a->mUnk_20c = 2;
        }
    }
    b->mUnk_1c = 0;
    b->mUnk_0c.mUnk_00 = (void (*)(void *, void *, u32)) param_6;
    b->mUnk_0c.mUnk_04 = param_7;
    b->mNext = a->mUnk_424;
    a->mUnk_424 = b;
    *param_4 = (int) b;
    return 0;
}

// non-matching: case 3's clearing loop compiles as r0/r1/r2 = zero/count/pointer with a bgt exit where the original has
// r2 = pointer, r1 = count, r0 = zero with a bne exit (size 0x230 against 0x234)
s32 func_ov000_02193954(Unk0218f960 *param_1, Unk021937c0Node *param_2) {
    Unk0218f960_00 *a = param_1->mUnk_00;
    Unk02190ed4Cb b;
    Unk02193954_0 *c;
    Unk02193954_1 *d;
    Unk02193954_3 *e;
    Unk02193954_4 *f;
    s32 g;
    s32 h;
    u8 *q;

    if (param_1 == 0) {
        func_0213442c(data_ov000_021b32f0, data_ov000_021b32b0, 0, 0x22);
    }
    if (param_1->mUnk_00 == 0) {
        func_0213442c(data_ov000_021b3304, data_ov000_021b32b0, 0, 0x23);
    }
    if (param_2 == 0) {
        func_0213442c(data_ov000_021b3318, data_ov000_021b32b0, 0, 0x24);
    }
    b = param_2->mUnk_0c;
    if (b.mUnk_00 != 0) {
        switch (param_2->mUnk_00) {
            case 0:
                c = func_ov000_021a3690(0x20);
                if (c == 0) {
                    func_ov000_02196590(param_1, data_ov000_021b32e0);
                    return 1;
                }
                func_02134de0(c, 0, 0x20);
                c->mUnk_00 = param_2->mUnk_1c;
                if (a->mUnk_418 == 0x201) {
                    c->mUnk_04 = a->mUnk_1a0;
                    a->mUnk_1a0 = 0;
                }
                g = func_ov000_02190ed4(param_1, b, c, param_2, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 1:
                d = func_ov000_021a3690(8);
                if (d == 0) {
                    func_ov000_02196590(param_1, data_ov000_021b32e0);
                    return 1;
                }
                ((u8 *) d)[0] = 0;
                ((u8 *) d)[1] = 0;
                ((u8 *) d)[2] = 0;
                ((u8 *) d)[3] = 0;
                ((u8 *) d)[4] = 0;
                ((u8 *) d)[5] = 0;
                ((u8 *) d)[6] = 0;
                ((u8 *) d)[7] = 0;
                d->mUnk_00 = param_2->mUnk_1c;
                g = func_ov000_02190ed4(param_1, b, d, param_2, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 2:
                c = func_ov000_021a3690(0x204);
                if (c == 0) {
                    func_ov000_02196590(param_1, data_ov000_021b32e0);
                    return 1;
                }
                func_02134de0(c, 0, 0x204);
                c->mUnk_00 = param_2->mUnk_1c;
                g = func_ov000_02190ed4(param_1, b, c, param_2, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 3:
                e = func_ov000_021a3690(0x10);
                if (e == 0) {
                    func_ov000_02196590(param_1, data_ov000_021b32e0);
                    return 1;
                }
                h = 0x10;
                q = (u8 *) e;
                do {
                    *q++ = 0;
                    h--;
                } while (h != 0);
                e->mUnk_00 = param_2->mUnk_1c;
                e->mUnk_0c = 0;
                g = func_ov000_02190ed4(param_1, b, e, param_2, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 4:
                f = func_ov000_021a3690(4);
                if (f == 0) {
                    func_ov000_02196590(param_1, data_ov000_021b32e0);
                    return 1;
                }
                ((u8 *) f)[0] = 0;
                ((u8 *) f)[1] = 0;
                ((u8 *) f)[2] = 0;
                ((u8 *) f)[3] = 0;
                f->mUnk_00 = param_2->mUnk_1c;
                g = func_ov000_02190ed4(param_1, b, f, param_2, 0);
                if (g != 0) {
                    return g;
                }
                break;
            default:
                func_0213442c(data_ov000_021b32ac, data_ov000_021b32b0, 0, 0x6b);
                break;
        }
    }
    return 0;
}

s32 func_ov000_02193b88(Unk0218f960 *param_1, Unk02193f2cNode *param_2, const u8 *param_3, s32 param_4) {
    u8 a[0x24];
    s32 b;

    if (param_2 == 0) {
        func_0213442c(data_ov000_021b332c, data_ov000_021b333c, 0, 0x389);
    }
    if (param_3 == 0) {
        param_3 = data_ov000_021b3348;
    }
    if (param_4 == -1) {
        param_4 = func_0213a434(param_3);
    }
    func_02135014(a, data_ov000_021b334c, param_4);
    b = func_ov000_02190968(param_1, (Unk02190988 *) param_2, a);
    if (b != 0) {
        return b;
    }
    b = func_ov000_02190988(param_1, (Unk02190988 *) param_2, param_3, param_4);
    if (b != 0) {
        return b;
    }
    b = func_ov000_02190a24(param_1, (Unk02190988 *) param_2, 0);
    if (b != 0) {
        return b;
    }
    param_2->mUnk_10 = func_ov000_0218e320(0) + 0x12c;
    return 0;
}

u32 func_ov000_02193c20(Unk0218f960 *param_1, Unk02193f2cNode *param_2, u32 param_3, Unk02193c20 *param_4) {
    u8 a[0x44];
    u32 b = param_4->mUnk_04;
    u32 c = param_4->mUnk_00;
    u32 d = param_4->mUnk_08;

    if (param_4 == 0) {
        func_0213442c(data_ov000_021b335c, data_ov000_021b333c, 0, 0x376);
    }
    func_02135014(a, data_ov000_021b3368, param_3, c, b, d);
    return func_ov000_02190968(param_1, (Unk02190988 *) param_2, a);
}

s32 func_ov000_02193c74(Unk0218f960 *param_1, Unk02193f2cNode *param_2, u32 param_3, const u8 *param_4) {
    u32 b;
    s32 c;

    if (param_2 == 0) {
        func_0213442c(data_ov000_021b332c, data_ov000_021b333c, 0, 0x340);
    }
    if (param_4 == 0) {
        func_0213442c(data_ov000_021b337c, data_ov000_021b333c, 0, 0x341);
    }
    b = func_0213a434(param_4);
    {
        Unk02193c74 a = {0};
        a.mUnk_10 = param_3;
        c = func_ov000_02190b80(param_1, &a, data_ov000_021b338c);
        if (c != 0) {
            return c;
        }
        c = func_ov000_02190b58(param_1, &a, param_3);
        if (c != 0) {
            return c;
        }
        c = func_ov000_02190b80(param_1, &a, data_ov000_021b3390);
        if (c != 0) {
            return c;
        }
        c = func_ov000_02190b58(param_1, &a, b);
        if (c != 0) {
            return c;
        }
        c = func_ov000_02190b80(param_1, &a, data_ov000_021b3398);
        if (c != 0) {
            return c;
        }
        a.mUnk_14 = a.mUnk_08;
        c = func_ov000_02190ba0(param_1, (Unk021906e4 *) &a, param_4, b);
        if (c != 0) {
            return c;
        }
        c = func_ov000_02190c64(param_1, (Unk021906e4 *) &a, 0);
        if (c != 0) {
            return c;
        }
        func_ov000_0218dbc0(param_2->mUnk_38, &a);
        param_2->mUnk_10 = func_ov000_0218e320(0) + 0x12c;
        return 0;
    }
}

// non-matching: the 8-byte local sits at stack offset 4 and the pointer local at 0, the original has them at 0 and 8 (6
// words)
s32 func_ov000_02193d64(Unk0218f960 *param_1, Unk02193f2cNode *param_2) {
    Unk02194934 *a;
    s32 c;

    if (func_ov000_02194934(param_1, param_2->mUnk_0c, &a) == 0) {
        func_ov000_02196590(param_1, data_ov000_021b33a0);
        return 3;
    }
    param_2->mUnk_08 = func_ov000_0218e554(2, 1, 0);
    if (param_2->mUnk_08 == -1) {
        func_ov000_021965a0(param_1, 5, data_ov000_021b33bc);
        func_ov000_02190f4c(param_1, 3, 0);
        return 3;
    }
    if (func_ov000_0218e80c(param_2->mUnk_08, 0) == 0) {
        func_ov000_021965a0(param_1, 5, data_ov000_021b33e4);
        func_ov000_02190f4c(param_1, 3, 0);
        return 3;
    }
    func_ov000_02193ff4(param_2->mUnk_08);
    {
        Unk02193d64 b = {0};
        b.mUnk_01 = 2;
        b.mUnk_04 = a->mUnk_08->mUnk_10;
        b.mUnk_02 = a->mUnk_08->mUnk_14;
        c = func_ov000_0218e4b4(param_2->mUnk_08, &b, 8);
        if (c == -1) {
            c = func_ov000_0218e368(param_2->mUnk_08);
            if (c != -6 && c != -0x1a && c != -0x4c) {
                func_ov000_021965a0(param_1, 5, data_ov000_021b3418);
                func_ov000_02190f4c(param_1, 3, 1);
                return 3;
            }
        }
        param_2->mUnk_00 = 0x67;
        return 0;
    }
}
