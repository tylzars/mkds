#include "ITCM/code_01ffb930.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_02165000.h"

void func_01ffb9e0(Unk0206bcb0 *p) {
    if ((p->mUnk_44 & 0x400) || p->mState != 0) {
        p->mUnk_2a8 = (s64) p->mUnk_2a8 * p->mUnk_2cc->mUnk_2c >> 12;
    }
    if (!(p->mUnk_48 & 0x2000)) {
        return;
    }
    p->mUnk_2a8 = (s64) p->mUnk_2a8 * 0xe66 >> 12;
}

void func_01ffb9cc(Unk0206bcb0 *p) {
    p->mUnk_260 = p->mUnk_260 + p->mUnk_c8;
}

void func_01ffb930(s32 *a, Unk0206bcb0 *p) {
    s32 b;
    u32 f;
    s32 c;

    if (p->mState != 0) {
        return;
    }
    f = p->mUnk_44;
    if (f & 8) {
        return;
    }
    if (!(f & 0x10)) {
        return;
    }
    if (*a <= 0x3000) {
        return;
    }
    b = p->mUnk_2d4;
    if (b <= 0) {
        b = -b;
    }
    c = (s32) ((s64) *a * data_usa_021654d8 >> 12);
    *a -= (s32) ((s64) c * b >> 12);
}
