#include "Main/Unknown/code_02067a2c.h"
#include "Main/Unknown/code_02074854.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02081120.h"
#include "Main/Unknown/code_020839d8.h"

s32 func_02067bf4(Unk0206bcb0 *a, s32 *b) {
    *b = 0xc;
    a->mUnk_48 &= 0xdfe77fdf;
    a->mUnk_238 = 0;
    a->mUnk_538.mUnk_00 = 0;
    a->mUnk_23c = 0;
    if ((a->mUnk_7c & 1) != 0) {
        if ((a->mUnk_4c & 0x10000000) == 0 && (a->mUnk_48 & 0x4000000) == 0) {
            func_02074854();
        }
        func_02055c5c();
    }
    a->mUnk_2a8 = 0;
    return 5;
}

s32 func_02067b60(Unk0206bcb0 *a, s32 *b) {
    *b = 0xc;
    a->mUnk_48 &= 0xdfe77fdf;
    a->mUnk_238 = 0;
    a->mUnk_538.mUnk_00 = 0;
    a->mUnk_23c = 0;
    if ((a->mUnk_7c & 1) != 0) {
        if ((a->mUnk_4c & 0x10000000) == 0 && (a->mUnk_48 & 0x4000000) == 0) {
            func_02074854();
        }
        func_02055c5c();
    }
    if (func_0206bcb0(a, 1, 0) != 0) {
        func_02081224(a->mUnk_74);
    }
    return 5;
}

s32 func_02067b0c(Unk0206bcb0 *a, s32 *b, s32 c) {
    if (func_0206a24c(a) != 0 && a->mUnk_44c != (struct Unk020e71a0 *) c && (a->mUnk_7c & 1) != 0) {
        func_0207a6b0()->mUnk_14++;
    }
    *b = 0;
    return 0;
}

s32 func_02067ad4(Unk0206bcb0 *p) {
    func_02083f6c((u16) data_usa_02154a84[p->mUnk_3e4], p);
    return 0;
}

s32 func_02067a9c(Unk0206bcb0 *p) {
    func_02083f6c((u16) data_usa_02154ac4[p->mUnk_3e4], p);
    return 0;
}

s32 func_02067a64(Unk0206bcb0 *p) {
    func_02083f6c((u16) data_usa_02154ae4[p->mUnk_3e4], p);
    return 5;
}

s32 func_02067a2c(Unk0206bcb0 *p) {
    func_0207a6c0(p);
    func_02083f6c((u16) data_usa_02154b24[p->mUnk_3e4], p);
    return 2;
}
