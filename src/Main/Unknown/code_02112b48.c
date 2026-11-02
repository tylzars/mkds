#include "Main/Unknown/code_02112b48.h"

#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_021113f0.h"
#include "Main/Unknown/code_0211130c.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02113790.h"
#include "Main/Unknown/code_0211398c.h"
#include "Main/Unknown/code_021139b4.h"
#include "Main/Unknown/code_02113f34.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "code_02148ca0.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02182fdc.h"
#include "code_0212df7c.h"
#include "registers.h"
#include "Main/Unknown/code_021137a8.h"
#include "Main/Unknown/code_02113f1c.h"
#include "Main/Unknown/code_021138e4.h"
#include "Main/Unknown/code_02113ef0.h"
#include "code_02016468.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02114504.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_021144b4.h"
#include "Main/Unknown/code_021144c0.h"
#include "01/code_021956dc.h"

#pragma thumb on

u16 func_02114584(u16 a) {
    Unk02116a4c w;

    func_021142d4((u8) a, &w);
    return w.mUnk_00 * 0x1a0 + w.mUnk_01 * 32 + w.mUnk_02;
}

void func_02114504(s32 a, u16 b) {
    s32 i;
    s32 j;
    s32 n;
    u16 p;
    s32 e;
    Unk0217d34c_04 t;
    u32 m;
    u16 v;
    Unk0217d34c_04 *q;

    p = 0;
    n = a + b;
    e = n - 1;
    for (i = a; i < e; i++) {
        m = 0;
        for (j = i; j < n; j++) {
            v = func_02114584(j);
            if (m < v) {
                m = v;
                p = j;
            }
        }
        for (j = p; j > i; j--) {
            q = data_0217d34c->mUnk_04 + j - 1;
            t = *q;
            *q = data_0217d34c->mUnk_04[j];
            data_0217d34c->mUnk_04[j] = t;
        }
    }
}

#pragma thumb off

#pragma thumb on

void func_021144c0(void *a) {
    int v1;
    void *v2;
    v1 = ((u32) func_02036bec(a, (u32) 0x10));
    *(int *) &data_0217d34c = v1;
    v2 = func_02036bec(a, (u32) 0x78);
    data_0217d34c->mUnk_04 = v2;
    v2 = func_0205eda0(a);
    data_0217d34c->mUnk_08 = v2;
    v2 = func_0204799c((const char *) &data_0216d3e4);
    data_0217d34c->mUnk_0c = v2;
}

#pragma thumb off

