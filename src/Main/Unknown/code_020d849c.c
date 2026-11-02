#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020d8cac.h"

void func_020d8620(Unk020e0144 *p) {
    Unk02042044 *a = p->mUnk_1c;
    p->mUnk_1c = p->mUnk_20;
    p->mUnk_20 = a;
    p->mUnk_18 = p->mUnk_18 == 0;
}

void func_020d859c(Unk020d84e4 *p, u16 b, s32 c) {
    s32 a;
    s32 d;
    func_020d90a8(&p->mUnk_00, b, c);
    a = p->mUnk_00.mUnk_1c->mUnk_0e;
    p->mUnk_2c = a != 0 ? p->mUnk_24 * a : p->mUnk_28;
    p->mUnk_30 = p->mUnk_2c;
    a = p->mUnk_00.mUnk_20->mUnk_0e;
    p->mUnk_34 = a != 0 ? p->mUnk_24 * a : p->mUnk_28;
    d = p->mUnk_30;
    p->mUnk_00.mUnk_04 = d;
    p->mUnk_00.mUnk_10 = (s32) (((s64) d * p->mUnk_00.mUnk_00->mUnk_00[p->mUnk_00.mUnk_0c].mUnk_34) >> 12);
}

s32 func_020d84e4(Unk020d84e4 *p) {
    s32 r;
    s32 a;
    s32 b;
    s32 c;
    r = func_020d8cc8(&p->mUnk_00);
    if (r != 0) {
        p->mUnk_2c = p->mUnk_34;
        a = p->mUnk_00.mUnk_20->mUnk_0e;
        p->mUnk_34 = a != 0 ? p->mUnk_24 * a : p->mUnk_28;
    }
    if (p->mUnk_2c != p->mUnk_34) {
        b = func_020d8cac(&p->mUnk_00);
        c = (s32) (((s64) p->mUnk_2c * (0x1000 - b)) >> 12) + (s32) (((s64) p->mUnk_34 * b) >> 12);
        p->mUnk_00.mUnk_04 = c;
        p->mUnk_00.mUnk_10 = (s32) (((s64) c * p->mUnk_00.mUnk_00->mUnk_00[p->mUnk_00.mUnk_0c].mUnk_34) >> 12);
    }
    return r;
}

void func_020d84c0(Unk020d849c *p, s32 a) {
    s32 t = p->mUnk_00.mUnk_34;
    p->mUnk_54 = a;
    a = t != 0 ? (s32) (((s64) a * t) >> 12) : 0x1000000;
    p->mUnk_58 = a;
}

BOOL func_020d849c(Unk020d849c *p) {
    p->mUnk_5c = p->mUnk_5c + p->mUnk_58;
    return p->mUnk_5c >= 0x1000000;
}
