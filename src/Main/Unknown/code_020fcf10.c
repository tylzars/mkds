#include "Main/Unknown/code_020fcf10.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"

void SteerItemKouraWToAnglePoint(ItemKouraW *item, s32 maxStep, s32 angle, s32 radius, s32 gain, s32 oldWeight,
                                 s32 shift) {
    Vec3 t;
    Vec3 *toTarget;
    Vec3 *pos;
    Vec3 *velocity;
    Kart *kart;
    s32 s;

    kart = item->mKartItems->mKart;
    item->mUnk_22c = kart->mSignedTurnedForward;
    pos = &item->mUnk_000.mPos;
    velocity = &item->mUnk_000.mVelocity;
    toTarget = &item->mUnk_238;
    if (kart->mUnk_44 & 0x100) {
        item->mUnk_22c.x = -item->mUnk_22c.x;
        item->mUnk_22c.y = -item->mUnk_22c.y;
        item->mUnk_22c.z = -item->mUnk_22c.z;
    }
    Vec3CrossUnrounded(&item->mUnk_22c, &kart->mGroundNormal, &t);
    s = ((s64) radius * gPairsByAngle[(angle >> 4) * 2 + 1]) >> 12;
    item->mUnk_250.x = ((s64) t.x * s) >> 12;
    item->mUnk_250.y = ((s64) t.y * s) >> 12;
    item->mUnk_250.z = ((s64) t.z * s) >> 12;
    s = ((s64) radius * gPairsByAngle[(angle >> 4) * 2]) >> 12;
    VEC_MultAdd(s, &item->mUnk_22c, &item->mUnk_250, &item->mUnk_250);
    VEC_MultAdd(0x1e000, &item->mUnk_22c, &item->mUnk_250, &t);
    if (func_0206c0b0(kart) == FALSE) {
        item->mUnk_244 = kart->mDrawMatrixPos;
    }
    VEC_Add(&t, &item->mUnk_244, &t);
    VEC_Subtract(&t, pos, toTarget);
    t.x = ((s64) toTarget->x * gain) >> 12;
    t.y = ((s64) toTarget->y * gain) >> 12;
    t.z = ((s64) toTarget->z * gain) >> 12;
    if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= (s64) maxStep * maxStep) {
        if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&t, &t);
        }
        t.x = ((s64) t.x * maxStep) >> 12;
        t.y = ((s64) t.y * maxStep) >> 12;
        t.z = ((s64) t.z * maxStep) >> 12;
    }
    velocity->x = (velocity->x * (s32) oldWeight + t.x) >> shift;
    velocity->y = (velocity->y * (s32) oldWeight + t.y) >> shift;
    velocity->z = (velocity->z * oldWeight + t.z) >> shift;
    VEC_Add(velocity, pos, pos);
    if (func_01ffdee4(pos, &item->mUnk_000.mPrevPos, 0, item->mUnk_000.mUnk_dc, 4, item->mUnk_000.mCollisionSlotIndex,
                      &t, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == 0) {
        return;
    }
    if ((kart->mUnk_48 & 1) == 0) {
        pos->y += t.y;
        return;
    }
    VEC_Add(pos, &t, pos);
}
