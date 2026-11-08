#include "01/code_0218c63c.h"
#include "01/code_02188950.h"
#include "code_02133048.h"

void SetKurikingCollisionAndShadow(Unk02188950 *mapObject) {
    s32 *shadowScaleTarget;
    MissionRunPrm *prm;
    prm = mapObject->mPrm;
    SetCollisionOffsetAndExtent(mapObject, prm->mUnk_008, prm->mUnk_00c, prm->mUnk_214);
    SetShadowOffsetYAndScale(mapObject, 0, mapObject->mPrm->mUnk_00c);
    shadowScaleTarget = &mapObject->mShadowScaleTargetX;
    *shadowScaleTarget = 0x00011800u;
    mapObject->mShadowScaleX = *shadowScaleTarget;
    shadowScaleTarget = &mapObject->mShadowScaleTargetZ;
    *shadowScaleTarget = 0x0000c000u;
    mapObject->mShadowScaleZ = *shadowScaleTarget;
}

void SetDoubledCollisionAndShadowTargets(Unk02188950 *mapObject) {
    u32 offsetPerCall;
    u32 extentPerCall;
    int extentXZ;
    MissionRunPrm *prm;
    int offsetY;
    prm = mapObject->mPrm;
    extentXZ = prm->mUnk_00c;
    offsetY = prm->mUnk_008;
    offsetPerCall = _s32_div_f(offsetY, 0x14);
    extentPerCall = _s32_div_f(extentXZ, 0x14);
    SetCollisionOffsetAndExtentTarget(mapObject, offsetY << 1, offsetPerCall, extentXZ << 1, prm->mUnk_214 << 1,
                                      extentPerCall);
    SetShadowOffsetYAndScaleTarget(mapObject, 0, 0, 0, 0x00000e00u);
    mapObject->mShadowScaleTargetX = 0x00023000u;
    mapObject->mShadowScaleTargetZ = 0x00018000u;
}

void SetTripledCollisionAndShadowTargets(Unk02188950 *mapObject) {
    u32 offsetPerCall;
    u32 extentPerCall;
    int extentXZ;
    MissionRunPrm *prm;
    int offsetY;
    prm = mapObject->mPrm;
    extentXZ = prm->mUnk_00c;
    offsetY = prm->mUnk_008;
    offsetPerCall = _s32_div_f(offsetY, 0x14);
    extentPerCall = _s32_div_f(extentXZ, 0x14);
    SetCollisionOffsetAndExtentTarget(mapObject, offsetY * 3, offsetPerCall, extentXZ * 3, prm->mUnk_214 * 3,
                                      extentPerCall);
    SetShadowOffsetYAndScaleTarget(mapObject, 0, 0, 0, 0x00000e00u);
    mapObject->mShadowScaleTargetX = 0x00034800u;
    mapObject->mShadowScaleTargetZ = 0x00024000u;
}