#pragma thumb on
void func_021144b4(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d34c;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on

void func_021143f4(void) {
    s32 i;
    u16 a;
    s32 b;
    s32 c;

    a = 0;
    data_0217d34c->mUnk_00 = 0;
    for (i = 0; i < 0x3c; i++) {
        if (func_02060b34(i)) {
            data_0217d34c->mUnk_00++;
            if (func_02060afc(i)) {
                a++;
            }
        }
    }
    if (data_0217d34c->mUnk_00 != 0) {
        b = 0;
        c = a;
        for (i = 0; i < 0x3c; i++) {
            if (func_02060b34(i)) {
                if (func_02060afc(i)) {
                    data_0217d34c->mUnk_04[b].mUnk_00 = (u8) i;
                    b++;
                } else {
                    data_0217d34c->mUnk_04[c].mUnk_00 = (u8) i;
                    c++;
                }
            }
        }
        func_02114504(0, a);
        func_02114504(a, data_0217d34c->mUnk_00 - a);
    }
}

u16 func_021143b4(void) {
    s32 i;
    u16 n;

    n = 0;
    if (data_0217d34c == 0) {
        for (i = 0; i < 0x3c; i++) {
            if (func_02060b34(i)) {
                n++;
            }
        }
        return n;
    }
    return data_0217d34c->mUnk_00;
}

s32 func_02114398(u16 a) {
    return func_02060afc(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_0211437c(u16 a) {
    return func_02060ac8(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_02114360(u16 a) {
    return func_02060a60(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_02114344(u16 a) {
    return func_020609f8(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_02114328(u16 a) {
    return func_02060a94(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_0211430c(u16 a) {
    return func_02060a2c(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_021142f0(u16 a) {
    return func_020609c4(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_021142d4(u16 a, void *b) {
    return func_02060950(data_0217d34c->mUnk_04[a].mUnk_00, b);
}

void func_02114298(u16 a, void *b, u32 c) {
    u8 t[0x14];

    func_020608fc(data_0217d34c->mUnk_04[a].mUnk_00, t);
    func_0214d168(b, 0, c);
    func_0214cffc(t, b, 0x14);
}

s32 func_0211427c(u16 a) {
    return func_02060880(data_0217d34c->mUnk_04[a].mUnk_00, 1);
}

s32 func_02114260(u16 a) {
    return func_02060880(data_0217d34c->mUnk_04[a].mUnk_00, 0);
}

void func_021141c8(u16 a, Unk021141c8 *b, void *c) {
    u8 d;

    func_0205ec14(data_0217d34c->mUnk_08, data_0217d34c->mUnk_04[a].mUnk_00);
    d = data_0217aa08->mUnk_28;
    do {
    } while (d == 0 ? (data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0) : 1);
    if (!func_0205eca4(data_0217d34c->mUnk_08, data_0217d34c->mUnk_04[a].mUnk_00, b) || b->mUnk_200 == 0) {
        b->mUnk_200 = 1;
        func_0214d0a8(data_0217d34c->mUnk_0c, b, 0x200);
    }
    func_020ac2fc(b, c, 0x20);
}

void func_02114174(u16 a) {
    u8 d;

    func_020607b0(data_0217d34c->mUnk_04[a].mUnk_00);
    d = data_0217aa08->mUnk_28;
    do {
    } while (d == 0 ? (data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0) : 1);
    func_021143f4();
}

s32 func_02114158(u16 a, void *b) {
    return func_02060468(data_0217d34c->mUnk_04[a].mUnk_00, b);
}

#pragma thumb off

#pragma thumb on

void func_02113f34(void) {
    void *v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int v6;
    int v7;
    int v8;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v8 = 0;
    v1 = func_0204799c((const char *) data_0216d20c);
    func_020b49bc(&data_0217d348->mUnk_00, v1);
    v1 = func_0204799c((const char *) data_0216d200);
    func_020b48b4(&data_0217d348->mUnk_04, v1);
    v1 = func_0204799c((const char *) data_0216d1f8);
    func_020b4a44((Unk020b4a44 **) (&v4), v1);
    v1 = func_0204799c((const char *) data_0216d1f4);
    data_0217d348->mUnk_08 = v1;
    v1 = func_0204799c((const char *) data_0216d22c);
    data_0217d348->mUnk_0c = v1;
    v1 = func_0204799c((const char *) data_0216d238);
    data_0217d348->mUnk_18 = v1;
    v1 = func_0204799c((const char *) data_0216d1fc);
    data_0217d348->mUnk_1c = v1;
    v1 = func_0204799c((const char *) data_0216d208);
    func_020b49bc(&data_0217d348->mUnk_28, v1);
    v1 = func_0204799c((const char *) data_0216d210);
    func_020b48b4(&data_0217d348->mUnk_2c, v1);
    v1 = func_0204799c((const char *) data_0216d218);
    func_020b4a44((Unk020b4a44 **) (&v8), v1);
    v1 = func_0204799c((const char *) data_0216d204);
    data_0217d348->mUnk_30 = v1;
    v1 = func_0204799c((const char *) data_0216d234);
    data_0217d348->mUnk_34 = v1;
    v1 = func_0204799c((const char *) data_0216d21c);
    data_0217d348->mUnk_38 = v1;
    v2 = ((u32) func_02077f00());
    v1 = func_0204799c((const char *) data_0216d220);
    func_020b4934((Unk020b4934 **) (&v5), v1);
    v1 = func_0204799c((const char *) data_0216d230);
    func_020b47d8((Unk020b47d8 **) (&v6), v1);
    v1 = func_0204799c((const char *) data_0216d228);
    func_020b47d8(&data_0217d348->mUnk_10, v1);
    v1 = func_0204799c((const char *) data_0216d214);
    func_020b47d8(&data_0217d348->mUnk_20, v1);
    v1 = func_0204799c((const char *) data_0216d224);
    func_020b4a44((Unk020b4a44 **) (&v7), v1);
    v3 = *(int *) (v4 + 0xc);
    func_02016468((u32) 0x13, (u32) 0, (void *) (data_0217d348->mUnk_00->mUnk_14),
                  (u32) (data_0217d348->mUnk_00->mUnk_10));
    func_02016468((u32) 0xe, (u32) 0, (void *) (*(u32 *) (v4 + 0xc)), (u32) (((u32) 0x000001a0u)));
    func_02016468((u32) 0xe, (u32) 0x1c0, (void *) (v3 + 0x1c0), (u32) 0x40);
    func_02016468((u32) 0x23, (u32) 0, (void *) (data_0217d348->mUnk_28->mUnk_14),
                  (u32) (data_0217d348->mUnk_28->mUnk_10));
    func_02016468((u32) 0x1e, (u32) 0, (void *) (*(u32 *) (v8 + 0xc)), (u32) (*(u32 *) (v8 + 8)));
    func_02016468((u32) 4, (u32) 0, (void *) (*(u32 *) (v5 + 0x14)), (u32) (*(u32 *) (v5 + 0x10)));
    func_02016468((u32) 8, (u32) 0, (void *) (v6 + 0xc), (u32) (*(u32 *) (v6 + 8)));
    func_02016468((u32) 0xf, (u32) 0, (void *) (*(u32 *) (v7 + 0xc)), (u32) 0x40);
    func_02016468((u32) 0xe, (u32) 0x40, (void *) (*(u32 *) (v2 + 0xc)), (u32) 0x20);
}

#pragma thumb off

#pragma thumb on

u16 func_02113f1c(void) {
    return data_0217d348->mUnk_6a * 5;
}

#pragma thumb off

#pragma thumb on

u32 func_02113ef0(int a) {
    int v1;
    int v2;
    v1 = func_02113f1c();
    v2 = func_021143b4();
    if (v2 > v1 + a) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_02113d84(void) {
    s32 i;
    u16 a;
    u16 b;

    b = data_0217d348->mUnk_30->mUnk_06;
    a = func_02113f1c();
    for (i = 0; i < 5; i++) {
        data_0217d348->mUnk_3c[data_0215c3e0[i]].mUnk_00 = 0;
        data_0217d348->mUnk_3c[data_0215c3ec[i]].mUnk_00 = 0;
        data_0217d348->mUnk_3c[data_0215c3f8[i]].mUnk_00 = 0;
        data_0217d348->mUnk_3c[data_0215c404[i]].mUnk_00 = 0;
        data_0217d348->mUnk_3c[b + data_0215c3bc[i]].mUnk_00 = 0;
    }
    for (i = 0; i < 5; i++) {
        if (func_02113ef0((s16) i)) {
            if (data_0217d348->mUnk_68 == i) {
                data_0217d348->mUnk_3c[data_0215c3ec[i]].mUnk_00 = 1;
                func_02124100(data_0215c3bc[i], 0xe, data_0217d348->mUnk_38, data_0217d348->mUnk_3c,
                              data_0217d348->mUnk_30);
            } else {
                data_0217d348->mUnk_3c[data_0215c3e0[i]].mUnk_00 = 1;
                func_02124100(data_0215c3bc[i], 0xf, data_0217d348->mUnk_38, data_0217d348->mUnk_3c,
                              data_0217d348->mUnk_30);
            }
            data_0217d348->mUnk_3c[data_0215c3f8[i]].mUnk_00 = !func_02114398(a + i);
            data_0217d348->mUnk_3c[data_0215c404[i]].mUnk_00 = func_02114398(a + i);
            data_0217d348->mUnk_3c[b + data_0215c3bc[i]].mUnk_00 = 1;
        }
    }
}

void func_02113a3c(void) {
    u16 buf[16];
    u32 v[3][3] = {0};
    u8 s[0x14];
    Unk02116a4c w;
    Unk0217d348 *d;
    s32 i;
    s32 j;
    s32 a;

    a = func_02113f1c();
    if (func_02114158(a + data_0217d348->mUnk_74, s)) {
        data_0217d348->mUnk_40 = 1;
        func_02016468(9, 0, &data_0217d348->mUnk_20->mUnk_0c, data_0217d348->mUnk_20->mUnk_08);
    } else {
        data_0217d348->mUnk_40 = 0;
        func_02016468(9, 0, &data_0217d348->mUnk_10->mUnk_0c, data_0217d348->mUnk_10->mUnk_08);
    }
    switch (data_0217d348->mUnk_40) {
        case 0:
            func_02114298(a + data_0217d348->mUnk_74, buf, 0x20);
            func_0212426c(0, 0, data_0217d348->mUnk_0c, buf, data_0217d348->mUnk_08, data_0217d348->mUnk_14);
            v[1][0] = func_0211437c(a + data_0217d348->mUnk_74);
            v[1][1] = func_02114360(a + data_0217d348->mUnk_74);
            v[1][2] = func_02114344(a + data_0217d348->mUnk_74);
            v[2][0] = func_02114328(a + data_0217d348->mUnk_74);
            v[2][1] = func_0211430c(a + data_0217d348->mUnk_74);
            v[2][2] = func_021142f0(a + data_0217d348->mUnk_74);
            for (i = 1; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (v[i][j] > 9999) {
                        v[i][j] = 9999;
                    }
                }
            }
            func_02124fac(v[1][0], buf);
            func_02124248(0, data_0215c410[1][0], data_0217d348->mUnk_0c, buf, data_0217d348->mUnk_08,
                          data_0217d348->mUnk_14, 6);
            func_02124fac(v[1][1], buf);
            func_02124248(0, data_0215c410[1][1], data_0217d348->mUnk_0c, buf, data_0217d348->mUnk_08,
                          data_0217d348->mUnk_14, 6);
            func_02124fac(v[1][2], buf);
            func_02124248(0, data_0215c410[1][2], data_0217d348->mUnk_0c, buf, data_0217d348->mUnk_08,
                          data_0217d348->mUnk_14, 6);
            func_02124fac(v[2][0], buf);
            func_02124248(0, data_0215c410[2][0], data_0217d348->mUnk_0c, buf, data_0217d348->mUnk_08,
                          data_0217d348->mUnk_14, 6);
            func_02124fac(v[2][1], buf);
            func_02124248(0, data_0215c410[2][1], data_0217d348->mUnk_0c, buf, data_0217d348->mUnk_08,
                          data_0217d348->mUnk_14, 6);
            func_02124fac(v[2][2], buf);
            func_02124248(0, data_0215c410[2][2], data_0217d348->mUnk_0c, buf, data_0217d348->mUnk_08,
                          data_0217d348->mUnk_14, 6);
            func_021142d4(a + data_0217d348->mUnk_74, &w);
            func_02116a4c(&w, buf);
            func_02124224(0, 0xc, data_0217d348->mUnk_0c, buf, data_0217d348->mUnk_08, data_0217d348->mUnk_14, 6);
            func_021141c8(a + data_0217d348->mUnk_74, data_0217d348->mUnk_78, data_0217d348->mUnk_7c);
            d = data_0217d348;
            func_02016468(0x13, func_0212497c(3, d->mUnk_04, d->mUnk_08) << 5, d->mUnk_7c, 0x200);
            break;
        case 1:
            func_02114298(a + data_0217d348->mUnk_74, buf, 0x20);
            func_0212426c(0, 0, data_0217d348->mUnk_1c, buf, data_0217d348->mUnk_18, data_0217d348->mUnk_24);
            for (i = 0; i < 12; i++) {
                func_02124fac(s[i] - 0x30, buf);
                func_0212426c(0, data_0215c478[i], data_0217d348->mUnk_1c, buf, data_0217d348->mUnk_18,
                              data_0217d348->mUnk_24);
            }
            func_021141c8(a + data_0217d348->mUnk_74, data_0217d348->mUnk_78, data_0217d348->mUnk_7c);
            d = data_0217d348;
            func_02016468(0x13, func_0212497c(1, d->mUnk_04, d->mUnk_18) << 5, d->mUnk_7c, 0x200);
            break;
    }
}

void func_021139b4(void) {
    s32 i;
    s32 a;
    s32 b;
    u8 buf[0x20];

    a = func_02113f1c();
    for (i = 0; i < 5; i++) {
        b = a + i;
        if (func_021143b4() > b) {
            func_02114298(b, buf, 0x20);
            func_0212426c(1, data_0215c3bc[i], data_0217d348->mUnk_38, buf, data_0217d348->mUnk_30,
                          data_0217d348->mUnk_3c);
        }
    }
    if (func_021143b4() <= a + data_0217d348->mUnk_68) {
        data_0217d348->mUnk_68 = func_021143b4() % 5 - 1;
        data_0217d348->mUnk_74 = data_0217d348->mUnk_68;
    }
    func_02113a3c();
}

#pragma thumb off

#pragma thumb on
u32 func_021139a0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d348;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 106u;
    value0 = (u32) * (const s16 *) ((value1) + (value0));
    value0 = (value0) + (1u);
    value1 = (value1) + 106u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_0211398c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d348;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 106u;
    value0 = (u32) * (const s16 *) ((value1) + (value0));
    value0 = (value0) - (1u);
    value1 = (value1) + 106u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_02113940(void) {
    int v1;
    int v2;
    v2 = (data_0217d348->mUnk_68 + 1) * 0x10000 >> 0x10;
    v1 = func_02113ef0(v2);
    if ((v1 == 0) || (5 <= v2)) {
        v2 = 0;
    }
    if (data_0217d348->mUnk_68 != v2) {
        func_0212ecc0((const void *) (((u32) ((u8 *) &data_0217d068))), (u32) 0, (u32) 0);
    }
    data_0217d348->mUnk_68 = (short) v2;
}

void func_021138e4(void) {
    int v1;
    u32 v2;
    int v3;
    int v4;
    v4 = (data_0217d348->mUnk_68 + -1) * 0x10000 >> 0x10;
    if (v4 < 0) {
        v4 = 4;
        v1 = func_02113ef0(4);
        if (v1 == 0) {
            v2 = func_021143b4();
            v3 = (int) (v2) % 5;
            v4 = (v3 + -1) * 0x10000 >> 0x10;
        }
    }
    if (data_0217d348->mUnk_68 != v4) {
        func_0212ecc0((const void *) &data_0217d068, (u32) 0, (u32) 0);
    }
    data_0217d348->mUnk_68 = (short) v4;
}

#pragma thumb off

#pragma thumb on

void func_021137f4(void) {
    s32 i;
    u16 a;

    a = func_02113f1c();
    data_0217d348->mUnk_3c[data_0215c3ac[0]].mUnk_04 = -func_020adc64(6 - data_0217d348->mUnk_80[0]);
    data_0217d348->mUnk_3c[data_0215c3ac[1]].mUnk_04 = func_020adc64(6 - data_0217d348->mUnk_80[1]);
    for (i = 0; i < 2; i++) {
        if (data_0217d348->mUnk_80[i] > 0) {
            data_0217d348->mUnk_80[i]--;
            data_0217d348->mUnk_3c[data_0215c3b0[i]].mUnk_00 = 0;
            data_0217d348->mUnk_3c[data_0215c3ac[i]].mUnk_00 = 1;
        } else {
            data_0217d348->mUnk_3c[data_0215c3b0[i]].mUnk_00 = 1;
            data_0217d348->mUnk_3c[data_0215c3ac[i]].mUnk_00 = 0;
        }
    }
    if (a == 0) {
        data_0217d348->mUnk_3c[data_0215c3b0[0]].mUnk_00 = 0;
    }
    if (a + 5 >= func_021143b4()) {
        data_0217d348->mUnk_3c[data_0215c3b0[1]].mUnk_00 = 0;
    }
}

void func_021137a8(s32 a) {
    s32 b;

    b = func_02113f1c();
    b += a;
    if (func_02114398(b)) {
        func_02114260(b);
        func_0212ecc0(&data_0217d068, 0, 0x25);
    } else {
        func_0211427c(b);
        func_0212ecc0(&data_0217d068, 0, 0x24);
    }
}

#pragma thumb off

#pragma thumb on

u32 func_02113790(void) {
    if (data_0217d348->mUnk_70 != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_021136f8(void) {
    u16 a;
    u16 b;
    s16 v;
    if (func_02113790() != 0) {
        if (data_0217d348->mUnk_70 == 7) {
            data_0217d348->mUnk_74 = data_0217d348->mUnk_68;
            func_02113a3c();
        } else {
            a = data_0217d348->mUnk_08->mUnk_06;
            b = data_0217d348->mUnk_18->mUnk_06;
            v = func_02116d10(7 - data_0217d348->mUnk_70, 0);
            data_0217d348->mUnk_5c = v;
            data_0217d348->mUnk_14[3].mUnk_06 = v;
            data_0217d348->mUnk_14[a].mUnk_06 = v;
            data_0217d348->mUnk_24[1].mUnk_06 = v;
            data_0217d348->mUnk_24[b].mUnk_06 = v;
        }
        data_0217d348->mUnk_70 = data_0217d348->mUnk_70 - 1;
    } else {
        if (data_0217d348->mUnk_68 != 5 && data_0217d348->mUnk_68 != data_0217d348->mUnk_74) {
            data_0217d348->mUnk_70 = 7;
        }
    }
}

void func_021134d4(void) {
    s32 i;
    u16 b;
    u16 x;
    s32 l;
    u16 a;
    s32 j;
    i = 0;
    data_0217d348->mUnk_50 = 0;
    data_0217d348->mUnk_54 = 0;
    data_0217d348->mUnk_58 = 0;
    data_0217d348->mUnk_5c = -192;
    data_0217d348->mUnk_60 = 0;
    data_0217d348->mUnk_64 = -192;
    a = data_0217d348->mUnk_08->mUnk_06;
    b = data_0217d348->mUnk_18->mUnk_06;
    x = data_0217d348->mUnk_30->mUnk_06;
    data_0217d348->mUnk_14[0].mUnk_06 = -192;
    data_0217d348->mUnk_14[1].mUnk_06 = -192;
    data_0217d348->mUnk_14[2].mUnk_06 = -192;
    data_0217d348->mUnk_14[3].mUnk_06 = -192;
    data_0217d348->mUnk_14[a].mUnk_06 = -192;
    data_0217d348->mUnk_14[a + 1].mUnk_06 = -192;
    data_0217d348->mUnk_14[a + 11].mUnk_06 = -192;
    data_0217d348->mUnk_14[a + 12].mUnk_06 = -192;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            data_0217d348->mUnk_14[a + data_0215c410[i][j]].mUnk_06 = -192;
        }
    }
    data_0217d348->mUnk_24[1].mUnk_06 = -192;
    data_0217d348->mUnk_24[0].mUnk_06 = -192;
    data_0217d348->mUnk_24[b].mUnk_06 = -192;
    data_0217d348->mUnk_24[b + 1].mUnk_06 = -192;
    data_0217d348->mUnk_24[b + 14].mUnk_06 = -192;
    for (j = 0; j < 12; j++) {
        data_0217d348->mUnk_24[b + data_0215c478[j]].mUnk_06 = -192;
    }
    data_0217d348->mUnk_3c[20].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[21].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[24].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[25].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[25].mUnk_00 = 0;
    data_0217d348->mUnk_3c[26].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[x + 5].mUnk_04 = 0x100;
    for (l = 0; l < 5; l++) {
        data_0217d348->mUnk_3c[data_0215c3e0[l]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3ec[l]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3f8[l]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c404[l]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[x + data_0215c3bc[l]].mUnk_04 = 0x100;
    }
    for (j = 0; j < 2; j++) {
        data_0217d348->mUnk_3c[data_0215c3ac[j]].mUnk_00 = 0;
    }
}

void func_021134b8(void) {
    data_0217d348->mUnk_50 = 1;
    data_0217d348->mUnk_54 = 0;
    func_02113a3c();
}

void func_0211349c(void) {
    data_0217d348->mUnk_50 = 2;
    data_0217d348->mUnk_54 = 0;
    func_021139b4();
}

void func_02113480(void) {
    data_0217d348->mUnk_50 = 3;
    data_0217d348->mUnk_54 = 0;
    func_02128374();
}

void func_0211346c(void) {
    data_0217d348->mUnk_50 = 4;
    data_0217d348->mUnk_54 = 0;
}

void func_02113458(void) {
    data_0217d348->mUnk_50 = 5;
    data_0217d348->mUnk_54 = 0;
}

void func_02113420(void) {
    data_0217d348->mUnk_50 = 6;
    data_0217d348->mUnk_54 = 0;
    switch (data_0217d348->mUnk_6c) {
        case 0:
            func_021139a0();
            break;
        case 1:
            func_0211398c();
            break;
    }
    func_021139b4();
}

void func_0211340c(void) {
    data_0217d348->mUnk_50 = 7;
    data_0217d348->mUnk_54 = 0;
}

void func_021132e4(void) {
    s32 i;
    u16 x;
    data_0217d348->mUnk_50 = 8;
    i = 0;
    data_0217d348->mUnk_54 = 0;
    x = data_0217d348->mUnk_30->mUnk_06;
    data_0217d348->mUnk_3c[20].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[21].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[24].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[25].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[25].mUnk_00 = 0;
    data_0217d348->mUnk_3c[26].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[x + 5].mUnk_04 = 0x100;
    for (i = 0; i < 5; i++) {
        data_0217d348->mUnk_3c[data_0215c3e0[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3ec[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3f8[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c404[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = 0x100;
    }
    for (i = 0; i < 2; i++) {
        data_0217d348->mUnk_3c[data_0215c3ac[i]].mUnk_00 = 0;
    }
    func_0205edf8();
}

void func_021132b4(void) {
    data_0217d348->mUnk_50 = 9;
    data_0217d348->mUnk_54 = 0;
    data_0217d348->mUnk_3c[25].mUnk_00 = 1;
    func_0212ecc0(&data_0217d068, 0, 4);
}

void func_02113298(void) {
    data_0217d348->mUnk_50 = 10;
    data_0217d348->mUnk_54 = 0;
    func_021282c8();
}

void func_02113174(void) {
    s32 i;
    u16 x;
    data_0217d348->mUnk_50 = 11;
    i = 0;
    data_0217d348->mUnk_54 = 0;
    x = data_0217d348->mUnk_30->mUnk_06;
    data_0217d348->mUnk_3c[20].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[21].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[24].mUnk_04 = -256;
    data_0217d348->mUnk_3c[25].mUnk_04 = -256;
    data_0217d348->mUnk_3c[26].mUnk_04 = -256;
    data_0217d348->mUnk_3c[x + 5].mUnk_04 = -256;
    for (i = 0; i < 5; i++) {
        data_0217d348->mUnk_3c[data_0215c3e0[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3ec[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3f8[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c404[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = 0x100;
    }
    for (i = 0; i < 2; i++) {
        data_0217d348->mUnk_3c[data_0215c3ac[i]].mUnk_00 = 0;
    }
    func_021139b4();
}

void func_02112bb4(void *a) {
    s32 r;
    s32 i;
    s32 j;
    u16 e;
    u16 x;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xc800;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0xcc00;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0x1018;
    data_0217d348 = func_02036bec(a, 0x94);
    data_0217d348->mUnk_48 = a;
    data_0217d348->mUnk_6a = func_02111418();
    data_0217d348->mUnk_68 = func_02111408();
    data_0217d348->mUnk_6c = 0;
    data_0217d348->mUnk_70 = 0;
    data_0217d348->mUnk_74 = data_0217d348->mUnk_68;
    data_0217d348->mUnk_40 = 0;
    data_0217d348->mUnk_88 = 0;
    data_0217d348->mUnk_8c = 0;
    for (i = 0; i < 2; i++) {
        data_0217d348->mUnk_80[i] = 0;
    }
    func_02077a28(a);
    func_02113f34();
    func_02124ed0(a, data_0217d348->mUnk_08, data_0217d348->mUnk_0c, &data_0217d348->mUnk_14);
    func_02124ed0(a, data_0217d348->mUnk_18, data_0217d348->mUnk_1c, &data_0217d348->mUnk_24);
    func_02124ed0(a, data_0217d348->mUnk_30, data_0217d348->mUnk_38, &data_0217d348->mUnk_3c);
    data_0217d348->mUnk_44 = func_0204799c("record.bmg");
    r = 0x8000;
    r -= func_021243ac(a, 0, data_0217d348->mUnk_0c, 0x8c, 0x10, 0, data_0217d348->mUnk_04, data_0217d348->mUnk_08,
                       data_0217d348->mUnk_14, r);
    r -= func_021243ac(a, 1, data_0217d348->mUnk_0c, 0xaa, 0xe, 1, data_0217d348->mUnk_04, data_0217d348->mUnk_08,
                       data_0217d348->mUnk_14, r);
    func_0212426c(0, 1, data_0217d348->mUnk_0c, func_020b3f7c(data_0217d348->mUnk_44, 0), data_0217d348->mUnk_08,
                  data_0217d348->mUnk_14);
    r -= func_021243ac(a, 0xb, data_0217d348->mUnk_0c, 0x96, 0xe, 2, data_0217d348->mUnk_04, data_0217d348->mUnk_08,
                       data_0217d348->mUnk_14, r);
    func_0212426c(0, 0xb, data_0217d348->mUnk_0c, func_020b3f7c(data_0217d348->mUnk_44, 1), data_0217d348->mUnk_08,
                  data_0217d348->mUnk_14);
    r -= func_021243ac(a, 0xc, data_0217d348->mUnk_0c, 0x46, 0x10, 3, data_0217d348->mUnk_04, data_0217d348->mUnk_08,
                       data_0217d348->mUnk_14, r);
    e = 4;
    x = data_0217d348->mUnk_08->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            r -= func_021243ac(a, data_0215c410[i][j], data_0217d348->mUnk_0c, data_0215c424[i][j], data_0215c438[i][j],
                               e, data_0217d348->mUnk_04, data_0217d348->mUnk_08, data_0217d348->mUnk_14, r);
            e = x + data_0215c410[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        func_0212426c(0, data_0215c410[0][i], data_0217d348->mUnk_0c,
                      func_020b3f7c(data_0217d348->mUnk_44, data_0215c3b4[i]), data_0217d348->mUnk_08,
                      data_0217d348->mUnk_14);
    }
    r -= func_021243ac(a, 0, data_0217d348->mUnk_1c, 0x8c, 0x10, 0, data_0217d348->mUnk_04, data_0217d348->mUnk_18,
                       data_0217d348->mUnk_24, r);
    r -= func_021243ac(a, 1, data_0217d348->mUnk_1c, 0x70, 0x10, 1, data_0217d348->mUnk_04, data_0217d348->mUnk_18,
                       data_0217d348->mUnk_24, r);
    func_0212426c(0, 1, data_0217d348->mUnk_1c, func_020b3f7c(data_0217d348->mUnk_44, 0xb), data_0217d348->mUnk_18,
                  data_0217d348->mUnk_24);
    r -= func_021243ac(a, 0xe, data_0217d348->mUnk_1c, 0xe0, 0x38, 2, data_0217d348->mUnk_04, data_0217d348->mUnk_18,
                       data_0217d348->mUnk_24, r);
    func_0212426c(0, 0xe, data_0217d348->mUnk_1c, func_020b3f7c(data_0217d348->mUnk_44, 0xc), data_0217d348->mUnk_18,
                  data_0217d348->mUnk_24);
    for (i = 0; i < 12; i++) {
        r -= func_021243ac(a, data_0215c478[i], data_0217d348->mUnk_1c, data_0215c490[i], data_0215c460[i], i + 3,
                           data_0217d348->mUnk_04, data_0217d348->mUnk_18, data_0217d348->mUnk_24, r);
    }
    r = func_02148ca0();
    for (i = 0; i < 5; i++) {
        r -= func_021243ac(a, data_0215c3bc[i], data_0217d348->mUnk_38, data_0215c3c8[i], data_0215c3d4[i],
                           data_0215c3ec[i], data_0217d348->mUnk_2c, data_0217d348->mUnk_30, data_0217d348->mUnk_3c, r);
    }
    func_021243ac(a, 5, data_0217d348->mUnk_38, 0x98, 0x10, 0x19, data_0217d348->mUnk_2c, data_0217d348->mUnk_30,
                  data_0217d348->mUnk_3c, r);
    func_0212426c(1, 5, data_0217d348->mUnk_38, func_020b3f7c(data_0217d348->mUnk_44, 3), data_0217d348->mUnk_30,
                  data_0217d348->mUnk_3c);
    for (i = 0; i < 5; i++) {
        func_02124a98(data_0215c3e0[i], 0, data_0217d348->mUnk_2c, data_0217d348->mUnk_30);
        func_02124a98(data_0215c3ec[i], 0, data_0217d348->mUnk_2c, data_0217d348->mUnk_30);
        func_02124140(data_0215c3bc[i], 0, data_0217d348->mUnk_38, data_0217d348->mUnk_3c, data_0217d348->mUnk_30);
    }
    func_02124a98(0x18, 0, data_0217d348->mUnk_2c, data_0217d348->mUnk_30);
    func_02124a98(0x19, 0, data_0217d348->mUnk_2c, data_0217d348->mUnk_30);
    func_02124140(5, 0, data_0217d348->mUnk_38, data_0217d348->mUnk_3c, data_0217d348->mUnk_30);
    data_0217d348->mUnk_78 = func_02036bec(a, 0x201);
    data_0217d348->mUnk_7c = func_02036bec(a, 0x200);
    if (func_0211147c() == 4) {
        if (func_021143b4() != 0) {
            data_0217d348->mUnk_4c = 11;
            func_02113174();
        } else {
            data_0217d348->mUnk_4c = 8;
            func_021132e4();
            if (func_0211146c() == 12) {
                data_0217d348->mUnk_90 = 6;
            } else {
                data_0217d348->mUnk_90 = 0;
            }
        }
    } else {
        data_0217d348->mUnk_4c = 0;
        func_021134d4();
        func_020ae6d4(func_02111318(), func_0211130c());
    }
    data_0217d348->mUnk_3c[24].mUnk_00 = 0;
    data_0217d348->mUnk_3c[25].mUnk_00 = 0;
}

void func_02112b48(void) {
    u32 v;
    if (data_0217d348->mUnk_90 == 4) {
        func_021113fc(data_0217d348->mUnk_6a);
        func_021113f0(data_0217d348->mUnk_68);
    } else {
        func_021113fc(0);
        func_021113f0(0);
        v = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((v & ~0x13) << 8);
    }
    data_0217d348 = 0;
}

#pragma thumb off
