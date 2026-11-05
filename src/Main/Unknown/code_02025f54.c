#include "Main/Unknown/code_02025f54.h"
#include "Main/Unknown/code_02025ebc.h"

#pragma thumb on

void func_02025f54(Unk02025ebc *a, u32 b) {
    a->mUnk_00 = b;
    switch (a->mUnk_00) {
        case 0:
        case 3:
            a->mUnk_04 = 0;
            return;
        case 1:
        case 2:
            a->mUnk_04 = a->mUnk_08;
    }
}

#pragma thumb off
