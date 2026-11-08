#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020f1000.h"
#include "Main/Unknown/code_020f2000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02134398.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02077bc0.h"

#pragma thumb on
#pragma optimize_for_size on

void *FindItemFile(u8 *fileName) {
    char buf[0x100];

    if (fileName == NULL) {
        return NULL;
    }
    snprintf(buf, 0x100, gItemFileFormat, fileName);
    return FindMainRaceOrMainEffectFile(buf);
}

NsbmdModel *CreateItemModel(u8 *modelName, u8 *animationName, u8 *textureName) {
    NsbmdModel *model;
    void *modelFile;
    void *animationFile;

    model = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    modelFile = FindItemFile(modelName);
    animationFile = FindItemFile(animationName);
    func_020e64b8(model, modelFile, animationFile, 0);
    model->mUnk_14 &= 0xc0ffffff;
    model->mUnk_14 |= 0x04000000;
    model->mUnk_14 &= ~0xf;
    model->mUnk_14 |= 0x2;
    model->mUnk_10 &= 0x8000ffff;
    model->mUnk_10 |= 0x10840000;
    return model;
}

void *CreateItemNsbmd(u8 *modelName, u8 *textureName) {
    void *model;
    void *modelFile;

    model = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x6c);
    modelFile = FindItemFile(modelName);
    InitNsbmd(model, modelFile);
    func_02084968(model, 4, 2, 0x294a);
    return model;
}

void CreateItemModels(void) {
    enum { K0 } i;
    ItemKind *itemKind;
    BOOL isRainbowCourse;

    i = 0;
    while (i < 0xe) {
        gItemModels[i] = NULL;
        i++;
    }
    gItemModels[0] = CreateItemModel(gItemKouraGNsbmdName, NULL, gItemKouraGNsbtxName);
    gItemModels[1] = CreateItemModel(gItemKouraRNsbmdName, NULL, gItemKouraRNsbtxName);
    gItemModels[2] = CreateItemModel(gItemBananaNsbmdName, NULL, gItemBananaNsbtxName);
    gItemModels[3] = CreateItemModel(gItemKinokoNsbmdName, NULL, gItemKinokoNsbtxName);
    gItemModels[4] = CreateItemModel(gItemStarNsbmdName, NULL, gItemStarNsbtxName);
    gItemModels[5] = CreateItemModel(gItemKouraWNsbmdName, NULL, gItemKouraWNsbtxName);
    gItemModels[6] = CreateItemModel(gItemThunderNsbmdName, NULL, gItemThunderNsbtxName);
    gItemModels[7] = CreateItemModel(gItemFBoxNsbmdName, NULL, gItemFBoxNsbtxName);
    gItemModels[9] = CreateItemModel(gItemBombNsbmdName, gItemBombNsbtpName, gItemBombNsbtxName);
    gItemModels[10] = CreateItemModel(gItemGessoNsbmdName, NULL, gItemGessoNsbtxName);
    gItemModels[11] = CreateItemModel(gItemTeresaNsbmdName, NULL, gItemTeresaNsbtxName);
    gItemModels[12] = CreateItemModel(gItemKinokoPNsbmdName, NULL, gItemKinokoPNsbtxName);
    gItemModels[13] = CreateItemModel(gItemKillerNsbmdName, NULL, gItemKillerNsbtxName);
    gItemModels[8] = gItemModels[7];
    isRainbowCourse = (gRaceSetup->mCourseId == COURSE_ID_RAINBOW);
    i = 0;
    while (i < 0xe) {
        itemKind = &gItemKinds[i];
        if (itemKind->mSetup != NULL) {
            itemKind->mSetup();
        }
        if (isRainbowCourse != FALSE) {
            gItemModels[i]->mUnk_14 &= 0xffff7fff;
        }
        i++;
    }
}

#pragma optimize_for_size off
#pragma thumb off

void InitLinkFollowingItemFromInUse(LinkFollowingItemObject *follower, ItemInUse *inUse, s32 rampCount,
                                    s32 rampWeightPerCount, s32 throwForward, s32 d, s32 endsOnFirstHit, s32 baseSpeed,
                                    u16 targetKartIndex, s32 h) {
    InitItemObjectThrow(follower, inUse, (endsOnFirstHit == 0) ? -1 : 0, throwForward, d, baseSpeed);
    follower->mRampTimer = rampCount;
    follower->mUnk_218 = rampWeightPerCount;
    follower->mPreviousLink = inUse->mKartItems->mUnk_1f0;
    PickNextItemPointLink(&follower->mPreviousLink, &follower->mTargetLink, targetKartIndex, h);
    follower->mUnk_224 = 0;
}

