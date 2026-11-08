#include "Main/Unknown/code_020937c4.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"

void CreateNsKiller1(void *a) {
    gNsKiller1 = CreateMapObjectModelAnimated(a, gNsKiller1NsbmdName);
}

void DrawNsKiller1(void *a, NsKiller1 *nsKiller1) {
    s32 t;

    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    func_01ff9048(0x1b, &nsKiller1->mUnk_00.mScale, 3);
    nsKiller1->mUnk_00.mMatrix.mUnk_00[3].x = nsKiller1->mUnk_00.mPos.x >> 4;
    nsKiller1->mUnk_00.mMatrix.mUnk_00[3].y = nsKiller1->mUnk_00.mPos.y >> 4;
    nsKiller1->mUnk_00.mMatrix.mUnk_00[3].z = nsKiller1->mUnk_00.mPos.z >> 4;
    func_01ff9048(0x19, &nsKiller1->mUnk_00.mMatrix, 12);
    DrawMapObjectModel(a, gNsKiller1, nsKiller1);
}

void InitNsKiller1Objects(MapObjectList *mapObjectList) {
    s32 i;
    NsKiller1 *nsKiller1;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (nsKiller1 = mapObjectList->mMapObjects[i]) != NULL; i++) {
        nsKiller1->mStateTimer = 0;
    }
}

void UpdateNsKiller1(void *a, NsKiller1 *nsKiller1) {
    Unk0210b7a8 s;

    switch (nsKiller1->mState) {
        case 0:
            if (nsKiller1->mStateTimer-- > 0) {
                return;
            }
            nsKiller1->mFollower.mSpeed = 0x2000;
            nsKiller1->mFollower.mProgressStep =
                ((s64) nsKiller1->mFollower.mPath->mSegments[nsKiller1->mFollower.mSegmentIndex].mInverseProgressLength
                 << 13) >>
                12;
            nsKiller1->mState = 1;
            break;
        case 1:
            if (AdvanceGroupFollower(&nsKiller1->mFollower) != FALSE) {
                nsKiller1->mStateTimer = 0x2d;
                nsKiller1->mState = 2;
            }
            GetGroupFollowerLinearXz(&nsKiller1->mFollower, &nsKiller1->mUnk_00.mPos);
            break;
        case 2:
            if (nsKiller1->mStateTimer == 0x2d) {
                if ((nsKiller1->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
                    NNS_SndPlayerStopSeq(GetSndHandleSlot(8), 0);
                    s = data_0216676c;
                    s.mPositionSource = &nsKiller1->mUnk_00.mPos;
                    s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&nsKiller1->mUnk_00.mPos);
                    func_0210b708(&s, GetSndHandleSlot(8));
                }
            } else if (nsKiller1->mStateTimer <= 0) {
                nsKiller1->mStateTimer = 0;
                nsKiller1->mState = 3;
            }
            nsKiller1->mStateTimer--;
            break;
        case 3:
            StartNsKiller2(&nsKiller1->mUnk_00.mPos, &nsKiller1->mUnk_00.mMatrix.mUnk_00[2], nsKiller1->mUnk_00.mAngle);
            if ((nsKiller1->mUnk_00.mFlags & 0x12) == 0) {
                StartEffect(0x4b, &nsKiller1->mUnk_00.mPos);
                StartEffect(0x4c, &nsKiller1->mUnk_00.mPos);
                StartEffect(0x4d, &nsKiller1->mUnk_00.mPos);
            }
            nsKiller1->mStateTimer = 0x4b;
            nsKiller1->mState = 0;
            break;
    }
}

void CreateNsKiller1DrawList(void) {
    CreateMapObjectDrawList1(CreateNsKiller1, DrawNsKiller1, NULL);
}

void CreateNsKiller1UpdateList(void) {
    CreateMapObjectUpdateList(InitNsKiller1Objects, UpdateNsKiller1, NULL);
}

void InitNsKiller2(NsKiller2 *nsKiller2) {
    nsKiller2->mUnk_00.mFlags |= data_021564b4;
    ParkMapObject(&nsKiller2->mUnk_00);
    nsKiller2->mSoundDistanceSquaredChange = func_020d286c(&nsKiller2->mUnk_00);
    ResetSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange);
    nsKiller2->mUnk_00.mSound->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) func_0210a6b4;
}

u8 CollideKartWithNsKiller2(NsKiller2 *nsKiller2, Kart *kart, u8 *c, u8 *d) {
    u8 x;
    u8 v;

    x = *c;
    v = *d;
    if (x == 1) {
        nsKiller2->mParkTimer = 0x78;
        nsKiller2->mMode = 1;
        nsKiller2->mUnk_00.mUnk_10.x = ((s64) nsKiller2->mUnk_00.mUnk_10.x << 10) >> 12;
        nsKiller2->mUnk_00.mUnk_10.y = ((s64) nsKiller2->mUnk_00.mUnk_10.y << 10) >> 12;
        nsKiller2->mUnk_00.mUnk_10.z = ((s64) nsKiller2->mUnk_00.mUnk_10.z << 10) >> 12;
        nsKiller2->mUnk_00.mUnk_10.y = 0x4000;
        nsKiller2->mUnk_00.mFlags |= data_021564ac;
        if (kart->mItemEffect == 1 || kart->mItemEffect == 3) {
            nsKiller2->mUnk_00.mDistanceSquaredAndFlags |= data_021564b0;
        }
        StartSoundIfKartStarOrKiller(&nsKiller2->mUnk_00, kart);
    }
    return v;
}

