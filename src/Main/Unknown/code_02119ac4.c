#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_02119ac4.h"

#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_02119dfc.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

#pragma thumb on
void func_02119d78(void) {
    s32 w;
    s16 r;

    if (func_02119dfc() != 0) {
        if (data_0217d364->mUnk_58 == 7) {
            data_0217d364->mUnk_5c = data_0217d364->mUnk_50;
            func_02119e88();
        } else if (*(vu16 *) 0x027ffc40 != 2) {
            w = data_0217d364->mUnk_04->mUnk_06;
            r = func_02116d10(7 - data_0217d364->mUnk_58, 1);
            data_0217d364->mUnk_1c[w].mUnk_06 = r;
            data_0217d364->mUnk_1c[w + 1].mUnk_06 = r;
        }
        data_0217d364->mUnk_58--;
    } else if (data_0217d364->mUnk_50 != data_0217d364->mUnk_5c) {
        data_0217d364->mUnk_58 = 7;
    }
}

void func_02119c20(void) {
    s16 v;
    s32 w;
    s32 i;
    s32 u;

    data_0217d364->mUnk_38 = 0;
    data_0217d364->mUnk_3c = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (func_020cccb4() != 0x1a) {
            w = data_0217d364->mUnk_04->mUnk_06;
            data_0217d364->mUnk_44 = -0xc0;
            data_0217d364->mUnk_1c[0].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[2].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[1].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[4].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[3].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[5].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w + 1].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w + 2].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w + 3].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w + 4].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w + 5].mUnk_06 = -0xc0;
        }
        if (func_020cccb4() != 0x1a) {
            v = -0x20;
        } else {
            v = -0xe0;
        }
        u = data_0217d364->mUnk_10->mUnk_06;
        data_0217d364->mUnk_48 = v;
        data_0217d364->mUnk_20[0x14].mUnk_06 = v;
        data_0217d364->mUnk_20[0x13].mUnk_06 = v;
        data_0217d364->mUnk_20[2].mUnk_06 = v;
        data_0217d364->mUnk_20[1].mUnk_06 = v;
        data_0217d364->mUnk_20[0].mUnk_06 = v;
        for (i = 0; i < 8; i++) {
            data_0217d364->mUnk_20[data_0215cacc[i]].mUnk_06 = v;
        }
        for (i = 0; i < 4; i++) {
            data_0217d364->mUnk_20[data_0215caa4[i]].mUnk_06 = v;
            data_0217d364->mUnk_20[u + data_0215cab4[i]].mUnk_06 = v;
        }
    }
}

void func_02119c0c(void) {
    data_0217d364->mUnk_38 = 1;
    data_0217d364->mUnk_3c = 0;
}

void func_02119bf0(void) {
    data_0217d364->mUnk_38 = 2;
    data_0217d364->mUnk_3c = 0;
    func_02128374();
}

void func_02119bdc(void) {
    data_0217d364->mUnk_38 = 3;
    data_0217d364->mUnk_3c = 0;
}

void func_02119ba8(void) {
    data_0217d364->mUnk_38 = 4;
    data_0217d364->mUnk_3c = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0212ecc0(&data_0217d068, 0, 5);
    }
}

void func_02119ac4(void) {
    u16 buf[0x100];
    Unk0217d364 *d;

    data_0217d364->mUnk_38 = 5;
    data_0217d364->mUnk_3c = 0;
    d = data_0217d364;
    switch (d->mUnk_40) {
        case 0:
        case 1:
        case 3:
            func_021277f8(func_020b3f7c(d->mUnk_28, 4), func_020b3f7c(d->mUnk_28, 2), 0);
            break;
        case 2:
            func_021277f8(func_020b3f7c(d->mUnk_28, 4), func_020b3f7c(d->mUnk_28, 2), 0);
            if (*(vu16 *) 0x027ffc40 == 2) {
                func_0212513c(func_020b3f7c(data_0217d364->mUnk_2c,
                                            data_0215cb3c[data_0215cadc[func_0202968c()]][data_0217d364->mUnk_50]),
                              func_020b3f7c(data_0217d364->mUnk_28, 0x8b), buf, 0x200);
                func_02125ebc(0x23);
                func_021266e4(buf);
            }
            break;
    }
}
#pragma thumb off
