#include "Main/Unknown/code_02067f94.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207a6b0.h"

void func_020680e0(Unk0206bcb0 *a, const Vec3 *b) {
    s32 c;
    BOOL d;
    s32 e;
    BOOL f;
    u32 g;
    s32 h;

    g = a->mUnk_4c;
    if ((g & 0x400000) != 0) {
        c = 0;
    } else if ((a->mUnk_7c & 0x200) != 0) {
        if (a->mState == 0 && (a->mUnk_48 & 0x1800) == 0 && (g & 0x10000040) == 0) {
            c = 1;
        } else {
            c = 0;
        }
    } else {
        d = TRUE;
        if ((g & 0x10000040) == 0 && (a->mUnk_48 & 0x1800) == 0) {
            e = 0;
            h = a->mState;
            if (h != 0 && h != 1 && h != 2) {
                e = d;
            }
            if (e == 0) {
                d = FALSE;
            }
        }
        c = d == FALSE ? 1 : 0;
    }
    if (c != 0) {
        func_0206add0(a, b, 0);
        f = TRUE;
    } else {
        f = FALSE;
    }
    if (f == FALSE) {
        return;
    }
    if ((a->mUnk_7c & 1) != 0) {
        func_0207a6b0()->mUnk_14++;
    }
    a->mUnk_48 |= 0x20000;
}

void func_02068094(Unk0206bcb0 *a, s32 b, s32 c) {
    if (func_0206b020(a, (Unk0206b020 *) c) == 0) {
        return;
    }
    if ((a->mUnk_7c & 1) != 0) {
        func_0207a6b0()->mUnk_14++;
    }
    a->mUnk_48 |= 0x20000;
}

void func_02067f94(Unk0206bcb0 *a, const Vec3 *b) {
    s32 c;
    BOOL d;
    s32 e;
    BOOL f;
    u32 g;
    s32 h;

    g = a->mUnk_4c;
    if ((g & 0x400000) != 0) {
        c = 0;
    } else if ((a->mUnk_7c & 0x200) != 0) {
        if (a->mState == 0 && (a->mUnk_48 & 0x1800) == 0 && (g & 0x10000040) == 0) {
            c = 1;
        } else {
            c = 0;
        }
    } else {
        d = TRUE;
        if ((g & 0x10000040) == 0 && (a->mUnk_48 & 0x1800) == 0) {
            e = 0;
            h = a->mState;
            if (h != 0 && h != 1 && h != 2) {
                e = d;
            }
            if (e == 0) {
                d = FALSE;
            }
        }
        c = d == FALSE ? 1 : 0;
    }
    if (c != 0) {
        func_0206a980(a, b, 0);
        f = TRUE;
    } else {
        f = FALSE;
    }
    if (f == FALSE) {
        return;
    }
    if ((a->mUnk_7c & 1) != 0) {
        func_0207a6b0()->mUnk_14++;
    }
    a->mUnk_48 |= 0x20000;
}
