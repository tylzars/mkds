#include "Main/Unknown/code_020f9c6c.h"
#include "code_02012b30.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020fe450.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1a24.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020fcbb8.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01fff000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020fc000.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01fff434.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fcb9c.h"
#include "Main/Unknown/code_020fcedc.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f2000.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020fd254.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"

void func_020fcb30(ItemKouraW *item) {
    item->mUnk_170 = 1;
}

void ResetItemKouraW(ItemKouraW *item) {
    InitStateMachine(&item->mUnk_2e8, (UnkFunc *const *) gItemKouraWStateTable, 8, item);
    MTX_Identity43_((MtxFx43 *) item->mUnk_2b4);
    item->mRank = 1;
    item->mRankKartIndex = gRaceProgress->mKartAtRank[0];
    item->mUnk_278 = 0;
    item->mPosStrip = NULL;
    item->mSoundId = 0xdc;
    item->mKartMask = 0;
    item->mHitSpinsKart = 0;
}

void func_020fc94c(ItemKouraW *item) {
    ResetSoundDistanceSquaredChange(&item->mUnk_300);
    item->mUnk_000.mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) func_0210a67c;
    item->mUnk_160 = 0;
    item->mUnk_000.mDrawPos = item->mUnk_000.mPos;
    FreeItemObjectCollisionSlot((s32) item);
    item->mUnk_000.mFlags |= 0x200000;
    ClearItemKouraWKartItemsAndAngle(item);
    if (gRaceProgress->mRaceDone != 0) {
        item->mRank = 1;
        item->mRankKartIndex = gRaceProgress->mKartAtRank[(item->mRank & 0xff) - 1];
    } else {
        item->mRankKartIndex = gRaceProgress->mKartAtRank[(item->mRank & 0xff) - 1];
        while (IsKartEnded(item->mRankKartIndex) != 0 && item->mRank < (u32) gRaceSetup->mKartCount) {
            item->mRank++;
            item->mRankKartIndex = gRaceProgress->mKartAtRank[(item->mRank & 0xff) - 1];
        }
    }
    item->mUnk_260 = 0x32000;
    item->mUnk_264 = 0xf000;
    item->mDrawOffsetAngle = 0;
    item->mUnk_27c = 0x1a000;
    item->mUnk_298.x = 0;
    item->mUnk_298.y = 0;
    item->mUnk_298.z = 0;
    VEC_Subtract(&item->mUnk_000.mVelocity, &item->mUnk_298, &item->mUnk_28c);
    item->mUnk_000.mUnk_d0 = &item->mUnk_000.mDrawPos;
    InitCourseColorBlend(&item->mUnk_000.mColorBlend, 1);
}

void SetItemKouraWKartItemsAndStateIfNone(ItemKouraW *item, s32 kartIndex) {
    Kart *kart;

    if (item->mKartItems != NULL) {
        return;
    }
    SetItemKouraWKartItems(item, kartIndex);
    kart = item->mKartItems->mKart;
    item->mNextState = ((item->mUnk_000.mFlags & 0x40000000) || (kart->mUnk_48 & 1)) ? 2 : 3;
    item->mNextStateRequested = 1;
}

s32 InitItemKouraW(ItemInUse *itemInUse, ItemKouraW *item) {
    Kart *kart;

    func_020f9114(item);
    if (itemInUse->mKartItems->mUnk_1f0.mLink != NULL) {
        InitLinkFollowingItemFromInUse((LinkFollowingItemObject *) item, itemInUse, 0x14, 0xcc, 1, 1, 0, 0x6000,
                                       item->mRankKartIndex, 1);
        SetStateMachineState(item->mUnk_2e8, 1);
    } else {
        SetItemKouraWKartItems(item, (u16) gRaceProgress->mKartAtRank[0]);
        kart = item->mKartItems->mKart;
        item->mNextState = ((item->mUnk_000.mFlags & 0x40000000) || (kart->mUnk_48 & 1)) ? 2 : 3;
        item->mNextStateRequested = 1;
        if (item->mUnk_000.mFlags & 0x8000000) {
            func_020fe71c(5, item->mKartItems->mKartIndex, item->mUnk_000.mId);
        }
    }
    func_020fc94c(item);
    // one 36-byte copy of the three vectors (three Vec3 assignments give 0x160 bytes against 0x150)
    *(MtxFx33 *) &item->mUnk_000.mUnk_94 = *(MtxFx33 *) &itemInUse->mKartOrientation.mUnk_00;
    if (item->mUnk_000.mFlags & 0x8000000) {
        item->mNextState = 0;
        item->mNextStateRequested = 1;
    }
    return 1;
}

void UpdateItemKouraWDrawPos(ItemKouraW *item) {
    Vec3 buf;
    s16 v;
    s32 a;

    a = item->mUnk_260;
    if (item->mUnk_000.mFlags & 0x40000000) {
        item->mDrawOffsetAngle += 0x5dc;
        v = gPairsByAngle[(item->mDrawOffsetAngle >> 4) * 2];
        VEC_MultAdd(a + (s32) (((s64) item->mUnk_264 * v) >> 12), &item->mUnk_000.mNormal, &item->mUnk_000.mPos, &buf);
        VEC_Subtract(&buf, &item->mUnk_000.mDrawPos, &buf);
        VEC_MultAdd(0x333, &buf, &item->mUnk_000.mDrawPos, &item->mUnk_000.mDrawPos);
    } else {
        item->mUnk_000.mDrawPos.y += item->mUnk_000.mVelocity.y >> 1;
        item->mDrawOffsetAngle += 0x5dc;
        v = gPairsByAngle[(item->mDrawOffsetAngle >> 4) * 2];
        a += (s32) (((s64) item->mUnk_264 * v) >> 12);
        a = a + item->mUnk_000.mPos.y - item->mUnk_000.mDrawPos.y;
        item->mUnk_000.mDrawPos.y += (s32) (((s64) a * 0x19a) >> 12);
        item->mUnk_000.mDrawPos.x = item->mUnk_000.mPos.x;
        item->mUnk_000.mDrawPos.z = item->mUnk_000.mPos.z;
    }
}

