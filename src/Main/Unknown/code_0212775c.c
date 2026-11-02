#include "Main/Unknown/code_0212775c.h"

#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_02127a84.h"
#include "Main/Unknown/code_02127a38.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "code_0214a390.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_0212802c.h"
#include "Main/Unknown/code_02128058.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"

#pragma thumb on
s32 func_02128058(void *a, s32 b, s32 c) {
    s32 i;
    s32 r;
    Unk0217d3f0_2098 *q;
    Unk0217d3f0_2178 *e;
    u32 t;
    data_0217d3f4 = func_02036bec(a, 0x8b4);
    if (*(vu16 *) 0x27ffc40 != 2) {
        func_0212802c();
        c = func_02127f14(c);
        data_0217d3f4->mUnk_8a4 = 1;
    } else {
        data_0217d3f4->mUnk_8a4 = 0;
        t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
        t &= ~1;
        *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (t << 8);
    }
    for (i = 0; i < 2; i++) {
        data_0217d3f4->mUnk_894[i] = func_02036bec(a, 0x800);
        func_02023408(&data_0217d3f4->mUnk_834[i], data_0217d3f4->mUnk_894[i], 0x20, 2, 4);
        q = &data_0217d3f4->mUnk_834[i];
        q->mUnk_18(q, 0);
        r = func_020b4acc();
        e = &data_0217d3f4->mUnk_874[i];
        e->mUnk_00 = &data_0217d3f4->mUnk_834[i];
        e->mUnk_04 = b;
        e->mUnk_08 = r;
        e->mUnk_0c = 0;
    }
    func_021281b4();
    data_0217d3f4->mUnk_00 = 1;
    data_0217d3f4->mUnk_04 = 0;
    data_0217d3f4->mUnk_08 = 0;
    data_0217d3f4->mUnk_0c = 0;
    data_0217d3f4->mUnk_10 = 0;
    data_0217d3f4->mUnk_14 = 1;
    data_0217d3f4->mUnk_24 = 0;
    data_0217d3f4->mUnk_28 = 0;
    data_0217d3f4->mUnk_1c = 0;
    data_0217d3f4->mUnk_20 = 0;
    data_0217d3f4->mUnk_8a8[0] = 7;
    data_0217d3f4->mUnk_8a8[1] = 0x10;
    data_0217d3f4->mUnk_8b0 = 0x10;
    return c;
}
#pragma thumb off

