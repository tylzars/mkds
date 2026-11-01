#include "Main/Unknown/code_02127a84.h"
#include "Main/Unknown/code_02127a38.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0214b824.h"
#include "code_02016468.h"

#pragma thumb on

s32 func_02127f14(s32 param_1) {
    Unk020b4934 *a;
    Unk020b47d8 *b;
    Unk020b4a44 *c;
    s32 s;
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    Unk0215d064 *e;

    func_020b4934(&a, func_02047a28(data_0216e840));
    func_020b47d8(&b, func_02047a28(data_0216e858));
    func_020b4a44(&c, func_02047a28(data_0216e874));
    param_1 = param_1 - a->mUnk_10;
    s = param_1 >> 5;
    data_0217d3f4->mUnk_89c = s;
    func_0200ee74(a->mUnk_14, a->mUnk_10);
    func_0214ba94(a->mUnk_14, param_1, a->mUnk_10);
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 32; j++) {
            *(data_0217d3f4->mUnk_2c + i * 32 + j) = s + *((u16 *) b->mUnk_0c + i * 32 + j);
        }
    }
    func_0200ee74(data_0217d3f4->mUnk_2c, b->mUnk_08);
    func_0214bdd4(data_0217d3f4->mUnk_2c, 0, b->mUnk_08);
    e = &data_0215d0a0;
    y = e->mUnk_02 * 32;
    x = e->mUnk_00;
    data_0217d3f4->mUnk_82c = data_0217d3f4->mUnk_89c + (x + y);
    data_0217d3f4->mUnk_830 = data_0217d3f4->mUnk_89c + (y + (x + 3));
    func_0200ee74(c->mUnk_0c, 0x1c0);
    func_0214c0f8(c->mUnk_0c + 0xe0, 0x1c0, 0x40);
    return param_1;
}

void func_02127e30(void) {
    s32 c;
    s32 i;
    s32 r;
    s32 f;
    Unk0215d064 *e;
    s32 w;
    s32 v;
    u8(*p)[2];
    s32 h;
    s32 q;

    i = 0;
    p = data_0215d09c;
    e = &data_0215d0a0;
    w = e->mUnk_01 - e->mUnk_00;
    h = e->mUnk_03 - e->mUnk_02;
    for (; i < 2; i++) {
        f = 0;
        if (i == data_0217d3f4->mUnk_18 && data_0217d3f4->mUnk_14 != 0) {
            f = 1;
        }
        for (r = 0; r <= h; r++) {
            for (c = 0; c <= w; c++) {
                q = c + (*p)[0] + ((r + (*p)[1]) << 5);
                v = r * 32 + (data_0217d3f4->mUnk_830 + c);
                if (f != 0) {
                    v = r * 32 + (data_0217d3f4->mUnk_82c + c);
                }
                if (f != 0) {
                    data_0217d3f4->mUnk_2c[q] = v + ((data_0217d3f4->mUnk_2c[q] & 0xffff0c00) + 0xe000);
                } else {
                    data_0217d3f4->mUnk_2c[q] = v + (data_0217d3f4->mUnk_2c[q] & 0xfffffc00);
                }
            }
        }
        p++;
    }
}

void func_02127db8(void) {
    s32 i;
    s32 r;
    s32 c;
    s32 v;
    s32 t;

    for (i = 0; i < 2; i++) {
        v = 0xe;
        if (data_0217d3f4->mUnk_18 != i) {
            v = 0xf;
        }
        for (r = data_0215d0ac[i].mUnk_02; r <= data_0215d0ac[i].mUnk_03; r++) {
            for (c = data_0215d0ac[i].mUnk_00; c <= data_0215d0ac[i].mUnk_01; c++) {
                t = data_0217d3f4->mUnk_2c[r * 32 + c];
                t &= 0xffff0fff;
                t += v << 12;
                data_0217d3f4->mUnk_2c[r * 32 + c] = t;
            }
        }
    }
}

void func_02127d74(void) {
    data_0217d3f4->mUnk_10 = 0;
    data_0217d3f4->mUnk_14 = 1;
    func_02127db8();
    func_02127e30();
    if (*(vu16 *) 0x27ffc40 != 2) {
        func_02016468(0x18, 0, data_0217d3f4->mUnk_2c, 0x800);
    }
}

void func_02127d28(void) {
    s32 a;

    a = data_0217d3f4->mUnk_18;
    data_0217d3f4->mUnk_18 = -1;
    func_02127db8();
    data_0217d3f4->mUnk_18 = a;
    data_0217d3f4->mUnk_10 = 0;
    data_0217d3f4->mUnk_14 = 1;
    if (*(vu16 *) 0x27ffc40 != 2) {
        func_02016468(0x18, 0, data_0217d3f4->mUnk_2c, 0x800);
    }
}