void UpdateItemKouraWOrientation(ItemKouraW *item, Vec3 *direction, s32 followDelta, Vec3 *normal) {
    Vec3 buf;
    Vec3 v3;
    Vec3 *previousDirection = &item->mUnk_28c;
    Vec3 *smoothedDelta = &item->mUnk_298;
    s32 ok;

    if (normal != NULL) {
        if ((s64) direction->x * direction->x + (s64) direction->y * direction->y + (s64) direction->z * direction->z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(direction, &item->mUnk_000.mUnk_94.mUnk_00[2]);
        }
        smoothedDelta->x = ((s64) smoothedDelta->x * 0xccd) >> 12;
        smoothedDelta->y = ((s64) smoothedDelta->y * 0xccd) >> 12;
        smoothedDelta->z = ((s64) smoothedDelta->z * 0xccd) >> 12;
        VEC_MultAdd(0x3000, smoothedDelta, normal, &buf);
        Vec3CrossUnrounded(&buf, &item->mUnk_000.mUnk_94.mUnk_00[2], &buf);
        if ((s64) buf.x * buf.x + (s64) buf.y * buf.y + (s64) buf.z * buf.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&buf, &item->mUnk_000.mUnk_94.mUnk_00[0]);
        }
    } else {
        if ((s64) direction->x * direction->x + (s64) direction->y * direction->y + (s64) direction->z * direction->z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(direction, &buf);
        }
        if (buf.x * buf.x + buf.z * buf.z < 0x112510) {
            return;
        }
        item->mUnk_000.mUnk_94.mUnk_00[2] = buf;
        if (followDelta != 0) {
            smoothedDelta->x += (s32) (((s64) (direction->x - previousDirection->x - smoothedDelta->x) * 0x148) >> 12);
            smoothedDelta->z += (s32) (((s64) (direction->z - previousDirection->z - smoothedDelta->z) * 0x148) >> 12);
        } else {
            smoothedDelta->x = ((s64) smoothedDelta->x * 0xc00) >> 12;
            smoothedDelta->z = ((s64) smoothedDelta->z * 0xc00) >> 12;
        }
        v3 = data_0216c6a8;
        v3.x = ((s64) smoothedDelta->x * 0x3000) >> 12;
        v3.z = ((s64) smoothedDelta->z * 0x3000) >> 12;
        buf = v3;
        Vec3CrossUnrounded(&buf, &item->mUnk_000.mUnk_94.mUnk_00[2], &item->mUnk_000.mUnk_94.mUnk_00[0]);
        if ((s64) item->mUnk_000.mUnk_94.mUnk_00[0].x * item->mUnk_000.mUnk_94.mUnk_00[0].x +
                (s64) item->mUnk_000.mUnk_94.mUnk_00[0].y * item->mUnk_000.mUnk_94.mUnk_00[0].y +
                (s64) item->mUnk_000.mUnk_94.mUnk_00[0].z * item->mUnk_000.mUnk_94.mUnk_00[0].z >=
            0x10) {
            ok = Vec3NormalizeAndGetLengthUnchecked(&item->mUnk_000.mUnk_94.mUnk_00[0],
                                                    &item->mUnk_000.mUnk_94.mUnk_00[0]);
        } else {
            ok = 0;
        }
        if (ok == 0) {
            Vec3 t = {0, 0, 0};
            t.x = item->mUnk_000.mUnk_94.mUnk_00[0].z;
            t.z = -item->mUnk_000.mUnk_94.mUnk_00[0].x;
            item->mUnk_000.mUnk_94.mUnk_00[0] = t;
        }
    }
    Vec3CrossUnrounded(&item->mUnk_000.mUnk_94.mUnk_00[2], &item->mUnk_000.mUnk_94.mUnk_00[0],
                       &item->mUnk_000.mUnk_94.mUnk_00[1]);
    *previousDirection = *direction;
}

void AdvanceItemKouraW(ItemKouraW *item) {
    AdvanceStateMachine(item->mUnk_2e8);
    func_020f9320(&item->mUnk_000, 0x3c000400u);
}

#pragma thumb off

void UpdateItemKouraWState0(ItemKouraW *item) {
    AdvanceItemObjectMotion((DirectedItemObject *) item, 0xd000);
    if (item->mUnk_000.mFlags & 1) {
        return;
    }
    AdvanceSoundDistanceSquaredChange(&item->mUnk_300, item->mUnk_000.mDistanceSquaredAndFlags & ~0xc000001f);
    if (item->mSoundId == 1) {
        return;
    }
    StartSoundWhileRequested(&item->mUnk_000.mSoundSource, item->mSoundId, 0x7f, 0);
}

static inline Vec3 *func_020fbd98_inline(ItemKouraW *item) {
    if (item->mState >= 3) {
        if (item->mKartItems->mKart->mUnk_48 & 1) {
            return &item->mKartItems->mKart->mGroundNormal;
        }
    } else if (item->mUnk_000.mFlags & 0x40000000) {
        return &item->mUnk_000.mNormal;
    }
    return NULL;
}

