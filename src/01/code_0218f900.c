#include "01/code_0218f900.h"
#include "01/code_02188cd8.h"

#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_0218f000.h"
#include "Main/Unknown/code_0209bef0.h"

u16 func_ov001_0218f9c0(Unk02188950 *a) {
    return a->mUnk_0a8 == 2;
}

void func_ov001_0218f9a8(Unk02188950 *a) {
    a->mUnk_2d8 = 0;
    SetKartCollisionCallback(a, func_ov001_0218f9a8);
}

void func_ov001_0218f900(Unk02188950 *a) {
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_198, a->mPrm->mUnk_19c);
    SetAlphaLimitTargetAndPerCall(a, a->mPrm->mUnk_1ac, a->mPrm->mUnk_1b0);
    SetSpeedAndClearTarget(a, 0);
    func_ov001_02188c90(a);
    StartEffectAtOffset(a, 0, 0, 0, 0x41b, 0);
    StartEffectAtOffset(a, 0, 0, 0, 0x41c, 0);
    StartEffectAtOffset(a, 0, 0, 0, 0x41d, 0);
    StartMapObjectSound(&a->mUnk_000, 0x22e);
    a->mUnk_000.mFlags &= ~1;
}
