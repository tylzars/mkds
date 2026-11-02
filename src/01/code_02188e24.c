#include "01/code_02188e24.h"

void func_ov001_02188e74(Unk02188950 *a, s32 b, UnkFunc *c) {
    a->mUnk_1d8 = b;
    a->mUnk_1dc = c;
    return;
}

void func_ov001_02188e48(Unk02188950 *a, s32 b, void (*c)(Unk02188950 *), s32 d, void (*e)(Unk02188950 *)) {
    a->mUnk_1e0 = b;
    a->mUnk_1e4 = c;
    a->mUnk_1e8 = d;
    a->mUnk_1ec = e;
    return;
}

void func_ov001_02188e24(Unk02188950 *a, s32 b, UnkFunc *c) {
    a->mUnk_1f0 = b;
    a->mUnk_0b0 = 0;
    if (c == NULL) {
        c = (UnkFunc *) func_ov001_02188e88;
    }
    a->mUnk_1f4 = c;
    return;
}
