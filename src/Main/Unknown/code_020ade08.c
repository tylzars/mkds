#include "Main/Unknown/code_020ade08.h"

#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/code_020ad8e0.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ae0c8.h"
#include "Main/Unknown/code_020ae0e4.h"
#include "Main/Unknown/code_020ae0f8.h"
#include "Main/Unknown/code_020ae178.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/code_0212b09c.h"
#include "code_0200eddc.h"
#include "code_02023374.h"
#include "code_0213c9f8.h"
#include "code_0213ecf8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae1f4.h"
#include "Main/Unknown/code_020ae214.h"
#include "Main/Unknown/code_020ae21c.h"
#include "Main/Unknown/code_020ae23c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0203b680.h"
#include "Main/Unknown/code_0203b69c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_020ae3d8.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0215d000.h"

#pragma optimize_for_size on

u32 data_02168024[] = {20, 22, 31, 18, 27, 28, 33, 24, 30, 17, 25, 19, 34, 26, 32, 29, 10, 11, 13,
                       14, 35, 16, 12, 9,  15, 36, 37, 38, 39, 23, 40, 1,  3,  4,  5,  6,  7,  8,
                       2,  21, 42, 43, 44, 45, 46, 47, 41, 48, 49, 50, 51, 52, 53, 54, 0};

#pragma thumb on

u16 func_020ae5c4(void *a) {
    u16 *p;
    u16 v;

    p = (u16 *) ((u8 *) a + 0x402);
    v = *p;
    *p = v + 1;
    return v;
}

s32 func_020ae584(s32 a) {
    s32 v1[15] = {4, 8, 10, 13, 12, 12, 12, 4, -4, -8, -12, -16, -16, -24, -40};

    if (a < 0) {
        return 0;
    }
    if (a >= 15) {
        return -40;
    }
    return v1[a];
}

#pragma thumb off

s16 func_020ae564(s32 a) {
    return gPairsByAngle[(a >> 4) * 2 + 1];
}

s32 func_020ae554(s32 a, s32 b) {
    return (s32) (((s64) a * b) >> 12);
}

s32 func_020ae54c(s32 a) {
    return a >> 12;
}

#pragma thumb on

s16 func_020ae4c0(s32 a, s16 b, s16 c, s32 d, s32 e) {
    s32 t;
    s32 v1;
    float f;

    if (d <= 0) {
        return b;
    }
    if (d >= e) {
        return c;
    }
    switch (a) {
        case 0:
            return b + d * (c - b) / e;
        case 1:
            t = func_020ae564((d << 15) / e);
            v1 = c - b;
            if (v1 > 0) {
                f = 0.5f + (float) (v1 << 12);
            } else {
                f = (float) (v1 << 12) - 0.5f;
            }
            return b + func_020ae54c(func_020ae554((s32) f, 0x1000 - t)) / 2;
    }
}

s16 func_020ae488(s32 a) {
    if (a < 0) {
        return 0;
    }
    if (a < 3) {
        return a * -3;
    }
    if (a < 7) {
        return -9;
    }
    if (a < 10) {
        return (a - 7) * 3 - 9;
    }
    return 0;
}

#pragma thumb off

u16 func_020ae474(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}

u16 func_020ae458(u32 a, u32 b) {
    return func_020ae474(&data_02175628[a], b);
}

u16 func_020ae444(Unk02175628 *a, u32 b) {
    return a->mRepeatBits & b;
}

u16 func_020ae428(u32 a, u32 b) {
    return func_020ae444(&data_02175628[a], b);
}

#pragma thumb on

u16 func_020ae408(u32 a, u32 b) {
    int v1;
    int v2;
    v1 = func_020ae458(a, b);
    v2 = func_020ae428(a, b);
    return v1 | v2;
}

#pragma thumb off

u32 func_020ae3f4(void) {
    return ((u32) data_021759d0->mUnk_20);
}

u32 func_020ae3d8(void) {
    return ((u32) &data_0217aa00->mUnk_1ee8);
}

#pragma thumb on

u32 func_020ae3b4(u32 a) {
    int v1;
    u32 v2;
    v1 = func_020ae3f4();
    if (v1 == 0) {
        v2 = (u32) func_0204aa60();
    } else {
        v2 = func_020ae3d8();
    }
    return func_02046524((Unk020f41c4_B *) v2, a);
}

#pragma thumb off

#pragma thumb on

u32 func_020ae3a4(s32 a, s32 b) {
    return data_02168024[a * 4 + b];
}

void FindMissionTableCell(u32 value, u8 *outRow, u8 *outColumn) {
    u32 table;
    s32 rowCount;
    s32 columnCount;
    u8 row;
    u8 column;

    table = (u32) func_02047a28("/missionTable.mtbl");
    rowCount = func_0203b6a4(table);
    columnCount = func_0203b69c(table);
    for (row = 1; row <= rowCount; row++) {
        for (column = 1; column <= columnCount; column++) {
            if (value == func_0203b680(table, row, column)) {
                *outRow = row;
                *outColumn = column;
            }
        }
    }
}

#pragma thumb off

u32 func_020ae338(Unk02175628_48 *p0) {
    return p0->mHasPair;
}