void UpdateItemKouraWState1(ItemKouraW *item) {
    u32 i;
    s32 r;
    s32 v;
    void *normal;
    Kart *kart;

    if (item->mStateFrames == 8) {
        item->mPosStrip = StartPosStrip(item->mUnk_000.mUnk_d0);
    }
    AdvanceLinkFollowingItem((LinkFollowingItemObject *) item, item->mUnk_27c, 0x21, item->mRankKartIndex, 1);
    if (!(item->mUnk_000.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(&item->mUnk_300, item->mUnk_000.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mUnk_000.mSoundSource, item->mSoundId, 0x7f, 0);
        }
    }
    item->mUnk_000.mVelocity.y -= (s32) (((s64) * (s32 *) item->mUnk_12c * 0x66) >> 12);
    if (item->mUnk_000.mFlags & 1) {
        return;
    }
    UpdateItemKouraWDrawPos(item);
    normal = func_020fbd98_inline(item);
    UpdateItemKouraWOrientation(item, &item->mUnk_000.mVelocity, 1, normal);
    if (item->mUnk_278 == 0) {
        if (gRaceProgress->mRaceDone != 0) {
            item->mRank = 1;
            item->mRankKartIndex = gRaceProgress->mKartAtRank[(u8) item->mRank - 1];
        } else {
            item->mRankKartIndex = gRaceProgress->mKartAtRank[(u8) item->mRank - 1];
            while (IsKartEnded(item->mRankKartIndex) != 0 && (u32) item->mRank < gRaceSetup->mKartCount) {
                (item->mRank)++;
                item->mRankKartIndex = gRaceProgress->mKartAtRank[(u8) item->mRank - 1];
            }
        }
        if (item->mRankKartIndex ==
                (u16) (!(item->mUnk_000.mUnk_78 & 0x8000) ? (u16) (item->mUnk_000.mUnk_78 & ~0xff00) : 8) ||
            func_02068eac(GetKart(item->mRankKartIndex)) != 0) {
            item->mUnk_278 = 1;
        } else {
            item->mKartMask |= 1 << item->mRankKartIndex;
        }
    }
    if (item->mUnk_278 != 0) {
        u32 kartCount;
        kartCount = (u8) gRaceSetup->mKartCount;
        for (i = 1; i <= kartCount; i = (u16) (i + 1)) {
            item->mRankKartIndex = gRaceProgress->mKartAtRank[(u8) i - 1];
            if (func_02068eac(GetKart(item->mRankKartIndex)) == 0) {
                break;
            }
        }
        item->mKartMask |= 1 << item->mRankKartIndex;
    }
    if (TrySetItemKouraWKartItems(item, item->mRankKartIndex) != 0) {
        kart = item->mKartItems->mKart;
        r = ((item->mUnk_000.mFlags & 0x40000000) || (kart->mUnk_48 & 1)) ? 2 : 3;
        item->mNextState = r;
        item->mNextStateRequested = 1;
        if (item->mUnk_000.mFlags & 0x8000000) {
            func_020fe71c(5, item->mKartItems->mKartIndex, item->mUnk_000.mId);
        }
        return;
    }
    r = (u16) GetRaceUpdateFramesMod8();
    if ((item->mKartMask & (1 << r)) != 0 && item->mRankKartIndex != r && IsKartEnded(r) != 0 &&
        TrySetItemKouraWKartItems(item, r) != 0) {
        kart = item->mKartItems->mKart;
        v = ((item->mUnk_000.mFlags & 0x40000000) || (kart->mUnk_48 & 1)) ? 2 : 3;
        item->mNextState = v;
        item->mNextStateRequested = 1;
        if (item->mUnk_000.mFlags & 0x8000000) {
            func_020fe71c(5, item->mKartItems->mKartIndex, item->mUnk_000.mId);
        }
        return;
    }
    if (item->mStateFrames <= 0xa8c) {
        return;
    }
    v = (u16) gRaceProgress->mKartAtRank[0];
    if (item->mKartItems != NULL) {
        return;
    }
    if ((u32) v >= 8) {
        v = 0;
    }
    SetItemKouraWKartItems(item, (u16) v);
    kart = item->mKartItems->mKart;
    r = ((item->mUnk_000.mFlags & 0x40000000) || (kart->mUnk_48 & 1)) ? 2 : 3;
    item->mNextState = r;
    item->mNextStateRequested = 1;
}

void EnterItemKouraWState3(ItemKouraW *item) {
    item->mUnk_27c = VEC_Mag(&item->mUnk_000.mVelocity);
    item->mUnk_284 = 0x1e000;
    if (item->mKartItems->mKartIndex == gRaceSetup->mEntryIndex) {
        item->mSoundId = 0xdd;
    }
}

