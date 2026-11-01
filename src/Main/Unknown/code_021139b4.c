#include "Main/Unknown/code_021139b4.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02113ef0.h"
#include "Main/Unknown/code_02113f1c.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02182fdc.h"
#include "code_02016468.h"
#include "code_0212df7c.h"

#pragma thumb on

// non-matching: second loop increments in a different order: the original adds 2 to the pointers for data_0215c3ec,
// data_0215c3bc and data_0215c3e0, then increments the stack variable a, then the pointers for data_0215c3f8 and
// data_0215c404; the compiled code increments a first
void func_02113d84(void) {
    s32 i;
    s32 a;
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
            data_0217d348->mUnk_3c[data_0215c3f8[i]].mUnk_00 = !func_02114398(a);
            data_0217d348->mUnk_3c[data_0215c404[i]].mUnk_00 = func_02114398(a);
            data_0217d348->mUnk_3c[b + data_0215c3bc[i]].mUnk_00 = 1;
        }
        a++;
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
