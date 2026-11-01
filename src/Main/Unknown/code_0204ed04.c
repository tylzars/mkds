#include "Main/Unknown/code_0204ed04.h"

#pragma thumb on

void func_0204ed84(void) {
    u16 b;
    u16 c;
    if (!(data_0217aa00->mUnk_1e44 & 1)) {
        u32 v;
        if (data_0217aa00 == 0) {
            v = 0;
        } else {
            v = data_0217aa00->mUnk_0000;
        }
        switch (v) {
            case 1:
                data_usa_0216522c.mUnk_04 = 0x192;
                b = func_02006954(data_0217aa00->mUnk_1e30, 0x192);
                c = data_0217aa00->mUnk_0044.mUnk_43;
                break;
            case 2:
                data_usa_0216522c.mUnk_04 = 0xe;
                b = func_02006914(data_0217aa00->mUnk_1e30, 0xe);
                c = 1;
                break;
        }
        if (func_02050650((void *) data_0217aa00->mUnk_1e30, b, c, 0, &data_usa_0216522c) == 0) {
            data_0217aa00->mUnk_1e42 = data_usa_02165228;
            data_0217aa00->mUnk_1e44 &= ~1;
        }
    }
}

void func_0204ed04(Unk0204ed04 *a) {
    u8 b[0x192];
    u32 v;
    if (a->mUnk_02 == 0 && a->mUnk_0c != 0 && a->mUnk_10 <= 0x192) {
        func_0200ee3c(a->mUnk_0c, a->mUnk_10);
        func_0214d1fc(a->mUnk_0c, b, a->mUnk_10);
        if (a->mUnk_04 == 7) {
            return;
        }
        if (a->mUnk_04 == 9) {
            return;
        }
        if (a->mUnk_04 == 0x15) {
            if (data_0217aa00 == 0) {
                v = 0;
            } else {
                v = data_0217aa00->mUnk_0000;
            }
            switch (v) {
                case 1:
                    func_0200692c(b, a->mUnk_10, a->mUnk_12);
                    break;
                case 2:
                    func_020068f4(b, a->mUnk_10);
                    break;
            }
        }
    }
}

#pragma thumb off
