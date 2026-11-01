#include "Main/Unknown/code_02117418.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_021185ec.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02117814.h"
#include "Main/Unknown/code_021177a4.h"
#include "Main/Unknown/code_02117be0.h"
#include "Main/Unknown/code_02117d98.h"
#include "Main/Unknown/code_02117bf8.h"
#include "Main/Unknown/code_021177c0.h"
#include "Main/Unknown/code_0211784c.h"
#include "Main/Unknown/code_02118148.h"
#include "Main/Unknown/code_02117db0.h"
#include "Main/Unknown/unk_0215c000.h"
#include "00/code_02182fdc.h"
#include "code_02016468.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

#pragma thumb on

void func_0211775c(void) {
    s32 a;

    func_02118414();
    if (func_02127788() != 0) {
        func_02118038();
        if (*(vu16 *) 0x027ffc40 == 2) {
            a = func_02127794();
            switch (a) {
                case -1:
                case 0:
                    break;
                case 1:
                    func_0212ecc0(&data_0217d068, 0, 0xf);
                    break;
            }
        }
    }
}

void func_02117700(void) {
    s32 a;

    func_02118414();
    if (func_021277ac() != 0) {
        a = func_02127794();
        switch (a) {
            case -1:
            case 0:
                func_021181b8();
                break;
            case 1:
                data_0217d360->mUnk_88 = 3;
                func_02118024();
                if (*(vu16 *) 0x027ffc40 == 2) {
                    func_0211f378();
                }
                break;
        }
    }
}

void func_0211756c(void) {
    s16 a;
    s16 b;
    s16 c;
    u16 v;
    int i;
    int j;
    int k;

    data_0217d360->mUnk_38 = data_0217d360->mUnk_38 + 1;
    if (*(vu16 *) 0x027ffc40 != 2) {
        v = data_0217d360->mUnk_04->mUnk_06;
        a = func_020ae4c0(1, 0, 0xe0, data_0217d360->mUnk_38, 0xa);
        b = func_020ae4c0(1, 0, -192, data_0217d360->mUnk_38, 0xa);
        if (data_0217d360->mUnk_88 == 2 || data_0217d360->mUnk_88 == 3 || data_0217d360->mUnk_3c == 0) {
            data_0217d360->mUnk_40 = b;
            data_0217d360->mUnk_18[19].mUnk_06 = b;
            data_0217d360->mUnk_18[2].mUnk_06 = b;
            data_0217d360->mUnk_18[1].mUnk_06 = b;
            data_0217d360->mUnk_18[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                data_0217d360->mUnk_18[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mUnk_18[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mUnk_18[data_0215c7d0[i]].mUnk_06 = b;
                data_0217d360->mUnk_18[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        data_0217d360->mUnk_18[20].mUnk_06 = b;
        c = -a;
        data_0217d360->mUnk_1c[0].mUnk_04 = c;
        data_0217d360->mUnk_1c[1].mUnk_04 = a;
        data_0217d360->mUnk_1c[2].mUnk_04 = c;
        data_0217d360->mUnk_1c[3].mUnk_04 = a;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mUnk_1c[data_0215c9bc[i][j]].mUnk_04 = -a;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mUnk_1c[data_0215c9bc[i][j]].mUnk_04 = a;
            }
        }
    }
}

s32 func_02117418(void) {
    int i;
    int n;
    u16 *p;

    data_0217d360->mUnk_30 = data_0217d360->mUnk_34;
    switch (data_0217d360->mUnk_30) {
        case 0:
            func_02117d98();
            break;
        case 1:
            func_02117bf8();
            break;
        case 2:
            func_02117be0();
            break;
        case 3:
            func_021178b0();
            break;
        case 4:
            func_0211784c();
            break;
        case 5:
            func_02117830();
            break;
        case 6:
            func_02117814();
            break;
        case 7:
            func_021177c0();
            break;
        case 8:
            func_021177a4();
            break;
        case 9:
            func_0211775c();
            break;
        case 10:
            func_02117700();
            break;
        case 11:
            func_0211756c();
            break;
    }
    func_02118814();
    func_02118458();
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (data_0217d360->mUnk_7c != 0 && func_020d0ec4() != 0) {
            p = func_020d0e58();
            func_02016468(0xf, 0, func_020d0ea0(), 0xe0);
            func_02016468(4, 0x20, func_020d0e7c(), 0xdc0);
            for (i = 0; i < 11; i++) {
                n = (i + 8) * 0x20 + 0x16;
                func_02016468(8, n * 2, p + n, 0x14);
            }
            data_0217d360->mUnk_7c = 0;
        }
        func_02124c30(data_0217d360->mUnk_04, data_0217d360->mUnk_00, data_0217d360->mUnk_08, data_0217d360->mUnk_80,
                      data_0217d360->mUnk_18);
        func_02124c30(data_0217d360->mUnk_10, data_0217d360->mUnk_0c, 0, data_0217d360->mUnk_84,
                      data_0217d360->mUnk_1c);
    } else {
        func_0211f39c();
    }
    if (data_0217d360->mUnk_30 == 0xb && data_0217d360->mUnk_38 >= 0xa) {
        return data_0217d360->mUnk_88;
    }
    return 0;
}

#pragma thumb off