void CreateNsKiller2AndNsKiller2S(void *a) {
    gNsKiller2 = CreateMapObjectModelAnimated(a, gNsKiller2NsbmdName);
    gNsKiller2S = CreateMapObjectModelShadow(a, gNsKiller2SNsbmdName);
    SetMapObjectModelPolygonId(gNsKiller2S, 0x3f);
}

void DrawNsKiller2(void *a, NsKiller2 *nsKiller2) {
    s32 t;
    s32 rotationMatrix[9];
    s32 angleIndex;

    if (nsKiller2->mParkTimer <= 0) {
        return;
    }
    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    func_01ff9048(0x19, SetTranslationMatrixPos(&nsKiller2->mUnk_00.mPos), 12);
    angleIndex = nsKiller2->mUnk_00.mAngle >> 4;
    MTX_RotY33_(rotationMatrix, gPairsByAngle[angleIndex * 2], gPairsByAngle[angleIndex * 2 + 1]);
    func_01ff9048(0x1a, rotationMatrix, 9);
    func_01ff9048(0x1b, &nsKiller2->mUnk_00.mScale, 3);
    DrawMapObjectModel(a, gNsKiller2S, nsKiller2);
    DrawMapObjectModel(a, gNsKiller2, nsKiller2);
}

void UpdateNsKiller2(void *a, NsKiller2 *nsKiller2) {
    if ((GetKartKind3ShapeMask() & nsKiller2->mUnk_00.mDigitMask) != 0) {
        nsKiller2->mUnk_00.mFlags |= data_021564a8;
    } else {
        nsKiller2->mUnk_00.mFlags &= ~2;
    }
    switch (nsKiller2->mMode) {
        case 0:
            if (nsKiller2->mParkTimer-- > 0) {
                if ((nsKiller2->mUnk_00.mFlags & 2) == 0 && (nsKiller2->mUnk_00.mDistanceSquaredAndFlags & 8) != 0) {
                    AdvanceSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange,
                                                      nsKiller2->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f);
                } else {
                    AdvanceSoundDistanceSquaredChange(nsKiller2->mSoundDistanceSquaredChange,
                                                      GetHorizontalCameraDistanceSquared(&nsKiller2->mUnk_00.mPos));
                }
                VEC_Add(&nsKiller2->mUnk_00.mPos, &nsKiller2->mUnk_00.mUnk_10, &nsKiller2->mUnk_00.mPos);
                if (nsKiller2->mParkTimer < 0x24e) {
                    StartMapObjectSoundWhileRequested(&nsKiller2->mUnk_00, 0x17d);
                }
            } else {
                ParkMapObject(&nsKiller2->mUnk_00);
            }
            break;
        case 1:
            if (nsKiller2->mParkTimer-- > 0) {
                nsKiller2->mUnk_00.mUnk_10.y -= 0x400;
                VEC_Add(&nsKiller2->mUnk_00.mPos, &nsKiller2->mUnk_00.mUnk_10, &nsKiller2->mUnk_00.mPos);
            } else {
                ParkMapObject(&nsKiller2->mUnk_00);
            }
            break;
    }
}

void CreateNsKiller2KindData(void) {
    MapObjectKindData *o;

    o = func_0209bf70(CollideKartWithNsKiller2, NULL, NULL, 1, 1, 0x17b);
    o->mUnk_38 = 0x32000;
    o->mUnk_3c = -0x64000;
}

void CreateNsKiller2DrawList(void) {
    CreateMapObjectDrawList1(CreateNsKiller2AndNsKiller2S, DrawNsKiller2, NULL);
}

void CreateNsKiller2UpdateList(void) {
    CreateMapObjectUpdateList(NULL, UpdateNsKiller2, NULL);
}

// Starts a parked NsKiller2 at a (raised), flying along b with angle c.
void StartNsKiller2(Vec3 *startPos, Vec3 *b, u16 angle) {
    NsKiller2 *nsKiller2;

    nsKiller2 = UnparkFirstParkedMapObject(FindMapObjectKindUpdateList(MAP_OBJECT_KIND_NS_KILLER2));
    if (nsKiller2 == NULL) {
        return;
    }
    nsKiller2->mParkTimer = 600;
    nsKiller2->mUnk_00.mPos.x = startPos->x;
    nsKiller2->mUnk_00.mPos.y = startPos->y + 0x2a000;
    nsKiller2->mUnk_00.mPos.z = startPos->z;
    nsKiller2->mUnk_00.mMatrix.mUnk_00[2].x = b->x;
    nsKiller2->mUnk_00.mMatrix.mUnk_00[2].y = 0;
    nsKiller2->mUnk_00.mMatrix.mUnk_00[2].z = b->z;
    nsKiller2->mUnk_00.mUnk_10.x = ((s64) b->x * 0x6000) >> 12;
    nsKiller2->mUnk_00.mUnk_10.y = 0;
    nsKiller2->mUnk_00.mUnk_10.z = ((s64) b->z * 0x6000) >> 12;
    nsKiller2->mUnk_00.mAngle = angle;
    nsKiller2->mMode = 0;
}
