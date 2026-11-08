#include "01/code_0218c63c.h"
#include "01/code_02188950.h"
#include "code_02133048.h"

void func_ov001_0218c728(Unk02188950 *a) {
    s32 *v1;
    MissionRunPrm *v2;
    v2 = a->mPrm;
    SetCollisionOffsetAndExtent(a, v2->mUnk_008, v2->mUnk_00c, v2->mUnk_214);
    SetShadowOffsetYAndScale(a, 0, a->mPrm->mUnk_00c);
    v1 = &a->mShadowScaleTargetX;
    *v1 = 0x00011800u;
    a->mShadowScaleX = *v1;
    v1 = &a->mShadowScaleTargetZ;
    *v1 = 0x0000c000u;
    a->mShadowScaleZ = *v1;
}

void func_ov001_0218c6b4(Unk02188950 *a) {
    u32 v1;
    u32 v2;
    int v3;
    MissionRunPrm *v4;
    int v5;
    v4 = a->mPrm;
    v3 = v4->mUnk_00c;
    v5 = v4->mUnk_008;
    v1 = _s32_div_f(v5, 0x14);
    v2 = _s32_div_f(v3, 0x14);
    SetCollisionOffsetAndExtentTarget(a, v5 << 1, v1, v3 << 1, v4->mUnk_214 << 1, v2);
    SetShadowOffsetYAndScaleTarget(a, 0, 0, 0, 0x00000e00u);
    a->mShadowScaleTargetX = 0x00023000u;
    a->mShadowScaleTargetZ = 0x00018000u;
}

void func_ov001_0218c63c(Unk02188950 *a) {
    u32 v1;
    u32 v2;
    int v3;
    MissionRunPrm *v4;
    int v5;
    v4 = a->mPrm;
    v3 = v4->mUnk_00c;
    v5 = v4->mUnk_008;
    v1 = _s32_div_f(v5, 0x14);
    v2 = _s32_div_f(v3, 0x14);
    SetCollisionOffsetAndExtentTarget(a, v5 * 3, v1, v3 * 3, v4->mUnk_214 * 3, v2);
    SetShadowOffsetYAndScaleTarget(a, 0, 0, 0, 0x00000e00u);
    a->mShadowScaleTargetX = 0x00034800u;
    a->mShadowScaleTargetZ = 0x00024000u;
}
