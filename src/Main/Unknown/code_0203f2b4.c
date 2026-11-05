#include "Main/Unknown/code_0203f2b4.h"
#include "Main/Unknown/code_020f36d8.h"

BOOL func_0203f2dc(u32 a) {
    BOOL f;
    s32 s;
    f = FALSE;
    s = data_021759c0->mCurrentEntries[a].mPlayer.mKind;
    if ((u32) s <= 3 && ((1 << s) & 0xd) != 0) {
        f = TRUE;
    }
    if (f != FALSE) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_0203f2b4(u32 a) {
    return gRaceProgress->mUnk_000[a].mStatus == 4;
}