#pragma thumb on
void func_0212804c(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d3f4;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
u32 func_0212802c(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0x4001008u;
    value1 = (u32) * (const u16 *) ((value2) + 0u);
    value0 = 3u;
    value1 = (value1) & ~(value0);
    *(u16 *) ((value2) + 0u) = (u16) value1;
    value1 = (u32) * (const u16 *) ((value2) + 0u);
    value0 = 67u;
    value1 = (value1) & (value0);
    value0 = 0xb00u;
    value1 = (value1) | (value0);
    *(u16 *) ((value2) + 0u) = (u16) value1;
    return value0;
}
#pragma thumb off

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

#pragma thumb on

void func_02127a38(void) {
    int *v1;
    int v2;
    v1 = (int *) &data_0217d3f4;
    v2 = *(int *) &data_0217d3f4;
    if (*(int *) (0x28 + v2) != 0) {
        *(u32 *) (v2 + 8) = 0;
        *(u32 *) (*v1 + 0x28) = 0;
        return;
    }
    *(int *) (v2 + 0xc) = *(int *) (v2 + 0xc) + 1;
    v2 = *(int *) (*v1 + 0xc);
    if (15 <= v2) {
        *(u32 *) (*v1 + 0x1c) = 1;
        *(u32 *) (*v1 + 0xc) = 0xf;
        return;
    }
    if (5 <= v2) {
        func_02127d74();
    }
}

#pragma thumb off

#pragma thumb on

void func_021279a0(void) {
    if (data_0217d3f4->mUnk_00 != 0) {
        data_0217d3f4->mUnk_04 = data_0217d3f4->mUnk_08;
        switch (data_0217d3f4->mUnk_04) {
            case 0:
                func_02127c78();
                break;
            case 1:
                func_02127a84();
                break;
            case 2:
                func_02127a38();
                break;
        }
        data_0217d3f4->mUnk_10++;
        if ((data_0217d3f4->mUnk_14 != 0 && data_0217d3f4->mUnk_10 > 0x1e) ||
            (data_0217d3f4->mUnk_14 == 0 && data_0217d3f4->mUnk_10 > 0x14)) {
            data_0217d3f4->mUnk_14 = data_0217d3f4->mUnk_14 == 0;
            data_0217d3f4->mUnk_10 = 0;
            func_02127e30();
            if (*(vu16 *) 0x27ffc40 != 2) {
                func_02016468(0x18, 0, data_0217d3f4->mUnk_2c, 0x800);
            }
        }
    }
}

void func_021278f4(void) {
    u32 a;

    if (data_0217d3f4->mUnk_00 != 0) {
        *(vu32 *) 0x4001010 = 0;
        if (data_0217d3f4->mUnk_04 == 0 || data_0217d3f4->mUnk_8a4 == 0) {
            func_0214a390((u16 *) 0x4001050, 0x1e, 0x1f, 6, 10, 0);
            a = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
            *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((a & ~1) << 8);
        } else {
            func_0214a390((u16 *) 0x4001050, 0x1e, 0x1f, 6, 10, -10);
            a = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
            *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((a | 1) << 8);
        }
    }
}

void func_021278c8(void) {
    if ((data_0217d3f4->mUnk_04 == 0 && data_0217d3f4->mUnk_24 != 0) || data_0217d3f4->mUnk_04 == 1) {
        data_0217d3f4->mUnk_28 = 1;
    } else {
        data_0217d3f4->mUnk_28 = 0;
    }
    data_0217d3f4->mUnk_24 = 1;
}

void func_021277f8(void *param_1, void *param_2, s32 param_3) {
    Unk0217d3f0_2098 *p;

    p = &data_0217d3f4->mUnk_834[0];
    p->mUnk_18(p, 5);
    p = &data_0217d3f4->mUnk_834[1];
    p->mUnk_18(p, 5);
    func_0212583c(&data_0217d3f4->mUnk_874[0], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, param_1);
    func_0212583c(&data_0217d3f4->mUnk_874[1], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, param_2);
    func_021281b4();
    data_0217d3f4->mUnk_8a0 = 1;
    func_021278c8();
    if (param_3 == 0) {
        data_0217d3f4->mUnk_18 = 0;
    } else {
        data_0217d3f4->mUnk_18 = 1;
    }
    func_02127d74();
    data_0217d3f4->mUnk_1c = 0;
    data_0217d3f4->mUnk_10 = 0;
    data_0217d3f4->mUnk_14 = 1;
}

void func_021277e4(void) {
    data_0217d3f4->mUnk_24 = 0;
    data_0217d3f4->mUnk_28 = 1;
}

u32 func_021277c8(void) {
    u32 r;

    r = 0;
    if (data_0217d3f4->mUnk_04 == 1 && data_0217d3f4->mUnk_28 == 0) {
        r = 1;
    }
    return r;
}

s32 func_021277ac(void) {
    s32 r;

    r = 0;
    if (data_0217d3f4->mUnk_04 == 0 && data_0217d3f4->mUnk_24 == 0) {
        r = 1;
    }
    return r;
}
#pragma thumb off

#pragma thumb on

s32 func_02127794(void) {
    if ((int) data_0217d3f4->mUnk_20 != 0) {
        return 0xffffffff;
    }
    return data_0217d3f4->mUnk_18;
}

u32 func_02127788(void) {
    return data_0217d3f4->mUnk_1c;
}

void func_0212775c(int param_1, u32 param_2) {
    if (param_1 == -1) {
        data_0217d3f4->mUnk_8b0 = param_2;
        return;
    }
    data_0217d3f4->mUnk_8a8[param_1] = param_2;
}

#pragma thumb off
