#include "01/code_0218add0.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"

void func_ov001_0218aef4(Unk02188950 *param_1) {
    Unk020f41c4_B *rng;
    s32 angle;
    s32 i;
    s32 idx;
    Vec3 pos;

    rng = func_020d22d0();
    rng->mUnk_00 = (s64) rng->mUnk_08 * (s64) rng->mUnk_00 + rng->mUnk_10;
    angle = (u16) (((rng->mUnk_00 >> 32) << 16) >> 32);
    for (i = 0; i < 3; i++) {
        Vec3 vel = {0, 0, 0};
        angle += 0x5555;
        idx = ((u16) angle >> 4) * 2;
        pos.x = param_1->mUnk_000.mUnk_04.x + (s32) (((s64) param_1->mUnk_0a0->mUnk_1e4 * data_0215d4b4[idx]) >> 12);
        pos.y = param_1->mUnk_000.mUnk_04.y;
        pos.z =
            param_1->mUnk_000.mUnk_04.z + (s32) (((s64) param_1->mUnk_0a0->mUnk_1e4 * data_0215d4b4[idx + 1]) >> 12);
        func_ov001_02187b94(func_020fd428(), &pos, &vel, param_1->mUnk_0a0->mUnk_1e8);
    }
    {
        Vec3 pos2;
        Vec3 vel2 = {0, 0, 0};
        pos2.x = param_1->mUnk_000.mUnk_04.x;
        pos2.y = param_1->mUnk_000.mUnk_04.y;
        pos2.z = param_1->mUnk_000.mUnk_04.z;
        func_ov001_02187b94(func_ov001_02187e00(9), &pos2, &vel2, param_1->mUnk_0a0->mUnk_1ec);
    }
    func_ov001_02188cec(param_1, 0);
}

void func_ov001_0218ae60(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, param_1->mUnk_0a0->mUnk_200, param_1->mUnk_0a0->mUnk_204, 0);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02187518(param_1, (u32) (0), (u32) (0), (u32) (0), (u32) (0x411), (u32) (0));
    func_ov001_02187518(param_1, (u32) (0), (u32) (0), (u32) (0), (u32) (0x412), (u32) (0));
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    param_1->mUnk_000.mUnk_02 &= ~0x20;
    func_ov001_02188200(param_1, (UnkFunc *) (0));
}

void func_ov001_0218add0(Unk02188950 *param_1) {
    Vec3 vec = {0, 0, 0};

    vec.y = param_1->mUnk_0a0->mUnk_1fc;
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1f4, param_1->mUnk_0a0->mUnk_1f8);
    func_ov001_02188950(param_1, &vec);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188db8(param_1, func_ov001_0218ae60);
    param_1->mUnk_2c0 = 1;
    func_020d2774(&param_1->mUnk_000, (u32) (0x23a));
    func_ov001_02188200(param_1, (UnkFunc *) (func_ov001_0218b2b8));
}
