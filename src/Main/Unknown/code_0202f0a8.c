#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/code_0202f028.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

#pragma thumb on

void func_0202f120(s32 a, s32 b, s32 c, s32 d) {
    void (*f)(int, int, int, int) = gScrollList->mUnk_028;
    if (f != NULL) {
        if (a == 1) {
            if (c < 0 || c >= gScrollList->mRowCount) {
                return;
            }
        }
        f(a, b, c, d);
    }
}

#pragma thumb off

u32 func_0202f0fc(InputSlotPair *a) {
    if (a->mPrevHasPair == 0 && a->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_0202f0c8(InputSlotPair *a) {
    u32 r = 0;
    if (func_0202f028(a) == 0 && func_0202f0fc(a) != 0) {
        r = 1;
    }
    return r;
}

u32 func_0202f0a8(u32 a) {
    return func_0202f0c8((InputSlotPair *) &data_02175628[a].mPairX);
}