BOOL func_020ed0f4(LinkFollowingItemObject *follower) {
    Vec3 vectors[6];
    Vec3 *direction;
    Vec3 *pos;
    s32 alignment;
    s32 alongDirection;

    pos = &follower->mUnk_000.mUnk_000.mPos;
    direction = &follower->mUnk_000.mDirection;
    VEC_Subtract(follower->mTargetLink.mLink->mPointPos, pos, &vectors[0]);
    if ((s64) vectors[0].x * vectors[0].x + (s64) vectors[0].y * vectors[0].y + (s64) vectors[0].z * vectors[0].z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&vectors[0], &vectors[1]);
    }
    alignment = Vec3DotUnrounded(direction, &vectors[1]);
    if (alignment > 0xddb || follower->mUnk_000.mUnk_158 != 0) {
        vectors[0].x >>= 2;
        vectors[0].y >>= 2;
        vectors[0].z >>= 2;
        alongDirection = VEC_DotProduct(direction, &vectors[0]);
        vectors[1].x = ((u64) ((s64) direction->x * alongDirection)) >> 12;
        vectors[1].y = ((u64) ((s64) direction->y * alongDirection)) >> 12;
        vectors[1].z = ((u64) ((s64) direction->z * alongDirection)) >> 12;
        VEC_Add(&vectors[0], &vectors[1], &vectors[0]);
        VEC_Subtract(pos, &vectors[1], &vectors[2]);
        vectors[3] = *pos;
        VEC_Add(pos, &vectors[0], &vectors[4]);
        vectors[5] = *follower->mTargetLink.mLink->mPointPos;
        InitSegmentPoints(&follower->mSegmentPoints, &vectors[2], follower->mUnk_000.mSpeed);
        return TRUE;
    }
    return FALSE;
}

void func_020ece1c(LinkFollowingItemObject *follower, s32 targetSpeed, s32 targetKartIndex, s32 c) {
    Vec3 toLink;
    Vec3 *direction;
    Vec3 *surfaceDirection;
    Vec3 *sideDirection;
    s32 n;
    s32 s;

    AdvanceItemObjectMotion(&follower->mUnk_000, targetSpeed);
    if (follower->mUnk_000.mUnk_158 != 0 && (follower->mUnk_000.mUnk_000.mFlags & 0x20000) != 0) {
        n = GetKart((u16) (follower->mUnk_000.mUnk_000.mUnk_78 & ~0xff00))->mDrawMatrixPos.y + 0x1e000;
        if (follower->mUnk_000.mUnk_000.mPos.y < n) {
            follower->mUnk_000.mUnk_000.mPos.y = n;
        }
    }
    if (follower->mUnk_000.mUnk_000.mFlags & 1) {
        return;
    }
    if (follower->mUnk_000.mUnk_158 == 0) {
        if (follower->mUnk_000.mUnk_000.mFlags & 0x20000) {
            return;
        }
    }
    direction = &follower->mUnk_000.mDirection;
    surfaceDirection = &follower->mUnk_000.mSurfaceDirection;
    if (CopyCloserItemPointLinkRef(&follower->mPreviousLink, &follower->mTargetLink, &follower->mPreviousLink,
                                   &follower->mUnk_000.mUnk_000.mPos) != FALSE) {
        PickNextItemPointLink(&follower->mPreviousLink, &follower->mTargetLink, targetKartIndex, c);
    }
    VEC_Subtract(follower->mTargetLink.mLink->mPointPos, &follower->mUnk_000.mUnk_000.mPos, &toLink);
    if (follower->mUnk_000.mUnk_000.mFlags & 0x40000000) {
        s = VEC_DotProduct(surfaceDirection, &toLink);
        toLink.x -= (s32) (((u64) ((s64) surfaceDirection->x * s)) >> 12);
        toLink.y -= (s32) (((u64) ((s64) surfaceDirection->y * s)) >> 12);
        toLink.z -= (s32) (((u64) ((s64) surfaceDirection->z * s)) >> 12);
        s = VEC_DotProduct(&follower->mUnk_000.mUnk_000.mNormal, &toLink);
        toLink.x -= (s32) (((u64) ((s64) follower->mUnk_000.mUnk_000.mNormal.x * s)) >> 12);
        toLink.y -= (s32) (((u64) ((s64) follower->mUnk_000.mUnk_000.mNormal.y * s)) >> 12);
        toLink.z -= (s32) (((u64) ((s64) follower->mUnk_000.mUnk_000.mNormal.z * s)) >> 12);
        VEC_MultAdd(0x29, &toLink, &follower->mUnk_000.mUnk_000.mPos, &follower->mUnk_000.mUnk_000.mPos);
        VEC_MultAdd(0x3, &toLink, surfaceDirection, surfaceDirection);
        return;
    }
    if (Vec3DotUnrounded(surfaceDirection, &toLink) < 0) {
        sideDirection = &follower->mUnk_000.mSideDirection;
        Vec3CrossUnrounded(surfaceDirection, &follower->mUnk_000.mUnk_000.mNormal, sideDirection);
        if (Vec3DotUnrounded(sideDirection, &toLink) > 0) {
            toLink = *sideDirection;
        } else {
            toLink.x = -sideDirection->x;
            toLink.y = -sideDirection->y;
            toLink.z = -sideDirection->z;
        }
        follower->mUnk_224 = 1;
    }
    if ((s64) toLink.x * toLink.x + (s64) toLink.y * toLink.y + (s64) toLink.z * toLink.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&toLink, &toLink);
    }
    s = 0x1000 - follower->mRampTimer * follower->mUnk_218;
    n = (follower->mUnk_224 != 0) ? 0x266 : 0x148;
    func_020eacc0(direction, ((u64) ((s64) n * s)) >> 12, &toLink, &toLink);
    SetItemObjectDirection(follower, &toLink);
}

