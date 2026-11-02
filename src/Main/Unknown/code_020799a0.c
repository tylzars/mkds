#include "Main/Unknown/code_020799a0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on

u32 func_020799a0(s32 param_1) {
    s32 a = 1;
    s32 b = a;
    s32 c = a;
    s32 d = a;
    if (param_1 != data_021759c0->mUnk_62 && param_1 != data_021759c0->mUnk_063) {
        d = 0;
    }
    if (d == 0 && data_021759c0->mUnk_08 != 4) {
        c = 0;
    }
    if (c == 0 && func_02062eb0() == 0) {
        b = 0;
    }
    if (b == 0 && data_021759c0->mUnk_08 != 1) {
        a = 0;
    }
    if (a != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
