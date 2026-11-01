#include "01/code_02183f0c.h"
#include "01/unk_021a6000.h"

void func_ov001_02183ff4(Unk02188950 *param_1) {
    Vec3 sp;
    s32 scale;

    sp.x = param_1->mUnk_000.mUnk_04.x;
    sp.y = 0;
    sp.z = param_1->mUnk_000.mUnk_04.z;
    if ((s64) sp.z * sp.z + ((s64) sp.x * sp.x + (s64) sp.y * sp.y) >= 16) {
        func_02039860(&sp, &sp);
    }
    scale = param_1->mUnk_0a0->mUnk_204;
    sp.x = (s64) sp.x * scale >> 12;
    sp.y = (s64) sp.y * scale >> 12;
    sp.z = (s64) sp.z * scale >> 12;
    sp.y = -param_1->mUnk_0a0->mUnk_208;
    func_ov001_02187218(param_1, 8, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1fc, param_1->mUnk_0a0->mUnk_200);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188950(param_1, &sp);
    func_ov001_0218720c(param_1);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_20c, func_ov001_02184160);
    func_ov001_021874c4(param_1, 0, 0, 0, 0x423, 0);
    func_ov001_021874c4(param_1, 0, 0, 0, 0x425, 0);
    func_ov001_02187444(param_1, 4, 0);
    func_020d2774(&param_1->mUnk_000, (u32) (0x244));
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a6578;
}

void func_ov001_02183f0c(Unk02188950 *param_1) {
    Vec3 sp8 = {0, 0, 0};

    func_ov001_02187218(param_1, 8, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_070, param_1->mUnk_0a0->mUnk_074);
    func_ov001_02188950(param_1, &sp8);
    func_ov001_0218720c(param_1);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    if (param_1->mUnk_000.mUnk_00 == 0x1f5) {
        func_ov001_021874c4(param_1, 0, 0, 0, 0x423, 0);
        func_ov001_021874c4(param_1, 0, 0, 0, 0x425, 0);
    } else if (param_1->mUnk_000.mUnk_00 == 0x1f6) {
        func_ov001_021874c4(param_1, 0, 0, 0, 0x423, 0);
        func_ov001_021874c4(param_1, 0, 0, 0, 0x425, 0);
    }
    {
        Unk021a78d8 sp14 = {0x212, 0, 0xc, 0};

        sp14.mUnk_04 = &param_1->mUnk_000.mUnk_04;
        sp14.mUnk_0c = func_020d4ef4(&param_1->mUnk_000.mUnk_04);
        func_0210b734(&sp14, func_02108e7c());
    }
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a6578;
}