void func_020ec9c0(LinkFollowingItemObject *follower, s32 targetSpeed, s32 speedEase, s32 targetKartIndex, s32 e) {
    SegmentPoints *segmentPoints;
    Vec3 *pos;
    Vec3 *velocity;
    Vec3 v28;
    Vec3 hitNormal;
    Vec3 wallNormal;
    Vec3 v4c;
    s32 s;
    BOOL f;
    s32 alongNormal;

    segmentPoints = &follower->mSegmentPoints;
    pos = &follower->mUnk_000.mUnk_000.mPos;
    velocity = &follower->mUnk_000.mUnk_000.mVelocity;
    f = (follower->mUnk_000.mUnk_000.mFlags & 0x40000000) != 0;
    targetSpeed -= follower->mUnk_000.mSpeed;
    follower->mUnk_000.mSpeed = follower->mUnk_000.mSpeed + (s32) (((u64) ((s64) targetSpeed * speedEase)) >> 12);
    SetSegmentProgressRate(&segmentPoints->mUnk_00, follower->mUnk_000.mSpeed);
    if (AdvanceSegmentProgress(&segmentPoints->mUnk_00) != FALSE) {
        do {
            follower->mPreviousLink = follower->mTargetLink;
            PickNextItemPointLink(&follower->mPreviousLink, &follower->mTargetLink, targetKartIndex, e);
        } while (PushSegmentPoint(segmentPoints, follower->mTargetLink.mLink->mPointPos) != 0);
    }
    if (f) {
        v4c = *pos;
        GetSegmentProgressPoint(segmentPoints, pos);
        velocity->y = 0;
        if (follower->mUnk_000.mUnk_158 == 0) {
            VEC_Subtract(pos, &v4c, &v4c);
            alongNormal = Vec3DotUnrounded(&v4c, &follower->mUnk_000.mUnk_000.mNormal);
            if (alongNormal > 0) {
                VEC_MultAdd(-alongNormal, &follower->mUnk_000.mUnk_000.mNormal, pos, pos);
            }
        }
    } else {
        if (follower->mUnk_000.mUnk_158 != 0 && (follower->mUnk_000.mUnk_000.mFlags & 0x20000) != 0) {
            v28.y = pos->y;
            GetSegmentProgressPointXzLinearY(segmentPoints, pos);
            if (pos->y < v28.y) {
                pos->y = v28.y;
            }
        } else {
            GetSegmentProgressPointXz(&segmentPoints->mUnk_00, pos);
        }
        pos->y = pos->y + velocity->y;
    }
    if (func_01ffdee4(pos, &follower->mUnk_000.mUnk_000.mPrevPos, 0, follower->mUnk_000.mUnk_000.mUnk_dc, 4,
                      follower->mUnk_000.mUnk_000.mCollisionSlotIndex, &v28, &hitNormal, (s32 *) &wallNormal,
                      &follower->mUnk_000.mUnk_000.mCollisionBits, NULL, NULL, NULL, NULL) != 0) {
        if (follower->mUnk_000.mUnk_158 != 0) {
            if (v28.y > 0) {
                pos->y = pos->y + v28.y;
            }
        } else {
            VEC_Add(&v28, pos, pos);
        }
        if (follower->mUnk_000.mUnk_000.mCollisionBits & 0x1e34ef) {
            s = VEC_DotProduct(&hitNormal, velocity);
            velocity->x -= (s32) (((u64) ((s64) hitNormal.x * s)) >> 12);
            velocity->y -= (s32) (((u64) ((s64) hitNormal.y * s)) >> 12);
            velocity->z -= (s32) (((u64) ((s64) hitNormal.z * s)) >> 12);
            s = (hitNormal.x == follower->mUnk_000.mUnk_000.mNormal.x &&
                 hitNormal.y == follower->mUnk_000.mUnk_000.mNormal.y &&
                 hitNormal.z == follower->mUnk_000.mUnk_000.mNormal.z)
                    ? 1
                    : 0;
            if (s == 0) {
                follower->mUnk_000.mUnk_000.mNormal = hitNormal;
                follower->mUnk_000.mUnk_000.mFlags |= 0x100;
            }
        }
        if ((follower->mUnk_000.mUnk_000.mCollisionBits & 0x214300) != 0 && follower->mUnk_000.mHasHitLimit != FALSE) {
            s = VEC_DotProduct(&wallNormal, velocity);
            v28.x = ((u64) ((s64) wallNormal.x * s)) >> 12;
            v28.y = ((u64) ((s64) wallNormal.y * s)) >> 12;
            v28.z = ((u64) ((s64) wallNormal.z * s)) >> 12;
            velocity->x -= v28.x;
            velocity->y -= v28.y;
            velocity->z -= v28.z;
            VEC_Subtract(velocity, &v28, velocity);
            velocity->x = ((u64) ((s64) velocity->x * 0x23d)) >> 12;
            velocity->y = ((u64) ((s64) velocity->y * 0x23d)) >> 12;
            velocity->z = ((u64) ((s64) velocity->z * 0x23d)) >> 12;
            func_020f6fc4(follower, 1);
            return;
        }
        if (follower->mUnk_000.mUnk_000.mCollisionBits & 0x8000) {
            if (follower->mUnk_000.mUnk_000.mKind != 5) {
                func_020f7070(follower, 1);
                return;
            }
        }
    }
    ApplyItemObjectGravity(follower);
    velocity->x = pos->x - follower->mUnk_000.mUnk_000.mPrevPos.x;
    velocity->z = pos->z - follower->mUnk_000.mUnk_000.mPrevPos.z;
}

