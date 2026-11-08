#include "01/code_02184cc8.h"
#include "01/code_02188218.h"
#include "01/code_0218820c.h"
#include "01/code_02185ef4.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"

void func_ov001_02184d9c(Unk02188950 *mapObject) {
    if (func_ov001_0218820c(mapObject) != 0) {
        Vec3 velocity = {0, 0, 0};

        velocity.y = mapObject->mPrm->mUnk_1f4;
        func_ov001_02187218(mapObject, 5, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_1ec, mapObject->mPrm->mUnk_1f0);
        SetVelocity(mapObject, &velocity);
        SetCourseCollisionCallback(mapObject, func_ov001_02184d9c);
    } else {
        func_ov001_02187218(mapObject, 0, NULL);
    }
}

void func_ov001_02184d70(Unk02188950 *mapObject) {
    func_ov001_02188218(mapObject, (u16) mapObject->mPrm->mUnk_1f8);
    func_ov001_02188c90(mapObject);
    func_ov001_02184d9c(mapObject);
}

void func_ov001_02184cf4(Unk02188950 *mapObject) {
    if (func_ov001_0218820c(mapObject) != 0) {
        Vec3 velocity = {0, 0, 0};

        velocity.y = mapObject->mPrm->mUnk_124;
        func_ov001_02187218(mapObject, 5, NULL);
        StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_11c, mapObject->mPrm->mUnk_120);
        SetVelocity(mapObject, &velocity);
        SetCourseCollisionCallback(mapObject, func_ov001_02184cf4);
    } else {
        func_ov001_02187218(mapObject, 0, NULL);
    }
}

void func_ov001_02184cc8(Unk02188950 *mapObject) {
    func_ov001_02188218(mapObject, (u16) mapObject->mPrm->mUnk_128);
    func_ov001_02188c90(mapObject);
    func_ov001_02184cf4(mapObject);
}
