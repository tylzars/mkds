#include "Main/Unknown/code_0203f2b4.h"

BOOL func_0203f2dc(u32 a) {
    BOOL f;
    s32 s;
    f = FALSE;
    s = data_021759c0->mUnk_68[a].mUnk_08.mUnk_00;
    if ((u32) s <= 3 && ((1 << s) & 0xd) != 0) {
        f = TRUE;
    }
    if (f != FALSE) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_0203f2b4(u32 a) {
    return data_0217561c->mUnk_000[a].mUnk_14 == 4;
}