void UpdateItemKouraWState3(ItemKouraW *item) {
    s32 r;
    void *normal;
    Kart *kart;

    kart = item->mKartItems->mKart;
    r = 0x800;
    if ((item->mUnk_000.mFlags & 0x10000000) && (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        r += 0x19a;
    }
    if (item->mUnk_27c > 0xd000) {
        item->mUnk_27c -= 0xccd;
    } else {
        item->mUnk_27c += 0xccd;
    }
    SteerItemKouraWAtAngleZero(item, r, item->mUnk_27c, item->mUnk_284);
    if (!(item->mUnk_000.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(&item->mUnk_300, item->mUnk_000.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mUnk_000.mSoundSource, item->mSoundId, 0x7f, 0);
        }
    }
    if ((s64) item->mUnk_238.x * item->mUnk_238.x + (s64) item->mUnk_238.z * item->mUnk_238.z < 0x1900000000LL) {
        item->mNextState = 4;
        item->mNextStateRequested = 1;
    }
    UpdateItemKouraWDrawPos(item);
    normal = func_020fbd98_inline(item);
    UpdateItemKouraWOrientation(item, &item->mUnk_000.mVelocity, 1, normal);
}

void UpdateItemKouraWState2(ItemKouraW *item) {
    s32 i;
    void *normal;
    ItemPointLink *link;

    if (item->mUnk_27c > 0xd000) {
        item->mUnk_27c -= 0xccd;
    } else {
        item->mUnk_27c += 0xccd;
    }
    AdvanceLinkFollowingItem((LinkFollowingItemObject *) item, item->mUnk_27c, 0x21, item->mRankKartIndex, 1);
    if (!(item->mUnk_000.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(&item->mUnk_300, item->mUnk_000.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mUnk_000.mSoundSource, item->mSoundId, 0x7f, 0);
        }
    }
    if (item->mUnk_000.mFlags & 1) {
        return;
    }
    UpdateItemKouraWDrawPos(item);
    normal = func_020fbd98_inline(item);
    UpdateItemKouraWOrientation(item, &item->mUnk_000.mVelocity, 1, normal);
    link = item->mKartItems->mUnk_1f0.mLink;
    for (i = 0; i < 4; i++) {
        if (link == item->mTargetLink) {
            item->mNextState = 3;
            item->mNextStateRequested = 1;
        }
        link = link->mNextLinks[0];
    }
}

void EnterItemKouraWState4(ItemKouraW *item) {
    item->mUnk_264 = 0x5000;
    item->mUnk_288 = 0x3e8;
    VEC_Subtract(&item->mUnk_238, &item->mUnk_298, &item->mUnk_28c);
    if (item->mPosStrip != NULL) {
        StopPosStrip(item->mPosStrip);
        item->mPosStrip = NULL;
    }
    if (item->mUnk_000.mFlags & 0x8000000) {
        func_020fe71c(5, item->mKartItems->mKartIndex, item->mUnk_000.mId);
    }
}

void UpdateItemKouraWState4(ItemKouraW *item) {
    Vec3 direction;
    void *normal;

    if (item->mUnk_27c > 0xd000) {
        item->mUnk_27c -= 0xccd;
    } else {
        item->mUnk_27c += 0xccd;
    }
    item->mUnk_260 -= 0xccd;
    item->mUnk_288 += 0x2d;
    if ((u32) item->mAngle < 0x8000) {
        item->mUnk_284 -= 0x666;
    } else {
        item->mUnk_284 -= 0xccd;
    }
    SteerItemKouraWToNextAnglePoint(item, 0x4cd, item->mUnk_27c, item->mUnk_284, item->mUnk_288);
    if (!(item->mUnk_000.mFlags & 1)) {
        AdvanceSoundDistanceSquaredChange(&item->mUnk_300, item->mUnk_000.mDistanceSquaredAndFlags & ~0xc000001f);
        if (item->mSoundId != 1) {
            StartSoundWhileRequested(&item->mUnk_000.mSoundSource, item->mSoundId, 0x7f, 0);
        }
    }
    UpdateItemKouraWDrawPos(item);
    if ((u32) item->mAngle < 0x11f40) {
        normal = func_020fbd98_inline(item);
        if (normal != NULL) {
            direction.x = item->mUnk_250.x * 2;
            direction.y = item->mUnk_250.y * 2;
            direction.z = item->mUnk_250.z * 2;
            Vec3CrossUnrounded(normal, &direction, &direction);
            VEC_MultAdd(((s64) (item->mAngle - 0x10000) * 0xccd) >> 12, normal, &direction, &direction);
        } else {
            direction.x = ((s64) item->mUnk_250.z * 0x2000) >> 12;
            direction.y = ((s64) (item->mAngle - 0x10000) * 0xccd) >> 12;
            direction.z = -(s32) (((s64) item->mUnk_250.x * 0x2000) >> 12);
        }
        if (item->mStateFrames == 0) {
            VEC_Subtract(&direction, &item->mUnk_298, &item->mUnk_28c);
        }
        UpdateItemKouraWOrientation(item, &direction, 1, normal);
        return;
    }
    item->mNextState = 5;
    item->mNextStateRequested = 1;
}

void EnterItemKouraWState5(ItemKouraW *item) {
    enum { K0 } kind;

    if (item->mUnk_000.mUnk_d0 == &item->mUnk_000.mDrawPos) {
        item->mUnk_000.mPos = item->mUnk_000.mDrawPos;
        item->mUnk_000.mUnk_d0 = &item->mUnk_000.mPos;
    }
    item->mUnk_260 = 0x28000;
    item->mUnk_264 = 0x333;
    kind = item->mUnk_000.mKind;
    item->mUnk_000.mUnk_100 = gItemKinds[kind].mUnk_74;
    item->mUnk_000.mFlags |= 0x800000;
    item->mUnk_2a4 = item->mUnk_28c;
    item->mUnk_27c = 0x3000;
    item->mUnk_284 = 0x59a;
}

void UpdateItemKouraWState5(ItemKouraW *item) {
    Vec3 v;
    Vec3 *normal;
    s32 x;
    s32 y;
    s32 z;

    item->mUnk_260 += 0x4cd;
    SteerItemKouraWToKartForward(item, item->mUnk_264, item->mUnk_260);
    if (item->mUnk_264 < 0xb33) {
        item->mUnk_264 += 0x52;
    }
    if (item->mUnk_260 > 0x2d000) {
        item->mNextState = 6;
        item->mNextStateRequested = 1;
    }
    item->mUnk_27c -= 0xa14;
    item->mUnk_284 -= 0x102;
    if (item->mUnk_284 < 0x7b) {
        item->mUnk_284 = 0x7b;
    }
    normal = func_020fbd98_inline(item);
    if (normal != NULL) {
        VEC_MultAdd(item->mUnk_27c, normal, &item->mUnk_22c, &v);
    } else {
        z = item->mUnk_22c.z;
        y = item->mUnk_27c;
        x = item->mUnk_22c.x;
        v.x = x;
        v.y = y;
        v.z = z;
    }
    VEC_Subtract(&v, &item->mUnk_2a4, &v);
    VEC_MultAdd(item->mUnk_284, &v, &item->mUnk_2a4, &item->mUnk_2a4);
    UpdateItemKouraWOrientation(item, &item->mUnk_2a4, 0, normal);
}

void EnterItemKouraWState6(ItemKouraW *item) {
    enum { K0 } kind;

    item->mUnk_260 = 0x28000;
    kind = item->mUnk_000.mKind;
    item->mUnk_000.mUnk_100 = gItemKinds[kind].mUnk_74;
    item->mUnk_000.mUnk_100 += 0x800;
    func_020f9c6c(&item->mUnk_000);
}

void UpdateItemKouraWState6(ItemKouraW *item) {
    s32 grew;
    Vec3 hitOffset;

    item->mUnk_260 -= 0x7000;
    SteerItemKouraWToKartForward(item, 0xb33, item->mUnk_260);
    if (item->mUnk_260 < -0x32000) {
        func_020f7104(&item->mUnk_000, 0);
        if (item->mUnk_000.mFlags & 0x8000000) {
            func_020fe71c(5, item->mKartItems->mKartIndex, item->mUnk_000.mId);
        }
    } else {
        Vec3 *position;

        position = &item->mUnk_000.mPos;
        if (func_01ffdee4(position, &item->mUnk_000.mPrevPos, 0, item->mUnk_000.mUnk_dc, 4,
                          item->mUnk_000.mCollisionSlotIndex, &hitOffset, NULL, NULL, &item->mUnk_000.mCollisionBits,
                          NULL, NULL, NULL, NULL) != 0) {
            VEC_Add(&hitOffset, position, position);
            func_020f7104(&item->mUnk_000, 0);
            if (item->mUnk_000.mFlags & 0x8000000) {
                func_020fe71c(5, item->mKartItems->mKartIndex, item->mUnk_000.mId);
            }
        }
    }
    grew =
        GrowItemObjectScale(item, gItemKinds[item->mUnk_000.mKind].mUnk_74, gItemKinds[item->mUnk_000.mKind].mUnk_78);
    if (func_020f9ce8(&item->mUnk_000) != 0) {
        return;
    }
    if (grew) {
        RefreshItemObjectScale(&item->mUnk_000);
    }
}

void EnterItemKouraWState7(ItemKouraW *param_1) {
    NNSSndSeqPlayer **sndHandle;
    struct ModelEffect *effect;
    s32 *effectScale;

    param_1->mUnk_000.mFlags |= 0x800000;
    param_1->mUnk_000.mUnk_100 = 0;
    param_1->mUnk_000.mScale = data_02159d84;
    param_1->mModelEffect =
        StartModelEffect(1, &param_1->mUnk_000.mPos, func_020f9160(&param_1->mUnk_000) == 0 ? 1 : 0);
    effect = param_1->mModelEffect;
    if (effect != NULL) {
        effectScale = effect->mScale;
        effectScale[0] = 0x1000;
        effectScale[1] = 0x1000;
        effectScale[2] = 0x1000;
    }
    func_020f91fc(param_1, 0xdf);
    if (data_0217c780 & 1) {
        sndHandle = TakeSoundHandleEntry(func_02108ea0(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(sndHandle, 0, 0xe0);
        }
    }
    StartCameraWobbleAtDistance(param_1->mUnk_000.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
}

void UpdateItemKouraWState7(ItemKouraW *item) {
    u32 stateFrames;

    stateFrames = item->mStateFrames;
    if (GrowItemObjectScale(item, gKouraWState7ScaleLimit, gKouraWState7ScaleStep)) {
        func_020f9fa8(&item->mUnk_000);
    }
    if (stateFrames < 0x16) {
        return;
    }
    if (stateFrames == 0x16) {
        item->mHitSpinsKart = 1;
    } else if (stateFrames == 0x2a) {
        FreeItemObjectCollisionSlot((s32) item);
    }
    if (stateFrames <= 0x55) {
        return;
    }
    ReleaseItemPoolObject(&gItemPools[item->mUnk_000.mKind], &item->mUnk_000);
}

void *func_020fb208(void *param_1, ItemKouraW *item, void *param_3) {
    void *r;
    void *t;

    if (item != NULL && param_3 != NULL) {
        func_020ff1b8(Vec3DotUnrounded(&item->mUnk_000.mVelocity, (Vec3 *) &item->mDirection) < 0 ? 1 : 0,
                      &item->mUnk_000.mVelocity.y);
    }
    t = CopyItemObjectData(param_1, item, param_3);
    r = CopyItemPointLinkIndex(t, item != NULL ? (void *) &item->mPreviousLink : 0, param_3);
    if (item != NULL && param_3 == NULL) {
        func_020ff1a0(item->mUnk_000.mVelocity.y, &item->mUnk_2fc);
    }
    if (item != NULL && param_3 != NULL) {
        return func_020fe8ac(item->mUnk_000.mKind);
    }
    return r;
}

void InitItemKouraWFromData(ItemKouraW *item) {
    s32 kartIndex;
    DirectionQuaternion directionQuaternion;
    Kart *kart;
    s32 nextState;

    func_020f8e78(item);
    if (item->mPreviousLink != 0) {
        InitLinkFollowingItem((LinkFollowingItemObject *) item, 0x14, 0xcc, 1, 0, item->mUnk_2fc,
                              gRaceProgress->mKartAtRank[0], 1);
        SetStateMachineState(&item->mUnk_2e8, 1);
    } else if (item->mUnk_000.mFlags & 0x8000000) {
        kartIndex = (u16) gRaceProgress->mKartAtRank[0];
        if (item->mKartItems == NULL) {
            SetItemKouraWKartItems(item, kartIndex);
            kart = item->mKartItems->mKart;
            nextState = ((item->mUnk_000.mFlags & 0x40000000) || (kart->mUnk_48 & 1)) ? 2 : 3;
            item->mNextState = nextState;
            item->mNextStateRequested = 1;
        }
    } else {
        kartIndex = (u16) gRaceProgress->mKartAtRank[0];
        SetItemKouraWKartItems(item, kartIndex);
        kart = item->mKartItems->mKart;
        nextState = ((item->mUnk_000.mFlags & 0x40000000) || (kart->mUnk_48 & 1)) ? 2 : 3;
        item->mNextState = nextState;
        item->mNextStateRequested = 1;
        if (item->mUnk_000.mFlags & 0x8000000) {
            func_020fe71c(5, item->mKartItems->mKartIndex, item->mUnk_000.mId);
        }
    }
    func_020fc94c(item);
    if ((s64) item->mUnk_000.mVelocity.x * item->mUnk_000.mVelocity.x +
            (s64) item->mUnk_000.mVelocity.y * item->mUnk_000.mVelocity.y +
            (s64) item->mUnk_000.mVelocity.z * item->mUnk_000.mVelocity.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&item->mUnk_000.mVelocity, &directionQuaternion.mDirection);
    }
    QuaternionFromYAxisToVec3(&directionQuaternion.mDirection, &directionQuaternion.mQuaternion);
    Matrix3x3FromQuaternion(&item->mUnk_000.mUnk_94, &directionQuaternion.mQuaternion);
}

void DrawItemKouraWModel(ItemKouraW *item, s32 param_2, s32 param_3) {
    u32 alpha;
    Vec3 scale;
    void *matrix;

    if (item->mUnk_000.mFlags & 0x2000) {
        if (IsItemObjectFartherFromCameraThan(&item->mUnk_000, 0x6a4) != 0) {
            return;
        }
    }
    scale.x = scale.z = item->mUnk_000.mScale.x;
    scale.y = item->mUnk_000.mScale.y;
    if (item->mUnk_000.mAlpha != 0x1f) {
        u32 i;
        NNSG3dResMdl *o;

        o = gKouraW->mResMdl;
        alpha = (u16) item->mUnk_000.mAlpha;
        for (i = 0; i < o->mInfo.mNumMat; i++) {
            NNS_G3dMdlSetMdlAlpha(o, i, alpha);
        }
    }
    if (item->mUnk_000.mFlags & 0x80000) {
        matrix = BuildItemObjectMatrix(&item->mUnk_000, (Vec3 *) param_2);
    } else {
        Vec3 *position;

        position = item->mUnk_000.mUnk_d0;
        item->mUnk_000.mUnk_94.mUnk_00[3].x = position->x >> 4;
        item->mUnk_000.mUnk_94.mUnk_00[3].y = position->y >> 4;
        item->mUnk_000.mUnk_94.mUnk_00[3].z = position->z >> 4;
        matrix = &item->mUnk_000.mUnk_94;
    }
    DrawNsbmdWithMatrixAndMaxAlpha(gKouraW, matrix, &scale, 0x1f);
    if (item->mUnk_000.mAlpha == 0x1f) {
        return;
    }
    {
        u32 i;
        NNSG3dResMdl *o;

        o = gKouraW->mResMdl;
        for (i = 0; i < o->mInfo.mNumMat; i++) {
            NNS_G3dMdlSetMdlAlpha(o, i, 0x1f);
        }
    }
}

void DrawItemKouraW(ItemKouraW *item, s32 param_2, s32 param_3) {
    ModelEffect *effect;

    if (item->mState != 7) {
        DrawItemKouraWModel(item, param_2, param_3);
        return;
    }
    effect = item->mModelEffect;
    if (effect == NULL) {
        return;
    }
    effect->mVisible = (item->mUnk_000.mFlags & 0x10000) == 0;
}

// Asks for state 7 unless the object is already in it; returns 1.
s32 RequestItemKouraWState7(ItemKouraW *item) {
    if (item->mState != 7) {
        InitStateMachine(&item->mUnk_2e8, (UnkFunc *const *) gItemKouraWStateTable, 8, item);
        item->mNextState = 7;
        item->mNextStateRequested = 1;
        if ((item->mUnk_000.mFlags & 0x180000) == 0) {
            item->mUnk_000.mAdvance = (void (*)(struct ItemObject *)) AdvanceItemKouraW;
        }
        item->mUnk_000.mFlags &= ~0x8000;
        item->mUnk_000.mFlags |= 0x80000;
        func_020f9c6c(&item->mUnk_000);
        item->mUnk_000.mUnk_78 &= ~0x4000;
    }
    return 1;
}

BOOL IsItemKouraWState7(ItemKouraW *item) {
    return item->mState == 7;
}

Vec3 *GetItemKouraWState7Info(ItemKouraW *item, s32 *stateFrames, s32 *scaleRatio) {
    *stateFrames = item->mStateFrames;
    *scaleRatio = ((s64) item->mUnk_000.mScale.z * gKouraWState7InverseLimit) >> 12;
    return &item->mUnk_000.mPos;
}

#pragma thumb on

void SetupItemKouraWKind(void) {
    s32 scaleLimit;
    s32 radiusRatio;
    s32 v;

    gKouraWState7ScaleLimit = 0x1e000;
    gKouraWState7InverseLimit = FX_Div(0x1000, gKouraWState7ScaleLimit);
    gKouraWState7ScaleStep = 0x299a;
    scaleLimit = gKouraWState7ScaleLimit;
    radiusRatio = gItemKinds[5].mUnk_6c;
    v = ((s64) scaleLimit * radiusRatio) >> 12;
    data_0217bd34 = v;
    v >>= 12;
    data_0217bd34 = v;
    data_0217bd34 = v * v;
    gKouraW = CreateItemNsbmd(data_0216c6f4, data_0216c704);
    if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(gKouraW->mResMdl, 0);
    }
}

#pragma thumb off

BOOL IsItemInfoObjectCountFree(s32 itemInfoIndex) {
    if (itemInfoIndex != 0x13) {
        return gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mUnk_0c -
                   gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mReservedCount >=
               gItemInfos[itemInfoIndex].mObjectCount;
    }
    return FALSE;
}

static inline BOOL func_020fab34_inline(s32 itemInfoIndex) {
    if (itemInfoIndex != 0x13) {
        return gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mUnk_0c -
                   gItemPools[gItemInfos[itemInfoIndex].mObjectKind].mReservedCount >=
               gItemInfos[itemInfoIndex].mObjectCount;
    }
    return FALSE;
}

// Replaces the rolled item by the fallback item when nothing was rolled or no objects are free for it; returns TRUE
// when it did.
BOOL ReplaceUnavailableItem(s32 *itemInfoIndexPointer) {
    s32 itemInfoIndex;
    s32 v;
    ItemInfo *itemInfo;
    s32 objectCount;

    itemInfoIndex = *itemInfoIndexPointer;
    if (itemInfoIndex == 0x13) {
        goto done;
    }
    if (gRaceSetup->mMode == 5) {
        itemInfo = &gItemInfos[itemInfoIndex];
        objectCount = itemInfo->mObjectCount;
        v = objectCount * func_020fa0e8(itemInfo->mObjectKind, 0);
        if (func_020fab34_inline(itemInfoIndex) != FALSE && data_0217aa14->mUnk_724 >= v) {
            return FALSE;
        }
    } else {
        if (func_020fab34_inline(itemInfoIndex) != FALSE) {
            return FALSE;
        }
    }
done:
    *itemInfoIndexPointer = gRaceSetup->mMode == 5 ? 4 : 2;
    return TRUE;
}

BOOL TryReleaseItemObjectsForItemInfo(s32 itemInfoIndex) {
    ItemInfo *itemInfo;
    s32 objectCount;
    ItemPool *pool;
    enum { K0 } kind;

    itemInfo = &gItemInfos[itemInfoIndex];
    kind = itemInfo->mObjectKind;
    pool = &gItemPools[kind];
    objectCount = itemInfo->mObjectCount;
    while (pool->mUnk_0c - pool->mReservedCount < objectCount) {
        if (gItemKinds[kind].mLimit == 1) {
            return FALSE;
        }
        if (TryReleaseFirstItemObject(pool) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void func_020fa9e4(void) {
    enum { K0 } poolIndex;
    u16 kartIndex;

    for (poolIndex = 0; poolIndex < 0xe; poolIndex++) {
        TryReleaseFirstItemObject(&gItemPools[poolIndex]);
    }
    for (kartIndex = 0; kartIndex < gKartItemsCount; kartIndex++) {
        ReleaseKartItems(&gKartItems[kartIndex]);
    }
}

void UpdateItems(void) {
    enum { K0 } poolIndex;
    u16 kartIndex;

    if (gRaceSetup->mMode == 5) {
        func_020fec30();
        func_020feb44();
    }
    for (poolIndex = 0; poolIndex < 0xe; poolIndex++) {
        if (gItemPools[poolIndex].mActiveCount != 0) {
            UpdateItemPool(&gItemPools[poolIndex]);
        }
    }
    for (kartIndex = 0; kartIndex < gKartItemsCount; kartIndex++) {
        UpdateKartItems(&gKartItems[kartIndex]);
    }
    func_020f8258();
    UpdateOrthoQuads();
    UpdateBouncingItemBoxTimers();
}

void DrawItems(void *a) {
    enum { K0 } poolIndex;
    void *viewAxis;

    viewAxis = &((Unk020e6b38 *) GetViewTransposeMatrix())->mUnk_18;
    func_020e6a74();
    for (poolIndex = 0; poolIndex < 0xe; poolIndex++) {
        if (gItemPools[poolIndex].mTakenCount > 0 && gItemPools[poolIndex].mUnk_40 == 0) {
            DrawItemPool(&gItemPools[poolIndex], viewAxis);
        }
    }
}

void StartItemSlotForKart(s32 kartIndex, s32 param_2, s32 param_3) {
    s32 playerKind;
    BOOL isHumanGhostOrPeer;

    if (gKartItems[kartIndex].mHeldItem.mItemInfoIndex != 0x13) {
        return;
    }
    playerKind = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mKind;
    if (playerKind == PLAYER_KIND_PEER) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        isHumanGhostOrPeer = FALSE;
        if ((u32) playerKind > 3) {
        } else if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
        StartItemSlot(&gKartItems[kartIndex], param_2, GetBattleItemRank(kartIndex), isHumanGhostOrPeer ? 1 : 0,
                      param_3);
    } else {
        isHumanGhostOrPeer = FALSE;
        if ((u32) playerKind > 3) {
        } else if ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) {
            isHumanGhostOrPeer = TRUE;
        }
        StartItemSlot(&gKartItems[kartIndex], param_2, GetKartRank(kartIndex), isHumanGhostOrPeer ? 1 : 0, param_3);
    }
}

static inline s32 func_020fa4c8_inline(ItemObject *item, Kart *kart) {
    Vec3 previousDelta;
    Vec3 delta;
    s32 previousDistanceSquared;
    s32 distanceSquared;
    s32 radius;
    s32 x;
    s64 fullDistanceSquared;

    if (!(item->mFlags & 0x8000)) {
        return 1;
    }
    if (kart->mIndex != (u16) (!(item->mUnk_78 & 0x8000) ? (u16) (item->mUnk_78 & ~0xff00) : 8)) {
        return 1;
    }
    if (item->mVelocity.x != 0 || item->mVelocity.y != 0 || item->mVelocity.z != 0 || kart->mForwardSpeed != 0) {
        VEC_Subtract(&item->mPrevPos, &kart->mPrevPointAlongUp, &previousDelta);
        previousDelta.y = 0;
        VEC_Subtract(&item->mPos, &kart->mPointAlongUp, &delta);
        delta.y = 0;
        previousDistanceSquared = Vec3DotUnrounded(&previousDelta, &previousDelta);
        distanceSquared = Vec3DotUnrounded(&delta, &delta);
        if (previousDistanceSquared - 0x1000 > distanceSquared) {
            return 1;
        }
    }
    radius = item->mRadius;
    x = item->mPos.x - kart->mPointAlongUp.x;
    fullDistanceSquared =
        (s64) (item->mPos.z - kart->mPointAlongUp.z) * (item->mPos.z - kart->mPointAlongUp.z) +
        ((s64) x * x + (s64) (item->mPos.y - kart->mPointAlongUp.y) * (item->mPos.y - kart->mPointAlongUp.y));
    return fullDistanceSquared < (s64) radius * radius ? 1 : 0;
}

// Returns how many item objects hit the kart; GetCollidedItemObject reads them.
s32 CollideKartWithItemObjects(Kart *kart) {
    s32 i;
    s32 hitCount;
    BOOL fl;
    s32 v;
    s32 lim;
    ItemObject *item;
    enum { K0 } kind;

    hitCount = 0;
    fl = (kart->mUnk_48 & 0x8000000) != 0;
    lim = 0xf;
    for (i = 0; i < gFoundCollisionSlotCount; i++) {
        if (!(gFoundCollisionSlotFlags[i] & 0x4000)) {
            continue;
        }
        item = gFoundCollisionSlotObjects[i];
        if (fl && !(item->mFlags & 0x200000)) {
            continue;
        }
        if (!func_020f97e0(item, kart)) {
            continue;
        }
        v = func_020fa4c8_inline(item, kart);
        if (v == 0) {
            continue;
        }
        if ((kart->mUnk_7c & 0x2000) && func_020f9880(item) != 0) {
            continue;
        }
        gCollidedItemObjects[hitCount++] = item;
        if (item->mFlags & 0x1000) {
            RemoveItemInUseObject(&gKartItems[(u16) (item->mUnk_78 & ~0xff00)].mItemInUse, item);
        }
        kind = item->mKind;
        if (gItemKinds[kind].mUnk_88 != 0) {
            if (func_020f9880(item) != 0) {
                func_020f6be8(item, &kart->mCollisionCenter, &kart->mVelocity, &kart->mSignedTurnedForward);
                func_020f6f10(item, 1, (u16) kart->mIndex);
            } else {
                func_020f7430(item, 1);
            }
        }
        if (hitCount >= 0x10) {
            hitCount = lim;
        }
    }
    return hitCount;
}

#pragma thumb on

#pragma thumb off

struct ItemObject *GetCollidedItemObject(u32 index) {
    return gCollidedItemObjects[index];
}

#pragma thumb off

void *StartItemObjectOrZero(s32 kind, u16 param_2, void *param_3, void *param_4) {
    ItemObject *item;
    ItemPool *pool;

    item = 0;
    if (gItemPools[kind].mLimit - gItemPools[kind].mReservedCount <= 0) {
        return 0;
    }
    TakeItemPoolObjects(&gItemPools[kind], 1, &item, param_2, param_3);
    pool = &gItemPools[kind];
    pool->mReservedCount++;
    StartItemObject(&gItemPools[item->mKind], item);
    func_020f98a0(item, param_3, param_4, 0, 0);
    if (param_2 == 8) {
        item->mUnk_78 |= data_02159cbc;
    }
    return item;
}

#pragma thumb on

static inline ItemObject *func_020fa3d0_inline(s32 kind, u16 param_2, void *param_3, void *param_4) {
    ItemObject *item;
    ItemPool *pool;

    item = 0;
    if (gItemPools[kind].mLimit - gItemPools[kind].mReservedCount <= 0) {
        return 0;
    }
    TakeItemPoolObjects(&gItemPools[kind], 1, &item, param_2, param_3);
    pool = &gItemPools[kind];
    pool->mReservedCount++;
    StartItemObject(&gItemPools[item->mKind], item);
    func_020f98a0(item, param_3, param_4, 0, 0);
    if (param_2 == 8) {
        item->mUnk_78 |= data_02159cbc;
    }
    return item;
}

// Starts an item object at every course map row of object kind 0x6d and rests it on the floor.
void StartCourseMapItemObjects(void) {
    u32 i;
    u32 rowCount;
    u32 v;
    ItemObject *item;
    Vec3 m;
    enum { K0 } kind;
    CourseMapRow *row;

    rowCount = gCourseMap->mRowCount;
    for (i = 0; i < rowCount; i++) {
        row = &gCourseMap->mRows[i];
        if (row->mKind == 0x6d) {
            kind = row->mUnk_28;
            if (func_01ffdee4(row, 0, 0, 0xa000, 8, -2, 0, &m, 0, 0, 0, 0, 0, &v) == 0) {
                m = data_02159cb0;
            }
            item = func_020fa3d0_inline(kind, 8, row, &m);
            if (item != 0) {
                void (*advance)(ItemObject *);

                kind = item->mKind;
                advance = gItemKinds[kind].mAdvance;
                if ((item->mFlags & 0x180000) == 0) {
                    item->mAdvance = advance;
                }
                StartRestingItemObject(item, &v);
            }
        }
    }
}

void InitItems(void) {
    void *heap;
    s32 a;
    s32 i;
    enum { K0 } kind;
    HeldItem *heldItem;
    u8 kartCount;

    heap = GetHeap(GetCurrentHeapCall());
    a = 0;
    CreateItemSlotTables();
    func_020f82e8(1);
    func_020f82c4(1);
    func_020f82a4(1);
    CreateItemInfos();
    InitItemKinds();
    CreateItemPushVector();
    InitItemPointLinkDirections();
    kartCount = gRaceSetup->mKartCount;
    gKartItemsCount = kartCount;
    gKartItems = HeapAlloc(heap, kartCount * 0x210);
    for (i = 0; i < gKartItemsCount; i++) {
        InitKartItems(&gKartItems[i], (u16) i);
    }
    gItemPools = HeapAlloc(heap, 0x3b8);
    for (kind = 0; kind < 0xe; kind++) {
        CreateItemPool(&gItemPools[kind], kind, &a);
    }
    CreateItemModels();
    if (gRaceSetup->mMode == 5) {
        func_020fe46c();
        func_020fe450();
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        for (i = 0; i < gKartItemsCount; i++) {
            heldItem = &gKartItems[i].mHeldItem;
            SetHeldItem(heldItem, 5);
            switch (GetKartVariant((u16) i)) {
                case 0:
                    RemoveHeldItemObjects(heldItem, 1);
                    break;
                case 1:
                    RemoveHeldItemObjects(heldItem, 2);
                    break;
            }
        }
    }
    gCollidedItemObjects = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    StartCourseMapItemObjects();
    CreateItemTeresaFrameScaleTable();
    InitOrthoQuads();
    InitBouncingItemBoxTimers();
}

s32 func_020fa0e8(s32 kind, s32 param_2) {
    switch (param_2) {
        case 0:
            return (u8) ((u8) gItemKinds[kind].mDataSize + 1);
        case 1:
            return 0x12;
        case 2:
            return 3;
        case 3:
            return (u8) ((kind == 0xb ? 3 : 2) + 1);
    }
    return 0;
}

#pragma thumb off

s32 GrowItemObjectScale(void *objectParam, s32 limit, s32 step) {
    ItemObject *item = objectParam;

    if (item->mScale.z < limit) {
        item->mScale.z += step;
        if (item->mScale.z > limit) {
            item->mScale.z = limit;
        }
        return 1;
    }
    return 0;
}

void RefreshItemObjectScale(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    kind = item->mKind;
    item->mFlags |= 0x40;
    item->mScale.y = item->mScale.z;
    item->mScale.x = item->mScale.y;
    kindInfo = &gItemKinds[kind];
    radiusRatio = kindInfo->mUnk_6c;
    item->mUnk_dc = ((s64) item->mScale.y * kindInfo->mUnk_64) >> 12;
    item->mRadius = ((s64) item->mScale.y * radiusRatio) >> 12;
    SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
}

void func_020f9fa8(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    kind = item->mKind;
    item->mFlags |= 0x40;
    item->mScale.y = item->mScale.z;
    item->mScale.x = item->mScale.y;
    kindInfo = &gItemKinds[kind];
    radiusRatio = kindInfo->mUnk_6c;
    item->mUnk_dc = ((s64) item->mScale.y * kindInfo->mUnk_64) >> 12;
    item->mRadius = ((s64) item->mScale.y * radiusRatio) >> 12;
    SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius);
}

void SetItemObjectScaleByRatios(ItemObject *objectParam, s32 xRatio, s32 yRatio) {
    ItemObject *item = objectParam;
    enum { K0 } kind;
    s32 m;

    kind = item->mKind;
    m = gItemKinds[kind].mUnk_68;
    item->mScale.x = ((s64) item->mScale.z * xRatio) >> 12;
    item->mScale.y = ((s64) item->mScale.z * yRatio) >> 12;
    item->mUnk_dc = ((s64) item->mScale.y * gItemKinds[kind].mUnk_64) >> 12;
    item->mRadius = ((s64) item->mScale.y * m) >> 12;
    SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
}

s32 func_020f9dc8(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    if (item->mUnk_100 <= -0x29 || item->mUnk_100 >= 0x29 || item->mScale.x - item->mScale.y <= -0x29 ||
        item->mScale.x - item->mScale.y >= 0x29) {
        kind = item->mKind;
        item->mFlags |= 0x40;
        item->mScale.y += item->mUnk_100;
        item->mUnk_100 += (s32) (((s64) (item->mScale.z - item->mScale.y) * 0x333) >> 12);
        item->mUnk_100 = ((s64) item->mUnk_100 * 0xc00) >> 12;
        item->mScale.x = item->mScale.z * 2 - item->mScale.y;
        kindInfo = &gItemKinds[kind];
        radiusRatio = kindInfo->mUnk_6c;
        item->mUnk_dc = ((s64) item->mScale.y * kindInfo->mUnk_64) >> 12;
        item->mRadius = ((s64) item->mScale.y * radiusRatio) >> 12;
        SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
        return 1;
    }
    item->mUnk_100 = 0;
    return 0;
}

s32 func_020f9ce8(ItemObject *item) {
    ItemKind *kindInfo;
    enum { K0 } kind;
    s32 radiusRatio;

    if (item->mUnk_100 != 0) {
        kind = item->mKind;
        item->mFlags |= 0x40;
        item->mScale.y += (s32) (((s64) (item->mUnk_100 - item->mScale.y) * 0x333) >> 12);
        item->mScale.x = item->mScale.z * 2 - item->mScale.y;
        kindInfo = &gItemKinds[kind];
        radiusRatio = kindInfo->mUnk_6c;
        item->mUnk_dc = ((s64) item->mScale.y * kindInfo->mUnk_64) >> 12;
        item->mRadius = ((s64) item->mScale.y * radiusRatio) >> 12;
        SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
        return 1;
    }
    return 0;
}

void CreateItemObjectCollisionSlot(void *objectParam) {
    ItemObject *item = objectParam;

    if (item->mCollisionSlotIndex != -1) {
        return;
    }
    item->mCollisionSlotIndex = CreateCollisionSlot(&item->mPos, item->mRadius + 0xa000, 0x4000, item);
}

void func_020f9c6c(ItemObject *item) {
    if (item->mCollisionSlotIndex != -1) {
        return;
    }
    item->mCollisionSlotIndex = CreateCollisionSlot(&item->mPos, item->mRadius, 0x4000, item);
}

#pragma thumb on