void func_02127c78(void) {
    s32 i;
    s32 j;
    s32 t;

    if (data_0217d3f4->mUnk_24 != 0) {
        func_02127d74();
        data_0217d3f4->mUnk_08 = 1;
        i = 0;
        data_0217d3f4->mUnk_24 = i;
        data_0217d3f4->mUnk_0c = i;
        data_0217d3f4->mUnk_20 = i;
        if (data_0217d3f4->mUnk_8a0 != 0) {
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 2; j++) {
                    t = (j + i * 2) * 32 + 5;
                    if (*(vu16 *) 0x27ffc40 != 2) {
                        func_02016468(0x14, (data_0217d3f4->mUnk_89c + t) << 5,
                                      data_0217d3f4->mUnk_894[i] + ((j * 32 + 5) << 5), 0x360);
                    }
                }
            }
        }
    }
}

static inline s32 func_02127a84_inline(u16 a, u16 b, u8 c, u8 d, u8 e, u8 f) {
    if (a >= c && a <= d && b >= e && b <= f) {
        return 1;
    }
    return 0;
}

static inline s32 func_02127a84_inline2(u32 v) {
    s32 r = 0;
    s32 s = 0;
    u16 c = data_02175674[v].mUnk_00;

    if (c == 0 && data_02175680[v].mUnk_00 < 5) {
        s = 1;
    }
    if (s == 0 && data_0217567c[v].mUnk_00 == 0 && c != 0) {
        r = 1;
    }
    return r;
}

void func_02127a84(void) {
    s32 hit;
    u16 x;
    u16 y;
    Unk02175628Index v;
    u16 w;

    v = UNK_02175628_INDEX_8;
    x = data_02175670[v].mUnk_00;
    y = data_02175672[v].mUnk_00;
    if (data_0217d3f4->mUnk_28 != 0) {
        data_0217d3f4->mUnk_08 = 0;
        data_0217d3f4->mUnk_28 = 0;
        return;
    }
    hit = -1;
    if (func_02127a84_inline2(v) != 0) {
        if (func_02127a84_inline(x, y, data_0215d0a4[0].mUnk_00, data_0215d0a4[0].mUnk_01, data_0215d0a4[0].mUnk_02,
                                 data_0215d0a4[0].mUnk_03) != 0) {
            hit = 0;
        }
        if (func_02127a84_inline(x, y, data_0215d0a4[1].mUnk_00, data_0215d0a4[1].mUnk_01, data_0215d0a4[1].mUnk_02,
                                 data_0215d0a4[1].mUnk_03) != 0) {
            hit = 1;
        }
    }
    w = data_02175628[v].mUnk_00;
    if ((u16) (w & 1) == 0 && hit == -1) {
        goto L;
    }
    if (hit == -1 || data_0217d3f4->mUnk_18 == hit) {
        func_02127d28();
    } else {
        data_0217d3f4->mUnk_18 = hit;
        func_02127d74();
    }
    data_0217d3f4->mUnk_08 = 2;
    if (data_0217d3f4->mUnk_8a4 != 0) {
        if (data_0217d3f4->mUnk_8a8[data_0217d3f4->mUnk_18] != -1) {
            func_02105ac0((u16) data_0217d3f4->mUnk_8a8[data_0217d3f4->mUnk_18]);
        }
    }
    return;
L:
    if ((u16) (w & 2) != 0) {
        data_0217d3f4->mUnk_20 = 1;
        data_0217d3f4->mUnk_0c = 0xb;
        data_0217d3f4->mUnk_08 = 2;
        if (data_0217d3f4->mUnk_8a4 != 0) {
            if (data_0217d3f4->mUnk_8b0 != -1) {
                func_02105ac0((u16) data_0217d3f4->mUnk_8b0);
            }
        }
        return;
    }
    if ((u16) (w & 0x40) != 0 && data_0217d3f4->mUnk_18 == 1) {
        data_0217d3f4->mUnk_18 = 0;
        func_02127d74();
        if (data_0217d3f4->mUnk_8a4 != 0) {
            func_02105ac0(0);
        }
        return;
    }
    if ((u16) (w & 0x80) != 0 && data_0217d3f4->mUnk_18 == 0) {
        data_0217d3f4->mUnk_18 = 1;
        func_02127d74();
        if (data_0217d3f4->mUnk_8a4 != 0) {
            func_02105ac0(0);
        }
    }
}
#pragma thumb off