void AdvanceLinkFollowingItem(LinkFollowingItemObject *follower, s32 targetSpeed, s32 speedEase, s32 targetKartIndex,
                              s32 d) {
    if (follower->mRampTimer >= 0) {
        func_020ece1c(follower, targetSpeed, targetKartIndex, d);
        if (follower->mRampTimer == 0) {
            if (func_020ed0f4(follower) != FALSE) {
                follower->mRampTimer = -1;
            }
            return;
        }
        if (follower->mUnk_000.mUnk_000.mFlags & 0x40020000) {
            if (follower->mUnk_000.mUnk_158 == 0) {
                return;
            }
        }
        follower->mRampTimer -= 1;
    } else {
        func_020ec9c0(follower, targetSpeed, speedEase, targetKartIndex, d);
    }
}

void InitLinkFollowingItem(LinkFollowingItemObject *follower, s32 rampCount, s32 rampWeightPerCount, s32 c,
                           s32 endsOnFirstHit, s32 reverse, u16 targetKartIndex, s32 g) {
    InitItemObjectMotion(follower, (endsOnFirstHit == 0) ? -1 : 0, reverse, c);
    follower->mRampTimer = rampCount;
    follower->mUnk_218 = rampWeightPerCount;
    PickNextItemPointLink(&follower->mPreviousLink, &follower->mTargetLink, targetKartIndex, g);
    follower->mUnk_224 = 0;
}
