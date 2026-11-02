#include "Main/Unknown/code_0212a910.h"

#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_020d1630.h"
#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/code_02124094.h"
#include "code_02142eac.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"
#include "code_0201ea30.h"
#include "Main/Unknown/code_0212abd0.h"

#pragma thumb on
void func_0212abd0(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d404;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
void func_0212aaa4(void) {
    s32 i;
    Unk020b4934 *c;
    Unk02021dc8 *d;
    Unk020b4a44 *e;
    void *a;
    Unk0201ea30 *b;
    Unk0217b4b0 *x;
    Unk0201ea30_08 *p;
    s32 j;
    x = func_020d1630();
    a = x->mUnk_00;
    b = x->mUnk_04;
    c = x->mUnk_08;
    d = x->mUnk_0c;
    e = x->mUnk_10;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < data_0215d168[i]; j++) {
            data_0217d404->mUnk_0bc[i][j] = (Unk0217d404_bc *) c->mUnk_14 + func_0212497c(data_0215d170[i][j], d, a);
        }
    }
    for (i = 0; i < 2; i++) {
        p = func_0201ea30(b, data_0215d164[i]);
        data_0217d404->mUnk_028[i].mUnk_00 = func_0201ebe8(p->mUnk_00_0, 0x10);
        data_0217d404->mUnk_028[i].mUnk_04 = func_0201eba0(p->mUnk_00_2, 0x10);
    }
    for (i = 0; i < 2; i++) {
        func_02016468(0x13, (0x400 - (i + 1) * 4) << 5, data_0217d404->mUnk_03c, 0x80);
    }
    func_02016468(0xe, 0x1a0, e->mUnk_0c + 0xd0, 0x20);
}

void func_0212a99c(void) {
    s32 n;
    s32 i;
    s32 v;
    BOOL r;
    n = 0;
    for (i = 0; i < 2; i++) {
        data_0217d404->mUnk_014[i] = -1;
        data_0217d404->mUnk_01c[i] = 0;
    }
    if (data_0217d404->mUnk_000[1] != 0) {
        data_0217d404->mUnk_014[0] = 1;
        data_0217d404->mUnk_01c[0] = func_021205e8();
        n = 1;
    }
    if (data_0217d404->mUnk_000[0] != 0) {
        data_0217d404->mUnk_014[n] = 0;
        v = 0;
        if (data_0217aa00->mUnk_0004 != 0) {
            v = func_021431d8();
        }
        data_0217d404->mUnk_01c[n] = v;
    } else if (data_0217d404->mUnk_000[4] != 0) {
        r = FALSE;
        if (!data_0217aa08->mUnk_00->mUnk_31_4) {
            if (func_021213f4() != 0) {
                r = TRUE;
            }
        }
        if (r != FALSE) {
            data_0217d404->mUnk_014[n] = 4;
        }
    }
    for (i = 0; i < 2; i++) {
        if (data_0217d404->mUnk_014[i] == -1) {
            func_02016468(0x13, (0x400 - (i + 1) * 4) << 5, data_0217d404->mUnk_03c, 0x80);
        } else {
            func_02016468(0x13, (0x400 - (i + 1) * 4) << 5,
                          data_0217d404->mUnk_0bc[data_0217d404->mUnk_014[i]][data_0217d404->mUnk_01c[i]], 0x80);
        }
    }
}

void func_0212a920(void) {
    s32 i;
    s32 v;
    data_0217d404->mUnk_024++;
    if (data_0217d404->mUnk_024 > 0x78) {
        data_0217d404->mUnk_024 = 0;
    }
    func_0212a99c();
    for (i = 0; i < 2; i++) {
        v = data_0217d404->mUnk_014[i];
        if (data_0217d404->mUnk_024 < 0x69 || (u32) v <= 1) {
            func_0214cffc(&data_0217d404->mUnk_10c[i],
                          &data_0217d404->mUnk_038->mUnk_00[data_0217d404->mUnk_038->mUnk_400], 6);
            data_0217d404->mUnk_038->mUnk_400++;
        }
    }
}
#pragma thumb off

#pragma thumb on
void func_0212a910(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_0217d404;
    value2 = (u32) * (const u32 *) ((value2) + 0u);
    value0 = (value0 << 2);
    *(u32 *) ((value2) + (value0)) = value1;
}
#pragma thumb off
