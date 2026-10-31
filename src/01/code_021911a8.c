#include "01/code_021911a8.h"
#include "01/code_02187098.h"
#include "01/code_021874c4.h"
#include "01/code_02187e78.h"
#include "01/code_02188158.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "01/code_02188de0.h"
#include "01/code_02188e24.h"
#include "01/code_02191470.h"
#include "01/code_02191488.h"
#include "01/code_02192794.h"
#include "01/code_021927c0.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"

void func_ov001_021913b8(Unk02188950 *param_1) {
    Unk0206bcb0 *v1 = func_0207a974((u16)data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    func_ov001_02187e78(param_1);
    func_ov001_02187218(param_1, 3, (s32 (*)(Unk02188950 *)) (func_ov001_02191470));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_0d0, param_1->mUnk_0a0->mUnk_0d4);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188c90(param_1);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_0d8, param_1->mUnk_0a0->mUnk_0dc);
    func_ov001_02188de0(param_1, param_1->mUnk_0a0->mUnk_0e8, 0, &v1->mUnk_80, func_ov001_02191488);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_0ec, func_ov001_02191488);
    param_1->mUnk_2c0 = 0;
}

void func_ov001_02191318(Unk02188950 *param_1) {
    Unk0206bcb0 *v1 = func_0207a974((u16)data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    local.y = param_1->mUnk_0a0->mUnk_0a4;
    func_ov001_02187218(param_1, 3, (s32 (*)(Unk02188950 *)) (func_ov001_02191470));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_08c, param_1->mUnk_0a0->mUnk_090);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188c90(param_1);
    func_ov001_02188998(param_1, &v1->mUnk_80);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_094, param_1->mUnk_0a0->mUnk_098);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_0a8, func_ov001_021913b8);
}

void func_ov001_02191258(Unk02188950 *param_1) {
    Vec3 local = {0, 0, 0};

    func_ov001_02187218(param_1, 3, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_210, param_1->mUnk_0a0->mUnk_214);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_218, 0);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188200(param_1, (UnkFunc *) (func_ov001_02192878));
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x414), (u32) (0));
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x415), (u32) (0));
    func_020d2774(&param_1->mUnk_000, (u32) (0x218));
}

void func_ov001_021911a8(Unk02188950 *param_1) {
    Unk0206bcb0 *v1 = func_0207a974((u16)data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    local.y = param_1->mUnk_0a0->mUnk_1e4;
    func_ov001_02187218(param_1, 3, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1cc, param_1->mUnk_0a0->mUnk_1d0);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188c90(param_1);
    func_ov001_02188998(param_1, &v1->mUnk_80);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_1d4, param_1->mUnk_0a0->mUnk_1d8);
    func_ov001_02188db8(param_1, func_ov001_02191258);
    func_ov001_02188200(param_1, (UnkFunc *) (func_ov001_02192794));
}
