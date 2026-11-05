#include "01/code_0218ac04.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "01/code_02187000.h"
#include "01/code_02185ef4.h"
#include "01/code_02187e78.h"
#include "01/code_02188000.h"
#include "01/code_02188da4.h"
#include "01/code_02188e24.h"
#include "01/code_0218ad68.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_0218a000.h"
#include "01/code_0218add0.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020fd000.h"

void func_ov001_0218acb4(Unk02188950 *a) {
    Vec3 v = {0, 0, 0};

    func_ov001_02187e78(a);
    func_ov001_02187218(a, 3, NULL);
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_1c0), (s32) (a->mPrm->mUnk_1c4));
    func_ov001_02188c48(a, a->mPrm->mUnk_1d0, a->mPrm->mUnk_1d4);
    SetAnglePointAndMoveAnglePoint(a, (Vec3 *) func_ov001_02187fc0(a));
    func_ov001_02188cd8(a, (s32) (a->mPrm->mUnk_1c8), (s32) (a->mPrm->mUnk_1cc));
    SetVelocity(a, &v);
    func_ov001_02188e24(a, a->mPrm->mUnk_1d8, func_ov001_0218ad68);
    a->mUnk_2c0 = FALSE;
}

void func_ov001_0218ac04(Unk02188950 *a) {
    Vec3 v = {0, 0, 0};

    v.y = a->mPrm->mUnk_1b8;
    func_ov001_02187218(a, 3, NULL);
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_1a8), (s32) (a->mPrm->mUnk_1ac));
    SetVelocity(a, &v);
    func_ov001_02188cd8(a, (s32) (a->mPrm->mUnk_1b0), (s32) (a->mPrm->mUnk_1b4));
    func_ov001_02188db8(a, func_ov001_0218ae60);
    func_ov001_02188e24(a, a->mPrm->mUnk_1bc, func_ov001_0218acb4);
    func_020d2774(&a->mUnk_000, (u32) (0x239));
    a->mUnk_000.mFlags |= data_ov001_021a6594;
}
