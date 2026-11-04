#include "code_0202210c.h"
#include "code_020222ec.h"
#include "code_02134398.h"

static inline void func_0202212c_inline2(const Unk02022030 *a, u16 i) {
    switch (a->mUnk_1c) {
        case 2:
            if (i == a->mUnk_28) {
                a->mUnk_24(a->mUnk_20, i);
            }
            break;
        case 3:
            a->mUnk_24(a->mUnk_20, i);
            break;
    }
}

static inline u32 func_0202212c_inline(Unk02022030 *a) {
    if (a->mUnk_08 != 0 && a->mUnk_0c >= (((Unk02022188 *) a->mUnk_00)->mUnk_04 << 12)) {
        return 1;
    }
    return 0;
}

u32 func_0202212c(Unk02022030 *a, s32 b) {
    u32 r;
    s32 n;
    Unk02021e40 *c;
    u16 i;
    s32 *p;

    r = 0;
    if (a->mUnk_08 != 1) {
        return 0;
    }
    a->mUnk_0c += Abs((u32) (((s64) a->mUnk_10 * b + 0x800) >> 12));
    p = &a->mUnk_0c;
    while (func_0202212c_inline(a)) {
        r = 1;
        *p = *p - (((Unk02022188 *) a->mUnk_00)->mUnk_04 << 12);
        if ((a->mUnk_10 > 0) ^ a->mUnk_04) {
            a->mUnk_00++;
        } else {
            a->mUnk_00--;
        }
        c = a->mUnk_00;
        if ((a->mUnk_10 > 0) ^ a->mUnk_04) {
            n = c >= &a->mUnk_18->mUnk_0c[a->mUnk_18->mUnk_00];
        } else {
            n = c <= &a->mUnk_18->mUnk_0c[a->mUnk_18->mUnk_02] - 1;
        }
        if (n) {
            func_02022310(a);
        }
        if (a->mUnk_1c != 0) {
            i = ((u32) a->mUnk_00 - (u32) a->mUnk_18->mUnk_0c) >> 3;
            func_0202212c_inline2(a, i);
        }
    }
    return r;
}

u32 func_0202210c(Unk02022030 *a, u32 b) {
    u32 r;

    r = func_020222ec(a, b);
    if (r != 0) {
        a->mUnk_0c = 0;
    }
    return r;
}
