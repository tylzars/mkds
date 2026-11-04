#include "Main/Unknown/code_020ae244.h"
#include "Main/Unknown/code_020ae1f4.h"
#include "Main/Unknown/code_020ae21c.h"
#include "Main/Unknown/code_020ae338.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

u32 func_020ae308(Unk02175628_48 *a) {
    if (func_020ae338(a) == 0 && a->mNoPairCount < 5) {
        return 1;
    }
    return 0;
}

u32 func_020ae2e4(Unk02175628_48 *a) {
    if (a->mPrevHasPair == 0 && a->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_020ae2b0(Unk02175628_48 *a) {
    if (func_020ae308(a) == 0 && func_020ae2e4(a) != 0) {
        return 1;
    }
    return 0;
}

u32 func_020ae290(u32 a) {
    return func_020ae2b0((Unk02175628_48 *) &data_02175628[a].mUnk_48);
}

#pragma thumb on

u32 func_020ae244(u32 a, Unk020ae244 b) {
    u32 x;
    u32 y;

    if (func_020ae290(a) != 0) {
        x = func_020ae21c(a);
        y = func_020ae1f4(a);
        if (b.mUnk_00 <= x && x <= b.mUnk_04 && b.mUnk_02 <= y && y <= b.mUnk_06) {
            return 1;
        }
    }
    return 0;
}