u32 func_020ae308(Unk02175628_48 *a) {
    if (func_020ae338(a) == 0 && a->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

u32 func_020ae2e4(Unk02175628_48 *a) {
    if (a->mPrevHasPair == 0 && a->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_020ae2b0(Unk02175628_48 *a) {
    if (func_020ae308(a) == 0 && func_020ae2e4(a) != 0) {
        return 1;
    }
    return 0;
}

u32 func_020ae290(u32 a) {
    return func_020ae2b0((Unk02175628_48 *) &data_02175628[a].mUnk_48);
}

#pragma thumb on

u32 func_020ae244(u32 a, Unk020ae244 b) {
    u32 x;
    u32 y;

    if (func_020ae290(a) != 0) {
        x = func_020ae21c(a);
        y = func_020ae1f4(a);
        if (b.mUnk_00 <= x && x <= b.mUnk_04 && b.mUnk_02 <= y && y <= b.mUnk_06) {
            return 1;
        }
    }
    return 0;
}

#pragma thumb off

u32 func_020ae23c(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 0));
}

u32 func_020ae21c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020ae23c;
    value0 = (value1) + (0x48u);
    value0 = (u32) func_020ae23c(value0);
    return value0;
}

u32 func_020ae214(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 2));
}

u32 func_020ae1f4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020ae214;
    value0 = (value1) + (0x48u);
    value0 = (u32) func_020ae214(value0);
    return value0;
}

#pragma thumb on

u32 func_020ae1d0(u32 a) {
    return (u8) (a >> 24) + (((u8) (a >> 16) << 8) + (((u8) a << 24) + ((u8) (a >> 8) << 16)));
}

void *func_020ae178(u32 a, u32 b) {
    u32 v[13] = {20, 25, 24, 27, 22, 26, 23, 21, 29, 28, 30, 31, 32};
    u32 t;

    if (b != 0 && a == 1) {
        t = 0x21;
    } else if (b != 0 && a == 8) {
        t = 0x22;
    } else {
        t = v[a];
    }
    return GetBmgEntry(func_020b47cc("common.bmg"), t);
}

#pragma thumb off

u32 func_020ae15c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (112));
    return value0;
}

u32 func_020ae114(u32 a) {
    if (func_020ae15c(a) == 0 || func_020ae15c(a) == 2 || func_020ae15c(a) == 3) {
        return 1;
    }
    return 0;
}

u32 func_020ae0f8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (136));
    return value0;
}

u32 func_020ae0e4(void) {
    return ((u32) data_021759c0->mMode);
}

u32 func_020ae0c8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (104));
    return value0;
}

int func_020ae0ac(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_021759c0;
    value1 = 0x30u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const s8 *) ((value1) + (134));
    return value0;
}

#pragma thumb on

void func_020adff0(u32 a, u16 *b, u32 c) {
    u16 v[2];
    u16 w[10];
    u16 x[12];
    u16 i;
    u32 n;
    u16 *p;

    for (i = 0; i < 11; i++) {
        b[i] = 0;
    }
    if (func_020ae114(a) != 0) {
        p = (u16 *) func_020ae0f8(a);
        if (p == NULL) {
            return;
        }
        if (c != 0) {
            n = 10;
        } else {
            n = func_020adc7c(p, &x[1]);
        }
    } else {
        if (func_020ae0e4() == 0 || func_020ae0e4() == 4) {
            p = (u16 *) func_020ae178(func_020ae0c8(a), c);
            n = 20;
        } else {
            wcsncpy(w, GetBmgEntry(func_020b47cc("common.bmg"), 0x72), 9);
            swprintf(v, 2, L"%d", func_020ae0ac(a));
            wcsncat(w, v, 1);
            p = w;
            n = 10;
        }
    }
    if (p != NULL) {
        wcsncpy(b, p, n);
    }
}

#pragma thumb off

void func_020adfd8(Unk02180728 *a, void *b, void *c, s32 d, s32 e) {
    a->mUnk_00 = b;
    a->mUnk_04 = c;
    a->mUnk_08 = d;
    a->mUnk_0c = e;
}

void func_020adfb0(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f) {
    func_02024340(a, b, c, d, e, f);
}

#pragma thumb on

void func_020adf00(u32 a) {
    Unk02023374 o;
    Unk02180728 q;
    u16 r[22];
    void *t;
    u16 *s;
    s32 i;
    s32 j;

    t = func_020b403c(0);
    s = func_0212b090();
    func_0212b09c();
    for (i = 0; i < 0x100; i++) {
        s[i] = 0;
    }
    func_02023408(&o, s, 8, 2, 4);
    func_020adfd8(&q, &o, t, 2, 0);
    func_020adff0(a, r, 0);
    for (j = -1; j < 2; j++) {
        for (i = -1; i < 2; i++) {
            func_020adfb0(&q, j + 0x20, i + 8, 2, 0x412, r);
        }
    }
    func_020adfb0(&q, 0x20, 8, 1, 0x412, r);
    func_0200ee74(func_0212b090(), 0x200);
}

void func_020adec0(u16 *a, s32 b, s32 c, s32 d) {
    u16 t;
    s32 o;
    s32 s;

    o = (b + c * 64) / 8 * 2;
    t = a[(b + c * 64) / 8];
    s = b % 8 * 2;
    t &= ~(3 << s);
    a[(b + c * 64) / 8] = t | (d << s);
}

void func_020ade08(const u16 *a, u16 *b, s32 c, s32 d, Unk020ade08_f *e) {
    s32 i;
    s32 j;
    s32 k;
    s32 p;
    s32 q;
    s32 u;
    s32 w;
    u16 v;

    for (i = 0; i < 16; i++) {
        p = i / 8;
        q = i % 8;
        for (j = 0; j < 16; j++) {
            u = j / 2;
            w = j % 2;
            v = a[i * 16 + j];
            for (k = 0; k < 4; k++) {
                switch ((u8) ((v >> (k * 4)) % 16)) {
                    case 0:
                        break;
                    case 1:
                        e(b, q * 8 + w * 4 + k, p * 8 + u, c);
                        break;
                    case 2:
                        e(b, q * 8 + w * 4 + k, p * 8 + u, d);
                        break;
                }
            }
        }
    }
}

#pragma thumb off
