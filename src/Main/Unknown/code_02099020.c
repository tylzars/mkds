#include "Main/Unknown/code_02099020.h"

#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/unk_02156000.h"

void func_02099278(u32 mapObject) {
    u32 addedFlagsAddress = ((u32) (&data_02156598));
    u32 flags = (*(u16 *) ((mapObject) + (2)));
    u32 addedFlags = (*(u16 *) ((addedFlagsAddress) + (0)));
    u32 newFlags = ((flags) | (addedFlags));
    u32 v7;
    u32 v9;
    *(u16 *) ((mapObject) + (2)) = newFlags;
    ParkMapObject((void *) mapObject);
    CreateMapObjectSoundSourceFalloff2((MapObject *) mapObject);
}

u32 func_02099208(Unk0209905c *a, Kart *kart, u8 *c, u8 *d) {
    u32 v1 = *c;
    u8 result = *d;
    if (v1 == 1) {
        a->mUnk_00.mFlags = a->mUnk_00.mFlags | data_usa_02156590;
        a->mState = 1;
        if (kart->mItemEffect == 1 || kart->mItemEffect == 3) {
            a->mUnk_00.mDistanceSquaredAndFlags = a->mUnk_00.mDistanceSquaredAndFlags | data_usa_02156594;
        }
        StartSoundIfKartStarOrKiller(&a->mUnk_00, kart);
    }
    return result;
}

void func_0209905c(void *a, Unk0209905c *p) {
    s32 falloffIndex;
    Unk0210b7a8 soundRequest;
    Unk0209905c_d0_08 *entry;
    switch (p->mState) {
        case 0:
            p->mHeightOffset = p->mHeightOffset + p->mUnk_c8;
            p->mUnk_c8 = p->mUnk_c8 - 0x1000;
            if (p->mHeightOffset <= 0) {
                p->mHeightOffset = 0;
                p->mUnk_c8 = 0x5800;
                if ((p->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
                    if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                        falloffIndex = 2;
                    } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                        falloffIndex = 3;
                    } else {
                        falloffIndex = 4;
                    }
                    soundRequest.mSoundId = 0x1af;
                    soundRequest.mPositionSource = &p->mUnk_00.mPos;
                    soundRequest.mUnk_08 = falloffIndex;
                    soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&p->mUnk_00.mPos);
                    func_0210b7a8(&soundRequest);
                }
            }
            if (AdvanceGroupFollower(&p->mFollower) != FALSE && p->mFollower.mForward == 0) {
                p->mState = 1;
            } else {
                GetGroupFollowerLinearPosStep(&p->mFollower, &p->mUnk_00.mPos, &p->mUnk_00.mUnk_10);
                p->mUnk_00.mPos.y = p->mUnk_00.mPos.y + (p->mHeightOffset + 0xf000);
            }
            if (p->mEmitter == NULL) {
                return;
            }
            if ((p->mUnk_00.mFlags & 0x12) != 0) {
                p->mEmitter->mUnk_24 |= 2;
                return;
            }
            PlaceEffect(p->mEmitter, &p->mUnk_00.mPos);
            p->mEmitter->mUnk_24 &= ~2;
            return;
        case 1:
            if (p->mEmitter != NULL) {
                for (entry = p->mEmitter->mUnk_08; entry != NULL; entry = entry->mUnk_00) {
                    entry->mUnk_26 = entry->mUnk_24;
                }
                func_0208b6b0((void **) &p->mEmitter);
            }
            ParkMapObject(&p->mUnk_00);
            return;
    }
}

void func_02099020(void) {
    func_0209bf70(&func_02099208, NULL, NULL, 1, 1, (0x0000018du));
}
