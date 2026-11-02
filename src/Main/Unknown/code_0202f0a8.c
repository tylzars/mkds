#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/code_0202f028.h"

#pragma optimize_for_size on

u32 func_0202f0a8(u32 a) {
    return func_0202f0c8((Unk02175628_48 *) &data_02175628[a].mUnk_48);
}

u32 func_0202f0c8(Unk02175628_48 *a) {
    u32 r = 0;
    if (func_0202f028(a) == 0 && func_0202f0fc(a) != 0) {
        r = 1;
    }
    return r;
}

u32 func_0202f0fc(Unk02175628_48 *a) {
    if (a->mUnk_0c == 0 && a->mUnk_04 != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb on

void func_0202f120(s32 a, s32 b, s32 c, s32 d) {
    void (*f)(int, int, int, int) = data_02174e48->mUnk_028;
    if (f != NULL) {
        if (a == 1) {
            if (c < 0 || c >= data_02174e48->mUnk_034) {
                return;
            }
        }
        f(a, b, c, d);
    }
}

#pragma thumb off
