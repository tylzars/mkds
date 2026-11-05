#include "01/code_0218b034.h"
#include "01/code_02185ef4.h"
#include "01/code_02187bfc.h"
#include "01/code_02187c4c.h"
#include "01/code_02187d14.h"
#include "01/code_02188218.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020fd264.h"

void func_ov001_0218b1d8(Unk02188950 *a) {
    Vec3 vec;

    if (func_ov001_02187c4c(a)) {
        vec.x = (s32) (((s64) a->mPrm->mUnk_134 * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2]) >> 12);
        vec.y = a->mPrm->mUnk_138;
        vec.z = (s32) (((s64) a->mPrm->mUnk_134 * gPairsByAngle[((u16) a->mMoveAngle >> 4) * 2 + 1]) >> 12);
        func_ov001_02187bfc(a, &vec, a->mPrm->mUnk_13c);
    }
}

void func_ov001_0218b034(Unk02188950 *a) {
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
        if (func_ov001_02188220(a) == 0) {
            idx = ((u16) angle >> 4) * 2;
            pos.x = a->mUnk_000.mPos.x + (s32) (((s64) a->mPrm->mUnk_14c * gPairsByAngle[idx]) >> 12);
            pos.y = a->mUnk_000.mPos.y + a->mPrm->mUnk_150;
            pos.z = a->mUnk_000.mPos.z + (s32) (((s64) a->mPrm->mUnk_14c * gPairsByAngle[idx + 1]) >> 12);
        } else {
            idx = ((u16) angle >> 4) * 2;
            pos.x = a->mUnk_000.mPos.x + (s32) (((s64) a->mPrm->mUnk_154 * gPairsByAngle[idx]) >> 12);
            pos.y = a->mUnk_000.mPos.y + a->mPrm->mUnk_158;
            pos.z = a->mUnk_000.mPos.z + (s32) (((s64) a->mPrm->mUnk_154 * gPairsByAngle[idx + 1]) >> 12);
        }
        if (i == 0) {
            func_ov001_02187b94(func_020fd428(), &pos, &vel, a->mPrm->mUnk_15c);
        } else {
            func_ov001_02187b94(func_ov001_02187e00(9), &pos, &vel, a->mPrm->mUnk_160);
        }
    }
    func_ov001_02187518(a, (u32) (0x2000), (u32) (0), (u32) (0x3ae), (u32) (0x410), (u32) (0));
    func_020d2774(&a->mUnk_000, (u32) (0x236));
}
