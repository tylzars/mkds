#include "01/code_021927c0.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020b502c.h"

u32 func_ov001_02192a60(void) {
    return data_ov001_021a9bc8->mUnk_04;
}

u32 func_ov001_02192a54(void) {
    return data_ov001_021a9bc8->mUnk_08;
}

u32 func_ov001_02192a48(void) {
    return data_ov001_021a9bc8->mUnk_10;
}

u32 func_ov001_02192a3c(void) {
    return data_ov001_021a9bc8->mUnk_18;
}

u32 func_ov001_02192a30(void) {
    return data_ov001_021a9bc8->mUnk_1c;
}

u32 func_ov001_02192a24(void) {
    return data_ov001_021a9bc8->mUnk_28;
}

u16 func_ov001_02192a14(u16 param_1) {
    return data_021758e8[0x10] & param_1;
}

u16 func_ov001_02192a04(u16 param_1) {
    return data_021758e8[0x11] & param_1;
}

int func_ov001_021928c8(int param_1) {
    switch (param_1) {
        case 0x20:
            return data_ov001_021a9bc8->mUnk_2c == 1 || data_ov001_021a9bc8->mUnk_2c == 0xf;
        case 0x10:
            return data_ov001_021a9bc8->mUnk_30 == 1 || data_ov001_021a9bc8->mUnk_30 == 0xf;
        case 0x40:
            return data_ov001_021a9bc8->mUnk_34 == 1 || data_ov001_021a9bc8->mUnk_34 == 0xf;
        case 0x80:
            return data_ov001_021a9bc8->mUnk_38 == 1 || data_ov001_021a9bc8->mUnk_38 == 0xf;
        case 1:
            return data_ov001_021a9bc8->mUnk_3c == 1 || data_ov001_021a9bc8->mUnk_3c == 0xf;
        case 2:
            return data_ov001_021a9bc8->mUnk_40 == 1 || data_ov001_021a9bc8->mUnk_40 == 0xf;
        case 0x400:
            return data_ov001_021a9bc8->mUnk_44 == 1 || data_ov001_021a9bc8->mUnk_44 == 0xf;
        case 0x800:
            return data_ov001_021a9bc8->mUnk_48 == 1 || data_ov001_021a9bc8->mUnk_48 == 0xf;
        case 0x200:
            return data_ov001_021a9bc8->mUnk_4c == 1 || data_ov001_021a9bc8->mUnk_4c == 0xf;
        case 0x100:
            return data_ov001_021a9bc8->mUnk_50 == 1 || data_ov001_021a9bc8->mUnk_50 == 0xf;
    }
    return 0;
}

void func_ov001_02192890(Unk02188950 *param_1) {
    param_1->mUnk_000.mUnk_94 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (param_1->mUnk_000.mUnk_94), (u32) (0xc), (Vec3 *) (&param_1->mUnk_000.mUnk_04));
    param_1->mUnk_000.mUnk_70 = data_0217cbec[0x14];
}

void func_ov001_02192878(Unk02188950 *param_1) {
    param_1->mUnk_2d8 = 2;
    func_ov001_02188200(param_1, func_ov001_02192878);
}

void func_ov001_021927c0(Unk02188950 *param_1) {
    if (param_1->mUnk_2d0 > 0) {
        param_1->mUnk_2d8 = 2;
        func_ov001_02188200(param_1, func_ov001_021927c0);
        return;
    }
    param_1->mUnk_000.mUnk_10.x =
        ((s64) param_1->mUnk_0a0->mUnk_144 * data_0215d4b4[(u16) param_1->mUnk_1a8 >> 4 << 1]) >> 12;
    param_1->mUnk_000.mUnk_10.y = 0;
    param_1->mUnk_000.mUnk_10.z =
        ((s64) param_1->mUnk_0a0->mUnk_144 * data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4 << 1) + 1]) >> 12;
    param_1->mUnk_2d8 = 0xd;
    func_ov001_02188200(param_1, func_ov001_021927c0);
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
}
