#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f54.h"

#pragma thumb on

void func_02025f14(Unk02025ebc *a, s32 b) {
    switch (b) {
        case 0:
            switch (a->mUnk_00) {
                case 2:
                case 3:
                    func_02025f54(a, b);
            }
            break;
        case 2:
            switch (a->mUnk_00) {
                case 0:
                case 1:
                    func_02025f54(a, b);
            }
            break;
        default:
            func_02025f54(a, b);
            break;
    }
}

void func_02025edc(Unk02025ebc *a) {
    switch (a->mUnk_00) {
        case 0:
            a->mUnk_04++;
            if (a->mUnk_04 > a->mUnk_08) {
                a->mUnk_04 = a->mUnk_08;
                a->mUnk_00 = 1;
            }
            break;
        case 2:
            a->mUnk_04--;
            if (a->mUnk_04 < 0) {
                a->mUnk_04 = 0;
                a->mUnk_00 = 3;
            }
            break;
    }
}

#pragma thumb off
