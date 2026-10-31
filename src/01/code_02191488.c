#include "01/code_02191488.h"
#include "01/code_02181b54.h"
#include "01/code_02187098.h"
#include "01/code_021874c4.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "01/code_02188e24.h"
#include "01/code_02191870.h"
#include "01/code_02191888.h"
#include "01/code_02192794.h"
#include "01/code_021927c0.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"

void func_ov001_021917d0(Unk02188950 *param_1) {
    func_0207a974((u16)data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, (s32 (*)(Unk02188950 *)) (func_ov001_02191888));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_148, param_1->mUnk_0a0->mUnk_14c);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_150, param_1->mUnk_0a0->mUnk_154);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_160, func_ov001_021918c8);
    func_ov001_021875c0(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x433), (u32) (0));
}

void func_ov001_021916e0(Unk02188950 *param_1) {
    Unk0206bcb0 *v1 = func_0207a974((u16)data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    if ((param_1->mUnk_000.mUnk_02 & 0x400) == 0) {
        param_1->mUnk_1a8 = param_1->mUnk_184 + 0x4000;
    } else {
        param_1->mUnk_1a8 = param_1->mUnk_184 - 0x4000;
    }
    func_ov001_02187218(param_1, 3, (s32 (*)(Unk02188950 *)) (func_ov001_02191870));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_128, param_1->mUnk_0a0->mUnk_12c);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_130, param_1->mUnk_0a0->mUnk_134);
    func_ov001_021889c8(param_1);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_140, func_ov001_021917d0);
    func_ov001_02188200(param_1, (UnkFunc *) (func_ov001_021927c0));
    func_ov001_021875c0(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x433), (u32) (0));
}

void func_ov001_02191618(Unk02188950 *param_1) {
    Vec3 local = {0, 0, 0};

    func_ov001_02187218(param_1, 3, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_118, param_1->mUnk_0a0->mUnk_11c);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_120, func_ov001_021916e0);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188200(param_1, (UnkFunc *) (func_ov001_02192878));
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x414), (u32) (0));
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x415), (u32) (0));
    func_020d2774(&param_1->mUnk_000, (u32) (0x218));
}

void func_ov001_02191550(Unk02188950 *param_1) {
    Vec3 local = {0, 0, 0};

    func_ov001_02187218(param_1, 3, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_10c, param_1->mUnk_0a0->mUnk_110);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_114, func_ov001_021918c8);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188200(param_1, (UnkFunc *) (func_ov001_02192878));
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x414), (u32) (0));
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x415), (u32) (0));
    func_020d2774(&param_1->mUnk_000, (u32) (0x218));
}

void func_ov001_02191488(Unk02188950 *param_1) {
    Vec3 local = {0, 0, 0};

    local.y = param_1->mUnk_0a0->mUnk_108;
    func_ov001_02187218(param_1, 3, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_0f0, param_1->mUnk_0a0->mUnk_0f4);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188c90(param_1);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_0f8, param_1->mUnk_0a0->mUnk_0fc);
    if (func_ov001_02188220(data_021759c0->mUnk_08 == 4 ? (Unk02188950 *) func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2)) : 0) >= 1) {
        func_ov001_02188db8(param_1, func_ov001_02191618);
    } else {
        func_ov001_02188db8(param_1, func_ov001_02191550);
    }
    param_1->mUnk_2c0 = 1;
    func_ov001_02188200(param_1, (UnkFunc *) (func_ov001_02192794));
}
