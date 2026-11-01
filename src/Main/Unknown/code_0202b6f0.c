#include "Main/Unknown/code_0202b6f0.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_0202a92c.h"
#include "Main/Unknown/code_0202cbf4.h"

#pragma thumb on

void func_0202b7c0(s32 a) {
    s32 i;

    func_02025f14(&data_02174e3c->mUnk_210[0], 2);
    func_02025f14(&data_02174e3c->mUnk_210[3], 2);
    func_02025f14(&data_02174e3c->mUnk_210[2], 2);
    switch (a) {
        case 0:
        case 1:
            for (i = 0; i < 8; i++) {
                if (i < data_02174e3c->mUnk_048 || data_02174e3c->mUnk_208 != 0) {
                    func_0202cc18(i, 1);
                }
            }
            break;
        case 2:
            func_02025f14(&data_02174e3c->mUnk_210[1], 2);
            break;
        case 3:
            for (i = 0; i < 8; i++) {
                func_0202cb2c(i);
            }
            data_02174e3c->mUnk_20c = 1;
            break;
    }
}

void func_0202b6f0(s32 a) {
    s32 i;
    s32 k;

    if (data_02174e3c->mUnk_204 != a) {
        if (a != 0) {
            for (i = 0; i < 8; i++) {
                if (i < data_02174e3c->mUnk_048 || data_02174e3c->mUnk_208 != 0) {
                    if (data_02174e3c->mUnk_04c[i].mUnk_00 == 0) {
                        k = 1;
                    } else if (data_02174e3c->mUnk_04c[i].mUnk_00 == 1) {
                        k = 2;
                    }
                    func_0202cc18(i, k);
                }
            }
            func_02025f14(&data_02174e3c->mUnk_210[2], 0);
            func_02025f14(&data_02174e3c->mUnk_210[0], 2);
        } else {
            for (i = 0; i < 8; i++) {
                if (i < data_02174e3c->mUnk_048 || data_02174e3c->mUnk_208 != 0) {
                    func_0202cc18(i, 1);
                }
            }
            func_02025f14(&data_02174e3c->mUnk_210[2], 2);
            func_02025f14(&data_02174e3c->mUnk_210[0], 0);
        }
    }
    data_02174e3c->mUnk_204 = a;
}

#pragma thumb off
