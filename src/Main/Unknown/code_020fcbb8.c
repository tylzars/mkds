#include "Main/Unknown/code_020fcbb8.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020fcf10.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02077bc0.h"

void SteerItemKouraWToNextAnglePoint(ItemKouraW *item, s32 gain, s32 maxStep, s32 radius, u16 angleStep) {
    item->mAngle += angleStep;
    SteerItemKouraWToAnglePoint(item, maxStep, (u16) item->mAngle, radius, gain, 1, 1);
}

void SteerItemKouraWToKartForward(ItemKouraW *item, s32 gain, s32 lift) {
    Vec3 v;
    s32 flagBit0;
    Vec3 *pos;
    Vec3 *velocity;
    Kart *kart;

    kart = item->mKartItems->mKart;
    flagBit0 = (kart->mUnk_48 & 1) ? 1 : 0;
    item->mUnk_22c = kart->mSignedTurnedForward;
    pos = &item->mUnk_000.mPos;
    velocity = &item->mUnk_000.mVelocity;
    if (kart->mUnk_44 & 0x100) {
        item->mUnk_22c.x = -item->mUnk_22c.x;
        item->mUnk_22c.y = -item->mUnk_22c.y;
        item->mUnk_22c.z = -item->mUnk_22c.z;
    }
    if (func_0206c0b0(kart) == FALSE) {
        item->mUnk_244 = kart->mDrawMatrixPos;
    }
    VEC_MultAdd(0x14ffa, &item->mUnk_22c, &item->mUnk_244, &v);
    if (flagBit0 == 0) {
        v.y += lift;
    } else {
        VEC_MultAdd(lift, &kart->mGroundNormal, &v, &v);
    }
    VEC_Subtract(&v, pos, &v);
    velocity->x = ((s64) v.x * gain) >> 12;
    velocity->y = ((s64) v.y * gain) >> 12;
    velocity->z = ((s64) v.z * gain) >> 12;
    VEC_Add(velocity, pos, pos);
    if (flagBit0 == 0) {
        return;
    }
    if (func_01ffdee4(pos, &item->mUnk_000.mPrevPos, 0, item->mUnk_000.mUnk_dc, 4, item->mUnk_000.mCollisionSlotIndex,
                      &v, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == 0) {
        return;
    }
    VEC_Add(pos, &v, pos);
}

BOOL TrySetItemKouraWKartItems(ItemKouraW *item, s32 kartIndex) {
    Kart *kart;
    KartItems *kartItems;
    Vec3 v;
    Vec3 *kartPos;
    s32 shortRange;
    s32 normalDistance;
    s32 offsetX;
    s32 offsetZ;

    kart = GetKart(kartIndex);
    if (func_0206c0b0(kart) != FALSE) {
        return FALSE;
    }
    kartItems = &(gKartItems)[kartIndex];
    kartPos = &kart->mDrawMatrixPos;
    if (kartItems->mUnk_1f0.mLink != item->mUnk_168) {
        shortRange = ((item->mUnk_000.mFlags & 0x40000000) || (kart->mUnk_48 & 1)) ? 1 : 0;
        VEC_Subtract(kartPos, &item->mUnk_000.mPos, &v);
        offsetX = v.x >> 12;
        offsetZ = v.z >> 12;
        if (offsetX * offsetX + offsetZ * offsetZ > (shortRange ? 0x9c40 : 0x27100)) {
            return FALSE;
        }
        normalDistance = Vec3DotUnrounded(&item->mUnk_000.mUnk_f0, &v) >> 12;
        if (normalDistance * normalDistance > 0x9c4) {
            return FALSE;
        }
    }
    if (item->mUnk_000.mFlags & 0x10000000) {
        return FALSE;
    }
    item->mKartItems = kartItems;
    item->mUnk_244 = *kartPos;
    return TRUE;
}
