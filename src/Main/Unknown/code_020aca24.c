#include "Main/Unknown/code_020aca24.h"
#include "Main/Unknown/code_020acaa4.h"
#include "Main/Unknown/code_02105e98.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void func_020aca24(Unk020aca24 *a) {
    s16 v[5] = {1, 6, 12, 7, 8};

    if (a != NULL) {
        switch (data_0217b340->mUnk_54) {
            case 0:
            case 3:
            case 4:
            default:
                func_020acab8(0);
                break;
            case 1:
                func_020acab8(2);
                func_020acaa4(0);
                break;
            case 2:
                func_020acab8(3);
                break;
        }
        a->mUnk_04 = v[data_0217b340->mUnk_54];
        func_02105e98();
    }
}

#pragma thumb off
