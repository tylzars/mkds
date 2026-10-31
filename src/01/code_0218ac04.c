#include "01/code_0218ac04.h"
#include "01/code_02187000.h"
#include "01/code_02187098.h"
#include "01/code_02187e78.h"
#include "01/code_02188000.h"
#include "01/code_02188da4.h"
#include "01/code_02188e24.h"
#include "01/code_0218ad68.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_0218a000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020fd000.h"

void func_ov001_0218acb4(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};

    func_ov001_02187e78(param_1);
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_1c0), (s32) (param_1->mUnk_0a0->mUnk_1c4));
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_1d0, param_1->mUnk_0a0->mUnk_1d4);
    func_ov001_02188998(param_1, (Vec3 *)func_ov001_02187fc0(param_1));
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_1c8), (s32) (param_1->mUnk_0a0->mUnk_1cc));
    func_ov001_02188950(param_1, &v);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_1d8, func_ov001_0218ad68);
    param_1->mUnk_2c0 = 0;
}

void func_ov001_0218ac04(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};

    v.y = param_1->mUnk_0a0->mUnk_1b8;
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_1a8), (s32) (param_1->mUnk_0a0->mUnk_1ac));
    func_ov001_02188950(param_1, &v);
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_1b0), (s32) (param_1->mUnk_0a0->mUnk_1b4));
    func_ov001_02188db8(param_1, func_ov001_0218ae60);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_1bc, func_ov001_0218acb4);
    func_020d2774(&param_1->mUnk_000, (u32) (0x239));
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a6594;
}
